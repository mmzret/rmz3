    .include "asm/macros.inc"

    .section .rodata
    .balign 4, 0

se_zero_death_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x0B, 0xBE, 0x7F, 0xBF, 0x40, 0xCF, 0x2D, 0x7F, 0xB0, 0xB0, 0xCE, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_zero_death:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x64
  .byte 0
  .4byte voicegroup000
  .4byte se_zero_death_mml
