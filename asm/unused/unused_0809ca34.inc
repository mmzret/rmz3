	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809CABC @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809CAB4
	adds r2, r3, #0
	adds r2, #0x25
	movs r1, #0
	movs r0, #8
	strb r0, [r2]
	ldr r0, _0809CAC0 @ =gProjectileFnTable
	strb r1, [r3, #9]
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r7, #0
	strh r1, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r7, [r0]
	ldr r0, [r6]
	str r0, [r3, #0x54]
	ldr r0, [r6, #4]
	str r0, [r3, #0x58]
	adds r0, r4, #0
	adds r0, #0x80
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	adds r0, r3, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r2, _0809CAC4 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _0809CA9A
	adds r0, #0xff
_0809CA9A:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _0809CAAE
	adds r0, #0xff
_0809CAAE:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
	strb r7, [r3, #0x10]
_0809CAB4:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809CABC: .4byte gProjectileHeaderPtr
_0809CAC0: .4byte gProjectileFnTable
_0809CAC4: .4byte gSineTable
