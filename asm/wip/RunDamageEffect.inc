	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl setCurProcessedEntityHeader
	ldr r0, [r4, #0xc]
	ldr r0, [r0, #4]
	str r0, [r4, #0xc]
	adds r3, r0, #0
	adds r0, r4, #0
	adds r0, #0x14
	cmp r3, r0
	beq _08016F8C
	ldr r5, _08016F94 @ =0x00001004
	ldr r0, _08016F98 @ =0x0202F360
	mov ip, r0
	ldr r7, _08016F9C @ =0x0202F344
	ldr r6, _08016FA0 @ =0x0202F330
_08016F16:
	ldrh r1, [r3, #0xa]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, r5
	bne _08016F7C
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08016F48
	adds r0, r3, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08016F48
	adds r0, r3, #0
	adds r0, #0x94
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08016F5E
_08016F48:
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	add r2, ip
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08016F5E:
	ldrb r0, [r7]
	cmp r0, #0
	bne _08016F7C
	adds r0, r3, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08016F7C
	ldr r0, [r3, #0x74]
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _08016F7C
	strb r1, [r6]
_08016F7C:
	ldr r0, [r4, #0xc]
	ldr r0, [r0, #4]
	str r0, [r4, #0xc]
	adds r3, r0, #0
	adds r0, r4, #0
	adds r0, #0x14
	cmp r3, r0
	bne _08016F16
_08016F8C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016F94: .4byte 0x00001004
_08016F98: .4byte 0x0202F360
_08016F9C: .4byte 0x0202F344
_08016FA0: .4byte 0x0202F330
