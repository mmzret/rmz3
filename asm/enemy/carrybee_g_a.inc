	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CarrybeeG_Init
CarrybeeG_Init: @ 0x0808A908
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _0808A974 @ =nop_0808b534
	adds r4, r6, #0
	adds r4, #0x74
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808a8b0
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r1, r6, #0
	adds r1, #0xc3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0808A978 @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808A984
	ldr r0, _0808A97C @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808A984
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808A980 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	b _0808A99C
	.align 2, 0
_0808A974: .4byte nop_0808b534
_0808A978: .4byte gSystemSavedata
_0808A97C: .4byte gCurStory
_0808A980: .4byte 0x08368C6C
_0808A984:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A9F8 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x30
_0808A99C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	str r2, [r6, #0x2c]
	str r2, [r6, #0x28]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r1, _0808A9FC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x14
	strb r0, [r1]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808AA5C
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _0808AA5C
	.align 2, 0
_0808A9F8: .4byte 0x08368C6C
_0808A9FC: .4byte gEnemyFnTable
_0808AA00:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808AA88 @ =0x08368C54
	bl SetDDP
	ldr r1, _0808AA8C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	adds r0, r6, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808AA5C
	ldrb r0, [r6, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r1, _0808AA90 @ =0x00006E06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateEntityAnim
_0808AA5C:
	movs r0, #0
	strb r0, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA72
	ldr r1, _0808AA94 @ =gOverworld
	ldr r0, _0808AA98 @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0808AA72:
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	bl CarrybeeG_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AA88: .4byte 0x08368C54
_0808AA8C: .4byte gEnemyFnTable
_0808AA90: .4byte 0x00006E06
_0808AA94: .4byte gOverworld
_0808AA98: .4byte 0x0002D02C

