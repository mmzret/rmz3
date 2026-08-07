	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start carrybeeg_0808b00c
carrybeeg_0808b00c: @ 0x0808B00C
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r0, _0808B02C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B030 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _0808B034
	cmp r0, #1
	beq _0808B03E
	b _0808B100
	.align 2, 0
_0808B02C: .4byte gStageRun+232
_0808B030: .4byte 0xFFFFC000
_0808B034:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0808B03E:
	ldrb r0, [r3, #0x12]
	adds r4, r0, #1
	strb r4, [r3, #0x12]
	adds r0, r3, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3, #0x68]
	ldr r2, _0808B0D0 @ =gSineTable
	ldrb r0, [r3, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	cmp r0, #0
	beq _0808B07A
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B0EA
_0808B07A:
	adds r0, r3, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x28]
	cmp r0, #0
	bne _0808B0E4
_0808B090:
	ldr r0, _0808B0D4 @ =gEnemyHeaderPtr
	ldr r1, [r0]
	movs r2, #8
	ldrsh r0, [r1, r2]
	movs r5, #0xa
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #5
	bgt _0808B0E4
	ldr r2, _0808B0D8 @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #0x42
	ands r0, r1
	cmp r0, #0
	bne _0808B0E4
	ldrb r1, [r2, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808B0C6
	ldr r0, _0808B0DC @ =gSystemSavedata
	ldr r1, [r0, #0x40]
	ldr r0, _0808B0E0 @ =0x000032DA
	cmp r1, r0
	beq _0808B0C6
	cmp r1, #0
	bne _0808B0E4
_0808B0C6:
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	b _0808B0FA
	.align 2, 0
_0808B0D0: .4byte gSineTable
_0808B0D4: .4byte gEnemyHeaderPtr
_0808B0D8: .4byte gCurStory
_0808B0DC: .4byte gSystemSavedata
_0808B0E0: .4byte 0x000032DA
_0808B0E4:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	b _0808B0FA
_0808B0EA:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0808B0FA
	movs r0, #3
	strb r0, [r3, #0xd]
	movs r0, #0
	strb r0, [r3, #0xe]
_0808B0FA:
	adds r0, r3, #0
	bl UpdateEntityAnim
_0808B100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

