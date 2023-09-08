	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrh r0, [r4, #0xc]
	mov sb, r0
	adds r3, r4, #0
	adds r3, #0x34
	ldr r0, [r4, #0x34]
	str r0, [r4, #0x3c]
	ldr r0, [r3, #4]
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x4c]
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x50]
	str r0, [r4, #0x58]
	ldr r0, [r2]
	asrs r0, r0, #8
	str r0, [r4, #0x34]
	ldr r1, [r2, #4]
	asrs r0, r1, #8
	str r0, [r3, #4]
	ldr r2, _080097B0 @ =gScreenX
	ldr r0, [r4, #0x34]
	asrs r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r0, _080097B4 @ =gScreenY
	asrs r1, r1, #0xc
	adds r1, r1, r0
	ldrb r0, [r1]
	ldr r1, [r5, #0x6c]
	ldrb r3, [r1, #2]
	cmp r2, r3
	bhs _080097A4
	ldrb r1, [r1, #3]
	cmp r0, r1
	blo _080097B8
_080097A4:
	ldr r7, [r4]
	ldr r0, [r4, #4]
	mov r8, r0
	ldr r6, [r4, #8]
	adds r0, r7, #0
	b _080097E8
	.align 2, 0
_080097B0: .4byte gScreenX
_080097B4: .4byte gScreenY
_080097B8:
	ldr r1, [r5, #0x74]
	ldrh r3, [r1]
	lsls r0, r3
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0, #8]
	movs r0, #2
	mov r2, sb
	subs r0, r0, r2
	lsls r0, r0, #2
	asrs r1, r0
	movs r0, #0xf
	ands r1, r0
	ldr r2, [r5, #0x70]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r3, [r0, #4]
	mov r8, r3
	ldr r6, [r0, #8]
	ldr r0, [r4]
_080097E8:
	cmp r0, r7
	bne _080097F2
	ldr r0, [r4, #4]
	cmp r0, r8
	beq _0800988E
_080097F2:
	ldr r2, [r4, #8]
	cmp r2, #0
	beq _08009800
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_08009800:
	str r7, [r4]
	mov r0, r8
	str r0, [r4, #4]
	str r6, [r4, #8]
	mov r2, sb
	lsls r1, r2, #2
	adds r0, r5, #0
	adds r0, #0x18
	adds r0, r0, r1
	ldr r6, [r0]
	str r6, [r4, #0x5c]
	adds r0, r5, #0
	adds r0, #0x24
	adds r0, r0, r1
	ldr r3, [r0]
	str r3, [r4, #0x60]
	adds r0, r5, #0
	adds r0, #0x30
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	str r0, [r4, #0x64]
	lsls r1, r2, #3
	adds r1, r1, r5
	ldr r0, [r1, #0x3c]
	str r0, [r4, #0x44]
	ldr r0, [r1, #0x40]
	str r0, [r4, #0x48]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x4c]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x50]
	cmp r7, #0
	bne _0800984A
	mov r5, r8
	cmp r5, #0
	beq _08009870
_0800984A:
	lsrs r1, r6, #4
	lsls r1, r1, #1
	ldr r2, _08009868 @ =gVideoRegBuffer+4
	adds r1, r1, r2
	mov r0, ip
	orrs r3, r0
	ldr r5, _0800986C @ =0x00006044
	adds r0, r5, #0
	orrs r3, r0
	strh r3, [r1]
	subs r2, #4
	lsls r0, r6, #8
	ldrh r1, [r2]
	orrs r0, r1
	b _08009878
	.align 2, 0
_08009868: .4byte gVideoRegBuffer+4
_0800986C: .4byte 0x00006044
_08009870:
	ldr r2, _0800989C @ =gVideoRegBuffer
	lsls r1, r6, #8
	ldrh r0, [r2]
	bics r0, r1
_08009878:
	strh r0, [r2]
	ldr r0, _080098A0 @ =0x80000001
	str r0, [r4, #0x40]
	str r0, [r4, #0x3c]
	str r0, [r4, #0x58]
	str r0, [r4, #0x54]
	movs r0, #0
	strb r0, [r4, #0xf]
	strb r0, [r4, #0xe]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x10]
_0800988E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800989C: .4byte gVideoRegBuffer
_080098A0: .4byte 0x80000001
