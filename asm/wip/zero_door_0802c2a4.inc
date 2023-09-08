	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _0802C314
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetMotion
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	ble _0802C2F0
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
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _0802C2EC @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	b _0802C30C
	.align 2, 0
_0802C2EC: .4byte 0xFFFFFE00
_0802C2F0:
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
	str r5, [r4, #0x5c]
_0802C30C:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _0802C346
_0802C314:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802C336
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r2, r0
	ble _0802C346
	str r0, [r4, #0x54]
	b _0802C34A
_0802C336:
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r2, r0
	bge _0802C346
	str r0, [r4, #0x54]
	movs r6, #1
_0802C346:
	cmp r6, #0
	beq _0802C35C
_0802C34A:
	movs r1, #0xd8
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xe]
	strb r1, [r4, #0xf]
_0802C35C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
