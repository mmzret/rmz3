	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a22f8
FUN_080a22f8: @ 0x080A22F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080A2334
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
	strb r0, [r4, #0xa]
	ldr r1, _080A2330 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080A2446
	.align 2, 0
_080A2330: .4byte gProjectileFnTable
_080A2334:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080A23AE
	cmp r5, #1
	bgt _080A2344
	cmp r5, #0
	beq _080A234A
	b _080A2446
_080A2344:
	cmp r5, #2
	beq _080A2438
	b _080A2446
_080A234A:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080A238C @ =0x0000A905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080A2390 @ =0x0836B2C4
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A2398
	ldr r0, [r4, #0x54]
	ldr r1, _080A2394 @ =0xFFFFEC00
	b _080A239E
	.align 2, 0
_080A238C: .4byte 0x0000A905
_080A2390: .4byte 0x0836B2C4
_080A2394: .4byte 0xFFFFEC00
_080A2398:
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #5
_080A239E:
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x64]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080A23AE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r0, r1
	str r1, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A23EE
	cmp r1, #0
	bge _080A23CC
	rsbs r1, r1, #0
_080A23CC:
	movs r0, #0xa0
	lsls r0, r0, #5
	cmp r1, r0
	ble _080A23EE
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A23EE
	movs r0, #1
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080a1594
	ldr r1, [r4, #0x5c]
	str r1, [r0, #0x5c]
_080A23EE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080A240A
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080A2416
_080A240A:
	ldr r0, [r4, #0x54]
	ldr r1, _080A2430 @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080A2416:
	adds r1, r0, #0
	cmp r1, #0
	beq _080A2446
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, _080A2434 @ =0xFFFFFD00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080A2446
	.align 2, 0
_080A2430: .4byte 0xFFFFFC00
_080A2434: .4byte 0xFFFFFD00
_080A2438:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080A2446:
	pop {r4, r5}
	pop {r0}
	bx r0

