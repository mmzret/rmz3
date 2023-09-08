	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Ghost29_Update
Ghost29_Update: @ 0x080BA2D4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080cb528
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080BA300
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BA308 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BA300:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BA308: .4byte gVFXFnTable

	thumb_func_start Ghost29_Die
Ghost29_Die: @ 0x080BA30C
	bx lr
	.align 2, 0
