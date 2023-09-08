	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r0, #0
	mov r8, r0
	mov sb, r0
	cmp r4, #0
	beq _08033F4A
	ldrb r1, [r4]
	mov sb, r1
_08033F4A:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r3, [r0, #0xc]
	adds r7, r0, #0
	cmp r3, #3
	bne _08033F96
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08033F76
	cmp r4, #0
	beq _08033F70
	strb r3, [r4]
_08033F70:
	movs r1, #1
	mov r8, r1
	b _08033FC6
_08033F76:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r2, r0
	cmp r2, #0
	beq _08033FC6
	adds r0, r5, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033FC6
	cmp r4, #0
	beq _08033F90
	strb r3, [r4]
_08033F90:
	movs r0, #2
	mov r8, r0
	b _08033FC6
_08033F96:
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08033FC6
	cmp r4, #0
	beq _08033FB0
	strb r3, [r4]
_08033FB0:
	ldr r1, _08034038 @ =sWeaponOKTable
	ldrb r0, [r7, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034064
_08033FC6:
	adds r2, r7, #0
	ldrb r3, [r2, #0xd]
	ldrb r0, [r2, #0xc]
	adds r1, r3, #0
	cmp r0, r1
	beq _0803406C
	cmp r1, #3
	bne _0803403C
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08033FFE
	cmp r4, #0
	beq _08033FE8
	strb r3, [r4]
_08033FE8:
	ldr r1, _08034038 @ =sWeaponOKTable
	ldrb r0, [r2, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034064
_08033FFE:
	adds r2, r7, #0
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0803406C
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803406C
	cmp r4, #0
	beq _0803401E
	ldrb r0, [r2, #0xd]
	strb r0, [r4]
_0803401E:
	ldr r1, _08034038 @ =sWeaponOKTable
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803406C
	movs r0, #2
	b _080340A0
	.align 2, 0
_08034038: .4byte sWeaponOKTable
_0803403C:
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0803406C
	cmp r4, #0
	beq _0803404E
	strb r3, [r4]
_0803404E:
	ldr r1, _08034068 @ =sWeaponOKTable
	ldrb r0, [r7, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803406C
_08034064:
	movs r0, #1
	b _080340A0
	.align 2, 0
_08034068: .4byte sWeaponOKTable
_0803406C:
	mov r0, r8
	cmp r0, #0
	beq _08034096
	cmp r4, #0
	beq _08034090
	ldr r1, _080340AC @ =sWeaponOKTable
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803409E
	movs r1, #0
	mov r8, r1
_08034090:
	mov r0, r8
	cmp r0, #0
	bne _0803409E
_08034096:
	cmp r4, #0
	beq _0803409E
	mov r1, sb
	strb r1, [r4]
_0803409E:
	mov r0, r8
_080340A0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080340AC: .4byte sWeaponOKTable
