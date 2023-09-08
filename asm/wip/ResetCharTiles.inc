	push {r4, r5, lr}
	ldr r0, _080E97E8 @ =gTextPrinter
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r2, r0, r1
	movs r1, #0
	str r1, [r2]
	movs r4, #0x4f
	adds r5, r0, #0
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r3, _080E97EC @ =0x0000037E
_080E97BE:
	strh r3, [r1, #6]
	ldr r0, [r2]
	str r0, [r1]
	str r1, [r2]
	subs r1, #8
	subs r3, #2
	subs r4, #1
	cmp r4, #0
	bge _080E97BE
	movs r0, #0
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r1, r5, r2
	str r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	str r0, [r1]
	strh r0, [r5, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E97E8: .4byte gTextPrinter
_080E97EC: .4byte 0x0000037E
