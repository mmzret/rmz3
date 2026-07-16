	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Petatria_Init
Petatria_Init: @ 0x0808FED4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808FF14 @ =nop_0809127c
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x4c
	str r2, [r0]
	subs r0, #7
	strb r2, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0808FF50
	ldr r0, _0808FF18 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r6, #0x54]
	cmp r2, r0
	ble _0808FF1C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FF1E
	.align 2, 0
_0808FF14: .4byte nop_0809127c
_0808FF18: .4byte pZero2
_0808FF1C:
	movs r0, #0xcc
_0808FF1E:
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0808FF4C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	b _0808FFE6
	.align 2, 0
_0808FF4C: .4byte gEnemyFnTable
_0808FF50:
	cmp r0, #0
	bne _0808FF74
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, _0808FF6C @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, _0808FF70 @ =0xFFFFE000
	b _0808FFAE
	.align 2, 0
_0808FF6C: .4byte 0xFFFFF600
_0808FF70: .4byte 0xFFFFE000
_0808FF74:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	movs r1, #0x80
	lsls r1, r1, #6
_0808FFAE:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _0808FFC4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0808FFC8
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FFCA
	.align 2, 0
_0808FFC4: .4byte pZero2
_0808FFC8:
	movs r0, #0xcc
_0808FFCA:
	str r0, [r6, #0x60]
	ldr r1, _0809000C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
_0808FFE6:
	adds r0, r6, #0
	bl IsFrozen
	adds r5, r0, #0
	cmp r5, #0
	beq _08090060
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08090014
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090010 @ =0x08369608
	b _08090024
	.align 2, 0
_0809000C: .4byte gEnemyFnTable
_08090010: .4byte sCollisions
_08090014:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090048 @ =0x08369638
_08090024:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809004C
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	b _08090054
	.align 2, 0
_08090048: .4byte sCollisions+(2*24)
_0809004C:
	ldr r1, _0809005C @ =0x00007E06
	adds r0, r6, #0
	bl SetMotion
_08090054:
	adds r0, r6, #0
	bl UpdateEntityAnim
	b _0809009A
	.align 2, 0
_0809005C: .4byte 0x00007E06
_08090060:
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809007C
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090078 @ =0x08369608
	b _0809008A
	.align 2, 0
_08090078: .4byte sCollisions
_0809007C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080900A8 @ =0x08369638
_0809008A:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_0809009A:
	adds r0, r6, #0
	bl Petatria_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080900A8: .4byte sCollisions+(2*24)

