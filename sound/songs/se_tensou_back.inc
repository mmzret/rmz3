.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_tensou_back_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x37, 0xBE, 0x64, 0xBF, 0x40, 0xF7, 0x2D, 0x7F, 0xA8, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_tensou_back:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_tensou_back_mml+0

