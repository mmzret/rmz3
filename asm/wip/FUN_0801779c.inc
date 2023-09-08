	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	adds r0, #0x6c
	bl UpdateMotionState
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r1, [r0]
	ldr r0, [r4, #0x6c]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	strb r3, [r5, #0x1a]
	ldrb r1, [r4, #0xb]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08017846
	ldrb r2, [r4, #0x1e]
	lsls r0, r2, #2
	ldr r1, _0801784C @ =gDynamicMotionMetaspriteTable
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r5, #8]
	cmp r0, r1
	beq _080177E8
	str r1, [r4, #0x3c]
_080177E8:
	lsls r0, r3, #2
	adds r0, r0, r1
	ldrb r3, [r0, #3]
	ldrb r1, [r4, #0x1f]
	movs r0, #0x7f
	ands r0, r1
	cmp r3, r0
	beq _08017846
	movs r0, #0x80
	orrs r3, r0
	strb r3, [r4, #0x1f]
	ldr r0, _08017850 @ =wDynamicGraphicTilenums
	lsls r2, r2, #1
	adds r0, r2, r0
	ldrh r1, [r0]
	ldrh r0, [r4, #0x20]
	adds r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x22
	ldr r0, _08017854 @ =wDynamicMotionPalIDs
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrb r3, [r3]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #0x14]
	ldr r0, _08017858 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #0x14]
	ldrb r1, [r4, #0xb]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _08017846
	lsls r2, r3, #4
	ldrb r1, [r5, #0x15]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #0x15]
	adds r0, r4, #0
	adds r0, #0x23
	strb r3, [r0]
_08017846:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801784C: .4byte gDynamicMotionMetaspriteTable
_08017850: .4byte wDynamicGraphicTilenums
_08017854: .4byte wDynamicMotionPalIDs
_08017858: .4byte 0xFFFFFC00
