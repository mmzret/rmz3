	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start hibou_080da098
hibou_080da098: @ 0x080DA098
	push {lr}
	ldr r2, _080DA0B8 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA0C4
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bhi _080DA0BC
	movs r0, #3
	strb r0, [r2, #0x11]
	movs r0, #0x94
	lsls r0, r0, #2
	b _080DA10E
	.align 2, 0
_080DA0B8: .4byte gCurStory
_080DA0BC:
	ldr r0, _080DA0C0 @ =0x00000251
	b _080DA10E
	.align 2, 0
_080DA0C0: .4byte 0x00000251
_080DA0C4:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DA0F4
	ldr r0, _080DA0E4 @ =gStageDiskManager
	ldr r0, [r0]
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DA0EC
	ldr r0, _080DA0E8 @ =0x0000024F
	b _080DA10E
	.align 2, 0
_080DA0E4: .4byte gStageDiskManager
_080DA0E8: .4byte 0x0000024F
_080DA0EC:
	ldr r0, _080DA0F0 @ =0x0000024E
	b _080DA10E
	.align 2, 0
_080DA0F0: .4byte 0x0000024E
_080DA0F4:
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	beq _080DA108
	movs r0, #2
	strb r0, [r2, #0x11]
	ldr r0, _080DA104 @ =0x0000024D
	b _080DA10E
	.align 2, 0
_080DA104: .4byte 0x0000024D
_080DA108:
	strb r3, [r2, #0x11]
	movs r0, #0x93
	lsls r0, r0, #2
_080DA10E:
	pop {r1}
	bx r1
	.align 2, 0
