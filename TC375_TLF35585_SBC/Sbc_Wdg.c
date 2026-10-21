/*
 * WWD/FWD services.
 * No watchdog command values or answer algorithms are guessed here.
 */
#include "Sbc_Wdg.h"
#include "Sbc_Reg.h"
#include "Sbc_Cfg.h"

static boolean Sbc_WdgConfigured = FALSE;

Sbc_ReturnType Sbc_Wdg_Configure(void)
{
    Sbc_WdgConfigured = FALSE;

    /*
     * TODO, per verified QUS01 datasheet and system safety timing:
     * - configure relevant safety/system registers
     * - configure WWD window and service mechanism
     * - configure FWD timing and question/answer response
     * - read back/verify all writable configuration
     */
    return SBC_RET_NOT_CONFIGURED;
}

Sbc_ReturnType Sbc_Wdg_FirstService(void)
{
    if (Sbc_WdgConfigured == FALSE)
    {
        return SBC_RET_NOT_CONFIGURED;
    }

    /* TODO: first WWD/FWD service based on the actual startup status. */
    return SBC_RET_NOT_CONFIGURED;
}

void Sbc_Wdg_MainFunction(void)
{
    if (Sbc_WdgConfigured == FALSE)
    {
        return;
    }

    /*
     * Recommended sequence:
     * 1. Verify application/safety-task health.
     * 2. Read watchdog state when permitted by timing.
     * 3. Generate the correct WWD command and FWD answer.
     * 4. Serialize SPI access and verify device response.
     * 5. Report a missed window/invalid answer as a safety fault.
     */
}
