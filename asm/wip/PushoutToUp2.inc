	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	movs r7, #0
	ldr r0, _08009AA0 @ =gOverworld+440
	mov sb, r0
	movs r2, #0xc5
	lsls r2, r2, #3
	add r2, sb
	mov r8, r2
_08009A68:
	mov r0, r8
	ldrh r1, [r0]
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
	beq _08009AD6
	ldr r0, _08009AA4 @ =0x0000800F
	cmp r1, r0
	beq _08009AD6
	cmp r2, #1
	bne _08009AAC
	ldr r0, _08009AA8 @ =0xFFFFF000
	ands r0, r4
	subs r4, r0, #1
	b _08009AE4
	.align 2, 0
_08009AA0: .4byte gOverworld+440
_08009AA4: .4byte 0x0000800F
_08009AA8: .4byte 0xFFFFF000
_08009AAC:
	ldr r1, _08009ADC @ =gShapeCheckerUp
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r2, _08009AE0 @ =0x00000FFF
	adds r1, r4, #0
	ands r1, r2
	ldr r3, [r0]
	adds r0, r6, #0
	ands r0, r2
	bl _call_via_r3
	cmp r0, #0
	beq _08009AD6
	adds r1, r4, #0
	adds r4, r4, r0
	eors r1, r4
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	cmp r1, #0
	bne _08009AE4
_08009AD6:
	subs r0, r4, r5
	b _08009AEC
	.align 2, 0
_08009ADC: .4byte gShapeCheckerUp
_08009AE0: .4byte 0x00000FFF
_08009AE4:
	adds r7, #1
	cmp r7, #0xf
	ble _08009A68
	movs r0, #1
_08009AEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
