#ifndef SBC_SPIIF_H
#define SBC_SPIIF_H
#include "Std_Types.h"
#include "Spi.h"
Std_ReturnType Sbc_SpiIf_Init(void);
Std_ReturnType Sbc_SpiIf_Transfer(const uint8 *tx, uint8 *rx,
                                  Spi_NumberOfDataType length);
#endif
