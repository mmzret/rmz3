	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806e288
FUN_0806e288: @ 0x0806E288
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806E298
	cmp r0, #1
	beq _0806E330
	b _0806E3A6
_0806E298:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bls _0806E2D6
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806E2C8 @ =0x083667F4
	bl SetDDP
	ldrb r0, [r4, #0xa]
	movs r2, #0xfe
	ands r2, r0
	strb r2, [r4, #0xa]
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #5
	bne _0806E2BA
	movs r1, #1
_0806E2BA:
	adds r3, r1, #0
	cmp r3, #0
	beq _0806E2CC
	movs r1, #0x10
	adds r0, r2, #0
	orrs r0, r1
	b _0806E2D0
	.align 2, 0
_0806E2C8: .4byte sCollisions+(24*2)
_0806E2CC:
	movs r0, #0xef
	ands r0, r2
_0806E2D0:
	strb r0, [r4, #0xa]
	adds r1, r3, #0
	b _0806E306
_0806E2D6:
	ldr r1, _0806E2F8 @ =0x00001E14
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806E2E8
	movs r1, #1
_0806E2E8:
	adds r2, r1, #0
	cmp r2, #0
	beq _0806E2FC
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806E302
	.align 2, 0
_0806E2F8: .4byte 0x00001E14
_0806E2FC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806E302:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
_0806E306:
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
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806E330:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806E33C
	subs r0, #1
	strb r0, [r4, #0x12]
	b _0806E3A0
_0806E33C:
	ldr r2, _0806E35C @ =pZero2
	ldr r0, [r2]
	ldrb r0, [r0, #0xa]
	lsrs r3, r0, #4
	movs r6, #1
	ands r3, r6
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	beq _0806E360
	cmp r3, r6
	bne _0806E364
	b _0806E3A0
	.align 2, 0
_0806E35C: .4byte pZero2
_0806E360:
	cmp r3, #0
	beq _0806E3A0
_0806E364:
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r1, r1, r0
	movs r0, #0x10
	ands r0, r5
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0806E390
	cmp r1, #0
	bge _0806E3A0
	ldr r0, _0806E38C @ =0xFFFF8800
	cmp r1, r0
	ble _0806E3A0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0806E3A0
	.align 2, 0
_0806E38C: .4byte 0xFFFF8800
_0806E390:
	subs r1, #1
	ldr r0, _0806E3AC @ =0x000077FE
	cmp r1, r0
	bhi _0806E3A0
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806E3A0:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0806E3A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E3AC: .4byte 0x000077FE

	thumb_func_start FUN_0806e3b0
FUN_0806e3b0: @ 0x0806E3B0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806E3C0
	cmp r0, #1
	beq _0806E40E
	b _0806E4B6
_0806E3C0:
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r2, [r3]
	movs r0, #1
	ands r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #2
	ands r0, r1
	lsrs r0, r0, #1
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #4
	ands r0, r1
	lsrs r0, r0, #2
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #8
	ands r0, r1
	lsrs r0, r0, #3
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	subs r1, #0x19
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	subs r1, #0x20
	ands r0, r1
	subs r1, #0x40
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806E40E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0806E4B2
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r3, [r4, #0x13]
	ldr r0, [r4, #0x5c]
	cmp r0, r3
	bne _0806E470
	adds r0, r4, #0
	adds r0, #0xb4
	adds r2, r3, #7
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	lsrs r0, r2
	cmp r0, #0
	beq _0806E452
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0806e590
	b _0806E466
_0806E452:
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0806e590
_0806E466:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0806E4B6
_0806E470:
	adds r0, r4, #0
	adds r0, #0xb4
	adds r2, r3, #7
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	lsrs r0, r2
	cmp r0, #0
	beq _0806E49C
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0806e590
	b _0806E4B6
_0806E49C:
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0806e590
	b _0806E4B6
_0806E4B2:
	subs r0, #1
	strb r0, [r4, #0x12]
_0806E4B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806e4bc
FUN_0806e4bc: @ 0x0806E4BC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r5, #1
	adds r1, r2, #0
	ands r1, r5
	movs r0, #2
	ands r0, r2
	lsrs r0, r0, #1
	adds r1, r1, r0
	movs r0, #4
	ands r0, r2
	lsrs r0, r0, #2
	adds r1, r1, r0
	movs r0, #8
	ands r0, r2
	lsrs r0, r0, #3
	adds r4, r1, r0
	movs r1, #0x10
	ands r1, r2
	lsrs r1, r1, #4
	movs r0, #0x20
	ands r0, r2
	lsrs r0, r0, #5
	adds r1, r1, r0
	movs r0, #0x40
	ands r0, r2
	lsrs r0, r0, #6
	adds r1, r1, r0
	movs r0, #0x80
	ands r2, r0
	lsrs r2, r2, #7
	adds r1, r1, r2
	cmp r4, r1
	bne _0806E512
	cmp r4, #0
	beq _0806E512
	movs r0, #0
	strb r0, [r3, #0xd]
	strb r5, [r3, #0xe]
	movs r0, #0x3c
	strb r0, [r3, #0x12]
_0806E512:
	pop {r4, r5}
	pop {r0}
	bx r0
