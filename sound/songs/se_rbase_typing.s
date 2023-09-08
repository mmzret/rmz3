    .include "MPlayDef.s"

    .section .rodata
    .balign 4, 0
    .global se_rbase_typing

se_rbase_typing_1:
  .byte KEYSH, 0x00
  .byte TEMPO, 0x28
  .byte VOICE, 0x6E
  .byte VOL, 0x30
  .byte PAN, 0x40
  .byte TIE, Fn1, v127
  .byte W96, W96
  .byte GOTO
  .4byte .-2
  .byte W48
  .byte EOT, Fn1
  .byte FINE

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

se_rbase_typing:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
  .byte 100
  .byte 0
  .4byte voicegroup002
  .4byte se_rbase_typing_1

  .end
