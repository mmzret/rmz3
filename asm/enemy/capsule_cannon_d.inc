	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08085c18
FUN_08085c18: @ 0x08085C18
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _08085C26
	movs r0, #1
	strb r0, [r1, #0xe]
_08085C26:
	pop {r0}
	bx r0
	.align 2, 0
