    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_walljump_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x0C, 0xBE, 0x46, 0xBF, 0x40, 0xDB, 0x30, 0x7F, 0x8C, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_walljump:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x5
  .byte 0
  .4byte voicegroup000
  .4byte se_walljump_mml
