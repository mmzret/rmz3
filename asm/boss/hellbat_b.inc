	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatMode4
hellbatMode4: @ 0x0804B904
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0804B910
	b _0804BA3A
_0804B910:
	lsls r0, r0, #2
	ldr r1, _0804B91C @ =_0804B920
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804B91C: .4byte _0804B920
_0804B920: @ jump table
	.4byte _0804B934 @ case 0
	.4byte _0804B9B0 @ case 1
	.4byte _0804B9C4 @ case 2
	.4byte _0804B9D8 @ case 3
	.4byte _0804BA10 @ case 4
_0804B934:
	ldr r0, _0804B964 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0804B968
	movs r0, #0x80
	lsls r0, r0, #8
	adds r3, r1, r0
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
	orrs r1, r0
	strb r1, [r4, #0xa]
	b _0804B988
	.align 2, 0
_0804B964: .4byte pZero2
_0804B968:
	ldr r0, _0804B9BC @ =0xFFFF8000
	adds r3, r1, r0
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
	strb r0, [r4, #0xa]
_0804B988:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x54]
	subs r0, r3, r0
	movs r1, #0x3c
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, _0804B9C0 @ =0x00007E90
	movs r1, #0x3c
	bl __divsi3
	str r0, [r4, #0x60]
	movs r0, #0x3b
	strb r0, [r4, #0x12]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804B9B0:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0804BA02
	subs r0, #1
	strb r0, [r4, #0x13]
	b _0804B9FC
	.align 2, 0
_0804B9BC: .4byte 0xFFFF8000
_0804B9C0: .4byte 0x00007E90
_0804B9C4:
	ldr r1, _0804BA0C @ =0x0000A805
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804B9D8:
	ldr r2, [r4, #0x60]
	subs r2, #0x12
	str r2, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804BA02
	subs r0, #1
	strb r0, [r4, #0x12]
_0804B9FC:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804BA3A
_0804BA02:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0804BA3A
	.align 2, 0
_0804BA0C: .4byte 0x0000A805
_0804BA10:
	adds r0, r4, #0
	adds r0, #0xd0
	ldr r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _0804BA2C
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r2, r3
	cmp r1, r0
	ble _0804BA32
_0804BA2C:
	movs r1, #0
	movs r0, #5
	b _0804BA36
_0804BA32:
	movs r1, #0
	movs r0, #3
_0804BA36:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804BA3A:
	pop {r4}
	pop {r0}
	bx r0
