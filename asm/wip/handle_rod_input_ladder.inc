	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb4
	movs r0, #0x86
	lsls r0, r0, #2
	adds r3, r5, r0
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080315AA
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_080315AA:
	ldr r0, [r3]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080315D0
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_080315D0:
	ldrb r0, [r4, #0xc]
	cmp r0, #2
	bne _080315DC
	adds r0, r5, #0
	movs r1, #0
	b _080315E0
_080315DC:
	adds r0, r5, #0
	movs r1, #1
_080315E0:
	bl GetWeaponCharge
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r2, _0803163C @ =0x00000133
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08031640 @ =0x00000225
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _08031662
	ldr r0, _08031644 @ =0x00000226
	adds r4, r5, r0
	ldrb r1, [r4]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r0, [r4]
	movs r1, #0x4a
	adds r1, r1, r5
	mov ip, r1
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	mov r0, ip
	ldrb r3, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4]
	ands r2, r0
	cmp r2, #0
	beq _08031648
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0803164E
	.align 2, 0
_0803163C: .4byte 0x00000133
_08031640: .4byte 0x00000225
_08031644: .4byte 0x00000226
_08031648:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803164E:
	strb r0, [r5, #0xa]
	adds r2, r5, #0
	adds r2, #0xed
	movs r1, #0
	movs r0, #7
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xee
	strb r1, [r0]
	b _08031674
_08031662:
	cmp r1, #2
	bne _0803167C
	adds r1, r5, #0
	adds r1, #0xed
	movs r0, #7
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xee
	strb r2, [r0]
_08031674:
	adds r0, r5, #0
	bl charge_rod
	b _08031690
_0803167C:
	adds r1, r5, #0
	adds r1, #0xed
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xee
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_08031698
_08031690:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
