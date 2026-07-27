	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807e5f4
FUN_0807e5f4: @ 0x0807E5F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x19
	bls _0807E600
	b _0807EACC
_0807E600:
	lsls r0, r0, #2
	ldr r1, _0807E60C @ =_0807E610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E60C: .4byte _0807E610
_0807E610: @ jump table
	.4byte _0807E678 @ case 0
	.4byte _0807E70A @ case 1
	.4byte _0807E748 @ case 2
	.4byte _0807E81E @ case 3
	.4byte _0807E884 @ case 4
	.4byte _0807EA7A @ case 5
	.4byte _0807E8A8 @ case 6
	.4byte _0807E8BA @ case 7
	.4byte _0807EA7A @ case 8
	.4byte _0807E910 @ case 9
	.4byte _0807EAAE @ case 10
	.4byte _0807EACC @ case 11
	.4byte _0807EACC @ case 12
	.4byte _0807EACC @ case 13
	.4byte _0807EACC @ case 14
	.4byte _0807EACC @ case 15
	.4byte _0807EACC @ case 16
	.4byte _0807EACC @ case 17
	.4byte _0807EACC @ case 18
	.4byte _0807EACC @ case 19
	.4byte _0807E920 @ case 20
	.4byte _0807E9F6 @ case 21
	.4byte _0807EA5C @ case 22
	.4byte _0807EA7A @ case 23
	.4byte _0807EA9C @ case 24
	.4byte _0807EAAE @ case 25
_0807E678:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807E6C8 @ =0x0000AB1B
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E6CC @ =sCollisions+(7*24)
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r2, [r0]
	cmp r2, #0
	bne _0807E6D4
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, _0807E6D0 @ =0xFFFFF800
	b _0807E6FA
	.align 2, 0
_0807E6C8: .4byte 0x0000AB1B
_0807E6CC: .4byte sCollisions+(7*24)
_0807E6D0: .4byte 0xFFFFF800
_0807E6D4:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #4
_0807E6FA:
	str r0, [r5, #0x5c]
	ldr r0, _0807E744 @ =0xFFFFFC60
	str r0, [r5, #0x60]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E70A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807E732
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E732
	b _0807EACC
_0807E732:
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E73E
	b _0807EA8A
_0807E73E:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0807EACC
	.align 2, 0
_0807E744: .4byte 0xFFFFFC60
_0807E748:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E798 @ =sCollisions+(5*24)
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r0, [r5, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0807E7A4
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0807E79C @ =0xFFFF7400
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	ldr r1, _0807E7A0 @ =0xFFFFF000
	b _0807E7D4
	.align 2, 0
_0807E798: .4byte sCollisions+(5*24)
_0807E79C: .4byte 0xFFFF7400
_0807E7A0: .4byte 0xFFFFF000
_0807E7A4:
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0x8c
	lsls r2, r2, #8
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
_0807E7D4:
	adds r6, r0, r1
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0807E874 @ =0xFFFF6000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r1, _0807E878 @ =0x0000AC05
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x1e
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x1e
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x1d
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E81E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807E82E
	str r1, [r5, #0x60]
_0807E82E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0807E85C
	ldr r0, [r5, #0x28]
	ldr r2, _0807E87C @ =0xFFC70054
	adds r0, r0, r2
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807E85C
	movs r0, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807E880 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807E85C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0807E86E
	b _0807EACC
_0807E86E:
	str r0, [r5, #0x58]
	b _0807EA8A
	.align 2, 0
_0807E874: .4byte 0xFFFF6000
_0807E878: .4byte 0x0000AC05
_0807E87C: .4byte 0xFFC70054
_0807E880: .4byte 0x0000AC06
_0807E884:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E8A0 @ =sCollisions+(1*24)
	bl SetDDP
	ldr r1, _0807E8A4 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	b _0807EA74
	.align 2, 0
_0807E8A0: .4byte sCollisions+(1*24)
_0807E8A4: .4byte 0x0000AC07
_0807E8A8:
	ldr r1, _0807E8EC @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E8BA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807E8D2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E8D2
	b _0807EACC
_0807E8D2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807E8F0
	movs r0, #0x10
	orrs r0, r2
	b _0807E8F4
	.align 2, 0
_0807E8EC: .4byte 0x0000AC09
_0807E8F0:
	movs r0, #0xef
	ands r0, r2
_0807E8F4:
	strb r0, [r5, #0xa]
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
	b _0807EACC
_0807E910:
	ldr r1, _0807E91C @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x1e
	b _0807EAA6
	.align 2, 0
_0807E91C: .4byte 0x0000AC01
_0807E920:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E974 @ =sCollisions+(5*24)
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r0, [r5, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0807E97C
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0x8c
	lsls r2, r2, #8
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	ldr r1, _0807E978 @ =0xFFFFD000
	b _0807E9AC
	.align 2, 0
_0807E974: .4byte sCollisions+(5*24)
_0807E978: .4byte 0xFFFFD000
_0807E97C:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0807EA48 @ =0xFFFF7400
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #6
_0807E9AC:
	adds r6, r0, r1
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0807EA4C @ =0xFFFF6000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r1, _0807EA50 @ =0x0000AC05
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x1e
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x1e
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x1d
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E9F6:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807EA06
	str r1, [r5, #0x60]
_0807EA06:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0807EA34
	ldr r0, [r5, #0x28]
	ldr r2, _0807EA54 @ =0xFFC70054
	adds r0, r0, r2
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807EA34
	movs r0, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EA58 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807EA34:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0807EACC
	str r0, [r5, #0x58]
	b _0807EA8A
	.align 2, 0
_0807EA48: .4byte 0xFFFF7400
_0807EA4C: .4byte 0xFFFF6000
_0807EA50: .4byte 0x0000AC05
_0807EA54: .4byte 0xFFC70054
_0807EA58: .4byte 0x0000AC06
_0807EA5C:
	movs r0, #0xd3
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EA94 @ =sCollisions+(1*24)
	bl SetDDP
	ldr r1, _0807EA98 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
_0807EA74:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EA7A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807EACC
_0807EA8A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0807EACC
	.align 2, 0
_0807EA94: .4byte sCollisions+(1*24)
_0807EA98: .4byte 0x0000AC07
_0807EA9C:
	ldr r1, _0807EAD4 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #2
_0807EAA6:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EAAE:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EAC4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807EACC
_0807EAC4:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0807EACC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EAD4: .4byte 0x0000AC01
