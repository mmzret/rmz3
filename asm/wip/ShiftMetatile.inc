	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r2, #0
	ldr r4, _080091A4 @ =gOverworld
	movs r3, #0xe8
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrb r3, [r2]
	movs r2, #0x7f
	ands r2, r3
	ldr r3, _080091A8 @ =gStageLandscape
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	ldr r3, _080091AC @ =0x000007E4
	adds r7, r4, r3
	mov r8, r7
	ldr r2, [r2, #0xc]
	ldrb r3, [r2, #2]
	lsls r2, r3, #4
	subs r3, r2, r3
	movs r4, #6
	ldrsh r2, [r6, r4]
	adds r1, r1, r2
	muls r1, r3, r1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r7, r1, r7
	movs r1, #2
	ldrsh r0, [r6, r1]
	adds r0, r0, r2
	muls r0, r3, r0
	movs r4, #0
	ldrsh r1, [r6, r4]
	adds r0, r0, r1
	lsls r0, r0, #1
	add r8, r0
	movs r5, #0
	cmp r5, r2
	bge _0800918E
	lsls r4, r3, #1
_08009170:
	subs r7, r7, r4
	mov r0, r8
	subs r0, r0, r4
	mov r8, r0
	movs r1, #4
	ldrsh r2, [r6, r1]
	lsls r2, r2, #1
	adds r1, r7, #0
	bl Transfer30Bytes
	adds r5, #1
	movs r3, #6
	ldrsh r0, [r6, r3]
	cmp r5, r0
	blt _08009170
_0800918E:
	ldr r0, _080091A4 @ =gOverworld
	movs r4, #0xb0
	lsls r4, r4, #0xa
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080091A4: .4byte gOverworld
_080091A8: .4byte gStageLandscape
_080091AC: .4byte 0x000007E4
