.section .rodata
.balign 4, 0

@ Need tools/preproc
@ preproc: treat "label::" as ".global label ; label:"

TextOfs_System:: @ 0x08376920
	.2byte (Text_System_WhoWillYouTalkWith-Start), (Text_System_WhatDoYouNeed-Start), (Text_System_SaveData-Start), (Text_System_SaveDataWhere-Start), (Text_System_OkToOverwrite-Start), (Text_System_LoadWhichData-Start), (Text_System_OkToLoad-Start), (Text_System_EraseWhichData-Start)
	.2byte (Text_System_OkToErase-Start), (Text_System_DataSaved-Start), (Text_System_DataLoaded-Start), (Text_System_DataErased-Start), (Text_System_YourOrdersPlease-Start), (Text_System_YourOrdersPlease_Alias1-Start), (Text_System_YourOrdersPlease_Alias2-Start), (Text_System_YourOrdersPlease_Alias3-Start)
	.2byte (Text_System_DisplayingThe-Start), (Text_System_AllRightLetS-Start), (Text_System_TheseAreTheOnly-Start), (Text_System_Empty-Start), (Text_System_TheNeoArcadian-Start), (Text_System_DoSomeScouting-Start), (Text_System_WeVeVerifiedA-Start), (Text_System_MissionAsk_1-Start)
	.2byte (Text_System_WeHaveDiscoveredA-Start), (Text_System_MissionAsk_2-Start), (Text_System_ThisWasAResi-Start), (Text_System_MissionAsk_3-Start), (Text_System_MissionSummary_4-Start), (Text_System_MissionAsk_4-Start), (Text_System_MissionSummary_5-Start), (Text_System_MissionAsk_5-Start)
	.2byte (Text_System_MissionSummary_6-Start), (Text_System_MissionAsk_6-Start), (Text_System_WeHaveAnalyzedThe-Start), (Text_System_MissionAsk_7-Start), (Text_System_ThisIsANeo-Start), (Text_System_MissionAsk_8-Start), (Text_System_ContainersHave-Start), (Text_System_MissionAsk_9-Start)
	.2byte (Text_System_TheRuinsOfAn-Start), (Text_System_MissionAsk_10-Start), (Text_System_NeoArcadiaHas-Start), (Text_System_MissionAsk_11-Start), (Text_System_CommencingTransfer-Start), (Text_System_AreYouReady-Start), (Text_System_WhereToTransfer-Start), (Text_System_WhereToTransfer_Alias1-Start)
	.2byte (Text_System_WhereToTransfer_Alias2-Start), (Text_System_WhereToTransfer_Alias3-Start), (Text_System_WhereToTransfer_Alias4-Start), (Text_System_DerelictSpacecraft-Start), (Text_System_AegisVolcanoBase-Start), (Text_System_OceanicHwyRuins-Start), (Text_System_WRFactory-Start), (Text_System_OldResidential-Start)
	.2byte (Text_System_MissileFactory-Start), (Text_System_TwilightDesert-Start), (Text_System_ForestOfAnatre-Start), (Text_System_FrontlineIceBase-Start), (Text_System_AreaX2-Start), (Text_System_EnergyFacility-Start), (Text_System_SnowyPlains-Start), (Text_System_SunkenLibrary-Start)
	.2byte (Text_System_GiantElevator-Start), (Text_System_SubArcadia-Start), (Text_System_MissionAssigned-Start), (Text_System_MissionAssigned_Alias1-Start), (Text_System_MissionAssigned_Alias2-Start), (Text_System_MissionAssigned_Alias3-Start), (Text_System_MissionAssigned_Alias4-Start), (Text_System_PreparationsFor-Start)
	.2byte (Text_System_Transfer-Start), (Text_System_ZeroBeCareful-Start), (Text_System_ZeroBeCareful_Alias1-Start), (Text_System_ZeroEllipsis-Start), (Text_System_ZeroComeBackSafely-Start), (Text_System_DonTDoAnything-Start), (Text_System_ZeroComeBackSafely_2-Start), (Text_System_Zerrroooo-Start)
	.2byte (Text_System_Transferring-Start), (Text_System_TransferComplete-Start), (Text_System_WhatShouldIDoWell-Start), (Text_System_WhatShouldIDoWell_Alias1-Start), (Text_System_WhatShouldIDoWell_Alias2-Start), (Text_System_WhatShouldIDoWell_Alias3-Start), (Text_System_WhatShouldIDoWell_Alias4-Start), (Text_System_WhatShouldIDoWell_Alias5-Start)
	.2byte (Text_System_WhatShouldIDoWell_Alias6-Start), (Text_System_WhatShouldIDoWell_Alias7-Start), (Text_System_ThankYouZeroWeFailed-Start), (Text_System_ZeroIMSorryYou-Start), (Text_System_ZeroThankYouThatRecycling-Start), (Text_System_ZeroThankYouTheReports-Start), (Text_System_CielGoodluck_7-Start), (Text_System_CielGoodluck_8-Start)
	.2byte (Text_System_CielGoodluck_9-Start), (Text_System_WelcomeBackZeroItAppears-Start), (Text_System_CielGoodluck_12-Start), (Text_System_CielGoodluck_13-Start), (Text_System_ThankYouZeroItLooks-Start), (Text_System_ZeroItSGreatTo-Start), (Text_System_WhatWillItBe-Start), (Text_System_BootCompleted-Start)
	.2byte (Text_System_EnterCommand-Start), (Text_System_CanTradeBattlechipsW-Start), (Text_System_BeginTransmission-Start), (Text_System_WaitingForTransmission-Start), (Text_System_CommunicatingWith-Start), (Text_System_TransmissionError-Start), (Text_System_TransmissionComplete-Start), (Text_System_TransmissionComplete_2-Start)
	.2byte (Text_System_MegaBoosterCardReceived-Start), (Text_System_MegaBoosterCardReceived_Alias1-Start), (Text_System_MegaBoosterCardReceived_Alias2-Start), (Text_System_MegaBoosterCardReceived_Alias3-Start), (Text_System_TransmissionError_2-Start), (Text_System_CardBoostReverted-Start), (Text_System_TitleBackgroundPicture-Start), (Text_System_TitleBackgroundPicture_Alias1-Start)
	.2byte (Text_System_TitleBackgroundPicture_Alias2-Start), (Text_System_TitleBackgroundPicture_Alias3-Start), (Text_System_PottedPlantAddedTo-Start), (Text_System_DesignOfElevatorIn-Start), (Text_System_ModCard_3-Start), (Text_System_PHunterEnergy-Start), (Text_System_PGuardianEnergy-Start), (Text_System_DesignOfNurseElvesHas-Start)
	.2byte (Text_System_ModCard_7-Start), (Text_System_TheDesignOfBustershot-Start), (Text_System_TheDesignOfTheZ-Start), (Text_System_TheDesignOfAlouetteS-Start), (Text_System_ModCard_11-Start), (Text_System_ZeroSDefenseIsNow-Start), (Text_System_TheDesignOfTheMessage-Start), (Text_System_TheDesignOfLifeEnergy-Start)
	.2byte (Text_System_ModCard_18-Start), (Text_System_AllBoostedItemsHave-Start), (Text_System_ThereIsALostCat-Start), (Text_System_ItIsSnowingAtThe-Start), (Text_System_TheDesignOfThe-Start), (Text_System_ModCard_23-Start), (Text_System_ModCard_24-Start), (Text_System_DesignOfComputerIn-Start)
	.2byte (Text_System_AMysteriousCyberElfHas-Start), (Text_System_ModCard_27-Start), (Text_System_APaintingHasBeenHung-Start), (Text_System_ANewDoorHasAppeared-Start), (Text_System_ModCard_30-Start), (Text_System_ModCard_31-Start), (Text_System_AFlowerHasBloomedOn-Start), (Text_System_TheDesignOfAnimalElves-Start)
	.2byte (Text_System_AndrewLooksYoungerNow-Start), (Text_System_ModCard_38-Start), (Text_System_SeagullsNowFlyInThe-Start), (Text_System_ModCard_41-Start), (Text_System_TheDesignOfSecretDisks-Start), (Text_System_ModCard_43-Start), (Text_System_SomebodyHasDrawnGraffiti-Start), (Text_System_ModCard_48-Start)
	.2byte (Text_System_ModCard_52-Start), (Text_System_ModCard_60-Start), (Text_System_ModCard_61-Start), (Text_System_ModCard_64-Start), (Text_System_ModCard_65-Start), (Text_System_TheDesignOfHackerElves-Start), (Text_System_EnergyOfCrossbyneHas-Start), (Text_System_EnergyOfPBase-Start)
	.2byte (Text_System_ModCard_69-Start), (Text_System_ItIsNowNighttimeAt-Start), (Text_System_EnergyOfPAqua-Start), (Text_System_FishNowJumpAroundThe-Start), (Text_System_ModCard_78-Start), (Text_System_ModCard_79-Start), (Text_System_ModCard_81-Start), (Text_System_ModCard_82-Start)
	.2byte (Text_System_EnergyOfPBomber-Start), (Text_System_EnergyOfAlteredP-Start), (Text_System_ModCard_90-Start), (Text_System_EnergyOfPurplenerple-Start), (Text_System_EnergyOfShellcrawler-Start), (Text_System_EnergyOfIcebonIncreased-Start), (Text_System_EnergyOfGCannon-Start), (Text_System_EnergyOfClaveker-Start)
	.2byte (Text_System_EnergyOfShotcounter-Start), (Text_System_EnergyOfGrandCannon-Start), (Text_System_EnergyOfShrimpolin-Start), (Text_System_EnergyOfBatring-Start), (Text_System_EnergyOfPCannon-Start), (Text_System_EnergyOfVolcaire-Start), (Text_System_EnergyOfSnakecord-Start), (Text_System_EnergyOfLemmingles-Start)
	.2byte (Text_System_EnergyOfLamplort-Start), (Text_System_EnergyOfTileCannon-Start), (Text_System_EnergyOfShelluno-Start), (Text_System_EnergyOfHeavyCannon-Start), (Text_System_EnergyOfMothjiro-Start), (Text_System_EnergyOfCCannon-Start), (Text_System_EnergyOfCalibeeG-Start), (Text_System_EnergyOfDeathlock-Start)
	.2byte (Text_System_EnergyOfGyroCannon-Start), (Text_System_EnergyOfSharkshielX-Start), (Text_System_EnergyOfOlwarmer-Start), (Text_System_EnergyOfBranwarmer-Start), (Text_System_EnergyOfLocomoIf-Start), (Text_System_EnergyOfBeeserver-Start), (Text_System_EnergyOfMegamilpa-Start), (Text_System_ZeroSMiniGame-Start)
	.2byte (Text_System_ZeroSMiniGame_Alias1-Start), (Text_System_ZeroSMiniGame_Alias2-Start), (Text_System_ZeroSMiniGame_Alias3-Start), (Text_System_CielSMiniGame-Start), (Text_System_CopyXSMiniGame-Start), (Text_System_HarpuiaSMiniGame-Start), (Text_System_FefnirSMiniGame-Start), (Text_System_LeviathanSMiniGame-Start)
	.2byte (Text_System_PhantomSMiniGame-Start), (Text_System_HardModeAddedPlayIn-Start), (Text_System_UltimateModeAddedPlayIn-Start)

