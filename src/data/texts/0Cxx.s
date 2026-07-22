.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_AreaX2:: @ 0x08380d60
  .2byte (Text_AreaX2_Empty-Start), (Text_AreaX2_SoYouVeCome-Start), (Text_AreaX2_AhaAhahahahDidYouS-Start), (Text_AreaX2_NNoWhWhyWhy-Start)
  .2byte (Text_AreaX2_HeIsNoLongerHere-Start), (Text_AreaX2_WhoAAreYouX-Start), (Text_AreaX2_HaaaaahOhNoWeilHas-Start), (Text_AreaX2_GeeGagagaICanT-Start)
  .2byte (Text_AreaX2_WeilKnewFromThe-Start), (Text_AreaX2_HearMeCitizensOf-Start), (Text_AreaX2_DrWeil-Start), (Text_AreaX2_JustNowOurHeroMaster-Start)
  .2byte (Text_AreaX2_ThankYouAllI-Start), (Text_AreaX2_ItSAllGoing-Start), (Text_AreaX2_WhatIsItWellNever-Start), (Text_AreaX2_TheHeart-Start)

Texts_AreaX2:: @ 0x08380d80
Start:

Text_AreaX2_Empty: @ 0x08380d80
	.string "$"

Text_AreaX2_SoYouVeCome: @ 0x08380D81
	@ EN: So you've come, / Zero. / D-do you know what / you are doing? / Doing? / You are helping / extremists! / Why would a-a / legendary hero help / an evil army? / So you're saying / that we're an / evil army... / ...and you people / are fighting for / justice? / Exactly right. / Almost a-all / humans support our / cause. / All humans dream of / defeating th-the / extremists. / What value is there / in the justice that / complacent humans / seek? / Wh-who cares about / value? Neo Arcadia's / doing what's right. / That i-is enough / proof that what we / do is j-just!
	.string "{WINDOW 0x37}"
		.string "きたネ…ゼロ▼"
		.string "キミは 自分が\n"
		.string "何を シていルか\n"
		.string "ワかってイるのかい？▼"
		.string "テロリストのミカタだよ…？▼"
		.string "伝説のエイユウが\n"
		.string "悪の軍団の手助けを\n"
		.string "していルんだヨ？▼"
	.string "{WINDOW 0x04}"
		.string "オレたちが\n"
		.string "悪の軍団で…▼"
		.string "オマエたちは、\n"
		.string "セイギのみかた…\n"
		.string "ということか……▼"
	.string "{WINDOW 0x37}"
		.string "そのとオり▼"
		.string "ボクたちは、\n"
		.string "人間たちのアットウ的なシジを\n"
		.string "うけている……▼"
		.string "テロリストを たおすことは、\n"
		.string "カレら人間…みんなのユメなんだよ▼"
	.string "{WINDOW 0x04}"
		.string "かいならされた人間たちが\n"
		.string "のぞむセイギに……▼"
		.string "いったい何のカチが\n"
		.string "あるっていうんだ▼"
	.string "{WINDOW 0x37}"
		.string "カチなんて どうでもイいんダよ…\n"
		.string "ネオ・アルカディアの\n"
		.string "やっテいることは たダしい…▼"
		.string "そのセイギの ショウメイになれば\n"
		.string "それで いイのさ！$"

Text_AreaX2_AhaAhahahahDidYouS: @ 0x08380EC8
	@ EN: Aha! Ahahahah! / Did you s-see that?! / I am the true hero!
	.string "{WINDOW 0x6E}"
		.string "あは！ アはハはハは！▼"
		.string "見タか！やっぱりボクは\n"
		.string "本当のエイユウなんダ！$"

Text_AreaX2_NNoWhWhyWhy: @ 0x08380EF1
	@ EN: N-no! Wh-why-why?! / I'm a hero! I / f-fight for justice! / Weil! / Dr. Weil! / Use Omeg-Omega! / Crush him in your / h-hand!
	.string "{WINDOW 0x6F}"
		.string "くソっ…ナぜだ…！▼"
		.string "ボクは…ボクはセイギの\n"
		.string "エイユウなんダぞ…！▼"
		.string "バイル！\n"
		.string "ドクター・バイル！▼"
		.string "オメガを…オメガをだセ！\n"
		.string "コイツをひネりつぶセーッ！$"

