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

