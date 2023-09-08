	push {r4, r5, r6, r7}
	mov r2, r8
	mov r3, sb
	mov r4, sl
	push {r2, r3, r4}
	sub sp, #0x18
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
	bpl _0800052C
	ldrb r3, [r0, #0x1b]
	lsls r3, r3, #1
	ldrb r4, [r0, #0x18]
	ldrb r7, [r0, #0x19]
	eors r4, r7
	beq _08000444
	rsbs r3, r3, #0
	lsls r3, r3, #0x17
	lsrs r3, r3, #0x17
_08000444:
	ldr r7, _08000678 @ =gSineTable
	ldrsh r4, [r7, r3]
	str r4, [sp]
	adds r3, #0x80
	lsls r3, r3, #0x17
	lsrs r3, r3, #0x17
	ldrsh r4, [r7, r3]
	str r4, [sp, #4]
_08000454:
	ldrh r4, [r2]
	lsrs r4, r4, #0xc
	movs r3, #2
	ldrsb r3, [r2, r3]
	ldr r7, _08000680+64 @ =0x080006A8
	ldrb r4, [r7, r4]
	str r4, [sp, #8]
	adds r3, r3, r4
	str r3, [sp, #0x10]
	ldr r4, [sp]
	muls r3, r4, r3
	ldrb r4, [r0, #0x18]
	orrs r4, r4
	beq _08000472
	rsbs r3, r3, #0
_08000472:
	mov sl, r3
	ldrh r4, [r2]
	lsrs r4, r4, #0xc
	movs r3, #3
	ldrsb r3, [r2, r3]
	ldr r7, _08000680+68 @ =0x080006B4
	ldrb r4, [r7, r4]
	str r4, [sp, #0xc]
	adds r3, r3, r4
	str r3, [sp, #0x14]
	ldr r4, [sp, #4]
	muls r3, r4, r3
	ldrb r4, [r0, #0x19]
	orrs r4, r4
	beq _08000492
	rsbs r3, r3, #0
_08000492:
	mov r4, sl
	adds r3, r3, r4
	asrs r3, r3, #8
	ldr r4, [sp, #0xc]
	lsls r4, r4, #1
	subs r3, r3, r4
	mov r7, sb
	ldr r7, [r7, #4]
	ldr r4, [r1, #0xc]
	subs r7, r7, r4
	asrs r7, r7, #8
	adds r3, r3, r7
	adds r3, #0x40
	cmp r3, #0xe0
	bhs _08000520
	subs r3, #0x40
	mov r8, r3
	ldr r3, [sp, #0x10]
	ldr r4, [sp, #4]
	muls r3, r4, r3
	ldrb r4, [r0, #0x18]
	orrs r4, r4
	beq _080004C2
	rsbs r3, r3, #0
_080004C2:
	mov sl, r3
	ldr r3, [sp, #0x14]
	ldr r4, [sp]
	muls r3, r4, r3
	ldrb r4, [r0, #0x19]
	orrs r4, r4
	bne _080004D2
	rsbs r3, r3, #0
_080004D2:
	mov r4, sl
	adds r3, r3, r4
	asrs r3, r3, #8
	ldr r4, [sp, #8]
	lsls r4, r4, #1
	subs r3, r3, r4
	mov r7, sb
	ldr r7, [r7]
	ldr r4, [r1, #8]
	subs r7, r7, r4
	asrs r7, r7, #8
	adds r3, r3, r7
	adds r3, #0x80
	ldr r4, _08000680+4 @ =0x00000176
	cmp r3, r4
	bhs _08000520
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
	str r4, [r6]
	ldrh r4, [r0, #0x14]
	lsls r3, r7, #0x16
	lsrs r3, r3, #0x16
	adds r4, r4, r3
	strh r4, [r6, #4]
	adds r6, #8
_08000520:
	subs r5, #1
	beq _08000528
	adds r2, #4
	b _08000454
_08000528:
	ldr r4, _08000680 @ =gOamManager+1024
	str r6, [r4]
_0800052C:
	add sp, #0x18
	pop {r0, r1, r2}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	pop {r4, r5, r6, r7}
	bx lr
