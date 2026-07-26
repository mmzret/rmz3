	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a9158
FUN_080a9158: @ 0x080A9158
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A91A0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb8
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A91A4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A91AA
	.align 2, 0
_080A91A0: .4byte gProjectileFnTable
_080A91A4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A91AA:
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
	beq _080A91EC
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A91E8 @ =0x0000FFE0
	b _080A91FE
	.align 2, 0
_080A91E8: .4byte 0x0000FFE0
_080A91EC:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9240 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A9244 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x20
_080A91FE:
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xbe
	movs r5, #0
	strh r5, [r0]
	ldr r0, [r6, #0x58]
	ldr r1, _080A9248 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	str r5, [r6, #0x60]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A924C @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl Projectile27_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9240: .4byte 0xFFFFF000
_080A9244: .4byte 0xFFFFFD00
_080A9248: .4byte 0xFFFFE800
_080A924C: .4byte sCollisions

	thumb_func_start FUN_080a9250
FUN_080a9250: @ 0x080A9250
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A9298 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r1, #0xb8
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A929C
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A92A2
	.align 2, 0
_080A9298: .4byte gProjectileFnTable
_080A929C:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A92A2:
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
	beq _080A92E8
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	ldr r0, _080A92E4 @ =0x0000FFE0
	b _080A9300
	.align 2, 0
_080A92E4: .4byte 0x0000FFE0
_080A92E8:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9344 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A9348 @ =0xFFFFFD00
	str r0, [r6, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #0x20
_080A9300:
	strh r0, [r1]
	ldr r0, [r6, #0x58]
	ldr r1, _080A934C @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	ldr r0, _080A9350 @ =0x0000FFE0
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A9354 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xff
	strb r0, [r6, #0x12]
	adds r0, r6, #0
	bl Projectile27_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9344: .4byte 0xFFFFF000
_080A9348: .4byte 0xFFFFFD00
_080A934C: .4byte 0xFFFFEE00
_080A9350: .4byte 0x0000FFE0
_080A9354: .4byte sCollisions

	thumb_func_start FUN_080a9358
FUN_080a9358: @ 0x080A9358
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080A93B4
	cmp r0, #1
	bgt _080A9370
	cmp r0, #0
	beq _080A9376
	b _080A9442
_080A9370:
	cmp r0, #2
	beq _080A9400
	b _080A9442
_080A9376:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0xbe
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r1, r0
	str r1, [r4, #0x60]
	cmp r2, #0
	bge _080A93A4
	rsbs r2, r2, #0
_080A93A4:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A9442
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080A9442
_080A93B4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x58]
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r2, r0
	ldr r0, _080A93D8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	subs r1, r1, r0
	asrs r1, r1, #9
	cmp r1, #0
	ble _080A93DC
	adds r0, r2, #0
	subs r0, #0x40
	b _080A93E4
	.align 2, 0
_080A93D8: .4byte pZero2
_080A93DC:
	cmp r1, #0
	bge _080A93E6
	adds r0, r2, #0
	adds r0, #0x40
_080A93E4:
	str r0, [r4, #0x58]
_080A93E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9442
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0x40
	strb r0, [r4, #0x12]
	b _080A9442
_080A9400:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r1, [r4, #0x12]
	movs r0, #3
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #1
	bls _080A941C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080A9422
_080A941C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080A9422:
	strb r0, [r4, #0xa]
	subs r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9442
	ldr r1, _080A9468 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9442:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9462
	ldr r1, _080A9468 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9462:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A9468: .4byte gProjectileFnTable

	thumb_func_start FUN_080a946c
FUN_080a946c: @ 0x080A946C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080A94AC @ =gProjectileFnTable
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
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A94B0 @ =0x00005C01
	adds r0, r6, #0
	bl SetMotion
	ldrb r2, [r6, #0x11]
	cmp r2, #0
	beq _080A94B4
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A94BA
	.align 2, 0
_080A94AC: .4byte gProjectileFnTable
_080A94B0: .4byte 0x00005C01
_080A94B4:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A94BA:
	strb r0, [r6, #0xa]
	movs r1, #1
	ands r1, r2
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
	beq _080A94F8
	ldr r0, [r6, #0x54]
	ldr r1, _080A94F0 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A94F4 @ =0xFFFFFF00
	b _080A9506
	.align 2, 0
_080A94F0: .4byte 0xFFFFF000
_080A94F4: .4byte 0xFFFFFF00
_080A94F8:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #1
_080A9506:
	str r0, [r6, #0x5c]
	movs r5, #0
	strb r5, [r6, #0x12]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A9538 @ =0x0836C138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl Projectile27_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9538: .4byte sCollisions+(2*24)

	thumb_func_start FUN_080a953c
FUN_080a953c: @ 0x080A953C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080A9586
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _080A9558
	ldr r0, [r6, #0x54]
	ldr r1, _080A9554 @ =0xFFFFE000
	b _080A955E
	.align 2, 0
_080A9554: .4byte 0xFFFFE000
_080A9558:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
_080A955E:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r5, #0
	strb r5, [r6, #0xe]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A95F8 @ =0x0836C138
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	strb r5, [r6, #0x12]
_080A9586:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bne _080A95C2
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A95FC @ =0x0836C168
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
_080A95C2:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A95D2
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080A95D2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A95F2
	ldr r1, _080A9600 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_080A95F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A95F8: .4byte sCollisions+(2*24)
_080A95FC: .4byte sCollisions+(4*24)
_080A9600: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9604
FUN_080a9604: @ 0x080A9604
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A964C @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A9650 @ =0x00005C02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A9654
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A965A
	.align 2, 0
_080A964C: .4byte gProjectileFnTable
_080A9650: .4byte 0x00005C02
_080A9654:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A965A:
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
	beq _080A9690
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #0x80
	lsls r0, r0, #3
	b _080A969A
_080A9690:
	ldr r0, [r6, #0x54]
	ldr r1, _080A96E8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _080A96EC @ =0xFFFFFC00
_080A969A:
	str r0, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0x24
	movs r5, #0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r1, [r6, #0x58]
	ldr r0, _080A96F0 @ =0xFFFFE800
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	str r5, [r6, #0x60]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A96F4 @ =0x0836C198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl Projectile27_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A96E8: .4byte 0xFFFFF000
_080A96EC: .4byte 0xFFFFFC00
_080A96F0: .4byte 0xFFFFE800
_080A96F4: .4byte sCollisions+(6*24)

	thumb_func_start FUN_080a96f8
FUN_080a96f8: @ 0x080A96F8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x28]
	ldr r1, _080A9740 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #1
	str r4, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitRotatableMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080A9744 @ =0x00005C02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	ands r2, r4
	cmp r2, #0
	beq _080A9748
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080A974E
	.align 2, 0
_080A9740: .4byte gProjectileFnTable
_080A9744: .4byte 0x00005C02
_080A9748:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080A974E:
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
	beq _080A9794
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A9790 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0xc0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0x40
	b _080A97AE
	.align 2, 0
_080A9790: .4byte gSineTable
_080A9794:
	ldr r0, [r6, #0x54]
	ldr r1, _080A9800 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, _080A9804 @ =gSineTable
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x5c]
	adds r1, #0xc0
_080A97AE:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	adds r1, r6, #0
	adds r1, #0x24
	movs r5, #0
	movs r0, #0xa0
	strb r0, [r1]
	ldr r1, [r6, #0x58]
	ldr r0, _080A9808 @ =0xFFFFEE00
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x54]
	bl FUN_08009f6c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A980C @ =0x0836C198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	bl Projectile27_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9800: .4byte 0xFFFFF000
_080A9804: .4byte gSineTable
_080A9808: .4byte 0xFFFFEE00
_080A980C: .4byte sCollisions+(6*24)

	thumb_func_start FUN_080a9810
FUN_080a9810: @ 0x080A9810
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0x12]
	adds r0, r1, #1
	strb r0, [r4, #0x12]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9840
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	bl FUN_080a90a0
_080A9840:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A9916
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	bgt _080A988E
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x2b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x15
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xea
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xd4
	bl FUN_080a90a0
	b _080A98FE
_080A988E:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A98CC
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xeb
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xd5
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xc0
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xab
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x95
	bl FUN_080a90a0
	b _080A98FE
_080A98CC:
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x6b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x55
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x40
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x2b
	bl FUN_080a90a0
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x15
	bl FUN_080a90a0
_080A98FE:
	movs r0, #0x3f
	bl PlaySound
	ldr r1, _080A991C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080A9916:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A991C: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9920
FUN_080a9920: @ 0x080A9920
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080A99C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitRotatableMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A99C8 @ =0x00005C03
	adds r0, r4, #0
	bl SetMotion
	movs r6, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r3, _080A99CC @ =gSineTable
	ldrb r2, [r4, #0x11]
	adds r1, r2, #0
	adds r1, #0xc0
	lsls r0, r2, #1
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #2
	str r0, [r4, #0x60]
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080A99D0 @ =0x0836C1C8
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x40
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	adds r0, r4, #0
	bl Projectile27_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A99C4: .4byte gProjectileFnTable
_080A99C8: .4byte 0x00005C03
_080A99CC: .4byte gSineTable
_080A99D0: .4byte sCollisions+(8*24)
