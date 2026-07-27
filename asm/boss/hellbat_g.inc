	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl UpdateEntityAnim
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
_0804C628: .4byte sCollisions+(21*24)
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
	ldr r1, _0804C65C @ =sCollisions
	bl SetDDP
	movs r0, #0x84
	bl PlaySound
	movs r0, #0xa
	strb r0, [r5, #0x12]
	b _0804C9B4
	.align 2, 0
_0804C65C: .4byte sCollisions
_0804C660:
	adds r0, r5, #0
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	bl UpdateEntityAnim
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
	ldr r1, _0804C85C @ =sCollisions+(25*24)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0804C9A4
	.align 2, 0
_0804C85C: .4byte sCollisions+(25*24)
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
	ldr r1, _0804C8F8 @ =sCollisions
	bl SetDDP
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0804C8AA:
	adds r0, r5, #0
	bl UpdateEntityAnim
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
_0804C8F8: .4byte sCollisions
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
	bl UpdateEntityAnim
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
	ldr r1, _0804C974 @ =sCollisions
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
	bl UpdateEntityAnim
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
_0804C974: .4byte sCollisions
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
