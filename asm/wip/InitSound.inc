  push {lr}
  bl m4aSoundInit
  ldr r1, _08004440 @ =0x020021A4
	ldr r0, _08004444 @ =0x00000150
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
	ldr r0, _08004448 @ =SoundID1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0800444C @ =SoundID2
	strh r1, [r0]
	pop {r0}
	bx r0
  .align 2, 0
_08004440: .4byte gSongCount
_08004444: .4byte 336
_08004448: .4byte SoundID1
_0800444C: .4byte SoundID2
