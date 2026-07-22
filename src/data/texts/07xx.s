.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_OldLifeSpace:: @ 0x08380114
  .2byte (Text_OldLifeSpace_BurnAwayTheIvy-Start), (Text_OldLifeSpace_ICanCutAnything-Start), (Text_OldLifeSpace_ChikachikaEvenIfYouDefeat-Start), (Text_OldLifeSpace_Maaama-Start), (Text_OldLifeSpace_Maaama_Alias1-Start), (Text_OldLifeSpace_HeyPrea-Start), (Text_OldLifeSpace_ThatSRightCrea-Start), (Text_OldLifeSpace_HeyPrea_2-Start)
  .2byte (Text_OldLifeSpace_ThatSRightCrea_2-Start), (Text_OldLifeSpace_ThoseMustBe-Start), (Text_OldLifeSpace_CielZeroIVePickedup-Start), (Text_OldLifeSpace_TheirMotherTheyMustBe-Start), (Text_OldLifeSpace_CielHeyZeroCanYouprotect-Start), (Text_OldLifeSpace_AlrightILlFindThem-Start), (Text_OldLifeSpace_CielThankYouZero-Start), (Text_OldLifeSpace_WhoAreYouYouSmell-Start)
  .2byte (Text_OldLifeSpace_WhoAreYouYouSmell_2-Start), (Text_OldLifeSpace_ChikachikaSoTheseAreBaby-Start), (Text_OldLifeSpace_HandOverThe-Start), (Text_OldLifeSpace_OhIKnowHimHe-Start), (Text_OldLifeSpace_IKnowHimTooThat-Start), (Text_OldLifeSpace_YouFaker-Start), (Text_OldLifeSpace_YouFaker_2-Start), (Text_OldLifeSpace_HmmChikachika-Start)
  .2byte (Text_OldLifeSpace_Waaaaaah-Start), (Text_OldLifeSpace_Waaaaaah_2-Start), (Text_OldLifeSpace_ThoseTwoBelong-Start), (Text_OldLifeSpace_IMDeathtanz-Start), (Text_OldLifeSpace_WhoAreYouMisterI-Start), (Text_OldLifeSpace_WhoAreYouMisterI_2-Start), (Text_OldLifeSpace_Heheheheheee-Start), (Text_OldLifeSpace_PreaDidYouHear-Start)
  .2byte (Text_OldLifeSpace_IHeardCreaHeS-Start), (Text_OldLifeSpace_IMLookingForThe-Start), (Text_OldLifeSpace_OkayLetSGo-Start), (Text_OldLifeSpace_OkayLetSGo_2-Start), (Text_OldLifeSpace_Wait-Start), (Text_OldLifeSpace_DarnCielCanYouFollow-Start), (Text_OldLifeSpace_CielIMSorryZero-Start), (Text_OldLifeSpace_Empty-Start)
  .2byte (Text_OldLifeSpace_OperatorMrZeroPleaseReturn-Start)

Text_OldLifeSpace:: @ 0x08380166
Start:

Text_OldLifeSpace_BurnAwayTheIvy: @ 0x08380166
	@ EN: Operator: / Mr. Zero! / You can burn away / the ivy with Flame- / based attacks. / The Recoil Rod's / charge attack can / destroy things too. / Keep that in mind.
	.string "{WINDOW 0x64}"
		.string "オペレーター:\n"
		.string "「ゼロさん！▼"
		.string "「ところどころにはえているツタは\n"
		.string " ホノオぞくせいのコウゲキで\n"
		.string " もやすことができます▼"
		.string "「また、リコイルロッドの\n"
		.string " チャージこうげきで\n"
		.string " こわせるところも あるようです▼"
		.string "「ちゅういしてください$"

Text_OldLifeSpace_ICanCutAnything: @ 0x083801D8
	@ EN: I can cut anything / with my beautiful / scythe! / Chikachikachika!
	.string "{WINDOW 0x0D}"
		.string "このうつくしきカマに\n"
		.string "きれないものは ない…！▼"
		.string "ギチギチギチギチィィィッ！$"

