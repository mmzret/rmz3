	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r7, #0
	movs r0, #0
	mov r8, r0
	ldr r1, [sp]
	cmp r1, #0
	beq _0801A088
	b _0801A1C4
_0801A088:
	ldr r2, _0801A0C8 @ =gStageRun
	ldr r0, [r2, #0xc]
	adds r0, #1
	str r0, [r2, #0xc]
	adds r0, r2, #0
	adds r0, #0xe8
	movs r1, #0x18
	ldrsb r1, [r0, r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	str r0, [sp, #4]
	adds r6, r2, #0
_0801A0A2:
	adds r0, r6, #0
	bl CheckMissionFail
	cmp r0, #0
	bne _0801A0F0
	ldrb r1, [r6, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801A0EC
	ldr r0, _0801A0CC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801A0D4
	ldr r0, _0801A0D0 @ =gFreerunUpdate
	b _0801A0D6
	.align 2, 0
_0801A0C8: .4byte gStageRun
_0801A0CC: .4byte gCurStory
_0801A0D0: .4byte gFreerunUpdate
_0801A0D4:
	ldr r0, _0801A0E8 @ =gMissionUpdate
_0801A0D6:
	ldrh r1, [r6]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	b _0801A0F0
	.align 2, 0
_0801A0E8: .4byte gMissionUpdate
_0801A0EC:
	movs r3, #1
	mov r8, r3
_0801A0F0:
	ldr r4, _0801A118 @ =gStageRun
	ldrb r1, [r4, #0x12]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0801A104
	ldrh r0, [r4, #8]
	adds r7, r5, #0
	bics r7, r0
_0801A104:
	adds r0, r4, #0
	adds r0, #0x10
	bl RunVM
	cmp r0, #0
	beq _0801A11C
	ldrh r0, [r4, #8]
	adds r7, r5, #0
	bics r7, r0
	b _0801A126
	.align 2, 0
_0801A118: .4byte gStageRun
_0801A11C:
	movs r0, #0
	mov r8, r0
	adds r0, r4, #0
	bl trySkipEventScene
_0801A126:
	mov r1, r8
	cmp r1, #0
	bne _0801A0A2
	ldr r3, [sp]
	cmp r3, #0
	bne _0801A19C
	ldr r0, _0801A1D4 @ =gStageRun+232
	mov sl, r0
	bl RunCameraCallback
	ldr r6, _0801A1D8 @ =0x020023D4
	subs r1, r6, #2
	mov sb, r1
	ldrb r0, [r1]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r4, r4, #3
	movs r5, #0x20
	rsbs r5, r5, #0
	ands r5, r4
	ldr r3, _0801A1DC @ =0x001FFFFF
	mov r8, r3
	lsrs r2, r5, #2
	adds r0, r6, #0
	ldr r1, _0801A1E0 @ =0x020026D4
	bl CpuFastSet
	movs r2, #0x1f
	ands r2, r4
	cmp r2, #0
	beq _0801A17A
	adds r0, r5, r6
	ldr r3, _0801A1E0 @ =0x020026D4
	adds r1, r5, r3
	lsrs r2, r2, #2
	mov r3, r8
	ands r2, r3
	movs r3, #0x80
	lsls r3, r3, #0x13
	orrs r2, r3
	bl CpuSet
_0801A17A:
	mov r1, sb
	ldrb r0, [r1]
	subs r1, r6, #1
	strb r0, [r1]
	mov r3, sp
	ldrb r0, [r3]
	mov r3, sb
	strb r0, [r3]
	mov r1, sl
	movs r0, #0x18
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0801A19C
	mov r0, sl
	adds r0, #0x38
	bl UpdateStageLandscape
_0801A19C:
	ldr r4, _0801A1E4 @ =gStageRun
	adds r0, r4, #0
	bl ApplyGiantElf
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _0801A1C2
	adds r0, r4, #0
	adds r0, #0xe8
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0801A1C2
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	bl UpdateStageEntities
_0801A1C2:
	adds r0, r7, #0
_0801A1C4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801A1D4: .4byte gStageRun+232
_0801A1D8: .4byte 0x020023D4
_0801A1DC: .4byte 0x001FFFFF
_0801A1E0: .4byte 0x020026D4
_0801A1E4: .4byte gStageRun
