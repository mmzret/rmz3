	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808d2f8
FUN_0808d2f8: @ 0x0808D2F8
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808D368
	ldr r1, _0808D328 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #9
	bne _0808D32C
	movs r0, #0
	b _0808D35C
	.align 2, 0
_0808D328: .4byte gEnemyFnTable
_0808D32C:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808D344
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #1
	strb r0, [r1]
	strb r4, [r2, #0xd]
	b _0808D35E
_0808D344:
	adds r0, r2, #0
	adds r0, #0xbb
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0808D35A
	movs r0, #3
	b _0808D35C
_0808D35A:
	movs r0, #1
_0808D35C:
	strb r0, [r2, #0xd]
_0808D35E:
	adds r0, r2, #0
	bl Deathlock_Die
	movs r0, #1
	b _0808D36A
_0808D368:
	movs r0, #0
_0808D36A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808d370
FUN_0808d370: @ 0x0808D370
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _0808D37C
	b _0808D496
_0808D37C:
	ldrb r0, [r4, #0x10]
	cmp r0, #9
	bne _0808D384
	b _0808D496
_0808D384:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	beq _0808D390
	b _0808D496
_0808D390:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808D39C
	cmp r0, #1
	beq _0808D420
	b _0808D496
_0808D39C:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808D496
	ldr r1, _0808D40C @ =sUpdates1
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D410 @ =sUpdates2
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0808D3FA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D414 @ =sCollisionIdxs1
	adds r5, r4, #0
	adds r5, #0xb9
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D418 @ =sCollisions
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _0808D41C @ =sMotions1
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
_0808D3FA:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808D406:
	movs r0, #1
	b _0808D498
	.align 2, 0
_0808D40C: .4byte sUpdates1
_0808D410: .4byte sUpdates2
_0808D414: .4byte sCollisionIdxs1
_0808D418: .4byte sCollisions
_0808D41C: .4byte sMotions1
_0808D420:
	adds r0, r4, #0
	bl IsFrozen
	cmp r0, #0
	beq _0808D494
	ldr r0, [r4, #0x54]
	ldr r1, _0808D48C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D45C
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808D462
_0808D45C:
	adds r0, r4, #0
	bl FUN_0808d160
_0808D462:
	ldrb r1, [r4, #0xd]
	cmp r1, #3
	bne _0808D46C
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
_0808D46C:
	ldrb r0, [r4, #0x10]
	cmp r0, #8
	beq _0808D406
	cmp r1, #3
	beq _0808D406
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D490 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D406
	movs r0, #0
	strb r0, [r4, #0xf]
	b _0808D498
	.align 2, 0
_0808D48C: .4byte 0xFFFFEE00
_0808D490: .4byte 0x00020001
_0808D494:
	strb r0, [r4, #0xf]
_0808D496:
	movs r0, #0
_0808D498:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d4a0
FUN_0808d4a0: @ 0x0808D4A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0808D4EE
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0808D4EE
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808D4EE
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0808D4DA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0808D4EE
_0808D4DA:
	ldr r2, _0808D4F4 @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808D4EE
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808D4EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D4F4: .4byte sElementCoord

	thumb_func_start Deathlock_Init
Deathlock_Init: @ 0x0808D4F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808D524 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #8
	bne _0808D52C
	movs r0, #7
	strb r0, [r6, #0xd]
	ldr r0, [r6, #0x58]
	ldr r1, _0808D528 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _0808D538
	.align 2, 0
_0808D524: .4byte gEnemyFnTable
_0808D528: .4byte 0xFFFFF800
_0808D52C:
	cmp r0, #9
	bne _0808D536
	movs r0, #5
	strb r0, [r6, #0xd]
	b _0808D538
_0808D536:
	strb r1, [r6, #0xd]
_0808D538:
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r1, r0
	movs r0, #1
	movs r4, #0
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #7
	bhi _0808D5C0
	ldr r0, _0808D58C @ =gSystemSavedata
	ldrb r1, [r0, #0x15]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808D598
	ldr r0, _0808D590 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0808D598
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D594 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D58C: .4byte gSystemSavedata
_0808D590: .4byte gCurStory
_0808D594: .4byte sCollisions
_0808D598:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D5BC @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D5BC: .4byte sCollisions
_0808D5C0:
	cmp r0, #9
	bne _0808D5E4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D600 @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
_0808D5E0:
	ldr r0, _0808D604 @ =nop_0808d2f4
	str r0, [r4, #0x24]
_0808D5E4:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bhi _0808D608
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	b _0808D618
	.align 2, 0
_0808D600: .4byte sCollisions
_0808D604: .4byte nop_0808d2f4
_0808D608:
	subs r1, r0, #4
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0808D618
	strb r1, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #0x11]
_0808D618:
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, r6, #0
	bl Deathlock_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0

