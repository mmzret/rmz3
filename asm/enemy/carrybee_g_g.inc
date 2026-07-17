	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808b41c
FUN_0808b41c: @ 0x0808B41C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r2, #0xc]
	cmp r0, #2
	bls _0808B442
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	b _0808B46A
_0808B442:
	ldr r0, _0808B48C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808B494
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
_0808B46A:
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808B490 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	bl CarrybeeG_Die
	b _0808B52E
	.align 2, 0
_0808B48C: .4byte gCurStory
_0808B490: .4byte gEnemyFnTable
_0808B494:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0808B4D0
	cmp r5, #1
	bgt _0808B4A4
	cmp r5, #0
	beq _0808B4AA
	b _0808B52E
_0808B4A4:
	cmp r5, #2
	beq _0808B4F8
	b _0808B52E
_0808B4AA:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0808B4F0 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B4F4 @ =0x08368C54
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B4D0:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808B52E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B52E
	.align 2, 0
_0808B4F0: .4byte 0x00006E06
_0808B4F4: .4byte 0x08368C54
_0808B4F8:
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B518
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0808B51E
_0808B518:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808B51E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808B52E:
	pop {r4, r5}
	pop {r0}
	bx r0

