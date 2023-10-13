	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r2, r0, #0
	ldr r7, [r2, #0xc]
	movs r1, #2
	ldrsh r0, [r7, r1]
	cmp r0, #6
	bls _080225C6
	b _08022800
_080225C6:
	lsls r0, r0, #2
	ldr r1, _080225D0 @ =_080225D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080225D0: .4byte _080225D4
_080225D4: @ jump table
	.4byte _080225F0 @ case 0
	.4byte _08022640 @ case 1
	.4byte _08022660 @ case 2
	.4byte _08022700 @ case 3
	.4byte _08022778 @ case 4
	.4byte _0802279A @ case 5
	.4byte _080227A8 @ case 6
_080225F0:
	ldr r1, _08022634 @ =gVideoRegBuffer+6
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r0, r1, #0
	adds r0, #0xa
	movs r4, #0
	str r4, [r0]
	subs r1, #6
	ldrh r2, [r1]
	movs r3, #0x90
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r5, _08022638 @ =0x08547280
	adds r0, r0, r5
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802263C @ =0x0854728C
	adds r0, r0, r1
	b _08022746
	.align 2, 0
_08022634: .4byte gVideoRegBuffer+6
_08022638: .4byte gGraphic_Capcom
_0802263C: .4byte gPalette_Capcom
_08022640:
	ldr r2, _08022658 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _0802265C @ =0x0000EDFF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	bl ResumeAllBlinks
	b _08022800
	.align 2, 0
_08022658: .4byte gVideoRegBuffer
_0802265C: .4byte 0x0000EDFF
_08022660:
	ldr r4, _080226E4 @ =gVideoRegBuffer+6
	ldr r5, _080226E8 @ =0x00008284
	adds r0, r5, #0
	strh r0, [r4]
	movs r3, #0
	strh r3, [r4, #0xa]
	movs r0, #0xa0
	strh r0, [r4, #0xc]
	subs r2, r4, #6
	ldrh r0, [r2]
	movs r5, #0x90
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	movs r6, #0
	orrs r0, r3
	ldr r1, _080226EC @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080226F0 @ =0x08547280
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _080226F4 @ =0x0854728C
	adds r0, r0, r2
	movs r1, #0
	bl LoadPalette
	ldr r5, _080226F8 @ =gBgMapOffsets
	ldrb r2, [r7, #1]
	str r6, [sp]
	movs r0, #0x12
	adds r1, r5, #0
	movs r3, #0
	bl LoadBgMap
	ldrh r1, [r4]
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r0, r1
	lsls r0, r0, #3
	ldr r3, _080226FC @ =0x06000800
	adds r0, r0, r3
	ldrb r2, [r7, #1]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r6, [sp]
	adds r1, r5, #0
	movs r3, #0
	bl loadBgMap_08004248
	bl PauseAllBlinks
	b _08022800
	.align 2, 0
_080226E4: .4byte gVideoRegBuffer+6
_080226E8: .4byte 0x00008284
_080226EC: .4byte 0x0000FEFF
_080226F0: .4byte gGraphic_Capcom
_080226F4: .4byte gPalette_Capcom
_080226F8: .4byte gBgMapOffsets
_080226FC: .4byte 0x06000800
_08022700:
	ldr r2, _08022760 @ =gVideoRegBuffer+6
	ldr r4, _08022764 @ =0x00008284
	adds r0, r4, #0
	strh r0, [r2]
	movs r3, #0
	strh r3, [r2, #0xa]
	movs r0, #0x60
	strh r0, [r2, #0xc]
	subs r2, #6
	ldrh r0, [r2]
	movs r5, #0x90
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	movs r4, #0
	orrs r0, r3
	ldr r1, _08022768 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802276C @ =0x08547280
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _08022770 @ =0x0854728C
	adds r0, r0, r2
_08022746:
	movs r1, #0
	bl LoadPalette
	ldr r1, _08022774 @ =gBgMapOffsets
	ldrb r2, [r7, #1]
	str r4, [sp]
	movs r0, #0x12
	movs r3, #0
	bl LoadBgMap
	bl PauseAllBlinks
	b _08022800
	.align 2, 0
_08022760: .4byte gVideoRegBuffer+6
_08022764: .4byte 0x00008284
_08022768: .4byte 0x0000FEFF
_0802276C: .4byte gGraphic_Capcom
_08022770: .4byte gPalette_Capcom
_08022774: .4byte gBgMapOffsets
_08022778:
	ldr r1, _08022790 @ =gVideoRegBuffer+18
	ldrh r0, [r1]
	cmp r0, #0
	beq _08022794
	subs r0, #1
	strh r0, [r1]
	ldr r0, [r2, #0xc]
	subs r0, #8
	str r0, [r2, #0xc]
	movs r0, #1
	b _08022802
	.align 2, 0
_08022790: .4byte gVideoRegBuffer+18
_08022794:
	bl text_080e9730
	b _08022800
_0802279A:
	ldr r1, _080227A4 @ =gPaletteManager
	ldr r0, [r7, #4]
	strh r0, [r1]
	b _08022800
	.align 2, 0
_080227A4: .4byte gPaletteManager
_080227A8:
	ldr r1, _0802280C @ =gVideoRegBuffer+6
	movs r3, #0x81
	lsls r3, r3, #2
	adds r0, r3, #0
	strh r0, [r1]
	adds r0, r1, #0
	adds r0, #0xa
	movs r4, #0
	str r4, [r0]
	subs r1, #6
	ldrh r2, [r1]
	movs r5, #0x90
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r0, r2
	strh r0, [r1]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08022810 @ =0x08547280
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _08022814 @ =0x0854728C
	adds r0, r0, r2
	movs r1, #0
	bl LoadPalette
	ldr r1, _08022818 @ =gBgMapOffsets
	ldrb r2, [r7, #1]
	str r4, [sp]
	movs r0, #0x12
	movs r3, #0
	bl LoadBgMap
	bl PauseAllBlinks
_08022800:
	movs r0, #0
_08022802:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802280C: .4byte gVideoRegBuffer+6
_08022810: .4byte gGraphic_Capcom
_08022814: .4byte gPalette_Capcom
_08022818: .4byte gBgMapOffsets
