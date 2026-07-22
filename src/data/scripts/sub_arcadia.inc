.balign 4

Camera_083580c4: @ 0x083580c4
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_083580f0: @ 0x083580f0
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 1800*PX, 2040*PX, 0*PX, MAX_Y

Camera_0835811c: @ 0x0835811c
  .byte 6, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 3712*PX, 3952*PX, 0*PX, MAX_Y

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


Entity_08358148: @ 0x08358148
  .byte PLAYER, ZERO, 0, 0
  .4byte 352*PX, 288*PX
  .4byte DIR_RIGHT

Entity_08358158: @ 0x08358158
  .byte PLAYER, ZERO, 0, 0
  .4byte 432*PX, 1088*PX
  .4byte DIR_LEFT

Entity_08358168: @ 0x08358168
  .byte PLAYER, ZERO, 0, 0
  .4byte 1848*PX, 432*PX
  .4byte DIR_RIGHT

Entity_08358178: @ 0x08358178
  .byte PLAYER, ZERO, 0, 0
  .4byte 432*PX, 1088*PX
  .4byte DIR_RIGHT

Entity_08358188: @ 0x08358188
  .byte PLAYER, ZERO, 0, 0
  .4byte 1552*PX, 1648*PX
  .4byte DIR_RIGHT

Entity_08358198: @ 0x08358198
  .byte PLAYER, ZERO, 0, 0
  .4byte 3472*PX, 3312*PX
  .4byte DIR_RIGHT

Entity_083581a8: @ 0x083581a8
  .byte PLAYER, ZERO, 0, 0
  .4byte 3760*PX, 3312*PX
  .4byte DIR_RIGHT

Entity_083581b8: @ 0x083581b8
  .byte BOSS, 21, 0, 0
  .4byte 1992*PX, 432*PX
  .4byte DIR_LEFT

Coord_083581c8: @ 0x083581c8
  .4byte 432*PX, 1088*PX

Entity_083581d0: @ 0x083581d0
  .byte BOSS, 6, 2, 0
  .4byte 3904*PX, 3312*PX
  .4byte DIR_LEFT

Entity_083581e0: @ 0x083581e0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 60, 0
  .4byte 3832*PX, 3312*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0_083581f0: @ 0x083581f0
  spawn 0, Entity_08358148
  reset_camera Camera_083580c4
  lock
  normal_screen
  wait 1
  visible 0, FALSE
  wait_transition_end
  wait 15
  force 6, 0, 0
  wait 15
  indicator 1, 2, 0
  wait 45
  play_bgm 184
  wait_indicator_end
  release
  resume 0
  end

Script_1_08358278: @ 0x08358278
  spawn 0, Entity_08358148
  reset_camera Camera_083580c4
  lock
  normal_screen
  wait_transition_end
  indicator 1, 2, 0
  wait 45
  play_bgm 184
  wait_indicator_end
  release
  resume 0
  end

