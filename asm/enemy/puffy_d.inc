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

	thumb_func_start FUN_0807cb50
FUN_0807cb50: @ 0x0807CB50
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807CB9A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _0807CB9A
	ldr r2, _0807CB8C @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807CB9A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807CB90
	strb r7, [r4, #0xd]
	b _0807CB98
	.align 2, 0
_0807CB8C: .4byte sElementCoord
_0807CB90:
	cmp r1, #0x30
	bne _0807CB9A
	movs r0, #3
	strb r0, [r4, #0xd]
_0807CB98:
	strb r5, [r4, #0xe]
_0807CB9A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807cba4
FUN_0807cba4: @ 0x0807CBA4
	push {lr}
	ldr r2, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	ldr r0, _0807CBD0 @ =gCollisionManager
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	adds r1, r2, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
_0807CBCC:
	pop {r0}
	bx r0
	.align 2, 0
_0807CBD0: .4byte gCollisionManager

	thumb_func_start dragInSea
dragInSea: @ 0x0807CBD4
	push {lr}
	adds r3, r0, #0
	ldr r1, _0807CBEC @ =gOverworld
	ldr r2, _0807CBF0 @ =0x0002C00C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r1, [r3, #0x58]
	cmp r2, r1
	ble _0807CBE8
	str r2, [r3, #0x58]
_0807CBE8:
	pop {r1}
	bx r1
	.align 2, 0
_0807CBEC: .4byte gOverworld
_0807CBF0: .4byte 0x0002C00C