Text_OldLifeSpace_ChikachikaEvenIfYouDefeat: @ 0x08380200
	@ EN: Chikachika... / Even if you defeat / me here... / My associates will / cut the old chains / that bind the world. / And build... / A new order... / Lord Weeeeiil!!!
	.string "{WINDOW 0x0C}"
		.string "ギチギチッ…▼"
		.string "たとえオレが\n"
		.string "ここでたおれても…▼"
		.string "仲間が…必ず……\n"
		.string "世界をしばる…古き…くさりを…\n"
		.string "たちきってくれるはず……▼"
		.string "新しい世界を…\n"
		.string "新しいチツジョを…！\n"
		.string "バ…バイルさまーーーーーーっ！$"

Text_OldLifeSpace_Maaama: @ 0x0838026D
Text_OldLifeSpace_Maaama_Alias1: @ 0x0838026D
	@ EN: Maaama. / Maaama.
	.string "{WINDOW 0x66}"
		.string "おかーさーん\n"
		.string "おかーさーん$"

Text_OldLifeSpace_HeyPrea: @ 0x0838027D
	@ EN: Hey, Prea. / Mama's not here.
	.string "{WINDOW 0x66}"
		.string "ねえ プリエ\n"
		.string "ここにも おかーさん いないね$"

Text_OldLifeSpace_ThatSRightCrea: @ 0x08380296
	@ EN: That's right, Crea. / Mama's not here.
	.string "{WINDOW 0x69}"
		.string "そうだね クリエ\n"
		.string "ここにも おかーさん いないね$"

Text_OldLifeSpace_HeyPrea_2: @ 0x083802B1
	@ EN: Hey, Prea. / Let's look a little / farther inside.
	.string "{WINDOW 0x66}"
		.string "ねえ プリエ\n"
		.string "もっとおくを さがしてみようか$"

Text_OldLifeSpace_ThatSRightCrea_2: @ 0x083802CA
	@ EN: That's right, Crea. / Let's look a little / farther inside.
	.string "{WINDOW 0x69}"
		.string "そうだね クリエ\n"
		.string "もっとおくをさがしてみようよ$"

Text_OldLifeSpace_ThoseMustBe: @ 0x083802E4
	@ EN: ... / Those must be...
	.string "{WINDOW 0x04}"
		.string "………▼"
		.string "あれは…たしか…$"

Text_OldLifeSpace_CielZeroIVePickedup: @ 0x083802F3
	@ EN: Ciel: Zero! I've picked / up some Baby Elf readings / on that portable scanner / I gave you! They may be the / same ones I was studying...
	.string "{WINDOW 0x00}"
		.string "シエル「ゼロ…！▼"
		.string "あなたにもっていってもらった▼"
		.string "ケイタイ用スキャンに… ベビーエルフのハンノウが！▼"
		.string "わたしが前に ケンキュウしていたベビーエルフと▼"
		.string "同じコかもしれないわ……$"

Text_OldLifeSpace_TheirMotherTheyMustBe: @ 0x0838034F
	@ EN: Their mother... / They must be looking / for the Dark Elf.
	.string "{WINDOW 0x04}"
		.string "ははおやを…▼"
		.string "ダークエルフを\n"
		.string "さがしているようだったな$"

Text_OldLifeSpace_CielHeyZeroCanYouprotect: @ 0x0838036D
	@ EN: Ciel: Hey Zero, can you / protect those babies?
	.string "{WINDOW 0x00}"
		.string "シエル「ねえ、ゼロ…▼"
		.string "あのコたちを ホゴできないかしら…$"

Text_OldLifeSpace_AlrightILlFindThem: @ 0x0838038C
	@ EN: Alright. / I'll find them.
	.string "{WINDOW 0x04}"
		.string "わかった…▼"
		.string "あとをおう$"

Text_OldLifeSpace_CielThankYouZero: @ 0x0838039A
	@ EN: Ciel: Thank you, Zero...
	.string "{WINDOW 0x00}"
		.string "シエル「ありがとう…ゼロ$"

Text_OldLifeSpace_WhoAreYouYouSmell: @ 0x083803A9
	@ EN: Who are you? / You smell like Mama.
	.string "{WINDOW 0x66}"
		.string "あなたは だあれ？▼"
		.string "おかーさんと おなじニオイが\n"
		.string "するよ$"

