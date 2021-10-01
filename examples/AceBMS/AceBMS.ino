#include <SPI.h>
#include <avr/wdt.h>
#include <limits.h>

#include "AceBMS.h"
#include "AceBus.h"
#include "MCP2515.h"

#define kInterruptPin (2)
void aceCallback(tinframe_t *frame){};
AceBus aceBus(Serial, kInterruptPin, aceCallback);

uint16_t frameSequence = 0;
bool heartBeat = false;

struct can_frame canMsg;
MCP2515 mcp2515(6);

const int buzzerPin = 9;
const int ledPin = 5;

#define CANBUS_CAN_ID_SHUNT 40
#define CANBUS_CAN_ID_BMS 300

typedef struct {
  int16_t cellVoltage[8];
  int16_t temperature[2];
  int32_t chargeMilliAmps;
  int32_t chargeMilliAmpSeconds;
  int16_t balanceVoltage;
} bms_t;

static bms_t bms;

void process(void) {
  // called 4 times per second, triggered by current shunt canbus message
  static int8_t count = 0;

  uint16_t cellMin = 5000;
  uint16_t cellMax = 0;
  uint16_t cellSum = 0;

  uint16_t cellHi = 0;
  uint16_t cellLo = 0;

  // reset watchdog timer when we get a current measurement
  wdt_reset();

  uint8_t i = 8;
  while (i--) {
    uint16_t v = bms.cellVoltage[i];
    if (v > cellMax)
      cellMax = v;
    if (v < cellMin)
      cellMin = v;
    cellSum += v;
  }

  uint16_t cellAvg = cellSum / 8;
  if (cellMax > 0) {
    bms.balanceVoltage = cellAvg + 2;
    if (bms.balanceVoltage < 3000) {
      bms.balanceVoltage = 3000;
    }
    cellHi = cellMax - cellAvg;
  } else {
    bms.balanceVoltage = 0;
  }

  if (cellMin < 5000) {
    cellLo = cellAvg - cellMin;
  }

  count++;
  bool buzzer = (count & 0x08) && (bms.chargeMilliAmps < -10000L);
  digitalWrite(buzzerPin, buzzer);

  if (count & 0x01) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (++frameSequence >= (4 * 60 * 60)) {
    frameSequence = 0; // force rollover on hour boundary
  }

  tinframe_t txFrame;
  msg_t *msg = (msg_t *)txFrame.data;
  sig_encode(msg, ACEBMS_VBAT, SIG_DIVU16BY10(cellSum + 5));
  sig_encode(msg, ACEBMS_IBAT, SIG_DIVS16BY100(bms.chargeMilliAmps + 50));
  sig_encode(msg, ACEBMS_VCHI, SIG_DIVU16BY10(cellHi + 5));
  sig_encode(msg, ACEBMS_VCLO, SIG_DIVU16BY10(cellLo + 5));
  sig_encode(msg, ACEBMS_RQST, frameSequence);
  aceBus.write(&txFrame);
  heartBeat = true;
}