Text_AreaX2_HeIsNoLongerHere: @ 0x08380F3E
	@ EN: He is... / ...no longer here.
	.string "{WINDOW 0x34}"
		.string "カレはもう…▼"
		.string "ここにはいないよ$"

Text_AreaX2_WhoAAreYouX: @ 0x08380F50
	@ EN: Who a-are you?! / X! / X?! / Y-you are my / original form?! / Weil has moved to / another base. / With Omega... / Weil was using you / for his own purpose. / Gee...g-gee... / Everyone treats me / l-like a fool! / I-I won't stand for / it! Let me show you / my true power!
	.string "{WINDOW 0x6F}"
		.string "な…なンだ、オマエハ！？▼"
	.string "{WINDOW 0x04}"
		.string "エックス…！▼"
	.string "{WINDOW 0x6F}"
		.string "…エックスだと…！？▼"
		.string "オマエが…ボクのもとにナった\n"
		.string "オリジナルのエックス…！？▼"
	.string "{WINDOW 0x34}"
		.string "バイルは…\n"
		.string "この本部をすて\n"
		.string "べつのところにうつったよ▼"
		.string "オメガをつれてね……▼"
		.string "キミはバイルに\n"
		.string "利用されていただけなんだよ…▼"
	.string "{WINDOW 0x6F}"
		.string "ギ…ギギッ…▼"
		.string "どいツも…こイつも…\n"
		.string "ボクをバカにしやがッテ…！▼"
		.string "ゆるサナイ…ユルサないぞ…！\n"
		.string "ボクの…本当のチカラを…\n"
		.string "見せテやル…！$"

Text_AreaX2_HaaaaahOhNoWeilHas: @ 0x0838101E
	@ EN: Haaaaah!!! / Oh no! / Weil has placed a / trap on your body!
	.string "{WINDOW 0x6F}"
		.string "{BOTTOM}ハぁーーーーっ！！▼"
	.string "{WINDOW 0x34}"
		.string "いけない！▼"
		.string "バイルはキミのカラダに\n"
		.string "ワナを！$"

Text_AreaX2_GeeGagagaICanT: @ 0x08381044
	@ EN: Gee...gagaga?! / I...can't... / can't move... / Gagagaaa... / Aaaaaaarggh!
	.string "{WINDOW 0x6F}"
		.string "{BOTTOM}ギ…ガガ…！？▼"
		.string "カ…カラダが…しびれ…▼"
		.string "グガガッ…\n"
		.string "アアアアアアーーーッ！$"

Text_AreaX2_WeilKnewFromThe: @ 0x0838106D
	@ EN: ?! / Weil knew from the / start how things / would turn out, / so he must have / rigged a trap on / him... / To fulfill his / true ambition...
	.string "{WINDOW 0x04}"
		.string "………！？▼"
	.string "{WINDOW 0x35}"
		.string "バイルは はじめから\n"
		.string "こうなることを 知っていて…\n"
		.string "カレにワナをしかけていたんだ▼"
		.string "カレの…本当のヤボウを\n"
		.string "かなえるために……$"

Text_AreaX2_HearMeCitizensOf: @ 0x083810B9
	@ EN: Hear me, citizens of / the great land of / Neo Arcadia... / I must inform you of / sorrowful news.
	.string "{WINDOW 0x52}"
		.string "…ネオ・アルカディアの\n"
		.string "すべてのゼンリョウなるシミンの\n"
		.string "みなさんに……▼"
		.string "かなしいお知らせをしなければ\n"
		.string "なりません……$"

Text_AreaX2_DrWeil: @ 0x083810F7
	@ EN: Dr. Weil...
	.string "{WINDOW 0x04}"
		.string "ドクター・バイル……$"

