	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080327B8 @ =gUnlockedElfPtr
	ldr r1, [r0]
	adds r1, #0x28
	ldrb r2, [r1]
	movs r1, #1
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _080327C8
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0803279C
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r2, _080327BC @ =0x00000231
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803279C
	ldrb r0, [r1]
	cmp r0, #0x28
	beq _0803279C
	ldrb r0, [r1, #1]
	cmp r0, #0x28
	bne _080327C8
_0803279C:
	ldr r3, _080327C0 @ =gCurStory
	ldrb r0, [r3, #8]
	movs r2, #0x80
	orrs r0, r2
	strb r0, [r3, #8]
	ldr r1, _080327C4 @ =gGameState+25200
	ldrb r0, [r1, #4]
	orrs r0, r2
	strb r0, [r1, #4]
	adds r1, #0x54
	ldrb r0, [r1, #4]
	orrs r2, r0
	strb r2, [r1, #4]
	b _080327E8
	.align 2, 0
_080327B8: .4byte gUnlockedElfPtr
_080327BC: .4byte 0x00000231
_080327C0: .4byte gCurStory
_080327C4: .4byte gGameState+25200
_080327C8:
	ldr r4, _08032820 @ =gCurStory
	ldrb r2, [r4, #8]
	movs r1, #0x7f
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r4, #8]
	ldr r2, _08032824 @ =gGameState+25200
	ldrb r3, [r2, #4]
	adds r0, r1, #0
	ands r0, r3
	strb r0, [r2, #4]
	adds r2, #0x54
	ldrb r0, [r2, #4]
	ands r1, r0
	strb r1, [r2, #4]
	adds r3, r4, #0
_080327E8:
	ldr r0, [r6]
	adds r0, #0x29
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803282C
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08032818
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r2, _08032828 @ =0x00000231
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08032818
	ldrb r0, [r1]
	cmp r0, #0x29
	beq _08032818
	ldrb r0, [r1, #1]
	cmp r0, #0x29
	bne _0803282C
_08032818:
	ldrb r1, [r3, #8]
	movs r0, #0x20
	orrs r0, r1
	b _08032832
	.align 2, 0
_08032820: .4byte gCurStory
_08032824: .4byte gGameState+25200
_08032828: .4byte 0x00000231
_0803282C:
	ldrb r1, [r3, #8]
	movs r0, #0xdf
	ands r0, r1
_08032832:
	strb r0, [r3, #8]
	ldr r0, [r6]
	ldrb r1, [r0, #0x1b]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08032870
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08032862
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r2, _0803286C @ =0x00000231
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08032862
	ldrb r0, [r1]
	cmp r0, #0x1b
	beq _08032862
	ldrb r0, [r1, #1]
	cmp r0, #0x1b
	bne _08032870
_08032862:
	ldrb r1, [r3, #8]
	movs r0, #1
	orrs r0, r1
	b _08032876
	.align 2, 0
_0803286C: .4byte 0x00000231
_08032870:
	ldrb r1, [r3, #8]
	movs r0, #0xfe
	ands r0, r1
_08032876:
	strb r0, [r3, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
