TC375 + TLF35585QUS01 AUTOSAR Classic SBC source template

Files:
  Sbc.c, Sbc_Reg.c, Sbc_Wdg.c, Sbc_Diag.c, Sbc_SpiIf.c
  matching headers and configuration stubs

IMPORTANT:
- This is a structured integration template, NOT a complete production-ready driver.
- Chip-specific SPI encoding/decoding, register addresses/bitfields, protected writes,
  WWD commands and FWD question-answer algorithm intentionally fail closed.
- Do not use on a vehicle or safety target until populated from the exact
  TLF35585QUS01 datasheet revision, reviewed, integrated with generated MCAL/SchM,
  and verified on hardware.
- Replace placeholder SPI channel/sequence and SchM exclusive-area macros.
- The SPI frame length and buffer conventions must be checked against the device
  datasheet and your MCAL implementation.
