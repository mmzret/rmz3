	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08097924
FUN_08097924: @ 0x08097924
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097934
	cmp r0, #1
	beq _080979E8
	b _08097A0C
_08097934:
	adds r1, r4, #0
	adds r1, #0xbe
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08096fb0
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097974 @ =0x0836A288
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08097994
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _08097978
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r2, r0
	bgt _08097982
	b _080979E2
	.align 2, 0
_08097974: .4byte sCollisions
_08097978:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	ble _080979E2
_08097982:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_08097994:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _080979A8
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	bgt _080979B2
	b _080979E2
_080979A8:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _080979E2
_080979B2:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_080979C4:
	movs r0, #0xef
	ands r0, r2
_080979C8:
	strb r0, [r4, #0xa]
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
_080979E2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080979E8:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08096ffc
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08097A06
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097A06:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08097A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097a14
cannonHopper_08097a14: @ 0x08097A14
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097A24
	cmp r0, #1
	beq _08097A60
	b _08097AF0
_08097A24:
	ldr r1, _08097A7C @ =0x0000DC01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x15
	strb r0, [r4, #0x12]
	ldr r0, _08097A80 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08097A44
	movs r2, #0x80
	lsls r2, r2, #2
_08097A44:
	str r2, [r4, #0x5c]
	ldr r0, _08097A84 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	adds r2, r0, #0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097A58
	movs r2, #0x80
	lsls r2, r2, #3
_08097A58:
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08097A60:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08097A8C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08097AEA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097A88 @ =0x0836A2B8
	bl SetDDP
	b _08097AEA
	.align 2, 0
_08097A7C: .4byte 0x0000DC01
_08097A80: .4byte 0xFFFFFE00
_08097A84: .4byte 0xFFFFFC00
_08097A88: .4byte sCollisions+(2*24)
_08097A8C:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08097224
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq _08097AD4
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097AB0
	movs r0, #0x10
	orrs r0, r2
	b _08097AB4
_08097AB0:
	movs r0, #0xef
	ands r0, r2
_08097AB4:
	strb r0, [r4, #0xa]
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
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
_08097AD4:
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #9
	bgt _08097AEA
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097AEA:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08097AF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097af8
cannonHopper_08097af8: @ 0x08097AF8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _08097B08
	cmp r4, #1
	beq _08097B20
	b _08097CBC
_08097B08:
	adds r0, r6, #0
	adds r0, #0xbe
	strb r4, [r0]
	ldr r1, _08097B40 @ =0x0000DC02
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08097B20:
	ldrb r0, [r6, #0x13]
	cmp r0, #8
	bls _08097B48
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08097B44 @ =0x0836A348
	adds r0, r4, #0
	bl SetDDP
	adds r1, r6, #0
	adds r1, #0xbe
	movs r0, #4
	strb r0, [r1]
	adds r7, r1, #0
	adds r5, r4, #0
	b _08097B72
	.align 2, 0
_08097B40: .4byte 0x0000DC02
_08097B44: .4byte sCollisions+(8*24)
_08097B48:
	adds r5, r6, #0
	adds r5, #0x74
	ldr r4, _08097BB0 @ =0x0836A424
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _08097BB4 @ =0x0836A288
	adds r1, r1, r0
	adds r0, r5, #0
	bl SetDDP
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0xbe
	strb r1, [r0]
	adds r7, r0, #0
_08097B72:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	movs r4, #0
	strb r0, [r6, #0x13]
	ldr r1, [r6, #0x5c]
	ldr r2, [r6, #0x60]
	adds r0, r6, #0
	bl FUN_08097224
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08097B98
	str r4, [r6, #0x5c]
	str r4, [r6, #0x60]
	strb r1, [r6, #0x12]
_08097B98:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08097BDC
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _08097BB8
	movs r0, #0x10
	orrs r0, r2
	b _08097BBC
	.align 2, 0
_08097BB0: .4byte u8_ARRAY_0836a424
_08097BB4: .4byte sCollisions
_08097BB8:
	movs r0, #0xef
	ands r0, r2
_08097BBC:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6, #0x5c]
	rsbs r0, r0, #0
	str r0, [r6, #0x5c]
_08097BDC:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08097C64
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08097C64
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08097C06
	ldr r0, [r6, #0x58]
	movs r1, #0xbc
	lsls r1, r1, #6
	b _08097C0A
_08097C06:
	ldr r0, [r6, #0x58]
	ldr r1, _08097C20 @ =0xFFFFD100
_08097C0A:
	adds r0, r0, r1
	str r0, [r6, #0x58]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x1d
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097C24
	movs r0, #0x20
	orrs r0, r2
	b _08097C28
	.align 2, 0
_08097C20: .4byte 0xFFFFD100
_08097C24:
	movs r0, #0xdf
	ands r0, r2
_08097C28:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r4, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08097C60 @ =0x0836A288
	adds r0, r5, #0
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r7]
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _08097CBC
	.align 2, 0
_08097C60: .4byte sCollisions
_08097C64:
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097C7E
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r1, r0
	b _08097C8C
_08097C7E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r0, r1
_08097C8C:
	ldr r0, _08097CC4 @ =0x00001FFF
	cmp r1, r0
	bgt _08097CB6
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CA0
	adds r0, #0xff
_08097CA0:
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CB2
	adds r0, #0xff
_08097CB2:
	asrs r0, r0, #8
	str r0, [r6, #0x60]
_08097CB6:
	adds r0, r6, #0
	bl UpdateEntityAnim
_08097CBC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097CC4: .4byte 0x00001FFF

