	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start LemminglesNest_Init
LemminglesNest_Init: @ 0x0806E010
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0806E0B8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0806E0BC @ =sInitModes
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0806E0AC
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0806E066
	adds r0, r5, #0
	bl FUN_0806df3c
_0806E066:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0806E0C0 @ =sCollisions
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	orrs r0, r6
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	ldr r1, _0806E0C4 @ =0xFFFFFEFF
	ands r0, r1
	ldr r1, _0806E0C8 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0806E0CC @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0806E0D0 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r2]
_0806E0AC:
	adds r0, r5, #0
	bl LemminglesNest_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E0B8: .4byte gEnemyFnTable
_0806E0BC: .4byte sInitModes
_0806E0C0: .4byte sCollisions
_0806E0C4: .4byte 0xFFFFFEFF
_0806E0C8: .4byte 0xFFFFFDFF
_0806E0CC: .4byte 0xFFFFFBFF
_0806E0D0: .4byte 0xFFFFF7FF

	thumb_func_start LemminglesNest_Update
LemminglesNest_Update: @ 0x0806E0D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bls _0806E10C
	ldr r0, _0806E108 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0806E10C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _0806E1AA
	.align 2, 0
_0806E108: .4byte gCurStory
_0806E10C:
	ldrb r0, [r4, #0x10]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0806E122
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0806E150
	b _0806E132
_0806E122:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806E150
_0806E132:
	ldr r1, _0806E14C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl LemminglesNest_Die
	b _0806E1C4
	.align 2, 0
_0806E14C: .4byte gEnemyFnTable
_0806E150:
	adds r0, r4, #0
	bl FUN_0806dfa4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0806E1C4
	ldr r1, _0806E1CC @ =0x083667A4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E1D0 @ =0x083667B4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, _0806E1D4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0xc8
	lsls r1, r1, #9
	cmp r0, r1
	bls _0806E1C4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_0806E1AA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806E1D8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0806E1C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E1CC: .4byte sUpdates1
_0806E1D0: .4byte sUpdates2
_0806E1D4: .4byte gStageRun+232
_0806E1D8: .4byte gEnemyFnTable

	thumb_func_start LemminglesNest_Die
LemminglesNest_Die: @ 0x0806E1DC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _0806E1F0
	cmp r0, #4
	beq _0806E1F0
	cmp r0, #5
	bne _0806E25A
_0806E1F0:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0806E274 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0806E278 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0806E27C @ =0x0000270E
	cmp r1, r0
	bhi _0806E240
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806E240:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806E25A:
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E274: .4byte 0xFFFFF000
_0806E278: .4byte gScore
_0806E27C: .4byte 0x0000270E
_0806E280: .4byte gEnemyFnTable
