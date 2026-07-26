	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08016080
FUN_08016080: @ 0x08016080
	ldr r1, _0801608C @ =gOverworld
	ldr r2, _08016090 @ =0x0002D034
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0801608C: .4byte gOverworld
_08016090: .4byte 0x0002D034

	thumb_func_start FUN_08016094
FUN_08016094: @ 0x08016094
	push {r4, r5, lr}
	ldr r3, _080160B0 @ =gOverworld
	ldr r5, _080160B4 @ =0x0002D040
	adds r4, r3, r5
	str r0, [r4]
	ldr r4, _080160B8 @ =0x0002D044
	adds r0, r3, r4
	str r1, [r0]
	adds r5, #8
	adds r3, r3, r5
	str r2, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080160B0: .4byte gOverworld
_080160B4: .4byte 0x0002D040
_080160B8: .4byte 0x0002D044

