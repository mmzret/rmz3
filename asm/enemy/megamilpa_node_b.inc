	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MegamilpaNode_Die
MegamilpaNode_Die: @ 0x0806587C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r2, [r5, #0xd]
	cmp r2, #0
	beq _0806588C
	cmp r2, #1
	beq _080658CC
	b _0806591C
_0806588C:
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r0, [r5, #0xa]
	movs r1, #0xfb
	ands r1, r0
	strb r1, [r5, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080658C4
	ldr r1, _080658C0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	b _0806591C
	.align 2, 0
_080658C0: .4byte gEnemyFnTable
_080658C4:
	str r2, [r5, #0x60]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080658CC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, #0x20
	str r1, [r5, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _080658E2
	str r0, [r5, #0x60]
_080658E2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806591C
	ldr r1, _08065924 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateGhost19_2
_0806591C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065924: .4byte gEnemyFnTable

