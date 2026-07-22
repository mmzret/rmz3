.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_SpaceCraft:: @ 0x0837f00c
  .2byte (Text_SpaceCraft_ItSureIsQuietThere-Start), (Text_SpaceCraft_TheReadingIs-Start), (Text_SpaceCraft_TheSnowIsLetting-Start), (Text_SpaceCraft_WWowLookAtThat-Start), (Text_SpaceCraft_IsThatSomeKind-Start), (Text_SpaceCraft_MsCielDidThatHuge-Start), (Text_SpaceCraft_NeoArcadiaHasThe-Start), (Text_SpaceCraft_UpAheadThatSWhere-Start)
  .2byte (Text_SpaceCraft_SheKnewWhoI-Start), (Text_SpaceCraft_CielZeroAreYouThere-Start), (Text_SpaceCraft_MaintainRadio-Start), (Text_SpaceCraft_OhIIMSorry-Start), (Text_SpaceCraft_GetDown-Start), (Text_SpaceCraft_NeoArcadiansMsCielLook-Start), (Text_SpaceCraft_NeoArcadiansMsCielLook_Alias1-Start), (Text_SpaceCraft_No-Start)
  .2byte (Text_SpaceCraft_Relax-Start), (Text_SpaceCraft_ScramIDonTHave-Start), (Text_SpaceCraft_Empty-Start), (Text_SpaceCraft_CielZeroCanYouHear-Start), (Text_SpaceCraft_SeemsYouReOkayLeave-Start), (Text_SpaceCraft_CielButZero-Start), (Text_SpaceCraft_IVeHeardThat-Start), (Text_SpaceCraft_IsItCallingMe-Start)
  .2byte (Text_SpaceCraft_Aaaaaargh-Start), (Text_SpaceCraft_NowYouReAskin-Start), (Text_SpaceCraft_ILlBlastYouTo-Start), (Text_SpaceCraft_Ooph-Start), (Text_SpaceCraft_PantPantAreYouAlive-Start), (Text_SpaceCraft_ZeroWhatTheHeckAre-Start), (Text_SpaceCraft_ThatSOmega-Start), (Text_SpaceCraft_BahThat-Start)
  .2byte (Text_SpaceCraft_OmegaHuhSoYouWere-Start), (Text_SpaceCraft_Grrr-Start), (Text_SpaceCraft_YouJustDonTGive-Start), (Text_SpaceCraft_SoYouReOmegaI-Start), (Text_SpaceCraft_Gaaarrrrwl-Start), (Text_SpaceCraft_HeheheheOmegaThatWillBe-Start), (Text_SpaceCraft_FromThisDay-Start), (Text_SpaceCraft_Gaarwl-Start)
  .2byte (Text_SpaceCraft_HeheheheIAmWeilYou-Start), (Text_SpaceCraft_MMasterX-Start), (Text_SpaceCraft_HarpuiaHeheYou-Start), (Text_SpaceCraft_YouMustBe-Start), (Text_SpaceCraft_ButMasterXThink-Start), (Text_SpaceCraft_WeilYouSoZeroYou-Start), (Text_SpaceCraft_HeheheNowThings-Start), (Text_SpaceCraft_WithThatBody-Start)
  .2byte (Text_SpaceCraft_CielZeroThisIsTerrible-Start), (Text_SpaceCraft_SoYouWere-Start), (Text_SpaceCraft_CielHurryBackToBase-Start)

Text_SpaceCraft:: @ 0x0837f072
Start:

