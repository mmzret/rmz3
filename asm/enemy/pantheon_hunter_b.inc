	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08064e7c
FUN_08064e7c: @ 0x08064E7C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08064E92
	movs r0, #0xb
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl phunter_08065218
	b _0806500A
_08064E92:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08064EF4
	ldr r1, _08064EB0 @ =0x00001309
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _08064EB4
	movs r0, #0x80
	b _08064EB8
	.align 2, 0
_08064EB0: .4byte 0x00001309
_08064EB4:
	movs r0, #0x80
	rsbs r0, r0, #0
_08064EB8:
	str r0, [r4, #0x5c]
	ldrb r2, [r2]
	cmp r2, #0
	beq _08064EC8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08064ECE
_08064EC8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08064ECE:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08064EFC
_08064EF4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08064EFC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08064F1E
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0806500A
_08064F1E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r2, _08064F68 @ =Coord_08365c8c
	adds r1, r4, #0
	adds r1, #0xbd
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r4, #0x54]
	ldr r1, [r1]
	adds r5, r2, r1
	ldr r3, _08064F6C @ =0xFFFFF800
	adds r1, r0, r3
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r6, r0, r2
	adds r0, r5, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _08064F60
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064F70
_08064F60:
	movs r1, #0
	movs r0, #9
	b _08065006
	.align 2, 0
_08064F68: .4byte Coord_08365c8c
_08064F6C: .4byte 0xFFFFF800
_08064F70:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08064F98
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r3, #0xa0
	lsls r3, r3, #6
	adds r0, r0, r3
	ldr r2, [r4, #0x54]
	cmp r2, r0
	ble _08064FB4
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r7, [r4, #0xe]
	b _0806500A
_08064F98:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _08064FB0 @ =0xFFFFD800
	adds r0, r0, r2
	ldr r2, [r4, #0x54]
	cmp r2, r0
	bge _08064FB4
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _0806500A
	.align 2, 0
_08064FB0: .4byte 0xFFFFD800
_08064FB4:
	ldr r0, _08065010 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	movs r3, #0xa
	ldrsh r0, [r0, r3]
	cmp r0, #6
	ble _0806500A
	movs r6, #0
	ldr r0, _08065014 @ =pZero2
	ldr r5, [r0]
	ldr r3, [r5, #0x54]
	cmp r3, r2
	bgt _08064FCE
	movs r6, #1
_08064FCE:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	ands r0, r1
	cmp r6, r0
	beq _0806500A
	subs r0, r3, r2
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r0, r1
	movs r1, #0xdc
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806500A
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #7
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #8
	cmp r0, r1
	bhi _0806500A
	ldrb r0, [r4, #0xd]
	movs r1, #0
	strb r0, [r4, #0xf]
	movs r0, #7
_08065006:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806500A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065010: .4byte gProjectileHeaderPtr
_08065014: .4byte pZero2
