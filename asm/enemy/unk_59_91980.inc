	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _0809198C
	b _08091AA6
_0809198C:
	lsls r0, r0, #2
	ldr r1, _08091998 @ =_0809199C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08091998: .4byte _0809199C
_0809199C: @ jump table
	.4byte _080919BC @ case 0
	.4byte _080919D0 @ case 1
	.4byte _080919E0 @ case 2
	.4byte _080919EA @ case 3
	.4byte _08091A08 @ case 4
	.4byte _08091A12 @ case 5
	.4byte _08091A3C @ case 6
	.4byte _08091A46 @ case 7
_080919BC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080919DC @ =0x08369894
	bl SetDDP
	movs r0, #0x1b
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	b _08091A30
	.align 2, 0
_080919DC: .4byte 0x08369894
_080919E0:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919EA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _08091A26
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A2C
_08091A08:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091A26
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _08091A2C
_08091A26:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A2C:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
_08091A30:
	cmp r0, #0
	bne _08091AA6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08091AA6
_08091A3C:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A46:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08091A64
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A6A
_08091A64:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A6A:
	strb r0, [r4, #0xa]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	bne _08091AA6
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091AAC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091AA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091AAC: .4byte gEnemyFnTable
