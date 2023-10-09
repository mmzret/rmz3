	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b7890
FUN_080b7890: @ 0x080B7890
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B7910
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080B78FC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B7900 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B7904 @ =0x00269EC3
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
	movs r2, #0xc1
	lsls r2, r2, #3
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b76d4
	ldrb r1, [r6, #0x10]
	ldr r2, _080B7908 @ =0x00000609
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b76d4
	ldrb r1, [r6, #0x10]
	ldr r2, _080B790C @ =0x0000060A
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080b76d4
	movs r0, #0x2a
	bl PlaySound
	b _080B7984
	.align 2, 0
_080B78FC: .4byte RNG_0202f388
_080B7900: .4byte 0x000343FD
_080B7904: .4byte 0x00269EC3
_080B7908: .4byte 0x00000609
_080B790C: .4byte 0x0000060A
_080B7910:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B79B0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B79B0
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080B7998 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B799C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080B79A0 @ =0x00269EC3
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
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b76d4
	ldrb r1, [r6, #0x10]
	ldr r2, _080B79A4 @ =0x00000609
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b76d4
	ldrb r1, [r6, #0x10]
	ldr r2, _080B79A8 @ =0x0000060A
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080b76d4
_080B7984:
	ldr r1, _080B79AC @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B79F8
	.align 2, 0
_080B7998: .4byte RNG_0202f388
_080B799C: .4byte 0x000343FD
_080B79A0: .4byte 0x00269EC3
_080B79A4: .4byte 0x00000609
_080B79A8: .4byte 0x0000060A
_080B79AC: .4byte gVFXFnTable
_080B79B0:
	ldrb r1, [r6, #0xe]
	cmp r1, #0
	beq _080B79BC
	cmp r1, #1
	beq _080B79D2
	b _080B79F8
_080B79BC:
	movs r0, #0x3c
	strb r0, [r6, #0x12]
	str r1, [r6, #0x60]
	strb r1, [r6, #0x13]
	ldr r1, _080B7A00 @ =0x00000607
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B79D2:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B79E2
	str r1, [r6, #0x60]
_080B79E2:
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
_080B79F8:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B7A00: .4byte 0x00000607

	thumb_func_start FUN_080b7a04
FUN_080b7a04: @ 0x080B7A04
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
	beq _080B7A3A
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080B7A5C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080B7A5C
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080B7A5C
_080B7A3A:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080B7A58 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080B7B2A
	.align 2, 0
_080B7A58: .4byte gVFXFnTable
_080B7A5C:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080B7A6A
	cmp r0, #1
	beq _080B7AD4
	b _080B7B2A
_080B7A6A:
	ldr r4, _080B7AEC @ =PTR_s32_ARRAY_0836e9c4
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
	ldr r3, _080B7AF0 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080B7AF4 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080B7AF8 @ =0x00269EC3
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
_080B7AD4:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B7AFC
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080B7B02
	.align 2, 0
_080B7AEC: .4byte PTR_s32_ARRAY_0836e9c4
_080B7AF0: .4byte RNG_0202f388
_080B7AF4: .4byte 0x000343FD
_080B7AF8: .4byte 0x00269EC3
_080B7AFC:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B7B02:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B7B14
	str r1, [r7, #0x60]
_080B7B14:
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
_080B7B2A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
