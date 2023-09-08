    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_dash_2_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x09, 0xBE, 0x25, 0xBF, 0x40, 0xE7, 0x3C, 0x7F, 0x98, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_dash_2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 5
  .byte 0
  .4byte voicegroup000
  .4byte se_dash_2_mml
