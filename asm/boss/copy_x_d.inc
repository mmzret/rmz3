	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start copyx_080569e4
copyx_080569e4: @ 0x080569E4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080569FA
	ldr r1, _08056A7C @ =0x0000B30D
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r5, #0xe]
_080569FA:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08056A76
	movs r4, #0
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	movs r0, #0x1d
	strb r0, [r5, #0xf]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #2
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #3
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #4
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #5
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #6
	bl FUN_080a88a4
	adds r0, r5, #0
	movs r1, #4
	movs r2, #7
	bl FUN_080a88a4
	adds r0, r5, #0
	adds r0, #0xc6
	strb r4, [r0]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	movs r0, #0x46
	bl PlaySound
_08056A76:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08056A7C: .4byte 0x0000B30D

