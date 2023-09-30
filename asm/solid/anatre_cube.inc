	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dec48
FUN_080dec48: @ 0x080DEC48
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080DECDC
	cmp r6, #1
	bgt _080DEC5E
	cmp r6, #0
	beq _080DEC6C
	b _080DEF34
_080DEC5E:
	cmp r6, #2
	bne _080DEC64
	b _080DED9C
_080DEC64:
	cmp r6, #3
	bne _080DEC6A
	b _080DEEB0
_080DEC6A:
	b _080DEF34
_080DEC6C:
	ldr r0, _080DED18 @ =gStageRun+232
	adds r7, r5, #0
	adds r7, #0x54
	adds r1, r7, #0
	bl CalcFromCamera
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bls _080DEC82
	b _080DEF34
_080DEC82:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r1, #0xe0
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x1d
	strb r0, [r1]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DED1C @ =0x083717EC
	adds r0, r4, #0
	adds r2, r7, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xb]
	movs r0, #0xef
	ands r0, r1
	ldrb r1, [r5, #0x1c]
	strb r1, [r5, #0x1d]
	movs r1, #8
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, _080DED20 @ =0x0837181C
	str r0, [r5, #0x30]
	ldr r0, _080DED24 @ =0x00002001
	strh r0, [r5, #0x26]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DECDC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq _080DED58
	ldr r0, _080DED28 @ =pZero2
	ldr r1, [r0]
	ldr r2, [r5, #0x54]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r2, r3
	ldr r1, [r1, #0x54]
	cmp r1, r0
	ble _080DED34
	ldr r1, _080DED2C @ =0xFFFFE000
	adds r0, r2, r1
	str r0, [r5, #0x5c]
	ldr r0, _080DED30 @ =0xFFFFF001
	str r0, [r5, #0x64]
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #2
	b _080DEF32
	.align 2, 0
_080DED18: .4byte gStageRun+232
_080DED1C: .4byte 0x083717EC
_080DED20: .4byte 0x0837181C
_080DED24: .4byte 0x00002001
_080DED28: .4byte pZero2
_080DED2C: .4byte 0xFFFFE000
_080DED30: .4byte 0xFFFFF001
_080DED34:
	ldr r3, _080DED50 @ =0xFFFFF000
	adds r0, r2, r3
	cmp r1, r0
	bge _080DED58
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r2, r1
	str r0, [r5, #0x5c]
	ldr r0, _080DED54 @ =0x00000FFF
	str r0, [r5, #0x64]
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #2
	b _080DEF32
	.align 2, 0
_080DED50: .4byte 0xFFFFF000
_080DED54: .4byte 0x00000FFF
_080DED58:
	ldr r0, _080DED98 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bhi _080DED6C
	b _080DEF34
_080DED6C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r5, #0xa]
	str r2, [r4]
	adds r0, r5, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r5, #0xb]
	strb r2, [r5, #0xd]
	b _080DEF34
	.align 2, 0
_080DED98: .4byte gStageRun+232
_080DED9C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	cmp r0, #0
	bge _080DEDB4
	ldr r0, [r5, #0x54]
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r0, [r5, #0x5c]
	adds r0, r1, r0
	b _080DEDC0
_080DEDB4:
	ldr r0, [r5, #0x54]
	lsls r1, r0, #3
	subs r1, r1, r0
	ldr r0, [r5, #0x5c]
	adds r1, r1, r0
	adds r0, r1, #7
_080DEDC0:
	cmp r0, #0
	bge _080DEDC6
	adds r0, #7
_080DEDC6:
	asrs r0, r0, #3
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0xf8
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	beq _080DEDFA
	ldr r0, [r5, #0x64]
	cmp r0, #0
	bge _080DEDF0
	ldr r0, [r5, #0x54]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	b _080DEDF2
_080DEDF0:
	ldr r0, [r5, #0x54]
_080DEDF2:
	ldr r1, _080DEE94 @ =0x7FFFF000
	ands r0, r1
	str r0, [r5, #0x5c]
	str r0, [r5, #0x54]
_080DEDFA:
	ldrb r1, [r5, #0x12]
	adds r1, #1
	strb r1, [r5, #0x12]
	ldr r6, _080DEE98 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r7, _080DEE9C @ =0x000343FD
	muls r0, r7, r0
	ldr r2, _080DEEA0 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1b
	adds r1, #1
	bl __umodsi3
	cmp r0, #0
	bne _080DEE5A
	adds r1, r4, #0
	muls r1, r7, r1
	ldr r3, _080DEEA0 @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r6]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	ldr r1, [r5, #0x58]
	movs r2, #0x90
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [sp, #4]
	bl PushoutToUp1
	cmp r0, #0
	beq _080DEE5A
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_080DEE5A:
	ldr r1, [r5, #0x5c]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bne _080DEF34
	ldr r3, _080DEEA4 @ =0x00000FFF
	adds r0, r1, r3
	ldr r1, [r5, #0x58]
	movs r2, #0x84
	lsls r2, r2, #6
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	bne _080DEEAC
	ldr r0, [r5, #0x54]
	ldr r3, _080DEEA8 @ =0xFFFFF001
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	movs r2, #0x84
	lsls r2, r2, #6
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	bne _080DEEAC
	str r0, [r5, #0x60]
	movs r0, #3
	b _080DEF32
	.align 2, 0
_080DEE94: .4byte 0x7FFFF000
_080DEE98: .4byte RNG_0202f388
_080DEE9C: .4byte 0x000343FD
_080DEEA0: .4byte 0x00269EC3
_080DEEA4: .4byte 0x00000FFF
_080DEEA8: .4byte 0xFFFFF001
_080DEEAC:
	movs r0, #0
	b _080DEF2E
_080DEEB0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x60]
	ldr r0, _080DEF3C @ =0x000006FF
	cmp r1, r0
	bgt _080DEEC4
	adds r0, r1, #0
	adds r0, #0x40
	str r0, [r5, #0x60]
_080DEEC4:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r3, _080DEF40 @ =0x00000FFF
	adds r0, r0, r3
	movs r6, #0x84
	lsls r6, r6, #6
	adds r1, r1, r6
	bl PushoutToUp1
	cmp r0, #0
	beq _080DEEF0
	ldr r0, [r5, #0x54]
	ldr r1, _080DEF40 @ =0x00000FFF
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
_080DEEF0:
	ldr r0, [r5, #0x54]
	ldr r2, _080DEF44 @ =0xFFFFF001
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	adds r1, r1, r6
	bl PushoutToUp1
	cmp r0, #0
	beq _080DEF10
	ldr r0, [r5, #0x54]
	ldr r3, _080DEF44 @ =0xFFFFF001
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
_080DEF10:
	cmp r4, #0
	beq _080DEF34
	movs r0, #0x41
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	ldr r1, _080DEF48 @ =0xFFFFE001
	adds r0, r4, r1
	str r0, [r5, #0x58]
	movs r0, #0
	str r0, [r5, #0x60]
_080DEF2E:
	str r0, [r5, #0x5c]
	movs r0, #1
_080DEF32:
	strb r0, [r5, #0xd]
_080DEF34:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEF3C: .4byte 0x000006FF
_080DEF40: .4byte 0x00000FFF
_080DEF44: .4byte 0xFFFFF001
_080DEF48: .4byte 0xFFFFE001

	thumb_func_start FUN_080def4c
FUN_080def4c: @ 0x080DEF4C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	ldrb r0, [r4, #0x11]
	cmp r0, #4
	beq _080DEF74
	ldr r0, _080DEF70 @ =0x00007002
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _080DEF82
	.align 2, 0
_080DEF70: .4byte 0x00007002
_080DEF74:
	ldr r0, _080DEFA0 @ =0x00007006
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a22c
	str r0, [r4, #0x54]
_080DEF82:
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x5c]
	ldr r1, _080DEFA4 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DEFA0: .4byte 0x00007006
_080DEFA4: .4byte gSolidFnTable

	thumb_func_start FUN_080defa8
FUN_080defa8: @ 0x080DEFA8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xd]
	cmp r6, #0
	beq _080DEFB8
	cmp r6, #1
	beq _080DF032
	b _080DF158
_080DEFB8:
	ldr r0, _080DF08C @ =gStageRun+232
	adds r7, r5, #0
	adds r7, #0x54
	adds r1, r7, #0
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _080DEFCE
	b _080DF158
_080DEFCE:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldr r1, [r5, #0x64]
	ldr r3, _080DF090 @ =gOverworld
	ldrb r0, [r5, #0x11]
	movs r2, #3
	ands r2, r0
	lsrs r0, r0, #2
	adds r0, #4
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _080DF094 @ =0x0002D028
	adds r3, r3, r0
	adds r2, r2, r3
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DF098 @ =0x08371804
	adds r0, r4, #0
	adds r2, r7, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldrb r1, [r5, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r5, #0x1d]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080DF032:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #4
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	bne _080DF070
	ldr r0, [r5, #0x54]
	ldr r1, _080DF09C @ =0xFFFFFC00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	bne _080DF070
	ldrb r0, [r5, #0x11]
	cmp r0, #4
	beq _080DF0A0
	ldr r0, [r5, #0x54]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	beq _080DF0A0
_080DF070:
	ldr r2, _080DF090 @ =gOverworld
	ldrb r0, [r5, #0x11]
	movs r1, #3
	ands r1, r0
	lsrs r0, r0, #2
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, _080DF094 @ =0x0002D028
	adds r0, r2, r3
	adds r1, r1, r0
	movs r0, #1
	b _080DF0B8
	.align 2, 0
_080DF08C: .4byte gStageRun+232
_080DF090: .4byte gOverworld
_080DF094: .4byte 0x0002D028
_080DF098: .4byte 0x08371804
_080DF09C: .4byte 0xFFFFFC00
_080DF0A0:
	ldr r2, _080DF0FC @ =gOverworld
	ldrb r0, [r5, #0x11]
	movs r1, #3
	ands r1, r0
	lsrs r0, r0, #2
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, _080DF100 @ =0x0002D028
	adds r0, r2, r3
	adds r1, r1, r0
	movs r0, #0
_080DF0B8:
	strb r0, [r1]
	ldrb r0, [r5, #0x11]
	movs r1, #3
	ands r1, r0
	lsrs r0, r0, #2
	adds r0, #4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, _080DF100 @ =0x0002D028
	adds r0, r2, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DF104
	ldrb r0, [r5, #0x1e]
	lsls r2, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r2, r0
	ldr r0, [r5, #0x64]
	adds r1, r0, #1
	cmp r2, r1
	beq _080DF126
	adds r0, #2
	cmp r2, r0
	beq _080DF126
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	b _080DF126
	.align 2, 0
_080DF0FC: .4byte gOverworld
_080DF100: .4byte 0x0002D028
_080DF104:
	ldrb r0, [r5, #0x1e]
	lsls r2, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r2, r0
	ldr r1, [r5, #0x64]
	cmp r2, r1
	beq _080DF126
	adds r1, #3
	cmp r2, r1
	beq _080DF126
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
_080DF126:
	ldr r0, _080DF160 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _080DF158
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r5, #0xa]
	str r2, [r4]
	adds r0, r5, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	strb r2, [r5, #0xd]
_080DF158:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DF160: .4byte gStageRun+232
