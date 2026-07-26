	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093994
FUN_08093994: @ 0x08093994
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080939E0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080939DA
	adds r2, r4, #0
	adds r2, #0x25
	movs r3, #0
	movs r1, #0x18
	strb r1, [r2]
	ldr r1, _080939E4 @ =gEnemyFnTable
	movs r2, #0x3e
	strb r2, [r4, #9]
	adds r1, #0xf8
	ldr r1, [r1]
	ldr r1, [r1]
	str r1, [r4, #0x14]
	movs r1, #0
	strh r3, [r4, #0x20]
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	ldrb r2, [r4, #0xb]
	movs r1, #0x10
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r1, [r4, #0x1c]
	strb r1, [r4, #0x1d]
	movs r1, #1
	strb r1, [r4, #0x10]
	str r5, [r4, #0x28]
_080939DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080939E0: .4byte gEnemyHeaderPtr
_080939E4: .4byte gEnemyFnTable
