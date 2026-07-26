	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CarryArm_Init
CarryArm_Init: @ 0x080715A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _08071614 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08071618 @ =0x08366BB0
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08071620
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807161C @ =0x08366B98
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	str r6, [r5, #0x28]
	str r6, [r5, #0x2c]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	b _08071640
	.align 2, 0
_08071614: .4byte gEnemyFnTable
_08071618: .4byte 0x08366BB0
_0807161C: .4byte 0x08366B98
_08071620:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807164C @ =0x08366B80
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08071650 @ =nop_08071568
	str r0, [r4, #0x24]
_08071640:
	adds r0, r5, #0
	bl CarryArm_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807164C: .4byte 0x08366B80
_08071650: .4byte nop_08071568

