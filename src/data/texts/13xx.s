.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_Others:: @ 0x083836cc
	.2byte (Text_Others_MsCielPlease-Start), (Text_Others_TheSimulationWill-Start), (Text_Others_ILlSaveOurData-Start), (Text_Others_ILlTakeCareOf-Start), (Text_Others_ShouldnTYouBe-Start), (Text_Others_HaveYouTalkedTo-Start), (Text_Others_CerveauSRoomGoThrough-Start), (Text_Others_HeyZeroYouRe-Start)
	.2byte (Text_Others_OhOneMoreThing-Start), (Text_Others_OperatorMrZeroPleaseCome-Start), (Text_Others_HmmZeroTheyRe-Start), (Text_Others_ThisRecoilRod-Start), (Text_Others_TheWorldIsToo-Start), (Text_Others_SorryThisTookSo-Start), (Text_Others_SelectAMission-Start), (Text_Others_WheneverYouRe-Start)
	.2byte (Text_Others_YouHaveCompleted-Start), (Text_Others_WeHaveToDo-Start), (Text_Others_AllRightOhYeah-Start), (Text_Others_WeLlContactYou-Start), (Text_Others_OkayButPlease-Start), (Text_Others_MasterXDoYouStill-Start), (Text_Others_ButHehehe-Start), (Text_Others_IDrWeilShall-Start)
	.2byte (Text_Others_StillToGossip-Start), (Text_Others_MasterXTheDarkElf-Start), (Text_Others_WeLlGoLeviathanAnd-Start), (Text_Others_Hehehehe-Start), (Text_Others_PreparationsHave-Start), (Text_Others_CielEnterTheCoordi-Start), (Text_Others_ThatSDangerous-Start), (Text_Others_OperatorHurryUpAndPrepare-Start)
	.2byte (Text_Others_ZeroIMNotSure-Start), (Text_Others_Empty-Start), (Text_Others_Okay-Start), (Text_Others_ZeroEllipsis-Start), (Text_Others_ZeroIMSoHappy-Start), (Text_Others_CerveauTookHimTo-Start), (Text_Others_ThenAtLeast-Start), (Text_Others_IStillDonTUnder-Start)
	.2byte (Text_Others_OkayIStillDonT-Start), (Text_Others_SomeoneHasBroken-Start), (Text_Others_PutThemThrough-Start), (Text_Others_CanYouHHHear-Start), (Text_Others_SurrenderHandOverTheNew-Start), (Text_Others_ICanTTrustYou-Start), (Text_Others_YouWerePreparedTo-Start), (Text_Others_IsThatYYour-Start)
	.2byte (Text_Others_TheTransmissionWas-Start), (Text_Others_TheNeoArcadian-Start), (Text_Others_ZeroIYouBelievedIn-Start), (Text_Others_MaintenanceRoomInUse-Start), (Text_Others_SoThisIsWhatIt-Start), (Text_Others_LivesWithPlenty-Start), (Text_Others_YesButFirst-Start), (Text_Others_WeVeIsolatedSome-Start)
	.2byte (Text_Others_AndThereWeVeJust-Start), (Text_Others_ThanksToZero-Start), (Text_Others_OhYesThatReminds-Start), (Text_Others_Okay_2-Start), (Text_Others_CanYouStandUp-Start), (Text_Others_WhatAreYouUpTo-Start), (Text_Others_OhYouReAwakeHow-Start), (Text_Others_WaitYourWoundsAreNot-Start)
	.2byte (Text_Others_SoHarpuiaRefuses-Start), (Text_Others_OperatorMrZeroComeTo-Start), (Text_Others_TheySureRunYou-Start), (Text_Others_ZeroHarpuiaDonTYou-Start), (Text_Others_WeAreAnalyzingThe-Start), (Text_Others_InformationAnalysis-Start), (Text_Others_ZeroIMSorryYou-Start), (Text_Others_File945388-Start)
	.2byte (Text_Others_NearTheEndOfThe-Start), (Text_Others_TheTechnologyUsed-Start), (Text_Others_HeheheheExcellentDetective-Start), (Text_Others_WhatUnfortunatelyYouWereA-Start), (Text_Others_IsThatDrWeil-Start), (Text_Others_HeheheThisTimeOmegaIs-Start), (Text_Others_NowYouWillSee-Start), (Text_Others_TasteTheFearFoolishReploids-Start)
	.2byte (Text_Others_InscribeMyName-Start), (Text_Others_ThatNameIs-Start), (Text_Others_HeheheheheeeBwahahahahah-Start), (Text_Others_No-Start), (Text_Others_RrrGrrph-Start), (Text_Others_ThisCanTBe-Start), (Text_Others_ANewWorld-Start), (Text_Others_CielBack-Start)
	.2byte (Text_Others_ZeroInscribeItUponThe-Start), (Text_Others_BothOfYouFreeze-Start), (Text_Others_ArghItSOkayThey-Start), (Text_Others_TookYouLong-Start), (Text_Others_IIVeVerifiedThe-Start), (Text_Others_RogerAll-Start), (Text_Others_PreparationsFor-Start), (Text_Others_Transfer-Start)
	.2byte (Text_Others_CoordinateData-Start), (Text_Others_TheCoordinates-Start), (Text_Others_ZeroBeCarefulIWill-Start), (Text_Others_YouCanGoAtAny-Start)

Text_Others:: @ 0x08383794
Start:

Text_Others_MsCielPlease: @ 0x08383794
	@ EN: Ms. Ciel, please / cheer up. / Everything's turned / out alright before, / hasn't it?! / That's right. / We believe in you, / Ms. Ciel. And in / Mr. Zero, too! / Thank you, everyone.
	.string "{WINDOW 0x6C}"
		.string "シエルさん、ゲンキ出してください▼"
		.string "今までだって、\n"
		.string "なんとかなったじゃないですか！▼"
	.string "{WINDOW 0x6D}"
		.string "そうですよ…▼"
		.string "ボクたち\n"
		.string "シエルさんや ゼロさんのこと\n"
		.string "シンライしてますから！▼"
	.string "{WINDOW 0x40}"
		.string "あ…ありがとう、みんな………$"

Text_Others_TheSimulationWill: @ 0x083837FB
	@ EN: The simulation will / take a while longer / to finish... / I think we're going / to need your help / again, Zero... / But you should get a / little rest, first. / For now...
	.string "{WINDOW 0x40}"
		.string "シミュレーションの\n"
		.string "ケッカが出るまで\n"
		.string "まだ時間がかかるみたい…▼"
		.string "またゼロに…\n"
		.string "色々おねがいしなければ\n"
		.string "いけなくなると思うの……▼"
		.string "それまで…少しだけでも\n"
		.string "カラダをやすめて…もらえるかしら▼"
		.string "とりあえず……$"

Text_Others_ILlSaveOurData: @ 0x08383869
	@ EN: I'll save our data. / YES / NO
		.string "今までのことをキロクしておくわね…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_Others_ILlTakeCareOf: @ 0x08383887
	@ EN: I'll take care of / managing the data, / just like always. / If you need any- / thing, let me know. / One more thing... / You should go see / Cerveau. / I hear he's finished / his Secret Disk / analyzer. / If you find any / Secret Disks that / you can't analyze, / ask Cerveau to have / a look for you.
	.string "{WINDOW 0x40}"
		.string "データのカンリは、\n"
		.string "いつものように\n"
		.string "わたしがするわね▼"
		.string "何かあったら\n"
		.string "いつでも声をかけて…▼"
		.string "あっそうだ…\n"
		.string "セルヴォのところへ\n"
		.string "かおを出してあげて▼"
		.string "シークレットディスクの\n"
		.string "カイセキそうちが\n"
		.string "カンセイしたみたいなの▼"
		.string "ゼロじゃカイセキできない\n"
		.string "シークレットディスクは\n"
		.string "セルヴォに おねがいするといいわ$"

