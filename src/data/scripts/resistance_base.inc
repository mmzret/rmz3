.balign 4

Camera_0835bdec: @ 0x0835bdec
  .byte 3, 8, 0, 0
  .4byte 0*PX, 0*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0835be18: @ 0x0835be18
  .byte 1, 8, 0, 0
  .4byte 360*PX, 400*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

Camera_0835be44: @ 0x0835be44
  .byte 1, 8, 0, 0
  .4byte 4264*PX, 400*PX
  .4byte 0*PX, 0*PX
  .2byte 0x0, 0x0, 0x0, 0x0
  .4byte 0*PX, MAX_X, 0*PX, MAX_Y

EntityTemplate_Zero_0835be70: @ 0x0835be70
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x19000, 464*PX
  .4byte DIR_LEFT

EntityTemplate_Zero_0835be80: @ 0x0835be80
  .byte PLAYER, ZERO, 0, 0
  .4byte 0xDB000, 304*PX
  .4byte DIR_LEFT

EntityTemplate_Ciel_0835be90: @ 0x0835be90
  .byte SOLID, SOLID_SCRIPT_ACTOR, ACTOR_SAVE_SELECT_CIEL, 0
  .4byte 0xD8000, 304*PX
  .4byte DIR_RIGHT

EntityTemplate_Zero_0835bea0: @ 0x0835bea0
  .byte PLAYER, ZERO, 0, 0
  .4byte 360*PX, 464*PX
  .4byte DIR_LEFT

EntityTemplate_0835beb0: @ 0x0835beb0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 22, 0
  .4byte 0x11000, 448*PX
  .4byte DIR_RIGHT

EntityTemplate_0835bec0: @ 0x0835bec0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 22, 1
  .4byte 0x11C00, 448*PX
  .4byte DIR_RIGHT

Entity_Zero_0835bed0: @ 0x0835bed0
  .byte PLAYER, ZERO, 0, 1
  .4byte 360*PX, 304*PX
  .4byte DIR_LEFT

Entity_0835bee0: @ 0x0835bee0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 48, 0
  .4byte 0x10B100, 448*PX
  .4byte DIR_RIGHT

Entity_0835bef0: @ 0x0835bef0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 49, 0
  .4byte 0x106000, 448*PX
  .4byte DIR_RIGHT

Entity_0835bf00: @ 0x0835bf00
  .byte SOLID, SOLID_SCRIPT_ACTOR, 50, 0
  .4byte 0x10CC00, 448*PX
  .4byte DIR_LEFT

Entity_0835bf10: @ 0x0835bf10
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x19000, 464*PX
  .4byte DIR_LEFT

Entity_0835bf20: @ 0x0835bf20
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x17800, 464*PX
  .4byte DIR_LEFT

Entity_0835bf30: @ 0x0835bf30
  .byte SOLID, SOLID_SCRIPT_ACTOR, 61, 0
  .4byte 0xBD000, 608*PX
  .4byte DIR_LEFT

Entity_0835bf40: @ 0x0835bf40
  .byte SOLID, SOLID_SCRIPT_ACTOR, 62, 0
  .4byte 0xB6000, 608*PX
  .4byte DIR_RIGHT

Entity_0835bf50: @ 0x0835bf50
  .byte SOLID, SOLID_SCRIPT_ACTOR, 63, 0
  .4byte 0xB3000, 608*PX
  .4byte DIR_RIGHT

Entity_0835bf60: @ 0x0835bf60
  .byte PLAYER, ZERO, 0, 0
  .4byte 0x77000, 0x39000
  .4byte DIR_RIGHT

Entity_0835bf70: @ 0x0835bf70
  .byte SOLID, SOLID_SCRIPT_ACTOR, 64, 0
  .4byte 0x1C800, 464*PX
  .4byte DIR_LEFT

Entity_0835bf80: @ 0x0835bf80
  .byte SOLID, SOLID_SCRIPT_ACTOR, 64, 1
  .4byte 0x10800, 464*PX
  .4byte DIR_RIGHT

Entity_0835bf90: @ 0x0835bf90
  .byte SOLID, SOLID_SCRIPT_ACTOR, 64, 2
  .4byte 0x1B400, 464*PX
  .4byte DIR_LEFT

