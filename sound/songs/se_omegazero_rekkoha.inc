.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_omegazero_rekkoha_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x50, 0xBE, 0x5C, 0xBF, 0x40, 0xFF, 0x2E, 0x7F, 0xB0, 0xB1, 0xBC, 0x00, 0xBD, 0x00, 0xBE, 0x0E, 0xBF, 0x40, 0xCF, 0x2C, 0x7F, 0x86, 0xBE, 0x5C, 0x86, 0x5A, 0x86, 0x59, 0x86, 0x54, 0x86, 0x4F, 0x86, 0x4B, 0x86, 0x45, 0x86, 0x3F, 0x86, 0x3B, 0x86, 0x35, 0x86, 0x2F, 0x86, 0x29, 0x8C, 0x1F, 0x8C, 0x15, 0x8C, 0x0E, 0x8C, 0x0B, 0x8C, 0x07, 0x8C, 0x03, 0x86, 0x00, 0x9A, 0xCE, 0xB1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_omegazero_rekkoha:
  .byte	2	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup002
  .4byte se_omegazero_rekkoha_mml+0
  .4byte se_omegazero_rekkoha_mml+15
