	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r4
	movs r5, #0
	ldr r0, _08009CD4 @ =gOverworld+440
	mov r8, r0
	movs r7, #0xc5
	lsls r7, r7, #3
	add r7, r8
_08009C96:
	ldrh r1, [r7]
	asrs r0, r6, #0xc
	muls r0, r1, r0
	asrs r1, r4, #0xc
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
	movs r2, #0xf
	ands r2, r1
	cmp r2, #0
	beq _08009D0C
	movs r3, #0x84
	lsls r3, r3, #8
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08009D0C
	cmp r2, #1
	bne _08009CDC
	ldr r0, _08009CD8 @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009D06
	.align 2, 0
_08009CD4: .4byte gOverworld+440
_08009CD8: .4byte 0xFFFFF000
_08009CDC:
	ldr r1, _08009D20 @ =gShapeCheckerLeft
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009D24 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009D0C
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	beq _08009D0C
_08009D06:
	adds r5, #1
	cmp r5, #0xf
	ble _08009C96
_08009D0C:
	cmp r5, #0xf
	bgt _08009D28
	adds r0, r4, #0
	adds r1, r6, #0
	bl CalcPushout_Left
	mov r1, sb
	subs r0, r0, r1
	b _08009D2A
	.align 2, 0
_08009D20: .4byte gShapeCheckerLeft
_08009D24: .4byte 0x00000FFF
_08009D28:
	movs r0, #1
_08009D2A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
