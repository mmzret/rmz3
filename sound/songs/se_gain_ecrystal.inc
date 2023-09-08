.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_gain_ecrystal_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x22, 0xBE, 0x41, 0xBF, 0x40, 0xEF, 0x3C, 0x7F, 0xA0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_gain_ecrystal:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x5A
  .byte 0
  .4byte voicegroup000
  .4byte se_gain_ecrystal_mml+0

