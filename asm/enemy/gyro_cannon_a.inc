	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start gyrocannon_0806d32c
gyrocannon_0806d32c: @ 0x0806D32C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806D360
	ldr r1, _0806D35C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl GyroCannon_Die
	b _0806D45C
	.align 2, 0
_0806D35C: .4byte gEnemyFnTable
_0806D360:
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _0806D418
	ldrb r0, [r5, #0xd]
	cmp r0, #8
	beq _0806D38C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806D388 @ =0x083666D8
	bl SetDDP
	adds r0, r5, #0
	bl IsFrozen
	cmp r0, #0
	bne _0806D396
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _0806D396
	.align 2, 0
_0806D388: .4byte sCollisions+(24*2)
_0806D38C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806D3B8 @ =0x083666F0
	bl SetDDP
_0806D396:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0806D3C6
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r2, [r0, #9]
	cmp r2, #0
	bne _0806D3BC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	b _0806D3E0
	.align 2, 0
_0806D3B8: .4byte sCollisions+(24*3)
_0806D3BC:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_0806D3C6:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0806D410 @ =0xFFFFE800
	adds r1, r1, r2
	bl IsVoidSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0806D45C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
_0806D3E0:
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
	ldr r1, _0806D414 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0806D45C
	.align 2, 0
_0806D410: .4byte 0xFFFFE800
_0806D414: .4byte gEnemyFnTable
_0806D418:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r1, [r4, #0x58]
	ldr r2, _0806D464 @ =0xFFFFFE00
	adds r0, r1, r2
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0806D444
	ldr r0, [r4, #0x54]
	ldr r2, _0806D468 @ =0xFFFFF200
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806D45C
_0806D444:
	ldr r1, _0806D46C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl GyroCannon_Die
_0806D45C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806D464: .4byte 0xFFFFFE00
_0806D468: .4byte 0xFFFFF200
_0806D46C: .4byte gEnemyFnTable

	thumb_func_start FUN_0806d470
FUN_0806d470: @ 0x0806D470
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	bne _0806D508
	adds r0, #0xb4
	ldrb r1, [r0, #0xa]
	adds r6, r0, #0
	cmp r1, #0
	beq _0806D48E
	strb r2, [r4, #0xd]
	adds r5, r4, #0
	adds r5, #0x8c
	b _0806D4E8
_0806D48E:
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	adds r5, r1, #0
	cmp r2, #0
	beq _0806D4E6
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0806D4C8 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r3, [r6, #8]
	movs r0, #0
	mov r1, sp
	bl FUN_080b2b40
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0806D4CC
	movs r0, #1
_0806D4C2:
	strb r0, [r4, #0xd]
	b _0806D4E8
	.align 2, 0
_0806D4C8: .4byte 0xFFFFEC00
_0806D4CC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0806D4C2
	movs r0, #2
	b _0806D4C2
_0806D4E6:
	strb r2, [r4, #0xd]
_0806D4E8:
	movs r1, #0
	str r1, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #1
	strb r0, [r6, #9]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806D508:
	ldr r0, _0806D520 @ =0x08366694
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806D520: .4byte sUpdates2

	thumb_func_start FUN_0806d524
FUN_0806d524: @ 0x0806D524
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0806D568 @ =0xFFFFEE00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806D5F4
	ldr r7, _0806D56C @ =sSlashedEnemies
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r5, [r2, #8]
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _0806D570
	orrs r3, r5
	b _0806D572
	.align 2, 0
_0806D568: .4byte 0xFFFFEE00
_0806D56C: .4byte sSlashedEnemies
_0806D570:
	adds r3, r5, #0
_0806D572:
	mov r0, sp
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r5, sp
	ldr r7, _0806D594 @ =sSlashedEnemies
	ldrb r2, [r6, #8]
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0806D598
	orrs r3, r2
	b _0806D59A
	.align 2, 0
_0806D594: .4byte sSlashedEnemies
_0806D598:
	adds r3, r2, #0
_0806D59A:
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r5, sp
	ldr r7, _0806D5BC @ =0x0836673C
	ldrb r2, [r6, #8]
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0806D5C0
	orrs r3, r2
	b _0806D5C2
	.align 2, 0
_0806D5BC: .4byte sSlashedEnemies+(28*1)
_0806D5C0:
	adds r3, r2, #0
_0806D5C2:
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r5, sp
	ldr r7, _0806D5E4 @ =0x0836673C
	ldrb r2, [r6, #8]
	ldrb r1, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0806D5E8
	orrs r3, r2
	b _0806D5EA
	.align 2, 0
_0806D5E4: .4byte sSlashedEnemies+(28*1)
_0806D5E8:
	adds r3, r2, #0
_0806D5EA:
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
_0806D5F4:
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _0806D614 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D614: .4byte gEnemyFnTable

	thumb_func_start FUN_0806d618
FUN_0806d618: @ 0x0806D618
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	bne _0806D632
	movs r1, #0xb8
	lsls r1, r1, #5
	bl SetMotion
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806D632:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0806D642
	str r1, [r4, #0x60]
_0806D642:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806D67A
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0806D680 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	adds r1, r4, #0
	adds r1, #0xb4
	movs r0, #1
	strb r0, [r1, #0xb]
_0806D67A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806D680: .4byte 0xFFFFF600

	thumb_func_start FUN_0806d684
FUN_0806d684: @ 0x0806D684
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0806D77A
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldr r4, _0806D6F4 @ =pZero2
	ldr r2, [r4]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	ldr r2, _0806D6F8 @ =0xFFFFE800
	adds r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _0806D6FC
	ldr r0, [r5, #0x5c]
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0806D716
	.align 2, 0
_0806D6F4: .4byte pZero2
_0806D6F8: .4byte 0xFFFFE800
_0806D6FC:
	ldr r0, [r4]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806D70E
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0806D710
_0806D70E:
	ldr r0, _0806D73C @ =0xFFFFFA00
_0806D710:
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
_0806D716:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _0806D740
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0806D762
	.align 2, 0
_0806D73C: .4byte 0xFFFFFA00
_0806D740:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_0806D762:
	adds r1, r5, #0
	adds r1, #0xb4
	movs r0, #1
	strb r0, [r1, #0xa]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0806D7D4 @ =0x08366708
	bl SetDDP
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806D77A:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r3, [r5, #0x5c]
	adds r0, r0, r3
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	adds r2, #0x40
	str r2, [r5, #0x60]
	adds r0, r0, r3
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0806D7B6
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _0806D7D8 @ =0xFFFFE800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806D7CE
_0806D7B6:
	ldr r1, _0806D7DC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl GyroCannon_Die
_0806D7CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806D7D4: .4byte sCollisions+(24*4)
_0806D7D8: .4byte 0xFFFFE800
_0806D7DC: .4byte gEnemyFnTable

	thumb_func_start FUN_0806d7e0
FUN_0806d7e0: @ 0x0806D7E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0806D7FE
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806D7FE:
	movs r2, #0
	ldr r0, _0806D81C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0806D80E
	movs r2, #1
_0806D80E:
	cmp r2, #0
	beq _0806D820
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806D826
	.align 2, 0
_0806D81C: .4byte pZero2
_0806D820:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806D826:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, _0806D890 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #5
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806D8A8
	ldr r2, _0806D894 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0806D898 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0806D89C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _0806D8A0
	movs r0, #3
	b _0806D8A2
	.align 2, 0
_0806D890: .4byte gSineTable
_0806D894: .4byte RNG_0202f388
_0806D898: .4byte 0x000343FD
_0806D89C: .4byte 0x00269EC3
_0806D8A0:
	movs r0, #5
_0806D8A2:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0806D8A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806d8b0
FUN_0806d8b0: @ 0x0806D8B0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	bne _0806D944
	ldr r1, _0806D904 @ =0x00001703
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x58]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0806D90C
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp]
	movs r4, #0xc0
	lsls r4, r4, #1
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x90
	bl CreateLemon
	ldr r0, [r5, #0x58]
	ldr r1, _0806D908 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x70
	bl CreateLemon
	b _0806D934
	.align 2, 0
_0806D904: .4byte 0x00001703
_0806D908: .4byte 0xFFFFFB00
_0806D90C:
	ldr r0, [r5, #0x54]
	ldr r2, _0806D964 @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [sp]
	movs r4, #0xc0
	lsls r4, r4, #1
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0xef
	bl CreateLemon
	ldr r0, [r5, #0x58]
	ldr r1, _0806D968 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0x10
	bl CreateLemon
_0806D934:
	movs r0, #0x2c
	bl PlaySound
	movs r0, #0x30
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806D944:
	ldr r4, [r5, #0x2c]
	cmp r4, #0
	bne _0806D96C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0806D96C
	strb r4, [r5, #0xd]
	strb r4, [r5, #0xe]
	b _0806D990
	.align 2, 0
_0806D964: .4byte 0xFFFFF000
_0806D968: .4byte 0xFFFFFB00
_0806D96C:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0806D990
	ldr r1, [r5, #0x2c]
	cmp r1, #0
	beq _0806D98A
	movs r0, #4
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
	b _0806D990
_0806D98A:
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806D990:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

