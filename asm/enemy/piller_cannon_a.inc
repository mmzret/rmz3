	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PillerCannon_Init
PillerCannon_Init: @ 0x0806832C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _08068378 @ =gSystemSavedata
	ldrb r1, [r0, #0x14]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08068384
	ldr r0, _0806837C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08068384
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08068380 @ =0x0836609C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _0806839C
	.align 2, 0
_08068378: .4byte gSystemSavedata
_0806837C: .4byte gCurStory
_08068380: .4byte sCollisions
_08068384:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080683F8 @ =0x0836609C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_0806839C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080683FC @ =FUN_08068f68
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r2, #0
	strb r2, [r0]
	adds r0, #4
	str r2, [r0]
	subs r0, #3
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #5
	strb r2, [r0]
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08068404
	ldr r1, _08068400 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0xd]
	b _0806841A
	.align 2, 0
_080683F8: .4byte sCollisions
_080683FC: .4byte FUN_08068f68
_08068400: .4byte gEnemyFnTable
_08068404:
	ldr r1, _08068444 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #2
	strb r0, [r6, #0xd]
_0806841A:
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _08068438
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_08068438:
	adds r0, r6, #0
	bl PillerCannon_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068444: .4byte gEnemyFnTable

