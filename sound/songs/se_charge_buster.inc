    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_charge_buster_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x1A, 0xBE, 0x64, 0xBF, 0x40, 0xF7, 0x30, 0x7F, 0xA8, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_charge_buster:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x50
  .byte 0
  .4byte voicegroup000
  .4byte se_charge_buster_mml
