.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0

se_charge_recoil_mml:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x37, 0xBE, 0x5A, 0xBF, 0x40, 0xFB, 0x2E, 0x7F, 0xAC, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_charge_recoil:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0x64
  .byte 0
  .4byte voicegroup000
  .4byte se_charge_recoil_mml+0

