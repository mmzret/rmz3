	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateSeaotterElf
CreateSeaotterElf: @ 0x080E45B8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E4610 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E4620
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E4614 @ =gElfFnTable
	movs r0, #9
	strb r0, [r3, #9]
	ldr r0, [r1, #0x24]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r4, [r0]
	strb r7, [r3, #0x10]
	strb r6, [r3, #0x11]
	strb r5, [r3, #0x12]
	cmp r5, #0
	bne _080E4618
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E461E
	.align 2, 0
_080E4610: .4byte gElfHeaderPtr
_080E4614: .4byte gElfFnTable
_080E4618:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E461E:
	strb r0, [r3, #0x13]
_080E4620:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start SeaOtterElf_Init
SeaOtterElf_Init: @ 0x080E4628
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E46F4 @ =gZeroRanges
	ldr r2, _080E46F8 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x54]
	asrs r4, r4, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0xb8
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x58]
	str r0, [r1]
	adds r2, #0x78
	movs r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #0x20
	strb r0, [r1]
	mov r2, r8
	str r2, [r7, #0x2c]
	ldr r1, _080E46FC @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl SeaOtterElf_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E46F4: .4byte gZeroRanges
_080E46F8: .4byte 0x00000147
_080E46FC: .4byte gElfFnTable

	thumb_func_start SeaOtterElf_Update
SeaOtterElf_Update: @ 0x080E4700
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080E476C @ =gPause
	ldrb r3, [r0]
	cmp r3, #0
	beq _080E471E
	b _080E49EC
_080E471E:
	ldr r1, _080E4770 @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E4778
	ldr r2, [r4, #0x2c]
	cmp r2, #0
	beq _080E4736
	ldrb r1, [r2, #0xb]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #0xb]
_080E4736:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E4774 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E49EC
	.align 2, 0
_080E476C: .4byte gPause
_080E4770: .4byte 0x00000232
_080E4774: .4byte gElfFnTable
_080E4778:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E4794
	adds r0, r5, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E47AC
_080E4794:
	ldr r1, _080E47A8 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080E49EC
	.align 2, 0
_080E47A8: .4byte gElfFnTable
_080E47AC:
	ldr r0, _080E47E4 @ =0x08371DC0
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080E47E8
	mov r0, sp
	bl FUN_080e16c4
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r1, [r4, #0x64]
	ldr r0, [r3]
	subs r6, r1, r0
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r1, [r4, #0x68]
	ldr r0, [r2]
	b _080E4860
	.align 2, 0
_080E47E4: .4byte 0x08371DC0
_080E47E8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E4820
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E4814
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r6, r1, r0
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E485C
_080E4814:
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r2, #0xd0
	lsls r2, r2, #4
	b _080E484C
_080E4820:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E4844
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E4840 @ =0xFFFFE500
	adds r0, r0, r2
	ldr r1, [r5, #0x54]
	subs r6, r1, r0
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E485C
	.align 2, 0
_080E4840: .4byte 0xFFFFE500
_080E4844:
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E48A4 @ =0xFFFFF300
_080E484C:
	adds r0, r0, r2
	ldr r1, [r5, #0x54]
	subs r6, r1, r0
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E485C:
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
_080E4860:
	subs r5, r1, r0
	adds r7, r3, #0
	mov r8, r2
	adds r0, r6, #0
	adds r1, r5, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E487A
	rsbs r1, r6, #0
_080E487A:
	adds r0, r5, #0
	cmp r5, #0
	bge _080E4882
	rsbs r0, r5, #0
_080E4882:
	cmp r1, r0
	ble _080E48AC
	adds r1, r6, #0
	cmp r1, #0
	bge _080E488E
	rsbs r1, r1, #0
_080E488E:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E48D0
	ldr r1, [r4, #0x5c]
	ldr r0, _080E48A8 @ =0x000005FF
	cmp r1, r0
	bgt _080E48E2
	adds r0, r1, #0
	adds r0, #0x80
	b _080E48E0
	.align 2, 0
_080E48A4: .4byte 0xFFFFF300
_080E48A8: .4byte 0x000005FF
_080E48AC:
	adds r1, r5, #0
	cmp r1, #0
	bge _080E48B4
	rsbs r1, r1, #0
_080E48B4:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E48D0
	ldr r1, [r4, #0x5c]
	ldr r0, _080E48CC @ =0x000005FF
	cmp r1, r0
	bgt _080E48E2
	adds r0, r1, #0
	adds r0, #0x80
	b _080E48E0
	.align 2, 0
_080E48CC: .4byte 0x000005FF
_080E48D0:
	ldr r0, [r4, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E48DC
	str r1, [r4, #0x5c]
_080E48DC:
	ldr r0, [r4, #0x5c]
	subs r0, #0x20
_080E48E0:
	str r0, [r4, #0x5c]
_080E48E2:
	ldr r0, [r4, #0x5c]
	cmp r0, #0x8f
	bgt _080E48EC
	movs r0, #0x90
	str r0, [r4, #0x5c]
_080E48EC:
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E48FE
	ldr r0, [r4, #0x64]
	str r0, [r7]
	ldr r0, [r4, #0x68]
	mov r2, r8
	str r0, [r2]
	b _080E4930
_080E48FE:
	ldr r2, _080E494C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, [r4, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r7]
	adds r0, r0, r1
	str r0, [r7]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r3]
_080E4930:
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bne _080E4950
	ldr r0, [r7]
	str r0, [r4, #0x54]
	mov r5, r8
	ldr r0, [r5]
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	b _080E49CC
	.align 2, 0
_080E494C: .4byte gSineTable
_080E4950:
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r5, [r1]
	lsls r3, r5, #3
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E49A0
	ldr r2, _080E499C @ =gSineTable
	movs r0, #0x3f
	subs r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r1, r1, #2
	ldr r0, [r7]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	mvns r0, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	mov r3, r8
	ldr r0, [r3]
	subs r0, r0, r1
	b _080E49CA
	.align 2, 0
_080E499C: .4byte gSineTable
_080E49A0:
	ldr r2, _080E49F8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r7]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r5, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r1, r1, #2
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
_080E49CA:
	str r0, [r4, #0x58]
_080E49CC:
	adds r5, r4, #0
	adds r5, #0xc1
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E49EC
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r5]
_080E49EC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E49F8: .4byte gSineTable

	thumb_func_start SeaOtterElf_Die
SeaOtterElf_Die: @ 0x080E49FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x2c]
	cmp r2, #0
	beq _080E4A0E
	ldrb r1, [r2, #0xb]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #0xb]
_080E4A0E:
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E4A38 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E4A38: .4byte gElfFnTable

	thumb_func_start FUN_080e4a3c
FUN_080e4a3c: @ 0x080E4A3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _080E4A52
	movs r0, #0x40
	strb r0, [r4, #0xf]
	adds r0, r1, #1
	strb r0, [r4, #0xe]
_080E4A52:
	ldrb r0, [r4, #0xf]
	adds r5, r0, #0
	cmp r5, #0
	beq _080E4A60
	subs r0, #1
	strb r0, [r4, #0xf]
	b _080E4A82
_080E4A60:
	adds r0, r2, #0
	bl CheckPlayerStandStill
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E4A82
	adds r0, r4, #0
	adds r0, #0x54
	bl FUN_080e1608
	str r0, [r4, #0x2c]
	cmp r0, #0
	beq _080E4A82
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_080E4A82:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e4a88
FUN_080e4a88: @ 0x080E4A88
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldr r1, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080E4A9C
	adds r0, #1
	strb r0, [r4, #0xe]
_080E4A9C:
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080E4AAE
	adds r0, r2, #0
	bl CheckPlayerStandStill
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E4AB6
_080E4AAE:
	movs r1, #0
	str r1, [r4, #0x2c]
	movs r0, #3
	b _080E4ADE
_080E4AB6:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r0, r2
	bhi _080E4AE2
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	cmp r0, r2
	bhi _080E4AE2
	movs r1, #0
	movs r0, #2
_080E4ADE:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080E4AE2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e4ae8
FUN_080e4ae8: @ 0x080E4AE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldr r5, [r4, #0x2c]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	bne _080E4B00
	movs r0, #0x40
	strb r0, [r4, #0xf]
	adds r0, r1, #1
	strb r0, [r4, #0xe]
_080E4B00:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bhi _080E4B12
	adds r0, r2, #0
	bl CheckPlayerStandStill
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E4B26
_080E4B12:
	ldrb r1, [r5, #0xb]
	movs r0, #0x7f
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xb]
	str r1, [r4, #0x2c]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080E4B50
_080E4B26:
	ldrb r0, [r4, #0xf]
	subs r0, #1
	movs r2, #0
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E4B48
	ldrb r0, [r5, #0xb]
	movs r1, #0x7f
	ands r1, r0
	strb r1, [r5, #0xb]
	str r2, [r4, #0x2c]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080E4B50
_080E4B48:
	ldrb r0, [r5, #0xb]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r5, #0xb]
_080E4B50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080e4b58
FUN_080e4b58: @ 0x080E4B58
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _080E4B6A
	movs r0, #0x40
	strb r0, [r1, #0xf]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_080E4B6A:
	ldr r0, [r1, #0x5c]
	cmp r0, #0x90
	ble _080E4B7E
	ldrb r0, [r1, #0xf]
	subs r0, #1
	strb r0, [r1, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E4B84
_080E4B7E:
	movs r0, #0
	strb r0, [r1, #0xd]
	strb r0, [r1, #0xe]
_080E4B84:
	pop {r0}
	bx r0
