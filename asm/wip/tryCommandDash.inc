	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, _08033754 @ =0x0000022F
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _08033760
	subs r0, #1
	strb r0, [r3]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08033758 @ =0x00000216
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0803375C
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #8
	orrs r1, r2
	str r1, [r0]
	b _080338A6
	.align 2, 0
_08033754: .4byte 0x0000022F
_08033758: .4byte 0x00000216
_0803375C:
	strb r5, [r3]
	b _080338A6
_08033760:
	movs r5, #0x85
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08033800
	movs r2, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #5
	mov r8, r1
	adds r3, r1, #0
	movs r0, #0x10
	mov ip, r0
_08033786:
	lsls r0, r2, #1
	adds r0, r7, r0
	ldrh r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08033796
	b _080338A6
_08033796:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080337A0
	b _080338A6
_080337A0:
	mov r0, ip
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080337F4
	adds r3, r2, #0
	adds r6, r3, #0
	adds r6, #0xa
	cmp r3, r6
	bge _080338A6
	movs r1, #0x86
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, _080337F0 @ =0x0000022F
	adds r4, r4, r0
_080337C0:
	lsls r0, r3, #1
	adds r0, r7, r0
	ldrh r1, [r0]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	bne _080337E2
	ldrh r0, [r5]
	mov r1, r8
	orrs r0, r1
	strh r0, [r5]
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x1c
	strb r0, [r4]
_080337E2:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r6
	blt _080337C0
	b _080338A6
	.align 2, 0
_080337F0: .4byte 0x0000022F
_080337F4:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #9
	bls _08033786
	b _08033896
_08033800:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _080338A4
	movs r2, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #5
	mov r8, r1
	adds r3, r1, #0
	movs r0, #0x20
	mov ip, r0
_08033822:
	lsls r0, r2, #1
	adds r0, r7, r0
	ldrh r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080338A6
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080338A6
	mov r0, ip
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803388C
	adds r3, r2, #0
	adds r6, r3, #0
	adds r6, #0xb
	cmp r3, r6
	bge _080338A6
	movs r1, #0x86
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, _08033888 @ =0x0000022F
	adds r4, r4, r0
_08033858:
	lsls r0, r3, #1
	adds r0, r7, r0
	ldrh r1, [r0]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	bne _0803387A
	ldrh r0, [r5]
	mov r1, r8
	orrs r0, r1
	strh r0, [r5]
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x1c
	strb r0, [r4]
_0803387A:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r6
	blt _08033858
	b _080338A6
	.align 2, 0
_08033888: .4byte 0x0000022F
_0803388C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xa
	bls _08033822
_08033896:
	ldr r2, _080338A0 @ =0x0000022F
	adds r0, r4, r2
	strb r1, [r0]
	b _080338A6
	.align 2, 0
_080338A0: .4byte 0x0000022F
_080338A4:
	strb r0, [r3]
_080338A6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
