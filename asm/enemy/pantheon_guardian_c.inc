	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806447c
FUN_0806447c: @ 0x0806447C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _080644A6
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08064498
	adds r0, #0x1f
_08064498:
	asrs r0, r0, #5
	str r0, [r4, #0x64]
	movs r0, #0x1f
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080644A6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r2, r1, r0
	str r2, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080644E0
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r2, #0
	bl FUN_080098a4
	movs r1, #0x80
	lsls r1, r1, #5
	ands r1, r0
	cmp r1, #0
	bne _080644EA
_080644E0:
	movs r0, #3
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080644F4
_080644EA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
_080644F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080644fc
FUN_080644fc: @ 0x080644FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _080645F6
	ldr r1, _0806456C @ =0x00001404
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _08064570 @ =pZero2
	ldr r2, [r4]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	ldr r2, _08064574 @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _08064578
	ldr r0, [r5, #0x5c]
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08064592
	.align 2, 0
_0806456C: .4byte 0x00001404
_08064570: .4byte pZero2
_08064574: .4byte 0xFFFFE800
_08064578:
	ldr r0, [r4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806458A
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0806458C
_0806458A:
	ldr r0, _080645B8 @ =0xFFFFFA00
_0806458C:
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
_08064592:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080645BC
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080645DE
	.align 2, 0
_080645B8: .4byte 0xFFFFFA00
_080645BC:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080645DE:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08064650 @ =sCollisions+(24*6)
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080645F6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	adds r2, #0x40
	str r2, [r5, #0x60]
	adds r0, r0, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08064632
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08064654 @ =0xFFFFE800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806464A
_08064632:
	ldr r1, _08064658 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl PantheonGuardian_Die
_0806464A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064650: .4byte sCollisions+(24*6)
_08064654: .4byte 0xFFFFE800
_08064658: .4byte gEnemyFnTable

