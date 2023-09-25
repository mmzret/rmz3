	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	ldr r1, _08018D5C @ =sStagePreloadEntities
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r6, [r0]
	ldrb r0, [r6]
	cmp r0, #0xff
	beq _08018E06
	movs r3, #1
	ldr r7, _08018D60 @ =0x0202FDBA
	ldr r0, _08018D64 @ =wStaticGraphicTilenums
	mov sb, r0
	ldr r1, _08018D68 @ =wStaticMotionPalIDs
	mov r8, r1
_08018D3E:
	ldrb r0, [r6, #1]
	mov r2, sl
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08018DFE
	ldr r0, _08018D6C @ =gStageEntityManager
	ldr r1, _08018D70 @ =0x00000227
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018D74
	ldrb r1, [r6, #5]
	movs r0, #2
	b _08018D78
	.align 2, 0
_08018D5C: .4byte sStagePreloadEntities
_08018D60: .4byte 0x0202FDBA
_08018D64: .4byte wStaticGraphicTilenums
_08018D68: .4byte wStaticMotionPalIDs
_08018D6C: .4byte gStageEntityManager
_08018D70: .4byte 0x00000227
_08018D74:
	ldrb r1, [r6, #5]
	adds r0, r3, #0
_08018D78:
	ands r0, r1
	cmp r0, #0
	beq _08018DFE
	ldrb r1, [r6, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08018DFE
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _08018D9A
	adds r0, r3, #0
	ldrb r2, [r6, #4]
	lsls r0, r2
	ldrh r1, [r7]
	orrs r0, r1
	b _08018DA4
_08018D9A:
	adds r1, r3, #0
	ldrb r0, [r6, #4]
	lsls r1, r0
	ldrh r0, [r7]
	bics r0, r1
_08018DA4:
	strh r0, [r7]
	ldrb r0, [r6]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r6, #2]
	strh r1, [r0]
	ldrb r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrb r1, [r6, #4]
	strh r1, [r0]
	ldrb r4, [r6]
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #2
	ldr r1, _08018E18 @ =gStaticMotionGraphics
	adds r0, r5, r1
	lsls r4, r4, #1
	mov r2, sb
	adds r1, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	str r3, [sp]
	bl LoadGraphic
	ldr r0, _08018E1C @ =gStaticMotionGraphics+12
	adds r5, r5, r0
	add r4, r8
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r5, #0
	bl LoadPalette
	ldr r3, [sp]
_08018DFE:
	adds r6, #8
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _08018D3E
_08018E06:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018E18: .4byte gStaticMotionGraphics
_08018E1C: .4byte gStaticMotionGraphics+12
