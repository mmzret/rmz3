	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808b708
FUN_0808b708: @ 0x0808B708
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808B718
	cmp r0, #1
	beq _0808B72E
	b _0808B78E
_0808B718:
	str r0, [r4, #0x60]
	movs r0, #0x10
	strb r0, [r4, #0x12]
	movs r1, #0xed
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B72E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808B73E
	str r1, [r4, #0x60]
_0808B73E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0808B76A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B788
	ldrb r1, [r4, #0x13]
	cmp r1, #1
	bhi _0808B788
	ldr r0, [r4, #0x64]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateOzChargeSaberRock
	b _0808B788
_0808B76A:
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808B788
	ldr r1, _0808B794 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0808B788:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808B78E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B794: .4byte gEnemyFnTable
