.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_SunkenLibrary:: @ 0x083817f0
	.2byte (Text_SunkenLibrary_GoToDataRoom-Start), (Text_SunkenLibrary_Operator_2-Start), (Text_SunkenLibrary_PushUpOnControlPad-Start), (Text_SunkenLibrary_FourMatchesWeilOmegaDark-Start), (Text_SunkenLibrary_ThreeMoreMatches-Start), (Text_SunkenLibrary_TwoMoreMatches-Start), (Text_SunkenLibrary_LastOne-Start), (Text_SunkenLibrary_SpecifySearchData-Start)
	.2byte (Text_SunkenLibrary_AreaWithWeilS-Start), (Text_SunkenLibrary_AreaWithOmegaS-Start), (Text_SunkenLibrary_AreaWithDarkElfS-Start), (Text_SunkenLibrary_AreaWithData-Start), (Text_SunkenLibrary_WhoDaresIntrude-Start), (Text_SunkenLibrary_IAmVolteelBiblio-Start), (Text_SunkenLibrary_HehehehehYouCanTHave-Start), (Text_SunkenLibrary_WhatSUpWithYou-Start)
	.2byte (Text_SunkenLibrary_OperatorMission-Start), (Text_SunkenLibrary_YouGotWeilSData-Start), (Text_SunkenLibrary_YouGotOmegaSData-Start), (Text_SunkenLibrary_YouGotTheDarkElf-Start), (Text_SunkenLibrary_YouGotTheElfWars-Start), (Text_SunkenLibrary_File650326-Start), (Text_SunkenLibrary_u16_ARRAY_0834ce8c_0-Start), (Text_SunkenLibrary_File815156-Start)
	.2byte (Text_SunkenLibrary_u16_ARRAY_0834ce8c_1-Start), (Text_SunkenLibrary_File351848-Start), (Text_SunkenLibrary_SoTheDarkElf-Start), (Text_SunkenLibrary_File945388-Start), (Text_SunkenLibrary_CielZeroItLooksLikethat-Start)

Text_SunkenLibrary:: @ 0x0838182a
Start:

Text_SunkenLibrary_GoToDataRoom: @ 0x0838182A
	@ EN: Operator: / First, please go to / the Data Room. / That room has the / highest probability / of containing / information about / Weil and Omega.
	.string "{WINDOW 0x64}"
		.string "オペレーター:\n"
		.string "「まずはデータルームへ\n"
		.string " 行ってください▼"
		.string "「バイルやオメガの\n"
		.string " ジョウホウがあるカノウセイは…\n"
		.string " そこがもっとも高そうです$"

Text_SunkenLibrary_Operator_2: @ 0x08381874
	@ EN: Operator: / This is the Data / Room. / Please search for / information on Weil / at that console. / After searching, / the data's location / will be displayed. / Please go to that / area, and recover / the data.
	.string "{WINDOW 0x64}"
		.string "オペレーター:\n"
		.string "「ここがデータルームです…▼"
		.string "「そこのコンソールで…\n"
		.string " バイルのことを\n"
		.string " ケンサクおねがいします▼"
		.string "「ケンサクすると…\n"
		.string " データがおさめられたエリアが\n"
		.string " ひょうじされるはずです▼"
		.string "「そのエリアへ行って\n"
		.string " データをカイシュウして\n"
		.string " いただけませんか？$"

Text_SunkenLibrary_PushUpOnControlPad: @ 0x083818F9
	@ EN: Push Up on +Control Pad.
	.string "{WINDOW 0x00}"
		.string "モニターの前で✚ボタンの上をおしてください$"

Text_SunkenLibrary_FourMatchesWeilOmegaDark: @ 0x08381914
	@ EN: Four matches... / Weil, Omega, Dark / Elf, Elf Wars...
	.string "{WINDOW 0x04}"
		.string "ガイトウするデータが4つ…▼"
		.string "バイル、オメガ、ダークエルフ\n"
		.string "ヨウセイ戦争……$"

Text_SunkenLibrary_ThreeMoreMatches: @ 0x0838193E
	@ EN: Three more matches.
	.string "{WINDOW 0x04}"
		.string "のこりのデータは3つ…$"

