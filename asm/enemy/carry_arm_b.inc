	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807156c
FUN_0807156c: @ 0x0807156C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08071582
	movs r0, #0
	b _080715A0
_08071582:
	ldr r1, _080715A4 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl CarryArm_Die
	movs r0, #1
_080715A0:
	pop {r1}
	bx r1
	.align 2, 0
_080715A4: .4byte gEnemyFnTable

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

	thumb_func_start CarryArm_Update
CarryArm_Update: @ 0x08071654
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807156c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08071682
	ldr r1, _08071688 @ =0x08366B48
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807168C @ =0x08366B60
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08071682:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08071688: .4byte 0x08366B48
_0807168C: .4byte 0x08366B60

	thumb_func_start CarryArm_Die
CarryArm_Die: @ 0x08071690
	push {lr}
	ldr r2, _080716A4 @ =0x08366B78
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080716A4: .4byte 0x08366B78
