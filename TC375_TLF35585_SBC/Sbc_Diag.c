/*
 * SBC diagnostic and startup-state handling.
 * Map register fields only after checking the exact QUS01 datasheet.
 */
#include "Sbc_Diag.h"
#include "Sbc_Reg.h"

static uint32 Sbc_DiagErrorCounter = 0U;
static uint8 Sbc_DiagLastError = 0U;

Sbc_ReturnType Sbc_Diag_ReadStartupStatus(void)
{
    /*
     * TODO:
     * Read and preserve WWDSCMD, FWDSTAT0, device status and reset/fault flags.
     * Respect read-to-clear and clear-on-write semantics.
     */
    return SBC_RET_NOT_CONFIGURED;
}

Sbc_ReturnType Sbc_Diag_VerifyNormal(void)
{
    /*
     * TODO: read DEVSTAT and verify the actual NORMAL state.
     * A successful SPI transaction alone is not sufficient.
     */
    return SBC_RET_NOT_CONFIGURED;
}

void Sbc_Diag_MainFunction(void)
{
    /* TODO: periodic status/fault checks and DEM/Safety Manager reporting. */
}

void Sbc_Diag_ReportFatal(void)
{
    /* TODO: project-specific Dem/Safety Manager safe reaction. */
    if (Sbc_DiagErrorCounter < UINT32_MAX)
    {
        Sbc_DiagErrorCounter++;
    }
    (void)Sbc_DiagLastError;
}
