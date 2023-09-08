	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateFollowerElf
CreateFollowerElf: @ 0x080E4118
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E4170 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E4184
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E4174 @ =gElfFnTable
	movs r0, #8
	strb r0, [r3, #9]
	ldr r0, [r1, #0x20]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r4, [r0]
	strb r7, [r3, #0x10]
	strb r6, [r3, #0x11]
	adds r0, #0xd
	strb r5, [r0]
	cmp r5, #0
	bne _080E4178
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	b _080E417E
	.align 2, 0
_080E4170: .4byte gElfHeaderPtr
_080E4174: .4byte gElfFnTable
_080E4178:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r1, [r0, #1]
_080E417E:
	adds r0, r3, #0
	adds r0, #0xb8
	strb r1, [r0]
_080E4184:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FollowerElf_Init
FollowerElf_Init: @ 0x080E418C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r1, _080E41D8 @ =gZeroRanges
	ldr r2, _080E41DC @ =0x00000147
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r7, [r0, #4]
	ldr r1, _080E41E0 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080E41E4
	movs r0, #0
	b _080E41EA
	.align 2, 0
_080E41D8: .4byte gZeroRanges
_080E41DC: .4byte 0x00000147
_080E41E0: .4byte gElfFnTable
_080E41E4:
	cmp r0, #1
	bne _080E41FC
	movs r0, #1
_080E41EA:
	bl createElfAction
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	b _080E420E
_080E41FC:
	movs r0, #2
	bl createElfAction
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
_080E420E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r1, r1, r0
	str r1, [r4, #0x54]
	asrs r2, r6, #0x10
	ldr r0, [r5, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x64]
	str r0, [r4, #0x68]
	adds r2, r4, #0
	adds r2, #0xc2
	movs r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0xc0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0x20
	strb r0, [r1]
	ldr r1, _080E4280 @ =0x00000121
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x28
	bne _080E4274
	ldr r0, _080E4284 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0, #8]
_080E4274:
	adds r0, r4, #0
	bl FollowerElf_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E4280: .4byte 0x00000121
_080E4284: .4byte gCurStory

	thumb_func_start FollowerElf_Update
FollowerElf_Update: @ 0x080E4288
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080E42E0 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	beq _080E42A0
	b _080E44E4
_080E42A0:
	ldr r1, _080E42E4 @ =0x00000232
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E42EC
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E42E8 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080E44E4
	.align 2, 0
_080E42E0: .4byte gPause
_080E42E4: .4byte 0x00000232
_080E42E8: .4byte gElfFnTable
_080E42EC:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E4308
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080E4320
_080E4308:
	ldr r1, _080E431C @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080E44E4
	.align 2, 0
_080E431C: .4byte gElfFnTable
_080E4320:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080E4360
	adds r0, r5, #0
	adds r0, #0xc1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080E434A
	ldr r0, [r5, #0x64]
	movs r3, #0xd8
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x54]
	subs r6, r1, r0
	ldr r0, [r5, #0x68]
	movs r1, #0x98
	lsls r1, r1, #5
	b _080E4394
_080E434A:
	ldr r0, [r5, #0x64]
	movs r2, #0xd0
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r4, #0x54]
	subs r6, r1, r0
	ldr r0, [r5, #0x68]
	movs r3, #0xa4
	lsls r3, r3, #6
	adds r0, r0, r3
	b _080E4396
_080E4360:
	adds r0, r5, #0
	adds r0, #0xc1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080E4384
	ldr r0, [r5, #0x64]
	ldr r1, _080E4380 @ =0xFFFFE500
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	subs r6, r1, r0
	ldr r0, [r5, #0x68]
	movs r2, #0x98
	lsls r2, r2, #5
	adds r0, r0, r2
	b _080E4396
	.align 2, 0
_080E4380: .4byte 0xFFFFE500
_080E4384:
	ldr r0, [r5, #0x64]
	ldr r3, _080E43D8 @ =0xFFFFF300
	adds r0, r0, r3
	ldr r1, [r4, #0x54]
	subs r6, r1, r0
	ldr r0, [r5, #0x68]
	movs r1, #0xa4
	lsls r1, r1, #6
_080E4394:
	adds r0, r0, r1
_080E4396:
	ldr r1, [r4, #0x58]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl CalcAngle
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r6, #0
	cmp r6, #0
	bge _080E43AE
	rsbs r1, r6, #0
_080E43AE:
	adds r0, r4, #0
	cmp r4, #0
	bge _080E43B6
	rsbs r0, r4, #0
_080E43B6:
	cmp r1, r0
	ble _080E43E0
	adds r1, r6, #0
	cmp r1, #0
	bge _080E43C2
	rsbs r1, r1, #0
_080E43C2:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4404
	ldr r1, [r5, #0x5c]
	ldr r0, _080E43DC @ =0x000005FF
	cmp r1, r0
	bgt _080E4416
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4414
	.align 2, 0
_080E43D8: .4byte 0xFFFFF300
_080E43DC: .4byte 0x000005FF
_080E43E0:
	adds r1, r4, #0
	cmp r1, #0
	bge _080E43E8
	rsbs r1, r1, #0
_080E43E8:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080E4404
	ldr r1, [r5, #0x5c]
	ldr r0, _080E4400 @ =0x000005FF
	cmp r1, r0
	bgt _080E4416
	adds r0, r1, #0
	adds r0, #0x10
	b _080E4414
	.align 2, 0
_080E4400: .4byte 0x000005FF
_080E4404:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _080E4410
	str r1, [r5, #0x5c]
_080E4410:
	ldr r0, [r5, #0x5c]
	subs r0, #0x20
_080E4414:
	str r0, [r5, #0x5c]
_080E4416:
	ldr r0, [r5, #0x5c]
	cmp r0, #0x7f
	bgt _080E4420
	movs r0, #0x80
	str r0, [r5, #0x5c]
_080E4420:
	ldr r4, _080E4498 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, [r5, #0x5c]
	adds r1, r2, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x64]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r2, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r5, #0x68]
	adds r0, r0, r1
	str r0, [r5, #0x68]
	adds r1, r5, #0
	adds r1, #0xc0
	ldrb r2, [r1]
	adds r3, r2, #1
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1]
	ldrb r3, [r1]
	lsls r2, r3, #3
	ldrb r0, [r7]
	cmp r0, #0
	beq _080E449C
	movs r0, #0x3f
	subs r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r5, #0x64]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	mvns r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r5, #0x68]
	subs r0, r0, r1
	b _080E44C2
	.align 2, 0
_080E4498: .4byte gSineTable
_080E449C:
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	ldr r0, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	ldr r0, [r5, #0x68]
	adds r0, r0, r1
_080E44C2:
	str r0, [r5, #0x58]
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E44E4
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r4]
_080E44E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FollowerElf_Die
FollowerElf_Die: @ 0x080E44EC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	subs r0, #0x60
	movs r1, #0
	bl FUN_080bfce8
	ldr r1, _080E4530 @ =0x00000121
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x28
	bne _080E4510
	ldr r2, _080E4534 @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #8]
_080E4510:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E4538 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E4530: .4byte 0x00000121
_080E4534: .4byte gCurStory
_080E4538: .4byte gElfFnTable

	thumb_func_start FUN_080e453c
FUN_080e453c: @ 0x080E453C
	push {lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldrb r2, [r3, #0x12]
	cmp r2, #0
	bne _080E455E
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080E45AE
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080E4572
_080E455E:
	adds r1, r0, #0
	adds r1, #0xb4
	ldrb r0, [r3, #0x13]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _080E45AE
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_080E4572:
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
	ldr r1, _080E45B4 @ =gElfFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	ldr r2, [r3, #0x2c]
	cmp r2, #0
	beq _080E45AE
	ldrb r1, [r2, #0xb]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #0xb]
_080E45AE:
	pop {r0}
	bx r0
	.align 2, 0
_080E45B4: .4byte gElfFnTable