Text_AreaX2_JustNowOurHeroMaster: @ 0x08381104
	@ EN: Just now... / Our hero Master X / was taken by blood- / thirsty extremists, / and he has sadly / passed away... / So, in accordance / with Ordinance ↾8, / I, Dr. Weil, will / become your new / leader... / It is time to put / a stop to these / extremists!
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}たった今…▼"
		.string "チにうえたテロリストの手にかかり\n"
		.string "ワレラがエイユウ…\n"
		.string "エックスさまが…………▼"
		.string "おナクなりに…\n"
		.string "なりました………▼"
		.string "今からジョウレイ8コウの\n"
		.string "テキヨウにより…▼"
		.string "フショウこのドクター・バイルが\n"
		.string "みなさんのシドウシャとなり…▼"
		.string "テロリストちんあつのシキを\n"
		.string "とりおこなうことになりました…$"

Text_AreaX2_ThankYouAllI: @ 0x0838119B
	@ EN: ... / Thank you all. I / have just confirmed / your approval. / I will have to ask / you all to do a / number of things... / Neo Arcadia cannot / know true peace, / until the extremists / are eradicated! / Let us all fight / together, until they / are wiped out! / He... / Hehehehe... / Heheheheheee... / Bwahahahahah!
	.string "{WINDOW 0x52}"
		.string "………▼"
		.string "ありがとうございます\n"
		.string "今、みなさんのごショウニンを\n"
		.string "カクニンいたしました▼"
		.string "これから、みなさんにイロイロな\n"
		.string "オネガイをすることになるかも\n"
		.string "しれませんが……▼"
		.string "テロリストぼくめつまで……\n"
		.string "ネオ・アルカディアに\n"
		.string "真の平和は、おとずれません！▼"
		.string "ともにテロリストをねだやしに\n"
		.string "するまで、戦おうでは\n"
		.string "ありませんか！！▼"
		.string "……クッ………▼"
		.string "クックックッ……▼"
		.string "クーックックックッ…\n"
		.string "クヒャーッハッハッハッハッ！$"

Text_AreaX2_ItSAllGoing: @ 0x08381269
	@ EN: ... / It's all going / according to his / plans. / Dr. Weil... / Will he try to / repeat the tragedy / of the Elf Wars, / that ended a / century ago... / I'll look for Weil. / I need you to help. / Okay. / I'll look for him, / too... / I wanted to say / something. About / Omega... / ...
	.string "{WINDOW 0x04}"
		.string "…………▼"
		.string "すべてヤツの\n"
		.string "スジガキどおり……か▼"
	.string "{WINDOW 0x35}"
		.string "ドクター・バイル……▼"
		.string "あなたは また\n"
		.string "100年前の戦争を…▼"
		.string "ヨウセイ戦争の ヒゲキを\n"
		.string "くりかえす つもりなのか…▼"
	.string "{WINDOW 0x04}"
		.string "オレはバイルの行方をおう▼"
		.string "チカラをかしてくれ▼"
	.string "{WINDOW 0x35}"
		.string "わかった……▼"
		.string "ボクもカレのイバショを\n"
		.string "さがそう……▼"
		.string "ところで……\n"
		.string "オメガのことなんだが……▼"
		.string "…………$"

Text_AreaX2_WhatIsItWellNever: @ 0x08381313
	@ EN: What is it? / Well...never mind. / I'll bring it up / again when the time / comes. / The heart is what / counts. Not the / body...
	.string "{WINDOW 0x04}"
		.string "なんだ……？▼"
	.string "{WINDOW 0x35}"
		.string "いや……▼"
		.string "その時になったら\n"
		.string "あらためて言うよ……▼"
		.string "大事なのは、カラダではなく\n"
		.string "心なのだと……$"

Text_AreaX2_TheHeart: @ 0x08381352
	@ EN: The heart? / ...
	.string "{WINDOW 0x04}"
		.string "心……だと？▼"
		.string "…………$"

.balign 4, 0
