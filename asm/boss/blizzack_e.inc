	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackNextMode
blizzackNextMode: @ 0x0805A1E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805A20A
	ldr r1, _0805A228 @ =0x0000B402
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _0805A22C @ =0x00006402
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #0x42
	bl PlaySound
_0805A20A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0805A222
	ldrb r0, [r4, #0xf]
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_0805A222:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805A228: .4byte 0x0000B402
_0805A22C: .4byte 0x00006402