Text_System:: @ 0x08376ad6
Start:
    # シエル
Text_System_WhoWillYouTalkWith: @ 0x08376AD6
	@ EN: Who will you talk with? / Operator / Ciel
	.string "{WINDOW 0x02}"
		.string "だれに、話しかけますか？\n"
		.string "  オペレーター\n"
		.string "  シエル$"

Text_System_WhatDoYouNeed: @ 0x08376AF5
	@ EN: What do you need? / Manage data / Talk
	.string "{WINDOW 0x40}"
		.string "なにかしら？ なんでも言ってね\n"
		.string "  データのかんり\n"
		.string "  話をする$"

Text_System_SaveData: @ 0x08376B1A
	@ EN: Save data / Load data / Erase data
	.string "{WINDOW 0x40}"
		.string "  データをキロクします\n"
		.string "  データを呼び出します\n"
		.string "  データを消します$"

Text_System_SaveDataWhere: @ 0x08376B44
	@ EN: Save data where?
	.string "{WINDOW 0x40}"
		.string "どこにデータをキロクしますか？$"

Text_System_OkToOverwrite: @ 0x08376B56
	@ EN: : OK to overwrite? / YES / NO
	.string "{WINDOW 0x40}"
		.string " のデータを上がきしていいですか？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_LoadWhichData: @ 0x08376B76
	@ EN: Load which data?
	.string "{WINDOW 0x40}"
		.string "どのデータを呼び出しますか？$"

Text_System_OkToLoad: @ 0x08376B89
	@ EN: : OK to load? / YES / NO
	.string "{WINDOW 0x40}"
		.string " のデータを呼び出していいですか？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_EraseWhichData: @ 0x08376BAA
	@ EN: Erase which data?
	.string "{WINDOW 0x40}"
		.string "どのデータを消しますか？$"

Text_System_OkToErase: @ 0x08376BBA
	@ EN: : OK to erase? / YES / NO
	.string "{WINDOW 0x40}"
		.string " のデータを消していいですか？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_DataSaved: @ 0x08376BD8
	@ EN: Data saved.
	.string "{WINDOW 0x40}"
		.string "データをキロクしました$"

Text_System_DataLoaded: @ 0x08376BE6
	@ EN: Data loaded.
	.string "{WINDOW 0x40}"
		.string "データを呼び出しました$"

Text_System_DataErased: @ 0x08376BF6
	@ EN: Data erased.
	.string "{WINDOW 0x40}"
		.string "データを消しました$"

@ オペレータ
Text_System_YourOrdersPlease: @ 0x08376C03
Text_System_YourOrdersPlease_Alias1: @ 0x08376C03
Text_System_YourOrdersPlease_Alias2: @ 0x08376C03
Text_System_YourOrdersPlease_Alias3: @ 0x08376C03
	@ EN: Your orders, please. / Select mission / Transfer back
	.string "{WINDOW 0x62}"
		.string "{TOP}しじを おねがいします\n"
		.string "  ミッションへ行く\n"
		.string "  いちど行ったエリアへ転送$"

Text_System_DisplayingThe: @ 0x08376C30
	@ EN: Displaying the / available missions:
	.string "{WINDOW 0x62}"
		.string "{TOP}センタクできるミッションを\n"
		.string "ひょうじ します$"

Text_System_AllRightLetS: @ 0x08376C4A
	@ EN: All right, let's / look at something / else.
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}では、他を見てみましょう$"

Text_System_TheseAreTheOnly: @ 0x08376C5C
	@ EN: These are the only / available missions. / Return when ready.
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}このミッションしかセンタクできません\n"
		.string "ジュンビができましたら\n"
		.string "いつでも声をおかけください…$"

Text_System_Empty: @ 0x08376C8E
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}$"

