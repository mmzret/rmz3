	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ae140
FUN_080ae140: @ 0x080AE140
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _080AE17C
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
	ldr r1, _080AE178 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080AE1F6
	.align 2, 0
_080AE178: .4byte gProjectileFnTable
_080AE17C:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080AE1A2
	cmp r5, #1
	bgt _080AE18C
	cmp r5, #0
	beq _080AE192
	b _080AE1F6
_080AE18C:
	cmp r5, #2
	beq _080AE1C8
	b _080AE1F6
_080AE192:
	ldr r1, _080AE1C4 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080AE1A2:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080AE1F6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080AE1F6
	.align 2, 0
_080AE1C4: .4byte 0x00006E06
_080AE1C8:
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE1E8
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _080AE1EE
_080AE1E8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080AE1EE:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080AE1F6:
	pop {r4, r5}
	pop {r0}
	bx r0
