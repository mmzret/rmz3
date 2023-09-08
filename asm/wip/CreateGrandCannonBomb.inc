	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	adds r7, r4, #0
	ldr r0, _0809D2A0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809D29A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0809D2A4 @ =gProjectileFnTable
	movs r0, #3
	strb r0, [r3, #9]
	ldr r0, [r1, #0xc]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r5]
	str r0, [r3, #0x54]
	ldr r0, [r5, #4]
	str r0, [r3, #0x58]
	ldr r1, _0809D2A8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	bge _0809D282
	adds r0, #0xff
_0809D282:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	bge _0809D296
	adds r0, #0xff
_0809D296:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
_0809D29A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D2A0: .4byte gProjectileHeaderPtr
_0809D2A4: .4byte gProjectileFnTable
_0809D2A8: .4byte gSineTable
