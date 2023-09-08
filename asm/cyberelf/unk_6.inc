	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Elf6_Init
Elf6_Init: @ 0x080E3678
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r0, _080E36F4 @ =gPause
	movs r4, #1
	strb r4, [r0]
	ldr r1, _080E36F8 @ =gElfFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	bl ResetDynamicMotion
	ldrb r0, [r6, #0xa]
	movs r7, #0
	orrs r0, r4
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	movs r0, #2
	bl createElfAction
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	ands r0, r4
	adds r1, r6, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	ands r1, r4
	adds r4, r6, #0
	adds r4, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	cmp r1, #0
	beq _080E36FC
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080E3702
	.align 2, 0
_080E36F4: .4byte gPause
_080E36F8: .4byte gElfFnTable
_080E36FC:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_080E3702:
	strb r0, [r6, #0xa]
	adds r2, r6, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xbc
	movs r1, #0
	str r1, [r0]
	subs r0, #4
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xb9
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x90
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	bl Elf6_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Elf6_Update
Elf6_Update: @ 0x080E373C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	ldr r1, _080E378C @ =gZeroRanges
	ldr r2, _080E3790 @ =0x00000147
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r7, [r0, #4]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E3776
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080E3798
_080E3776:
	ldr r1, _080E3794 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _080E3888
	.align 2, 0
_080E378C: .4byte gZeroRanges
_080E3790: .4byte 0x00000147
_080E3794: .4byte gElfFnTable
_080E3798:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	asrs r1, r6, #0x10
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r6, r0, #0
	adds r6, #0x60
	str r6, [r1]
	adds r4, r5, #0
	adds r4, #0xb8
	ldrb r0, [r4]
	adds r3, r0, #1
	adds r0, r3, #0
	movs r1, #0x30
	bl __modsi3
	adds r3, r0, #0
	strb r3, [r4]
	lsls r0, r3, #8
	movs r1, #0x30
	bl __divsi3
	adds r3, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _080E37E4
	movs r1, #1
_080E37E4:
	ldr r2, _080E3890 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	asrs r0, r0, #8
	muls r1, r0, r1
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r6, #0
	muls r1, r0, r1
	asrs r1, r1, #8
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	subs r4, r0, #1
	strh r4, [r1]
	adds r6, r5, #0
	adds r6, #0xb9
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E3840
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r6]
_080E3840:
	cmp r4, #0
	bne _080E3856
	ldr r1, _080E3894 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080E3856:
	cmp r4, #0xef
	bhi _080E3888
	movs r0, #0xf0
	subs r4, r0, r4
	lsls r0, r4, #4
	subs r1, r0, r4
	adds r0, r1, #0
	movs r1, #0xf0
	bl __udivsi3
	adds r1, r0, #0
	movs r0, #0xf
	ands r4, r0
	lsrs r4, r4, #2
	cmp r4, #1
	bne _080E3878
	adds r1, #1
_080E3878:
	ldr r2, _080E3898 @ =wMOSAIC
	movs r0, #0xf
	ands r1, r0
	lsls r0, r1, #4
	orrs r0, r1
	lsls r1, r0, #8
	orrs r0, r1
	strh r0, [r2]
_080E3888:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E3890: .4byte gSineTable
_080E3894: .4byte gElfFnTable
_080E3898: .4byte wMOSAIC

	thumb_func_start Elf6_Die
Elf6_Die: @ 0x080E389C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	ldrb r3, [r4, #0xd]
	adds r2, r3, #0
	cmp r2, #0
	beq _080E38AE
	b _080E39A8
_080E38AE:
	subs r0, #0x60
	movs r1, #0
	bl FUN_080bfce8
	ldr r1, _080E394C @ =gUnlockedElfPtr
	adds r3, r5, #0
	adds r3, #0xb4
	ldr r2, _080E3950 @ =0x00000121
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _080E3954 @ =0x08371D6A
	ldrb r0, [r4, #0x10]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _080E38E2
	ldrh r0, [r3, #4]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #4]
_080E38E2:
	ldr r1, _080E3958 @ =gMission
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0x4c
	ldrb r0, [r2]
	adds r6, r1, #0
	cmp r0, #0x62
	bhi _080E38F6
	adds r0, #1
	strb r0, [r2]
_080E38F6:
	ldr r1, _080E395C @ =0x08371D5C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	ldr r0, _080E3960 @ =gCurStory
	lsrs r2, r3, #3
	adds r0, #4
	adds r2, r2, r0
	movs r1, #7
	ands r1, r3
	movs r0, #1
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	cmp r3, #0x27
	bne _080E392C
	ldr r1, _080E3964 @ =gGameState+25200
	ldrb r0, [r1, #4]
	movs r2, #0x80
	orrs r0, r2
	strb r0, [r1, #4]
	adds r1, #0x54
	ldrb r0, [r1, #4]
	orrs r0, r2
	strb r0, [r1, #4]
_080E392C:
	cmp r3, #0x23
	bne _080E3982
	ldr r5, _080E3968 @ =0x0202F33C
	ldrh r2, [r5]
	ldr r1, _080E396C @ =0x00007FFF
	adds r0, r1, #0
	ands r0, r2
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r0, r7
	cmp r0, r1
	ble _080E3974
	ldr r1, _080E3970 @ =0x0000FFFF
	adds r0, r1, #0
	b _080E3980
	.align 2, 0
_080E394C: .4byte gUnlockedElfPtr
_080E3950: .4byte 0x00000121
_080E3954: .4byte 0x08371D6A
_080E3958: .4byte gMission
_080E395C: .4byte 0x08371D5C
_080E3960: .4byte gCurStory
_080E3964: .4byte gGameState+25200
_080E3968: .4byte 0x0202F33C
_080E396C: .4byte 0x00007FFF
_080E3970: .4byte 0x0000FFFF
_080E3974:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r2, r7
	ldr r2, _080E39A0 @ =0xFFFF8000
	adds r1, r2, #0
	orrs r0, r1
_080E3980:
	strh r0, [r5]
_080E3982:
	cmp r3, #0x28
	bne _080E398C
	ldr r1, [r6]
	movs r0, #5
	strb r0, [r1, #1]
_080E398C:
	ldr r1, _080E39A4 @ =gPause
	movs r0, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #4
	strb r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _080E39B6
	.align 2, 0
_080E39A0: .4byte 0xFFFF8000
_080E39A4: .4byte gPause
_080E39A8:
	adds r1, r4, #0
	adds r1, #0xc0
	cmp r2, #1
	bne _080E39B8
	ldr r0, _080E39FC @ =gPause
	strb r2, [r0]
	adds r0, r3, #1
_080E39B6:
	strb r0, [r4, #0xd]
_080E39B8:
	ldrb r0, [r1]
	subs r2, r0, #1
	strb r2, [r1]
	cmp r2, #0
	bne _080E39E0
	ldr r0, _080E39FC @ =gPause
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E3A00 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080E39E0:
	lsls r0, r2, #4
	subs r0, r0, r2
	lsrs r0, r0, #2
	ldr r2, _080E3A04 @ =wMOSAIC
	movs r1, #0xf
	ands r0, r1
	lsls r1, r0, #4
	orrs r1, r0
	lsls r0, r1, #8
	orrs r1, r0
	strh r1, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E39FC: .4byte gPause
_080E3A00: .4byte gElfFnTable
_080E3A04: .4byte wMOSAIC
