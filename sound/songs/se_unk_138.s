.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0
.global se_unk_138

se_unk_138_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x11, 0xBE, 0x44, 0xBF, 0x40, 0xD5, 0x4D, 0x7F, 0x86, 0xD5, 0x86, 0x4D, 0x48, 0x86, 0xB1, 0xBC, 0x00, 0xBD, 0x24, 0xBE, 0x44, 0xBF, 0x40, 0xD5, 0x41, 0x7F, 0x86, 0xD5, 0x86, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_unk_138:
  .byte	2	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x5A
  .byte 0
  .4byte voicegroup001
  .4byte se_unk_138_mml+0
  .4byte se_unk_138_mml+20

  .end