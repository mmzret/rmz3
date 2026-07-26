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
