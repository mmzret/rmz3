	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r4, [r3, #0xc]
	ldr r1, [r4, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08022B20
	movs r5, #1
	ands r1, r5
	cmp r1, #0
	beq _08022B00
	ldr r0, _08022AFC @ =gCurStory
	ldrh r3, [r4, #2]
	lsls r2, r3, #0x10
	asrs r2, r2, #0x13
	adds r0, #4
	adds r2, r2, r0
	movs r1, #7
	ands r1, r3
	adds r0, r5, #0
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	b _08022B18
	.align 2, 0
_08022AFC: .4byte gCurStory
_08022B00:
	ldr r0, _08022B1C @ =gCurStory
	ldrh r1, [r4, #2]
	lsls r2, r1, #0x10
	asrs r2, r2, #0x13
	adds r0, #4
	adds r2, r2, r0
	movs r0, #7
	ands r0, r1
	adds r1, r5, #0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
_08022B18:
	strb r0, [r2]
	b _08022B48
	.align 2, 0
_08022B1C: .4byte gCurStory
_08022B20:
	ldrb r0, [r4, #1]
	lsls r2, r0, #4
	adds r0, r3, #0
	adds r0, #0x10
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08022B48
	cmp r1, #0
	beq _08022B3E
	adds r2, r3, r2
	ldrb r1, [r4, #2]
	ldrb r0, [r2, #0x19]
	orrs r0, r1
	b _08022B46
_08022B3E:
	adds r2, r3, r2
	ldrb r1, [r4, #2]
	ldrb r0, [r2, #0x19]
	bics r0, r1
_08022B46:
	strb r0, [r2, #0x19]
_08022B48:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
