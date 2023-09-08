	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r0, _08038184 @ =DeleteSaber
	bl KillAllWeapons
	ldr r0, _08038188 @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r5, r0, #0
	cmp r5, #0
	beq _080381EA
	adds r0, r6, #0
	adds r0, #0xe4
	ldrb r1, [r0]
	cmp r1, #1
	bne _0803819C
	ldr r0, _0803818C @ =gWeaponFnTable
	strb r1, [r5, #9]
	ldr r0, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r5, #0xb]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _08038190 @ =gWeaponTileNum
	ldrh r0, [r0]
	strh r0, [r5, #0x20]
	ldr r0, _08038194 @ =gWeaponPalIDs
	ldrb r0, [r0]
	subs r1, #3
	strb r0, [r1]
	ldr r1, _08038198 @ =gSaberElements
	adds r4, r6, #0
	adds r4, #0xb4
	ldrb r0, [r4, #0xe]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0
	bl SetWeaponElement
	b _080381D8
	.align 2, 0
_08038184: .4byte DeleteSaber
_08038188: .4byte gWeaponHeaderPtr
_0803818C: .4byte gWeaponFnTable
_08038190: .4byte gWeaponTileNum
_08038194: .4byte gWeaponPalIDs
_08038198: .4byte gSaberElements
_0803819C:
	movs r0, #1
	ldr r1, _080381F4 @ =gWeaponFnTable
	strb r0, [r5, #9]
	ldr r0, [r1, #4]
	ldr r0, [r0]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r5, #0xb]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _080381F8 @ =gWeaponTileNum
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x20]
	ldr r0, _080381FC @ =gWeaponPalIDs
	ldrb r0, [r0, #1]
	subs r1, #3
	strb r0, [r1]
	ldr r1, _08038200 @ =gSaberElements
	adds r4, r6, #0
	adds r4, #0xb4
	ldrb r0, [r4, #0xe]
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #1
	bl SetWeaponElement
_080381D8:
	ldr r1, _08038204 @ =0x0000012D
	adds r0, r6, r1
	strb r7, [r0]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	strb r7, [r5, #0x10]
	ldrb r0, [r4, #0xe]
	strb r0, [r5, #0x11]
_080381EA:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080381F4: .4byte gWeaponFnTable
_080381F8: .4byte gWeaponTileNum
_080381FC: .4byte gWeaponPalIDs
_08038200: .4byte gSaberElements
_08038204: .4byte 0x0000012D
