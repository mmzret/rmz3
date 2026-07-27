	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808a0ec
FUN_0808a0ec: @ 0x0808A0EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808A138 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A130
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A13C @ =gEnemyFnTable
	movs r1, #0x31
	strb r1, [r4, #9]
	adds r0, #0xc4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
_0808A130:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808A138: .4byte gEnemyHeaderPtr
_0808A13C: .4byte gEnemyFnTable
