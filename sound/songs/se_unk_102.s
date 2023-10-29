.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_unk_102

se_unk_102_1:
  .byte 0xBC, 0x00, 0xBB, 0x27, 0xBD, 0x62, 0xBE, 0x6A, 0xCF, 0x2E, 0x7F, 0xB0, 0xB0, 0xB0
  .byte GOTO
  .word .-3
  .byte 0x98, 0xCE, 0x2E
  .byte FINE
  .byte 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

se_unk_102:
  .byte 1       @ NumTrks
  .byte 0       @ NumBlks
  .byte 100
  .byte 0
  .word voicegroup002
  .4byte se_unk_102_1+0

.end