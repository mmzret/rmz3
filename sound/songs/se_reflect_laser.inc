    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_reflect_laser_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x12, 0xBE, 0x6E, 0xBF, 0x40, 0xF7, 0x36, 0x7F, 0xA8, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_reflect_laser:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_reflect_laser_mml

