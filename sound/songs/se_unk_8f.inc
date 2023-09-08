.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_unk_8f_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x34, 0xBE, 0x50, 0xBF, 0x40, 0xD5, 0x30, 0x7F, 0x86, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_8f:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_unk_8f_mml+0

