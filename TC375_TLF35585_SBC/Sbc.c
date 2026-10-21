/*
 * SBC manager state machine for TC375 + TLF35585QUS01.
 * State transitions are guarded; chip-specific operations must be implemented.
 */
#include "Sbc.h"
#include "Sbc_Wdg.h"
#include "Sbc_Diag.h"

static Sbc_StateType Sbc_State = SBC_STATE_UNINIT;
static uint32 Sbc_StateTicks = 0U;

void Sbc_Init(void)
{
    Sbc_StateTicks = 0U;
    Sbc_State = SBC_STATE_READ_STATUS;
}

Sbc_StateType Sbc_GetState(void)
{
    return Sbc_State;
}

static void Sbc_SetFault(void)
{
    Sbc_State = SBC_STATE_FAULT;
    Sbc_Diag_ReportFatal();
}

void Sbc_MainFunction(void)
{
    Sbc_ReturnType ret;

    if (Sbc_StateTicks < UINT32_MAX)
    {
        Sbc_StateTicks++;
    }

    switch (Sbc_State)
    {
        case SBC_STATE_READ_STATUS:
            ret = Sbc_Diag_ReadStartupStatus();
            if (ret == SBC_RET_OK)
                Sbc_State = SBC_STATE_CONFIGURE;
            else
                Sbc_SetFault();
            break;

        case SBC_STATE_CONFIGURE:
            ret = Sbc_Wdg_Configure();
            if (ret == SBC_RET_OK)
                Sbc_State = SBC_STATE_FIRST_WDG_SERVICE;
            else
                Sbc_SetFault();
            break;

        case SBC_STATE_FIRST_WDG_SERVICE:
            ret = Sbc_Wdg_FirstService();
            if (ret == SBC_RET_OK)
                Sbc_State = SBC_STATE_REQUEST_NORMAL;
            else
                Sbc_SetFault();
            break;

        case SBC_STATE_REQUEST_NORMAL:
            ret = Sbc_RequestNormal();
            if (ret == SBC_RET_OK)
                Sbc_State = SBC_STATE_VERIFY_NORMAL;
            else
                Sbc_SetFault();
            break;

        case SBC_STATE_VERIFY_NORMAL:
            ret = Sbc_Diag_VerifyNormal();
            if (ret == SBC_RET_OK)
                Sbc_State = SBC_STATE_NORMAL;
            else
                Sbc_SetFault();
            break;

        case SBC_STATE_NORMAL:
            Sbc_Wdg_MainFunction();
            Sbc_Diag_MainFunction();
            break;

        case SBC_STATE_FAULT:
        case SBC_STATE_UNINIT:
        default:
            /* Remain in safe/fault state; no blind retry. */
            break;
    }
}

/*
 * Implement with the QUS01 datasheet's DEVCTRL/DEVCTRLN semantics,
 * protected-write sequence and status verification.
 */
Sbc_ReturnType Sbc_RequestNormal(void)
{
    return SBC_RET_NOT_CONFIGURED;
}