Text_SpaceCraft_ItSureIsQuietThere: @ 0x0837F072
	@ EN: It sure is quiet... / There haven't been / many Neo Arcadian / attacks lately. / Things are almost / too peaceful now... / Ms. Ciel completed / her research on the / new energy... / And if it solves / the energy crisis, / Neo Arcadia won't / have a reason to / fight us anymore. / Actually... / I already informed / Neo Arcadia about / this new energy, / the "Ciel System"... / But... / I haven't received / a reply yet... / Don't worry! I'm / sure their answer / will come soon! / There's no more / reason to fight. We / can live in peace! / Right?! / We're in the middle / of a mission. / So put a lid on it / and walk! / *gulp!* Sorry!
	.string "{WINDOW 0x6C}"
		.string "しずかだな…▼"
		.string "最近…\n"
		.string "ネオ・アルカディアのコウゲキも\n"
		.string "ほとんどないし…▼"
		.string "まったく…\n"
		.string "平和になったもんだ▼"
	.string "{WINDOW 0x6D}"
		.string "シエルさんがケンキュウしていた\n"
		.string "新エネルギーも\n"
		.string "ついにカンセイしたし…▼"
		.string "これでエネルギー不足が\n"
		.string "カイショウしたら…▼"
		.string "ネオ・アルカディアも\n"
		.string "オレたちと戦う理由がなくなる…\n"
		.string "ってもんだよな ▼"
	.string "{WINDOW 0x40}"
		.string "じつはね……▼"
		.string "新エネルギー…\n"
		.string "システマ・シエルのこと▼"
		.string "ネオ・アルカディアに\n"
		.string "伝えてみたのよ…▼"
		.string "ヘンジは…▼"
		.string "まだ、だけど…ね▼"
	.string "{WINDOW 0x6C}"
		.string "だいじょうぶですって！\n"
		.string "もうすぐヘンジがきますよ！！▼"
		.string "もう、戦う理由がなくなった\n"
		.string "これからは、ともに生きよう……▼"
		.string "ってね！▼"
	.string "{WINDOW 0x05}"
		.string "作戦行動中だ……▼"
		.string "だまって…あるけ……▼"
	.string "{WINDOW 0x40}"
		.string "ご、ごめんなさい$"

Text_SpaceCraft_TheReadingIs: @ 0x0837F1BE
	@ EN: The reading is / getting stronger. / We're close...
	.string "{WINDOW 0x40}"
		.string "ハンノウが強くなってきたわ\n"
		.string "このあたりのはずなんだけど…$"

Text_SpaceCraft_TheSnowIsLetting: @ 0x0837F1DE
	@ EN: The snow is letting / up...
	.string "{WINDOW 0x6D}"
		.string "ユキがはれてきたな…$"

Text_SpaceCraft_WWowLookAtThat: @ 0x0837F1EB
	@ EN: W-wow! / Look at that!
	.string "{WINDOW 0x6C}"
		.string "お、おい…！▼"
		.string "あれを見ろ！！$"

Text_SpaceCraft_IsThatSomeKind: @ 0x0837F1FD
	@ EN: Is that...some kind / of ship?
	.string "{WINDOW 0x05}"
		.string "これは…フネ…か？$"

Text_SpaceCraft_MsCielDidThatHuge: @ 0x0837F209
	@ EN: Ms. Ciel... / Did that...huge / thing...fall from / outer space?! / Yes...but what's / more... / It's giving out the / same energy reading / as the Dark Elf... / of which there is / only one in the / whole world... / Zero was against the / idea, but I just had / to find out... / What could possibly / be going on here?
	.string "{WINDOW 0x6C}"
		.string "シエルさん…▼"
		.string "あんな…ばかでかいものが……\n"
		.string "ウチュウから\n"
		.string "おちてきたのですか！？▼"
	.string "{WINDOW 0x41}"
		.string "ええ…それも…▼"
		.string "この世界に \n"
		.string "たったひとりしかいないはずの\n"
		.string "ダークエルフと…▼"
		.string "同じエネルギーはんのうを\n"
		.string "出しながら…ね……▼"
		.string "ゼロには、ハンタイされたけど…\n"
		.string "どうしても \n"
		.string "この目で たしかめてみたかったの…▼"
		.string "この世界に……いったい…\n"
		.string "何がおきようとしているのか$"

Text_SpaceCraft_NeoArcadiaHasThe: @ 0x0837F2C0
	@ EN: Neo Arcadia has the / area ahead of us / cordoned off. / What?! / You guys stay here / until I make sure / it's safe. / Okay... / Be careful, Zero...
	.string "{WINDOW 0x05}"
		.string "ここからさきに\n"
		.string "ネオ・アルカディアの\n"
		.string "ケイカイセンがはってある……▼"
	.string "{WINDOW 0x40}"
		.string "なんですって！？▼"
	.string "{WINDOW 0x05}"
		.string "オレがルートをカクホするまで\n"
		.string "オマエたちは、\n"
		.string "ここでタイキしろ……▼"
	.string "{WINDOW 0x40}"
		.string "わかったわ……\n"
		.string "気をつけてね…ゼロ……$"

Text_SpaceCraft_UpAheadThatSWhere: @ 0x0837F32A
	@ EN: Up ahead... / That's where the / Dark Elf reading is / coming from.
	.string "{WINDOW 0x04}"
		.string "このおく……か、▼"
		.string "ダークエルフのハンノウが\n"
		.string "あったのは……$"

