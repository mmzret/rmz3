	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, [sp, #0x20]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, _08036F00 @ =DeleteSaber
	bl KillAllWeapons
	ldr r0, _08036F04 @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r5, r0, #0
	cmp r5, #0
	bne _08036EC0
	b _08036FE8
_08036EC0:
	adds r0, r6, #0
	adds r0, #0xe4
	ldrb r1, [r0]
	cmp r1, #0
	bne _08036F14
	ldr r0, _08036F08 @ =gWeaponFnTable
	strb r1, [r5, #9]
	ldr r0, [r0]
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
	ldr r0, _08036F0C @ =gWeaponTileNum
	ldrh r0, [r0]
	strh r0, [r5, #0x20]
	ldr r0, _08036F10 @ =gWeaponPalIDs
	ldrb r0, [r0]
	subs r1, #3
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0xb4
	ldrb r1, [r4, #0xe]
	movs r0, #0
	bl SetWeaponElement
	b _08036F4A
	.align 2, 0
_08036F00: .4byte DeleteSaber
_08036F04: .4byte gWeaponHeaderPtr
_08036F08: .4byte gWeaponFnTable
_08036F0C: .4byte gWeaponTileNum
_08036F10: .4byte gWeaponPalIDs
_08036F14:
	ldr r1, _08036F84 @ =gWeaponFnTable
	movs r0, #0
	strb r0, [r5, #9]
	ldr r0, [r1]
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
	ldr r0, _08036F88 @ =gWeaponTileNum
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x20]
	ldr r0, _08036F8C @ =gWeaponPalIDs
	ldrb r0, [r0, #1]
	subs r1, #3
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0xb4
	ldrb r1, [r4, #0xe]
	movs r0, #1
	bl SetWeaponElement
_08036F4A:
	adds r3, r5, #0
	adds r3, #0xb4
	str r6, [r3]
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r6, #0x54]
	ldr r1, [r7]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r7, #4]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0
	mov r1, r8
	strb r1, [r5, #0x10]
	strb r0, [r5, #0x11]
	mov r2, sb
	adds r7, r3, #0
	cmp r2, #0
	beq _08036F90
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08036F96
	.align 2, 0
_08036F84: .4byte gWeaponFnTable
_08036F88: .4byte gWeaponTileNum
_08036F8C: .4byte gWeaponPalIDs
_08036F90:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08036F96:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	mov r3, sl
	adds r6, r2, #0
	cmp r3, #0
	beq _08036FC4
	ldrb r0, [r5, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _08036FCA
_08036FC4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
_08036FCA:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r3
	adds r0, r5, #0
	adds r0, #0x4d
	strb r1, [r0]
	lsls r1, r1, #5
	ldrb r2, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r4, #0xe]
	strb r0, [r7, #0xd]
_08036FE8:
	adds r0, r5, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
