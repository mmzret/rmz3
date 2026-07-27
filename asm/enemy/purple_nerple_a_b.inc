	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08075d40
FUN_08075d40: @ 0x08075D40
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08075DC0
	ldr r1, _08075D78 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r3, [r2, #0x10]
	cmp r3, #1
	beq _08075DA4
	cmp r3, #1
	bgt _08075D7C
	cmp r3, #0
	beq _08075D82
	b _08075DB6
	.align 2, 0
_08075D78: .4byte gEnemyFnTable
_08075D7C:
	cmp r3, #2
	beq _08075DB2
	b _08075DB6
_08075D82:
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _08075D92
	movs r0, #1
	b _08075DB4
_08075D92:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _08075DA0
	movs r0, #5
	b _08075DB4
_08075DA0:
	strb r3, [r2, #0xd]
	b _08075DB6
_08075DA4:
	ldr r0, [r2, #0x28]
	cmp r0, #0
	beq _08075DAE
	adds r0, #0xb8
	strb r3, [r0]
_08075DAE:
	strb r1, [r2, #0xd]
	b _08075DB6
_08075DB2:
	movs r0, #4
_08075DB4:
	strb r0, [r2, #0xd]
_08075DB6:
	adds r0, r2, #0
	bl PurpleNerple_Die
	movs r0, #1
	b _08075DC2
_08075DC0:
	movs r0, #0
_08075DC2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08075dc8
FUN_08075dc8: @ 0x08075DC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08075E82
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _08075E82
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08075DE8
	cmp r0, #1
	beq _08075E30
	b _08075E82
_08075DE8:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	beq _08075E82
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08075E82
	ldr r1, _08075E28 @ =PTR_ARRAY_083670d0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08075E2C @ =PTR_ARRAY_083670f8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_08075E24:
	movs r0, #1
	b _08075E84
	.align 2, 0
_08075E28: .4byte PTR_ARRAY_083670d0
_08075E2C: .4byte PTR_ARRAY_083670f8
_08075E30:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08075E3A
	cmp r0, #3
	bne _08075E58
_08075E3A:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08075E58
	adds r0, r4, #0
	bl FUN_08075aa8
	ldr r1, _08075E78 @ =0x00002A04
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
_08075E58:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08075E80
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08075E7C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08075E24
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08075E84
	.align 2, 0
_08075E78: .4byte 0x00002A04
_08075E7C: .4byte 0x00020001
_08075E80:
	strb r0, [r4, #0xf]
_08075E82:
	movs r0, #0
_08075E84:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