Text_SpaceCraft_SheKnewWhoI: @ 0x0837F34A
	@ EN: She knew who I / was... / Why would the elf / who almost destroyed / the world know me?
	.string "{WINDOW 0x04}"
		.string "{BOTTOM}アイツは…\n"
		.string "オレのことを 知っていた…▼"
		.string "世界をほろぼしかけたエルフが\n"
		.string "なぜオレのことを…$"

Text_SpaceCraft_CielZeroAreYouThere: @ 0x0837F37D
	@ EN: Ciel: Zero? Are you there?
	.string "{WINDOW 0x00}"
		.string "シエル「ゼロ？ 聞こえる？$"

Text_SpaceCraft_MaintainRadio: @ 0x0837F38E
	@ EN: Maintain radio / silence! / The enemy is near...
	.string "{WINDOW 0x04}"
		.string "つうしんヘイサだ！▼"
		.string "テキが近い……$"

Text_SpaceCraft_OhIIMSorry: @ 0x0837F3A3
	@ EN: Oh, I-I'm sorry...
	.string "{WINDOW 0x41}"
		.string "えっ、ご、ごめんなさい……$"

Text_SpaceCraft_GetDown: @ 0x0837F3B3
	@ EN: Get down!
	.string "{WINDOW 0x6C}"
		.string "ふせて！！$"

Text_SpaceCraft_NeoArcadiansMsCielLook: @ 0x0837F3BB
Text_SpaceCraft_NeoArcadiansMsCielLook_Alias1: @ 0x0837F3BB
	@ EN: Neo Arcadians! / Ms. Ciel, look out!
	.string "{WINDOW 0x6C}"
		.string "ネオ・アルカディアか！▼"
	.string "{WINDOW 0x6D}"
		.string "シエルさん！ さがって！$"

Text_SpaceCraft_No: @ 0x0837F3D8
	@ EN: No!
	.string "{WINDOW 0x04}"
		.string "ちっ…$"

Text_SpaceCraft_Relax: @ 0x0837F3DE
	@ EN: Relax. / They won't come to / any harm. / Harpuia?! / I'm letting you off / the hook this time. / But you and those / Resistance fighters / must leave, now! / You're letting us / off the hook?!
	.string "{WINDOW 0x2D}"
		.string "安心しろ\n"
		.string "イノチまではとらん▼"
	.string "{WINDOW 0x04}"
		.string "ハルピュイア…！▼"
	.string "{WINDOW 0x2D}"
		.string "今回は見のがしてやる▼"
		.string "レジスタンスともども…\n"
		.string "今すぐここから たち去れ！▼"
	.string "{WINDOW 0x04}"
		.string "見のがす…だと？$"

Text_SpaceCraft_ScramIDonTHave: @ 0x0837F434
	@ EN: Scram! / I don't have time to / mess with you now!
	.string "{WINDOW 0x2D}"
		.string "さっさと消えろ▼"
		.string "今は、オマエたちに\n"
		.string "かまっているバアイじゃないんだ…$"

Text_SpaceCraft_Empty: @ 0x0837F45B
	@ EN: ...
	.string "{WINDOW 0x04}"
		.string "………$"

Text_SpaceCraft_CielZeroCanYouHear: @ 0x0837F461
	@ EN: Ciel: Zero... / Can you hear me?
	.string "{WINDOW 0x00}"
		.string "シエル「ゼ…ゼロ▼"
		.string "聞こえる…かしら……？$"

Text_SpaceCraft_SeemsYouReOkayLeave: @ 0x0837F479
	@ EN: Seems you're okay... / Leave the rest of / this up to me. / I want you all to / head back to the / Resistance Base.
	.string "{WINDOW 0x04}"
		.string "無事だったようだな…▼"
		.string "ここからさきは…\n"
		.string "オレだけでやらせてもらう▼"
		.string "オマエたちは、\n"
		.string "レジスタンスベースにもどれ$"

Text_SpaceCraft_CielButZero: @ 0x0837F4B4
	@ EN: Ciel: But, Zero...
	.string "{WINDOW 0x00}"
		.string "シエル「で、でも……$"

Text_SpaceCraft_IVeHeardThat: @ 0x0837F4C1
	@ EN: I've heard that / voice somewhere / before...
	.string "{WINDOW 0x04}"
		.string "この声…\n"
		.string "前にも どこかで………$"

Text_SpaceCraft_IsItCallingMe: @ 0x0837F4D6
	@ EN: Is it...calling me?
	.string "{WINDOW 0x04}"
		.string "{BOTTOM}オレを…\n"
		.string "呼んでいるのか…？$"

