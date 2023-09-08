.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_unk_e2_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x41, 0xBE, 0x3C, 0xBF, 0x40, 0xF7, 0x2B, 0x7F, 0xA8, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_e2:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x0A
  .byte 0
  .4byte voicegroup000
  .4byte se_unk_e2_mml+0

