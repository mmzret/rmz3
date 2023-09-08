    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_no_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x03, 0xBE, 0x6B, 0xBF, 0x40, 0xEF, 0x3C, 0x7F, 0xA0, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_no:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x78
  .byte 0
  .4byte voicegroup000
  .4byte se_no_1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
