	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ReflectLaser_Init
ReflectLaser_Init: @ 0x0803AE54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0xb4
	ldr r0, [r7]
	mov r8, r0
	ldr r1, [r6, #0x28]
	mov sl, r1
	ldr r1, _0803AF48 @ =gWeaponFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0803AF4C @ =0x08361548
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl SetMotion
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0
	mov sb, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	mov r1, sb
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #0x10]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803AF1A
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r5, _0803AF50 @ =0x08361504
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	mov r0, sb
	str r0, [r4, #0x24]
	mov r0, sl
	bl CalcBusterBonus
	adds r2, r0, #0
	adds r2, #0xa
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	bl InitWeaponBody
_0803AF1A:
	mov r1, r8
	ldr r0, [r1, #0x54]
	str r0, [r7, #4]
	ldr r0, [r1, #0x58]
	str r0, [r7, #8]
	movs r0, #0
	strb r0, [r6, #0x12]
	ldrb r2, [r6, #0x10]
	cmp r2, #5
	bhi _0803AF62
	ldr r1, [r6, #0x28]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0803AF54
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r1, r6, #0
	bl CreateReflectLaser
	b _0803AF62
	.align 2, 0
_0803AF48: .4byte gWeaponFnTable
_0803AF4C: .4byte 0x08361548
_0803AF50: .4byte 0x08361504
_0803AF54:
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	mov r1, r8
	bl CreateReflectLaser
_0803AF62:
	adds r0, r6, #0
	bl ReflectLaser_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ReflectLaser_Update
ReflectLaser_Update: @ 0x0803AF78
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r6, [r5]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _0803AFC4
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
	ldr r1, _0803AFC0 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0803B002
	.align 2, 0
_0803AFC0: .4byte gWeaponFnTable
_0803AFC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803AFDE
	ldr r0, [r5, #4]
	str r0, [r4, #0x54]
	ldr r0, [r5, #8]
	str r0, [r4, #0x58]
	b _0803AFF6
_0803AFDE:
	ldr r0, [r5, #4]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r5, #8]
	ldr r1, [r6, #0x58]
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	str r1, [r4, #0x58]
_0803AFF6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r6, #0x54]
	str r1, [r0, #4]
	ldr r1, [r6, #0x58]
	str r1, [r0, #8]
_0803B002:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ReflectLaser_Die
ReflectLaser_Die: @ 0x0803B008
	adds r2, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0803B038 @ =gWeaponFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_0803B038: .4byte gWeaponFnTable
