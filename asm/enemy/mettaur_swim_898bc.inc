	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _080898CE
	cmp r4, #1
	beq _080898F2
	b _080899EA
_080898CE:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808994C @ =0x08368844
	bl SetDDP
	ldr r1, _08089950 @ =0x0000DD06
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0x78
	strh r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080898F2:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r2, [r6, #0x12]
	adds r3, r2, #0
	cmp r2, #0
	bne _08089908
	ldrb r0, [r6, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r6, #0x13]
_08089908:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _08089958
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r4, r0, r1
	ldr r3, _08089954 @ =gSineTable
	movs r1, #0x80
	subs r1, r1, r2
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	b _0808998A
	.align 2, 0
_0808994C: .4byte 0x08368844
_08089950: .4byte 0x0000DD06
_08089954: .4byte gSineTable
_08089958:
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r5, _080899F4 @ =0xFFFFE800
	adds r4, r0, r5
	ldr r2, _080899F8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
_0808998A:
	lsls r0, r0, #5
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080899E4
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0x2c
	bl PlaySound
	ldr r0, [r6, #0x54]
	ldr r2, _080899FC @ =0xFFFFF800
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r6, #0x58]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r5, #0x80
	lsls r5, r5, #2
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xe0
	bl CreateLemon
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xa0
	bl CreateLemon
_080899E4:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080899EA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080899F4: .4byte 0xFFFFE800
_080899F8: .4byte gSineTable
_080899FC: .4byte 0xFFFFF800
