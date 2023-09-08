	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	movs r1, #0x13
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080B54BA
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080B54BA
	movs r0, #0xf
	bl PlaySound
_080B54BA:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, _080B54E8 @ =gOverworld
	ldr r1, _080B54EC @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x58]
	ldr r1, _080B54F0 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Ripple_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B54E8: .4byte gOverworld
_080B54EC: .4byte 0x0002C00C
_080B54F0: .4byte gVFXFnTable
