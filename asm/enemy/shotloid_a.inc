	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093930
FUN_08093930: @ 0x08093930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809398C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08093984
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093990 @ =gEnemyFnTable
	movs r1, #0x3e
	strb r1, [r3, #9]
	adds r0, #0xf8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xbd
	strb r4, [r0]
_08093984:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809398C: .4byte gEnemyHeaderPtr
_08093990: .4byte gEnemyFnTable

	thumb_func_start FUN_08093994
FUN_08093994: @ 0x08093994
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080939E0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080939DA
	adds r2, r4, #0
	adds r2, #0x25
	movs r3, #0
	movs r1, #0x18
	strb r1, [r2]
	ldr r1, _080939E4 @ =gEnemyFnTable
	movs r2, #0x3e
	strb r2, [r4, #9]
	adds r1, #0xf8
	ldr r1, [r1]
	ldr r1, [r1]
	str r1, [r4, #0x14]
	movs r1, #0
	strh r3, [r4, #0x20]
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	ldrb r2, [r4, #0xb]
	movs r1, #0x10
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r1, [r4, #0x1c]
	strb r1, [r4, #0x1d]
	movs r1, #1
	strb r1, [r4, #0x10]
	str r5, [r4, #0x28]
_080939DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080939E0: .4byte gEnemyHeaderPtr
_080939E4: .4byte gEnemyFnTable

	thumb_func_start FUN_080939e8
FUN_080939e8: @ 0x080939E8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08093A14 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _080939FC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_080939FC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093A18
	movs r0, #0
	b _08093A1A
	.align 2, 0
_08093A14: .4byte 0xFFFFF200
_08093A18:
	movs r0, #1
_08093A1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a20
FUN_08093a20: @ 0x08093A20
	push {lr}
	movs r3, #0
	ldr r1, _08093A50 @ =pZero2
	ldr r1, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _08093A32
	movs r3, #1
_08093A32:
	ldr r1, _08093A54 @ =0xFFFFA000
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #0xe
	adds r0, r0, r1
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08093A58 @ =0x00000FFF
	cmp r0, r1
	bls _08093A5C
	adds r0, r3, #0
	b _08093A5E
	.align 2, 0
_08093A50: .4byte pZero2
_08093A54: .4byte 0xFFFFA000
_08093A58: .4byte 0x00000FFF
_08093A5C:
	movs r0, #2
_08093A5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a64
FUN_08093a64: @ 0x08093A64
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _08093A90
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08093A8C @ =0x000007FF
	cmp r1, r0
	bgt _08093A90
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _08093A92
	.align 2, 0
_08093A8C: .4byte 0x000007FF
_08093A90:
	movs r0, #0
_08093A92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093a98
FUN_08093a98: @ 0x08093A98
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _08093AEE
	cmp r5, #0
	bge _08093AC8
	ldr r0, [r4, #0x54]
	ldr r1, _08093AC0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AC4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #1
	b _08093AF0
	.align 2, 0
_08093AC0: .4byte 0xFFFFF200
_08093AC4: .4byte 0xFFFFF600
_08093AC8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AE4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #2
	b _08093AF0
	.align 2, 0
_08093AE4: .4byte 0xFFFFF600
_08093AE8:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08093AEE:
	movs r0, #0
_08093AF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_08093af8
nop_08093af8: @ 0x08093AF8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093afc
FUN_08093afc: @ 0x08093AFC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08093B48
	ldr r1, _08093B3C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08093B40
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08093B42
	strb r4, [r2, #0xd]
	b _08093B44
	.align 2, 0
_08093B3C: .4byte gEnemyFnTable
_08093B40:
	movs r0, #1
_08093B42:
	strb r0, [r2, #0xd]
_08093B44:
	movs r0, #1
	b _08093B4A
_08093B48:
	movs r0, #0
_08093B4A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093b50
FUN_08093b50: @ 0x08093B50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _08093BD6
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _08093BD6
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08093B70
	cmp r0, #1
	beq _08093BB4
	b _08093BD6
_08093B70:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08093BD6
	ldr r1, _08093BAC @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093BB0 @ =0x08369E3C
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
_08093BA6:
	movs r0, #1
	b _08093BD8
	.align 2, 0
_08093BAC: .4byte 0x08369E18
_08093BB0: .4byte 0x08369E3C
_08093BB4:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _08093BD4
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093BD0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093BA6
	strb r5, [r4, #0xf]
	b _08093BD6
	.align 2, 0
_08093BD0: .4byte 0x00020001
_08093BD4:
	strb r0, [r4, #0xf]
_08093BD6:
	movs r0, #0
_08093BD8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