Entity_0835bfa0: @ 0x0835bfa0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 64, 3
  .4byte 0x11C00, 464*PX
  .4byte DIR_RIGHT

Entity_0835bfb0: @ 0x0835bfb0
  .byte SOLID, SOLID_SCRIPT_ACTOR, 65, 0
  .4byte 360*PX, 448*PX
  .4byte DIR_RIGHT

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Script_0835bfc0:
  spawn 0, EntityTemplate_Zero_0835be70
  reset_camera Camera_0835bdec
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_ContinueGameSaveSelect:
  spawn 0, EntityTemplate_Zero_0835be80
  spawn 3, EntityTemplate_Ciel_0835be90
  reset_camera Camera_0835bdec
  lock
  normal_screen
  play_bgm BGM_RBASE
  wait 1
  start_talk
  wait_transition_end
  resume 0
  end

Script_0835c060:
  spawn 0, EntityTemplate_Zero_0835bea0
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_transition_end
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_ReturnFromStageRun:
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  reset_camera Camera_0835be18
  normal_screen
  wait FRAME
  spawn 3, EntityTemplate_0835beb0
  spawn 4, EntityTemplate_0835bec0
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_transition_end
  print_message 0x14, TEXT_SYSTEM_TRANSFERRING
  wait_msgbox_end
  play_se SE_TENSOU_VOICE
  wait SECOND
  spawn 0, Entity_Zero_0835bed0, 1
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, TEXT_SYSTEM_TRANSFER_COMPLETE @ おつかれさまでした
  wait_msgbox_end
  reset_camera Camera_0835bdec
  play_bgm BGM_RBASE
  wait SECOND+15*FRAME
  gimmick 1, 1, 1
  wait SECOND/4
  goodluck 0
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  wait 8*FRAME
  gimmick 1, 1, 2
  wait 8*FRAME
  gimmick 1, 1, 0x82
  wait 8*FRAME
  gimmick 1, 1, 0x80
  wait 45*FRAME
  message 1, 0, TEXT_OTHERS_MS_CIEL_PLEASE
  wait_msgbox_end
  wait SECOND/2
  entityflag 3, 0, TRUE
  wait SECOND/4
  entityflag 4, 0, TRUE
  wait 3*SECOND
  destroy 3
  destroy 4
  gimmick 1, 1, 0x82
  wait 8*FRAME
  gimmick 1, 1, 2
  wait 8*FRAME
  gimmick 1, 1, 0
  wait SECOND/4
  start_talk
  wait 16*FRAME
  wait_msgbox_end
  release
  resume 0
  end

Script_0835c288:
  lock
  message 1, 0, TEXT_OTHERS_YOU_HAVE_COMPLETED
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 2
  wait SECOND/2
  message 1, 0, TEXT_OTHERS_WE_HAVE_TO_DO
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  wait 8*FRAME
  start_talk
  wait 16*FRAME
  wait_msgbox_end
  stop_bgm
  wait SECOND
  start_transition 10
  wait_transition_end
  destroy 0
  wait SECOND*2
  end

Script_ReceiveRod:
  lock
  wait_msgbox_end
  wait 70*FRAME
  message 1, 0, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_RECOIL_ROD @ リコイルロッドを手に入れた！
  wait_msgbox_end
  message 1, 0, TEXT_OPEN_SECRET_DISK_YOU_GOT_THE_SBOOMERANG
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, TEXT_OTHERS_OH_ONE_MORE_THING
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, TEXT_OTHERS_OPERATOR_MR_ZERO_PLEASE_COME
  wait_msgbox_end
  wait SECOND
  message 1, 0, TEXT_OTHERS_HMM_ZERO_THEY_RE
  wait_msgbox_end
  wait SECOND/2
  end_talk
  wait SECOND/2
  walkto 0xD5000
  wait SECOND/2
  message 1, 0, TEXT_OTHERS_THIS_RECOIL_ROD @ リコイルロッド使いやすそうだ...
  wait_msgbox_end
  wait SECOND/4
  sweep 2, 0, 0
  forcekeyinput DPAD_LEFT
  wait 10*FRAME
  blackout_screen
  wait_transition_end
  lock
  stop_camera
  normal_screen
  wait_transition_end
  message 1, 0, TEXT_OTHERS_THE_WORLD_IS_TOO @ シエルにはまだ...ささえてやってくれ ゼロ....
  wait_msgbox_end
  sweep 3, 0, 0
  wait 32*FRAME
  resume_camera
  wait_transition_end
  release
  resume 0
  end

