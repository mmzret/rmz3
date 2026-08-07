	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start phantom_08060244
phantom_08060244: @ 0x08060244
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x1b
	bls _08060250
	b _080603AC
_08060250:
	lsls r0, r0, #2
	ldr r1, _0806025C @ =_08060260
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806025C: .4byte _08060260
_08060260: @ jump table
	.4byte _080602D0 @ case 0
	.4byte _080603AC @ case 1
	.4byte _080603AC @ case 2
	.4byte _080603AC @ case 3
	.4byte _080603AC @ case 4
	.4byte _080603AC @ case 5
	.4byte _080603AC @ case 6
	.4byte _080603AC @ case 7
	.4byte _080603AC @ case 8
	.4byte _080603AC @ case 9
	.4byte _080603AC @ case 10
	.4byte _080603AC @ case 11
	.4byte _080603AC @ case 12
	.4byte _080603AC @ case 13
	.4byte _080603AC @ case 14
	.4byte _080603AC @ case 15
	.4byte _080603AC @ case 16
	.4byte _080603AC @ case 17
	.4byte _080603AC @ case 18
	.4byte _080603AC @ case 19
	.4byte _080602E4 @ case 20
	.4byte _080602F2 @ case 21
	.4byte _08060300 @ case 22
	.4byte _0806034C @ case 23
	.4byte _08060368 @ case 24
	.4byte _0806037A @ case 25
	.4byte _0806038E @ case 26
	.4byte _0806039C @ case 27
_080602D0:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _080603AC
_080602E4:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080602F2:
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080603AC
	b _08060386
_08060300:
	movs r0, #0xfa
	bl PlaySound
	movs r4, #0xbe
	lsls r4, r4, #1
	ldr r1, _08060358 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _0806035C @ =wStaticGraphicTilenums
	ldrh r1, [r1, #0x26]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08060360 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _08060364 @ =wStaticMotionPalIDs
	ldrh r1, [r0, #0x26]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806034C:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080603AC
	b _08060386
	.align 2, 0
_08060358: .4byte gStaticMotionGraphics
_0806035C: .4byte wStaticGraphicTilenums
_08060360: .4byte gStaticMotionGraphics+12
_08060364: .4byte wStaticMotionPalIDs
_08060368:
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080607a0
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806037A:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080603AC
_08060386:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080603AC
_0806038E:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080607a0
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806039C:
	ldr r0, _080603B4 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080603AC
	strb r1, [r5, #0xd]
	strh r1, [r5, #0xe]
_080603AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080603B4: .4byte gStageRun

