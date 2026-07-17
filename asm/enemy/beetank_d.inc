	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807bc90
FUN_0807bc90: @ 0x0807BC90
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807BCA0
	cmp r0, #1
	beq _0807BCB4
	b _0807BD36
_0807BCA0:
	movs r1, #0xf8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807BCB4:
	ldr r0, _0807BCDC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807BCE0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807BD18
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807BCFA
	movs r0, #0x10
	orrs r0, r2
	b _0807BCFE
	.align 2, 0
_0807BCDC: .4byte pZero2
_0807BCE0:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807BD18
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807BCFA
	movs r0, #0x10
	orrs r0, r2
	b _0807BCFE
_0807BCFA:
	movs r0, #0xef
	ands r0, r2
_0807BCFE:
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
_0807BD18:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807BD2E
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807BD36
_0807BD2E:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807BD36:
	pop {r4}
	pop {r0}
	bx r0

