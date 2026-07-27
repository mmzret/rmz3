	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808bb88
FUN_0808bb88: @ 0x0808BB88
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808BB98
	cmp r0, #1
	beq _0808BBBE
	b _0808BBDA
_0808BB98:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xca
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808BBE0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808BBBE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808BBDA
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808BBDA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808BBE0: .4byte 0xFFFFC000
