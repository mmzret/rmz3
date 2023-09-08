	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Harpuia_Init
Harpuia_Init: @ 0x08035038
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	movs r6, #1
	strb r6, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0803510C @ =0x0835EAF8
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #0x20
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_0800a05c
	str r0, [r7, #0x58]
	ldr r1, _08035110 @ =gZeroFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	bl FUN_0809af20
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	ldr r1, _08035114 @ =0x00000286
	adds r0, r7, r1
	strb r5, [r0]
	subs r2, #4
	adds r1, r7, r2
	ldr r0, [r7, #0x54]
	str r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r7, #0x58]
	str r0, [r1]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r5, [r0]
	adds r2, #9
	adds r0, r7, r2
	strb r5, [r0]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	adds r0, #8
	str r5, [r0, #4]
	str r5, [r7, #0x64]
	adds r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r7, #0
	bl Harpuia_Update
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803510C: .4byte 0x0835EAF8
_08035110: .4byte gZeroFnTable
_08035114: .4byte 0x00000286

	thumb_func_start Harpuia_Update
Harpuia_Update: @ 0x08035118
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #2
	beq _0803515C
	ldr r1, [r4, #0x54]
	ldr r0, [r5, #0x34]
	adds r3, r1, r0
	str r3, [r4, #0x54]
	movs r6, #0x9f
	lsls r6, r6, #2
	adds r2, r4, r6
	ldr r1, [r2]
	ldr r0, [r5, #0x30]
	adds r0, r1, r0
	cmp r3, r0
	beq _0803515C
	ldr r6, _080351A8 @ =0xFFFFF800
	adds r1, r3, r6
	subs r1, r0, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r0, r3, r0
	str r0, [r4, #0x54]
	ldr r2, [r2]
	ldr r1, [r5, #0x30]
	adds r1, r2, r1
	cmp r0, r1
	blt _0803515C
	str r1, [r4, #0x54]
_0803515C:
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x30]
	adds r0, r0, r1
	ldr r6, _080351AC @ =0xFFFF9C00
	adds r0, r0, r6
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bge _08035176
	b _080352A2
_08035176:
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r0, #2
	beq _080351B8
	ldr r1, _080351B0 @ =0x0835EAD0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080351B4 @ =0x0835EAE4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl harpuia_08035684
	b _080351DE
	.align 2, 0
_080351A8: .4byte 0xFFFFF800
_080351AC: .4byte 0xFFFF9C00
_080351B0: .4byte 0x0835EAD0
_080351B4: .4byte 0x0835EAE4
_080351B8:
	ldrb r0, [r2, #0xc]
	cmp r0, #0
	bne _080351DE
	ldr r1, _080352D4 @ =0x0835EAD0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080352D8 @ =0x0835EAE4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080351DE:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #4
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _08035204
	ldr r1, [r4, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _08035204
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _080352DC @ =0x00000137
	bl PlaySound
_08035204:
	ldr r0, [r5]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803523C
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _08035244
	subs r0, #1
	strb r0, [r1, #0xc]
	movs r0, #0xf8
	bl PlaySound
	movs r0, #4
	bl PlaySound
	ldr r6, _080352E0 @ =0x00000287
	adds r1, r4, r6
	movs r0, #0x5a
	strb r0, [r1]
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	bne _0803526E
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0803523C:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	bne _0803526E
_08035244:
	ldr r0, _080352E0 @ =0x00000287
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08035252
	subs r0, #1
	strb r0, [r1]
_08035252:
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803526E
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_0803526E:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r1, [r2]
	ldr r0, [r4, #0x54]
	str r0, [r1, #0x54]
	ldr r1, [r2]
	ldr r0, [r4, #0x58]
	str r0, [r1, #0x58]
	ldr r0, [r2]
	ldr r1, [r0, #0x2c]
	cmp r1, #0
	beq _08035294
	ldr r0, [r4, #0x54]
	str r0, [r1, #0x54]
	ldr r0, [r2]
	ldr r1, [r0, #0x2c]
	ldr r0, [r4, #0x58]
	str r0, [r1, #0x58]
_08035294:
	ldr r0, [r4, #0x58]
	ldr r2, _080352E4 @ =0xFFFF9C00
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #9
	cmp r0, r1
	ble _080352CC
_080352A2:
	movs r0, #0xf8
	bl PlaySound
	movs r0, #4
	bl PlaySound
	ldr r0, [r4, #0x28]
	movs r2, #0
	strb r2, [r0, #0xc]
	ldr r1, _080352E8 @ =gZeroFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
_080352CC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080352D4: .4byte 0x0835EAD0
_080352D8: .4byte 0x0835EAE4
_080352DC: .4byte 0x00000137
_080352E0: .4byte 0x00000287
_080352E4: .4byte 0xFFFF9C00
_080352E8: .4byte gZeroFnTable

	thumb_func_start Harpuia_Die
Harpuia_Die: @ 0x080352EC
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08035328 @ =gZeroFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	bx lr
	.align 2, 0
_08035328: .4byte gZeroFnTable

	thumb_func_start FUN_0803532c
FUN_0803532c: @ 0x0803532C
	movs r0, #1
	bx lr

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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

	thumb_func_start FUN_080355c0
FUN_080355c0: @ 0x080355C0
	movs r0, #1
	bx lr

	thumb_func_start FUN_080355c4
FUN_080355c4: @ 0x080355C4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080355D4
	cmp r5, #1
	beq _080355FA
	b _08035672
_080355D4:
	ldr r1, _08035678 @ =0x0000BE21
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080355FA:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0803560A
	str r1, [r4, #0x60]
_0803560A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	movs r0, #0x96
	lsls r0, r0, #9
	cmp r1, r0
	bgt _08035652
	ldr r0, [r4, #0x54]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bne _0803564C
	ldr r0, [r4, #0x54]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	bne _0803564C
	ldr r0, [r4, #0x54]
	ldr r1, _0803567C @ =0xFFFFE600
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	beq _08035652
_0803564C:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08035652:
	ldr r0, [r4, #0x58]
	ldr r1, _08035680 @ =0xFFFF9C00
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #9
	cmp r0, r1
	ble _0803566C
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_0803566C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08035672:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08035678: .4byte 0x0000BE21
_0803567C: .4byte 0xFFFFE600
_08035680: .4byte 0xFFFF9C00

	thumb_func_start harpuia_08035684
harpuia_08035684: @ 0x08035684
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x58]
	movs r2, #0x96
	lsls r2, r2, #9
	cmp r1, r2
	ble _0803569E
	ldr r0, [r4, #0x54]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	b _080356A6
_0803569E:
	ldr r0, [r4, #0x54]
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r0, r0, r2
_080356A6:
	bl PushoutToLeft2
	adds r5, r0, #0
	cmp r5, #0
	beq _080356B6
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_080356B6:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _080356E4
	ldr r0, [r4, #0x28]
	movs r2, #4
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bne _080356E4
	ldr r0, _08035778 @ =gJoypad
	ldrh r0, [r0, #4]
	movs r2, #1
	ands r1, r0
	cmp r1, #0
	beq _080356E4
	strb r2, [r3]
	ldr r3, _0803577C @ =0x00000285
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _08035780 @ =0xFFFFFAC0
	str r0, [r4, #0x60]
_080356E4:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrb r1, [r6]
	cmp r1, #1
	beq _080356F2
	b _08035814
_080356F2:
	ldr r0, _08035778 @ =gJoypad
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _0803570A
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bge _0803570A
	str r1, [r4, #0x60]
	ldr r2, _0803577C @ =0x00000285
	adds r0, r4, r2
	strb r1, [r0]
_0803570A:
	ldr r3, _0803577C @ =0x00000285
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #1
	bne _08035720
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08035720
	movs r0, #0
	str r0, [r4, #0x60]
	strb r0, [r1]
_08035720:
	ldr r0, [r4, #0x60]
	adds r0, #0x2c
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08035730
	str r1, [r4, #0x60]
_08035730:
	ldr r0, [r4, #0x58]
	ldr r3, [r4, #0x60]
	adds r1, r0, r3
	str r1, [r4, #0x58]
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r7, r4, r0
	ldr r2, [r7]
	ldr r0, _08035784 @ =0x7FFFFFFF
	cmp r2, r0
	bne _08035748
	b _08035870
_08035748:
	cmp r1, r2
	ble _0803574E
	b _08035870
_0803574E:
	ldr r0, [r4, #0x54]
	ldr r6, _08035788 @ =0xFFFFE600
	adds r0, r0, r6
	adds r1, r1, r3
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _0803578C
	ldr r0, [r7]
	cmp r1, r0
	bgt _0803578C
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	b _080357EC
	.align 2, 0
_08035778: .4byte gJoypad
_0803577C: .4byte 0x00000285
_08035780: .4byte 0xFFFFFAC0
_08035784: .4byte 0x7FFFFFFF
_08035788: .4byte 0xFFFFE600
_0803578C:
	ldr r0, [r4, #0x54]
	movs r6, #0xd0
	lsls r6, r6, #5
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _080357C2
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _080357C2
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	b _080357EC
_080357C2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _08035870
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _08035870
	ldr r0, [r4, #0x54]
_080357EC:
	ldr r1, [r4, #0x58]
	ldr r2, _0803580C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	str r0, [r4, #0x58]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08035810 @ =0x00000285
	adds r0, r4, r2
	strb r1, [r0]
	b _08035870
	.align 2, 0
_0803580C: .4byte 0xFFFFF000
_08035810: .4byte 0x00000285
_08035814:
	ldr r0, [r4, #0x54]
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r1, [r4, #0x58]
	cmp r5, r1
	beq _08035870
	ldr r0, [r4, #0x54]
	ldr r2, _08035878 @ =0xFFFFE600
	adds r0, r0, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r1, [r4, #0x58]
	cmp r5, r1
	beq _08035870
	ldr r0, [r4, #0x54]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r4, #0x58]
	cmp r5, r0
	beq _08035870
	movs r2, #0
	movs r1, #1
	strb r1, [r6]
	ldr r3, _0803587C @ =0x00000285
	adds r0, r4, r3
	strb r1, [r0]
	str r2, [r4, #0x60]
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r5, r0
	ble _08035870
	ldr r0, _08035880 @ =0x7FFFFFFF
	str r0, [r1]
	ldr r2, _08035884 @ =0x00000286
	adds r1, r4, r2
	movs r0, #0x78
	strb r0, [r1]
_08035870:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035878: .4byte 0xFFFFE600
_0803587C: .4byte 0x00000285
_08035880: .4byte 0x7FFFFFFF
_08035884: .4byte 0x00000286
