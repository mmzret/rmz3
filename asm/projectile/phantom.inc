	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080af368
FUN_080af368: @ 0x080AF368
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldr r6, [r0, #0x54]
	ldr r7, [r0, #0x58]
	ldrb r0, [r0, #0xa]
	lsrs r4, r0, #4
	movs r0, #1
	ands r4, r0
	adds r2, r4, #0
	cmp r2, #0
	beq _080AF388
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080AF38E
_080AF388:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF38E:
	strb r0, [r3, #0xa]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r2
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, #0
	bne _080AF3BC
	movs r0, #1
_080AF3BC:
	lsls r0, r0, #0xc
	adds r0, r6, r0
	str r0, [r3, #0x54]
	ldr r1, _080AF3E4 @ =0xFFFFE400
	adds r0, r7, r1
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080AF3DC
	strb r5, [r3, #0xd]
	ldr r1, _080AF3E8 @ =0x00008601
	adds r0, r3, #0
	bl SetMotion
_080AF3DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF3E4: .4byte 0xFFFFE400
_080AF3E8: .4byte 0x00008601

	thumb_func_start FUN_080af3ec
FUN_080af3ec: @ 0x080AF3EC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x28]
	ldrb r0, [r1, #0xf]
	cmp r0, #2
	bls _080AF408
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	adds r0, r3, #0
	bl FUN_080af46c
	b _080AF462
_080AF408:
	ldr r5, [r1, #0x54]
	ldr r6, [r1, #0x58]
	ldrb r0, [r1, #0xa]
	lsrs r4, r0, #4
	movs r0, #1
	ands r4, r0
	adds r2, r4, #0
	cmp r2, #0
	beq _080AF422
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080AF428
_080AF422:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF428:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r4, #0
	bne _080AF452
	movs r1, #1
_080AF452:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #9
	adds r0, r5, r0
	str r0, [r3, #0x54]
	ldr r1, _080AF468 @ =0xFFFFE900
	adds r0, r6, r1
	str r0, [r3, #0x58]
_080AF462:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF468: .4byte 0xFFFFE900

	thumb_func_start FUN_080af46c
FUN_080af46c: @ 0x080AF46C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AF490
	ldr r1, _080AF48C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	b _080AF506
	.align 2, 0
_080AF48C: .4byte gProjectileFnTable
_080AF490:
	ldr r1, _080AF4BC @ =0x0836D424
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, [r5, #0x2c]
	cmp r0, r4
	bne _080AF4C0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bhi _080AF4C0
	cmp r0, #4
	bne _080AF508
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	b _080AF508
	.align 2, 0
_080AF4BC: .4byte 0x0836D424
_080AF4C0:
	ldr r0, _080AF510 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _080AF508
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF514 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_080AF506:
	str r0, [r4, #0x14]
_080AF508:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF510: .4byte gStageRun+232
_080AF514: .4byte gProjectileFnTable

	thumb_func_start FUN_080af518
FUN_080af518: @ 0x080AF518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r7, #0
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080AF570 @ =0x0836D358
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r4, #1
	strb r4, [r6, #0xe]
	movs r1, #0x86
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x28]
	ldr r5, [r0, #0x54]
	ldr r1, [r0, #0x58]
	mov ip, r1
	ldrb r0, [r0, #0xa]
	lsrs r3, r0, #4
	ands r3, r4
	movs r1, #0
	cmp r3, #0
	bne _080AF562
	movs r1, #1
_080AF562:
	adds r2, r1, #0
	cmp r2, #0
	beq _080AF574
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080AF57A
	.align 2, 0
_080AF570: .4byte 0x0836D358
_080AF574:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080AF57A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, #0
	beq _080AF5A0
	movs r0, #1
_080AF5A0:
	adds r3, r0, #0
	lsls r0, r3, #5
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r0, r5, r0
	str r0, [r6, #0x54]
	ldr r0, _080AF5C8 @ =0xFFFFF200
	add r0, ip
	str r0, [r6, #0x58]
	lsls r0, r3, #0xa
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	lsls r0, r3, #6
	rsbs r0, r0, #0
	str r0, [r6, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF5C8: .4byte 0xFFFFF200

	thumb_func_start FUN_080af5cc
FUN_080af5cc: @ 0x080AF5CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r4, #0
	adds r2, #0x5c
	adds r3, r4, #0
	adds r3, #0x64
	bl FUN_080afdf0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080AF5EC
	movs r0, #2
	strb r0, [r4, #0xe]
_080AF5EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af5f4
FUN_080af5f4: @ 0x080AF5F4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x54
	adds r2, r4, #0
	adds r2, #0x5c
	adds r3, r4, #0
	adds r3, #0x64
	bl FUN_080afe38
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080AF614
	movs r0, #1
	strb r0, [r4, #0xe]
_080AF614:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af61c
FUN_080af61c: @ 0x080AF61C
	push {lr}
	ldr r2, _080AF630 @ =0x0836D430
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF630: .4byte 0x0836D430

	thumb_func_start FUN_080af634
FUN_080af634: @ 0x080AF634
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF658 @ =0x00008605
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af65c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF658: .4byte 0x00008605

	thumb_func_start FUN_080af65c
FUN_080af65c: @ 0x080AF65C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r5, r1, r0
	str r5, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r3, r1, r0
	str r3, [r4, #0x58]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080AF6B2
	ldr r2, _080AF700 @ =gSineTable
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	adds r0, r5, r0
	adds r1, r3, r1
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AF6B2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0x10]
	strb r1, [r4, #0xd]
_080AF6B2:
	ldr r0, _080AF704 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF6FA
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF708 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF6FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF700: .4byte gSineTable
_080AF704: .4byte gStageRun+232
_080AF708: .4byte gProjectileFnTable

	thumb_func_start FUN_080af70c
FUN_080af70c: @ 0x080AF70C
	push {lr}
	adds r3, r0, #0
	adds r0, #0x8c
	movs r2, #0
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080AF744 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r3, #0x14]
	strb r2, [r3, #0xd]
	adds r0, r3, #0
	bl PhantomProjectile_Update
	pop {r0}
	bx r0
	.align 2, 0
_080AF744: .4byte gProjectileFnTable

	thumb_func_start FUN_080af748
FUN_080af748: @ 0x080AF748
	push {lr}
	ldr r2, _080AF75C @ =0x0836D438
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF75C: .4byte 0x0836D438

	thumb_func_start FUN_080af760
FUN_080af760: @ 0x080AF760
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF7A8 @ =0x00008605
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	ldr r0, [r4, #0x60]
	ldr r1, _080AF7AC @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r0, #0x1c
	strb r0, [r4, #0x13]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af7b0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF7A8: .4byte 0x00008605
_080AF7AC: .4byte 0xFFFFFA00

	thumb_func_start FUN_080af7b0
FUN_080af7b0: @ 0x080AF7B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AF7CE
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _080AF7D2
_080AF7CE:
	ldrb r0, [r5, #0xa]
	orrs r0, r1
_080AF7D2:
	strb r0, [r5, #0xa]
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	bne _080AF814
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
	ldr r1, _080AF810 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080AF8A8
	.align 2, 0
_080AF810: .4byte gProjectileFnTable
_080AF814:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080AF824
	str r1, [r5, #0x60]
_080AF824:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	ldr r4, _080AF898 @ =gSineTable
	ldrb r2, [r5, #0x12]
	adds r2, #0x40
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r2, r2, r4
	movs r6, #0
	ldrsh r3, [r2, r6]
	lsls r3, r3, #3
	ldrb r2, [r5, #0x12]
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r4, #0
	ldrsh r2, [r2, r4]
	lsls r2, r2, #3
	adds r0, r0, r3
	adds r1, r1, r2
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _080AF88A
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #1
	rsbs r0, r0, #0
	cmp r0, #0
	bge _080AF886
	adds r0, #0xff
_080AF886:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
_080AF88A:
	ldrb r1, [r5, #0x12]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080AF89C
	adds r1, #8
	b _080AF89E
	.align 2, 0
_080AF898: .4byte gSineTable
_080AF89C:
	subs r1, #8
_080AF89E:
	strb r1, [r5, #0x12]
	adds r1, #0x20
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
_080AF8A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af8b0
FUN_080af8b0: @ 0x080AF8B0
	push {lr}
	ldr r2, _080AF8C4 @ =0x0836D440
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF8C4: .4byte 0x0836D440

	thumb_func_start FUN_080af8c8
FUN_080af8c8: @ 0x080AF8C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF8E4 @ =0x00008605
	bl SetMotion
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl FUN_080af8e8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF8E4: .4byte 0x00008605

	thumb_func_start FUN_080af8e8
FUN_080af8e8: @ 0x080AF8E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080AF912
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _080AF97E
_080AF912:
	ldr r1, [r5, #0x54]
	str r1, [r4, #0x54]
	ldr r3, _080AF9A0 @ =gSineTable
	ldrb r2, [r4, #0x12]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r1, [r5, #0x58]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r2, #0x20
	adds r0, r4, #0
	adds r0, #0x24
	movs r5, #0
	strb r2, [r0]
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	ldr r0, _080AF9A4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AF998
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_080AF97E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080AF9A8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AF998:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF9A0: .4byte gSineTable
_080AF9A4: .4byte gStageRun+232
_080AF9A8: .4byte gProjectileFnTable

	thumb_func_start nop_080af9ac
nop_080af9ac: @ 0x080AF9AC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080af9b0
FUN_080af9b0: @ 0x080AF9B0
	push {lr}
	ldr r2, _080AF9C4 @ =0x0836D44C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080AF9C4: .4byte 0x0836D44C

	thumb_func_start FUN_080af9c8
FUN_080af9c8: @ 0x080AF9C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF9F0 @ =0x00008602
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0x24
	movs r2, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r2, [r4, #0x13]
	adds r0, r4, #0
	bl FUN_080af9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF9F0: .4byte 0x00008602

	thumb_func_start FUN_080af9f4
FUN_080af9f4: @ 0x080AF9F4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080AFA6A
	movs r5, #0
	ldr r7, _080AFB10 @ =gSineTable
	mov r6, sp
_080AFA1E:
	ldrb r3, [r4, #0x13]
	lsls r3, r3, #4
	lsls r0, r5, #6
	adds r3, r3, r0
	lsls r3, r3, #0x18
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	lsrs r2, r3, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x17
	adds r3, r3, r0
	lsrs r3, r3, #0x17
	adds r3, r3, r7
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #3
	ldr r1, [sp]
	adds r0, r0, r1
	str r0, [sp]
	lsls r0, r2, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	ldr r1, [r6, #4]
	adds r0, r0, r1
	str r0, [r6, #4]
	mov r0, sp
	movs r1, #0xf0
	lsls r1, r1, #2
	movs r3, #0
	bl FUN_080afbfc
	adds r5, #1
	cmp r5, #3
	ble _080AFA1E
_080AFA6A:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080AFAC2
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFAC2:
	ldr r0, _080AFB18 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _080AFB08
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
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
	ldr r1, _080AFB14 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080AFB08:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFB10: .4byte gSineTable
_080AFB14: .4byte gProjectileFnTable
_080AFB18: .4byte gStageRun+232

	thumb_func_start FUN_080afb1c
FUN_080afb1c: @ 0x080AFB1C
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AFB5E
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
	ldr r1, _080AFB64 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080AFB5E:
	pop {r0}
	bx r0
	.align 2, 0
_080AFB64: .4byte gProjectileFnTable

	thumb_func_start PhantomProjectile_Die
PhantomProjectile_Die: @ 0x080AFB68
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AFBAC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBAC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbb0
FUN_080afbb0: @ 0x080AFBB0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFBF4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFBEC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFBF8 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r4, [r3, #0x10]
	str r5, [r3, #0x28]
_080AFBEC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFBF4: .4byte gProjectileHeaderPtr
_080AFBF8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afbfc
FUN_080afbfc: @ 0x080AFBFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	mov r8, r4
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldr r0, _080AFC90 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFC82
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFC94 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	ldr r2, _080AFC98 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC64
	adds r0, #0xff
_080AFC64:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080AFC78
	adds r0, #0xff
_080AFC78:
	asrs r0, r0, #8
	str r0, [r3, #0x60]
	mov r0, r8
	strb r0, [r3, #0x12]
	strb r7, [r3, #0x11]
_080AFC82:
	adds r0, r3, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFC90: .4byte gProjectileHeaderPtr
_080AFC94: .4byte gProjectileFnTable
_080AFC98: .4byte gSineTable

	thumb_func_start FUN_080afc9c
FUN_080afc9c: @ 0x080AFC9C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080AFCE4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFCDC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFCE8 @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x28]
_080AFCDC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AFCE4: .4byte gProjectileHeaderPtr
_080AFCE8: .4byte gProjectileFnTable

	thumb_func_start FUN_080afcec
FUN_080afcec: @ 0x080AFCEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	mov r8, r5
	ldr r0, _080AFD98 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080AFD8C
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFD9C @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r4, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r2, _080AFDA0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD50
	adds r0, #0xff
_080AFD50:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080AFD64
	adds r0, #0xff
_080AFD64:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	mov r0, r8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0x80
	bl FUN_080afc9c
	adds r0, r4, #0
	movs r1, #0xc0
	bl FUN_080afc9c
_080AFD8C:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AFD98: .4byte gProjectileHeaderPtr
_080AFD9C: .4byte gProjectileFnTable
_080AFDA0: .4byte gSineTable

	thumb_func_start FUN_080afda4
FUN_080afda4: @ 0x080AFDA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AFDE8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080AFDDE
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080AFDEC @ =gProjectileFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #5
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_080AFDDE:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AFDE8: .4byte gProjectileHeaderPtr
_080AFDEC: .4byte gProjectileFnTable

	thumb_func_start FUN_080afdf0
FUN_080afdf0: @ 0x080AFDF0
	push {r4, r5, lr}
	ldr r5, [r2]
	ldr r3, [r1]
	adds r4, r3, r5
	str r4, [r1]
	ldr r3, [r1, #4]
	ldr r2, [r2, #4]
	adds r3, r3, r2
	str r3, [r1, #4]
	adds r1, r0, #0
	adds r1, #0xdc
	ldr r1, [r1]
	ldr r2, _080AFE28 @ =0xFFFFB400
	adds r1, r1, r2
	ldr r3, _080AFE2C @ =0xFFFFDA00
	adds r2, r4, r3
	adds r0, #0xd4
	ldr r0, [r0]
	subs r4, r2, r0
	cmp r4, r1
	bls _080AFE30
	adds r0, r4, #0
	muls r0, r5, r0
	cmp r0, #0
	ble _080AFE30
	movs r0, #1
	b _080AFE32
	.align 2, 0
_080AFE28: .4byte 0xFFFFB400
_080AFE2C: .4byte 0xFFFFDA00
_080AFE30:
	movs r0, #0
_080AFE32:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080afe38
FUN_080afe38: @ 0x080AFE38
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	adds r6, r3, #0
	ldr r5, [r6]
	ldr r0, [r2]
	adds r3, r0, r5
	str r3, [r2]
	ldr r1, [r2, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	ble _080AFE54
	subs r1, #8
	str r1, [r2, #4]
_080AFE54:
	ldr r0, [r4]
	adds r0, r0, r3
	str r0, [r4]
	ldr r0, [r4, #4]
	adds r0, r0, r1
	str r0, [r4, #4]
	ldr r0, _080AFE70 @ =0x000003FF
	adds r1, r3, r0
	ldr r0, _080AFE74 @ =0x000007FE
	cmp r1, r0
	bhi _080AFE78
	movs r0, #0
	b _080AFE7E
	.align 2, 0
_080AFE70: .4byte 0x000003FF
_080AFE74: .4byte 0x000007FE
_080AFE78:
	rsbs r0, r5, #0
	str r0, [r6]
	movs r0, #1
_080AFE7E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

