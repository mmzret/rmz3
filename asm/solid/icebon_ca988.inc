	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080CA99C
	cmp r0, #1
	beq _080CA9D2
	b _080CAAEE
_080CA99C:
	adds r0, r7, #0
	bl InitScalerotMotion1
	adds r0, r7, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	ble _080CA9BC
	ldr r1, _080CA9B8 @ =0x00001101
	adds r0, r7, #0
	bl SetMotion
	b _080CA9C4
	.align 2, 0
_080CA9B8: .4byte 0x00001101
_080CA9BC:
	ldr r1, _080CAA70 @ =0x00001103
	adds r0, r7, #0
	bl SetMotion
_080CA9C4:
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r0, #0
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080CA9D2:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080CAA24
	ldr r4, _080CAA74 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080CAA78 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080CAA7C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #5
	bl __umodsi3
	ldr r1, _080CAA80 @ =0xFFFFF200
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
_080CAA24:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r1, r7, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrb r0, [r7, #0x12]
	subs r0, #8
	strb r0, [r7, #0x12]
	adds r2, r7, #0
	adds r2, #0xb4
	ldr r0, _080CAA84 @ =gOverworld
	ldr r1, _080CAA88 @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	adds r4, r2, #0
	cmp r1, r0
	bge _080CAA4E
	str r0, [r4]
_080CAA4E:
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r1, [r2]
	movs r0, #4
	ands r1, r0
	ldr r3, [r7, #0x58]
	adds r5, r2, #0
	cmp r1, #0
	beq _080CAA90
	ldr r0, _080CAA8C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r3, r0
	ble _080CAA90
	movs r0, #0x80
	lsls r0, r0, #4
	b _080CAA92
	.align 2, 0
_080CAA70: .4byte 0x00001103
_080CAA74: .4byte RNG_0202f388
_080CAA78: .4byte 0x000343FD
_080CAA7C: .4byte 0x00269EC3
_080CAA80: .4byte 0xFFFFF200
_080CAA84: .4byte gOverworld
_080CAA88: .4byte 0x0002C00C
_080CAA8C: .4byte pZero2
_080CAA90:
	movs r0, #0
_080CAA92:
	str r0, [r7, #0x68]
	ldr r0, [r4]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	subs r0, r0, r3
	cmp r0, #0
	bge _080CAAA2
	adds r0, #7
_080CAAA2:
	asrs r0, r0, #3
	adds r0, r3, r0
	str r0, [r7, #0x58]
	ldrb r2, [r7, #0x12]
	cmp r2, #0x9f
	bhi _080CAAB6
	ldrb r1, [r7, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r7, #0xb]
_080CAAB6:
	cmp r2, #8
	bhi _080CAAEE
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	str r2, [r5]
	adds r0, r7, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080CAAF8 @ =gSolidFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080CAAEE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CAAF8: .4byte gSolidFnTable
