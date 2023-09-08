	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start UpdateCerveau
UpdateCerveau: @ 0x080DB404
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #7
	bls _080DB410
	b _080DB6DE
_080DB410:
	lsls r0, r0, #2
	ldr r1, _080DB41C @ =_080DB420
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DB41C: .4byte _080DB420
_080DB420: @ jump table
	.4byte _080DB440 @ case 0
	.4byte _080DB4FA @ case 1
	.4byte _080DB5A8 @ case 2
	.4byte _080DB5EC @ case 3
	.4byte _080DB63C @ case 4
	.4byte _080DB660 @ case 5
	.4byte _080DB684 @ case 6
	.4byte _080DB6A8 @ case 7
_080DB440:
	ldr r0, _080DB484 @ =gCurStory
	ldrb r1, [r0, #6]
	movs r0, #0x14
	ands r0, r1
	cmp r0, #4
	bne _080DB48C
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DB488 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DB6DE
	.align 2, 0
_080DB484: .4byte gCurStory
_080DB488: .4byte gSolidFnTable
_080DB48C:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r5, #0
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
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DB57C @ =Collision_ARRAY_083713b0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080DB4FA:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	bne _080DB512
	b _080DB6DE
_080DB512:
	ldr r0, _080DB580 @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DB51C
	b _080DB6DE
_080DB51C:
	ldr r0, _080DB584 @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	beq _080DB530
	b _080DB6DE
_080DB530:
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r2, _080DB588 @ =gCurStory
	ldrb r1, [r2, #5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DB598
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #5]
	ldr r0, _080DB58C @ =0x00001307
	bl PrintNormalMessage
	ldr r0, _080DB590 @ =gStageRun+16
	ldr r1, _080DB594 @ =gStageScriptList
	ldr r1, [r1, #0x44]
	ldr r1, [r1, #0x14]
	adds r2, r6, #0
	bl FUN_08021cb4
	movs r0, #3
	strb r0, [r6, #0xd]
	b _080DB6DE
	.align 2, 0
_080DB57C: .4byte Collision_ARRAY_083713b0
_080DB580: .4byte gInChat
_080DB584: .4byte gCollisionManager
_080DB588: .4byte gCurStory
_080DB58C: .4byte 0x00001307
_080DB590: .4byte gStageRun+16
_080DB594: .4byte gStageScriptList
_080DB598:
	ldr r0, _080DB5A4 @ =gGameState
	movs r1, #0xc1
	lsls r1, r1, #0xa
	bl SetGameMode
	b _080DB6A0
	.align 2, 0
_080DB5A4: .4byte gGameState
_080DB5A8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080DB5E4 @ =gGameState
	ldrb r1, [r0, #2]
	cmp r1, #0
	beq _080DB5B8
	b _080DB6DE
_080DB5B8:
	ldr r0, _080DB5E8 @ =gInChat
	strb r1, [r0]
	movs r3, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r3, [r0]
	adds r4, r6, #0
	adds r4, #0x4a
	movs r2, #0x10
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	strb r3, [r6, #0xd]
	b _080DB6DE
	.align 2, 0
_080DB5E4: .4byte gGameState
_080DB5E8: .4byte gInChat
_080DB5EC:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080DB62C @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _080DB6DE
	ldr r2, _080DB630 @ =pZero2
	ldr r0, [r2]
	adds r0, #0xb4
	ldrb r1, [r0, #0x16]
	movs r3, #4
	orrs r1, r3
	strb r1, [r0, #0x16]
	ldr r1, [r2]
	adds r1, #0xb4
	ldrb r0, [r1, #0x16]
	movs r2, #8
	orrs r0, r2
	strb r0, [r1, #0x16]
	ldr r1, _080DB634 @ =gGameState+25696
	ldrb r0, [r1, #0x16]
	orrs r0, r3
	orrs r0, r2
	strb r0, [r1, #0x16]
	ldr r1, _080DB638 @ =0x0000C201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080DB6A0
	.align 2, 0
_080DB62C: .4byte gTextWindow+8
_080DB630: .4byte pZero2
_080DB634: .4byte gGameState+25696
_080DB638: .4byte 0x0000C201
_080DB63C:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB6DE
	ldr r1, _080DB65C @ =0x0000C202
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	b _080DB6A0
	.align 2, 0
_080DB65C: .4byte 0x0000C202
_080DB660:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB6DE
	ldr r1, _080DB680 @ =0x0000C201
	adds r0, r6, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r6, #0x12]
	b _080DB6A0
	.align 2, 0
_080DB680: .4byte 0x0000C201
_080DB684:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB6DE
	movs r1, #0xc2
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
_080DB6A0:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080DB6DE
_080DB6A8:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, _080DB6E4 @ =gStageRun
	ldrb r1, [r0, #0x12]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080DB6DE
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	strb r4, [r6, #0xd]
_080DB6DE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DB6E4: .4byte gStageRun

	thumb_func_start UpdateBlockingColbor
UpdateBlockingColbor: @ 0x080DB6E8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r2, [r5, #0xd]
	cmp r2, #1
	beq _080DB7BA
	cmp r2, #1
	bgt _080DB6FC
	cmp r2, #0
	beq _080DB704
	b _080DB862
_080DB6FC:
	cmp r2, #2
	bne _080DB702
	b _080DB84C
_080DB702:
	b _080DB862
_080DB704:
	ldr r0, _080DB74C @ =gCurStory
	ldrb r1, [r0, #5]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _080DB754
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080DB750 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080DB862
	.align 2, 0
_080DB74C: .4byte gCurStory
_080DB750: .4byte gSolidFnTable
_080DB754:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r1, #0x82
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DB808 @ =Collision_ARRAY_083713e0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DB7BA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	beq _080DB862
	ldr r0, _080DB80C @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DB862
	ldr r0, _080DB810 @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	bne _080DB862
	movs r2, #0
	ldr r0, _080DB814 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080DB7FC
	movs r2, #1
_080DB7FC:
	cmp r2, #0
	beq _080DB818
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080DB81E
	.align 2, 0
_080DB808: .4byte Collision_ARRAY_083713e0
_080DB80C: .4byte gInChat
_080DB810: .4byte gCollisionManager
_080DB814: .4byte pZero2
_080DB818:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080DB81E:
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
	ldr r0, _080DB848 @ =0x00001306
	bl PrintNormalMessage
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080DB860
	.align 2, 0
_080DB848: .4byte 0x00001306
_080DB84C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080DB868 @ =gTextWindow+8
	ldrh r1, [r0, #2]
	cmp r1, #0
	bne _080DB862
	ldr r0, _080DB86C @ =gInChat
	strb r1, [r0]
	movs r0, #1
_080DB860:
	strb r0, [r5, #0xd]
_080DB862:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DB868: .4byte gTextWindow+8
_080DB86C: .4byte gInChat

	thumb_func_start UpdateSearchConsole
UpdateSearchConsole: @ 0x080DB870
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080DB8BC
	cmp r6, #1
	bgt _080DB884
	cmp r6, #0
	beq _080DB88A
	b _080DB920
_080DB884:
	cmp r6, #2
	beq _080DB910
	b _080DB920
_080DB88A:
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DB8FC @ =Collision_ARRAY_08371410
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DB8BC:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	beq _080DB920
	ldr r0, _080DB900 @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DB920
	ldr r0, _080DB904 @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	bne _080DB920
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _080DB908 @ =gGameState
	ldr r1, _080DB90C @ =0x00070400
	bl SetGameMode
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080DB91E
	.align 2, 0
_080DB8FC: .4byte Collision_ARRAY_08371410
_080DB900: .4byte gInChat
_080DB904: .4byte gCollisionManager
_080DB908: .4byte gGameState
_080DB90C: .4byte 0x00070400
_080DB910:
	ldr r0, _080DB928 @ =gGameState
	ldrb r1, [r0, #2]
	cmp r1, #0
	bne _080DB920
	ldr r0, _080DB92C @ =gInChat
	strb r1, [r0]
	movs r0, #1
_080DB91E:
	strb r0, [r5, #0xd]
_080DB920:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DB928: .4byte gGameState
_080DB92C: .4byte gInChat

	thumb_func_start FUN_080db930
FUN_080db930: @ 0x080DB930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080DB9D6
	cmp r6, #1
	bgt _080DB944
	cmp r6, #0
	beq _080DB94A
	b _080DBA2C
_080DB944:
	cmp r6, #2
	beq _080DBA1C
	b _080DBA2C
_080DB94A:
	ldr r0, _080DB994 @ =gCurStory
	ldr r0, [r0, #4]
	movs r1, #0x82
	lsls r1, r1, #0xb
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	beq _080DB99C
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080DB998 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080DBA2C
	.align 2, 0
_080DB994: .4byte gCurStory
_080DB998: .4byte gSolidFnTable
_080DB99C:
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DBA0C @ =Collision_ARRAY_08371410
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DB9D6:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x16
	ands r0, r1
	cmp r0, #0
	beq _080DBA2C
	ldr r0, _080DBA10 @ =gInChat
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DBA2C
	ldr r0, _080DBA14 @ =gCollisionManager
	movs r1, #0xc5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x74
	ldr r0, [r0]
	cmp r0, r1
	bne _080DBA2C
	ldr r0, _080DBA18 @ =0x00001333
	bl PrintNormalMessage
	ldrb r0, [r5, #0xd]
	adds r0, #1
	b _080DBA2A
	.align 2, 0
_080DBA0C: .4byte Collision_ARRAY_08371410
_080DBA10: .4byte gInChat
_080DBA14: .4byte gCollisionManager
_080DBA18: .4byte 0x00001333
_080DBA1C:
	ldr r0, _080DBA34 @ =gTextWindow+8
	ldrh r1, [r0, #2]
	cmp r1, #0
	bne _080DBA2C
	ldr r0, _080DBA38 @ =gInChat
	strb r1, [r0]
	movs r0, #1
_080DBA2A:
	strb r0, [r5, #0xd]
_080DBA2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DBA34: .4byte gTextWindow+8
_080DBA38: .4byte gInChat
