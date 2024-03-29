	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080153e8
FUN_080153e8: @ 0x080153E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	ldr r0, [r0, #0x5c]
	lsls r5, r0, #0x10
	mov r0, r8
	bl DrawGeneralStageLayer
	lsrs r1, r5, #0x14
	lsls r1, r1, #2
	ldr r0, _080154F8 @ =gVideoRegBuffer+12
	adds r4, r1, r0
	ldrh r2, [r4]
	str r2, [sp]
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl Malloc
	adds r7, r0, #0
	cmp r7, #0
	beq _080154E8
	ldr r2, _080154FC @ =gIntrManager
	movs r3, #0xba
	lsls r3, r3, #1
	adds r0, r2, r3
	str r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08015500 @ =0x0400001C
	str r0, [r1]
	adds r3, #8
	adds r1, r2, r3
	ldr r0, _08015504 @ =0xA6600001
	str r0, [r1]
	lsrs r5, r5, #0x14
	str r5, [sp, #4]
	adds r1, r4, #0
	adds r2, r7, #0
	movs r5, #0xf
_0801544E:
	ldr r0, [r1]
	stm r2!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _0801544E
	movs r5, #0x10
	ldr r2, _08015508 @ =gSineTable
	mov r6, sb
	adds r6, #0x80
	movs r0, #0x40
	adds r0, r0, r7
	mov sl, r0
_08015466:
	mov r3, r8
	ldrh r1, [r3, #0x10]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r0, r1, #2
	adds r0, r6, r0
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r4, r4, r0
	asrs r4, r4, #8
	adds r4, #4
	add r4, sb
	lsls r4, r4, #0x10
	lsls r0, r5, #1
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r1, #0x13
	str r2, [sp, #8]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp]
	adds r0, r1, r0
	ldr r1, _0801550C @ =0x0000FFFF
	ands r0, r1
	orrs r4, r0
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	stm r3!, {r4}
	adds r6, #8
	adds r5, #1
	ldr r2, [sp, #8]
	cmp r5, #0x5f
	ble _08015466
	cmp r5, #0x9f
	bgt _080154E8
	ldr r1, [sp, #4]
	lsls r0, r1, #2
	ldr r1, _080154F8 @ =gVideoRegBuffer+12
	adds r1, r0, r1
	lsls r0, r5, #2
	adds r2, r0, r7
_080154DE:
	ldr r0, [r1]
	stm r2!, {r0}
	adds r5, #1
	cmp r5, #0x9f
	ble _080154DE
_080154E8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080154F8: .4byte gVideoRegBuffer+12
_080154FC: .4byte gIntrManager
_08015500: .4byte 0x0400001C
_08015504: .4byte 0xA6600001
_08015508: .4byte gSineTable
_0801550C: .4byte 0x0000FFFF

	thumb_func_start FUN_08015510
FUN_08015510: @ 0x08015510
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801553C
	ldr r0, [r3, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #1
	ldr r1, _08015550 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _08015554 @ =0x0000FFFC
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r0]
	ldr r0, _08015558 @ =0xFFFFFEC0
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801553C:
	ldr r0, _0801555C @ =gOverworld
	ldr r1, _08015560 @ =0x0002D027
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x63
	bls _0801554C
	movs r0, #0
	str r0, [r3, #0x50]
_0801554C:
	pop {r0}
	bx r0
	.align 2, 0
_08015550: .4byte gVideoRegBuffer+4
_08015554: .4byte 0x0000FFFC
_08015558: .4byte 0xFFFFFEC0
_0801555C: .4byte gOverworld
_08015560: .4byte 0x0002D027

	thumb_func_start weilLabo_08015564
weilLabo_08015564: @ 0x08015564
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08015594
	cmp r0, #1
	bgt _0801557E
	cmp r0, #0
	beq _08015584
	b _0801560A
_0801557E:
	cmp r0, #2
	beq _080155FC
	b _0801560A
_08015584:
	ldr r0, _0801561C @ =gOverworld
	ldr r1, _08015620 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801560A
	movs r0, #1
	strb r0, [r6, #0xe]
_08015594:
	lsrs r4, r7, #4
	lsls r2, r4, #1
	ldr r3, _08015624 @ =gVideoRegBuffer+4
	adds r2, r2, r3
	ldr r0, [r6, #0x64]
	movs r1, #0x47
	orrs r0, r1
	strh r0, [r2]
	lsls r4, r4, #2
	adds r3, #8
	adds r4, r4, r3
	movs r0, #0
	str r0, [r4]
	ldr r0, _08015628 @ =0x085223D0
	ldr r0, [r0]
	ldr r1, _0801562C @ =0x085223D8
	adds r0, r0, r1
	ldr r1, _08015630 @ =gOverworld+180260
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldr r4, _08015634 @ =0x087044F0
	ldr r0, [r4]
	ldr r1, _08015638 @ =0x08704540
	adds r0, r0, r1
	movs r5, #0x80
	lsls r5, r5, #7
	adds r1, r5, #0
	bl LoadGraphic
	ldr r0, [r4]
	ldr r1, _0801563C @ =0x0870454C
	adds r0, r0, r1
	movs r1, #0
	bl LoadPalette
	ldr r0, [r4]
	ldr r1, _08015640 @ =0x08704554
	adds r0, r0, r1
	adds r1, r5, #0
	bl LoadGraphic
	ldr r0, [r4]
	ldr r1, _08015644 @ =0x08704560
	adds r0, r0, r1
	movs r1, #0
	bl LoadPalette
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080155FC:
	lsrs r0, r7, #4
	lsls r0, r0, #2
	ldr r1, _08015648 @ =0x0200214E
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #4
	strh r1, [r0]
_0801560A:
	ldrb r0, [r6, #0xf]
	cmp r0, #4
	bls _08015612
	b _0801570A
_08015612:
	lsls r0, r0, #2
	ldr r1, _0801564C @ =_08015650
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801561C: .4byte gOverworld
_08015620: .4byte 0x0002D024
_08015624: .4byte gVideoRegBuffer+4
_08015628: .4byte 0x085223D0
_0801562C: .4byte 0x085223D8
_08015630: .4byte gOverworld+180260
_08015634: .4byte 0x087044F0
_08015638: .4byte 0x08704540
_0801563C: .4byte 0x0870454C
_08015640: .4byte 0x08704554
_08015644: .4byte 0x08704560
_08015648: .4byte 0x0200214E
_0801564C: .4byte _08015650
_08015650: @ jump table
	.4byte _08015664 @ case 0
	.4byte _0801567E @ case 1
	.4byte _0801569C @ case 2
	.4byte _080156B2 @ case 3
	.4byte _080156D6 @ case 4
_08015664:
	ldr r0, _08015690 @ =gOverworld
	ldr r1, _08015694 @ =0x0002D027
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801570A
	ldr r0, _08015698 @ =0x0000010D
	movs r1, #0
	bl LoadBlink
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
_0801567E:
	ldr r0, _08015698 @ =0x0000010D
	bl UpdateBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0801570A
	b _08015704
	.align 2, 0
_08015690: .4byte gOverworld
_08015694: .4byte 0x0002D027
_08015698: .4byte 0x0000010D
_0801569C:
	ldr r0, _080156EC @ =0x0000010D
	bl ClearBlink
	movs r0, #0x87
	lsls r0, r0, #1
	movs r1, #0
	bl LoadBlink
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
_080156B2:
	movs r0, #0x87
	lsls r0, r0, #1
	bl UpdateBlinkMotionState
	ldr r0, _080156F0 @ =gOverworld
	ldr r1, _080156F4 @ =0x0002D027
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801570A
	movs r0, #0x1f
	movs r1, #8
	movs r2, #0x60
	bl LoadScreenIntoMetatileMap
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
_080156D6:
	ldr r0, _080156F0 @ =gOverworld
	ldr r1, _080156F8 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080156FC
	movs r0, #0x87
	lsls r0, r0, #1
	bl UpdateBlinkMotionState
	b _0801570A
	.align 2, 0
_080156EC: .4byte 0x0000010D
_080156F0: .4byte gOverworld
_080156F4: .4byte 0x0002D027
_080156F8: .4byte 0x0002D024
_080156FC:
	movs r0, #0x87
	lsls r0, r0, #1
	bl ClearBlink
_08015704:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
_0801570A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start weilLabo_08015710
weilLabo_08015710: @ 0x08015710
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r1, _0801572C @ =gOverworld
	ldr r4, _08015730 @ =0x0002D024
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015734
	adds r0, r2, #0
	adds r1, r3, #0
	bl DrawGeneralStageLayer
	b _08015788
	.align 2, 0
_0801572C: .4byte gOverworld
_08015730: .4byte 0x0002D024
_08015734:
	ldr r2, _08015790 @ =0x0002C002
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015788
	ldr r0, _08015794 @ =0x085223D0
	ldr r0, [r0]
	ldr r4, _08015798 @ =0x085223D8
	adds r0, r0, r4
	adds r2, #0x22
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	ldr r4, _0801579C @ =0x087044F0
	ldr r0, [r4]
	ldr r1, _080157A0 @ =0x08704540
	adds r0, r0, r1
	movs r5, #0x80
	lsls r5, r5, #7
	adds r1, r5, #0
	bl LoadGraphic
	ldr r0, [r4]
	ldr r2, _080157A4 @ =0x0870454C
	adds r0, r0, r2
	movs r1, #0
	bl LoadPalette
	ldr r0, [r4]
	ldr r1, _080157A8 @ =0x08704554
	adds r0, r0, r1
	adds r1, r5, #0
	bl LoadGraphic
	ldr r0, [r4]
	ldr r2, _080157AC @ =0x08704560
	adds r0, r0, r2
	movs r1, #0
	bl LoadPalette
_08015788:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015790: .4byte 0x0002C002
_08015794: .4byte 0x085223D0
_08015798: .4byte 0x085223D8
_0801579C: .4byte 0x087044F0
_080157A0: .4byte 0x08704540
_080157A4: .4byte 0x0870454C
_080157A8: .4byte 0x08704554
_080157AC: .4byte 0x08704560

	thumb_func_start FUN_080157b0
FUN_080157b0: @ 0x080157B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov r8, r1
	ldrb r5, [r6, #0xe]
	cmp r5, #1
	beq _0801581C
	cmp r5, #1
	bgt _080157D2
	cmp r5, #0
	beq _080157D8
	b _0801587A
_080157D2:
	cmp r5, #2
	beq _0801582E
	b _0801587A
_080157D8:
	lsrs r3, r0, #0x14
	lsls r2, r3, #1
	ldr r4, _08015888 @ =gVideoRegBuffer+4
	adds r2, r2, r4
	ldr r1, [r6, #0x64]
	ldr r7, _0801588C @ =0x00004046
	adds r0, r7, #0
	orrs r1, r0
	strh r1, [r2]
	lsls r3, r3, #2
	adds r4, #8
	adds r3, r3, r4
	str r5, [r3]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	movs r0, #0
	bl RequestType2Transfer
	ldr r0, _08015890 @ =gOverworld
	ldr r1, _08015894 @ =0x0002D025
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x68
	strb r1, [r0]
	adds r0, #1
	strb r5, [r0]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0801581C:
	ldr r0, _08015890 @ =gOverworld
	ldr r5, _08015898 @ =0x0002D024
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801587A
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0801582E:
	mov r7, r8
	lsrs r4, r7, #4
	lsls r2, r4, #1
	ldr r3, _08015888 @ =gVideoRegBuffer+4
	adds r2, r2, r3
	ldr r1, [r6, #0x64]
	ldr r5, _0801588C @ =0x00004046
	adds r0, r5, #0
	orrs r1, r0
	strh r1, [r2]
	lsls r4, r4, #2
	adds r3, #8
	adds r4, r4, r3
	movs r5, #0
	str r5, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r5, [sp, #4]
	ldr r2, _0801589C @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080158A0 @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x4a
	movs r3, #0
	bl LoadBgMap
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0801587A:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015888: .4byte gVideoRegBuffer+4
_0801588C: .4byte 0x00004046
_08015890: .4byte gOverworld
_08015894: .4byte 0x0002D025
_08015898: .4byte 0x0002D024
_0801589C: .4byte 0x01000400
_080158A0: .4byte gBgMapOffsets

	thumb_func_start weilLabo_080158a4
weilLabo_080158a4: @ 0x080158A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r2, r0, #0x10
	lsrs r7, r2, #0x10
	ldr r5, _08015910 @ =gOverworld
	ldr r1, _08015914 @ =0x0002D024
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080158C2
	b _08015A3C
_080158C2:
	ldr r3, _08015918 @ =0x0002C002
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r4, #0x68
	adds r4, r4, r6
	mov r8, r4
	cmp r0, #0
	bne _080158E0
	ldr r0, _0801591C @ =0x0002D025
	adds r1, r5, r0
	ldrb r0, [r4]
	lsrs r4, r2, #0x14
	ldrb r1, [r1]
	cmp r0, r1
	beq _08015976
_080158E0:
	ldr r1, _0801591C @ =0x0002D025
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801592C
	ldr r0, _08015920 @ =0x085223C4
	ldr r0, [r0]
	ldr r3, _08015924 @ =0x085223CC
	adds r0, r0, r3
	lsrs r1, r2, #0x14
	lsls r1, r1, #1
	ldr r2, _08015928 @ =gVideoRegBuffer+4
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x98
	lsls r2, r2, #3
	bl RequestBgMapTransfer
	b _0801594E
	.align 2, 0
_08015910: .4byte gOverworld
_08015914: .4byte 0x0002D024
_08015918: .4byte 0x0002C002
_0801591C: .4byte 0x0002D025
_08015920: .4byte 0x085223C4
_08015924: .4byte 0x085223CC
_08015928: .4byte gVideoRegBuffer+4
_0801592C:
	ldr r0, _08015A04 @ =0x085223C0
	ldr r0, [r0]
	ldr r4, _08015A08 @ =0x085223C8
	adds r0, r0, r4
	lsrs r1, r2, #0x14
	lsls r1, r1, #1
	ldr r2, _08015A0C @ =gVideoRegBuffer+4
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x98
	lsls r2, r2, #3
	bl RequestBgMapTransfer
_0801594E:
	lsrs r4, r7, #4
	lsls r0, r4, #1
	ldr r1, _08015A0C @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #5
	movs r0, #0
	bl RequestType2Transfer
	ldr r0, _08015A10 @ =gOverworld
	ldr r1, _08015A14 @ =0x0002D025
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r2, r8
	strb r0, [r2]
_08015976:
	ldr r1, _08015A10 @ =gOverworld
	ldr r3, _08015A18 @ =0x0002D034
	adds r0, r1, r3
	ldr r2, [r0]
	adds r5, r1, #0
	cmp r2, #0
	beq _080159C2
	ldr r0, _08015A1C @ =0x0002D038
	adds r1, r5, r0
	ldr r0, [r2, #0x54]
	str r0, [r1]
	adds r3, #8
	adds r1, r5, r3
	ldr r0, [r2, #0x58]
	str r0, [r1]
	ldr r0, _08015A20 @ =0x0202F360
	ldrb r1, [r2, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080159C2
	ldr r1, _08015A24 @ =gPaletteManager
	ldr r0, _08015A28 @ =0x00000404
	adds r2, r1, r0
	movs r0, #0x90
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r2, _08015A2C @ =0x00000406
	adds r1, r1, r2
	movs r0, #0x20
	strh r0, [r1]
_080159C2:
	lsls r3, r4, #2
	ldr r2, _08015A30 @ =gVideoRegBuffer+12
	adds r4, r3, r2
	mov r8, r4
	ldr r1, [r6, #0x34]
	ldr r4, _08015A1C @ =0x0002D038
	adds r0, r5, r4
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x30
	ldr r0, [r6, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [r6, #0x38]
	ldr r2, _08015A34 @ =0x0002D03C
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r4, _08015A38 @ =0xFFFB0000
	adds r0, r0, r4
	asrs r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	subs r1, r1, r0
	ldr r0, [r6, #0x30]
	asrs r0, r0, #8
	adds r0, #0x90
	b _08015B06
	.align 2, 0
_08015A04: .4byte 0x085223C0
_08015A08: .4byte 0x085223C8
_08015A0C: .4byte gVideoRegBuffer+4
_08015A10: .4byte gOverworld
_08015A14: .4byte 0x0002D025
_08015A18: .4byte 0x0002D034
_08015A1C: .4byte 0x0002D038
_08015A20: .4byte 0x0202F360
_08015A24: .4byte gPaletteManager
_08015A28: .4byte 0x00000404
_08015A2C: .4byte 0x00000406
_08015A30: .4byte gVideoRegBuffer+12
_08015A34: .4byte 0x0002D03C
_08015A38: .4byte 0xFFFB0000
_08015A3C:
	ldr r3, _08015B74 @ =0x0002C002
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015A7A
	movs r4, #0
	lsrs r0, r2, #0x14
	lsls r0, r0, #1
	ldr r1, _08015B78 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r4, [sp, #4]
	ldr r2, _08015B7C @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08015B80 @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x4a
	movs r3, #0
	bl LoadBgMap
_08015A7A:
	ldr r4, _08015B84 @ =0x0002D040
	adds r0, r5, r4
	ldr r3, [r0]
	cmp r3, #0
	beq _08015AC4
	ldr r0, _08015B88 @ =0x0002D04C
	adds r1, r5, r0
	ldr r2, _08015B8C @ =0x0002D044
	adds r0, r5, r2
	ldr r2, [r0]
	ldr r0, [r2]
	str r0, [r1]
	adds r4, #0x10
	adds r1, r5, r4
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, _08015B90 @ =0x0202F360
	ldrb r1, [r3, #0x1d]
	lsrs r2, r1, #5
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08015AC4
	ldr r0, _08015B94 @ =gPaletteManager
	ldr r2, _08015B98 @ =0x00000404
	adds r1, r0, r2
	movs r2, #0x40
	strh r2, [r1]
	ldr r3, _08015B9C @ =0x00000406
	adds r0, r0, r3
	strh r2, [r0]
_08015AC4:
	lsrs r3, r7, #4
	lsls r3, r3, #2
	ldr r2, _08015BA0 @ =gVideoRegBuffer+12
	adds r4, r3, r2
	mov r8, r4
	ldr r1, [r6, #0x34]
	ldr r4, _08015B88 @ =0x0002D04C
	adds r0, r5, r4
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0x50
	ldr r0, [r6, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	adds r2, #2
	adds r3, r3, r2
	ldr r1, [r6, #0x38]
	ldr r2, _08015BA4 @ =0x0002D050
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r4, _08015BA8 @ =0xFFFB0000
	adds r0, r0, r4
	asrs r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	subs r1, r1, r0
	ldr r0, [r6, #0x30]
	asrs r0, r0, #8
	adds r0, #0x80
_08015B06:
	adds r1, r1, r0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	strh r1, [r3]
	ldr r3, _08015BAC @ =0x0002D025
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015BFC
	lsls r0, r2, #0x10
	asrs r3, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	mov ip, r0
	cmp r3, r1
	ble _08015BFC
	ldr r2, _08015BB0 @ =gVideoRegBuffer
	lsls r0, r7, #8
	ldrh r1, [r2]
	orrs r0, r1
	movs r7, #0
	strh r0, [r2]
	movs r0, #0x20
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08015BD4
	adds r0, r6, #0
	adds r0, #0x69
	ldrb r1, [r0]
	adds r4, r0, #0
	ldr r3, _08015BB4 @ =gWindowRegBuffer
	cmp r1, #0
	bne _08015BC6
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r2, #0xff
	strb r2, [r3, #0xd]
	ldrb r1, [r3, #0xe]
	movs r0, #0xe
	orrs r0, r1
	strb r0, [r3, #0xe]
	movs r0, #0xff
	strh r0, [r3, #6]
	ldr r1, _08015BB8 @ =0x0002D024
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015BBC
	movs r0, #0xfb
	b _08015BBE
	.align 2, 0
_08015B74: .4byte 0x0002C002
_08015B78: .4byte gVideoRegBuffer+4
_08015B7C: .4byte 0x01000400
_08015B80: .4byte gBgMapOffsets
_08015B84: .4byte 0x0002D040
_08015B88: .4byte 0x0002D04C
_08015B8C: .4byte 0x0002D044
_08015B90: .4byte 0x0202F360
_08015B94: .4byte gPaletteManager
_08015B98: .4byte 0x00000404
_08015B9C: .4byte 0x00000406
_08015BA0: .4byte gVideoRegBuffer+12
_08015BA4: .4byte 0x0002D050
_08015BA8: .4byte 0xFFFB0000
_08015BAC: .4byte 0x0002D025
_08015BB0: .4byte gVideoRegBuffer
_08015BB4: .4byte gWindowRegBuffer
_08015BB8: .4byte 0x0002D024
_08015BBC:
	movs r0, #0xf3
_08015BBE:
	ands r2, r0
	strb r2, [r3, #0xd]
	movs r0, #1
	strb r0, [r4]
_08015BC6:
	mov r2, ip
	asrs r0, r2, #0x10
	rsbs r0, r0, #0
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #0xa]
	b _08015C26
_08015BD4:
	adds r3, r6, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _08015C26
	ldr r1, _08015BF4 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _08015BF8 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	strb r7, [r3]
	b _08015C26
	.align 2, 0
_08015BF4: .4byte gWindowRegBuffer
_08015BF8: .4byte 0x0000BFFF
_08015BFC:
	ldr r2, _08015C34 @ =gVideoRegBuffer
	lsls r1, r7, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	adds r3, r6, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _08015C26
	ldr r1, _08015C38 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _08015C3C @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r0, #0
	strb r0, [r3]
_08015C26:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015C34: .4byte gVideoRegBuffer
_08015C38: .4byte gWindowRegBuffer
_08015C3C: .4byte 0x0000BFFF

	thumb_func_start FUN_08015c40
FUN_08015c40: @ 0x08015C40
	ldr r1, _08015C54 @ =gWindowRegBuffer
	ldrh r2, [r1]
	ldr r0, _08015C58 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	bx lr
	.align 2, 0
_08015C54: .4byte gWindowRegBuffer
_08015C58: .4byte 0x0000BFFF

	thumb_func_start FUN_08015c5c
FUN_08015c5c: @ 0x08015C5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	lsls r4, r0, #0x10
	lsrs r7, r4, #0x10
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _08015C86
	cmp r0, #1
	bgt _08015CD0
	cmp r0, #0
	bne _08015CD0
	ldr r0, _08015CD8 @ =gOverworld
	ldr r1, _08015CDC @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015CD0
	movs r0, #1
	strb r0, [r6, #0xe]
_08015C86:
	lsrs r4, r4, #0x14
	lsls r2, r4, #1
	ldr r3, _08015CE0 @ =gVideoRegBuffer+4
	adds r2, r2, r3
	ldr r1, [r6, #0x64]
	ldr r5, _08015CE4 @ =0x00004046
	adds r0, r5, #0
	orrs r1, r0
	strh r1, [r2]
	lsls r4, r4, #2
	adds r3, #8
	adds r4, r4, r3
	movs r5, #0
	str r5, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r5, [sp, #4]
	ldr r2, _08015CE8 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08015CEC @ =gBgMapOffsets
	str r5, [sp]
	movs r2, #0x4b
	movs r3, #0
	bl LoadBgMap
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08015CD0:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015CD8: .4byte gOverworld
_08015CDC: .4byte 0x0002D024
_08015CE0: .4byte gVideoRegBuffer+4
_08015CE4: .4byte 0x00004046
_08015CE8: .4byte 0x01000400
_08015CEC: .4byte gBgMapOffsets

	thumb_func_start FUN_08015cf0
FUN_08015cf0: @ 0x08015CF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	lsls r6, r0, #0x10
	lsrs r0, r6, #0x10
	mov r8, r0
	ldr r7, _08015D18 @ =gOverworld
	ldr r2, _08015D1C @ =0x0002D024
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015D20
	adds r0, r5, #0
	bl DrawGeneralStageLayer
	b _08015E24
	.align 2, 0
_08015D18: .4byte gOverworld
_08015D1C: .4byte 0x0002D024
_08015D20:
	ldr r3, _08015DF0 @ =0x0002C002
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08015D60
	movs r4, #0
	lsrs r0, r6, #0x14
	lsls r0, r0, #1
	ldr r1, _08015DF4 @ =gVideoRegBuffer+4
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #5
	ands r1, r0
	lsls r1, r1, #3
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	str r4, [sp, #4]
	ldr r2, _08015DF8 @ =0x01000400
	add r0, sp, #4
	bl CpuFastSet
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08015DFC @ =gBgMapOffsets
	str r4, [sp]
	movs r2, #0x4b
	movs r3, #0
	bl LoadBgMap
_08015D60:
	adds r3, r7, #0
	ldr r2, _08015E00 @ =0x0002D040
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08015D82
	ldr r0, _08015E04 @ =0x0002D054
	adds r1, r3, r0
	adds r2, #8
	adds r0, r3, r2
	ldr r2, [r0]
	ldr r0, [r2]
	str r0, [r1]
	ldr r0, _08015E08 @ =0x0002D058
	adds r1, r3, r0
	ldr r0, [r2, #4]
	str r0, [r1]
_08015D82:
	lsrs r2, r6, #0x14
	lsls r2, r2, #2
	ldr r4, _08015E0C @ =gVideoRegBuffer+12
	adds r3, r2, r4
	ldr r1, [r5, #0x34]
	ldr r6, _08015E04 @ =0x0002D054
	adds r0, r7, r6
	ldr r0, [r0]
	asrs r0, r0, #8
	subs r1, r1, r0
	adds r1, #0xe0
	ldr r0, [r5, #0x2c]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r3]
	adds r0, r4, #2
	adds r2, r2, r0
	ldr r1, [r5, #0x38]
	ldr r3, _08015E08 @ =0x0002D058
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r6, _08015E10 @ =0xFFFB0000
	adds r0, r0, r6
	asrs r0, r0, #8
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r0, r3
	subs r1, r1, r0
	ldr r0, [r5, #0x30]
	asrs r0, r0, #8
	adds r0, #0x70
	adds r1, r1, r0
	lsls r0, r1, #0x10
	lsrs r3, r0, #0x10
	strh r1, [r2]
	ldr r6, _08015E14 @ =0x0002D025
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015E18
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08015E18
	adds r0, r4, #0
	subs r0, #0xc
	mov r2, r8
	lsls r1, r2, #8
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08015E24
	.align 2, 0
_08015DF0: .4byte 0x0002C002
_08015DF4: .4byte gVideoRegBuffer+4
_08015DF8: .4byte 0x01000400
_08015DFC: .4byte gBgMapOffsets
_08015E00: .4byte 0x0002D040
_08015E04: .4byte 0x0002D054
_08015E08: .4byte 0x0002D058
_08015E0C: .4byte gVideoRegBuffer+12
_08015E10: .4byte 0xFFFB0000
_08015E14: .4byte 0x0002D025
_08015E18:
	ldr r2, _08015E30 @ =gVideoRegBuffer
	mov r3, r8
	lsls r1, r3, #8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_08015E24:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015E30: .4byte gVideoRegBuffer

	thumb_func_start weillabo_08015e34
weillabo_08015e34: @ 0x08015E34
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	ldr r5, _08015EE0 @ =gOverworld
	cmp r0, #0
	bne _08015E72
	ldr r0, [r6, #0x5c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08015EE4 @ =gVideoRegBuffer+4
	movs r3, #0
	adds r1, r6, #0
	adds r1, #0xc
_08015E4E:
	str r3, [r1, #0x68]
	subs r1, #4
	cmp r1, r6
	bge _08015E4E
	lsrs r2, r0, #4
	lsls r2, r2, #1
	adds r2, r2, r4
	ldrh r1, [r2]
	ldr r0, _08015EE8 @ =0x0000FFFC
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strh r0, [r6, #0x10]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08015E72:
	ldr r1, _08015EEC @ =0x0002D026
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08015F04
	ldrh r0, [r6, #0x10]
	adds r0, #1
	strh r0, [r6, #0x10]
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x68
_08015E88:
	ldr r0, [r4]
	cmp r0, #0
	bne _08015E98
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl FUN_080d8f7c
	str r0, [r4]
_08015E98:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _08015E88
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	bne _08015EB4
	adds r0, r4, #0
	bl PlaySound
_08015EB4:
	ldrh r1, [r6, #0x10]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08015F64
	ldr r2, _08015EF0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08015EF4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08015EF8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r3
	cmp r0, #0
	beq _08015F64
	ldr r1, _08015EFC @ =gBlendRegBuffer
	ldr r0, _08015F00 @ =0x00000C0A
	b _08015F68
	.align 2, 0
_08015EE0: .4byte gOverworld
_08015EE4: .4byte gVideoRegBuffer+4
_08015EE8: .4byte 0x0000FFFC
_08015EEC: .4byte 0x0002D026
_08015EF0: .4byte RNG_0202f388
_08015EF4: .4byte 0x000343FD
_08015EF8: .4byte 0x00269EC3
_08015EFC: .4byte gBlendRegBuffer
_08015F00: .4byte 0x00000C0A
_08015F04:
	movs r4, #0
	ldr r7, _08015F70 @ =gSolidFnTable
	adds r3, r6, #0
	adds r3, #0x68
	movs r5, #3
_08015F0E:
	ldr r2, [r3]
	cmp r2, #0
	beq _08015F48
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r7
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	str r4, [r3]
_08015F48:
	adds r3, #4
	subs r5, #1
	cmp r5, #0
	bge _08015F0E
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08015F64
	adds r0, r4, #0
	bl stopSound
_08015F64:
	ldr r1, _08015F74 @ =gBlendRegBuffer
	ldr r0, _08015F78 @ =0x00000C04
_08015F68:
	strh r0, [r1, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015F70: .4byte gSolidFnTable
_08015F74: .4byte gBlendRegBuffer
_08015F78: .4byte 0x00000C04

	thumb_func_start FUN_08015f7c
FUN_08015f7c: @ 0x08015F7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08015FB0 @ =gOverworld
	ldr r1, _08015FB4 @ =0x0002D026
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08015FC4
	ldr r4, _08015FB8 @ =gStageTilesetOffsets+(18*4)
	ldr r0, [r4]
	ldr r1, _08015FBC @ =0x08705268
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldr r0, [r4]
	ldr r1, _08015FC0 @ =0x08705274
	adds r0, r0, r1
	movs r1, #0
	bl LoadPalette
	b _08015FFE
	.align 2, 0
_08015FB0: .4byte gOverworld
_08015FB4: .4byte 0x0002D026
_08015FB8: .4byte gStageTilesetOffsets+(18*4)
_08015FBC: .4byte 0x08705268
_08015FC0: .4byte 0x08705274
_08015FC4:
	ldr r6, _08016010 @ =gStageTilesetOffsets+(18*4)
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	movs r5, #3
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08016014 @ =0x0870527C
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrh r0, [r7, #0x10]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r6]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08015FFE:
	adds r0, r7, #0
	mov r1, r8
	bl DrawGeneralStageLayer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016010: .4byte gStageTilesetOffsets+(18*4)
_08016014: .4byte 0x0870527C

	thumb_func_start FUN_08016018
FUN_08016018: @ 0x08016018
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _0801607C @ =gSolidFnTable
	adds r3, r0, #0
	movs r4, #3
_08016022:
	ldr r2, [r3, #0x68]
	cmp r2, #0
	beq _0801605A
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r1, [r2, #9]
	lsls r1, r1, #2
	adds r1, r1, r6
	movs r0, #3
	str r0, [r2, #0xc]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_0801605A:
	adds r3, #4
	subs r4, #1
	cmp r4, #0
	bge _08016022
	movs r4, #0x92
	lsls r4, r4, #1
	adds r0, r4, #0
	bl isSoundPlaying
	cmp r0, #0
	beq _08016076
	adds r0, r4, #0
	bl stopSound
_08016076:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801607C: .4byte gSolidFnTable

	thumb_func_start FUN_08016080
FUN_08016080: @ 0x08016080
	ldr r1, _0801608C @ =gOverworld
	ldr r2, _08016090 @ =0x0002D034
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_0801608C: .4byte gOverworld
_08016090: .4byte 0x0002D034

	thumb_func_start FUN_08016094
FUN_08016094: @ 0x08016094
	push {r4, r5, lr}
	ldr r3, _080160B0 @ =gOverworld
	ldr r5, _080160B4 @ =0x0002D040
	adds r4, r3, r5
	str r0, [r4]
	ldr r4, _080160B8 @ =0x0002D044
	adds r0, r3, r4
	str r1, [r0]
	adds r5, #8
	adds r3, r3, r5
	str r2, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080160B0: .4byte gOverworld
_080160B4: .4byte 0x0002D040
_080160B8: .4byte 0x0002D044
