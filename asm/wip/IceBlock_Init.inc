	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #2
	movs r6, #0
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x5c
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _080D8BEC @ =0xFFFFF500
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r2, _080D8BF0 @ =gSolidFnTable
	mov r8, r2
	ldrb r2, [r5, #9]
	lsls r2, r2, #2
	add r2, r8
	movs r3, #1
	str r3, [r5, #0xc]
	ldr r2, [r2]
	ldr r2, [r2, #4]
	str r2, [r5, #0x14]
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D8C64
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	movs r4, #0x80
	lsls r4, r4, #6
	adds r1, r1, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D8BF4
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080D8C92
	.align 2, 0
_080D8BEC: .4byte 0xFFFFF500
_080D8BF0: .4byte gSolidFnTable
_080D8BF4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	bl FUN_0800bd38
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D8C0E
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
_080D8C0E:
	ldrb r0, [r5, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080D8C54 @ =0x083710D8
	str r0, [r5, #0x30]
	ldr r0, _080D8C58 @ =0x00003801
	strh r0, [r5, #0x26]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800bd78
	ldr r1, _080D8C5C @ =0x0000CB01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D8C60 @ =0x083710C0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x50
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r0, #2
	strb r0, [r5, #0x10]
	strb r0, [r5, #0xd]
	b _080D8C8C
	.align 2, 0
_080D8C54: .4byte 0x083710D8
_080D8C58: .4byte 0x00003801
_080D8C5C: .4byte 0x0000CB01
_080D8C60: .4byte 0x083710C0
_080D8C64:
	movs r1, #0xcb
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080D8C9C @ =0x083710A8
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x50
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D8C8C:
	adds r0, r5, #0
	bl IceBlock_Update
_080D8C92:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8C9C: .4byte 0x083710A8