@ ミッション選択(序盤4)
Text_System_TheNeoArcadian: @ 0x08376C92
	@ EN: The Neo Arcadian / army is building up / at the base in Aegis / Volcano. / We do not know what / their intention is.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ネオ・アルカディア軍が\n"
		.string "アグニスかざんにある基地に\n"
		.string "シュウケツしつつあります▼"
		.string "カレらの目的は、\n"
		.string "現在のところ不明…$"

Text_System_DoSomeScouting: @ 0x08376CD8
	@ EN: Do some scouting? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}テイサツをおねがいしたいのですが…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_WeVeVerifiedA: @ 0x08376CF8
	@ EN: We've verified a / reading similar to / the Dark Elf on the / ruins of an inter- / continental oceanic / highway... / We have verified / that Neo Arcadia / is pursuing this. / We believe it will / take some time for / them to reach the / source of this / reading. / If possible, you / should verify / this signal, / and if it is indeed / the Dark Elf, / protect it.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}カイジョウをはしる\n"
		.string "タイリク間ハイウェイあとちにて\n"
		.string "ダークエルフらしきハンノウと…▼"
		.string "それをツイセキする\n"
		.string "ネオ・アルカディアを…\n"
		.string "カクニンしました▼"
		.string "カレらがこのハンノウを\n"
		.string "ホソクするまで\n"
		.string "まだじかんがかかりそうですが…▼"
		.string "できれば、はやめに\n"
		.string "このハンノウをカクニンし…▼"
		.string "ダークエルフであった場合、\n"
		.string "ホゴしていただきたいのですが…$"

Text_System_MissionAsk_1: @ 0x08376DA0
	@ EN: Do you accept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}おねがいできますか…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_WeHaveDiscoveredA: @ 0x08376DB9
	@ EN: We have discovered a / Neo Arcadian weapons / factory. / They are fixing and / refitting broken / weaponry. / It seems this is / more efficient than / making new ones. / They have doubled / weapon production / recently. / Destroy this factory / to cut Neo Arcadia's / military power.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ネオ・アルカディアの\n"
		.string "ヘイキ再生工場を発見しました▼"
		.string "こわれたヘイキをシュウリし\n"
		.string "再利用しているようなのですが…▼"
		.string "イチからセイサンするより\n"
		.string "コウリツがいいらしく▼"
		.string "ここ最近、\n"
		.string "ヘイキのセイサンリョウが\n"
		.string "2倍になっています▼"
		.string "この工場をハカイし\n"
		.string "ネオ・アルカディアの戦力を\n"
		.string "弱体化させたいのですが…$"

Text_System_MissionAsk_2: @ 0x08376E5F
	@ EN: Do you accept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}おねがいできますか…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_ThisWasAResi: @ 0x08376E78
	@ EN: This was a resi- / dential area where / humans once lived. / We sent some people / to investigate... / And received news / that Dark Elf may / have been seen. / For some reason, we / are unable to scan / this area. / We would like you to / go there to investi- / gate first-hand.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ここは かつて人間がすんでいた\n"
		.string "きょじゅうくのあとちです▼"
		.string "チョウサに行った仲間たちから…▼"
		.string "ダークエルフらしきものを\n"
		.string "見たというホウコクが\n"
		.string "とどいています▼"
		.string "このエリアにたいしては\n"
		.string "なぜかスキャンが使用できません▼"
		.string "ゼロさんにチョクセツ\n"
		.string "チョウサに行って\n"
		.string "いただきたいのですが…$"

Text_System_MissionAsk_3: @ 0x08376F0D
	@ EN: Can you investigate? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}チョウサ…おねがいできますか？\n"
		.string "  はい\n"
		.string "  いいえ$"

@ ミッション選択(中盤4)
Text_System_MissionSummary_4: @ 0x08376F2B
	@ EN: We have detected / Neo Arcadian units / moving through the / southern desert. / These forces must be / intercepted as / soon as possible.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ミナミの砂ばくをすすむ\n"
		.string "ネオ・アルカディア軍を\n"
		.string "カクニン…▼"
		.string "ヒカク的はやめのゲイゲキが\n"
		.string "ヒツヨウかと思われます$"

Text_System_MissionAsk_4: @ 0x08376F6A
	@ EN: Can you intercept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}ゲイゲキをおねがいしたいのですが…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_MissionSummary_5: @ 0x08376F8A
	@ EN: We have detected / Neo Arcadian units / moving through the / Forest of Anatre... / These forces must be / intercepted as / soon as possible.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}アナトレーのモリをすすむ\n"
		.string "ネオ・アルカディア軍を\n"
		.string "カクニン…▼"
		.string "ヒカク的はやめのゲイゲキが\n"
		.string "ヒツヨウかと思われます$"

Text_System_MissionAsk_5: @ 0x08376FC9
	@ EN: Can you intercept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}ゲイゲキをおねがいしたいのですが…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_MissionSummary_6: @ 0x08376FE9
	@ EN: We have detected / Neo Arcadian units / moving through the / northern tundra... / The enemy is / constructing a / frontline base. / There seems to be a / reasonable amount of / time left to act.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}キタのツンドラをすすむ\n"
		.string "ネオ・アルカディア軍を\n"
		.string "カクニン…▼"
		.string "テキは…\n"
		.string "ゼンセン基地を\n"
		.string "コウチクしているモヨウ…▼"
		.string "タショウの時間的ヨユウが\n"
		.string "あるものと思われます…$"

Text_System_MissionAsk_6: @ 0x08377044
	@ EN: Can you intercept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}ゲイゲキに向かわれますか…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_WeHaveAnalyzedThe: @ 0x08377061
	@ EN: We have analyzed the / enemy's movements... / As a result, we have / succeeded in / determining the / location of the Neo / Arcadian HQ. / It seems that Copy X / and Weil are / commanding the / entire army from / this base. / If you strike here, / you may be able to / stop Neo Arcadia.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}テキのしんこうルートを\n"
		.string "カイセキし…▼"
		.string "ネオ・アルカディア本部の\n"
		.string "イチのトクテイに\n"
		.string "セイコウしました…▼"
		.string "コピーエックスとバイルは、\n"
		.string "ここより全軍のシキを\n"
		.string "とっているモヨウ…▼"
	.string "{WINDOW 0x04}"
		.string "{BOTTOM}ここをたたけば…\n"
		.string "ネオ・アルカディアを\n"
		.string "止めることができる…か…$"

Text_System_MissionAsk_7: @ 0x083770E3
	@ EN: Are you ready? / YES / NO
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ジュンビは、よろしいでしょうか？\n"
		.string "  はい\n"
		.string "  いいえ$"

@ ミッション選択(後半4)
Text_System_ThisIsANeo: @ 0x08377102
	@ EN: This is a Neo / Arcadian energy / plant. It is / currently shut. / What is so important / that they had to / shut down the plant / in the middle of an / energy crisis? / The place was shut / down around the time / Weil appeared, so it / bears investigation.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ここはネオ・アルカディアの\n"
		.string "エネルギーしせつなのですが…\n"
		.string "今は、ヘイサされています▼"
		.string "エネルギー不足にもかかわらず\n"
		.string "シセツをヘイサしてまで\n"
		.string "カレらがやりたいことは何か？▼"
		.string "ちょうどバイルが現れたあたりに\n"
		.string "ヘイサされたのが気になります$"

