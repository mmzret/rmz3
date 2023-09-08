	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r3, r0, #0
	adds r5, r1, #0
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #3
	ldr r1, _0800934C @ =0x02002220
	mov r8, r1
	add r0, r8
	mov ip, r0
	ldr r2, [r5, #8]
	movs r0, #0
	movs r1, #0
	mov r4, ip
	strh r3, [r4, #0xc]
	strb r0, [r4, #0xf]
	strb r0, [r4, #0xe]
	strh r1, [r4, #0x12]
	strh r1, [r4, #0x10]
	adds r4, #0x34
	ldr r0, _08009350 @ =0x80000001
	mov r6, ip
	str r0, [r6, #0x40]
	str r0, [r6, #0x3c]
	str r0, [r4, #4]
	str r0, [r6, #0x34]
	str r0, [r6, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6]
	movs r0, #1
	str r0, [r6, #4]
	str r1, [r6, #8]
	ldr r0, [r2]
	adds r7, r0, r2
	ldr r0, [r2, #8]
	adds r6, r0, r2
	cmp r3, #0
	bne _08009358
	mov r0, ip
	adds r0, #0x14
	ldr r2, _08009354 @ =0x0002C004
	add r2, r8
	str r6, [sp]
	ldr r1, [r5, #0xc]
	str r1, [sp, #4]
	adds r1, r4, #0
	adds r3, r7, #0
	bl ResetLayerGraphic
	b _0800938E
	.align 2, 0
_0800934C: .4byte 0x02002220
_08009350: .4byte 0x80000001
_08009354: .4byte 0x0002C004
_08009358:
	mov r0, ip
	adds r0, #0x14
	mov r2, ip
	ldr r1, [r2, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r2, _0800939C @ =gVideoRegBuffer+4
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r2, r1
	lsls r2, r2, #3
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r2, r2, r1
	str r6, [sp]
	lsls r3, r3, #2
	adds r1, r5, #0
	adds r1, #0xc
	adds r1, r1, r3
	ldr r1, [r1]
	str r1, [sp, #4]
	adds r1, r4, #0
	adds r3, r7, #0
	bl ResetLayerGraphic
_0800938E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800939C: .4byte gVideoRegBuffer+4
