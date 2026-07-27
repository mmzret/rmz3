	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start BeeServer_Init
BeeServer_Init: @ 0x0804CE68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _0804CEBC @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _0804CEC0 @ =sBeeServerInitModes
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldr r0, _0804CEC4 @ =gSystemSavedata
	ldrb r1, [r0, #0x16]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804CECC
	ldr r1, _0804CEC8 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x30
	bl ResetBossBody
	b _0804CED6
	.align 2, 0
_0804CEBC: .4byte gBossFnTable
_0804CEC0: .4byte sBeeServerInitModes
_0804CEC4: .4byte gSystemSavedata
_0804CEC8: .4byte sCollisions
_0804CECC:
	ldr r1, _0804CFB8 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x20
	bl ResetBossBody
_0804CED6:
	ldr r1, _0804CFBC @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	movs r1, #0
	str r1, [r0]
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r7, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r7, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #0xe0
	lsls r0, r0, #6
	adds r1, r1, r0
	str r1, [r7, #0x58]
	movs r4, #0xaf
	lsls r4, r4, #3
	ldr r1, _0804CFC0 @ =gStaticMotionGraphics
	mov r8, r1
	adds r0, r4, r1
	ldr r6, _0804CFC4 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x8c
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0804CFC8 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _0804CFCC @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x8c
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
	ldr r4, _0804CFD0 @ =0x0000058C
	add r8, r4
	adds r6, #0x8e
	ldrh r1, [r6]
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
	add r4, sl
	adds r5, #0x8e
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x54]
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, r7, #0
	bl BeeServer_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804CFB8: .4byte sCollisions
_0804CFBC: .4byte onCollision
_0804CFC0: .4byte gStaticMotionGraphics
_0804CFC4: .4byte wStaticGraphicTilenums
_0804CFC8: .4byte gStaticMotionGraphics+12
_0804CFCC: .4byte wStaticMotionPalIDs
_0804CFD0: .4byte 0x0000058C

	thumb_func_start BeeServer_Update
BeeServer_Update: @ 0x0804CFD4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0804CFEE
	bl isKilled
	cmp r0, #0
	beq _0804CFEE
	movs r0, #0
	str r0, [r5]
_0804CFEE:
	adds r0, r4, #0
	adds r0, #0xb8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0x80
	lsls r2, r2, #2
	adds r3, r0, #0
	cmp r1, r2
	bls _0804D020
	ldrh r0, [r3]
	rsbs r0, r0, #0
	strh r0, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _0804D01C
	adds r0, #0xff
_0804D01C:
	asrs r0, r0, #8
	b _0804D022
_0804D020:
	movs r0, #0
_0804D022:
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	str r0, [r4, #0x54]
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _0804D046
	subs r0, r2, #1
	strh r0, [r1]
_0804D046:
	adds r0, r4, #0
	bl tryKillBeeServer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D078
	ldr r1, _0804D080 @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0804D084 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0x45
	bl StepPaletteAnimation
_0804D078:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D080: .4byte sUpdates1
_0804D084: .4byte sUpdates2

	thumb_func_start BeeServer_Die
BeeServer_Die: @ 0x0804D088
	push {lr}
	ldr r2, _0804D09C @ =sDeads
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0804D09C: .4byte sDeads