Text_OldLifeSpace_WhoAreYouYouSmell_2: @ 0x083803C8
	@ EN: Who are you? / You smell like us.
	.string "{WINDOW 0x69}"
		.string "あなたは だあれ？▼"
		.string "わたしたちと おなじニオイが\n"
		.string "するよ$"

Text_OldLifeSpace_ChikachikaSoTheseAreBaby: @ 0x083803E7
	@ EN: Chikachika... / So these are Baby / Elves? / Lord Weil ordered me / to find them. / They really are just / little elves. Are / they useful?
	.string "{WINDOW 0x1D}"
		.string "ギチギチギチ…▼"
		.string "コイツらがベビーエルフか…▼"
		.string "バイルさまのめいれいで\n"
		.string "コイツらを さがしにきたが…▼"
		.string "ホントにガキのエルフじゃねえか…\n"
		.string "こんなヤツら、やくにたつのか？$"

Text_OldLifeSpace_HandOverThe: @ 0x0838043B
	@ EN: Hand over the / Baby Elves.
	.string "{WINDOW 0x04}"
		.string "…ベビーエルフを\n"
		.string "わたせ$"

Text_OldLifeSpace_OhIKnowHimHe: @ 0x0838044A
	@ EN: Oh, I know him! / He pushed Mama / around!
	.string "{WINDOW 0x66}"
		.string "あ！ あいつ しってるよ！▼"
		.string "こないだ おかーさんを\n"
		.string "いじめた やつだ！$"

Text_OldLifeSpace_IKnowHimTooThat: @ 0x08380470
	@ EN: I know him, too! / That's the guy who / pushed Mama around / a century ago!
	.string "{WINDOW 0x69}"
		.string "わたしも あいつ しってるよ！▼"
		.string "100ねんまえも おかーさんを\n"
		.string "いじめた やつだ！$"

Text_OldLifeSpace_YouFaker: @ 0x0838049C
	@ EN: You faker!
	.string "{WINDOW 0x66}"
		.string "ニセモノのくせにー！$"

Text_OldLifeSpace_YouFaker_2: @ 0x083804A9
	@ EN: You faker!
	.string "{WINDOW 0x69}"
		.string "ニセモノのくせにー！$"

Text_OldLifeSpace_HmmChikachika: @ 0x083804B6
	@ EN: Hmm? / Chikachika... / Shut up, you Baby / Elves! / If you don't wanna / get chopped up, go / into that room!
	.string "{WINDOW 0x04}"
		.string "…？▼"
	.string "{WINDOW 0x1D}"
		.string "ギチギチッ…\n"
		.string "うるせえぞ\n"
		.string "ベビーエルフども！▼"
		.string "ブッたギられたくなかったら\n"
		.string "おくのへやに ひっこんでろ！！$"

Text_OldLifeSpace_Waaaaaah: @ 0x083804F2
	@ EN: Waaaaaah!
	.string "{WINDOW 0x66}"
		.string "うわぁぁぁん$"

Text_OldLifeSpace_Waaaaaah_2: @ 0x083804FB
	@ EN: Waaaaaah!
	.string "{WINDOW 0x69}"
		.string "うわぁぁぁん$"

Text_OldLifeSpace_ThoseTwoBelong: @ 0x08380504
	@ EN: Those two belong / to Lord Weil. You / can't have them.
	.string "{WINDOW 0x1D}"
		.string "アイツらはバイルさまのもんだ…\n"
		.string "テメエなんかには\n"
		.string "わたさねえよ…！$"

Text_OldLifeSpace_IMDeathtanz: @ 0x08380528
	@ EN: I'm Deathtanz / Mantisk, one of / Weil's Numbers. / Now, time to slice / you into ribbons!
	.string "{WINDOW 0x0D}"
		.string "オレはバイル・ナンバーズがひとり\n"
		.string "デスタンツ・マンティスク▼"
		.string "テメエはオレが\n"
		.string "きりきざんでやるよ！$"

Text_OldLifeSpace_WhoAreYouMisterI: @ 0x0838055B
	@ EN: Who are you, mister? / I've seen you / somewhere before.
	.string "{WINDOW 0x66}"
		.string "おじちゃんは だあれ？▼"
		.string "みたこと あるような\n"
		.string "きがするよ$"

