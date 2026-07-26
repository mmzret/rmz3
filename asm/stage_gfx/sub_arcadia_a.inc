	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08014f58
FUN_08014f58: @ 0x08014F58
	push {lr}
	adds r1, r0, #0
	ldrb r3, [r1, #0xe]
	adds r2, r3, #0
	cmp r2, #0
	bne _08014F7A
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r1, #0x44]
	movs r0, #0x80
	str r0, [r1, #0x48]
	str r2, [r1, #0x4c]
	movs r0, #0x96
	lsls r0, r0, #3
	str r0, [r1, #0x50]
	adds r0, r3, #1
	strb r0, [r1, #0xe]
_08014F7A:
	pop {r0}
	bx r0
	.align 2, 0
