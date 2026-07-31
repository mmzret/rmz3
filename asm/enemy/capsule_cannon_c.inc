	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08085a14
FUN_08085a14: @ 0x08085A14
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08085A44
	cmp r0, #1
	bgt _08085A28
	cmp r0, #0
	beq _08085A32
	b _08085A90
_08085A28:
	cmp r0, #2
	beq _08085A60
	cmp r0, #3
	beq _08085A78
	b _08085A90
_08085A32:
	ldr r1, _08085A5C @ =0x00006801
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08085A44:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08085A90
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08085A90
	.align 2, 0
_08085A5C: .4byte 0x00006801
_08085A60:
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08085A98 @ =0x08368488
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08085A78:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08085A88
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08085A90
_08085A88:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08085A90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085A98: .4byte 0x08368488
