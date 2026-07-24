	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initHarpuiaMinigame
initHarpuiaMinigame: @ 0x080FA8B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r7, _080FAAC4 @ =0x00000DCC
	add r7, sl
	ldr r1, _080FAAC8 @ =0x00000DC4
	add r1, sl
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [r1, #4]
	movs r0, #0xa
	bl ResetLandscape
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r1, #0x8e
	movs r0, #0
	strh r0, [r1]
	ldr r5, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, #0x8e
	movs r0, #7
	strh r0, [r5]
	ldr r4, _080FAAD4 @ =0x0000058C
	ldr r1, _080FAAD8 @ =gStaticMotionGraphics
	mov r8, r1
	adds r0, r4, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	rsbs r1, r1, #0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r6, _080FAADC @ =gStaticMotionGraphics+12
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	mov sb, r0
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf3
	lsls r5, r4, #1
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xc8
	strh r1, [r0]
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, r2, r5
	movs r0, #8
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, r8
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xa1
	lsls r5, r4, #1
	ldr r1, _080FAACC @ =wStaticGraphicTilenums
	adds r0, r1, r5
	movs r1, #0xf0
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	adds r5, r2, r5
	movs r0, #9
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r4, r4, r0
	mov r2, r8
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	adds r4, r4, r6
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	ldr r5, _080FAAE0 @ =0x00000D48
	mov r1, r8
	adds r0, r5, r1
	movs r4, #0xaa
	lsls r4, r4, #1
	ldr r2, _080FAACC @ =wStaticGraphicTilenums
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
	adds r5, r5, r6
	ldr r0, _080FAAD0 @ =wStaticMotionPalIDs
	adds r4, r0, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r5, #0
	bl LoadPalette
	movs r1, #0xf0
	ldr r2, _080FAACC @ =wStaticGraphicTilenums
	strh r1, [r2]
	movs r0, #0xe
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	strh r0, [r2]
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
	ldr r2, _080FAAD0 @ =wStaticMotionPalIDs
	ldrh r1, [r2]
	ldrb r0, [r6, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r6, #0
	bl LoadPalette
	movs r0, #0x96
	lsls r0, r0, #9
	str r0, [sp, #4]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #4
	movs r2, #0
	bl CreatePlayerHarpuia
	str r0, [r7, #0x14]
	ldr r1, _080FAAE4 @ =pZero2
	str r0, [r1]
	movs r1, #0
	add r6, sp, #4
	movs r5, #0x80
	lsls r5, r5, #5
_080FAA3A:
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
	movs r2, #3
	adds r3, r7, #0
	adds r3, #0xc
	bl FUN_080c82b8
	mov r1, sl
	str r1, [r0, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r5, r5, r2
	adds r1, r4, #0
	cmp r1, #2
	ble _080FAA3A
	movs r4, #0
	movs r0, #3
	strb r0, [r7, #0xc]
	movs r1, #0
	strh r4, [r7]
	movs r0, #0x78
	mov r2, sl
	strh r0, [r2, #6]
	strh r4, [r2, #8]
	strh r4, [r2, #0xa]
	strh r4, [r7, #4]
	strh r4, [r7, #6]
	str r4, [r7, #0x18]
	str r4, [r7, #0x1c]
	str r4, [r7, #0x30]
	str r4, [r7, #0x2c]
	strh r4, [r7, #0xe]
	strh r4, [r7, #0x38]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r7, #0x34]
	strb r1, [r7, #0xd]
	str r4, [r7, #0x20]
	str r4, [r7, #0x24]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	ldr r0, _080FAAE8 @ =gSystemSavedata
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x3c]
	strh r4, [r7, #0x3a]
	movs r0, #0xb7
	bl PlayBGM
	mov r0, sl
	strh r4, [r0, #4]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FAAC4: .4byte 0x00000DCC
_080FAAC8: .4byte 0x00000DC4
_080FAACC: .4byte wStaticGraphicTilenums
_080FAAD0: .4byte wStaticMotionPalIDs
_080FAAD4: .4byte 0x0000058C
_080FAAD8: .4byte gStaticMotionGraphics
_080FAADC: .4byte gStaticMotionGraphics+12
_080FAAE0: .4byte 0x00000D48
_080FAAE4: .4byte pZero2
_080FAAE8: .4byte gSystemSavedata
