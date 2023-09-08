	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08032CC4 @ =gUnlockedElfPtr
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08032CCC
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _08032CBE
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r4, _08032CC8 @ =0x00000231
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08032CBE
	ldrb r0, [r2]
	cmp r0, r1
	beq _08032CBE
	ldrb r0, [r2, #1]
	cmp r0, r1
	bne _08032CCC
_08032CBE:
	movs r0, #1
	b _08032CCE
	.align 2, 0
_08032CC4: .4byte gUnlockedElfPtr
_08032CC8: .4byte 0x00000231
_08032CCC:
	movs r0, #0
_08032CCE:
	pop {r4}
	pop {r1}
	bx r1
