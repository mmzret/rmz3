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

	thumb_func_start nop_0808a140
nop_0808a140: @ 0x0808A140
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808a144
FUN_0808a144: @ 0x0808A144
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808A18C
	ldr r1, _0808A17C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808A180
	movs r0, #1
	strb r0, [r2, #0xd]
	b _0808A182
	.align 2, 0
_0808A17C: .4byte gEnemyFnTable
_0808A180:
	strb r1, [r2, #0xd]
_0808A182:
	adds r0, r2, #0
	bl PantheonBase_Die
	movs r0, #1
	b _0808A18E
_0808A18C:
	movs r0, #0
_0808A18E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start pBase_0808a194
pBase_0808a194: @ 0x0808A194
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _0808A208
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808A1AE
	cmp r0, #1
	beq _0808A1F0
	b _0808A208
_0808A1AE:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808A208
	ldr r1, _0808A1E8 @ =0x0836896C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808A1EC @ =0x08368974
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
	movs r0, #1
	b _0808A20A
	.align 2, 0
_0808A1E8: .4byte 0x0836896C
_0808A1EC: .4byte 0x08368974
_0808A1F0:
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808A206
	movs r0, #1
	b _0808A20A
_0808A206:
	strb r0, [r4, #0xf]
_0808A208:
	movs r0, #0
_0808A20A:
	pop {r4}
	pop {r1}
	bx r1
