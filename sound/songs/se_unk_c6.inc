.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_unk_c6_mml:
  .byte 0xBC, 0x00, 0xBB, 0x27, 0xBD, 0x76, 0xBE, 0x1C, 0xBF, 0x40, 0xCF, 0x2A, 0x7F, 0xB0, 0xB0, 0xB0, 0xB2, 0xBE, 0x6A, 0x33, 0x08, 0xA0, 0xCE, 0x2A, 0xB1, 0x00, 0x00, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_c6:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x64
  .byte 0
  .4byte voicegroup001
  .4byte se_unk_c6_mml+0

