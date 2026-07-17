	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start sharksealxMode3
sharksealxMode3: @ 0x08070994
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _080709A0
	b _08070C5A
_080709A0:
	lsls r0, r0, #2
	ldr r1, _080709AC @ =_080709B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080709AC: .4byte _080709B0
_080709B0: @ jump table
	.4byte _080709C8 @ case 0
	.4byte _08070A22 @ case 1
	.4byte _08070B0C @ case 2
	.4byte _08070B16 @ case 3
	.4byte _08070B74 @ case 4
	.4byte _08070B94 @ case 5
_080709C8:
	movs r0, #0
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080709F4 @ =sCollisions
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _080709F8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080709FE
	.align 2, 0
_080709F4: .4byte sCollisions
_080709F8:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080709FE:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070A22:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, _08070A4C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070A50 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _08070A54
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bge _08070A42
	movs r0, #0
	str r0, [r5, #0x60]
_08070A42:
	ldr r2, [r5, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	b _08070A62
	.align 2, 0
_08070A4C: .4byte pZero2
_08070A50: .4byte 0xFFFFEC00
_08070A54:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08070A5E
	movs r0, #0
	str r0, [r5, #0x60]
_08070A5E:
	ldr r2, [r5, #0x60]
	ldr r1, _08070A90 @ =0xFFFFFF00
_08070A62:
	subs r1, r1, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x60]
	ldr r0, [r5, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08070A98
	ldr r0, [r5, #0x5c]
	ldr r1, _08070A94 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	cmp r0, r1
	bge _08070AA8
	b _08070AA6
	.align 2, 0
_08070A90: .4byte 0xFFFFFF00
_08070A94: .4byte 0xFFFFFE00
_08070A98:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	cmp r0, r1
	ble _08070AA8
_08070AA6:
	str r1, [r5, #0x5c]
_08070AA8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r4, r5, #0
	adds r4, #0xb8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r6]
	cmp r0, #0
	bne _08070AD8
	ldr r0, _08070AD4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _08070AEA
	b _08070AE4
	.align 2, 0
_08070AD4: .4byte pZero2
_08070AD8:
	ldr r0, _08070B08 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08070AEA
_08070AE4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070AEA:
	ldr r4, [r4]
	cmp r4, #0
	bge _08070AF2
	rsbs r4, r4, #0
_08070AF2:
	movs r0, #0x90
	lsls r0, r0, #9
	cmp r4, r0
	bgt _08070AFC
	b _08070C5A
_08070AFC:
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070B08: .4byte pZero2
_08070B0C:
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070B16:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r1, [r5, #0x60]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r1, r0
	str r3, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	rsbs r2, r1, #0
	movs r0, #0xb
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _08070B6C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070B70 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r1, r3
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08070B62
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070C5A
_08070B62:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070B6C: .4byte pZero2
_08070B70: .4byte 0xFFFFEC00
_08070B74:
	ldr r1, _08070BF4 @ =0x00001801
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08070BF8 @ =0x08366A74
	bl SetDDP
	movs r0, #0xc
	strb r0, [r5, #0x12]
	movs r0, #2
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08070B94:
	ldr r1, [r5, #0x60]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r3, r1, r0
	str r3, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	rsbs r2, r1, #0
	movs r0, #0xb
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, _08070BFC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _08070C00 @ =0xFFFFEC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r1, r3
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl forceWaterLanding
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08070BDA
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070C54
_08070BDA:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08070C54
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08070C04
	strb r0, [r5, #0xe]
	b _08070C5A
	.align 2, 0
_08070BF4: .4byte 0x00001801
_08070BF8: .4byte sCollisions+(24*2)
_08070BFC: .4byte pZero2
_08070C00: .4byte 0xFFFFEC00
_08070C04:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070C1E
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08070C24
_08070C1E:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070C24:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08070C60 @ =sCollisions
	bl SetDDP
	ldr r1, _08070C64 @ =0x00001806
	adds r0, r5, #0
	bl SetMotion
_08070C54:
	adds r0, r5, #0
	bl UpdateEntityAnim
_08070C5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08070C60: .4byte sCollisions
_08070C64: .4byte 0x00001806

