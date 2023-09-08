	push {r4, r5, r6, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08034340
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r1, _0803433C @ =0x00000131
	adds r0, r3, r1
	ldrb r6, [r0]
	ldrb r1, [r2, #0xc]
	b _0803434E
	.align 2, 0
_0803433C: .4byte 0x00000131
_08034340:
	adds r2, r3, #0
	adds r2, #0xb4
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r6, [r0]
	ldrb r1, [r2, #0xd]
_0803434E:
	movs r0, #3
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	adds r5, r2, #0
	movs r4, #0
	cmp r0, #0
	beq _08034388
	ldrb r0, [r5, #0xf]
	cmp r0, #3
	bne _08034368
	movs r4, #1
_08034368:
	adds r0, r3, #0
	movs r1, #0x34
	bl isElfUsed_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803437C
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0803437C:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _08034388
	cmp r4, #2
	bne _08034388
	movs r4, #1
_08034388:
	ldr r0, _08034398 @ =sFullChargeBorder
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r6, r0
	blo _0803439C
	movs r0, #2
	b _080343B2
	.align 2, 0
_08034398: .4byte sFullChargeBorder
_0803439C:
	ldr r0, _080343AC @ =sSemiChargeBorder
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r6, r0
	bhs _080343B0
	movs r0, #0
	b _080343B2
	.align 2, 0
_080343AC: .4byte sSemiChargeBorder
_080343B0:
	movs r0, #1
_080343B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
