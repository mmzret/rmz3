	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initPhantomMinigame
initPhantomMinigame: @ 0x080FBE20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r0, _080FC058 @ =0x00000DCC
	adds r7, r4, r0
	ldr r2, _080FC05C @ =0x00000DC4
	adds r1, r4, r2
	ldr r0, _080FC060 @ =0x0009D800
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #0xb
	str r0, [r1, #4]
	movs r0, #6
	bl ResetLandscape
	movs r2, #0
	str r2, [r7, #0x14]
	str r2, [r7, #4]
	movs r5, #0xa0
	lsls r5, r5, #7
	str r5, [r7, #0x1c]
	movs r3, #0xa0
	lsls r3, r3, #8
	str r3, [r7, #0x20]
	movs r0, #0xea
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	str r5, [r7, #0x24]
	str r3, [r7, #0x28]
	ldr r0, [r7, #8]
	ldr r0, [r0, #0x58]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r7, #0x18]
	movs r3, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r7, #0x2c]
	str r2, [r7, #0x34]
	str r2, [r7, #0x38]
	ldr r0, _080FC064 @ =gSystemSavedata
	ldr r0, [r0, #0x3c]
	str r0, [r7, #0x3c]
	str r2, [r7, #0x30]
	ldr r0, _080FC068 @ =0x00000EA1
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	strb r3, [r7]
	strb r3, [r7, #1]
	strb r3, [r7, #2]
	strb r3, [r7, #3]
	ldr r1, _080FC06C @ =0x00000EA2
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	subs r1, #0x1b
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	str r2, [r0]
	mov r8, r2
	mov sb, r2
	movs r0, #0xe7
	lsls r0, r0, #4
	adds r6, r4, r0
	subs r1, #0x8c
	adds r5, r4, r1
_080FBED2:
	mov r2, r8
	lsls r4, r2, #3
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #0xa0
	lsls r3, r3, #2
	bl CreatePhantomIcon
	adds r1, r7, #0
	adds r1, #0xa4
	adds r1, r1, r4
	movs r0, #0xdc
	lsls r0, r0, #8
	mov r2, sb
	subs r0, r0, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xa8
	adds r0, r0, r4
	movs r1, #0x8e
	lsls r1, r1, #8
	str r1, [r0]
	ldrb r1, [r5, #0x11]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0x60
	orrs r0, r1
	movs r2, #0xd
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	strb r0, [r5, #0x11]
	movs r0, #0x90
	lsls r0, r0, #5
	add sb, r0
	adds r6, #8
	adds r5, #0x20
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #2
	ble _080FBED2
	ldr r6, _080FC070 @ =gStaticMotionGraphics
	ldr r0, _080FC074 @ =wStaticGraphicTilenums
	mov sb, r0
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
	ldr r0, _080FC078 @ =gStaticMotionGraphics+12
	mov sl, r0
	ldr r1, _080FC07C @ =wStaticMotionPalIDs
	mov r8, r1
	ldrh r1, [r1]
	ldrb r0, [r0, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, sl
	bl LoadPalette
	ldr r5, _080FC080 @ =0x00000A78
	adds r0, r5, r6
	movs r4, #0x86
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
	add r5, sl
	add r4, r8
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadPalette
	movs r4, #0xe1
	lsls r4, r4, #2
	adds r0, r4, r6
	mov r1, sb
	adds r1, #0x5a
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, sl
	mov r0, r8
	adds r0, #0x5a
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc8
	lsls r4, r4, #4
	adds r6, r4, r6
	movs r5, #0xa0
	lsls r5, r5, #1
	add sb, r5
	mov r2, sb
	ldrh r1, [r2]
	ldrh r0, [r6, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r6, #0
	bl LoadGraphic
	add r4, sl
	add r8, r5
	mov r2, r8
	ldrh r1, [r2]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080FC060 @ =0x0009D800
	movs r2, #0xbe
	lsls r2, r2, #0xb
	adds r0, r7, #0
	adds r1, r4, #0
	bl CreatePlayerPhantom
	str r0, [r7, #8]
	movs r2, #0xbf
	lsls r2, r2, #0xb
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080d915c
	ldr r0, [r7, #8]
	ldr r1, [r0, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r1, r1, r2
	ldr r2, [r0, #0x58]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r2, r2, r0
	adds r0, r7, #0
	movs r3, #0
	bl FUN_080d91b4
	movs r0, #0xa8
	bl PlayBGM
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FC058: .4byte 0x00000DCC
_080FC05C: .4byte 0x00000DC4
_080FC060: .4byte 0x0009D800
_080FC064: .4byte gSystemSavedata
_080FC068: .4byte 0x00000EA1
_080FC06C: .4byte 0x00000EA2
_080FC070: .4byte gStaticMotionGraphics
_080FC074: .4byte wStaticGraphicTilenums
_080FC078: .4byte gStaticMotionGraphics+12
_080FC07C: .4byte wStaticMotionPalIDs
_080FC080: .4byte 0x00000A78
