	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	ldr r0, _080B2AD4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080B2B34
	adds r2, r4, #0
	adds r2, #0x25
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	ldr r0, _080B2AD8 @ =gVFXFnTable
	strb r1, [r4, #9]
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r1, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldr r0, _080B2ADC @ =sSmokeMotionIdx
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r2, r7, #0
	cmp r2, #0
	beq _080B2AE0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B2AE6
	.align 2, 0
_080B2AD4: .4byte gVFXHeaderPtr
_080B2AD8: .4byte gVFXFnTable
_080B2ADC: .4byte sSmokeMotionIdx
_080B2AE0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B2AE6:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	mov r3, r8
	adds r5, r2, #0
	cmp r3, #0
	beq _080B2B14
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080B2B1A
_080B2B14:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080B2B1A:
	strb r0, [r4, #0xa]
	movs r0, #1
	ands r0, r3
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	lsls r0, r0, #5
	ldrb r2, [r5]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5]
_080B2B34:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
