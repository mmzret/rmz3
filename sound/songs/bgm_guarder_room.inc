    .include "asm/macros.inc"
     

    .section .rodata
    .balign 4, 0

bgm_guarder_room_mml:
  .byte 0xBC, 0x00, 0xBB, 0x37, 0xBD, 0x0B, 0xBE, 0x30, 0xBF, 0x3C, 0xD9, 0x37, 0x44, 0x8C, 0x31, 0x8C, 0x2A, 0x28, 0x8C, 0x31, 0x50, 0x8C, 0x37, 0x44, 0x8C, 0x31, 0x48, 0x8C, 0x2A, 0x3C, 0x8C, 0x31, 0x44, 0x8C, 0xD9, 0x37, 0x40, 0x8C, 0x31, 0x8C, 0x2A, 0x34, 0x8C, 0x31, 0x44, 0x8C, 0x37, 0x8C, 0x31, 0x8C, 0x2A, 0x38, 0x8C, 0x31, 0x3C, 0x8C, 0xB4, 0xD9, 0x38, 0x34, 0x8C, 0x32, 0x50, 0x8C, 0x2B, 0x2C, 0x8C, 0x32, 0x4C, 0x8C, 0x38, 0x8C, 0x32, 0x8C, 0x2B, 0x3C, 0x8C, 0x32, 0x50, 0x8C, 0xB4, 0xD9, 0x38, 0x4C, 0x8C, 0x32, 0x8C, 0x2B, 0x40, 0x8C, 0x32, 0x4C, 0x8C, 0x38, 0x44, 0x8C, 0x32, 0x50, 0x8C, 0x2B, 0x3C, 0x8C, 0x32, 0x4C, 0x8C, 0xB4, 0x37, 0x44, 0x8C, 0x31, 0x8C, 0x2A, 0x28, 0x8C, 0x31, 0x50, 0x8C, 0x37, 0x44, 0x8C, 0x31, 0x48, 0x8C, 0x2A, 0x3C, 0x8C, 0x31, 0x44, 0x8C, 0xB3, 0x92, 0x50, 0x32, 0x08, 0xB3, 0xA9, 0x50, 0x32, 0x08, 0xB3, 0xC1, 0x50, 0x32, 0x08, 0xB2, 0x72, 0x50, 0x32, 0x08, 0xB1, 0xBC, 0x00, 0xBD, 0x0C, 0xBE, 0x53, 0xBF, 0x28, 0xCF, 0x24, 0x78, 0xB0, 0xAF, 0x83, 0xCE, 0x81, 0xCF, 0x23, 0xB0, 0xAF, 0x83, 0xCE, 0x81, 0xCF, 0x24, 0xB0, 0xAF, 0x83, 0xCE, 0x81, 0xCF, 0x23, 0xB0, 0xAF, 0x83, 0xCE, 0x81, 0xB2, 0x08, 0x51, 0x32, 0x08, 0xB1, 0xBC, 0x00, 0xBD, 0x0A, 0xBE, 0x37, 0xBF, 0x57, 0xCF, 0x1F, 0x64, 0xCF, 0x24, 0xB0, 0xAF, 0x83, 0xCE, 0x1F, 0x24, 0x81, 0xCF, 0x20, 0x64, 0xCF, 0x25, 0xB0, 0xB4, 0xAF, 0x83, 0xCE, 0x20, 0x25, 0x81, 0xCF, 0x1F, 0xCF, 0x24, 0xB0, 0xAF, 0x83, 0xCE, 0x1F, 0x24, 0x81, 0xB3, 0x45, 0x51, 0x32, 0x08, 0xAF, 0x83, 0xCE, 0x20, 0x25, 0x81, 0xB2, 0x33, 0x51, 0x32, 0x08, 0xB1
  .balign 4, 0

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

bgm_guarder_room:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
  .byte 0xDC
  .byte 0x99
  .4byte voicegroup001
  .4byte bgm_guarder_room_mml
  .4byte bgm_guarder_room_mml+150
  .4byte bgm_guarder_room_mml+150+43
