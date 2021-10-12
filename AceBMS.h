#ifndef ACEBMS_H
#define ACEBMS_H

#include "sig.h"

#define ACEBMS_BAUD (1200L)

#define ACEBMS_STATUS (0x01 | SIG_SIZE5)
#define ACEBMS_VBANK1 (0x11 | SIG_SIZE8)
#define ACEBMS_VBANK2 (0x21 | SIG_SIZE8)
#define ACEBMS_TEMPER (0x31 | SIG_SIZE8)

#define ACEBMS_VBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF0 | SIG_CENT)
#define ACEBMS_IBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF2 | SIG_DECI)
#define ACEBMS_RQST (ACEBMS_STATUS | SIG_BYTE | SIG_OFF4 | SIG_UNIT | SIG_UINT)

#define ACEBMS_CEL1 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL2 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL3 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL4 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF6 | SIG_MILL)

#define ACEBMS_CEL5 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL6 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL7 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL8 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF6 | SIG_MILL)

#define ACEBMS_VBAL (ACEBMS_TEMPER | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CHAH (ACEBMS_TEMPER | SIG_WORD | SIG_OFF2 | SIG_CENT)
#define ACEBMS_BTC1 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF4 | SIG_UNIT)
#define ACEBMS_BTC2 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF5 | SIG_UNIT)

#define ACEBMS_NAMES                 \
      {"bVb", ACEBMS_VBAT},     \
      {"bIb", ACEBMS_IBAT},     \
      {"bVc1", ACEBMS_CEL1},   \
      {"bVc2", ACEBMS_CEL2},   \
      {"bVc3", ACEBMS_CEL3},   \
      {"bVc4", ACEBMS_CEL4},   \
      {"bVc5", ACEBMS_CEL5},   \
      {"bVc6", ACEBMS_CEL6},   \
      {"bVc7", ACEBMS_CEL7},   \
      {"bVc8", ACEBMS_CEL8},   \
      {"bVcb", ACEBMS_VBAL},     \
      {"bAhr", ACEBMS_CHAH},     \
      {"bTc1", ACEBMS_BTC1},   \
      {"bTc2", ACEBMS_BTC2},   \
      {"bReq", ACEBMS_RQST}

#endif // ACEBMS_H
