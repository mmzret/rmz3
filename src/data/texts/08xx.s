.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_MissileFactory:: @ 0x08380724
  .2byte (Text_MissileFactory_YouMadeIt-Start), (Text_MissileFactory_No-Start), (Text_MissileFactory_CielTheyLaunchedItZero-Start), (Text_MissileFactory_IHaveToActNow-Start), (Text_MissileFactory_CielZero-Start), (Text_MissileFactory_BabyElves-Start), (Text_MissileFactory_HeCame-Start), (Text_MissileFactory_HeCame_2-Start)
  .2byte (Text_MissileFactory_OmegaWillGo-Start), (Text_MissileFactory_WeLlProtectHim-Start), (Text_MissileFactory_HeheGrandpaWill-Start), (Text_MissileFactory_Waaaaah-Start), (Text_MissileFactory_Owwwwww-Start), (Text_MissileFactory_WeMayHaveLost-Start), (Text_MissileFactory_WeMayHaveLost_2-Start), (Text_MissileFactory_Grrawrrr-Start)
  .2byte (Text_MissileFactory_Yay-Start), (Text_MissileFactory_Yay_2-Start), (Text_MissileFactory_Grrarraarrrr-Start), (Text_MissileFactory_Grrarraarrrr_2-Start), (Text_MissileFactory_HeyCanYouBeatUp-Start), (Text_MissileFactory_YeahCanYouBeat-Start), (Text_MissileFactory_WeTheReploidsOf-Start), (Text_MissileFactory_ArrrrgghIIAm-Start)
  .2byte (Text_MissileFactory_Harpuia-Start), (Text_MissileFactory_Perfect-Start), (Text_MissileFactory_GetHimGetHim-Start), (Text_MissileFactory_CielZeroDonTMove-Start), (Text_MissileFactory_OperatorTransferring-Start)

Text_MissileFactory:: @ 0x0838075e
Start:

Text_MissileFactory_YouMadeIt: @ 0x0838075E
	@ EN: Ciel: / You made it! / What a relief! / Have you determined / the missile's / target? / Ciel: / The target is... / Area Z... 3079. / What?! That's a / human residential / district!!! / Wait, that's not / all... The Dark Elf / is there, too! / So he's trying to / jump right in and / take the Dark Elf... / Understood.
	.string "{WINDOW 0x64}"
		.string "シエル:\n"
		.string "「よかった！ 無事だったのね！！▼"
	.string "{WINDOW 0x04}"
		.string "ミサイルのモクヒョウは、\n"
		.string "わかったか？▼"
	.string "{WINDOW 0x64}"
		.string "シエル:\n"
		.string "「あっ…えっと今……\n"
		.string " モクヒョウ…エリアZ…3079▼"
		.string "「なんてこと…！\n"
		.string " 人間の……きょじゅうくだわ！！▼"
		.string "「まって、それだけじゃない……\n"
		.string " その きょじゅうくに、\n"
		.string " ダークエルフがいるらしいわ！！▼"
	.string "{WINDOW 0x04}"
		.string "チョクセツのりこんで\n"
		.string "ダークエルフをとらえる気か…▼"
		.string "りょうかいした$"

Text_MissileFactory_No: @ 0x08380821
	@ EN: No!
	.string "{WINDOW 0x04}"
		.string "ちっ…！$"

Text_MissileFactory_CielTheyLaunchedItZero: @ 0x08380828
	@ EN: Ciel: They launched it! / Zero! Don't get any / closer!
	.string "{WINDOW 0x00}"
		.string "シエル「ハッシャされたのね！！▼"
		.string "ゼロ！ これ以上はキケンだわ！$"

Text_MissileFactory_IHaveToActNow: @ 0x0838084C
	@ EN: I have to act now, / while Omega is / immobile... / I'll sneak in and / stop both him and / the missile.
	.string "{WINDOW 0x05}"
		.string "今ならオメガは動けない……▼"
		.string "後方からシンニュウして、\n"
		.string "ヤツごとミサイルをしとめる$"

Text_MissileFactory_CielZero: @ 0x0838087B
	@ EN: Ciel: Zero!!!
	.string "{WINDOW 0x00}"
		.string "シエル「ゼローーー！！$"

Text_MissileFactory_BabyElves: @ 0x08380889
	@ EN: Baby Elves?!
	.string "{WINDOW 0x04}"
		.string "ベビーエルフ…！？$"

Text_MissileFactory_HeCame: @ 0x08380895
	@ EN: He came! / The bad Reploid!
	.string "{WINDOW 0x66}"
		.string "やっぱりきたよ！\n"
		.string "わるいレプリロイドだ！$"

Text_MissileFactory_HeCame_2: @ 0x083808AC
	@ EN: He came! / The nasty Reploid!
	.string "{WINDOW 0x69}"
		.string "やっぱりきたね！\n"
		.string "わるいレプリロイドめ！$"

Text_MissileFactory_OmegaWillGo: @ 0x083808C3
	@ EN: Omega will go / rescue Mama! / Don't get in his / way! Leave!
	.string "{WINDOW 0x66}"
		.string "オメガにーちゃんは\n"
		.string "おかーさんを\n"
		.string "たすけにいくんだ！▼"
		.string "じゃまするな！\n"
		.string "あっちいけぇー！$"

Text_MissileFactory_WeLlProtectHim: @ 0x083808F1
	@ EN: We'll protect him / from you! / Don't get in his / way! Leave!
	.string "{WINDOW 0x69}"
		.string "オメガにーちゃんを\n"
		.string "オマエから\n"
		.string "まもるんだ！▼"
		.string "じゃまするな！\n"
		.string "あっちいけぇー！！$"

