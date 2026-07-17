	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Blizzack_Init
Blizzack_Init: @ 0x08059AA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _08059C94 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r4, #0xfa
	lsls r4, r4, #3
	ldr r5, _08059C98 @ =gStaticMotionGraphics
	adds r0, r4, r5
	ldr r2, _08059C9C @ =wStaticGraphicTilenums
	mov sb, r2
	mov r1, sb
	adds r1, #0xc8
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #9
	adds r1, r1, r6
	bl LoadGraphic
	ldr r0, _08059CA0 @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r1, _08059CA4 @ =wStaticMotionPalIDs
	mov sl, r1
	mov r0, sl
	adds r0, #0xc8
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xf5
	lsls r4, r4, #3
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0xc4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r1, r1, r6
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xc4
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _08059CA8 @ =0x000007BC
	adds r5, r4, r5
	mov r0, sb
	adds r0, #0xc6
	ldrh r1, [r0]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r5, #0
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xc6
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r1, r7, #0
	adds r1, #0xd0
	movs r0, #0x40
	strb r0, [r1]
	ldr r1, _08059CAC @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a134
	adds r1, r0, #0
	adds r4, r7, #0
	adds r4, #0xb8
	str r1, [r4]
	ldr r0, [r7, #0x54]
	bl FUN_0800a31c
	adds r5, r7, #0
	adds r5, #0xb4
	str r0, [r5]
	ldr r0, [r7, #0x54]
	ldr r1, [r4]
	bl FUN_0800a22c
	adds r1, r7, #0
	adds r1, #0xd8
	str r0, [r1]
	adds r3, r7, #0
	adds r3, #0xdc
	ldr r2, [r5]
	subs r0, r0, r2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r2, r2, r0
	str r2, [r3]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r1, r7, #0
	adds r1, #0xbc
	str r0, [r1]
	str r0, [r7, #0x58]
	adds r1, #4
	ldr r0, [r7, #0x54]
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc5
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r1, #8
	ldr r0, _08059CB0 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl CreateEnemy42
	str r0, [r7, #0x2c]
	movs r1, #1
	strb r1, [r0, #0xe]
	ldr r0, [r7, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xcc
	movs r0, #3
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xd4
	mov r1, r8
	str r1, [r0]
	adds r0, #0xc
	strb r2, [r0]
	strb r2, [r7, #0xd]
	movs r2, #1
	strb r2, [r7, #0xe]
	adds r0, r7, #0
	bl Blizzack_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08059C94: .4byte gBossFnTable
_08059C98: .4byte gStaticMotionGraphics
_08059C9C: .4byte wStaticGraphicTilenums
_08059CA0: .4byte gStaticMotionGraphics+12
_08059CA4: .4byte wStaticMotionPalIDs
_08059CA8: .4byte 0x000007BC
_08059CAC: .4byte sCollisions
_08059CB0: .4byte 0x0000FFFF

	thumb_func_start Blizzack_Update
Blizzack_Update: @ 0x08059CB4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08059CD2
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08059D08
_08059CD2:
	ldr r0, _08059D00 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _08059D08
	ldr r1, _08059D04 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	adds r0, r4, #0
	bl Blizzack_Die
	b _08059D8E
	.align 2, 0
_08059D00: .4byte gStageRun
_08059D04: .4byte gBossFnTable
_08059D08:
	adds r0, r4, #0
	bl FUN_0805af14
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r0, [r6]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08059D7E
	movs r2, #0
	ldr r0, _08059D94 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08059D2C
	movs r2, #1
_08059D2C:
	adds r0, r4, #0
	adds r0, #0xc4
	strb r2, [r0]
	adds r5, r4, #0
	adds r5, #0xd4
	ldr r0, [r5]
	cmp r0, #0
	bne _08059D48
	ldr r2, _08059D98 @ =sElementCoord
	movs r0, #0x1a
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_08059D48:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08059D56
	movs r0, #0
	str r0, [r5]
_08059D56:
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08059D6C
	adds r1, r4, #0
	adds r1, #0xe0
	movs r0, #0x80
	strb r0, [r1]
_08059D6C:
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08059D7E
	movs r0, #0x13
	strb r0, [r4, #0xd]
	strb r7, [r4, #0xe]
_08059D7E:
	ldr r0, _08059D9C @ =0x08364B50
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08059D8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08059D94: .4byte pZero2
_08059D98: .4byte sElementCoord
_08059D9C: .4byte sUpdates

