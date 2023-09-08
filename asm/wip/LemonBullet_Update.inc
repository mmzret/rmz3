	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xd]
	cmp r0, #0
	bne _080377E6
	adds r0, r5, #0
	bl isBlocked
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080377E6
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r4, #1
	ands r2, r4
	movs r1, #6
	bl CreateParticle
	ldr r6, [r5, #0x5c]
	rsbs r3, r6, #0
	str r3, [r5, #0x5c]
	ldr r2, _080377B4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080377B8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080377BC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	cmp r0, #0
	beq _080377C0
	str r3, [r5, #0x60]
	b _080377C2
	.align 2, 0
_080377B4: .4byte RNG_0202f388
_080377B8: .4byte 0x000343FD
_080377BC: .4byte 0x00269EC3
_080377C0:
	str r6, [r5, #0x60]
_080377C2:
	movs r0, #0x2b
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080377E6:
	adds r0, r5, #0
	bl shouldDelete
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08037804
	ldr r1, _0803780C @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_08037804:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803780C: .4byte gWeaponFnTable
