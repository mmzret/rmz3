	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start PantheonAquaMod_Init
PantheonAquaMod_Init: @ 0x08051330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _08051384 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _08051388 @ =0x0836394C
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldr r0, _0805138C @ =gSystemSavedataManager
	ldrb r1, [r0, #0x12]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08051394
	ldr r1, _08051390 @ =0x0836364C
	adds r0, r7, #0
	movs r2, #0x50
	bl ResetBossBody
	b _0805139E
	.align 2, 0
_08051384: .4byte gBossFnTable
_08051388: .4byte 0x0836394C
_0805138C: .4byte gSystemSavedataManager
_08051390: .4byte 0x0836364C
_08051394:
	ldr r1, _0805158C @ =0x0836364C
	adds r0, r7, #0
	movs r2, #0x40
	bl ResetBossBody
_0805139E:
	ldr r1, _08051590 @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x4c
	str r0, [sp]
	movs r1, #0
	str r1, [r0]
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r7, #0x54]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	movs r2, #0xf0
	lsls r2, r2, #7
	adds r1, r1, r2
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x58]
	asrs r0, r0, #8
	str r0, [r7, #0x58]
	movs r1, #0xa0
	bl __divsi3
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldrb r0, [r7, #0x10]
	cmp r0, #0
	bne _08051424
	movs r4, #0xc3
	lsls r4, r4, #2
	ldr r1, _08051594 @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _08051598 @ =wStaticGraphicTilenums
	adds r1, #0x4e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805159C @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080515A0 @ =wStaticMotionPalIDs
	adds r0, #0x4e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
_08051424:
	ldr r4, _080515A4 @ =0x00000604
	ldr r5, _08051594 @ =gStaticMotionGraphics
	adds r0, r4, r5
	ldr r1, _08051598 @ =wStaticGraphicTilenums
	mov sb, r1
	adds r1, #0x9a
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805159C @ =gStaticMotionGraphics+12
	mov r8, r0
	add r4, r8
	ldr r1, _080515A0 @ =wStaticMotionPalIDs
	mov sl, r1
	mov r0, sl
	adds r0, #0x9a
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r6, #0x80
	lsls r6, r6, #2
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc3
	lsls r4, r4, #3
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0x9c
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x9c
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080515A8 @ =0x0000062C
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0x9e
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0x9e
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	movs r4, #0xc8
	lsls r4, r4, #3
	adds r0, r4, r5
	mov r1, sb
	adds r1, #0xa0
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xa0
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	ldr r4, _080515AC @ =0x00000654
	adds r5, r4, r5
	mov r0, sb
	adds r0, #0xa2
	ldrh r1, [r0]
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	adds r0, r5, #0
	bl LoadGraphic
	add r4, r8
	mov r0, sl
	adds r0, #0xa2
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r6
	adds r0, r4, #0
	bl LoadPalette
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	adds r0, #2
	movs r2, #0
	strh r2, [r0]
	adds r3, r7, #0
	adds r3, #0xbc
	ldr r0, [r7, #0x58]
	ldr r1, _080515B0 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0xb9
	strb r2, [r0]
	movs r0, #0
	ldr r1, [sp]
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xc4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc5
	strb r2, [r0]
	ldrb r0, [r7, #0x10]
	cmp r0, #1
	bne _08051576
	ldr r0, [r3]
	str r0, [r7, #0x58]
_08051576:
	adds r0, r7, #0
	bl PantheonAquaMod_Update
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805158C: .4byte 0x0836364C
_08051590: .4byte onCollision
_08051594: .4byte gStaticMotionGraphics
_08051598: .4byte wStaticGraphicTilenums
_0805159C: .4byte gStaticMotionGraphics+12
_080515A0: .4byte wStaticMotionPalIDs
_080515A4: .4byte 0x00000604
_080515A8: .4byte 0x0000062C
_080515AC: .4byte 0x00000654
_080515B0: .4byte 0xFFFFEC00

	thumb_func_start PantheonAquaMod_Update
PantheonAquaMod_Update: @ 0x080515B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	beq _080515CE
	bl isKilled
	cmp r0, #0
	beq _080515CE
	movs r0, #0
	str r0, [r5]
_080515CE:
	adds r0, r4, #0
	bl tryKillPantheonAquaMod
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080515FA
	ldr r1, _08051600 @ =0x08363600
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08051604 @ =0x08363624
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080515FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051600: .4byte 0x08363600
_08051604: .4byte 0x08363624

	thumb_func_start PantheonAquaMod_Die
PantheonAquaMod_Die: @ 0x08051608
	push {lr}
	ldr r2, _0805161C @ =0x08363648
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0805161C: .4byte 0x08363648

	thumb_func_start nop_08051620
nop_08051620: @ 0x08051620
	bx lr
	.align 2, 0

	thumb_func_start paquamNeutral
paquamNeutral: @ 0x08051624
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08051638
	cmp r5, #1
	beq _0805167C
	b _0805179C
_08051638:
	ldr r1, _080516D0 @ =0x00004D01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x46
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _08051658
	ldrb r0, [r6]
	bl ClearBlink
	strb r5, [r6]
_08051658:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x54
	bl LoadBlink
	movs r0, #0x54
	strb r0, [r6]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805167C:
	adds r1, r4, #0
	adds r1, #0xb9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08051688
	b _0805178C
_08051688:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080516D8
	subs r0, #0x34
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080516D8
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	beq _080516B6
	cmp r1, #0x20
	beq _080516B6
	cmp r1, #0x30
	bne _080516D8
_080516B6:
	ldr r2, _080516D4 @ =0x08363950
	movs r0, #0x15
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	adds r6, r4, #0
	adds r6, #0xb8
	movs r7, #0x74
	adds r7, r7, r4
	mov r8, r7
	b _0805176E
	.align 2, 0
_080516D0: .4byte 0x00004D01
_080516D4: .4byte 0x08363950
_080516D8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	adds r6, r4, #0
	adds r6, #0xb8
	movs r1, #0x74
	adds r1, r1, r4
	mov r8, r1
	cmp r0, #0
	bne _0805176E
	ldr r0, _08051718 @ =pZero2
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0805176E
	adds r0, r2, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0805176E
	ldr r2, _0805171C @ =RNG_0202f388
	ldr r5, _08051720 @ =0x08363958
	adds r3, r4, #0
	adds r3, #0xc4
	b _0805172E
	.align 2, 0
_08051718: .4byte pZero2
_0805171C: .4byte RNG_0202f388
_08051720: .4byte 0x08363958
_08051724:
	adds r0, r4, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	cmp r0, #1
	bls _0805174E
_0805172E:
	ldr r1, [r2]
	ldr r0, _08051784 @ =0x000343FD
	muls r0, r1, r0
	ldr r7, _08051788 @ =0x00269EC3
	adds r0, r0, r7
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r1, r0, #0x11
	movs r0, #3
	ands r1, r0
	adds r0, r1, r5
	ldrb r0, [r0]
	ldrb r7, [r3]
	cmp r0, r7
	beq _08051724
_0805174E:
	adds r2, r1, r5
	ldrb r0, [r2]
	ldrb r1, [r3]
	cmp r0, r1
	bne _08051762
	adds r1, r4, #0
	adds r1, #0xc5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08051762:
	ldrb r0, [r2]
	movs r1, #0
	strb r0, [r3]
	ldrb r0, [r2]
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0805176E:
	adds r0, r4, #0
	bl paquam_080512f8
	ldrb r0, [r6]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051794
	.align 2, 0
_08051784: .4byte 0x000343FD
_08051788: .4byte 0x00269EC3
_0805178C:
	subs r0, #1
	strb r0, [r1]
	adds r4, #0x74
	mov r8, r4
_08051794:
	ldr r1, _080517A8 @ =0x08363664
	mov r0, r8
	bl SetDDP
_0805179C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080517A8: .4byte 0x08363664

	thumb_func_start paquam_080517ac
paquam_080517ac: @ 0x080517AC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _080517B8
	b _080519B6
_080517B8:
	lsls r0, r0, #2
	ldr r1, _080517C4 @ =_080517C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080517C4: .4byte _080517C8
_080517C8: @ jump table
	.4byte _080517F8 @ case 0
	.4byte _0805183E @ case 1
	.4byte _08051874 @ case 2
	.4byte _080518E6 @ case 3
	.4byte _0805188C @ case 4
	.4byte _0805189E @ case 5
	.4byte _080518C0 @ case 6
	.4byte _080518E6 @ case 7
	.4byte _08051908 @ case 8
	.4byte _0805191A @ case 9
	.4byte _08051960 @ case 10
	.4byte _08051976 @ case 11
_080517F8:
	adds r1, r5, #0
	adds r1, #0x25
	movs r4, #0
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08080908
	adds r0, r5, #0
	bl FUN_08080964
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x12]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805183E:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051856
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08051856:
	ldr r1, [r5, #0x68]
	str r1, [r5, #0x58]
	ldr r2, _08051870 @ =gSineTable
	ldrb r0, [r5, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	str r1, [r5, #0x58]
	b _08051954
	.align 2, 0
_08051870: .4byte gSineTable
_08051874:
	adds r2, r5, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08051888 @ =0x00002702
	b _080518DA
	.align 2, 0
_08051888: .4byte 0x00002702
_0805188C:
	movs r0, #0x20
	strb r0, [r5, #0x13]
	ldr r1, _080518BC @ =0x00002704
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805189E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080518B8
	b _080519B6
_080518B8:
	b _080518F6
	.align 2, 0
_080518BC: .4byte 0x00002704
_080518C0:
	movs r0, #0x63
	bl PlaySound
	ldr r0, [r5, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	ldr r2, _08051900 @ =0xFFFFE300
	adds r1, r1, r2
	bl FUN_08080c64
	ldr r1, _08051904 @ =0x00002706
_080518DA:
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080518E6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080519B6
_080518F6:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080519B6
	.align 2, 0
_08051900: .4byte 0xFFFFE300
_08051904: .4byte 0x00002706
_08051908:
	movs r0, #0x20
	strb r0, [r5, #0x13]
	ldr r1, _0805195C @ =0x00002707
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805191A:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805193A
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805193A
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0805193A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080519B6
	movs r1, #0x9c
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
_08051954:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080519B6
	.align 2, 0
_0805195C: .4byte 0x00002707
_08051960:
	movs r0, #0xc8
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	ldr r1, _080519BC @ =0x00002708
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08051976:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08051990
	movs r0, #2
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
_08051990:
	ldr r2, [r5, #0x64]
	ldr r0, _080519C0 @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _080519C4 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _080519C8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080519CC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080519B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080519BC: .4byte 0x00002708
_080519C0: .4byte 0xFFFFFE00
_080519C4: .4byte RNG_0202f388
_080519C8: .4byte 0x000343FD
_080519CC: .4byte 0x00269EC3

	thumb_func_start paquam_080519d0
paquam_080519d0: @ 0x080519D0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _080519DE
	b _08051B82
_080519DE:
	lsls r0, r0, #2
	ldr r1, _080519E8 @ =_080519EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080519E8: .4byte _080519EC
_080519EC: @ jump table
	.4byte _08051A0C @ case 0
	.4byte _08051A54 @ case 1
	.4byte _08051A74 @ case 2
	.4byte _08051AAC @ case 3
	.4byte _08051AE4 @ case 4
	.4byte _08051B14 @ case 5
	.4byte _08051B54 @ case 6
	.4byte _08051B64 @ case 7
_08051A0C:
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08051A70 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	adds r3, r0, #0
	str r3, [r4, #0x2c]
	cmp r3, #0
	beq _08051A46
	adds r0, #0x7c
	movs r1, #0
	strb r1, [r0]
	subs r0, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r1, [r3, #0x78]
_08051A46:
	movs r1, #0
	movs r0, #0x32
	strb r0, [r4, #0x12]
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051A54:
	ldr r1, [r4, #0x5c]
	movs r0, #0xb0
	lsls r0, r0, #7
	subs r0, r0, r1
	cmp r0, #0
	bge _08051A62
	adds r0, #0x1f
_08051A62:
	asrs r0, r0, #5
	adds r5, r1, r0
	str r5, [r4, #0x5c]
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _08051ACA
	b _08051AB4
	.align 2, 0
_08051A70: .4byte 0xFFFFF000
_08051A74:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	str r0, [r4, #0x58]
	movs r1, #0x9a
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051AAC:
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _08051ACA
	ldr r5, [r4, #0x5c]
_08051AB4:
	adds r2, r5, #0
	cmp r5, #0
	bge _08051ABC
	adds r2, r5, #7
_08051ABC:
	asrs r2, r2, #3
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	muls r0, r2, r0
	adds r0, r5, r0
	str r0, [r3, #0x78]
_08051ACA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051ADC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051ADC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051B82
_08051AE4:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x52
	bl LoadBlink
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x52
	strb r0, [r1]
	bl UpdateBlinkMotionState
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051B14:
	ldr r0, [r4, #0x5c]
	subs r0, #0xa0
	str r0, [r4, #0x5c]
	cmp r0, #0
	bge _08051B22
	movs r0, #0
	str r0, [r4, #0x5c]
_08051B22:
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _08051B40
	ldr r5, [r4, #0x5c]
	adds r2, r5, #0
	cmp r5, #0
	bge _08051B32
	adds r2, r5, #7
_08051B32:
	asrs r2, r2, #3
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	muls r0, r2, r0
	adds r0, r5, r0
	str r0, [r3, #0x78]
_08051B40:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051B82
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08051B82
_08051B54:
	ldr r3, [r4, #0x2c]
	adds r1, r3, #0
	adds r1, #0x77
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051B64:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bne _08051B7C
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_08051B7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08051B82:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start paquam_08051b8c
paquam_08051b8c: @ 0x08051B8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #1
	beq _08051C0A
	cmp r6, #1
	bgt _08051BA0
	cmp r6, #0
	beq _08051BAC
	b _08051CD6
_08051BA0:
	cmp r6, #2
	beq _08051C6C
	cmp r6, #3
	bne _08051BAA
	b _08051CB2
_08051BAA:
	b _08051CD6
_08051BAC:
	movs r0, #0xe4
	bl PlaySound
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #4
	ands r0, r1
	str r0, [r2]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	adds r0, r4, #0
	bl createLaserSign
	adds r5, r4, #0
	adds r5, #0xb8
	ldrb r0, [r5]
	cmp r0, #0
	beq _08051BDE
	bl ClearBlink
	strb r6, [r5]
_08051BDE:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x58
	bl LoadBlink
	movs r0, #0x58
	strb r0, [r5]
	ldr r1, _08051C68 @ =0x00004D01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051C0A:
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, [r2]
	movs r0, #4
	ands r1, r0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r1, #0
	beq _08051C4A
	ldrb r0, [r5]
	cmp r0, #0
	beq _08051C2C
	bl ClearBlink
	movs r0, #0
	strb r0, [r5]
_08051C2C:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x59
	bl LoadBlink
	movs r0, #0x59
	strb r0, [r5]
_08051C4A:
	ldr r0, [r6]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08051C5A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051C5A:
	ldrb r0, [r5]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051CD6
	.align 2, 0
_08051C68: .4byte 0x00004D01
_08051C6C:
	movs r0, #0xe6
	bl PlaySound
	adds r0, r4, #0
	bl createLaserSign2
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r5, r4, #0
	adds r5, #0xb8
	ldrb r0, [r5]
	cmp r0, #0
	beq _08051C8E
	bl ClearBlink
	movs r0, #0
	strb r0, [r5]
_08051C8E:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x54
	bl LoadBlink
	movs r0, #0x54
	strb r0, [r5]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051CB2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051CC6
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_08051CC6:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08051CD6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051cdc
FUN_08051cdc: @ 0x08051CDC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08051D52
	cmp r5, #1
	bgt _08051CF0
	cmp r5, #0
	beq _08051CFA
	b _08051DB0
_08051CF0:
	cmp r5, #2
	beq _08051D80
	cmp r5, #3
	beq _08051D84
	b _08051DB0
_08051CFA:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08051D7C @ =0x00004D01
	adds r0, r4, #0
	bl SetMotion
	adds r6, r4, #0
	adds r6, #0xb8
	ldrb r0, [r6]
	cmp r0, #0
	beq _08051D2E
	bl ClearBlink
	strb r5, [r6]
_08051D2E:
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x54
	bl LoadBlink
	movs r0, #0x54
	strb r0, [r6]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051D52:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08051D64
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051D64:
	adds r0, r4, #0
	bl paquam_080512f8
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08051DB0
	.align 2, 0
_08051D7C: .4byte 0x00004D01
_08051D80:
	movs r0, #3
	strb r0, [r4, #0xe]
_08051D84:
	ldr r0, _08051DB8 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r2, #1
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	bne _08051D9A
	strb r1, [r4, #0xd]
	strb r2, [r4, #0xe]
	movs r0, #0x46
	strb r0, [r4, #0x12]
_08051D9A:
	adds r0, r4, #0
	bl paquam_080512f8
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08051DB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08051DB8: .4byte gStageRun

	thumb_func_start paquamSweepLaser
paquamSweepLaser: @ 0x08051DBC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _08051DC8
	b _08051F3E
_08051DC8:
	lsls r0, r0, #2
	ldr r1, _08051DD8 @ =0x08051DDC
	adds r0, r0, r1
	ldr r0, [r0]
	adds r5, r4, #0
	adds r5, #0xb8
	mov pc, r0
	.align 2, 0
_08051DD8: .4byte 0x08051DDC
_08051DDC:
	.byte 0xF4, 0x1D, 0x05, 0x08
	.byte 0x5C, 0x1E, 0x05, 0x08, 0xA4, 0x1E, 0x05, 0x08, 0xEA, 0x1E, 0x05, 0x08, 0x0C, 0x1F, 0x05, 0x08
	.byte 0x16, 0x1F, 0x05, 0x08, 0xE5, 0x20, 0xB2, 0xF7, 0xD3, 0xFB, 0x22, 0x1C, 0xB4, 0x32, 0x10, 0x68
	.byte 0x05, 0x21, 0x49, 0x42, 0x08, 0x40, 0x04, 0x39, 0x08, 0x40, 0x08, 0x39, 0x08, 0x40, 0x10, 0x60
	.byte 0x61, 0x6D, 0xA2, 0x6D, 0x20, 0x1C, 0x6E, 0xF0, 0x47, 0xFA, 0x20, 0x1C, 0xB8, 0x30, 0x01, 0x78
	.byte 0x05, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x28, 0x78, 0xB2, 0xF7, 0x44, 0xF9, 0x00, 0x20, 0x28, 0x70
	.byte 0x20, 0x1C, 0xC5, 0xF7, 0xDF, 0xFD, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00
	.byte 0x10, 0x1C, 0x01, 0x43, 0x58, 0x20, 0xB2, 0xF7, 0x71, 0xF8, 0x58, 0x20, 0x28, 0x70, 0x14, 0x49
	.byte 0x20, 0x1C, 0xC5, 0xF7, 0x89, 0xFB, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0xB4, 0x30
	.byte 0x01, 0x68, 0x04, 0x22, 0x11, 0x40, 0x06, 0x1C, 0x00, 0x29, 0x15, 0xD0, 0x28, 0x78, 0x00, 0x28
	.byte 0x03, 0xD0, 0xB2, 0xF7, 0x1F, 0xF9, 0x00, 0x20, 0x28, 0x70, 0x20, 0x1C, 0xC5, 0xF7, 0xBA, 0xFD
	.byte 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x59, 0x20
	.byte 0xB2, 0xF7, 0x4C, 0xF8, 0x59, 0x20, 0x28, 0x70, 0x30, 0x68, 0x08, 0x21, 0x29, 0xE0, 0x00, 0x00
	.byte 0x01, 0x4D, 0x00, 0x00, 0xE6, 0x20, 0xB2, 0xF7, 0x7B, 0xFB, 0x20, 0x1C, 0xB8, 0x30, 0x01, 0x78
	.byte 0x05, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x28, 0x78, 0xB2, 0xF7, 0xFC, 0xF8, 0x00, 0x20, 0x28, 0x70
	.byte 0x20, 0x1C, 0xC5, 0xF7, 0x97, 0xFD, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00
	.byte 0x10, 0x1C, 0x01, 0x43, 0x54, 0x20, 0xB2, 0xF7, 0x29, 0xF8, 0x54, 0x20, 0x28, 0x70, 0x20, 0x1C
	.byte 0x2E, 0xF0, 0xA2, 0xFD, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0xB4, 0x30, 0x00, 0x68
	.byte 0x10, 0x21, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x28, 0x78
	.byte 0xB2, 0xF7, 0xB2, 0xF8, 0x20, 0x1C, 0xC5, 0xF7, 0xA9, 0xFB, 0x18, 0xE0, 0x18, 0x20, 0xA0, 0x74
	.byte 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x7C, 0x01, 0x38, 0xA0, 0x74, 0x00, 0x06, 0x00, 0x0E
	.byte 0x00, 0x28, 0x04, 0xD1, 0x60, 0x73, 0x01, 0x20, 0xA0, 0x73, 0x46, 0x20, 0xA0, 0x74, 0x20, 0x1C
	.byte 0xB8, 0x30, 0x00, 0x78, 0xB2, 0xF7, 0x98, 0xF8, 0x20, 0x1C, 0xC5, 0xF7, 0x8F, 0xFB
_08051F3E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start paquam_08051f44
paquam_08051f44: @ 0x08051F44
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08051FC8
	cmp r5, #1
	bgt _08051F58
	cmp r5, #0
	beq _08051F62
	b _080520A6
_08051F58:
	cmp r5, #2
	beq _08051FF4
	cmp r5, #3
	beq _08052052
	b _080520A6
_08051F62:
	movs r0, #0xe4
	bl PlaySound
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	subs r1, #0x61
	ands r0, r1
	str r0, [r2]
	ldr r0, _08051F9C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08051FA8
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08051FA0 @ =0x083637E4
	bl SetDDP
	strb r5, [r4, #0x13]
	ldr r1, _08051FA4 @ =0x00004D02
	adds r0, r4, #0
	bl SetMotion
	b _08051FBE
	.align 2, 0
_08051F9C: .4byte pZero2
_08051FA0: .4byte 0x083637E4
_08051FA4: .4byte 0x00004D02
_08051FA8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08051FEC @ =0x0836385C
	bl SetDDP
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _08051FF0 @ =0x00004D07
	adds r0, r4, #0
	bl SetMotion
_08051FBE:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051FC8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051FDA
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08051FDA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080520A6
	.align 2, 0
_08051FEC: .4byte 0x0836385C
_08051FF0: .4byte 0x00004D07
_08051FF4:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _08052024
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0805201C @ =0x08363724
	bl SetDDP
	ldr r1, _08052020 @ =0x00004D03
	adds r0, r4, #0
	bl SetMotion
	b _08052044
	.align 2, 0
_0805201C: .4byte 0x08363724
_08052020: .4byte 0x00004D03
_08052024:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080520AC @ =0x08363784
	bl SetDDP
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080520B0 @ =0x00004D08
	adds r0, r4, #0
	bl SetMotion
_08052044:
	ldrb r1, [r4, #0x13]
	adds r0, r4, #0
	bl createStretchedGrabArm
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08052052:
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r1, [r6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805206E
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	adds r0, r4, #0
	bl FUN_08080858
_0805206E:
	ldr r5, [r6]
	movs r0, #0xc0
	lsls r0, r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08052096
	ldr r1, _080520B4 @ =0x00004D01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r6]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	strb r5, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x46
	strb r0, [r4, #0x12]
_08052096:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080520A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080520AC: .4byte 0x08363784
_080520B0: .4byte 0x00004D08
_080520B4: .4byte 0x00004D01

	thumb_func_start paquqmRubble
paquqmRubble: @ 0x080520B8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0805211C
	cmp r5, #1
	bgt _080520CC
	cmp r5, #0
	beq _080520D4
	b _08052236
_080520CC:
	cmp r5, #2
	bne _080520D2
	b _08052204
_080520D2:
	b _08052236
_080520D4:
	movs r0, #0xe3
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080521DC @ =0x083636DC
	bl SetDDP
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r0, [r2]
	ldr r1, _080521E0 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _080521E4 @ =0xFFFFFBFF
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	adds r1, #0x80
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080521E8 @ =0x00004D0E
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl createStretchedArms
	strb r5, [r4, #0x12]
	strb r5, [r4, #0x13]
	str r5, [r4, #0x68]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0805211C:
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080521C8
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bne _0805213C
	ldr r0, _080521EC @ =0x0000010D
	bl PlaySound
	movs r0, #1
	str r0, [r4, #0x68]
_0805213C:
	ldr r0, [r4, #0x5c]
	movs r1, #0x38
	bl __modsi3
	cmp r0, #0
	bne _08052172
	ldr r2, _080521F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080521F4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080521F8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	ldr r2, _080521FC @ =0xFFFFB800
	adds r1, r1, r2
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	bl createPAquaModRubble
_08052172:
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #3
	bl AppendQuake
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080521B2
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _080521B2
	ldr r0, _080521EC @ =0x0000010D
	bl stopSound
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080521B2:
	ldr r1, [r4, #0x64]
	str r1, [r4, #0x54]
	ldr r2, _08052200 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #0x54]
_080521C8:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08052236
	.align 2, 0
_080521DC: .4byte 0x083636DC
_080521E0: .4byte 0xFFFFFDFF
_080521E4: .4byte 0xFFFFFBFF
_080521E8: .4byte 0x00004D0E
_080521EC: .4byte 0x0000010D
_080521F0: .4byte RNG_0202f388
_080521F4: .4byte 0x000343FD
_080521F8: .4byte 0x00269EC3
_080521FC: .4byte 0xFFFFB800
_08052200: .4byte gSineTable
_08052204:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08052226
	ldr r1, _0805223C @ =0x00004D01
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x46
	strb r0, [r4, #0x12]
_08052226:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	bl UpdateBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08052236:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805223C: .4byte 0x00004D01

	thumb_func_start paqua_mod_08052240
paqua_mod_08052240: @ 0x08052240
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0805224C
	b _080523AA
_0805224C:
	lsls r0, r0, #2
	ldr r1, _0805225C @ =0x08052260
	adds r0, r0, r1
	ldr r0, [r0]
	adds r5, r4, #0
	adds r5, #0xb8
	mov pc, r0
	.align 2, 0
_0805225C: .4byte 0x08052260
_08052260:
	.byte 0x78, 0x22, 0x05, 0x08, 0x9E, 0x22, 0x05, 0x08, 0xC8, 0x22, 0x05, 0x08, 0x12, 0x23, 0x05, 0x08
	.byte 0x32, 0x23, 0x05, 0x08, 0x8E, 0x23, 0x05, 0x08, 0x20, 0x1C, 0x74, 0x30, 0x10, 0x49, 0xB4, 0xF7
	.byte 0xC9, 0xFF, 0x22, 0x1C, 0xB4, 0x32, 0x10, 0x68, 0x80, 0x21, 0x09, 0x01, 0x08, 0x43, 0x10, 0x60
	.byte 0x0C, 0x49, 0x20, 0x1C, 0xC5, 0xF7, 0x68, 0xF9, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C
	.byte 0xB8, 0x30, 0x00, 0x78, 0xB1, 0xF7, 0xE0, 0xFE, 0x20, 0x1C, 0xC5, 0xF7, 0xD7, 0xF9, 0x20, 0x1C
	.byte 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x78, 0xD1, 0xA0, 0x7B, 0x01, 0x30, 0x74, 0xE0, 0x00, 0x00
	.byte 0xD4, 0x38, 0x36, 0x08, 0x0F, 0x4D, 0x00, 0x00, 0xE5, 0x20, 0xB2, 0xF7, 0x69, 0xF9, 0x28, 0x20
	.byte 0xA0, 0x74, 0x20, 0x1C, 0x6E, 0xF0, 0x34, 0xF8, 0x20, 0x1C, 0xB8, 0x30, 0x01, 0x78, 0x05, 0x1C
	.byte 0x00, 0x29, 0x04, 0xD0, 0x28, 0x78, 0xB1, 0xF7, 0xE5, 0xFE, 0x00, 0x20, 0x28, 0x70, 0x20, 0x1C
	.byte 0xC5, 0xF7, 0x80, 0xFB, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22, 0x92, 0x00, 0x10, 0x1C
	.byte 0x01, 0x43, 0x58, 0x20, 0xB1, 0xF7, 0x12, 0xFE, 0x58, 0x20, 0x28, 0x70, 0xA0, 0x7B, 0x01, 0x30
	.byte 0xA0, 0x73, 0xA0, 0x7C, 0x01, 0x38, 0xA0, 0x74, 0x00, 0x06, 0x00, 0x28, 0x02, 0xD1, 0xA0, 0x7B
	.byte 0x01, 0x30, 0xA0, 0x73, 0x28, 0x78, 0xB1, 0xF7, 0x9F, 0xFE, 0x20, 0x1C, 0xC5, 0xF7, 0x96, 0xF9
	.byte 0x3B, 0xE0, 0x2C, 0x20, 0xB2, 0xF7, 0x34, 0xF9, 0x60, 0x6D, 0xA1, 0x6D, 0x53, 0xF0, 0x3A, 0xFC
	.byte 0x22, 0x1C, 0xB4, 0x32, 0x10, 0x68, 0x1A, 0x49, 0x08, 0x40, 0x10, 0x60, 0x20, 0x1C, 0xB8, 0x30
	.byte 0x01, 0x78, 0x05, 0x1C, 0x00, 0x29, 0x04, 0xD0, 0x28, 0x78, 0xB1, 0xF7, 0xAB, 0xFE, 0x00, 0x20
	.byte 0x28, 0x70, 0x20, 0x1C, 0xC5, 0xF7, 0x46, 0xFB, 0x01, 0x1C, 0x09, 0x06, 0xC9, 0x0C, 0x80, 0x22
	.byte 0x92, 0x00, 0x10, 0x1C, 0x01, 0x43, 0x59, 0x20, 0xB1, 0xF7, 0xD8, 0xFD, 0x59, 0x20, 0x28, 0x70
	.byte 0x0C, 0x49, 0x20, 0x1C, 0xC5, 0xF7, 0xF0, 0xF8, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x28, 0x78
	.byte 0xB1, 0xF7, 0x6A, 0xFE, 0x20, 0x1C, 0xC5, 0xF7, 0x61, 0xF9, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78
	.byte 0x03, 0x28, 0x02, 0xD1, 0x00, 0x20, 0x60, 0x73, 0xA0, 0x73
_080523AA:
	pop {r4, r5}
	pop {r0}
	bx r0
_080523B0:
	.byte 0xFF, 0xF7, 0xFF, 0xFF, 0x11, 0x4D, 0x00, 0x00

	thumb_func_start FUN_080523b8
FUN_080523b8: @ 0x080523B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r4, [r7, #0xe]
	cmp r4, #1
	beq _0805245E
	cmp r4, #1
	ble _080523D0
	b _0805259C
_080523D0:
	cmp r4, #0
	beq _080523D6
	b _0805259C
_080523D6:
	ldr r0, _08052550 @ =0x0000010D
	bl stopSound
	ldr r1, _08052554 @ =0x00004D12
	adds r0, r7, #0
	bl SetMotion
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r0, [r5]
	cmp r0, #0
	beq _080523F4
	bl ClearBlink
	strb r4, [r5]
_080523F4:
	adds r0, r7, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x54
	bl LoadBlink
	movs r0, #0x54
	strb r0, [r5]
	bl UpdateBlinkMotionState
	ldr r3, _08052558 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _08052438
	ldrb r1, [r3, #0x12]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08052438
	ldr r0, _0805255C @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_08052438:
	movs r0, #0xff
	strb r0, [r7, #0x12]
	movs r1, #0
	movs r0, #2
	strb r0, [r7, #0x13]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805245E:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _08052480
	cmp r0, #1
	bne _0805247A
	adds r4, r7, #0
	adds r4, #0xb8
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805247A
	bl ClearBlink
	movs r0, #0
	strb r0, [r4]
_0805247A:
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
_08052480:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x12]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080524DC
	ldr r1, [r7, #0x54]
	ldr r3, _08052560 @ =0xFFFFE000
	mov r8, r3
	add r1, r8
	ldr r0, _08052564 @ =RNG_0202f388
	mov sb, r0
	ldr r0, [r0]
	ldr r6, _08052568 @ =0x000343FD
	muls r0, r6, r0
	ldr r3, _0805256C @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	ldr r5, _08052570 @ =0x00003FFF
	ands r0, r5
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, [r7, #0x58]
	add r2, r8
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, sb
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
_080524DC:
	ldrb r0, [r7, #0x12]
	adds r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08052522
	ldr r5, _08052564 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08052568 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _0805256C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsls r1, r1, #1
	lsrs r1, r1, #0x12
	ldr r0, _08052560 @ =0xFFFFE000
	adds r1, r1, r0
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	muls r2, r4, r2
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	str r1, [r5]
	lsls r2, r2, #2
	lsrs r2, r2, #0x13
	movs r1, #0x80
	lsls r1, r1, #5
	adds r2, r2, r1
	ldr r1, [r7, #0x58]
	subs r1, r1, r2
	bl FUN_080c02f4
_08052522:
	ldrb r0, [r7, #0x12]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052536
	movs r0, #0x31
	bl PlaySound
_08052536:
	movs r0, #0x12
	ldrsb r0, [r7, r0]
	ldrb r2, [r7, #0x12]
	cmp r0, #0
	blt _0805257C
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08052574
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0805257A
	.align 2, 0
_08052550: .4byte 0x0000010D
_08052554: .4byte 0x00004D12
_08052558: .4byte gStageRun
_0805255C: .4byte 0x0000FFFE
_08052560: .4byte 0xFFFFE000
_08052564: .4byte RNG_0202f388
_08052568: .4byte 0x000343FD
_0805256C: .4byte 0x00269EC3
_08052570: .4byte 0x00003FFF
_08052574:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0805257A:
	strb r0, [r7, #0xa]
_0805257C:
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _0805259C
	ldr r2, _080525AC @ =gStageRun
	ldrb r1, [r2, #0x12]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #0xd
	bl TryDropItem
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0805259C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080525AC: .4byte gStageRun
