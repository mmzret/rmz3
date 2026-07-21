	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start sharksealxMode4
sharksealxMode4: @ 0x08070C6C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	bls _08070C78
	b _08070F2C
_08070C78:
	lsls r0, r0, #2
	ldr r1, _08070C84 @ =_08070C88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070C84: .4byte _08070C88
_08070C88: @ jump table
	.4byte _08070CB4 @ case 0
	.4byte _08070D1E @ case 1
	.4byte _08070D6C @ case 2
	.4byte _08070DA4 @ case 3
	.4byte _08070DC4 @ case 4
	.4byte _08070F2C @ case 5
	.4byte _08070F2C @ case 6
	.4byte _08070F2C @ case 7
	.4byte _08070F2C @ case 8
	.4byte _08070F2C @ case 9
	.4byte _08070E5C @ case 10
_08070CB4:
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070CF0 @ =sCollisions
	bl SetDDP
	movs r2, #0
	str r2, [r4, #0x60]
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08070CF4
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bne _08070D0A
	strb r0, [r4, #0xf]
	b _08070D0C
	.align 2, 0
_08070CF0: .4byte sCollisions
_08070CF4:
	str r2, [r4, #0x5c]
	movs r0, #0x20
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070D0A
	movs r0, #1
	strb r0, [r4, #0xf]
	b _08070D0C
_08070D0A:
	strb r2, [r4, #0xf]
_08070D0C:
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070D1E:
	ldr r1, _08070D60 @ =gSineTable
	ldrb r2, [r4, #0x13]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r2, #4
	strb r2, [r4, #0x13]
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl forceWaterLanding
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08070D52
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08070D52
	b _08070F2C
_08070D52:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _08070D64
	ldrb r0, [r4, #0xe]
	adds r0, #2
	strb r0, [r4, #0xe]
	b _08070F2C
	.align 2, 0
_08070D60: .4byte gSineTable
_08070D64:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08070F2C
_08070D6C:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070D7E
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08070D84
_08070D7E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070D84:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	b _08070DEE
_08070DA4:
	ldr r1, _08070DF4 @ =0x00001801
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070DF8 @ =0x08366A74
	bl SetDDP
	movs r0, #0xc
	strb r0, [r4, #0x12]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08070DC4:
	adds r0, r4, #0
	bl forceWaterLanding
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08070DDA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070E4C
_08070DDA:
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08070E4C
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08070DFC
_08070DEE:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08070F2C
	.align 2, 0
_08070DF4: .4byte 0x00001801
_08070DF8: .4byte sCollisions+(24*2)
_08070DFC:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
	ldrb r2, [r0]
	cmp r2, #0
	beq _08070E16
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08070E1C
_08070E16:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08070E1C:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
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
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08070E54 @ =sCollisions
	bl SetDDP
	ldr r1, _08070E58 @ =0x00001806
	adds r0, r4, #0
	bl SetMotion
_08070E4C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08070F2C
	.align 2, 0
_08070E54: .4byte sCollisions
_08070E58: .4byte 0x00001806
_08070E5C:
	ldr r1, [r4, #0x5c]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08070E72
	ldr r0, _08070E88 @ =0xFFFFFE00
	cmp r1, r0
	bge _08070E74
_08070E72:
	str r0, [r4, #0x5c]
_08070E74:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x68]
	cmp r1, r0
	ble _08070E90
	ldr r2, _08070E8C @ =0xFFFFFF00
	b _08070E94
	.align 2, 0
_08070E88: .4byte 0xFFFFFE00
_08070E8C: .4byte 0xFFFFFF00
_08070E90:
	movs r2, #0x80
	lsls r2, r2, #1
_08070E94:
	adds r0, r1, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl forceWaterLanding
	ldr r2, [r4, #0x5c]
	cmp r2, #0
	bge _08070EA6
	rsbs r2, r2, #0
_08070EA6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r4, #0x54]
	ldr r6, [r0]
	subs r5, r1, r6
	adds r7, r0, #0
	adds r3, r1, #0
	cmp r5, #0
	ble _08070EBE
	cmp r5, r2
	ble _08070EC4
	b _08070ECA
_08070EBE:
	subs r0, r6, r3
	cmp r0, r2
	bgt _08070ECA
_08070EC4:
	movs r1, #0
	movs r0, #1
	b _08070F22
_08070ECA:
	ldr r1, [r7]
	subs r2, r3, r1
	cmp r2, #0
	ble _08070EDC
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	ble _08070EE6
	b _08070F26
_08070EDC:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _08070F26
_08070EE6:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _08070F00
	ldr r0, _08070EFC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r3, r0
	b _08070F08
	.align 2, 0
_08070EFC: .4byte pZero2
_08070F00:
	ldr r0, _08070F34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r3
_08070F08:
	ldr r0, _08070F38 @ =0x00007FFF
	cmp r1, r0
	bgt _08070F26
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r7]
	subs r1, r3, r0
	cmp r1, #0
	bgt _08070F1C
	subs r1, r0, r3
_08070F1C:
	str r1, [r2]
	movs r1, #0
	movs r0, #2
_08070F22:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08070F26:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08070F2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070F34: .4byte pZero2
_08070F38: .4byte 0x00007FFF

