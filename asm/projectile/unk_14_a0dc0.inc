	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _080A0DCE
	b _080A0F70
_080A0DCE:
	lsls r0, r0, #2
	ldr r1, _080A0DD8 @ =_080A0DDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A0DD8: .4byte _080A0DDC
_080A0DDC: @ jump table
	.4byte _080A0DFC @ case 0
	.4byte _080A0E1C @ case 1
	.4byte _080A0E68 @ case 2
	.4byte _080A0E88 @ case 3
	.4byte _080A0E96 @ case 4
	.4byte _080A0EEC @ case 5
	.4byte _080A0F1E @ case 6
	.4byte _080A0F28 @ case 7
_080A0DFC:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A0E40 @ =0x0836B11C
	bl SetDDP
	movs r0, #0x80
	str r0, [r4, #0x5c]
	ldr r1, _080A0E44 @ =0x00003701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0E1C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0E48
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	cmp r1, r0
	bgt _080A0E3C
	b _080A0F70
_080A0E3C:
	b _080A0EDE
	.align 2, 0
_080A0E40: .4byte 0x0836B11C
_080A0E44: .4byte 0x00003701
_080A0E48:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, _080A0E64 @ =0xFFFF9800
	adds r0, r0, r2
	cmp r1, r0
	blt _080A0E60
	b _080A0F70
_080A0E60:
	b _080A0EDE
	.align 2, 0
_080A0E64: .4byte 0xFFFF9800
_080A0E68:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _080A0E84 @ =0xFFFF7000
	adds r0, r0, r2
	cmp r1, r0
	bge _080A0F70
	str r0, [r4, #0x58]
	b _080A0EDE
	.align 2, 0
_080A0E84: .4byte 0xFFFF7000
_080A0E88:
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0E96:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A0EC0
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #0xb
	ldr r1, _080A0EBC @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r1, r1, r0
	cmp r2, r1
	ble _080A0F70
	b _080A0EDC
	.align 2, 0
_080A0EBC: .4byte 0xFFFFF800
_080A0EC0:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #0xb
	ldr r1, _080A0EE8 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	cmp r2, r1
	bge _080A0F70
_080A0EDC:
	str r1, [r4, #0x54]
_080A0EDE:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A0F70
	.align 2, 0
_080A0EE8: .4byte 0xFFFFF800
_080A0EEC:
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x68]
	subs r1, r1, r0
	cmp r2, r1
	ble _080A0F70
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r1, r5, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
	b _080A0F70
_080A0F1E:
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A0F28:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A0F70
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A0F6C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080A0F9C
	.align 2, 0
_080A0F6C: .4byte gProjectileFnTable
_080A0F70:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	adds r0, #0x30
	str r0, [r4, #0x5c]
	movs r1, #0xa0
	lsls r1, r1, #4
	cmp r0, r1
	ble _080A0F86
	str r1, [r4, #0x5c]
_080A0F86:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080A0F9E
	ldr r1, _080A0FA4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_080A0F9C:
	str r0, [r4, #0x14]
_080A0F9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0FA4: .4byte gProjectileFnTable
