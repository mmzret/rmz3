	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile17_Init
Projectile17_Init: @ 0x080A2898
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _080A28D4
	movs r0, #0xef
	ands r2, r0
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080A28F4
_080A28D4:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080A28F4:
	movs r0, #0xff
	strb r0, [r6, #0x12]
	ldrb r7, [r6, #0x11]
	cmp r7, #0
	bne _080A298C
	movs r4, #0xa5
	lsls r4, r4, #3
	ldr r1, _080A2974 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080A2978 @ =wStaticGraphicTilenums
	adds r1, #0x84
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080A297C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080A2980 @ =wStaticMotionPalIDs
	adds r0, #0x84
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A2984 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r7, [r4, #0x24]
	ldr r1, _080A2988 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _080A2A20
	.align 2, 0
_080A2974: .4byte gStaticMotionGraphics
_080A2978: .4byte wStaticGraphicTilenums
_080A297C: .4byte gStaticMotionGraphics+12
_080A2980: .4byte wStaticMotionPalIDs
_080A2984: .4byte sCollisions
_080A2988: .4byte gProjectileFnTable
_080A298C:
	cmp r7, #1
	bne _080A29C4
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A29BC @ =0x0836B3F0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r1, _080A29C0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	b _080A2A14
	.align 2, 0
_080A29BC: .4byte sCollisions+(2*24)
_080A29C0: .4byte gProjectileFnTable
_080A29C4:
	cmp r7, #2
	bne _080A2A20
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080A2A2C @ =0x0836B408
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r2, _080A2A30 @ =Coord_ARRAY_080ff080
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r6, #0x54]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r6, #0x54]
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #3
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r6, #0x58]
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, _080A2A34 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
_080A2A14:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_080A2A20:
	adds r0, r6, #0
	bl Projectile17_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2A2C: .4byte sCollisions+(3*24)
_080A2A30: .4byte Coord_ARRAY_080ff080
_080A2A34: .4byte gProjectileFnTable
