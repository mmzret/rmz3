	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080950d0
FUN_080950d0: @ 0x080950D0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809511C
	ldr r1, _08095110 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08095114
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08095116
	strb r4, [r2, #0xd]
	b _08095118
	.align 2, 0
_08095110: .4byte gEnemyFnTable
_08095114:
	movs r0, #1
_08095116:
	strb r0, [r2, #0xd]
_08095118:
	movs r0, #1
	b _0809511E
_0809511C:
	movs r0, #0
_0809511E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095124
FUN_08095124: @ 0x08095124
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080951AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080951AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08095144
	cmp r0, #1
	beq _08095188
	b _080951AA
_08095144:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080951AA
	ldr r1, _08095180 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08095184 @ =0x08369FA4
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
_0809517A:
	movs r0, #1
	b _080951AC
	.align 2, 0
_08095180: .4byte 0x08369F80
_08095184: .4byte 0x08369FA4
_08095188:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _080951A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080951A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809517A
	strb r5, [r4, #0xf]
	b _080951AA
	.align 2, 0
_080951A4: .4byte 0x00020001
_080951A8:
	strb r0, [r4, #0xf]
_080951AA:
	movs r0, #0
_080951AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080951b4
FUN_080951b4: @ 0x080951B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080951F4
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080951F4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080951E0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080951F4
_080951E0:
	ldr r2, _080951FC @ =0x0836A064
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080951F4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080951F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080951FC: .4byte 0x0836A064

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

	thumb_func_start PantheonFist_Update
PantheonFist_Update: @ 0x080952F0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080950d0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	adds r0, r4, #0
	bl FUN_080951b4
	adds r0, r4, #0
	bl FUN_08095124
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	ldr r1, _08095338 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809533C @ =0x08369FA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08095330:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095338: .4byte 0x08369F80
_0809533C: .4byte 0x08369FA4

	thumb_func_start PantheonFist_Die
PantheonFist_Die: @ 0x08095340
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08095394
	ldr r0, _0809538C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08095394
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
	ldr r1, _08095390 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080953A4
	.align 2, 0
_0809538C: .4byte gCurStory
_08095390: .4byte gEnemyFnTable
_08095394:
	ldr r0, _080953A8 @ =0x08369FC8
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080953A4:
	pop {r0}
	bx r0
	.align 2, 0
_080953A8: .4byte 0x08369FC8
