	mov ip, r0
	mov r1, ip
	adds r1, #0xc8
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r0, ip
	adds r0, #0xc4
	ldr r2, [r0]
	mov r0, ip
	str r2, [r0, #0x58]
	ldr r3, _080500C4 @ =gSineTable
	ldrh r0, [r1]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r2, r2, r0
	mov r0, ip
	str r2, [r0, #0x58]
	bx lr
	.align 2, 0
_080500C4: .4byte gSineTable
