	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _080B63A8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B63D6
	adds r0, #0x25
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	ldr r1, _080B63AC @ =gVFXFnTable
	movs r0, #0xf
	strb r0, [r4, #9]
	ldr r0, [r1, #0x3c]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r4, #0x28]
	ldr r0, [r5]
	str r0, [r4, #0x64]
	ldr r0, [r5, #4]
	str r0, [r4, #0x68]
	strb r3, [r4, #0x10]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r1, _080B63B0 @ =0x0836E828
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r5]
	lsrs r2, r0, #0x1f
	cmp r2, #0
	beq _080B63B4
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B63BA
	.align 2, 0
_080B63A8: .4byte gVFXHeaderPtr
_080B63AC: .4byte gVFXFnTable
_080B63B0: .4byte 0x0836E828
_080B63B4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B63BA:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080B63D6:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
