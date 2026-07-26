	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805fb24
FUN_0805fb24: @ 0x0805FB24
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x74
	ldr r1, _0805FB4C @ =sCollisions+(6*24)
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805FB50
	movs r0, #5
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080607a0
	movs r0, #4
	strb r0, [r4, #0x12]
	b _0805FB84
	.align 2, 0
_0805FB4C: .4byte sCollisions+(6*24)
_0805FB50:
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	bne _0805FB84
	adds r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _0805FB84
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
_0805FB84:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805fb8c
FUN_0805fb8c: @ 0x0805FB8C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	subs r3, r0, #1
	strb r3, [r5, #0x12]
	cmp r3, #0
	bne _0805FC04
	movs r0, #6
	strb r0, [r5, #0xf]
	ldr r2, _0805FC0C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805FC10 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0805FC14 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r6, r0, #0x11
	movs r0, #3
	ands r6, r0
	subs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	adds r0, r1, r0
	str r0, [r5, #0x64]
	movs r2, #0
	subs r0, r0, r1
	cmp r0, #0
	ble _0805FBD4
	movs r2, #1
_0805FBD4:
	lsls r0, r2, #9
	ldr r1, _0805FC18 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	strb r3, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xc4
	str r3, [r0]
	movs r4, #0
_0805FBE6:
	cmp r4, r6
	beq _0805FBF2
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0809130c
_0805FBF2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0805FBE6
	adds r0, r5, #0
	movs r1, #4
	bl FUN_0809130c
_0805FC04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805FC0C: .4byte RNG_0202f388
_0805FC10: .4byte 0x000343FD
_0805FC14: .4byte 0x00269EC3
_0805FC18: .4byte 0xFFFFFF00

	thumb_func_start FUN_0805fc1c
FUN_0805fc1c: @ 0x0805FC1C
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r2, #0x12]
	adds r0, #1
	strb r0, [r2, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0805FC3E
	ldrb r0, [r2, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FC44
_0805FC3E:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FC44:
	strb r0, [r2, #0xa]
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x5c]
	adds r1, r0, r1
	str r1, [r2, #0x54]
	ldr r0, [r2, #0x64]
	subs r3, r0, r1
	adds r4, r0, #0
	cmp r3, #0
	blt _0805FC5E
	cmp r3, #0xff
	ble _0805FC64
	b _0805FC76
_0805FC5E:
	subs r0, r1, r4
	cmp r0, #0xff
	bgt _0805FC76
_0805FC64:
	str r4, [r2, #0x54]
	movs r0, #2
	strh r0, [r2, #0xe]
	ldrb r1, [r2, #0x12]
	movs r0, #0x8d
	subs r0, r0, r1
	movs r1, #0
	strb r0, [r2, #0x13]
	strb r1, [r2, #0x12]
_0805FC76:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805fc7c
FUN_0805fc7c: @ 0x0805FC7C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0805FC96
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805FC9C
_0805FC96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805FC9C:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	movs r2, #0x10
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0805FCB6
	movs r0, #1
	str r0, [r5]
	movs r0, #5
	b _0805FD52
_0805FCB6:
	ldrb r1, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	subs r0, #0x3c
	cmp r1, r0
	ble _0805FCF4
	movs r0, #8
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805FCF0 @ =sCollisions+(8*24)
	bl SetDDP
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805FCF4
	adds r1, r4, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805FD50
	movs r0, #4
	b _0805FD52
	.align 2, 0
_0805FCF0: .4byte sCollisions+(8*24)
_0805FCF4:
	ldrb r0, [r4, #0x12]
	ldrb r1, [r4, #0x13]
	cmp r0, r1
	bls _0805FD54
	ldr r0, _0805FD14 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _0805FD1C
	ldr r0, _0805FD18 @ =0x00003FFF
	cmp r2, r0
	ble _0805FD24
	b _0805FD3C
	.align 2, 0
_0805FD14: .4byte pZero2
_0805FD18: .4byte 0x00003FFF
_0805FD1C:
	subs r1, r1, r0
	ldr r0, _0805FD38 @ =0x00003FFF
	cmp r1, r0
	bgt _0805FD3C
_0805FD24:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #1
	str r0, [r5]
	strb r0, [r4, #0xd]
	strh r2, [r4, #0xe]
	b _0805FD54
	.align 2, 0
_0805FD38: .4byte 0x00003FFF
_0805FD3C:
	adds r1, r4, #0
	adds r1, #0xc8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805FD50
	movs r0, #4
	b _0805FD52
_0805FD50:
	movs r0, #3
_0805FD52:
	strh r0, [r4, #0xe]
_0805FD54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
