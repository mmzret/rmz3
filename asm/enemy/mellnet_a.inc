	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807d724
FUN_0807d724: @ 0x0807D724
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807D776
	ldr r1, _0807D764 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _0807D768
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0807D76A
	strb r4, [r2, #0xd]
	b _0807D76C
	.align 2, 0
_0807D764: .4byte gEnemyFnTable
_0807D768:
	movs r0, #1
_0807D76A:
	strb r0, [r2, #0xd]
_0807D76C:
	adds r0, r2, #0
	bl Mellnet_Die
	movs r0, #1
	b _0807D778
_0807D776:
	movs r0, #0
_0807D778:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807d780
FUN_0807d780: @ 0x0807D780
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _0807D806
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0807D806
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0807D7A0
	cmp r0, #1
	beq _0807D7E4
	b _0807D806
_0807D7A0:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807D806
	ldr r1, _0807D7DC @ =0x08367C98
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807D7E0 @ =0x08367CB4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0807D7D6:
	movs r0, #1
	b _0807D808
	.align 2, 0
_0807D7DC: .4byte 0x08367C98
_0807D7E0: .4byte 0x08367CB4
_0807D7E4:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807D804
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0807D800 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807D7D6
	strb r5, [r4, #0xf]
	b _0807D806
	.align 2, 0
_0807D800: .4byte 0x00020001
_0807D804:
	strb r0, [r4, #0xf]
_0807D806:
	movs r0, #0
_0807D808:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807d810
FUN_0807d810: @ 0x0807D810
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0807D850
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807D850
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0807D83C
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0807D850
_0807D83C:
	ldr r2, _0807D858 @ =0x08367D3C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807D850
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807D850:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D858: .4byte 0x08367D3C

	thumb_func_start Mellnet_Init
Mellnet_Init: @ 0x0807D85C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0807D8C4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807D8C8 @ =0x08367D44
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0807D8CC @ =0x08367CDC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #4
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807D8D0 @ =FUN_0807d720
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, r4, #0
	bl Mellnet_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D8C4: .4byte gEnemyFnTable
_0807D8C8: .4byte 0x08367D44
_0807D8CC: .4byte sCollisions
_0807D8D0: .4byte FUN_0807d720

