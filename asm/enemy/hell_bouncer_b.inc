	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807ead8
FUN_0807ead8: @ 0x0807EAD8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807eadc
FUN_0807eadc: @ 0x0807EADC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x2f
	bls _0807EAEA
	bl _0807F630
_0807EAEA:
	lsls r0, r0, #2
	ldr r1, _0807EAF4 @ =_0807EAF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807EAF4: .4byte _0807EAF8
_0807EAF8: @ jump table
	.4byte _0807EBB8 @ case 0
	.4byte _0807EC00 @ case 1
	.4byte _0807EC12 @ case 2
	.4byte _0807EE60 @ case 3
	.4byte _0807EC50 @ case 4
	.4byte _0807ECBA @ case 5
	.4byte _0807ECD2 @ case 6
	.4byte _0807ECF0 @ case 7
	.4byte _0807EE48 @ case 8
	.4byte _0807EE60 @ case 9
	.4byte _0807EE84 @ case 10
	.4byte _0807EEA4 @ case 11
	.4byte _0807EF04 @ case 12
	.4byte _0807EF7C @ case 13
	.4byte _0807F044 @ case 14
	.4byte _0807F04E @ case 15
	.4byte _0807F064 @ case 16
	.4byte _0807F09C @ case 17
	.4byte _0807F0D8 @ case 18
	.4byte _0807F0F6 @ case 19
	.4byte _0807F114 @ case 20
	.4byte _0807F126 @ case 21
	.4byte _0807F148 @ case 22
	.4byte _0807F1BE @ case 23
	.4byte _0807F1D0 @ case 24
	.4byte _0807F208 @ case 25
	.4byte _0807F630 @ case 26
	.4byte _0807F630 @ case 27
	.4byte _0807F630 @ case 28
	.4byte _0807F630 @ case 29
	.4byte _0807F220 @ case 30
	.4byte _0807F22E @ case 31
	.4byte _0807F248 @ case 32
	.4byte _0807F2A0 @ case 33
	.4byte _0807F360 @ case 34
	.4byte _0807F378 @ case 35
	.4byte _0807F394 @ case 36
	.4byte _0807F3BE @ case 37
	.4byte _0807F3D0 @ case 38
	.4byte _0807F424 @ case 39
	.4byte _0807F43C @ case 40
	.4byte _0807F452 @ case 41
	.4byte _0807F46C @ case 42
	.4byte _0807F492 @ case 43
	.4byte _0807F4B4 @ case 44
	.4byte _0807F4CA @ case 45
	.4byte _0807F52C @ case 46
	.4byte _0807F5F0 @ case 47
_0807EBB8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EBE0 @ =sCollisions+(1*24)
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EBE8
	ldr r0, _0807EBE4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0807EBDC
	bl _0807F516
_0807EBDC:
	b _0807EE74
	.align 2, 0
_0807EBE0: .4byte sCollisions+(1*24)
_0807EBE4: .4byte pZero2
_0807EBE8:
	ldr r0, _0807EBFC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0807EBF8
	bl _0807F516
_0807EBF8:
	b _0807EE74
	.align 2, 0
_0807EBFC: .4byte pZero2
_0807EC00:
	ldr r1, _0807EC4C @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EC12:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EC2C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807EC2C
	bl _0807F630
_0807EC2C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	bne _0807EC42
	bl _0807F404
_0807EC42:
	movs r0, #0x10
	orrs r0, r2
	bl _0807F408
	.align 2, 0
