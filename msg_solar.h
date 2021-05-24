#ifndef MSG_SOLAR_H
#define MSG_SOLAR_H

#include "msg.h"

#define LOG_CRCE {0x00, 0, 16, MSG_UNIT}
#define LOG_SEQE {0x00, 16, 16, MSG_UNIT}
#define LOG_OVRE {0x00, 32, 16, MSG_UNIT}
#define LOG_MSGE {0x00, 48, 16, MSG_UNIT}

#define BMS_VBAT {0x80, 0, 16, MSG_MILLI}
#define BMS_VTRG {0x80, 16, 16, MSG_MILLI}
#define BMS_IBAT {0x80, 32, 16, MSG_CENTI}
#define BMS_ITRG {0x80, 48, 16, MSG_CENTI}

#define BMS_CEL1 {0x82, 0, 16, MSG_MILLI}
#define BMS_CEL2 {0x82, 16, 16, MSG_MILLI}
#define BMS_CEL3 {0x82, 32, 16, MSG_MILLI}
#define BMS_CEL4 {0x82, 48, 16, MSG_MILLI}

#define BMS_CEL5 {0x84, 0, 16, MSG_MILLI}
#define BMS_CEL6 {0x84, 16, 16, MSG_MILLI}
#define BMS_CEL7 {0x84, 32, 16, MSG_MILLI}
#define BMS_CEL8 {0x84, 48, 16, MSG_MILLI}

#define BMS_VBAL {0x86, 0, 16, MSG_MILLI}
#define BMS_CHAH {0x86, 16, 16, MSG_CENTI}
#define BMS_BTC1 {0x86, 32, 8, MSG_UNIT}
#define BMS_BTC2 {0x86, 40, 8, MSG_UNIT}

#define MSG_NAMES {     \
  {"Vbat", BMS_VBAT},   \
  {"Vtrg", BMS_VTRG },  \
  {"Ibat", BMS_IBAT },  \
  {"Itrg", BMS_ITRG },  \
\
  {"Vc1", BMS_CEL1 },  \
  {"Vc2", BMS_CEL2 },  \
  {"Vc3", BMS_CEL3 },  \
  {"Vc4", BMS_CEL4 },  \
\
  {"Vc5", BMS_CEL5 },  \
  {"Vc6", BMS_CEL6 },  \
  {"Vc7", BMS_CEL7 },  \
  {"Vc8", BMS_CEL8 },  \
\
  {"Vbal", BMS_VBAL },  \
  {"ChAh", BMS_CHAH },  \
  {"BTc1", BMS_BTC1 },  \
  {"BTc2", BMS_BTC2 },  \
}

#endif // MSG_SOLAR_H
