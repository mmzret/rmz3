.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_phantom_zan_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x5B, 0xBE, 0x75, 0xBF, 0x40, 0xEF, 0x2E, 0x7F, 0xA0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_phantom_zan:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_phantom_zan_mml+0

