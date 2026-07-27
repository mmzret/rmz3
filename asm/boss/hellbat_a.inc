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
	ldr r1, _0804B73C @ =sCollisions+(1*24)
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
	bl UpdateEntityAnim
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
_0804B73C: .4byte sCollisions+(1*24)
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
	bl UpdateEntityAnim
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
	ldr r0, _0804B7F0 @ =gScore
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
	ldr r5, _0804B800 @ =HellbatFarModes
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
_0804B7F0: .4byte gScore
_0804B7F4: .4byte RNG_0202f388
_0804B7F8: .4byte 0x000343FD
_0804B7FC: .4byte 0x00269EC3
_0804B800: .4byte HellbatFarModes
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
	ldr r5, _0804B85C @ =HellbatNearModes
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
_0804B85C: .4byte HellbatNearModes
_0804B860:
	ldr r0, _0804B88C @ =gScore
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
	ldr r5, _0804B89C @ =HellbatFarModes
	b _0804B8BE
	.align 2, 0
_0804B88C: .4byte gScore
_0804B890: .4byte RNG_0202f388
_0804B894: .4byte 0x000343FD
_0804B898: .4byte 0x00269EC3
_0804B89C: .4byte HellbatFarModes
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
	ldr r5, _0804B8FC @ =HellbatNearModes
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
_0804B8FC: .4byte HellbatNearModes
