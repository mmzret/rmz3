	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806b098
FUN_0806b098: @ 0x0806B098
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0806B0A8
	cmp r3, #1
	beq _0806B0D2
	b _0806B0D8
_0806B0A8:
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
_0806B0D2:
	adds r0, r2, #0
	bl UpdateEntityAnim
_0806B0D8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0806b0dc
FUN_0806b0dc: @ 0x0806B0DC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0806B0EC
	cmp r3, #1
	beq _0806B116
	b _0806B11C
_0806B0EC:
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
_0806B116:
	adds r0, r2, #0
	bl UpdateEntityAnim
_0806B11C:
	pop {r0}
	bx r0