Text_Others_ShouldnTYouBe: @ 0x0838391F
	@ EN: Shouldn't you be / resting? Don't / overdo it. / I'll manage the / data. Tell me if / you need anything. / One more thing... / You should go see / Cerveau. / I hear he's finished / his Secret Disk / analyzer. / If you find any / Secret Disks that / you can't analyze, / ask Cerveau to have / a look for you.
	.string "{WINDOW 0x40}"
		.string "やすまなくてヘイキ？\n"
		.string "無理はしないでね▼"
		.string "データのカンリは、\n"
		.string "いつものようにわたしがするわね\n"
		.string "何かあったらいつでも声をかけて▼"
		.string "あっそうだ…\n"
		.string "セルヴォのところへ\n"
		.string "かおを出してあげて▼"
		.string "シークレットディスクの\n"
		.string "カイセキそうちが\n"
		.string "カンセイしたみたいなの▼"
		.string "ゼロじゃカイセキできない\n"
		.string "シークレットディスクは\n"
		.string "セルヴォに おねがいするといいわ$"

Text_Others_HaveYouTalkedTo: @ 0x083839CA
	@ EN: Have you talked to / Cerveau yet? / I hear he can't wait / to try out his / disk analyzer!
	.string "{WINDOW 0x40}"
		.string "セルヴォには、もう会ったの？▼"
		.string "セルヴォったら、\n"
		.string "ディスクのカイセキそうちを\n"
		.string "はやく ためしてみたいそうよ$"

Text_Others_CerveauSRoomGoThrough: @ 0x08383A02
	@ EN: Cerveau's room? / Go through the / commander's room to / the right, and it's / the room right in / front of you. / It's convenient / that the base is so / big now, but it sure / is easy to get lost!
	.string "{WINDOW 0x6C}"
		.string "セルヴォのへやですか？▼"
		.string "シレイシツを 右へぬけて、\n"
		.string "手前のへやですよ▼"
		.string "ベースがベンリになるのは\n"
		.string "うれしいですけど…\n"
		.string "こうひろいと まよっちゃいますよね$"

Text_Others_HeyZeroYouRe: @ 0x08383A53
	@ EN: Hey, Zero! You're / all right! / I heard the news. / Despite the new / energy, the world is / still not at peace. / I never thought / peace would be easy, / but still... / ... / Anyway, I just / finished a new / weapon for you. / I also fixed your / S.Boomerang! / Here, take it!
	.string "{WINDOW 0x43}"
		.string "おお！ ゼロ！ 無事だったか！！▼"
		.string "話は聞いたぞ▼"
		.string "せっかく新エネルギーが\n"
		.string "カンセイしたというのに\n"
		.string "和平どころじゃなくなったな…▼"
		.string "もっとも、\n"
		.string "そうかんたんに平和がくるとも…\n"
		.string "考えていなかったがな▼"
		.string "………▼"
		.string "それはそうと\n"
		.string "新しいブキについてなんだが\n"
		.string "たった今、カンセイしたところだ▼"
		.string "それにシールドブーメランも\n"
		.string "シュウリしておいたぞ！▼"
		.string "もっていきなさい！$"

Text_Others_OhOneMoreThing: @ 0x08383B0E
	@ EN: Oh, one more thing. / About Secret Disks. / Secret Disks contain / things that you / can't decode, right? / Well, I can analyze / them for you, so / stop by anytime. / You can also talk to / me if you ever want / to look at the / contents of a disk / we've already / analyzed.
	.string "{WINDOW 0x43}"
		.string "あっ、そうそう\n"
		.string "シークレットディスクに\n"
		.string "ついてなのだが…▼"
		.string "シークレットディスクの中に\n"
		.string "ゼロじゃカイセキできない\n"
		.string "ものがあるだろ？▼"
		.string "そんな時は、\n"
		.string "わたしがカイセキするので\n"
		.string "えんりょなく、話しかけてくれ▼"
		.string "いちどカイセキしたディスクでも\n"
		.string "ナイヨウをカクニンしたい時は\n"
		.string "わたしのところに来なさい$"

Text_Others_OperatorMrZeroPleaseCome: @ 0x08383BA5
	@ EN: Operator: Mr. Zero... / Please come to the / commander's room, / immediately.
	.string "{WINDOW 0x00}"
		.string "オペレーター「ゼロさん、ゼロさん…▼"
		.string "シキュウ、シレイシツまでおこしください…$"

Text_Others_HmmZeroTheyRe: @ 0x08383BCE
	@ EN: Hmm? Zero, they're / asking for you.
	.string "{WINDOW 0x43}"
		.string "ん？ ゼロ…呼んどるようだぞ$"

Text_Others_ThisRecoilRod: @ 0x08383BE0
	@ EN: This Recoil Rod / looks easy to use. / Thanks.
	.string "{WINDOW 0x04}"
		.string "リコイルロッド……使いやすそうだ\n"
		.string "カンシャする…$"

Text_Others_TheWorldIsToo: @ 0x08383BFC
	@ EN: The world is too / much for Ciel to / bear alone... / Take good care of / her, Zero...
	.string "{WINDOW 0x43}"
		.string "シエルにはまだ……\n"
		.string "世界は、おも過ぎる……▼"
		.string "ささえてやってくれ\n"
		.string "ゼロ……$"

Text_Others_SorryThisTookSo: @ 0x08383C26
	@ EN: Sorry this took so / long, Zero. / Are you ready? / We've simulated our / options based on the / information at hand. / I've had the results / prepared in the form / of missions. / The first two are... / Missions to prevent / Neo Arcadia getting / the Dark Elf. / The other two are... / Guerilla attacks / on Neo Arcadia. / to protect everyone / from its threat. / ... / ... / Zero...is fighting / our only option? / I mean, we've / developed this new / energy... / I thought the world / would finally be at / peace... / Do we really have to / keep fighting? / Ciel... / You're already doing / the best you can. / And you're not / alone. / Leave the rest to / us. / Ze...Zero... / Mr. Zero, we're / ready. You can leave / at any time.
	.string "{WINDOW 0x40}"
		.string "またせちゃったわね\n"
		.string "ゼロ…\n"
		.string "ジュンビはいい？▼"
		.string "わたしたちに できることを\n"
		.string "色々なジョウホウをもとに\n"
		.string "シミュレートして…▼"
		.string "そのケッカを\n"
		.string "ミッションのカタチで\n"
		.string "テイアンしてもらったの…▼"
		.string "まず2つは…▼"
		.string "ダークエルフを\n"
		.string "ネオ・アルカディアに\n"
		.string "わたさないためのミッション…▼"
		.string "のこり2つは…▼"
		.string "ネオ・アルカディアから\n"
		.string "みんなを守るためにおこなう▼"
		.string "ネオ・アルカディアへの\n"
		.string "ゲリラこうげきミッション…▼"
		.string "………▼"
		.string "……▼"
		.string "ゼロ…わたしたち……\n"
		.string "戦うしかないのかな……▼"
		.string "せっかく、\n"
		.string "新エネルギーが開発できて……▼"
		.string "これでようやく……\n"
		.string "世界が平和になると思ったのに……▼"
		.string "まだ…戦い続けるしか\n"
		.string "ないっていうの………▼"
	.string "{WINDOW 0x05}"
		.string "シエル……▼"
		.string "オマエにできることは、\n"
		.string "もうジュウブンやっている……▼"
		.string "オマエは、ひとりじゃない▼"
		.string "あとは、オレたちにまかせろ▼"
	.string "{WINDOW 0x40}"
		.string "ゼ…ゼロ……▼"
	.string "{WINDOW 0x62}"
		.string "ゼロさん\n"
		.string "いつでも行けます……$"

