	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0x50
	movs r0, #0
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08043444 @ =sCollisions
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	adds r1, r7, #0
	adds r1, #0xc9
	movs r0, #0x40
	strb r0, [r1]
	ldr r1, _08043448 @ =Volteel_OnCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	mov r1, r8
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	str r4, [r0]
	subs r0, #9
	mov r1, r8
	strb r1, [r0]
	ldr r1, [r7, #0x58]
	ldr r0, _0804344C @ =0xFFFFC000
	adds r1, r1, r0
	ldr r0, [r7, #0x54]
	bl FUN_0800a05c
	str r0, [r7, #0x58]
	adds r1, r7, #0
	adds r1, #0xb8
	ldr r0, [r7, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r7, #0x58]
	str r0, [r1]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a134
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	adds r1, r5, #0
	bl FUN_0800a22c
	adds r6, r0, #0
	ldr r0, [r7, #0x54]
	adds r1, r5, #0
	bl FUN_0800a31c
	adds r4, r0, #0
	subs r0, r6, r4
	asrs r5, r0, #1
	adds r5, r4, r5
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_0800a134
	adds r1, r7, #0
	adds r1, #0xd4
	str r0, [r1]
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl FUN_0800a05c
	adds r1, r7, #0
	adds r1, #0xd8
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xdc
	str r4, [r0]
	adds r0, #4
	str r6, [r0]
	subs r0, #0x16
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08043454
	ldr r1, _08043450 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	mov r0, r8
	strb r0, [r7, #0xd]
	strb r0, [r7, #0xe]
	strb r0, [r7, #0xf]
	b _08043470
	.align 2, 0
_08043444: .4byte sCollisions
_08043448: .4byte Volteel_OnCollision
_0804344C: .4byte 0xFFFFC000
_08043450: .4byte gBossFnTable
_08043454:
	ldr r1, _08043484 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	movs r0, #3
	strb r0, [r7, #0xd]
	mov r1, r8
	strb r1, [r7, #0xe]
	strb r1, [r7, #0xf]
_08043470:
	movs r0, #0
	strb r0, [r7, #0x11]
	adds r0, r7, #0
	bl Volteel_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08043484: .4byte gBossFnTable
