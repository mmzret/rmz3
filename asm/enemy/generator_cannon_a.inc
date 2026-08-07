	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808c3ec
FUN_0808c3ec: @ 0x0808C3EC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808C448
	ldr r1, _0808C428 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	beq _0808C43C
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0808C42C
	strb r4, [r2, #0xd]
	b _0808C43E
	.align 2, 0
_0808C428: .4byte gEnemyFnTable
_0808C42C:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0808C43A
	movs r0, #3
	b _0808C43C
_0808C43A:
	movs r0, #1
_0808C43C:
	strb r0, [r2, #0xd]
_0808C43E:
	adds r0, r2, #0
	bl GeneratorCannon_Die
	movs r0, #1
	b _0808C44A
_0808C448:
	movs r0, #0
_0808C44A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808c450
FUN_0808c450: @ 0x0808C450
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0808C4DE
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0808C4DE
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808C470
	cmp r0, #1
	beq _0808C4B4
	b _0808C4DE
_0808C470:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808C4DE
	ldr r1, _0808C4AC @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808C4B0 @ =sUpdates2
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
_0808C4A6:
	movs r0, #1
	b _0808C4E0
	.align 2, 0
_0808C4AC: .4byte sUpdates1
_0808C4B0: .4byte sUpdates2
_0808C4B4:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808C4DC
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808C4A6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C4D8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C4A6
	strb r5, [r4, #0xf]
	b _0808C4DE
	.align 2, 0
_0808C4D8: .4byte 0x00020001
_0808C4DC:
	strb r0, [r4, #0xf]
_0808C4DE:
	movs r0, #0
_0808C4E0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
