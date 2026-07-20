	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blazin_080403a0
blazin_080403a0: @ 0x080403A0
	push {lr}
	cmp r1, #0
	bne _080403AA
	adds r0, #0xd4
	b _080403BC
_080403AA:
	cmp r1, #1
	bne _080403B2
	adds r0, #0xd8
	b _080403BC
_080403B2:
	cmp r1, #2
	beq _080403BA
	adds r0, #0xe0
	b _080403BC
_080403BA:
	adds r0, #0xdc
_080403BC:
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0

