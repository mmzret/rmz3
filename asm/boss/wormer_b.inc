	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080428c4
FUN_080428c4: @ 0x080428C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080428D4
	cmp r0, #1
	beq _080428F0
	b _0804290A
_080428D4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08042910 @ =sCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x80
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080428F0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042904
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08042904:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804290A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042910: .4byte sCollisions

	thumb_func_start FUN_08042914
FUN_08042914: @ 0x08042914
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	beq _08042952
	cmp r0, #1
	bgt _08042928
	cmp r0, #0
	beq _08042932
	b _0804297C
_08042928:
	cmp r0, #2
	beq _08042966
	cmp r0, #3
	beq _0804296A
	b _0804297C
_08042932:
	ldrb r0, [r2, #0x10]
	cmp r0, #1
	bne _08042944
	adds r3, r2, #0
	adds r3, #0x49
	ldrb r0, [r3]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r3]
_08042944:
	ldrb r0, [r2, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08042952:
	ldr r0, [r2, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804297C
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	b _0804297C
_08042966:
	movs r0, #3
	strb r0, [r2, #0xe]
_0804296A:
	ldr r0, _08042980 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804297C
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0804297C:
	pop {r0}
	bx r0
	.align 2, 0
_08042980: .4byte gStageRun

	thumb_func_start FUN_08042984
FUN_08042984: @ 0x08042984
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08042A6C
	cmp r0, #1
	bgt _08042998
	cmp r0, #0
	beq _080429A6
	b _08042B36
_08042998:
	cmp r0, #2
	bne _0804299E
	b _08042AE8
_0804299E:
	cmp r0, #3
	bne _080429A4
	b _08042AF6
_080429A4:
	b _08042B36
_080429A6:
	ldrb r4, [r5, #0x10]
	cmp r4, #1
	bne _08042A1A
	movs r0, #0x55
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	str r0, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	cmp r1, #0
	beq _080429E4
	subs r0, #0x74
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, _080429E0 @ =0xFFFFA000
	b _08042A06
	.align 2, 0
_080429E0: .4byte 0xFFFFA000
_080429E4:
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #7
_08042A06:
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r5, #0
	adds r1, #0xb4
	str r0, [r1]
	b _08042A20
_08042A1A:
	movs r0, #0x55
	bl PlaySound
_08042A20:
	adds r0, r5, #0
	adds r0, #0xba
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0xbb
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldrb r2, [r5, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042AD0 @ =0x08362110
	adds r1, r1, r2
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #0xa8
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, _08042AD4 @ =0xFFFFFEB0
	str r0, [r5, #0x60]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042A6C:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	movs r1, #1
	ands r0, r1
	adds r4, r5, #0
	adds r4, #0xb4
	cmp r0, #0
	bne _08042AB2
	ldr r2, _08042AD8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042ADC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042AE0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _08042AE4 @ =0xFFFFF400
	adds r0, r0, r1
	ldr r3, [r5, #0x54]
	adds r3, r3, r0
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0x22
	ldrb r2, [r0]
	adds r0, r3, #0
	bl CreateGhost35
_08042AB2:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r4]
	cmp r0, r1
	bge _08042AC8
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042AC8:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08042B36
	.align 2, 0
_08042AD0: .4byte sCollisions+(1*24)
_08042AD4: .4byte 0xFFFFFEB0
_08042AD8: .4byte RNG_0202f388
_08042ADC: .4byte 0x000343FD
_08042AE0: .4byte 0x00269EC3
_08042AE4: .4byte 0xFFFFF400
_08042AE8:
	ldr r1, _08042B3C @ =0x00002B01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08042AF6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _08042B40 @ =0x0836226C
	adds r1, r5, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r3, [r5, #0x10]
	lsls r2, r3, #3
	subs r2, r2, r3
	ldrb r1, [r1]
	adds r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08042B44 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08042B36
	movs r0, #0
	strb r1, [r5, #0xd]
	strb r0, [r5, #0xe]
_08042B36:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08042B3C: .4byte 0x00002B01
_08042B40: .4byte 0x0836226C
_08042B44: .4byte sCollisions

	thumb_func_start FUN_08042b48
FUN_08042b48: @ 0x08042B48
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08042B54
	b _08042C6E
_08042B54:
	lsls r0, r0, #2
	ldr r1, _08042B60 @ =_08042B64
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042B60: .4byte _08042B64
_08042B64: @ jump table
	.4byte _08042B78 @ case 0
	.4byte _08042B94 @ case 1
	.4byte _08042BDE @ case 2
	.4byte _08042C10 @ case 3
	.4byte _08042C1E @ case 4
_08042B78:
	adds r0, r4, #0
	adds r0, #0x74
	ldrb r2, [r4, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042BBC @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	movs r0, #2
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042B94:
	ldr r2, _08042BC0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042BC4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042BC8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08042BD0
	ldr r1, _08042BCC @ =0x00002B04
	adds r0, r4, #0
	bl SetMotion
	b _08042BD8
	.align 2, 0
_08042BBC: .4byte sCollisions+(5*24)
_08042BC0: .4byte RNG_0202f388
_08042BC4: .4byte 0x000343FD
_08042BC8: .4byte 0x00269EC3
_08042BCC: .4byte 0x00002B04
_08042BD0:
	ldr r1, _08042C08 @ =0x00002B03
	adds r0, r4, #0
	bl SetMotion
_08042BD8:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042BDE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08042C6E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08042C0C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08042C6C
	.align 2, 0
_08042C08: .4byte 0x00002B03
_08042C0C:
	movs r0, #1
	b _08042C6C
_08042C10:
	ldr r1, _08042C44 @ =0x00002B05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08042C1E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08042C6E
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08042C4E
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0
	beq _08042C48
	movs r0, #6
	strb r0, [r4, #0xd]
	b _08042C6A
	.align 2, 0
_08042C44: .4byte 0x00002B05
_08042C48:
	movs r0, #4
	strb r0, [r4, #0xd]
	b _08042C6A
_08042C4E:
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _08042C5E
	movs r0, #0xa
	b _08042C60
_08042C5E:
	movs r0, #9
_08042C60:
	strb r0, [r4, #0xd]
	ldrb r0, [r2]
	movs r1, #1
	eors r0, r1
	strb r0, [r2]
_08042C6A:
	movs r0, #0
_08042C6C:
	strb r0, [r4, #0xe]
_08042C6E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042c74
FUN_08042c74: @ 0x08042C74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08042CB2
	cmp r0, #1
	bgt _08042C88
	cmp r0, #0
	beq _08042C8E
	b _08042D46
_08042C88:
	cmp r0, #2
	beq _08042CFE
	b _08042D46
_08042C8E:
	adds r0, r6, #0
	adds r0, #0x74
	ldrb r2, [r6, #0x10]
	movs r1, #0xa8
	muls r1, r2, r1
	ldr r2, _08042D20 @ =0x08362170
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _08042D24 @ =0x00002B06
	adds r0, r6, #0
	bl SetMotion
	movs r0, #4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08042CB2:
	movs r0, #0x18
	strb r0, [r6, #0x13]
	movs r0, #0x2d
	bl PlaySound
	ldr r5, [r6, #0x54]
	ldr r0, _08042D28 @ =0xFFFFDA00
	adds r5, r5, r0
	ldr r4, [r6, #0x58]
	ldr r1, _08042D2C @ =0xFFFFB800
	adds r4, r4, r1
	ldr r2, _08042D30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08042D34 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08042D38 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x28
	bl __umodsi3
	adds r2, r0, #0
	adds r2, #0x6c
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r0, #0x22
	ldrb r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateWormerRockDrone
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08042CFE:
	ldrb r0, [r6, #0x13]
	subs r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08042D40
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08042D3C
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _08042D40
	.align 2, 0
_08042D20: .4byte sCollisions+(5*24)
_08042D24: .4byte 0x00002B06
_08042D28: .4byte 0xFFFFDA00
_08042D2C: .4byte 0xFFFFB800
_08042D30: .4byte RNG_0202f388
_08042D34: .4byte 0x000343FD
_08042D38: .4byte 0x00269EC3
_08042D3C:
	movs r0, #1
	strb r0, [r6, #0xe]
_08042D40:
	adds r0, r6, #0
	bl UpdateEntityAnim
_08042D46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

