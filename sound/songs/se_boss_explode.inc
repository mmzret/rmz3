.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_boss_explode_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x2F, 0xBE, 0x7F, 0xBF, 0x40, 0x86, 0xF7, 0x30, 0x7F, 0xAE, 0xBD, 0x30, 0xCF, 0x2A, 0xCF, 0x30, 0x86, 0x27, 0xAE, 0xA4, 0xCE, 0x2A, 0x30, 0x86, 0x27, 0xB1, 0xBC, 0x00, 0xBD, 0x00, 0xBE, 0x14, 0xBF, 0x40, 0xCF, 0x2C, 0x7F, 0x86, 0xBE, 0x7F, 0x86, 0x7D, 0x86, 0x7B, 0x86, 0x75, 0x86, 0x6E, 0x86, 0x68, 0x86, 0x60, 0x86, 0x58, 0x86, 0x52, 0x86, 0x4A, 0x86, 0x42, 0x86, 0x39, 0x8C, 0x2B, 0x8C, 0x1E, 0x8C, 0x14, 0x8C, 0x10, 0x8C, 0x0A, 0x8C, 0x05, 0x86, 0x00, 0x9E, 0xA4, 0xCE, 0xB1, 0x00, 0x00, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_boss_explode:
  .byte	2	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x50
  .byte 0
  .4byte voicegroup000
  .4byte se_boss_explode_mml+0
  .4byte se_boss_explode_mml+31
