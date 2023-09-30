	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08050090
FUN_08050090: @ 0x08050090
	mov ip, r0
	mov r1, ip
	adds r1, #0xc8
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r0, ip
	adds r0, #0xc4
	ldr r2, [r0]
	mov r0, ip
	str r2, [r0, #0x58]
	ldr r3, _080500C4 @ =gSineTable
	ldrh r0, [r1]
	lsrs r0, r0, #8
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r2, r2, r0
	mov r0, ip
	str r2, [r0, #0x58]
	bx lr
	.align 2, 0
_080500C4: .4byte gSineTable

	thumb_func_start FUN_080500c8
FUN_080500c8: @ 0x080500C8
	push {r4, lr}
	ldr r1, [r0, #0xc]
	ldr r3, [r1, #0x2c]
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080500EC
	movs r4, #0
	ldr r1, [r2, #0x54]
	ldr r0, [r3, #0x54]
	cmp r1, r0
	bge _080500E6
	movs r4, #1
_080500E6:
	adds r0, r2, #0
	adds r0, #0xcc
	strb r4, [r0]
_080500EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080500f4
FUN_080500f4: @ 0x080500F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x8c
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08050114
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0805018C
_08050114:
	ldr r0, _08050174 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _0805018C
	adds r5, r4, #0
	adds r5, #0xd0
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0805013E
	adds r0, r1, #0
	bl stopSound
	ldr r0, _08050178 @ =0x0000FFFF
	strh r0, [r5]
_0805013E:
	adds r1, r4, #0
	adds r1, #0xce
	ldrb r0, [r1]
	cmp r0, #0
	beq _08050150
	strb r6, [r1]
	movs r0, #0
	bl FUN_08010188
_08050150:
	ldr r1, _0805017C @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _08050180
	movs r0, #1
	strb r0, [r4, #0xd]
	b _08050182
	.align 2, 0
_08050174: .4byte gStageRun
_08050178: .4byte 0x0000FFFF
_0805017C: .4byte gBossFnTable
_08050180:
	strb r1, [r4, #0xd]
_08050182:
	adds r0, r4, #0
	bl Anubis_Die
	movs r0, #1
	b _0805018E
_0805018C:
	movs r0, #0
_0805018E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Anubis_Init
Anubis_Init: @ 0x08050194
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _080502EC @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _080502F0 @ =0x083635B4
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _080502F4 @ =0x0836356C
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
	ldr r1, _080502F8 @ =FUN_080500c8
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x40
	str r5, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	beq _080502D6
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r4]
	adds r4, #4
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xa0
	bl __divsi3
	adds r0, #1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	str r1, [r4]
	adds r0, r7, #0
	adds r0, #0xc0
	str r5, [r0]
	adds r0, #8
	movs r1, #0
	strh r5, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xcd
	movs r0, #0x40
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xce
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r4, _080502FC @ =0x000005B4
	ldr r0, _08050300 @ =gStaticMotionGraphics
	mov r8, r0
	adds r0, r4, r0
	ldr r6, _08050304 @ =wStaticGraphicTilenums
	adds r1, r6, #0
	adds r1, #0x92
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08050308 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r4, sl
	ldr r5, _0805030C @ =wStaticMotionPalIDs
	adds r0, r5, #0
	adds r0, #0x92
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov sb, r2
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xb9
	lsls r4, r4, #3
	add r8, r4
	adds r6, #0x94
	ldrh r1, [r6]
	mov r2, r8
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, r8
	bl LoadGraphic
	add r4, sl
	adds r5, #0x94
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r7, #0
	adds r1, #0xd0
	ldr r0, _08050310 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r1, #1
	strb r1, [r0]
_080502D6:
	adds r0, r7, #0
	bl Anubis_Update
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080502EC: .4byte gBossFnTable
_080502F0: .4byte 0x083635B4
_080502F4: .4byte 0x0836356C
_080502F8: .4byte FUN_080500c8
_080502FC: .4byte 0x000005B4
_08050300: .4byte gStaticMotionGraphics
_08050304: .4byte wStaticGraphicTilenums
_08050308: .4byte gStaticMotionGraphics+12
_0805030C: .4byte wStaticMotionPalIDs
_08050310: .4byte 0x0000FFFF

	thumb_func_start Anubis_Update
Anubis_Update: @ 0x08050314
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0805032E
	bl isKilled
	cmp r0, #0
	beq _08050348
	movs r0, #0
	b _08050346
_0805032E:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08050348
	ldr r2, _08050358 @ =0x083635B8
	movs r0, #0x14
	adds r1, r4, #0
	bl ApplyElementEffect
_08050346:
	str r0, [r5]
_08050348:
	adds r2, r4, #0
	adds r2, #0xca
	ldrb r0, [r2]
	cmp r0, #0
	beq _0805035C
	subs r0, #1
	b _0805036E
	.align 2, 0
_08050358: .4byte 0x083635B8
_0805035C:
	ldr r0, _080503A4 @ =pZero2
	ldr r0, [r0]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08050370
	movs r0, #0x60
_0805036E:
	strb r0, [r2]
_08050370:
	adds r0, r4, #0
	bl FUN_080500f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805039C
	ldr r1, _080503A8 @ =0x0836350C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080503AC @ =0x08363538
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0805039C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080503A4: .4byte pZero2
_080503A8: .4byte 0x0836350C
_080503AC: .4byte 0x08363538

	thumb_func_start Anubis_Die
Anubis_Die: @ 0x080503B0
	push {lr}
	ldr r2, _080503C4 @ =0x08363564
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080503C4: .4byte 0x08363564

	thumb_func_start nop_080503c8
nop_080503c8: @ 0x080503C8
	bx lr
	.align 2, 0

	thumb_func_start anubisMode0
anubisMode0: @ 0x080503CC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _080503D8
	b _080505E6
_080503D8:
	lsls r0, r0, #2
	ldr r1, _080503E4 @ =_080503E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080503E4: .4byte _080503E8
_080503E8: @ jump table
	.4byte _08050418 @ case 0
	.4byte _080504E0 @ case 1
	.4byte _08050516 @ case 2
	.4byte _08050528 @ case 3
	.4byte _0805053C @ case 4
	.4byte _08050592 @ case 5
	.4byte _08050544 @ case 6
	.4byte _08050560 @ case 7
	.4byte _08050584 @ case 8
	.4byte _08050592 @ case 9
	.4byte _080505B0 @ case 10
	.4byte _080505BE @ case 11
_08050418:
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080504C4
	ldr r4, _080504A4 @ =0x000005DC
	ldr r1, _080504A8 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080504AC @ =wStaticGraphicTilenums
	adds r1, #0x96
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080504B0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080504B4 @ =wStaticMotionPalIDs
	adds r0, #0x96
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r0, [r4]
	ldr r1, _080504B8 @ =0xFFFF4000
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, _080504BC @ =0x0000AF0C
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r4]
	ldr r2, _080504C0 @ =0xFFFF8A00
	adds r1, r0, r2
	ldr r0, [r5, #0x58]
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _08050486
	adds r0, r1, #3
_08050486:
	asrs r0, r0, #2
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xd
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_080bf3d8
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080504E0
	.align 2, 0
_080504A4: .4byte 0x000005DC
_080504A8: .4byte gStaticMotionGraphics
_080504AC: .4byte wStaticGraphicTilenums
_080504B0: .4byte gStaticMotionGraphics+12
_080504B4: .4byte wStaticMotionPalIDs
_080504B8: .4byte 0xFFFF4000
_080504BC: .4byte 0x0000AF0C
_080504C0: .4byte 0xFFFF8A00
_080504C4:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r1, _080504DC @ =0xFFFF8A00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r1, r5, #0
	adds r1, #0xc4
	str r0, [r1]
	movs r0, #6
	strb r0, [r5, #0xe]
	b _080505E6
	.align 2, 0
_080504DC: .4byte 0xFFFF8A00
_080504E0:
	ldr r1, [r5, #0x60]
	cmp r1, #0
	bge _08050508
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050578
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _08050572
_08050508:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r1, #0
	subs r0, #8
	str r0, [r5, #0x60]
	b _08050578
_08050516:
	adds r1, r5, #0
	adds r1, #0xc4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	movs r0, #0x64
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050528:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080505E6
	b _080505A2
_0805053C:
	ldr r1, _08050540 @ =0x0000AF0D
	b _08050586
	.align 2, 0
_08050540: .4byte 0x0000AF0D
_08050544:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl FUN_080a4ef8
	ldr r1, _08050580 @ =0x0000AF01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050560:
	adds r0, r5, #0
	bl FUN_08050090
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08050578
_08050572:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050578:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080505E6
	.align 2, 0
_08050580: .4byte 0x0000AF01
_08050584:
	ldr r1, _080505AC @ =0x0000AF02
_08050586:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050592:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080505E6
_080505A2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080505E6
	.align 2, 0
_080505AC: .4byte 0x0000AF02
_080505B0:
	ldr r1, _080505EC @ =0x0000AF01
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080505BE:
	adds r0, r5, #0
	bl FUN_08050090
	ldr r0, _080505F0 @ =gStageRun
	ldrb r1, [r0, #0x12]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _080505E0
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080505F4 @ =0x08363584
	bl SetDDP
	strb r4, [r5, #0xd]
	strb r4, [r5, #0xe]
_080505E0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080505E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080505EC: .4byte 0x0000AF01
_080505F0: .4byte gStageRun
_080505F4: .4byte 0x08363584

	thumb_func_start anubisNeutral
anubisNeutral: @ 0x080505F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0805062E
	cmp r0, #1
	bgt _08050610
	cmp r0, #0
	beq _08050616
	b _080507CC
_08050610:
	cmp r0, #2
	beq _08050638
	b _080507CC
_08050616:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08050668 @ =0x08363584
	bl SetDDP
	ldr r1, _0805066C @ =0x0000AF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805062E:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050638:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xa4
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0xf
	ble _08050676
	adds r0, r4, #0
	adds r0, #0xce
	ldrb r1, [r0]
	cmp r1, #0
	beq _08050670
	movs r0, #0xa
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _08050676
	.align 2, 0
_08050668: .4byte 0x08363584
_0805066C: .4byte 0x0000AF01
_08050670:
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08050676:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0805067E
	b _080507C0
_0805067E:
	ldr r0, _080506B4 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08050694
	b _080507C0
_08050694:
	adds r0, r2, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080506A2
	b _080507C0
_080506A2:
	adds r2, r4, #0
	adds r2, #0xd2
	ldrb r0, [r2]
	cmp r0, #0
	beq _080506B8
	strb r1, [r2]
	movs r0, #2
	b _080507BC
	.align 2, 0
_080506B4: .4byte pZero2
_080506B8:
	adds r0, r4, #0
	adds r0, #0xcb
	ldrb r0, [r0]
	cmp r0, #2
	bls _0805073C
	ldr r7, _080506D0 @ =0x083635C0
	ldr r0, _080506D4 @ =gMission
	mov r8, r0
	ldr r6, _080506D8 @ =RNG_0202f388
	adds r5, r4, #0
	adds r5, #0xcf
	b _080506E4
	.align 2, 0
_080506D0: .4byte 0x083635C0
_080506D4: .4byte gMission
_080506D8: .4byte RNG_0202f388
_080506DC:
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080507AC
_080506E4:
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08050710
	ldr r1, [r6]
	ldr r0, _08050708 @ =0x000343FD
	muls r0, r1, r0
	ldr r2, _0805070C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r1, r0, #0x11
	movs r0, #3
	ands r1, r0
	b _0805072C
	.align 2, 0
_08050708: .4byte 0x000343FD
_0805070C: .4byte 0x00269EC3
_08050710:
	ldr r1, [r6]
	ldr r0, _08050734 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08050738 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0805072C:
	ldrb r0, [r5]
	cmp r0, #0
	bne _080506DC
	b _080507AC
	.align 2, 0
_08050734: .4byte 0x000343FD
_08050738: .4byte 0x00269EC3
_0805073C:
	ldr r2, _0805074C @ =gMission
	mov r8, r2
	ldr r6, _08050750 @ =RNG_0202f388
	adds r5, r4, #0
	adds r5, #0xcf
	ldr r7, _08050754 @ =0x083635C4
	b _08050760
	.align 2, 0
_0805074C: .4byte gMission
_08050750: .4byte RNG_0202f388
_08050754: .4byte 0x083635C4
_08050758:
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080507AC
_08050760:
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	cmp r0, #4
	bls _08050790
	ldr r1, [r6]
	ldr r0, _08050788 @ =0x000343FD
	muls r0, r1, r0
	ldr r2, _0805078C @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _080507A6
	.align 2, 0
_08050788: .4byte 0x000343FD
_0805078C: .4byte 0x00269EC3
_08050790:
	ldr r1, [r6]
	ldr r0, _080507D8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080507DC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r1, r0, #0x11
	movs r0, #3
	ands r1, r0
_080507A6:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08050758
_080507AC:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080507B6
	subs r0, #1
	strb r0, [r5]
_080507B6:
	adds r0, r1, r7
	ldrb r0, [r0]
	movs r1, #0
_080507BC:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080507C0:
	adds r0, r4, #0
	bl FUN_08050090
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080507CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080507D8: .4byte 0x000343FD
_080507DC: .4byte 0x00269EC3

	thumb_func_start anubisMode2
anubisMode2: @ 0x080507E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0805082C
	cmp r0, #1
	bgt _080507F4
	cmp r0, #0
	beq _080507FE
	b _0805089E
_080507F4:
	cmp r0, #2
	beq _0805084C
	cmp r0, #3
	beq _08050876
	b _0805089E
_080507FE:
	movs r0, #0x54
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xd0
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	subs r1, #7
	ands r0, r1
	subs r1, #0xc
	ands r0, r1
	str r0, [r2]
	ldr r1, _08050848 @ =0x0000AF02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805082C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0805089E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0805089E
	.align 2, 0
_08050848: .4byte 0x0000AF02
_0805084C:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0805086E
	ldr r2, _080508A4 @ =0xFFFFFE00
_0805086E:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050876:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _080508A8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bls _0805089E
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805089E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080508A4: .4byte 0xFFFFFE00
_080508A8: .4byte gStageRun+232

	thumb_func_start anubisMode3
anubisMode3: @ 0x080508AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080508B8
	b _08050A12
_080508B8:
	lsls r0, r0, #2
	ldr r1, _080508C4 @ =_080508C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080508C4: .4byte _080508C8
_080508C8: @ jump table
	.4byte _080508DC @ case 0
	.4byte _080508EC @ case 1
	.4byte _08050900 @ case 2
	.4byte _080509A4 @ case 3
	.4byte _080509D8 @ case 4
_080508DC:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080508EC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080508FA
	b _08050A12
_080508FA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08050A10
_08050900:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xd0
	lsls r0, r0, #3
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strb r0, [r4, #0x12]
	lsls r0, r0, #4
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	eors r0, r2
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	eors r1, r2
	ands r1, r2
	adds r5, r4, #0
	adds r5, #0x4a
	lsls r3, r1, #4
	ldrb r2, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	cmp r1, #0
	beq _08050954
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0805095A
_08050954:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0805095A:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08050980
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, _0805097C @ =0xFFFF6800
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r4, #0x64]
	b _08050996
	.align 2, 0
_0805097C: .4byte 0xFFFF6800
_08050980:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0x98
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	str r2, [r4, #0x64]
_08050996:
	ldr r1, _080509D4 @ =0x0000AF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080509A4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080509B6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080509B6:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08050090
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08050A12
	.align 2, 0
_080509D4: .4byte 0x0000AF01
_080509D8:
	adds r0, r4, #0
	bl FUN_08050090
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08050A12
	adds r5, r4, #0
	adds r5, #0xd0
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08050A0C
	adds r0, r1, #0
	bl stopSound
	ldr r0, _08050A18 @ =0x0000FFFF
	strh r0, [r5]
_08050A0C:
	movs r0, #1
	strb r0, [r4, #0xd]
_08050A10:
	strb r0, [r4, #0xe]
_08050A12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050A18: .4byte 0x0000FFFF

	thumb_func_start anubisMode4
anubisMode4: @ 0x08050A1C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08050A64
	cmp r0, #1
	bgt _08050A30
	cmp r0, #0
	beq _08050A3A
	b _08050AD6
_08050A30:
	cmp r0, #2
	beq _08050A80
	cmp r0, #3
	beq _08050A9C
	b _08050AD6
_08050A3A:
	movs r0, #0x54
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xd0
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08050A7C @ =0x0000AF02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050A64:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08050AD6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08050AD4
	.align 2, 0
_08050A7C: .4byte 0x0000AF02
_08050A80:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08050ADC @ =0x0000AF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050A9C:
	adds r0, r4, #0
	bl FUN_08050090
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08050AD6
	adds r5, r4, #0
	adds r5, #0xd0
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08050AD0
	adds r0, r1, #0
	bl stopSound
	ldr r0, _08050AE0 @ =0x0000FFFF
	strh r0, [r5]
_08050AD0:
	movs r0, #1
	strb r0, [r4, #0xd]
_08050AD4:
	strb r0, [r4, #0xe]
_08050AD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050ADC: .4byte 0x0000AF01
_08050AE0: .4byte 0x0000FFFF

	thumb_func_start anubisMode5
anubisMode5: @ 0x08050AE4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08050AF4
	cmp r0, #1
	beq _08050B3E
	b _08050B62
_08050AF4:
	adds r0, r4, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050B10
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #2
	strb r0, [r4, #0xe]
	strb r0, [r4, #0x12]
	b _08050B62
_08050B10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08050B68 @ =0x0836356C
	bl SetDDP
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	movs r1, #0x20
	orrs r0, r1
	subs r1, #0x61
	ands r0, r1
	str r0, [r2]
	ldr r1, _08050B6C @ =0x0000AF08
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050B3E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08050B62
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	ldr r1, _08050B70 @ =0xFFFFFEFF
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08050B62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08050B68: .4byte 0x0836356C
_08050B6C: .4byte 0x0000AF08
_08050B70: .4byte 0xFFFFFEFF

	thumb_func_start anubisMode6
anubisMode6: @ 0x08050B74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08050B84
	cmp r0, #1
	beq _08050BFE
	b _08050C62
_08050B84:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r4, _08050C24 @ =0x000005DC
	ldr r1, _08050C28 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _08050C2C @ =wStaticGraphicTilenums
	adds r1, #0x96
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08050C30 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _08050C34 @ =wStaticMotionPalIDs
	adds r0, #0x96
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r3, _08050C38 @ =0x083635C9
	ldr r2, _08050C3C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08050C40 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08050C44 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x1f
	bgt _08050BEE
	adds r1, #8
_08050BEE:
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r5, #0x12]
	movs r0, #0x1e
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050BFE:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050C62
	movs r0, #0x60
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08050C48
	movs r0, #7
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _08050C4C
	.align 2, 0
_08050C24: .4byte 0x000005DC
_08050C28: .4byte gStaticMotionGraphics
_08050C2C: .4byte wStaticGraphicTilenums
_08050C30: .4byte gStaticMotionGraphics+12
_08050C34: .4byte wStaticMotionPalIDs
_08050C38: .4byte 0x083635C9
_08050C3C: .4byte RNG_0202f388
_08050C40: .4byte 0x000343FD
_08050C44: .4byte 0x00269EC3
_08050C48:
	movs r0, #1
	strb r0, [r5, #0xe]
_08050C4C:
	movs r0, #0x55
	bl PlaySound
	movs r1, #0
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08050C5C
	movs r1, #1
_08050C5C:
	adds r0, r5, #0
	bl CreateAnubisCoffins
_08050C62:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start anubisMode7
anubisMode7: @ 0x08050C68
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08050C90
	cmp r0, #1
	bgt _08050C7C
	cmp r0, #0
	beq _08050C86
	b _08050CF0
_08050C7C:
	cmp r0, #2
	beq _08050CA4
	cmp r0, #3
	beq _08050CCC
	b _08050CF0
_08050C86:
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050C90:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050CF0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08050CF0
_08050CA4:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08050CF8 @ =0x0000AF0E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050CCC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08050CF0
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r2, r4, #0
	adds r2, #0xcd
	movs r1, #0
	strb r0, [r2]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08050CF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08050CF8: .4byte 0x0000AF0E

	thumb_func_start anubisMode8
anubisMode8: @ 0x08050CFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08050D10
	cmp r0, #1
	beq _08050D34
	b _08050E0C
_08050D10:
	movs r0, #0x53
	bl PlaySound
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r1, _08050E18 @ =0x0000AF03
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08050D34:
	ldrb r0, [r5, #0x12]
	movs r1, #0xc0
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq _08050DF4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050DF4
	movs r4, #0xbe
	lsls r4, r4, #3
	ldr r2, _08050E1C @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldr r1, _08050E20 @ =wStaticGraphicTilenums
	adds r1, #0x98
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _08050E24 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _08050E28 @ =wStaticMotionPalIDs
	adds r0, #0x98
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldr r2, _08050E2C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08050E30 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08050E34 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #1
	ands r1, r0
	adds r0, r1, #1
	cmp r0, #0
	beq _08050DEE
	movs r7, #0
	adds r6, r0, #0
_08050DA8:
	ldr r0, _08050E38 @ =pZero2
	ldr r0, [r0]
	ldr r4, [r0, #0x54]
	ldr r2, _08050E3C @ =0xFFFFCE00
	adds r4, r4, r2
	adds r4, r4, r7
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, _08050E40 @ =0xFFFF9000
	adds r1, r0, r2
	cmp r4, r1
	bge _08050DC4
	adds r4, r1, #0
_08050DC4:
	movs r1, #0xe0
	lsls r1, r1, #7
	adds r0, r0, r1
	cmp r4, r0
	ble _08050DD0
	adds r4, r0, #0
_08050DD0:
	ldr r1, [r5, #0x58]
	adds r0, r4, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl createPantheonZombie
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r7, r7, r2
	subs r6, #1
	cmp r6, #0
	bne _08050DA8
_08050DEE:
	movs r0, #0x55
	bl PlaySound
_08050DF4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	mov r0, r8
	ldr r1, [r0]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	bne _08050E0C
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08050E0C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050E18: .4byte 0x0000AF03
_08050E1C: .4byte gStaticMotionGraphics
_08050E20: .4byte wStaticGraphicTilenums
_08050E24: .4byte gStaticMotionGraphics+12
_08050E28: .4byte wStaticMotionPalIDs
_08050E2C: .4byte RNG_0202f388
_08050E30: .4byte 0x000343FD
_08050E34: .4byte 0x00269EC3
_08050E38: .4byte pZero2
_08050E3C: .4byte 0xFFFFCE00
_08050E40: .4byte 0xFFFF9000

	thumb_func_start FUN_08050e44
FUN_08050e44: @ 0x08050E44
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _08050E56
	cmp r1, #1
	beq _08050EC4
	b _08050F2C
_08050E56:
	ldrb r0, [r4, #0xb]
	movs r7, #0x10
	movs r6, #0
	orrs r0, r7
	strb r0, [r4, #0xb]
	ldrb r0, [r5, #0x1c]
	strb r0, [r4, #0x1d]
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
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	adds r1, r4, #0
	adds r1, #0x4c
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r3, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	mov r2, ip
	strb r0, [r2]
	cmp r1, #0
	beq _08050EAE
	ldrb r0, [r4, #0xa]
	orrs r0, r7
	b _08050EB4
_08050EAE:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08050EB4:
	strb r0, [r4, #0xa]
	ldr r1, _08050ED8 @ =0x0000AF07
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050EC4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08050EDC
	movs r0, #0xf6
	b _08050EDE
	.align 2, 0
_08050ED8: .4byte 0x0000AF07
_08050EDC:
	movs r0, #0xfa
_08050EDE:
	muls r0, r1, r0
	cmp r0, #0
	bge _08050EE6
	adds r0, #0xff
_08050EE6:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_0801779c
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bne _08050F2C
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
	ldr r1, _08050F34 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08050F2C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050F34: .4byte gBossFnTable

	thumb_func_start anubis_08050f38
anubis_08050f38: @ 0x08050F38
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08050F84
	cmp r0, #1
	bgt _08050F4C
	cmp r0, #0
	beq _08050F56
	b _08051002
_08050F4C:
	cmp r0, #2
	beq _08050FA4
	cmp r0, #3
	beq _08050FDE
	b _08051002
_08050F56:
	movs r0, #0x53
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0xcf
	movs r0, #2
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r1, _08050FA0 @ =0x0000AF03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050F84:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050F96
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050F96:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051002
	.align 2, 0
_08050FA0: .4byte 0x0000AF03
_08050FA4:
	adds r0, r4, #0
	adds r0, #0xce
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _08050FB4
	movs r0, #0
	b _08050FD0
_08050FB4:
	ldr r2, _08051008 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0805100C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08051010 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	adds r0, #1
_08050FD0:
	strb r0, [r5]
	ldrb r0, [r5]
	bl FUN_08010188
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08050FDE:
	bl FUN_080101a8
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08050FFC
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r0, [r2]
	ldr r1, _08051014 @ =0xFFFFFEFF
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
_08050FFC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08051002:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051008: .4byte RNG_0202f388
_0805100C: .4byte 0x000343FD
_08051010: .4byte 0x00269EC3
_08051014: .4byte 0xFFFFFEFF

	thumb_func_start anubis_08051018
anubis_08051018: @ 0x08051018
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _080510E0
	lsls r0, r0, #2
	ldr r1, _0805102C @ =_08051030
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805102C: .4byte _08051030
_08051030: @ jump table
	.4byte _08051044 @ case 0
	.4byte _08051090 @ case 1
	.4byte _080510B8 @ case 2
	.4byte _080510C8 @ case 3
	.4byte _080510E0 @ case 4
_08051044:
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
	ldr r3, _080510AC @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _0805107E
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0805107E
	ldr r0, _080510B0 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_0805107E:
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _080510B4 @ =0x0000AF04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051090:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080510E0
	b _080510DA
	.align 2, 0
_080510AC: .4byte gStageRun
_080510B0: .4byte 0x0000FFFE
_080510B4: .4byte 0x0000AF04
_080510B8:
	ldr r1, _080510E8 @ =0x083635DC
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080510C8:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080510E0
	ldr r2, _080510EC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_080510DA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080510E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080510E8: .4byte 0x083635DC
_080510EC: .4byte gStageRun

	thumb_func_start anubis_080510f0
anubis_080510f0: @ 0x080510F0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _080510FE
	b _08051286
_080510FE:
	lsls r0, r0, #2
	ldr r1, _08051108 @ =_0805110C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08051108: .4byte _0805110C
_0805110C: @ jump table
	.4byte _08051120 @ case 0
	.4byte _080511F4 @ case 1
	.4byte _0805125E @ case 2
	.4byte _0805126E @ case 3
	.4byte _08051286 @ case 4
_08051120:
	movs r0, #0x2f
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0xcc
	ldrb r6, [r0]
	ldr r0, _08051214 @ =gBossHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08051188
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08051218 @ =gBossFnTable
	movs r0, #0xb
	strb r0, [r3, #9]
	ldr r0, [r1, #0x2c]
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
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r3, #0x5c]
	str r4, [r3, #0x28]
	movs r1, #1
	strb r1, [r3, #0x10]
	ldrb r0, [r4, #0xa]
	lsrs r0, r0, #4
	ands r0, r1
	eors r0, r6
	strb r0, [r3, #0x13]
_08051188:
	ldr r1, _0805121C @ =0x0000AF06
	adds r0, r4, #0
	bl SetMotion
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
	ldr r3, _08051220 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080511CA
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080511CA
	ldr r0, _08051224 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080511CA:
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r1, r6, #9
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r0, #0x32
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080511F4:
	ldr r0, [r4, #0x54]
	ldr r2, [r4, #0x5c]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xcc
	ldrb r3, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08051228
	cmp r3, #1
	bne _0805122C
	b _08051230
	.align 2, 0
_08051214: .4byte gBossHeaderPtr
_08051218: .4byte gBossFnTable
_0805121C: .4byte 0x0000AF06
_08051220: .4byte gStageRun
_08051224: .4byte 0x0000FFFE
_08051228:
	cmp r3, #0
	beq _08051230
_0805122C:
	movs r0, #0xfa
	b _08051232
_08051230:
	movs r0, #0xf6
_08051232:
	muls r0, r2, r0
	cmp r0, #0
	bge _0805123A
	adds r0, #0xff
_0805123A:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08051256
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051256:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051286
_0805125E:
	ldr r1, _08051290 @ =0x083635E4
	adds r0, r4, #0
	bl CreateBossExplosion
	str r0, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805126E:
	ldr r0, [r4, #0x2c]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08051286
	ldr r2, _08051294 @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051286:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08051290: .4byte 0x083635E4
_08051294: .4byte gStageRun
