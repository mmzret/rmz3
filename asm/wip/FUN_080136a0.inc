	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r5, _08013710 @ =gOverworld
	ldr r1, _08013714 @ =0x000007D4
	adds r0, r5, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0xd
	bne _08013768
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _08013768
	ldr r2, _08013718 @ =0x0002D02A
	adds r6, r5, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _08013724
	ldr r4, _0801371C @ =gStageTilesetOffsets+(18*4)
	adds r2, r0, #0
	lsls r2, r2, #1
	ldr r0, _08013720 @ =0x0002D029
	adds r5, r5, r0
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r0, #0x48
	adds r2, r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrb r2, [r6]
	lsls r2, r2, #1
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r0, #0x48
	adds r2, r2, r0
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r4]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
	b _08013768
	.align 2, 0
_08013710: .4byte gOverworld
_08013714: .4byte 0x000007D4
_08013718: .4byte 0x0002D02A
_0801371C: .4byte gStageTilesetOffsets+(18*4)
_08013720: .4byte 0x0002D029
_08013724:
	ldr r1, _08013774 @ =gStageTilesetOffsets+(18*4)
	mov r8, r1
	ldr r2, _08013778 @ =0x0002D029
	adds r6, r5, r2
	ldrb r0, [r6]
	lsrs r0, r0, #2
	movs r5, #1
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0801377C @ =0x08704A98
	adds r1, r1, r4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl RequestGraphicTransfer
	ldrb r0, [r6]
	lsrs r0, r0, #2
	ands r0, r5
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08013768:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08013774: .4byte gStageTilesetOffsets+(18*4)
_08013778: .4byte 0x0002D029
_0801377C: .4byte 0x08704A98
