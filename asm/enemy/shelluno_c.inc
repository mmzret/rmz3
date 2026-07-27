	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807a01c
FUN_0807a01c: @ 0x0807A01C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807A036
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A05C @ =0x083675E4
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807A036:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807A056
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0807A060 @ =0x083675CC
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807A056:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A05C: .4byte 0x083675E4
_0807A060: .4byte 0x083675CC
