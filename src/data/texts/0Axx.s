.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_AnatreForest:: @ 0x08380bf4
  .2byte (Text_AnatreForest_MyBodyHasReturned-Start), (Text_AnatreForest_JusticeIsOnThe-Start), (Text_AnatreForest_AnImpressiveFight-Start)

Texts_AnatreForest:: @ 0x08380bfa
Start:

Text_AnatreForest_MyBodyHasReturned: @ 0x08380BFA
	@ EN: My body has returned / from decay... / For Lord Weil, who / gave me life... / I have returned! / And now, I will take / your pitiful soul. / Let's see you fight / like a hero!
	.string "{WINDOW 0x29}"
		.string "いちどは くちた このカラダ…▼"
		.string "イノチをあたえて下さった\n"
		.string "バイルさまのため…▼"
		.string "今再び！\n"
		.string "あなたのミシルシ\n"
		.string "いただきにまいりました！▼"
		.string "いざ…ジンジョウに▼"
		.string "ショウブ！$"

Text_AnatreForest_JusticeIsOnThe: @ 0x08380C51
	@ EN: Justice is on the / side of the Neo / Arcadians!
	.string "{WINDOW 0x28}"
		.string "セイギは、われら\n"
		.string "ネオ・アルカディアにあり！$"

Text_AnatreForest_AnImpressiveFight: @ 0x08380C6A
	@ EN: An impressive fight! / However... / Evil must fail in / the end! / History will judge / who the true / winner was! / May you perish, / O Ancient God of / Destruction!
	.string "{WINDOW 0x28}"
		.string "お…おみごと…！\n"
		.string "ですが…▼"
		.string "最後に悪がほろびるは\n"
		.string "世のつね…！▼"
		.string "真のショウシャは…\n"
		.string "レキシがきめること……！▼"
		.string "ほろびよ…古きハカイ神…！$"

.balign 4, 0
