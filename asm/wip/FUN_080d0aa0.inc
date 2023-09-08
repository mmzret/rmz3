	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldrb r0, [r4, #0xf]
	cmp r0, #5
	bls _080D0AB4
	b _080D0C16
_080D0AB4:
	lsls r0, r0, #2
	ldr r1, _080D0AC0 @ =_080D0AC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D0AC0: .4byte _080D0AC4
_080D0AC4: @ jump table
	.4byte _080D0ADC @ case 0
	.4byte _080D0B24 @ case 1
	.4byte _080D0B50 @ case 2
	.4byte _080D0B88 @ case 3
	.4byte _080D0BC2 @ case 4
	.4byte _080D0BE4 @ case 5
_080D0ADC:
	adds r0, r4, #0
	bl InitScalerotMotion1
	cmp r5, #0
	beq _080D0AEC
	adds r0, r4, #0
	bl ResetDynamicMotion
_080D0AEC:
	adds r0, r4, #0
	adds r1, r6, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x50
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	bl PaintEntityWhite
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x68]
	ldr r0, _080D0B48 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _080D0B4C @ =0xFFFFA000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080D0B24:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	ble _080D0C16
	str r1, [r4, #0x58]
	movs r0, #0x9b
	bl PlaySound
	movs r0, #1
	strb r0, [r4, #0x12]
	b _080D0BBA
	.align 2, 0
_080D0B48: .4byte gStageRun+232
_080D0B4C: .4byte 0xFFFFA000
_080D0B50:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #6
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #5
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r2, #0
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x52
	strh r1, [r0]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080D0C16
	movs r0, #1
	strb r0, [r4, #0x12]
	b _080D0BBA
_080D0B88:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #2
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r2, #0
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #2
	adds r0, #0xe0
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080D0C16
_080D0BBA:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _080D0C16
_080D0BC2:
	adds r0, r4, #0
	bl InitNonAffineMotion
	cmp r5, #0
	beq _080D0BD2
	adds r0, r4, #0
	bl ResetDynamicMotion
_080D0BD2:
	adds r0, r4, #0
	adds r1, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080D0BE4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D0BFC
	adds r0, r4, #0
	bl UpdateEntityPaletteID
	b _080D0C02
_080D0BFC:
	adds r0, r4, #0
	bl PaintEntityWhite
_080D0C02:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080D0C16
	strb r0, [r4, #0xf]
	movs r0, #1
	b _080D0C18
_080D0C16:
	movs r0, #0
_080D0C18:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