Text_SpaceCraft_Aaaaaargh: @ 0x0837F4E9
	@ EN: Aaaaaargh!
	.string "{WINDOW 0x2F}"
		.string "きゃああああっ…！$"

Text_SpaceCraft_NowYouReAskin: @ 0x0837F4F5
	@ EN: Now you're askin' / for it!
	.string "{WINDOW 0x31}"
		.string "やりやがったな！$"

Text_SpaceCraft_ILlBlastYouTo: @ 0x0837F500
	@ EN: I'll blast you to / pieces!
	.string "{WINDOW 0x31}"
		.string "ふっとびやがれえっ！$"

Text_SpaceCraft_Ooph: @ 0x0837F50D
	@ EN: Ooph!
	.string "{WINDOW 0x31}"
		.string "グオオオオッ！$"

Text_SpaceCraft_PantPantAreYouAlive: @ 0x0837F517
	@ EN: *pant pant* / Are you alive, / Fefnir? / What a monster... / The two of us / fighting together, / and not a scratch. / Omega, the evil / Reploid banished / from Neo Arcadia... / He's pretty tough...
	.string "{WINDOW 0x2F}"
		.string "{BOTTOM}はあ…はあ…▼"
		.string "生きてる…？\n"
		.string "ファーブニル…▼"
	.string "{WINDOW 0x30}"
		.string "{BOTTOM}まったくバケモンだぜ…▼"
		.string "オレたちふたりがかりで\n"
		.string "キズひとつ\n"
		.string "つかねえなんて…な…▼"
	.string "{WINDOW 0x2F}"
		.string "{BOTTOM}ネオ・アルカディアをツイホウされた\n"
		.string "アクマのレプリロイド…オメガ…▼"
		.string "ケッコウやるわね…$"

Text_SpaceCraft_ZeroWhatTheHeckAre: @ 0x0837F58C
	@ EN: Zero?! / What the heck are / YOU doing here?! / What is that thing?
	.string "{WINDOW 0x30}"
		.string "…ゼロ！？▼"
		.string "なんでテメーがここに…！？▼"
	.string "{WINDOW 0x05}"
		.string "ヤツは何者だ？$"

Text_SpaceCraft_ThatSOmega: @ 0x0837F5AE
	@ EN: That's Omega. / His mere existence / defies reality... / He's strong, but... / He's not as fun to / fight as you are. / Hehe... / I don't feel like / fighting him, so / he's all yours... / See you later, Zero.
	.string "{WINDOW 0x2E}"
		.string "アイツは、オメガ……\n"
		.string "そんざいジタイが\n"
		.string "デタラメなヤツ………▼"
		.string "強いんだけど…▼"
		.string "戦ってもなんだか もえないのよね\n"
		.string "あなたとちがって…ふふ……▼"
		.string "気がのらないから\n"
		.string "あとは…あなたにまかせるわ……▼"
		.string "またね…ゼロ……$"

Text_SpaceCraft_BahThat: @ 0x0837F61B
	@ EN: Bah, that / Leviathan... / Grr, I can't move! / We'll have to finish / this another time! / Hey, Zero! / I'll get you and / that Omega one of / these days! / Don't you dare die / before then, Zero!
	.string "{WINDOW 0x30}"
		.string "ちっ、レヴィアタンめ…▼"
		.string "くそっ、体がいうことをきかねえ…\n"
		.string "今日のところは出なおしだ…！▼"
		.string "おい…ゼロ！▼"
		.string "テメエもオメガも…\n"
		.string "いつかかならず…ぶっころす！▼"
		.string "それまで死ぬんじゃねーぞ…\n"
		.string "ゼロ……！$"

Text_SpaceCraft_OmegaHuhSoYouWere: @ 0x0837F682
	@ EN: Omega, huh? / So you were the one / who called me here?
	.string "{WINDOW 0x04}"
		.string "オメガとか言ったな…▼"
		.string "オマエか…\n"
		.string "オレを呼んでいたのは…$"

Text_SpaceCraft_Grrr: @ 0x0837F6A3
	@ EN: Grrr...
	.string "{WINDOW 0x3D}"
		.string "グ…オオ……！$"

Text_SpaceCraft_YouJustDonTGive: @ 0x0837F6AD
	@ EN: You just don't give / up, do you...
	.string "{WINDOW 0x04}"
		.string "ちっ…\n"
		.string "しぶといヤツだ$"