Text_SunkenLibrary_TwoMoreMatches: @ 0x0838194C
	@ EN: Two more matches.
	.string "{WINDOW 0x04}"
		.string "のこりのデータは2つ…$"

Text_SunkenLibrary_LastOne: @ 0x0838195A
	@ EN: Last one...
	.string "{WINDOW 0x04}"
		.string "サイゴのデータか…$"

Text_SunkenLibrary_SpecifySearchData: @ 0x08381966
	@ EN: Specify search data.
	.string "{WINDOW 0x6A}"
		.string "ドノ データヲ サーチ シマスカ？$"

Text_SunkenLibrary_AreaWithWeilS: @ 0x0838197A
	@ EN: Area with Weil's / data found. / To search for more / information, use the / console again.
	.string "{WINDOW 0x6A}"
		.string "バイル ノ データガ アル\n"
		.string "エリアヲ サーチシマシタ▼"
		.string "サイド ジョウホウガ\n"
		.string "ヒツヨウナ トキハ\n"
		.string "コンソールヲ シラベテクダサイ$"

Text_SunkenLibrary_AreaWithOmegaS: @ 0x083819BC
	@ EN: Area with Omega's / data found. / To search for more / information, use the / console again.
	.string "{WINDOW 0x6A}"
		.string "オメガ ノ データガ アル\n"
		.string "エリアヲ サーチシマシタ▼"
		.string "サイド ジョウホウガ\n"
		.string "ヒツヨウナ トキハ\n"
		.string "コンソールヲ シラベテクダサイ$"

Text_SunkenLibrary_AreaWithDarkElfS: @ 0x083819FE
	@ EN: Area with Dark Elf's / data found. / To search for more / information, use the / console again.
	.string "{WINDOW 0x6A}"
		.string "ダークエルフ ノ データガ アル\n"
		.string "エリアヲ サーチシマシタ▼"
		.string "サイド ジョウホウガ\n"
		.string "ヒツヨウナ トキハ\n"
		.string "コンソールヲ シラベテクダサイ$"

Text_SunkenLibrary_AreaWithData: @ 0x08381A43
	@ EN: Area with data / concerning the Elf / Wars found. / To search for more / information, use the / console again.
	.string "{WINDOW 0x6A}"
		.string "ヨウセイ戦争 ノ データガ アル\n"
		.string "エリアヲ サーチシマシタ▼"
		.string "サイド ジョウホウガ\n"
		.string "ヒツヨウナ トキハ\n"
		.string "コンソールヲ シラベテクダサイ$"

Text_SunkenLibrary_WhoDaresIntrude: @ 0x08381A8A
	@ EN: Who dares intrude / upon my territory? / ...Ze-Zero! Heheh! / So, it's you! / Heheh!
	.string "{WINDOW 0x23}"
		.string "…だ…だれだ…\n"
		.string "オレの…なわばりに\n"
		.string "……来たヤツは…▼"
		.string "…ゼ…ゼロ…！ひっ…ひひっ！\n"
		.string "そうか…オマエか…！\n"
		.string "ひひっ…！$"

Text_SunkenLibrary_IAmVolteelBiblio: @ 0x08381AC8
	@ EN: I am Volteel Biblio, / of Weil's Numbers. / What is that you've / got there? Give that / data back! Nooowww!
	.string "{WINDOW 0x13}"
		.string "オレは…バイル・ナンバーズ…\n"
		.string "ヴォルティール・ビブリーオ▼"
		.string "なんだ…その手にもっているのは…\n"
		.string "そのデータ…かえせ…\n"
		.string "かえせぇぇぇっ！$"

Text_SunkenLibrary_HehehehehYouCanTHave: @ 0x08381B0D
	@ EN: Heheheheh! / You can't have this / data! Nyah nyah / nyah nyaaaah nyah!
	.string "{WINDOW 0x12}"
		.string "ひひひひひひっ！▼"
		.string "わたさないっ…このデータ…\n"
		.string "わたさないっ！ ひひっ！$"

