.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_unk_e0_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x6B, 0xBE, 0x4D, 0xBF, 0x40, 0xCF, 0x22, 0x7F, 0xB0, 0xB0, 0xB2, 0xDA, 0x71, 0x33, 0x08, 0x98, 0xCE, 0x22, 0xB1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_e0:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_unk_e0_mml+0

