	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C7398 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	ldr r1, _080C739C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	str r1, [r4, #0x74]
	str r0, [r4, #0x78]
	strb r2, [r4, #0x12]
	movs r0, #0x80
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl CyberSpaceElf_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C7398: .4byte gVFXFnTable
_080C739C: .4byte 0xFFFFEE00
