	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080B3DF8 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r6, _080B3DFC @ =0x000343FD
	muls r0, r6, r0
	ldr r5, _080B3E00 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r0, r0, #1
	mov r1, r8
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #0x1b
	bl SetMotion
	mov r2, r8
	ldr r0, [r2]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r1, r1, #1
	movs r3, #0
	ldrb r2, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r2
	strb r0, [r4, #0xa]
	movs r0, #1
	mov sb, r0
	adds r0, r4, #0
	adds r0, #0x4d
	strb r3, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r2, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	subs r0, #4
	lsls r0, r0, #8
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r1, _080B3E04 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, sb
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ghost5_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3DF8: .4byte RNG_0202f388
_080B3DFC: .4byte 0x000343FD
_080B3E00: .4byte 0x00269EC3
_080B3E04: .4byte gVFXFnTable