Text_Others_SelectAMission: @ 0x08383DB4
	@ EN: Select a mission? / YES / NO
	.string "{WINDOW 0x62}"
		.string "ミッションをセンタクしますか？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_Others_WheneverYouRe: @ 0x08383DD1
	@ EN: Whenever you're / ready, just let me / know.
	.string "{WINDOW 0x62}"
		.string "{TOP}では、ジュンビができましたら\n"
		.string "いつでも声をおかけください…$"

Text_Others_YouHaveCompleted: @ 0x08383DF3
	@ EN: You have completed / all the missions. / This next mission / involves deciding / what to do with a / missile factory / that's been newly / discovered. / We are currently / also searching for / the Dark Elf, / while we look into / solutions for this / problem.
	.string "{WINDOW 0x61}"
		.string "これですべてのミッションが\n"
		.string "シュウリョウしました▼"
		.string "今回のミッションで\n"
		.string "新たに発見されたミサイル工場を\n"
		.string "どうするか…▼"
		.string "現在、\n"
		.string "ダークエルフのタンサクと同時に…▼"
		.string "このモンダイへの\n"
		.string "タイオウをケントウ中です$"

Text_Others_WeHaveToDo: @ 0x08383E65
	@ EN: We have to do / something about that / missile right now. / We had to calculate / the transfer / coordinates for the / missile factory / based on old satel- / lite photographs... / ...so the coordi- / nates would be too / dangerous to use as / a direct transfer / route. / The land route to / the missile factory / is also dangerous, / due to the scout / patrols that are / searching the area. / We're scanning / for the Dark Elf, / but no luck yet. / Understood. / Let me know if / anything changes.
	.string "{WINDOW 0x40}"
		.string "イッコクもはやく\n"
		.string "あのミサイルをなんとか\n"
		.string "したいんだけど…▼"
		.string "ミサイル工場への転送ザヒョウは、\n"
		.string "古いエイセイしゃしんをもとに\n"
		.string "ケイサンしただけだから……▼"
		.string "転送ルートとして使うには、\n"
		.string "あまりにキケンすぎるの▼"
	.string "{WINDOW 0x62}"
		.string "ミサイル工場への地上ルートは、\n"
		.string "テイサツ部隊がソウサク中ですが\n"
		.string "ナンコウしてます▼"
		.string "ダークエルフの方も、\n"
		.string "スキャニングを続けていますが\n"
		.string "まだハンノウがありません▼"
	.string "{WINDOW 0x04}"
		.string "わかった…▼"
		.string "ジョウキョウがかわったら\n"
		.string "おしえてくれ…$"

Text_Others_AllRightOhYeah: @ 0x08383F4B
	@ EN: All right. / Oh, yeah...
	.string "{WINDOW 0x40}"
		.string "わかったわ…▼"
		.string "あっ、そうだ…$"

Text_Others_WeLlContactYou: @ 0x08383F5C
	@ EN: We'll contact you / right away if we / learn anything new. / Please get some rest / until then.
	.string "{WINDOW 0x40}"
		.string "何か わかったら、\n"
		.string "すぐにレンラクするから…\n"
		.string "それまで、ゆっくりやすんで…ね$"

Text_Others_OkayButPlease: @ 0x08383F86
	@ EN: Okay...but please / try not to overdo / it. / We'll contact you / soon, so please get / some rest for now.
	.string "{WINDOW 0x40}"
		.string "そう…でも無理はしないでね▼"
		.string "すぐにレンラクするから…\n"
		.string "それまで、ゆっくりやすんで…ね$"

Text_Others_MasterXDoYouStill: @ 0x08383FB5
	@ EN: Master X... / Do you still trust / that man...Weil? / His banishment did / not follow official / ch-channels. / Just because what he / did resulted i-in a / terrible calamity... / Do-does not mean / that banishing him / was justified. / He has returned to / Neo Arcadia in a / legal manner. / What reason-n is / there to drive him / out? / Don't worr-rr-rry. / He learned many / things from his / mistakes of the / past. / He'll do things / right th-this time.
	.string "{WINDOW 0x2C}"
		.string "エックスさま……▼"
		.string "まだ、あのオトコ…バイルを\n"
		.string "信用されているのですか……？▼"
	.string "{WINDOW 0x37}"
		.string "かレの ツイほウは、\n"
		.string "セイシキな テつヅキをとらず\n"
		.string "実行された…▼"
		.string "カレが おこなったコとが\n"
		.string "ケッカとして、おおキなヒゲキを\n"
		.string "ひきおこしたからといって…▼"
		.string "ホウリツをムシして…\n"
		.string "カレを ツイホウしたことは、\n"
		.string "アヤまりだト おもわないかい？▼"
		.string "今回かレは、ゴウホウ的にこの\n"
		.string "ネオ・アルかでィアにフッキした▼"
		.string "カレをハイジョするリユウが\n"
		.string "ドコニあるんダ▼"
		.string "シンパイいらないよ\n"
		.string "カレも過去のアヤマチから…\n"
		.string "多くのものをマナんだ…▼"
		.string "今度こそウマくやるに\n"
		.string "チガいなイ……$"

Text_Others_ButHehehe: @ 0x083840CD
	@ EN: But... / Hehehe... / Thank you, Master X.
	.string "{WINDOW 0x2C}"
		.string "ですが…！▼"
	.string "{WINDOW 0x3B}"
		.string "クックック…\n"
		.string "さすがは、エックスさま$"

Text_Others_IDrWeilShall: @ 0x083840EA
	@ EN: I, Dr. Weil, shall / never repeat my / past mistakes. / Never again. Yes. / Hehehe...
	.string "{WINDOW 0x3B}"
		.string "このバイル、\n"
		.string "同じアヤマチは、\n"
		.string "にどとおかしません▼"
		.string "そう…にどと……ね\n"
		.string "クックック…$"

Text_Others_StillToGossip: @ 0x08384118
	@ EN: Still, to gossip / about me behind my / back... / My, how the almighty / Four Guardians have / fallen! / What?! Weil!
	.string "{WINDOW 0x3B}"
		.string "{BOTTOM}しかし…\n"
		.string "ワシのいないところで\n"
		.string "かげぐちとは…▼"
		.string "かつての四天王も\n"
		.string "おちたものですな▼"
	.string "{WINDOW 0x2C}"
		.string "{BOTTOM}なんだと……バイル…！$"

Text_Others_MasterXTheDarkElf: @ 0x08384157
	@ EN: Master X. / The Dark Elf has / appeared in Neo / Arcadia. / Area Z-3079... / It's the farthest / area from here. / A human / residential / district.
	.string "{WINDOW 0x3B}"
		.string "ところでエックスさま▼"
		.string "ダークエルフが\n"
		.string "ネオ・アルカディアに\n"
		.string "現れたもようです▼"
		.string "エリアZ-3079…\n"
		.string "ここから、もっともはなれた\n"
		.string "人間の きょじゅうくなんですが…$"

