	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080B5410 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _080B5450
	mov r1, ip
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080B5414 @ =gVFXFnTable
	movs r0, #0xc
	mov r3, ip
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	mov r1, ip
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	adds r2, r4, #0
	cmp r2, #0
	beq _080B5418
	ldrb r0, [r3, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r3, #0xa]
	b _080B5424
	.align 2, 0
_080B5410: .4byte gVFXHeaderPtr
_080B5414: .4byte gVFXFnTable
_080B5418:
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r0, #0xdf
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
_080B5424:
	movs r4, #1
	adds r1, r4, #0
	ands r1, r2
	mov r0, ip
	adds r0, #0x4d
	movs r3, #0
	strb r1, [r0]
	mov r5, ip
	adds r5, #0x4a
	lsls r1, r1, #5
	ldrb r2, [r5]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5]
	mov r0, ip
	strb r3, [r0, #0x10]
	strb r3, [r0, #0x11]
	ldr r1, _080B5458 @ =0x0000011B
	adds r0, r6, r1
	strb r4, [r0]
_080B5450:
	mov r0, ip
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B5458: .4byte 0x0000011B
