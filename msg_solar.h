#ifndef MSG_SOLAR_H
#define MSG_SOLAR_H

#include "msg.h"

#define MSG_SEQ_OFFSET (0)
#define MSG_ID_OFFSET (1)

#define MSGID_BMS_STATUS (0x00)
#define MSGID_BMS_VBANK1 (0x01)
#define MSGID_BMS_VBANK2 (0x02)
#define MSGID_BMS_TEMP (0x03)

#define MSGID_LOG_ERROR (0x04)

#define BMS_VBAT (MSGID_BMS_STATUS | MSG_WORD | MSG_BYTE_0 | MSG_MILLI)
#define BMS_VTRG (MSGID_BMS_STATUS | MSG_WORD | MSG_BYTE_2 | MSG_MILLI)
#define BMS_IBAT (MSGID_BMS_STATUS | MSG_WORD | MSG_BYTE_4 | MSG_CENTI)
#define BMS_ITRG (MSGID_BMS_STATUS | MSG_WORD | MSG_BYTE_6 | MSG_CENTI)
#define BMS_CEL1 (MSGID_BMS_VBANK1 | MSG_WORD | MSG_BYTE_0 | MSG_MILLI)
#define BMS_CEL2 (MSGID_BMS_VBANK1 | MSG_WORD | MSG_BYTE_2 | MSG_MILLI)
#define BMS_CEL3 (MSGID_BMS_VBANK1 | MSG_WORD | MSG_BYTE_4 | MSG_MILLI)
#define BMS_CEL4 (MSGID_BMS_VBANK1 | MSG_WORD | MSG_BYTE_6 | MSG_MILLI)
#define BMS_CEL5 (MSGID_BMS_VBANK2 | MSG_WORD | MSG_BYTE_0 | MSG_MILLI)
#define BMS_CEL6 (MSGID_BMS_VBANK2 | MSG_WORD | MSG_BYTE_2 | MSG_MILLI)
#define BMS_CEL7 (MSGID_BMS_VBANK2 | MSG_WORD | MSG_BYTE_4 | MSG_MILLI)
#define BMS_CEL8 (MSGID_BMS_VBANK2 | MSG_WORD | MSG_BYTE_6 | MSG_MILLI)
#define BMS_VBAL (MSGID_BMS_TEMP | MSG_WORD | MSG_BYTE_0 | MSG_MILLI)
#define BMS_CHAH (MSGID_BMS_TEMP | MSG_WORD | MSG_BYTE_2 | MSG_CENTI)
#define BMS_BTC1 (MSGID_BMS_TEMP | MSG_BYTE | MSG_BYTE_4 | MSG_UNIT)
#define BMS_BTC2 (MSGID_BMS_TEMP | MSG_BYTE | MSG_BYTE_5 | MSG_UNIT)

#define LOG_ERROR (MSGID_LOG_ERROR | MSG_WORD | MSG_BYTE_0 | MSG_UNIT)

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
\
  {"LogE", LOG_ERROR },  \
}

#endif // MSG_SOLAR_H
