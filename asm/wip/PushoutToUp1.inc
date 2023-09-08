	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	mov r4, sb
	movs r5, #0
	ldr r0, _080099E4 @ =gOverworld+440
	mov r8, r0
	movs r7, #0xc5
	lsls r7, r7, #3
	add r7, r8
	ldr r1, _080099E8 @ =0x0000800F
	mov sl, r1
_080099B0:
	ldrh r1, [r7]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08009A20
	cmp r1, sl
	beq _08009A20
	cmp r0, #1
	bne _080099F0
	ldr r0, _080099EC @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009A1A
	.align 2, 0
_080099E4: .4byte gOverworld+440
_080099E8: .4byte 0x0000800F
_080099EC: .4byte 0xFFFFF000
_080099F0:
	ldr r1, _08009A34 @ =gShapeCheckerUp
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, _08009A38 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009A20
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009A20
_08009A1A:
	adds r5, #1
	cmp r5, #0xf
	ble _080099B0
_08009A20:
	cmp r5, #0xf
	bgt _08009A3C
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcPushout_Up
	mov r1, sb
	subs r0, r0, r1
	b _08009A3E
	.align 2, 0
_08009A34: .4byte gShapeCheckerUp
_08009A38: .4byte 0x00000FFF
_08009A3C:
	movs r0, #1
_08009A3E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
