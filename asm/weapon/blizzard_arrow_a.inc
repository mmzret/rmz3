	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateBlizzardArrow
CreateBlizzardArrow: @ 0x0803B7FC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0803B84C @ =gWeaponHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	mov ip, r0
	cmp r0, #0
	beq _0803B8E2
	adds r0, r4, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B85C
	ldr r1, _0803B850 @ =gWeaponFnTable
	movs r0, #0xa
	mov r2, ip
	strb r0, [r2, #9]
	ldr r0, [r1, #0x28]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	ldrb r1, [r2, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #0xb]
	mov r1, ip
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0803B854 @ =gWeaponTileNum
	ldrh r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, _0803B858 @ =gWeaponPalIDs
	ldrb r0, [r0]
	b _0803B884
	.align 2, 0
_0803B84C: .4byte gWeaponHeaderPtr
_0803B850: .4byte gWeaponFnTable
_0803B854: .4byte gWeaponTileNum
_0803B858: .4byte gWeaponPalIDs
_0803B85C:
	ldr r1, _0803B8A0 @ =gWeaponFnTable
	movs r0, #0xa
	mov r2, ip
	strb r0, [r2, #9]
	ldr r0, [r1, #0x28]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	ldrb r1, [r2, #0xb]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #0xb]
	mov r1, ip
	adds r1, #0x25
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0803B8A4 @ =gWeaponTileNum
	ldrh r0, [r0, #2]
	strh r0, [r2, #0x20]
	ldr r0, _0803B8A8 @ =gWeaponPalIDs
	ldrb r0, [r0, #1]
_0803B884:
	subs r1, #3
	strb r0, [r1]
	mov r0, ip
	str r4, [r0, #0x28]
	adds r3, r5, #0
	cmp r3, #0
	beq _0803B8AC
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	orrs r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	b _0803B8B6
	.align 2, 0
_0803B8A0: .4byte gWeaponFnTable
_0803B8A4: .4byte gWeaponTileNum
_0803B8A8: .4byte gWeaponPalIDs
_0803B8AC:
	mov r2, ip
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
_0803B8B6:
	movs r1, #1
	ands r1, r3
	mov r0, ip
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	mov r4, ip
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	mov r2, ip
	str r0, [r2, #0x54]
	str r1, [r2, #0x58]
	strb r6, [r2, #0x10]
	strb r3, [r2, #0x11]
_0803B8E2:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start BlizzardArrow_Init
BlizzardArrow_Init: @ 0x0803B8EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	mov r8, r0
	ldr r1, _0803B940 @ =gWeaponFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0803B944 @ =0x00005202
	adds r0, r7, #0
	bl SetMotion
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803B948
	ldr r0, [r7, #0x54]
	movs r1, #0xd0
	lsls r1, r1, #4
	b _0803B94C
	.align 2, 0
_0803B940: .4byte gWeaponFnTable
_0803B944: .4byte 0x00005202
_0803B948:
	ldr r0, [r7, #0x54]
	ldr r1, _0803B9C4 @ =0xFFFFF300
_0803B94C:
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, _0803B9C8 @ =sBlizzardArrowYOffsets
	ldrb r1, [r7, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r7, #0x60]
	cmp r0, #0
	bge _0803B962
	adds r0, #7
_0803B962:
	asrs r0, r0, #3
	rsbs r0, r0, #0
	str r0, [r7, #0x68]
	movs r5, #0
	strb r5, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r6, _0803B9CC @ =sCollisions
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	mov r0, r8
	bl CalcBusterBonus
	adds r2, r0, #0
	adds r2, #4
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [sp]
	ldrb r0, [r7, #0x10]
	adds r0, #2
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	bl InitWeaponBody
	ldr r0, _0803B9D0 @ =hitBlizzardArrow
	str r0, [r4, #0x24]
	adds r0, r7, #0
	bl BlizzardArrow_Update
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B9C4: .4byte 0xFFFFF300
_0803B9C8: .4byte sBlizzardArrowYOffsets
_0803B9CC: .4byte sCollisions
_0803B9D0: .4byte hitBlizzardArrow
