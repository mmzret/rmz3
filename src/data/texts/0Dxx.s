.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_EnergyFactory:: @ 0x08381364
  .2byte Text_EnergyFactory_FacilityCore-Start, Text_EnergyFactory_WhatSThis-Start, Text_EnergyFactory_TeeheeheeHeyYouWerenT-Start, Text_EnergyFactory_IAmCubitFoxtar-Start
  .2byte Text_EnergyFactory_TeeheeThatSIt-Start, Text_EnergyFactory_IfIAmDefeated-Start

Texts_EnergyFactory:: @ 0x08381370
Start:

Text_EnergyFactory_FacilityCore: @ 0x08381370
	@ EN: Operator: / The facility's core / has not yet been / activated. / We'll need to / activate the core / and reestablish / facility opera- / tions to get into / the deeper areas.
	.string "{WINDOW 0x64}"
		.string "オペレーター:\n"
		.string "「現在、シセツのロシンは\n"
		.string " キドウしてないモヨウです▼"
		.string "「おくのエリアに行くには、\n"
		.string " ロシンを動かしてシセツのキノウを\n"
		.string " とりもどすヒツヨウがあります$"

Text_EnergyFactory_WhatSThis: @ 0x083813C9
	@ EN: What's this?
	.string "{WINDOW 0x04}"
		.string "これは…？$"

Text_EnergyFactory_TeeheeheeHeyYouWerenT: @ 0x083813D1
	@ EN: Teeheehee... / Hey! You weren't / supposed to see / this place. / ... / This is a Dark Elf / copy factory. / We've got copies of / the Dark Elf / sleeping here. / In other words, / Baby Elves. / We had the factory / sealed off so / nobody'd get / suspicious. Now / you've done it! / I'll have to ensure / you remain silent / about this... / ...For-e-ver!
	.string "{WINDOW 0x1F}"
		.string "ホホホホホッ…▼"
		.string "あらあら！\n"
		.string "見てはいけないものを\n"
		.string "見ちゃったのねぇ…▼"
	.string "{WINDOW 0x04}"
		.string "………▼"
	.string "{WINDOW 0x1F}"
		.string "ここはダークエルフのコピー工場…▼"
		.string "ここにねむっているのは、\n"
		.string "ダークエルフのコピー…\n"
		.string "つまり…ベビーエルフたちなのよ▼"
		.string "あやしまれないよう、\n"
		.string "工場をヘイサしていたのに…\n"
		.string "いけない人ねぇ▼"
		.string "見られてしまったからには\n"
		.string "だまっていてもらうわね▼"
		.string "え い え ん…に！$"

Text_EnergyFactory_IAmCubitFoxtar: @ 0x08381483
	@ EN: I am Cubit Foxtar, / member of Weil's / Numbers! / I'll make sure you / never talk again!
	.string "{WINDOW 0x0F}"
		.string "わたしはバイル・ナンバーズがひとり\n"
		.string "キュービット・フォクスター！▼"
		.string "にどと 口がきけないように\n"
		.string "してやるわ！$"

Text_EnergyFactory_TeeheeThatSIt: @ 0x083814BC
	@ EN: Teehee! That's it! / See what happens / to nosy people! / Relax! I'll show you / the way to the / afterlife.
	.string "{WINDOW 0x0E}"
		.string "ホーッホッホッ！ いいキミね！\n"
		.string "わたしたちのジャマをするから\n"
		.string "そうなるのよ！▼"
		.string "安心しなさい…！\n"
		.string "きちんとあの世へ あんない\n"
		.string "してあげるわ$"

Text_EnergyFactory_IfIAmDefeated: @ 0x08381506
	@ EN: If I am defeated, / this room will cease / functioning, / and the copies will / all die... / There will be no / proof. Nobody will / know the truth. / And anyway... / We don't actually / need the Baby Elves. / The Dark Elf alone / will be enough to / take care of the / Reploids... / I can already see / it... The shining / future, the new / world Lord Weil is / about to create... / And I see...you, / wallowing in the / depths of despair! / Teeheeheeeeeee!
	.string "{WINDOW 0x0E}"
		.string "わたしが たおされれば…\n"
		.string "このへやは キノウを うしなって…\n"
		.string "コピーたちも みんな死んでしまう…▼"
		.string "何も ショウコは のこらない…\n"
		.string "真実はダレにも 知られない…▼"
		.string "でもね…▼"
		.string "ベビーエルフなんかなくっても\n"
		.string "ダークエルフさえいれば\n"
		.string "レプリロイドたちを………▼"
		.string "ああ…見えますわ…\n"
		.string "バイルさまの作る…新しい世界…\n"
		.string "ひかる未来が…▼"
		.string "そして…やみの中で\n"
		.string "ブザマにもがく\n"
		.string "オマエのすがたもね！▼"
		.string "ホーッホッホッホッ！$"

.balign 4, 0
