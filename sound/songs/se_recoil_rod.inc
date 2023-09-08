.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_recoil_rod_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x36, 0xBE, 0x50, 0xBF, 0x40, 0xE7, 0x30, 0x7F, 0x98, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_recoil_rod:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x64
  .byte 0
  .4byte voicegroup000
  .4byte se_recoil_rod_mml+0

