	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitMode6
cubitMode6: @ 0x08053464
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _08053470
	b _0805371C
_08053470:
	lsls r0, r0, #2
	ldr r1, _0805347C @ =_08053480
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805347C: .4byte _08053480
_08053480: @ jump table
	.4byte _080534A4 @ case 0
	.4byte _080534E4 @ case 1
	.4byte _08053500 @ case 2
	.4byte _08053564 @ case 3
	.4byte _080535B8 @ case 4
	.4byte _08053600 @ case 5
	.4byte _08053634 @ case 6
	.4byte _080536F0 @ case 7
	.4byte _08053714 @ case 8
_080534A4:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080534CC
	ldr r1, _080534C4 @ =0x0000B010
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080534C8 @ =sCollisions+(24*1)
	bl SetDDP
	b _080534DE
	.align 2, 0
_080534C4: .4byte 0x0000B010
_080534C8: .4byte sCollisions+(24*1)
_080534CC:
	ldr r1, _080534F8 @ =0x0000B00D
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080534FC @ =sCollisions+(24*1)
	bl SetDDP
_080534DE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080534E4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080534F6
	b _0805371C
_080534F6:
	b _08053706
	.align 2, 0
_080534F8: .4byte 0x0000B00D
_080534FC: .4byte sCollisions+(24*1)
_08053500:
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053518
	ldr r1, _08053514 @ =0x0000B011
	adds r0, r5, #0
	bl SetMotion
	b _08053520
	.align 2, 0
_08053514: .4byte 0x0000B011
_08053518:
	ldr r1, _080535A4 @ =0x0000B00E
	adds r0, r5, #0
	bl SetMotion
_08053520:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080535A8 @ =sCollisions
	bl SetDDP
	movs r0, #0x41
	strb r0, [r5, #0x12]
	ldr r2, _080535AC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080535B0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080535B4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	bl FUN_080a5f00
	adds r1, r5, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0xcd
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08053564:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0805358A
	cmp r0, #3
	beq _0805358A
	cmp r0, #5
	beq _0805358A
	cmp r0, #7
	beq _0805358A
	cmp r0, #8
	beq _0805358A
	b _080536F6
_0805358A:
	adds r0, r5, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0805359A
	b _080536F6
_0805359A:
	movs r0, #0xcb
	bl PlaySound
	b _080536F6
	.align 2, 0
_080535A4: .4byte 0x0000B00E
_080535A8: .4byte sCollisions
_080535AC: .4byte RNG_0202f388
_080535B0: .4byte 0x000343FD
_080535B4: .4byte 0x00269EC3
_080535B8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r4, #0
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805362C @ =sCollisions
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r2, _08053630 @ =Coord_ARRAY_080fef88
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #3
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r0]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	strb r4, [r5, #0x13]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08053600:
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r0]
	ldrb r1, [r1, #0xe]
	adds r4, r0, #0
	cmp r1, #6
	bls _08053622
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _08053622
	movs r0, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0805362C @ =sCollisions
	bl SetDDP
_08053622:
	ldr r0, [r4]
	ldrb r0, [r0, #0xe]
	cmp r0, #9
	bls _0805371C
	b _08053706
	.align 2, 0
_0805362C: .4byte sCollisions
_08053630: .4byte Coord_ARRAY_080fef88
_08053634:
	adds r1, r5, #0
	adds r1, #0xcc
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r5, #0xa]
	movs r3, #1
	movs r6, #0
	adds r2, r3, #0
	orrs r2, r0
	strb r2, [r5, #0xa]
	ldr r0, _08053690 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _08053694
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _080536D6
	lsrs r0, r2, #4
	eors r0, r3
	ands r0, r3
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r3
	ands r1, r3
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080536CE
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080536D4
	.align 2, 0
_08053690: .4byte pZero2
_08053694:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080536D6
	lsrs r0, r2, #4
	eors r0, r3
	ands r0, r3
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	eors r1, r3
	ands r1, r3
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080536CE
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080536D4
_080536CE:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080536D4:
	strb r0, [r5, #0xa]
_080536D6:
	adds r1, r5, #0
	adds r1, #0xc8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08053710 @ =0x0000B011
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x34
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080536F0:
	adds r0, r5, #0
	bl UpdateEntityAnim
_080536F6:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08053706
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805371C
_08053706:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0805371C
	.align 2, 0
_08053710: .4byte 0x0000B011
_08053714:
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0805371C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

