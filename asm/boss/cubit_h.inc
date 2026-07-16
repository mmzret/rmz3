	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitMode8
cubitMode8: @ 0x08053A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xe
	bls _08053A18
	b _08053CFC
_08053A18:
	lsls r0, r0, #2
	ldr r1, _08053A24 @ =_08053A28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053A24: .4byte _08053A28
_08053A28: @ jump table
	.4byte _08053A64 @ case 0
	.4byte _08053A9A @ case 1
	.4byte _08053AA8 @ case 2
	.4byte _08053B02 @ case 3
	.4byte _08053B48 @ case 4
	.4byte _08053B56 @ case 5
	.4byte _08053B70 @ case 6
	.4byte _08053B98 @ case 7
	.4byte _08053C24 @ case 8
	.4byte _08053C5C @ case 9
	.4byte _08053C84 @ case 10
	.4byte _08053C9C @ case 11
	.4byte _08053CAE @ case 12
	.4byte _08053CCC @ case 13
	.4byte _08053CDE @ case 14
_08053A64:
	ldr r0, _08053A84 @ =pZero2
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd8
	ldr r2, [r0, #0x54]
	ldr r0, [r1]
	cmp r2, r0
	ble _08053A88
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053A80
	b _08053CC0
_08053A80:
	b _08053A94
	.align 2, 0
_08053A84: .4byte pZero2
_08053A88:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08053A94
	b _08053CC0
_08053A94:
	movs r0, #3
	strb r0, [r4, #0xe]
	b _08053CFC
_08053A9A:
	ldr r1, _08053AF4 @ =0x0000B003
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053AA8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053ABA
	b _08053CFC
_08053ABA:
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
	beq _08053AF8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08053AFE
	.align 2, 0
_08053AF4: .4byte 0x0000B003
_08053AF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08053AFE:
	strb r0, [r4, #0xa]
	b _08053CC0
_08053B02:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053B24
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053B20 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053B34
	.align 2, 0
_08053B20: .4byte 0xFFFFF800
_08053B24:
	ldr r0, [r4, #0x54]
	ldr r1, _08053B40 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053B44 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053B34:
	cmp r0, #0
	bne _08053B3A
	b _08053CC0
_08053B3A:
	movs r0, #9
	strb r0, [r4, #0xe]
	b _08053CFC
	.align 2, 0
_08053B40: .4byte 0xFFFFE400
_08053B44: .4byte 0xFFFFF800
_08053B48:
	ldr r1, _08053B6C @ =0x0000B004
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053B56:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08053B68
	b _08053CFC
_08053B68:
	b _08053CC0
	.align 2, 0
_08053B6C: .4byte 0x0000B004
_08053B70:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053B7E
	movs r0, #0x40
	b _08053B82
_08053B7E:
	movs r0, #0x40
	rsbs r0, r0, #0
_08053B82:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	ldr r1, _08053BBC @ =0x0000B005
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053B98:
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _08053BA6
	rsbs r0, r0, #0
_08053BA6:
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r0, r2
	ble _08053BC4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053BC0
	str r2, [r4, #0x5c]
	b _08053BC4
	.align 2, 0
_08053BBC: .4byte 0x0000B005
_08053BC0:
	ldr r0, _08053BF8 @ =0xFFFFFC00
	str r0, [r4, #0x5c]
_08053BC4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08053C00
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053BFC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	b _08053C10
	.align 2, 0
_08053BF8: .4byte 0xFFFFFC00
_08053BFC: .4byte 0xFFFFF800
_08053C00:
	ldr r0, [r4, #0x54]
	ldr r1, _08053C1C @ =0xFFFFDC00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08053C20 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
_08053C10:
	cmp r0, #0
	beq _08053CFC
	movs r0, #0x14
	strb r0, [r4, #0x12]
	b _08053CC0
	.align 2, 0
_08053C1C: .4byte 0xFFFFDC00
_08053C20: .4byte 0xFFFFF800
_08053C24:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #6
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08053CC0
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053CFC
	b _08053CC0
_08053C5C:
	ldr r1, _08053C98 @ =0x0000B00D
	adds r0, r4, #0
	bl SetMotion
	movs r0, #9
	strb r0, [r4, #0x12]
	movs r0, #4
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl cubit_080a6078
	adds r1, r4, #0
	adds r1, #0xcc
	str r0, [r1]
	movs r0, #0xcd
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053C84:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08053CFC
	b _08053CC0
	.align 2, 0
_08053C98: .4byte 0x0000B00D
_08053C9C:
	ldr r1, _08053CC8 @ =0x0000B00E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053CAE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08053CFC
_08053CC0:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08053CFC
	.align 2, 0
_08053CC8: .4byte 0x0000B00E
_08053CCC:
	ldr r1, _08053D04 @ =0x0000B001
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08053CDE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08053CF4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053CFC
_08053CF4:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08053CFC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053D04: .4byte 0x0000B001

