#ifndef SBC_REG_H
#define SBC_REG_H
#include "Std_Types.h"
typedef enum {
    SBC_RET_OK = 0U, SBC_RET_PARAM, SBC_RET_SPI, SBC_RET_PROTOCOL,
    SBC_RET_VERIFY, SBC_RET_STATE, SBC_RET_TIMEOUT, SBC_RET_NOT_CONFIGURED
} Sbc_ReturnType;
typedef struct {
    uint16 rawResponse;
    uint16 registerValue;
    uint8 deviceStatus;
} Sbc_RegResponseType;
Sbc_ReturnType Sbc_Reg_Read(uint8 address, Sbc_RegResponseType *response);
Sbc_ReturnType Sbc_Reg_Write(uint8 address, uint8 value,
                             Sbc_RegResponseType *response);
#endif
