	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r5, #0xdc
	ldrb r3, [r7, #0xe]
	cmp r3, #1
	beq _0800C700
	cmp r3, #1
	bgt _0800C6CE
	cmp r3, #0
	beq _0800C6D4
	b _0800C730
_0800C6CE:
	cmp r3, #2
	beq _0800C74C
	b _0800C730
_0800C6D4:
	lsrs r2, r0, #0x14
	lsls r2, r2, #1
	ldr r0, _0800C738 @ =gVideoRegBuffer+4
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r0, _0800C73C @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xc0
	str r0, [r7, #0x44]
	str r0, [r7, #0x48]
	adds r0, #0xa8
	str r0, [r7, #0x4c]
	movs r0, #0x78
	str r0, [r7, #0x50]
	strh r3, [r7, #0x10]
	strh r3, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800C700:
	ldr r1, _0800C740 @ =0xFFFFFA1C
	adds r0, r5, r1
	ldr r1, [r7, #0x34]
	adds r0, r1, r0
	cmp r0, r5
	blo _0800C71C
	ldr r2, _0800C744 @ =0xFFFFF884
	adds r0, r5, r2
	adds r0, r1, r0
	lsls r1, r4, #8
	mov r8, r1
	cmp r0, r5
	blo _0800C71C
	b _0800C840
_0800C71C:
	movs r0, #0x78
	bl PlaySound
	ldr r1, _0800C748 @ =gStageRun+288
	movs r0, #8
	bl AppendQuake
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0800C730:
	lsls r4, r4, #8
	mov r8, r4
	b _0800C840
	.align 2, 0
_0800C738: .4byte gVideoRegBuffer+4
_0800C73C: .4byte 0x0000FFFC
_0800C740: .4byte 0xFFFFFA1C
_0800C744: .4byte 0xFFFFF884
_0800C748: .4byte gStageRun+288
_0800C74C:
	ldrh r0, [r7, #0x10]
	adds r0, #1
	strh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bne _0800C808
	movs r6, #0
	lsls r4, r4, #8
	mov r8, r4
_0800C760:
	mov r2, sp
	adds r0, r2, r6
	strb r6, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #6
	bls _0800C760
	movs r6, #0
	ldr r4, _0800C7FC @ =RNG_0202f388
	mov sb, r4
	ldr r0, _0800C800 @ =0x00269EC3
	mov sl, r0
_0800C77A:
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _0800C804 @ =0x000343FD
	muls r0, r2, r0
	add r0, sl
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r1]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0800C804 @ =0x000343FD
	adds r0, r5, #0
	muls r0, r1, r0
	add r0, sl
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, sb
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sp
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0xf
	bls _0800C77A
	movs r6, #0
_0800C7CE:
	lsls r2, r6, #2
	adds r2, r2, r7
	mov r4, sp
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r1, r1, #5
	adds r1, #0x18
	ldr r0, [r7, #0x34]
	adds r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2, #0x68]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #2
	bls _0800C7CE
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl CreateVolcanoBomb
	b _0800C82E
	.align 2, 0
_0800C7FC: .4byte RNG_0202f388
_0800C800: .4byte 0x00269EC3
_0800C804: .4byte 0x000343FD
_0800C808:
	cmp r0, #0x40
	bne _0800C81C
	ldr r0, [r7, #0x6c]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl CreateVolcanoBomb
	lsls r4, r4, #8
	mov r8, r4
	b _0800C82E
_0800C81C:
	lsls r4, r4, #8
	mov r8, r4
	cmp r0, #0x50
	bne _0800C82E
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x38]
	lsls r1, r1, #8
	bl CreateVolcanoBomb
_0800C82E:
	ldrh r0, [r7, #0x10]
	cmp r0, #0xa0
	bne _0800C840
	movs r0, #0
	strh r0, [r7, #0x10]
	strh r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	subs r0, #1
	strb r0, [r7, #0xe]
_0800C840:
	ldr r1, [r7, #0x34]
	ldr r0, _0800C854 @ =0x0000043F
	cmp r1, r0
	bgt _0800C85C
	ldr r1, _0800C858 @ =gVideoRegBuffer
	ldrh r0, [r1]
	mov r2, r8
	bics r0, r2
	strh r0, [r1]
	b _0800C866
	.align 2, 0
_0800C854: .4byte 0x0000043F
_0800C858: .4byte gVideoRegBuffer
_0800C85C:
	ldr r1, _0800C878 @ =gVideoRegBuffer
	ldrh r0, [r1]
	mov r4, r8
	orrs r4, r0
	strh r4, [r1]
_0800C866:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800C878: .4byte gVideoRegBuffer
