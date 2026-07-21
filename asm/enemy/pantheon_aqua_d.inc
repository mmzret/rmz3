	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08072804
FUN_08072804: @ 0x08072804
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #0
	beq _08072814
	cmp r4, #1
	beq _08072900
	b _080729E2
_08072814:
	ldr r1, _08072880 @ =0x00002701
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x40
	strb r0, [r7, #0x12]
	strb r4, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _08072884 @ =sCollisions
	bl SetDDP
	ldr r0, _08072888 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r2, r2, r0
	adds r5, r2, #0
	ldr r0, [r7, #0x58]
	ldr r3, _0807288C @ =0xFFFFFA00
	adds r0, r0, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	adds r6, r1, #0
	cmp r2, #0
	bne _0807284C
	cmp r1, #0
	beq _08072890
_0807284C:
	asrs r0, r5, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r6, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0xe
	lsls r0, r5, #8
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r0, r6, #8
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	b _08072894
	.align 2, 0
_08072880: .4byte 0x00002701
_08072884: .4byte sCollisions
_08072888: .4byte pZero2
_0807288C: .4byte 0xFFFFFA00
_08072890:
	movs r5, #0x80
	lsls r5, r5, #1
_08072894:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x64]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x68]
	ldr r0, _080728D4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080728D8
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080728FA
	.align 2, 0
_080728D4: .4byte pZero2
_080728D8:
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080728FA:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08072900:
	ldr r0, [r7, #0x64]
	ldr r2, [r7, #0x5c]
	subs r0, r0, r2
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x60]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl FUN_08073610
	ldrb r0, [r7, #0x13]
	adds r1, r0, #1
	strb r1, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807294C
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080733b4
_0807294C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r1, r7, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	beq _08072966
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080729CC
_08072966:
	adds r0, r7, #0
	bl FUN_080735ac
	cmp r0, #2
	bne _080729CC
	ldr r0, _0807299C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _080729A0
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080729C2
	.align 2, 0
_0807299C: .4byte pZero2
_080729A0:
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080729C2:
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
	b _080729D6
_080729CC:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080729DC
	subs r0, #1
	strb r0, [r7, #0x12]
_080729D6:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080729E2
_080729DC:
	movs r0, #0
	strb r0, [r7, #0xd]
	strb r0, [r7, #0xe]
_080729E2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

