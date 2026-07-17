	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start OmegaGoldSword_Init
OmegaGoldSword_Init: @ 0x0808B7FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	movs r5, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r2, #1
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xa]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0808B8A4 @ =0x08368DC4
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	ldr r0, _0808B8A8 @ =nop_0808c384
	str r0, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	ldr r1, _0808B8AC @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _0808B8B0 @ =0xFFFFED00
	str r0, [r1]
	adds r1, #4
	ldr r0, _0808B8B4 @ =0xFFFFC600
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r5, [r0]
	ldrb r1, [r7, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	bl OmegaGoldSword_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B8A4: .4byte 0x08368DC4
_0808B8A8: .4byte nop_0808c384
_0808B8AC: .4byte gEnemyFnTable
_0808B8B0: .4byte 0xFFFFED00
_0808B8B4: .4byte 0xFFFFC600

