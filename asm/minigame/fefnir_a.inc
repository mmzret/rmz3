	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	ldr r0, _080FB244 @ =gSystemSavedata
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
	bl PlayBGM
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
_080FB244: .4byte gSystemSavedata
_080FB248: .4byte 0x00000DF8
_080FB24C: .4byte 0x00000DFB
