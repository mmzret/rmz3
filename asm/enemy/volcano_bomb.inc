	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080713ec
FUN_080713ec: @ 0x080713EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080713FC
	cmp r5, #1
	beq _08071418
	b _08071460
_080713FC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08071468 @ =0x08366AF8
	bl SetDDP
	str r5, [r4, #0x60]
	movs r1, #0xf8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08071418:
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08071428
	str r1, [r4, #0x60]
_08071428:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0807145A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _0807146C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0807145A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08071460:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071468: .4byte sCollisions+24
_0807146C: .4byte gEnemyFnTable