Text_System_MissionAsk_8: @ 0x0837717E
	@ EN: Can you investigate? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}チョウサをおねがいしたいのですが…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_ContainersHave: @ 0x0837719E
	@ EN: Containers have / fallen out of a / space ship, / which fell onto / snowy plains. / It is possible that / they contain data / about Omega or Weil. / We sent a scouting / party, but the / Neo Arcadian forces / are too strong, and / they cannot pass. / We would like you to / reinforce them, and / retrieve the data.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ウチュウセンがおちてきた\n"
		.string "あのセツゲンに…▼"
		.string "おそらくウチュウセンに\n"
		.string "つまれていたのだろうと思われる\n"
		.string "コンテナがちらばっています▼"
		.string "もしかしたら、\n"
		.string "オメガやバイルにかんするデータが\n"
		.string "のこっているカノウセイがあります▼"
		.string "テイサツ部隊を\n"
		.string "ハケンしていますが…▼"
		.string "ネオ・アルカディアの\n"
		.string "テイコウが強く…\n"
		.string "なかなかさきにすすめません▼"
		.string "仲間をエンゴし、\n"
		.string "データをカイシュウして\n"
		.string "いただきたいのですが…$"

Text_System_MissionAsk_9: @ 0x08377267
	@ EN: Do you accept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}おねがいできますか…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_TheRuinsOfAn: @ 0x08377280
	@ EN: The ruins of an / ancient library have / been found. / It's completely / soaked inside, but / there may still be / some data around. / We'd like you to / search for data on / Weil or Omega.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}旧ジダイのトショカンのイセキが\n"
		.string "発見されました▼"
		.string "内部はミズびたしですが…\n"
		.string "どこかに生きてるデータが\n"
		.string "あるかもしれません▼"
		.string "バイルやオメガのデータを\n"
		.string "さがしていただきたいのですが…$"

Text_System_MissionAsk_10: @ 0x083772E2
	@ EN: Do you accept? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}おねがいできますか…\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_NeoArcadiaHas: @ 0x083772FB
	@ EN: Neo Arcadia has / completed a giant / elevator. / We do not know its / purpose. / They are bringing / something up from / deep underground.
	.string "{WINDOW 0x61}"
		.string "{BOTTOM}ネオ・アルカディアが\n"
		.string "巨大なエレベーターを\n"
		.string "カンセイさせたようです▼"
		.string "使用目的は、不明…▼"
		.string "地下深くより\n"
		.string "何かをはこんでいるようです$"

Text_System_MissionAsk_11: @ 0x0837734B
	@ EN: Can you investigate? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{BOTTOM}チョウサをおねがいできますか\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_CommencingTransfer: @ 0x08377368
	@ EN: Commencing transfer / to the coordinates / obtained from / Original X. / Zero... / Please be careful.
	.string "{WINDOW 0x61}"
		.string "オリジナルエックスより\n"
		.string "入手した ざひょうに転送します▼"
	.string "{WINDOW 0x40}"
		.string "ゼロ……▼"
		.string "気をつけてね………$"

Text_System_AreYouReady: @ 0x0837739C
	@ EN: Are you ready? / YES / NO
	.string "{WINDOW 0x62}"
		.string "ジュンビは、よろしいでしょうか？\n"
		.string "  はい\n"
		.string "  いいえ$"

@ フリーラン
Text_System_WhereToTransfer: @ 0x083773BA
Text_System_WhereToTransfer_Alias1: @ 0x083773BA
Text_System_WhereToTransfer_Alias2: @ 0x083773BA
Text_System_WhereToTransfer_Alias3: @ 0x083773BA
Text_System_WhereToTransfer_Alias4: @ 0x083773BA
	@ EN: Where to transfer?
	.string "{WINDOW 0x62}"
		.string "どこに転送しますか？$"

