	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804e3f4
tretista_0804e3f4: @ 0x0804E3F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0804E4B4
	cmp r5, #1
	bgt _0804E408
	cmp r5, #0
	beq _0804E416
	b _0804E53C
_0804E408:
	cmp r5, #2
	bne _0804E40E
	b _0804E530
_0804E40E:
	cmp r5, #3
	bne _0804E414
	b _0804E534
_0804E414:
	b _0804E53C
_0804E416:
	ldr r1, _0804E458 @ =0x0000AB0A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E45C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E464
	ldr r1, _0804E460 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	ble _0804E48E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r3
	b _0804E48C
	.align 2, 0
_0804E458: .4byte 0x0000AB0A
_0804E45C: .4byte sCollisions+(24*1)
_0804E460: .4byte pZero2
_0804E464:
	ldr r1, _0804E49C @ =pZero2
	ldr r0, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	adds r6, r1, #0
	cmp r2, r0
	bge _0804E4A4
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804E48C:
	strb r0, [r4, #0xa]
_0804E48E:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0804E4A4
	ldr r0, _0804E4A0 @ =0xFFFFFEA0
	b _0804E4A8
	.align 2, 0
_0804E49C: .4byte pZero2
_0804E4A0: .4byte 0xFFFFFEA0
_0804E4A4:
	movs r0, #0xb0
	lsls r0, r0, #1
_0804E4A8:
	str r0, [r4, #0x5c]
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E4B4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x70]
	ldr r0, _0804E4F0 @ =0x00FFFF00
	ands r1, r0
	movs r0, #0x81
	lsls r0, r0, #9
	cmp r1, r0
	beq _0804E4CE
	ldr r0, _0804E4F4 @ =0x00010900
	cmp r1, r0
	bne _0804E4D4
_0804E4CE:
	movs r0, #0xde
	bl PlaySound
_0804E4D4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0804E4F8
	movs r1, #0xd8
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804E502
	.align 2, 0
_0804E4F0: .4byte 0x00FFFF00
_0804E4F4: .4byte 0x00010900
_0804E4F8:
	ldr r1, _0804E52C @ =0xFFFF9400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804E502:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804E512
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #1
	strb r0, [r4, #0x12]
_0804E512:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804E522
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804E53C
_0804E522:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804E53C
	.align 2, 0
_0804E52C: .4byte 0xFFFF9400
_0804E530:
	movs r0, #3
	strb r0, [r4, #0xe]
_0804E534:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E53C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
