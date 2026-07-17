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
	bl Camera_GetDistance
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