Script_0835c480:
  lock
  killtimeelf
  force 1, 0, 0
  end_talk
  wait SECOND/4
  walkto 360*PX
  wait SECOND/4
  turn_left 0
  message 1, 0, TEXT_SYSTEM_MISSION_ASSIGNED_ALIAS4
  wait_msgbox_end
  stop_bgm
  play_se SE_TENSOU_BEEP
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait SECOND
  print_message 0x1E, TEXT_SYSTEM_PREPARATIONS_FOR
  wait_msgbox_end
  wait SECOND/4
  print_message 0x14, TEXT_SYSTEM_TRANSFER
  wait SECOND/4
  play_se SE_TENSOU_VOICE
  wait SECOND*3/4
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait SECOND/2
  fadeout_se SECOND SE_TENSOU_BEEP
  wait SECOND/4
  goodluck 1
  wait SECOND/4
  emergency_off
  wait_msgbox_end
  wait SECOND/4
  blackout_screen
  wait_transition_end
  wait SECOND
  end

Script_0835c5b0:
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  reset_camera Camera_0835be18
  normal_screen
  wait FRAME
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_transition_end
  print_message 0x14, TEXT_SYSTEM_TRANSFERRING
  wait_msgbox_end
  play_se SE_TENSOU_VOICE
  wait SECOND
  spawn 0, Entity_Zero_0835bed0, 1
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, TEXT_SYSTEM_TRANSFER_COMPLETE @ おつかれさまでした
  wait_msgbox_end
  reset_camera Camera_0835bdec
  play_bgm BGM_RBASE
  wait 75*FRAME
  gimmick 1, 1, 1
  wait SECOND/4
  goodluck 0
  wait_msgbox_end
  wait SECOND/4
  gimmick 1, 1, 0
  release
  resume 0
  end

Script_FreeRunTransport:
  lock
  killtimeelf
  force 1, 0, 0
  end_talk
  wait SECOND/4
  walkto 360*PX
  wait SECOND/4
  turn_left 0
  stop_bgm
  play_se SE_TENSOU_BEEP
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait SECOND
  print_message 0x1E, TEXT_SYSTEM_PREPARATIONS_FOR
  wait_msgbox_end
  wait SECOND/4
  print_message 0x14, TEXT_SYSTEM_TRANSFER
  wait SECOND/4
  play_se SE_TENSOU_VOICE
  wait SECOND*3/4
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  fadeout_se SECOND SE_TENSOU_BEEP
  emergency_off
  wait SECOND
  blackout_screen
  wait_transition_end
  wait SECOND
  end

Script_0835c7b0:
  play_bgm SE_RBASE_TYPING
  cmd1c 0, 0, 0
  reset_camera Camera_0835be18
  normal_screen
  wait FRAME
  gimmick 1, 0, 1
  cmd1c 1, 0, 0
  wait_transition_end
  spawn 0, Entity_Zero_0835bed0, 1
  lock
  wait FRAME
  force 6, 0, 0
  gimmick 1, 0, 2
  wait SECOND
  stop_bgm
  print_message 0x14, TEXT_SYSTEM_TRANSFER_COMPLETE @ おつかれさまでした
  wait_msgbox_end
  reset_camera Camera_0835bdec
  play_bgm BGM_RBASE
  wait 75*FRAME
  release
  resume 0
  end

