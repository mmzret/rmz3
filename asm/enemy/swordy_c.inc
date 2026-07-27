	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807c480
FUN_0807c480: @ 0x0807C480
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807C48E
	movs r0, #1
	strb r0, [r4, #0xe]
_0807C48E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807C4A4
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807C4A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
