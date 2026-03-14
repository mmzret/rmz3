	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Projectile42_Init
Projectile42_Init: @ 0x080B129C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080B12FC @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B1300 @ =0x0836D730
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
	ldr r1, _080B1304 @ =0x0836D718
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080B1308 @ =0x080B1299
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl Projectile42_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B12FC: .4byte gProjectileFnTable
_080B1300: .4byte 0x0836D730
_080B1304: .4byte 0x0836D718
_080B1308: .4byte 0x080B1299

	thumb_func_start Projectile42_Update
Projectile42_Update: @ 0x080B130C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080B1360
	ldr r0, _080B1358 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B1360
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B135C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080B1380
	.align 2, 0
_080B1358: .4byte gCurStory
_080B135C: .4byte gProjectileFnTable
_080B1360:
	ldr r1, _080B1388 @ =0x0836D710
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080B138C @ =0x0836D714
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080B1380:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1388: .4byte 0x0836D710
_080B138C: .4byte 0x0836D714

	thumb_func_start Projectile42_Die
Projectile42_Die: @ 0x080B1390
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080B13D4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B13D4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b13d8
FUN_080b13d8:
	bx lr
  .align 2, 0

	thumb_func_start FUN_080b13dc
FUN_080b13dc: @ 0x080B13DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B13EC
	cmp r0, #1
	beq _080B13FA
	b _080B144E
