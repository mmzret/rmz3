	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shrimporin_08069c80
shrimporin_08069c80: @ 0x08069C80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08069C90
	cmp r0, #1
	beq _08069CA2
	b _08069CF6
_08069C90:
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069CFC @ =sCollisions+48
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069CA2:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _08069CE0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08069CBE
	str r1, [r4, #0x60]
_08069CBE:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bge _08069CE0
	str r5, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08069CE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08069CF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08069CFC: .4byte sCollisions+48

	thumb_func_start shrimporin_08069d00
shrimporin_08069d00: @ 0x08069D00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08069D10
	cmp r0, #1
	beq _08069D28
	b _08069D64
_08069D10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069D48 @ =sCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069D28:
	ldr r0, _08069D4C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r1, r1, r0
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _08069D54
	ldr r0, _08069D50 @ =0x000077FF
	cmp r1, r0
	bgt _08069D64
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08069D64
	.align 2, 0
_08069D48: .4byte sCollisions
_08069D4C: .4byte pZero2
_08069D50: .4byte 0x000077FF
_08069D54:
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	ble _08069D64
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08069D64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start shrimporinBurrowSnow
shrimporinBurrowSnow: @ 0x08069D6C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08069D7C
	cmp r5, #1
	beq _08069D9A
	b _08069F56
_08069D7C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069E74 @ =sCollisions
	bl SetDDP
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069D9A:
	ldrb r0, [r4, #0x13]
	movs r5, #3
	ands r0, r5
	cmp r0, #0
	bne _08069DAE
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x11]
	bl FUN_080b8f68
_08069DAE:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x78
	bls _08069DC8
	strb r5, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08069DC8:
	ldr r0, _08069E78 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	ldr r1, _08069E7C @ =0xFFFFC000
	adds r2, r2, r1
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08069DE2
	movs r0, #0x80
	lsls r0, r0, #8
	adds r2, r2, r0
_08069DE2:
	movs r1, #0x80
	lsls r1, r1, #6
	adds r2, r2, r1
	ldrb r0, [r4, #0x12]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #0xe
	subs r2, r2, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r4, #0x64]
	adds r1, r0, #0
	ldr r0, [r4, #0x54]
	subs r0, r2, r0
	cmp r0, #0
	bge _08069E06
	ldr r1, _08069E80 @ =0xFFFFFB00
_08069E06:
	str r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08069E18
	adds r0, #0xff
_08069E18:
	asrs r0, r0, #8
	adds r0, r2, r0
	str r0, [r4, #0x5c]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	bgt _08069E2C
	ldr r1, _08069E84 @ =0xFFFFFD00
	cmp r0, r1
	bge _08069E2E
_08069E2C:
	str r1, [r4, #0x5c]
_08069E2E:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r0]
	subs r1, r1, r2
	movs r0, #0xb4
	lsls r0, r0, #9
	cmp r1, r0
	bgt _08069E4C
	ldr r0, _08069E88 @ =0xFFFE9800
	cmp r1, r0
	bge _08069E50
_08069E4C:
	adds r0, r2, r0
	str r0, [r4, #0x54]
_08069E50:
	movs r6, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08069E90
	ldr r0, [r4, #0x54]
	movs r5, #0xc0
	lsls r5, r5, #4
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _08069E8C @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft2
	adds r2, r0, #0
	cmp r2, #0
	bge _08069EAE
	b _08069EA6
	.align 2, 0
_08069E74: .4byte sCollisions
_08069E78: .4byte pZero2
_08069E7C: .4byte 0xFFFFC000
_08069E80: .4byte 0xFFFFFB00
_08069E84: .4byte 0xFFFFFD00
_08069E88: .4byte 0xFFFE9800
_08069E8C: .4byte 0xFFFFF800
_08069E90:
	ldr r0, [r4, #0x54]
	ldr r5, _08069EEC @ =0xFFFFF400
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	ldr r2, _08069EF0 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	adds r2, r0, #0
	cmp r2, #0
	ble _08069EAE
_08069EA6:
	movs r6, #1
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_08069EAE:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r2, r0
	movs r1, #0xf0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08069EF4 @ =0x00001DFF
	cmp r0, r1
	bls _08069ED4
	movs r6, #1
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
_08069ED4:
	ldrb r0, [r4, #0x12]
	adds r0, r6, r0
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	lsrs r2, r0, #0x1f
	cmp r2, #0
	beq _08069EF8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08069EFE
	.align 2, 0
_08069EEC: .4byte 0xFFFFF400
_08069EF0: .4byte 0xFFFFF800
_08069EF4: .4byte 0x00001DFF
_08069EF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08069EFE:
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
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _08069F4C
	ldr r1, _08069F48 @ =0x00000D02
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08069F56
	.align 2, 0
_08069F48: .4byte 0x00000D02
_08069F4C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	str r0, [r4, #0x58]
_08069F56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start popoutShrimporin
popoutShrimporin: @ 0x08069F5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08069FA4
	cmp r0, #1
	bgt _08069F70
	cmp r0, #0
	beq _08069F7A
	b _0806A062
_08069F70:
	cmp r0, #2
	beq _08069FBC
	cmp r0, #3
	beq _0806A03C
	b _0806A062
_08069F7A:
	movs r0, #0x55
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08069FB8 @ =0x00000D01
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl GotoMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069FA4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806A062
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0806A062
	.align 2, 0
_08069FB8: .4byte 0x00000D01
_08069FBC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069FF8 @ =sCollisions+24
	bl SetDDP
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x11]
	bl createShrimporinIce
	ldr r1, _08069FFC @ =0x00000D02
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldr r0, _0806A000 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08069FEA
	movs r2, #1
_08069FEA:
	cmp r2, #0
	beq _0806A004
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806A00A
	.align 2, 0
_08069FF8: .4byte sCollisions+24
_08069FFC: .4byte 0x00000D02
_0806A000: .4byte pZero2
_0806A004:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806A00A:
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
	movs r1, #0x18
	ldr r0, _0806A068 @ =0xFFFFFA56
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	ldr r2, _0806A06C @ =0xFFFFF800
	adds r0, r0, r2
	str r0, [r4, #0x58]
	strb r1, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806A03C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0806A05C
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806A05C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806A062:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806A068: .4byte 0xFFFFFA56
_0806A06C: .4byte 0xFFFFF800

	thumb_func_start shrimporinSpin
shrimporinSpin: @ 0x0806A070
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0806A080
	cmp r5, #1
	beq _0806A090
	b _0806A0EA
_0806A080:
	ldr r1, _0806A0F0 @ =0x00000D03
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806A090:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806A0A8
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806A0A8:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bne _0806A0EA
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0806A0EA
	movs r3, #1
	strb r3, [r4, #0x12]
	ldr r1, [r4, #0x54]
	ldr r0, _0806A0F4 @ =0xFFFFF900
	adds r5, r1, r0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0806A0D6
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r5, r1, r0
_0806A0D6:
	ldr r1, [r4, #0x58]
	movs r0, #0xf0
	lsls r0, r0, #4
	adds r1, r1, r0
	lsrs r2, r2, #4
	ands r2, r3
	ldrb r3, [r4, #0x11]
	adds r0, r5, #0
	bl CreateShrimporin
_0806A0EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A0F0: .4byte 0x00000D03
_0806A0F4: .4byte 0xFFFFF900

	thumb_func_start shrimporinIce
shrimporinIce: @ 0x0806A0F8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0806A108
	cmp r0, #1
	beq _0806A1D6
	b _0806A226
_0806A108:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806A134 @ =sCollisions+72
	bl SetDDP
	ldr r1, _0806A138 @ =0x00000D06
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0806A13C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	cmp r0, #0
	ble _0806A140
	cmp r1, #1
	bne _0806A144
	b _0806A150
	.align 2, 0
_0806A134: .4byte sCollisions+72
_0806A138: .4byte 0x00000D06
_0806A13C: .4byte pZero2
_0806A140:
	cmp r1, #0
	beq _0806A150
_0806A144:
	movs r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	b _0806A1CC
_0806A150:
	ldr r0, _0806A1C0 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r5, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	asrs r0, r0, #8
	adds r6, r0, #0
	muls r6, r0, r6
	asrs r1, r1, #8
	adds r0, r1, #0
	muls r0, r1, r0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0806A1C4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r1, r0, #0
	str r1, [r5, #0x60]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #7
	cmp r0, #0
	bge _0806A1A8
	adds r0, #0xff
_0806A1A8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	cmp r0, #0
	bge _0806A1B8
	adds r0, #0xff
_0806A1B8:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	b _0806A1CC
	.align 2, 0
_0806A1C0: .4byte pZero2
_0806A1C4:
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0806A1CC:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806A1D6:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldrb r2, [r5, #0x12]
	subs r2, #1
	strb r2, [r5, #0x12]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806A20A
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0806A20A
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0806A220
_0806A20A:
	ldr r1, _0806A22C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	movs r0, #3
	strb r0, [r5, #0xd]
_0806A220:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0806A226:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806A22C: .4byte gEnemyFnTable

	thumb_func_start shrimporin_0806a230
shrimporin_0806a230: @ 0x0806A230
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _0806A240
	cmp r2, #1
	beq _0806A252
	b _0806A366
_0806A240:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
	str r2, [r4, #0x5c]
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806A252:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _0806A270
	str r0, [r4, #0x60]
_0806A270:
	cmp r2, #0
	beq _0806A2B4
	cmp r2, #0
	ble _0806A298
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _0806A294 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft2
	adds r5, r0, #0
	cmp r5, #0
	bge _0806A2B4
	b _0806A2AE
	.align 2, 0
_0806A294: .4byte 0xFFFFF800
_0806A298:
	ldr r0, [r4, #0x54]
	ldr r3, _0806A30C @ =0xFFFFF400
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	ldr r2, _0806A310 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	adds r5, r0, #0
	cmp r5, #0
	ble _0806A2B4
_0806A2AE:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0806A2B4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r1, r1, r3
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl IsVoidSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806A318
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806A314 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0806A366
	.align 2, 0
_0806A30C: .4byte 0xFFFFF400
_0806A310: .4byte 0xFFFFF800
_0806A314: .4byte gEnemyFnTable
_0806A318:
	cmp r5, #0
	bge _0806A366
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	beq _0806A350
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _0806A340
	movs r3, #0xb4
	lsls r3, r3, #9
	adds r0, r0, r3
	cmp r1, r0
	ble _0806A350
	ldr r3, _0806A33C @ =0xFFFE9800
	b _0806A34C
	.align 2, 0
_0806A33C: .4byte 0xFFFE9800
_0806A340:
	ldr r3, _0806A36C @ =0xFFFE9800
	adds r0, r0, r3
	cmp r1, r0
	bge _0806A350
	movs r3, #0xb4
	lsls r3, r3, #9
_0806A34C:
	adds r0, r1, r3
	str r0, [r2]
_0806A350:
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldrb r2, [r4, #0x11]
	bl createShrimporinIce
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806A366:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A36C: .4byte 0xFFFE9800

	thumb_func_start explodeShrimpolin
explodeShrimpolin: @ 0x0806A370
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #4]
	ldr r0, [r4, #0x58]
	ldr r1, _0806A3F8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0806A3FC @ =sMotions
	ldrb r0, [r4, #0x11]
	str r0, [sp]
	adds r0, r4, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b8080
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0806A400 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0806A404 @ =0x0000270E
	cmp r1, r0
	bhi _0806A3D4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806A3D4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0806A408 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806A3F8: .4byte 0xFFFFF000
_0806A3FC: .4byte sMotions
_0806A400: .4byte gMission
_0806A404: .4byte 0x0000270E
_0806A408: .4byte gEnemyFnTable

	thumb_func_start slashShrimporin
slashShrimporin: @ 0x0806A40C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0806A41E
	cmp r6, #1
	beq _0806A49A
	b _0806A4D8
_0806A41E:
	movs r4, #0
	ldr r0, _0806A4E0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0806A430
	movs r4, #1
_0806A430:
	ldr r1, _0806A4E4 @ =0x00000D04
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0x14]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #0x10
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0806A4E8 @ =sMotions+6
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	ldrb r0, [r5, #0x11]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	add r2, sp, #0x10
	movs r3, #0x40
	bl FUN_080b869c
	strb r4, [r5, #0x12]
	str r6, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806A49A:
	ldr r0, [r5, #0x60]
	adds r0, #0x30
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806A4AA
	str r1, [r5, #0x60]
_0806A4AA:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806A4D2
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806A4D8
_0806A4D2:
	adds r0, r5, #0
	bl explodeShrimpolin
_0806A4D8:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806A4E0: .4byte pZero2
_0806A4E4: .4byte 0x00000D04
_0806A4E8: .4byte sMotions+6

	thumb_func_start shrimporin_0806a4ec
shrimporin_0806a4ec: @ 0x0806A4EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806A528 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _0806A52C
	movs r0, #0x3f
	bl PlaySound
	b _0806A534
	.align 2, 0
_0806A528: .4byte gEnemyFnTable
_0806A52C:
	movs r0, #0x91
	lsls r0, r0, #1
	bl PlaySound
_0806A534:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x11]
	bl shrimporinIceCrash
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start shrimporin_0806a544
shrimporin_0806a544: @ 0x0806A544
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0806A554
	cmp r0, #1
	beq _0806A5E0
	b _0806A6C0
_0806A554:
	ldr r1, _0806A5C0 @ =0x00000D03
	adds r0, r5, #0
	movs r2, #6
	movs r3, #1
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0806A5C4 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0806A5C8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r4, r4, #2
	str r4, [r5, #0x5c]
	lsls r0, r0, #2
	str r0, [r5, #0x60]
	b _0806A5D0
	.align 2, 0
_0806A5C0: .4byte 0x00000D03
_0806A5C4: .4byte pZero2
_0806A5C8:
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0806A5D0:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806A628 @ =sCollisions+(24*5)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806A5E0:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806A5F8
	str r1, [r5, #0x60]
_0806A5F8:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	cmp r2, #0
	beq _0806A654
	cmp r2, #0
	ble _0806A630
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r3, _0806A62C @ =0xFFFFF800
	adds r1, r1, r3
	bl PushoutToLeft2
	adds r2, r0, #0
	cmp r2, #0
	bge _0806A654
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	b _0806A662
	.align 2, 0
_0806A628: .4byte sCollisions+(24*5)
_0806A62C: .4byte 0xFFFFF800
_0806A630:
	ldr r0, [r5, #0x54]
	ldr r4, _0806A64C @ =0xFFFFF400
	adds r0, r0, r4
	ldr r2, _0806A650 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight2
	adds r2, r0, #0
	cmp r2, #0
	ble _0806A654
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	b _0806A662
	.align 2, 0
_0806A64C: .4byte 0xFFFFF400
_0806A650: .4byte 0xFFFFF800
_0806A654:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0806A66A
_0806A662:
	adds r0, r5, #0
	bl explodeShrimpolin
	b _0806A6C0
_0806A66A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r2, r0, #0
	cmp r2, #0
	bge _0806A6C0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _0806A6AC
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r1, [r5, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	ble _0806A69C
	movs r4, #0xb4
	lsls r4, r4, #9
	adds r0, r0, r4
	cmp r1, r0
	ble _0806A6AC
	ldr r4, _0806A698 @ =0xFFFE9800
	b _0806A6A8
	.align 2, 0
_0806A698: .4byte 0xFFFE9800
_0806A69C:
	ldr r4, _0806A6C8 @ =0xFFFE9800
	adds r0, r0, r4
	cmp r1, r0
	bge _0806A6AC
	movs r4, #0xb4
	lsls r4, r4, #9
_0806A6A8:
	adds r0, r1, r4
	str r0, [r3]
_0806A6AC:
	ldr r1, [r5, #0x58]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldrb r2, [r5, #0x11]
	bl createShrimporinIce
	adds r0, r5, #0
	bl explodeShrimpolin
_0806A6C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806A6C8: .4byte 0xFFFE9800
