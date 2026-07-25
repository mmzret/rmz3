	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b970c
FUN_080b970c: @ 0x080B970C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B972E
	ldr r1, _080B9734 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080B972E:
	pop {r0}
	bx r0
	.align 2, 0
_080B9734: .4byte gVFXFnTable

	thumb_func_start FUN_080b9738
FUN_080b9738: @ 0x080B9738
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r5, #0xff
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080B9754
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080B97E0
_080B9754:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B9760
	cmp r0, #1
	beq _080B97AA
	b _080B97E0
_080B9760:
	ldr r2, _080B97E8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080B97EC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080B97F0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	strb r0, [r4, #0x13]
	ands r0, r5
	adds r2, r4, #0
	adds r2, #0x24
	strb r0, [r2]
	adds r3, r4, #0
	adds r3, #0x50
	movs r1, #0
	movs r0, #0x80
	strh r0, [r3]
	movs r5, #0x52
	strh r0, [r5, r4]
	strb r1, [r2]
	adds r0, #0x80
	strh r0, [r3]
	strh r0, [r5, r4]
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B97AA:
	ldr r2, [r4, #0x5c]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B97CA
	str r1, [r4, #0x60]
_080B97CA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080B97E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B97E8: .4byte RNG_0202f388
_080B97EC: .4byte 0x000343FD
_080B97F0: .4byte 0x00269EC3


