	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start tretista_0804e020
tretista_0804e020: @ 0x0804E020
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0804E030
	cmp r5, #1
	beq _0804E048
	b _0804E07E
_0804E030:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0804E084 @ =0x0000AB09
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0804E048:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0804E064
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0804E064
	strb r2, [r4, #0x12]
	movs r0, #0xd4
	bl PlaySound
_0804E064:
	ldr r0, _0804E088 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0804E078
	strb r1, [r4, #0x12]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0804E078:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0804E07E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E084: .4byte 0x0000AB09
_0804E088: .4byte gStageRun
