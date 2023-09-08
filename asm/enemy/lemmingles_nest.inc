	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0806df3c
FUN_0806df3c: @ 0x0806DF3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0806DF90 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0806DF9C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0806DF94 @ =gEnemyFnTable
	movs r0, #0xc
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	str r4, [r3, #0x28]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0806DF98
	movs r0, #2
	b _0806DF9A
	.align 2, 0
_0806DF90: .4byte gZakoHeaderPtr
_0806DF94: .4byte gEnemyFnTable
_0806DF98:
	movs r0, #3
_0806DF9A:
	strb r0, [r3, #0x10]
_0806DF9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0806dfa4
FUN_0806dfa4: @ 0x0806DFA4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0806DFB4
	cmp r0, #1
	beq _0806DFF8
	b _0806E008
_0806DFB4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806E008
	ldr r1, _0806DFF0 @ =0x083667A4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806DFF4 @ =0x083667B4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #1
	b _0806E00A
	.align 2, 0
_0806DFF0: .4byte 0x083667A4
_0806DFF4: .4byte 0x083667B4
_0806DFF8:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0806E006
	movs r0, #1
	b _0806E00A
_0806E006:
	strb r0, [r4, #0xf]
_0806E008:
	movs r0, #0
_0806E00A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start LemminglesNest_Init
LemminglesNest_Init: @ 0x0806E010
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0806E0B8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0806E0BC @ =0x0836680C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0806E0AC
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0806E066
	adds r0, r5, #0
	bl FUN_0806df3c
_0806E066:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0806E0C0 @ =0x083667C4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	orrs r0, r6
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	ldr r1, _0806E0C4 @ =0xFFFFFEFF
	ands r0, r1
	ldr r1, _0806E0C8 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0806E0CC @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0806E0D0 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r2]
_0806E0AC:
	adds r0, r5, #0
	bl LemminglesNest_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E0B8: .4byte gEnemyFnTable
_0806E0BC: .4byte 0x0836680C
_0806E0C0: .4byte 0x083667C4
_0806E0C4: .4byte 0xFFFFFEFF
_0806E0C8: .4byte 0xFFFFFDFF
_0806E0CC: .4byte 0xFFFFFBFF
_0806E0D0: .4byte 0xFFFFF7FF

	thumb_func_start LemminglesNest_Update
LemminglesNest_Update: @ 0x0806E0D4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bls _0806E10C
	ldr r0, _0806E108 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0806E10C
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
	b _0806E1AA
	.align 2, 0
_0806E108: .4byte gCurStory
_0806E10C:
	ldrb r0, [r4, #0x10]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0806E122
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0806E150
	b _0806E132
_0806E122:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0806E150
_0806E132:
	ldr r1, _0806E14C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl LemminglesNest_Die
	b _0806E1C4
	.align 2, 0
_0806E14C: .4byte gEnemyFnTable
_0806E150:
	adds r0, r4, #0
	bl FUN_0806dfa4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0806E1C4
	ldr r1, _0806E1CC @ =0x083667A4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0806E1D0 @ =0x083667B4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r0, _0806E1D4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc8
	lsls r1, r1, #9
	cmp r0, r1
	bls _0806E1C4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_0806E1AA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0806E1D8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0806E1C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E1CC: .4byte 0x083667A4
_0806E1D0: .4byte 0x083667B4
_0806E1D4: .4byte gStageRun+232
_0806E1D8: .4byte gEnemyFnTable

	thumb_func_start LemminglesNest_Die
LemminglesNest_Die: @ 0x0806E1DC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _0806E1F0
	cmp r0, #4
	beq _0806E1F0
	cmp r0, #5
	bne _0806E25A
_0806E1F0:
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0806E274 @ =0xFFFFF000
	adds r0, r0, r1
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
	ldr r2, _0806E278 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0806E27C @ =0x0000270E
	cmp r1, r0
	bhi _0806E240
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806E240:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0806E25A:
	ldr r1, _0806E280 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806E274: .4byte 0xFFFFF000
_0806E278: .4byte gMission
_0806E27C: .4byte 0x0000270E
_0806E280: .4byte gEnemyFnTable

	thumb_func_start nop_0806e284
nop_0806e284: @ 0x0806E284
	bx lr
	.align 2, 0

	thumb_func_start FUN_0806e288
FUN_0806e288: @ 0x0806E288
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806E298
	cmp r0, #1
	beq _0806E330
	b _0806E3A6
_0806E298:
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bls _0806E2D6
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806E2C8 @ =0x083667F4
	bl SetDDP
	ldrb r0, [r4, #0xa]
	movs r2, #0xfe
	ands r2, r0
	strb r2, [r4, #0xa]
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #5
	bne _0806E2BA
	movs r1, #1
_0806E2BA:
	adds r3, r1, #0
	cmp r3, #0
	beq _0806E2CC
	movs r1, #0x10
	adds r0, r2, #0
	orrs r0, r1
	b _0806E2D0
	.align 2, 0
_0806E2C8: .4byte 0x083667F4
_0806E2CC:
	movs r0, #0xef
	ands r0, r2
_0806E2D0:
	strb r0, [r4, #0xa]
	adds r1, r3, #0
	b _0806E306
_0806E2D6:
	ldr r1, _0806E2F8 @ =0x00001E14
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0806E2E8
	movs r1, #1
_0806E2E8:
	adds r2, r1, #0
	cmp r2, #0
	beq _0806E2FC
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806E302
	.align 2, 0
_0806E2F8: .4byte 0x00001E14
_0806E2FC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806E302:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
_0806E306:
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
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806E330:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0806E33C
	subs r0, #1
	strb r0, [r4, #0x12]
	b _0806E3A0
_0806E33C:
	ldr r2, _0806E35C @ =pZero2
	ldr r0, [r2]
	ldrb r0, [r0, #0xa]
	lsrs r3, r0, #4
	movs r6, #1
	ands r3, r6
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	beq _0806E360
	cmp r3, r6
	bne _0806E364
	b _0806E3A0
	.align 2, 0
_0806E35C: .4byte pZero2
_0806E360:
	cmp r3, #0
	beq _0806E3A0
_0806E364:
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r1, r1, r0
	movs r0, #0x10
	ands r0, r5
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0806E390
	cmp r1, #0
	bge _0806E3A0
	ldr r0, _0806E38C @ =0xFFFF8800
	cmp r1, r0
	ble _0806E3A0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0806E3A0
	.align 2, 0
_0806E38C: .4byte 0xFFFF8800
_0806E390:
	subs r1, #1
	ldr r0, _0806E3AC @ =0x000077FE
	cmp r1, r0
	bhi _0806E3A0
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806E3A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806E3A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806E3AC: .4byte 0x000077FE

	thumb_func_start FUN_0806e3b0
FUN_0806e3b0: @ 0x0806E3B0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806E3C0
	cmp r0, #1
	beq _0806E40E
	b _0806E4B6
_0806E3C0:
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r2, [r3]
	movs r0, #1
	ands r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #2
	ands r0, r1
	lsrs r0, r0, #1
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #4
	ands r0, r1
	lsrs r0, r0, #2
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	movs r1, #8
	ands r0, r1
	lsrs r0, r0, #3
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r3]
	subs r1, #0x19
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	subs r1, #0x20
	ands r0, r1
	subs r1, #0x40
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806E40E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0806E4B2
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r3, [r4, #0x13]
	ldr r0, [r4, #0x5c]
	cmp r0, r3
	bne _0806E470
	adds r0, r4, #0
	adds r0, #0xb4
	adds r2, r3, #7
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	lsrs r0, r2
	cmp r0, #0
	beq _0806E452
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0806e590
	b _0806E466
_0806E452:
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0806e590
_0806E466:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0806E4B6
_0806E470:
	adds r0, r4, #0
	adds r0, #0xb4
	adds r2, r3, #7
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	lsrs r0, r2
	cmp r0, #0
	beq _0806E49C
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0806e590
	b _0806E4B6
_0806E49C:
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	ands r2, r5
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0806e590
	b _0806E4B6
_0806E4B2:
	subs r0, #1
	strb r0, [r4, #0x12]
_0806E4B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806e4bc
FUN_0806e4bc: @ 0x0806E4BC
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r5, #1
	adds r1, r2, #0
	ands r1, r5
	movs r0, #2
	ands r0, r2
	lsrs r0, r0, #1
	adds r1, r1, r0
	movs r0, #4
	ands r0, r2
	lsrs r0, r0, #2
	adds r1, r1, r0
	movs r0, #8
	ands r0, r2
	lsrs r0, r0, #3
	adds r4, r1, r0
	movs r1, #0x10
	ands r1, r2
	lsrs r1, r1, #4
	movs r0, #0x20
	ands r0, r2
	lsrs r0, r0, #5
	adds r1, r1, r0
	movs r0, #0x40
	ands r0, r2
	lsrs r0, r0, #6
	adds r1, r1, r0
	movs r0, #0x80
	ands r2, r0
	lsrs r2, r2, #7
	adds r1, r1, r2
	cmp r4, r1
	bne _0806E512
	cmp r4, #0
	beq _0806E512
	movs r0, #0
	strb r0, [r3, #0xd]
	strb r5, [r3, #0xe]
	movs r0, #0x3c
	strb r0, [r3, #0x12]
_0806E512:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0806e518
FUN_0806e518: @ 0x0806E518
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0806E52A
	cmp r0, #1
	beq _0806E584
	b _0806E58A
_0806E52A:
	ldrb r0, [r4, #0xb]
	movs r6, #0x10
	movs r5, #0
	orrs r0, r6
	strb r0, [r4, #0xb]
	ldrb r0, [r1, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0806E558 @ =0x00001E15
	adds r0, r4, #0
	bl SetMotion
	movs r1, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _0806E54A
	movs r1, #1
_0806E54A:
	adds r2, r1, #0
	cmp r2, #0
	beq _0806E55C
	ldrb r0, [r4, #0xa]
	orrs r0, r6
	b _0806E562
	.align 2, 0
_0806E558: .4byte 0x00001E15
_0806E55C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806E562:
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
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806E584:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0806E58A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