Text_System_DerelictSpacecraft: @ 0x083773C9
	@ EN: DERELICT SPACECRAFT? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}こわれたウチュウセン{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_AegisVolcanoBase: @ 0x083773E7
	@ EN: AEGIS VOLCANO BASE? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}アグニスかざんの基地{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_OceanicHwyRuins: @ 0x08377407
	@ EN: OCEANIC HWY RUINS? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}カイジョウのハイウェイあとち{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_WRFactory: @ 0x08377429
	@ EN: W.R. FACTORY? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}ヘイキ再生工場{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_OldResidential: @ 0x08377447
	@ EN: OLD RESIDENTIAL? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}旧きょじゅうく{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_MissileFactory: @ 0x08377463
	@ EN: MISSILE FACTORY? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}ミサイル工場{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_TwilightDesert: @ 0x0837747E
	@ EN: TWILIGHT DESERT? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}ゆうやみの砂ばく{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_ForestOfAnatre: @ 0x0837749B
	@ EN: FOREST OF ANATRE? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}アナトレーのモリ{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_FrontlineIceBase: @ 0x083774B7
	@ EN: FRONTLINE ICE BASE? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}コオリのゼンセン基地{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_AreaX2: @ 0x083774D7
	@ EN: AREA X-2? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}エリアX-2{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_EnergyFacility: @ 0x083774F1
	@ EN: ENERGY FACILITY? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}エネルギーしせつ{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_SnowyPlains: @ 0x0837750D
	@ EN: SNOWY PLAINS? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}セツゲン{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_SunkenLibrary: @ 0x08377525
	@ EN: SUNKEN LIBRARY? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}すいぼつしたトショカン{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_GiantElevator: @ 0x08377544
	@ EN: GIANT ELEVATOR? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}巨大エレベーター{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_SubArcadia: @ 0x08377562
	@ EN: SUB ARCADIA? / YES / NO
	.string "{WINDOW 0x62}"
		.string "{RED}アンダー・アルカディア{RED_END}ですね？\n"
		.string "  はい\n"
		.string "  いいえ$"

@ 転送
Text_System_MissionAssigned: @ 0x08377581
Text_System_MissionAssigned_Alias1: @ 0x08377581
Text_System_MissionAssigned_Alias2: @ 0x08377581
Text_System_MissionAssigned_Alias3: @ 0x08377581
Text_System_MissionAssigned_Alias4: @ 0x08377581
	@ EN: Mission assigned... / All personnel, / prepare to transfer.
	.string "{WINDOW 0x61}"
		.string "ミッションはつれい…\n"
		.string "かくいん、転送じゅんびにかかれ$"

Text_System_PreparationsFor: @ 0x083775A0
	@ EN: Preparations for / transfer complete.
	.string "{WINDOW 0x62}"
		.string "転送じゅんびカンリョウ…$"

Text_System_Transfer: @ 0x083775B1
	@ EN: Transfer!
	.string "{WINDOW 0x61}"
		.string "転送！$"

@ シエルの見送りメッセージ
Text_System_ZeroBeCareful: @ 0x083775B9
Text_System_ZeroBeCareful_Alias1: @ 0x083775B9
	@ EN: Zero... Be careful.
	.string "{WINDOW 0x40}"
		.string "ゼロ…気をつけて……$"
Text_System_ZeroEllipsis: @ 0x083775C7
	@ EN: Zero...
	.string "{WINDOW 0x40}"
		.string "ゼロ……$"

Text_System_ZeroComeBackSafely: @ 0x083775CE
	@ EN: Zero... / Come back safely... / Okay?
	.string "{WINDOW 0x40}"
		.string "ゼロ……▼"
		.string "かならず…\n"
		.string "かえってきて…ね…$"

Text_System_DonTDoAnything: @ 0x083775E5
	@ EN: Don't do anything / dangerous, Zero...
	.string "{WINDOW 0x40}"
		.string "無理しないでね…ゼロ$"

Text_System_ZeroComeBackSafely_2: @ 0x083775F4
	@ EN: Zero... / Come back safely...
	.string "{WINDOW 0x40}"
		.string "ゼロ……▼"
		.string "かえって…きてね……$"

Text_System_Zerrroooo: @ 0x08377606
	@ EN: Zerrroooo!
	.string "{WINDOW 0x40}"
		.string "ゼローーーーーー！$"

@ ミッション終了後
Text_System_Transferring: @ 0x08377612
	@ EN: Transferring... / Two... / One...
	.string "{WINDOW 0x62}"
		.string "転送カンリョウまで…     \n"
		.string "2…     \n"
		.string "1…$"

Text_System_TransferComplete: @ 0x08377631
	@ EN: Transfer complete.
	.string "{WINDOW 0x61}"
		.string "おつかれさまでした$"

Text_System_WhatShouldIDoWell: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias1: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias2: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias3: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias4: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias5: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias6: @ 0x0837763D
Text_System_WhatShouldIDoWell_Alias7: @ 0x0837763D
	@ EN: What should I do? / Well, for now... / Not letting Neo / Arcadia have the / Dark Elf... / That would be / priority number one. / I will calculate / our best course of / action, giving / priority to the / search for the / Dark Elf. / I will report to / Ms. Ciel as soon as / the results are in.
	.string "{WINDOW 0x40}"
		.string "どうしたらいいんだろう……\n"
		.string "わたし………▼"
	.string "{WINDOW 0x05}"
		.string "とりあえず……▼"
		.string "ダークエルフを\n"
		.string "ネオ・アルカディアに\n"
		.string "わたさないことが……▼"
		.string "サイユウセン……だな▼"
	.string "{WINDOW 0x62}"
		.string "ダークエルフそうさくを\n"
		.string "サイユウセンとして……▼"
		.string "今後ワレワレがとるべき行動を\n"
		.string "シミュレートしてみます▼"
		.string "ケッカがわかりしだい\n"
		.string "シエルさんにホウコクしますね$"

Text_System_ThankYouZeroWeFailed: @ 0x083776DA
	@ EN: Thank you, Zero. / We failed to destroy / the missile, / but I believe we / succeeded in / delaying its / construction. / I will analyze the / route to the missile / factory as quickly / as possible. / Please wait a bit / longer, okay?
	.string "{WINDOW 0x40}"
		.string "ありがとう…ゼロ▼"
		.string "ミサイルは、\n"
		.string "ハカイできなかったけど……▼"
		.string "これでミサイルのケンゾウを\n"
		.string "おくらせることができたはず……▼"
		.string "ミサイル工場へのルートは、\n"
		.string "できるだけ\n"
		.string "いそいでカイセキするわ▼"
		.string "もうしばらく\n"
		.string "時間をちょうだい…ね$"

Text_System_ZeroIMSorryYou: @ 0x0837774D
	@ EN: Zero, I'm sorry. / You risked your life / to go after the Dark / Elf... / But the Dark Elf was / too fast, and we / lost sight of it. / I scanned that area / again, / but there's no / reading anywhere / in the vicinity. / I know an apology is / not enough, but I am / truly sorry, Zero.
	.string "{WINDOW 0x40}"
		.string "ゼロ…ごめんなさい……▼"
		.string "せっかくゼロがいのちがけで\n"
		.string "ダークエルフを\n"
		.string "おいかけてくれたのに……▼"
		.string "ダークエルフのスピードが\n"
		.string "はやすぎて\n"
		.string "見うしなってしまったの……▼"
		.string "もういちど\n"
		.string "さっきのエリアを\n"
		.string "スキャンしなおしたんだけど……▼"
		.string "やっぱり…もう…\n"
		.string "あのあたりにハンノウは\n"
		.string "ないみたい……▼"
		.string "あやまってすむことじゃないけど……\n"
		.string "本当にごめんなさい…ゼロ$"

Text_System_ZeroThankYouThatRecycling: @ 0x083777FD
	@ EN: Zero... Thank you. / That recycling plant / will be out of / operation for some / time, I think. / Thank you so much...
	.string "{WINDOW 0x40}"
		.string "ゼロ…ありがとう▼"
		.string "これで再生工場は、\n"
		.string "しばらく動かないと思うわ…▼"
		.string "本当に…ありがとう…$"

Text_System_ZeroThankYouTheReports: @ 0x08377832
	@ EN: Zero... Thank you. / The reports of the / Dark Elf... / They were really / Baby Elf sitings... / I wonder what Neo / Arcadia is planning / on doing with them.
	.string "{WINDOW 0x40}"
		.string "ゼロ、ありがとう…▼"
		.string "ホウコクにあった\n"
		.string "ダークエルフって…▼"
		.string "ベビーエルフたちのこと\n"
		.string "だったのね…▼"
		.string "ネオ・アルカディアは…\n"
		.string "あのコたちを使って\n"
		.string "何をするつもりなのかしら……$"

Text_System_CielGoodluck_7: @ 0x0837788B
	@ EN: Thank you, Zero. / Now that they are / without a leader, / the Neo Arcadians in / that area have / retreated. / Thank you so much...
	.string "{WINDOW 0x40}"
		.string "ありがとう…ゼロ…▼"
		.string "リーダーをうしなって\n"
		.string "このエリアのネオ・アルカディアは\n"
		.string "タイキャクしたみたい…▼"
		.string "本当にありがとう…$"

Text_System_CielGoodluck_8: @ 0x083778CB
	@ EN: Thank you, Zero. / Now that they are / without a leader, / the Neo Arcadians in / that area have / retreated. / Thank you so much...
	.string "{WINDOW 0x40}"
		.string "ありがとう…ゼロ…▼"
		.string "リーダーをうしなって\n"
		.string "このエリアのネオ・アルカディアは\n"
		.string "タイキャクしたみたい…▼"
		.string "本当にありがとう…$"

Text_System_CielGoodluck_9: @ 0x0837790B
	@ EN: Thank you, Zero. / Now that they are / without a leader, / the Neo Arcadians in / that area have / retreated. / Thank you so much...
	.string "{WINDOW 0x40}"
		.string "ありがとう…ゼロ…▼"
		.string "リーダーをうしなって\n"
		.string "このエリアのネオ・アルカディアは\n"
		.string "タイキャクしたみたい…▼"
		.string "本当にありがとう…$"

Text_System_WelcomeBackZeroItAppears: @ 0x0837794B
	@ EN: Welcome back, Zero. / It appears that Weil / was attempting to / mass-produce Baby / Elves at that / factory. / But I wonder... / What was he planning / on doing with all / those Baby Elves?
	.string "{WINDOW 0x40}"
		.string "おかえりなさい…ゼロ…▼"
		.string "バイルは、あの工場で\n"
		.string "ベビーエルフをタイリョウに\n"
		.string "作ろうとしてたみたい…▼"
		.string "でも いったい……▼"
		.string "ベビーエルフをあんなに作って…\n"
		.string "バイルは何するつもりだったのかしら$"

Text_System_CielGoodluck_12: @ 0x083779AE
	@ EN: Zero... Thank you. / I'm analyzing all of / the data you / recovered for us. / We may be able to / figure out what Weil / is attempting to do, / by analyzing past / data. / I'll do my best.
	.string "{WINDOW 0x40}"
		.string "ゼロ…ありがとう…▼"
		.string "カイシュウしてくれたデータは\n"
		.string "今、全力で\n"
		.string "ブンセキをしているわ…▼"
		.string "過去のデータを\n"
		.string "ブンセキすることで…▼"
		.string "バイルが今、\n"
		.string "何をしようとしているか…\n"
		.string "わかるかもしれない▼"
		.string "わたしも…がんばるから…ね$"

Text_System_CielGoodluck_13: @ 0x08377A21
	@ EN: Zero... Thank you. / I'm analyzing all of / the data you / recovered for us. / We may be able to / figure out what Weil / is attempting to do, / by analyzing past / data. / I'll do my best.
	.string "{WINDOW 0x40}"
		.string "ゼロ…ありがとう…▼"
		.string "カイシュウしてくれたデータは\n"
		.string "今、全力で\n"
		.string "ブンセキにかけてるわ…▼"
		.string "過去のデータを\n"
		.string "ブンセキすることで…▼"
		.string "バイルが今、\n"
		.string "何をしようとしているか…\n"
		.string "わかるかもしれない▼"
		.string "わたしも…がんばるから…ね…$"

Text_System_ThankYouZeroItLooks: @ 0x08377A95
	@ EN: Thank you, Zero. / It looks like that / elevator was being / used to carry mass / amounts of / E-Crystals. / But, I wonder... / What was Weil up to / with all that / energy?
	.string "{WINDOW 0x40}"
		.string "ありがとう…ゼロ…▼"
		.string "あのエレベーターは、\n"
		.string "Eクリスタルをたいりょうに\n"
		.string "はこんでいたみたい…▼"
		.string "でも、いったい……▼"
		.string "あんなにエネルギーを集めて…\n"
		.string "バイルは何するつもりだったのかしら$"

Text_System_ZeroItSGreatTo: @ 0x08377AF2
	@ EN: Zero, it's great to / see you back safe. / X just sent us some / new coordinates. / Apparently, they / indicate where / Weil and Omega are. / This may be the last / battle... / Come talk to me when / you are ready.
	.string "{WINDOW 0x40}"
		.string "ゼロ…無事でよかった…▼"
		.string "さっきエックスから\n"
		.string "新しいザヒョウがおくられてきたの▼"
		.string "どうやらそこに\n"
		.string "バイルとオメガがいるみたい…▼"
		.string "これが最後の戦いに\n"
		.string "なるかもしれない……▼"
		.string "ジュンビができたら\n"
		.string "声をかけてね…$"

@ セルヴォ
Text_System_WhatWillItBe: @ 0x08377B60
	@ EN: What will it be? / Secret Disk / Talk
	.string "{WINDOW 0x43}"
		.string "なんのようかな？\n"
		.string "  シークレットディスクのカイセキ\n"
		.string "  話をする$"

@ コンピュータ
Text_System_BootCompleted: @ 0x08377B85
	@ EN: Boot completed.
	.string "{WINDOW 0x02}"
		.string "キドウシマシタ$"

Text_System_EnterCommand: @ 0x08377B8F
	@ EN: Enter command. / Look something up / Transmission
	.string "{WINDOW 0x02}"
		.string "コマンド ヲ センタク シテ クダサイ\n"
		.string "  何かをしらべる\n"
		.string "  通信する$"

Text_System_CanTradeBattlechipsW: @ 0x08377BB9
	@ EN: Can trade BattleChips w /  / "MMBN 4 Red Sun" and / "MMBN 4 Blue Moon." / Send BattleChips to / "MMZ 3" to change / enemies in Cyberspace. / Begin transmission by / selecting "BattleChips" from / "Trade" in "Comm." / on the PET screen of "Mega / Man Battle Network 4."
	.string "{WINDOW 0x02}"
		.string "「ロックマンエグゼ4 レッドサン」\n"
		.string "「ロックマンエグゼ4 ブルームーン」 ト\n"
		.string "バトルチップ トレード ガ デキマス▼"
		.string "「ロックマンゼロ3」 ニ バトルチップ ヲ オクル ト\n"
		.string "サイバークウカン ノ テキ ガ ヘンカ シマス▼"
		.string "「ロックマンエグゼ4」 デ PETガメン ニ ハイリ\n"
		.string "「つうしん」 ノ 「トレード」 カラ\n"
		.string "「バトルチップ」 ヲ センタク シテ 通信シテクダサイ$"

Text_System_BeginTransmission: @ 0x08377C75
	@ EN: Begin transmission? / YES / NO
	.string "{WINDOW 0x02}"
		.string "通信ヲ カイシ シマスカ？\n"
		.string "  はい\n"
		.string "  いいえ$"

Text_System_WaitingForTransmission: @ 0x08377C92
	@ EN: Waiting for transmission. /  / (Cancel with the B BUTTON)
	.string "{WINDOW 0x02}"
		.string "通信タイキ中デス\n"
		.string "\n"
		.string "(Bボタン デ キャンセル デキマス)$"

Text_System_CommunicatingWith: @ 0x08377CB5
	@ EN: Communicating with / MMBN 4. Enter / commands from MMBN 4.
	.string "{WINDOW 0x02}"
		.string "ロックマンエグゼ4 ト 通信中デス\n"
		.string "ロックマンエグゼ4 ガワ デ ソウサ シテ クダサイ$"

Text_System_TransmissionError: @ 0x08377CE7
	@ EN: Transmission error. / Ending transmission.
	.string "{WINDOW 0x02}"
		.string "通信エラー デス\n"
		.string "通信ヲ シュウリョウ シマス$"

Text_System_TransmissionComplete: @ 0x08377D05
	@ EN: Transmission complete. / Cyberspace has changed!
	.string "{WINDOW 0x02}"
		.string "通信カンリョウ\n"
		.string "サイバークウカン ガ ヘンカ シマシタ！$"

Text_System_TransmissionComplete_2: @ 0x08377D26
	@ EN: Transmission complete.
	.string "{WINDOW 0x02}"
		.string "通信カンリョウ$"

@ 改造カード
Text_System_MegaBoosterCardReceived: @ 0x08377D32
Text_System_MegaBoosterCardReceived_Alias1: @ 0x08377D32
Text_System_MegaBoosterCardReceived_Alias2: @ 0x08377D32
Text_System_MegaBoosterCardReceived_Alias3: @ 0x08377D32
	@ EN: Mega Booster Card received. / BOOST UP / CANCEL
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}改造カードをじゅしんしました\n"
		.string "  改造じっこう\n"
		.string "  やめておく$"