Text_SunkenLibrary_WhatSUpWithYou: @ 0x08381B33
	@ EN: What's up with you! / You're opposing / Lord Weil?! Aren't / you afraid of him?! / You...you're crazy! / Aaaaaarrrggghhh!!!
	.string "{WINDOW 0x12}"
		.string "なんだ…なんなんだオマエ…！▼"
		.string "バイルさまにさからうのが…\n"
		.string "こわくないのか…！？▼"
		.string "い…いかれてる！▼"
		.string "ひゃあああああああっ！$"

Text_SunkenLibrary_OperatorMission: @ 0x08381B72
	@ EN: Operator: Mission / completed. Commencing / transfer.
	.string "{WINDOW 0x00}"
		.string "オペレーター「ミッションしゅうりょう▼"
		.string "転送をカイシします$"

Text_SunkenLibrary_YouGotWeilSData: @ 0x08381B93
	@ EN: You got Weil's data!
	.string "{WINDOW 0x00}"
		.string "バイルのデータをゲットした！$"

Text_SunkenLibrary_YouGotOmegaSData: @ 0x08381BA4
	@ EN: You got Omega's data!
	.string "{WINDOW 0x00}"
		.string "オメガのデータをゲットした！$"

Text_SunkenLibrary_YouGotTheDarkElf: @ 0x08381BB5
	@ EN: You got the Dark Elf data!
	.string "{WINDOW 0x00}"
		.string "ダークエルフのデータをゲットした！$"

Text_SunkenLibrary_YouGotTheElfWars: @ 0x08381BC9
	@ EN: You got the Elf Wars data!
	.string "{WINDOW 0x00}"
		.string "ヨウセイ戦争のデータをゲットした！$"

Text_SunkenLibrary_File650326: @ 0x08381BDF
	@ EN: File ↾650326 / == Dr. Weil == / From Neo Arcadia... / Creator of Omega... / Altered the Mother / Elf, sparking the / Elf Wars... / Banished from Neo / Arcadia after the / Elf Wars...
	.string "{WINDOW 0x04}"
		.string "ファイルナンバー650326\n"
		.string "--ドクター・バイル--▼"
		.string "ネオ・アルカディアしょぞく……▼"
		.string "オメガのセイサクシャ…▼"
		.string "マザーエルフを改造し\n"
		.string "ヨウセイ戦争をひきおこす…▼"
		.string "ヨウセイ戦争でのセキニンをとわれ\n"
		.string "ネオ・アルカディアを\n"
		.string "ツイホウされる…$"

Text_SunkenLibrary_u16_ARRAY_0834ce8c_0: @ 0x08381C5D
	@ EN: If we can analyze / this data, we might / be able to find some / new information / about Weil...
	.string "{WINDOW 0x04}"
		.string "このデータをカイセキすれば、\n"
		.string "バイルについて さらにジョウホウが\n"
		.string "手に入るかもしれない………$"

Text_SunkenLibrary_File815156: @ 0x08381C90
	@ EN: File ↾815156 / == Omega == / The ultimate / Reploid, created by / Dr. Weil... / Possesses incredible / power when combined / with the Dark Elf. / Banished to outer / space to avoid / another Elf War...
	.string "{WINDOW 0x04}"
		.string "ファイルナンバー815156\n"
		.string "--オメガ--▼"
		.string "ドクター・バイルに作られた\n"
		.string "キュウキョクのレプリロイド…▼"
		.string "ダークエルフと\n"
		.string "くみあわせることにより\n"
		.string "おそろしいチカラをハッキする▼"
		.string "ヨウセイ戦争のヒゲキを\n"
		.string "くりかえさぬため…\n"
		.string "ウチュウへツイホウされる……$"

Text_SunkenLibrary_u16_ARRAY_0834ce8c_1: @ 0x08381D11
	@ EN: If we can analyze / this data, we might / be able to find out / something new / about Omega...
	.string "{WINDOW 0x04}"
		.string "このデータをカイセキすれば、\n"
		.string "オメガについて さらにジョウホウが\n"
		.string "手に入るかもしれない………$"

