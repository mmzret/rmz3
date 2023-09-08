	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldrb r0, [r0, #0xc]
	cmp r0, #2
	bne _08031544
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r2, #0x10
	b _0803154E
_08031544:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r2, #0x20
_0803154E:
	orrs r1, r2
	strb r1, [r0]
	adds r2, r0, #0
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08031574 @ =gZeroRodLadderRoutine
	adds r0, r3, #0
	adds r0, #0xed
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08031574: .4byte rodRoutine
