	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatDamage
hellbatDamage: @ 0x0804C9F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804CA00
	cmp r5, #1
	beq _0804CA46
	b _0804CA82
_0804CA00:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x8a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804CA3E
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CA3E:
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804CA46:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804CA56
	str r1, [r4, #0x60]
_0804CA56:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804CA7A
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	movs r1, #0x80
	lsls r1, r1, #2
	b _0804CA7E
_0804CA7A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0804CA7E:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CA82:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0804CA9A
	movs r1, #0
	str r1, [r5]
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804CA9A:
	pop {r4, r5}
	pop {r0}
	bx r0
