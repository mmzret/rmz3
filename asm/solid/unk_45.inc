	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid45_Die
Solid45_Die: @ 0x080DE7B4
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldrb r2, [r0, #0xb]
	movs r1, #0xf7
	ands r1, r2
	strb r1, [r0, #0xb]
	ldr r2, _080DE7D8 @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080DE7D8: .4byte gSolidFnTable
