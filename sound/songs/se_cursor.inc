    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_cursor_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x01, 0xBE, 0x6B, 0xBF, 0x40, 0xD4, 0x2A, 0x7F, 0x86, 0x2A, 0x40, 0x85, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_cursor:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x78
  .byte 0
  .4byte voicegroup000
  .4byte se_cursor_1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