Script_2_083582d8: @ 0x083582d8
  spawn 0, Entity_08358148
  reset_camera Camera_083580c4
  lock
  start_transition 9
  wait_transition_end
  play_bgm 184
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_3_08358330: @ 0x08358330
  spawn 0, Entity_08358158
  reset_camera Camera_083580c4
  lock
  start_transition 9
  wait 1
  force 11, 0, 0
  wait_transition_end
  play_bgm 184
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_4_08358398: @ 0x08358398
  stop_bgm
  lock
  pause
  cutscene_start CS_SUBARCADIA_46
  reset_camera Camera_083580f0
  wait 1
  spawn 1, Entity_083581b8
  play_bgm BGM_GUARDER_ROOM
  wait 90
  triumphant_message 0, TEXT_SUB_ARCADIA_ALL_LEGENDS_ARE
  message 1, 0, TEXT_SUB_ARCADIA_INEVER_THOUGHT_I
  wait_msgbox_end
  cutscene_end
  entityflag 1, 0, TRUE
  wait 60
  warning_indicator
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_5_08358440: @ 0x08358440
  stop_bgm
  lock
  pause
  reset_camera Camera_083580f0
  wait 1
  spawn 1, Entity_083581b8
  play_bgm BGM_GUARDER_ROOM
  wait 90
  triumphant_message 0, TEXT_SUB_ARCADIA_ALL_LEGENDS_ARE
  entityflag 1, 0, TRUE
  wait 60
  warning_indicator
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_6_083584c8: @ 0x083584c8
  spawn 0, Entity_08358168
  spawn 1, Entity_083581b8
  reset_camera Camera_083580f0
  lock
  normal_screen
  wait 1
  force 11, 0, 0
  wait_transition_end
  triumphant_message 0, TEXT_SUB_ARCADIA_ALL_LEGENDS_ARE
  entityflag 1, 0, TRUE
  wait 80
  warning_indicator
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_7_08358550: @ 0x08358550
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  message 6, 0, 0
  message 1, 0, TEXT_SUB_ARCADIA_GASP_YOU_TRULY_DID
  wait_msgbox_end
  entityflag 1, 7, TRUE
  cmd08_wait_set 1
  wait 60
  force 4, 0, 0
  wait 8
  force 5, 0, 0
  start_transition 6
  wait_transition_end
  wait 32
  destroy 1
  load_graphic_primitive
  stop_camera
  backdrop_color 0xFFFF
  blackout_screen
  wait_transition_end
  backdrop_color 0x0000
  set_entity_coords 0, Coord_083581c8
  turn_left 0
  reset_camera Camera_083580c4
  normal_screen
  wait 1
  force 6, 0, 0
  wait_transition_end
  play_bgm 184
  release
  resume 1
  end

Script_8_08358668: @ 0x08358668
  spawn 0, Entity_08358178
  reset_camera Camera_083580c4
  lock
  start_transition 9
  wait_transition_end
  play_bgm 184
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_9_083586c0: @ 0x083586c0
  spawn 0, Entity_08358188
  reset_camera Camera_083580c4
  lock
  start_transition 9
  wait_transition_end
  play_bgm 184
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_10_08358718: @ 0x08358718
  spawn 0, Entity_08358198
  reset_camera Camera_083580c4
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_11_08358770: @ 0x08358770
  spawn 3, Entity_083581e0
  forcekeyinput 0x0010
  stop_bgm
  pause
  cutscene_start CS_SUBARCADIA_47
  walkto 3688*PX
  lock
  emotion_bubble 0, 16, -40, 0
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0 3640*PX
  adjust_camera 12, 0 3952*PX
  wait 60
  play_bgm 166
  wait 15
  message 1, 0, TEXT_SUB_ARCADIA_DR_WEIL
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 60
  message 1, 0, TEXT_SUB_ARCADIA_HEHEHEHEHEEE_HOW_GALLANT_YOU_ARE
  wait_msgbox_end
  wait 15
  emotion_bubble 0, 16, -40, 0
  wait 30
  entityflag 3, 1, TRUE
  wait 30
  forcekeyinput 0x4010
  wait 15
  walkto 3760*PX
  wait 60
  message 1, 0, TEXT_SUB_ARCADIA_CREA_PREA
  wait_msgbox_end
  wait 15
  destroy 3
  spawn 1, Entity_083581d0
  emotion_bubble 0, 16, -40, 0
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0 3712*PX
  wait 60
  play_se 276
  entityflag 1, 6, TRUE
  wait 30
  entityflag 1, 6, FALSE
  wait 15
  message 1, 0, TEXT_SUB_ARCADIA_HE_SBACK
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 1, 7, TRUE
  wait 30
  entityflag 1, 7, FALSE
  wait 15
  message 1, 0, TEXT_SUB_ARCADIA_HE_SBACK_2
  wait_msgbox_end
  wait 15
  play_se 276
  entityflag 1, 6, TRUE
  wait 30
  entityflag 1, 6, FALSE
  wait 15
  message 1, 0, TEXT_SUB_ARCADIA_ILL_RIP_YOU_TO
  wait_msgbox_end
  wait 15
  play_se 277
  entityflag 1, 7, TRUE
  wait 30
  entityflag 1, 7, FALSE
  wait 15
  message 1, 0, TEXT_SUB_ARCADIA_ILL_TEAR_YOU_TO
  wait_msgbox_end
  wait 15
  triumphant_message 0, TEXT_SUB_ARCADIA_AHAHAHAHAHAHAA
  cutscene_end
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  walkto 3832*PX
  wait_indicator_end
  force 1, 0, 0
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_12_08358a20: @ 0x08358a20
  forcekeyinput 0x0010
  pause
  cutscene_start CS_SUBARCADIA_47
  wait 10
  spawn 1, Entity_083581d0
  walkto 3760*PX
  lock
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0 3712*PX
  adjust_camera 12, 0 3952*PX
  wait 60
  triumphant_message 0, TEXT_SUB_ARCADIA_AHAHAHAHAHAHAA
  cutscene_end
  entityflag 1, 0, TRUE
  stop_bgm
  wait 120
  warning_indicator
  walkto 3832*PX
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_13_08358ae0: @ 0x08358ae0
  spawn 0, Entity_083581a8
  spawn 1, Entity_083581d0
  reset_camera Camera_0835811c
  lock
  normal_screen
  wait_transition_end
  triumphant_message 0, TEXT_MISSILE_FACTORY_HEHE_GRANDPA_WILL
  entityflag 1, 0, TRUE
  wait 120
  warning_indicator
  walkto 3832*PX
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_14_08358b60: @ 0x08358b60
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  walkto 3832*PX
  wait 15
  turn_right 0
  wait 60
  play_bgm 169
  play_se 276
  wait 45
  message 1, 0, TEXT_SUB_ARCADIA_PREA_THERE_S
  wait_msgbox_end
  wait 15
  play_se 277
  wait 45
  message 1, 0, TEXT_SUB_ARCADIA_YES_CREA_THERE_S
  wait_msgbox_end
  wait 15
  play_se 276
  wait 45
  message 1, 0, TEXT_SUB_ARCADIA_IFEEL_LIKE_IM
  wait_msgbox_end
  wait 15
  play_se 277
  wait 45
  message 1, 0, TEXT_SUB_ARCADIA_IFEEL_LIKE_IM_2
  wait_msgbox_end
  wait 15
  stop_bgm
  entityflag 1, 7, TRUE
  cmd08_wait_set 1
  wait 120
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_SUB_ARCADIA_CIEL_ZERO_ARE_YOU_ALLRIGHT
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 45
  message 1, 0, TEXT_SUB_ARCADIA_UNDERSTOOD
  wait_msgbox_end
  wait 15
  stop_bgm
  force 5, 0, 0
  wait 60
  blackout_screen
  wait_transition_end
  stop_camera
  wait 60
  destroy 0
  start_result_screen
  wait_for_result_screen_end
  end