Text_Others_WeLlGoLeviathanAnd: @ 0x083841AD
	@ EN: We'll go. / Leviathan and / Fefnir are still / undergoing / maintenance, but if / we hurry things / along a bit... / Harpuia, how long do / you plan to act like / you're in charge? / Letting th-the / Resistance get away / with countless / uprisings... / Even letting th-the / Dark Elf escape... / I'm tired of useless / p-people like you. / The Four Guardians / are going to be / stepped down. / But...Master X?! / Dr. Weil... / I'm entrusting you / with the leadership / of our ar-armies. / Will you accept?
	.string "{WINDOW 0x2C}"
		.string "われわれが行きます▼"
		.string "レヴィアタンとファーブニルは、\n"
		.string "まだメンテナンス中ですが…\n"
		.string "いそがせれば…▼"
	.string "{WINDOW 0x37}"
		.string "いツまで カンブきどりダ\n"
		.string "ハルピュイア……▼"
		.string "たびかサなる レジスタンスの\n"
		.string "はんらんヲ ゆるし…▼"
		.string "ついには ダークエルフまデも…\n"
		.string "にがした…▼"
		.string "おマエたちノヨうな ノウナシには\n"
		.string "もウ、あキアきした▼"
		.string "キみたち四天王は…\n"
		.string "カンブから オリてもらウよ…▼"
	.string "{WINDOW 0x2C}"
		.string "なっ…エックスさま…！？▼"
	.string "{WINDOW 0x37}"
		.string "ドクター・バイル…▼"
		.string "全軍のシキは…\n"
		.string "キミにまカせる▼"
		.string "やっテクれる…ナ$"

Text_Others_Hehehehe: @ 0x08384296
	@ EN: Hehehehe... / Yes sir! / I will capture the / Dark Elf, without / fail... / ...Before she falls / into the hands of / the Resistance and / becomes a threat to / this world...
	.string "{WINDOW 0x3B}"
		.string "クーックックックッ…\n"
		.string "リョウカイいたしました…▼"
		.string "かならずやダークエルフを\n"
		.string "手に入れましょう▼"
		.string "レジスタンスの手にわたり…\n"
		.string "この世界のキョウイとならぬよう…\n"
		.string "クーックックッ$"

Text_Others_PreparationsHave: @ 0x083842F2
	@ EN: Preparations have / begun for the launch / of the missile. / We do not know the / target area, but we / are attempting to / hack our way in and / find out. / A tremendous energy / is emanating / from the missile. / It seems that Omega / is on board. / Omega?! / That Omega, on the / missile!? / ...
	.string "{WINDOW 0x61}"
		.string "巨大ミサイルが\n"
		.string "ハッシャじゅんびに入りました▼"
		.string "モクヒョウとされるエリアは不明\n"
		.string "現在ハッキングにてチョウサ中▼"
	.string "{WINDOW 0x62}"
		.string "ミサイルに\n"
		.string "強力なエネルギーはんのう▼"
		.string "ミサイルには、\n"
		.string "オメガがつまれているもようです▼"
	.string "{WINDOW 0x40}"
		.string "オメガ！？▼"
		.string "あのオメガがミサイルに！！▼"
	.string "{WINDOW 0x04}"
		.string "………$"

Text_Others_CielEnterTheCoordi: @ 0x0838437D
	@ EN: Ciel... / Enter the coordi- / nates you found.
	.string "{WINDOW 0x04}"
		.string "シエル…▼"
		.string "オマエがカイセキした\n"
		.string "ザヒョウを入力させろ$"

Text_Others_ThatSDangerous: @ 0x0838439C
	@ EN: That's...dangerous!
	.string "{WINDOW 0x40}"
		.string "そんな…キケンだわ！$"

Text_Others_OperatorHurryUpAndPrepare: @ 0x083843A9
	@ EN: Operator. / Hurry up and prepare / for transfer.
	.string "{WINDOW 0x04}"
		.string "オペレーター▼"
		.string "転送ジュンビいそげ$"

Text_Others_ZeroIMNotSure: @ 0x083843BE
	@ EN: Zero, I'm not sure / about this! / I believe in you.
	.string "{WINDOW 0x40}"
		.string "ゼロ……自信がない！！▼"
	.string "{WINDOW 0x04}"
		.string "オレは、オマエを信じている$"

Text_Others_Empty: @ 0x083843DF
	@ EN: ...
	.string "{WINDOW 0x40}"
		.string "………………$"

Text_Others_Okay: @ 0x083843E8
	@ EN: Okay... / ... / Enter...the data... / Please, transfer / him! / Understood. / Commencing transfer / preparations.
	.string "{WINDOW 0x40}"
		.string "わかった……\n"
		.string "………\n"
		.string "データを…入力して………▼"
		.string "転送……おねがい！▼"
	.string "{WINDOW 0x61}"
		.string "リョウカイ\n"
		.string "転送ジュンビかいし…$"

Text_Others_ZeroEllipsis: @ 0x08384425
	@ EN: Zero...
	.string "{WINDOW 0x40}"
		.string "ゼロ………$"

Text_Others_ZeroIMSoHappy: @ 0x0838442D
	@ EN: Zero... / I'm so happy that / you're safe... / Please...never do / anything as crazy as / that again.... / ... / I'll think about it. / By the way... / How is Harpuia?
	.string "{WINDOW 0x40}"
		.string "ゼロ………▼"
		.string "ほんとに…無事でよかった……▼"
		.string "もう……にどと………\n"
		.string "あんなむちゃ……しないでね\n"
		.string "おねがいよ………▼"
	.string "{WINDOW 0x05}"
		.string "………\n"
		.string "考えておこう……▼"
		.string "ところで……\n"
		.string "ハルピュイアは…？$"

Text_Others_CerveauTookHimTo: @ 0x08384489
	@ EN: Cerveau took him to / the maintenance / room. / He wasn't hurt very / badly, but... / He'll have to rest / and recuperate for / a while. / ... / Things really have / gotten horrible... / The operators will / collect as much / info as possible. / Analyzing all of the / information will / take a while. / Try to get some rest / until then. / I'm all right.
	.string "{WINDOW 0x40}"
		.string "セルヴォがメンテナンス・ルームに\n"
		.string "つれていったわ▼"
		.string "キズは、それほど\n"
		.string "深くないみたいだけど……▼"
		.string "しばらく あんせいにしないと\n"
		.string "だめみたい………▼"
		.string "…………▼"
		.string "ほんとに………\n"
		.string "タイヘンなことに\n"
		.string "なってしまったわね……▼"
		.string "今、オペレーターさんたちに\n"
		.string "カノウなかぎり ジョウホウを\n"
		.string "集めてもらってるわ▼"
		.string "ブンセキには、時間がかかりそうなの\n"
		.string "それまで、少しやすんでいて…▼"
	.string "{WINDOW 0x05}"
		.string "だいじょうぶだ$"

Text_Others_ThenAtLeast: @ 0x0838454C
	@ EN: Then, at least...
	.string "{WINDOW 0x40}"
		.string "じゃあ、せめて……$"

Text_Others_IStillDonTUnder: @ 0x08384558
	@ EN: I still don't under- / stand how Neo / Arcadia could fire a / missile into an / area where humans / live... / ...even to obtain / the Dark Elf...
	.string "{WINDOW 0x40}"
		.string "…それにしても、\n"
		.string "ダークエルフのためとは言え…▼"
		.string "ネオ・アルカディアが\n"
		.string "人間たちのいるエリアに\n"
		.string "ミサイルを おとすなんて…$"

Text_Others_OkayIStillDonT: @ 0x0838459A
	@ EN: Okay... / I still don't under- / stand how Neo / Arcadia could fire a / missile into an / area where humans / live... / ...even to obtain / the Dark Elf.
	.string "{WINDOW 0x40}"
		.string "そう…わかったわ……▼"
		.string "…それにしても、\n"
		.string "ダークエルフのためとは言え…▼"
		.string "ネオ・アルカディアが\n"
		.string "人間たちのいるエリアに\n"
		.string "ミサイルを おとすなんて…$"

Text_Others_SomeoneHasBroken: @ 0x083845E7
	@ EN: Someone has broken / into our trans- / mission circuit! / It's Neo Arcadia!
	.string "{WINDOW 0x61}"
		.string "ツウシンかいせんに\n"
		.string "キョウセイわりこみ……！▼"
		.string "ネオ・アルカディアからです！$"

Text_Others_PutThemThrough: @ 0x0838460F
	@ EN: Put them through!
	.string "{WINDOW 0x05}"
		.string "つなげろ！$"

