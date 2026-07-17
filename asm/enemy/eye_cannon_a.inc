	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08084744
FUN_08084744: @ 0x08084744
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _080847B0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808475C
	cmp r0, #1
	beq _080847A0
	b _080847B0
_0808475C:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080847B0
	ldr r1, _08084798 @ =0x083682DC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808479C @ =0x083682F4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #1
	b _080847B2
	.align 2, 0
_08084798: .4byte 0x083682DC
_0808479C: .4byte 0x083682F4
_080847A0:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080847AE
	movs r0, #1
	b _080847B2
_080847AE:
	strb r0, [r4, #0xf]
_080847B0:
	movs r0, #0
_080847B2:
	pop {r4}
	pop {r1}
	bx r1

