#ifndef SBC_DIAG_H
#define SBC_DIAG_H
#include "Sbc_Reg.h"
Sbc_ReturnType Sbc_Diag_ReadStartupStatus(void);
Sbc_ReturnType Sbc_Diag_VerifyNormal(void);
void Sbc_Diag_MainFunction(void);
void Sbc_Diag_ReportFatal(void);
#endif
