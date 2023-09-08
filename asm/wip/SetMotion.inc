	push {r4, r5, lr}
	mov ip, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsrs r2, r1, #0x18
	ldrb r0, [r0, #0x1e]
	cmp r2, r0
	beq _080175B0
	mov r3, ip
	ldrb r1, [r3, #0xb]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08017598
	lsls r0, r2, #2
	ldr r1, _08017594 @ =gDynamicMotionCmdTable
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r3, #0x6c]
	movs r0, #0xff
	strb r0, [r3, #0x1f]
	b _080175AC
	.align 2, 0
_08017594: .4byte gDynamicMotionCmdTable
_08017598:
	lsls r0, r2, #2
	ldr r3, _08017620 @ =gStaticMotionCmdTable
	adds r1, r0, r3
	ldr r1, [r1]
	mov r3, ip
	str r1, [r3, #0x6c]
	ldr r1, _08017624 @ =gStaticMotionMetaspriteTable
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r3, #0x3c]
_080175AC:
	mov r3, ip
	strb r2, [r3, #0x1e]
_080175B0:
	mov r0, ip
	ldrb r1, [r0, #0xb]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0801760C
	mov r4, ip
	adds r4, #0x34
	ldr r0, _08017628 @ =wStaticGraphicTilenums
	lsls r2, r2, #1
	adds r0, r2, r0
	ldrh r1, [r0]
	mov r3, ip
	ldrh r3, [r3, #0x20]
	adds r1, r1, r3
	mov r3, ip
	adds r3, #0x22
	ldr r0, _0801762C @ =wStaticMotionPalIDs
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrb r3, [r3]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r4, #0x14]
	ldr r0, _08017630 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #0x14]
	mov r0, ip
	ldrb r1, [r0, #0xb]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0801760C
	lsls r2, r3, #4
	ldrb r1, [r4, #0x15]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, #0x15]
	mov r0, ip
	adds r0, #0x23
	strb r3, [r0]
_0801760C:
	mov r0, ip
	adds r0, #0x6c
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl setMotionStep
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017620: .4byte gStaticMotionCmdTable
_08017624: .4byte gStaticMotionMetaspriteTable
_08017628: .4byte wStaticGraphicTilenums
_0801762C: .4byte wStaticMotionPalIDs
_08017630: .4byte 0xFFFFFC00
