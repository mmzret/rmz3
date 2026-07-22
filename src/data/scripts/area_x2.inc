.balign 4

Camera_08354840: @ 0x08354840
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x0, 0x3C0000, 0x0, 0x280000

Camera_0835486c: @ 0x0835486c
  .byte 6
  .byte 8
  .byte 0, 0
  .4byte 0x0, 0x0
  .4byte 0x0, 0x0
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0x103000, 0x116000, 0x0, 0x280000

Entity_08354898: @ 0x08354898
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 352*PX, 2528*PX
  .4byte DIR_RIGHT

Entity_083548a8: @ 0x083548a8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 2032*PX
  .4byte DIR_RIGHT

Entity_083548b8: @ 0x083548b8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 3952*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548c8: @ 0x083548c8
  .byte PLAYER, 0
  .byte 0
  .byte 0
  .4byte 4192*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548d8: @ 0x083548d8
  .byte ENTITY_BOSS
  .byte BOSS_COPY_X
  .byte 0
  .byte 0
  .4byte 4336*PX, 448*PX
  .4byte DIR_LEFT

Entity_083548e8: @ 0x083548e8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 0
  .4byte 4264*PX, 448*PX
  .4byte DIR_RIGHT

Entity_083548f8: @ 0x083548f8
  .byte ENTITY_SOLID
  .byte SOLID_SCRIPT_ACTOR
  .byte ACTOR_UNK_57
  .byte 1
  .4byte 4264*PX, 448*PX
  .4byte DIR_LEFT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_08354908:
  spawn 0, Entity_08354898
  reset_camera Camera_08354840
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
  play_bgm BGM_NEOARCADIA3
  wait_indicator_end
  release
  resume 0
  end

Script_08354990:
  spawn 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  normal_screen
  wait_transition_end
  indicator 1, 2, 0
  wait 45
  play_bgm BGM_NEOARCADIA3
  wait_indicator_end
  release
  resume 0
  end

Script_083549f0:
  spawn 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_NEOARCADIA3
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354a48:
  spawn 0, Entity_083548a8
  reset_camera Camera_08354840
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_NEOARCADIA3
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354aa0:
  spawn 0, Entity_083548b8
  cmd1c 3, 0, 480*PX
  reset_camera Camera_08354840
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_GUARDER_ROOM
  indicator 1, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_08354b00:
  stop_bgm
  spawn 1, Entity_083548d8
  forcekeyinput DPAD_RIGHT
  pause
  cutscene_start CS_AREAX2_BOSS
  force 9, 0, 1073152
  lock
  play_bgm BGM_X
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0, 1060864
  adjust_camera 12, 0, 1138688
  gimmick 1, 0, 1
  wait 75
  triumphant_message 0, TEXT_AREA_X2_AHA_AHAHAHAH_DID_YOU_S
  message 1, 0, TEXT_AREA_X2_SO_YOU_VE_COME
  wait_msgbox_end
  cutscene_end
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_08354c00:
  stop_bgm
  spawn 1, Entity_083548d8
  forcekeyinput DPAD_RIGHT
  pause
  cutscene_start CS_AREAX2_BOSS
  force 9, 0, 1073152
  lock
  play_bgm BGM_X
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0, 1060864
  adjust_camera 12, 0, 1138688
  gimmick 1, 0, 1
  wait 75
  triumphant_message 0, TEXT_AREA_X2_AHA_AHAHAHAH_DID_YOU_S
  cutscene_end
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_08354cf0:
  cmd1c 3, 0, 480*PX
  spawn 0, Entity_083548c8
  spawn 1, Entity_083548d8
  reset_camera Camera_0835486c
  lock
  normal_screen
  wait 1
  gimmick 1, 0, 1
  wait_transition_end
  triumphant_message 0, TEXT_AREA_X2_AHA_AHAHAHAH_DID_YOU_S
  entityflag 1, 0, TRUE
  stop_bgm
  gimmick 1, 0, 2
  wait 90
  warning_indicator
  wait 90
  change_camera_mode 6
  set_chase_mode 4
  adjust_camera 11, 0, 1044480
  wait_indicator_end
  release
  play_bgm BGM_BOSS_BATTLE
  resume 1
  end