_080B13EC:
	ldr r1, _080B1454 @ =0x00008E0C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B13FA:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1412
	str r1, [r4, #0x60]
_080B1412:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B143C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080B144E
_080B143C:
	ldr r1, _080B1458 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080B144E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1454: .4byte 0x00008E0C
_080B1458: .4byte gProjectileFnTable

	thumb_func_start FUN_080b145c
FUN_080b145c: @ 0x080B145C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080B14B0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B14A8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B14B4 @ =gProjectileFnTable
	movs r1, #0x2b
	strb r1, [r3, #9]
	adds r0, #0xac
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r1, #0
	strh r2, [r3, #0x20]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r5, [r3, #0x5c]
	movs r0, #0
	cmp r5, #0
	ble _080B14A4
	movs r0, #1
_080B14A4:
	strb r0, [r3, #0x12]
	strb r1, [r3, #0x10]
_080B14A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B14B0: .4byte gProjectileHeaderPtr
_080B14B4: .4byte gProjectileFnTable

	thumb_func_start Projectile43_Init
Projectile43_Init: @ 0x080B14B8
	push {lr}
	ldr r2, _080B14EC @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #1
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #4]
	str r1, [r0, #0x14]
	ldr r2, _080B14F0 @ =0x0836D77C
	ldrb r1, [r0, #0x10]
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0, #0xd]
	ldrb r1, [r0, #0xa]
	movs r2, #1
	orrs r1, r2
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #0xa]
	bl Projectile43_Update
	pop {r0}
	bx r0
	.align 2, 0
_080B14EC: .4byte gProjectileFnTable
_080B14F0: .4byte 0x0836D77C

	thumb_func_start Projectile43_Update
Projectile43_Update: @ 0x080B14F4
	push {lr}
	adds r3, r0, #0
	ldr r0, _080B153C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080B1544
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080B1540 @ =gProjectileFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080B1554
	.align 2, 0
_080B153C: .4byte gCurStory
_080B1540: .4byte gProjectileFnTable
_080B1544:
	ldr r0, _080B1558 @ =0x0836D748
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080B1554:
	pop {r0}
	bx r0
	.align 2, 0
_080B1558: .4byte 0x0836D748

	thumb_func_start FUN_080b155c
FUN_080b155c: @ 0x080B155C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B156C
	cmp r6, #1
	beq _080B15E2
	b _080B1656
_080B156C:
	ldrb r1, [r5, #0xa]
	movs r0, #4
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B15A8 @ =0x0836D74C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, _080B15AC @ =0x0000DB0D
	adds r0, r5, #0
	bl SetMotion
	ldrb r2, [r5, #0x12]
	cmp r2, #0
	beq _080B15B0
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080B15B6
	.align 2, 0
_080B15A8: .4byte 0x0836D74C
_080B15AC: .4byte 0x0000DB0D
_080B15B0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080B15B6:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
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
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	movs r0, #0x55
	strb r0, [r5, #0x13]
	movs r0, #6
	strb r0, [r5, #0x12]
_080B15E2:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1610
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B160C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1656
	.align 2, 0
_080B160C: .4byte gProjectileFnTable
_080B1610:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080B164C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B1650
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080B1650
	ldr r1, _080B1648 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1650
	.align 2, 0
_080B1648: .4byte gProjectileFnTable
_080B164C:
	subs r0, #1
	strb r0, [r5, #0x12]
_080B1650:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B1656:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
  .align 2, 0

	thumb_func_start Projectile43_Die
Projectile43_Die:
	.byte 0x02, 0x1C, 0x91, 0x7A
	.byte 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30, 0x01, 0x60, 0x04, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49
	.byte 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61
	.byte 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08

	thumb_func_start FUN_080b1698
FUN_080b1698: @ 0x080B1698
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080B16E8 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B16E0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B16EC @ =gProjectileFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	strb r5, [r3, #0x12]
	strb r4, [r3, #0x13]
_080B16E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B16E8: .4byte gProjectileHeaderPtr
_080B16EC: .4byte gProjectileFnTable
_080B16F0:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080b16f4
FUN_080b16f4: @ 0x080B16F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080B1754 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080B1758 @ =0x0836D7B4
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
	ldr r1, _080B175C @ =0x0836D79C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080B1760 @ =0x080B16F1
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_080b1764
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1754: .4byte gProjectileFnTable
_080B1758: .4byte 0x0836D7B4
_080B175C: .4byte 0x0836D79C
_080B1760: .4byte 0x080B16F1

	thumb_func_start FUN_080b1764
FUN_080b1764: @ 0x080B1764
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B1790 @ =0x0836D794
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080B1794 @ =0x0836D798
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1790: .4byte 0x0836D794
_080B1794: .4byte 0x0836D798

	thumb_func_start FUN_080b1798
FUN_080b1798: @ 0x080B1798
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
	ldr r1, _080B17D4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17D4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b17d8
FUN_080b17d8:
  bx lr
	.align 2, 0

	thumb_func_start FUN_080b17dc
FUN_080b17dc: @ 0x080B17DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080B17EC
	cmp r0, #1
	beq _080B1834
	b _080B18C2
_080B17EC:
	movs r0, #0x40
	str r0, [r4, #0x64]
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Sqrt
	ldr r1, [r4, #0x64]
	rsbs r1, r1, #0
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	adds r2, r1, #0
	muls r2, r3, r2
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080B1812
	str r1, [r4, #0x64]
	rsbs r0, r2, #0
	str r0, [r4, #0x5c]
_080B1812:
	lsls r0, r3, #1
	str r0, [r4, #0x68]
	movs r2, #0xa0
	ldrb r1, [r4, #0x13]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x60]
	movs r1, #0xd7
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080B1834:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _080B184C
	subs r0, #1
	str r0, [r4, #0x68]
	ldr r0, [r4, #0x64]
	adds r0, r1, r0
	str r0, [r4, #0x5c]
_080B184C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _080B1880
	ldr r0, _080B1878 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B187C @ =0xFFFF2800
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bge _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080B1894
	.align 2, 0
_080B1878: .4byte gStageRun+232
_080B187C: .4byte 0xFFFF2800
_080B1880:
	ldr r0, _080B18C8 @ =gStageRun+232
	ldr r0, [r0, #0x38]
	ldr r1, _080B18CC @ =0x0000D7FF
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	cmp r1, r0
	ble _080B18C2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080B1894:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B18D0 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080B18C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B18C8: .4byte gStageRun+232
_080B18CC: .4byte 0x0000D7FF
_080B18D0: .4byte gProjectileFnTable

	thumb_func_start FUN_080b18d4
FUN_080b18d4: @ 0x080B18D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080B192C @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B1922
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B1930 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r6, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	ldr r0, [r5]
	str r0, [r3, #0x64]
	ldr r0, [r5, #4]
	str r0, [r3, #0x68]
_080B1922:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B192C: .4byte gProjectileHeaderPtr
_080B1930: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1934
FUN_080b1934: @ 0x080B1934
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B1988 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B197E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B198C @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B197E:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B1988: .4byte gProjectileHeaderPtr
_080B198C: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1990
FUN_080b1990: @ 0x080B1990
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B19E4 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B19DA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B19E8 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B19DA:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B19E4: .4byte gProjectileHeaderPtr
_080B19E8: .4byte gProjectileFnTable

	thumb_func_start FUN_080b19ec
FUN_080b19ec: @ 0x080B19EC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080B1A40 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B1A36
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B1A44 @ =gProjectileFnTable
	movs r1, #0x2d
	strb r1, [r3, #9]
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r6, [r3, #0x28]
_080B1A36:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B1A40: .4byte gProjectileHeaderPtr
_080B1A44: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1a48
FUN_080b1a48: @ 0x080B1A48
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r5, [r4, #0x10]
	cmp r5, #0
	bne _080B1A9C
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _080B1A98 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	b _080B1B0C
	.align 2, 0
_080B1A98: .4byte gProjectileFnTable
_080B1A9C:
	cmp r5, #1
	bne _080B1ACC
	movs r2, #0
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r1, _080B1AC8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	b _080B1B00
	.align 2, 0
_080B1AC8: .4byte gProjectileFnTable
_080B1ACC:
	cmp r5, #2
	beq _080B1AD4
	cmp r5, #3
	bne _080B1B0C
_080B1AD4:
	movs r2, #0
	movs r0, #0xef
	ands r1, r0
	strb r1, [r4, #0xa]
	movs r3, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r1, _080B1B24 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
_080B1B00:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r5, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
_080B1B0C:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	adds r1, r4, #0
	adds r1, #0xbc
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080b1b28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B24: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1b28
FUN_080b1b28: @ 0x080B1B28
	push {lr}
	ldr r2, _080B1B3C @ =0x0836D7CC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B1B3C: .4byte 0x0836D7CC

	thumb_func_start FUN_080b1b40
FUN_080b1b40:
	.byte 0x02, 0x1C, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x00, 0x21, 0x90, 0x72, 0x10, 0x1C, 0x8C, 0x30
	.byte 0x01, 0x60, 0x04, 0x30, 0x01, 0x60, 0x04, 0x30, 0x01, 0x70, 0x91, 0x7A, 0xFB, 0x20, 0x08, 0x40
	.byte 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00, 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68
	.byte 0x00, 0x69, 0x50, 0x61, 0x70, 0x47, 0x00, 0x00, 0x0C, 0xA9, 0x36, 0x08
  .align 2, 0

	thumb_func_start FUN_080b1b7c
FUN_080b1b7c: @ 0x080B1B7C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1BA2
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	b _080B1BBC
_080B1BA2:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B1BD4
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1BD4
_080B1BBC:
	ldr r1, _080B1BD0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B1CAE
	.align 2, 0
_080B1BD0: .4byte gProjectileFnTable
_080B1BD4:
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _080B1BE0
	cmp r6, #1
	beq _080B1CA0
	b _080B1CAE
_080B1BE0:
	movs r7, #0
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1C2C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C28 @ =0x0836D7DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb6
	lsls r1, r1, #7
	b _080B1C52
	.align 2, 0
_080B1C28: .4byte 0x0836D7DC
_080B1C2C:
	cmp r0, #1
	bne _080B1C60
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1C5C @ =0x0836D7F4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xb8
	lsls r1, r1, #7
_080B1C52:
	adds r0, r5, #0
	bl SetMotion
	b _080B1C8C
	.align 2, 0
_080B1C5C: .4byte 0x0836D7F4
_080B1C60:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1C8C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1CB4 @ =0x0836D80C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r1, #0xbe
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
_080B1C8C:
	ldr r0, _080B1CB8 @ =FUN_080b2178
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1CA0:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080B1CAE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1CB4: .4byte 0x0836D80C
_080B1CB8: .4byte FUN_080b2178

	thumb_func_start FUN_080b1cbc
FUN_080b1cbc: @ 0x080B1CBC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0xbc
	ldrb r6, [r0]
	cmp r6, #0
	beq _080B1D24
	subs r0, #0x30
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _080B1D0E
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	ldr r0, _080B1D20 @ =0x00000137
	bl PlaySound
_080B1D0E:
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	b _080B1EE2
	.align 2, 0
_080B1D20: .4byte 0x00000137
_080B1D24:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r7, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1D34
	b _080B1ED6
_080B1D34:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B1E0C
	cmp r0, #1
	bgt _080B1D44
	cmp r0, #0
	beq _080B1D52
	b _080B1EF4
_080B1D44:
	cmp r0, #2
	bne _080B1D4A
	b _080B1E5C
_080B1D4A:
	cmp r0, #3
	bne _080B1D50
	b _080B1EA0
_080B1D50:
	b _080B1EF4
_080B1D52:
	adds r0, r5, #0
	bl InitNonAffineMotion
	adds r0, r5, #0
	adds r0, #0x24
	strb r6, [r0]
	adds r0, #0x2c
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _080B1D9C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1D94 @ =0x0836D824
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1D98 @ =0x00000E08
	b _080B1DC0
	.align 2, 0
_080B1D94: .4byte 0x0836D824
_080B1D98: .4byte 0x00000E08
_080B1D9C:
	cmp r0, #1
	bne _080B1DD0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B1DC8 @ =0x0836D83C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1DCC @ =0x00000E07
_080B1DC0:
	adds r0, r5, #0
	bl SetMotion
	b _080B1DFA
	.align 2, 0
_080B1DC8: .4byte 0x0836D83C
_080B1DCC: .4byte 0x00000E07
_080B1DD0:
	adds r4, r5, #0
	adds r4, #0x74
	cmp r0, #2
	bne _080B1DFA
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080B1E4C @ =0x0836D854
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _080B1E50 @ =0x00000E09
	adds r0, r5, #0
	bl SetMotion
_080B1DFA:
	ldr r0, _080B1E54 @ =FUN_080b21c0
	str r0, [r4, #0x24]
	movs r0, #0
	str r0, [r5, #0x60]
	subs r0, #0xa8
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B1E0C:
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1E1C
	str r1, [r5, #0x60]
_080B1E1C:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _080B1E58 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1EF4
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _080B1E94
	.align 2, 0
_080B1E4C: .4byte 0x0836D854
_080B1E50: .4byte 0x00000E09
_080B1E54: .4byte FUN_080b21c0
_080B1E58: .4byte 0xFFFFF800
_080B1E5C:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _080B1E9C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, [r5, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	cmp r0, r1
	beq _080B1EF4
	str r6, [r5, #0x60]
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #0x28
	strb r0, [r5, #0x13]
_080B1E94:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080B1EF4
	.align 2, 0
_080B1E9C: .4byte 0xFFFFF000
_080B1EA0:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080B1EB0
	str r1, [r5, #0x60]
_080B1EB0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080B1ED6
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1EF4
_080B1ED6:
	ldr r1, [r5, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #0
	beq _080B1EE2
	subs r0, #1
	strb r0, [r1, #0xc]
_080B1EE2:
	ldr r1, _080B1EFC @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080B1EF4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1EFC: .4byte gProjectileFnTable

	thumb_func_start FUN_080b1f00
FUN_080b1f00: @ 0x080B1F00
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B1F12
	movs r0, #0xff
	strb r0, [r6, #0x12]
_080B1F12:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B1F38
	ldr r1, _080B1F34 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	b _080B2030
	.align 2, 0
_080B1F34: .4byte gProjectileFnTable
_080B1F38:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080B1F44
	cmp r0, #1
	beq _080B2010
	b _080B2030
_080B1F44:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	str r1, [r6, #0x58]
	ldr r0, _080B1FC0 @ =0x000117FF
	cmp r1, r0
	ble _080B1FA2
	ldr r0, _080B1FC4 @ =0x00013BFF
	cmp r1, r0
	bgt _080B1FD4
	ldr r0, [r6, #0x54]
	ldr r4, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r4
	bl FUN_0800a31c
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_0800a22c
	ldr r0, [r6, #0x54]
	ldr r2, _080B1FCC @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	adds r1, r1, r4
	bl FUN_08009f6c
	movs r4, #0x9e
	lsls r4, r4, #9
	cmp r0, r4
	bgt _080B1FA2
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	ldr r2, _080B1FC8 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	cmp r0, r4
	ble _080B1FD4
_080B1FA2:
	ldr r1, _080B1FD0 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	b _080B2030
	.align 2, 0
_080B1FC0: .4byte 0x000117FF
_080B1FC4: .4byte 0x00013BFF
_080B1FC8: .4byte 0xFFFFF800
_080B1FCC: .4byte 0xFFFFE000
_080B1FD0: .4byte gProjectileFnTable
_080B1FD4:
	adds r1, r6, #0
	adds r1, #0x25
	movs r5, #0
	movs r0, #0x12
	strb r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B2038 @ =0x0836D86C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xf3
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080B2010:
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2020
	ldr r0, [r6, #0x54]
	ldr r1, _080B203C @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r6, #0x54]
_080B2020:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080B2040 @ =gStageRun+232
	adds r1, r6, #0
	adds r1, #0x54
	bl CalcFromCamera
_080B2030:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2038: .4byte 0x0836D86C
_080B203C: .4byte 0xFFFC4000
_080B2040: .4byte gStageRun+232

	thumb_func_start FUN_080b2044
FUN_080b2044: @ 0x080B2044
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne _080B2056
	movs r0, #0xff
	strb r0, [r5, #0x12]
_080B2056:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B207C
	ldr r1, _080B2078 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080B216C
	.align 2, 0
_080B2078: .4byte gProjectileFnTable
_080B207C:
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #1
	bne _080B20C2
	ldrb r0, [r5, #0xe]
	cmp r0, #2
	beq _080B20C2
	ldr r1, [r5, #0x28]
	ldrh r0, [r1, #0xe]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0xe]
	ldr r0, _080B20D4 @ =0x00000137
	bl PlaySound
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x10
	strb r0, [r5, #0x12]
	movs r0, #2
	strb r0, [r5, #0xe]
_080B20C2:
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080B2116
	cmp r0, #1
	bgt _080B20D8
	cmp r0, #0
	beq _080B20DE
	b _080B216C
	.align 2, 0
_080B20D4: .4byte 0x00000137
_080B20D8:
	cmp r0, #2
	beq _080B214C
	b _080B216C
_080B20DE:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080B2138 @ =0x0836D884
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080B213C @ =FUN_080b2204
	str r0, [r4, #0x24]
	ldr r1, _080B2140 @ =0x0000AA04
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080B2116:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B2126
	ldr r0, [r5, #0x54]
	ldr r1, _080B2144 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B2126:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080B2148 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	b _080B216C
	.align 2, 0
_080B2138: .4byte 0x0836D884
_080B213C: .4byte FUN_080b2204
_080B2140: .4byte 0x0000AA04
_080B2144: .4byte 0xFFFC4000
_080B2148: .4byte gStageRun+232
_080B214C:
	ldrb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080B215C
	movs r0, #0x22
	bl PlaySound
_080B215C:
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _080B216C
	ldr r0, [r5, #0x54]
	ldr r1, _080B2174 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r5, #0x54]
_080B216C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B2174: .4byte 0xFFFC4000

	thumb_func_start FUN_080b2178
FUN_080b2178: @ 0x080B2178
	push {r4, lr}
	movs r4, #0
	ldr r3, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r2, [r0, #0x2c]
	ldrb r0, [r3, #0x11]
	cmp r0, #0
	bne _080B2190
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B2190
	movs r4, #1
_080B2190:
	ldrb r0, [r3, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21A0
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21A0
	movs r4, #1
_080B21A0:
	cmp r1, #2
	bne _080B21AC
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21AC
	movs r4, #1
_080B21AC:
	adds r1, r3, #0
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
	cmp r4, #1
	bne _080B21BA
	strb r4, [r1]
_080B21BA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b21c0
FUN_080b21c0: @ 0x080B21C0
	push {lr}
	movs r3, #0
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	bne _080B21D8
	ldrb r0, [r2, #0x11]
	cmp r0, #2
	bne _080B21D8
	movs r3, #1
_080B21D8:
	ldrb r0, [r1, #0x11]
	adds r1, r0, #0
	cmp r1, #1
	bne _080B21E8
	ldrb r0, [r2, #0x11]
	cmp r0, #0
	bne _080B21E8
	movs r3, #1
_080B21E8:
	cmp r1, #2
	bne _080B21F4
	ldrb r0, [r2, #0x11]
	cmp r0, #1
	bne _080B21F4
	movs r3, #1
_080B21F4:
	cmp r3, #1
	bne _080B21FE
	adds r0, r2, #0
	adds r0, #0xbc
	strb r3, [r0]
_080B21FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2204
FUN_080b2204: @ 0x080B2204
	push {lr}
	ldr r1, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _080B2218
	adds r1, #0xbc
	movs r0, #1
	strb r0, [r1]
_080B2218:
	pop {r0}
	bx r0

	thumb_func_start FUN_080b221c
FUN_080b221c: @ 0x080B221C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080B2268 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B225E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B226C @ =gProjectileFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080B225E:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080B2268: .4byte gProjectileHeaderPtr
_080B226C: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2270
FUN_080b2270: @ 0x080B2270
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _080B22C0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B22B6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B22C4 @ =gProjectileFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r6, [r3, #0x28]
	str r7, [r3, #0x2c]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080B22B6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B22C0: .4byte gProjectileHeaderPtr
_080B22C4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b22c8
FUN_080b22c8: @ 0x080B22C8
	push {lr}
	ldr r2, _080B22DC @ =0x0836D8B0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B22DC: .4byte 0x0836D8B0

	thumb_func_start FUN_080b22e0
FUN_080b22e0: @ 0x080B22E0
	push {lr}
	ldr r2, _080B22F4 @ =0x0836D8BC
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B22F4: .4byte 0x0836D8BC

	thumb_func_start FUN_080b22f8
FUN_080b22f8: @ 0x080B22F8
	push {lr}
	ldr r2, _080B230C @ =0x0836D8C8
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B230C: .4byte 0x0836D8C8

	thumb_func_start FUN_080b2310
FUN_080b2310: @ 0x080B2310
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xea
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r3, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	str r2, [r4, #0x58]
	ldr r1, _080B2380 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B2380: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2384
FUN_080b2384: @ 0x080B2384
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B241C @ =0x0000E902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r5, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #8
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x58]
	ldr r1, _080B2420 @ =0x00000DE9
	adds r0, r6, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x12]
	ldrb r3, [r4, #0x11]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_080b2270
	str r0, [r4, #0x2c]
	ldr r1, _080B2424 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B241C: .4byte 0x0000E902
_080B2420: .4byte 0x00000DE9
_080B2424: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2428
FUN_080b2428: @ 0x080B2428
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B24BC @ =0x0000E905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #9
	strb r0, [r1]
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r3, #1
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #5
	adds r0, #8
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x58]
	ldr r0, _080B24C0 @ =0x00000DE9
	adds r5, r5, r0
	ldrb r0, [r4, #0x11]
	adds r5, r5, r0
	ldrb r0, [r5]
	strb r0, [r4, #0x12]
	ldr r1, _080B24C4 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r3, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_080b22e0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B24BC: .4byte 0x0000E905
_080B24C0: .4byte 0x00000DE9
_080B24C4: .4byte gProjectileFnTable

	thumb_func_start FUN_080b24c8
FUN_080b24c8: @ 0x080B24C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B251C
	cmp r0, #1
	bgt _080B24DE
	cmp r0, #0
	beq _080B24E8
	b _080B257A
_080B24DE:
	cmp r0, #2
	beq _080B2538
	cmp r0, #3
	beq _080B2560
	b _080B257A
_080B24E8:
	ldrb r1, [r4, #0x11]
	ldr r2, _080B2514 @ =0x00000DE4
	adds r0, r5, r2
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _080B257A
	adds r2, r0, #0
	adds r0, r5, #0
	bl FUN_0809bdd4
	str r0, [r4, #0x2c]
	cmp r0, #0
	beq _080B257A
	ldr r0, _080B2518 @ =0x00000E12
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B2578
	.align 2, 0
_080B2514: .4byte 0x00000DE4
_080B2518: .4byte 0x00000E12
_080B251C:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bls _080B2538
	ldr r1, _080B2554 @ =0x0000EA01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080B2558 @ =0x00000139
	bl PlaySound
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080B2538:
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x58]
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080B257A
	ldr r1, _080B255C @ =0x0000EA02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080B2578
	.align 2, 0
_080B2554: .4byte 0x0000EA01
_080B2558: .4byte 0x00000139
_080B255C: .4byte 0x0000EA02
_080B2560:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B257A
	ldr r1, _080B2588 @ =0x00000DE4
	adds r0, r5, r1
	ldrb r2, [r4, #0x11]
	adds r0, r0, r2
	movs r1, #0xff
	strb r1, [r0]
	movs r0, #0
_080B2578:
	strb r0, [r4, #0xd]
_080B257A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2588: .4byte 0x00000DE4

	thumb_func_start FUN_080b258c
FUN_080b258c: @ 0x080B258C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldr r1, _080B25B0 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B2646
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B25D8
	cmp r0, #1
	bgt _080B25B4
	cmp r0, #0
	beq _080B25BA
	b _080B2646
	.align 2, 0
_080B25B0: .4byte 0x00000DCC
_080B25B4:
	cmp r0, #2
	beq _080B2614
	b _080B2646
_080B25BA:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2646
	ldr r1, _080B25D4 @ =0x0000E903
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080B2604
	.align 2, 0
_080B25D4: .4byte 0x0000E903
_080B25D8:
	ldr r1, _080B260C @ =0x00000DE9
	adds r0, r5, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r1, [r4, #0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080B2646
	ldr r1, _080B2610 @ =0x0000E904
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0x9d
	lsls r0, r0, #1
	bl PlaySound
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_080B2604:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080B2646
	.align 2, 0
_080B260C: .4byte 0x00000DE9
_080B2610: .4byte 0x0000E904
_080B2614:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2646
	ldr r1, _080B264C @ =0x0000E902
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	strb r2, [r4, #0xd]
	ldrb r0, [r4, #0x12]
	cmp r0, #4
	bne _080B2646
	ldr r0, _080B2650 @ =0x00000DE9
	adds r1, r5, r0
	ldrb r0, [r4, #0x11]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	strb r2, [r4, #0x12]
_080B2646:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B264C: .4byte 0x0000E902
_080B2650: .4byte 0x00000DE9

	thumb_func_start FUN_080b2654
FUN_080b2654: @ 0x080B2654
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080B26B8
	cmp r0, #1
	bgt _080B266E
	cmp r0, #0
	beq _080B2678
	b _080B2742
_080B266E:
	cmp r0, #2
	beq _080B2700
	cmp r0, #3
	beq _080B2724
	b _080B2742
_080B2678:
	ldr r1, _080B26B4 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B2742
	adds r1, #0x1d
	adds r0, r5, r1
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	ldrb r1, [r4, #0x12]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080B2742
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	b _080B2716
	.align 2, 0
_080B26B4: .4byte 0x00000DCC
_080B26B8:
	ldrb r0, [r4, #0x12]
	cmp r0, #4
	bne _080B26EC
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2742
	ldr r1, _080B26E8 @ =0x00000DCC
	adds r0, r5, r1
	ldrb r0, [r0, #4]
	cmp r0, #3
	bhi _080B26E0
	adds r1, r4, #0
	adds r1, #0x54
	ldrb r3, [r4, #0x11]
	adds r0, r5, #0
	movs r2, #0
	bl CreateGhost78_1
_080B26E0:
	movs r0, #0x1e
	strb r0, [r4, #0x13]
	b _080B2716
	.align 2, 0
_080B26E8: .4byte 0x00000DCC
_080B26EC:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _080B2742
	movs r0, #0
	strb r0, [r4, #0xd]
	b _080B2742
_080B2700:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080B2742
	ldr r1, _080B2720 @ =0x0000E90A
	adds r0, r4, #0
	bl SetMotion
_080B2716:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080B2742
	.align 2, 0
_080B2720: .4byte 0x0000E90A
_080B2724:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080B2742
	ldr r1, _080B2748 @ =0x0000E905
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0x12]
_080B2742:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2748: .4byte 0x0000E905

	thumb_func_start FUN_080b274c
FUN_080b274c: @ 0x080B274C
	ldr r2, _080B2760 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080B2760: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2764
FUN_080b2764: @ 0x080B2764
	ldr r2, _080B2778 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080B2778: .4byte gProjectileFnTable

	thumb_func_start FUN_080b277c
FUN_080b277c: @ 0x080B277C
	ldr r2, _080B2790 @ =gProjectileFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080B2790: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2794
FUN_080b2794: @ 0x080B2794
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080B27E0 @ =gProjectileHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080B27EC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080B27E4 @ =gProjectileFnTable
	movs r1, #0x2f
	strb r1, [r3, #9]
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r2, [r3, #0x5c]
	cmp r5, #0
	beq _080B27E8
	movs r0, #0xc0
	lsls r0, r0, #2
	b _080B27EA
	.align 2, 0
_080B27E0: .4byte gProjectileHeaderPtr
_080B27E4: .4byte gProjectileFnTable
_080B27E8:
	ldr r0, _080B27F4 @ =0xFFFFFD00
_080B27EA:
	str r0, [r3, #0x60]
_080B27EC:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080B27F4: .4byte 0xFFFFFD00

	thumb_func_start FUN_080b27f8
FUN_080b27f8: @ 0x080B27F8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r7, #0
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080B287C @ =0x0836D8E8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r1, #0xb7
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bge _080B285C
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080B285C:
	ldr r1, _080B2880 @ =gProjectileFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl FUN_080b2884
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B287C: .4byte 0x0836D8E8
_080B2880: .4byte gProjectileFnTable

	thumb_func_start FUN_080b2884
FUN_080b2884: @ 0x080B2884
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r0, _080B28D0 @ =gOverworld
	ldr r1, _080B28D4 @ =0x0002C00C
	adds r0, r0, r1
	ldr r2, [r4, #0x58]
	ldr r0, [r0]
	cmp r2, r0
	blt _080B28A2
	movs r0, #0x82
	lsls r0, r0, #0xb
	cmp r2, r0
	ble _080B28DC
_080B28A2:
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080B28D8 @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080B28EA
	.align 2, 0
_080B28D0: .4byte gOverworld
_080B28D4: .4byte 0x0002C00C
_080B28D8: .4byte gProjectileFnTable
_080B28DC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, r2, r0
	str r0, [r4, #0x58]
_080B28EA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b28f0
FUN_080b28f0: @ 0x080B28F0
	adds r2, r0, #0
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
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
	ldr r1, _080B2928 @ =gProjectileFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
	bx lr
	.align 2, 0
_080B2928: .4byte gProjectileFnTable
