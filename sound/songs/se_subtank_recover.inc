.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_subtank_recover_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x1F, 0xBE, 0x61, 0xBF, 0x40, 0xDB, 0x33, 0x7F, 0x8C, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_subtank_recover:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x5A
  .byte 0
  .4byte voicegroup000
  .4byte se_subtank_recover_mml+0

