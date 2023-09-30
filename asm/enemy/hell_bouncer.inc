	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createHellBouncer
createHellBouncer: @ 0x0807E27C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0807E2DC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0807E2D4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0807E2E0 @ =gEnemyFnTable
	movs r1, #0x24
	strb r1, [r3, #9]
	adds r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
	str r7, [r3, #0x28]
_0807E2D4:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807E2DC: .4byte gZakoHeaderPtr
_0807E2E0: .4byte gEnemyFnTable

	thumb_func_start HellBouncer_Init
HellBouncer_Init: @ 0x0807E2E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r5, #0
	movs r1, #2
	orrs r0, r1
	movs r7, #0
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0807E34C @ =0x08367D98
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x40
	str r0, [r1]
	ldr r0, _0807E350 @ =nop_0807fd1c
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0xb]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r6, #0xb]
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	ldrb r3, [r6, #0x10]
	cmp r3, #1
	bne _0807E378
	ldrb r0, [r1, #0xa]
	lsrs r2, r0, #4
	ands r2, r3
	cmp r2, #0
	beq _0807E354
	ldrb r0, [r6, #0xa]
	orrs r0, r4
	b _0807E35A
	.align 2, 0
_0807E34C: .4byte 0x08367D98
_0807E350: .4byte nop_0807fd1c
_0807E354:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0807E35A:
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
_0807E378:
	movs r2, #0
	str r2, [r6, #0x60]
	str r2, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbc
	str r2, [r0]
	subs r0, #3
	strb r2, [r0]
	ldrb r1, [r6, #0x11]
	subs r0, #1
	strb r1, [r0]
	adds r0, #3
	strb r2, [r0]
	adds r0, #6
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldrb r3, [r6, #0x10]
	cmp r3, #1
	bne _0807E3B8
	ldr r1, _0807E3B4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	b _0807E3CE
	.align 2, 0
_0807E3B4: .4byte gEnemyFnTable
_0807E3B8:
	ldr r1, _0807E3F8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #2
	strb r0, [r6, #0xd]
_0807E3CE:
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0807E3EA
	ldr r1, _0807E3FC @ =0x0000AB1B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0807E3EA:
	adds r0, r6, #0
	bl HellBouncer_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E3F8: .4byte gEnemyFnTable
_0807E3FC: .4byte 0x0000AB1B

	thumb_func_start HellBouncer_Update
HellBouncer_Update: @ 0x0807E400
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xbb
	movs r0, #0
	strb r0, [r1]
	ldr r3, _0807E434 @ =0x0202F360
	ldr r0, [r6, #0x28]
	ldrb r1, [r0, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r3
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0807E438
	adds r0, r6, #0
	bl PaintEntityWhite
	b _0807E43E
	.align 2, 0
_0807E434: .4byte 0x0202F360
_0807E438:
	adds r0, r6, #0
	bl UpdateEntityPaletteID
_0807E43E:
	ldr r0, [r6, #0x28]
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807E452
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #0x80
	strb r0, [r1]
	b _0807E45E
_0807E452:
	adds r2, r6, #0
	adds r2, #0x94
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
_0807E45E:
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #1
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _0807E496
	adds r2, r6, #0
	adds r2, #0xb4
	adds r0, #0x18
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r2]
	subs r0, r0, r1
	adds r2, #7
	strb r0, [r2]
	ldr r1, [r6, #0x28]
	adds r0, r1, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E496
	adds r0, r1, #0
	adds r0, #0x74
	ldrb r1, [r2]
	bl CalcPutitedSpikeDamage
_0807E496:
	adds r2, r6, #0
	adds r2, #0xc2
	ldrb r0, [r2]
	cmp r0, #0
	bne _0807E4B6
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807E4BA
	movs r0, #0x3c
	strb r0, [r2]
	movs r0, #0x52
	bl PlaySound
	b _0807E4BA
_0807E4B6:
	subs r0, #1
	strb r0, [r2]
_0807E4BA:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0807E554
	ldr r1, _0807E534 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	ldr r2, _0807E538 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0807E53C @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0807E540 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	adds r5, r6, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0807E544 @ =0x0000AB28
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r5]
	ldr r2, _0807E548 @ =0x0000AB29
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r5]
	ldr r2, _0807E54C @ =0x0000AB2A
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080becf8
	ldrb r1, [r5]
	ldr r2, _0807E550 @ =0x0000AB2B
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080becf8
	adds r0, r6, #0
	bl HellBouncer_Die
	b _0807E59A
	.align 2, 0
_0807E534: .4byte gEnemyFnTable
_0807E538: .4byte RNG_0202f388
_0807E53C: .4byte 0x000343FD
_0807E540: .4byte 0x00269EC3
_0807E544: .4byte 0x0000AB28
_0807E548: .4byte 0x0000AB29
_0807E54C: .4byte 0x0000AB2A
_0807E550: .4byte 0x0000AB2B
_0807E554:
	ldr r1, _0807E578 @ =0x08367D80
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0807E57C
	ldrb r1, [r6, #0xd]
	adds r0, r6, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0807E59A
	.align 2, 0
_0807E578: .4byte 0x08367D80
_0807E57C:
	ldr r1, _0807E5A4 @ =0x08367D8C
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r1, r6, #0
	adds r1, #0xb4
	adds r0, r6, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r1]
_0807E59A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E5A4: .4byte 0x08367D8C

	thumb_func_start HellBouncer_Die
HellBouncer_Die: @ 0x0807E5A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0807E5E4 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807E5E8 @ =0x0000270E
	cmp r1, r0
	bhi _0807E5BA
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807E5BA:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807E5EC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E5E4: .4byte gMission
_0807E5E8: .4byte 0x0000270E
_0807E5EC: .4byte gEnemyFnTable

	thumb_func_start FUN_0807e5f0
FUN_0807e5f0: @ 0x0807E5F0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807e5f4
FUN_0807e5f4: @ 0x0807E5F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x19
	bls _0807E600
	b _0807EACC
_0807E600:
	lsls r0, r0, #2
	ldr r1, _0807E60C @ =_0807E610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E60C: .4byte _0807E610
_0807E610: @ jump table
	.4byte _0807E678 @ case 0
	.4byte _0807E70A @ case 1
	.4byte _0807E748 @ case 2
	.4byte _0807E81E @ case 3
	.4byte _0807E884 @ case 4
	.4byte _0807EA7A @ case 5
	.4byte _0807E8A8 @ case 6
	.4byte _0807E8BA @ case 7
	.4byte _0807EA7A @ case 8
	.4byte _0807E910 @ case 9
	.4byte _0807EAAE @ case 10
	.4byte _0807EACC @ case 11
	.4byte _0807EACC @ case 12
	.4byte _0807EACC @ case 13
	.4byte _0807EACC @ case 14
	.4byte _0807EACC @ case 15
	.4byte _0807EACC @ case 16
	.4byte _0807EACC @ case 17
	.4byte _0807EACC @ case 18
	.4byte _0807EACC @ case 19
	.4byte _0807E920 @ case 20
	.4byte _0807E9F6 @ case 21
	.4byte _0807EA5C @ case 22
	.4byte _0807EA7A @ case 23
	.4byte _0807EA9C @ case 24
	.4byte _0807EAAE @ case 25
_0807E678:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807E6C8 @ =0x0000AB1B
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E6CC @ =0x08367E40
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r2, [r0]
	cmp r2, #0
	bne _0807E6D4
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
	ldr r0, _0807E6D0 @ =0xFFFFF800
	b _0807E6FA
	.align 2, 0
_0807E6C8: .4byte 0x0000AB1B
_0807E6CC: .4byte 0x08367E40
_0807E6D0: .4byte 0xFFFFF800
_0807E6D4:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
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
	movs r0, #0x80
	lsls r0, r0, #4
_0807E6FA:
	str r0, [r5, #0x5c]
	ldr r0, _0807E744 @ =0xFFFFFC60
	str r0, [r5, #0x60]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E70A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807E732
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E732
	b _0807EACC
_0807E732:
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807E73E
	b _0807EA8A
_0807E73E:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0807EACC
	.align 2, 0
_0807E744: .4byte 0xFFFFFC60
_0807E748:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E798 @ =0x08367E10
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r0, [r5, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0807E7A4
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
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
	orrs r0, r3
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0807E79C @ =0xFFFF7400
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	ldr r1, _0807E7A0 @ =0xFFFFF000
	b _0807E7D4
	.align 2, 0
_0807E798: .4byte 0x08367E10
_0807E79C: .4byte 0xFFFF7400
_0807E7A0: .4byte 0xFFFFF000
_0807E7A4:
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
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0x8c
	lsls r2, r2, #8
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
_0807E7D4:
	adds r6, r0, r1
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0807E874 @ =0xFFFF6000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r1, _0807E878 @ =0x0000AC05
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x1e
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x1e
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x1d
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E81E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807E82E
	str r1, [r5, #0x60]
_0807E82E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0807E85C
	ldr r0, [r5, #0x28]
	ldr r2, _0807E87C @ =0xFFC70054
	adds r0, r0, r2
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807E85C
	movs r0, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807E880 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807E85C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0807E86E
	b _0807EACC
_0807E86E:
	str r0, [r5, #0x58]
	b _0807EA8A
	.align 2, 0
_0807E874: .4byte 0xFFFF6000
_0807E878: .4byte 0x0000AC05
_0807E87C: .4byte 0xFFC70054
_0807E880: .4byte 0x0000AC06
_0807E884:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E8A0 @ =0x08367DB0
	bl SetDDP
	ldr r1, _0807E8A4 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	b _0807EA74
	.align 2, 0
_0807E8A0: .4byte 0x08367DB0
_0807E8A4: .4byte 0x0000AC07
_0807E8A8:
	ldr r1, _0807E8EC @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E8BA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807E8D2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E8D2
	b _0807EACC
_0807E8D2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807E8F0
	movs r0, #0x10
	orrs r0, r2
	b _0807E8F4
	.align 2, 0
_0807E8EC: .4byte 0x0000AC09
_0807E8F0:
	movs r0, #0xef
	ands r0, r2
_0807E8F4:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _0807EACC
_0807E910:
	ldr r1, _0807E91C @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x1e
	b _0807EAA6
	.align 2, 0
_0807E91C: .4byte 0x0000AC01
_0807E920:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807E974 @ =0x08367E10
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldr r0, [r5, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0807E97C
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
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0x8c
	lsls r2, r2, #8
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	ldr r1, _0807E978 @ =0xFFFFD000
	b _0807E9AC
	.align 2, 0
_0807E974: .4byte 0x08367E10
_0807E978: .4byte 0xFFFFD000
_0807E97C:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
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
	orrs r0, r3
	strb r0, [r2]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0807EA48 @ =0xFFFF7400
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #6
_0807E9AC:
	adds r6, r0, r1
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0807EA4C @ =0xFFFF6000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r1, _0807EA50 @ =0x0000AC05
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x1e
	bl __divsi3
	str r0, [r5, #0x5c]
	movs r0, #0xe1
	lsls r0, r0, #7
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x58]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x1e
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x1d
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807E9F6:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807EA06
	str r1, [r5, #0x60]
_0807EA06:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	bne _0807EA34
	ldr r0, [r5, #0x28]
	ldr r2, _0807EA54 @ =0xFFC70054
	adds r0, r0, r2
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807EA34
	movs r0, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EA58 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807EA34:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0807EACC
	str r0, [r5, #0x58]
	b _0807EA8A
	.align 2, 0
_0807EA48: .4byte 0xFFFF7400
_0807EA4C: .4byte 0xFFFF6000
_0807EA50: .4byte 0x0000AC05
_0807EA54: .4byte 0xFFC70054
_0807EA58: .4byte 0x0000AC06
_0807EA5C:
	movs r0, #0xd3
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EA94 @ =0x08367DB0
	bl SetDDP
	ldr r1, _0807EA98 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
_0807EA74:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EA7A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807EACC
_0807EA8A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0807EACC
	.align 2, 0
_0807EA94: .4byte 0x08367DB0
_0807EA98: .4byte 0x0000AC07
_0807EA9C:
	ldr r1, _0807EAD4 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #2
_0807EAA6:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EAAE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EAC4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807EACC
_0807EAC4:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0807EACC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EAD4: .4byte 0x0000AC01

	thumb_func_start FUN_0807ead8
FUN_0807ead8: @ 0x0807EAD8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807eadc
FUN_0807eadc: @ 0x0807EADC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x2f
	bls _0807EAEA
	bl _0807F630
_0807EAEA:
	lsls r0, r0, #2
	ldr r1, _0807EAF4 @ =_0807EAF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807EAF4: .4byte _0807EAF8
_0807EAF8: @ jump table
	.4byte _0807EBB8 @ case 0
	.4byte _0807EC00 @ case 1
	.4byte _0807EC12 @ case 2
	.4byte _0807EE60 @ case 3
	.4byte _0807EC50 @ case 4
	.4byte _0807ECBA @ case 5
	.4byte _0807ECD2 @ case 6
	.4byte _0807ECF0 @ case 7
	.4byte _0807EE48 @ case 8
	.4byte _0807EE60 @ case 9
	.4byte _0807EE84 @ case 10
	.4byte _0807EEA4 @ case 11
	.4byte _0807EF04 @ case 12
	.4byte _0807EF7C @ case 13
	.4byte _0807F044 @ case 14
	.4byte _0807F04E @ case 15
	.4byte _0807F064 @ case 16
	.4byte _0807F09C @ case 17
	.4byte _0807F0D8 @ case 18
	.4byte _0807F0F6 @ case 19
	.4byte _0807F114 @ case 20
	.4byte _0807F126 @ case 21
	.4byte _0807F148 @ case 22
	.4byte _0807F1BE @ case 23
	.4byte _0807F1D0 @ case 24
	.4byte _0807F208 @ case 25
	.4byte _0807F630 @ case 26
	.4byte _0807F630 @ case 27
	.4byte _0807F630 @ case 28
	.4byte _0807F630 @ case 29
	.4byte _0807F220 @ case 30
	.4byte _0807F22E @ case 31
	.4byte _0807F248 @ case 32
	.4byte _0807F2A0 @ case 33
	.4byte _0807F360 @ case 34
	.4byte _0807F378 @ case 35
	.4byte _0807F394 @ case 36
	.4byte _0807F3BE @ case 37
	.4byte _0807F3D0 @ case 38
	.4byte _0807F424 @ case 39
	.4byte _0807F43C @ case 40
	.4byte _0807F452 @ case 41
	.4byte _0807F46C @ case 42
	.4byte _0807F492 @ case 43
	.4byte _0807F4B4 @ case 44
	.4byte _0807F4CA @ case 45
	.4byte _0807F52C @ case 46
	.4byte _0807F5F0 @ case 47
_0807EBB8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EBE0 @ =0x08367DB0
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EBE8
	ldr r0, _0807EBE4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0807EBDC
	bl _0807F516
_0807EBDC:
	b _0807EE74
	.align 2, 0
_0807EBE0: .4byte 0x08367DB0
_0807EBE4: .4byte pZero2
_0807EBE8:
	ldr r0, _0807EBFC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0807EBF8
	bl _0807F516
_0807EBF8:
	b _0807EE74
	.align 2, 0
_0807EBFC: .4byte pZero2
_0807EC00:
	ldr r1, _0807EC4C @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EC12:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EC2C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807EC2C
	bl _0807F630
_0807EC2C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	bne _0807EC42
	bl _0807F404
_0807EC42:
	movs r0, #0x10
	orrs r0, r2
	bl _0807F408
	.align 2, 0
_0807EC4C: .4byte 0x0000AC09
_0807EC50:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EC68
	ldr r0, [r5, #0x54]
	ldr r1, _0807EC64 @ =0xFFFF6000
	adds r4, r0, r1
	b _0807EC70
	.align 2, 0
_0807EC64: .4byte 0xFFFF6000
_0807EC68:
	ldr r0, [r5, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r4, r0, r2
_0807EC70:
	ldr r1, _0807EC84 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807EC88
	movs r0, #0x1c
	b _0807EC8A
	.align 2, 0
_0807EC84: .4byte 0x0000AC02
_0807EC88:
	movs r0, #0x28
_0807EC8A:
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r4, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	muls r0, r1, r0
	lsls r0, r0, #6
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807ECBA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807ECCE
	bl _0807F630
_0807ECCE:
	bl _0807F516
_0807ECD2:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807ED2C @ =0x08367DE0
	bl SetDDP
	ldr r1, _0807ED30 @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807ECF0:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807ED00
	str r1, [r5, #0x60]
_0807ED00:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r3, r0, r1
	str r3, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _0807ED3C
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807ED34 @ =0xFFFFEE00
	adds r0, r0, r4
	cmp r3, r0
	bge _0807ED3C
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807ED38 @ =0x0000AC04
	b _0807ED54
	.align 2, 0
_0807ED2C: .4byte 0x08367DE0
_0807ED30: .4byte 0x0000AC03
_0807ED34: .4byte 0xFFFFEE00
_0807ED38: .4byte 0x0000AC04
_0807ED3C:
	cmp r2, #1
	bne _0807ED64
	cmp r1, #0
	ble _0807ED64
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807ED5C @ =0x08367E10
	bl SetDDP
	ldr r1, _0807ED60 @ =0x0000AC05
_0807ED54:
	adds r0, r5, #0
	bl SetMotion
	b _0807ED82
	.align 2, 0
_0807ED5C: .4byte 0x08367E10
_0807ED60: .4byte 0x0000AC05
_0807ED64:
	cmp r2, #2
	bne _0807ED82
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807EDAC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0807ED82
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EDB0 @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807ED82:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EDB8
	adds r2, r1, #0
	cmp r1, #0
	bge _0807ED9E
	rsbs r2, r1, #0
_0807ED9E:
	ldr r0, _0807EDB4 @ =0x000007FF
	cmp r2, r0
	bgt _0807EDB8
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807EDAC: .4byte 0xFFFFEE00
_0807EDB0: .4byte 0x0000AC06
_0807EDB4: .4byte 0x000007FF
_0807EDB8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EE04
	ldr r0, [r5, #0x54]
	ldr r2, _0807EDE0 @ =0xFFFFEC00
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	ldr r3, _0807EDE4 @ =0xFFFFF800
	adds r1, r1, r3
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EDE8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0807EE3E
	.align 2, 0
_0807EDE0: .4byte 0xFFFFEC00
_0807EDE4: .4byte 0xFFFFF800
_0807EDE8:
	ldr r1, [r5, #0x54]
	ldr r4, _0807EE00 @ =0xFFFFEC00
	adds r1, r1, r4
	ldr r0, [r5, #0x28]
	adds r0, #0xd0
	ldr r0, [r0]
	cmp r1, r0
	blt _0807EDFC
	bl _0807F630
_0807EDFC:
	b _0807EE3E
	.align 2, 0
_0807EE00: .4byte 0xFFFFEC00
_0807EE04:
	ldr r0, [r5, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0807EE24 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0807EE28
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _0807EE3E
	.align 2, 0
_0807EE24: .4byte 0xFFFFF800
_0807EE28:
	ldr r1, [r5, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r0, [r5, #0x28]
	adds r0, #0xdc
	ldr r0, [r0]
	cmp r1, r0
	bgt _0807EE3E
	bl _0807F630
_0807EE3E:
	str r0, [r5, #0x54]
	movs r0, #0xa
	strb r0, [r5, #0xe]
	bl _0807F630
_0807EE48:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EE7C @ =0x08367DB0
	bl SetDDP
	ldr r1, _0807EE80 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EE60:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807EE74
	bl _0807F630
_0807EE74:
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807EE7C: .4byte 0x08367DB0
_0807EE80: .4byte 0x0000AC07
_0807EE84:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EED0 @ =0x08367DE0
	bl SetDDP
	ldr r1, _0807EED4 @ =0x0000AC0A
	adds r0, r5, #0
	bl SetMotion
	movs r1, #0
	movs r0, #8
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EEA4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807EEB4
	subs r0, #1
	strb r0, [r5, #0x12]
_0807EEB4:
	ldrh r0, [r5, #0x12]
	cmp r0, #0
	bne _0807EEF6
	movs r1, #1
	strb r1, [r5, #0x13]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807EED8
	movs r0, #0x10
	orrs r0, r2
	b _0807EEDC
	.align 2, 0
_0807EED0: .4byte 0x08367DE0
_0807EED4: .4byte 0x0000AC0A
_0807EED8:
	movs r0, #0xef
	ands r0, r2
_0807EEDC:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0807EEF6:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807EF02
	b _0807F630
_0807EF02:
	b _0807F516
_0807EF04:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807EF1C
	ldr r0, [r5, #0x54]
	ldr r1, _0807EF18 @ =0xFFFF6000
	adds r4, r0, r1
	b _0807EF24
	.align 2, 0
_0807EF18: .4byte 0xFFFF6000
_0807EF1C:
	ldr r0, [r5, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r4, r0, r2
_0807EF24:
	ldr r1, _0807EF3C @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807EF40
	movs r0, #0x1c
	b _0807EF42
	.align 2, 0
_0807EF3C: .4byte 0x0000AC03
_0807EF40:
	movs r0, #0x28
_0807EF42:
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r4, r0
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	adds r0, r1, #1
	asrs r0, r0, #1
	muls r0, r1, r0
	lsls r0, r0, #6
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x58]
	ldr r3, [r3, #0x58]
	subs r2, r2, r3
	subs r0, r0, r2
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r1, #0
	strb r0, [r5, #0x12]
	strb r1, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807EF7C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807EF8C
	str r1, [r5, #0x60]
_0807EF8C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r3, r0, r1
	str r3, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _0807EFC0
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807EFB8 @ =0xFFFFC000
	adds r0, r0, r4
	cmp r3, r0
	bge _0807EFC0
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807EFBC @ =0x0000AC04
	b _0807EFD8
	.align 2, 0
_0807EFB8: .4byte 0xFFFFC000
_0807EFBC: .4byte 0x0000AC04
_0807EFC0:
	cmp r2, #1
	bne _0807EFE8
	cmp r1, #0
	ble _0807EFE8
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807EFE0 @ =0x08367E10
	bl SetDDP
	ldr r1, _0807EFE4 @ =0x0000AC05
_0807EFD8:
	adds r0, r5, #0
	bl SetMotion
	b _0807F006
	.align 2, 0
_0807EFE0: .4byte 0x08367E10
_0807EFE4: .4byte 0x0000AC05
_0807EFE8:
	cmp r2, #2
	bne _0807F006
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807F038 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _0807F006
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F03C @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807F006:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0807F01C
	b _0807F630
_0807F01C:
	adds r2, r1, #0
	cmp r1, #0
	bge _0807F024
	rsbs r2, r1, #0
_0807F024:
	ldr r0, _0807F040 @ =0x000007FF
	cmp r2, r0
	ble _0807F02C
	b _0807F630
_0807F02C:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807F038: .4byte 0xFFFFE000
_0807F03C: .4byte 0x0000AC06
_0807F040: .4byte 0x000007FF
_0807F044:
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F04E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0807F056
	b _0807F516
_0807F056:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F062
	b _0807F630
_0807F062:
	b _0807F516
_0807F064:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F0C8 @ =0x08367E10
	bl SetDDP
	ldr r1, _0807F0CC @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0807F0D0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0807F0D4 @ =0xFFFF4C00
	adds r0, r0, r2
	str r0, [r5, #0x58]
	movs r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x60]
	ldr r0, [r1, #0x58]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F09C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F0AC
	str r1, [r5, #0x60]
_0807F0AC:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	cmp r0, r1
	bgt _0807F0C4
	b _0807F630
_0807F0C4:
	str r1, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807F0C8: .4byte 0x08367E10
_0807F0CC: .4byte 0x0000AC06
_0807F0D0: .4byte pZero2
_0807F0D4: .4byte 0xFFFF4C00
_0807F0D8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F10C @ =0x08367DB0
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807F110 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F0F6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F108
	b _0807F630
_0807F108:
	b _0807F516
	.align 2, 0
_0807F10C: .4byte 0x08367DB0
_0807F110: .4byte 0x0000AC07
_0807F114:
	ldr r1, _0807F144 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F126:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0807F134
	b _0807F516
_0807F134:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F140
	b _0807F630
_0807F140:
	b _0807F516
	.align 2, 0
_0807F144: .4byte 0x0000AC01
_0807F148:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F188
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r3, _0807F174 @ =0xFFFFE000
	adds r0, r0, r3
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0807F178
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
	.align 2, 0
_0807F174: .4byte 0xFFFFE000
_0807F178:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F188:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r4, #0x80
	lsls r4, r4, #6
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0807F1A8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F1A8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F1B8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _0807F1BA
_0807F1B8:
	movs r0, #0x1e
_0807F1BA:
	strb r0, [r5, #0xe]
	b _0807F436
_0807F1BE:
	ldr r1, _0807F204 @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F1D0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F1E8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F1E8
	b _0807F630
_0807F1E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	bne _0807F1FC
	b _0807F404
_0807F1FC:
	movs r0, #0x10
	orrs r0, r2
	b _0807F408
	.align 2, 0
_0807F204: .4byte 0x0000AC09
_0807F208:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F21A
	b _0807F630
_0807F21A:
	movs r0, #0x1e
	strb r0, [r5, #0xe]
	b _0807F630
_0807F220:
	ldr r1, _0807F244 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F22E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F240
	b _0807F630
_0807F240:
	b _0807F516
	.align 2, 0
_0807F244: .4byte 0x0000AC02
_0807F248:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F25C
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _0807F258 @ =0xFFFFE000
	adds r6, r0, r1
	b _0807F266
	.align 2, 0
_0807F258: .4byte 0xFFFFE000
_0807F25C:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r6, r0, r2
_0807F266:
	ldr r1, _0807F2E0 @ =0x0000AC03
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F2E4 @ =0x08367DE0
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	movs r4, #0
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	subs r0, r6, r0
	movs r1, #0x14
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r0, _0807F2E8 @ =0xFFFFFCE0
	str r0, [r5, #0x60]
	movs r0, #0x13
	strb r0, [r5, #0x12]
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F2A0:
	ldr r0, [r5, #0x60]
	adds r0, #0x50
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F2B0
	str r1, [r5, #0x60]
_0807F2B0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _0807F2F4
	ldr r0, [r5, #0x28]
	ldr r3, _0807F2EC @ =0xFFE38054
	adds r0, r0, r3
	ldr r0, [r0, #4]
	cmp r1, r0
	bge _0807F2F4
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F2F0 @ =0x0000AC04
	b _0807F312
	.align 2, 0
_0807F2E0: .4byte 0x0000AC03
_0807F2E4: .4byte 0x08367DE0
_0807F2E8: .4byte 0xFFFFFCE0
_0807F2EC: .4byte 0xFFE38054
_0807F2F0: .4byte 0x0000AC04
_0807F2F4:
	ldrb r0, [r5, #0x13]
	adds r2, r0, #0
	cmp r2, #1
	bne _0807F324
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0807F324
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F31C @ =0x08367E10
	bl SetDDP
	ldr r1, _0807F320 @ =0x0000AC05
_0807F312:
	adds r0, r5, #0
	bl SetMotion
	b _0807F342
	.align 2, 0
_0807F31C: .4byte 0x08367E10
_0807F320: .4byte 0x0000AC05
_0807F324:
	cmp r2, #2
	bne _0807F342
	ldr r0, [r5, #0x28]
	ldr r4, _0807F358 @ =0xFFE38054
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _0807F342
	adds r0, r2, #1
	strb r0, [r5, #0x13]
	ldr r1, _0807F35C @ =0x0000AC06
	adds r0, r5, #0
	bl SetMotion
_0807F342:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bge _0807F354
	b _0807F630
_0807F354:
	str r0, [r5, #0x58]
	b _0807F516
	.align 2, 0
_0807F358: .4byte 0xFFE38054
_0807F35C: .4byte 0x0000AC06
_0807F360:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F38C @ =0x08367DB0
	bl SetDDP
	ldr r1, _0807F390 @ =0x0000AC07
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F378:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F38A
	b _0807F630
_0807F38A:
	b _0807F516
	.align 2, 0
_0807F38C: .4byte 0x08367DB0
_0807F390: .4byte 0x0000AC07
_0807F394:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F3A8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807F3B6
	movs r0, #0x28
	b _0807F3BA
_0807F3A8:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807F3B6
	movs r0, #0x28
	b _0807F3BA
_0807F3B6:
	ldrb r0, [r5, #0xe]
	adds r0, #1
_0807F3BA:
	strb r0, [r5, #0xe]
	b _0807F436
_0807F3BE:
	ldr r1, _0807F400 @ =0x0000AC09
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xf
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F3D0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F3E8
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807F3E8
	b _0807F630
_0807F3E8:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807F404
	movs r0, #0x10
	orrs r0, r2
	b _0807F408
	.align 2, 0
_0807F400: .4byte 0x0000AC09
_0807F404:
	movs r0, #0xef
	ands r0, r2
_0807F408:
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _0807F630
_0807F424:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F436
	b _0807F630
_0807F436:
	movs r0, #0x28
	strb r0, [r5, #0xe]
	b _0807F630
_0807F43C:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F468 @ =0x0000AC01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F452:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807F464
	b _0807F630
_0807F464:
	b _0807F516
	.align 2, 0
_0807F468: .4byte 0x0000AC01
_0807F46C:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0807F478
	movs r0, #0xb0
	lsls r0, r0, #3
	b _0807F47A
_0807F478:
	ldr r0, _0807F4A8 @ =0xFFFFFA80
_0807F47A:
	str r0, [r5, #0x5c]
	ldr r0, _0807F4AC @ =0xFFFFF880
	str r0, [r5, #0x60]
	ldr r1, _0807F4B0 @ =0x0000AC02
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F492:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F4A4
	b _0807F630
_0807F4A4:
	b _0807F516
	.align 2, 0
_0807F4A8: .4byte 0xFFFFFA80
_0807F4AC: .4byte 0xFFFFF880
_0807F4B0: .4byte 0x0000AC02
_0807F4B4:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F520 @ =0x08367DE0
	bl SetDDP
	movs r0, #0xd3
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F4CA:
	ldr r0, [r5, #0x60]
	adds r0, #8
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F4DA
	str r1, [r5, #0x60]
_0807F4DA:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _0807F500
	ldr r0, [r5, #0x28]
	ldr r3, _0807F524 @ =0xFFD54054
	adds r0, r0, r3
	ldr r0, [r0, #4]
	cmp r1, r0
	bge _0807F500
	adds r0, r2, #1
	strb r0, [r5, #0x13]
_0807F500:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r4, _0807F528 @ =0xFFFF4C00
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	blt _0807F516
	b _0807F630
_0807F516:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0807F630
	.align 2, 0
_0807F520: .4byte 0x08367DE0
_0807F524: .4byte 0xFFD54054
_0807F528: .4byte 0xFFFF4C00
_0807F52C:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807F57C @ =0x0000AB1B
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0807F580 @ =0x08367E40
	bl SetDDP
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r2, [r5, #0x11]
	cmp r2, #0
	bne _0807F58C
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
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x54]
	ldr r3, _0807F584 @ =0xFFFF6000
	adds r0, r1, r3
	str r0, [r5, #0x54]
	ldr r4, _0807F588 @ =0xFFFF7100
	b _0807F5BE
	.align 2, 0
_0807F57C: .4byte 0x0000AB1B
_0807F580: .4byte 0x08367E40
_0807F584: .4byte 0xFFFF6000
_0807F588: .4byte 0xFFFF7100
_0807F58C:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
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
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x54]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r1, r3
	str r0, [r5, #0x54]
	movs r4, #0x8f
	lsls r4, r4, #8
_0807F5BE:
	adds r1, r1, r4
	ldr r0, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x28]
	ldr r1, [r2, #0x58]
	ldr r3, _0807F638 @ =0xFFFF6000
	adds r0, r1, r3
	str r0, [r5, #0x58]
	ldr r4, _0807F63C @ =0xFFFF8B00
	adds r1, r1, r4
	ldr r0, [r2, #0x58]
	subs r0, r0, r1
	str r0, [r5, #0x60]
	ldrb r1, [r5, #0x12]
	bl __divsi3
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0807F5F0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0807F616
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F630
_0807F616:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807F640 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0807F630:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807F638: .4byte 0xFFFF6000
_0807F63C: .4byte 0xFFFF8B00
_0807F640: .4byte gEnemyFnTable

	thumb_func_start FUN_0807f644
FUN_0807f644: @ 0x0807F644
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807f648
FUN_0807f648: @ 0x0807F648
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x11]
	cmp r0, #0
	beq _0807F654
	b _0807F984
_0807F654:
	ldrb r0, [r6, #0xe]
	cmp r0, #0x11
	bls _0807F65C
	b _0807FCFE
_0807F65C:
	lsls r0, r0, #2
	ldr r1, _0807F668 @ =_0807F66C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807F668: .4byte _0807F66C
_0807F66C: @ jump table
	.4byte _0807F6B4 @ case 0
	.4byte _0807F6DE @ case 1
	.4byte _0807F728 @ case 2
	.4byte _0807F748 @ case 3
	.4byte _0807F764 @ case 4
	.4byte _0807F778 @ case 5
	.4byte _0807F7B8 @ case 6
	.4byte _0807F7C6 @ case 7
	.4byte _0807F7E0 @ case 8
	.4byte _0807F7F6 @ case 9
	.4byte _0807F810 @ case 10
	.4byte _0807F826 @ case 11
	.4byte _0807F888 @ case 12
	.4byte _0807F896 @ case 13
	.4byte _0807F8B0 @ case 14
	.4byte _0807F8C8 @ case 15
	.4byte _0807F904 @ case 16
	.4byte _0807FCBE @ case 17
_0807F6B4:
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0807F720 @ =0x0000AC08
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, _0807F724 @ =0xFFFFFE00
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F6DE:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _0807F6FC
	movs r0, #0xd3
	bl PlaySound
_0807F6FC:
	ldr r0, [r6, #0x64]
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r6, #0x54]
	cmp r1, r0
	bge _0807F712
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #1
	strb r0, [r1]
_0807F712:
	ldr r0, [r6, #0x64]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r0, r2
	ldr r1, [r6, #0x54]
	b _0807FC2A
	.align 2, 0
_0807F720: .4byte 0x0000AC08
_0807F724: .4byte 0xFFFFFE00
_0807F728:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F75C @ =0x0000AC0B
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _0807F760 @ =0xFFFFFD80
	str r0, [r6, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r6, #0x5c]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F748:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F75A
	b _0807FCFE
_0807F75A:
	b _0807FC2E
	.align 2, 0
_0807F75C: .4byte 0x0000AC0B
_0807F760: .4byte 0xFFFFFD80
_0807F764:
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807F7B0 @ =0x0000AC0C
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F778:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F788
	str r1, [r6, #0x60]
_0807F788:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _0807F7B4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	bgt _0807F7AC
	b _0807FCFE
_0807F7AC:
	str r0, [r6, #0x58]
	b _0807FC2E
	.align 2, 0
_0807F7B0: .4byte 0x0000AC0C
_0807F7B4: .4byte pZero2
_0807F7B8:
	ldr r1, _0807F7DC @ =0x0000AC0D
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F7C6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F7D8
	b _0807FCFE
_0807F7D8:
	b _0807FC2E
	.align 2, 0
_0807F7DC: .4byte 0x0000AC0D
_0807F7E0:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807F80C @ =0x0000AC01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F7F6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807F808
	b _0807FCFE
_0807F808:
	b _0807FC2E
	.align 2, 0
_0807F80C: .4byte 0x0000AC01
_0807F810:
	ldr r1, _0807F858 @ =0x0000AC09
	adds r0, r6, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F826:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807F83C
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F87A
_0807F83C:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0807F87A
	movs r1, #1
	strb r1, [r6, #0x13]
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807F85C
	movs r0, #0x10
	orrs r0, r2
	b _0807F860
	.align 2, 0
_0807F858: .4byte 0x0000AC09
_0807F85C:
	movs r0, #0xef
	ands r0, r2
_0807F860:
	strb r0, [r6, #0xa]
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
_0807F87A:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F886
	b _0807FCFE
_0807F886:
	b _0807FC2E
_0807F888:
	ldr r1, _0807F8AC @ =0x0000AC02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F896:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807F8A8
	b _0807FCFE
_0807F8A8:
	b _0807FC2E
	.align 2, 0
_0807F8AC: .4byte 0x0000AC02
_0807F8B0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	ldr r0, _0807F8F8 @ =0xFFFFF900
	str r0, [r6, #0x60]
	ldr r1, _0807F8FC @ =0x0000AC03
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F8C8:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807F8D8
	str r1, [r6, #0x60]
_0807F8D8:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r3, _0807F900 @ =0xFFFF8800
	adds r0, r0, r3
	b _0807FC28
	.align 2, 0
_0807F8F8: .4byte 0xFFFFF900
_0807F8FC: .4byte 0x0000AC03
_0807F900: .4byte 0xFFFF8800
_0807F904:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807F974 @ =0x0000AB1B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807F978 @ =0x08367E40
	bl SetDDP
	movs r0, #0x20
	strb r0, [r6, #0x12]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r4, [r6, #0x28]
	ldr r1, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #8
	adds r0, r1, r2
	str r0, [r6, #0x54]
	movs r3, #0x8f
	lsls r3, r3, #8
	adds r1, r1, r3
	ldr r0, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r1, [r4, #0x58]
	ldr r2, _0807F97C @ =0xFFFF6000
	adds r0, r1, r2
	str r0, [r6, #0x58]
	ldr r3, _0807F980 @ =0xFFFF8B00
	adds r1, r1, r3
	ldr r0, [r4, #0x58]
	b _0807FCAC
	.align 2, 0
_0807F974: .4byte 0x0000AB1B
_0807F978: .4byte 0x08367E40
_0807F97C: .4byte 0xFFFF6000
_0807F980: .4byte 0xFFFF8B00
_0807F984:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xf
	bls _0807F98C
	b _0807FCFE
_0807F98C:
	lsls r0, r0, #2
	ldr r1, _0807F998 @ =_0807F99C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807F998: .4byte _0807F99C
_0807F99C: @ jump table
	.4byte _0807F9DC @ case 0
	.4byte _0807F9F2 @ case 1
	.4byte _0807FA00 @ case 2
	.4byte _0807FA76 @ case 3
	.4byte _0807FAE8 @ case 4
	.4byte _0807FAFE @ case 5
	.4byte _0807FB18 @ case 6
	.4byte _0807FB34 @ case 7
	.4byte _0807FB94 @ case 8
	.4byte _0807FBA2 @ case 9
	.4byte _0807FBBC @ case 10
	.4byte _0807FBCA @ case 11
	.4byte _0807FBE4 @ case 12
	.4byte _0807FBFA @ case 13
	.4byte _0807FC48 @ case 14
	.4byte _0807FCBE @ case 15
_0807F9DC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xc0
	strb r1, [r0]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807F9F2:
	ldr r0, [r6, #0x2c]
	adds r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807F9FE
	b _0807FCFE
_0807F9FE:
	b _0807FC2E
_0807FA00:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0807FAD8 @ =0x0000AC05
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x64]
	movs r1, #0x84
	lsls r1, r1, #8
	adds r0, r0, r1
	movs r1, #0x28
	strb r1, [r6, #0x12]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	movs r1, #0x28
	bl __divsi3
	str r0, [r6, #0x5c]
	movs r0, #0xc8
	lsls r0, r0, #8
	ldr r1, _0807FADC @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x58]
	ldr r2, [r6, #0x58]
	subs r1, r1, r2
	subs r0, r0, r1
	movs r1, #0x28
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r6, #0x60]
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FA76:
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807FA86
	str r1, [r6, #0x60]
_0807FA86:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldrb r2, [r6, #0x13]
	cmp r2, #0
	bne _0807FAB6
	ldr r0, _0807FADC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	ldr r3, _0807FAE0 @ =0xFFFFA000
	adds r0, r0, r3
	cmp r1, r0
	ble _0807FAB6
	adds r0, r2, #1
	strb r0, [r6, #0x13]
	ldr r1, _0807FAE4 @ =0x0000AC06
	adds r0, r6, #0
	bl SetMotion
_0807FAB6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FACE
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807FACE
	b _0807FCFE
_0807FACE:
	ldr r0, _0807FADC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	str r0, [r6, #0x58]
	b _0807FC2E
	.align 2, 0
_0807FAD8: .4byte 0x0000AC05
_0807FADC: .4byte pZero2
_0807FAE0: .4byte 0xFFFFA000
_0807FAE4: .4byte 0x0000AC06
_0807FAE8:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807FB14 @ =0x0000AC07
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FAFE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FB10
	b _0807FCFE
_0807FB10:
	b _0807FC2E
	.align 2, 0
_0807FB14: .4byte 0x0000AC07
_0807FB18:
	movs r0, #0xd3
	bl PlaySound
	ldr r1, _0807FB64 @ =0x0000AC09
	adds r0, r6, #0
	bl SetMotion
	movs r1, #0
	movs r0, #0xf
	strb r0, [r6, #0x12]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FB34:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FB4A
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807FB86
_0807FB4A:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	bne _0807FB86
	movs r1, #1
	strb r1, [r6, #0x13]
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _0807FB68
	movs r0, #0x10
	orrs r0, r2
	b _0807FB6C
	.align 2, 0
_0807FB64: .4byte 0x0000AC09
_0807FB68:
	movs r0, #0xef
	ands r0, r2
_0807FB6C:
	strb r0, [r6, #0xa]
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
_0807FB86:
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FB92
	b _0807FCFE
_0807FB92:
	b _0807FC2E
_0807FB94:
	ldr r1, _0807FBB8 @ =0x0000AC01
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBA2:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #2
	beq _0807FBB4
	b _0807FCFE
_0807FBB4:
	b _0807FC2E
	.align 2, 0
_0807FBB8: .4byte 0x0000AC01
_0807FBBC:
	ldr r1, _0807FBE0 @ =0x0000AC02
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBCA:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0807FBDC
	b _0807FCFE
_0807FBDC:
	b _0807FC2E
	.align 2, 0
_0807FBE0: .4byte 0x0000AC02
_0807FBE4:
	ldr r0, _0807FC38 @ =0xFFFFFA00
	str r0, [r6, #0x5c]
	ldr r0, _0807FC3C @ =0xFFFFF900
	str r0, [r6, #0x60]
	ldr r1, _0807FC40 @ =0x0000AC03
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FBFA:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807FC0A
	str r1, [r6, #0x60]
_0807FC0A:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0807FC44 @ =0xFFFF8800
	adds r0, r0, r1
_0807FC28:
	ldr r1, [r6, #0x58]
_0807FC2A:
	cmp r1, r0
	bge _0807FCFE
_0807FC2E:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _0807FCFE
	.align 2, 0
_0807FC38: .4byte 0xFFFFFA00
_0807FC3C: .4byte 0xFFFFF900
_0807FC40: .4byte 0x0000AC03
_0807FC44: .4byte 0xFFFF8800
_0807FC48:
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0807FD04 @ =0x0000AB1B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0807FD08 @ =0x08367E40
	bl SetDDP
	movs r0, #0x20
	strb r0, [r6, #0x12]
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r5, [r6, #0x28]
	ldr r1, [r5, #0x54]
	ldr r4, _0807FD0C @ =0xFFFF6000
	adds r0, r1, r4
	str r0, [r6, #0x54]
	ldr r2, _0807FD10 @ =0xFFFF7100
	adds r1, r1, r2
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x5c]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x5c]
	ldr r1, [r5, #0x58]
	adds r4, r1, r4
	str r4, [r6, #0x58]
	ldr r3, _0807FD14 @ =0xFFFF8B00
	adds r1, r1, r3
	ldr r0, [r5, #0x58]
_0807FCAC:
	subs r0, r0, r1
	str r0, [r6, #0x60]
	ldrb r1, [r6, #0x12]
	bl __divsi3
	str r0, [r6, #0x60]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0807FCBE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _0807FCE4
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807FCFE
_0807FCE4:
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807FD18 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
_0807FCFE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD04: .4byte 0x0000AB1B
_0807FD08: .4byte 0x08367E40
_0807FD0C: .4byte 0xFFFF6000
_0807FD10: .4byte 0xFFFF7100
_0807FD14: .4byte 0xFFFF8B00
_0807FD18: .4byte gEnemyFnTable

	thumb_func_start nop_0807fd1c
nop_0807fd1c: @ 0x0807FD1C
	bx lr
	.align 2, 0
