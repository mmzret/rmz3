	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hellbatThunderRevorb
hellbatThunderRevorb: @ 0x0804C224
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xe
	bls _0804C232
	b _0804C542
_0804C232:
	lsls r0, r0, #2
	ldr r1, _0804C23C @ =_0804C240
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804C23C: .4byte _0804C240
_0804C240: @ jump table
	.4byte _0804C27C @ case 0
	.4byte _0804C298 @ case 1
	.4byte _0804C2E0 @ case 2
	.4byte _0804C2F2 @ case 3
	.4byte _0804C310 @ case 4
	.4byte _0804C31A @ case 5
	.4byte _0804C32C @ case 6
	.4byte _0804C41C @ case 7
	.4byte _0804C422 @ case 8
	.4byte _0804C460 @ case 9
	.4byte _0804C47C @ case 10
	.4byte _0804C4AC @ case 11
	.4byte _0804C4C4 @ case 12
	.4byte _0804C514 @ case 13
	.4byte _0804C52C @ case 14
_0804C27C:
	ldr r1, _0804C2D8 @ =0x0000A802
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C2DC @ =sCollisions+(1*24)
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C298:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0804C2A8
	str r1, [r4, #0x60]
_0804C2A8:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C2CE
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C2CE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0804C542
	.align 2, 0
_0804C2D8: .4byte 0x0000A802
_0804C2DC: .4byte sCollisions+(1*24)
_0804C2E0:
	ldr r1, _0804C30C @ =0x0000A803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C2F2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0804C304
	b _0804C542
_0804C304:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C30C: .4byte 0x0000A803
_0804C310:
	movs r0, #4
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C31A:
	ldr r1, _0804C3A8 @ =0x0000A813
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C32C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C342
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C342:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	beq _0804C352
	b _0804C542
_0804C352:
	adds r0, r4, #0
	adds r0, #0x72
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0804C362
	b _0804C542
_0804C362:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C3AC @ =0x08362FE0
	bl SetDDP
	ldr r6, [r4, #0x54]
	str r6, [sp]
	ldr r5, [r4, #0x58]
	str r5, [sp, #4]
	ldr r2, _0804C3B0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0804C3B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0804C3B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _0804C3C4
	ldr r1, _0804C3BC @ =0xFFFFF800
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3C0 @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3A8: .4byte 0x0000A813
_0804C3AC: .4byte sCollisions+(6*24)
_0804C3B0: .4byte RNG_0202f388
_0804C3B4: .4byte 0x000343FD
_0804C3B8: .4byte 0x00269EC3
_0804C3BC: .4byte 0xFFFFF800
_0804C3C0: .4byte 0xFFFFD800
_0804C3C4:
	cmp r2, #1
	bne _0804C3E4
	ldr r1, _0804C3DC @ =0xFFFFE000
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3E0 @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3DC: .4byte 0xFFFFE000
_0804C3E0: .4byte 0xFFFFD800
_0804C3E4:
	ldr r1, _0804C3F8 @ =0xFFFFD000
	adds r0, r5, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0804C400
	ldr r1, _0804C3FC @ =0xFFFFD800
	b _0804C404
	.align 2, 0
_0804C3F8: .4byte 0xFFFFD000
_0804C3FC: .4byte 0xFFFFD800
_0804C400:
	movs r1, #0xa0
	lsls r1, r1, #6
_0804C404:
	adds r0, r6, r1
	str r0, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080a14dc
	movs r0, #0x87
	bl PlaySound
	b _0804C542
_0804C41C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C422:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C43A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C43A
	b _0804C542
_0804C43A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C458 @ =sCollisions+(1*24)
	bl SetDDP
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C45C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C458: .4byte sCollisions+(1*24)
_0804C45C:
	movs r0, #5
	b _0804C540
_0804C460:
	ldr r1, _0804C4A4 @ =0x0000A814
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C4A8 @ =sCollisions+(1*24)
	bl SetDDP
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C47C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804C542
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0804C49C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804C542
_0804C49C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C4A4: .4byte 0x0000A814
_0804C4A8: .4byte sCollisions+(1*24)
_0804C4AC:
	ldr r1, _0804C4F0 @ =0x0000A801
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C4F4 @ =sCollisions+(1*24)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C4C4:
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	ldr r1, _0804C4F8 @ =0xFFFFB800
	adds r5, r0, r1
	ldr r1, [r4, #0x58]
	subs r0, r5, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x58]
	subs r2, r5, r1
	cmp r2, #0
	ble _0804C500
	ldr r0, _0804C4FC @ =0x000003FF
	cmp r2, r0
	ble _0804C508
	b _0804C542
	.align 2, 0
_0804C4F0: .4byte 0x0000A801
_0804C4F4: .4byte sCollisions+(1*24)
_0804C4F8: .4byte 0xFFFFB800
_0804C4FC: .4byte 0x000003FF
_0804C500:
	subs r1, r1, r5
	ldr r0, _0804C510 @ =0x000003FF
	cmp r1, r0
	bgt _0804C542
_0804C508:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0804C540
	.align 2, 0
_0804C510: .4byte 0x000003FF
_0804C514:
	ldr r1, _0804C54C @ =0x0000A802
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0804C550 @ =sCollisions+(1*24)
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804C52C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0804C542
	movs r0, #0
	strb r1, [r4, #0xd]
_0804C540:
	strb r0, [r4, #0xe]
_0804C542:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C54C: .4byte 0x0000A802
_0804C550: .4byte sCollisions+(1*24)
