	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08093930
FUN_08093930: @ 0x08093930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809398C @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08093984
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093990 @ =gEnemyFnTable
	movs r1, #0x3e
	strb r1, [r3, #9]
	adds r0, #0xf8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xbd
	strb r4, [r0]
_08093984:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809398C: .4byte gEnemyHeaderPtr
_08093990: .4byte gEnemyFnTable

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
