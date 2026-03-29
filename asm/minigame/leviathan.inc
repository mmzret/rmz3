	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start leviathan_minigame_080fb594
leviathan_minigame_080fb594: @ 0x080FB594
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080FB5D4 @ =0x00000DCC
	adds r4, r4, r0
	ldr r0, _080FB5D8 @ =0x0810E2AC
	movs r1, #0xa
	movs r2, #0x13
	bl PrintUnicodeString
	ldr r0, [r4, #0x20]
	movs r1, #0x3c
	bl __divsi3
	movs r1, #0x3c
	bl __modsi3
	movs r1, #0x12
	movs r2, #0x13
	bl PrintMinigameNumber
	ldr r0, [r4, #0x20]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl __divsi3
	movs r1, #0xf
	movs r2, #0x13
	bl PrintMinigameNumber
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FB5D4: .4byte 0x00000DCC
_080FB5D8: .4byte 0x0810E2AC

	thumb_func_start leviathan_minigame_080fb5dc
leviathan_minigame_080fb5dc: @ 0x080FB5DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080FB658 @ =0x00000DCC
	adds r7, r0, r1
	ldrh r0, [r7, #0x16]
	subs r0, #1
	strh r0, [r7, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB64E
	ldrh r0, [r7, #0x14]
	strh r0, [r7, #0x16]
	ldr r4, _080FB65C @ =RNG_0202f388
	mov r8, r4
	ldr r0, [r4]
	ldr r5, _080FB660 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _080FB664 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r6, r0, #1
	mov r1, r8
	str r6, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	adds r2, r6, #0
	muls r2, r5, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r3, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	ldr r6, _080FB668 @ =0x08386BB0
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r4, r8
	str r3, [r4]
	lsrs r0, r0, #0x11
	movs r3, #0xf
	ands r0, r3
	adds r0, r0, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	bl FUN_08099fb8
_080FB64E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB658: .4byte 0x00000DCC
_080FB65C: .4byte RNG_0202f388
_080FB660: .4byte 0x000343FD
_080FB664: .4byte 0x00269EC3
_080FB668: .4byte 0x08386BB0

	thumb_func_start leviathan_minigame_080fb66c
leviathan_minigame_080fb66c: @ 0x080FB66C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	ldr r0, _080FB6DC @ =0x00000DCC
	adds r7, r1, r0
	ldrh r0, [r7, #0x16]
	subs r0, #1
	strh r0, [r7, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB74A
	ldrh r0, [r7, #0x14]
	strh r0, [r7, #0x16]
	ldr r4, _080FB6E0 @ =0x00000DFE
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #8
	bls _080FB6F4
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080FB6E4 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB6E8 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB6EC @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #6
	bl __umodsi3
	adds r1, r0, #0
	ldr r0, _080FB6F0 @ =0x00042400
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08099fb8
	b _080FB74A
	.align 2, 0
_080FB6DC: .4byte 0x00000DCC
_080FB6E0: .4byte 0x00000DFE
_080FB6E4: .4byte RNG_0202f388
_080FB6E8: .4byte 0x000343FD
_080FB6EC: .4byte 0x00269EC3
_080FB6F0: .4byte 0x00042400
_080FB6F4:
	ldr r1, _080FB7AC @ =RNG_0202f388
	mov r8, r1
	ldr r0, [r1]
	ldr r5, _080FB7B0 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _080FB7B4 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r6, r0, #1
	str r6, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	adds r2, r6, #0
	muls r2, r5, r2
	adds r2, r2, r4
	lsls r2, r2, #1
	lsrs r3, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	ldr r6, _080FB7B8 @ =0x08386BC0
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r4, r8
	str r3, [r4]
	lsrs r0, r0, #0x11
	movs r3, #0xf
	ands r0, r3
	adds r0, r0, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	bl FUN_08099fb8
_080FB74A:
	ldrh r0, [r7, #0x1a]
	subs r0, #1
	strh r0, [r7, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080FB804
	ldrh r0, [r7, #0x18]
	strh r0, [r7, #0x1a]
	adds r1, r7, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #8
	bls _080FB7C0
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080FB7AC @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB7B0 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB7B4 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #6
	bl __umodsi3
	adds r1, r0, #0
	ldr r0, _080FB7BC @ =0x00042400
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08099fb8
	b _080FB804
	.align 2, 0
_080FB7AC: .4byte RNG_0202f388
_080FB7B0: .4byte 0x000343FD
_080FB7B4: .4byte 0x00269EC3
_080FB7B8: .4byte 0x08386BC0
_080FB7BC: .4byte 0x00042400
_080FB7C0:
	ldr r4, _080FB810 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080FB814 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080FB818 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r1, r0, #0
	movs r0, #0xfc
	lsls r0, r0, #0xa
	adds r1, r1, r0
	mov r2, r8
	muls r2, r5, r2
	adds r2, r2, r6
	lsls r2, r2, #1
	lsrs r0, r2, #1
	str r0, [r4]
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	adds r0, r7, #0
	movs r3, #0
	bl FUN_08099fb8
_080FB804:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FB810: .4byte RNG_0202f388
_080FB814: .4byte 0x000343FD
_080FB818: .4byte 0x00269EC3

	thumb_func_start initLeviathanMinigame
initLeviathanMinigame: @ 0x080FB81C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _080FBAC8 @ =0x00000DCC
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _080FBACC @ =0x00000DC4
	adds r1, r7, r2
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #0xb
	str r0, [r1, #4]
	movs r0, #9
	bl ResetLandscape
	ldr r1, _080FBAD0 @ =gStaticMotionGraphics
	mov sl, r1
	ldr r2, _080FBAD4 @ =wStaticGraphicTilenums
	ldrh r1, [r2]
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sl
	bl LoadGraphic
	ldr r1, _080FBAD8 @ =wStaticMotionPalIDs
	mov sb, r1
	ldrh r1, [r1]
	ldr r2, _080FBADC @ =gStaticMotionGraphics+12
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadPalette
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r1, #0x6a
	ldr r0, _080FBAE0 @ =0x00000167
	strh r0, [r1]
	mov r5, sb
	adds r5, #0x6a
	movs r2, #0
	strh r2, [r5]
	ldr r4, _080FBAE4 @ =0x00000424
	mov r2, sl
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, _080FBAE8 @ =0x00000195
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	strh r0, [r1, #0x30]
	movs r0, #2
	mov r2, sb
	strh r0, [r2, #0x30]
	movs r6, #0xf0
	lsls r6, r6, #1
	mov r1, sl
	adds r0, r6, r1
	ldr r2, _080FBAD4 @ =wStaticGraphicTilenums
	ldrh r1, [r2, #0x30]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r1, _080FBADC @ =gStaticMotionGraphics+12
	adds r0, r6, r1
	mov r2, sb
	ldrh r1, [r2, #0x30]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
	movs r4, #0xef
	lsls r5, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	add r5, sb
	movs r2, #0
	strh r2, [r5]
	lsls r4, r4, #4
	movs r0, #0xef
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, sl
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r0, _080FBAD4 @ =wStaticGraphicTilenums
	adds r1, r0, r6
	ldr r0, _080FBAEC @ =0x000002A7
	strh r0, [r1]
	add r6, sb
	movs r2, #2
	strh r2, [r6]
	movs r4, #0x96
	lsls r4, r4, #5
	mov r2, sl
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf1
	lsls r5, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xb6
	lsls r1, r1, #2
	strh r1, [r0]
	add r5, sb
	movs r2, #2
	strh r2, [r5]
	lsls r4, r4, #4
	movs r0, #0xf1
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, sl
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf2
	lsls r0, r4, #1
	ldr r1, _080FBAD4 @ =wStaticGraphicTilenums
	adds r2, r1, r0
	movs r1, #0xbb
	lsls r1, r1, #2
	strh r1, [r2]
	add sb, r0
	movs r0, #5
	mov r2, sb
	strh r0, [r2]
	lsls r4, r4, #4
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r4, r4, r0
	add sl, r4
	mov r2, sl
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sl
	bl LoadGraphic
	ldr r1, _080FBADC @ =gStaticMotionGraphics+12
	adds r4, r4, r1
	mov r2, sb
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r2, #0xf7
	lsls r2, r2, #0xa
	mov r0, r8
	movs r1, #0xb4
	lsls r1, r1, #9
	bl CreatePlayerLeviathan
	mov r1, r8
	str r0, [r1, #4]
	ldr r2, _080FBAF0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FBAF4 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080FBAF8 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	mov r0, r8
	bl FUN_0809a02c
	mov r1, r8
	str r0, [r1, #0xc]
	movs r0, #0x3c
	strh r0, [r1, #0x14]
	strh r0, [r1, #0x16]
	movs r0, #0xb4
	strh r0, [r1, #0x18]
	strh r0, [r1, #0x1a]
	movs r0, #0xe1
	lsls r0, r0, #3
	str r0, [r1, #0x20]
	ldr r2, _080FBAFC @ =0x00000DFD
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, r8
	str r2, [r0, #0x1c]
	ldr r1, _080FBB00 @ =0x00000E01
	adds r0, r7, r1
	strb r2, [r0]
	subs r1, #3
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	movs r2, #0
	mov r0, r8
	str r2, [r0, #0x24]
	str r2, [r0, #0x28]
	ldr r0, _080FBB04 @ =gSystemSavedataManager
	ldr r0, [r0, #0x38]
	mov r1, r8
	str r0, [r1, #0x2c]
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	ldr r1, _080FBB08 @ =0x00000DFC
	adds r0, r7, r1
	strb r2, [r0]
	movs r0, #0xb6
	bl playBGM
	movs r0, #0x32
	bl PlaySound
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FBAC8: .4byte 0x00000DCC
_080FBACC: .4byte 0x00000DC4
_080FBAD0: .4byte gStaticMotionGraphics
_080FBAD4: .4byte wStaticGraphicTilenums
_080FBAD8: .4byte wStaticMotionPalIDs
_080FBADC: .4byte gStaticMotionGraphics+12
_080FBAE0: .4byte 0x00000167
_080FBAE4: .4byte 0x00000424
_080FBAE8: .4byte 0x00000195
_080FBAEC: .4byte 0x000002A7
_080FBAF0: .4byte RNG_0202f388
_080FBAF4: .4byte 0x000343FD
_080FBAF8: .4byte 0x00269EC3
_080FBAFC: .4byte 0x00000DFD
_080FBB00: .4byte 0x00000E01
_080FBB04: .4byte gSystemSavedataManager
_080FBB08: .4byte 0x00000DFC

	thumb_func_start leviathanMinigame
leviathanMinigame: @ 0x080FBB0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080FBB38 @ =0x00000DCC
	adds r4, r5, r0
	ldr r0, _080FBB3C @ =0x08386BA4
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	adds r0, r5, #0
	bl leviathan_minigame_080fb594
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bge _080FBB40
	movs r0, #0
	str r0, [r4, #0x24]
	b _080FBB48
	.align 2, 0
_080FBB38: .4byte 0x00000DCC
_080FBB3C: .4byte 0x08386BA4
_080FBB40:
	ldr r1, _080FBB68 @ =0x0001869F
	cmp r0, r1
	ble _080FBB48
	str r1, [r4, #0x24]
_080FBB48:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x2c]
	cmp r1, r0
	ble _080FBB7C
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0
	bne _080FBB6C
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #1
	bl PlaySound
	b _080FBB72
	.align 2, 0
_080FBB68: .4byte 0x0001869F
_080FBB6C:
	ldr r0, _080FBB78 @ =0x00000137
	bl PlaySound
_080FBB72:
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x2c]
	b _080FBB88
	.align 2, 0
_080FBB78: .4byte 0x00000137
_080FBB7C:
	ldr r0, [r4, #0x28]
	cmp r0, r1
	beq _080FBB88
	ldr r0, _080FBB9C @ =0x00000137
	bl PlaySound
_080FBB88:
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	adds r0, r5, #0
	bl MinigameLeviathan_DrawScoreHiscore
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080FBB9C: .4byte 0x00000137

	thumb_func_start leviathan_minigame_080fbba0
leviathan_minigame_080fbba0: @ 0x080FBBA0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080FBBB8 @ =0x00000DCC
	adds r4, r5, r0
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _080FBBD4
	cmp r0, #1
	bgt _080FBBBC
	cmp r0, #0
	beq _080FBBC6
	b _080FBC1A
	.align 2, 0
_080FBBB8: .4byte 0x00000DCC
_080FBBBC:
	cmp r0, #2
	beq _080FBBF0
	cmp r0, #3
	beq _080FBC04
	b _080FBC1A
_080FBBC6:
	ldr r0, _080FBBEC @ =0x00000DFF
	adds r1, r5, r0
	movs r0, #0x3c
	strb r0, [r1]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBBD4:
	adds r1, r4, #0
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080FBC1A
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FBC1A
	.align 2, 0
_080FBBEC: .4byte 0x00000DFF
_080FBBF0:
	movs r0, #0x1d
	bl PlaySound
	movs r0, #0
	bl CreateMissionAlert
	str r0, [r4, #8]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBC04:
	ldr r0, [r4, #8]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBC1A
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
_080FBC1A:
	movs r0, #0
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	adds r0, r5, #0
	bl leviathan_minigame_080fb5dc
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start leviathan_minigame_080fbc30
leviathan_minigame_080fbc30: @ 0x080FBC30
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080FBC54 @ =0x00000DCC
	adds r4, r5, r0
	ldr r0, _080FBC58 @ =gJoypad
	ldrh r1, [r0]
	strh r1, [r4, #0x10]
	ldrh r0, [r0, #4]
	strh r0, [r4, #0x12]
	ldr r0, _080FBC5C @ =0x00000DFD
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FBC60
	subs r0, #1
	strb r0, [r1]
	b _080FBC92
	.align 2, 0
_080FBC54: .4byte 0x00000DCC
_080FBC58: .4byte gJoypad
_080FBC5C: .4byte 0x00000DFD
_080FBC60:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _080FBC6C
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBC8C
_080FBC6C:
	ldr r2, _080FBCCC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080FBCD0 @ =0x000343FD
	muls r1, r0, r1
	ldr r0, _080FBCD4 @ =0x00269EC3
	adds r1, r1, r0
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r2]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809a02c
	str r0, [r4, #0xc]
_080FBC8C:
	adds r0, r5, #0
	bl leviathan_minigame_080fb66c
_080FBC92:
	ldr r0, [r4, #0x20]
	ldr r1, _080FBCD8 @ =0x00002A30
	cmp r0, r1
	ble _080FBC9C
	str r1, [r4, #0x20]
_080FBC9C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _080FBCAA
	subs r0, #1
	str r0, [r4, #0x20]
	cmp r0, #0
	bgt _080FBCC2
_080FBCAA:
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x34
	movs r0, #1
	strb r0, [r2]
	str r1, [r4, #0x20]
_080FBCC2:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080FBCCC: .4byte RNG_0202f388
_080FBCD0: .4byte 0x000343FD
_080FBCD4: .4byte 0x00269EC3
_080FBCD8: .4byte 0x00002A30

	thumb_func_start leviathan_minigame_080fbcdc
leviathan_minigame_080fbcdc: @ 0x080FBCDC
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _080FBD20 @ =0x00000DCC
	adds r4, r1, r0
	movs r5, #0
	strh r5, [r4, #0x10]
	strh r5, [r4, #0x12]
	adds r0, #0x31
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080FBCF8
	subs r0, #1
	strb r0, [r2]
_080FBCF8:
	adds r0, r1, #0
	bl leviathan_minigame_080fb5dc
	ldr r0, [r4, #0x20]
	ldr r1, _080FBD24 @ =0x00002A30
	cmp r0, r1
	ble _080FBD08
	str r1, [r4, #0x20]
_080FBD08:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bgt _080FBD10
	str r5, [r4, #0x20]
_080FBD10:
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _080FBDB4
	lsls r0, r0, #2
	ldr r1, _080FBD28 @ =_080FBD2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080FBD20: .4byte 0x00000DCC
_080FBD24: .4byte 0x00002A30
_080FBD28: .4byte _080FBD2C
_080FBD2C: @ jump table
	.4byte _080FBD44 @ case 0
	.4byte _080FBD5E @ case 1
	.4byte _080FBD70 @ case 2
	.4byte _080FBD7E @ case 3
	.4byte _080FBD8E @ case 4
	.4byte _080FBD9A @ case 5
_080FBD44:
	movs r0, #0xb6
	bl fadeoutBGM
	movs r0, #0xf6
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x33
	movs r0, #0x3c
	strb r0, [r1]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD5E:
	adds r1, r4, #0
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080FBDB4
	b _080FBD86
_080FBD70:
	movs r0, #4
	bl CreateMissionAlert
	str r0, [r4, #8]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD7E:
	ldr r0, [r4, #8]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080FBDB4
_080FBD86:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	b _080FBDB4
_080FBD8E:
	ldr r1, _080FBDB0 @ =gGameState
	movs r0, #0x40
	strh r0, [r1, #4]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_080FBD9A:
	ldr r0, _080FBDB0 @ =gGameState
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0x20
	bne _080FBDB4
	movs r0, #0x32
	bl stopSound
	movs r0, #0
	b _080FBDB6
	.align 2, 0
_080FBDB0: .4byte gGameState
_080FBDB4:
	movs r0, #1
_080FBDB6:
	pop {r4, r5}
	pop {r1}
	bx r1
