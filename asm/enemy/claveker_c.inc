	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808eb24
FUN_0808eb24: @ 0x0808EB24
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808EB5C
	cmp r0, #1
	bgt _0808EB38
	cmp r0, #0
	beq _0808EB3E
	b _0808EBAA
_0808EB38:
	cmp r0, #2
	beq _0808EB90
	b _0808EBAA
_0808EB3E:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EB84 @ =0x08369388
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EB5C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _0808EB88 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl Camera_GetDistance
	ldr r1, _0808EB8C @ =0x00003FFF
	cmp r0, r1
	bhi _0808EBAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a134
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EBAA
	.align 2, 0
_0808EB84: .4byte 0x08369388
_0808EB88: .4byte gStageRun+232
_0808EB8C: .4byte 0x00003FFF
_0808EB90:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808EBAA
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EBAA:
	pop {r4}
	pop {r0}
	bx r0

