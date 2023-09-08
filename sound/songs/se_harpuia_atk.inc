.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_harpuia_atk_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x59, 0xBE, 0x76, 0xBF, 0x40, 0xEF, 0x2E, 0x7F, 0xA0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_harpuia_atk:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_harpuia_atk_mml+0

