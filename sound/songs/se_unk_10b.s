.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_unk_10b

se_unk_10b_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x6B, 0xBE, 0x32, 0xBF, 0x40, 0xCF, 0x2E, 0x7F, 0xB0, 0xB0
  .byte GOTO
  .word .-2
  .byte 0x98, 0xCE, 0x2E
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

se_unk_10b:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 20
  .byte 0
  .word voicegroup002
  .4byte se_unk_10b_1+0

.end

