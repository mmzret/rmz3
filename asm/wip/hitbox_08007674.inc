	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r2, _08007798 @ =gCollisionManager
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0800768E
	b _08007B72
_0800768E:
	ldr r0, [r4, #4]
	ldr r1, [r5, #0x3c]
	ldr r2, [r0, #4]
	ands r1, r2
	adds r3, r0, #0
	cmp r1, #0
	bne _0800769E
	b _08007B72
_0800769E:
	ldr r0, [r5, #4]
	ldrb r1, [r0, #2]
	adds r6, r0, #0
	cmp r1, #3
	bne _080076C0
	ldr r0, [r5, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x16
	orrs r0, r1
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x18]
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0xc5
	lsls r0, r0, #3
	add r0, r8
	str r5, [r0]
_080076C0:
	ldrb r0, [r6, #2]
	cmp r0, #4
	bne _080076DC
	ldr r0, [r5, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r0, r1
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x18]
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, _0800779C @ =0x0000062C
	add r0, r8
	str r5, [r0]
_080076DC:
	ldrb r0, [r6, #2]
	cmp r0, #5
	bne _080076FA
	ldr r0, [r5, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x18]
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0xc6
	lsls r0, r0, #3
	add r0, r8
	str r5, [r0]
_080076FA:
	mov r1, r8
	ldrb r0, [r1]
	ldrb r1, [r3, #1]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0800770C
	b _08007B72
_0800770C:
	ldrb r7, [r6, #0xa]
	movs r0, #0x21
	ands r0, r7
	cmp r0, #0
	beq _080077D0
	ldrb r1, [r3, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080077D0
	ldr r1, [r5, #0x18]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r1, #0
	ands r0, r2
	mov ip, r1
	cmp r0, #0
	bne _080077D0
	ldr r0, [r4, #0x18]
	movs r3, #0x80
	lsls r3, r3, #3
	ands r0, r3
	cmp r0, #0
	bne _080077D0
	ldr r0, [r5, #0x1c]
	ands r0, r2
	cmp r0, #0
	bne _0800774C
	ldr r0, [r4, #0x1c]
	ands r0, r3
	cmp r0, #0
	beq _080077A0
_0800774C:
	ldr r0, [r5, #0x10]
	cmp r0, r4
	bne _080077D0
	ldr r0, [r4, #0x10]
	cmp r0, r5
	bne _080077D0
	movs r0, #2
	ands r0, r7
	adds r1, r5, #0
	adds r1, #0x21
	cmp r0, #0
	beq _0800776A
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800777A
_0800776A:
	ldrb r0, [r1]
	cmp r0, #0
	beq _080077D0
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #0
	beq _080077D0
_0800777A:
	ldr r1, [r5, #0x14]
	movs r0, #0x80
	lsls r0, r0, #4
	orrs r1, r0
	str r1, [r5, #0x14]
	ldr r2, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r2, r0
	str r2, [r4, #0x14]
	mov r0, ip
	orrs r1, r0
	str r1, [r5, #0x18]
	b _080077CA
	.align 2, 0
_08007798: .4byte gCollisionManager
_0800779C: .4byte 0x0000062C
_080077A0:
	str r4, [r5, #0x10]
	str r5, [r4, #0x10]
	ldrb r1, [r6, #0xa]
	movs r0, #0xf0
	ands r0, r1
	lsrs r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x21
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
	ldr r1, [r5, #0x14]
	orrs r1, r2
	str r1, [r5, #0x14]
	ldr r2, [r4, #0x14]
	orrs r2, r3
	str r2, [r4, #0x14]
	ldr r0, [r5, #0x18]
	orrs r0, r1
	str r0, [r5, #0x18]
_080077CA:
	ldr r0, [r4, #0x18]
	orrs r0, r2
	str r0, [r4, #0x18]
_080077D0:
	ldr r1, [r4, #0x18]
	movs r0, #9
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	beq _080077DE
	b _08007B72
_080077DE:
	ldr r0, [r4, #4]
	ldr r1, [r5, #0x3c]
	ldr r2, [r0, #0xc]
	ands r1, r2
	adds r3, r0, #0
	cmp r1, #0
	bne _080077EE
	b _08007940
_080077EE:
	ldr r0, [r5, #4]
	ldrb r1, [r0, #2]
	adds r6, r0, #0
	cmp r1, #1
	bne _08007830
	ldrb r2, [r6, #4]
	cmp r2, #0
	beq _08007830
	ldr r0, [r4, #0x1c]
	movs r1, #0x18
	ands r0, r1
	cmp r0, #0
	beq _08007830
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, r2
	bne _08007830
	adds r0, r4, #0
	adds r0, #0x22
	adds r1, r5, #0
	adds r1, #0x3a
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _08007830
	str r4, [r5, #0xc]
	str r5, [r4, #0xc]
	movs r0, #0x10
	mov r1, ip
	b _08007B6E
_08007830:
	ldrb r0, [r3, #8]
	cmp r0, #0xff
	beq _08007852
	str r4, [r5, #0xc]
	ldr r2, [r5, #0x14]
	movs r0, #0x20
	orrs r2, r0
	str r2, [r5, #0x14]
	ldrb r1, [r3, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08007852
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
	str r2, [r5, #0x14]
_08007852:
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800785E
	b _08007A3E
_0800785E:
	adds r0, r5, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0800786A
	b _08007A3E
_0800786A:
	str r5, [r4, #0xc]
	ldr r0, [r4, #0x14]
	movs r1, #8
	orrs r0, r1
	str r0, [r4, #0x14]
	ldrb r0, [r6, #4]
	movs r1, #0x23
	adds r1, r1, r4
	mov ip, r1
	movs r3, #0xf
	adds r1, r3, #0
	ands r1, r0
	mov r0, ip
	ldrb r2, [r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	adds r1, r5, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #4
	ands r0, r3
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x39
	ldrb r1, [r2]
	movs r7, #4
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080078C4
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r4, #0x14]
_080078C4:
	ldrb r3, [r2]
	movs r0, #1
	ands r0, r3
	adds r2, r3, #0
	cmp r0, #0
	beq _080078DA
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	orrs r0, r1
	str r0, [r4, #0x14]
_080078DA:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080078EC
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r4, #0x14]
_080078EC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080078FE
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #9
	orrs r0, r1
	str r0, [r4, #0x14]
_080078FE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08007910
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [r4, #0x14]
_08007910:
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _08007922
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r4, #0x14]
_08007922:
	ldr r0, [r4, #4]
	ldrb r0, [r0, #8]
	cmp r0, #0xff
	bne _0800792C
	b _08007B62
_0800792C:
	ldrb r0, [r6, #4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0800793A
	b _08007B62
_0800793A:
	mov r0, r8
	strb r7, [r0, #2]
	b _08007B62
_08007940:
	ldr r0, [r5, #4]
	ldrb r1, [r0, #2]
	adds r6, r0, #0
	cmp r1, #1
	bne _08007982
	ldrb r2, [r6, #4]
	cmp r2, #0
	beq _08007982
	ldr r0, [r4, #0x1c]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08007982
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, r2
	bne _08007982
	adds r0, r4, #0
	adds r0, #0x22
	adds r1, r5, #0
	adds r1, #0x3a
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _08007982
	str r4, [r5, #0xc]
	str r5, [r4, #0xc]
	movs r0, #2
	mov r1, ip
	b _08007B6E
_08007982:
	ldrb r0, [r3, #8]
	cmp r0, #0xff
	beq _080079AE
	str r4, [r5, #0xc]
	ldr r2, [r5, #0x14]
	movs r0, #4
	orrs r2, r0
	str r2, [r5, #0x14]
	ldrb r1, [r3, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080079AE
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
	str r2, [r5, #0x14]
_080079AE:
	ldrb r0, [r3, #2]
	adds r7, r4, #0
	adds r7, #0x20
	cmp r0, #2
	bne _080079DA
	ldrb r0, [r7]
	cmp r0, #0
	beq _080079F0
	adds r0, r4, #0
	adds r0, #0x22
	adds r1, r5, #0
	adds r1, #0x3a
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080079DA
	ldrb r0, [r6, #4]
	cmp r0, #0
	beq _080079DA
	movs r0, #0
	str r0, [r5, #0x14]
	b _08007B72
_080079DA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _080079F0
	adds r0, r4, #0
	adds r0, #0x22
	adds r1, r5, #0
	adds r1, #0x3a
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _080079FA
_080079F0:
	adds r0, r5, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08007A48
_080079FA:
	adds r2, r5, #0
	adds r2, #0x39
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08007A1E
	str r4, [r5, #0xc]
	movs r0, #0x80
	lsls r0, r0, #5
	mov r1, ip
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r5, #0x14]
_08007A1E:
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08007A3E
	str r4, [r5, #0xc]
	ldr r0, [r4, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r5, #0x14]
_08007A3E:
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x14]
	orrs r0, r1
	str r0, [r5, #0x18]
	b _08007B72
_08007A48:
	str r5, [r4, #0xc]
	ldr r0, [r4, #0x14]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r4, #0x14]
	ldrb r0, [r6, #4]
	movs r1, #0x23
	adds r1, r1, r4
	mov ip, r1
	movs r3, #0xf
	adds r1, r3, #0
	ands r1, r0
	mov r0, ip
	ldrb r2, [r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	adds r1, r5, #0
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r1, r1, #4
	ands r0, r3
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x39
	ldrb r1, [r2]
	movs r6, #4
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08007AAE
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r5, #0x14]
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r4, #0x14]
_08007AAE:
	ldrb r3, [r2]
	mov r0, r8
	ands r0, r3
	adds r2, r3, #0
	cmp r0, #0
	beq _08007AC4
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #7
	orrs r0, r1
	str r0, [r4, #0x14]
_08007AC4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08007AD6
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r4, #0x14]
_08007AD6:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08007AE8
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #9
	orrs r0, r1
	str r0, [r4, #0x14]
_08007AE8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08007AFA
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [r4, #0x14]
_08007AFA:
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _08007B16
	ldr r0, [r5, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [r5, #0x14]
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r4, #0x14]
_08007B16:
	adds r0, r5, #0
	adds r1, r4, #0
	bl CalcDamage
	ldrh r1, [r4, #0x30]
	subs r1, r1, r0
	strh r1, [r4, #0x30]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _08007B38
	movs r0, #0
	strh r0, [r4, #0x30]
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r4, #0x14]
_08007B38:
	ldr r0, [r4, #4]
	ldrb r0, [r0, #8]
	cmp r0, #0xff
	beq _08007B52
	ldr r0, [r5, #4]
	ldrb r0, [r0, #4]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08007B52
	ldr r0, _08007B7C @ =gCollisionManager
	strb r6, [r0, #2]
_08007B52:
	ldr r0, [r4, #4]
	ldrb r0, [r0, #2]
	cmp r0, #1
	beq _08007B5E
	cmp r0, #2
	bne _08007B62
_08007B5E:
	movs r0, #0x5a
	strb r0, [r7]
_08007B62:
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x14]
	orrs r0, r1
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x14]
_08007B6E:
	orrs r0, r1
	str r0, [r4, #0x18]
_08007B72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007B7C: .4byte gCollisionManager
