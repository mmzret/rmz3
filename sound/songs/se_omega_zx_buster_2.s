.include "asm/macros.inc"
 

.section .rodata
.balign 4, 0
.global se_omega_zx_buster_2

se_omega_zx_buster_2_1:
  .byte 0xBC, 0x00, 0xBB, 0x3C, 0xBD, 0x72, 0xBE, 0x64, 0xBF, 0x40, 0xFF, 0x21, 0x7F, 0xB0, 0xB1, 0x00

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_omega_zx_buster_2:
  .byte	1	@ NumTrks
  .byte	0	@ NumBlks
  .byte 0xDC
  .byte 0
  .word voicegroup002
  .4byte se_omega_zx_buster_2_1+0

.end

