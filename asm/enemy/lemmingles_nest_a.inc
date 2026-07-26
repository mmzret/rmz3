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
