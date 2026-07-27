	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808c334
FUN_0808c334: @ 0x0808C334
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0808C344
	cmp r3, #1
	beq _0808C364
	b _0808C380
_0808C344:
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	str r3, [r2, #0x5c]
	str r3, [r2, #0x60]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_0808C364:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	cmp r0, #0x40
	ble _0808C372
	movs r0, #0x40
	str r0, [r2, #0x60]
_0808C372:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0
	bl UpdateEntityAnim
_0808C380:
	pop {r0}
	bx r0
