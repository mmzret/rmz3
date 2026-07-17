	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08089a34
FUN_08089a34: @ 0x08089A34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08089A40
	b _08089B3E
_08089A40:
	lsls r0, r0, #2
	ldr r1, _08089A4C @ =_08089A50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08089A4C: .4byte _08089A50
_08089A50: @ jump table
	.4byte _08089A68 @ case 0
	.4byte _08089A88 @ case 1
	.4byte _08089AB8 @ case 2
	.4byte _08089AC6 @ case 3
	.4byte _08089B00 @ case 4
	.4byte _08089B0E @ case 5
_08089A68:
	movs r4, #0
	strb r4, [r5, #0x10]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08089AB0 @ =0x08368814
	bl SetDDP
	ldr r1, _08089AB4 @ =0x0000DD07
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089A88:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089AA2
	str r1, [r5, #0x60]
_08089AA2:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089AF2
	b _08089AEC
	.align 2, 0
_08089AB0: .4byte sCollisions
_08089AB4: .4byte 0x0000DD07
_08089AB8:
	ldr r1, _08089AFC @ =0x0000DD08
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089AC6:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089AE0
	str r1, [r5, #0x60]
_08089AE0:
	adds r0, r5, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089AF2
_08089AEC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089AF2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08089B3E
	.align 2, 0
_08089AFC: .4byte 0x0000DD08
_08089B00:
	ldr r1, _08089B44 @ =0x0000DD0E
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089B0E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089B2E
	str r1, [r5, #0x60]
_08089B2E:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089B3E
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_08089B3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089B44: .4byte 0x0000DD0E

	thumb_func_start FUN_08089b48
FUN_08089b48: @ 0x08089B48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089B58
	cmp r0, #1
	beq _08089C0E
	b _08089C84
_08089B58:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089BC0 @ =0x08368844
	bl SetDDP
	ldr r1, _08089BC4 @ =0x0000DD09
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08089BC8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	ldr r2, _08089BCC @ =0xFFFFF000
	adds r1, r1, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	adds r0, #0x10
	movs r5, #0xe0
	ands r5, r0
	ldr r1, _08089BD0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r1, #0
	cmp r0, #0
	ble _08089BB2
	movs r1, #1
_08089BB2:
	adds r2, r1, #0
	cmp r2, #0
	beq _08089BD4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08089BDA
	.align 2, 0
_08089BC0: .4byte sCollisions+(2*24)
_08089BC4: .4byte 0x0000DD09
_08089BC8: .4byte pZero2
_08089BCC: .4byte 0xFFFFF000
_08089BD0: .4byte gSineTable
_08089BD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08089BDA:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	ldr r1, _08089C8C @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089C0E:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08088c4c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089C28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _08089C28
	subs r0, #1
	strb r0, [r4, #0x12]
_08089C28:
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r4, #0x54]
	ldr r1, [r3]
	subs r2, r0, r1
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	ble _08089C3E
	adds r0, r1, r0
	str r0, [r4, #0x54]
_08089C3E:
	ldr r0, _08089C90 @ =0xFFFF6000
	cmp r2, r0
	bge _08089C4C
	ldr r0, [r3]
	ldr r5, _08089C90 @ =0xFFFF6000
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08089C4C:
	ldr r0, [r4, #0x5c]
	movs r1, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	bge _08089C58
	adds r0, #0xff
_08089C58:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	muls r0, r1, r0
	cmp r0, #0
	bge _08089C66
	adds r0, #0xff
_08089C66:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089C7E
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089C7E:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08089C84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089C8C: .4byte gSineTable
_08089C90: .4byte 0xFFFF6000

	thumb_func_start FUN_08089c94
FUN_08089c94: @ 0x08089C94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _08089CA0
	b _08089E56
_08089CA0:
	lsls r0, r0, #2
	ldr r1, _08089CAC @ =_08089CB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08089CAC: .4byte _08089CB0
_08089CB0: @ jump table
	.4byte _08089CD8 @ case 0
	.4byte _08089CF2 @ case 1
	.4byte _08089D6A @ case 2
	.4byte _08089DD4 @ case 3
	.4byte _08089D74 @ case 4
	.4byte _08089D82 @ case 5
	.4byte _08089DBC @ case 6
	.4byte _08089DD4 @ case 7
	.4byte _08089E10 @ case 8
	.4byte _08089E22 @ case 9
_08089CD8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089D10 @ =0x08368844
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089CF2:
	movs r2, #0
	ldr r0, _08089D14 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08089D04
	movs r2, #1
_08089D04:
	cmp r2, #0
	beq _08089D18
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08089D1E
	.align 2, 0
_08089D10: .4byte sCollisions+(2*24)
_08089D14: .4byte pZero2
_08089D18:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08089D1E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
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
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089D54
	str r1, [r4, #0x60]
_08089D54:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089DAE
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08089DAE
_08089D6A:
	ldr r1, _08089D70 @ =0x0000DD0A
	b _08089DC8
	.align 2, 0
_08089D70: .4byte 0x0000DD0A
_08089D74:
	ldr r1, _08089DB8 @ =0x0000DD0B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089D82:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089D9C
	str r1, [r4, #0x60]
_08089D9C:
	adds r0, r4, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089DAE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089DAE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08089E56
	.align 2, 0
_08089DB8: .4byte 0x0000DD0B
_08089DBC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089E08 @ =0x08368814
	bl SetDDP
	ldr r1, _08089E0C @ =0x0000DD0F
_08089DC8:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089DD4:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089DEE
	str r1, [r4, #0x60]
_08089DEE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089E56
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08089E56
	.align 2, 0
_08089E08: .4byte sCollisions
_08089E0C: .4byte 0x0000DD0F
_08089E10:
	ldr r1, _08089E5C @ =0x0000DD0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089E22:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089E3C
	str r1, [r4, #0x60]
_08089E3C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089E50
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089E50:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08089E56:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089E5C: .4byte 0x0000DD0B

