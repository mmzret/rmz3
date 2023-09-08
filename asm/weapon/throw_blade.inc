	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ThrowBlade_Init
ThrowBlade_Init: @ 0x0803BED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov sb, r0
	ldr r4, [r6, #0x28]
	ldr r1, _0803BF8C @ =gWeaponFnTable
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
	ldrb r1, [r6, #0xb]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0
	mov sl, r1
	strb r0, [r6, #0xb]
	movs r0, #0
	mov r1, sl
	strh r1, [r6, #0x20]
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	movs r1, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0x10]
	mov r8, r0
	cmp r0, #0
	beq _0803BF94
	adds r0, r6, #0
	movs r1, #0x1e
	bl SetMotion
	adds r0, r6, #0
	movs r1, #1
	bl ForceEntityPalette
	movs r0, #0x40
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	bl CalcSaberBonus
	adds r0, #6
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r5, _0803BF90 @ =0x08361660
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	mov r1, sl
	str r1, [r4, #0x24]
	movs r0, #0x12
	str r0, [sp]
	subs r0, #0x13
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	movs r3, #3
	bl InitWeaponBody
	b _0803BFE2
	.align 2, 0
_0803BF8C: .4byte gWeaponFnTable
_0803BF90: .4byte 0x08361660
_0803BF94:
	adds r0, r6, #0
	movs r1, #0x1d
	bl SetMotion
	movs r0, #0xd
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	bl CalcSaberBonus
	adds r0, #6
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r5, _0803BFF8 @ =0x08361630
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	mov r0, r8
	str r0, [r4, #0x24]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	movs r3, #0
	bl InitWeaponBody
_0803BFE2:
	mov r1, sb
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0803BFFC
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0803C002
	.align 2, 0
_0803BFF8: .4byte 0x08361630
_0803BFFC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0803C002:
	strb r0, [r6, #0xa]
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
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803C03A
	mov r1, sb
	ldr r0, [r1, #0x54]
	movs r1, #0x98
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0803C046
_0803C03A:
	mov r1, sb
	ldr r0, [r1, #0x54]
	ldr r1, _0803C06C @ =0xFFFFDA00
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _0803C070 @ =0xFFFFFA00
_0803C046:
	str r0, [r6, #0x5c]
	mov r1, sb
	ldr r0, [r1, #0x58]
	ldr r1, _0803C074 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r0, _0803C078 @ =zsaber_0803c0f4
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl ThrowBlade_Update
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C06C: .4byte 0xFFFFDA00
_0803C070: .4byte 0xFFFFFA00
_0803C074: .4byte 0xFFFFEC00
_0803C078: .4byte zsaber_0803c0f4

	thumb_func_start ThrowBlade_Update
ThrowBlade_Update: @ 0x0803C07C
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0803C09A
	movs r0, #0x2b
	bl PlaySound
_0803C09A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C0B0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	b _0803C0C8
_0803C0B0:
	ldr r1, _0803C0D0 @ =gWeaponFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl ThrowBlade_Die
_0803C0C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C0D0: .4byte gWeaponFnTable

	thumb_func_start ThrowBlade_Die
ThrowBlade_Die: @ 0x0803C0D4
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0803C0F0 @ =gWeaponFnTable
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
_0803C0F0: .4byte gWeaponFnTable

	thumb_func_start zsaber_0803c0f4
zsaber_0803c0f4: @ 0x0803C0F4
	push {lr}
	ldr r0, [r0, #0x14]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0803C10E
	ldr r2, _0803C114 @ =gMission
	ldrh r1, [r2, #0x1e]
	ldr r0, _0803C118 @ =0x0000FFFE
	cmp r1, r0
	bhi _0803C10E
	adds r0, r1, #1
	strh r0, [r2, #0x1e]
_0803C10E:
	pop {r0}
	bx r0
	.align 2, 0
_0803C114: .4byte gMission
_0803C118: .4byte 0x0000FFFE
