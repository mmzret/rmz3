.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_electric_snakecord_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x3A, 0xBE, 0x39, 0xBF, 0x40, 0xD8, 0x37, 0x7F, 0x89, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_electric_snakecord:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x0A
  .byte 0
  .4byte voicegroup000
  .4byte se_electric_snakecord_mml+0