Script_08354db0:
  lockmenu
  forcekeyinput 0xFFFF
  stop_bgm
  wait 1
  lock
  force 8, 0, 0
  cutscene_start CS_AREAX2_29
  time 0
  change_camera_mode 1
  set_chase_mode 2
  set_camera_target_x 4264*PX
  set_camera_target_y 400*PX
  force 9, 0, 1073152
  wait 4
  turn_right 0
  lock
  wait 15
  waitabs 90
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_AREA_X2_NNO_WH_WHY_WHY @ くソっ…ナぜだ…！
  wait_msgbox_end
  wait 60
  message 1, 0, TEXT_AREA_X2_HE_IS_NO_LONGER_HERE @ カレはもう… ここにはいないよ
  wait_msgbox_end
  emotion_bubble 1, 12, -40, 0
  wait 60
  spawn 3, Entity_083548e8
  wait 180
  message 1, 0, TEXT_AREA_X2_WHO_AARE_YOU_X
  wait_msgbox_end
  entityflag 1, 7, TRUE
  wait 30
  message 1, 0, TEXT_AREA_X2_HAAAAAH_OH_NO_WEIL_HAS
  wait_msgbox_end
  entityflag 1, 1, TRUE
  wait 30
  message 1, 0, TEXT_AREA_X2_GEE_GAGAGA_ICAN_T
  wait_msgbox_end
  stop_bgm
  wait 60
  entityflag 1, 2, TRUE
  play_se 48
  cmd08_wait_set 1
  wait 120
  start_transition 6
  wait_transition_end
  fadeout_se 120, 317
  wait 90
  destroy 1
  stop_camera
  backdrop_color 0xFFFF
  start_transition 5
  wait 60
  cutscene_end
  start_result_screen
  wait_for_result_screen_end
  load_graphic_primitive
  destroy 0
  destroy 3
  wait 2
  end

Script_08354f98:
  backdrop_color 0xFFFF
  start_result_screen
  wait_for_result_screen_end
  lockmenu
  end

Script_08354fc0:
  unlockmenu
  cutscene_start CS_AREAX2_30
  spawn 0, Entity_083548c8
  spawn 3, Entity_083548f8
  reset_camera Camera_0835486c
  lock
  normal_screen
  wait 1
  normal_screen
  gimmick 1, 0, 3
  wait 1
  normal_screen
  wait_transition_end
  play_se 317
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_AREA_X2_WEIL_KNEW_FROM_THE
  wait_msgbox_end
  wait 60
  message 1, 0, TEXT_AREA_X2_HEAR_ME_CITIZENS_OF
  wait_msgbox_end
  wait 15
  emotion_bubble 0, 16, -40, 0
  stop_bgm
  wait 75
  message 1, 0, TEXT_AREA_X2_DR_WEIL
  wait_msgbox_end
  fadeout_se 60, 317
  blackout_screen
  wait_transition_end
  stop_camera
  cmd06 120, 0, 0
  normal_screen
  wait_transition_end
  play_bgm 166
  wait 15
  message 1, 0, TEXT_AREA_X2_JUST_NOW_OUR_HERO_MASTER
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  cmd06 0, 1, 0
  reset_camera Camera_0835486c
  normal_screen
  wait_transition_end
  play_se 317
  wait 60
  message 1, 0, TEXT_AREA_X2_THANK_YOU_ALL_I
  wait_msgbox_end
  stop_bgm
  wait 120
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_AREA_X2_IT_SALL_GOING
  wait_msgbox_end
  emotion_bubble 0, 16, -40, 1
  wait 75
  message 1, 0, TEXT_AREA_X2_WHAT_IS_IT_WELL_NEVER
  wait_msgbox_end
  wait 15
  stop_se 317
  entityflag 3, 0, TRUE
  wait 30
  entityflag 3, 1, TRUE
  wait 210
  force 2, 0, 0
  wait 60
  message 1, 0, TEXT_AREA_X2_THE_HEART
  wait_msgbox_end
  wait 30
  force 5, 0, 0
  stop_bgm
  wait 60
  blackout_screen
  wait_transition_end
  wait 30
  destroy 0
  destroy 3
  cutscene_end
  end

Script_08355230:
  spawn 0, Entity_08354898
  reset_camera Camera_08354840
  lock
  wait 1
  visible 0, FALSE
  normal_screen
  wait_transition_end
  play_bgm BGM_NEOARCADIA3
  indicator 1, 0, 0
  wait 15
  force 6, 0, 0
  wait_indicator_end
  release
  resume 0
  end

Script_083552a8:
  forcekeyinput 0xFFFF
  stop_bgm
  pause
  force 9, 0, 1091584
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

.global gAreaX2ScriptList
gAreaX2ScriptList: @ 0x08355330
  .4byte Script_08354908 @  0
  .4byte Script_08354990 @  1
  .4byte Script_083549f0 @  2
  .4byte Script_08354a48 @  3
  .4byte Script_08354aa0 @  4
  .4byte Script_08354b00 @  5
  .4byte Script_08354c00 @  6
  .4byte Script_08354cf0 @  7
  .4byte Script_08354db0 @  8
  .4byte Script_08354f98 @  9
  .4byte Script_08354fc0 @ 10
  .4byte Script_08355230 @ 11
  .4byte Script_083552a8 @ 12
