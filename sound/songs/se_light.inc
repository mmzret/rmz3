.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_light_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x2F, 0xBE, 0x75, 0xBF, 0x40, 0xDA, 0x40, 0x7F, 0x8C, 0x40, 0x64, 0x8C, 0xDB, 0x40, 0x3C, 0x8C, 0x40, 0x14, 0x8C, 0xB1, 0x00, 0x00, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_light:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x50
  .byte 0
  .4byte voicegroup000
  .4byte se_light_mml+0

