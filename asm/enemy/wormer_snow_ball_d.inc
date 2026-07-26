	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807b800
FUN_0807b800: @ 0x0807B800
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0807B854 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _0807B858 @ =0x0000270E
	cmp r1, r0
	bhi _0807B812
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807B812:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	bl TryDropZakoDisk
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl CreateIceballParticle4
	ldr r1, _0807B85C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B854: .4byte gScore
_0807B858: .4byte 0x0000270E
_0807B85C: .4byte gEnemyFnTable

