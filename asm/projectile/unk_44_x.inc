	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b1764
FUN_080b1764: @ 0x080B1764
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B1790 @ =0x0836D794
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080B1794 @ =0x0836D798
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1790: .4byte 0x0836D794
_080B1794: .4byte 0x0836D798

