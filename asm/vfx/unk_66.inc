	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c44a8
FUN_080c44a8: @ 0x080C44A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080C450C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080C4500
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080C4510 @ =gVFXFnTable
	movs r1, #0x42
	strb r1, [r4, #9]
	adds r1, #0xc6
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080C4500:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C450C: .4byte gVFXHeaderPtr
_080C4510: .4byte gVFXFnTable

	thumb_func_start Ghost66_Init
Ghost66_Init: @ 0x080C4514
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080C4550
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080C4570
_080C4550:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080C4570:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080C457C
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080C457E
_080C457C:
	movs r0, #0xc0
_080C457E:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080C45A8
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080C45A4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080C45DA
	.align 2, 0
_080C45A4: .4byte gVFXFnTable
_080C45A8:
	ldr r2, _080C45EC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C45F0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C45F4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080C45F8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	movs r0, #2
	strb r0, [r4, #0xd]
_080C45DA:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl Ghost66_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C45EC: .4byte RNG_0202f388
_080C45F0: .4byte 0x000343FD
_080C45F4: .4byte 0x00269EC3
_080C45F8: .4byte gVFXFnTable

	thumb_func_start Ghost66_Update
Ghost66_Update: @ 0x080C45FC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C4628 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080C4630
	ldr r1, _080C462C @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Ghost66_Die
	b _080C4640
	.align 2, 0
_080C4628: .4byte gCurStory
_080C462C: .4byte gVFXFnTable
_080C4630:
	ldr r0, _080C4644 @ =0x0836F5C0
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080C4640:
	pop {r0}
	bx r0
	.align 2, 0
_080C4644: .4byte 0x0836F5C0

	thumb_func_start Ghost66_Die
Ghost66_Die: @ 0x080C4648
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080C4664 @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080C4664: .4byte gVFXFnTable

	thumb_func_start nop_080c4668
nop_080c4668: @ 0x080C4668
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c466c
FUN_080c466c: @ 0x080C466C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C46E8
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C46D0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C46D4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C46D8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46DC @ =0x00007507
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46E0 @ =0x00007508
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C46E4 @ =0x00007509
	mov r0, sp
	b _080C4754
	.align 2, 0
_080C46D0: .4byte RNG_0202f388
_080C46D4: .4byte 0x000343FD
_080C46D8: .4byte 0x00269EC3
_080C46DC: .4byte 0x00007507
_080C46E0: .4byte 0x00007508
_080C46E4: .4byte 0x00007509
_080C46E8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C478C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C478C
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080C4770 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C4774 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080C4778 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r6, #0x10]
	ldr r2, _080C477C @ =0x00007507
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C4780 @ =0x00007508
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r6, #0x10]
	ldr r2, _080C4784 @ =0x00007509
	adds r0, r5, #0
_080C4754:
	adds r3, r4, #0
	bl FUN_080c44a8
	ldr r1, _080C4788 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080C47D2
	.align 2, 0
_080C4770: .4byte RNG_0202f388
_080C4774: .4byte 0x000343FD
_080C4778: .4byte 0x00269EC3
_080C477C: .4byte 0x00007507
_080C4780: .4byte 0x00007508
_080C4784: .4byte 0x00007509
_080C4788: .4byte gVFXFnTable
_080C478C:
	ldrb r1, [r6, #0xe]
	cmp r1, #0
	beq _080C4798
	cmp r1, #1
	beq _080C47AC
	b _080C47D2
_080C4798:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	str r1, [r6, #0x60]
	ldr r1, _080C47DC @ =0x00007506
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080C47AC:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C47BC
	str r1, [r6, #0x60]
_080C47BC:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080C47D2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C47DC: .4byte 0x00007506

	thumb_func_start FUN_080c47e0
FUN_080c47e0: @ 0x080C47E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C4816
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C4838
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C4838
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C4838
_080C4816:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080C4834 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C4906
	.align 2, 0
_080C4834: .4byte gVFXFnTable
_080C4838:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C4846
	cmp r0, #1
	beq _080C48B0
	b _080C4906
_080C4846:
	ldr r4, _080C48C8 @ =0x0836F62C
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080C48CC @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C48D0 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C48D4 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C48B0:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C48D8
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C48DE
	.align 2, 0
_080C48C8: .4byte 0x0836F62C
_080C48CC: .4byte RNG_0202f388
_080C48D0: .4byte 0x000343FD
_080C48D4: .4byte 0x00269EC3
_080C48D8:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C48DE:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C48F0
	str r1, [r7, #0x60]
_080C48F0:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080C4906:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
