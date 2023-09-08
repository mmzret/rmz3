	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x34
	adds r0, #0x70
	ldrb r1, [r0]
	ldr r0, [r5, #0x6c]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r0, #0
	strb r3, [r6, #0x1a]
	ldrb r1, [r5, #0xb]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801797C
	ldrb r0, [r5, #0x1e]
	lsls r4, r0, #2
	ldr r2, _08017904 @ =gDynamicMotionMetaspriteTable
	adds r1, r4, r2
	ldr r2, [r1]
	ldr r1, [r6, #8]
	mov ip, r0
	cmp r1, r2
	beq _080178A6
	str r2, [r5, #0x3c]
_080178A6:
	lsls r0, r3, #2
	adds r0, r0, r2
	ldrb r3, [r0, #3]
	ldrb r0, [r5, #0x1f]
	cmp r3, r0
	beq _0801797C
	strb r3, [r5, #0x1f]
	ldr r0, _08017908 @ =wDynamicGraphicTilenums
	mov r2, ip
	lsls r1, r2, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r2, [r5, #0x20]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r2, r5, #0
	adds r2, #0x22
	ldr r0, _0801790C @ =wDynamicMotionPalIDs
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r0, ip
	cmp r0, #0x8f
	bhi _08017914
	ldr r2, _08017910 @ =gDynamicMotionGraphicOffsets
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	lsrs r1, r1, #6
	subs r1, r7, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl RequestGraphicTransfer
	b _0801794E
	.align 2, 0
_08017904: .4byte gDynamicMotionMetaspriteTable
_08017908: .4byte wDynamicGraphicTilenums
_0801790C: .4byte wDynamicMotionPalIDs
_08017910: .4byte gDynamicMotionGraphicOffsets
_08017914:
	ldr r2, _08017988 @ =gDynamicMotionGraphicOffsets
	adds r0, r4, r2
	ldr r4, [r0]
	adds r4, r4, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r1, [r4, #6]
	lsrs r1, r1, #6
	subs r1, r7, r1
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r4, #0
	bl RequestGraphicTransfer
	adds r0, r4, #0
	adds r0, #0xc
	ldrb r1, [r4, #0x13]
	mov r2, r8
	subs r1, r2, r1
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	bl LoadPalette
_0801794E:
	ldr r1, _0801798C @ =0x000003FF
	ands r1, r7
	ldrh r2, [r6, #0x14]
	ldr r0, _08017990 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r6, #0x14]
	ldrb r1, [r5, #0xb]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0801797C
	mov r0, r8
	lsls r2, r0, #4
	ldrb r1, [r6, #0x15]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r6, #0x15]
	adds r0, r5, #0
	adds r0, #0x23
	mov r1, r8
	strb r1, [r0]
_0801797C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017988: .4byte gDynamicMotionGraphicOffsets
_0801798C: .4byte 0x000003FF
_08017990: .4byte 0xFFFFFC00
