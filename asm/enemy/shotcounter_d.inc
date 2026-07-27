	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08066adc
FUN_08066adc: @ 0x08066ADC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _08066AF6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B28 @ =0x08365E24
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066AF6:
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r0, [r4]
	bl isKilled
	cmp r0, #0
	beq _08066B20
	adds r1, r5, #0
	adds r1, #0xbf
	movs r0, #0
	strb r0, [r1]
	str r0, [r4]
	movs r4, #1
	strb r4, [r5, #0xd]
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066B2C @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0xe]
_08066B20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08066B28: .4byte sCollisions+(24*8)
_08066B2C: .4byte sCollisions+(24*7)
