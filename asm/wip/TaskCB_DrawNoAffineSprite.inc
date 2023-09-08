	push {r4, r5, r6, r7}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, [r0, #0xc]
	mov sb, r3
	ldrb r4, [r0, #0x1a]
	lsls r4, r4, #2
	ldr r2, [r0, #8]
	adds r3, r2, r4
	ldrh r4, [r3]
	adds r2, r2, r4
	ldrb r5, [r3, #2]
	lsls r3, r5, #3
	ldr r4, _08000680 @ =gOamManager+1024
	ldr r6, [r4]
	subs r4, r4, r3
	cmp r6, r4
	bpl _080003FC
_08000362:
	mov r3, sb
	ldr r3, [r3, #4]
	ldr r4, [r1, #0xc]
	subs r3, r3, r4
	asrs r3, r3, #8
	movs r7, #3
	ldrsb r7, [r2, r7]
	ldrb r4, [r0, #0x19]
	orrs r4, r4
	beq _08000384
	subs r3, r3, r7
	ldrh r4, [r2]
	lsrs r4, r4, #0xc
	ldr r7, _08000680+36 @ =_08000694
	ldrb r4, [r7, r4]
	subs r3, r3, r4
	b _08000386
_08000384:
	adds r3, r3, r7
_08000386:
	adds r3, #0x40
	cmp r3, #0xe0
	bhs _080003F0
	subs r3, #0x40
	mov r8, r3
	mov r3, sb
	ldr r3, [r3]
	ldr r4, [r1, #8]
	subs r3, r3, r4
	asrs r3, r3, #8
	movs r7, #2
	ldrsb r7, [r2, r7]
	ldrb r4, [r0, #0x18]
	orrs r4, r4
	beq _080003B2
	subs r3, r3, r7
	ldrh r4, [r2]
	lsrs r4, r4, #0xc
	ldr r7, _08000680+32 @ =_08000688
	ldrb r4, [r7, r4]
	subs r3, r3, r4
	b _080003B4
_080003B2:
	adds r3, r3, r7
_080003B4:
	adds r3, #0x80
	ldr r4, _08000680+4 @ =0x00000176
	cmp r3, r4
	bhs _080003F0
	subs r3, #0x80
	ldr r4, [r0, #0x10]
	lsls r3, r3, #0x17
	lsrs r3, r3, #7
	orrs r4, r3
	mov r3, r8
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	orrs r4, r3
	ldrh r7, [r2]
	lsrs r3, r7, #0xa
	lsls r3, r3, #0x1c
	orrs r4, r3
	lsrs r3, r7, #0xe
	lsls r3, r3, #0xe
	orrs r4, r3
	ldrb r3, [r0, #0x16]
	lsls r3, r3, #0x18
	eors r4, r3
	str r4, [r6]
	ldrh r4, [r0, #0x14]
	lsls r3, r7, #0x16
	lsrs r3, r3, #0x16
	adds r4, r4, r3
	strh r4, [r6, #4]
	adds r6, #8
_080003F0:
	subs r5, #1
	beq _080003F8
	adds r2, #4
	b _08000362
_080003F8:
	ldr r4, _08000680 @ =gOamManager+1024
	str r6, [r4]
_080003FC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	bx lr
