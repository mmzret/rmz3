	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb4
	ldr r6, [r4]
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	beq _08038DA8
	b _08038EBE
_08038DA8:
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r0, #0xd8
	lsls r0, r0, #5
	cmp r1, r0
	beq _08038E60
	adds r0, #1
	cmp r1, r0
	bne _08038E28
	ldrb r0, [r5, #0x10]
	cmp r0, #0x16
	bne _08038DD8
	ldr r1, _08038DD4 @ =0x00006401
	adds r0, r5, #0
	bl SetMotion
	b _08038E0E
	.align 2, 0
_08038DD4: .4byte 0x00006401
_08038DD8:
	ldr r1, _08038E24 @ =0x00006403
	adds r0, r5, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	bne _08038E0E
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038E0E
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl CreateSmashElec
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl CreateSmashElec
_08038E0E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08038EE0
	.align 2, 0
_08038E24: .4byte 0x00006403
_08038E28:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08038E5C @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08038EDE
	.align 2, 0
_08038E5C: .4byte gWeaponFnTable
_08038E60:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #1
	bls _08038EB8
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08038EB4 @ =gSaberCollisions
	ldrb r2, [r5, #0x10]
	lsls r2, r2, #2
	adds r2, r2, r1
	adds r1, r5, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	ldrb r2, [r4, #0xd]
	ldrb r3, [r4, #0xc]
	ldrb r4, [r4, #0xe]
	str r4, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	bl InitWeaponBody
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	b _08038EE0
	.align 2, 0
_08038EB4: .4byte gSaberCollisions
_08038EB8:
	adds r0, #1
	strb r0, [r5, #0x12]
	b _08038EE0
_08038EBE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08038EE0
	ldr r1, _08038EE8 @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
_08038EDE:
	str r0, [r5, #0x14]
_08038EE0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08038EE8: .4byte gWeaponFnTable