Text_MissileFactory_HeheGrandpaWill: @ 0x0838091C
	@ EN: Hehe! Grandpa will / be so proud of us! / Haha! Grandpa will / be so proud of us!
	.string "{WINDOW 0x66}"
		.string "あはははっ！ おじーちゃん\n"
		.string "ほめてくれるかなぁ？▼"
	.string "{WINDOW 0x69}"
		.string "うふふふっ！ おじーちゃん\n"
		.string "きっと ほめてくれるよー$"

Text_MissileFactory_Waaaaah: @ 0x08380954
	@ EN: Waaaaah! / You horrible thing!
	.string "{WINDOW 0x66}"
		.string "うわぁぁんっ！\n"
		.string "ひどいよー！$"

Text_MissileFactory_Owwwwww: @ 0x08380965
	@ EN: Owwwwww! / That hurt!
	.string "{WINDOW 0x69}"
		.string "やあぁぁんっ！\n"
		.string "いたいよー！$"

Text_MissileFactory_WeMayHaveLost: @ 0x08380976
	@ EN: We may have lost, / but the missile will / land soon! / Our mission is a / success!
	.string "{WINDOW 0x66}"
		.string "まけちゃったけど\n"
		.string "もうすぐミサイル おちちゃうよ！\n"
		.string "さくせんセイコウだね！$"

Text_MissileFactory_WeMayHaveLost_2: @ 0x0838099E
	@ EN: We may have lost, / but we'll see our / Mama soon! / Our mission is a / success! / *gulp!*
	.string "{WINDOW 0x69}"
		.string "まけちゃったけど\n"
		.string "もうすぐ おかーさんにあえるよ！\n"
		.string "さくせんセイコウだね！▼"
	.string "{WINDOW 0x04}"
		.string "くっ…！$"

Text_MissileFactory_Grrawrrr: @ 0x083809CD
	@ EN: Grrawrrr!
	.string "{WINDOW 0x3C}"
		.string "グ…オオ…！$"

Text_MissileFactory_Yay: @ 0x083809D6
	@ EN: Yay! / Maaama! Maaama!
	.string "{WINDOW 0x66}"
		.string "わーい！\n"
		.string "おかーさん！ おかーさん！$"

Text_MissileFactory_Yay_2: @ 0x083809EB
	@ EN: Yay! / Maaama! Maaama!
	.string "{WINDOW 0x69}"
		.string "わーい！\n"
		.string "おかーさん！ おかーさん！$"

Text_MissileFactory_Grrarraarrrr: @ 0x08380A00
	@ EN: Grrarraarrrr!
	.string "{WINDOW 0x3D}"
		.string "グ…オオオオオオオオッ！$"

Text_MissileFactory_Grrarraarrrr_2: @ 0x08380A0F
	@ EN: Grrarraarrrr!
	.string "{WINDOW 0x3F}"
		.string "グ…オオオオオオオオッ！$"

Text_MissileFactory_HeyCanYouBeatUp: @ 0x08380A1E
	@ EN: Hey, can you beat up / that bad Reploid for / us?
	.string "{WINDOW 0x66}"
		.string "ついでに わるいレプリロイドも\n"
		.string "やっつけちゃえー$"

Text_MissileFactory_YeahCanYouBeat: @ 0x08380A39
	@ EN: Yeah, can you beat / up that fake Reploid / for us?
	.string "{WINDOW 0x69}"
		.string "ついでに ニセモノレプリロイドも\n"
		.string "やっつけちゃえー$"

Text_MissileFactory_WeTheReploidsOf: @ 0x08380A55
	@ EN: ... / We, the Reploids of / Neo Arcadia... / We are defenders of / humanity. The only / justice here. / Is this wasteland / what you people / call justice?! / Weil!!!
	.string "{WINDOW 0x2C}"
		.string "……………▼"
		.string "われらネオ・アルカディアの\n"
		.string "レプリロイドは…▼"
		.string "人間を守る……\n"
		.string "この地上のユイイツのセイギ▼"
		.string "これが…\n"
		.string "このハイキョが…\n"
		.string "キサマらの セイギかーっ！▼"
		.string "バイルーーーッ！$"

Text_MissileFactory_ArrrrgghIIAm: @ 0x08380AB4
	@ EN: Arrrrggh! / I... I am...
	.string "{WINDOW 0x2C}"
		.string "ぐあああああっ…！▼"
		.string "くっ…オレは…オレは…っ！$"

Text_MissileFactory_Harpuia: @ 0x08380ACE
	@ EN: Harpuia!
	.string "{WINDOW 0x04}"
		.string "ハルピュイア！$"

Text_MissileFactory_Perfect: @ 0x08380AD8
	@ EN: Perfect!
	.string "{WINDOW 0x66}"
		.string "いいぞいいぞー！$"

Text_MissileFactory_GetHimGetHim: @ 0x08380AE3
	@ EN: Get him! Get him!
	.string "{WINDOW 0x69}"
		.string "やっちゃえやっちゃえー！$"

Text_MissileFactory_CielZeroDonTMove: @ 0x08380AF2
	@ EN: Ciel: Zero, don't move! / I'll transfer you to the / base, now!
	.string "{WINDOW 0x00}"
		.string "シエル「ゼロ、動かないで！▼"
		.string "今ベースへ転送するわ！！$"

Text_MissileFactory_OperatorTransferring: @ 0x08380B13
	@ EN: Operator: Transferring!
	.string "{WINDOW 0x00}"
		.string "オペレーター「転送！$"

.balign 4, 0
