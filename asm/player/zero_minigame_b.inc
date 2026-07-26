	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08036870
FUN_08036870: @ 0x08036870
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080368A0
	cmp r0, #1
	bgt _08036884
	cmp r0, #0
	beq _0803688E
	b _080368FC
_08036884:
	cmp r0, #2
	beq _080368C2
	cmp r0, #3
	beq _080368DE
	b _080368FC
_0803688E:
	adds r0, r4, #0
	movs r1, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080368A0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080368D2
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080368D6
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080368FC
	b _080368D6
_080368C2:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080368FC
_080368D2:
	movs r0, #0xa
	strb r0, [r4, #0x12]
_080368D6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080368FC
_080368DE:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080368F4
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080368FC
_080368F4:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080368FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

