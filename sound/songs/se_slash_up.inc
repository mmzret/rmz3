    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_slash_up_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x15, 0xBE, 0x52, 0xBF, 0x40, 0xC0, 0x4F, 0xE7, 0x32, 0x7F, 0x98, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_slash_up:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x64
  .byte 0
  .4byte voicegroup000
  .4byte se_slash_up_mml

