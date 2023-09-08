	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b721c
FUN_080b721c: @ 0x080B721C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080B727C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B7270
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080B7280 @ =gVFXFnTable
	movs r0, #0x14
	strb r0, [r4, #9]
	ldr r0, [r1, #0x50]
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
_080B7270:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B727C: .4byte gVFXHeaderPtr
_080B7280: .4byte gVFXFnTable

	thumb_func_start Ghost20_Init
Ghost20_Init: @ 0x080B7284
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
	bne _080B72C4
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
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080B72E6
_080B72C4:
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
	movs r0, #0xc0
_080B72E6:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _080B7310
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080B730C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080B7342
	.align 2, 0
_080B730C: .4byte gVFXFnTable
_080B7310:
	ldr r2, _080B7354 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B7358 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080B735C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x7f
	strb r0, [r4, #0x12]
	ldr r1, _080B7360 @ =gVFXFnTable
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
_080B7342:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl Ghost20_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B7354: .4byte RNG_0202f388
_080B7358: .4byte 0x000343FD
_080B735C: .4byte 0x00269EC3
_080B7360: .4byte gVFXFnTable

	thumb_func_start Ghost20_Update
Ghost20_Update: @ 0x080B7364
	push {lr}
	adds r2, r0, #0
	ldr r0, _080B7390 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B7398
	ldr r1, _080B7394 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl Ghost20_Die
	b _080B73A8
	.align 2, 0
_080B7390: .4byte gCurStory
_080B7394: .4byte gVFXFnTable
_080B7398:
	ldr r0, _080B73AC @ =0x0836E8CC
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080B73A8:
	pop {r0}
	bx r0
	.align 2, 0
_080B73AC: .4byte 0x0836E8CC

	thumb_func_start Ghost20_Die
Ghost20_Die: @ 0x080B73B0
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080B73CC @ =gVFXFnTable
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
_080B73CC: .4byte gVFXFnTable

	thumb_func_start FUN_080b73d0
FUN_080b73d0: @ 0x080B73D0
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b73d4
FUN_080b73d4: @ 0x080B73D4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B7450
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080B7438 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B743C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B7440 @ =0x00269EC3
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
	ldr r2, _080B7444 @ =0x00000409
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B7448 @ =0x0000040A
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B744C @ =0x0000040B
	mov r0, sp
	b _080B74BC
	.align 2, 0
_080B7438: .4byte RNG_0202f388
_080B743C: .4byte 0x000343FD
_080B7440: .4byte 0x00269EC3
_080B7444: .4byte 0x00000409
_080B7448: .4byte 0x0000040A
_080B744C: .4byte 0x0000040B
_080B7450:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B74F4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B74F4
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080B74D8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B74DC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B74E0 @ =0x00269EC3
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
	ldr r2, _080B74E4 @ =0x00000409
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B74E8 @ =0x0000040A
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b721c
	ldrb r1, [r6, #0x10]
	ldr r2, _080B74EC @ =0x0000040B
	adds r0, r5, #0
_080B74BC:
	adds r3, r4, #0
	bl FUN_080b721c
	ldr r1, _080B74F0 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B753C
	.align 2, 0
_080B74D8: .4byte RNG_0202f388
_080B74DC: .4byte 0x000343FD
_080B74E0: .4byte 0x00269EC3
_080B74E4: .4byte 0x00000409
_080B74E8: .4byte 0x0000040A
_080B74EC: .4byte 0x0000040B
_080B74F0: .4byte gVFXFnTable
_080B74F4:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B7500
	cmp r0, #1
	beq _080B7516
	b _080B753C
_080B7500:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	ldr r0, _080B7544 @ =0xFFFFFF00
	str r0, [r6, #0x60]
	ldr r1, _080B7548 @ =0x00000407
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B7516:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B7526
	str r1, [r6, #0x60]
_080B7526:
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
_080B753C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7544: .4byte 0xFFFFFF00
_080B7548: .4byte 0x00000407

	thumb_func_start FUN_080b754c
FUN_080b754c: @ 0x080B754C
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
	beq _080B7582
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B75A4
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B75A4
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080B75A4
_080B7582:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080B75A0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080B7672
	.align 2, 0
_080B75A0: .4byte gVFXFnTable
_080B75A4:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080B75B2
	cmp r0, #1
	beq _080B761C
	b _080B7672
_080B75B2:
	ldr r4, _080B7634 @ =0x0836E938
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
	ldr r3, _080B7638 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080B763C @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080B7640 @ =0x00269EC3
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
_080B761C:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7644
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080B764A
	.align 2, 0
_080B7634: .4byte 0x0836E938
_080B7638: .4byte RNG_0202f388
_080B763C: .4byte 0x000343FD
_080B7640: .4byte 0x00269EC3
_080B7644:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B764A:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B765C
	str r1, [r7, #0x60]
_080B765C:
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
_080B7672:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
