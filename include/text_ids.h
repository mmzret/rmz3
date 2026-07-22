#ifndef GUARD_RMZ3_TEXT_IDS_H
#define GUARD_RMZ3_TEXT_IDS_H

// Named message IDs for the gTextTable / PrintTextWindow dialogue system.
//   - PrintTextWindow(TEXT_SYSTEM_DO_SOME_SCOUTING, kind)   direct
//   - TextID arrays, e.g. MissionAskTextIDs[] = { TEXT_..., ... }
//   - script command macros, e.g. `message 1, 0, TEXT_SPACE_CRAFT_...`
// Each comment is the official English (US) line for that message.

#define TEXT_SYSTEM_THE_NEO_ARCADIAN 0x0014                                      // The Neo Arcadian / army is building up / at the base in Aegi
#define TEXT_SYSTEM_DO_SOME_SCOUTING 0x0015                                      // Do some scouting? / YES / NO
#define TEXT_SYSTEM_WE_VE_VERIFIED_A 0x0016                                      // We've verified a / reading similar to / the Dark Elf on the
#define TEXT_SYSTEM_MISSION_ASK_1 0x0017                                         // Do you accept? / YES / NO
#define TEXT_SYSTEM_WE_HAVE_DISCOVERED_A 0x0018                                  // We have discovered a / Neo Arcadian weapons / factory. / The
#define TEXT_SYSTEM_MISSION_ASK_2 0x0019                                         // Do you accept? / YES / NO
#define TEXT_SYSTEM_THIS_WAS_ARESI 0x001A                                        // This was a resi- / dential area where / humans once lived. /
#define TEXT_SYSTEM_MISSION_ASK_3 0x001B                                         // Can you investigate? / YES / NO
#define TEXT_SYSTEM_MISSION_SUMMARY_4 0x001C                                     // We have detected / Neo Arcadian units / moving through the /
#define TEXT_SYSTEM_MISSION_ASK_4 0x001D                                         // Can you intercept? / YES / NO
#define TEXT_SYSTEM_MISSION_SUMMARY_5 0x001E                                     // We have detected / Neo Arcadian units / moving through the /
#define TEXT_SYSTEM_MISSION_ASK_5 0x001F                                         // Can you intercept? / YES / NO
#define TEXT_SYSTEM_MISSION_SUMMARY_6 0x0020                                     // We have detected / Neo Arcadian units / moving through the /
#define TEXT_SYSTEM_MISSION_ASK_6 0x0021                                         // Can you intercept? / YES / NO
#define TEXT_SYSTEM_WE_HAVE_ANALYZED_THE 0x0022                                  // We have analyzed the / enemy's movements... / As a result, w
#define TEXT_SYSTEM_MISSION_ASK_7 0x0023                                         // Are you ready? / YES / NO
#define TEXT_SYSTEM_THIS_IS_ANEO 0x0024                                          // This is a Neo / Arcadian energy / plant. It is / currently s
#define TEXT_SYSTEM_MISSION_ASK_8 0x0025                                         // Can you investigate? / YES / NO
#define TEXT_SYSTEM_CONTAINERS_HAVE 0x0026                                       // Containers have / fallen out of a / space ship, / which fell
#define TEXT_SYSTEM_MISSION_ASK_9 0x0027                                         // Do you accept? / YES / NO
#define TEXT_SYSTEM_THE_RUINS_OF_AN 0x0028                                       // The ruins of an / ancient library have / been found. / It's
#define TEXT_SYSTEM_MISSION_ASK_10 0x0029                                        // Do you accept? / YES / NO
#define TEXT_SYSTEM_NEO_ARCADIA_HAS 0x002A                                       // Neo Arcadia has / completed a giant / elevator. / We do not
#define TEXT_SYSTEM_MISSION_ASK_11 0x002B                                        // Can you investigate? / YES / NO
#define TEXT_SYSTEM_WHERE_TO_TRANSFER_ALIAS1 0x002F                              // Where to transfer?
#define TEXT_SYSTEM_WHERE_TO_TRANSFER_ALIAS2 0x0030                              // Where to transfer?
#define TEXT_SYSTEM_WHERE_TO_TRANSFER_ALIAS3 0x0031                              // Where to transfer?
#define TEXT_SYSTEM_WHERE_TO_TRANSFER_ALIAS4 0x0032                              // Where to transfer?
#define TEXT_SYSTEM_DERELICT_SPACECRAFT 0x0033                                   // DERELICT SPACECRAFT? / YES / NO
#define TEXT_SYSTEM_AEGIS_VOLCANO_BASE 0x0034                                    // AEGIS VOLCANO BASE? / YES / NO
#define TEXT_SYSTEM_OCEANIC_HWY_RUINS 0x0035                                     // OCEANIC HWY RUINS? / YES / NO
#define TEXT_SYSTEM_WRFACTORY 0x0036                                             // W.R. FACTORY? / YES / NO
#define TEXT_SYSTEM_OLD_RESIDENTIAL 0x0037                                       // OLD RESIDENTIAL? / YES / NO
#define TEXT_SYSTEM_MISSILE_FACTORY 0x0038                                       // MISSILE FACTORY? / YES / NO
#define TEXT_SYSTEM_TWILIGHT_DESERT 0x0039                                       // TWILIGHT DESERT? / YES / NO
#define TEXT_SYSTEM_FOREST_OF_ANATRE 0x003A                                      // FOREST OF ANATRE? / YES / NO
#define TEXT_SYSTEM_FRONTLINE_ICE_BASE 0x003B                                    // FRONTLINE ICE BASE? / YES / NO
#define TEXT_SYSTEM_AREA_X2 0x003C                                               // AREA X-2? / YES / NO
#define TEXT_SYSTEM_ENERGY_FACILITY 0x003D                                       // ENERGY FACILITY? / YES / NO
#define TEXT_SYSTEM_SNOWY_PLAINS 0x003E                                          // SNOWY PLAINS? / YES / NO
#define TEXT_SYSTEM_SUNKEN_LIBRARY 0x003F                                        // SUNKEN LIBRARY? / YES / NO
#define TEXT_SYSTEM_GIANT_ELEVATOR 0x0040                                        // GIANT ELEVATOR? / YES / NO
#define TEXT_SYSTEM_SUB_ARCADIA 0x0041                                           // SUB ARCADIA? / YES / NO
#define TEXT_SYSTEM_MISSION_ASSIGNED_ALIAS4 0x0046                               // Mission assigned... / All personnel, / prepare to transfer.
#define TEXT_SYSTEM_PREPARATIONS_FOR 0x0047                                      // Preparations for / transfer complete.
#define TEXT_SYSTEM_TRANSFER 0x0048                                              // Transfer!
#define TEXT_SYSTEM_TRANSFERRING 0x0050                                          // Transferring... / Two... / One...
#define TEXT_SYSTEM_TRANSFER_COMPLETE 0x0051                                     // Transfer complete.
#define TEXT_SYSTEM_WHAT_SHOULD_IDO_WELL_ALIAS7 0x0059                           // What should I do? / Well, for now... / Not letting Neo / Arc
#define TEXT_SYSTEM_THANK_YOU_ZERO_WE_FAILED 0x005A                              // Thank you, Zero. / We failed to destroy / the missile, / but
#define TEXT_SYSTEM_ZERO_IMSORRY_YOU 0x005B                                      // Zero, I'm sorry. / You risked your life / to go after the Da
#define TEXT_SYSTEM_ZERO_THANK_YOU_THAT_RECYCLING 0x005C                         // Zero... Thank you. / That recycling plant / will be out of /
#define TEXT_SYSTEM_ZERO_THANK_YOU_THE_REPORTS 0x005D                            // Zero... Thank you. / The reports of the / Dark Elf... / They
#define TEXT_SYSTEM_CIEL_GOODLUCK_7 0x005E                                       // Thank you, Zero. / Now that they are / without a leader, / t
#define TEXT_SYSTEM_CIEL_GOODLUCK_8 0x005F                                       // Thank you, Zero. / Now that they are / without a leader, / t
#define TEXT_SYSTEM_CIEL_GOODLUCK_9 0x0060                                       // Thank you, Zero. / Now that they are / without a leader, / t
#define TEXT_SYSTEM_WELCOME_BACK_ZERO_IT_APPEARS 0x0061                          // Welcome back, Zero. / It appears that Weil / was attempting
#define TEXT_SYSTEM_CIEL_GOODLUCK_12 0x0062                                      // Zero... Thank you. / I'm analyzing all of / the data you / r
#define TEXT_SYSTEM_CIEL_GOODLUCK_13 0x0063                                      // Zero... Thank you. / I'm analyzing all of / the data you / r
#define TEXT_SYSTEM_THANK_YOU_ZERO_IT_LOOKS 0x0064                               // Thank you, Zero. / It looks like that / elevator was being /
#define TEXT_SYSTEM_ZERO_IT_SGREAT_TO 0x0065                                     // Zero, it's great to / see you back safe. / X just sent us so
#define TEXT_SYSTEM_TITLE_BACKGROUND_PICTURE_ALIAS3 0x0079                       // Title background picture / has changed.
#define TEXT_SYSTEM_POTTED_PLANT_ADDED_TO 0x007A                                 // Potted plant added to / Resistance Base, somewhere.
#define TEXT_SYSTEM_DESIGN_OF_ELEVATOR_IN 0x007B                                 // Design of elevator in / Resistance Base changed.
#define TEXT_SYSTEM_MOD_CARD_3 0x007C                                            // Attack of Z Saber increased / by 1.
#define TEXT_SYSTEM_PHUNTER_ENERGY 0x007D                                        // P. Hunter energy / increased by 4.
#define TEXT_SYSTEM_PGUARDIAN_ENERGY 0x007E                                      // P. Guardian energy / increased by 4.
#define TEXT_SYSTEM_DESIGN_OF_NURSE_ELVES_HAS 0x007F                             // Design of Nurse elves has / changed.
#define TEXT_SYSTEM_MOD_CARD_7 0x0080                                            // You have a new friend some- / where on the second floor / of
#define TEXT_SYSTEM_THE_DESIGN_OF_BUSTERSHOT 0x0081                              // The design of BusterShot / bullets has changed.
#define TEXT_SYSTEM_THE_DESIGN_OF_THE_Z 0x0082                                   // The design of the Z Panels / in the game has changed.
#define TEXT_SYSTEM_THE_DESIGN_OF_ALOUETTE_S 0x0083                              // The design of Alouette's / clothing has changed.
#define TEXT_SYSTEM_MOD_CARD_11 0x0084                                           // Attack of Animal elves / Archim and Archil have / increased
#define TEXT_SYSTEM_ZERO_SDEFENSE_IS_NOW 0x0085                                  // Zero's Defense is now / doubled.
#define TEXT_SYSTEM_THE_DESIGN_OF_THE_MESSAGE 0x0086                             // The design of the message / window has changed.
#define TEXT_SYSTEM_THE_DESIGN_OF_LIFE_ENERGY 0x0087                             // The design of Life Energy / has changed.
#define TEXT_SYSTEM_MOD_CARD_18 0x0088                                           // Attack of Recoil Rod has / increased by 1.
#define TEXT_SYSTEM_ALL_BOOSTED_ITEMS_HAVE 0x0089                                // All boosted items have / been reset to default.
#define TEXT_SYSTEM_THERE_IS_ALOST_CAT 0x008A                                    // There is a lost cat / somewhere in the / Resistance Base.
#define TEXT_SYSTEM_IT_IS_SNOWING_AT_THE 0x008B                                  // It is snowing at the / Resistance Base.
#define TEXT_SYSTEM_THE_DESIGN_OF_THE 0x008C                                     // The design of the / E-Crystals in the / game has changed.
#define TEXT_SYSTEM_MOD_CARD_23 0x008D                                           // Attack of S.Boomerang / has increased by 1.
#define TEXT_SYSTEM_MOD_CARD_24 0x008E                                           // Attack of Animal elves / Beetack and Beenipe have / increase
#define TEXT_SYSTEM_DESIGN_OF_COMPUTER_IN 0x008F                                 // Design of computer in / Ciel's room has changed.
#define TEXT_SYSTEM_AMYSTERIOUS_CYBER_ELF_HAS 0x0090                             // A mysterious Cyber-elf has / appeared somewhere in the / Res
#define TEXT_SYSTEM_MOD_CARD_27 0x0091                                           // The Attack of BusterShots / has increased by 1.
#define TEXT_SYSTEM_APAINTING_HAS_BEEN_HUNG 0x0092                               // A painting has been hung / from the Resistance Base / wall.
#define TEXT_SYSTEM_ANEW_DOOR_HAS_APPEARED 0x0093                                // A new door has appeared / somewhere in the Resistance / Base
#define TEXT_SYSTEM_MOD_CARD_30 0x0094                                           // The Attack of BusterShots / has increased by 2.
#define TEXT_SYSTEM_MOD_CARD_31 0x0095                                           // You have a new friend some- / where on the first floor / of
#define TEXT_SYSTEM_AFLOWER_HAS_BLOOMED_ON 0x0096                                // A flower has bloomed on the / Resistance Base roof.
#define TEXT_SYSTEM_THE_DESIGN_OF_ANIMAL_ELVES 0x0097                            // The design of Animal elves / has changed.
#define TEXT_SYSTEM_ANDREW_LOOKS_YOUNGER_NOW 0x0098                              // Andrew looks younger now.
#define TEXT_SYSTEM_MOD_CARD_38 0x0099                                           // Attack of Animal elves / Archim and Archil have / increased
#define TEXT_SYSTEM_SEAGULLS_NOW_FLY_IN_THE 0x009A                               // Seagulls now fly in the sky / above the Resistance Base.
#define TEXT_SYSTEM_MOD_CARD_41 0x009B                                           // Attack of Animal elves / Beetack and Beenipe have / increase
#define TEXT_SYSTEM_THE_DESIGN_OF_SECRET_DISKS 0x009C                            // The design of Secret Disks / has changed.
#define TEXT_SYSTEM_MOD_CARD_43 0x009D                                           // Attack of S.Boomerang / has increased by 2.
#define TEXT_SYSTEM_SOMEBODY_HAS_DRAWN_GRAFFITI 0x009E                           // Somebody has drawn graffiti / on the Resistance Base / wall.
#define TEXT_SYSTEM_MOD_CARD_48 0x009F                                           // Attack of Recoil Rod has / increased by 2.
#define TEXT_SYSTEM_MOD_CARD_52 0x00A0                                           // The conversation with the / Resistance fighter in the / watc
#define TEXT_SYSTEM_MOD_CARD_60 0x00A1                                           // Attack of S.Boomerang / has increased by 3.
#define TEXT_SYSTEM_MOD_CARD_61 0x00A2                                           // The conversation with the / Resistance fighter in the / watc
#define TEXT_SYSTEM_MOD_CARD_64 0x00A3                                           // Attack of Animal elves / Beetack and Beenipe have / increase
#define TEXT_SYSTEM_MOD_CARD_65 0x00A4                                           // Attack of Animal elves / Archim and Archil have / increased
#define TEXT_SYSTEM_THE_DESIGN_OF_HACKER_ELVES 0x00A5                            // The design of Hacker elves / has changed.
#define TEXT_SYSTEM_ENERGY_OF_CROSSBYNE_HAS 0x00A6                               // Energy of Crossbyne has / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_PBASE 0x00A7                                       // Energy of P. Base / has increased by 4.
#define TEXT_SYSTEM_MOD_CARD_69 0x00A8                                           // The Attack of BusterShots / has increased by 3.
#define TEXT_SYSTEM_IT_IS_NOW_NIGHTTIME_AT 0x00A9                                // It is now nighttime at the / Resistance Base.
#define TEXT_SYSTEM_ENERGY_OF_PAQUA 0x00AA                                       // Energy of P. Aqua / has increased by 4.
#define TEXT_SYSTEM_FISH_NOW_JUMP_AROUND_THE 0x00AB                              // Fish now jump around the / Resistance Base harbor.
#define TEXT_SYSTEM_MOD_CARD_78 0x00AC                                           // Attack of Recoil Rod has / increased by 3.
#define TEXT_SYSTEM_MOD_CARD_79 0x00AD                                           // You have a new friend some- / where on the third floor / of
#define TEXT_SYSTEM_MOD_CARD_81 0x00AE                                           // Attack of Animal elves / Archim and Archil have / increased
#define TEXT_SYSTEM_MOD_CARD_82 0x00AF                                           // Attack of Z Saber increased / by 2.
#define TEXT_SYSTEM_ENERGY_OF_PBOMBER 0x00B0                                     // Energy of P. Bomber / has increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_ALTERED_P 0x00B1                                   // Energy of altered P. / Aqua has increased by / 16.
#define TEXT_SYSTEM_MOD_CARD_90 0x00B2                                           // Attack of Z Saber increased / by 3.
#define TEXT_SYSTEM_ENERGY_OF_PURPLENERPLE 0x00B3                                // Energy of PurpleNerple / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SHELLCRAWLER 0x00B4                                // Energy of Shellcrawler / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_ICEBON_INCREASED 0x00B5                            // Energy of Icebon increased / by 4.
#define TEXT_SYSTEM_ENERGY_OF_GCANNON 0x00B6                                     // Energy of G. Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_CLAVEKER 0x00B7                                    // Energy of Claveker / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SHOTCOUNTER 0x00B8                                 // Energy of Shotcounter / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_GRAND_CANNON 0x00B9                                // Energy of Grand Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SHRIMPOLIN 0x00BA                                  // Energy of Shrimpolin / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_BATRING 0x00BB                                     // Energy of Batring / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_PCANNON 0x00BC                                     // Energy of P. Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_VOLCAIRE 0x00BD                                    // Energy of Volcaire / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SNAKECORD 0x00BE                                   // Energy of Snakecord / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_LEMMINGLES 0x00BF                                  // Energy of Lemmingles / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_LAMPLORT 0x00C0                                    // Energy of Lamplort / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_TILE_CANNON 0x00C1                                 // Energy of Tile Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SHELLUNO 0x00C2                                    // Energy of Shelluno / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_HEAVY_CANNON 0x00C3                                // Energy of Heavy Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_MOTHJIRO 0x00C4                                    // Energy of Mothjiro / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_CCANNON 0x00C5                                     // Energy of C. Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_CALIBEE_G 0x00C6                                   // Energy of Calibee G / increased by 16.
#define TEXT_SYSTEM_ENERGY_OF_DEATHLOCK 0x00C7                                   // Energy of Deathlock / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_GYRO_CANNON 0x00C8                                 // Energy of Gyro Cannon / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_SHARKSHIEL_X 0x00C9                                // Energy of Sharkshiel X / increased by 4.
#define TEXT_SYSTEM_ENERGY_OF_OLWARMER 0x00CA                                    // Energy of Olwarmer / increased by 16.
#define TEXT_SYSTEM_ENERGY_OF_BRANWARMER 0x00CB                                  // Energy of Branwarmer / increased by 16.
#define TEXT_SYSTEM_ENERGY_OF_LOCOMO_IF 0x00CC                                   // Energy of Locomo IF / increased by 16.
#define TEXT_SYSTEM_ENERGY_OF_BEESERVER 0x00CD                                   // Energy of Beeserver / increased by 16.
#define TEXT_SYSTEM_ENERGY_OF_MEGAMILPA 0x00CE                                   // Energy of Megamilpa / increased by 16.
#define TEXT_SYSTEM_ZERO_SMINI_GAME_ALIAS3 0x00D2                                // Zero's mini game / added!
#define TEXT_SYSTEM_CIEL_SMINI_GAME 0x00D3                                       // Ciel's mini game / added!
#define TEXT_SYSTEM_COPY_XSMINI_GAME 0x00D4                                      // Copy X's mini game / added!
#define TEXT_SYSTEM_HARPUIA_SMINI_GAME 0x00D5                                    // Harpuia's mini game / added!
#define TEXT_SYSTEM_FEFNIR_SMINI_GAME 0x00D6                                     // Fefnir's mini game / added!
#define TEXT_SYSTEM_LEVIATHAN_SMINI_GAME 0x00D7                                  // Leviathan's mini game / added!
#define TEXT_SYSTEM_PHANTOM_SMINI_GAME 0x00D8                                    // Phantom's mini game / added!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SECRET_DISK 0x0100                     // You got the / Secret Disk!
#define TEXT_OPEN_SECRET_DISK_YOU_CAPTURED_THE_EX_SKILLOF_ALIAS6 0x010A          // You captured the EX skill / of Deathtanz Mantisk! / You got
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_3 0x010B                           // You captured the EX skill / of Childre Inarabitta! / You got
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_2 0x010C                           // You captured the EX skill / of Blazin' Flizard! / You got th
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_4 0x010D                           // You captured the EX skill / of Devilbat Schilt! / You got th
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_9 0x010E                           // You captured the EX skill / of Blizzack Staggroff R! / You g
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_8 0x010F                           // You captured the EX skill / of Hanumachine R! / You got the
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_12 0x0110                          // You captured the EX skill / of Glacier Le Cactank! / You got
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_10 0x0111                          // You captured the EX skill / of Copy X Mark II! / You got the
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_14 0x0112                          // You captured the EX skill / of Tretista Kelverian! / You got
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_7 0x0113                           // You captured the EX skill / of Anubis Necromancess V! / You
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_11 0x0114                          // You captured the EX skill / of Cubit Foxtar! / You got the S
#define TEXT_OPEN_SECRET_DISK_UNLOCK_EX_SKILL_13 0x0115                          // You captured the EX skill / of Volteel Biblio! / You got the
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_LIGHTBODY_CHIP 0x0116                  // You got the Light / Body Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_ICEBODY_CHIP 0x0117                    // You got the Ice / Body Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_FLAMEBODY_CHIP 0x0118                  // You got the Flame / Body Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_THUNDERBODY_CHIP 0x0119                // You got the Thunder / Body Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_ABSORBERBODY_CHIP 0x011A               // You got the Absorber / Body Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SHADOW_DASHFOOT 0x011B                 // You got the Shadow Dash / Foot Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_DOUBLE_JUMPFOOT 0x011C                 // You got the Double Jump / Foot Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SPIKEFOOT_CHIP 0x011D                  // You got the Spike / Foot Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_QUICKFOOT_CHIP 0x011E                  // You got the Quick / Foot Chip!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_RECOIL_ROD 0x011F                      // You got the Recoil Rod!
#define TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SBOOMERANG 0x0120                      // You got the S.Boomerang!
#define TEXT_SPACE_CRAFT_IT_SURE_IS_QUIET_THERE 0x0300                           // It sure is quiet... / There haven't been / many Neo Arcadian
#define TEXT_SPACE_CRAFT_THE_READING_IS 0x0301                                   // The reading is / getting stronger. / We're close...
#define TEXT_SPACE_CRAFT_THE_SNOW_IS_LETTING 0x0302                              // The snow is letting / up...
#define TEXT_SPACE_CRAFT_WWOW_LOOK_AT_THAT 0x0303                                // W-wow! / Look at that!
#define TEXT_SPACE_CRAFT_IS_THAT_SOME_KIND 0x0304                                // Is that...some kind / of ship?
#define TEXT_SPACE_CRAFT_MS_CIEL_DID_THAT_HUGE 0x0305                            // Ms. Ciel... / Did that...huge / thing...fall from / outer sp
#define TEXT_SPACE_CRAFT_NEO_ARCADIA_HAS_THE 0x0306                              // Neo Arcadia has the / area ahead of us / cordoned off. / Wha
#define TEXT_SPACE_CRAFT_UP_AHEAD_THAT_SWHERE 0x0307                             // Up ahead... / That's where the / Dark Elf reading is / comin
#define TEXT_SPACE_CRAFT_SHE_KNEW_WHO_I 0x0308                                   // She knew who I / was... / Why would the elf / who almost des
#define TEXT_SPACE_CRAFT_CIEL_ZERO_ARE_YOU_THERE 0x0309                          // Ciel: Zero? Are you there?
#define TEXT_SPACE_CRAFT_MAINTAIN_RADIO 0x030A                                   // Maintain radio / silence! / The enemy is near...
#define TEXT_SPACE_CRAFT_OH_IIMSORRY 0x030B                                      // Oh, I-I'm sorry...
#define TEXT_SPACE_CRAFT_GET_DOWN 0x030C                                         // Get down!
#define TEXT_SPACE_CRAFT_NEO_ARCADIANS_MS_CIEL_LOOK_ALIAS1 0x030E                // Neo Arcadians! / Ms. Ciel, look out!
#define TEXT_SPACE_CRAFT_NO 0x030F                                               // No!
#define TEXT_SPACE_CRAFT_RELAX 0x0310                                            // Relax. / They won't come to / any harm. / Harpuia?! / I'm le
#define TEXT_SPACE_CRAFT_SCRAM_IDON_THAVE 0x0311                                 // Scram! / I don't have time to / mess with you now!
#define TEXT_SPACE_CRAFT_EMPTY 0x0312                                            // ...
#define TEXT_SPACE_CRAFT_CIEL_ZERO_CAN_YOU_HEAR 0x0313                           // Ciel: Zero... / Can you hear me?
#define TEXT_SPACE_CRAFT_SEEMS_YOU_RE_OKAY_LEAVE 0x0314                          // Seems you're okay... / Leave the rest of / this up to me. /
#define TEXT_SPACE_CRAFT_CIEL_BUT_ZERO 0x0315                                    // Ciel: But, Zero...
#define TEXT_SPACE_CRAFT_IVE_HEARD_THAT 0x0316                                   // I've heard that / voice somewhere / before...
#define TEXT_SPACE_CRAFT_IS_IT_CALLING_ME 0x0317                                 // Is it...calling me?
#define TEXT_SPACE_CRAFT_NOW_YOU_RE_ASKIN 0x0319                                 // Now you're askin' / for it!
#define TEXT_SPACE_CRAFT_ILL_BLAST_YOU_TO 0x031A                                 // I'll blast you to / pieces!
#define TEXT_SPACE_CRAFT_OOPH 0x031B                                             // Ooph!
#define TEXT_SPACE_CRAFT_PANT_PANT_ARE_YOU_ALIVE 0x031C                          // *pant pant* / Are you alive, / Fefnir? / What a monster... /
#define TEXT_SPACE_CRAFT_ZERO_WHAT_THE_HECK_ARE 0x031D                           // Zero?! / What the heck are / YOU doing here?! / What is that
#define TEXT_SPACE_CRAFT_THAT_SOMEGA 0x031E                                      // That's Omega. / His mere existence / defies reality... / He'
#define TEXT_SPACE_CRAFT_BAH_THAT 0x031F                                         // Bah, that / Leviathan... / Grr, I can't move! / We'll have t
#define TEXT_SPACE_CRAFT_OMEGA_HUH_SO_YOU_WERE 0x0320                            // Omega, huh? / So you were the one / who called me here?
#define TEXT_SPACE_CRAFT_GRRR 0x0321                                             // Grrr...
#define TEXT_SPACE_CRAFT_YOU_JUST_DON_TGIVE 0x0322                               // You just don't give / up, do you...
#define TEXT_SPACE_CRAFT_SO_YOU_RE_OMEGA_I 0x0323                                // So you're Omega. / I'm afraid I can't / let you leave this /
#define TEXT_SPACE_CRAFT_GAAARRRRWL 0x0324                                       // Gaaarrrrwl!
#define TEXT_SPACE_CRAFT_HEHEHEHE_OMEGA_THAT_WILL_BE 0x0325                      // Hehehehe... / Omega, that will be / quite enough.
#define TEXT_SPACE_CRAFT_FROM_THIS_DAY 0x0326                                    // From this day / forward... / You will fight with / this pers
#define TEXT_SPACE_CRAFT_GAARWL 0x0327                                           // Gaarwl... / Lord...Weil... / A Neo Arcadian?! / Who is this
#define TEXT_SPACE_CRAFT_HEHEHEHE_IAM_WEIL_YOU 0x0328                            // Hehehehe... / I am Weil. You may / call me Dr. Weil. / You m
#define TEXT_SPACE_CRAFT_MMASTER_X 0x0329                                        // M...Master X?! / Is that you?!
#define TEXT_SPACE_CRAFT_HARPUIA_HEHE_YOU 0x032A                                 // Harpuia! Hehe, you / haven't ch-changed! / And th-then / the
#define TEXT_SPACE_CRAFT_YOU_MUST_BE 0x032B                                      // You must be... / You're a copy, / aren't you? / Hehehe! / I
#define TEXT_SPACE_CRAFT_BUT_MASTER_XTHINK 0x032C                                // But Master X! Think / how many humans died / because of the
#define TEXT_SPACE_CRAFT_WEIL_YOU_SO_ZERO_YOU 0x032D                             // Weil...you... / So, Zero. / You g-guys are / also searching
#define TEXT_SPACE_CRAFT_HEHEHE_NOW_THINGS 0x032E                                // Hehehe... Now things / are getting / interesting, Zero! / Le
#define TEXT_SPACE_CRAFT_WITH_THAT_BODY 0x032F                                   // "With that body"...? / ...
#define TEXT_SPACE_CRAFT_CIEL_ZERO_THIS_IS_TERRIBLE 0x0330                       // Ciel: Zero... / This is terrible...
#define TEXT_SPACE_CRAFT_SO_YOU_WERE 0x0331                                      // So you were / monitoring the whole / thing?
#define TEXT_SPACE_CRAFT_CIEL_HURRY_BACK_TO_BASE 0x0332                          // Ciel: Hurry back to base. / Operator? / Operator: Commencing
#define TEXT_VOLCANO_STRONG_ENERGY_READING 0x0400                                // Operator: / A strong energy / reading detected. / They are b
#define TEXT_VOLCANO_IALMOST_GAVE_UP_ON_2 0x0402                                 // I almost gave up on / finding a foe worthy / of fighting me.
#define TEXT_VOLCANO_SSYAAAAAH_GET_READY_FOR 0x0403                              // Ssyaaaaah! / Get ready for / Blazin' Flizard, one / of Weil'
#define TEXT_VOLCANO_WHAT_IS_THAT_ALL 0x0404                                     // What, is that all / you got? / How...tepid. And I / was hopi
#define TEXT_VOLCANO_WHO_ARE_YOU_TO_PUT 0x0405                                   // Who are you to...put / out my flames? / Lord Weil will get /
#define TEXT_OCEAN_HIGHWAY_RUINS_GOT_AREADING 0x0500                             // Ciel: / Zero! We've just / got a reading! / Dark Elf detecte
#define TEXT_OCEAN_HIGHWAY_RUINS_WHO_THE_HECK_RE_YOU_2_ALIAS1 0x0503             // Who the heck're you? / Heh, you must be / after that Dark El
#define TEXT_OCEAN_HIGHWAY_RUINS_CIEL_CAN_YOU_HEAR_ME 0x0504                     // Ciel: Can you hear me, / Zero?! There's a switch / up ahead
#define TEXT_OCEAN_HIGHWAY_RUINS_WHO_THE_HECK_RE_YOU_2_ALIAS4 0x0508             // Zeeeeeeerrooooo / Dark Elf!
#define TEXT_OCEAN_HIGHWAY_RUINS_STOOOOOOP_IIIIIIT 0x0509                        // Stoooooop iiiiiit!
#define TEXT_OCEAN_HIGHWAY_RUINS_EMPTY 0x050A                                    // !!!
#define TEXT_OCEAN_HIGHWAY_RUINS_ILL_HAVE_TO_TAKE 0x050B                         // I'll have to take / care of this guy / first...
#define TEXT_OCEAN_HIGHWAY_RUINS_WHAT_APAIN_YOU_ARE 0x050C                       // What a pain you are! / I thought you'd be / easier to scare
#define TEXT_OCEAN_HIGHWAY_RUINS_YOU_RE_SHARK_FOOD 0x050D                        // You're shark food, / now! / Now, time to go / after that Dar
#define TEXT_OCEAN_HIGHWAY_RUINS_YOU_RE_KIDDING_ME_WHY 0x050E                    // You're kidding me... / Why is this... / happening...to me?!
#define TEXT_WEAPON_REPAIR_FACTORY_FACTORY_CONTROL_UNIT 0x0600                   // Operator: / Ahead is the factory / control unit. / Data from
#define TEXT_WEAPON_REPAIR_FACTORY_WELL_IF_IT_ISN_T_ALIAS1 0x0602                // Well, if it isn't / the legendary hero. / The Mechaniloids /
#define TEXT_WEAPON_REPAIR_FACTORY_KEKEKE_THE_FIRST_LESSON_A 0x0603              // Kekeke! / The first lesson a / gentleman must learn / in ref
#define TEXT_WEAPON_REPAIR_FACTORY_KEKE_THE_BLOOD_OF_A 0x0604                    // Keke! / The blood of a / century-old hero has / such a lovel
#define TEXT_WEAPON_REPAIR_FACTORY_KE_KEKE_NO_MANNERS 0x0605                     // Ke...keke! / No manners... / No manners at all! / Trying to
#define TEXT_OLD_LIFE_SPACE_BURN_AWAY_THE_IVY 0x0700                             // Operator: / Mr. Zero! / You can burn away / the ivy with Fla
#define TEXT_OLD_LIFE_SPACE_ICAN_CUT_ANYTHING 0x0701                             // I can cut anything / with my beautiful / scythe! / Chikachik
#define TEXT_OLD_LIFE_SPACE_CHIKACHIKA_EVEN_IF_YOU_DEFEAT 0x0702                 // Chikachika... / Even if you defeat / me here... / My associa
#define TEXT_OLD_LIFE_SPACE_MAAAMA_ALIAS1 0x0704                                 // Maaama. / Maaama.
#define TEXT_OLD_LIFE_SPACE_HEY_PREA 0x0705                                      // Hey, Prea. / Mama's not here.
#define TEXT_OLD_LIFE_SPACE_THAT_SRIGHT_CREA 0x0706                              // That's right, Crea. / Mama's not here.
#define TEXT_OLD_LIFE_SPACE_HEY_PREA_2 0x0707                                    // Hey, Prea. / Let's look a little / farther inside.
#define TEXT_OLD_LIFE_SPACE_THAT_SRIGHT_CREA_2 0x0708                            // That's right, Crea. / Let's look a little / farther inside.
#define TEXT_OLD_LIFE_SPACE_THOSE_MUST_BE 0x0709                                 // ... / Those must be...
#define TEXT_OLD_LIFE_SPACE_CIEL_ZERO_IVE_PICKEDUP 0x070A                        // Ciel: Zero! I've picked / up some Baby Elf readings / on tha
#define TEXT_OLD_LIFE_SPACE_THEIR_MOTHER_THEY_MUST_BE 0x070B                     // Their mother... / They must be looking / for the Dark Elf.
#define TEXT_OLD_LIFE_SPACE_CIEL_HEY_ZERO_CAN_YOUPROTECT 0x070C                  // Ciel: Hey Zero, can you / protect those babies?
#define TEXT_OLD_LIFE_SPACE_ALRIGHT_ILL_FIND_THEM 0x070D                         // Alright. / I'll find them.
#define TEXT_OLD_LIFE_SPACE_CIEL_THANK_YOU_ZERO 0x070E                           // Ciel: Thank you, Zero...
#define TEXT_OLD_LIFE_SPACE_WHO_ARE_YOU_YOU_SMELL 0x070F                         // Who are you? / You smell like Mama.
#define TEXT_OLD_LIFE_SPACE_WHO_ARE_YOU_YOU_SMELL_2 0x0710                       // Who are you? / You smell like us.
#define TEXT_OLD_LIFE_SPACE_CHIKACHIKA_SO_THESE_ARE_BABY 0x0711                  // Chikachika... / So these are Baby / Elves? / Lord Weil order
#define TEXT_OLD_LIFE_SPACE_HAND_OVER_THE 0x0712                                 // Hand over the / Baby Elves.
#define TEXT_OLD_LIFE_SPACE_OH_IKNOW_HIM_HE 0x0713                               // Oh, I know him! / He pushed Mama / around!
#define TEXT_OLD_LIFE_SPACE_IKNOW_HIM_TOO_THAT 0x0714                            // I know him, too! / That's the guy who / pushed Mama around /
#define TEXT_OLD_LIFE_SPACE_YOU_FAKER 0x0715                                     // You faker!
#define TEXT_OLD_LIFE_SPACE_YOU_FAKER_2 0x0716                                   // You faker!
#define TEXT_OLD_LIFE_SPACE_HMM_CHIKACHIKA 0x0717                                // Hmm? / Chikachika... / Shut up, you Baby / Elves! / If you d
#define TEXT_OLD_LIFE_SPACE_WAAAAAAH 0x0718                                      // Waaaaaah!
#define TEXT_OLD_LIFE_SPACE_WAAAAAAH_2 0x0719                                    // Waaaaaah!
#define TEXT_OLD_LIFE_SPACE_THOSE_TWO_BELONG 0x071A                              // Those two belong / to Lord Weil. You / can't have them.
#define TEXT_OLD_LIFE_SPACE_IMDEATHTANZ 0x071B                                   // I'm Deathtanz / Mantisk, one of / Weil's Numbers. / Now, tim
#define TEXT_OLD_LIFE_SPACE_WHO_ARE_YOU_MISTER_I 0x071C                          // Who are you, mister? / I've seen you / somewhere before.
#define TEXT_OLD_LIFE_SPACE_WHO_ARE_YOU_MISTER_I_2 0x071D                        // Who are you, mister? / I've seen him / somewhere before, / t
#define TEXT_OLD_LIFE_SPACE_HEHEHEHEHEEE 0x071E                                  // Heheheheheee... / My name is Weil. / I'm the one who / made
#define TEXT_OLD_LIFE_SPACE_PREA_DID_YOU_HEAR 0x071F                             // Prea, did you hear / that? / He's our Grandpa!
#define TEXT_OLD_LIFE_SPACE_IHEARD_CREA_HE_S 0x0720                              // I heard, Crea! / He's our Grandpa!
#define TEXT_OLD_LIFE_SPACE_IMLOOKING_FOR_THE 0x0721                             // I'm looking for the / Dark Elf, too. / I need your help. / Y
#define TEXT_OLD_LIFE_SPACE_OKAY_LET_SGO 0x0722                                  // Okay! Let's go, / Prea!
#define TEXT_OLD_LIFE_SPACE_OKAY_LET_SGO_2 0x0723                                // Okay! Let's go, / Crea!
#define TEXT_OLD_LIFE_SPACE_WAIT 0x0724                                          // Wait!
#define TEXT_OLD_LIFE_SPACE_DARN_CIEL_CAN_YOU_FOLLOW 0x0725                      // Darn... / Ciel, can you follow / their readings?
#define TEXT_OLD_LIFE_SPACE_CIEL_IMSORRY_ZERO 0x0726                             // Ciel: I'm sorry, Zero. / That won't be possible / with your
#define TEXT_OLD_LIFE_SPACE_EMPTY 0x0727                                         // ...
#define TEXT_OLD_LIFE_SPACE_OPERATOR_MR_ZERO_PLEASE_RETURN 0x0728                // Operator: Mr. Zero, / please return to base. / Commencing tr
#define TEXT_MISSILE_FACTORY_YOU_MADE_IT 0x0800                                  // Ciel: / You made it! / What a relief! / Have you determined
#define TEXT_MISSILE_FACTORY_NO 0x0801                                           // No!
#define TEXT_MISSILE_FACTORY_CIEL_THEY_LAUNCHED_IT_ZERO 0x0802                   // Ciel: They launched it! / Zero! Don't get any / closer!
#define TEXT_MISSILE_FACTORY_IHAVE_TO_ACT_NOW 0x0803                             // I have to act now, / while Omega is / immobile... / I'll sne
#define TEXT_MISSILE_FACTORY_CIEL_ZERO 0x0804                                    // Ciel: Zero!!!
#define TEXT_MISSILE_FACTORY_BABY_ELVES 0x0805                                   // Baby Elves?!
#define TEXT_MISSILE_FACTORY_HE_CAME 0x0806                                      // He came! / The bad Reploid!
#define TEXT_MISSILE_FACTORY_HE_CAME_2 0x0807                                    // He came! / The nasty Reploid!
#define TEXT_MISSILE_FACTORY_OMEGA_WILL_GO 0x0808                                // Omega will go / rescue Mama! / Don't get in his / way! Leave
#define TEXT_MISSILE_FACTORY_WE_LL_PROTECT_HIM 0x0809                            // We'll protect him / from you! / Don't get in his / way! Leav
#define TEXT_MISSILE_FACTORY_HEHE_GRANDPA_WILL 0x080A                            // Hehe! Grandpa will / be so proud of us! / Haha! Grandpa will
#define TEXT_MISSILE_FACTORY_WAAAAAH 0x080B                                      // Waaaaah! / You horrible thing!
#define TEXT_MISSILE_FACTORY_OWWWWWW 0x080C                                      // Owwwwww! / That hurt!
#define TEXT_MISSILE_FACTORY_WE_MAY_HAVE_LOST 0x080D                             // We may have lost, / but the missile will / land soon! / Our
#define TEXT_MISSILE_FACTORY_WE_MAY_HAVE_LOST_2 0x080E                           // We may have lost, / but we'll see our / Mama soon! / Our mis
#define TEXT_MISSILE_FACTORY_GRRAWRRR 0x080F                                     // Grrawrrr!
#define TEXT_MISSILE_FACTORY_YAY 0x0810                                          // Yay! / Maaama! Maaama!
#define TEXT_MISSILE_FACTORY_YAY_2 0x0811                                        // Yay! / Maaama! Maaama!
#define TEXT_MISSILE_FACTORY_GRRARRAARRRR 0x0812                                 // Grrarraarrrr!
#define TEXT_MISSILE_FACTORY_GRRARRAARRRR_2 0x0813                               // Grrarraarrrr!
#define TEXT_MISSILE_FACTORY_HEY_CAN_YOU_BEAT_UP 0x0814                          // Hey, can you beat up / that bad Reploid for / us?
#define TEXT_MISSILE_FACTORY_YEAH_CAN_YOU_BEAT 0x0815                            // Yeah, can you beat / up that fake Reploid / for us?
#define TEXT_MISSILE_FACTORY_WE_THE_REPLOIDS_OF 0x0816                           // ... / We, the Reploids of / Neo Arcadia... / We are defender
#define TEXT_MISSILE_FACTORY_ARRRRGGH_IIAM 0x0817                                // Arrrrggh! / I... I am...
#define TEXT_MISSILE_FACTORY_HARPUIA 0x0818                                      // Harpuia!
#define TEXT_MISSILE_FACTORY_PERFECT 0x0819                                      // Perfect!
#define TEXT_MISSILE_FACTORY_GET_HIM_GET_HIM 0x081A                              // Get him! Get him!
#define TEXT_MISSILE_FACTORY_CIEL_ZERO_DON_TMOVE 0x081B                          // Ciel: Zero, don't move! / I'll transfer you to the / base, n
#define TEXT_MISSILE_FACTORY_OPERATOR_TRANSFERRING 0x081C                        // Operator: Transferring!
#define TEXT_TWILIGHT_DESERT_IHAVE_BEEN_SUMMONED 0x0900                          // I have been summoned / by Lord Weil back / from the netherwo
#define TEXT_TWILIGHT_DESERT_THERE_IS_NO_ETERNITY 0x0901                         // There is no eternity / in this world. / Even your life must
#define TEXT_TWILIGHT_DESERT_YOU_OF_THE_ANCIENT 0x0902                           // You, of the ancient / soul. / You have no place in / the new
#define TEXT_ANATRE_FOREST_MY_BODY_HAS_RETURNED 0x0A00                           // My body has returned / from decay... / For Lord Weil, who /
#define TEXT_ANATRE_FOREST_JUSTICE_IS_ON_THE 0x0A01                              // Justice is on the / side of the Neo / Arcadians!
#define TEXT_ANATRE_FOREST_AN_IMPRESSIVE_FIGHT 0x0A02                            // An impressive fight! / However... / Evil must fail in / the
#define TEXT_ICE_BASE_HMPH_IAM_IMPRESSED 0x0B00                                  // Hmph. I am impressed / you made it to this / base. / Still..
#define TEXT_ICE_BASE_HMPH_ACENTURY_IS_NOT 0x0B01                                // Hmph. / A century is not / enough. This time, / sleep foreve
#define TEXT_ICE_BASE_GROAN 0x0B02                                               // *groan* / Forgive me... / Lord Weil... / Hm...phahh!
#define TEXT_AREA_X2_SO_YOU_VE_COME 0x0C01                                       // So you've come, / Zero. / D-do you know what / you are doing
#define TEXT_AREA_X2_AHA_AHAHAHAH_DID_YOU_S 0x0C02                               // Aha! Ahahahah! / Did you s-see that?! / I am the true hero!
#define TEXT_AREA_X2_NNO_WH_WHY_WHY 0x0C03                                       // N-no! Wh-why-why?! / I'm a hero! I / f-fight for justice! /
#define TEXT_AREA_X2_HE_IS_NO_LONGER_HERE 0x0C04                                 // He is... / ...no longer here.
#define TEXT_AREA_X2_WHO_AARE_YOU_X 0x0C05                                       // Who a-are you?! / X! / X?! / Y-you are my / original form?!
#define TEXT_AREA_X2_HAAAAAH_OH_NO_WEIL_HAS 0x0C06                               // Haaaaah!!! / Oh no! / Weil has placed a / trap on your body!
#define TEXT_AREA_X2_GEE_GAGAGA_ICAN_T 0x0C07                                    // Gee...gagaga?! / I...can't... / can't move... / Gagagaaa...
#define TEXT_AREA_X2_WEIL_KNEW_FROM_THE 0x0C08                                   // ?! / Weil knew from the / start how things / would turn out,
#define TEXT_AREA_X2_HEAR_ME_CITIZENS_OF 0x0C09                                  // Hear me, citizens of / the great land of / Neo Arcadia... /
#define TEXT_AREA_X2_DR_WEIL 0x0C0A                                              // Dr. Weil...
#define TEXT_AREA_X2_JUST_NOW_OUR_HERO_MASTER 0x0C0B                             // Just now... / Our hero Master X / was taken by blood- / thir
#define TEXT_AREA_X2_THANK_YOU_ALL_I 0x0C0C                                      // ... / Thank you all. I / have just confirmed / your approval
#define TEXT_AREA_X2_IT_SALL_GOING 0x0C0D                                        // ... / It's all going / according to his / plans. / Dr. Weil.
#define TEXT_AREA_X2_WHAT_IS_IT_WELL_NEVER 0x0C0E                                // What is it? / Well...never mind. / I'll bring it up / again
#define TEXT_AREA_X2_THE_HEART 0x0C0F                                            // The heart? / ...
#define TEXT_ENERGY_FACTORY_FACILITY_CORE 0x0D00                                 // Operator: / The facility's core / has not yet been / activat
#define TEXT_ENERGY_FACTORY_WHAT_STHIS 0x0D01                                    // What's this?
#define TEXT_ENERGY_FACTORY_TEEHEEHEE_HEY_YOU_WEREN_T 0x0D02                     // Teeheehee... / Hey! You weren't / supposed to see / this pla
#define TEXT_ENERGY_FACTORY_IAM_CUBIT_FOXTAR 0x0D03                              // I am Cubit Foxtar, / member of Weil's / Numbers! / I'll make
#define TEXT_ENERGY_FACTORY_TEEHEE_THAT_SIT 0x0D04                               // Teehee! That's it! / See what happens / to nosy people! / Re
#define TEXT_ENERGY_FACTORY_IF_IAM_DEFEATED 0x0D05                               // If I am defeated, / this room will cease / functioning, / an
#define TEXT_SNOWY_PLAINS_AH_MR_ZERO_THE_ENEMY 0x0E00                            // Ah, Mr. Zero! / The enemy is / waiting in ambush up / ahead.
#define TEXT_SNOWY_PLAINS_IS_THAT_IT 0x0E01                                      // Is that it?
#define TEXT_SNOWY_PLAINS_HAH_THAT_CONTAINER_WAS 0x0E02                          // Hah! / That container was / on Omega's ship. So / you see, i
#define TEXT_SNOWY_PLAINS_IGLACIER_LE 0x0E03                                     // I, Glacier Le / Cactank, of / Weil's Numbers, / have reached
#define TEXT_SNOWY_PLAINS_HAH_CONSIDER_YOUR_SINS 0x0E04                          // Hah! / Consider your sins / from deep beneath / the silent s
#define TEXT_SNOWY_PLAINS_OH_MY_NOT_STOPPING_AT 0x0E05                           // Oh...my... / Not stopping at / thievery, you also / defy Lor
#define TEXT_SNOWY_PLAINS_WE_VE_DISCOVERED 0x0E06                                // We've discovered / data inside the / container! / Mr. Zero!
#define TEXT_SNOWY_PLAINS_OPERATOR_MISSION_COMPLETED_COMMENCING_TRANSFER 0x0E07  // Operator: Mission completed. / Commencing transfer.
#define TEXT_SUNKEN_LIBRARY_GO_TO_DATA_ROOM 0x0F00                               // Operator: / First, please go to / the Data Room. / That room
#define TEXT_SUNKEN_LIBRARY_OPERATOR_2 0x0F01                                    // Operator: / This is the Data / Room. / Please search for / i
#define TEXT_SUNKEN_LIBRARY_FOUR_MATCHES_WEIL_OMEGA_DARK 0x0F03                  // Four matches... / Weil, Omega, Dark / Elf, Elf Wars...
#define TEXT_SUNKEN_LIBRARY_THREE_MORE_MATCHES 0x0F04                            // Three more matches.
#define TEXT_SUNKEN_LIBRARY_TWO_MORE_MATCHES 0x0F05                              // Two more matches.
#define TEXT_SUNKEN_LIBRARY_LAST_ONE 0x0F06                                      // Last one...
#define TEXT_SUNKEN_LIBRARY_AREA_WITH_WEIL_S 0x0F08                              // Area with Weil's / data found. / To search for more / inform
#define TEXT_SUNKEN_LIBRARY_AREA_WITH_OMEGA_S 0x0F09                             // Area with Omega's / data found. / To search for more / infor
#define TEXT_SUNKEN_LIBRARY_AREA_WITH_DARK_ELF_S 0x0F0A                          // Area with Dark Elf's / data found. / To search for more / in
#define TEXT_SUNKEN_LIBRARY_AREA_WITH_DATA 0x0F0B                                // Area with data / concerning the Elf / Wars found. / To searc
#define TEXT_SUNKEN_LIBRARY_WHO_DARES_INTRUDE 0x0F0C                             // Who dares intrude / upon my territory? / ...Ze-Zero! Heheh!
#define TEXT_SUNKEN_LIBRARY_IAM_VOLTEEL_BIBLIO 0x0F0D                            // I am Volteel Biblio, / of Weil's Numbers. / What is that you
#define TEXT_SUNKEN_LIBRARY_HEHEHEHEH_YOU_CAN_THAVE 0x0F0E                       // Heheheheh! / You can't have this / data! Nyah nyah / nyah ny
#define TEXT_SUNKEN_LIBRARY_WHAT_SUP_WITH_YOU 0x0F0F                             // What's up with you! / You're opposing / Lord Weil?! Aren't /
#define TEXT_SUNKEN_LIBRARY_YOU_GOT_WEIL_SDATA 0x0F11                            // You got Weil's data!
#define TEXT_SUNKEN_LIBRARY_YOU_GOT_OMEGA_SDATA 0x0F12                           // You got Omega's data!
#define TEXT_SUNKEN_LIBRARY_YOU_GOT_THE_DARK_ELF 0x0F13                          // You got the Dark Elf data!
#define TEXT_SUNKEN_LIBRARY_YOU_GOT_THE_ELF_WARS 0x0F14                          // You got the Elf Wars data!
#define TEXT_SUNKEN_LIBRARY_FILE650326 0x0F15                                    // File ↾650326 / == Dr. Weil == / From Neo Arcadia... / Creato
#define TEXT_SUNKEN_LIBRARY_U16_ARRAY_0834CE8C_0 0x0F16                          // If we can analyze / this data, we might / be able to find so
#define TEXT_SUNKEN_LIBRARY_FILE815156 0x0F17                                    // File ↾815156 / == Omega == / The ultimate / Reploid, created
#define TEXT_SUNKEN_LIBRARY_U16_ARRAY_0834CE8C_1 0x0F18                          // If we can analyze / this data, we might / be able to find ou
#define TEXT_SUNKEN_LIBRARY_FILE351848 0x0F19                                    // File ↾351848 / == Dark Elf == / Officially known as / the "M
#define TEXT_SUNKEN_LIBRARY_SO_THE_DARK_ELF 0x0F1A                               // So, the Dark Elf... / What's going on? / ... / If we can ana
#define TEXT_SUNKEN_LIBRARY_FILE945388 0x0F1B                                    // File ↾945388 / == Elf Wars == / .........end of the / ......
#define TEXT_SUNKEN_LIBRARY_CIEL_ZERO_IT_LOOKS_LIKETHAT 0x0F1C                   // Ciel: Zero? It looks like / that data is corrupt. I / think
#define TEXT_GIANT_ELEVATOR_GRRR_SO_YOU_RE 0x1001                                // Grrr... So you're / Zerrooo? / You're so tiny, I / almost st
#define TEXT_GIANT_ELEVATOR_WHAT_STHIS_AHH_I 0x1002                              // What's this? / Ahh, I must've / stepped on you. / You're so
#define TEXT_GIANT_ELEVATOR_HUH 0x1003                                           // Huh? / Zero... Where did / you go? I don't / see you... / An
#define TEXT_SUB_ARCADIA_DR_WEIL 0x1101                                          // Dr. Weil!
#define TEXT_SUB_ARCADIA_HEHEHEHEHEEE_HOW_GALLANT_YOU_ARE 0x1102                 // Heheheheheee... / How gallant you are, / Zero. To play hero,
#define TEXT_SUB_ARCADIA_CREA_PREA 0x1103                                        // Crea! Prea! / Do with this one as / you please! / I've got s
#define TEXT_SUB_ARCADIA_HE_SBACK 0x1104                                         // He's back! / The bad Reploid!
#define TEXT_SUB_ARCADIA_HE_SBACK_2 0x1105                                       // He's back! / The fake Reploid!
#define TEXT_SUB_ARCADIA_ILL_RIP_YOU_TO 0x1106                                   // I'll rip you to / pieces!
#define TEXT_SUB_ARCADIA_ILL_TEAR_YOU_TO 0x1107                                  // I'll tear you to / shreds!
#define TEXT_SUB_ARCADIA_AHAHAHAHAHAHAA 0x1108                                   // Ahahahahahahaa! / He's all ripped to / pieces! / Teheheheeeh
#define TEXT_SUB_ARCADIA_PREA_THERE_S 0x1109                                     // Prea, there's / something wrong...
#define TEXT_SUB_ARCADIA_YES_CREA_THERE_S 0x110A                                 // Yes Crea, there's / something wrong...
#define TEXT_SUB_ARCADIA_IFEEL_LIKE_IM 0x110B                                    // I feel like I'm / being stabbed with / pins and needles...
#define TEXT_SUB_ARCADIA_IFEEL_LIKE_IM_2 0x110C                                  // I feel like I'm / being smashed with / clubs and hammers...
#define TEXT_SUB_ARCADIA_CIEL_ZERO_ARE_YOU_ALLRIGHT 0x110D                       // Ciel: Zero, are you all / right? I just received / some new
#define TEXT_SUB_ARCADIA_UNDERSTOOD 0x110E                                       // Understood. / Transfer me.
#define TEXT_SUB_ARCADIA_INEVER_THOUGHT_I 0x110F                                 // I never thought I / would meet you again / in this world. /
#define TEXT_SUB_ARCADIA_ALL_LEGENDS_ARE 0x1110                                  // All legends are / forgotten in the / end. Goodbye, Zero!
#define TEXT_SUB_ARCADIA_GASP_YOU_TRULY_DID 0x1111                               // *gasp* / You truly did... / have the soul of a / hero... / G
#define TEXT_WEIL_LABO_YAAAAAH_ILOVE_LORD_WEIL 0x1201                            // Yaaaaah! / I love Lord Weil's / new world! So hot! / I won't
#define TEXT_WEIL_LABO_YAAAAAAAH_INSCRIBE_HIS_NAME 0x1202                        // Yaaaaaaah! / Inscribe his name / on the world! Our / ruler,
#define TEXT_WEIL_LABO_YAAH_HOT_SO_HOT_I 0x1203                                  // Yaah...hot...so hot! / I hope you writhe in / pain, alone in
#define TEXT_WEIL_LABO_YOU_DUNDERHEAD_LORD_WEIL_S 0x1204                         // You dunderhead! / Lord Weil's ideals / were set in motion a
#define TEXT_WEIL_LABO_YOU_SURE_ARE_SLOW 0x1205                                  // You sure are slow- / witted! / The times have past / you by!
#define TEXT_WEIL_LABO_OOPH_YOU_CAN_HURRY_AS 0x1206                              // *ooph!* / You can hurry as / fast as you want... / But you'l
#define TEXT_WEIL_LABO_YOU_SURE_ARE_A 0x1207                                     // You sure are a / boisterous lout. / Knock quietly next / tim
#define TEXT_WEIL_LABO_GO_BACK_HOME_BACK_TO 0x1208                               // Go back home. / Back to the depths, / where you slept all /
#define TEXT_WEIL_LABO_KEKEKE_YOU_SILLY 0x1209                                   // Kekeke... / You silly... / ...inconsiderate.. / barbarian! /
#define TEXT_WEIL_LABO_WHAT_STHE_USE_OF 0x120A                                   // What's the use of / century-old junk / in this new world? /
#define TEXT_WEIL_LABO_CHIKA_CHIKACHIKA_WATCH_AS_I 0x120B                        // Chika! Chikachika! / Watch as I slice / your old world and /
#define TEXT_WEIL_LABO_HOW_COULD_ITHE 0x120C                                     // How could I, the / newest and greatest, / lose to a century-
#define TEXT_WEIL_LABO_WHAT_ARE_YOU_DOING 0x120D                                 // What are you doing / in a place like / this, little boy? / I
#define TEXT_WEIL_LABO_GOOD_NIGHT_LITTLE 0x120E                                  // Good night, little / boy. / I don't expect / you'll wake aga
#define TEXT_WEIL_LABO_ARRGH 0x120F                                              // Arrgh... / No need to throw / a temper tantrum... / All your
#define TEXT_WEIL_LABO_HAH_FIRST_THIEVERY_AND 0x1210                             // Hah! / First thievery, and / now unlawful entry! / How outra
#define TEXT_WEIL_LABO_HAH_THOSE_WHO_DISRUPT 0x1211                              // Hah! / Those who disrupt / Lord Weil's world / must face my
#define TEXT_WEIL_LABO_WHAT_IS_THIS_YOU 0x1212                                   // What is this? You / dare to defy my / judgment?! / Lord Weil
#define TEXT_WEIL_LABO_HEHEHEHE_SO_YOU_RE_BACK 0x1213                            // Hehehehe! / So you're back! / Back again, ready to / be brok
#define TEXT_WEIL_LABO_HEHEHEHEHEHE_LOOK_AT_YOU 0x1214                           // Hehehehehehe! / Look at you! / You're broken now! / hehehe!
#define TEXT_WEIL_LABO_HEHE_HE 0x1215                                            // Hehe...he... / You broke me! / But you won't be / able to br
#define TEXT_WEIL_LABO_IAM_THE_GUARD_DOG 0x1216                                  // I am the guard dog / of Hades! / Lord Weil instructed / me n
#define TEXT_WEIL_LABO_GRRARWOOORRR_THERE_SNOT_ENOUGH 0x1217                     // Grrarwooorrr! / There's not enough / meat on your bones! / I
#define TEXT_WEIL_LABO_HHOW_DID_THIS 0x1218                                      // H-how did this / happen? Why can't I / bite you to chunks? /
#define TEXT_WEIL_LABO_HEHEHEHE_HAVING_FUN_PLAYING 0x1219                        // Hehehehe... / Having fun playing / the hero, Zero? / Hmmm? /
#define TEXT_WEIL_LABO_THAT_SRIGHT 0x121A                                        // That's right! / I'm a bona fide / human. / The creator of /
#define TEXT_WEIL_LABO_IBET_MOST_DECENT 0x121B                                   // I bet most decent / humans wouldn't / understand, either. /
#define TEXT_WEIL_LABO_OH_OH_HO_ZEEERROO_YOU 0x121C                              // Oh, oh ho, Zeeerroo! / You were a fun guy, / Zero! / I'd lik
#define TEXT_WEIL_LABO_GRRR_RARWRARR_HEHEHE 0x121D                               // Grrr... Rarwrarr! / Hehehe... / Not bad, Zero. / But Omega's
#define TEXT_WEIL_LABO_GRRRRRRRRRRRAAWRR 0x121E                                  // GrrrrrrRRRRRAAWRR!!!
#define TEXT_WEIL_LABO_WHAT_IS_THIS_PLACE 0x121F                                 // What is this place?
#define TEXT_WEIL_LABO_THIS_IS_WHERE_IWAS 0x1220                                 // This is where I was / sleeping...
#define TEXT_WEIL_LABO_HEHEHEHEHE 0x1221                                         // Hehehehehe! / Excellent, Zero! / Your power is extra- / ordi
#define TEXT_WEIL_LABO_HEHEHEHE_YOU_THOUGHT_YOU_WERE 0x1223                      // Hehehehe... / You thought you were / a hero all along, / did
#define TEXT_WEIL_LABO_YOU_PLAN_TO 0x1224                                        // You plan to... / reactivate Omega?
#define TEXT_WEIL_LABO_GULP_HEHEHE 0x1225                                        // *gulp!* / Hehehe... / Watch, but don't / interfere. / Don't
#define TEXT_WEIL_LABO_HURRY_STAND_UP 0x1226                                     // Zero! / What are you doing?! / Hurry, stand up!!!
#define TEXT_WEIL_LABO_HEY_IMHERE_TO 0x1227                                      // Hey! / I'm here to get a / little payback, / Omega!
#define TEXT_WEIL_LABO_TIME_TO_STRAIGHTEN 0x1228                                 // Time to straighten / the record!
#define TEXT_WEIL_LABO_YOU_GUYS_WEIL_IS_TRYING 0x1229                            // You guys! / Weil is trying to / bluff you... / He can't do a
#define TEXT_WEIL_LABO_ZEEEERROOOO_WHAT_IS_IT_DARK 0x122A                        // Zeeeerroooo! / What is it, Dark / Elf?!
#define TEXT_WEIL_LABO_HER_THE_DARK_ELF_S 0x122B                                 // Her... / The Dark Elf's / curse is fading... / Who's that! X
#define TEXT_WEIL_LABO_ZERO_DON_TDO_IT 0x122C                                    // Zero, don't do it!!! / That's your original / body! Don't yo
#define TEXT_WEIL_LABO_CAN_YOU_HEAR_ME 0x122E                                    // Can you hear me, / Zero? / My energy is almost / all spent.
#define TEXT_WEIL_LABO_ZERO_WAKE_UP 0x122F                                       // Zero, wake up!
#define TEXT_WEIL_LABO_ZERO_AH_WHAT_ARELIEF 0x1230                               // Zero! / Ah, what a relief! / I was so worried / about you...
#define TEXT_WEIL_LABO_HEY_EVERYONE_MR_ZERO_IS 0x1231                            // Hey! Everyone! / Mr. Zero is awake! / He's all right! / Yaho
#define TEXT_WEIL_LABO_WHERE_IS_THIS_THE 0x1232                                  // Where is this...the / Resistance Base? / Who could have...?
#define TEXT_WEIL_LABO_ZERRROOOO 0x1233                                          // Zerrroooo...
#define TEXT_WEIL_LABO_DARK_ELF_WAIT_NO_YOU 0x1234                               // Dark Elf? / Wait, no. You are... / She brought you back / he
#define TEXT_WEIL_LABO_SHOULDN_TWE_FOLLOW 0x1235                                 // Shouldn't we follow / her? / She's finally free. / There's s
#define TEXT_WEIL_LABO_XTOLD_ME_ABOUT_YOU 0x1236                                 // X told me about you, / Zero. / Really... / I know you're not
#define TEXT_WEIL_LABO_CIEL_THANK_YOU_ZE_ZERO 0x1237                             // Ciel... / Thank you. / Ze-Zero!
#define TEXT_WEIL_LABO_IT_SJUST_ME_I 0x1238                                      // It's just me... / I am... / ...Zero.
#define TEXT_OTHERS_MS_CIEL_PLEASE 0x1300                                        // Ms. Ciel, please / cheer up. / Everything's turned / out alr
#define TEXT_OTHERS_OH_ONE_MORE_THING 0x1308                                     // Oh, one more thing. / About Secret Disks. / Secret Disks con
#define TEXT_OTHERS_OPERATOR_MR_ZERO_PLEASE_COME 0x1309                          // Operator: Mr. Zero... / Please come to the / commander's roo
#define TEXT_OTHERS_HMM_ZERO_THEY_RE 0x130A                                      // Hmm? Zero, they're / asking for you.
#define TEXT_OTHERS_THIS_RECOIL_ROD 0x130B                                       // This Recoil Rod / looks easy to use. / Thanks.
#define TEXT_OTHERS_THE_WORLD_IS_TOO 0x130C                                      // The world is too / much for Ciel to / bear alone... / Take g
#define TEXT_OTHERS_YOU_HAVE_COMPLETED 0x1310                                    // You have completed / all the missions. / This next mission /
#define TEXT_OTHERS_WE_HAVE_TO_DO 0x1311                                         // We have to do / something about that / missile right now. /
#define TEXT_OTHERS_MASTER_XDO_YOU_STILL 0x1315                                  // Master X... / Do you still trust / that man...Weil? / His ba
#define TEXT_OTHERS_BUT_HEHEHE 0x1316                                            // But... / Hehehe... / Thank you, Master X.
#define TEXT_OTHERS_IDR_WEIL_SHALL 0x1317                                        // I, Dr. Weil, shall / never repeat my / past mistakes. / Neve
#define TEXT_OTHERS_STILL_TO_GOSSIP 0x1318                                       // Still, to gossip / about me behind my / back... / My, how th
#define TEXT_OTHERS_MASTER_XTHE_DARK_ELF 0x1319                                  // Master X. / The Dark Elf has / appeared in Neo / Arcadia. /
#define TEXT_OTHERS_WE_LL_GO_LEVIATHAN_AND 0x131A                                // We'll go. / Leviathan and / Fefnir are still / undergoing /
#define TEXT_OTHERS_HEHEHEHE 0x131B                                              // Hehehehe... / Yes sir! / I will capture the / Dark Elf, with
#define TEXT_OTHERS_PREPARATIONS_HAVE 0x131C                                     // Preparations have / begun for the launch / of the missile. /
#define TEXT_OTHERS_CIEL_ENTER_THE_COORDI 0x131D                                 // Ciel... / Enter the coordi- / nates you found.
#define TEXT_OTHERS_THAT_SDANGEROUS 0x131E                                       // That's...dangerous!
#define TEXT_OTHERS_OPERATOR_HURRY_UP_AND_PREPARE 0x131F                         // Operator. / Hurry up and prepare / for transfer.
#define TEXT_OTHERS_ZERO_IMNOT_SURE 0x1320                                       // Zero, I'm not sure / about this! / I believe in you.
#define TEXT_OTHERS_EMPTY 0x1321                                                 // ...
#define TEXT_OTHERS_OKAY 0x1322                                                  // Okay... / ... / Enter...the data... / Please, transfer / him
#define TEXT_OTHERS_ZERO_ELLIPSIS 0x1323                                         // Zero...
#define TEXT_OTHERS_ZERO_IMSO_HAPPY 0x1324                                       // Zero... / I'm so happy that / you're safe... / Please...neve
#define TEXT_OTHERS_CERVEAU_TOOK_HIM_TO 0x1325                                   // Cerveau took him to / the maintenance / room. / He wasn't hu
#define TEXT_OTHERS_SOMEONE_HAS_BROKEN 0x1329                                    // Someone has broken / into our trans- / mission circuit! / It
#define TEXT_OTHERS_PUT_THEM_THROUGH 0x132A                                      // Put them through!
#define TEXT_OTHERS_CAN_YOU_HHHEAR 0x132B                                        // Can you h-h-hear me? / Members of the / Resistance. / And...
#define TEXT_OTHERS_SURRENDER_HAND_OVER_THE_NEW 0x132C                           // Surrender? / Hand over the new / energy you invented, / the
#define TEXT_OTHERS_ICAN_TTRUST_YOU 0x132D                                       // ... / I can't... / trust...you. / What's th-that?
#define TEXT_OTHERS_YOU_WERE_PREPARED_TO 0x132E                                  // You were prepared to / sacrifice humans to / obtain the Dark
#define TEXT_OTHERS_IS_THAT_YYOUR 0x132F                                         // Is that...y-your / answer? / Fine. / You have a-a / monopoly
#define TEXT_OTHERS_THE_TRANSMISSION_WAS 0x1330                                  // The transmission was / cut off.
#define TEXT_OTHERS_THE_NEO_ARCADIAN 0x1331                                      // The Neo Arcadian / military has begun / advancing on our / b
#define TEXT_OTHERS_SO_THIS_IS_WHAT_IT 0x1334                                    // So this is what it / has come to... / Dr. Weil as the / rule
#define TEXT_OTHERS_LIVES_WITH_PLENTY 0x1335                                     // Lives with plenty / of food and / comfort... / People have s
#define TEXT_OTHERS_AND_THERE_WE_VE_JUST 0x1338                                  // And...there. / We've just finished / inputting the data / re
#define TEXT_OTHERS_CAN_YOU_STAND_UP 0x133C                                      // Can you stand up / already? / Wow, Harpuia, you're / hard to
#define TEXT_OTHERS_WHAT_ARE_YOU_UP_TO 0x133D                                    // What are you up to? / Why did you rescue / me? / Do you expe
#define TEXT_OTHERS_OH_YOU_RE_AWAKE_HOW 0x133E                                   // Oh, you're awake. / How do you feel? / Horrible. / Just the
#define TEXT_OTHERS_WAIT_YOUR_WOUNDS_ARE_NOT 0x133F                              // Wait! / Your wounds are not / fully healed yet! / I am a war
#define TEXT_OTHERS_SO_HARPUIA_REFUSES 0x1340                                    // So... / Harpuia refuses / to go with us. / ...
#define TEXT_OTHERS_OPERATOR_MR_ZERO_COME_TO 0x1341                              // Operator: Mr. Zero... / Come to the commander's / room immed
#define TEXT_OTHERS_THEY_SURE_RUN_YOU 0x1342                                     // They sure run you / ragged, don't they, / Zero. / I'll be ba
#define TEXT_OTHERS_ZERO_HARPUIA_DON_TYOU 0x1343                                 // Zero... / Harpuia... / Don't you dare / die...
#define TEXT_OTHERS_ZERO_IMSORRY_YOU 0x1346                                      // Zero... I'm sorry. / You gathered a lot / of information for
#define TEXT_OTHERS_FILE945388 0x1347                                            // File ↾945388 / == Elf Wars ==
#define TEXT_OTHERS_NEAR_THE_END_OF_THE 0x1348                                   // Near the end of the / Maverick Wars, many / Cyber-elves were
#define TEXT_OTHERS_THE_TECHNOLOGY_USED 0x1349                                   // The technology used / at this time... / ...the technology of
#define TEXT_OTHERS_HEHEHEHE_EXCELLENT_DETECTIVE 0x134A                          // ... / Hehehehe... / Excellent detective / work, Dr. Ciel.
#define TEXT_OTHERS_WHAT_UNFORTUNATELY_YOU_WERE_A 0x134B                         // What? / Unfortunately... / ...you were a little / too late.
#define TEXT_OTHERS_IS_THAT_DR_WEIL 0x134C                                       // Is that Dr. Weil?!
#define TEXT_OTHERS_HEHEHE_THIS_TIME_OMEGA_IS 0x134D                             // Hehehe... / This time, Omega is / absolutely perfect. / I ca
#define TEXT_OTHERS_NOW_YOU_WILL_SEE 0x134E                                      // Now you will see, / pitiful humans, / what you get for / ban
#define TEXT_OTHERS_TASTE_THE_FEAR_FOOLISH_REPLOIDS 0x134F                       // Taste the fear... / Foolish Reploids, / who banished me!
#define TEXT_OTHERS_INSCRIBE_MY_NAME 0x1350                                      // Inscribe my name, / upon this world... / The name of your /
#define TEXT_OTHERS_THAT_NAME_IS 0x1351                                          // That name is / Dr. Weil. / The entire world is / in my hands
#define TEXT_OTHERS_HEHEHEHEHEEE_BWAHAHAHAHAH 0x1352                             // Heheheheheee... / Bwahahahahah!
#define TEXT_OTHERS_NO 0x1353                                                    // No!
#define TEXT_OTHERS_RRR_GRRPH 0x1354                                             // Rrr...grrph...
#define TEXT_OTHERS_THIS_CAN_TBE 0x1355                                          // This can't be / happening!
#define TEXT_OTHERS_ANEW_WORLD 0x1356                                            // A new world... / A new order... / History is once / again in
#define TEXT_OTHERS_CIEL_BACK 0x1357                                             // Ciel! Back!
#define TEXT_OTHERS_ZERO_INSCRIBE_IT_UPON_THE 0x1358                             // Zero?! / Inscribe it upon the / world... The name of / our r
#define TEXT_OTHERS_BOTH_OF_YOU_FREEZE 0x1359                                    // Both of you, freeze!
#define TEXT_OTHERS_ARGH_IT_SOKAY_THEY 0x135A                                    // Argh! / It's okay. They're / just unconscious. / All I did w
#define TEXT_OTHERS_TOOK_YOU_LONG 0x135B                                         // Took you long / enough, X. / Where's Weil? / In Neo Arcadia'
#define TEXT_OTHERS_IIVE_VERIFIED_THE 0x135C                                     // I... / I've verified the / coordinates for / Sub Arcadia on
#define TEXT_OTHERS_ROGER_ALL 0x135D                                             // Roger. All / personnel, prepare / for transfer.
#define TEXT_OTHERS_PREPARATIONS_FOR 0x135E                                      // Preparations for / transfer complete.
#define TEXT_OTHERS_TRANSFER 0x135F                                              // Transfer!
#define TEXT_OTHERS_COORDINATE_DATA 0x1360                                       // Coordinate data / obtained from / Original X... / ...has bee
#define TEXT_OTHERS_THE_COORDINATES 0x1361                                       // The coordinates / lead to an abandoned / research lab. / Acc
#define TEXT_OTHERS_ZERO_BE_CAREFUL_IWILL 0x1362                                 // Zero... / Be careful... / I will. / Operator... / Is everyth
#define TEXT_OTHERS_YOU_CAN_GO_AT_ANY 0x1363                                     // You can go at any / time, Mr. Zero.

#endif  // GUARD_RMZ3_TEXT_IDS_H
