	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Fefnir_Update
Fefnir_Update: @ 0x080346B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _080346D4
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	beq _080346D4
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080346D4:
	ldr r1, _08034718 @ =0x0835E9E8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0803471C @ =0x0835E9F8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r4, #0x54]
	ldr r1, _08034720 @ =0x00267C00
	cmp r0, r1
	bgt _08034702
	str r1, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_08034702:
	ldr r1, [r4, #0x54]
	ldr r0, _08034724 @ =0x002753FF
	cmp r1, r0
	ble _08034712
	adds r0, #1
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x5c]
_08034712:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034718: .4byte 0x0835E9E8
_0803471C: .4byte 0x0835E9F8
_08034720: .4byte 0x00267C00
_08034724: .4byte 0x002753FF

	thumb_func_start Fefnir_Die
Fefnir_Die: @ 0x08034728
	ldr r2, _0803473C @ =gZeroFnTable
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
_0803473C: .4byte gZeroFnTable

	thumb_func_start nop_08034740
nop_08034740: @ 0x08034740
	bx lr
	.align 2, 0

	thumb_func_start FUN_08034744
FUN_08034744: @ 0x08034744
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrh r1, [r3, #0x18]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0803475C
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803475C:
	ldrh r1, [r3, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803476E
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803476E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08034774
FUN_08034774: @ 0x08034774
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrh r0, [r3, #0x18]
	movs r1, #0x30
	ands r1, r0
	cmp r1, #0
	bne _08034788
	strb r1, [r2, #0xd]
	strb r1, [r2, #0xe]
_08034788:
	ldrh r1, [r3, #0x1a]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803479A
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803479A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080347a0
FUN_080347a0: @ 0x080347A0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _080347B0
	cmp r1, #1
	beq _080347DE
	b _080347E4
_080347B0:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080347EC @ =0x0000A117
	adds r0, r4, #0
	movs r2, #9
	movs r3, #4
	bl GotoMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080347DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080347E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080347EC: .4byte 0x0000A117

	thumb_func_start fefnir_080347f0
fefnir_080347f0: @ 0x080347F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08034802
	cmp r5, #1
	beq _08034828
	b _080348B6
_08034802:
	adds r0, r4, #0
	adds r0, #0x54
	ldrh r2, [r6, #0x18]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	ldr r1, _0803487C @ =0x0000A10C
	adds r0, r4, #0
	movs r2, #4
	movs r3, #4
	bl GotoMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08034828:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803484C
	adds r0, r4, #0
	adds r0, #0x54
	ldrh r2, [r6, #0x18]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	bl CreateParticle
_0803484C:
	ldrh r1, [r6, #0x18]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08034884
	ldr r0, [r4, #0x54]
	ldr r1, _08034880 @ =0xFFFFFD00
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	b _080348AE
	.align 2, 0
_0803487C: .4byte 0x0000A10C
_08034880: .4byte 0xFFFFFD00
_08034884:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080348B0
	ldr r0, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0xa]
	orrs r0, r1
_080348AE:
	strb r0, [r4, #0xa]
_080348B0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080348B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start fefnir_080348bc
fefnir_080348bc: @ 0x080348BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080348CC
	cmp r5, #1
	beq _0803494A
	b _08034962
_080348CC:
	movs r0, #0xf5
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08034918
	ldr r1, _08034910 @ =0x0000A119
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08034914 @ =0xFFFFB400
	adds r1, r1, r2
	bl CreateWeapon6
	b _08034930
	.align 2, 0
_08034910: .4byte 0x0000A119
_08034914: .4byte 0xFFFFB400
_08034918:
	ldr r1, _08034968 @ =0x0000A118
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, _0803496C @ =0xFFFFF700
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08034970 @ =0xFFFFB400
	adds r1, r1, r2
	bl CreateWeapon6
_08034930:
	ldrb r1, [r4, #0x13]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803494A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08034962
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08034962:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034968: .4byte 0x0000A118
_0803496C: .4byte 0xFFFFF700
_08034970: .4byte 0xFFFFB400

	thumb_func_start fefnir_08034974
fefnir_08034974: @ 0x08034974
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08034984
	cmp r0, #1
	beq _08034998
	b _0803499E
_08034984:
	movs r0, #0xf4
	bl PlaySound
	ldr r1, _080349A4 @ =0x0000A11B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08034998:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0803499E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080349A4: .4byte 0x0000A11B
