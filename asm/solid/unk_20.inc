	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080d04cc
FUN_080d04cc: @ 0x080D04CC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080D04D8
	b _080D0652
_080D04D8:
	lsls r0, r0, #2
	ldr r1, _080D04E4 @ =_080D04E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D04E4: .4byte _080D04E8
_080D04E8: @ jump table
	.4byte _080D04FC @ case 0
	.4byte _080D0554 @ case 1
	.4byte _080D0560 @ case 2
	.4byte _080D05A8 @ case 3
	.4byte _080D05FC @ case 4
_080D04FC:
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
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D054C @ =0x00007A02
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xbc
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r0, [r0, #0x54]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r0, r3
	str r0, [r2]
	ldr r0, [r1]
	ldr r0, [r0, #0x58]
	str r0, [r2, #4]
	ldr r2, _080D0550 @ =gCollisionManager
	ldrb r1, [r2, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0x40
	b _080D05E8
	.align 2, 0
_080D054C: .4byte 0x00007A02
_080D0550: .4byte gCollisionManager
_080D0554:
	ldr r1, _080D05A4 @ =gCollisionManager
	movs r0, #0
	strb r0, [r1, #1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D0560:
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r0, [r3]
	adds r0, #0x4c
	movs r1, #1
	strb r1, [r0]
	ldr r1, [r3]
	adds r1, #0x4a
	ldrb r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	ldrb r0, [r1, #0xa]
	orrs r2, r0
	strb r2, [r1, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D0592
	movs r0, #0x9c
	bl PlaySound
_080D0592:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D0652
	movs r0, #0x38
	b _080D05E8
	.align 2, 0
_080D05A4: .4byte gCollisionManager
_080D05A8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r1, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D05CC
	ldr r1, _080D05F4 @ =gStageRun+232
	adds r0, r4, #0
	adds r0, #0xbc
	str r0, [r1, #0x48]
_080D05CC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D0652
	movs r0, #0x9d
	bl PlaySound
	ldr r1, _080D05F8 @ =0x00007A03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080D05E8:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080D0652
	.align 2, 0
_080D05F4: .4byte gStageRun+232
_080D05F8: .4byte 0x00007A03
_080D05FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D0652
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D0630
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_0800a05c
	ldr r1, [r5]
	str r0, [r1, #0x58]
_080D0630:
	ldr r1, _080D0658 @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080D065C @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	ldr r3, [r5]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080D0660 @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080D0652:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0658: .4byte gStageRun
_080D065C: .4byte 0x0000FFFE
_080D0660: .4byte 0x00000119

	thumb_func_start FUN_080d0664
FUN_080d0664: @ 0x080D0664
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080D0670
	b _080D07F2
_080D0670:
	lsls r0, r0, #2
	ldr r1, _080D067C @ =_080D0680
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D067C: .4byte _080D0680
_080D0680: @ jump table
	.4byte _080D0694 @ case 0
	.4byte _080D06F0 @ case 1
	.4byte _080D06FC @ case 2
	.4byte _080D0748 @ case 3
	.4byte _080D079C @ case 4
_080D0694:
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
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080D06E4 @ =0x00007A02
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xbc
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r0, [r0, #0x54]
	ldr r3, _080D06E8 @ =0xFFFFC800
	adds r0, r0, r3
	str r0, [r2]
	ldr r0, [r1]
	ldr r0, [r0, #0x58]
	str r0, [r2, #4]
	ldr r2, _080D06EC @ =gCollisionManager
	ldrb r1, [r2, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0x40
	b _080D0786
	.align 2, 0
_080D06E4: .4byte 0x00007A02
_080D06E8: .4byte 0xFFFFC800
_080D06EC: .4byte gCollisionManager
_080D06F0:
	ldr r1, _080D0744 @ =gCollisionManager
	movs r0, #0
	strb r0, [r1, #1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080D06FC:
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r0, [r3]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r3]
	adds r1, #0x4a
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r2, [r3]
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D0732
	movs r0, #0x9c
	bl PlaySound
_080D0732:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D07F2
	movs r0, #0x38
	b _080D0786
	.align 2, 0
_080D0744: .4byte gCollisionManager
_080D0748:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r2, _080D0790 @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r1, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080D076A
	ldr r1, _080D0794 @ =gStageRun+232
	adds r0, r4, #0
	adds r0, #0xbc
	str r0, [r1, #0x48]
_080D076A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D07F2
	movs r0, #0x9d
	bl PlaySound
	ldr r1, _080D0798 @ =0x00007A03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080D0786:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080D07F2
	.align 2, 0
_080D0790: .4byte 0xFFFFFF00
_080D0794: .4byte gStageRun+232
_080D0798: .4byte 0x00007A03
_080D079C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D07F2
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D07D0
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_0800a05c
	ldr r1, [r5]
	str r0, [r1, #0x58]
_080D07D0:
	ldr r1, _080D07F8 @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080D07FC @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	ldr r3, [r5]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080D0800 @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080D07F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D07F8: .4byte gStageRun
_080D07FC: .4byte 0x0000FFFE
_080D0800: .4byte 0x00000119

	thumb_func_start FUN_080d0804
FUN_080d0804: @ 0x080D0804
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _080D0822
	cmp r4, #1
	bgt _080D0818
	cmp r4, #0
	beq _080D081E
	b _080D0864
_080D0818:
	cmp r4, #2
	beq _080D0842
	b _080D0864
_080D081E:
	movs r0, #1
	strb r0, [r5, #0xe]
_080D0822:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D0864
	movs r1, #0xf4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080D0862
_080D0842:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x10]
	ands r4, r0
	cmp r4, #0
	beq _080D0864
	ldr r0, _080D086C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080D0864
	strb r0, [r5, #0xd]
_080D0862:
	strb r0, [r5, #0xe]
_080D0864:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D086C: .4byte gCurStory
