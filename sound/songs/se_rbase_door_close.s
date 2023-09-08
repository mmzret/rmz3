	.include "MPlayDef.s"

	.equ	se_rbase_door_close_grp, voicegroup002
	.equ	se_rbase_door_close_pri, 120
	.equ	se_rbase_door_close_rev, 0
	.equ	se_rbase_door_close_mvl, 127
	.equ	se_rbase_door_close_key, 0
	.equ	se_rbase_door_close_tbs, 1
	.equ	se_rbase_door_close_exg, 0
	.equ	se_rbase_door_close_cmp, 1

	.section .rodata
	.global	se_rbase_door_close
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_rbase_door_close_1:
	.byte	KEYSH , se_rbase_door_close_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 120*se_rbase_door_close_tbs/2
	.byte		VOICE , 113
	.byte		VOL   , 108*se_rbase_door_close_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Gn1 , v127
	.byte	W48
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

se_rbase_door_close_2:
	.byte	KEYSH , se_rbase_door_close_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 99
	.byte		VOL   , 108*se_rbase_door_close_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W32
	.byte	W01
	.byte		N48   , As1 , v127
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

se_rbase_door_close:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rbase_door_close_pri	@ Priority
	.byte	se_rbase_door_close_rev	@ Reverb.

	.word	se_rbase_door_close_grp

	.word	se_rbase_door_close_1
	.word	se_rbase_door_close_2

	.end
