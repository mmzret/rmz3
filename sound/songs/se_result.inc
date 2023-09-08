.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_result_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x34, 0xBE, 0x64, 0xBF, 0x40, 0xD4, 0x36, 0x7F, 0x85, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_result:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x78
  .byte 0
  .4byte voicegroup000
  .4byte se_result_mml+0

