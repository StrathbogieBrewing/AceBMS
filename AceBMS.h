#ifndef ACEBMS_H
#define ACEBMS_H

#include "sig.h"

#define ACEBMS_STATUS (SIG_PRIORITY_MEDIUM | 0x00)
#define ACEBMS_VBANK1 (SIG_PRIORITY_MEDIUM | 0x10)
#define ACEBMS_VBANK2 (SIG_PRIORITY_MEDIUM | 0x20)
#define ACEBMS_TEMPER (SIG_PRIORITY_MEDIUM | 0x30)

#define ACEBMS_VBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_VTRG (ACEBMS_STATUS | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_IBAT (ACEBMS_STATUS | SIG_WORD | SIG_OFF4 | SIG_CENT)
#define ACEBMS_ITRG (ACEBMS_STATUS | SIG_BYTE | SIG_OFF6 | SIG_UNIT)
#define ACEBMS_RQST (ACEBMS_STATUS | SIG_BYTE | SIG_OFF7 | SIG_UNIT | SIG_UINT)
#define ACEBMS_CEL1 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL2 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL3 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL4 (ACEBMS_VBANK1 | SIG_WORD | SIG_OFF6 | SIG_MILL)
#define ACEBMS_CEL5 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CEL6 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_CEL7 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF4 | SIG_MILL)
#define ACEBMS_CEL8 (ACEBMS_VBANK2 | SIG_WORD | SIG_OFF6 | SIG_MILL)
#define ACEBMS_VBAL (ACEBMS_TEMPER | SIG_WORD | SIG_OFF0 | SIG_MILL)
#define ACEBMS_CHAH (ACEBMS_TEMPER | SIG_WORD | SIG_OFF2 | SIG_MILL)
#define ACEBMS_BTC1 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF4 | SIG_UNIT)
#define ACEBMS_BTC2 (ACEBMS_TEMPER | SIG_BYTE | SIG_OFF5 | SIG_UNIT)

#define ACEBMS_NAMES  {"Vbat", ACEBMS_VBAT},  \
                      {"Vtrg", ACEBMS_VTRG},  \
                      {"Ibat", ACEBMS_IBAT},  \
                      {"Itrg", ACEBMS_ITRG},  \
                      {"Req", ACEBMS_RQST},   \
                      {"Vc1", ACEBMS_CEL1},   \
                      {"Vc2", ACEBMS_CEL2},   \
                      {"Vc3", ACEBMS_CEL3},   \
                      {"Vc4", ACEBMS_CEL4},   \
                      {"Vc5", ACEBMS_CEL5},   \
                      {"Vc6", ACEBMS_CEL6},   \
                      {"Vc7", ACEBMS_CEL7},   \
                      {"Vc8", ACEBMS_CEL8},   \
                      {"Vbal", ACEBMS_VBAL},  \
                      {"ChAh", ACEBMS_CHAH},  \
                      {"BTc1", ACEBMS_BTC1},  \
                      {"BTc2", ACEBMS_BTC2}   

#endif // ACEBMS_H
