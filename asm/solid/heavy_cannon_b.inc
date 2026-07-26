	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cc2d4
FUN_080cc2d4: @ 0x080CC2D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r0, [r5]
	cmp r0, #0
	beq _080CC2EA
	bl isKilled
	cmp r0, #0
	beq _080CC316
_080CC2EA:
	movs r1, #0
	str r1, [r5]
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bhi _080CC308
	strb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC304 @ =0x0836FED4
	bl SetDDP
	b _080CC316
	.align 2, 0
_080CC304: .4byte sCollisions+(24*3)
_080CC308:
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC31C @ =0x0836FEA4
	bl SetDDP
_080CC316:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC31C: .4byte sCollisions+(24*1)

	thumb_func_start FUN_080cc320
FUN_080cc320: @ 0x080CC320
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _080CC32C
	b _080CC4C4
_080CC32C:
	lsls r0, r0, #2
	ldr r1, _080CC338 @ =_080CC33C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CC338: .4byte _080CC33C
_080CC33C: @ jump table
	.4byte _080CC358 @ case 0
	.4byte _080CC37A @ case 1
	.4byte _080CC392 @ case 2
	.4byte _080CC3EA @ case 3
	.4byte _080CC3FC @ case 4
	.4byte _080CC468 @ case 5
	.4byte _080CC4AC @ case 6
_080CC358:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080CC3AC @ =0x0836FF30
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _080CC36E
	adds r1, #8
_080CC36E:
	str r1, [r4, #0x30]
	ldr r0, _080CC3B0 @ =0x00000801
	strh r0, [r4, #0x26]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC37A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC3B4 @ =0x0836FED4
	bl SetDDP
	ldr r1, _080CC3B8 @ =0x00003801
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC392:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CC3BC
	movs r0, #5
	strb r0, [r4, #0xe]
	b _080CC4CA
	.align 2, 0
_080CC3AC: .4byte Rect_ARRAY_0836ff30
_080CC3B0: .4byte 0x00000801
_080CC3B4: .4byte sCollisions+(24*3)
_080CC3B8: .4byte 0x00003801
_080CC3BC:
	movs r2, #0
	ldr r0, _080CC3DC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080CC3CC
	movs r2, #1
_080CC3CC:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CC3E0
	cmp r2, #0
	beq _080CC3E4
	b _080CC4C4
	.align 2, 0
_080CC3DC: .4byte pZero2
_080CC3E0:
	cmp r2, #0
	beq _080CC4C4
_080CC3E4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080CC4C2
_080CC3EA:
	ldr r1, _080CC418 @ =0x00003803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC3FC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080CC4C4
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080CC41C
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080CC4CA
	.align 2, 0
_080CC418: .4byte 0x00003803
_080CC41C:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080CC42E
	movs r0, #0x10
	orrs r0, r2
	b _080CC432
_080CC42E:
	movs r0, #0xef
	ands r0, r2
_080CC432:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _080CC464 @ =0x00003808
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080CC4C4
	.align 2, 0
_080CC464: .4byte 0x00003808
_080CC468:
	ldr r1, [r4, #0x54]
	ldr r0, _080CC4D0 @ =0xFFFFE800
	adds r5, r1, r0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080CC47E
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r5, r1, r0
_080CC47E:
	ldr r3, [r4, #0x58]
	ldr r0, _080CC4D4 @ =0xFFFFF700
	adds r1, r3, r0
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080CC492
	movs r0, #0x90
	lsls r0, r0, #4
	adds r1, r3, r0
_080CC492:
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateHeavyCannonBall
	ldr r1, _080CC4D8 @ =0x00003802
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC4AC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080CC4C4
	movs r0, #0x70
	strb r0, [r4, #0x12]
	movs r0, #1
_080CC4C2:
	strb r0, [r4, #0xe]
_080CC4C4:
	adds r0, r4, #0
	bl FUN_080cbe38
_080CC4CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC4D0: .4byte 0xFFFFE800
_080CC4D4: .4byte 0xFFFFF700
_080CC4D8: .4byte 0x00003802

