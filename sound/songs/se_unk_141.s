	.include "MPlayDef.s"

.section .rodata
.balign 4
.global	se_unk_141

se_unk_141_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x6A, 0xBE, 0x59, 0xEF, 0x1D, 0x7F, 0xA0, 0xEF, 0x1D, 0x7F, 0xA0
  .byte GOTO
  .word .-5
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4
se_unk_141:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0xDC
  .byte 0
  .4byte voicegroup002
  .4byte se_unk_141_1

  .end
