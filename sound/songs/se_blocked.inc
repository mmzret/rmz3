.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_blocked_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x2B, 0xBE, 0x61, 0xBF, 0x40, 0xE7, 0x30, 0x7F, 0x98, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_blocked:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x32
  .byte 0
  .4byte voicegroup000
  .4byte se_blocked_mml+0

