	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804e548
tretista_0804e548: @ 0x0804E548
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804E558
	cmp r0, #2
	beq _0804E558
	b _0804E6F0
_0804E558:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E560
	b _0804E8E0
_0804E560:
	lsls r0, r0, #2
	ldr r1, _0804E56C @ =_0804E570
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E56C: .4byte _0804E570
_0804E570: @ jump table
	.4byte _0804E594 @ case 0
	.4byte _0804E7B2 @ case 1
	.4byte _0804E5D8 @ case 2
	.4byte _0804E62A @ case 3
	.4byte _0804E642 @ case 4
	.4byte _0804E660 @ case 5
	.4byte _0804E672 @ case 6
	.4byte _0804E69C @ case 7
	.4byte _0804E6C8 @ case 8
_0804E594:
	ldr r1, _0804E5C8 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E5CC @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, _0804E5D0 @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldrb r0, [r4, #0xf]
	cmp r0, #2
	beq _0804E5D4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804E5BE
	b _0804E778
_0804E5BE:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bgt _0804E5C6
	b _0804E78A
_0804E5C6:
	b _0804E77E
	.align 2, 0
_0804E5C8: .4byte 0x0000AB0C
_0804E5CC: .4byte sCollisions+(24*1)
_0804E5D0: .4byte pZero2
_0804E5D4:
	movs r0, #0
	b _0804E788
_0804E5D8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E5EA
	b _0804E8E0
_0804E5EA:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _0804E620
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804E626
_0804E620:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804E626:
	strb r0, [r4, #0xa]
	b _0804E88C
_0804E62A:
	ldr r1, _0804E658 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E65C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E642:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E654
	b _0804E8E0
_0804E654:
	b _0804E88C
	.align 2, 0
_0804E658: .4byte 0x0000AB0C
_0804E65C: .4byte sCollisions+(24*1)
_0804E660:
	ldr r1, _0804E698 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E672:
	ldr r1, [r4, #0x60]
	adds r1, #0x20
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r3, r0, r2
	str r3, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	cmp r2, #0
	bgt _0804E68C
	b _0804E848
_0804E68C:
	movs r2, #0xa0
	lsls r2, r2, #6
	adds r0, r3, r2
	bl PushoutToLeft1
	b _0804E850
	.align 2, 0
_0804E698: .4byte 0x0000AB0D
_0804E69C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E6E4 @ =sCollisions+(24*1)
	bl SetDDP
	ldr r1, _0804E6E8 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804E6EC @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E6C8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	beq _0804E6DA
	b _0804E8E0
_0804E6DA:
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E6E4: .4byte sCollisions+(24*1)
_0804E6E8: .4byte 0x0000AB0F
_0804E6EC: .4byte 0xFFFFF000
_0804E6F0:
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E6F8
	b _0804E8E0
_0804E6F8:
	lsls r0, r0, #2
	ldr r1, _0804E704 @ =_0804E708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E704: .4byte _0804E708
_0804E708: @ jump table
	.4byte _0804E72C @ case 0
	.4byte _0804E7B2 @ case 1
	.4byte _0804E7C4 @ case 2
	.4byte _0804E62A @ case 3
	.4byte _0804E642 @ case 4
	.4byte _0804E80E @ case 5
	.4byte _0804E820 @ case 6
	.4byte _0804E89C @ case 7
	.4byte _0804E8C8 @ case 8
_0804E72C:
	ldr r1, _0804E750 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E754 @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, _0804E758 @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E760
	ldr r0, _0804E75C @ =0xFFFF7900
	adds r5, r5, r0
	b _0804E766
	.align 2, 0
_0804E750: .4byte 0x0000AB0C
_0804E754: .4byte sCollisions+(24*1)
_0804E758: .4byte pZero2
_0804E75C: .4byte 0xFFFF7900
_0804E760:
	movs r2, #0x87
	lsls r2, r2, #8
	adds r5, r5, r2
_0804E766:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E778
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E78A
	b _0804E77E
_0804E778:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bge _0804E78A
_0804E77E:
	ldr r1, _0804E7C0 @ =0x0000AB0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
_0804E788:
	strb r0, [r4, #0x13]
_0804E78A:
	movs r0, #0x38
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r5, r0
	movs r1, #0x38
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xc4
	lsls r0, r0, #8
	movs r1, #0x38
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x37
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E7B2:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	beq _0804E88C
	movs r0, #4
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E7C0: .4byte 0x0000AB0B
_0804E7C4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E7D6
	b _0804E8E0
_0804E7D6:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	bne _0804E806
	b _0804E620
_0804E806:
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804E626
_0804E80E:
	ldr r1, _0804E844 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E820:
	ldr r1, [r4, #0x60]
	adds r1, #0x20
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r3, r0, r2
	str r3, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	cmp r2, #0
	ble _0804E848
	movs r2, #0xa0
	lsls r2, r2, #6
	adds r0, r3, r2
	bl PushoutToLeft1
	b _0804E850
	.align 2, 0
_0804E844: .4byte 0x0000AB0D
_0804E848:
	ldr r2, _0804E894 @ =0xFFFFD800
	adds r0, r3, r2
	bl PushoutToRight1
_0804E850:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E85C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804E85C:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0804E876
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804E876
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E898 @ =0x08363410
	bl SetDDP
_0804E876:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804E88C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E8E0
_0804E88C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804E8E0
	.align 2, 0
_0804E894: .4byte 0xFFFFD800
_0804E898: .4byte 0x08363410
_0804E89C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E8E8 @ =sCollisions+(24*1)
	bl SetDDP
	ldr r1, _0804E8EC @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804E8F0 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E8C8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804E8E0
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #2
	strb r0, [r4, #0xf]
_0804E8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E8E8: .4byte sCollisions+(24*1)
_0804E8EC: .4byte 0x0000AB0F
_0804E8F0: .4byte 0xFFFFF000
