	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080CFB48
	cmp r5, #1
	beq _080CFB84
	b _080CFBC4
_080CFB48:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CFBCC @ =0x08370694
	bl SetDDP
	ldr r1, _080CFBD0 @ =0x00006D0D
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r4, #0x58]
	str r0, [r1]
	str r5, [r4, #0x5c]
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r2, r0, #0
	ldr r0, _080CFBD4 @ =pZero2
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CFB7C
	movs r2, #0x20
_080CFB7C:
	str r2, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CFB84:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0xe0
	lsls r0, r0, #2
	cmp r1, r0
	ble _080CFB9C
	str r0, [r4, #0x5c]
_080CFB9C:
	ldr r0, [r4, #0x5c]
	ldr r1, _080CFBD8 @ =0xFFFFFC80
	cmp r0, r1
	bge _080CFBA6
	str r1, [r4, #0x5c]
_080CFBA6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	bl FUN_080cf428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CFBC4
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
_080CFBC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFBCC: .4byte 0x08370694
_080CFBD0: .4byte 0x00006D0D
_080CFBD4: .4byte pZero2
_080CFBD8: .4byte 0xFFFFFC80
