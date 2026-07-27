	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08035330
FUN_08035330: @ 0x08035330
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08035340
	cmp r0, #1
	beq _08035352
	b _08035370
_08035340:
	ldr r1, _08035378 @ =0x0000BE21
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035352:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035368
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035370
_08035368:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08035370:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035378: .4byte 0x0000BE21

	thumb_func_start FUN_0803537c
FUN_0803537c: @ 0x0803537C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _0803539E
	ldr r0, _080353A4 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803539E
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0803539E:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_080353A4: .4byte gJoypad

	thumb_func_start FUN_080353a8
FUN_080353a8: @ 0x080353A8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080353B8
	cmp r0, #1
	beq _080353D0
	b _080353D6
_080353B8:
	ldr r1, _080353DC @ =0x0000BE21
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080353E0 @ =0x0835EAF8
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080353D0:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080353D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080353DC: .4byte 0x0000BE21
_080353E0: .4byte 0x0835EAF8

	thumb_func_start FUN_080353e4
FUN_080353e4: @ 0x080353E4
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #1
	bls _08035402
	ldr r0, _08035408 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035402
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08035402:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08035408: .4byte gJoypad

	thumb_func_start FUN_0803540c
FUN_0803540c: @ 0x0803540C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0803543C
	cmp r0, #1
	bgt _08035420
	cmp r0, #0
	beq _0803542A
	b _0803549E
_08035420:
	cmp r0, #2
	beq _08035464
	cmp r0, #3
	beq _08035480
	b _0803549E
_0803542A:
	ldr r1, _08035460 @ =0x0000BE21
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803543C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08035474
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035478
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803549E
	b _08035478
	.align 2, 0
_08035460: .4byte 0x0000BE21
_08035464:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803549E
_08035474:
	movs r0, #0xa
	strb r0, [r4, #0x12]
_08035478:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0803549E
_08035480:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08035496
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803549E
_08035496:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0803549E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080354a4
FUN_080354a4: @ 0x080354A4
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #1
	bne _080354C8
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080354C8
	ldr r0, _080354D0 @ =gJoypad
	ldrh r1, [r0, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080354C8
	strb r3, [r2, #0xf]
_080354C8:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_080354D0: .4byte gJoypad

	thumb_func_start harpuia_080354d4
harpuia_080354d4: @ 0x080354D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08035512
	cmp r5, #1
	bgt _080354E8
	cmp r5, #0
	beq _080354F2
	b _080355AA
_080354E8:
	cmp r5, #2
	beq _0803555C
	cmp r5, #3
	beq _0803557A
	b _080355AA
_080354F2:
	ldr r1, _08035548 @ =0x0000BE22
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0803554C @ =0x0835EB10
	bl SetDDP
	movs r0, #0xf9
	bl PlaySound
	strb r5, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08035512:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x70]
	ldr r1, _08035550 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _08035554 @ =0x00010500
	cmp r0, r1
	bne _0803552E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08035558 @ =0x0835EAF8
	bl SetDDP
_0803552E:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080355AA
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _080355A2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080355AA
	.align 2, 0
_08035548: .4byte 0x0000BE22
_0803554C: .4byte 0x0835EB10
_08035550: .4byte 0x00FFFF00
_08035554: .4byte 0x00010500
_08035558: .4byte 0x0835EAF8
_0803555C:
	ldr r1, _080355B0 @ =0x0000BE23
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080355B4 @ =0x0835EB10
	bl SetDDP
	movs r0, #0xf9
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0803557A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x70]
	ldr r1, _080355B8 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x82
	lsls r1, r1, #9
	cmp r0, r1
	bne _08035598
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080355BC @ =0x0835EAF8
	bl SetDDP
_08035598:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080355AA
_080355A2:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080355AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080355B0: .4byte 0x0000BE23
_080355B4: .4byte 0x0835EB10
_080355B8: .4byte 0x00FFFF00
_080355BC: .4byte 0x0835EAF8
