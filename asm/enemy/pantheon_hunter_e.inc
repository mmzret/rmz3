	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start explodePHunter
explodePHunter: @ 0x08065370
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	bne _0806538E
	ldr r1, _080653C8 @ =0x00001303
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xf]
	adds r0, #1
	strb r0, [r7, #0xf]
_0806538E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080653A0
	b _08065500
_080653A0:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _080653CC @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r6, _080653D0 @ =sSlashedEnemies
	adds r2, r7, #0
	adds r2, #0xbc
	ldrb r4, [r2]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _080653D4
	orrs r3, r4
	b _080653D6
	.align 2, 0
_080653C8: .4byte 0x00001303
_080653CC: .4byte 0xFFFFE800
_080653D0: .4byte sSlashedEnemies
_080653D4:
	adds r3, r4, #0
_080653D6:
	mov r0, sp
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r6, _080653F8 @ =sSlashedEnemies+28
	ldrb r2, [r5]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080653FC
	orrs r3, r2
	b _080653FE
	.align 2, 0
_080653F8: .4byte sSlashedEnemies+28
_080653FC:
	adds r3, r2, #0
_080653FE:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r6, _08065420 @ =sSlashedEnemies+56
	ldrb r2, [r5]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065424
	orrs r3, r2
	b _08065426
	.align 2, 0
_08065420: .4byte sSlashedEnemies+56
_08065424:
	adds r3, r2, #0
_08065426:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r0, [r7, #0x58]
	ldr r1, _0806550C @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r3, _08065510 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r2, _08065514 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, _08065518 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	movs r6, #0x1f
	ands r1, r6
	movs r4, #0x10
	subs r1, r4, r1
	lsls r1, r1, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	bl CreateSmoke
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	subs r4, r4, r0
	lsls r4, r4, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0806551C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08065520 @ =0x0000270E
	cmp r1, r0
	bhi _080654E6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080654E6:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _08065524 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_08065500:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806550C: .4byte 0xFFFFF000
_08065510: .4byte RNG_0202f388
_08065514: .4byte 0x000343FD
_08065518: .4byte 0x00269EC3
_0806551C: .4byte gScore
_08065520: .4byte 0x0000270E
_08065524: .4byte gEnemyFnTable

	thumb_func_start slashPHunter
slashPHunter: @ 0x08065528
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080655B6
	ldr r1, _0806556C @ =0x00001304
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08065570
	adds r0, r5, #0
	adds r0, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	adds r4, r5, #0
	adds r4, #0xbc
	ldrb r3, [r4]
	movs r1, #0
	bl CreateGhost18
	b _0806558A
	.align 2, 0
_0806556C: .4byte 0x00001304
_08065570:
	adds r0, r5, #0
	adds r0, #0x54
	ldr r1, _080655A0 @ =sSlashedEnemies+84
	ldrb r2, [r5, #0xa]
	movs r3, #0x10
	ands r3, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r2, #0
	bl CreateSlashedEnemy
	adds r4, r5, #0
	adds r4, #0xbc
_0806558A:
	ldr r0, [r5, #0x58]
	ldr r1, _080655A4 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r4]
	cmp r0, #0
	beq _080655A8
	movs r0, #0x80
	rsbs r0, r0, #0
	b _080655AA
	.align 2, 0
_080655A0: .4byte sSlashedEnemies+84
_080655A4: .4byte 0xFFFFE000
_080655A8:
	movs r0, #0x80
_080655AA:
	str r0, [r5, #0x5c]
	ldr r0, _08065610 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080655B6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080655CC
	str r1, [r5, #0x60]
_080655CC:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x60]
	adds r1, r1, r2
	str r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080656B4
	adds r7, r5, #0
	adds r7, #0x54
	ldr r0, _08065614 @ =sSlashedEnemies
	mov ip, r0
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r6, [r2]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	mov r8, r7
	adds r4, r2, #0
	cmp r0, #0
	beq _08065618
	orrs r3, r6
	b _0806561A
	.align 2, 0
_08065610: .4byte 0xFFFFFF00
_08065614: .4byte sSlashedEnemies
_08065618:
	adds r3, r6, #0
_0806561A:
	adds r0, r7, #0
	mov r1, ip
	movs r2, #0
	bl CreateSlashedEnemy
	mov r6, r8
	ldr r7, _0806563C @ =sSlashedEnemies+28
	ldrb r2, [r4]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065640
	orrs r3, r2
	b _08065642
	.align 2, 0
_0806563C: .4byte sSlashedEnemies+28
_08065640:
	adds r3, r2, #0
_08065642:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r6, r8
	ldr r7, _08065664 @ =sSlashedEnemies+56
	ldrb r2, [r4]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08065668
	orrs r3, r2
	b _0806566A
	.align 2, 0
_08065664: .4byte sSlashedEnemies+56
_08065668:
	adds r3, r2, #0
_0806566A:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, r8
	movs r0, #1
	adds r1, r4, #0
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080656C0 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080656C4 @ =0x0000270E
	cmp r1, r0
	bhi _0806569A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806569A:
	adds r0, r5, #0
	mov r1, r8
	bl TryDropZakoDisk
	ldr r1, _080656C8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080656B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080656C0: .4byte gScore
_080656C4: .4byte 0x0000270E
_080656C8: .4byte gEnemyFnTable
