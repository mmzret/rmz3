	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806bfdc
FUN_0806bfdc: @ 0x0806BFDC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0806BFEC
	cmp r1, #1
	beq _0806C002
	b _0806C03E
_0806BFEC:
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C002:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r4, #0x58]
	ldr r1, _0806C044 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C048 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806C03E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806C044: .4byte gSineTable
_0806C048: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c04c
FUN_0806c04c: @ 0x0806C04C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0806C05C
	cmp r1, #1
	beq _0806C072
	b _0806C0AE
_0806C05C:
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806C072:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r4, #0x54]
	ldr r1, _0806C0B4 @ =gSineTable
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C0B8 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806C0AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806C0B4: .4byte gSineTable
_0806C0B8: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c0bc
FUN_0806c0bc: @ 0x0806C0BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0806C0CC
	cmp r1, #1
	beq _0806C0E2
	b _0806C140
_0806C0CC:
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806C0E2:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r5, #0x54]
	ldr r4, _0806C148 @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r5, #0x58]
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C14C @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateEntityAnim
_0806C140:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C148: .4byte gSineTable
_0806C14C: .4byte 0x0000FFFF

	thumb_func_start FUN_0806c150
FUN_0806c150: @ 0x0806C150
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #0
	beq _0806C160
	cmp r1, #1
	beq _0806C176
	b _0806C1D4
_0806C160:
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806C176:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r0]
	str r2, [r5, #0x54]
	ldr r4, _0806C1DC @ =gSineTable
	adds r3, r5, #0
	adds r3, #0xbc
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	subs r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r2, [r0]
	str r2, [r5, #0x58]
	ldr r0, [r3]
	lsrs r0, r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _0806C1E0 @ =0x0000FFFF
	ands r0, r1
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateEntityAnim
_0806C1D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806C1DC: .4byte gSineTable
_0806C1E0: .4byte 0x0000FFFF
