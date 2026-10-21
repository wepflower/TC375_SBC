/*
 * Register/protocol layer.
 * IMPORTANT: Fill frame encoding/decoding only from the verified
 * TLF35585QUS01 datasheet revision. This template deliberately fails closed.
 */
#include "Sbc_Reg.h"
#include "Sbc_SpiIf.h"
#include "Sbc_Cfg.h"

#define SBC_FRAME_LENGTH 2U

static boolean Sbc_ProtocolConfigured(void)
{
    /* Set TRUE only after protocol implementation and review. */
    return FALSE;
}

static Sbc_ReturnType Sbc_EncodeRead(uint8 address, uint8 *tx)
{
    (void)address;
    (void)tx;
    if (Sbc_ProtocolConfigured() == FALSE)
    {
        return SBC_RET_NOT_CONFIGURED;
    }
    /* TODO: datasheet-verified READ opcode/address/parity/CRC encoding. */
    return SBC_RET_NOT_CONFIGURED;
}

static Sbc_ReturnType Sbc_EncodeWrite(uint8 address, uint8 value, uint8 *tx)
{
    (void)address;
    (void)value;
    (void)tx;
    if (Sbc_ProtocolConfigured() == FALSE)
    {
        return SBC_RET_NOT_CONFIGURED;
    }
    /* TODO: datasheet-verified WRITE opcode/address/data/parity/CRC encoding. */
    return SBC_RET_NOT_CONFIGURED;
}

static Sbc_ReturnType Sbc_DecodeResponse(const uint8 *rx,
                                         Sbc_RegResponseType *response)
{
    (void)rx;
    (void)response;
    /* TODO: validate response framing, device status and returned data. */
    return SBC_RET_NOT_CONFIGURED;
}

Sbc_ReturnType Sbc_Reg_Read(uint8 address, Sbc_RegResponseType *response)
{
    uint8 tx[SBC_FRAME_LENGTH] = {0U, 0U};
    uint8 rx[SBC_FRAME_LENGTH] = {0U, 0U};
    Sbc_ReturnType ret;

    if (response == NULL_PTR)
    {
        return SBC_RET_PARAM;
    }

    ret = Sbc_EncodeRead(address, tx);
    if (ret != SBC_RET_OK)
    {
        return ret;
    }

    if (Sbc_SpiIf_Transfer(tx, rx, SBC_FRAME_LENGTH) != E_OK)
    {
        return SBC_RET_SPI;
    }

    return Sbc_DecodeResponse(rx, response);
}

Sbc_ReturnType Sbc_Reg_Write(uint8 address, uint8 value,
                             Sbc_RegResponseType *response)
{
    uint8 tx[SBC_FRAME_LENGTH] = {0U, 0U};
    uint8 rx[SBC_FRAME_LENGTH] = {0U, 0U};
    Sbc_ReturnType ret;

    if (response == NULL_PTR)
    {
        return SBC_RET_PARAM;
    }

    ret = Sbc_EncodeWrite(address, value, tx);
    if (ret != SBC_RET_OK)
    {
        return ret;
    }

    if (Sbc_SpiIf_Transfer(tx, rx, SBC_FRAME_LENGTH) != E_OK)
    {
        return SBC_RET_SPI;
    }

    return Sbc_DecodeResponse(rx, response);
}
