	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080E996C @ =gTextPrinter
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	bne _080E9906
	b _080E9A60
_080E9906:
	movs r2, #0xf
	mov r8, r2
	ldr r0, _080E9970 @ =gFontTall
	mov sl, r0
	movs r1, #0xf8
	lsls r1, r1, #1
	mov sb, r1
_080E9914:
	ldrh r1, [r6, #6]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080E9924
	b _080E9A58
_080E9924:
	subs r2, #1
	adds r0, r2, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldrh r2, [r6, #4]
	ldr r0, _080E9974 @ =gVideoRegBuffer+4
	ldrh r1, [r0]
	movs r0, #0xc
	ands r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r7, r0, r1
	ldr r0, _080E9978 @ =0x000001FF
	cmp r2, r0
	bhi _080E9984
	ldr r1, _080E997C @ =0x0000FFF0
	adds r0, r1, #0
	adds r4, r2, #0
	ands r4, r0
	lsls r4, r4, #6
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #5
	adds r4, r4, r0
	mov r1, sl
	adds r0, r4, r1
	ldrh r1, [r6, #6]
	lsls r1, r1, #5
	adds r1, r7, r1
	movs r2, #8
	bl CpuFastSet
	ldr r2, _080E9980 @ =0x080FF37C
	b _080E9A04
	.align 2, 0
_080E996C: .4byte gTextPrinter
_080E9970: .4byte gFontTall
_080E9974: .4byte gVideoRegBuffer+4
_080E9978: .4byte 0x000001FF
_080E997C: .4byte 0x0000FFF0
_080E9980: .4byte gFontTall+(32*16)
_080E9984:
	ldr r0, _080E99D0 @ =0x000003FF
	cmp r2, r0
	bhi _080E99D4
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #6
	mov r1, r8
	ands r2, r1
	lsls r1, r2, #5
	adds r0, r0, r1
	mov r2, sl
	adds r1, r0, r2
	ldrh r0, [r6, #6]
	lsls r0, r0, #5
	adds r3, r7, r0
	movs r2, #0
_080E99A6:
	ldm r1!, {r0}
	lsls r0, r0, #2
	stm r3!, {r0}
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls _080E99A6
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r2, #0
_080E99BE:
	ldm r1!, {r0}
	lsls r0, r0, #2
	stm r3!, {r0}
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #7
	bls _080E99BE
	b _080E9A58
	.align 2, 0
_080E99D0: .4byte 0x000003FF
_080E99D4:
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080E9A20
	adds r4, r2, #0
	mov r1, sb
	ands r4, r1
	lsls r4, r4, #7
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #6
	adds r4, r4, r0
	ldr r1, _080E9A18 @ =gFontBig
	adds r0, r4, r1
	ldrh r1, [r6, #6]
	lsls r1, r1, #5
	adds r1, r7, r1
	movs r2, #8
	bl CpuFastSet
	ldr r2, _080E9A1C @ =0x08106E3C
_080E9A04:
	adds r4, r4, r2
	ldrh r1, [r6, #6]
	lsls r1, r1, #5
	adds r1, #0x20
	adds r1, r7, r1
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	b _080E9A58
	.align 2, 0
_080E9A18: .4byte gFontBig
_080E9A1C: .4byte gFontBig+1024
_080E9A20:
	adds r4, r2, #0
	mov r0, sb
	ands r4, r0
	lsls r4, r4, #7
	mov r1, r8
	ands r2, r1
	lsls r0, r2, #6
	adds r4, r4, r0
	ldr r5, _080E9A70 @ =0x08106A5C
	adds r0, r4, r5
	ldrh r1, [r6, #6]
	lsls r1, r1, #5
	adds r1, r7, r1
	movs r2, #8
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #3
	adds r5, r5, r2
	adds r4, r4, r5
	ldrh r1, [r6, #6]
	lsls r1, r1, #5
	adds r1, #0x20
	adds r1, r7, r1
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
_080E9A58:
	ldr r6, [r6]
	cmp r6, #0
	beq _080E9A60
	b _080E9914
_080E9A60:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E9A70: .4byte gFontBig+32
