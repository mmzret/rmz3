	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B37F0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B381A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080B37F4 @ =gVFXFnTable
	movs r0, #5
	strb r0, [r3, #9]
	ldr r0, [r1, #0x14]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r4, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	adds r2, r5, #0
	cmp r2, #0
	beq _080B37F8
	ldrb r0, [r3, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B37FE
	.align 2, 0
_080B37F0: .4byte gVFXHeaderPtr
_080B37F4: .4byte gVFXFnTable
_080B37F8:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B37FE:
	strb r0, [r3, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080B381A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
