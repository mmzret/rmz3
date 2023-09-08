.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_copyx_recover_voice_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x4A, 0xBE, 0x78, 0xBF, 0x40, 0xEF, 0x2E, 0x7F, 0xA0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_copyx_recover_voice:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_copyx_recover_voice_mml+0

