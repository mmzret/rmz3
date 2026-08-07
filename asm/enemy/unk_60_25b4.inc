	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov ip, r0
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _08092624
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r2, #0xfe
	mov r8, r2
	mov r0, r8
	ands r0, r1
	movs r3, #0
	mov r1, ip
	strb r0, [r1, #0xa]
	mov r6, ip
	adds r6, #0x8c
	str r3, [r6]
	mov r5, ip
	adds r5, #0x90
	str r3, [r5]
	mov r4, ip
	adds r4, #0x94
	strb r3, [r4]
	ldrb r1, [r1, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r1
	mov r1, r8
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	str r3, [r6]
	str r3, [r5]
	strb r3, [r4]
	ldrb r0, [r1, #0xa]
	ands r2, r0
	strb r2, [r1, #0xa]
	ldr r1, _08092620 @ =gEnemyFnTable
	mov r2, ip
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _0809263E
	.align 2, 0
_08092620: .4byte gEnemyFnTable
_08092624:
	ldr r1, _08092648 @ =0x08369A78
	mov r2, ip
	ldrb r0, [r2, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r2, #0xd]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	mov r0, ip
	bl _call_via_r1
_0809263E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092648: .4byte 0x08369A78
