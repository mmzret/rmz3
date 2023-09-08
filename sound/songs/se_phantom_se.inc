.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_phantom_se_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x60, 0xBE, 0x19, 0xBF, 0x40, 0xDB, 0x30, 0x7F, 0x8C, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_phantom_se:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_phantom_se_mml+0

