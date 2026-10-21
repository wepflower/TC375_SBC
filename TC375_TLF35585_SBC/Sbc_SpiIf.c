/*
 * TC375 + TLF35585QUS01 AUTOSAR Classic SPI adapter template.
 * Integrate with the project's generated MCAL Spi configuration.
 * Verify the exact MCAL API signatures and SPI frame timing before use.
 */
#include "Sbc_SpiIf.h"
#include "Sbc_Spi_Cfg.h"
#include "SchM_Sbc.h"

Std_ReturnType Sbc_SpiIf_Init(void)
{
    /* Spi_Init() should normally be called by EcuM/MCAL startup. */
    return E_OK;
}

Std_ReturnType Sbc_SpiIf_Transfer(
    const uint8 *tx,
    uint8 *rx,
    Spi_NumberOfDataType length)
{
    Std_ReturnType result = E_NOT_OK;

    if ((tx == NULL_PTR) || (rx == NULL_PTR) || (length == 0U))
    {
        return E_NOT_OK;
    }

    SchM_Enter_Sbc_SPI_EXCLUSIVE_AREA();

    if (Spi_SetupEB(SBC_SPI_CHANNEL,
                    (Spi_DataBufferType *)tx,
                    rx,
                    length) == E_OK)
    {
        if (Spi_SyncTransmit(SBC_SPI_SEQUENCE) == E_OK)
        {
            result = E_OK;
        }
    }

    SchM_Exit_Sbc_SPI_EXCLUSIVE_AREA();
    return result;
}
