.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_mission_voice_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x1C, 0xBE, 0x75, 0xBF, 0x40, 0xEF, 0x2E, 0x64, 0xA0, 0xB1, 0xBC, 0x00, 0xBD, 0x1E, 0xBE, 0x75, 0xBF, 0x40, 0xEF, 0x2E, 0x7F, 0xA0, 0xB1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_mission_voice:
  .byte	2	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x50
  .byte 0
  .4byte voicegroup000
  .4byte se_mission_voice_mml+0
  .4byte se_mission_voice_mml+15

