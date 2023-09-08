	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r0, [r1]
	adds r5, r0, #0
	adds r5, #0xb4
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r6, #1
	adds r2, r6, #0
	ands r2, r0
	cmp r2, #0
	beq _08036D96
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _08036E50
_08036D96:
	ldrb r0, [r3, #0x10]
	cmp r0, #1
	bls _08036E7E
	ldrb r4, [r5, #0xe]
	ldrb r1, [r1, #0xd]
	cmp r4, r1
	bne _08036E4A
	ldrb r1, [r3, #0x10]
	cmp r1, #4
	beq _08036E34
	cmp r1, #4
	bgt _08036DB4
	cmp r1, #2
	beq _08036DBA
	b _08036E7E
_08036DB4:
	cmp r1, #5
	beq _08036E3C
	b _08036E7E
_08036DBA:
	cmp r4, #0
	bne _08036DE4
	ldrh r1, [r5, #0x12]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08036E7E
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	b _08036E64
_08036DE4:
	cmp r4, #2
	bne _08036DF4
	ldrh r1, [r5, #0x12]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08036E7E
	b _08036E4A
_08036DF4:
	cmp r4, #3
	bne _08036E7E
	ldrh r1, [r5, #0x12]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08036E7E
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08036E30 @ =gWeaponFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r3, #0xc]
	b _08036E78
	.align 2, 0
_08036E30: .4byte gWeaponFnTable
_08036E34:
	ldrh r0, [r5, #0x12]
	ands r1, r0
	lsrs r2, r1, #2
	b _08036E46
_08036E3C:
	ldrh r1, [r5, #0x12]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x13
_08036E46:
	cmp r2, #0
	bne _08036E7E
_08036E4A:
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08036E50:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
_08036E64:
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08036E84 @ =gWeaponFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
_08036E78:
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_08036E7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036E84: .4byte gWeaponFnTable
