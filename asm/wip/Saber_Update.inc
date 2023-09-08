	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r6, [r5]
	ldr r0, _08038424 @ =0x0000012D
	adds r1, r6, r0
	ldrb r0, [r4, #0x10]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0803842C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _08038428 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080384CE
	.align 2, 0
_08038424: .4byte 0x0000012D
_08038428: .4byte gWeaponFnTable
_0803842C:
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	beq _0803844C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0803844C
	movs r0, #0x2b
	bl PlaySound
	movs r0, #0
	strb r0, [r5, #0xf]
_0803844C:
	ldrb r0, [r4, #0x10]
	cmp r0, #6
	bne _08038480
	ldrb r0, [r6, #0xd]
	cmp r0, #2
	bne _0803846C
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08038494
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803849A
_0803846C:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _08038494
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803849A
_08038480:
	ldrb r0, [r6, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08038494
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803849A
_08038494:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803849A:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r6, #0x58]
	str r0, [r4, #0x58]
	ldr r1, _080384D4 @ =0x0835F010
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080384CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080384D4: .4byte sSaberActions
