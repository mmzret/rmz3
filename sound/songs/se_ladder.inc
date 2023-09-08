    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_ladder_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x0D, 0xBE, 0x39, 0xBF, 0x40, 0xEF, 0x2A, 0x7F, 0xA0, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_ladder:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0xA
  .byte 0
  .4byte voicegroup000
  .4byte se_ladder_mml