Text_Others_CanYouHHHear: @ 0x08384617
	@ EN: Can you h-h-hear me? / Members of the / Resistance. / And...Dr. C-Ciel. / Copy X! / We have custody of / the D-Dark Elf. / Let us put a-a / stop to this foolish / conflict. / We ask that you / surrender t-to us.
	.string "{WINDOW 0x36}"
		.string "{BOTTOM}ギ…ギギッ…きコえるカい…\n"
		.string "レジスタンスのショクん…▼"
		.string "ソして…ドクター・シエル…▼"
	.string "{WINDOW 0x41}"
		.string "コピー…エックス……！▼"
	.string "{WINDOW 0x36}"
		.string "ダークエルフは、ついに\n"
		.string "われワれの もノと ナっタ…▼"
		.string "くダらない アラソいは、\n"
		.string "オわリに しタい…▼"
		.string "キミたちに コウフクを\n"
		.string "よびカけるこトに したよ$"

Text_Others_SurrenderHandOverTheNew: @ 0x0838469E
	@ EN: Surrender? / Hand over the new / energy you invented, / the Ciel System. / If you do this, I / guarantee the safety / of you Mavericks. / He's got to be... / As a result of our / analysis of the / Ciel System / information you so / kindly sent us... / We have determined / that by combining it / with the Dark Elf, / it may be possible / to generate enormous / amounts of energy. / This would solve the / energy crisis in / one fell swoop. / There would no / longer be a reason / for us to fight. / Ciel... / A single answer from / you will bring peace / t-to the world.
	.string "{WINDOW 0x40}"
		.string "コウフクですって…？▼"
	.string "{WINDOW 0x3B}"
		.string "キミの発明した新エネルギー\n"
		.string "システマ・シエルを\n"
		.string "われわれに わたしてほしい▼"
		.string "そうすれば、\n"
		.string "キミたちイレギュラーの\n"
		.string "安全は、ホショウしよう…▼"
	.string "{WINDOW 0x40}"
		.string "そんな……▼"
	.string "{WINDOW 0x3B}"
		.string "キミが送ってくれた\n"
		.string "システマ・シエルのジョウホウを\n"
		.string "カイセキしたケッカ…▼"
		.string "ダークエルフと\n"
		.string "くみあわせることにより……▼"
		.string "バクダイなエネルギーを\n"
		.string "生み出すカノウセイが\n"
		.string "あることがわかったのだよ▼"
		.string "これでエネルギー不足は、\n"
		.string "いっきょにカイケツ▼"
		.string "もう、オマエたちを\n"
		.string "ショブンするヒツヨウもない……▼"
	.string "{WINDOW 0x37}"
		.string "シエル…▼"
		.string "キみのコタエひとつで\n"
		.string "世界は、平和になルんだよ…$"

Text_Others_ICanTTrustYou: @ 0x083847BB
	@ EN: ... / I can't... / trust...you. / What's th-that?
	.string "{WINDOW 0x40}"
		.string "……………▼"
		.string "あなたたちは……▼"
		.string "信用……できません………▼"
	.string "{WINDOW 0x37}"
		.string "…なんだっテ？$"

Text_Others_YouWerePreparedTo: @ 0x083847E5
	@ EN: You were prepared to / sacrifice humans to / obtain the Dark Elf! / I cannot trust you / after seeing that. / You cannot have the / Ciel System. / It was built so that / humans and Reploids / could live in peace!
	.string "{WINDOW 0x40}"
		.string "ダークエルフを手に入れるために\n"
		.string "人間をぎせいにするような……▼"
		.string "そんな…あなたたちは……\n"
		.string "信用できません！▼"
		.string "システマ・シエルは、わたさない▼"
		.string "これは、人とレプリロイドが\n"
		.string "平和にくらすためのものだから！$"

Text_Others_IsThatYYour: @ 0x08384853
	@ EN: Is that...y-your / answer? / Fine. / You have a-a / monopoly on energy / resources... / And Zero, a Reploid / with terrifying / f-fighting skills... / Y-you are nothing / more than filthy / extremists! / Ciel... / I was holding-ng / back until now, / because you were / there, a human... / Now, you can face / the consequences, / along with your / Maverick friends!
	.string "{WINDOW 0x37}"
		.string "{BOTTOM}…そレが…こたえか…▼"
		.string "いいだろウ…▼"
		.string "エネルギーしげんを\n"
		.string "ドクセンし……▼"
		.string "ゼロという、\n"
		.string "おそロシい戦闘力をモつ\n"
		.string "レプリロイドを ホユウしていル……▼"
		.string "おまエタちなど、もハヤ\n"
		.string "たダノ うすヨごれた テロリストだ▼"
		.string "シエル…\n"
		.string "人間のおまエガ いたかラ\n"
		.string "いマまで、テカゲンしてイタが…▼"
		.string "イレギュラー ともドモ\n"
		.string "ショブンしてヤる！$"

Text_Others_TheTransmissionWas: @ 0x083848FA
	@ EN: The transmission was / cut off.
	.string "{WINDOW 0x61}"
		.string "ツウシンとだえました$"

Text_Others_TheNeoArcadian: @ 0x08384907
	@ EN: The Neo Arcadian / military has begun / advancing on our / base from multiple / areas. / They've launched a / total offensive.
	.string "{WINDOW 0x62}"
		.string "ネオ・アルカディア軍が\n"
		.string "かくエリアから べースへ向けて\n"
		.string "シンコウを カイシしました▼"
		.string "ソウコウゲキを\n"
		.string "しかけてくるもようです$"

Text_Others_ZeroIYouBelievedIn: @ 0x08384949
	@ EN: Zero...I... / You believed in / yourself, and fought / accordingly. / What comes next... / is my job. / Tell me which areas / they are in. / I will intercept. / Zero... / Displaying the Neo / Arcadian movements / on the monitor...
	.string "{WINDOW 0x40}"
		.string "ゼロ……わたし………▼"
	.string "{WINDOW 0x05}"
		.string "オマエは自分を信じて戦った▼"
		.string "ここからは…\n"
		.string "オレのシゴトだ…▼"
		.string "ヤツらのいるエリアをおしえろ\n"
		.string "ゲイゲキする▼"
	.string "{WINDOW 0x40}"
		.string "ゼ…ゼロ…………▼"
	.string "{WINDOW 0x61}"
		.string "ネオ・アルカディアの\n"
		.string "しんこうルートを\n"
		.string "モニターにヒョウジします$"

Text_Others_MaintenanceRoomInUse: @ 0x083849BE
	@ EN: Maintenance room in use...
	.string "{WINDOW 0x00}"
		.string "メンテナンス・ルーム 使用中…$"

Text_Others_SoThisIsWhatIt: @ 0x083849D3
	@ EN: So this is what it / has come to... / Dr. Weil as the / ruler of Neo / Arcadia... / Those humans haven't / been told a thing... / No, that's not it. / They haven't tried / to learn a thing...
	.string "{WINDOW 0x40}"
		.string "とうとう\n"
		.string "ドクター・バイルが……▼"
		.string "ネオ・アルカディアの\n"
		.string "シハイシャに\n"
		.string "なってしまったわね………▼"
	.string "{WINDOW 0x05}"
		.string "何も知らされていない\n"
		.string "人間たち…▼"
		.string "いや…\n"
		.string "何も知ろうとしない\n"
		.string "人間たち…か$"

