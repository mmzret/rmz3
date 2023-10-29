.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_phantom_zan

se_phantom_zan_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x5B, 0xBE, 0x75, 0xBF, 0x40, 0xEF, 0x2E, 0x7F, 0xA0
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

se_phantom_zan:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 20
  .byte 0
  .word voicegroup002
  .4byte se_phantom_zan_1+0

.end

