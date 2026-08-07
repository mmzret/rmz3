	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Hanumachine_Init
Hanumachine_Init: @ 0x0805B94C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, _0805BA3C @ =0x00000848
	ldr r1, _0805BA40 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _0805BA44 @ =wStaticGraphicTilenums
	adds r1, #0xd4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805BA48 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _0805BA4C @ =wStaticMotionPalIDs
	adds r0, #0xd4
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb5
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xbd
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _0805BA50 @ =sCollisions
	adds r0, r6, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _0805BA54 @ =FUN_0805d568
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_0800a134
	adds r4, r0, #0
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a31c
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	ldr r0, [r6, #0x54]
	adds r1, r4, #0
	bl FUN_0800a22c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	str r5, [r0]
	ldr r1, _0805BA58 @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r5, [r6, #0xd]
	adds r0, r6, #0
	bl Hanumachine_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805BA3C: .4byte 0x00000848
_0805BA40: .4byte gStaticMotionGraphics
_0805BA44: .4byte wStaticGraphicTilenums
_0805BA48: .4byte gStaticMotionGraphics+12
_0805BA4C: .4byte wStaticMotionPalIDs
_0805BA50: .4byte sCollisions
_0805BA54: .4byte FUN_0805d568
_0805BA58: .4byte gBossFnTable

