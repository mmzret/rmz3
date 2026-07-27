	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807be20
FUN_0807be20: @ 0x0807BE20
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807BE32
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BE32:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807BE48
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807BE48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807be50
FUN_0807be50: @ 0x0807BE50
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807BE9A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807BE9A
	ldr r2, _0807BE8C @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807BE9A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807BE90
	movs r0, #2
	b _0807BE96
	.align 2, 0
_0807BE8C: .4byte sElementCoord
_0807BE90:
	cmp r1, #0x30
	bne _0807BE9A
	movs r0, #4
_0807BE96:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807BE9A:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
