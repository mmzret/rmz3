	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Enemy61_Init
Enemy61_Init: @ 0x08093630
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080936A0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080936A4 @ =0x08369E00
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080936A8 @ =0x08369D40
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080936AC @ =onCollision
	str r0, [r5, #0x24]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	str r0, [r2]
	adds r0, r4, #0
	bl Enemy61_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080936A0: .4byte gEnemyFnTable
_080936A4: .4byte 0x08369E00
_080936A8: .4byte 0x08369D40
_080936AC: .4byte onCollision

	thumb_func_start Enemy61_Update
Enemy61_Update: @ 0x080936B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080936D4
	ldr r1, _080936D0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080936F4
	.align 2, 0
_080936D0: .4byte gEnemyFnTable
_080936D4:
	ldr r1, _080936FC @ =0x08369D38
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093700 @ =0x08369D3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080936F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080936FC: .4byte 0x08369D38
_08093700: .4byte 0x08369D3C

	thumb_func_start Enemy61_Die
Enemy61_Die: @ 0x08093704
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	beq _08093716
	cmp r1, #1
	beq _08093732
	b _0809374A
_08093716:
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08093732:
	ldrb r0, [r3, #0xc]
	cmp r0, #2
	bls _0809374A
	ldr r1, _08093750 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
_0809374A:
	pop {r0}
	bx r0
	.align 2, 0
_08093750: .4byte gEnemyFnTable
