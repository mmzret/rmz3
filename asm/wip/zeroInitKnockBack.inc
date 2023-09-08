	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #1
	strb r4, [r5, #0xf]
	movs r0, #0xa
	bl PlaySound
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	ands r0, r4
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	cmp r0, r1
	beq _0802BD5C
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	b _0802BD66
_0802BD5C:
	movs r1, #0xc4
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
_0802BD66:
	adds r4, r5, #0
	adds r4, #0xb4
	ldrb r0, [r4, #0x10]
	adds r6, r4, #0
	cmp r0, #2
	beq _0802BD82
	adds r0, r5, #0
	movs r1, #0x1f
	bl IsElfUsed
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0802BDAC
_0802BD82:
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802BDA8
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BE28
	ldr r0, _0802BDA4 @ =0xFFFFFF00
	b _0802BE2C
	.align 2, 0
_0802BDA4: .4byte 0xFFFFFF00
_0802BDA8:
	str r0, [r5, #0x5c]
	b _0802BE30
_0802BDAC:
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802BDF0
	strb r2, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BDD0
	ldr r0, _0802BDCC @ =0xFFFFFC00
	b _0802BDD4
	.align 2, 0
_0802BDCC: .4byte 0xFFFFFC00
_0802BDD0:
	movs r0, #0x80
	lsls r0, r0, #3
_0802BDD4:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x5c]
	str r0, [r6, #0x54]
	ldr r0, _0802BDEC @ =0xFFFFFBC0
	str r0, [r5, #0x60]
	movs r0, #2
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	bl zeroAirKnockBack
	b _0802BE56
	.align 2, 0
_0802BDEC: .4byte 0xFFFFFBC0
_0802BDF0:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0802BE12
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BE0C
	ldr r0, _0802BE08 @ =0xFFFFFE00
	b _0802BE2C
	.align 2, 0
_0802BE08: .4byte 0xFFFFFE00
_0802BE0C:
	movs r0, #0x80
	lsls r0, r0, #2
	b _0802BE2C
_0802BE12:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BE28
	ldr r0, _0802BE24 @ =0xFFFFFF00
	b _0802BE2C
	.align 2, 0
_0802BE24: .4byte 0xFFFFFF00
_0802BE28:
	movs r0, #0x80
	lsls r0, r0, #1
_0802BE2C:
	str r0, [r5, #0x5c]
	movs r0, #0
_0802BE30:
	str r0, [r5, #0x60]
	ldr r2, _0802BE48 @ =0x0000018D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BE4C
	movs r0, #1
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	bl zeroKnockBack
	b _0802BE56
	.align 2, 0
_0802BE48: .4byte 0x0000018D
_0802BE4C:
	movs r0, #2
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	bl zeroAirKnockBack
_0802BE56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
