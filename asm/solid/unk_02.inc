	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cafd0
FUN_080cafd0: @ 0x080CAFD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080CAFDC
	b _080CB14E
_080CAFDC:
	lsls r0, r0, #2
	ldr r1, _080CAFE8 @ =_080CAFEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CAFE8: .4byte _080CAFEC
_080CAFEC: @ jump table
	.4byte _080CB000 @ case 0
	.4byte _080CB050 @ case 1
	.4byte _080CB068 @ case 2
	.4byte _080CB0A4 @ case 3
	.4byte _080CB0F8 @ case 4
_080CB000:
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
	ldr r1, _080CB04C @ =0x00001202
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x9e
	bl PlaySound
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
	movs r0, #0x40
	b _080CB0E4
	.align 2, 0
_080CB04C: .4byte 0x00001202
_080CB050:
	ldrb r1, [r4, #0x10]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CB062
	ldr r0, _080CB0A0 @ =gCollisionManager
	strb r1, [r0, #1]
_080CB062:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CB068:
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
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB14E
	movs r0, #0x38
	b _080CB0E4
	.align 2, 0
_080CB0A0: .4byte gCollisionManager
_080CB0A4:
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
	bne _080CB0C8
	ldr r1, _080CB0F0 @ =gStageRun+232
	adds r0, r4, #0
	adds r0, #0xbc
	str r0, [r1, #0x48]
_080CB0C8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB14E
	movs r0, #0x9f
	bl PlaySound
	ldr r1, _080CB0F4 @ =0x00001203
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080CB0E4:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CB14E
	.align 2, 0
_080CB0F0: .4byte gStageRun+232
_080CB0F4: .4byte 0x00001203
_080CB0F8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB14E
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB12C
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_0800a05c
	ldr r1, [r5]
	str r0, [r1, #0x58]
_080CB12C:
	ldr r1, _080CB154 @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080CB158 @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	ldr r3, [r5]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080CB15C @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080CB14E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB154: .4byte gStageRun
_080CB158: .4byte 0x0000FFFE
_080CB15C: .4byte 0x00000119

	thumb_func_start FUN_080cb160
FUN_080cb160: @ 0x080CB160
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080CB16C
	b _080CB2E6
_080CB16C:
	lsls r0, r0, #2
	ldr r1, _080CB178 @ =_080CB17C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CB178: .4byte _080CB17C
_080CB17C: @ jump table
	.4byte _080CB190 @ case 0
	.4byte _080CB1E4 @ case 1
	.4byte _080CB1FC @ case 2
	.4byte _080CB23C @ case 3
	.4byte _080CB290 @ case 4
_080CB190:
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
	ldr r1, _080CB1DC @ =0x00001202
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x9e
	bl PlaySound
	adds r2, r4, #0
	adds r2, #0xbc
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r0, [r0, #0x54]
	ldr r3, _080CB1E0 @ =0xFFFFC800
	adds r0, r0, r3
	str r0, [r2]
	ldr r0, [r1]
	ldr r0, [r0, #0x58]
	str r0, [r2, #4]
	movs r0, #0x40
	b _080CB27A
	.align 2, 0
_080CB1DC: .4byte 0x00001202
_080CB1E0: .4byte 0xFFFFC800
_080CB1E4:
	ldrb r1, [r4, #0x10]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080CB1F6
	ldr r0, _080CB238 @ =gCollisionManager
	strb r1, [r0, #1]
_080CB1F6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CB1FC:
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
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB2E6
	movs r0, #0x38
	b _080CB27A
	.align 2, 0
_080CB238: .4byte gCollisionManager
_080CB23C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	ldr r2, _080CB284 @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r1, #0x54]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x1c
	bne _080CB25E
	ldr r1, _080CB288 @ =gStageRun+232
	adds r0, r4, #0
	adds r0, #0xbc
	str r0, [r1, #0x48]
_080CB25E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB2E6
	movs r0, #0x9f
	bl PlaySound
	ldr r1, _080CB28C @ =0x00001203
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_080CB27A:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080CB2E6
	.align 2, 0
_080CB284: .4byte 0xFFFFFF00
_080CB288: .4byte gStageRun+232
_080CB28C: .4byte 0x00001203
_080CB290:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CB2E6
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CB2C4
	ldr r1, [r5]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	bl FUN_0800a05c
	ldr r1, [r5]
	str r0, [r1, #0x58]
_080CB2C4:
	ldr r1, _080CB2EC @ =gStageRun
	ldrh r2, [r1, #0x14]
	ldr r0, _080CB2F0 @ =0x0000FFFE
	ands r0, r2
	movs r2, #0
	strh r0, [r1, #0x14]
	adds r1, #0xe8
	ldr r3, [r5]
	adds r0, r3, #0
	adds r0, #0x54
	str r0, [r1, #0x48]
	ldr r1, _080CB2F4 @ =0x00000119
	adds r0, r3, r1
	strb r2, [r0]
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080CB2E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB2EC: .4byte gStageRun
_080CB2F0: .4byte 0x0000FFFE
_080CB2F4: .4byte 0x00000119

	thumb_func_start FUN_080cb2f8
FUN_080cb2f8: @ 0x080CB2F8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xe]
	cmp r4, #1
	beq _080CB316
	cmp r4, #1
	bgt _080CB30C
	cmp r4, #0
	beq _080CB312
	b _080CB358
_080CB30C:
	cmp r4, #2
	beq _080CB336
	b _080CB358
_080CB312:
	movs r0, #1
	strb r0, [r5, #0xe]
_080CB316:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080CB358
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080CB356
_080CB336:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x10]
	ands r4, r0
	cmp r4, #0
	beq _080CB358
	ldr r0, _080CB360 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080CB358
	strb r0, [r5, #0xd]
_080CB356:
	strb r0, [r5, #0xe]
_080CB358:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB360: .4byte gCurStory
