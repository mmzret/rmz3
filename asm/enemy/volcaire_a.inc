	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080772f8
FUN_080772f8: @ 0x080772F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0807737E
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0807737E
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08077318
	cmp r0, #1
	beq _0807735C
	b _0807737E
_08077318:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807737E
	ldr r1, _08077354 @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08077358 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0807734E:
	movs r0, #1
	b _08077380
	.align 2, 0
_08077354: .4byte sUpdates1
_08077358: .4byte sUpdates2
_0807735C:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0807737C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08077378 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0807734E
	strb r5, [r4, #0xf]
	b _0807737E
	.align 2, 0
_08077378: .4byte 0x00020001
_0807737C:
	strb r0, [r4, #0xf]
_0807737E:
	movs r0, #0
_08077380:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