Text_Others_LivesWithPlenty: @ 0x08384A35
	@ EN: Lives with plenty / of food and / comfort... / People have stopped / bothering to think / with their heads... / There may still be / some people who want / to do something. / If we could somehow / let those kinds of / people know what / Dr. Weil is really / thinking... / We might be able to / change Neo Arcadia. / Who is this / Dr. Weil, anyway? / What has he been / doing since he / reappeared? / If you can gather / some information... / We might be able to / analyze it to / determine where he / is presently, and / what he's been doing / until now. / Okay. / Where do I need to / Go. Just tell me...
	.string "{WINDOW 0x40}"
		.string "たべものにも、\n"
		.string "すむバショにも不自由しない\n"
		.string "セイカツ……▼"
		.string "人々は、だんだん…\n"
		.string "自分のアタマで\n"
		.string "考えようとしなくなった……▼"
		.string "でも…中には、\n"
		.string "何とかしたいと思っている人が\n"
		.string "いるかもしれない▼"
		.string "ドクター・バイルが\n"
		.string "何を考えているのか…▼"
		.string "そんな人たちに\n"
		.string "伝えることができたら……▼"
		.string "ネオ・アルカディアを\n"
		.string "かえることができるかもしれない…▼"
	.string "{WINDOW 0x61}"
		.string "ドクター・バイルは\n"
		.string "いったい何者なのか……▼"
		.string "この世界に再び現れてから\n"
		.string "今まで何をやっていたのか……▼"
	.string "{WINDOW 0x62}"
		.string "ジョウホウを\n"
		.string "集めていただければ……▼"
		.string "カレが今どこにいるか…\n"
		.string "何をしようとしているのか…\n"
		.string "ブンセキできるかもしれません▼"
	.string "{WINDOW 0x05}"
		.string "わかった▼"
		.string "どこへ行けばいいか\n"
		.string "おしえてくれ…$"

Text_Others_YesButFirst: @ 0x08384B81
	@ EN: Yes, but first...
	.string "{WINDOW 0x40}"
		.string "ええ、でも その前に…$"

Text_Others_WeVeIsolatedSome: @ 0x08384B90
	@ EN: We've isolated some / locations for you to / gather information.
	.string "{WINDOW 0x61}"
		.string "ジョウホウが\n"
		.string "入手できそうなバショを\n"
		.string "ピックアップしてみました$"

Text_Others_AndThereWeVeJust: @ 0x08384BB4
	@ EN: And...there. / We've just finished / inputting the data / recovered so far. / Now, to begin the / analysis.
	.string "{WINDOW 0x61}"
		.string "ゼロさんが今までカイシュウされた\n"
		.string "データの入力……▼"
		.string "今、終わりました▼"
	.string "{WINDOW 0x62}"
		.string "カイセキにうつります$"

Text_Others_ThanksToZero: @ 0x08384BEB
	@ EN: Thanks to Zero, / we've collected / much information. / It will take time to / analyze the data, so / for now...
	.string "{WINDOW 0x40}"
		.string "ゼロのおかげで、\n"
		.string "いろいろなジョウホウが\n"
		.string "集まったわ……▼"
		.string "カイセキが終わるまで\n"
		.string "少し時間がかかりそうだから\n"
		.string "今のうちに……$"

Text_Others_OhYesThatReminds: @ 0x08384C31
	@ EN: Oh yes, that reminds / me. / Cerveau told me that / Harpuia's condition / has improved a lot. / Why don't you go / pay your respects?
	.string "{WINDOW 0x40}"
		.string "あっ、そうだ\n"
		.string "そういえばセルヴォが……▼"
		.string "ハルピュイアのカラダ……\n"
		.string "だいぶん よくなったって\n"
		.string "言ってたわ…▼"
		.string "おみまいに……\n"
		.string "行ってあげたら…どうかしら？$"

Text_Others_Okay_2: @ 0x08384C81
	@ EN: Okay... / But please, don't / overdo it. / Oh yes, that reminds / me. / Cerveau told me that / Harpuia's condition / has improved a lot. / Why don't you go / pay your respects?
	.string "{WINDOW 0x40}"
		.string "わかったわ…\n"
		.string "でも……無理…しないでね……▼"
		.string "あっ、そうだ\n"
		.string "そういえばセルヴォが……▼"
		.string "ハルピュイアのカラダ……\n"
		.string "だいぶん よくなったって\n"
		.string "言ってたわ…▼"
		.string "おみまいに……\n"
		.string "行ってあげたら…どうかしら？$"

Text_Others_CanYouStandUp: @ 0x08384CE9
	@ EN: Can you stand up / already? / Wow, Harpuia, you're / hard to keep down...
	.string "{WINDOW 0x04}"
		.string "もう…たてるのか▼"
		.string "さすがだな\n"
		.string "ハルピュイア……$"

Text_Others_WhatAreYouUpTo: @ 0x08384D03
	@ EN: What are you up to? / Why did you rescue / me? / Do you expect some / favor in return? / Perhaps.
	.string "{WINDOW 0x2D}"
		.string "どういうつもりだ？\n"
		.string "なぜ助けた？▼"
		.string "かりはかえすとでも言いたいのか！？▼"
	.string "{WINDOW 0x04}"
		.string "さあな$"

Text_Others_OhYouReAwakeHow: @ 0x08384D30
	@ EN: Oh, you're awake. / How do you feel? / Horrible. / Just the thought of / being helped by you / makes me nauseous. / Stripped of my / position, and driven / out of Neo Arcadia. / I'm used goods... / That's not true. / You just stood up / for your beliefs, / just like we do. / You've made no / mistakes. / My beliefs... / I can't sit back / any longer... / We must protect the / humans from Weil. / We have to stop him / immediately. That... / that...Weil!!!
	.string "{WINDOW 0x42}"
		.string "おお、気がついたか▼"
		.string "気分はどうだね？▼"
	.string "{WINDOW 0x2D}"
		.string "…サイアクだな▼"
		.string "キサマらに助けられたかと思うと\n"
		.string "ハキケがする▼"
		.string "カンブを おろされ…\n"
		.string "ネオ・アルカディアを おわれ\n"
		.string "オレもおちたものだ…▼"
	.string "{WINDOW 0x42}"
		.string "そんなことは ないよ▼"
		.string "キミは自分の考えを\n"
		.string "つらぬいただけだ…\n"
		.string "わたしたちと同じようにね▼"
		.string "何も まちがっては\n"
		.string "いないさ▼"
	.string "{WINDOW 0x2D}"
		.string "自分の考え…か…▼"
		.string "もうこれ以上\n"
		.string "ねてなどいられない……▼"
		.string "バイルから…\n"
		.string "人間たちを守ってやらねば\n"
		.string "ならんのだ………▼"
		.string "はやくアイツを止めなければ……\n"
		.string "アイツは……アイツは…！$"

Text_Others_WaitYourWoundsAreNot: @ 0x08384E33
	@ EN: Wait! / Your wounds are not / fully healed yet! / I am a warrior, born / to protect humans. / I am a proud warrior / of Neo Arcadia! I / don't need any help! / Even if my body / should fall into / ruin... / I will still gladly / fight for humanity!
	.string "{WINDOW 0x42}"
		.string "まちたまえ！▼"
		.string "キミのキズはまだカンゼンには\n"
		.string "なおっていないんだ！▼"
	.string "{WINDOW 0x2D}"
		.string "オレは……\n"
		.string "人間を守るために生まれた戦士…▼"
		.string "ほこりたかき\n"
		.string "ネオ・アルカディアの戦士だ！\n"
		.string "キサマらの 助けなどいらない！▼"
		.string "たとえこのカラダが\n"
		.string "くちはてようとも……▼"
		.string "人間のためなら\n"
		.string "よろこんで戦おう！$"

Text_Others_SoHarpuiaRefuses: @ 0x08384EC7
	@ EN: So... / Harpuia refuses / to go with us. / ...
	.string "{WINDOW 0x42}"
		.string "やはり…われわれとは▼"
		.string "いっしょに\n"
		.string "行けないというのか…▼"
	.string "{WINDOW 0x04}"
		.string "………$"

