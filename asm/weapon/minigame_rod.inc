	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Weapon16_Die
Weapon16_Die: @ 0x0803CF48
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0803CF80 @ =gWeaponFnTable
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
_0803CF80: .4byte gWeaponFnTable

	thumb_func_start weapon_0803cf84
weapon_0803cf84: @ 0x0803CF84
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _0803CF94
	cmp r4, #1
	beq _0803CFC2
	b _0803D086
_0803CF94:
	ldr r1, _0803CFE8 @ =0x083618E8
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0803CFC2:
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x11]
	cmp r0, #5
	bhi _0803CFEC
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #1
	bne _0803D02C
	b _0803CFFA
	.align 2, 0
_0803CFE8: .4byte 0x083618E8
_0803CFEC:
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #2
	bne _0803D02C
_0803CFFA:
	ldrb r0, [r5, #0x12]
	adds r6, r0, #0
	cmp r6, #0
	bne _0803D02C
	adds r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0803D03C @ =0x083618FC
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0803D02C:
	ldrb r0, [r5, #0x11]
	cmp r0, #5
	bhi _0803D040
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #4
	bne _0803D06A
	b _0803D048
	.align 2, 0
_0803D03C: .4byte 0x083618FC
_0803D040:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #5
	bne _0803D06A
_0803D048:
	ldrb r0, [r5, #0x12]
	cmp r0, #1
	bne _0803D06A
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
_0803D06A:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803D086
	ldr r1, _0803D08C @ =gWeaponFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0803D086:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D08C: .4byte gWeaponFnTable
