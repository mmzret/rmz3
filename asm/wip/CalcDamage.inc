	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, [r1, #4]
	adds r1, #0x3b
	ldrb r2, [r3, #9]
	ldrb r0, [r1]
	adds r5, r0, #0
	orrs r5, r2
	ldr r0, _08007608 @ =gCollisionManager
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08007602
	ldrb r0, [r3, #8]
	cmp r0, #0xff
	beq _08007602
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	bne _08007602
	ldr r2, _0800760C @ =sDamageScale
	adds r0, r4, #0
	adds r0, #0x38
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrb r1, [r3, #8]
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldr r1, [r0]
	cmp r1, #9
	bne _08007610
_08007602:
	movs r0, #0
	b _0800766E
	.align 2, 0
_08007608: .4byte gCollisionManager
_0800760C: .4byte sDamageScale
_08007610:
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r4, [r0]
	adds r0, r4, #0
	muls r0, r1, r0
	asrs r2, r0, #2
	ldrb r1, [r3, #2]
	cmp r1, #1
	bne _08007640
	ldr r0, _08007664 @ =gCurStory
	ldrb r0, [r0, #8]
	ands r1, r0
	cmp r1, #0
	beq _08007632
	cmp r4, #0xfe
	bne _08007632
	movs r2, #8
_08007632:
	ldr r0, _08007668 @ =gSystemSavedataManager
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08007640
	asrs r2, r2, #1
_08007640:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq _0800764A
	lsls r2, r2, #1
_0800764A:
	movs r0, #4
	ands r5, r0
	cmp r5, #0
	beq _0800765C
	lsls r0, r2, #1
	movs r1, #3
	bl __divsi3
	adds r2, r0, #0
_0800765C:
	cmp r2, #0
	bne _0800766C
	movs r0, #1
	b _0800766E
	.align 2, 0
_08007664: .4byte gCurStory
_08007668: .4byte gSystemSavedataManager
_0800766C:
	adds r0, r2, #0
_0800766E:
	pop {r4, r5}
	pop {r1}
	bx r1
