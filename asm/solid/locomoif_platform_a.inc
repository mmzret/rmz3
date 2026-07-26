	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ce538
FUN_080ce538: @ 0x080CE538
	push {r4, r5, r6, r7, lr}
	ldr r5, [r0, #0x28]
	ldr r3, [r5, #0x54]
	str r3, [r0, #0x54]
	ldr r6, _080CE584 @ =gSineTable
	adds r4, r0, #0
	adds r4, #0xb4
	ldrh r1, [r4]
	lsrs r1, r1, #8
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r6
	movs r7, #0
	ldrsh r2, [r1, r7]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r3, r3, r1
	str r3, [r0, #0x54]
	ldr r3, [r5, #0x58]
	ldr r1, _080CE588 @ =0xFFFFF000
	adds r3, r3, r1
	str r3, [r0, #0x58]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r4, #0
	ldrsh r2, [r1, r4]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r3, r3, r1
	str r3, [r0, #0x58]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE584: .4byte gSineTable
_080CE588: .4byte 0xFFFFF000

	thumb_func_start nop_080ce58c
nop_080ce58c: @ 0x080CE58C
	bx lr
	.align 2, 0
