	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807cad4
FUN_0807cad4: @ 0x0807CAD4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807CAE4
	cmp r0, #1
	beq _0807CAEC
	b _0807CB30
_0807CAE4:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807CAEC:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807CAFC
	str r1, [r4, #0x60]
_0807CAFC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807CB28
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0807CB24 @ =0xFFFFF000
	b _0807CB2C
	.align 2, 0
_0807CB24: .4byte 0xFFFFF000
_0807CB28:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0807CB2C:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0807CB30:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807CB4A
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807CB4A:
	pop {r4, r5}
	pop {r0}
	bx r0
