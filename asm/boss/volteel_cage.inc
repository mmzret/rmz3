	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xf
	bls _08044CC4
	b _08044EF2
_08044CC4:
	lsls r0, r0, #2
	ldr r1, _08044CD0 @ =_08044CD4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044CD0: .4byte _08044CD4
_08044CD4: @ jump table
	.4byte _08044D14 @ case 0
	.4byte _08044D74 @ case 1
	.4byte _08044D82 @ case 2
	.4byte _08044EF2 @ case 3
	.4byte _08044EF2 @ case 4
	.4byte _08044EF2 @ case 5
	.4byte _08044EF2 @ case 6
	.4byte _08044EF2 @ case 7
	.4byte _08044EF2 @ case 8
	.4byte _08044EF2 @ case 9
	.4byte _08044DDC @ case 10
	.4byte _08044DFC @ case 11
	.4byte _08044E2C @ case 12
	.4byte _08044E78 @ case 13
	.4byte _08044E98 @ case 14
	.4byte _08044EDC @ case 15
_08044D14:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08044D48
	ldr r0, [r4, #0x54]
	movs r1, #0xd8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08044D40 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _08044D44
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044D40: .4byte 0xFFFFF800
_08044D44:
	movs r0, #0xa
	b _08044EF0
_08044D48:
	ldr r0, [r4, #0x54]
	ldr r1, _08044D68 @ =0xFFFFCA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08044D6C @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _08044D70
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044D68: .4byte 0xFFFFCA00
_08044D6C: .4byte 0xFFFFF800
_08044D70:
	movs r0, #0xa
	b _08044EF0
_08044D74:
	ldr r1, _08044DB8 @ =0x0000A507
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044D82:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08044D94
	b _08044EF2
_08044D94:
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08044DBC
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	b _08044DD6
	.align 2, 0
_08044DB8: .4byte 0x0000A507
_08044DBC:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08044DD6:
	strb r0, [r4, #0xa]
	movs r0, #0xa
	b _08044EF0
_08044DDC:
	movs r0, #0x46
	strb r0, [r4, #0x12]
	ldr r1, _08044E24 @ =0x0000A508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044E28 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x12
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044DFC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08044EF2
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08044E1C
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044EF2
_08044E1C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044E24: .4byte 0x0000A508
_08044E28: .4byte sCollisions+(24*1)
_08044E2C:
	ldr r1, _08044E54 @ =0x0000A509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044E58 @ =0x083623A8
	bl SetDDP
	ldr r2, _08044E5C @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _08044E64
	ldr r0, _08044E60 @ =0x0002D024
	b _08044E66
	.align 2, 0
_08044E54: .4byte 0x0000A509
_08044E58: .4byte 0x083623A8
_08044E5C: .4byte gOverworld
_08044E60: .4byte 0x0002D024
_08044E64:
	ldr r0, _08044E94 @ =0x0002D026
_08044E66:
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x7d
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044E78:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08044E8E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08044EF2
_08044E8E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08044EF0
	.align 2, 0
_08044E94: .4byte 0x0002D026
_08044E98:
	ldr r1, _08044EB8 @ =0x0000A50A
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08044EBC @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _08044EC4
	ldr r0, _08044EC0 @ =0x0002D024
	b _08044EC6
	.align 2, 0
_08044EB8: .4byte 0x0000A50A
_08044EBC: .4byte gOverworld
_08044EC0: .4byte 0x0002D024
_08044EC4:
	ldr r0, _08044EF8 @ =0x0002D026
_08044EC6:
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08044EFC @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08044EDC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08044EF2
	movs r0, #0
	strb r1, [r4, #0xd]
_08044EF0:
	strb r0, [r4, #0xe]
_08044EF2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08044EF8: .4byte 0x0002D026
_08044EFC: .4byte sCollisions+(24*1)