Script_0835c868:
  cutscene_start CS_HARPUIA_FIRED
  gimmick 0, 10, 0
  reset_camera Camera_0835be44
  normal_screen
  wait 1
  cmd1c 0, 0, 0
  gimmick 0, 10, 0
  spawn 3, Entity_0835bee0
  spawn 4, Entity_0835bef0
  start_transition 9
  wait_transition_end
  play_bgm BGM_X
  wait 120
  message 1, 0, TEXT_OTHERS_MASTER_XDO_YOU_STILL @ エックスさま…… まだ、あのオトコ…バイルを
  wait_msgbox_end
  entityflag 4, 0, TRUE
  wait 30
  message 1, 0, TEXT_OTHERS_BUT_HEHEHE
  wait_msgbox_end
  wait 15
  spawn 5, Entity_0835bf00
  wait 60
  message 1, 0, TEXT_OTHERS_IDR_WEIL_SHALL
  wait_msgbox_end
  blackout_screen
  wait_transition_end
  stop_camera
  cmd06 118, 0, 0
  normal_screen
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_STILL_TO_GOSSIP
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  cmd06 0, 1, 0
  reset_camera Camera_0835be44
  normal_screen
  wait_transition_end
  wait 15
  entityflag 5, 0, TRUE
  wait 90
  message 1, 0, TEXT_OTHERS_MASTER_XTHE_DARK_ELF
  wait_msgbox_end
  emotion_bubble 4, 12, -48, 0
  wait 75
  message 1, 0, TEXT_OTHERS_WE_LL_GO_LEVIATHAN_AND
  wait_msgbox_end
  entityflag 5, 0, FALSE
  wait 75
  message 1, 0, TEXT_OTHERS_HEHEHEHE
  wait_msgbox_end
  stop_bgm
  wait 60
  start_transition 10
  wait_transition_end
  wait 120
  destroy 3
  destroy 4
  destroy 5
  cutscene_end
  end

Script_0835ca60:
  cutscene_start CS_MISSILE_ALERT
  cmd1c 1, 0, 0
  wait 1
  gimmick 0, 17, 0
  spawn 0, Entity_0835bf10
  reset_camera Camera_0835bdec
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_RBASE
  wait 60
  stop_bgm
  play_se 293
  emergency_on
  emotion_bubble 0, 8, -40, 0
  wait 75
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_OTHERS_PREPARATIONS_HAVE @ 巨大ミサイルが ハッシャじゅんびに入りました
  wait_msgbox_end
  wait 15
  force 9, 0, 92160
  lock
  wait 15
  message 1, 0, TEXT_OTHERS_CIEL_ENTER_THE_COORDI
  wait_msgbox_end
  sweep 2, 0, 0
  wait 15
  gimmick 1, 1, 1
  wait 30
  message 1, 0, TEXT_OTHERS_THAT_SDANGEROUS
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 45
  message 1, 0, TEXT_OTHERS_OPERATOR_HURRY_UP_AND_PREPARE
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 30
  message 1, 0, TEXT_OTHERS_ZERO_IMNOT_SURE
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 2
  wait 15
  message 1, 0, TEXT_OTHERS_EMPTY
  wait_msgbox_end
  wait 90
  gimmick 1, 1, 0
  wait 15
  message 1, 0, TEXT_OTHERS_OKAY
  wait_msgbox_end
  wait 15
  gimmick 1, 0, 1
  wait 75
  print_message 20, TEXT_SYSTEM_TRANSFER
  wait 15
  play_se 153
  wait 45
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait 30
  fadeout_se 60, 293
  gimmick 1, 1, 1
  wait 30
  message 1, 0, TEXT_OTHERS_ZERO_ELLIPSIS
  wait 15
  emergency_off
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_transition_end
  wait 60
  sweep 3, 0, 0
  cutscene_end
  end

Script_0835ccc8:
  spawn 0, Entity_0835bf20
  lock
  sweep 2, 0, 0
  wait 1
  force 2, 0, 0
  wait 15
  reset_camera Camera_0835bdec
  lock
  start_transition 9
  wait_transition_end
  play_bgm BGM_ANTAN
  wait 30
  gimmick 1, 1, 1
  wait 30
  message 1, 0, TEXT_OTHERS_ZERO_IMSO_HAPPY
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  gimmick 1, 1, 2
  message 1, 0, TEXT_OTHERS_CERVEAU_TOOK_HIM_TO
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  sweep 3, 0, 0
  wait 16
  wait_msgbox_end
  wait 30
  end

Script_0835cdb8:
  spawn 0, Entity_0835bf20
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_transition_end
  play_bgm BGM_ANTAN
  end

