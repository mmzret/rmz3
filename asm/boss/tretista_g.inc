	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretistaPipeThrow
tretistaPipeThrow: @ 0x0804EB3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0x35
	bls _0804EB48
	b _0804F2AA
_0804EB48:
	lsls r0, r0, #2
	ldr r1, _0804EB54 @ =_0804EB58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804EB54: .4byte _0804EB58
_0804EB58: @ jump table
	.4byte _0804EC30 @ case 0
	.4byte _0804EC60 @ case 1
	.4byte _0804EC80 @ case 2
	.4byte _0804EC9C @ case 3
	.4byte _0804ED32 @ case 4
	.4byte _0804ED72 @ case 5
	.4byte _0804F2AA @ case 6
	.4byte _0804F2AA @ case 7
	.4byte _0804F2AA @ case 8
	.4byte _0804F2AA @ case 9
	.4byte _0804EDB6 @ case 10
	.4byte _0804EDEC @ case 11
	.4byte _0804EE08 @ case 12
	.4byte _0804F2AA @ case 13
	.4byte _0804F2AA @ case 14
	.4byte _0804F2AA @ case 15
	.4byte _0804F2AA @ case 16
	.4byte _0804F2AA @ case 17
	.4byte _0804F2AA @ case 18
	.4byte _0804F2AA @ case 19
	.4byte _0804EE5A @ case 20
	.4byte _0804EC60 @ case 21
	.4byte _0804EEE8 @ case 22
	.4byte _0804EF04 @ case 23
	.4byte _0804EF70 @ case 24
	.4byte _0804F0A8 @ case 25
	.4byte _0804F2AA @ case 26
	.4byte _0804F2AA @ case 27
	.4byte _0804F2AA @ case 28
	.4byte _0804F2AA @ case 29
	.4byte _0804EF98 @ case 30
	.4byte _0804EC60 @ case 31
	.4byte _0804F034 @ case 32
	.4byte _0804F04C @ case 33
	.4byte _0804F090 @ case 34
	.4byte _0804F0A8 @ case 35
	.4byte _0804F2AA @ case 36
	.4byte _0804F2AA @ case 37
	.4byte _0804F2AA @ case 38
	.4byte _0804F2AA @ case 39
	.4byte _0804F0CC @ case 40
	.4byte _0804F0F8 @ case 41
	.4byte _0804F12C @ case 42
	.4byte _0804F14E @ case 43
	.4byte _0804F194 @ case 44
	.4byte _0804F1B0 @ case 45
	.4byte _0804F2AA @ case 46
	.4byte _0804F2AA @ case 47
	.4byte _0804F2AA @ case 48
	.4byte _0804F2AA @ case 49
	.4byte _0804F1E0 @ case 50
	.4byte _0804F212 @ case 51
	.4byte _0804F274 @ case 52
	.4byte _0804F286 @ case 53
