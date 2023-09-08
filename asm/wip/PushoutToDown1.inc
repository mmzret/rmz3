	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sb, r1
	mov r4, sb
	movs r5, #0
	ldr r0, _08009B5C @ =gOverworld+440
	mov r8, r0
	movs r1, #0xc5
	lsls r1, r1, #3
	add r1, r8
	mov sl, r1
	ldr r3, _08009B60 @ =0x00000FFF
_08009B1A:
	mov r2, sl
	ldrh r1, [r2]
	asrs r0, r4, #0xc
	muls r0, r1, r0
	asrs r1, r6, #0xc
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009B9A
	movs r7, #0x84
	lsls r7, r7, #8
	adds r0, r7, #0
	ands r1, r0
	cmp r1, #0
	bne _08009B9A
	cmp r2, #1
	bne _08009B68
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, _08009B64 @ =0xFFFFF000
	ands r4, r0
	b _08009B94
	.align 2, 0
_08009B5C: .4byte gOverworld+440
_08009B60: .4byte 0x00000FFF
_08009B64: .4byte 0xFFFFF000
_08009B68:
	ldr r1, _08009BAC @ =gShapeCheckerDown
	lsls r0, r2, #2
	adds r0, r0, r1
	adds r1, r3, #0
	bics r1, r4
	ldr r2, [r0]
	adds r0, r6, #0
	ands r0, r3
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _08009B9A
	adds r1, r4, #0
	subs r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009B9A
_08009B94:
	adds r5, #1
	cmp r5, #0xf
	ble _08009B1A
_08009B9A:
	cmp r5, #0xf
	bgt _08009BB0
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcPushout_Down
	mov r1, sb
	subs r0, r0, r1
	b _08009BB4
	.align 2, 0
_08009BAC: .4byte gShapeCheckerDown
_08009BB0:
	movs r0, #1
	rsbs r0, r0, #0
_08009BB4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