Script_0835cdf0:
  cutscene_start CS_RBASE_24
  wait 30
  play_se 298
  wait 90
  message 1, 0, TEXT_OTHERS_SOMEONE_HAS_BROKEN @ ツウシンかいせんに キョウセイわりこみ……！
  wait_msgbox_end
  wait 15
  emotion_bubble 0, 8, -40, 0
  wait 75
  sweep 2, 0, 0
  force 2, 0, 0
  wait 60
  message 1, 0, TEXT_OTHERS_PUT_THEM_THROUGH
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_transition_end
  stop_camera
  cmd06 119, 0, 0
  normal_screen
  wait_transition_end
  play_bgm 166
  wait 15
  message 1, 0, TEXT_OTHERS_CAN_YOU_HHHEAR
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_SURRENDER_HAND_OVER_THE_NEW
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 2
  wait 90
  message 1, 0, TEXT_OTHERS_ICAN_TTRUST_YOU
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 15
  message 1, 0, TEXT_OTHERS_YOU_WERE_PREPARED_TO
  wait_msgbox_end
  blackout_screen
  wait_transition_end
  stop_camera
  cmd06 119, 0, 0
  normal_screen
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_IS_THAT_YYOUR
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_transition_end
  wait 15
  stop_bgm
  message 1, 0, TEXT_OTHERS_THE_TRANSMISSION_WAS
  wait_msgbox_end
  wait 15
  play_se 293
  emergency_on
  wait 90
  message 1, 0, TEXT_OTHERS_THE_NEO_ARCADIAN
  wait_msgbox_end
  fadeout_se 60, 293
  emergency_off
  wait 15
  cutscene_end
  sweep 3, 0, 0
  wait 16
  play_bgm BGM_RBASE
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d098:
  spawn 0, Entity_0835bf20
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_transition_end
  play_bgm BGM_RBASE
  force 2, 0, 0
  wait 16
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d108:
  lock
  sweep 2, 0, 0
  wait 8
  gimmick 1, 1, 2
  wait 15
  force 2, 0, 0
  wait 30
  message 1, 0, TEXT_OTHERS_LIVES_WITH_PLENTY
  wait_msgbox_end
  wait 15
  gimmick 1, 1, 0
  wait 8
  sweep 3, 0, 0
  wait 16
  wait_msgbox_end
  wait 15
  release
  unlockmenu
  resume 0
  end

Script_0835d1a8:
  lock
  message 1, 0, TEXT_OTHERS_AND_THERE_WE_VE_JUST
  wait_msgbox_end
  wait 15
  force 2, 0, 0
  wait 16
  wait_msgbox_end
  wait 30
  release
  unlockmenu
  resume 0
  end

Script_0835d208:
  cmd1c 3, 0, 160*PX
  gameflag FLAG_BRAIN_CONTROL, TRUE
  destroy 0
  cutscene_start CS_RBASE_44
  spawn 3, Entity_0835bf30
  spawn 4, Entity_0835bf40
  wait_transition_end
  stop_bgm
  wait 15
  emotion_bubble 4, 16, -40, 0
  wait 75
  play_bgm BGM_ANTAN
  message 1, 0, TEXT_OTHERS_CAN_YOU_STAND_UP @ もう…たてるのか さすがだな ハルピュイア……
  wait_msgbox_end
  wait 15
  entityflag 4, 0, TRUE
  wait 120
  message 1, 0, TEXT_OTHERS_WHAT_ARE_YOU_UP_TO
  wait_msgbox_end
  wait 15
  spawn 5, Entity_0835bf50
  wait 105
  message 1, 0, TEXT_OTHERS_OH_YOU_RE_AWAKE_HOW
  wait_msgbox_end
  message 1, 0, TEXT_OTHERS_WAIT_YOUR_WOUNDS_ARE_NOT
  wait_msgbox_end
  wait 15
  entityflag 3, 0, TRUE
  wait 120
  message 1, 0, TEXT_OTHERS_SO_HARPUIA_REFUSES
  wait_msgbox_end
  wait 60
  message 1, 0, TEXT_OTHERS_OPERATOR_MR_ZERO_COME_TO
  wait_msgbox_end
  wait 15
  message 1, 0, TEXT_OTHERS_THEY_SURE_RUN_YOU
  wait_msgbox_end
  wait 15
  entityflag 4, 1, TRUE
  wait 120
  message 1, 0, TEXT_OTHERS_ZERO_HARPUIA_DON_TYOU
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_transition_end
  cmd1c 3, 0, 10240*PX
  destroy 3
  destroy 4
  destroy 5
  wait 30
  cutscene_end
  spawn 0, Entity_0835bf60
  reset_camera Camera_0835bdec
  forcekeyinput 0xFFFF
  normal_screen
  wait 1
  release
  wait_transition_end
  play_bgm BGM_RBASE
  end

