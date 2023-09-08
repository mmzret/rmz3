	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r0, [sp, #0x18]
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0803ADF0 @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _0803AE3A
	adds r0, r4, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803AE00
	ldr r1, _0803ADF4 @ =gWeaponFnTable
	movs r0, #7
	strb r0, [r2, #9]
	ldr r0, [r1, #0x1c]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	ldrb r1, [r2, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #0xb]
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0803ADF8 @ =gWeaponTileNum
	ldrh r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, _0803ADFC @ =gWeaponPalIDs
	ldrb r0, [r0]
	b _0803AE26
	.align 2, 0
_0803ADF0: .4byte gWeaponHeaderPtr
_0803ADF4: .4byte gWeaponFnTable
_0803ADF8: .4byte gWeaponTileNum
_0803ADFC: .4byte gWeaponPalIDs
_0803AE00:
	ldr r1, _0803AE48 @ =gWeaponFnTable
	movs r0, #7
	strb r0, [r2, #9]
	ldr r0, [r1, #0x1c]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	ldrb r1, [r2, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #0xb]
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0803AE4C @ =gWeaponTileNum
	ldrh r0, [r0, #2]
	strh r0, [r2, #0x20]
	ldr r0, _0803AE50 @ =gWeaponPalIDs
	ldrb r0, [r0, #1]
_0803AE26:
	subs r1, #3
	strb r0, [r1]
	str r4, [r2, #0x28]
	adds r0, r2, #0
	adds r0, #0xb4
	str r7, [r0]
	mov r0, r8
	str r0, [r2, #0x2c]
	strb r6, [r2, #0x10]
	strb r5, [r2, #0x11]
_0803AE3A:
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803AE48: .4byte gWeaponFnTable
_0803AE4C: .4byte gWeaponTileNum
_0803AE50: .4byte gWeaponPalIDs
