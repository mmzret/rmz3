	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r5, #0x10
	movs r1, #0
	ldr r0, _080258E4 @ =gUnlockedElfPtr
	ldr r6, [r0]
_08025888:
	adds r1, #1
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	adds r0, r6, r3
	ldrb r2, [r0]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080258C2
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _080258BC
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r7, _080258E8 @ =0x00000231
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _080258BC
	ldrb r0, [r2]
	cmp r0, r3
	beq _080258BC
	ldrb r0, [r2, #1]
	cmp r0, r3
	bne _080258C2
_080258BC:
	adds r0, r5, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080258C2:
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08025888
	adds r0, r4, #0
	bl IsDoubleHP
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080258DA
	lsls r0, r5, #0x19
	lsrs r5, r0, #0x18
_080258DA:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080258E4: .4byte gUnlockedElfPtr
_080258E8: .4byte 0x00000231
