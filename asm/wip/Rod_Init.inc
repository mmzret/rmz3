	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	ldr r1, _08039540 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08039544 @ =0x08360430
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	ldr r1, _08039548 @ =0x083611F4
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	mov r8, r0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #0x15
	bne _0803954C
	movs r0, #0x38
	bl PlaySound
	b _0803955E
	.align 2, 0
_08039540: .4byte gWeaponFnTable
_08039544: .4byte 0x08360430
_08039548: .4byte 0x083611F4
_0803954C:
	cmp r0, #0xa
	bhi _08039558
	movs r0, #0x36
	bl PlaySound
	b _0803955E
_08039558:
	movs r0, #0x37
	bl PlaySound
_0803955E:
	adds r2, r6, #0
	adds r2, #0xb4
	movs r4, #1
	strb r4, [r2, #7]
	ldr r1, _08039598 @ =0x083611F4
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r1, [r0, #6]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _080395A0
	ldr r1, _0803959C @ =0x0836045C
	mov r2, sb
	adds r2, #0xb4
	ldrb r0, [r2, #0xe]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	movs r0, #8
	strb r0, [r5, #5]
	adds r7, r2, #0
	b _080395C2
	.align 2, 0
_08039598: .4byte 0x083611F4
_0803959C: .4byte 0x0836045C
_080395A0:
	ldr r0, _080395FC @ =0x0836045C
	ldrb r0, [r0]
	strb r0, [r5, #4]
	movs r0, #8
	strb r0, [r5, #5]
	ldr r1, _08039600 @ =0x08360430
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	mov r7, sb
	adds r7, #0xb4
	cmp r0, #0
	beq _080395C2
	strb r3, [r5, #7]
_080395C2:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x15
	bne _080395CC
	movs r0, #6
	strb r0, [r5, #5]
_080395CC:
	mov r0, sb
	bl CalcRodBonus
	ldrb r1, [r5, #5]
	adds r0, r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _08039604
	adds r4, r6, #0
	adds r4, #0x74
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #4]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	ldrb r0, [r5, #7]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	bl InitWeaponBody
	b _0803961C
	.align 2, 0
_080395FC: .4byte 0x0836045C
_08039600: .4byte 0x08360430
_08039604:
	adds r4, r6, #0
	adds r4, #0x74
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #4]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	bl InitWeaponBody
_0803961C:
	movs r0, #0
	strb r0, [r5, #6]
	ldrh r1, [r7, #0x12]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08039644
	ldrb r0, [r6, #0x10]
	cmp r0, #0xc
	beq _08039636
	cmp r0, #0xf
	bne _08039644
_08039636:
	ldrb r0, [r7, #0xe]
	cmp r0, #2
	bne _08039640
	movs r0, #1
	b _08039642
_08039640:
	movs r0, #2
_08039642:
	strb r0, [r5, #6]
_08039644:
	movs r0, #1
	strb r0, [r5, #8]
	ldr r0, _08039660 @ =FUN_08039960
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl Rod_Update
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039660: .4byte FUN_08039960
