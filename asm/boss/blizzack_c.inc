	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start blizzackMode1
blizzackMode1: @ 0x08059E00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08059E2A
	ldr r1, _08059E54 @ =0x0000B401
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x2c]
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r0, [r4, #0x2c]
	adds r0, #0xbc
	movs r2, #0
	ldr r1, _08059E58 @ =0x00006401
	strh r1, [r0]
	strb r2, [r4, #0xe]
	movs r0, #0x42
	bl PlaySound
_08059E2A:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08059E4E
	ldr r0, _08059E5C @ =gStageRun
	ldrb r1, [r0, #0x12]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08059E4E
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08059E4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08059E54: .4byte 0x0000B401
_08059E58: .4byte 0x00006401
_08059E5C: .4byte gStageRun