Text_Others_OperatorMrZeroComeTo: @ 0x08384EEC
	@ EN: Operator: Mr. Zero... / Come to the commander's / room immediately.
	.string "{WINDOW 0x00}"
		.string "オペレーター「ゼロさん、ゼロさん…▼"
		.string "シキュウ、シレイシツまでおこしください…$"

Text_Others_TheySureRunYou: @ 0x08384F15
	@ EN: They sure run you / ragged, don't they, / Zero. / I'll be back later.
	.string "{WINDOW 0x42}"
		.string "いきつくひまもないな…\n"
		.string "ゼロ……▼"
	.string "{WINDOW 0x04}"
		.string "…行ってくる$"

Text_Others_ZeroHarpuiaDonTYou: @ 0x08384F32
	@ EN: Zero... / Harpuia... / Don't you dare / die...
	.string "{WINDOW 0x42}"
		.string "ゼロ……▼"
		.string "ハルピュイア……▼"
		.string "みんな…死ぬんじゃないぞ……$"

Text_Others_WeAreAnalyzingThe: @ 0x08384F52
	@ EN: We are analyzing the / data. Please wait a / little longer.
	.string "{WINDOW 0x61}"
		.string "データのカイセキ中です\n"
		.string "しばらく おまちください$"

Text_Others_InformationAnalysis: @ 0x08384F6E
	@ EN: Information analysis / is complete. / Ms. Ciel will report / on what we've found.
	.string "{WINDOW 0x61}"
		.string "ジョウホウのカイセキ…\n"
		.string "カンリョウしました▼"
		.string "シエルさんから\n"
		.string "ホウコクしていただきます……$"

Text_Others_ZeroIMSorryYou: @ 0x08384F9D
	@ EN: Zero... I'm sorry. / You gathered a lot / of information for / us, but... / We still do not know / where Weil is. / But we have figured / out what he might / be attempting to do. / Before we talk about / Weil... / I'll open the data / file for the Elf / Wars that you found.
	.string "{WINDOW 0x40}"
		.string "ゼロ…ごめんなさい▼"
		.string "せっかくゼロにいろいろな\n"
		.string "ジョウホウを\n"
		.string "集めてもらったのに……▼"
		.string "バイルがどこにいるかまでは、\n"
		.string "わからなかったわ▼"
		.string "でも…バイルが\n"
		.string "何をしようとしているのか……\n"
		.string "それは少し わかったかもしれないの▼"
		.string "バイルの話をする前に\n"
		.string "まず……▼"
		.string "ゼロが見つけてくれた\n"
		.string "ヨウセイ戦争の\n"
		.string "データファイルをひらくわね$"

Text_Others_File945388: @ 0x08385043
	@ EN: File ↾945388 / == Elf Wars ==
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ファイルナンバー945388\n"
		.string "--ヨウセイ戦争--$"

Text_Others_NearTheEndOfThe: @ 0x08385062
	@ EN: Near the end of the / Maverick Wars, many / Cyber-elves were used... / The period from this time / until the end of the / fighting was referred to as / the Elf Wars, as a result. / In particular, the use of / the gigantic elf known as / the "Dark Elf," / and copies of this / elf, known as "Baby / Elves," / to amplify the power / of Reploids... / while controlling / said Reploids at / will... / made this the worst / war in recorded / history... / While use of the Dark / Elf brought the war to / an end in four years... / Approximately 90% of / all Reploids, / and 60% of all humans, / were wiped out.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}イレギュラー戦争の終わりごろ、\n"
		.string "サイバーエルフがタイリョウに\n"
		.string "使用されたことから……▼"
		.string "これ以後、戦争が終わるまでを\n"
		.string "ヨウセイ戦争と呼ぶ▼"
		.string "とくにダークエルフと呼ばれる\n"
		.string "ちょう大型ヨウセイと…▼"
		.string "そのコピーであるベビーエルフの\n"
		.string "使用により……▼"
		.string "レプリロイドのチカラを\n"
		.string "ゾウフクさせ……▼"
		.string "同時に思いどおりに\n"
		.string "コントロールすることが\n"
		.string "カノウになってからは……▼"
		.string "かつてないほどの……\n"
		.string "最悪の戦争となった……▼"
		.string "戦争は、ダークエルフ使用により\n"
		.string "4年でシュウケツするが……▼"
		.string "レプリロイドのほぼ90%……▼"
		.string "人間の60%がシメツした……$"

Text_Others_TheTechnologyUsed: @ 0x08385187
	@ EN: The technology used / at this time... / ...the technology of / using Baby Elves to / control Reploids. / This must be what / Weil is attempting / to use again. / I'm sure that what / Zero saw at the Dark / Elf copy factory, / was machinery / prepared for just / this purpose.
	.string "{WINDOW 0x40}"
		.string "この時、使用したギジュツ……▼"
		.string "ベビーエルフを使って\n"
		.string "レプリロイドを思いどおりに\n"
		.string "コントロールするギジュツを▼"
		.string "バイルは、再び\n"
		.string "使用しようと\n"
		.string "してるんじゃないかしら……▼"
		.string "ゼロが\n"
		.string "ダークエルフのコピー工場で\n"
		.string "見たものは▼"
		.string "きっと、そのために 用意した\n"
		.string "モノだと思うんだけど……$"

Text_Others_HeheheheExcellentDetective: @ 0x0838521D
	@ EN: ... / Hehehehe... / Excellent detective / work, Dr. Ciel.
	.string "{WINDOW 0x62}"
		.string "………▼"
		.string "クックックック……▼"
		.string "よくしらべたな\n"
		.string "ドクター・シエル……$"

Text_Others_WhatUnfortunatelyYouWereA: @ 0x08385240
	@ EN: What? / Unfortunately... / ...you were a little / too late.
	.string "{WINDOW 0x40}"
		.string "な？▼"
	.string "{WINDOW 0x61}"
		.string "だが少し………▼"
		.string "おそすぎたんじゃないかね$"

Text_Others_IsThatDrWeil: @ 0x0838525D
	@ EN: Is that Dr. Weil?!
	.string "{WINDOW 0x04}"
		.string "ドクター・バイルか！？$"

Text_Others_HeheheThisTimeOmegaIs: @ 0x0838526B
	@ EN: Hehehe... / This time, Omega is / absolutely perfect. / I can now manipulate / all the Reploids on / the planet, / without using the / Baby Elves, / and make them do / whatever I want! / Hehehehe... / Time to start, / Omega.
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}クーックックッ…▼"
		.string "今度のオメガは、まさに\n"
		.string "カンペキだ……▼"
		.string "もう、ベビーエルフなど\n"
		.string "使わなくとも…▼"
		.string "この世界…\n"
		.string "すべてのレプリロイドを▼"
		.string "思うがままに\n"
		.string "あやつれるようになったのだ！！▼"
		.string "クーックックックッ…\n"
		.string "さあ…はじめるとするか…\n"
		.string "オメガよ…$"

Text_Others_NowYouWillSee: @ 0x083852EC
	@ EN: Now you will see, / pitiful humans, / what you get for / banishing Dr. Weil!
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}今こそ思い知れ…▼"
		.string "ワシをツイホウした\n"
		.string "人間どもよ！$"

Text_Others_TasteTheFearFoolishReploids: @ 0x0838530E
	@ EN: Taste the fear... / Foolish Reploids, / who banished me!
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}キョウフしろ…▼"
		.string "ワシをツイホウした\n"
		.string "レプリロイドどもよ！$"

Text_Others_InscribeMyName: @ 0x0838532E
	@ EN: Inscribe my name, / upon this world... / The name of your / new ruler!
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}きざみこむのだ\n"
		.string "この世界に…▼"
		.string "シハイシャたるワシの名を！$"