Text_System_TransmissionError_2: @ 0x08377D59
	@ EN: Transmission error.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}通信エラーです$"

Text_System_CardBoostReverted: @ 0x08377D66
	@ EN: Card boost reverted / to previous state.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}カード{VARIABLE}の改造を もとにもどしました$"

Text_System_TitleBackgroundPicture: @ 0x08377D7E
Text_System_TitleBackgroundPicture_Alias1: @ 0x08377D7E
Text_System_TitleBackgroundPicture_Alias2: @ 0x08377D7E
Text_System_TitleBackgroundPicture_Alias3: @ 0x08377D7E
	@ EN: Title background picture / has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}タイトルバックのえが\n"
		.string "ちがうものに かわりました$"

Text_System_PottedPlantAddedTo: @ 0x08377D9A
	@ EN: Potted plant added to / Resistance Base, somewhere.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのどこかに\n"
		.string "はちうえが おかれました$"

Text_System_DesignOfElevatorIn: @ 0x08377DB9
	@ EN: Design of elevator in / Resistance Base changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのエレベーターの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_3: @ 0x08377DDB
	@ EN: Attack of Z Saber increased / by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゼットセイバーのコウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_PHunterEnergy: @ 0x08377E01
	@ EN: P. Hunter energy / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パンテオン・ハンターの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_PGuardianEnergy: @ 0x08377E1E
	@ EN: P. Guardian energy / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パンテオン・ガーディアンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_DesignOfNurseElvesHas: @ 0x08377E3D
	@ EN: Design of Nurse elves has / changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ナース系エルフの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_7: @ 0x08377E57
	@ EN: You have a new friend some- / where on the second floor / of the Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースの2かいの\n"
		.string "どこかに 仲間が ふえました$"

