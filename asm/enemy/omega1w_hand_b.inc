	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806b8cc
FUN_0806b8cc: @ 0x0806B8CC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0806b8d0
FUN_0806b8d0: @ 0x0806B8D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _0806B8DC
	b _0806BB4A
_0806B8DC:
	lsls r0, r0, #2
	ldr r1, _0806B8E8 @ =_0806B8EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B8E8: .4byte _0806B8EC
_0806B8EC: @ jump table
	.4byte _0806B910 @ case 0
	.4byte _0806B99C @ case 1
	.4byte _0806B9EE @ case 2
	.4byte _0806BA4E @ case 3
	.4byte _0806BA58 @ case 4
	.4byte _0806BA74 @ case 5
	.4byte _0806BA98 @ case 6
	.4byte _0806BAE0 @ case 7
	.4byte _0806BB4A @ case 8
_0806B910:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r4, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldr r2, _0806B990 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806B994 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806B998 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806BB48
	.align 2, 0
_0806B990: .4byte RNG_0202f388
_0806B994: .4byte 0x000343FD
_0806B998: .4byte 0x00269EC3
_0806B99C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x54]
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r3, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806B9DC
	b _0806BB4A
_0806B9DC:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806B9E8
	b _0806BB4A
_0806B9E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
_0806B9EE:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806B9FE
	str r1, [r5, #0x60]
_0806B9FE:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	beq _0806BA46
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BA40
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r0, #0xe8
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	b _0806BA46
_0806BA40:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA46:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0806BB4A
_0806BA4E:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA58:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
_0806BA74:
	ldr r2, _0806BAD4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BAD8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BADC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	adds r0, #5
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BA98:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	ldr r2, _0806BAD4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BAD8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BADC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BB48
	.align 2, 0
_0806BAD4: .4byte RNG_0202f388
_0806BAD8: .4byte 0x000343FD
_0806BADC: .4byte 0x00269EC3
_0806BAE0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r4, [r5, #0x28]
	ldr r0, [r3]
	ldr r1, [r4, #0x54]
	adds r0, r0, r1
	ldr r2, [r5, #0x54]
	cmp r2, r0
	ble _0806BB10
	ldr r0, _0806BB0C @ =0xFFFFFD00
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	bge _0806BB2A
	b _0806BB22
	.align 2, 0
_0806BB0C: .4byte 0xFFFFFD00
_0806BB10:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r2, r2, r1
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	ble _0806BB2A
_0806BB22:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BB2A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	beq _0806BB4A
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BB4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BB4A
	movs r0, #4
_0806BB48:
	strb r0, [r5, #0xe]
_0806BB4A:
	ldr r2, [r5, #0x28]
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0806BB7E
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806BB84 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, _0806BB88 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
_0806BB7E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806BB84: .4byte 0xFFFFF800
_0806BB88: .4byte 0xFFFFE800

	thumb_func_start FUN_0806bb8c
FUN_0806bb8c: @ 0x0806BB8C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _0806BB98
	b _0806BDCA
_0806BB98:
	lsls r0, r0, #2
	ldr r1, _0806BBA4 @ =_0806BBA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806BBA4: .4byte _0806BBA8
_0806BBA8: @ jump table
	.4byte _0806BBCC @ case 0
	.4byte _0806BC44 @ case 1
	.4byte _0806BC7E @ case 2
	.4byte _0806BCDE @ case 3
	.4byte _0806BCE8 @ case 4
	.4byte _0806BD04 @ case 5
	.4byte _0806BD20 @ case 6
	.4byte _0806BD60 @ case 7
	.4byte _0806BDCA @ case 8
_0806BBCC:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r4, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	ldr r1, _0806BC34 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldr r2, _0806BC38 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BC3C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BC40 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #2
	b _0806BDC8
	.align 2, 0
_0806BC34: .4byte 0x00000901
_0806BC38: .4byte RNG_0202f388
_0806BC3C: .4byte 0x000343FD
_0806BC40: .4byte 0x00269EC3
_0806BC44:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BC6C
	b _0806BDCA
_0806BC6C:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806BC78
	b _0806BDCA
_0806BC78:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
_0806BC7E:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #2
	cmp r0, r1
	ble _0806BC8E
	str r1, [r5, #0x60]
_0806BC8E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	beq _0806BCD6
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806BCD0
	adds r0, #1
	strb r0, [r5, #0x12]
	movs r0, #0xe8
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	b _0806BCD6
_0806BCD0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BCD6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0806BDCA
_0806BCDE:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BCE8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
_0806BD04:
	ldr r2, _0806BD54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BD58 @ =0x000343FD
	muls r0, r1, r0
	ldr r3, _0806BD5C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	movs r0, #5
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BD20:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	ldr r2, _0806BD54 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806BD58 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806BD5C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r0, r0, #1
	str r0, [r2]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0806BDC8
	.align 2, 0
_0806BD54: .4byte RNG_0202f388
_0806BD58: .4byte 0x000343FD
_0806BD5C: .4byte 0x00269EC3
_0806BD60:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r4, [r5, #0x28]
	ldr r0, [r3]
	ldr r1, [r4, #0x54]
	adds r0, r0, r1
	ldr r2, [r5, #0x54]
	cmp r2, r0
	ble _0806BD90
	ldr r0, _0806BD8C @ =0xFFFFFC80
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	bge _0806BDAA
	b _0806BDA2
	.align 2, 0
_0806BD8C: .4byte 0xFFFFFC80
_0806BD90:
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r2, r2, r1
	str r2, [r5, #0x54]
	ldr r1, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r1, r0
	cmp r2, r0
	ble _0806BDAA
_0806BDA2:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806BDAA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	beq _0806BDCA
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0806BDCA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806BDCA
	movs r0, #4
_0806BDC8:
	strb r0, [r5, #0xe]
_0806BDCA:
	ldr r2, [r5, #0x28]
	adds r0, r2, #0
	adds r0, #0xd4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0806BDFE
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806BE04 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r3, _0806BE08 @ =0xFFFFE800
	adds r0, r0, r3
	str r0, [r5, #0x58]
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r0, [r5, #0xf]
_0806BDFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806BE04: .4byte 0xFFFFF800
_0806BE08: .4byte 0xFFFFE800
