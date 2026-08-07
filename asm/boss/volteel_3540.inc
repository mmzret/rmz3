	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08043614
	cmp r0, #1
	bgt _08043554
	cmp r0, #0
	beq _0804355A
	b _08043638
_08043554:
	cmp r0, #2
	beq _08043630
	b _08043638
_0804355A:
	ldr r3, _080435D4 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0804357C
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0804357C
	ldr r0, _080435D8 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0804357C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	strb r0, [r1]
	adds r1, #0x2c
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x7f
	bl isSoundPlaying
	cmp r0, #0
	beq _080435BE
	movs r0, #0x7f
	bl StopSound
_080435BE:
	ldr r2, _080435DC @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0xd
	bne _080435E4
	ldr r1, _080435E0 @ =0x0002D024
	b _080435E6
	.align 2, 0
_080435D4: .4byte gStageRun
_080435D8: .4byte 0x0000FFFE
_080435DC: .4byte gOverworld
_080435E0: .4byte 0x0002D024
_080435E4:
	ldr r1, _0804362C @ =0x0002D026
_080435E6:
	adds r0, r2, r1
	strb r5, [r0]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08043614:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08043638
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08043638
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08043638
	.align 2, 0
_0804362C: .4byte 0x0002D026
_08043630:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08043638:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

