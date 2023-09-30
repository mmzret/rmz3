	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldr r1, _0801AC50 @ =gQuakeManager+4
	movs r2, #0xce
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r5, [r0]
	ldr r0, [r1]
	subs r3, r1, #4
	mov ip, r3
	cmp r0, #0
	beq _0801ABE2
_0801ABD0:
	ldr r0, [r1]
	lsls r0, r0, #8
	cmp r5, r0
	bge _0801ABDA
	adds r5, r0, #0
_0801ABDA:
	adds r1, #0xc
	ldr r0, [r1]
	cmp r0, #0
	bne _0801ABD0
_0801ABE2:
	asrs r0, r5, #6
	cmp r0, #0
	beq _0801AC60
	ldr r2, _0801AC54 @ =gSineTable
	movs r3, #0xcf
	lsls r3, r3, #1
	add r3, ip
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r5, r0
	cmp r0, #0
	bge _0801AC08
	adds r0, #0xff
_0801AC08:
	asrs r2, r0, #8
	asrs r0, r0, #0xc
	str r0, [r6]
	mov r1, ip
	ldr r0, [r1]
	ldr r4, _0801AC58 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _0801AC5C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r7, ip
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r0, #0x7f
	ldr r1, [r6]
	muls r0, r1, r0
	asrs r0, r0, #7
	str r0, [r6]
	str r2, [r6, #4]
	subs r2, #3
	ldr r0, [r7]
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r7]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r2, r2, r0
	asrs r2, r2, #1
	str r2, [r6, #4]
	b _0801AC64
	.align 2, 0
_0801AC50: .4byte gQuakeManager+4
_0801AC54: .4byte gSineTable
_0801AC58: .4byte 0x000343FD
_0801AC5C: .4byte 0x00269EC3
_0801AC60:
	str r0, [r6, #4]
	str r0, [r6]
_0801AC64:
	movs r1, #0xd0
	lsls r1, r1, #1
	add r1, ip
	lsls r0, r5, #4
	subs r0, r0, r5
	asrs r0, r0, #4
	str r0, [r1]
	movs r1, #0xce
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	mov r1, ip
	str r0, [r1, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