_0804EC30:
	ldr r1, _0804EC74 @ =0x0000AB11
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EC78 @ =sCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	movs r0, #0x34
	strb r0, [r4, #0x12]
	str r1, [r4, #0x5c]
	ldr r0, _0804EC7C @ =0x0001A680
	movs r1, #0x34
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x33
_0804EC58:
	strb r0, [r4, #0x12]
_0804EC5A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EC60:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804EC72
	b _0804F2AA
_0804EC72:
	b _0804F268
	.align 2, 0
_0804EC74: .4byte 0x0000AB11
_0804EC78: .4byte sCollisions+(24*1)
_0804EC7C: .4byte 0x0001A680
_0804EC80:
	ldr r1, _0804ED00 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804ED04 @ =0x08363410
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EC9C:
	ldr r2, [r4, #0x60]
	adds r2, #0x50
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	bgt _0804ECB6
	b _0804F252
_0804ECB6:
	ldrb r6, [r4, #0x13]
	cmp r6, #0
	beq _0804ECBE
	b _0804F252
_0804ECBE:
	movs r5, #1
	strb r5, [r4, #0x13]
	ldr r1, _0804ED08 @ =0x0000AB12
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _0804ED0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804ED10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804ED14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r5
	cmp r0, #0
	beq _0804ED18
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	adds r0, r4, #0
	bl tretista_080a36f4
	adds r1, r4, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r6, [r4, #0xf]
	b _0804F252
	.align 2, 0
_0804ED00: .4byte 0x0000AB0D
_0804ED04: .4byte 0x08363410
_0804ED08: .4byte 0x0000AB12
_0804ED0C: .4byte RNG_0202f388
_0804ED10: .4byte 0x000343FD
_0804ED14: .4byte 0x00269EC3
_0804ED18:
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	adds r0, r4, #0
	bl tretista_080a369c
	adds r1, r4, #0
	adds r1, #0xc4
	str r0, [r1]
	strb r5, [r4, #0xf]
	b _0804F252
_0804ED32:
	ldr r1, _0804EDA4 @ =0x0000AB12
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EDA8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EDAC @ =sCollisions+(24*1)
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804ED72:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804ED84
	b _0804F2AA
_0804ED84:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804ED96
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804ED96
	b _0804F2AA
_0804ED96:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0804EDB0
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804EDA4: .4byte 0x0000AB12
_0804EDA8: .4byte 0xFFFFF000
_0804EDAC: .4byte sCollisions+(24*1)
_0804EDB0:
	movs r0, #0x28
	strb r0, [r4, #0xe]
	b _0804F2AA
_0804EDB6:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #8
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
	ldr r1, _0804EE00 @ =0x0000AB13
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EE04 @ =sCollisions+(24*1)
	bl SetDDP
	movs r1, #0
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EDEC:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0804EDFA
	b _0804F252
_0804EDFA:
	movs r0, #1
	strb r0, [r4, #0x13]
	b _0804F252
	.align 2, 0
_0804EE00: .4byte 0x0000AB13
_0804EE04: .4byte sCollisions+(24*1)
_0804EE08:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0804EE18
	movs r0, #1
	strb r0, [r4, #0x13]
_0804EE18:
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _0804EE22
	movs r1, #0
	b _0804F2A4
_0804EE22:
	ldr r2, _0804EE44 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804EE48 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804EE4C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804EE50
	movs r0, #0x14
	b _0804EE52
	.align 2, 0
_0804EE44: .4byte RNG_0202f388
_0804EE48: .4byte 0x000343FD
_0804EE4C: .4byte 0x00269EC3
_0804EE50:
	movs r0, #0x1e
_0804EE52:
	strb r0, [r4, #0xe]
	movs r0, #0x1e
	strb r0, [r4, #0xe]
	b _0804F2AA
_0804EE5A:
	ldr r1, _0804EE94 @ =0x0000AB0C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EE98 @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804EEA4
	ldr r0, [r4, #0x54]
	ldr r2, _0804EE9C @ =0xFFFF6800
	adds r5, r0, r2
	ldr r1, _0804EEA0 @ =0xFFFF2800
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	bge _0804EEC2
	movs r2, #0x80
	lsls r2, r2, #7
	b _0804EEC0
	.align 2, 0
_0804EE94: .4byte 0x0000AB0C
_0804EE98: .4byte sCollisions+(24*1)
_0804EE9C: .4byte 0xFFFF6800
_0804EEA0: .4byte 0xFFFF2800
_0804EEA4:
	ldr r0, [r4, #0x54]
	movs r1, #0x98
	lsls r1, r1, #8
	adds r5, r0, r1
	movs r1, #0xd8
	lsls r1, r1, #8
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	ble _0804EEC2
	ldr r2, _0804EEE4 @ =0xFFFFC000
_0804EEC0:
	adds r5, r1, r2
_0804EEC2:
	movs r0, #0x38
	strb r0, [r4, #0x12]
	subs r0, r5, r3
	movs r1, #0x38
	bl __divsi3
	str r0, [r4, #0x5c]
	movs r0, #0xf5
	lsls r0, r0, #9
	movs r1, #0x38
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x37
	b _0804EC58
	.align 2, 0
_0804EEE4: .4byte 0xFFFFC000
_0804EEE8:
	ldr r1, _0804EF60 @ =0x0000AB0D
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EF64 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804EF04:
	ldr r2, [r4, #0x60]
	adds r2, #0x50
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	cmp r2, #0
	ble _0804EF30
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804EF30
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EF68 @ =0x08363410
	bl SetDDP
_0804EF30:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0804EF6C @ =0xFFFFD300
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r1, r0
	bgt _0804EF44
	b _0804F252
_0804EF44:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bgt _0804EF4C
	b _0804F252
_0804EF4C:
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	str r0, [r1]
	b _0804F252
	.align 2, 0
_0804EF60: .4byte 0x0000AB0D
_0804EF64: .4byte sCollisions+(24*1)
_0804EF68: .4byte 0x08363410
_0804EF6C: .4byte 0xFFFFD300
_0804EF70:
	ldr r1, _0804EF90 @ =0x0000AB0F
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xde
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0804EF94 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _0804F098
	.align 2, 0
_0804EF90: .4byte 0x0000AB0F
_0804EF94: .4byte 0xFFFFF000
_0804EF98:
	ldr r1, _0804EFD0 @ =0x0000AB14
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804EFD4 @ =0x083634A0
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804EFEC
	ldr r0, [r4, #0x54]
	ldr r1, _0804EFD8 @ =0xFFFF2800
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	bge _0804EFDC
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r1, r2
	b _0804EFE0
	.align 2, 0
_0804EFD0: .4byte 0x0000AB14
_0804EFD4: .4byte 0x083634A0
_0804EFD8: .4byte 0xFFFF2800
_0804EFDC:
	ldr r0, _0804EFE4 @ =0xFFFFA800
	adds r1, r3, r0
_0804EFE0:
	ldr r0, _0804EFE8 @ =0xFFFFFD00
	b _0804F016
	.align 2, 0
_0804EFE4: .4byte 0xFFFFA800
_0804EFE8: .4byte 0xFFFFFD00
_0804EFEC:
	ldr r0, [r4, #0x54]
	movs r1, #0xd8
	lsls r1, r1, #8
	adds r2, r0, r1
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r1, [r1]
	adds r3, r0, #0
	cmp r2, r1
	ble _0804F00C
	ldr r2, _0804F008 @ =0xFFFFC000
	adds r1, r1, r2
	b _0804F012
	.align 2, 0
_0804F008: .4byte 0xFFFFC000
_0804F00C:
	movs r0, #0xb0
	lsls r0, r0, #7
	adds r1, r3, r0
_0804F012:
	movs r0, #0xc0
	lsls r0, r0, #2
_0804F016:
	str r0, [r4, #0x5c]
	subs r0, r1, r3
	cmp r0, #0
	bgt _0804F020
	subs r0, r3, r1
_0804F020:
	str r0, [r4, #0x60]
	ldr r1, _0804F030 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r4, #0x64]
	b _0804EC5A
	.align 2, 0
_0804F030: .4byte 0xFFFFE000
_0804F034:
	ldr r1, _0804F088 @ =0x0000AB15
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F08C @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F04C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	bge _0804F05A
	rsbs r1, r1, #0
_0804F05A:
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	cmp r0, r1
	ble _0804F076
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	str r0, [r1]
_0804F076:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x64]
	ldr r0, [r4, #0x60]
	cmp r1, r0
	bgt _0804F086
	b _0804F2AA
_0804F086:
	b _0804F268
	.align 2, 0
_0804F088: .4byte 0x0000AB15
_0804F08C: .4byte sCollisions+(24*1)
_0804F090:
	ldr r1, _0804F0C4 @ =0x0000AB16
	adds r0, r4, #0
	bl SetMotion
_0804F098:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F0C8 @ =sCollisions+(24*1)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F0A8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	beq _0804F0BA
	b _0804F2AA
_0804F0BA:
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F0C4: .4byte 0x0000AB16
_0804F0C8: .4byte sCollisions+(24*1)
_0804F0CC:
	ldr r1, _0804F120 @ =0x0000AB17
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F124 @ =0x08363458
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #2
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F0F8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x70]
	ldr r1, _0804F128 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #9
	cmp r0, r1
	bne _0804F112
	movs r0, #0xd8
	bl PlaySound
_0804F112:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F11E
	b _0804F2AA
_0804F11E:
	b _0804F258
	.align 2, 0
_0804F120: .4byte 0x0000AB17
_0804F124: .4byte 0x08363458
_0804F128: .4byte 0x00FFFF00
_0804F12C:
	ldr r1, _0804F18C @ =0x0000AB18
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F190 @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0xb7
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F14E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804F17A
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0804F17A
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	adds r1, #0xc0
	ldr r0, [r1]
	movs r2, #4
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	bl PlaySound
_0804F17A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804F268
	b _0804F1C6
	.align 2, 0
_0804F18C: .4byte 0x0000AB18
_0804F190: .4byte sCollisions+(24*1)
_0804F194:
	ldr r1, _0804F1D8 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804F1DC @ =sCollisions+(24*1)
	bl SetDDP
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F1B0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F29C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F29C
_0804F1C6:
	adds r0, r4, #0
	adds r0, #0xb7
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F2AA
	movs r0, #0x32
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F1D8: .4byte 0x0000AB09
_0804F1DC: .4byte sCollisions+(24*1)
_0804F1E0:
	ldr r1, _0804F200 @ =0x0000AB24
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804F204
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	b _0804F20A
	.align 2, 0
_0804F200: .4byte 0x0000AB24
_0804F204:
	ldr r0, [r4, #0x54]
	ldr r1, _0804F238 @ =0xFFFFF000
	adds r0, r0, r1
_0804F20A:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F212:
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804F23C
	movs r1, #0xb8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _0804F246
	.align 2, 0
_0804F238: .4byte 0xFFFFF000
_0804F23C:
	ldr r1, _0804F270 @ =0xFFFFD200
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_0804F246:
	adds r1, r0, #0
	cmp r1, #0
	beq _0804F252
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804F252:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804F258:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F268
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F2AA
_0804F268:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804F2AA
	.align 2, 0
_0804F270: .4byte 0xFFFFD200
_0804F274:
	ldr r1, _0804F2B0 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804F286:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804F29C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F2AA
_0804F29C:
	adds r0, r4, #0
	adds r0, #0xb7
	movs r1, #0
	strb r1, [r0]
_0804F2A4:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804F2AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F2B0: .4byte 0x0000AB09
