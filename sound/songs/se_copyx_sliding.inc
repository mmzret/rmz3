.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_copyx_sliding_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x4C, 0xBE, 0x57, 0xBF, 0x40, 0xE1, 0x32, 0x7F, 0x92, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_copyx_sliding:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_copyx_sliding_mml+0

