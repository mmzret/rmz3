	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Claveker_Init
Claveker_Init: @ 0x0808E52C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _0808E578 @ =gSystemSavedata
	ldrb r1, [r0, #0x13]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808E584
	ldr r0, _0808E57C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808E584
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E580 @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	b _0808E59C
	.align 2, 0
_0808E578: .4byte gSystemSavedata
_0808E57C: .4byte gCurStory
_0808E580: .4byte 0x08369388
_0808E584:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E60C @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
_0808E59C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808E610 @ =FUN_0808f234
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r4, #0
	strb r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r1, _0808E614 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808E5F8
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_0808E5F8:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r6, #0
	bl Claveker_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E60C: .4byte 0x08369388
_0808E610: .4byte FUN_0808f234
_0808E614: .4byte gEnemyFnTable

