	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start cubitKnockBackDamage
cubitKnockBackDamage: @ 0x08054340
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08054350
	cmp r5, #1
	beq _080543F4
	b _080544AE
_08054350:
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xd1
	bl PlaySound
	ldr r1, _080543A8 @ =0x0000B01E
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080543AC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080543B4
	ldr r0, _080543B0 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
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
	orrs r0, r1
	b _080543D6
	.align 2, 0
_080543A8: .4byte 0x0000B01E
_080543AC: .4byte pZero2
_080543B0: .4byte 0xFFFFFE00
_080543B4:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
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
_080543D6:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xc0
	str r2, [r0]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	strb r2, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080543F4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	rsbs r1, r0, #0
	lsls r1, r1, #3
	asrs r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08054416
	str r1, [r4, #0x60]
_08054416:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08054444
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r3, _080544B4 @ =0xFFFFF400
	adds r1, r2, r3
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054444
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08054444:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08054466
	ldr r0, [r4, #0x54]
	ldr r1, _080544B8 @ =0xFFFFE400
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080544B4 @ =0xFFFFF400
	adds r1, r1, r2
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054466
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08054466:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r5, _080544BC @ =0xFFFFFC00
	adds r1, r1, r5
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08054482
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08054482:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805448C
	subs r0, #1
	strb r0, [r4, #0x12]
_0805448C:
	ldrh r1, [r4, #0x12]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _080544AE
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xc8
	movs r1, #0
	strb r1, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	movs r0, #0xff
	strb r0, [r4, #0xf]
_080544AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080544B4: .4byte 0xFFFFF400
_080544B8: .4byte 0xFFFFE400
_080544BC: .4byte 0xFFFFFC00

	thumb_func_start cubit_080544c0
cubit_080544c0: @ 0x080544C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08054522
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054522
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r0, r1
	ldr r1, _08054500 @ =0x0000B019
	cmp r0, r1
	bne _08054508
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bne _08054514
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	beq _08054514
	ldr r2, _08054504 @ =0x08363A70
	b _0805450A
	.align 2, 0
_08054500: .4byte 0x0000B019
_08054504: .4byte 0x08363A70
_08054508:
	ldr r2, _0805452C @ =0x08363A68
_0805450A:
	movs r0, #0x16
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
_08054514:
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	cmp r0, #0
	beq _08054522
	movs r0, #0
	str r0, [r1]
_08054522:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805452C: .4byte 0x08363A68

	thumb_func_start FUN_08054530
FUN_08054530: @ 0x08054530
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldrb r0, [r2, #4]
	cmp r0, #3
	beq _08054546
	cmp r0, #0xe
	beq _08054546
	cmp r0, #0xf
	bne _08054588
_08054546:
	ldr r2, [r3, #0x2c]
	ldr r0, [r3, #0xc]
	ldr r4, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08054568
	adds r0, r2, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08054588
_08054568:
	ldr r0, _08054580 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08054588
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bge _08054584
	movs r0, #0xff
	b _08054586
	.align 2, 0
_08054580: .4byte gStageRun
_08054584:
	movs r0, #0xfe
_08054586:
	strb r0, [r2, #0x11]
_08054588:
	ldr r0, [r3, #0xc]
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	ldrb r0, [r1]
	cmp r0, #2
	beq _080545C0
	ldr r1, [r1, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080545C0
	ldr r0, [r2, #4]
	ldr r1, _080545C8 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _080545C0
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #0xd]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080545C0
	movs r1, #0
	movs r0, #0xb
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080545C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080545C8: .4byte 0x000200FF

	thumb_func_start cubit_080545cc
cubit_080545cc: @ 0x080545CC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r3, #0xc8
	ldrb r1, [r3]
	cmp r1, #0
	beq _08054614
	cmp r2, #1
	bne _080545F8
	movs r2, #0
	ldr r5, _080545F4 @ =0x08363AA0
	adds r3, r5, #0
_080545E4:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _080545E4
	b _0805466A
	.align 2, 0
_080545F4: .4byte 0x08363AA0
_080545F8:
	movs r2, #0
	ldr r5, _08054610 @ =0x08363AA0
	adds r3, r5, #0
_080545FE:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	ble _080545FE
	b _0805466A
	.align 2, 0
_08054610: .4byte 0x08363AA0
_08054614:
	cmp r2, #1
	bne _08054656
	movs r2, #0
	ldr r5, _08054638 @ =0x08363A98
	adds r3, r5, #0
_0805461E:
	ldrh r1, [r3]
	cmp r1, r4
	bne _0805463C
	adds r1, r2, #1
	adds r0, r1, #0
	cmp r1, #0
	bge _0805462E
	adds r0, r2, #4
_0805462E:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	b _0805464E
	.align 2, 0
_08054638: .4byte 0x08363A98
_0805463C:
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _0805461E
	b _0805466A
_08054646:
	adds r0, r2, #1
	movs r1, #3
	bl __modsi3
_0805464E:
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	b _0805466A
_08054656:
	movs r2, #0
	ldr r5, _08054670 @ =0x08363A98
	adds r3, r5, #0
_0805465C:
	ldrh r1, [r3]
	cmp r1, r4
	beq _08054646
	adds r3, #2
	adds r2, #1
	cmp r2, #3
	ble _0805465C
_0805466A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08054670: .4byte 0x08363A98

