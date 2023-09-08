	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, _08004E08 @ =gOamManager
	movs r1, #0x80
	lsls r1, r1, #3
	adds r7, r0, r1
	ldr r5, [r7]
	cmp r5, r7
	bhs _08004E00
	ldr r2, [r4, #8]
	ldr r0, [r2, #4]
	ldr r1, [r3, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r6, r0, #0x10
	adds r0, r6, #0
	adds r0, #0x40
	cmp r0, #0xdf
	bhi _08004E00
	ldr r0, [r2]
	ldr r1, [r3, #8]
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r3, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x80
	ldr r0, _08004E0C @ =0x0000016F
	cmp r1, r0
	bhi _08004E00
	ldr r2, [r4, #0xc]
	str r2, [r5]
	movs r1, #0xff
	ands r1, r6
	ldrb r0, [r4, #0xd]
	lsrs r0, r0, #6
	lsls r0, r0, #0xe
	orrs r1, r0
	ldr r0, _08004E10 @ =0x000001FF
	ands r3, r0
	lsls r0, r3, #0x10
	orrs r1, r0
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #0x1c
	orrs r1, r0
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #0x1d
	orrs r1, r0
	ldrb r0, [r4, #0xf]
	lsrs r0, r0, #6
	lsls r0, r0, #0x1e
	orrs r1, r0
	orrs r2, r1
	str r2, [r5]
	ldrh r1, [r4, #0x10]
	strh r1, [r5, #4]
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	orrs r1, r0
	strh r1, [r5, #4]
	adds r0, r5, #0
	adds r0, #8
	str r0, [r7]
_08004E00:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004E08: .4byte gOamManager
_08004E0C: .4byte 0x0000016F
_08004E10: .4byte 0x000001FF
