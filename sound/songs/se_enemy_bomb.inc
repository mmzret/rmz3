.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_enemy_bomb_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x2D, 0xBE, 0x76, 0xBF, 0x40, 0xE7, 0x30, 0x7F, 0x98, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_enemy_bomb:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_enemy_bomb_mml+0

