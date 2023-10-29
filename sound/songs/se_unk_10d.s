	.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_unk_10d

se_unk_10d_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x6D, 0xBE, 0x4B, 0xBF, 0x40, 0xCF, 0x26, 0x7F, 0xB0, 0xB0
  .byte GOTO
  .word .-2
  .byte 0x86, 0xCE, 0x26
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

se_unk_10d:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 20
  .byte 0
  .4byte voicegroup002
  .4byte se_unk_10d_1

  .end

