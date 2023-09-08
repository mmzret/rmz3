    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_not_allowed_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x04, 0xBE, 0x78, 0xBF, 0x40, 0xE1, 0x2B, 0x7F, 0x92, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_not_allowed:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x78
  .byte 0
  .4byte voicegroup000
  .4byte se_not_allowed_mml

