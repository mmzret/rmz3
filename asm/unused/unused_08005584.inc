	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	mov ip, r2
	movs r1, #0
_08005592:
	movs r3, #0
	lsls r4, r1, #0x10
	asrs r0, r4, #0x10
	lsls r6, r0, #6
	lsls r1, r0, #4
	subs r5, r1, r0
_0800559E:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r3, r2, #1
	adds r3, r6, r3
	lsls r3, r3, #1
	add r3, r8
	adds r1, r5, r2
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0]
	str r0, [r3]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r0, [r0, #4]
	str r0, [r3, #0x40]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0xe
	ble _0800559E
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _08005592
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
