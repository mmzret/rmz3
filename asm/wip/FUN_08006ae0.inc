	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r1
	str r2, [sp]
	ldr r2, [r1]
	adds r0, r2, #0
	subs r0, #0x10
	ldr r1, [r1, #4]
	adds r5, r1, #0
	subs r5, #0x10
	asrs r0, r2, #4
	adds r4, r0, #0
	asrs r5, r1, #4
	lsls r0, r0, #1
	adds r0, #4
	adds r0, r3, r0
	ldrh r2, [r3]
	adds r1, r2, #0
	muls r1, r5, r1
	lsls r1, r1, #1
	adds r6, r0, r1
	movs r1, #0
	mov r0, sl
	ldr r0, [r0, #0xc]
	mov ip, r0
	lsls r2, r2, #1
	str r2, [sp, #4]
_08006B20:
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	adds r0, r0, r5
	movs r2, #0xf
	ands r0, r2
	lsls r0, r0, #7
	ldr r3, [sp]
	adds r7, r3, r0
	movs r0, #0
	mov r8, r1
_08006B34:
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	adds r1, r3, r4
	adds r2, r1, #0
	movs r0, #0xf
	ands r2, r0
	lsls r2, r2, #2
	adds r2, r7, r2
	movs r0, #0x10
	ands r1, r0
	lsls r1, r1, #7
	adds r2, r2, r1
	ldrh r0, [r6]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	str r0, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0, #4]
	str r0, [r2, #0x40]
	adds r6, #2
	adds r3, #1
	lsls r3, r3, #0x10
	lsrs r0, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x11
	ble _08006B34
	ldr r1, [sp, #4]
	adds r0, r6, r1
	adds r6, r0, #0
	subs r6, #0x24
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _08006B20
	mov r2, sb
	ldr r3, [r2]
	ldr r2, _08006BB0 @ =0x000001FF
	adds r0, r3, #0
	ands r0, r2
	mov r6, sl
	strh r0, [r6, #8]
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r6, #0xa]
	str r3, [r6]
	str r1, [r6, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006BB0: .4byte 0x000001FF
