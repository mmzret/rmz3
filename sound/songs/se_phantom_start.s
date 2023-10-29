.include "MPlayDef.s"

.section .rodata
.balign 4, 0
.global se_phantom_start

se_phantom_start_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x5A, 0xBE, 0x75, 0xEF, 0x2D, 0x64, 0xA0, 0xBD, 0x65, 0xEF, 0x2D, 0x7F, 0xA0
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.balign 4, 0

se_phantom_start:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 80
  .byte 0
  .word voicegroup002
  .4byte se_phantom_start_1+0

.end

