	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c5530
FUN_080c5530: @ 0x080C5530
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C5540
	cmp r0, #1
	beq _080C5574
	b _080C55AA
_080C5540:
	ldr r2, _080C55B0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C55B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C55B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	bl __umodsi3
	strb r0, [r4, #0x13]
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C5574:
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
	ble _080C5594
	str r1, [r4, #0x60]
_080C5594:
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
_080C55AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C55B0: .4byte RNG_0202f388
_080C55B4: .4byte 0x000343FD
_080C55B8: .4byte 0x00269EC3

	thumb_func_start FUN_080c55bc
FUN_080c55bc: @ 0x080C55BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C55CC
	cmp r0, #1
	beq _080C55D6
	b _080C561E
_080C55CC:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C55D6:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C55EC
	str r1, [r4, #0x60]
_080C55EC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080C560C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C561E
_080C560C:
	ldr r1, _080C5624 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080C561E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C5624: .4byte gVFXFnTable