Text_SpaceCraft_SoYouReOmegaI: @ 0x0837F6BB
	@ EN: So you're Omega. / I'm afraid I can't / let you leave this / place, ever. / Time for your / destruction!
	.string "{WINDOW 0x2C}"
		.string "オマエがオメガ…か…▼"
		.string "オマエのようなものを\n"
		.string "ここから出すわけにはいかん▼"
		.string "ここで…ハカイする！！$"

Text_SpaceCraft_Gaaarrrrwl: @ 0x0837F6EE
	@ EN: Gaaarrrrwl!
	.string "{WINDOW 0x3D}"
		.string "グオオオオオッ！$"

Text_SpaceCraft_HeheheheOmegaThatWillBe: @ 0x0837F6F9
	@ EN: Hehehehe... / Omega, that will be / quite enough.
	.string "{WINDOW 0x3B}"
		.string "クーックックックッ…▼"
		.string "オメガよ…\n"
		.string "そのくらいにしておけ$"

Text_SpaceCraft_FromThisDay: @ 0x0837F717
	@ EN: From this day / forward... / You will fight with / this person as a / Neo Arcadian. / It's not polite, / smashing a friend / like that.
	.string "{WINDOW 0x3B}"
		.string "オマエは今日から…▼"
		.string "ネオ・アルカディアの\n"
		.string "メンバーとして\n"
		.string "この方と ともに戦うのだ…▼"
		.string "仲間になる者を\n"
		.string "ころしてしまっては、\n"
		.string "いごこちも悪かろう…$"

Text_SpaceCraft_Gaarwl: @ 0x0837F76A
	@ EN: Gaarwl... / Lord...Weil... / A Neo Arcadian?! / Who is this guy?!
	.string "{WINDOW 0x3D}"
		.string "グ…オオ…\n"
		.string "バイル…サマ…▼"
	.string "{WINDOW 0x2C}"
		.string "{BOTTOM}ネオ・アルカディアの…\n"
		.string "メンバーだと！？▼"
		.string "何者だ！？$"

Text_SpaceCraft_HeheheheIAmWeilYou: @ 0x0837F79A
	@ EN: Hehehehe... / I am Weil. You may / call me Dr. Weil. / You must know my / name, Harpuia of the / Four Guardians? / And you...the / legendary hero. / Zero... / Dr. Weil?! / You're kidding me! / It can't be! Why / are you, who were / banished from Neo / Arcadia a century / ago, with Omega?! / That's simple. / I-I brought him.
	.string "{WINDOW 0x3B}"
		.string "{BOTTOM}クーックックックッ…▼"
		.string "わが名はバイル…\n"
		.string "ドクター・バイルだ…▼"
		.string "名前くらいは聞いたことがあろう？\n"
		.string "四天王ハルピュイア▼"
		.string "そして…伝説のエイユウ▼"
		.string "ゼロ……▼"
	.string "{WINDOW 0x2C}"
		.string "{BOTTOM}ドクター・バイル…だと！？▼"
		.string "バカな！ ありえん！▼"
		.string "100年前にネオ・アルカディアを\n"
		.string "ツイホウされたはずのオマエが\n"
		.string "なぜオメガを！？▼"
	.string "{WINDOW 0x37}"
		.string "{BOTTOM}ボくが…▼"
		.string "よンだのサ…$"

Text_SpaceCraft_MMasterX: @ 0x0837F847
	@ EN: M...Master X?! / Is that you?!
	.string "{WINDOW 0x2C}"
		.string "エ…\n"
		.string "エックス…さま！？$"

Text_SpaceCraft_HarpuiaHeheYou: @ 0x0837F856
	@ EN: Harpuia! Hehe, you / haven't ch-changed! / And th-then / there's... / I missed y-you, / Zero...
	.string "{WINDOW 0x37}"
		.string "ギギッ…ハルピュイアか\n"
		.string "フフ…かわりない…な▼"
		.string "そしテ……▼"
		.string "会いタかッたよ……ゼロ$"

