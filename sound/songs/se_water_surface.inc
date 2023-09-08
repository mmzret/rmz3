    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

se_water_surface_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x0F, 0xBE, 0x66, 0xBF, 0x40, 0xEF, 0x2F, 0x7F, 0xA0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_water_surface:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0x32
  .byte 0
  .4byte voicegroup000
  .4byte se_water_surface_mml

