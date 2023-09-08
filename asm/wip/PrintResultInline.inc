	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	ldr r5, _080EA7DC @ =gTextWindow+8
	ldr r4, _080EA7E0 @ =gTextTable
	lsrs r3, r0, #0x18
	lsls r3, r3, #2
	adds r4, r3, r4
	ldr r2, _080EA7E4 @ =gTextOffsetTable
	adds r3, r3, r2
	movs r2, #0xff
	lsls r2, r2, #0x10
	ands r2, r0
	ldr r0, [r3]
	lsrs r2, r2, #0xf
	adds r2, r2, r0
	ldrh r2, [r2]
	ldr r0, [r4]
	adds r4, r0, r2
	cmp r1, #0
	bne _080EA7E8
	movs r0, #6
	bl PlaySound
	b _080EA7EE
	.align 2, 0
_080EA7DC: .4byte gTextWindow+8
_080EA7E0: .4byte gTextTable
_080EA7E4: .4byte gTextOffsetTable
_080EA7E8:
	movs r0, #4
	bl PlaySound
_080EA7EE:
	str r4, [r5, #0x18]
	movs r0, #0
	str r0, [r5, #8]
	adds r0, r5, #0
	bl resetTextWindow
	adds r0, r5, #0
	bl setupTextWindow
	movs r0, #3
	str r0, [r5, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
