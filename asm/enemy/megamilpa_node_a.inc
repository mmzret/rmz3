	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start MegamilpaNode_Init
MegamilpaNode_Init: @ 0x08065778
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _08065814 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _08065818 @ =0x08365CF0
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806581C @ =0x08365CD8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080657F6
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_080657F6:
	ldrb r0, [r6, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	adds r0, r6, #0
	bl MegamilpaNode_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065814: .4byte gEnemyFnTable
_08065818: .4byte 0x08365CF0
_0806581C: .4byte 0x08365CD8

	thumb_func_start MegamilpaNode_Update
MegamilpaNode_Update: @ 0x08065820
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0806584C
	ldr r1, _08065848 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl MegamilpaNode_Die
	b _0806586C
	.align 2, 0
_08065848: .4byte gEnemyFnTable
_0806584C:
	ldr r1, _08065874 @ =0x08365CA8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08065878 @ =0x08365CB4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0806586C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065874: .4byte 0x08365CA8
_08065878: .4byte 0x08365CB4

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
