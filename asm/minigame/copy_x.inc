	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initCopyXMinigame
initCopyXMinigame: @ 0x080FA294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #0xc]
	ldr r1, _080FA510 @ =0x00000DCC
	adds r7, r0, r1
	ldr r2, _080FA514 @ =0x00000DC4
	adds r1, r0, r2
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #4
	bl ResetLandscape
	movs r5, #0x8c
	lsls r5, r5, #1
	ldr r0, _080FA518 @ =gStaticMotionGraphics
	mov r8, r0
	ldr r1, _080FA51C @ =wStaticGraphicTilenums
	mov sb, r1
	ldrh r1, [r1, #0x1c]
	ldr r2, _080FA520 @ =0x085D7A10
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadGraphic
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12
	adds r5, r5, r1
	ldr r6, _080FA528 @ =wStaticMotionPalIDs
	ldrh r1, [r6, #0x1c]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sl, r2
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _080FA52C @ =0x0000071C
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xb6
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xe6
	lsls r4, r4, #3
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xb8
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080FA530 @ =0x0000076C
	mov r1, r8
	adds r0, r4, r1
	mov r1, sb
	adds r1, #0xbe
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r0, #0
	mov r1, sb
	strh r0, [r1, #0x1c]
	movs r0, #7
	strh r0, [r6, #0x1c]
	ldr r2, _080FA520 @ =0x085D7A10
	ldrh r1, [r2, #6]
	lsrs r1, r1, #6
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	subs r1, r0, r1
	adds r0, r2, #0
	bl LoadGraphic
	ldrh r1, [r6, #0x1c]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	ldr r5, _080FA534 @ =0x00001310
	mov r1, r8
	adds r0, r5, r1
	movs r4, #0xf4
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FA524 @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r5, #0
	bl LoadPalette
	add r0, sp, #4
	movs r1, #0
	bl CreateMinigameIcon_1
	movs r1, #0xb9
	lsls r1, r1, #1
	mov r2, sb
	strh r1, [r2]
	movs r0, #0xe
	strh r0, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldrh r1, [r6]
	ldr r2, _080FA524 @ =gStaticMotionGraphics+12
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r2, #0
	bl LoadPalette
	movs r4, #0x9f
	lsls r0, r4, #1
	add sb, r0
	movs r1, #0xf0
	lsls r1, r1, #1
	mov r2, sb
	strh r1, [r2]
	adds r6, r6, r0
	movs r0, #9
	strh r0, [r6]
	lsls r4, r4, #4
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r4, r0
	add r8, r4
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	ldr r1, _080FA524 @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sl
	adds r0, r4, #0
	bl LoadPalette
	movs r0, #0x8c
	lsls r0, r0, #9
	str r0, [sp, #4]
	movs r0, #0xf6
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreatePlayerCopyX
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080FA4A8:
	adds r4, r1, #1
	movs r0, #0xec
	lsls r0, r0, #9
	subs r0, r0, r5
	str r0, [sp, #4]
	movs r0, #0x94
	lsls r0, r0, #9
	str r0, [r6, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #2
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	movs r2, #0x80
	lsls r2, r2, #5
	adds r5, r5, r2
	adds r1, r4, #0
	cmp r1, #2
	ble _080FA4A8
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	strh r4, [r7]
	movs r0, #0x78
	strh r0, [r7, #2]
	str r4, [r7, #0x20]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	ldr r0, _080FA538 @ =gSystemSavedataManager
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x24]
	strh r4, [r7, #0xe]
	movs r0, #0xb3
	bl playBGM
	ldr r0, [sp, #0xc]
	strh r4, [r0, #4]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FA510: .4byte 0x00000DCC
_080FA514: .4byte 0x00000DC4
_080FA518: .4byte gStaticMotionGraphics
_080FA51C: .4byte wStaticGraphicTilenums
_080FA520: .4byte 0x085D7A10
_080FA524: .4byte gStaticMotionGraphics+12
_080FA528: .4byte wStaticMotionPalIDs
_080FA52C: .4byte 0x0000071C
_080FA530: .4byte 0x0000076C
_080FA534: .4byte 0x00001310
_080FA538: .4byte gSystemSavedataManager

	thumb_func_start copyXMinigame
copyXMinigame: @ 0x080FA53C
	push {lr}
	ldr r2, _080FA558 @ =0x00000DCC
	adds r1, r0, r2
	ldr r2, _080FA55C @ =0x08386B80
	movs r3, #4
	ldrsh r1, [r1, r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_080FA558: .4byte 0x00000DCC
_080FA55C: .4byte 0x08386B80

	thumb_func_start copyx_minigame_080fa560
copyx_minigame_080fa560: @ 0x080FA560
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA57C @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080FA594
	cmp r0, #1
	bgt _080FA580
	cmp r0, #0
	beq _080FA58A
	b _080FA5CE
	.align 2, 0
_080FA57C: .4byte 0x00000DCC
_080FA580:
	cmp r0, #2
	beq _080FA5A8
	cmp r0, #3
	beq _080FA5BC
	b _080FA5CE
_080FA58A:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA594:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA5CE
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA5CE
_080FA5A8:
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0x1d
	bl PlaySound
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA5BC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA5CE
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA5CE:
	ldr r1, _080FA624 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA5F6
	str r4, [r5, #0x24]
_080FA5F6:
	add r4, sp, #8
	ldr r1, _080FA628 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	movs r0, #1
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA624: .4byte 0x0810E25C
_080FA628: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa62c
copyx_minigame_080fa62c: @ 0x080FA62C
	push {r4, r5, lr}
	sub sp, #0x1c
	ldr r1, _080FA6AC @ =0x00000DCC
	adds r5, r0, r1
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #2
	ldrsh r1, [r5, r3]
	bl __modsi3
	adds r4, r0, #0
	cmp r4, #0
	bne _080FA6E8
	ldr r1, _080FA6B0 @ =gGameState
	ldr r0, _080FA6B4 @ =0x0000626C
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r3, _080FA6B8 @ =0x41C64E6D
	muls r0, r3, r0
	ldr r2, _080FA6BC @ =0x00003039
	adds r0, r0, r2
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [sp, #0x14]
	movs r0, #0xf0
	lsls r0, r0, #8
	add r1, sp, #0x14
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [sp, #0x14]
	ldr r0, [r1, #4]
	ldr r3, _080FA6C0 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r1, #4]
	adds r0, r5, #0
	bl FUN_080b1934
	ldr r0, [r5, #0x20]
	adds r0, #1
	str r0, [r5, #0x20]
	strh r4, [r5]
	cmp r0, #3
	bhi _080FA6C4
	movs r0, #0x78
	b _080FA6E6
	.align 2, 0
_080FA6AC: .4byte 0x00000DCC
_080FA6B0: .4byte gGameState
_080FA6B4: .4byte 0x0000626C
_080FA6B8: .4byte 0x41C64E6D
_080FA6BC: .4byte 0x00003039
_080FA6C0: .4byte 0xFFFFD000
_080FA6C4:
	cmp r0, #0xb
	bhi _080FA6CC
	movs r0, #0x70
	b _080FA6E6
_080FA6CC:
	cmp r0, #0x17
	bhi _080FA6D4
	movs r0, #0x68
	b _080FA6E6
_080FA6D4:
	cmp r0, #0x1f
	bhi _080FA6DC
	movs r0, #0x60
	b _080FA6E6
_080FA6DC:
	cmp r0, #0x2f
	bhi _080FA6E4
	movs r0, #0x58
	b _080FA6E6
_080FA6E4:
	movs r0, #0x46
_080FA6E6:
	strh r0, [r5, #2]
_080FA6E8:
	ldr r1, _080FA75C @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA722
	str r4, [r5, #0x24]
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne _080FA722
	movs r0, #1
	strh r0, [r5, #0xe]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
_080FA722:
	add r4, sp, #8
	ldr r1, _080FA760 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	ldrb r1, [r5, #0xc]
	cmp r1, #0
	bne _080FA752
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_080FA752:
	movs r0, #1
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA75C: .4byte 0x0810E25C
_080FA760: .4byte 0x0810E264

	thumb_func_start copyx_minigame_080fa764
copyx_minigame_080fa764: @ 0x080FA764
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r1, _080FA780 @ =0x00000DCC
	adds r5, r0, r1
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #5
	bhi _080FA800
	lsls r0, r0, #2
	ldr r1, _080FA784 @ =_080FA788
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FA780: .4byte 0x00000DCC
_080FA784: .4byte _080FA788
_080FA788: @ jump table
	.4byte _080FA7A0 @ case 0
	.4byte _080FA7AA @ case 1
	.4byte _080FA7B8 @ case 2
	.4byte _080FA7CC @ case 3
	.4byte _080FA7DC @ case 4
	.4byte _080FA7E8 @ case 5
_080FA7A0:
	movs r0, #0x3c
	strh r0, [r5]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7AA:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FA800
	b _080FA7D4
_080FA7B8:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r5, #0x10]
	movs r0, #0xb3
	bl fadeoutBGM
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7CC:
	ldr r0, [r5, #0x10]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FA800
_080FA7D4:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	b _080FA800
_080FA7DC:
	ldr r1, _080FA7FC @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_080FA7E8:
	ldr r0, _080FA7FC @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FA800
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #6]
	b _080FA84C
	.align 2, 0
_080FA7FC: .4byte gGameState
_080FA800:
	ldr r1, _080FA854 @ =0x0810E25C
	mov r0, sp
	movs r2, #6
	bl memcpy
	mov r0, sp
	movs r1, #0x12
	movs r2, #0
	bl PrintUnicodeString
	ldr r4, [r5, #0x1c]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, [r5, #0x24]
	cmp r4, r0
	bls _080FA828
	str r4, [r5, #0x24]
_080FA828:
	add r4, sp, #8
	ldr r1, _080FA858 @ =0x0810E264
	adds r0, r4, #0
	movs r2, #9
	bl memcpy
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	bl PrintUnicodeString
	ldr r4, [r5, #0x24]
	adds r0, r4, #0
	movs r1, #0x1b
	movs r2, #1
	bl minigame_str_080e9d04
	movs r0, #1
_080FA84C:
	add sp, #0x14
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FA854: .4byte 0x0810E25C
_080FA858: .4byte 0x0810E264

