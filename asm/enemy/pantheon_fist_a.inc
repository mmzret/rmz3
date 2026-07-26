	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonFist_Init
PantheonFist_Init: @ 0x08095200
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0x10]
	cmp r1, #1
	bne _08095212
	movs r0, #0
	strb r0, [r5, #0x10]
	strb r1, [r5, #0x11]
	b _08095216
_08095212:
	movs r0, #0
	strb r0, [r5, #0x11]
_08095216:
	ldr r1, _0809527C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08095280 @ =0x0836A06C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08095284 @ =0x08369FD4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08095288 @ =nop_080950cc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _0809528C
	adds r0, r5, #0
	adds r0, #0xb8
	strb r6, [r0]
	b _0809529E
	.align 2, 0
_0809527C: .4byte gEnemyFnTable
_08095280: .4byte 0x0836A06C
_08095284: .4byte sCollisions
_08095288: .4byte nop_080950cc
_0809528C:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_0809529E:
	movs r2, #0
	ldr r0, _080952BC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080952AE
	movs r2, #1
_080952AE:
	cmp r2, #0
	beq _080952C0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080952C6
	.align 2, 0
_080952BC: .4byte pZero2
_080952C0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080952C6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	bl PantheonFist_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