Text_System_TheDesignOfBustershot: @ 0x08377E7A
	@ EN: The design of BusterShot / bullets has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}バスターショットのタマの\n"
		.string "デザインが かわりました$"

Text_System_TheDesignOfTheZ: @ 0x08377E97
	@ EN: The design of the Z Panels / in the game has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゲーム中に出現するZパネルの\n"
		.string "デザインが かわりました$"

Text_System_TheDesignOfAlouetteS: @ 0x08377EB9
	@ EN: The design of Alouette's / clothing has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アルエットのきている ふくの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_11: @ 0x08377ED8
	@ EN: Attack of Animal elves / Archim and Archil have / increased by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのアーチムと\n"
		.string "アーチルのコウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_ZeroSDefenseIsNow: @ 0x08377F0B
	@ EN: Zero's Defense is now / doubled.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゼロのボウギョりょくが\n"
		.string "つうじょう時の2倍になりました$"

Text_System_TheDesignOfTheMessage: @ 0x08377F2C
	@ EN: The design of the message / window has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}メッセージウィンドウの\n"
		.string "デザインが かわりました$"

Text_System_TheDesignOfLifeEnergy: @ 0x08377F48
	@ EN: The design of Life Energy / has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ライフエネルギーの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_18: @ 0x08377F62
	@ EN: Attack of Recoil Rod has / increased by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}リコイルロッドのコウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_AllBoostedItemsHave: @ 0x08377F88
	@ EN: All boosted items have / been reset to default.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}これまで改造したものを\n"
		.string "すべて リセットしました$"

Text_System_ThereIsALostCat: @ 0x08377FA6
	@ EN: There is a lost cat / somewhere in the / Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのどこかに\n"
		.string "ネコが まよいこみました$"

Text_System_ItIsSnowingAtThe: @ 0x08377FC5
	@ EN: It is snowing at the / Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースに\n"
		.string "ユキが ふってきました$"

Text_System_TheDesignOfThe: @ 0x08377FDF
	@ EN: The design of the / E-Crystals in the / game has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゲーム中に出現する\n"
		.string "Eクリスタルの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_23: @ 0x08378004
	@ EN: Attack of S.Boomerang / has increased by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シールドブーメランの\n"
		.string "コウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_ModCard_24: @ 0x0837802D
	@ EN: Attack of Animal elves / Beetack and Beenipe have / increased by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのビータックと\n"
		.string "ビーナイプのコウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_DesignOfComputerIn: @ 0x08378062
	@ EN: Design of computer in / Ciel's room has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シエルのへやのコンピューターの\n"
		.string "デザインが かわりました$"

Text_System_AMysteriousCyberElfHas: @ 0x08378082
	@ EN: A mysterious Cyber-elf has / appeared somewhere in the / Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのどこかに\n"
		.string "なぞのサイバーエルフが現れました$"

Text_System_ModCard_27: @ 0x083780A6
	@ EN: The Attack of BusterShots / has increased by 1.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}バスターショットのコウゲキりょくが\n"
		.string "つうじょう時より{RED}1{RED_END}ふえました$"

Text_System_APaintingHasBeenHung: @ 0x083780CD
	@ EN: A painting has been hung / from the Resistance Base / wall.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのかべに\n"
		.string "カイガが かけられました$"

Text_System_ANewDoorHasAppeared: @ 0x083780EB
	@ EN: A new door has appeared / somewhere in the Resistance / Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのどこかに\n"
		.string "新しくトビラが出現しました$"

Text_System_ModCard_30: @ 0x0837810E
	@ EN: The Attack of BusterShots / has increased by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}バスターショットのコウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_ModCard_31: @ 0x08378135
	@ EN: You have a new friend some- / where on the first floor / of the Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースの1かいの\n"
		.string "どこかに 仲間が ふえました$"

Text_System_AFlowerHasBloomedOn: @ 0x08378158
	@ EN: A flower has bloomed on the / Resistance Base roof.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのおくじょうに\n"
		.string "はなが さきました$"

Text_System_TheDesignOfAnimalElves: @ 0x08378176
	@ EN: The design of Animal elves / has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフの\n"
		.string "デザインが かわりました$"

Text_System_AndrewLooksYoungerNow: @ 0x08378191
	@ EN: Andrew looks younger now.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アンドリューのすがたが\n"
		.string "わかがえりました$"

Text_System_ModCard_38: @ 0x083781A9
	@ EN: Attack of Animal elves / Archim and Archil have / increased by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのアーチムと\n"
		.string "アーチルのコウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_SeagullsNowFlyInThe: @ 0x083781DC
	@ EN: Seagulls now fly in the sky / above the Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのそらに\n"
		.string "カモメが やってきました$"

Text_System_ModCard_41: @ 0x083781FA
	@ EN: Attack of Animal elves / Beetack and Beenipe have / increased by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのビータックと\n"
		.string "ビーナイプのコウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_TheDesignOfSecretDisks: @ 0x0837822F
	@ EN: The design of Secret Disks / has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シークレットディスクの\n"
		.string "デザインが かわりました$"

Text_System_ModCard_43: @ 0x0837824B
	@ EN: Attack of S.Boomerang / has increased by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シールドブーメランの\n"
		.string "コウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_SomebodyHasDrawnGraffiti: @ 0x08378274
	@ EN: Somebody has drawn graffiti / on the Resistance Base / wall.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのかべに\n"
		.string "だれかが ラクガキしました$"

Text_System_ModCard_48: @ 0x08378293
	@ EN: Attack of Recoil Rod has / increased by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}リコイルロッドのコウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_ModCard_52: @ 0x083782B9
	@ EN: The conversation with the / Resistance fighter in the / watchtower at the right / side of the base has / changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースの右の\n"
		.string "カンシトウにいるレジスタンスの\n"
		.string "会話のナイヨウが かわりました$"

Text_System_ModCard_60: @ 0x083782EC
	@ EN: Attack of S.Boomerang / has increased by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シールドブーメランの\n"
		.string "コウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_ModCard_61: @ 0x08378315
	@ EN: The conversation with the / Resistance fighter in the / watchtower at the left / side of the base has / changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースの左の\n"
		.string "カンシトウにいるレジスタンスの\n"
		.string "会話のナイヨウが かわりました$"

Text_System_ModCard_64: @ 0x08378348
	@ EN: Attack of Animal elves / Beetack and Beenipe have / increased by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのビータックと\n"
		.string "ビーナイプのコウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_ModCard_65: @ 0x0837837D
	@ EN: Attack of Animal elves / Archim and Archil have / increased by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのアーチムと\n"
		.string "アーチルのコウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_TheDesignOfHackerElves: @ 0x083783B0
	@ EN: The design of Hacker elves / has changed.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ハッカー系エルフの\n"
		.string "デザインが かわりました$"

Text_System_EnergyOfCrossbyneHas: @ 0x083783CB
	@ EN: Energy of Crossbyne has / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}クロスバインの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfPBase: @ 0x083783E4
	@ EN: Energy of P. Base / has increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パンテオン・ベースの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_ModCard_69: @ 0x08378400
	@ EN: The Attack of BusterShots / has increased by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}バスターショットのコウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_ItIsNowNighttimeAt: @ 0x08378427
	@ EN: It is now nighttime at the / Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースが\n"
		.string "よるに なりました$"

