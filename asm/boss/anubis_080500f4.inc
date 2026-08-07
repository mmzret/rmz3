	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x8c
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08050114
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0805018C
_08050114:
	ldr r0, _08050174 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _0805018C
	adds r5, r4, #0
	adds r5, #0xd0
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0805013E
	adds r0, r1, #0
	bl StopSound
	ldr r0, _08050178 @ =0x0000FFFF
	strh r0, [r5]
_0805013E:
	adds r1, r4, #0
	adds r1, #0xce
	ldrb r0, [r1]
	cmp r0, #0
	beq _08050150
	strb r6, [r1]
	movs r0, #0
	bl FUN_08010188
_08050150:
	ldr r1, _0805017C @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08050180
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08050182
	.align 2, 0
_08050174: .4byte gStageRun
_08050178: .4byte 0x0000FFFF
_0805017C: .4byte gBossFnTable
_08050180:
	strb r1, [r4, #0xd]
_08050182:
	adds r0, r4, #0
	bl Anubis_Die
	movs r0, #1
	b _0805018E
_0805018C:
	movs r0, #0
_0805018E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
