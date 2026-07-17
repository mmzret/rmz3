	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Mellnet_Die
Mellnet_Die: @ 0x0807D924
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x10]
	cmp r3, #0
	bne _0807D978
	ldr r0, _0807D970 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0807D978
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _0807D974 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _0807D988
	.align 2, 0
_0807D970: .4byte gCurStory
_0807D974: .4byte gEnemyFnTable
_0807D978:
	ldr r0, _0807D98C @ =0x08367CD0
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_0807D988:
	pop {r0}
	bx r0
	.align 2, 0
_0807D98C: .4byte 0x08367CD0

