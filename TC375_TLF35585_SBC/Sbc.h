#ifndef SBC_H
#define SBC_H
#include "Std_Types.h"
#include "Sbc_Reg.h"
typedef enum {
    SBC_STATE_UNINIT = 0U, SBC_STATE_READ_STATUS, SBC_STATE_CONFIGURE,
    SBC_STATE_FIRST_WDG_SERVICE, SBC_STATE_REQUEST_NORMAL,
    SBC_STATE_VERIFY_NORMAL, SBC_STATE_NORMAL, SBC_STATE_FAULT
} Sbc_StateType;
void Sbc_Init(void);
void Sbc_MainFunction(void);
Sbc_StateType Sbc_GetState(void);
Sbc_ReturnType Sbc_RequestNormal(void);
#endif
