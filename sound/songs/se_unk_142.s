	.include "MPlayDef.s"

	.equ	se_unk_142_grp, voicegroup002
	.equ	se_unk_142_pri, 220
	.equ	se_unk_142_rev, 0
	.equ	se_unk_142_mvl, 127
	.equ	se_unk_142_key, 0
	.equ	se_unk_142_tbs, 1
	.equ	se_unk_142_exg, 1
	.equ	se_unk_142_cmp, 1

	.section .rodata
	.global	se_unk_142
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_unk_142_1:
	.byte	KEYSH , se_unk_142_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 100*se_unk_142_tbs/2
	.byte		VOICE , 106
	.byte		VOL   , 89*se_unk_142_mvl/mxv
	.byte		N24   , Fn0 , v127
	.byte	W24
	.byte		N24   
	.byte	W24
_083386ea:
	.byte		N24   , Fn0 , v127
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte GOTO
	.word _083386ea
@ 001   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

se_unk_142:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_142_pri	@ Priority
	.byte	se_unk_142_rev	@ Reverb.

	.word	se_unk_142_grp

	.word	se_unk_142_1

	.end
