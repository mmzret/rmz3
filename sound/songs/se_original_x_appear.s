	.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_original_x_appear

se_original_x_appear_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x78, 0xBE, 0x7F, 0xBF, 0x40, 0xCF, 0x26, 0x7F, 0xB0, 0xB0, 0xB0, 0xB0
  .byte GOTO
  .word .-4
  .byte 0xB0, 0xCE, 0x26
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0
se_original_x_appear:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_original_x_appear_1

  .end
