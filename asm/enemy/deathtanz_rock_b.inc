	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start DeathtanzRock_Init
DeathtanzRock_Init: @ 0x0807A5FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0807A660 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0807A664 @ =0x08367742
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
	cmp r0, #0
	bne _0807A66C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A668 @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x14
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #3
	strb r0, [r1]
	b _0807A68A
	.align 2, 0
_0807A660: .4byte gEnemyFnTable
_0807A664: .4byte 0x08367742
_0807A668: .4byte 0x08367664
_0807A66C:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807A69C @ =0x08367664
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_0807A68A:
	ldr r0, _0807A6A0 @ =nop_0807a5bc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl DeathtanzRock_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807A69C: .4byte 0x08367664
_0807A6A0: .4byte nop_0807a5bc

	thumb_func_start DeathtanzRock_Update
DeathtanzRock_Update: @ 0x0807A6A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807a5c0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807A6D2
	ldr r1, _0807A6D8 @ =0x08367648
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807A6DC @ =0x08367654
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0

	non_word_aligned_thumb_func_start FUN_0807a6ce
FUN_0807a6ce: @ 0x0807A6CE
	bl _call_via_r1
_0807A6D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A6D8: .4byte 0x08367648
_0807A6DC: .4byte 0x08367654

