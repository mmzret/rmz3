	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r3, _080095DC @ =gOverworld
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	movs r4, #0x7f
	mov r8, r4
	mov r2, r8
	ands r2, r1
	mov r8, r2
	ldr r2, _080095E0 @ =gStageLandscape
	mov r4, r8
	lsls r1, r4, #2
	adds r1, r1, r2
	ldr r1, [r1]
	mov sb, r1
	ldr r1, [r0]
	ldr r0, [r0, #4]
	ldr r2, _080095E4 @ =gScreenX
	asrs r1, r1, #0xc
	adds r1, r1, r2
	ldrb r2, [r1]
	ldr r1, _080095E8 @ =gScreenY
	asrs r0, r0, #0xc
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sb
	ldr r1, [r4, #0x6c]
	ldrb r4, [r1, #2]
	cmp r2, r4
	bhs _0800969C
	ldrb r4, [r1, #3]
	cmp r0, r4
	bhs _0800969C
	ldrb r4, [r1]
	lsls r0, r4
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r7, [r0, #4]
	lsrs r2, r7, #4
	ldr r1, _080095EC @ =0x000007D4
	adds r0, r3, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, r8
	bne _080095F0
	movs r0, #0xff
	ands r0, r1
	cmp r2, r0
	bne _080095F4
	b _0800962E
	.align 2, 0
_080095DC: .4byte gOverworld
_080095E0: .4byte gStageLandscape
_080095E4: .4byte gScreenX
_080095E8: .4byte gScreenY
_080095EC: .4byte 0x000007D4
_080095F0:
	cmp r2, #0xff
	beq _0800962E
_080095F4:
	mov r2, r8
	lsls r5, r2, #2
	ldr r4, _0800964C @ =gStageTilesetOffsets
	adds r5, r5, r4
	ldr r0, [r5]
	adds r0, r0, r5
	lsrs r6, r7, #4
	lsls r4, r6, #2
	adds r4, r4, r6
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldr r0, [r5]
	adds r0, r0, r5
	adds r0, r0, r4
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
	ldr r0, _08009650 @ =gOverworld
	mov r2, r8
	lsls r1, r2, #8
	orrs r6, r1
	ldr r4, _08009654 @ =0x000007D4
	adds r0, r0, r4
	strh r6, [r0]
_0800962E:
	movs r2, #0xf
	ands r2, r7
	ldr r0, _08009650 @ =gOverworld
	ldr r1, _08009658 @ =0x000007D6
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, r8
	bne _0800965C
	movs r0, #0xff
	ands r0, r1
	cmp r2, r0
	bne _08009660
	b _0800969C
	.align 2, 0
_0800964C: .4byte gStageTilesetOffsets
_08009650: .4byte gOverworld
_08009654: .4byte 0x000007D4
_08009658: .4byte 0x000007D6
_0800965C:
	cmp r2, #0xff
	beq _0800969C
_08009660:
	mov r2, r8
	lsls r6, r2, #2
	ldr r4, _080096AC @ =gStageTilesetOffsets
	adds r6, r6, r4
	ldr r0, [r6]
	adds r0, r0, r6
	movs r5, #0xf
	ands r5, r7
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldr r0, [r6]
	adds r0, r0, r6
	adds r0, r0, r4
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
	ldr r0, _080096B0 @ =gOverworld
	mov r2, r8
	lsls r1, r2, #8
	orrs r5, r1
	ldr r4, _080096B4 @ =0x000007D6
	adds r0, r0, r4
	strh r5, [r0]
_0800969C:
	mov r0, sb
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080096AC: .4byte gStageTilesetOffsets
_080096B0: .4byte gOverworld
_080096B4: .4byte 0x000007D6
