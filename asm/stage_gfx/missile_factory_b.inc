	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800f874
FUN_0800f874: @ 0x0800F874
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #0xe]
	cmp r2, #0
	bne _0800F88A
	movs r0, #0xc0
	str r0, [r1, #0x44]
	ldr r0, _0800F890 @ =0x000006CC
	str r0, [r1, #0x4c]
	adds r0, r2, #1
	strb r0, [r1, #0xe]
_0800F88A:
	pop {r0}
	bx r0
	.align 2, 0
_0800F890: .4byte 0x000006CC

	thumb_func_start FUN_0800f894
FUN_0800f894: @ 0x0800F894
	ldr r1, _0800F8A0 @ =gOverworld
	ldr r2, _0800F8A4 @ =0x0002D038
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0800F8A0: .4byte gOverworld
_0800F8A4: .4byte 0x0002D038
