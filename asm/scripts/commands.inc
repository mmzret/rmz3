
	.macro goto a b c
  .byte 0x00
	.byte 0
  .2byte \b
  .4byte \c
	.endm

	.macro pause
  .byte 0x01
	.byte 0x00
  .2byte 0x00
  .4byte 0x00
	.endm

	.macro wait frame
  .byte 0x01
	.byte 0x01
  .2byte 0x00
  .4byte \frame
	.endm

	.macro waitabs absolute_time
  .byte 0x01
	.byte 0x02
  .2byte 0x00
  .4byte \absolute_time
	.endm

	.macro time t
  .byte 0x02
	.byte 0x00
  .2byte 0x00
  .4byte \t
	.endm

	.macro cmd04 a b addr
  .byte 0x04
	.byte \a
  .2byte \b
  .4byte \addr
	.endm

	.macro cmd05 a b c
  .byte 0x05
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro cmd06 a b c
  .byte 0x06
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro resume a
  .byte 0x07
	.byte \a
  .2byte 0
  .4byte 0
	.endm

	.macro disablekeyinput a b c
  .byte 0x09
	.byte \a
  .2byte \b
  .4byte \c
	.endm

  .macro lock
  .byte 0x09
	.byte 0
  .2byte 0
  .4byte 0
	.endm

  .macro release
  .byte 0x09
	.byte 1
  .2byte 0
  .4byte 0
	.endm

  .macro forcekeyinput input
  .byte 0x09
	.byte 2
  .2byte 0
  .4byte \input
	.endm

	.macro spawn slot b addr
  .byte 0x0b
	.byte \slot
  .2byte \b
  .4byte \addr
	.endm

	.macro cmd0c a b c
  .byte 0x0c
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro emergency_on
  .byte 0x10
	.byte 0
  .2byte 0
  .4byte 0
	.endm

	.macro emergency_off
  .byte 0x10
	.byte 1
  .2byte 0
  .4byte 0
	.endm

	.macro cmd0d a b c
  .byte 0x0D
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro emotion idx x y c
  .byte 0x12
	.byte \idx
  .2byte \x >> 8
  .2byte \c
  .2byte \y >> 8
	.endm

	.macro scroll a string_id duration
  .byte 0x13
	.byte \a
  .2byte \string_id
  .4byte \duration
	.endm

	.macro screeneffect a
	.byte 0x14, \a
  .2byte 0, 0, 0
	.endm

  .macro wait_screeneffect
	.byte 0x14, 0x00
  .2byte 0, 0, 0
	.endm

  .macro normal_screen
	.byte 0x14, 0x01
  .2byte 0, 0, 0
	.endm

  .macro blackout_screen
	.byte 0x14, 0x02
  .2byte 0, 0, 0
	.endm

  .macro whiteout_screen
	.byte 0x14, 0x04
  .2byte 0, 0, 0
	.endm

	.macro rune x y string
  .byte 0x15
	.byte \x
  .2byte \y
  .2byte \string
  .2byte 0x00
	.endm

	.macro indicator a b c
  .byte 0x16
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro message a b c
  .byte 0x17
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro print_message msgtype textid
  .byte 0x17
	.byte 0
  .2byte \msgtype
  .2byte \textid
  .2byte 0x00
	.endm

	.macro wait_msgbox_end
  .byte 0x17
	.byte 2
  .2byte 0
  .4byte 0x00
	.endm

  .macro play_bgm song
  .byte 0x18
  .byte 0x00
  .2byte 0
  .4byte \song
  .endm

  .macro stop_bgm
  .byte 0x18
  .byte 0x01
  .2byte 0
  .4byte 0
  .endm

  .macro wait_bgm_end
  .byte 0x18
  .byte 0x02
  .2byte 0
  .4byte 0
  .endm

	.macro play_se se
  .byte 0x19
	.byte 0
  .2byte 0
  .4byte \se
	.endm

	.macro stop_se se
  .byte 0x19
	.byte 1
  .2byte 0
  .4byte \se
	.endm

	.macro fadeout_se duration se
  .byte 0x19
	.byte 2
  .2byte \duration
  .4byte \se
	.endm

	.macro force a b c
  .byte 0x1a
	.byte \a
  .2byte \b
  .4byte \c
	.endm

  .macro start_talk
  .byte 0x1a
	.byte 2
  .2byte 0
  .4byte 0
	.endm

  .macro end_talk
  .byte 0x1a
	.byte 3
  .2byte 0
  .4byte 0
	.endm

  .macro walkto dst
  .byte 0x1a
	.byte 9
  .2byte 0
  .4byte \dst
	.endm

	.macro cmd1b a b c
  .byte 0x1b
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro cmd1c a b c
  .byte 0x1c
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro sweep a b c
  .byte 0x1d
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro lockmenu
  .byte 0x1e
	.byte 0
  .2byte 0
  .4byte 0
	.endm

	.macro unlockmenu
  .byte 0x1e
	.byte 1
  .2byte 0
  .4byte 0
	.endm

	.macro eventflag a b c
  .byte 0x1f
	.byte \a
  .2byte \b
  .4byte \c
	.endm

	.macro goodluck val
  .byte 0x23
	.byte \val
  .2byte 0
  .4byte 0
	.endm

	.macro killtimeelf
  .byte 0x24
	.byte 0
  .2byte 0
  .4byte 0
	.endm

	.macro cutscene id
  .byte 0x25
	.byte \id
  .2byte 0
  .4byte 0
	.endm

	.macro end
  .byte 0xFF
	.byte 0
  .2byte 0
  .4byte 0
	.endm
