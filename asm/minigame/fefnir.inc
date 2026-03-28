	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start fefnir_080fb018
fefnir_080fb018: @ 0x080FB018
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FB050 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FB054 @ =0x0810E284
	movs r1, #1
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x20]
	movs r1, #0xc
	movs r2, #0
	bl minigame_str_080e9d04
	ldr r0, _080FB058 @ =0x0810E28C
	movs r1, #0xf
	movs r2, #0
	bl PrintUnicodeString
	ldr r0, [r4, #0x28]
	movs r1, #0x1c
	movs r2, #0
	bl minigame_str_080e9d04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FB050: .4byte 0x00000DCC
_080FB054: .4byte 0x0810E284
_080FB058: .4byte 0x0810E28C

	thumb_func_start initFefnirMinigame
initFefnirMinigame: @ 0x080FB05C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r5, _080FB204 @ =0x00000DCC
	add r5, sb
	ldr r1, _080FB208 @ =0x00000DC4
	add r1, sb
	ldr r0, _080FB20C @ =0x0026E800
	str r0, [r1]
	movs r2, #0x88
	lsls r2, r2, #0xa
	str r2, [r1, #4]
	movs r0, #7
	bl ResetLandscape
	ldr r6, _080FB210 @ =gStaticMotionGraphics
	ldr r0, _080FB214 @ =wStaticGraphicTilenums
	mov sl, r0
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	ldr r0, _080FB218 @ =gStaticMotionGraphics+12
	mov r8, r0
	ldr r7, _080FB21C @ =wStaticMotionPalIDs
	ldrh r1, [r7]
	ldrb r0, [r0, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, r8
	bl LoadPalette
	movs r4, #0xa5
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sl
	adds r1, #0x42
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	adds r0, r7, #0
	adds r0, #0x42
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sl
	adds r1, #0x44
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r6, r4, r6
	mov r0, sl
	adds r0, #0x46
	ldrh r1, [r0]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	adds r0, r6, #0
	bl LoadGraphic
	add r4, r8
	adds r0, r7, #0
	adds r0, #0x46
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r5, #0
	ldr r1, _080FB20C @ =0x0026E800
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl CreatePlayerFefnir
	ldr r1, _080FB220 @ =0x00269700
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #4]
	ldr r1, _080FB224 @ =0x0026CD00
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #8]
	ldr r1, _080FB228 @ =0x00270300
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #0xc]
	ldr r1, _080FB22C @ =0x00273900
	adds r0, r5, #0
	movs r2, #0x88
	lsls r2, r2, #0xa
	bl FUN_08071508
	str r0, [r5, #0x10]
	ldr r2, _080FB230 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FB234 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080FB238 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x30
	ldr r1, _080FB23C @ =0x00000DF9
	add r1, sb
	strb r0, [r1]
	ldr r0, _080FB240 @ =0x00000DFA
	add r0, sb
	movs r2, #0
	strb r2, [r0]
	strb r2, [r5]
	strb r2, [r5, #1]
	strb r2, [r5, #2]
	strb r2, [r5, #3]
	movs r0, #0
	str r0, [r5, #0x20]
	str r0, [r5, #0x24]
	ldr r0, _080FB244 @ =gSystemSavedataManager
	ldr r0, [r0, #0x34]
	str r0, [r5, #0x28]
	ldr r0, _080FB248 @ =0x00000DF8
	add r0, sb
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080FB24C @ =0x00000DFB
	add sb, r2
	mov r0, sb
	strb r1, [r0]
	movs r0, #0xbd
	bl playBGM
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB204: .4byte 0x00000DCC
_080FB208: .4byte 0x00000DC4
_080FB20C: .4byte 0x0026E800
_080FB210: .4byte gStaticMotionGraphics
_080FB214: .4byte wStaticGraphicTilenums
_080FB218: .4byte gStaticMotionGraphics+12
_080FB21C: .4byte wStaticMotionPalIDs
_080FB220: .4byte 0x00269700
_080FB224: .4byte 0x0026CD00
_080FB228: .4byte 0x00270300
_080FB22C: .4byte 0x00273900
_080FB230: .4byte RNG_0202f388
_080FB234: .4byte 0x000343FD
_080FB238: .4byte 0x00269EC3
_080FB23C: .4byte 0x00000DF9
_080FB240: .4byte 0x00000DFA
_080FB244: .4byte gSystemSavedataManager
_080FB248: .4byte 0x00000DF8
_080FB24C: .4byte 0x00000DFB

	thumb_func_start fefnirMinigame
fefnirMinigame: @ 0x080FB250
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080FB294 @ =0x00000DCC
	adds r4, r5, r0
	ldr r1, _080FB298 @ =0x08386B98
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r0, [r4, #0x20]
	ldr r1, _080FB29C @ =0x0001869F
	cmp r0, r1
	ble _080FB274
	str r1, [r4, #0x20]
_080FB274:
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	ble _080FB2B4
	ldr r0, _080FB2A0 @ =0x00000DF8
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080FB2A4
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	b _080FB2AA
	.align 2, 0
_080FB294: .4byte 0x00000DCC
_080FB298: .4byte 0x08386B98
_080FB29C: .4byte 0x0001869F
_080FB2A0: .4byte 0x00000DF8
_080FB2A4:
	ldr r0, _080FB2B0 @ =0x00000137
	bl PlaySound
_080FB2AA:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x28]
	b _080FB2C0
	.align 2, 0
_080FB2B0: .4byte 0x00000137
_080FB2B4:
	ldr r0, [r4, #0x24]
	cmp r0, r1
	beq _080FB2C0
	ldr r0, _080FB2D4 @ =0x00000137
	bl PlaySound
_080FB2C0:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl fefnir_080fb018
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080FB2D4: .4byte 0x00000137

	thumb_func_start fefnir_minigame_080fb2d8
fefnir_minigame_080fb2d8: @ 0x080FB2D8
	push {r4, lr}
	ldr r1, _080FB2F0 @ =0x00000DCC
	adds r4, r0, r1
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _080FB308
	cmp r0, #1
	bgt _080FB2F4
	cmp r0, #0
	beq _080FB2FE
	b _080FB344
	.align 2, 0
_080FB2F0: .4byte 0x00000DCC
_080FB2F4:
	cmp r0, #2
	beq _080FB31A
	cmp r0, #3
	beq _080FB32E
	b _080FB344
_080FB2FE:
	movs r0, #0x3c
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB308:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #0
	bne _080FB344
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FB344
_080FB31A:
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r4, #0x14]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB32E:
	ldr r0, [r4, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB344
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
_080FB344:
	movs r0, #0
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fefnir_minigame_080fb354
fefnir_minigame_080fb354: @ 0x080FB354
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r1, _080FB448 @ =0x00000DCC
	adds r6, r0, r1
	ldr r2, _080FB44C @ =gJoypad
	ldrh r1, [r2]
	strh r1, [r6, #0x18]
	ldrh r1, [r2, #4]
	strh r1, [r6, #0x1a]
	movs r7, #0
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r2, r2, r0
	mov sb, r2
	movs r3, #0
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #3
_080FB380:
	ldr r0, [r1]
	cmp r0, #0
	beq _080FB390
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB390
	str r3, [r1]
	movs r7, #1
_080FB390:
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080FB380
	cmp r7, #0
	beq _080FB3B2
	adds r2, r6, #0
	adds r2, #0x2f
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	strb r1, [r6, #1]
	strb r1, [r6, #2]
	strb r1, [r6, #3]
_080FB3B2:
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _080FB472
	ldr r0, _080FB450 @ =RNG_0202f388
	mov ip, r0
	ldr r0, [r0]
	ldr r3, _080FB454 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r2, _080FB458 @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r4, r1, #1
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	lsrs r0, r0, #3
	subs r0, #0x30
	subs r1, r1, r0
	mov r0, r8
	strb r1, [r0]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, ip
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #3
	ands r2, r0
	adds r7, r2, #0
	adds r0, r2, #4
	cmp r2, r0
	bge _080FB468
	mov r4, ip
_080FB406:
	adds r0, r2, #0
	cmp r2, #0
	bge _080FB40E
	adds r0, r2, #3
_080FB40E:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r2, r0
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	cmp r3, #0
	beq _080FB460
	ldr r1, [r4]
	ldr r0, _080FB454 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080FB458 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	ldr r2, _080FB45C @ =0x0026E800
	movs r3, #0xe0
	lsls r3, r3, #9
	bl FUN_08071470
	b _080FB468
	.align 2, 0
_080FB448: .4byte 0x00000DCC
_080FB44C: .4byte gJoypad
_080FB450: .4byte RNG_0202f388
_080FB454: .4byte 0x000343FD
_080FB458: .4byte 0x00269EC3
_080FB45C: .4byte 0x0026E800
_080FB460:
	adds r2, #1
	adds r0, r7, #4
	cmp r2, r0
	blt _080FB406
_080FB468:
	ldrb r0, [r5]
	cmp r0, #0xfe
	bhi _080FB472
	adds r0, #1
	strb r0, [r5]
_080FB472:
	mov r2, r8
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r0, #1
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fefnir_minigame_080fb48c
fefnir_minigame_080fb48c: @ 0x080FB48C
	push {r4, lr}
	ldr r1, _080FB4A8 @ =0x00000DCC
	adds r4, r0, r1
	movs r0, #0
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _080FB528
	lsls r0, r0, #2
	ldr r1, _080FB4AC @ =_080FB4B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FB4A8: .4byte 0x00000DCC
_080FB4AC: .4byte _080FB4B0
_080FB4B0: @ jump table
	.4byte _080FB4C8 @ case 0
	.4byte _080FB4D8 @ case 1
	.4byte _080FB4E4 @ case 2
	.4byte _080FB4F2 @ case 3
	.4byte _080FB502 @ case 4
	.4byte _080FB50E @ case 5
_080FB4C8:
	movs r0, #0xbd
	bl fadeoutBGM
	movs r0, #0x3c
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB4D8:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #0
	bne _080FB528
	b _080FB4FA
_080FB4E4:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r4, #0x14]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB4F2:
	ldr r0, [r4, #0x14]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FB528
_080FB4FA:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FB528
_080FB502:
	ldr r1, _080FB524 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FB50E:
	ldr r0, [r4, #0x1c]
	subs r0, #1
	str r0, [r4, #0x1c]
	ldr r0, _080FB524 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FB528
	movs r0, #0
	b _080FB52A
	.align 2, 0
_080FB524: .4byte gGameState
_080FB528:
	movs r0, #1
_080FB52A:
	pop {r4}
	pop {r1}
	bx r1

