	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080CA194
	cmp r5, #1
	bgt _080CA16A
	cmp r5, #0
	beq _080CA174
	b _080CA290
_080CA16A:
	cmp r5, #2
	beq _080CA238
	cmp r5, #3
	beq _080CA242
	b _080CA290
_080CA174:
	movs r0, #0x83
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA194:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CA1D6
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r1, _080CA218 @ =0xFFFFFC00
	adds r1, r0, r1
	str r1, [sp]
	ldr r2, _080CA21C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080CA220 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CA224 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	ldr r2, [sp]
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	ldr r2, _080CA228 @ =0xFFFFEB00
	adds r1, r1, r2
	bl createIcebonIce
_080CA1D6:
	ldrb r0, [r4, #0x12]
	cmp r0, #0x2b
	bls _080CA290
	ldr r0, [r4, #0x58]
	ldr r1, _080CA22C @ =0xFFFFCC00
	adds r0, r0, r1
	ldr r1, _080CA230 @ =gOverworld
	ldr r2, _080CA234 @ =0x0002C00C
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r0, r1
	ble _080CA20E
	movs r1, #0
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080CA1F8
	movs r1, #1
_080CA1F8:
	adds r0, r4, #0
	bl icebon_080ca550
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
_080CA20E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CA290
	.align 2, 0
_080CA218: .4byte 0xFFFFFC00
_080CA21C: .4byte RNG_0202f388
_080CA220: .4byte 0x000343FD
_080CA224: .4byte 0x00269EC3
_080CA228: .4byte 0xFFFFEB00
_080CA22C: .4byte 0xFFFFCC00
_080CA230: .4byte gOverworld
_080CA234: .4byte 0x0002C00C
_080CA238:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CA242:
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CA278
	ldr r6, [r4, #0x54]
	ldr r0, _080CA298 @ =0xFFFFFC00
	adds r6, r6, r0
	ldr r2, _080CA29C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080CA2A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080CA2A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsls r0, r0, #4
	lsrs r0, r0, #0x15
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	ldr r2, _080CA2A8 @ =0xFFFFEB00
	adds r1, r1, r2
	bl createIcebonIce
_080CA278:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CA290
	movs r0, #0xe1
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CA290:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA298: .4byte 0xFFFFFC00
_080CA29C: .4byte RNG_0202f388
_080CA2A0: .4byte 0x000343FD
_080CA2A4: .4byte 0x00269EC3
_080CA2A8: .4byte 0xFFFFEB00
