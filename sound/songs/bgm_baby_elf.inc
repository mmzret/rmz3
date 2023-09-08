.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

bgm_baby_elf_mml:
  .byte 0xBC, 0x00, 0xBB, 0x2D, 0xBD, 0x0E, 0xBE, 0x46, 0xD8, 0x37, 0x54, 0x8C, 0x31, 0x3C, 0x8C, 0x37, 0x54, 0x8C, 0x3D, 0x44, 0x8C, 0x3C, 0x38, 0x8C, 0x37, 0x4C, 0x8C, 0xD8, 0x37, 0x58, 0x8C, 0x31, 0x38, 0x8C, 0x37, 0x54, 0x8C, 0x3D, 0x4C, 0x8C, 0x3C, 0x44, 0x8C, 0x37, 0x48, 0x8C, 0xB4, 0xD8, 0x36, 0x50, 0x8C, 0x31, 0x38, 0x8C, 0x36, 0x48, 0x8C, 0x3C, 0x44, 0x8C, 0x3A, 0x8C, 0x36, 0x40, 0x8C, 0xB4, 0xD8, 0x36, 0x50, 0x8C, 0x31, 0x3C, 0x8C, 0x36, 0x44, 0x8C, 0x3C, 0x2C, 0x8C, 0x3B, 0x40, 0x8C, 0x36, 0x8C, 0xB4, 0xD8, 0x37, 0x54, 0x8C, 0x31, 0x3C, 0x8C, 0x37, 0x54, 0x8C, 0x3D, 0x44, 0x8C, 0x3C, 0x38, 0x8C, 0x37, 0x4C, 0x8C, 0xB4, 0xB3, 0xE7, 0x6E, 0x32, 0x08, 0xB3, 0xFB, 0x6E, 0x32, 0x08, 0xB3, 0x0E, 0x6F, 0x32, 0x08, 0xB3, 0x21, 0x6F, 0x32, 0x08, 0xB3, 0xE7, 0x6E, 0x32, 0x08, 0xB3, 0xFB, 0x6E, 0x32, 0x08, 0xB3, 0x0E, 0x6F, 0x32, 0x08, 0xB2, 0xCE, 0x6E, 0x32, 0x08, 0xB1, 0xBC, 0x00, 0xBD, 0x0C, 0xBE, 0x5A, 0xA8, 0xA8, 0xA8, 0xA8, 0xEB, 0x37, 0x50, 0x9C, 0x43, 0x58, 0x9C, 0xF7, 0x42, 0x4C, 0xA8, 0xEB, 0x36, 0x58, 0x9C, 0x42, 0x60, 0x9C, 0xE7, 0x41, 0x54, 0x98, 0xDB, 0x40, 0x5C, 0x8C, 0xEB, 0x3F, 0x58, 0x9C, 0x37, 0x64, 0x9C, 0x43, 0x68, 0x9C, 0xF7, 0x42, 0x5C, 0xA8, 0xEB, 0x36, 0x54, 0x9C, 0x42, 0x58, 0x9C, 0xE7, 0x41, 0x98, 0xDB, 0x40, 0x5C, 0x8C, 0xEB, 0x3F, 0x68, 0x9C, 0xB2, 0x60, 0x6F, 0x32, 0x08, 0xB1, 0xBC, 0x00, 0xBD, 0x1D, 0xBE, 0x5A, 0xCF, 0x35, 0x7F, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xCF, 0x34, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xCF, 0x35, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xCF, 0x34, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xCF, 0x35, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xCF, 0x34, 0xA8, 0xA7, 0x83, 0xCE, 0x81, 0xB2, 0xAA, 0x6F, 0x32, 0x08, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

bgm_baby_elf:
  .byte	3	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0xDC
  .byte 153
  .4byte voicegroup001
  .4byte bgm_baby_elf_mml+0
  .4byte bgm_baby_elf_mml+146
  .4byte bgm_baby_elf_mml+220
