.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_unk_124

se_unk_124_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x3A, 0xBE, 0x46, 0xBF, 0x40, 0xCF, 0x34, 0x7F, 0xB0, 0xB0
  .byte GOTO
  .word .-2
  .byte 0x86, 0xCE, 0x34
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_124:
  .byte 1       @ NumTrks
  .byte 0       @ NumBlks
  .byte 0x14
  .byte 0
  .word voicegroup000
  .4byte se_unk_124_1

.end
