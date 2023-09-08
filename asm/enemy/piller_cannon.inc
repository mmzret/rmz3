	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PillerCannon_Init
PillerCannon_Init: @ 0x0806832C
	push {r4, r5, r6, lr}
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
	ldr r0, _08068378 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x14]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08068384
	ldr r0, _0806837C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08068384
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08068380 @ =0x0836609C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	b _0806839C
	.align 2, 0
_08068378: .4byte gSystemSavedataManager
_0806837C: .4byte gCurStory
_08068380: .4byte 0x0836609C
_08068384:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080683F8 @ =0x0836609C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
_0806839C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _080683FC @ =FUN_08068f68
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r2, #0
	strb r2, [r0]
	adds r0, #4
	str r2, [r0]
	subs r0, #3
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r0, #5
	strb r2, [r0]
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08068404
	ldr r1, _08068400 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0xd]
	b _0806841A
	.align 2, 0
_080683F8: .4byte 0x0836609C
_080683FC: .4byte FUN_08068f68
_08068400: .4byte gEnemyFnTable
_08068404:
	ldr r1, _08068444 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #2
	strb r0, [r6, #0xd]
_0806841A:
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _08068438
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08068438:
	adds r0, r6, #0
	bl PillerCannon_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08068444: .4byte gEnemyFnTable

	thumb_func_start PillerCannon_Update
PillerCannon_Update: @ 0x08068448
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08068478
	ldr r1, _08068474 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl PillerCannon_Die
	b _08068508
	.align 2, 0
_08068474: .4byte gEnemyFnTable
_08068478:
	ldr r0, _080684AC @ =0x08366054
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08068f08
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _080684B0
	cmp r0, #8
	beq _080684B0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080684B0
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xba
	strb r1, [r0]
	b _08068508
	.align 2, 0
_080684AC: .4byte 0x08366054
_080684B0:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	beq _080684E2
	bl isKilled
	cmp r0, #0
	bne _080684D4
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080684D0 @ =0x083661BC
	bl SetDDP
	b _08068508
	.align 2, 0
_080684D0: .4byte 0x083661BC
_080684D4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080684F4 @ =0x083661A4
	bl SetDDP
	movs r0, #0
	str r0, [r5]
_080684E2:
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080684F8
	subs r0, #1
	strb r0, [r1]
	b _08068508
	.align 2, 0
_080684F4: .4byte 0x083661A4
_080684F8:
	ldr r0, _08068510 @ =0x08366078
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08068508:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068510: .4byte 0x08366078

	thumb_func_start PillerCannon_Die
PillerCannon_Die: @ 0x08068514
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0806855C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08068564
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
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
	ldr r1, _08068560 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080685F4
	.align 2, 0
_0806855C: .4byte gCurStory
_08068560: .4byte gEnemyFnTable
_08068564:
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _08068594
	cmp r1, #1
	bgt _08068574
	cmp r1, #0
	beq _0806857A
	b _080685F6
_08068574:
	cmp r1, #2
	beq _080685A4
	b _080685F6
_0806857A:
	movs r0, #1
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
_08068594:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080685F6
_080685A4:
	ldr r0, [r4, #0x5c]
	str r0, [sp]
	ldr r0, [r4, #0x60]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08068600 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08068604 @ =0x0000270E
	cmp r1, r0
	bhi _080685D4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080685D4:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08068608 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_080685F4:
	str r0, [r4, #0x14]
_080685F6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068600: .4byte gMission
_08068604: .4byte 0x0000270E
_08068608: .4byte gEnemyFnTable

	thumb_func_start FUN_0806860c
FUN_0806860c: @ 0x0806860C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068610
FUN_08068610: @ 0x08068610
	bx lr
	.align 2, 0

	thumb_func_start FUN_08068614
FUN_08068614: @ 0x08068614
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068618
FUN_08068618: @ 0x08068618
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #0
	beq _08068628
	cmp r4, #1
	beq _08068678
	b _0806869E
_08068628:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _080686A4 @ =0x0836609C
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r3, [r4]
	cmp r3, #0
	beq _08068672
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r4]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _080686A8 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068672:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068678:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080686AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	bhs _0806869E
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0806869E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080686A4: .4byte 0x0836609C
_080686A8: .4byte gVFXFnTable
_080686AC: .4byte pZero2

	thumb_func_start FUN_080686b0
FUN_080686b0: @ 0x080686B0
	movs r0, #1
	bx lr

	thumb_func_start FUN_080686b4
FUN_080686b4: @ 0x080686B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _0806871E
	cmp r4, #1
	bgt _080686C8
	cmp r4, #0
	beq _080686CE
	b _08068776
_080686C8:
	cmp r4, #2
	beq _08068750
	b _08068776
_080686CE:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08068744 @ =0x0836609C
	bl SetDDP
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r3, [r4]
	cmp r3, #0
	beq _08068718
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r4]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _08068748 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068718:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806871E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0806874C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #7
	cmp r0, r1
	bhs _08068776
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068776
	.align 2, 0
_08068744: .4byte 0x0836609C
_08068748: .4byte gVFXFnTable
_0806874C: .4byte pZero2
_08068750:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0806877C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0xe0
	lsls r1, r1, #7
	cmp r0, r1
	blo _08068776
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08068776:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806877C: .4byte pZero2

	thumb_func_start FUN_08068780
FUN_08068780: @ 0x08068780
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068784
FUN_08068784: @ 0x08068784
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08068790
	b _08068AC8
_08068790:
	lsls r0, r0, #2
	ldr r1, _0806879C @ =_080687A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806879C: .4byte _080687A0
_080687A0: @ jump table
	.4byte _080687D0 @ case 0
	.4byte _080688FC @ case 1
	.4byte _08068994 @ case 2
	.4byte _08068AC8 @ case 3
	.4byte _08068AC8 @ case 4
	.4byte _08068AC8 @ case 5
	.4byte _08068AC8 @ case 6
	.4byte _08068AC8 @ case 7
	.4byte _08068AC8 @ case 8
	.4byte _08068AC8 @ case 9
	.4byte _08068A58 @ case 10
	.4byte _08068AA8 @ case 11
_080687D0:
	ldrb r3, [r4, #0x10]
	cmp r3, #0
	bne _0806883E
	ldr r0, _0806880C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08068810
	adds r2, r4, #0
	adds r2, #0xb8
	strb r3, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	b _080688A2
	.align 2, 0
_0806880C: .4byte pZero2
_08068810:
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #1
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	b _080688A0
_0806883E:
	ldr r0, _08068878 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0806887C
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #1
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	b _080688A0
	.align 2, 0
_08068878: .4byte pZero2
_0806887C:
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #0
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
_080688A0:
	adds r2, r3, #0
_080688A2:
	ldrb r2, [r2]
	cmp r2, #0
	bne _080688AE
	strb r2, [r4, #0x13]
	movs r0, #1
	b _080688B4
_080688AE:
	movs r0, #6
	strb r0, [r4, #0x13]
	movs r0, #2
_080688B4:
	strb r0, [r4, #0xe]
	ldr r1, _080688F0 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _080688F4 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080688F8 @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
	movs r0, #6
	strb r0, [r4, #0x12]
	b _08068A50
	.align 2, 0
_080688F0: .4byte 0x083661F4
_080688F4: .4byte 0x08366204
_080688F8: .4byte 0x0836609C
_080688FC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068976
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068976
	ldrb r0, [r4, #0x13]
	cmp r0, #5
	bls _08068918
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068976
_08068918:
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068946
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08068946:
	ldr r1, _08068984 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068988 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0806898C @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068976:
	ldr r0, _08068990 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bgt _08068A16
	b _08068A3C
	.align 2, 0
_08068984: .4byte 0x083661F4
_08068988: .4byte 0x08366204
_0806898C: .4byte 0x0836609C
_08068990: .4byte pZero2
_08068994:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068A0A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08068A0A
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080689B2
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068A0A
_080689B2:
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080689DA
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
_080689DA:
	ldr r1, _08068A2C @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068A30 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08068A34 @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068A0A:
	ldr r0, _08068A38 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08068A3C
_08068A16:
	ldrb r2, [r4, #0x13]
	cmp r2, #2
	bne _08068A50
	adds r0, r4, #0
	adds r0, #0xbb
	movs r1, #0
	strb r2, [r0]
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08068A50
	.align 2, 0
_08068A2C: .4byte 0x083661F4
_08068A30: .4byte 0x08366204
_08068A34: .4byte 0x0836609C
_08068A38: .4byte pZero2
_08068A3C:
	ldrb r3, [r4, #0x13]
	adds r2, r3, #0
	cmp r2, #4
	bne _08068A50
	adds r1, r4, #0
	adds r1, #0xbb
	movs r0, #0
	strb r3, [r1]
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_08068A50:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08068AC8
_08068A58:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068AD0 @ =0x0836609C
	bl SetDDP
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r3, [r5]
	cmp r3, #0
	beq _08068A9E
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r5]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _08068AD4 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068A9E:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068AA8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068AC8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08068AC8
	ldrb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068AC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068AD0: .4byte 0x0836609C
_08068AD4: .4byte gVFXFnTable

	thumb_func_start FUN_08068ad8
FUN_08068ad8: @ 0x08068AD8
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068adc
FUN_08068adc: @ 0x08068ADC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xa
	bls _08068AEA
	b _08068C70
_08068AEA:
	lsls r0, r0, #2
	ldr r1, _08068AF4 @ =_08068AF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068AF4: .4byte _08068AF8
_08068AF8: @ jump table
	.4byte _08068B24 @ case 0
	.4byte _08068C1E @ case 1
	.4byte _08068B30 @ case 2
	.4byte _08068B50 @ case 3
	.4byte _08068C18 @ case 4
	.4byte _08068B84 @ case 5
	.4byte _08068B9A @ case 6
	.4byte _08068C0E @ case 7
	.4byte _08068C18 @ case 8
	.4byte _08068C36 @ case 9
	.4byte _08068C4A @ case 10
_08068B24:
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068C1E
_08068B30:
	ldr r0, _08068B78 @ =0x00000103
	bl PlaySound
	ldr r1, _08068B7C @ =0x00000805
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068B50:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08068B62
	b _08068C70
_08068B62:
	adds r1, r5, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08068B80 @ =0x083661A4
	bl SetDDP
	b _08068C2E
	.align 2, 0
_08068B78: .4byte 0x00000103
_08068B7C: .4byte 0x00000805
_08068B80: .4byte 0x083661A4
_08068B84:
	ldr r1, _08068BCC @ =0x00000806
	adds r0, r5, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r5, #0x12]
	movs r0, #3
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068B9A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08068C04
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068C04
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	movs r7, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08068BD4
	ldr r0, [r5, #0x54]
	ldr r1, _08068BD0 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp]
	movs r6, #0xa0
	lsls r6, r6, #2
	movs r2, #0
	b _08068BE4
	.align 2, 0
_08068BCC: .4byte 0x00000806
_08068BD0: .4byte 0xFFFFE800
_08068BD4:
	ldr r0, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp]
	movs r6, #0xa0
	lsls r6, r6, #2
	movs r2, #0x80
_08068BE4:
	mov r0, sp
	adds r1, r6, #0
	bl CreateLemon
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2c
	bl PlaySound
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
_08068C04:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	b _08068C2A
_08068C0E:
	movs r0, #0x16
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068C18:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08068C1E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08068C70
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
_08068C2A:
	cmp r0, #0
	bne _08068C70
_08068C2E:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08068C70
_08068C36:
	ldr r0, _08068C78 @ =0x00000103
	bl PlaySound
	ldr r1, _08068C7C @ =0x00000807
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08068C4A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08068C70
	adds r0, r5, #0
	adds r0, #0xb9
	movs r4, #0
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08068C80 @ =0x08366144
	bl SetDDP
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_08068C70:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068C78: .4byte 0x00000103
_08068C7C: .4byte 0x00000807
_08068C80: .4byte 0x08366144

	thumb_func_start FUN_08068c84
FUN_08068c84: @ 0x08068C84
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068c88
FUN_08068c88: @ 0x08068C88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08068C94
	b _08068E50
_08068C94:
	lsls r0, r0, #2
	ldr r1, _08068CA0 @ =_08068CA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068CA0: .4byte _08068CA4
_08068CA4: @ jump table
	.4byte _08068CD4 @ case 0
	.4byte _08068D10 @ case 1
	.4byte _08068D56 @ case 2
	.4byte _08068E50 @ case 3
	.4byte _08068E50 @ case 4
	.4byte _08068E50 @ case 5
	.4byte _08068E50 @ case 6
	.4byte _08068E50 @ case 7
	.4byte _08068E50 @ case 8
	.4byte _08068E50 @ case 9
	.4byte _08068DE0 @ case 10
	.4byte _08068E30 @ case 11
_08068CD4:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08068CEA
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
	movs r0, #1
	b _08068CF4
_08068CEA:
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	strb r0, [r4, #0x13]
	movs r0, #2
_08068CF4:
	strb r0, [r4, #0xe]
	ldr r1, _08068D0C @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	b _08068DCC
	.align 2, 0
_08068D0C: .4byte 0x083661F4
_08068D10:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068DCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068DCC
	ldrb r0, [r4, #0x13]
	cmp r0, #5
	bhi _08068D6E
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068D9C
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _08068D9C
_08068D56:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068DCC
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08068DCC
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _08068D74
_08068D6E:
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068DCC
_08068D74:
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068D9C
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
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
_08068D9C:
	ldr r1, _08068DD4 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068DD8 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08068DDC @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068DCC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08068E50
	.align 2, 0
_08068DD4: .4byte 0x083661F4
_08068DD8: .4byte 0x08366204
_08068DDC: .4byte 0x0836609C
_08068DE0:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068E58 @ =0x0836609C
	bl SetDDP
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r3, [r5]
	cmp r3, #0
	beq _08068E26
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r5]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _08068E5C @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068E26:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068E30:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068E50
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08068E50
	ldrb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068E50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068E58: .4byte 0x0836609C
_08068E5C: .4byte gVFXFnTable

	thumb_func_start FUN_08068e60
FUN_08068e60: @ 0x08068E60
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068e64
FUN_08068e64: @ 0x08068E64
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08068E7E
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068EA8 @ =0x083661BC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068E7E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08068EA0
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068EAC @ =0x083661A4
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068EA0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068EA8: .4byte 0x083661BC
_08068EAC: .4byte 0x083661A4

	thumb_func_start FUN_08068eb0
FUN_08068eb0: @ 0x08068EB0
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068eb4
FUN_08068eb4: @ 0x08068EB4
	bx lr
	.align 2, 0

	thumb_func_start FUN_08068eb8
FUN_08068eb8: @ 0x08068EB8
	movs r0, #1
	bx lr

	thumb_func_start FUN_08068ebc
FUN_08068ebc: @ 0x08068EBC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08068ED6
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068F00 @ =0x083661BC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068ED6:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08068EF8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068F04 @ =0x083661A4
	bl SetDDP
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068EF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068F00: .4byte 0x083661BC
_08068F04: .4byte 0x083661A4

	thumb_func_start FUN_08068f08
FUN_08068f08: @ 0x08068F08
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _08068F5C
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08068F5C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	ldr r2, _08068F64 @ =0x083661EC
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	bne _08068F5C
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08068F5C
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08068F5C
	movs r0, #0x64
	strb r0, [r1]
_08068F5C:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08068F64: .4byte 0x083661EC

	thumb_func_start FUN_08068f68
FUN_08068f68: @ 0x08068F68
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #4]
	ldr r2, [r4, #0x2c]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x5c]
	str r1, [r2, #0x60]
	ldr r0, [r3, #4]
	ldr r1, _08068FAC @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08068FA4
	ldr r2, [r4, #0x2c]
	adds r0, r2, #0
	adds r0, #0xb9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068FA4
	ldr r1, _08068FB0 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_08068FA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08068FAC: .4byte 0x000200FF
_08068FB0: .4byte gEnemyFnTable
