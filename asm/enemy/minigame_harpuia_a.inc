	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start HarpuiaMinigameEnemy_Init
HarpuiaMinigameEnemy_Init: @ 0x0809B0D8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0x10]
	cmp r7, #0
	bne _0809B160
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	movs r2, #0
	bl FUN_0809af88
	str r0, [r6, #0x2c]
	ldrb r0, [r6, #0xb]
	orrs r4, r0
	strb r4, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B15C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B15C: .4byte gEnemyFnTable
_0809B160:
	cmp r7, #1
	bne _0809B1D4
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r7, [r0]
	adds r5, r6, #0
	adds r5, #0x4a
	movs r3, #0x10
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	ldrb r0, [r6, #0xb]
	orrs r2, r0
	strb r2, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B1D0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B1D0: .4byte gEnemyFnTable
_0809B1D4:
	cmp r7, #2
	bne _0809B278
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B224
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B220 @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r7, [r0]
	b _0809B248
	.align 2, 0
_0809B220: .4byte 0x0836A7D0
_0809B224:
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B26C @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
_0809B248:
	ldr r0, _0809B270 @ =FUN_0809bd2c
	str r0, [r4, #0x24]
	ldr r1, _0809B274 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B26C: .4byte 0x0836A7D0
_0809B270: .4byte FUN_0809bd2c
_0809B274: .4byte gEnemyFnTable
_0809B278:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B2D4 @ =0x0836A818
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _0809B2D8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_0809B2C6:
	adds r0, r6, #0
	bl HarpuiaMinigameEnemy_Update
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2D4: .4byte 0x0836A818
_0809B2D8: .4byte gEnemyFnTable
