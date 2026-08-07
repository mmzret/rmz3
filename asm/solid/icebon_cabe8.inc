	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	beq _080CAC00
	cmp r4, #1
	beq _080CAC1A
	b _080CACD0
_080CAC00:
	adds r0, r7, #0
	bl InitScalerotMotion1
	ldr r1, _080CACE0 @ =0x00001105
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xff
	strb r0, [r7, #0x12]
	strb r4, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080CAC1A:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	movs r1, #0
	mov sb, r1
	strb r0, [r7, #0x13]
	movs r1, #3
	mov sl, r1
	ands r0, r1
	cmp r0, #0
	bne _080CAC72
	ldr r4, _080CACE4 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080CACE8 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080CACEC @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CACF0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r2, [r7, #0x54]
	adds r2, r2, r0
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	adds r0, r2, #0
	bl FUN_080b98ac
_080CAC72:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r1, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r7, #0x12]
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x12]
	subs r0, #8
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _080CACD0
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	mov r1, sb
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080CACF4 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, sl
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080CACD0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CACE0: .4byte 0x00001105
_080CACE4: .4byte RNG_0202f388
_080CACE8: .4byte 0x000343FD
_080CACEC: .4byte 0x00269EC3
_080CACF0: .4byte 0xFFFFF200
_080CACF4: .4byte gSolidFnTable
