	.include "MPlayDef.s"

	.equ	se_release_seal_grp, voicegroup001
	.equ	se_release_seal_pri, 80
	.equ	se_release_seal_rev, 0
	.equ	se_release_seal_mvl, 127
	.equ	se_release_seal_key, 0
	.equ	se_release_seal_tbs, 1
	.equ	se_release_seal_exg, 0
	.equ	se_release_seal_cmp, 1

	.section .rodata
	.global	se_release_seal
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_release_seal_1:
	.byte	KEYSH , se_release_seal_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 170*se_release_seal_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 9*se_release_seal_mvl/mxv
	.byte		PAN   , c_v+1
	.byte		BEND  , c_v+0
	.byte		TIE   , Cn2 , v127
	.byte	W12
	.byte		VOL   , 18*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        28*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        37*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        47*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        56*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        61*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        66*se_release_seal_mvl/mxv
	.byte	W12
@ 001   ----------------------------------------
	.byte		        70*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        57*se_release_seal_mvl/mxv
	.byte	W12
	.byte		EOT   
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

se_release_seal_2:
	.byte	KEYSH , se_release_seal_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 12
	.byte		VOL   , 4*se_release_seal_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Cs3 , v072
	.byte		TIE   , Gn3 
	.byte		TIE   , Cn4 
	.byte	W12
	.byte		VOL   , 9*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        18*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        28*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        42*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        56*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        75*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        94*se_release_seal_mvl/mxv
	.byte	W12
@ 001   ----------------------------------------
	.byte		        120*se_release_seal_mvl/mxv
	.byte	W12
	.byte		        94*se_release_seal_mvl/mxv
	.byte	W08
	.byte		EOT   , Cs3 
	.byte		        Gn3 
	.byte		        Cn4 
	.byte	FINE

@******************************************************@
	.align	2

se_release_seal:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_release_seal_pri	@ Priority
	.byte	se_release_seal_rev	@ Reverb.

	.word	se_release_seal_grp

	.word	se_release_seal_1
	.word	se_release_seal_2

	.end
