	.include "MPlayDef.s"

	.equ	se_unk_11d_grp, voicegroup002
	.equ	se_unk_11d_pri, 20
	.equ	se_unk_11d_rev, 0
	.equ	se_unk_11d_mvl, 127
	.equ	se_unk_11d_key, 0
	.equ	se_unk_11d_tbs, 1
	.equ	se_unk_11d_exg, 0
	.equ	se_unk_11d_cmp, 1

	.section .rodata
	.global	se_unk_11d
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

se_unk_11d_1:
	.byte	KEYSH , se_unk_11d_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 200*se_unk_11d_tbs/2
	.byte		VOICE , 109
	.byte		VOL   , 72*se_unk_11d_mvl/mxv
	.byte		N76   , Dn2 , v127
	.byte	W04
	.byte		VOL   , 69*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        68*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        67*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        65*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        64*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        63*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        62*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        61*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        60*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        59*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        58*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        57*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        57*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        56*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        55*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        54*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        52*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        51*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        51*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        50*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        49*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        48*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        47*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        46*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        45*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        44*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        43*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        41*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        41*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        40*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        39*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        38*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        37*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        37*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        36*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        35*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        34*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        33*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        32*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        31*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        31*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        30*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        28*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        28*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        27*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        26*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        25*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        24*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        24*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        23*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        21*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        21*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        20*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        19*se_unk_11d_mvl/mxv
	.byte	W02
	.byte		        18*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        17*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        17*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        15*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        12*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        11*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        8*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        5*se_unk_11d_mvl/mxv
	.byte	W01
	.byte		        1*se_unk_11d_mvl/mxv
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_unk_11d:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_unk_11d_pri	@ Priority
	.byte	se_unk_11d_rev	@ Reverb.

	.word	se_unk_11d_grp

	.word	se_unk_11d_1

	.end
