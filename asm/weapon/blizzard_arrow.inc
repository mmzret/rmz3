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
	bl AllocEntityFirst
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
	ldr r0, _0803B9C8 @ =0x08361624
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
	ldr r6, _0803B9CC @ =0x083615E0
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
_0803B9C8: .4byte 0x08361624
_0803B9CC: .4byte 0x083615E0
_0803B9D0: .4byte hitBlizzardArrow

	thumb_func_start BlizzardArrow_Update
BlizzardArrow_Update: @ 0x0803B9D4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0803BACC
	ldrb r4, [r6, #0xd]
	cmp r4, #1
	beq _0803BA28
	cmp r4, #1
	bgt _0803B9EE
	cmp r4, #0
	beq _0803B9FC
	b _0803BD32
_0803B9EE:
	cmp r4, #2
	bne _0803B9F4
	b _0803BAF0
_0803B9F4:
	cmp r4, #3
	bne _0803B9FA
	b _0803BCB8
_0803B9FA:
	b _0803BD32
_0803B9FC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r1, [r6, #0x60]
	ldr r0, [r6, #0x68]
	adds r1, r1, r0
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x58]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0803BA20
	b _0803BD32
_0803BA20:
	str r4, [r6, #0x5c]
	movs r0, #0x80
	str r0, [r6, #0x64]
	b _0803BAAC
_0803BA28:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803BA4C
	ldr r1, [r6, #0x5c]
	ldr r0, _0803BA48 @ =0x000006FF
	cmp r1, r0
	bgt _0803BA5A
	ldr r0, [r6, #0x64]
	adds r0, r1, r0
	b _0803BA58
	.align 2, 0
_0803BA48: .4byte 0x000006FF
_0803BA4C:
	ldr r1, [r6, #0x5c]
	ldr r0, _0803BAB4 @ =0xFFFFF900
	cmp r1, r0
	ble _0803BA5A
	ldr r0, [r6, #0x64]
	subs r0, r1, r0
_0803BA58:
	str r0, [r6, #0x5c]
_0803BA5A:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803BA84
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803BA7C
	movs r1, #0
_0803BA7C:
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _0803BAAC
_0803BA84:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0803BAB8
	adds r0, r6, #0
	adds r0, #0x54
	ldrb r2, [r6, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #6
	bl CreateParticle
	movs r0, #0x2b
	bl PlaySound
_0803BAAC:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _0803BD32
	.align 2, 0
_0803BAB4: .4byte 0xFFFFF900
_0803BAB8:
	ldr r0, _0803BAE8 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	bhi _0803BACC
	b _0803BD32
_0803BACC:
	ldr r1, _0803BAEC @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl BlizzardArrow_Die
	b _0803BD32
	.align 2, 0
_0803BAE8: .4byte gStageRun+232
_0803BAEC: .4byte gWeaponFnTable
_0803BAF0:
	ldr r2, _0803BB18 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0803BB1C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803BB20 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803BB28
	ldr r1, _0803BB24 @ =0x00005203
	adds r0, r6, #0
	bl SetMotion
	b _0803BB30
	.align 2, 0
_0803BB18: .4byte RNG_0202f388
_0803BB1C: .4byte 0x000343FD
_0803BB20: .4byte 0x00269EC3
_0803BB24: .4byte 0x00005203
_0803BB28:
	ldr r1, _0803BB9C @ =0x00005204
	adds r0, r6, #0
	bl SetMotion
_0803BB30:
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r2, r6, #0
	adds r2, #0xb4
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, #8
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803BBB0
	ldr r2, _0803BBA0 @ =RNG_0202f388
	ldr r0, [r2]
	ldr r5, _0803BBA4 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _0803BBA8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _0803BBAC @ =0x000001FF
	ands r0, r4
	adds r0, #0x80
	rsbs r0, r0, #0
	str r0, [r6, #0x5c]
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r0, #0x80
	rsbs r0, r0, #0
	b _0803BBDC
	.align 2, 0
_0803BB9C: .4byte 0x00005204
_0803BBA0: .4byte RNG_0202f388
_0803BBA4: .4byte 0x000343FD
_0803BBA8: .4byte 0x00269EC3
_0803BBAC: .4byte 0x000001FF
_0803BBB0:
	ldr r2, _0803BC34 @ =RNG_0202f388
	ldr r0, [r2]
	ldr r5, _0803BC38 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _0803BC3C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _0803BC40 @ =0x000001FF
	ands r0, r4
	adds r0, #0x80
	str r0, [r6, #0x5c]
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r0, #0x80
_0803BBDC:
	str r0, [r6, #0x64]
	adds r5, r2, #0
	ldr r0, [r5]
	ldr r3, _0803BC38 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _0803BC3C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r4, #0xf
	ands r0, r4
	adds r0, #8
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r4
	adds r0, #8
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x68]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r2, r0, #0x11
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0803BC44
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803BC4A
	.align 2, 0
_0803BC34: .4byte RNG_0202f388
_0803BC38: .4byte 0x000343FD
_0803BC3C: .4byte 0x00269EC3
_0803BC40: .4byte 0x000001FF
_0803BC44:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803BC4A:
	strb r0, [r6, #0xa]
	movs r4, #1
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, [r5]
	ldr r0, _0803BC88 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0803BC8C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r2, r0, #0x11
	ands r2, r4
	cmp r2, #0
	beq _0803BC90
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _0803BC96
	.align 2, 0
_0803BC88: .4byte 0x000343FD
_0803BC8C: .4byte 0x00269EC3
_0803BC90:
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
_0803BC96:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r2, r6, #0
	adds r2, #0x4d
	strb r1, [r2]
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x40
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_0803BCB8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r2, r6, #0
	adds r2, #0xb4
	ldr r0, [r2]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r2, #4]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #0xc]
	ldr r1, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r2, #0xc]
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x68]
	adds r0, #0x40
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0x12]
	subs r1, r0, #1
	strb r1, [r6, #0x12]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803BD1A
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0803BD0C
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	b _0803BD32
_0803BD0C:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	b _0803BD32
_0803BD1A:
	ldr r1, _0803BD38 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl BlizzardArrow_Die
_0803BD32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803BD38: .4byte gWeaponFnTable

	thumb_func_start BlizzardArrow_Die
BlizzardArrow_Die: @ 0x0803BD3C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803BD58 @ =gWeaponFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0803BD58: .4byte gWeaponFnTable

	thumb_func_start hitBlizzardArrow
hitBlizzardArrow: @ 0x0803BD5C
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803BD92
	ldr r4, [r2, #0x2c]
	ldr r3, _0803BD98 @ =gMission
	ldrh r1, [r3, #0x1c]
	ldr r0, _0803BD9C @ =0x0000FFFE
	cmp r1, r0
	bhi _0803BD7A
	adds r0, r1, #1
	strh r0, [r3, #0x1c]
_0803BD7A:
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BD8E
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0803BD92
_0803BD8E:
	movs r0, #1
	strb r0, [r4, #0x13]
_0803BD92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803BD98: .4byte gMission
_0803BD9C: .4byte 0x0000FFFE
