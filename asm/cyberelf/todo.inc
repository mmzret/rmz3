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
	bl createElfAction
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
	bl FUN_080e1b10
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
	bl FUN_080e1b10
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
	bl FUN_080e1b10
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

	thumb_func_start FUN_080e4b88
FUN_080e4b88: @ 0x080E4B88
	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, [r3, #0x64]
	cmp r2, #0
	bne _080E4BAA
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E4BEC
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E4BBE
_080E4BAA:
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _080E4BEC
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_080E4BBE:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080E4BF0 @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080E4BEC:
	pop {r0}
	bx r0
	.align 2, 0
_080E4BF0: .4byte gElfFnTable

	thumb_func_start elf_080e4bf4
elf_080e4bf4: @ 0x080E4BF4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E4C4C @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E4C5C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E4C50 @ =gElfFnTable
	movs r0, #0xa
	strb r0, [r3, #9]
	ldr r0, [r1, #0x28]
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
	str r5, [r3, #0x64]
	cmp r5, #0
	bne _080E4C54
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E4C5A
	.align 2, 0
_080E4C4C: .4byte gElfHeaderPtr
_080E4C50: .4byte gElfFnTable
_080E4C54:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E4C5A:
	strb r0, [r3, #0x13]
_080E4C5C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Elf10_Init
Elf10_Init: @ 0x080E4C64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E4D30 @ =gZeroRanges
	ldr r2, _080E4D34 @ =0x00000147
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
	bl createElfAction
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
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	ldr r1, _080E4D38 @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl Elf10_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E4D30: .4byte gZeroRanges
_080E4D34: .4byte 0x00000147
_080E4D38: .4byte gElfFnTable

	thumb_func_start Elf10_Update
Elf10_Update: @ 0x080E4D3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080E4D9C @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	beq _080E4D5A
	b _080E500A
_080E4D5A:
	ldr r1, _080E4DA0 @ =0x00000232
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E4DA8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E4DA4 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080E500A
	.align 2, 0
_080E4D9C: .4byte gPause
_080E4DA0: .4byte 0x00000232
_080E4DA4: .4byte gElfFnTable
_080E4DA8:
	adds r0, r7, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E4DC4
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E4DDC
_080E4DC4:
	ldr r1, _080E4DD8 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080E500A
	.align 2, 0
_080E4DD8: .4byte gElfFnTable
_080E4DDC:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E4E14
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4E08
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E4E50
_080E4E08:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r2, #0xd0
	lsls r2, r2, #4
	b _080E4E40
_080E4E14:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4E38
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E4E34 @ =0xFFFFE500
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E4E50
	.align 2, 0
_080E4E34: .4byte 0xFFFFE500
_080E4E38:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E4E98 @ =0xFFFFF300
_080E4E40:
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E4E50:
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	subs r4, r1, r0
	mov r8, r3
	mov sb, r2
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E4E6E
	rsbs r1, r6, #0
_080E4E6E:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E4E76
	rsbs r0, r4, #0
_080E4E76:
	cmp r1, r0
	ble _080E4EA0
	adds r1, r6, #0
	cmp r1, #0
	bge _080E4E82
	rsbs r1, r1, #0
_080E4E82:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4EC4
	ldr r1, [r5, #0x5c]
	ldr r0, _080E4E9C @ =0x000005FF
	cmp r1, r0
	bgt _080E4ED6
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4ED4
	.align 2, 0
_080E4E98: .4byte 0xFFFFF300
_080E4E9C: .4byte 0x000005FF
_080E4EA0:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E4EA8
	rsbs r1, r1, #0
_080E4EA8:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4EC4
	ldr r1, [r5, #0x5c]
	ldr r0, _080E4EC0 @ =0x000005FF
	cmp r1, r0
	bgt _080E4ED6
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4ED4
	.align 2, 0
_080E4EC0: .4byte 0x000005FF
_080E4EC4:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E4ED0
	str r1, [r5, #0x5c]
_080E4ED0:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E4ED4:
	str r0, [r5, #0x5c]
_080E4ED6:
	ldr r0, [r5, #0x5c]
	cmp r0, #0x9f
	bgt _080E4EE0
	movs r0, #0xa0
	str r0, [r5, #0x5c]
_080E4EE0:
	mov r6, r8
	ldr r3, _080E4F5C @ =gSineTable
	mov ip, r3
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r6]
	mov r4, sb
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _080E4F60
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r6]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	mvns r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r4]
	subs r0, r0, r1
	b _080E4F8A
	.align 2, 0
_080E4F5C: .4byte gSineTable
_080E4F60:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r1
_080E4F8A:
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E4F96
	subs r0, #1
	b _080E4FE8
_080E4F96:
	adds r0, r7, #0
	bl FUN_080e1b10
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E4FE6
	ldr r0, [r5, #0x64]
	cmp r0, #0
	bne _080E4FB0
	adds r0, r7, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	b _080E4FB6
_080E4FB0:
	adds r0, r7, #0
	adds r0, #0xb4
	ldrb r1, [r0, #1]
_080E4FB6:
	ldr r0, _080E4FD8 @ =gUnlockedElfPtr
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E4FDC
	ldrb r2, [r5, #0x10]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080e5048
	b _080E4FE6
	.align 2, 0
_080E4FD8: .4byte gUnlockedElfPtr
_080E4FDC:
	ldrb r2, [r5, #0x10]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080e5048
_080E4FE6:
	movs r0, #0x3c
_080E4FE8:
	strb r0, [r5, #0x12]
	adds r4, r5, #0
	adds r4, #0xc1
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E500A
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E500A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Elf10_Die
Elf10_Die: @ 0x080E5018
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E5044 @ =gElfFnTable
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
_080E5044: .4byte gElfFnTable

	thumb_func_start FUN_080e5048
FUN_080e5048: @ 0x080E5048
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080E5094 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E508C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E5098 @ =gElfFnTable
	movs r0, #0xb
	strb r0, [r3, #9]
	ldr r0, [r1, #0x2c]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	adds r0, #0x92
	str r5, [r0]
	adds r0, #4
	str r6, [r0]
	strb r4, [r3, #0x10]
	strb r1, [r3, #0x11]
_080E508C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080E5094: .4byte gElfHeaderPtr
_080E5098: .4byte gElfFnTable

	thumb_func_start Elf11_Init
Elf11_Init: @ 0x080E509C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080E50F4 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x22
	movs r5, #1
	strb r1, [r0]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xb]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0xa]
	orrs r0, r5
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E50F8 @ =0x08371DF8
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl Elf11_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E50F4: .4byte gElfFnTable
_080E50F8: .4byte 0x08371DF8

	thumb_func_start Elf11_Update
Elf11_Update: @ 0x080E50FC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080E5154 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	bne _080E5170
	ldr r1, _080E5158 @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E5160
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080E515C @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E5170
	.align 2, 0
_080E5154: .4byte gPause
_080E5158: .4byte 0x00000232
_080E515C: .4byte gElfFnTable
_080E5160:
	ldr r0, _080E5178 @ =0x08371E08
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_080E5170:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5178: .4byte 0x08371E08

	thumb_func_start Elf11_Die
Elf11_Die: @ 0x080E517C
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080E51AC @ =gElfFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080E51AC: .4byte gElfFnTable

	thumb_func_start FUN_080e51b0
FUN_080e51b0: @ 0x080E51B0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	adds r0, #4
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	adds r5, r6, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080E51F8
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E51FE
_080E51F8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E51FE:
	strb r0, [r6, #0xa]
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E529C
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E525E
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E529C
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E5294
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E529A
_080E525E:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E5294
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E529A
_080E5294:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E529A:
	strb r0, [r6, #0xa]
_080E529C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_08034520
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E52EC @ =0x08371E18
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E52F0
	movs r0, #0xc0
	lsls r0, r0, #3
	b _080E52F2
	.align 2, 0
_080E52EC: .4byte 0x08371E18
_080E52F0:
	ldr r0, _080E52FC @ =0xFFFFFA00
_080E52F2:
	str r0, [r6, #0x5c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E52FC: .4byte 0xFFFFFA00

	thumb_func_start FUN_080e5300
FUN_080e5300: @ 0x080E5300
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0xb8
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl SetMotion
	adds r6, r7, #0
	adds r6, #0x4c
	movs r0, #0
	strb r0, [r6]
	movs r1, #0x4a
	adds r1, r1, r7
	mov sl, r1
	ldrb r1, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r2, sl
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	bl FUN_08034520
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7, #0xa]
	movs r2, #4
	orrs r1, r2
	strb r1, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E53DC @ =0x08371E18
	adds r1, r1, r0
	adds r5, r7, #0
	adds r5, #0x54
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	mov r2, r8
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r7, #0x54]
	str r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_080e1608
	adds r1, r0, #0
	str r1, [r7, #0x2c]
	cmp r1, #0
	beq _080E53E4
	mov r0, sp
	bl FUN_080e16c4
	ldr r2, [sp]
	ldr r3, [sp, #4]
	ldr r0, [r7, #0x54]
	subs r0, r2, r0
	ldr r1, [r7, #0x58]
	subs r1, r3, r1
	bl CalcAngle
	adds r2, r7, #0
	adds r2, #0xbc
	strb r0, [r2]
	ldr r3, _080E53E0 @ =gSineTable
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	str r0, [r7, #0x5c]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	b _080E5494
	.align 2, 0
_080E53DC: .4byte 0x08371E18
_080E53E0: .4byte gSineTable
_080E53E4:
	mov r4, sb
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E547C
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	mov r0, sb
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E5440
	mov r0, sb
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E547C
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	strb r0, [r6]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	lsls r3, r1, #4
	mov r0, sl
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, sl
	strb r0, [r2]
	cmp r1, #0
	beq _080E5474
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E547A
_080E5440:
	mov r4, sb
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	strb r0, [r6]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	lsls r3, r1, #4
	mov r0, sl
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, sl
	strb r0, [r2]
	cmp r1, #0
	beq _080E5474
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E547A
_080E5474:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E547A:
	strb r0, [r7, #0xa]
_080E547C:
	mov r4, sb
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E548E
	movs r0, #0xc0
	lsls r0, r0, #3
	b _080E5490
_080E548E:
	ldr r0, _080E54A8 @ =0xFFFFFA00
_080E5490:
	str r0, [r7, #0x5c]
	movs r0, #0
_080E5494:
	str r0, [r7, #0x60]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E54A8: .4byte 0xFFFFFA00

	thumb_func_start FUN_080e54ac
FUN_080e54ac: @ 0x080E54AC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	adds r0, #4
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	adds r5, r6, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _080E54F4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E54FA
_080E54F4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E54FA:
	strb r0, [r6, #0xa]
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	bne _080E5598
	ldrb r1, [r4, #0x1e]
	lsls r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r0, r1
	movs r1, #0xa0
	lsls r1, r1, #3
	cmp r0, r1
	bne _080E555A
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	ble _080E5598
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E5590
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5596
_080E555A:
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E5590
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5596
_080E5590:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E5596:
	strb r0, [r6, #0xa]
_080E5598:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_0803455c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _080E55E8 @ =0x08371E18
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E55EC
	movs r0, #0x80
	lsls r0, r0, #3
	b _080E55EE
	.align 2, 0
_080E55E8: .4byte 0x08371E18
_080E55EC:
	ldr r0, _080E5600 @ =0xFFFFFC00
_080E55EE:
	str r0, [r6, #0x5c]
	ldr r0, _080E5604 @ =0xFFFFFD00
	str r0, [r6, #0x60]
	movs r0, #0xb4
	strb r0, [r6, #0x12]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5600: .4byte 0xFFFFFC00
_080E5604: .4byte 0xFFFFFD00

	thumb_func_start FUN_080e5608
FUN_080e5608: @ 0x080E5608
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb8
	ldr r7, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl SetMotion
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E564A
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E5650
_080E564A:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E5650:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	bl FUN_0803455c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6, #0xa]
	movs r1, #4
	movs r5, #0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080E569C @ =0x08371F08
	adds r1, r1, r0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	movs r0, #0x27
	bl PlaySound
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E569C: .4byte 0x08371F08

	thumb_func_start FUN_080e56a0
FUN_080e56a0: @ 0x080E56A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E56C6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E56E4
_080E56C6:
	ldr r1, _080E56E0 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
	b _080E570C
	.align 2, 0
_080E56E0: .4byte gElfFnTable
_080E56E4:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080E570C
	movs r0, #0x2b
	bl PlaySound
	ldr r1, _080E5714 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E570C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E5714: .4byte gElfFnTable

	thumb_func_start FUN_080e5718
FUN_080e5718: @ 0x080E5718
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E5746
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E5764
_080E5746:
	ldr r1, _080E5760 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
	b _080E578C
	.align 2, 0
_080E5760: .4byte gElfFnTable
_080E5764:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _080E578C
	movs r0, #0x2b
	bl PlaySound
	ldr r1, _080E5794 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E578C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E5794: .4byte gElfFnTable

	thumb_func_start FUN_080e5798
FUN_080e5798: @ 0x080E5798
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
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
	ble _080E57BE
	str r0, [r4, #0x60]
_080E57BE:
	adds r0, r4, #0
	bl FUN_080e586c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #0x12]
	subs r2, r1, #1
	strb r2, [r4, #0x12]
	cmp r0, #1
	beq _080E57E6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080E5810 @ =0x00001004
	ands r0, r1
	cmp r0, #0
	bne _080E57E6
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _080E5808
_080E57E6:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #3
	bl FUN_080e5048
	ldr r1, _080E5814 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf11_Die
_080E5808:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5810: .4byte 0x00001004
_080E5814: .4byte gElfFnTable

	thumb_func_start FUN_080e5818
FUN_080e5818: @ 0x080E5818
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080E5840
	movs r1, #0
	str r1, [r3]
	adds r0, r2, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
_080E5840:
	adds r0, r2, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080E5862
	ldr r1, _080E5868 @ =gElfFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Elf11_Die
_080E5862:
	pop {r0}
	bx r0
	.align 2, 0
_080E5868: .4byte gElfFnTable

	thumb_func_start FUN_080e586c
FUN_080e586c: @ 0x080E586C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r2, _080E5894 @ =0x7FF20000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080E5888
	movs r1, #0
_080E5888:
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _080E5898
	movs r0, #1
	b _080E58B6
	.align 2, 0
_080E5894: .4byte 0x7FF20000
_080E5898:
	ldr r0, _080E58B0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bhi _080E58B4
	movs r0, #0
	b _080E58B6
	.align 2, 0
_080E58B0: .4byte gStageRun+232
_080E58B4:
	movs r0, #2
_080E58B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080e58bc
FUN_080e58bc: @ 0x080E58BC
	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldrb r2, [r3, #0x12]
	cmp r2, #0
	bne _080E58DE
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E5920
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E58F2
_080E58DE:
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _080E5920
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_080E58F2:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080E5924 @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080E5920:
	pop {r0}
	bx r0
	.align 2, 0
_080E5924: .4byte gElfFnTable

	thumb_func_start CreateBirdElf
CreateBirdElf: @ 0x080E5928
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E5980 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E5990
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E5984 @ =gElfFnTable
	movs r0, #0xc
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
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
	bne _080E5988
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E598E
	.align 2, 0
_080E5980: .4byte gElfHeaderPtr
_080E5984: .4byte gElfFnTable
_080E5988:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E598E:
	strb r0, [r3, #0x13]
_080E5990:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start BirdElf_Init
BirdElf_Init: @ 0x080E5998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E5A64 @ =gZeroRanges
	ldr r2, _080E5A68 @ =0x00000147
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
	bl createElfAction
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
	ldr r1, _080E5A6C @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl BirdElf_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5A64: .4byte gZeroRanges
_080E5A68: .4byte 0x00000147
_080E5A6C: .4byte gElfFnTable

	thumb_func_start BirdElf_Update
BirdElf_Update: @ 0x080E5A70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080E5AC8 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	bne _080E5B38
	ldr r1, _080E5ACC @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E5AD4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _080E5AD0 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E5B38
	.align 2, 0
_080E5AC8: .4byte gPause
_080E5ACC: .4byte 0x00000232
_080E5AD0: .4byte gElfFnTable
_080E5AD4:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E5AF0
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080E5B08
_080E5AF0:
	ldr r1, _080E5B04 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080E5B38
	.align 2, 0
_080E5B04: .4byte gElfFnTable
_080E5B08:
	ldr r1, _080E5B40 @ =0x08371F94
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r5, r4, #0
	adds r5, #0xc1
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E5B38
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r5]
_080E5B38:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5B40: .4byte 0x08371F94

	thumb_func_start BirdElf_Die
BirdElf_Die: @ 0x080E5B44
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E5B70 @ =gElfFnTable
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
_080E5B70: .4byte gElfFnTable

	thumb_func_start FUN_080e5b74
FUN_080e5b74: @ 0x080E5B74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r7, [r0]
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	bne _080E5B9A
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x5c]
	adds r0, r2, #1
	strb r0, [r5, #0xe]
_080E5B9A:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E5BD2
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5BC6
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r1, #0xd8
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E5C10
_080E5BC6:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	movs r2, #0xd0
	lsls r2, r2, #4
	b _080E5C00
_080E5BD2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5BF8
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E5BF4 @ =0xFFFFE500
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E5C10
	.align 2, 0
_080E5BF4: .4byte 0xFFFFE500
_080E5BF8:
	adds r3, r5, #0
	adds r3, #0xb8
	ldr r0, [r3]
	ldr r2, _080E5C58 @ =0xFFFFF300
_080E5C00:
	adds r0, r0, r2
	ldr r1, [r7, #0x54]
	subs r6, r1, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E5C10:
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	subs r4, r1, r0
	mov r8, r3
	mov sb, r2
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E5C2E
	rsbs r1, r6, #0
_080E5C2E:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E5C36
	rsbs r0, r4, #0
_080E5C36:
	cmp r1, r0
	ble _080E5C60
	adds r1, r6, #0
	cmp r1, #0
	bge _080E5C42
	rsbs r1, r1, #0
_080E5C42:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E5C84
	ldr r1, [r5, #0x5c]
	ldr r0, _080E5C5C @ =0x000005FF
	cmp r1, r0
	bgt _080E5C96
	adds r0, r1, #0
	adds r0, #0x80
	b _080E5C94
	.align 2, 0
_080E5C58: .4byte 0xFFFFF300
_080E5C5C: .4byte 0x000005FF
_080E5C60:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E5C68
	rsbs r1, r1, #0
_080E5C68:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E5C84
	ldr r1, [r5, #0x5c]
	ldr r0, _080E5C80 @ =0x000005FF
	cmp r1, r0
	bgt _080E5C96
	adds r0, r1, #0
	adds r0, #0x80
	b _080E5C94
	.align 2, 0
_080E5C80: .4byte 0x000005FF
_080E5C84:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E5C90
	str r1, [r5, #0x5c]
_080E5C90:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E5C94:
	str r0, [r5, #0x5c]
_080E5C96:
	ldr r0, [r5, #0x5c]
	cmp r0, #0xbf
	bgt _080E5CA0
	movs r0, #0xc0
	str r0, [r5, #0x5c]
_080E5CA0:
	mov r6, r8
	ldr r3, _080E5D1C @ =gSineTable
	mov ip, r3
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r6]
	mov r4, sb
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5, #0x5c]
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080E5D20
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r6]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	mvns r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r4]
	subs r0, r0, r1
	b _080E5D4A
	.align 2, 0
_080E5D1C: .4byte gSineTable
_080E5D20:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r1
_080E5D4A:
	str r0, [r5, #0x58]
	ldrb r0, [r7, #0xd]
	cmp r0, #8
	bne _080E5D5C
	ldrb r0, [r5, #0xd]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080E5D5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e5d68
FUN_080e5d68: @ 0x080E5D68
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	ldrb r1, [r7, #0xe]
	cmp r1, #0
	bne _080E5D8A
	adds r0, r7, #0
	adds r0, #0xc0
	strb r1, [r0]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080E5D8A:
	adds r6, r7, #0
	adds r6, #0xb8
	mov r1, sb
	ldr r0, [r1, #0x54]
	str r0, [r6]
	movs r2, #0xbc
	adds r2, r2, r7
	mov r8, r2
	ldr r0, [r1, #0x58]
	ldr r1, _080E5E18 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r2]
	adds r4, r7, #0
	adds r4, #0xc0
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #0x30
	bl __modsi3
	adds r5, r0, #0
	strb r5, [r4]
	movs r1, #0x30
	bl __modsi3
	lsls r0, r0, #8
	movs r1, #0x30
	bl __divsi3
	ldr r4, _080E5E1C @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	ldr r0, [r6]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r5, #0
	movs r1, #0x18
	bl __modsi3
	lsls r0, r0, #8
	movs r1, #0x18
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #3
	mov r2, r8
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, sb
	ldrb r1, [r0]
	cmp r1, #0x3b
	bhi _080E5E28
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bhi _080E5E20
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E5E26
	.align 2, 0
_080E5E18: .4byte 0xFFFFE000
_080E5E1C: .4byte gSineTable
_080E5E20:
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
_080E5E26:
	strb r0, [r7, #0xa]
_080E5E28:
	mov r1, sb
	ldrb r0, [r1, #0xd]
	cmp r0, #8
	beq _080E5E36
	movs r0, #0
	strb r0, [r7, #0xd]
	strb r0, [r7, #0xe]
_080E5E36:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
