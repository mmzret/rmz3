	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackMode0
blizzackMode0: @ 0x08059DB8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08059DE2
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	strh r1, [r0]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0x12]
_08059DE2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08059DFA
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_08059DFA:
	pop {r4}
	pop {r0}
	bx r0

