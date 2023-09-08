	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0
	str r0, [r6, #4]
	str r0, [r6]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	bl FUN_080094f0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r8, r7
	ldr r0, [r5]
	ldr r1, _08008F94 @ =0xFFFF8800
	adds r0, r0, r1
	ldr r1, [r5, #4]
	bl FUN_080094f0
	subs r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08008F18
	ldr r4, [r6]
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r4, r4, r1
	ldr r0, [r5]
	bl __modsi3
	subs r4, r4, r0
	str r4, [r6]
_08008F18:
	ldr r0, [r5]
	movs r4, #0xf0
	lsls r4, r4, #7
	adds r0, r0, r4
	ldr r1, [r5, #4]
	bl FUN_080094f0
	subs r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08008F40
	ldr r0, [r5]
	adds r1, r4, #0
	bl __modsi3
	ldr r1, [r6]
	subs r1, r1, r0
	str r1, [r6]
_08008F40:
	cmp r7, #0xd
	bhi _08008F9C
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, _08008F98 @ =0xFFFFB000
	adds r1, r1, r2
	bl FUN_080094f0
	subs r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08008F6E
	ldr r4, [r6, #4]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r4, r4, r1
	ldr r0, [r5, #4]
	bl __modsi3
	subs r4, r4, r0
	str r4, [r6, #4]
_08008F6E:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	movs r4, #0xa0
	lsls r4, r4, #7
	adds r1, r1, r4
	bl FUN_080094f0
	subs r0, #1
	subs r0, r7, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08008FC2
	ldr r0, [r5, #4]
	adds r1, r4, #0
	bl __modsi3
	ldr r1, [r6, #4]
	b _08008FBE
	.align 2, 0
_08008F94: .4byte 0xFFFF8800
_08008F98: .4byte 0xFFFFB000
_08008F9C:
	mov r0, r8
	cmp r0, #0xe
	bne _08008FB2
	ldr r0, [r5, #4]
	movs r1, #0xa0
	lsls r1, r1, #8
	bl __modsi3
	movs r1, #0xf0
	lsls r1, r1, #8
	b _08008FBE
_08008FB2:
	ldr r0, [r5, #4]
	movs r1, #0xa0
	lsls r1, r1, #8
	bl __modsi3
	ldr r1, _08008FCC @ =0xFFFFB000
_08008FBE:
	subs r1, r1, r0
	str r1, [r6, #4]
_08008FC2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08008FCC: .4byte 0xFFFFB000
