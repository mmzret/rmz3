.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_Volcano:: @ 0x0837fb30
  .2byte (Text_Volcano_StrongEnergyReading-Start), (Text_Volcano_IAlmostGaveUpOn-Start), (Text_Volcano_IAlmostGaveUpOn_2-Start), (Text_Volcano_SsyaaaaahGetReadyFor-Start)
  .2byte (Text_Volcano_WhatIsThatAll-Start), (Text_Volcano_WhoAreYouToPut-Start)

Text_Volcano:: @ 0x0837fb3c
Start:

Text_Volcano_StrongEnergyReading: @ 0x0837FB3C
	@ EN: Operator: / A strong energy / reading detected. / They are building / a huge missile / outside the base. / The base must be / here to support the / construction. / Ciel: / Analyzing a route to / the missile factory / will take quite a / while... Zero, what / should we do?! / All right. I'll / buy us some time by / attacking the base. / Start your analysis!
	.string "{WINDOW 0x64}"
		.string "オペレーター:\n"
		.string "「ただいま強力な\n"
		.string " エネルギーはんのうをカクニン▼"
		.string "「基地の近くで巨大なミサイルを\n"
		.string " ケンゾウ中のようです▼"
		.string "「この基地はミサイルのケンゾウを\n"
		.string " サポートしている基地だと\n"
		.string " 思われます▼"
		.string "シエル:\n"
		.string "「ミサイル工場への\n"
		.string " 転送ルートかいせきは▼"
		.string "「かなり時間がかかりそうなの…\n"
		.string " どうしよう…ゼロ！▼"
	.string "{WINDOW 0x04}"
		.string "わかった…\n"
		.string "この基地をコウゲキして\n"
		.string "時間をかせぐ…▼"
		.string "カイセキは まかせたぞ$"

Text_Volcano_IAlmostGaveUpOn: @ 0x0837FC15
Text_Volcano_IAlmostGaveUpOn_2:
	@ EN: I almost gave up on / finding a foe worthy / of fighting me... / You look like you / might at least be a / minor challenge. / I'm gonna enjoy / this, Zero!
	.string "{WINDOW 0x17}"
		.string "たよりないザコどもを\n"
		.string "まとめるのに…しょうじき\n"
		.string "あきていたところだが…▼"
		.string "オマエなら\n"
		.string "少しは、たのしめそうだ…▼"
		.string "かんげいするぜ！\n"
		.string "ゼロォッ！$"

Text_Volcano_SsyaaaaahGetReadyFor: @ 0x0837FC5E
	@ EN: Ssyaaaaah! / Get ready for / Blazin' Flizard, one / of Weil's Numbers! / Let's heat it up, / Zerrroooo!!!
	.string "{WINDOW 0x07}"
		.string "シャハアァァァッ！▼"
		.string "バイル・ナンバーズがひとり！\n"
		.string "オレの名は\n"
		.string "ブレイジン・フリザード！▼"
		.string "オレをあつくしてくれ！\n"
		.string "ゼェロォォォッッ！$"

Text_Volcano_WhatIsThatAll: @ 0x0837FCA3
	@ EN: What, is that all / you got? / How...tepid. And I / was hoping to have a / little fun, too. / Ssyahahah!
	.string "{WINDOW 0x06}"
		.string "もうおしまいか！？▼"
		.string "さめちまうなぁ！\n"
		.string "ひまつぶしにもならんかぁ！▼"
		.string "シャハァーッハッハッハァ！$"

Text_Volcano_WhoAreYouToPut: @ 0x0837FCD4
	@ EN: Who are you to...put / out my flames? / Lord Weil will get / you, though... Make / no mistake... / He'll cover the / whole world in / flames, you'll see. / You can't...put out / the flames...of our / new world... / Ssyah...aaaarrgh!
	.string "{WINDOW 0x06}"
		.string "オレのホノオを…かき消すとは…！\n"
		.string "なんて…ヤツ…だっ▼"
		.string "しかし…かならず…\n"
		.string "バイルさまが…▼"
		.string "世界を…ホノオに……\n"
		.string "つつんでくださる…はずだ▼"
		.string "オマエに…\n"
		.string "われらの…新たなる世界の\n"
		.string "ホノオを消すことは…できん…▼"
		.string "シャ…ギャハアアァァァァッ！$"

.balign 4, 0
