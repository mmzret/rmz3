	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804e8f4
FUN_0804e8f4: @ 0x0804E8F4
	movs r0, #1
	bx lr

	thumb_func_start FUN_0804e8f8
FUN_0804e8f8: @ 0x0804E8F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804E904
	b _0804EB26
_0804E904:
	lsls r0, r0, #2
	ldr r1, _0804E910 @ =_0804E914
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E910: .4byte _0804E914
_0804E914: @ jump table
	.4byte _0804E938 @ case 0
	.4byte _0804E9AA @ case 1
	.4byte _0804E9C0 @ case 2
	.4byte _0804EA1A @ case 3
	.4byte _0804EA32 @ case 4
	.4byte _0804EA50 @ case 5
	.4byte _0804EA62 @ case 6
	.4byte _0804EAE4 @ case 7
	.4byte _0804EB10 @ case 8
_0804E938:
	ldr r1, _0804E964 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804E968 @ =sCollisions+(24*1)
	bl SetDDP
	ldr r0, _0804E96C @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804E970
	ldr r0, [r4, #0x54]
	cmp r5, r0
	ble _0804E982
	b _0804E976
	.align 2, 0
_0804E964: .4byte 0x0000AB0C
_0804E968: .4byte sCollisions+(24*1)
_0804E96C: .4byte pZero2
_0804E970:
	ldr r0, [r4, #0x54]
	cmp r5, r0
	bge _0804E982
_0804E976:
	ldr r1, _0804E9B8 @ =0x0000AB0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0x13]
_0804E982:
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
_0804E9AA:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0804E9BC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804E9B8: .4byte 0x0000AB0B
_0804E9BC:
	movs r0, #4
	b _0804EB24
_0804E9C0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804E9D2
	b _0804EB26
_0804E9D2:
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
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _0804EA0C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0804EA12
_0804EA0C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804EA12:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
_0804EA1A:
	ldr r1, _0804EA48 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EA4C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EA32:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804EB26
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804EA48: .4byte 0x0000AB0C
_0804EA4C: .4byte sCollisions+(24*1)
_0804EA50:
	ldr r1, _0804EAA4 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EA62:
	ldr r2, [r4, #0x60]
	adds r2, #0x20
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	ble _0804EA8E
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804EA8E
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EAA8 @ =0x08363410
	bl SetDDP
_0804EA8E:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0804EAAC
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804EAB8
	.align 2, 0
_0804EAA4: .4byte 0x0000AB0D
_0804EAA8: .4byte 0x08363410
_0804EAAC:
	ldr r0, [r4, #0x54]
	ldr r2, _0804EAE0 @ =0xFFFFD800
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804EAB8:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804EAC4
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804EAC4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804EADA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804EB26
_0804EADA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804EB24
	.align 2, 0
_0804EAE0: .4byte 0xFFFFD800
_0804EAE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EB2C @ =sCollisions+(24*1)
	bl SetDDP
	ldr r1, _0804EB30 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EB34 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	movs r0, #0xde
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EB10:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804EB26
	movs r0, #0
	strb r1, [r4, #0xd]
_0804EB24:
	strb r0, [r4, #0xe]
_0804EB26:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804EB2C: .4byte sCollisions+(24*1)
_0804EB30: .4byte 0x0000AB0F
_0804EB34: .4byte 0xFFFFF000

	thumb_func_start FUN_0804eb38
FUN_0804eb38: @ 0x0804EB38
	movs r0, #1
	bx lr
