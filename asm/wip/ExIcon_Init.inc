	push {lr}
	ldr r2, _080E71AC @ =gWidgetFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldrb r2, [r0, #0xa]
	movs r1, #1
	movs r3, #0
	orrs r1, r2
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #0xa]
	adds r1, r0, #0
	adds r1, #0x4c
	strb r3, [r1]
	adds r3, r0, #0
	adds r3, #0x4a
	ldrb r2, [r3]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r3]
	ldrb r2, [r0, #0xa]
	movs r1, #0xef
	ands r1, r2
	strb r1, [r0, #0xa]
	ldrb r2, [r0, #0x10]
	movs r1, #3
	ands r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0xb
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	str r1, [r0, #0x54]
	ldrb r2, [r0, #0x10]
	lsrs r2, r2, #2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #0xb
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0, #0x58]
	bl ExIcon_Update
	pop {r0}
	bx r0
	.align 2, 0
_080E71AC: .4byte gWidgetFnTable