Text_SunkenLibrary_File351848: @ 0x08381D44
	@ EN: File ↾351848 / == Dark Elf == / Officially known as / the "Mother Elf." / Creator unknown. / This Cyber-elf was / originally created / for the purpose of / restoring Maverick / Programs to their / original state... / But the Mother Elf / was altered by Dr. / Weil so she could be / used to manipulate / Reploids, by freely / rewriting programs. / Although the / organized fighting / of the Reploids / manipulated by the / altered Mother Elf / did end the wars, / this terrible power / was sealed off to / prevent misuse.
	.string "{WINDOW 0x04}"
		.string "ファイルナンバー351848\n"
		.string "--ダークエルフ--▼"
		.string "セイシキメイショウ マザーエルフ\n"
		.string "セイサクシャ不明▼"
		.string "もともと……\n"
		.string "イレギュラープログラムを\n"
		.string "もとにもどし………▼"
		.string "イレギュラーを\n"
		.string "すくうために作られた…\n"
		.string "サイバーエルフであったが……▼"
		.string "レプリロイドをあやつるため…\n"
		.string "プログラムを自由に\n"
		.string "かきかえることができるよう……▼"
		.string "ドクター・バイルによって\n"
		.string "改造された………▼"
		.string "改造されたマザーエルフに\n"
		.string "あやつられたレプリロイドが\n"
		.string "ソシキ的に戦うことにより…▼"
		.string "戦争は…\n"
		.string "シュウケツをむかえたが…▼"
		.string "その強大な力が\n"
		.string "悪用されることをおそれ\n"
		.string "ふういんされる$"

Text_SunkenLibrary_SoTheDarkElf: @ 0x08381E63
	@ EN: So, the Dark Elf... / What's going on? / ... / If we can analyze / this data, we might / be able to find out / something new / about her...
	.string "{WINDOW 0x04}"
		.string "ダークエルフ…か…\n"
		.string "アイツはいったい……▼"
		.string "……▼"
		.string "このデータをカイセキすれば、\n"
		.string "アイツについて 他にも何か\n"
		.string "わかるかもしれない………$"

Text_SunkenLibrary_File945388: @ 0x08381EA9
	@ EN: File ↾945388 / == Elf Wars == / .........end of the / .........Wars...... / Cyber-elves......used... / ...........from this time / .................... / ........................... / ....Elf Wars.............. / ...............the use... / ......................... / ...."Dark Elf," / and copies........ / ................... / ....... / ...amplify the power / .............. / while............ / ............at / will... / ..........the worst / ....in......... / .......... / .................... / ............the war... / ...end................. / Approximately 90%... / ............. / ...................... / .........wiped.....
	.string "{WINDOW 0x04}"
		.string "ファイルナンバー945388\n"
		.string "--ヨウセイ戦争--▼"
		.string "………………戦争の終わり……\n"
		.string "サイバーエルフ………………\n"
		.string "使用され………………▼"
		.string "これ以後………………\n"
		.string "ヨウセイ戦争………………▼"
		.string "…………ダークエルフ…\n"
		.string "………………と…▼"
		.string "そのコピーである………………\n"
		.string "使用に………………▼"
		.string "………………チカラを\n"
		.string "ゾウフク……▼"
		.string "同時に………………\n"
		.string "………………することが\n"
		.string "カノウに………からは……▼"
		.string "………………の……\n"
		.string "最悪の………………▼"
		.string "戦争は、………………\n"
		.string "………シュウケツ……▼"
		.string "………………ほぼ90%……▼"
		.string "…………………した……$"

Text_SunkenLibrary_CielZeroItLooksLikethat: @ 0x08381FBF
	@ EN: Ciel: Zero? It looks like / that data is corrupt. I / think we may be able to / repair it at the base. / Thank you...Zero...
	.string "{WINDOW 0x00}"
		.string "シエル「ゼロ…？▼"
		.string "どうやらデータがこわれているみたいね…▼"
		.string "多分、ベースでなら▼"
		.string "シュウフクできると…思うわ……▼"
		.string "ありがとう…ゼロ…$"

.balign 4, 0
