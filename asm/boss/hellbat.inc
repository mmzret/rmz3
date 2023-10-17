	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatNeutral
hellbatNeutral: @ 0x0804B6B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #1
	beq _0804B70A
	cmp r4, #1
	bgt _0804B6D2
	cmp r4, #0
	beq _0804B6D8
	b _0804B8E2
_0804B6D2:
	cmp r4, #2
	beq _0804B760
	b _0804B8E2
_0804B6D8:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x24
	strb r4, [r0]
	ldr r1, _0804B738 @ =0x0000A804
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804B73C @ =0x08362F68
	bl SetDDP
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	str r4, [r6, #0x68]
	str r4, [r6, #0x64]
	movs r0, #0x17
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804B70A:
	adds r0, r6, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r1, _0804B740 @ =0xFFFFB800
	adds r4, r0, r1
	ldr r1, [r6, #0x58]
	subs r0, r4, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x58]
	subs r2, r4, r1
	cmp r2, #0
	ble _0804B748
	ldr r0, _0804B744 @ =0x000003FF
	cmp r2, r0
	ble _0804B752
	b _0804B8E2
	.align 2, 0
_0804B738: .4byte 0x0000A804
_0804B73C: .4byte 0x08362F68
_0804B740: .4byte 0xFFFFB800
_0804B744: .4byte 0x000003FF
_0804B748:
	subs r1, r1, r4
	ldr r0, _0804B75C @ =0x000003FF
	cmp r1, r0
	ble _0804B752
	b _0804B8E2
_0804B752:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0804B8E2
	.align 2, 0
_0804B75C: .4byte 0x000003FF
_0804B760:
	adds r0, r6, #0
	bl hellbat_0804cd5c
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804B774
	b _0804B8E2
_0804B774:
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0804B782
	b _0804B8E2
_0804B782:
	adds r0, r6, #0
	adds r0, #0xb5
	adds r1, r6, #0
	adds r1, #0xb6
	movs r3, #0
	ldrsb r3, [r0, r3]
	movs r2, #0
	ldrsb r2, [r1, r2]
	mov r8, r0
	mov sb, r1
	cmp r3, r2
	bne _0804B860
	ldr r0, _0804B7F0 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804B804
	adds r0, r6, #0
	bl isHellbatFarAway
	adds r3, r0, #0
	ldr r2, _0804B7F4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804B7F8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804B7FC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804B800 @ =0x080FEEBA
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0804B8D2
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0804cccc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0804B8D2
	.align 2, 0
_0804B7F0: .4byte gMission
_0804B7F4: .4byte RNG_0202f388
_0804B7F8: .4byte 0x000343FD
_0804B7FC: .4byte 0x00269EC3
_0804B800: .4byte 0x080FEEBA
_0804B804:
	adds r0, r6, #0
	bl isHellbatFarAway
	adds r3, r0, #0
	ldr r2, _0804B850 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804B854 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804B858 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804B85C @ =0x080FEE98
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bne _0804B8D2
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0804cccc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _0804B8D2
	.align 2, 0
_0804B850: .4byte RNG_0202f388
_0804B854: .4byte 0x000343FD
_0804B858: .4byte 0x00269EC3
_0804B85C: .4byte 0x080FEE98
_0804B860:
	ldr r0, _0804B88C @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _0804B8A0
	adds r0, r6, #0
	bl isHellbatFarAway
	adds r3, r0, #0
	ldr r2, _0804B890 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804B894 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804B898 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804B89C @ =0x080FEEBA
	b _0804B8BE
	.align 2, 0
_0804B88C: .4byte gMission
_0804B890: .4byte RNG_0202f388
_0804B894: .4byte 0x000343FD
_0804B898: .4byte 0x00269EC3
_0804B89C: .4byte 0x080FEEBA
_0804B8A0:
	adds r0, r6, #0
	bl isHellbatFarAway
	adds r3, r0, #0
	ldr r2, _0804B8F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804B8F4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804B8F8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ldr r5, _0804B8FC @ =0x080FEE98
_0804B8BE:
	lsls r4, r3, #4
	adds r4, r4, r3
	adds r1, r4, r5
	ldrb r1, [r1]
	bl __umodsi3
	adds r4, #1
	adds r4, r0, r4
	adds r4, r4, r5
	ldrb r1, [r4]
_0804B8D2:
	strb r1, [r6, #0xd]
	strb r7, [r6, #0xe]
	mov r2, r8
	ldrb r0, [r2]
	mov r2, sb
	strb r0, [r2]
	mov r0, r8
	strb r1, [r0]
_0804B8E2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B8F0: .4byte RNG_0202f388
_0804B8F4: .4byte 0x000343FD
_0804B8F8: .4byte 0x00269EC3
_0804B8FC: .4byte 0x080FEE98

	thumb_func_start FUN_0804b900
FUN_0804b900: @ 0x0804B900
	movs r0, #1
	bx lr

	thumb_func_start hellbatMode4
hellbatMode4: @ 0x0804B904
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0804B910
	b _0804BA3A
_0804B910:
	lsls r0, r0, #2
	ldr r1, _0804B91C @ =_0804B920
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804B91C: .4byte _0804B920
_0804B920: @ jump table
	.4byte _0804B934 @ case 0
	.4byte _0804B9B0 @ case 1
	.4byte _0804B9C4 @ case 2
	.4byte _0804B9D8 @ case 3
	.4byte _0804BA10 @ case 4
_0804B934:
	ldr r0, _0804B964 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0804B968
	movs r0, #0x80
	lsls r0, r0, #8
	adds r3, r1, r0
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804B988
	.align 2, 0
_0804B964: .4byte pZero2
_0804B968:
	ldr r0, _0804B9BC @ =0xFFFF8000
	adds r3, r1, r0
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804B988:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r3, r0
	movs r1, #0x3c
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0804B9C0 @ =0x00007E90
	movs r1, #0x3c
	bl __divsi3
	str r0, [r4, #0x60]
	movs r0, #0x3b
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804B9B0:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0804BA02
	subs r0, #1
	strb r0, [r4, #0x13]
	b _0804B9FC
	.align 2, 0
_0804B9BC: .4byte 0xFFFF8000
_0804B9C0: .4byte 0x00007E90
_0804B9C4:
	ldr r1, _0804BA0C @ =0x0000A805
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804B9D8:
	ldr r2, [r4, #0x60]
	subs r2, #0x12
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BA02
	subs r0, #1
	strb r0, [r4, #0x12]
_0804B9FC:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BA3A
_0804BA02:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804BA3A
	.align 2, 0
_0804BA0C: .4byte 0x0000A805
_0804BA10:
	adds r0, r4, #0
	adds r0, #0xd0
	ldr r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _0804BA2C
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r2, r3
	cmp r1, r0
	ble _0804BA32
_0804BA2C:
	movs r1, #0
	movs r0, #5
	b _0804BA36
_0804BA32:
	movs r1, #0
	movs r0, #3
_0804BA36:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804BA3A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804ba40
FUN_0804ba40: @ 0x0804BA40
	movs r0, #1
	bx lr

	thumb_func_start hellbatDisappear
hellbatDisappear: @ 0x0804BA44
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _0804BA50
	b _0804BCEE
_0804BA50:
	lsls r0, r0, #2
	ldr r1, _0804BA5C @ =_0804BA60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BA5C: .4byte _0804BA60
_0804BA60: @ jump table
	.4byte _0804BA84 @ case 0
	.4byte _0804BAA8 @ case 1
	.4byte _0804BB10 @ case 2
	.4byte _0804BB4C @ case 3
	.4byte _0804BB98 @ case 4
	.4byte _0804BBB0 @ case 5
	.4byte _0804BC5C @ case 6
	.4byte _0804BC7C @ case 7
	.4byte _0804BCD8 @ case 8
_0804BA84:
	ldr r1, _0804BAD0 @ =0x0000A80F
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BAD4 @ =0x08363148
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x5c]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804BAA8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BABA
	b _0804BCEE
_0804BABA:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0804BAD8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BADE
	.align 2, 0
_0804BAD0: .4byte 0x0000A80F
_0804BAD4: .4byte 0x08363148
_0804BAD8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BADE:
	strb r0, [r4, #0xa]
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _0804BAF2
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BAF2
	b _0804BCEE
_0804BAF2:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BB0C @ =0x08362F50
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
	.align 2, 0
_0804BB0C: .4byte 0x08362F50
_0804BB10:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BB22
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BB28
_0804BB22:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BB28:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BB42
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BB42
	b _0804BCEE
_0804BB42:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BB4C:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BB60
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	adds r0, r0, r1
	b _0804BB6A
_0804BB60:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	subs r0, r0, r1
_0804BB6A:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x27
	bhi _0804BB86
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _0804BB86
	b _0804BCEE
_0804BB86:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BB98:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BBAA
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BBAA
	b _0804BCEE
_0804BBAA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BBB0:
	ldr r2, _0804BC1C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804BC20 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804BC24 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0xd0
	ldr r0, [r0]
	adds r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r4, #0x64]
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r2, _0804BC28 @ =0xFFFFB800
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, _0804BC2C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0804BC30
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804BC56
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	b _0804BC54
	.align 2, 0
_0804BC1C: .4byte RNG_0202f388
_0804BC20: .4byte 0x000343FD
_0804BC24: .4byte 0x00269EC3
_0804BC28: .4byte 0xFFFFB800
_0804BC2C: .4byte pZero2
_0804BC30:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804BC56
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804BC54:
	strb r0, [r4, #0xa]
_0804BC56:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
_0804BC5C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804BC98 @ =0x0000A810
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804BC7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BC9C
	lsrs r1, r1, #1
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	b _0804BCA6
	.align 2, 0
_0804BC98: .4byte 0x0000A810
_0804BC9C:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x19
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	subs r0, r0, r1
_0804BCA6:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BCBE
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BCEE
_0804BCBE:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BCD4 @ =0x08362F68
	bl SetDDP
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804BCEC
	.align 2, 0
_0804BCD4: .4byte 0x08362F68
_0804BCD8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804BCEE
	movs r0, #0
	strb r1, [r4, #0xd]
_0804BCEC:
	strb r0, [r4, #0xe]
_0804BCEE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804bcf4
FUN_0804bcf4: @ 0x0804BCF4
	movs r0, #1
	bx lr

	thumb_func_start hellbatBatShower
hellbatBatShower: @ 0x0804BCF8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #6
	bls _0804BD06
	b _0804BECE
_0804BD06:
	lsls r0, r0, #2
	ldr r1, _0804BD10 @ =_0804BD14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BD10: .4byte _0804BD14
_0804BD14: @ jump table
	.4byte _0804BD30 @ case 0
	.4byte _0804BD52 @ case 1
	.4byte _0804BD7C @ case 2
	.4byte _0804BD94 @ case 3
	.4byte _0804BDFC @ case 4
	.4byte _0804BEA0 @ case 5
	.4byte _0804BEB8 @ case 6
_0804BD30:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BD78 @ =0x08362F68
	bl SetDDP
	movs r1, #0
	movs r0, #0x28
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldr r0, [r6, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BD52:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BD72
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BD72
	b _0804BECE
_0804BD72:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BD78: .4byte 0x08362F68
_0804BD7C:
	movs r0, #0x85
	bl PlaySound
	ldr r1, _0804BDF4 @ =0x0000A811
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BD94:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0804BDCA
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0804BDCA
	movs r0, #1
	strb r0, [r6, #0x13]
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BDF8 @ =0x08362FE0
	bl SetDDP
_0804BDCA:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BDD6
	b _0804BECE
_0804BDD6:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BDE6
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
_0804BDE6:
	movs r0, #6
	strb r0, [r6, #0x12]
	movs r0, #0x10
	strb r0, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BDF4: .4byte 0x0000A811
_0804BDF8: .4byte 0x08362FE0
_0804BDFC:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0804BE20
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
_0804BE20:
	ldr r2, [r6, #0x54]
	str r2, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804BE3C
	ldr r1, _0804BE38 @ =0xFFFFE800
	b _0804BE40
	.align 2, 0
_0804BE38: .4byte 0xFFFFE800
_0804BE3C:
	movs r1, #0xc0
	lsls r1, r1, #5
_0804BE40:
	adds r0, r2, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0804BE90 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r5, _0804BE94 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _0804BE98 @ =0x000343FD
	adds r2, r0, #0
	muls r2, r3, r2
	ldr r1, _0804BE9C @ =0x00269EC3
	adds r2, r2, r1
	lsls r2, r2, #1
	lsrs r0, r2, #1
	lsrs r2, r2, #0x11
	movs r4, #3
	ands r2, r4
	muls r3, r0, r3
	adds r3, r3, r1
	lsls r3, r3, #1
	lsrs r0, r3, #1
	str r0, [r5]
	lsrs r3, r3, #0x11
	ands r3, r4
	adds r0, r6, #0
	mov r1, sp
	bl createBat
	movs r0, #6
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BECE
	ldrb r0, [r6, #0xe]
	adds r0, #1
	b _0804BECC
	.align 2, 0
_0804BE90: .4byte 0xFFFFE000
_0804BE94: .4byte RNG_0202f388
_0804BE98: .4byte 0x000343FD
_0804BE9C: .4byte 0x00269EC3
_0804BEA0:
	ldr r1, _0804BED8 @ =0x0000A812
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0804BEDC @ =0x08362F68
	bl SetDDP
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0804BEB8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804BECE
	movs r0, #0
	strb r1, [r6, #0xd]
_0804BECC:
	strb r0, [r6, #0xe]
_0804BECE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BED8: .4byte 0x0000A812
_0804BEDC: .4byte 0x08362F68

	thumb_func_start FUN_0804bee0
FUN_0804bee0: @ 0x0804BEE0
	movs r0, #1
	bx lr

	thumb_func_start hellbatEchoWave
hellbatEchoWave: @ 0x0804BEE4
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0804BEF2
	b _0804C218
_0804BEF2:
	lsls r0, r0, #2
	ldr r1, _0804BEFC @ =_0804BF00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804BEFC: .4byte _0804BF00
_0804BF00: @ jump table
	.4byte _0804BF38 @ case 0
	.4byte _0804BF5C @ case 1
	.4byte _0804BFC0 @ case 2
	.4byte _0804BFF8 @ case 3
	.4byte _0804C1F4 @ case 4
	.4byte _0804C03C @ case 5
	.4byte _0804C150 @ case 6
	.4byte _0804C162 @ case 7
	.4byte _0804C17E @ case 8
	.4byte _0804C1B0 @ case 9
	.4byte _0804C1EE @ case 10
	.4byte _0804C1DC @ case 11
	.4byte _0804C1EE @ case 12
	.4byte _0804C210 @ case 13
_0804BF38:
	ldr r1, _0804BF84 @ =0x0000A80F
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BF88 @ =0x08363148
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x5c]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804BF5C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804BF6E
	b _0804C218
_0804BF6E:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0804BF8C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BF92
	.align 2, 0
_0804BF84: .4byte 0x0000A80F
_0804BF88: .4byte 0x08363148
_0804BF8C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BF92:
	strb r0, [r4, #0xa]
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _0804BFA6
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BFA6
	b _0804C218
_0804BFA6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804BFBC @ =0x08362F50
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r4, #0x12]
	b _0804C204
	.align 2, 0
_0804BFBC: .4byte 0x08362F50
_0804BFC0:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BFD2
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804BFD8
_0804BFD2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804BFD8:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BFF2
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804BFF2
	b _0804C218
_0804BFF2:
	movs r0, #0
	strb r0, [r4, #0x12]
	b _0804C204
_0804BFF8:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804C00C
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	adds r0, r0, r1
	b _0804C016
_0804C00C:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r4, #0x5c]
	subs r0, r0, r1
_0804C016:
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x27
	bhi _0804C032
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _0804C032
	b _0804C218
_0804C032:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	b _0804C14A
_0804C03C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804C09C @ =0x0000A810
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C0A0 @ =0x08362F68
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0xd0
	ldr r0, _0804C0A4 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r3, _0804C0A8 @ =0xFFFF9000
	adds r0, r0, r3
	ldr r5, [r1]
	subs r6, r5, r0
	cmp r6, #0
	bgt _0804C06E
	subs r6, r0, r5
_0804C06E:
	str r6, [sp]
	ldr r0, [r2, #0x54]
	ldr r3, _0804C0AC @ =0xFFFF5000
	adds r0, r0, r3
	subs r3, r5, r0
	cmp r3, #0
	bgt _0804C07E
	subs r3, r0, r5
_0804C07E:
	str r3, [sp, #4]
	ldr r0, [r2, #0x54]
	ldr r2, _0804C0B0 @ =0xFFFF1000
	adds r0, r0, r2
	subs r2, r5, r0
	cmp r2, #0
	bgt _0804C08E
	subs r2, r0, r5
_0804C08E:
	str r2, [sp, #8]
	cmp r6, r3
	bge _0804C0B4
	movs r0, #2
	cmp r6, r2
	bge _0804C0BC
	b _0804C0C0
	.align 2, 0
_0804C09C: .4byte 0x0000A810
_0804C0A0: .4byte 0x08362F68
_0804C0A4: .4byte pZero2
_0804C0A8: .4byte 0xFFFF9000
_0804C0AC: .4byte 0xFFFF5000
_0804C0B0: .4byte 0xFFFF1000
_0804C0B4:
	movs r0, #2
	cmp r3, r2
	bge _0804C0BC
	movs r0, #1
_0804C0BC:
	cmp r0, #0
	bne _0804C0CA
_0804C0C0:
	ldr r0, [r1]
	movs r3, #0xe0
	lsls r3, r3, #7
	adds r0, r0, r3
	b _0804C0E0
_0804C0CA:
	cmp r0, #1
	bne _0804C0D8
	ldr r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r0, r1
	b _0804C0E0
_0804C0D8:
	ldr r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r0, r0, r2
_0804C0E0:
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x64]
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r3, _0804C120 @ =0xFFFFCE00
	adds r0, r0, r3
	str r0, [r4, #0x58]
	ldr r0, _0804C124 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0804C128
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804C10A
	b _0804C204
_0804C10A:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r4, #0xa]
	orrs r0, r2
	b _0804C14C
	.align 2, 0
_0804C120: .4byte 0xFFFFCE00
_0804C124: .4byte pZero2
_0804C128:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804C204
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
_0804C14A:
	ands r0, r1
_0804C14C:
	strb r0, [r4, #0xa]
	b _0804C204
_0804C150:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C218
	b _0804C204
_0804C162:
	ldr r1, _0804C1A8 @ =0x0000A809
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x86
	bl PlaySound
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C17E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0804C1F4
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0804C1F4
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C1AC @ =0x08363088
	bl SetDDP
	b _0804C1F4
	.align 2, 0
_0804C1A8: .4byte 0x0000A809
_0804C1AC: .4byte 0x08363088
_0804C1B0:
	movs r5, #0
	add r6, sp, #0xc
_0804C1B4:
	ldr r0, [r4, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x58]
	ldr r1, _0804C1D8 @ =0xFFFFD600
	adds r0, r0, r1
	str r0, [r6, #4]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r6, #0
	bl createEchoWave
	adds r5, #1
	cmp r5, #5
	ble _0804C1B4
	movs r0, #0x20
	b _0804C1E6
	.align 2, 0
_0804C1D8: .4byte 0xFFFFD600
_0804C1DC:
	ldr r1, _0804C20C @ =0x0000A80A
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
_0804C1E6:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C1EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0804C1F4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C204
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C218
_0804C204:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804C218
	.align 2, 0
_0804C20C: .4byte 0x0000A80A
_0804C210:
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804C218:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804c220
FUN_0804c220: @ 0x0804C220
	movs r0, #1
	bx lr

	thumb_func_start hellbatThunderRevorb
hellbatThunderRevorb: @ 0x0804C224
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xe
	bls _0804C232
	b _0804C542
_0804C232:
	lsls r0, r0, #2
	ldr r1, _0804C23C @ =_0804C240
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804C23C: .4byte _0804C240
_0804C240: @ jump table
	.4byte _0804C27C @ case 0
	.4byte _0804C298 @ case 1
	.4byte _0804C2E0 @ case 2
	.4byte _0804C2F2 @ case 3
	.4byte _0804C310 @ case 4
	.4byte _0804C31A @ case 5
	.4byte _0804C32C @ case 6
	.4byte _0804C41C @ case 7
	.4byte _0804C422 @ case 8
	.4byte _0804C460 @ case 9
	.4byte _0804C47C @ case 10
	.4byte _0804C4AC @ case 11
	.4byte _0804C4C4 @ case 12
	.4byte _0804C514 @ case 13
	.4byte _0804C52C @ case 14
_0804C27C:
	ldr r1, _0804C2D8 @ =0x0000A802
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C2DC @ =0x08362F68
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C298:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804C2A8
	str r1, [r4, #0x60]
_0804C2A8:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C2CE
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C2CE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0804C542
	.align 2, 0
_0804C2D8: .4byte 0x0000A802
_0804C2DC: .4byte 0x08362F68
_0804C2E0:
	ldr r1, _0804C30C @ =0x0000A803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C2F2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804C304
	b _0804C542
_0804C304:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C30C: .4byte 0x0000A803
_0804C310:
	movs r0, #4
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C31A:
	ldr r1, _0804C3A8 @ =0x0000A813
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C32C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C342
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C342:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	beq _0804C352
	b _0804C542
_0804C352:
	adds r0, r4, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0804C362
	b _0804C542
_0804C362:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C3AC @ =0x08362FE0
	bl SetDDP
	ldr r6, [r4, #0x54]
	str r6, [sp]
	ldr r5, [r4, #0x58]
	str r5, [sp, #4]
	ldr r2, _0804C3B0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804C3B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804C3B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _0804C3C4
	ldr r1, _0804C3BC @ =0xFFFFF800
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3C0 @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3A8: .4byte 0x0000A813
_0804C3AC: .4byte 0x08362FE0
_0804C3B0: .4byte RNG_0202f388
_0804C3B4: .4byte 0x000343FD
_0804C3B8: .4byte 0x00269EC3
_0804C3BC: .4byte 0xFFFFF800
_0804C3C0: .4byte 0xFFFFD800
_0804C3C4:
	cmp r2, #1
	bne _0804C3E4
	ldr r1, _0804C3DC @ =0xFFFFE000
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3E0 @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3DC: .4byte 0xFFFFE000
_0804C3E0: .4byte 0xFFFFD800
_0804C3E4:
	ldr r1, _0804C3F8 @ =0xFFFFD000
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3FC @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3F8: .4byte 0xFFFFD000
_0804C3FC: .4byte 0xFFFFD800
_0804C400:
	movs r1, #0xa0
	lsls r1, r1, #6
_0804C404:
	adds r0, r6, r1
	str r0, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080a14dc
	movs r0, #0x87
	bl PlaySound
	b _0804C542
_0804C41C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C422:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C43A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C43A
	b _0804C542
_0804C43A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C458 @ =0x08362F68
	bl SetDDP
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C45C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C458: .4byte 0x08362F68
_0804C45C:
	movs r0, #5
	b _0804C540
_0804C460:
	ldr r1, _0804C4A4 @ =0x0000A814
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C4A8 @ =0x08362F68
	bl SetDDP
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C47C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C542
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C49C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C542
_0804C49C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C4A4: .4byte 0x0000A814
_0804C4A8: .4byte 0x08362F68
_0804C4AC:
	ldr r1, _0804C4F0 @ =0x0000A801
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C4F4 @ =0x08362F68
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C4C4:
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r1, _0804C4F8 @ =0xFFFFB800
	adds r5, r0, r1
	ldr r1, [r4, #0x58]
	subs r0, r5, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x58]
	subs r2, r5, r1
	cmp r2, #0
	ble _0804C500
	ldr r0, _0804C4FC @ =0x000003FF
	cmp r2, r0
	ble _0804C508
	b _0804C542
	.align 2, 0
_0804C4F0: .4byte 0x0000A801
_0804C4F4: .4byte 0x08362F68
_0804C4F8: .4byte 0xFFFFB800
_0804C4FC: .4byte 0x000003FF
_0804C500:
	subs r1, r1, r5
	ldr r0, _0804C510 @ =0x000003FF
	cmp r1, r0
	bgt _0804C542
_0804C508:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C510: .4byte 0x000003FF
_0804C514:
	ldr r1, _0804C54C @ =0x0000A802
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C550 @ =0x08362F68
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C52C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804C542
	movs r0, #0
	strb r1, [r4, #0xd]
_0804C540:
	strb r0, [r4, #0xe]
_0804C542:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C54C: .4byte 0x0000A802
_0804C550: .4byte 0x08362F68

	thumb_func_start FUN_0804c554
FUN_0804c554: @ 0x0804C554
	movs r0, #1
	bx lr

	thumb_func_start hellbatEX
hellbatEX: @ 0x0804C558
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x19
	bls _0804C566
	b _0804C9E2
_0804C566:
	lsls r0, r0, #2
	ldr r1, _0804C570 @ =_0804C574
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804C570: .4byte _0804C574
_0804C574: @ jump table
	.4byte _0804C5DC @ case 0
	.4byte _0804C5FC @ case 1
	.4byte _0804C660 @ case 2
	.4byte _0804C69E @ case 3
	.4byte _0804C6DE @ case 4
	.4byte _0804C724 @ case 5
	.4byte _0804C748 @ case 6
	.4byte _0804C7A4 @ case 7
	.4byte _0804C9A4 @ case 8
	.4byte _0804C860 @ case 9
	.4byte _0804C896 @ case 10
	.4byte _0804C8AA @ case 11
	.4byte _0804C9E2 @ case 12
	.4byte _0804C9E2 @ case 13
	.4byte _0804C9E2 @ case 14
	.4byte _0804C9E2 @ case 15
	.4byte _0804C9E2 @ case 16
	.4byte _0804C9E2 @ case 17
	.4byte _0804C9E2 @ case 18
	.4byte _0804C9E2 @ case 19
	.4byte _0804C8FC @ case 20
	.4byte _0804C90E @ case 21
	.4byte _0804C916 @ case 22
	.4byte _0804C948 @ case 23
	.4byte _0804C9A4 @ case 24
	.4byte _0804C9BC @ case 25
_0804C5DC:
	ldr r1, _0804C624 @ =0x0000A80F
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804C628 @ =0x08363148
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x5c]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C5FC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804C60E
	b _0804C9E2
_0804C60E:
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0804C62C
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804C632
	.align 2, 0
_0804C624: .4byte 0x0000A80F
_0804C628: .4byte 0x08363148
_0804C62C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804C632:
	strb r0, [r5, #0xa]
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _0804C646
	subs r0, r2, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C646
	b _0804C9E2
_0804C646:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804C65C @ =0x08362F50
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r5, #0x12]
	b _0804C9B4
	.align 2, 0
_0804C65C: .4byte 0x08362F50
_0804C660:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804C678
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0804C67E
_0804C678:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0804C67E:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804C698
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C698
	b _0804C9E2
_0804C698:
	movs r0, #0
	strb r0, [r5, #0x12]
	b _0804C9B4
_0804C69E:
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804C6B2
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r5, #0x5c]
	adds r0, r0, r1
	b _0804C6BC
_0804C6B2:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r5, #0x5c]
	subs r0, r0, r1
_0804C6BC:
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0x27
	bhi _0804C6D8
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _0804C6D8
	b _0804C9E2
_0804C6D8:
	movs r0, #0x30
	strb r0, [r5, #0x12]
	b _0804C9B4
_0804C6DE:
	ldr r1, _0804C740 @ =0x0000A803
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x88
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r1, _0804C744 @ =0xFFFF7200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0
	strb r0, [r5, #0x13]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x4d
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C724:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804C6D8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C73C
	b _0804C9E2
_0804C73C:
	b _0804C6D8
	.align 2, 0
_0804C740: .4byte 0x0000A803
_0804C744: .4byte 0xFFFF7200
_0804C748:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r0, [r0]
	movs r2, #0xe0
	lsls r2, r2, #7
	adds r1, r0, r2
	str r1, [sp]
	movs r3, #0xb0
	lsls r3, r3, #8
	adds r1, r0, r3
	str r1, [sp, #4]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	add r0, sp
	ldr r0, [r0]
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804C79E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C79E
	b _0804C9E2
_0804C79E:
	movs r0, #3
	strb r0, [r5, #0x13]
	b _0804C9B4
_0804C7A4:
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, _0804C7F4 @ =pZero2
	ldr r6, [r1]
	ldr r1, [r6, #0x54]
	ldr r3, _0804C7F8 @ =0xFFFF9000
	adds r2, r1, r3
	ldr r4, [r0]
	subs r1, r4, r2
	adds r7, r0, #0
	cmp r1, #0
	bgt _0804C7BE
	subs r1, r2, r4
_0804C7BE:
	str r1, [sp]
	ldr r0, [r6, #0x54]
	ldr r2, _0804C7FC @ =0xFFFF5000
	adds r0, r0, r2
	subs r3, r4, r0
	cmp r3, #0
	bgt _0804C7CE
	subs r3, r0, r4
_0804C7CE:
	str r3, [sp, #4]
	ldr r0, [r6, #0x54]
	ldr r2, _0804C800 @ =0xFFFF1000
	adds r0, r0, r2
	subs r2, r4, r0
	cmp r2, #0
	bgt _0804C7DE
	subs r2, r0, r4
_0804C7DE:
	str r2, [sp, #8]
	cmp r1, r3
	ble _0804C804
	cmp r1, r2
	bgt _0804C810
	movs r0, #2
	cmp r3, r2
	ble _0804C80C
	movs r0, #1
	b _0804C81A
	.align 2, 0
_0804C7F4: .4byte pZero2
_0804C7F8: .4byte 0xFFFF9000
_0804C7FC: .4byte 0xFFFF5000
_0804C800: .4byte 0xFFFF1000
_0804C804:
	movs r0, #2
	cmp r3, r2
	ble _0804C80C
	movs r0, #1
_0804C80C:
	cmp r0, #0
	bne _0804C81A
_0804C810:
	ldr r0, [r7]
	movs r3, #0xe0
	lsls r3, r3, #7
	adds r0, r0, r3
	b _0804C830
_0804C81A:
	cmp r0, #1
	bne _0804C828
	ldr r0, [r7]
	movs r1, #0xb0
	lsls r1, r1, #8
	adds r0, r0, r1
	b _0804C830
_0804C828:
	ldr r0, [r7]
	movs r2, #0xf0
	lsls r2, r2, #8
	adds r0, r0, r2
_0804C830:
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	adds r1, r5, #0
	adds r1, #0x54
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl createHellbatElectricBeam
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804C85C @ =0x083631A8
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804C9A4
	.align 2, 0
_0804C85C: .4byte 0x083631A8
_0804C860:
	ldr r0, [r5, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x58]
	movs r3, #0xb8
	lsls r3, r3, #6
	adds r0, r0, r3
	add r1, sp, #0xc
	str r0, [r1, #4]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080a1538
	movs r0, #0x89
	bl PlaySound
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0804C890
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C890
	b _0804C9B4
_0804C890:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0804C9E2
_0804C896:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804C8F8 @ =0x08362F50
	bl SetDDP
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C8AA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r0, [r0]
	movs r2, #0xe0
	lsls r2, r2, #7
	adds r1, r0, r2
	str r1, [sp]
	movs r3, #0xb0
	lsls r3, r3, #8
	adds r1, r0, r3
	str r1, [sp, #4]
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	add r0, sp
	ldr r0, [r0]
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804C8F0
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C9E2
_0804C8F0:
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0804C9E2
	.align 2, 0
_0804C8F8: .4byte 0x08362F50
_0804C8FC:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C90E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _0804C9A4
_0804C916:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0804C970 @ =0x0000A801
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0804C974 @ =0x08362F50
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r5, #0x68]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C948:
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804C978
	lsrs r1, r1, #2
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	b _0804C982
	.align 2, 0
_0804C970: .4byte 0x0000A801
_0804C974: .4byte 0x08362F50
_0804C978:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1a
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	subs r0, r0, r1
_0804C982:
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	cmp r0, #0x1d
	bhi _0804C996
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _0804C9E2
_0804C996:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #8
	strb r0, [r5, #0x12]
	b _0804C9B4
_0804C9A4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0804C9B4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C9E2
_0804C9B4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804C9E2
_0804C9BC:
	adds r0, r5, #0
	adds r0, #0x4d
	movs r2, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
	strb r2, [r5, #0xf]
_0804C9E2:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0804c9ec
nop_0804c9ec: @ 0x0804C9EC
	movs r0, #1
	bx lr

	thumb_func_start hellbatDamage
hellbatDamage: @ 0x0804C9F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804CA00
	cmp r5, #1
	beq _0804CA46
	b _0804CA82
_0804CA00:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x8a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804CA3E
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CA3E:
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804CA46:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804CA56
	str r1, [r4, #0x60]
_0804CA56:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804CA7A
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	movs r1, #0x80
	lsls r1, r1, #2
	b _0804CA7E
_0804CA7A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0804CA7E:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CA82:
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0804CA9A
	movs r1, #0
	str r1, [r5]
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804CA9A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804caa0
FUN_0804caa0: @ 0x0804CAA0
	movs r0, #1
	bx lr

	thumb_func_start hellbatKnockBackDamage
hellbatKnockBackDamage: @ 0x0804CAA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804CAB4
	cmp r5, #1
	beq _0804CB62
	b _0804CBD4
_0804CAB4:
	movs r0, #0x8a
	bl PlaySound
	ldr r1, _0804CAF0 @ =0x0000A80B
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _0804CAF4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0804CAFC
	ldr r0, _0804CAF8 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804CB1E
	.align 2, 0
_0804CAF0: .4byte 0x0000A80B
_0804CAF4: .4byte pZero2
_0804CAF8: .4byte 0xFFFFFE00
_0804CAFC:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
_0804CB1E:
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r3, #0
	orrs r1, r0
	strb r1, [r4, #0xa]
	movs r0, #0x20
	ands r1, r0
	cmp r1, #0
	beq _0804CB52
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xe4
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0804CB52:
	adds r0, r4, #0
	adds r0, #0xc0
	str r3, [r0]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804CB62:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	cmp r0, #0
	ble _0804CB9A
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	ldr r2, _0804CBDC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804CB9A
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804CB9A:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804CBBC
	ldr r0, [r4, #0x54]
	ldr r1, _0804CBE0 @ =0xFFFFE800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _0804CBDC @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804CBBC
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0804CBBC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804CBCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804CBD4
_0804CBCC:
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804CBD4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804CBDC: .4byte 0xFFFFF800
_0804CBE0: .4byte 0xFFFFE800

	thumb_func_start hellbat_0804cbe4
hellbat_0804cbe4: @ 0x0804CBE4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r6, [r5]
	cmp r6, #0
	bne _0804CC2E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804CC2E
	ldr r2, _0804CC28 @ =0x08363208
	movs r0, #0x11
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0804CC2E
	str r6, [r5]
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x30
	bne _0804CC2C
	movs r0, #0x8a
	bl PlaySound
	b _0804CC2E
	.align 2, 0
_0804CC28: .4byte 0x08363208
_0804CC2C:
	str r6, [r5]
_0804CC2E:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start hellbat_0804cc38
hellbat_0804cc38: @ 0x0804CC38
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _0804CC4E
	cmp r0, #0xe
	beq _0804CC4E
	cmp r0, #0xf
	bne _0804CC90
_0804CC4E:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0804CC70
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804CC90
_0804CC70:
	ldr r0, _0804CC88 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0804CC90
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _0804CC8C
	movs r0, #0xff
	b _0804CC8E
	.align 2, 0
_0804CC88: .4byte gStageRun
_0804CC8C:
	movs r0, #0xfe
_0804CC8E:
	strb r0, [r2, #0x11]
_0804CC90:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _0804CCC2
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804CCC2
	ldr r0, [r2, #4]
	ldr r1, _0804CCC8 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _0804CCC2
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	cmp r0, #0xb
	beq _0804CCC2
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0804CCC2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CCC8: .4byte 0x000200FF

	thumb_func_start FUN_0804cccc
FUN_0804cccc: @ 0x0804CCCC
	push {r4, r5, lr}
	adds r4, r1, #0
	cmp r2, #1
	bne _0804CD06
	movs r2, #0
	ldr r5, _0804CCEC @ =0x080FEEDC
	adds r3, r5, #0
_0804CCDA:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804CCF0
	adds r3, #2
	adds r2, #1
	cmp r2, #5
	ble _0804CCDA
	b _0804CD1A
	.align 2, 0
_0804CCEC: .4byte 0x080FEEDC
_0804CCF0:
	adds r0, r2, #1
	movs r1, #6
	b _0804CCFA
_0804CCF6:
	adds r0, r2, #1
	movs r1, #5
_0804CCFA:
	bl __modsi3
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0804CD1A
_0804CD06:
	movs r2, #0
	ldr r5, _0804CD20 @ =0x080FEEDC
	adds r3, r5, #0
_0804CD0C:
	ldrh r1, [r3]
	cmp r1, r4
	beq _0804CCF6
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0804CD0C
_0804CD1A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804CD20: .4byte 0x080FEEDC

	thumb_func_start isHellbatFarAway
isHellbatFarAway: @ 0x0804CD24
	push {lr}
	ldr r1, _0804CD3C @ =pZero2
	ldr r1, [r1]
	ldr r3, [r1, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0804CD44
	ldr r0, _0804CD40 @ =0x00004FFF
	cmp r2, r0
	ble _0804CD4C
	b _0804CD54
	.align 2, 0
_0804CD3C: .4byte pZero2
_0804CD40: .4byte 0x00004FFF
_0804CD44:
	subs r1, r1, r3
	ldr r0, _0804CD50 @ =0x00004FFF
	cmp r1, r0
	bgt _0804CD54
_0804CD4C:
	movs r0, #0
	b _0804CD56
	.align 2, 0
_0804CD50: .4byte 0x00004FFF
_0804CD54:
	movs r0, #1
_0804CD56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start hellbat_0804cd5c
hellbat_0804cd5c: @ 0x0804CD5C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x1e]
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r3, _0804CDA0 @ =0x0000A80E
	cmp r0, r3
	bne _0804CDCC
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804CE02
	ldrb r1, [r2, #0xa]
	movs r3, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804CDA4
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldrb r0, [r2, #0xa]
	orrs r0, r3
	b _0804CDBE
	.align 2, 0
_0804CDA0: .4byte 0x0000A80E
_0804CDA4:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
_0804CDBE:
	strb r0, [r2, #0xa]
	movs r1, #0xa8
	lsls r1, r1, #8
	adds r0, r2, #0
	bl SetMotion
	b _0804CE02
_0804CDCC:
	ldr r0, _0804CDEC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	ble _0804CDF0
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804CE02
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
	b _0804CE02
	.align 2, 0
_0804CDEC: .4byte pZero2
_0804CDF0:
	ldrb r1, [r2, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0804CE02
	adds r0, r2, #0
	adds r1, r3, #0
	bl SetMotion
_0804CE02:
	pop {r0}
	bx r0
	.align 2, 0
