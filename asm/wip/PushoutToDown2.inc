	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009C24 @ =gOverworld+440
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009BE0:
	mov r3, r8
	ldrh r1, [r3]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009C56
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009C56
	cmp r2, #1
	bne _08009C2C
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009C28 @ =0xFFFFF000
	ands r4, r0
	b _08009C64
	.align 2, 0
_08009C24: .4byte gOverworld+440
_08009C28: .4byte 0xFFFFF000
_08009C2C:
	ldr r1, _08009C5C @ =gShapeCheckerDown
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009C60 @ =0x00000FFF
	adds r1, r2, #0
	bics r1, r4
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009C56
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009C64
_08009C56:
	subs r0, r4, r5
	b _08009C6E
	.align 2, 0
_08009C5C: .4byte gShapeCheckerDown
_08009C60: .4byte 0x00000FFF
_08009C64:
	adds r7, #1
	cmp r7, #0xf
	ble _08009BE0
	movs r0, #1
	rsbs r0, r0, #0
_08009C6E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
