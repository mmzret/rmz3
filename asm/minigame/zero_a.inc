	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initZeroMinigame
initZeroMinigame: @ 0x080F91E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r7, _080F9384 @ =0x00000DCC
	add r7, sl
	ldr r1, _080F9388 @ =0x00000DC4
	add r1, sl
	ldr r0, _080F938C @ =0x002E6800
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #3
	bl ResetLandscape
	ldr r4, _080F9390 @ =0x0000058C
	ldr r1, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r1, #0x8e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080F939C @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r6, _080F93A0 @ =wStaticMotionPalIDs
	adds r0, r6, #0
	adds r0, #0x8e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0x9e
	lsls r5, r4, #1
	ldr r1, _080F9398 @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xe1
	lsls r1, r1, #2
	strh r1, [r0]
	adds r5, r6, r5
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r4, r4, r2
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xf0
	ldr r0, _080F9398 @ =wStaticGraphicTilenums
	strh r1, [r0]
	movs r0, #0xe
	strh r0, [r6]
	ldr r2, _080F9394 @ =gStaticMotionGraphics
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r2, #0
	bl LoadGraphic
	ldrh r1, [r6]
	mov r2, r8
	ldrb r0, [r2, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	mov r0, r8
	bl LoadPalette
	ldr r0, _080F938C @ =0x002E6800
	str r0, [sp, #4]
	movs r0, #0xb4
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreateZeroMini
	str r0, [r7, #0x14]
	ldr r1, _080F93A4 @ =pZero2
	str r0, [r1]
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080F92E2:
	adds r4, r1, #1
	ldr r0, _080F93A8 @ =0x002ED800
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
	movs r2, #0
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r5, r5, r1
	adds r1, r4, #0
	cmp r1, #2
	ble _080F92E2
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	movs r5, #0
	strh r4, [r7]
	movs r0, #0x60
	mov r2, sl
	strh r0, [r2, #6]
	ldr r1, _080F93AC @ =gGameState
	ldr r0, _080F93B0 @ =0x0000626C
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _080F93B4 @ =0x41C64E6D
	muls r0, r2, r0
	ldr r2, _080F93B8 @ =0x00003039
	adds r0, r0, r2
	str r0, [r1]
	lsrs r0, r0, #0x10
	movs r1, #6
	bl __umodsi3
	mov r1, sl
	strh r0, [r1, #8]
	strh r4, [r1, #0xa]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	strh r4, [r7, #8]
	strh r4, [r7, #0xa]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	str r4, [r7, #0x30]
	str r4, [r7, #0x2c]
	strh r4, [r7, #0x38]
	movs r0, #0xe0
	lsls r0, r0, #1
	str r0, [r7, #0x34]
	strb r5, [r7, #0xd]
	strh r4, [r7, #0xe]
	str r4, [r7, #0x20]
	str r4, [r7, #0x24]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	strh r4, [r1, #4]
	ldr r0, _080F93BC @ =gSystemSavedata
	ldr r0, [r0, #0x24]
	str r0, [r7, #0x3c]
	strh r4, [r7, #0x3a]
	movs r0, #0xad
	bl PlayBGM
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F9384: .4byte 0x00000DCC
_080F9388: .4byte 0x00000DC4
_080F938C: .4byte 0x002E6800
_080F9390: .4byte 0x0000058C
_080F9394: .4byte gStaticMotionGraphics
_080F9398: .4byte wStaticGraphicTilenums
_080F939C: .4byte gStaticMotionGraphics+12
_080F93A0: .4byte wStaticMotionPalIDs
_080F93A4: .4byte pZero2
_080F93A8: .4byte 0x002ED800
_080F93AC: .4byte gGameState
_080F93B0: .4byte 0x0000626C
_080F93B4: .4byte 0x41C64E6D
_080F93B8: .4byte 0x00003039
_080F93BC: .4byte gSystemSavedata
