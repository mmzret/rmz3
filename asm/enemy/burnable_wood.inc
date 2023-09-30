	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start BurnableWood_Init
BurnableWood_Init: @ 0x0807D610
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0807D664 @ =0x00000801
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807D646
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _0807D668 @ =0x08367C7C
	str r0, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x26]
_0807D646:
	ldr r1, _0807D66C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl BurnableWood_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D664: .4byte 0x00000801
_0807D668: .4byte 0x08367C7C
_0807D66C: .4byte gEnemyFnTable

	thumb_func_start BurnableWood_Update
BurnableWood_Update: @ 0x0807D670
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800e284
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807D69C
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _0807D6A4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0807D69C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D6A4: .4byte gEnemyFnTable

	thumb_func_start BurnableWood_Die
BurnableWood_Die: @ 0x0807D6A8
	ldr r2, _0807D6BC @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0807D6BC: .4byte gEnemyFnTable