Text_Others_ThatNameIs: @ 0x08385351
	@ EN: That name is / Dr. Weil. / The entire world is / in my hands... / I have the power to / crush it between my / fingers at any time!
	.string "{WINDOW 0x3A}"
		.string "{BOTTOM}わが名はドクター・バイル▼"
		.string "世界は、わが手の中にある…\n"
		.string "この手をにぎりしめるだけで……▼"
		.string "この世界を終わらすことが\n"
		.string "できるのだ！！$"

Text_Others_HeheheheheeeBwahahahahah: @ 0x0838539D
	@ EN: Heheheheheee... / Bwahahahahah!
	.string "{WINDOW 0x61}"
		.string "クーックックックッ…▼"
		.string "クヒャーッハッハッハッハッ！$"

Text_Others_No: @ 0x083853B9
	@ EN: No!
	.string "{WINDOW 0x40}"
		.string "まっ、まさか！？$"

Text_Others_RrrGrrph: @ 0x083853C4
	@ EN: Rrr...grrph...
	.string "{WINDOW 0x5F}"
		.string "う…うう…$"

Text_Others_ThisCanTBe: @ 0x083853CC
	@ EN: This can't be / happening!
	.string "{WINDOW 0x40}"
		.string "そ、そんな……！$"

Text_Others_ANewWorld: @ 0x083853D7
	@ EN: A new world... / A new order... / History is once / again in motion...
	.string "{WINDOW 0x5E}"
		.string "新たなる世界…\n"
		.string "新たなるチツジョ…▼"
		.string "とじられたレキシが…\n"
		.string "再び 動きはじめる…$"

Text_Others_CielBack: @ 0x08385407
	@ EN: Ciel! Back!
	.string "{WINDOW 0x05}"
		.string "さがれ！ シエル！$"

Text_Others_ZeroInscribeItUponThe: @ 0x08385413
	@ EN: Zero?! / Inscribe it upon the / world... The name of / our ruler... / Weil! Weil! Weil! / Weil! Weil! Weil! / Weil! Weil! Weil!
	.string "{WINDOW 0x40}"
		.string "ゼロ！？▼"
	.string "{WINDOW 0x5E}"
		.string "世界にきざめ…\n"
		.string "われらのシハイシャの名は…▼"
		.string "バイル！ バイル！ バイル！\n"
		.string "バイル！ バイル！ バイル！\n"
		.string "バイル！ バイル！ バイル！$"

Text_Others_BothOfYouFreeze: @ 0x08385462
	@ EN: Both of you, freeze!
	.string "{WINDOW 0x34}"
		.string "ふたりとも、動かないで！$"

Text_Others_ArghItSOkayThey: @ 0x08385472
	@ EN: Argh! / It's okay. They're / just unconscious. / All I did was / disable the power of / the Dark Elf. / But my current power / can only protect / those at this base.
	.string "{WINDOW 0x40}"
		.string "あ…！▼"
	.string "{WINDOW 0x34}"
		.string "だいじょうぶ…\n"
		.string "気をうしなっているだけだよ▼"
		.string "ダークエルフのチカラを\n"
		.string "とりのぞいたんだ▼"
		.string "今のボクのチカラじゃ…\n"
		.string "このベースの中のみんなを守るので\n"
		.string "せいいっぱいだけど…$"

Text_Others_TookYouLong: @ 0x083854D1
	@ EN: Took you long / enough, X. / Where's Weil? / In Neo Arcadia's / underground power / system... / "Sub Arcadia"! / Omega is there too, / transmitting the / power of the Dark / Elf around the / world. / Apparently... / X and I are the only / ones who can move / around freely. / X. / Tell us the / coordinates for / Sub Arcadia. / So you plan on / fighting against / Omega? / Yes... / Why? / Nothing,I'm sure / you'll be fine... / Be careful, Zero.
	.string "{WINDOW 0x05}"
		.string "おそいぞエックス……▼"
		.string "バイルはどこだ▼"
	.string "{WINDOW 0x34}"
		.string "ネオ・アルカディアの\n"
		.string "地下動力部……▼"
		.string "アンダー・アルカディア…だよ▼"
		.string "オメガはそこから\n"
		.string "世界中にダークエルフのチカラを\n"
		.string "おくっているんだ▼"
	.string "{WINDOW 0x05}"
		.string "どうやら…▼"
		.string "まともに動けるのは、\n"
		.string "オレとエックスだけのようだな▼"
		.string "エックス▼"
		.string "アンダー・アルカディアの\n"
		.string "ザヒョウをおしえろ▼"
	.string "{WINDOW 0x34}"
		.string "オメガと…戦うんだね？▼"
	.string "{WINDOW 0x05}"
		.string "ああ……▼"
		.string "それが…なんだ？▼"
	.string "{WINDOW 0x34}"
		.string "いや、キミならだいじょうぶだ…▼"
		.string "気をつけて………ゼロ$"

Text_Others_IIVeVerifiedThe: @ 0x083855B0
	@ EN: I... / I've verified the / coordinates for / Sub Arcadia on the / transfer device. / Transfer me.
	.string "{WINDOW 0x61}"
		.string "て…▼"
		.string "転送ソウチに…\n"
		.string "アンダー・アルカディアの\n"
		.string "ザヒョウ入力をカクニン…▼"
	.string "{WINDOW 0x04}"
		.string "転送をたのむ$"

Text_Others_RogerAll: @ 0x083855E6
	@ EN: Roger. All / personnel, prepare / for transfer.
	.string "{WINDOW 0x61}"
		.string "リョウカイ…\n"
		.string "カクイン…転送じゅんびにかかれ$"

Text_Others_PreparationsFor: @ 0x08385601
	@ EN: Preparations for / transfer complete.
	.string "{WINDOW 0x62}"
		.string "転送じゅんびカンリョウ…$"

Text_Others_Transfer: @ 0x08385612
	@ EN: Transfer!
	.string "{WINDOW 0x61}"
		.string "転送…$"

Text_Others_CoordinateData: @ 0x0838561A
	@ EN: Coordinate data / obtained from / Original X... / ...has been / input completely.
	.string "{WINDOW 0x61}"
		.string "オリジナルエックスより\n"
		.string "入手しました ざひょうデータ…▼"
		.string "入力…カンリョウしました$"

Text_Others_TheCoordinates: @ 0x08385649
	@ EN: The coordinates / lead to an abandoned / research lab. / According to our / records, this is / where Weil used to / carry out his / research. / It's right next to / the place were you / were sleeping, Zero. / Weil and Omega are / there, aren't they.
	.string "{WINDOW 0x40}"
		.string "ザヒョウがしめすバショは\n"
		.string "ハイキされた\n"
		.string "古いケンキュウジョなの……▼"
		.string "キロクによると\n"
		.string "ここは、むかしバイルが\n"
		.string "ケンキュウをしていたバショで…▼"
		.string "ゼロがねむっていた…\n"
		.string "あのバショの…すぐ近くだわ……▼"
	.string "{WINDOW 0x05}"
		.string "そこに…\n"
		.string "バイルとオメガがいるんだな$"

Text_Others_ZeroBeCarefulIWill: @ 0x083856C3
	@ EN: Zero... / Be careful... / I will. / Operator... / Is everything ready?
	.string "{WINDOW 0x40}"
		.string "ゼロ……▼"
		.string "気をつけてね………▼"
	.string "{WINDOW 0x05}"
		.string "あぁ……▼"
		.string "オペレーター…\n"
		.string "行けるか？$"

Text_Others_YouCanGoAtAny: @ 0x083856EB
	@ EN: You can go at any / time, Mr. Zero.
	.string "{WINDOW 0x61}"
		.string "いつでも行けます$"

.balign 4, 0