Text_System_EnergyOfPAqua: @ 0x0837843F
	@ EN: Energy of P. Aqua / has increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パンテオン・アクアの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_FishNowJumpAroundThe: @ 0x0837845B
	@ EN: Fish now jump around the / Resistance Base harbor.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースのミナトで\n"
		.string "サカナが はねるようになりました$"

Text_System_ModCard_78: @ 0x0837847E
	@ EN: Attack of Recoil Rod has / increased by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}リコイルロッドのコウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_ModCard_79: @ 0x083784A4
	@ EN: You have a new friend some- / where on the third floor / of the Resistance Base.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レジスタンスベースの3かいの\n"
		.string "どこかに 仲間が ふえました$"

Text_System_ModCard_81: @ 0x083784C7
	@ EN: Attack of Animal elves / Archim and Archil have / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アニマル系エルフのアーチムと\n"
		.string "アーチルのコウゲキりょくが\n"
		.string "つうじょう時より{RED}4{RED_END}ふえました$"

Text_System_ModCard_82: @ 0x083784FA
	@ EN: Attack of Z Saber increased / by 2.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゼットセイバーのコウゲキりょくが\n"
		.string "つうじょう時より{RED}2{RED_END}ふえました$"

Text_System_EnergyOfPBomber: @ 0x08378520
	@ EN: Energy of P. Bomber / has increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パンテオン・ボマーの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfAlteredP: @ 0x0837853C
	@ EN: Energy of altered P. / Aqua has increased by / 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}かいぞうパンテオン・アクアの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_ModCard_90: @ 0x0837855D
	@ EN: Attack of Z Saber increased / by 3.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ゼットセイバーのコウゲキりょくが\n"
		.string "つうじょう時より{RED}3{RED_END}ふえました$"

Text_System_EnergyOfPurplenerple: @ 0x08378583
	@ EN: Energy of PurpleNerple / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}パープルナープルの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfShellcrawler: @ 0x0837859E
	@ EN: Energy of Shellcrawler / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シェルクローラーの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfIcebonIncreased: @ 0x083785B9
	@ EN: Energy of Icebon increased / by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}アイスボンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfGCannon: @ 0x083785D1
	@ EN: Energy of G. Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ジェネレーターキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfClaveker: @ 0x083785EF
	@ EN: Energy of Claveker / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}クラベッガーの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfShotcounter: @ 0x08378608
	@ EN: Energy of Shotcounter / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シャットカウンターの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfGrandCannon: @ 0x08378624
	@ EN: Energy of Grand Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}グランドキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfShrimpolin: @ 0x0837863F
	@ EN: Energy of Shrimpolin / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シュリンポリンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfBatring: @ 0x08378659
	@ EN: Energy of Batring / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}バットンリングの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfPCannon: @ 0x08378673
	@ EN: Energy of P. Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ピラーキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfVolcaire: @ 0x0837868D
	@ EN: Energy of Volcaire / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ヴォルケールの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfSnakecord: @ 0x083786A6
	@ EN: Energy of Snakecord / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}スネーケーブルの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfLemmingles: @ 0x083786C0
	@ EN: Energy of Lemmingles / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}レミングルスの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfLamplort: @ 0x083786D9
	@ EN: Energy of Lamplort / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ランプロートの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfTileCannon: @ 0x083786F2
	@ EN: Energy of Tile Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}タイルキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfShelluno: @ 0x0837870C
	@ EN: Energy of Shelluno / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シェルーノーの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfHeavyCannon: @ 0x08378725
	@ EN: Energy of Heavy Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ヘビーキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfMothjiro: @ 0x0837873F
	@ EN: Energy of Mothjiro / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}モスジーロの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfCCannon: @ 0x08378757
	@ EN: Energy of C. Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}カプセルキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfCalibeeG: @ 0x08378772
	@ EN: Energy of Calibee G / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}キャリビーGの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_EnergyOfDeathlock: @ 0x0837878C
	@ EN: Energy of Deathlock / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ダスロックの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfGyroCannon: @ 0x083787A4
	@ EN: Energy of Gyro Cannon / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ジャイロキャノンの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfSharkshielX: @ 0x083787BF
	@ EN: Energy of Sharkshiel X / increased by 4.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}シャークシールXの体力が\n"
		.string "{RED}4{RED_END}ふえました$"

Text_System_EnergyOfOlwarmer: @ 0x083787DA
	@ EN: Energy of Olwarmer / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}オールワーマーの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_EnergyOfBranwarmer: @ 0x083787F5
	@ EN: Energy of Branwarmer / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ブランワーマーの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_EnergyOfLocomoIf: @ 0x08378810
	@ EN: Energy of Locomo IF / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ロコモIFの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_EnergyOfBeeserver: @ 0x08378829
	@ EN: Energy of Beeserver / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}ビーサーバーの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_EnergyOfMegamilpa: @ 0x08378843
	@ EN: Energy of Megamilpa / increased by 16.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}メガミルパの体力が\n"
		.string "{RED}16{RED_END}ふえました$"

Text_System_ZeroSMiniGame: @ 0x0837885C
Text_System_ZeroSMiniGame_Alias1: @ 0x0837885C
Text_System_ZeroSMiniGame_Alias2: @ 0x0837885C
Text_System_ZeroSMiniGame_Alias3: @ 0x0837885C
	@ EN: Zero's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}ゼロ{RED_END}のミニゲームが ツイカされました$"

Text_System_CielSMiniGame: @ 0x08378874
	@ EN: Ciel's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}シエル{RED_END}のミニゲームが ツイカされました$"

Text_System_CopyXSMiniGame: @ 0x0837888D
	@ EN: Copy X's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}コピーエックス{RED_END}のミニゲームが ツイカされました$"

Text_System_HarpuiaSMiniGame: @ 0x083788AA
	@ EN: Harpuia's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}ハルピュイア{RED_END}のミニゲームが ツイカされました$"

Text_System_FefnirSMiniGame: @ 0x083788C6
	@ EN: Fefnir's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}ファーブニル{RED_END}のミニゲームが ツイカされました$"

Text_System_LeviathanSMiniGame: @ 0x083788E2
	@ EN: Leviathan's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}レヴィアタン{RED_END}のミニゲームが ツイカされました$"

Text_System_PhantomSMiniGame: @ 0x083788FE
	@ EN: Phantom's mini game / added!
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}ファントム{RED_END}のミニゲームが ツイカされました$"

Text_System_HardModeAddedPlayIn: @ 0x08378919
	@ EN: Hard Mode added! / Play in Hard Mode by / holding the L BUTTON down / while selecting NEW GAME.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}ハードモード{RED_END}が ツイカされました▼"
		.string "Lボタンをおしながら\n"
		.string "「はじめから」をせんたくすると\n"
		.string "ハードモードでプレイすることができます$"

Text_System_UltimateModeAddedPlayIn: @ 0x0837895E
	@ EN: Ultimate Mode added! / Play in Ultimate Mode by / holding the R BUTTON down / while selecting NEW GAME.
	.string "{WINDOW 0x02}"
		.string "{BOTTOM}{RED}アルティメットモード{RED_END}が ツイカされました▼"
		.string "Rボタンをおしながら\n"
		.string "「はじめから」をせんたくすると\n"
		.string "アルティメットモードでプレイすることができます$"

.balign 4, 0