_0807EC4C: .4byte 0x0000AC09
_0807EC50:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EC68
	ldr r0, [r5, #0x54]
	ldr r1, _0807EC64 @ =0xFFFF6000
	adds r4, r0, r1
	b _0807EC70
	.align 2, 0
_0807EC64: .4byte 0xFFFF6000
_0807EC68:
	ldr r0, [r5, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r4, r0, r2
_0807EC70:
	ldr r1, _0807EC84 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807EC88
	movs r0, #0x1c
	b _0807EC8A
	.align 2, 0
_0807EC84: .4byte 0x0000AC02
_0807EC88:
	movs r0, #0x28
_0807EC8A:
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r4, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	muls r0, r1, r0
	lsls r0, r0, #6
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807ECBA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807ECCE
	bl _0807F630
_0807ECCE:
	bl _0807F516
_0807ECD2:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807ED2C @ =sCollisions+(3*24)
	bl SetDDP
	ldr r1, _0807ED30 @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807ECF0:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807ED00
	str r1, [r5, #0x60]
_0807ED00:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r3, r0, r1
	str r3, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _0807ED3C
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807ED34 @ =0xFFFFEE00
	adds r0, r0, r4
	cmp r3, r0
	bge _0807ED3C
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807ED38 @ =0x0000AC04
	b _0807ED54
	.align 2, 0
_0807ED2C: .4byte sCollisions+(3*24)
_0807ED30: .4byte 0x0000AC03
_0807ED34: .4byte 0xFFFFEE00
_0807ED38: .4byte 0x0000AC04
_0807ED3C:
	cmp r2, #1
	bne _0807ED64
	cmp r1, #0
	ble _0807ED64
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807ED5C @ =sCollisions+(5*24)
	bl SetDDP
	ldr r1, _0807ED60 @ =0x0000AC05
_0807ED54:
	adds r0, r5, #0
	bl SetMotion
	b _0807ED82
	.align 2, 0
_0807ED5C: .4byte sCollisions+(5*24)
_0807ED60: .4byte 0x0000AC05
_0807ED64:
	cmp r2, #2
	bne _0807ED82
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807EDAC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0807ED82
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EDB0 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807ED82:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EDB8
	adds r2, r1, #0
	cmp r1, #0
	bge _0807ED9E
	rsbs r2, r1, #0
_0807ED9E:
	ldr r0, _0807EDB4 @ =0x000007FF
	cmp r2, r0
	bgt _0807EDB8
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807EDAC: .4byte 0xFFFFEE00
_0807EDB0: .4byte 0x0000AC06
_0807EDB4: .4byte 0x000007FF
_0807EDB8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EE04
	ldr r0, [r5, #0x54]
	ldr r2, _0807EDE0 @ =0xFFFFEC00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r3, _0807EDE4 @ =0xFFFFF800
	adds r1, r1, r3
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EDE8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0807EE3E
	.align 2, 0
_0807EDE0: .4byte 0xFFFFEC00
_0807EDE4: .4byte 0xFFFFF800
_0807EDE8:
	ldr r1, [r5, #0x54]
	ldr r4, _0807EE00 @ =0xFFFFEC00
	adds r1, r1, r4
	ldr r0, [r5, #0x28]
	adds r0, #0xd0
	ldr r0, [r0]
	cmp r1, r0
	blt _0807EDFC
	bl _0807F630
_0807EDFC:
	b _0807EE3E
	.align 2, 0
_0807EE00: .4byte 0xFFFFEC00
_0807EE04:
	ldr r0, [r5, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807EE24 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EE28
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0807EE3E
	.align 2, 0
_0807EE24: .4byte 0xFFFFF800
_0807EE28:
	ldr r1, [r5, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r0, [r5, #0x28]
	adds r0, #0xdc
	ldr r0, [r0]
	cmp r1, r0
	bgt _0807EE3E
	bl _0807F630
_0807EE3E:
	str r0, [r5, #0x54]
	movs r0, #0xa
	strb r0, [r5, #0xe]
	bl _0807F630
_0807EE48:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EE7C @ =sCollisions+(1*24)
	bl SetDDP
	ldr r1, _0807EE80 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EE60:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807EE74
	bl _0807F630
_0807EE74:
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807EE7C: .4byte sCollisions+(1*24)
_0807EE80: .4byte 0x0000AC07
_0807EE84:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EED0 @ =sCollisions+(3*24)
	bl SetDDP
	ldr r1, _0807EED4 @ =0x0000AC0A
	adds r0, r5, #0
	bl SetMotion
	movs r1, #0
	movs r0, #8
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EEA4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EEB4
	subs r0, #1
	strb r0, [r5, #0x12]
_0807EEB4:
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	bne _0807EEF6
	movs r1, #1
	strb r1, [r5, #0x13]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807EED8
	movs r0, #0x10
	orrs r0, r2
	b _0807EEDC
	.align 2, 0
_0807EED0: .4byte sCollisions+(3*24)
_0807EED4: .4byte 0x0000AC0A
_0807EED8:
	movs r0, #0xef
	ands r0, r2
_0807EEDC:
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
_0807EEF6:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807EF02
	b _0807F630
_0807EF02:
	b _0807F516
_0807EF04:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EF1C
	ldr r0, [r5, #0x54]
	ldr r1, _0807EF18 @ =0xFFFF6000
	adds r4, r0, r1
	b _0807EF24
	.align 2, 0
_0807EF18: .4byte 0xFFFF6000
_0807EF1C:
	ldr r0, [r5, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r4, r0, r2
_0807EF24:
	ldr r1, _0807EF3C @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807EF40
	movs r0, #0x1c
	b _0807EF42
	.align 2, 0
_0807EF3C: .4byte 0x0000AC03
_0807EF40:
	movs r0, #0x28
_0807EF42:
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r4, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	muls r0, r1, r0
	lsls r0, r0, #6
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x58]
	ldr r3, [r3, #0x58]
	subs r2, r2, r3
	subs r0, r0, r2
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EF7C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807EF8C
	str r1, [r5, #0x60]
_0807EF8C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r3, r0, r1
	str r3, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _0807EFC0
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807EFB8 @ =0xFFFFC000
	adds r0, r0, r4
	cmp r3, r0
	bge _0807EFC0
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EFBC @ =0x0000AC04
	b _0807EFD8
	.align 2, 0
_0807EFB8: .4byte 0xFFFFC000
_0807EFBC: .4byte 0x0000AC04
_0807EFC0:
	cmp r2, #1
	bne _0807EFE8
	cmp r1, #0
	ble _0807EFE8
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EFE0 @ =sCollisions+(5*24)
	bl SetDDP
	ldr r1, _0807EFE4 @ =0x0000AC05
_0807EFD8:
	adds r0, r5, #0
	bl SetMotion
	b _0807F006
	.align 2, 0
_0807EFE0: .4byte sCollisions+(5*24)
_0807EFE4: .4byte 0x0000AC05
_0807EFE8:
	cmp r2, #2
	bne _0807F006
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807F038 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0807F006
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F03C @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807F006:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0807F01C
	b _0807F630
_0807F01C:
	adds r2, r1, #0
	cmp r1, #0
	bge _0807F024
	rsbs r2, r1, #0
_0807F024:
	ldr r0, _0807F040 @ =0x000007FF
	cmp r2, r0
	ble _0807F02C
	b _0807F630
_0807F02C:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807F038: .4byte 0xFFFFE000
_0807F03C: .4byte 0x0000AC06
_0807F040: .4byte 0x000007FF
_0807F044:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F04E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0807F056
	b _0807F516
_0807F056:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F062
	b _0807F630
_0807F062:
	b _0807F516
_0807F064:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F0C8 @ =sCollisions+(5*24)
	bl SetDDP
	ldr r1, _0807F0CC @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0807F0D0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0807F0D4 @ =0xFFFF4C00
	adds r0, r0, r2
	str r0, [r5, #0x58]
	movs r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x60]
	ldr r0, [r1, #0x58]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F09C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F0AC
	str r1, [r5, #0x60]
_0807F0AC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	cmp r0, r1
	bgt _0807F0C4
	b _0807F630
_0807F0C4:
	str r1, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807F0C8: .4byte sCollisions+(5*24)
_0807F0CC: .4byte 0x0000AC06
_0807F0D0: .4byte pZero2
_0807F0D4: .4byte 0xFFFF4C00
_0807F0D8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F10C @ =sCollisions+(1*24)
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807F110 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F0F6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F108
	b _0807F630
_0807F108:
	b _0807F516
	.align 2, 0
_0807F10C: .4byte sCollisions+(1*24)
_0807F110: .4byte 0x0000AC07
_0807F114:
	ldr r1, _0807F144 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F126:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0807F134
	b _0807F516
_0807F134:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F140
	b _0807F630
_0807F140:
	b _0807F516
	.align 2, 0
_0807F144: .4byte 0x0000AC01
_0807F148:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F188
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r3, _0807F174 @ =0xFFFFE000
	adds r0, r0, r3
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0807F178
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
	.align 2, 0
_0807F174: .4byte 0xFFFFE000
_0807F178:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F188:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r4, #0x80
	lsls r4, r4, #6
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0807F1A8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F1A8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F1B8:
	movs r0, #0x1e
_0807F1BA:
	strb r0, [r5, #0xe]
	b _0807F436
_0807F1BE:
	ldr r1, _0807F204 @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F1D0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F1E8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F1E8
	b _0807F630
_0807F1E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	bne _0807F1FC
	b _0807F404
_0807F1FC:
	movs r0, #0x10
	orrs r0, r2
	b _0807F408
	.align 2, 0
_0807F204: .4byte 0x0000AC09
_0807F208:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F21A
	b _0807F630
_0807F21A:
	movs r0, #0x1e
	strb r0, [r5, #0xe]
	b _0807F630
_0807F220:
	ldr r1, _0807F244 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F22E:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F240
	b _0807F630
_0807F240:
	b _0807F516
	.align 2, 0
_0807F244: .4byte 0x0000AC02
_0807F248:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F25C
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _0807F258 @ =0xFFFFE000
	adds r6, r0, r1
	b _0807F266
	.align 2, 0
_0807F258: .4byte 0xFFFFE000
_0807F25C:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r6, r0, r2
_0807F266:
	ldr r1, _0807F2E0 @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F2E4 @ =sCollisions+(3*24)
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	movs r4, #0
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x14
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, _0807F2E8 @ =0xFFFFFCE0
	str r0, [r5, #0x60]
	movs r0, #0x13
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F2A0:
	ldr r0, [r5, #0x60]
	adds r0, #0x50
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F2B0
	str r1, [r5, #0x60]
_0807F2B0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _0807F2F4
	ldr r0, [r5, #0x28]
	ldr r3, _0807F2EC @ =0xFFE38054
	adds r0, r0, r3
	ldr r0, [r0, #4]
	cmp r1, r0
	bge _0807F2F4
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F2F0 @ =0x0000AC04
	b _0807F312
	.align 2, 0
_0807F2E0: .4byte 0x0000AC03
_0807F2E4: .4byte sCollisions+(3*24)
_0807F2E8: .4byte 0xFFFFFCE0
_0807F2EC: .4byte 0xFFE38054
_0807F2F0: .4byte 0x0000AC04
_0807F2F4:
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #1
	bne _0807F324
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0807F324
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F31C @ =sCollisions+(5*24)
	bl SetDDP
	ldr r1, _0807F320 @ =0x0000AC05
_0807F312:
	adds r0, r5, #0
	bl SetMotion
	b _0807F342
	.align 2, 0
_0807F31C: .4byte sCollisions+(5*24)
_0807F320: .4byte 0x0000AC05
_0807F324:
	cmp r2, #2
	bne _0807F342
	ldr r0, [r5, #0x28]
	ldr r4, _0807F358 @ =0xFFE38054
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807F342
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F35C @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807F342:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bge _0807F354
	b _0807F630
_0807F354:
	str r0, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807F358: .4byte 0xFFE38054
_0807F35C: .4byte 0x0000AC06
_0807F360:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F38C @ =sCollisions+(1*24)
	bl SetDDP
	ldr r1, _0807F390 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F378:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F38A
	b _0807F630
_0807F38A:
	b _0807F516
	.align 2, 0
_0807F38C: .4byte sCollisions+(1*24)
_0807F390: .4byte 0x0000AC07
_0807F394:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F3A8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F3B6
	movs r0, #0x28
	b _0807F3BA
_0807F3A8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F3B6
	movs r0, #0x28
	b _0807F3BA
_0807F3B6:
	ldrb r0, [r5, #0xe]
	adds r0, #1
_0807F3BA:
	strb r0, [r5, #0xe]
	b _0807F436
_0807F3BE:
	ldr r1, _0807F400 @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F3D0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F3E8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F3E8
	b _0807F630
_0807F3E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807F404
	movs r0, #0x10
	orrs r0, r2
	b _0807F408
	.align 2, 0
_0807F400: .4byte 0x0000AC09
_0807F404:
	movs r0, #0xef
	ands r0, r2
_0807F408:
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
	b _0807F630
_0807F424:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F436
	b _0807F630
_0807F436:
	movs r0, #0x28
	strb r0, [r5, #0xe]
	b _0807F630
_0807F43C:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F468 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F452:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807F464
	b _0807F630
_0807F464:
	b _0807F516
	.align 2, 0
_0807F468: .4byte 0x0000AC01
_0807F46C:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F478
	movs r0, #0xb0
	lsls r0, r0, #3
	b _0807F47A
_0807F478:
	ldr r0, _0807F4A8 @ =0xFFFFFA80
_0807F47A:
	str r0, [r5, #0x5c]
	ldr r0, _0807F4AC @ =0xFFFFF880
	str r0, [r5, #0x60]
	ldr r1, _0807F4B0 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F492:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F4A4
	b _0807F630
_0807F4A4:
	b _0807F516
	.align 2, 0
_0807F4A8: .4byte 0xFFFFFA80
_0807F4AC: .4byte 0xFFFFF880
_0807F4B0: .4byte 0x0000AC02
_0807F4B4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F520 @ =sCollisions+(3*24)
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F4CA:
	ldr r0, [r5, #0x60]
	adds r0, #8
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F4DA
	str r1, [r5, #0x60]
_0807F4DA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _0807F500
	ldr r0, [r5, #0x28]
	ldr r3, _0807F524 @ =0xFFD54054
	adds r0, r0, r3
	ldr r0, [r0, #4]
	cmp r1, r0
	bge _0807F500
	adds r0, r2, #1
	strb r0, [r5, #0x13]
_0807F500:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807F528 @ =0xFFFF4C00
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	blt _0807F516
	b _0807F630
_0807F516:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807F520: .4byte sCollisions+(3*24)
_0807F524: .4byte 0xFFD54054
_0807F528: .4byte 0xFFFF4C00
_0807F52C:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807F57C @ =0x0000AB1B
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F580 @ =sCollisions+(7*24)
	bl SetDDP
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r2, [r5, #0x11]
	cmp r2, #0
	bne _0807F58C
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
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x54]
	ldr r3, _0807F584 @ =0xFFFF6000
	adds r0, r1, r3
	str r0, [r5, #0x54]
	ldr r4, _0807F588 @ =0xFFFF7100
	b _0807F5BE
	.align 2, 0
_0807F57C: .4byte 0x0000AB1B
_0807F580: .4byte sCollisions+(7*24)
_0807F584: .4byte 0xFFFF6000
_0807F588: .4byte 0xFFFF7100
_0807F58C:
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
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r1, r3
	str r0, [r5, #0x54]
	movs r4, #0x8f
	lsls r4, r4, #8
_0807F5BE:
	adds r1, r1, r4
	ldr r0, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x58]
	ldr r3, _0807F638 @ =0xFFFF6000
	adds r0, r1, r3
	str r0, [r5, #0x58]
	ldr r4, _0807F63C @ =0xFFFF8B00
	adds r1, r1, r4
	ldr r0, [r2, #0x58]
	subs r0, r0, r1
	str r0, [r5, #0x60]
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F5F0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F616
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F630
_0807F616:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807F640 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0807F630:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807F638: .4byte 0xFFFF6000
_0807F63C: .4byte 0xFFFF8B00
_0807F640: .4byte gEnemyFnTable

	thumb_func_start FUN_0807f644
FUN_0807f644: @ 0x0807F644
	movs r0, #1
	bx lr
