	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	ldr r0, [r4, #4]
	adds r2, r4, #0
	adds r2, #0x3b
	ldrb r1, [r0, #9]
	ldrb r0, [r2]
	adds r2, r0, #0
	orrs r2, r1
	adds r5, r2, #0
	ldr r0, _08007C64 @ =gCollisionManager
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08007C5E
	adds r6, r4, #0
	adds r6, #0x20
	ldrb r0, [r6]
	cmp r0, #0
	beq _08007C68
_08007C5E:
	movs r0, #0
	b _08007CC4
	.align 2, 0
_08007C64: .4byte gCollisionManager
_08007C68:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08007C74
	lsls r0, r3, #0x19
	lsrs r3, r0, #0x18
_08007C74:
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	beq _08007C88
	lsls r0, r3, #1
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_08007C88:
	cmp r3, #0
	bne _08007C8E
	movs r3, #1
_08007C8E:
	movs r0, #2
	ands r5, r0
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08007CC2
	ldrh r0, [r4, #0x30]
	subs r0, r0, r3
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08007CB2
	strh r1, [r4, #0x30]
	ldr r0, [r4, #0x14]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r4, #0x14]
_08007CB2:
	ldr r0, [r4, #4]
	ldrb r0, [r0, #2]
	cmp r0, #1
	beq _08007CBE
	cmp r0, #2
	bne _08007CC2
_08007CBE:
	movs r0, #0x5a
	strb r0, [r6]
_08007CC2:
	adds r0, r3, #0
_08007CC4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
