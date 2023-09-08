	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r0, r0, #0x1c
	lsls r0, r0, #1
	ldr r4, _08004240 @ =gVideoRegBuffer+4
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r4
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r6, r0, r4
	lsls r5, r5, #0x18
	asrs r5, r5, #0x13
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r5, r5, r3
	lsls r5, r5, #1
	adds r6, r6, r5
	lsrs r2, r2, #0x16
	adds r0, r2, r1
	ldr r0, [r0]
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1, #4]
	ldrh r4, [r1, #6]
	adds r5, r1, #0
	adds r5, #8
	cmp r4, #0
	beq _08004234
	lsls r7, r0, #1
	lsrs r0, r7, #1
	mov r8, r0
	ldr r3, _08004244 @ =0x001FFFFF
	mov sb, r3
_08004218:
	adds r0, r5, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	ands r2, r3
	bl CpuSet
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r5, r7
	adds r6, #0x40
	cmp r4, #0
	bne _08004218
_08004234:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004240: .4byte gVideoRegBuffer+4
_08004244: .4byte 0x001FFFFF