Script_15_08358d08: @ 0x08358d08
  spawn 0, Entity_08358148
  reset_camera Camera_083580c4
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_transition_end
  play_bgm 184
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_16_08358d80: @ 0x08358d80
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  walkto 3832*PX
  lock
  wait 16
  force 4, 0, 0
  wait 30
  force 5, 0, 0
  wait 60
  blackout_screen
  wait_transition_end
  wait 30
  destroy 0
  force 1, 0, 0
  release
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gSubArcadiaScriptList
gSubArcadiaScriptList: @ 0x08358e08
  .4byte Script_0_083581f0 @ 0x083581f0
  .4byte Script_1_08358278 @ 0x08358278
  .4byte Script_2_083582d8 @ 0x083582d8
  .4byte Script_3_08358330 @ 0x08358330
  .4byte Script_4_08358398 @ 0x08358398
  .4byte Script_5_08358440 @ 0x08358440
  .4byte Script_6_083584c8 @ 0x083584c8
  .4byte Script_7_08358550 @ 0x08358550
  .4byte Script_8_08358668 @ 0x08358668
  .4byte Script_9_083586c0 @ 0x083586c0
  .4byte Script_10_08358718 @ 0x08358718
  .4byte Script_11_08358770 @ 0x08358770
  .4byte Script_12_08358a20 @ 0x08358a20
  .4byte Script_13_08358ae0 @ 0x08358ae0
  .4byte Script_14_08358b60 @ 0x08358b60
  .4byte Script_15_08358d08 @ 0x08358d08
  .4byte Script_16_08358d80 @ 0x08358d80