Text_OldLifeSpace_WhoAreYouMisterI_2: @ 0x0838057A
	@ EN: Who are you, mister? / I've seen him / somewhere before, / too.
	.string "{WINDOW 0x69}"
		.string "おじちゃんは だあれ？▼"
		.string "わたしも みたことある\n"
		.string "きがするよ$"

Text_OldLifeSpace_Heheheheheee: @ 0x0838059A
	@ EN: Heheheheheee... / My name is Weil. / I'm the one who / made your mother, / the Dark Elf. / You might think of / me as your Grandpa.
	.string "{WINDOW 0x3B}"
		.string "クーックックックッ…\n"
		.string "ワシの名はバイル…▼"
		.string "オマエたちの ははおや\n"
		.string "ダークエルフを作ったのは\n"
		.string "このワシじゃ▼"
		.string "いわば オマエたちの\n"
		.string "おじいさん という\n"
		.string "ところじゃな$"

Text_OldLifeSpace_PreaDidYouHear: @ 0x083805EF
	@ EN: Prea, did you hear / that? / He's our Grandpa!
	.string "{WINDOW 0x66}"
		.string "きいた？ プリエ！▼"
		.string "わたしたちの おじーちゃん\n"
		.string "だって！$"

Text_OldLifeSpace_IHeardCreaHeS: @ 0x0838060E
	@ EN: I heard, Crea! / He's our Grandpa!
	.string "{WINDOW 0x69}"
		.string "きいた！ クリエ！▼"
		.string "わたしたちの おじーちゃん\n"
		.string "だって！$"

Text_OldLifeSpace_IMLookingForThe: @ 0x0838062D
	@ EN: I'm looking for the / Dark Elf, too. / I need your help. / You should come with / me to Neo Arcadia. / I'll give you new / powers, and a new / body...
	.string "{WINDOW 0x3B}"
		.string "ワシも ダークエルフを\n"
		.string "さがしておる▼"
		.string "オマエたちの\n"
		.string "チカラをかしておくれ▼"
		.string "ワシといっしょに\n"
		.string "ネオ・アルカディアへ\n"
		.string "来るといい▼"
		.string "新しいチカラとカラダを…\n"
		.string "あたえてやろう$"

Text_OldLifeSpace_OkayLetSGo: @ 0x08380685
	@ EN: Okay! Let's go, / Prea!
	.string "{WINDOW 0x66}"
		.string "よし！ いこう！ プリエ！$"

Text_OldLifeSpace_OkayLetSGo_2: @ 0x08380695
	@ EN: Okay! Let's go, / Crea!
	.string "{WINDOW 0x69}"
		.string "うん！ いこう！ クリエ！$"

Text_OldLifeSpace_Wait: @ 0x083806A5
	@ EN: Wait!
	.string "{WINDOW 0x04}"
		.string "まてっ！$"

Text_OldLifeSpace_DarnCielCanYouFollow: @ 0x083806AC
	@ EN: Darn... / Ciel, can you follow / their readings?
	.string "{WINDOW 0x04}"
		.string "ちっ……▼"
		.string "シエル\n"
		.string "ヤツらのハンノウを\n"
		.string "おえるか？$"

Text_OldLifeSpace_CielIMSorryZero: @ 0x083806C7
	@ EN: Ciel: I'm sorry, Zero. / That won't be possible / with your scanner.
	.string "{WINDOW 0x00}"
		.string "シエル「ごめんなさい…▼"
		.string "そのケイタイ用スキャンでは、ちょっと無理みたい…$"

Text_OldLifeSpace_Empty: @ 0x083806F1
	@ EN: ...
	.string "{WINDOW 0x04}"
		.string "………$"

Text_OldLifeSpace_OperatorMrZeroPleaseReturn: @ 0x083806F7
	@ EN: Operator: Mr. Zero, / please return to base. / Commencing transfer.
	.string "{WINDOW 0x00}"
		.string "オペレーター「ゼロさん… ベースへキカンしてください▼"
		.string "転送をカイシします…$"

.balign 4, 0
