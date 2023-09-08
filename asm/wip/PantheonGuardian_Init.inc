	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _080637A0 @ =gSystemSavedataManager
	ldrb r1, [r0, #8]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080637AC
	ldr r0, _080637A4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080637AC
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080637A8 @ =0x08365AC8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	b _080637C4
	.align 2, 0
_080637A0: .4byte gSystemSavedataManager
_080637A4: .4byte gCurStory
_080637A8: .4byte 0x08365AC8
_080637AC:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0806381C @ =0x08365AC8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
_080637C4:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08063820 @ =FUN_0806465c
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r2, #0
	str r2, [r6, #0x60]
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xc0
	str r2, [r0]
	subs r0, #8
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r1, _08063824 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #1
	str r3, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r0, _08063828 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	bge _0806382C
	strb r3, [r6, #0xd]
	b _08063830
	.align 2, 0
_0806381C: .4byte 0x08365AC8
_08063820: .4byte FUN_0806465c
_08063824: .4byte gEnemyFnTable
_08063828: .4byte pZero2
_0806382C:
	movs r0, #2
	strb r0, [r6, #0xd]
_08063830:
	strb r2, [r6, #0xe]
	adds r0, r6, #0
	bl PantheonGuardian_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
  .align 2, 0