Script_0835d3f0:
  spawn 0, Entity_0835bf60
  reset_camera Camera_0835bdec
  lock
  normal_screen
  wait_transition_end
  play_bgm BGM_RBASE
  release
  resume 0
  end

Script_0835d438:
  cutscene_start CS_RBASE_45
  lock
  message 1, 1, TEXT_OTHERS_ZERO_IMSORRY_YOU
  message 2, 1, 0
  kill_message
  wait_msgbox_end
  stop_bgm
  wait 15
  blackout_screen
  wait_transition_end
  stop_camera
  normal_screen
  wait_transition_end
  play_bgm 223
  wait 60
  message 1, 0, TEXT_OTHERS_FILE945388
  wait_msgbox_end
  wait 15
  normal_screen
  wait 1
  cmd06 122, 0, 0
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_NEAR_THE_END_OF_THE
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  cmd06 0, 1, 0
  reset_camera Camera_0835bdec
  normal_screen
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_THE_TECHNOLOGY_USED
  wait_msgbox_end
  stop_bgm
  wait 60
  message 1, 0, TEXT_OTHERS_HEHEHEHE_EXCELLENT_DETECTIVE
  wait_msgbox_end
  play_bgm 166
  wait 15
  emotion_bubble 0, 12, -40, 0
  wait 75
  message 1, 0, TEXT_OTHERS_WHAT_UNFORTUNATELY_YOU_WERE_A
  wait_msgbox_end
  wait 30
  message 1, 0, TEXT_OTHERS_IS_THAT_DR_WEIL
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  stop_camera
  play_brain_control_movie 0
  normal_screen
  wait_transition_end
  wait 15
  play_brain_control_movie 1
  wait 15
  message 1, 1, TEXT_OTHERS_HEHEHE_THIS_TIME_OMEGA_IS
  message 2, 1, 0
  message 1, 1, TEXT_OTHERS_NOW_YOU_WILL_SEE
  message 2, 1, 0
  wait 15
  play_se 333
  start_transition 5
  wait 15
  message 1, 1, TEXT_OTHERS_TASTE_THE_FEAR_FOOLISH_REPLOIDS
  message 2, 1, 0
  wait 15
  play_se 333
  start_transition 5
  wait 15
  message 1, 1, TEXT_OTHERS_INSCRIBE_MY_NAME
  message 2, 1, 0
  wait 15
  play_se 333
  start_transition 5
  wait 30
  play_se 333
  start_transition 5
  wait 30
  play_se 333
  start_transition 5
  wait 12
  play_se 333
  start_transition 5
  wait 12
  play_se 333
  start_transition 5
  wait 12
  play_se 333
  start_transition 5
  wait 15
  message 1, 1, TEXT_OTHERS_THAT_NAME_IS
  message 2, 1, 0
  kill_message
  wait_msgbox_end
  wait 15
  start_transition 6
  wait_transition_end
  wait 120
  play_brain_control_movie 2
  reset_camera Camera_0835bdec
  gimmick 0, 17, 0
  start_transition 5
  wait_transition_end
  wait 15
  message 1, 0, TEXT_OTHERS_HEHEHEHEHEEE_BWAHAHAHAHAH
  wait_msgbox_end
  message 1, 0, TEXT_OTHERS_NO
  wait_msgbox_end
  wait 15
  spawn 3, Entity_0835bf70
  wait 60
  emotion_bubble 0, 12, -40, 0
  wait 75
  force 3, 0, 0
  wait 15
  turn_right 0
  wait 15
  message 1, 0, TEXT_OTHERS_RRR_GRRPH
  wait_msgbox_end
  wait 30
  message 1, 0, TEXT_OTHERS_THIS_CAN_TBE
  wait_msgbox_end
  wait 15
  spawn 4, Entity_0835bf80
  wait 60
  message 1, 0, TEXT_OTHERS_ANEW_WORLD
  wait_msgbox_end
  wait 15
  force 9, 0, 100352
  wait 15
  message 1, 0, TEXT_OTHERS_CIEL_BACK
  wait_msgbox_end
  wait 15
  spawn 5, Entity_0835bf90
  spawn 6, Entity_0835bfa0
  wait 75
  message 1, 0, TEXT_OTHERS_ZERO_INSCRIBE_IT_UPON_THE
  wait_msgbox_end
  wait 30
  message 1, 0, TEXT_OTHERS_BOTH_OF_YOU_FREEZE
  wait_msgbox_end
  wait 30
  spawn 7, Entity_0835bfb0
  wait 150
  play_se 333
  entityflag 3, 0, TRUE
  entityflag 4, 0, TRUE
  entityflag 5, 0, TRUE
  entityflag 6, 0, TRUE
  start_transition 5
  stop_bgm
  wait 90
  message 1, 0, TEXT_OTHERS_ARGH_IT_SOKAY_THEY
  wait 30
  play_bgm BGM_ANTAN
  wait_msgbox_end
  wait 15
  turn_left 0
  force 2, 0, 0
  wait 45
  message 1, 0, TEXT_OTHERS_TOOK_YOU_LONG
  wait_msgbox_end
  wait 15
  entityflag 7, 0, TRUE
  entityflag 7, 1, TRUE
  wait 210
  message 1, 0, TEXT_OTHERS_IIVE_VERIFIED_THE
  wait_msgbox_end
  wait 15
  force 3, 0, 0
  wait 15
  force 9, 0, 92160
  wait 15
  turn_left 0
  message 1, 0, TEXT_OTHERS_ROGER_ALL
  wait_msgbox_end
  stop_bgm
  play_se 293
  emergency_on
  gimmick 1, 0, 1
  force 4, 0, 0
  wait 60
  print_message 30, TEXT_OTHERS_PREPARATIONS_FOR
  wait_msgbox_end
  wait 15
  print_message 20, TEXT_OTHERS_TRANSFER
  wait 15
  play_se 153
  wait 45
  wait_msgbox_end
  force 5, 0, 0
  gimmick 1, 0, 2
  wait 30
  fadeout_se 60, 293
  wait 15
  goodluck 1
  wait 15
  emergency_off
  wait_msgbox_end
  wait 15
  blackout_screen
  wait_transition_end
  destroy 3
  destroy 4
  destroy 5
  destroy 6
  destroy 7
  wait 60
  cutscene_end
  end

