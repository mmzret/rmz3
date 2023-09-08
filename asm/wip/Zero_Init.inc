	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	ldr r1, _080291EC @ =gZeroFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0xa]
	movs r1, #1
	movs r4, #0
	movs r6, #0
	orrs r1, r0
	movs r7, #0xff
	movs r0, #2
	orrs r1, r0
	strb r1, [r5, #0xa]
	adds r0, r5, #0
	movs r1, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08029034
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_0800a05c
	str r0, [r5, #0x58]
_08029034:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080291F0 @ =gZeroCollisions
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080291F4 @ =onCollision
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl InitPlayerKeyMap
	str r6, [r5, #0x5c]
	str r6, [r5, #0x60]
	str r6, [r5, #0x64]
	str r6, [r5, #0x68]
	adds r2, r5, #0
	adds r2, #0xb4
	strb r6, [r5, #0xd]
	adds r0, r5, #0
	adds r0, #0xe8
	strb r6, [r0]
	strb r6, [r5, #0xe]
	adds r0, #1
	strb r6, [r0]
	strb r6, [r5, #0xf]
	adds r0, #3
	strb r6, [r0]
	adds r0, #4
	strb r6, [r0]
	subs r0, #3
	strb r6, [r0]
	adds r0, #4
	strb r6, [r0]
	subs r0, #3
	strb r6, [r0]
	adds r0, #4
	strb r6, [r0]
	subs r0, #3
	strb r6, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0xfa
	ldr r0, _080291F8 @ =0x0000FFFF
	strh r0, [r1]
	ldrb r1, [r2, #0xc]
	adds r0, r5, #0
	adds r0, #0xe4
	strb r1, [r0]
	ldrb r0, [r2, #0xd]
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	ldrb r0, [r2, #0xc]
	adds r4, r2, #0
	ldr r1, _080291FC @ =0x00000113
	adds r1, r1, r5
	mov sb, r1
	ldr r2, _08029200 @ =0x00000119
	adds r2, r5, r2
	str r2, [sp, #0xc]
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x10]
	ldr r2, _08029204 @ =0x0000011B
	adds r2, r5, r2
	str r2, [sp, #0x14]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x18]
	ldr r2, _08029208 @ =0x0000011D
	adds r2, r5, r2
	str r2, [sp, #0x1c]
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x20]
	ldr r2, _0802920C @ =0x00000121
	adds r2, r5, r2
	str r2, [sp, #0x24]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x28]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp]
	ldr r1, _08029210 @ =0x0000018D
	adds r1, r5, r1
	str r1, [sp, #4]
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #8]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r1, r5, r1
	str r1, [sp, #0x30]
	ldr r2, _08029214 @ =0x00000231
	adds r2, r2, r5
	mov sl, r2
	ldr r1, _08029218 @ =0x00000232
	adds r1, r5, r1
	str r1, [sp, #0x34]
	ldr r2, _0802921C @ =0x00000233
	adds r2, r5, r2
	str r2, [sp, #0x38]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r5, r1
	str r1, [sp, #0x3c]
	ldr r2, _08029220 @ =0x00000149
	adds r2, r5, r2
	str r2, [sp, #0x40]
	movs r1, #0xe0
	adds r1, r1, r5
	mov r8, r1
	adds r2, r5, #0
	adds r2, #0xa4
	str r2, [sp, #0x2c]
	ldrb r1, [r4, #0xd]
	cmp r0, r1
	bne _0802917A
	ldrb r0, [r4]
	orrs r0, r7
	strb r0, [r4]
	ldrb r0, [r4, #1]
	orrs r0, r7
	strb r0, [r4, #1]
	movs r3, #0
	adds r6, r4, #0
	ldrh r7, [r4, #0x14]
	movs r2, #1
	mov ip, r2
_08029156:
	mov r2, ip
	lsls r2, r3
	adds r0, r7, #0
	ands r0, r2
	asrs r0, r3
	cmp r0, #0
	beq _08029174
	ldrh r1, [r4, #0x12]
	adds r0, r1, #0
	ands r0, r2
	asrs r0, r3
	cmp r0, #0
	beq _08029174
	eors r1, r2
	strh r1, [r6, #0x12]
_08029174:
	adds r3, #1
	cmp r3, #0xb
	bls _08029156
_0802917A:
	movs r0, #0
	str r0, [r4, #0x40]
	str r0, [r4, #0x58]
	mov r1, sb
	strb r0, [r1]
	str r0, [r4, #0x60]
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	ldr r2, [sp, #0x14]
	strb r0, [r2]
	ldr r1, [sp, #0x18]
	strb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	movs r1, #0xff
	ldr r2, [sp, #0x24]
	strb r1, [r2]
	ldr r1, [sp, #0x28]
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08033ed4
	movs r3, #0
	ldr r0, _080291F8 @ =0x0000FFFF
	adds r2, r0, #0
	ldr r1, [sp]
_080291B6:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #0xf
	bls _080291B6
	movs r0, #0
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, [sp, #8]
	str r0, [r2]
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	ldr r0, _08029224 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08029228
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	b _0802922C
	.align 2, 0
_080291EC: .4byte gZeroFnTable
_080291F0: .4byte gZeroCollisions
_080291F4: .4byte onCollision
_080291F8: .4byte 0x0000FFFF
_080291FC: .4byte 0x00000113
_08029200: .4byte 0x00000119
_08029204: .4byte 0x0000011B
_08029208: .4byte 0x0000011D
_0802920C: .4byte 0x00000121
_08029210: .4byte 0x0000018D
_08029214: .4byte 0x00000231
_08029218: .4byte 0x00000232
_0802921C: .4byte 0x00000233
_08029220: .4byte 0x00000149
_08029224: .4byte gCurStory
_08029228:
	mov r1, sl
	strb r0, [r1]
_0802922C:
	movs r0, #0
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r1, [sp, #0x40]
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	beq _08029258
	adds r0, r5, #0
	bl GetMaxHP
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	bls _08029262
_08029258:
	adds r0, r5, #0
	bl GetMaxHP
	mov r1, r8
	strb r0, [r1]
_08029262:
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, [sp, #0x2c]
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl CreateChargeEffect
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #1
	bl CreateChargeEffect
	ldrb r1, [r4]
	adds r0, r5, #0
	movs r2, #0
	bl CreateSateliteElf
	ldrb r1, [r4, #1]
	adds r0, r5, #0
	movs r2, #1
	bl CreateSateliteElf
	adds r0, r5, #0
	bl GetZeroColor
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl LoadZeroPalette
	ldrb r0, [r4, #0xe]
	bl setWramElement
	adds r0, r5, #0
	bl Zero_Update
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
