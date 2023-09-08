	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0x14
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x44]
	adds r3, r0, #0
	muls r3, r1, r3
	asrs r3, r3, #8
	ldr r0, [r7, #0x4c]
	adds r3, r3, r0
	ldr r0, [r7, #0x38]
	ldr r4, [r7, #0x48]
	adds r2, r0, #0
	muls r2, r4, r2
	asrs r2, r2, #8
	ldr r0, [r7, #0x50]
	adds r2, r2, r0
	ldr r0, [r7, #0x3c]
	muls r0, r1, r0
	asrs r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r5, r0, r1
	ldr r0, [r7, #0x40]
	muls r0, r4, r0
	asrs r0, r0, #8
	ldr r1, [r7, #0x58]
	adds r6, r0, r1
	subs r0, r3, r5
	adds r1, r0, #0
	adds r1, #0xf
	subs r0, r2, r6
	adds r4, r0, #0
	adds r4, #0xf
	ldr r0, [r7, #0x2c]
	asrs r0, r0, #8
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [r7, #0x30]
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #4]
	ldrh r0, [r7, #0xc]
	cmp r0, #0
	beq _08009474
	cmp r1, #0x1e
	bhi _08009422
	cmp r4, #0x1e
	bls _0800944C
_08009422:
	ldr r0, [r7, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _08009448 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	mov r0, r8
	mov r1, sp
	bl FUN_08005a70
	b _080094C6
	.align 2, 0
_08009448: .4byte gVideoRegBuffer+4
_0800944C:
	ldr r0, [r7, #0x5c]
	lsrs r0, r0, #4
	lsls r0, r0, #1
	ldr r1, _08009470 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r0
	lsls r2, r2, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r2, r2, r0
	mov r0, r8
	mov r1, sp
	bl FUN_080050b0
	b _080094C6
	.align 2, 0
_08009470: .4byte gVideoRegBuffer+4
_08009474:
	cmp r1, #0x1e
	bhi _0800948A
	cmp r4, #0x1e
	bhi _0800948A
	ldr r3, _0800949C @ =gOverworld
	movs r1, #0xb0
	lsls r1, r1, #0xa
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080094A8
_0800948A:
	ldr r2, _080094A0 @ =gOverworld+180260
	ldr r0, _080094A4 @ =0xFFFD47BC
	adds r3, r2, r0
	mov r0, r8
	mov r1, sp
	bl FUN_08006a10
	b _080094BA
	.align 2, 0
_0800949C: .4byte gOverworld
_080094A0: .4byte gOverworld+180260
_080094A4: .4byte 0xFFFD47BC
_080094A8:
	ldr r1, _080094E4 @ =0x0002C024
	adds r2, r3, r1
	movs r0, #0xfc
	lsls r0, r0, #3
	adds r3, r3, r0
	mov r0, r8
	mov r1, sp
	bl FUN_08006bb4
_080094BA:
	ldr r0, _080094E8 @ =gOverworld
	movs r1, #0xb0
	lsls r1, r1, #0xa
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
_080094C6:
	ldr r1, [r7, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #2
	ldr r0, _080094EC @ =gVideoRegBuffer+12
	adds r1, r1, r0
	mov r0, r8
	bl UpdateBGOFS
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080094E4: .4byte 0x0002C024
_080094E8: .4byte gOverworld
_080094EC: .4byte gVideoRegBuffer+12
