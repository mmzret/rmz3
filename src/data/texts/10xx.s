.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

.global TextOfs_GiantElevator
TextOfs_GiantElevator: @ 0x08382008
  .2byte (Text_GiantElevator_Empty - Start), (Text_GiantElevator_GrrrSoYouRe - Start), (Text_GiantElevator_WhatSThisAhhI - Start), (Text_GiantElevator_Huh - Start)

Texts_GiantElevator:: @ 0x08382010
Start:

Text_GiantElevator_Empty: @ 0x08382010
  .string "$"

Text_GiantElevator_GrrrSoYouRe: @ 0x08382011
	@ EN: Grrr... So you're / Zerrooo? / You're so tiny, I / almost stepped on / yah! / My name is Tretista / Kelverian, of Weil's / Numbers. / Your neck is so / tiny... I'll snap it / with one chomp! / Grrrrrrr!
	.string "{WINDOW 0x15}"
		.string "ゴルルルゥ…テメエがゼロかぁ…？▼"
		.string "小さすぎてぇ\n"
		.string "ふんづけちまうところだったぜぇ…！▼"
		.string "オレの名はバイル・ナンバーズ\n"
		.string "トレテスタ・ケルベリアン▼"
		.string "そのほそいくび…\n"
		.string "ひとくちでぇ\n"
		.string "かみちぎってやるぜぇ！▼"
		.string "ゴルルルルルルァ！$"

Text_GiantElevator_WhatSThisAhhI: @ 0x08382081
	@ EN: What's this? / Ahh, I must've / stepped on you. / You're so tiny, I / didn't even realize / it!
	.string "{WINDOW 0x14}"
		.string "ああーん？▼"
		.string "いつのまにかぁ\n"
		.string "ふみつぶしちまったかぁ？▼"
		.string "小さすぎて気づかなかったぜぇ！$"

Text_GiantElevator_Huh: @ 0x083820b0
	@ EN: Huh? / Zero... Where did / you go? I don't / see you... / And my whole body / hurts... Ouch... / Oouuuch! / Gaarrrwwwrrr!
	.string "{WINDOW 0x14}"
		.string "あ…れぇ…？\n"
		.string "ゼロォ…どこ行きやがったぁ…？\n"
		.string "見えねえぞぉ…？▼"
		.string "それに…カラダもいてえ…\n"
		.string "いてえ…いてえぞおおおっ！▼"
		.string "ゴアアアアアアッ！$"

.balign 4, 0
