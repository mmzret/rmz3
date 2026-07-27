	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807c234
FUN_0807c234: @ 0x0807C234
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0807C240
	b _0807C46E
_0807C240:
	lsls r0, r0, #2
	ldr r1, _0807C24C @ =_0807C250
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807C24C: .4byte _0807C250
_0807C250: @ jump table
	.4byte _0807C268 @ case 0
	.4byte _0807C2A6 @ case 1
	.4byte _0807C360 @ case 2
	.4byte _0807C3FC @ case 3
	.4byte _0807C420 @ case 4
	.4byte _0807C43E @ case 5
_0807C268:
	movs r1, #0xfc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807C290 @ =sCollisions
	bl SetDDP
	ldr r0, _0807C294 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r1, _0807C298 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	cmp r0, r1
	ble _0807C29C
	movs r0, #0
	b _0807C29E
	.align 2, 0
_0807C290: .4byte sCollisions
_0807C294: .4byte pZero2
_0807C298: .4byte 0xFFFFF800
_0807C29C:
	movs r0, #1
_0807C29E:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C2A6:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0807C2D0
	ldr r1, [r4, #0x58]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r1, r3
	str r1, [r4, #0x58]
	ldr r2, _0807C2C8 @ =pZero2
	ldr r0, [r2]
	ldr r0, [r0, #0x58]
	ldr r3, _0807C2CC @ =0xFFFFF800
	adds r0, r0, r3
	cmp r0, r1
	bge _0807C2EE
	b _0807C2E6
	.align 2, 0
_0807C2C8: .4byte pZero2
_0807C2CC: .4byte 0xFFFFF800
_0807C2D0:
	ldr r1, [r4, #0x58]
	ldr r0, _0807C314 @ =0xFFFFFE80
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r2, _0807C318 @ =pZero2
	ldr r0, [r2]
	ldr r0, [r0, #0x58]
	ldr r3, _0807C31C @ =0xFFFFF800
	adds r0, r0, r3
	cmp r0, r1
	ble _0807C2EE
_0807C2E6:
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C2EE:
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C320
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807C358
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C33A
	movs r0, #0x10
	orrs r0, r2
	b _0807C33E
	.align 2, 0
_0807C314: .4byte 0xFFFFFE80
_0807C318: .4byte pZero2
_0807C31C: .4byte 0xFFFFF800
_0807C320:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807C358
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C33A
	movs r0, #0x10
	orrs r0, r2
	b _0807C33E
_0807C33A:
	movs r0, #0xef
	ands r0, r2
_0807C33E:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C358:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0807C46E
_0807C360:
	ldr r0, _0807C388 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C3B0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807C3AA
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C38C
	movs r0, #0x10
	orrs r0, r2
	b _0807C390
	.align 2, 0
_0807C388: .4byte pZero2
_0807C38C:
	movs r0, #0xef
	ands r0, r2
_0807C390:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C3AA:
	movs r0, #0xc0
	lsls r0, r0, #1
	b _0807C3EA
_0807C3B0:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807C3E8
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807C3CA
	movs r0, #0x10
	orrs r0, r2
	b _0807C3CE
_0807C3CA:
	movs r0, #0xef
	ands r0, r2
_0807C3CE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807C3E8:
	ldr r0, _0807C41C @ =0xFFFFFE80
_0807C3EA:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x64]
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C3FC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807C412
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C46E
_0807C412:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C46E
	.align 2, 0
_0807C41C: .4byte 0xFFFFFE80
_0807C420:
	ldr r1, _0807C474 @ =0x00003F01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807C478 @ =0x08367A88
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C43E:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x64]
	adds r1, r0, #0
	cmp r1, #0
	bge _0807C454
	rsbs r1, r1, #0
_0807C454:
	movs r0, #0xf0
	lsls r0, r0, #9
	cmp r1, r0
	ble _0807C468
	ldr r1, [r4, #0x60]
	adds r1, #0x80
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	subs r0, r0, r1
	str r0, [r4, #0x58]
_0807C468:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0807C46E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C474: .4byte 0x00003F01
_0807C478: .4byte sCollisions+(2*24)
