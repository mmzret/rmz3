	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806da5c
FUN_0806da5c: @ 0x0806DA5C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806DA7A
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806DA7A:
	adds r1, r4, #0
	adds r1, #0xb4
	movs r5, #0
	movs r0, #1
	strb r0, [r1, #0xb]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806DA9C
	strb r5, [r4, #0xd]
	b _0806DAAE
_0806DA9C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806DAB0
	movs r0, #3
	strb r0, [r4, #0xd]
_0806DAAE:
	strb r5, [r4, #0xe]
_0806DAB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806dab8
FUN_0806dab8: @ 0x0806DAB8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0806DADC
	movs r1, #0xb8
	lsls r1, r1, #5
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806DB40 @ =0x083666C0
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806DADC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806DAEC
	str r1, [r4, #0x60]
_0806DAEC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806DB14
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0806DB44 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0806DB14:
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0806DB52
	movs r6, #0
	str r6, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806DB48 @ =sCollisions
	bl SetDDP
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0806DB4C
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _0806DB52
	.align 2, 0
_0806DB40: .4byte sCollisions+(24*1)
_0806DB44: .4byte 0xFFFFF600
_0806DB48: .4byte sCollisions
_0806DB4C:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0806DB52:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

