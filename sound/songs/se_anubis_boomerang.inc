.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_anubis_boomerang_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x54, 0xBE, 0x61, 0xBF, 0x40, 0xD5, 0x35, 0x7F, 0x86, 0x36, 0x5C, 0x86, 0x37, 0x3C, 0x86, 0x37, 0x34, 0x86, 0xD5, 0x36, 0x3C, 0x86, 0x36, 0x34, 0x86, 0xB2, 0x0F, 0x48, 0x32, 0x08, 0xB1

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_anubis_boomerang:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x14
  .byte 0
  .4byte voicegroup000
  .4byte se_anubis_boomerang_mml+0
