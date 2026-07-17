	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080726ac
FUN_080726ac: @ 0x080726AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080726D0
	cmp r0, #1
	bgt _080726C0
	cmp r0, #0
	beq _080726C6
	b _080727F8
_080726C0:
	cmp r0, #2
	beq _080726EE
	b _080727F8
_080726C6:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080726D0:
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08072748 @ =sCollisions
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080726EE:
	ldr r2, [r4, #0x5c]
	rsbs r0, r2, #0
	movs r3, #0xb
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	rsbs r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl FUN_08073610
	ldr r0, _0807274C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08072750
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08072772
	.align 2, 0
_08072748: .4byte sCollisions
_0807274C: .4byte pZero2
_08072750:
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08072772:
	ldrb r0, [r4, #0x13]
	adds r1, r0, #1
	strb r1, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x1c
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08072790
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080733b4
_08072790:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r1, r4, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	bne _080727AA
	adds r0, r4, #0
	bl FUN_080735ac
	adds r5, r0, #0
	b _080727B0
_080727AA:
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
_080727B0:
	cmp r5, #2
	bne _080727BC
	movs r0, #0
	strb r5, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _080727DE
_080727BC:
	cmp r5, #1
	bne _080727D4
	adds r0, r4, #0
	bl FUN_08073500
	adds r2, r4, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	strb r5, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080727DE
_080727D4:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080727E4
	subs r0, #1
	strb r0, [r4, #0x12]
_080727DE:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080727F8
_080727E4:
	adds r0, r4, #0
	bl FUN_08073500
	adds r2, r4, #0
	adds r2, #0xb9
	movs r1, #0
	strb r0, [r2]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080727F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

