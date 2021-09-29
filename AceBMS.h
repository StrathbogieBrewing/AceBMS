#ifndef ACEBMS_H
#define ACEBMS_H

#include "sig.h"

#define ACEBMS_STATUS (SIG_PRIORITY_MEDIUM | 0x00)
#define ACEBMS_VBANK1 (SIG_PRIORITY_MEDIUM | 0x10)
#define ACEBMS_VBANK2 (SIG_PRIORITY_MEDIUM | 0x20)
#define ACEBMS_TEMPER (SIG_PRIORITY_MEDIUM | 0x30)

#define ACEBMS_VBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF0 | SIG_CENT)
#define ACEBMS_VCHI (ACEBMS_STATUS | SIG_BYTE | SIG_OFF2 | SIG_CENT | SIG_UINT)
#define ACEBMS_VCLO (ACEBMS_STATUS | SIG_BYTE | SIG_OFF3 | SIG_CENT | SIG_UINT)
#define ACEBMS_IBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF4 | SIG_DECI)
#define ACEBMS_RQST (ACEBMS_STATUS | SIG_WORD | SIG_OFF6 | SIG_UNIT | SIG_UINT)

#define ACEBMS_CEL1 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL2 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL3 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL4 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF6 | SIG_MILL)

#define ACEBMS_CEL5 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL6 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL7 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL8 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF6 | SIG_MILL)

#define ACEBMS_VBAL (ACEBMS_TEMPER | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CHAH (ACEBMS_TEMPER | SIG_WORD | SIG_OFF2 | SIG_DECI)
#define ACEBMS_BTC1 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF4 | SIG_UNIT)
#define ACEBMS_BTC2 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF5 | SIG_UNIT)

#define ACEBMS_NAMES  {"bms/vbat", ACEBMS_VBAT},  \
                      {"bms/vchi", ACEBMS_VCHI},  \
                      {"bms/vclo", ACEBMS_VCLO},  \
                      {"bms/ibat", ACEBMS_IBAT},  \
                      {"bms/vcel/1", ACEBMS_CEL1},   \
                      {"bms/vcel/2", ACEBMS_CEL2},   \
                      {"bms/vcel/3", ACEBMS_CEL3},   \
                      {"bms/vcel/4", ACEBMS_CEL4},   \
                      {"bms/vcel/5", ACEBMS_CEL5},   \
                      {"bms/vcel/6", ACEBMS_CEL6},   \
                      {"bms/vcel/7", ACEBMS_CEL7},   \
                      {"bms/vcel/8", ACEBMS_CEL8},   \
                      {"bms/vbal", ACEBMS_VBAL},  \
                      {"bms/chah", ACEBMS_CHAH},  \
                      {"bms/temp/1", ACEBMS_BTC1},  \
                      {"bms/temp/2", ACEBMS_BTC2},  \
                      {"bms/req", ACEBMS_RQST}

#endif // ACEBMS_H