Text_SpaceCraft_YouMustBe: @ 0x0837F882
	@ EN: You must be... / You're a copy, / aren't you? / Hehehe! / I brought back / Master X, whom you / defeated long ago! / To protect humanity / from the chaos of / this world! / Weil saved my life. / I owe h-him, see... / I'll take Omega / back, thank y-you. / Harpuia, you k-keep / searching for the / Dark Elf. / Omega and the Dark / Elf... / We'll need them / both for what's to / c-come...
	.string "{WINDOW 0x04}"
		.string "オマエ……\n"
		.string "コピーだな……▼"
	.string "{WINDOW 0x3B}"
		.string "{BOTTOM}クックックッ……▼"
		.string "かつてオマエに\n"
		.string "たおされたエックスさまを\n"
		.string "このワシが よみがえらせた…▼"
		.string "コントンとした この世界から\n"
		.string "人間を守るためにな！▼"
	.string "{WINDOW 0x37}"
		.string "{TOP}バイルは…\n"
		.string "ぼクの いのチのおんじンなのサ…▼"
		.string "オメガは、かいしゅうスる…▼"
		.string "ハルピュイア\n"
		.string "おマえはひき続き\n"
		.string "ダークエルフのそうさくにアたレ▼"
		.string "オメガとダークエルフ…▼"
		.string "ふたつとも、\n"
		.string "これカらのボくたちに\n"
		.string "ひつヨウなものだからネ…$"

Text_SpaceCraft_ButMasterXThink: @ 0x0837F955
	@ EN: But Master X! Think / how many humans died / because of the Dark / Elf and Omega, both / built by this man... / How can you justify / exposing humanity to / such a grave danger, / especially now with / the energy crisis / almost solved?! / What's this? Are you / trying to tell / Master X what to do? / When did you grow so / bold, Harpuia?
	.string "{WINDOW 0x2C}"
		.string "し…しかし！ エックスさま！▼"
		.string "このオトコが作った\n"
		.string "ダークエルフとオメガのせいで…\n"
		.string "どれだけ多くの人間が死んだか…▼"
		.string "新エネルギーがカンセイし\n"
		.string "エネルギーもんだいが\n"
		.string "カイケツするかもしれない時に…▼"
		.string "人間をキケンにさらすようなことは、\n"
		.string "おやめください！▼"
	.string "{WINDOW 0x3B}"
		.string "{BOTTOM}エックスさまにイケンをするのか？\n"
		.string "ハルピュイア…▼"
		.string "いつからそんなに、\n"
		.string "えらくなった$"

Text_SpaceCraft_WeilYouSoZeroYou: @ 0x0837FA09
	@ EN: Weil...you... / So, Zero. / You g-guys are / also searching for / the Dark Elf, right? / Let's m-make a / contest out of it! / I'll sh-show you / who the real hero / i-is!
	.string "{WINDOW 0x2C}"
		.string "{TOP}くっ…バイル……▼"
	.string "{WINDOW 0x37}"
		.string "サて…ゼロ▼"
		.string "キミたちも…ダークエルフを\n"
		.string "サがしてイるんだろウ？\n"
		.string "きょうそうと いコウじゃないか！▼"
		.string "ギッ…ギギギッ…！\n"
		.string "こんどは まケないヨ…！▼"
		.string "ボクこそガ…\n"
		.string "本当のエイユウなんダからネ！$"

Text_SpaceCraft_HeheheNowThings: @ 0x0837FA77
	@ EN: Hehehe... Now things / are getting / interesting, Zero! / Let's see how far / you get with that / body! Hehehe...
	.string "{WINDOW 0x3B}"
		.string "{BOTTOM}クーックックックッ…\n"
		.string "たのしくなってきたな、ゼロ！▼"
		.string "そのカラダでどこまでできるか…\n"
		.string "見せてもらうとしよう！\n"
		.string "クックックッ…$"

Text_SpaceCraft_WithThatBody: @ 0x0837FAB9
	@ EN: "With that body"...? / ...
	.string "{WINDOW 0x04}"
		.string "そのカラダ…だと…？▼"
		.string "………$"

Text_SpaceCraft_CielZeroThisIsTerrible: @ 0x0837FACA
	@ EN: Ciel: Zero... / This is terrible...
	.string "{WINDOW 0x00}"
		.string "シエル「ゼロ……▼"
		.string "タイヘンなことになったわね……$"

Text_SpaceCraft_SoYouWere: @ 0x0837FAE5
	@ EN: So you were / monitoring the whole / thing?
	.string "{WINDOW 0x04}"
		.string "モニターしていたのか……$"

Text_SpaceCraft_CielHurryBackToBase: @ 0x0837FAF4
	@ EN: Ciel: Hurry back to base. / Operator? / Operator: Commencing trans.
	.string "{WINDOW 0x00}"
		.string "シエル「すぐにベースへもどってきて……▼"
		.string "オペレーターさん…おねがい▼"
	.string "{WINDOW 0x00}"
		.string "オペレーター「転送をカイシします$"

.balign 4, 0
