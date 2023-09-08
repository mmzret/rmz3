.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

.equ se_eruption_mml, se_eruption-16
@ se_eruption_mml:
@   .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x78, 0xBE, 0x78, 0xBF, 0x40, 0xFF, 0x2C, 0x7F, 0xB0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_eruption:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_eruption_mml+0