Script_0835dae0:
  wait SECOND/4
  message 1, 0, TEXT_OTHERS_COORDINATE_DATA
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, TEXT_OTHERS_THE_COORDINATES
  wait_msgbox_end
  wait 90*FRAME
  message 1, 0, TEXT_OTHERS_ZERO_BE_CAREFUL_IWILL
  wait_msgbox_end
  wait SECOND/4
  message 1, 0, TEXT_OTHERS_YOU_CAN_GO_AT_ANY
  wait_msgbox_end
  wait SECOND/4
  end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global gResistanceBaseScriptList
gResistanceBaseScriptList:
  .word Script_0835bfc0
  .word Script_ContinueGameSaveSelect
  .word Script_0835c060
  .word Script_ReturnFromStageRun
  .word Script_0835c288
  .word Script_ReceiveRod
  .word Script_0835c480
  .word Script_0835c5b0
  .word Script_FreeRunTransport
  .word Script_0835c7b0
  .word Script_0835c868
  .word Script_0835ca60
  .word Script_0835ccc8
  .word Script_0835cdb8
  .word Script_0835cdf0
  .word Script_0835d108
  .word Script_0835d1a8
  .word Script_0835d208
  .word Script_0835d3f0
  .word Script_0835d438
  .word Script_0835dae0
  .word Script_0835d098