void setup() {
  // enable watchdog timer
  wdt_reset();
  wdt_enable(WDTO_1S);

  aceBus.begin();

  SPI.begin();

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_250KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  // update bus
  int status = aceBus.update();
  if (status == AceBus_kWriteComplete) {
    // send other parameters when sequence number matches message ID
    if (heartBeat) {
      heartBeat = false;
      tinframe_t txFrame;
      msg_t *msg = (msg_t *)txFrame.data;
      if ((frameSequence & 0xFF) == (SIG_MSG_ID(ACEBMS_CEL1) & 0xFF)) {
        sig_encode(msg, ACEBMS_CEL1, bms.cellVoltage[0]);
        sig_encode(msg, ACEBMS_CEL2, bms.cellVoltage[1]);
        sig_encode(msg, ACEBMS_CEL3, bms.cellVoltage[2]);
        sig_encode(msg, ACEBMS_CEL4, bms.cellVoltage[3]);
        aceBus.write(&txFrame);
      } else if ((frameSequence & 0xFF) == (SIG_MSG_ID(ACEBMS_CEL5) & 0xFF)) {
        sig_encode(msg, ACEBMS_CEL5, bms.cellVoltage[4]);
        sig_encode(msg, ACEBMS_CEL6, bms.cellVoltage[5]);
        sig_encode(msg, ACEBMS_CEL7, bms.cellVoltage[6]);
        sig_encode(msg, ACEBMS_CEL8, bms.cellVoltage[7]);
        aceBus.write(&txFrame);
      } else if ((frameSequence & 0xFF) == (SIG_MSG_ID(ACEBMS_VBAL) & 0xFF)) {
        sig_encode(msg, ACEBMS_VBAL, bms.balanceVoltage);
        sig_encode(msg, ACEBMS_CHAH, ((bms.chargeMilliAmpSeconds >> 8L) * 466L) >> 16L);
        sig_encode(msg, ACEBMS_BTC1, bms.temperature[0]);
        sig_encode(msg, ACEBMS_BTC2, bms.temperature[1]);
        aceBus.write(&txFrame);
      }
    }
  }

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    if (canMsg.can_id == (CANBUS_CAN_ID_SHUNT | CAN_EFF_FLAG)) {
      if (canMsg.can_dlc == 8) {
        int32_t current = (int32_t)(((uint32_t)canMsg.data[0] << 16) +
                                    ((uint32_t)canMsg.data[1] << 8) +
                                    (uint32_t)canMsg.data[2]) -
                          8388608L;
        bms.chargeMilliAmps = current;
        bms.chargeMilliAmpSeconds += current / 4;

        process();

        // send can message
        canMsg.can_id = (CANBUS_CAN_ID_BMS | CAN_EFF_FLAG);
        canMsg.can_dlc = 2;
        canMsg.data[0] = bms.balanceVoltage >> 8;
        canMsg.data[1] = bms.balanceVoltage;
        mcp2515.sendMessage(&canMsg);
      }
    }
    if (canMsg.can_id == ((CANBUS_CAN_ID_BMS + 1) | CAN_EFF_FLAG)) {
      if (canMsg.can_dlc == 8) {
        // update cell voltages
        bms.cellVoltage[0] =
            ((uint16_t)canMsg.data[0] << 8) + (uint16_t)canMsg.data[1];
        bms.cellVoltage[1] =
            ((uint16_t)canMsg.data[2] << 8) + (uint16_t)canMsg.data[3];
        bms.cellVoltage[2] =
            ((uint16_t)canMsg.data[4] << 8) + (uint16_t)canMsg.data[5];
        bms.cellVoltage[3] =
            ((uint16_t)canMsg.data[6] << 8) + (uint16_t)canMsg.data[7];
      }
    }
    if (canMsg.can_id == ((CANBUS_CAN_ID_BMS + 2) | CAN_EFF_FLAG)) {
      if (canMsg.can_dlc == 8) {
        // update cell voltages
        bms.cellVoltage[4] =
            ((uint16_t)canMsg.data[0] << 8) + (uint16_t)canMsg.data[1];
        bms.cellVoltage[5] =
            ((uint16_t)canMsg.data[2] << 8) + (uint16_t)canMsg.data[3];
        bms.cellVoltage[6] =
            ((uint16_t)canMsg.data[4] << 8) + (uint16_t)canMsg.data[5];
        bms.cellVoltage[7] =
            ((uint16_t)canMsg.data[6] << 8) + (uint16_t)canMsg.data[7];
      }
    }
    if (canMsg.can_id == ((CANBUS_CAN_ID_BMS + 4) | CAN_EFF_FLAG)) {
      if (canMsg.can_dlc == 8) {
        // update temperatures
        bms.temperature[0] = (int16_t)canMsg.data[0] - 40;
        bms.temperature[1] = (int16_t)canMsg.data[1] - 40;
      }
    }
  }
}
