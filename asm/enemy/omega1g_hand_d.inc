	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080835b8
FUN_080835b8: @ 0x080835B8
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _080835C8
	cmp r3, #1
	beq _080835F2
	b _080835F8
_080835C8:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080835F2:
	adds r0, r2, #0
	bl UpdateEntityAnim
_080835F8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080835fc
FUN_080835fc: @ 0x080835FC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0808360C
	cmp r3, #1
	beq _08083636
	b _0808363C
_0808360C:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083636:
	adds r0, r2, #0
	bl UpdateEntityAnim
_0808363C:
	pop {r0}
	bx r0
	.align 2, 0
