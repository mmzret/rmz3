	push {r4, r5, lr}
	ldr r2, _08008D78 @ =gVideoRegBuffer
	ldrh r1, [r2]
	ldr r0, _08008D7C @ =0x0000C1FF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08008D80 @ =gOverworld
	ldr r1, _08008D84 @ =0x000007D4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r5, r0, #8
	cmp r5, #0xff
	beq _08008CD2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	beq _08008CD2
	lsls r5, r5, #2
	ldr r2, _08008D88 @ =gStageTilesetOffsets
	adds r5, r5, r2
	ldr r0, [r5]
	adds r0, r0, r5
	lsls r4, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, [r5]
	adds r0, r0, r5
	adds r0, r0, r4
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08008CD2:
	ldr r0, _08008D80 @ =gOverworld
	ldr r1, _08008D8C @ =0x000007D6
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r5, r0, #8
	cmp r5, #0xff
	beq _08008D10
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	beq _08008D10
	lsls r5, r5, #2
	ldr r2, _08008D88 @ =gStageTilesetOffsets
	adds r5, r5, r2
	ldr r0, [r5]
	adds r0, r0, r5
	lsls r4, r1, #2
	adds r4, r4, r1
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #7
	bl LoadGraphic
	ldr r0, [r5]
	adds r0, r0, r5
	adds r0, r0, r4
	adds r0, #0xc
	movs r1, #0
	bl LoadPalette
_08008D10:
	ldr r5, _08008D78 @ =gVideoRegBuffer
	ldr r4, _08008D80 @ =gOverworld
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	adds r1, #0x5c
	movs r3, #2
_08008D1E:
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, [r1, #0x18]
	adds r0, r0, r2
	str r0, [r1, #0x18]
	ldr r0, [r1, #0x1c]
	adds r0, r0, r2
	str r0, [r1, #0x1c]
	adds r1, #0x88
	subs r3, #1
	cmp r3, #0
	bge _08008D1E
	ldrh r0, [r5]
	ldr r1, _08008D90 @ =0x0000F0FF
	ands r1, r0
	movs r2, #0xfb
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r5]
	ldr r1, _08008D94 @ =0x000007DA
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r5, #6]
	adds r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r5, #8]
	adds r1, #4
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r5, #0xa]
	ldr r2, _08008D98 @ =0x0002C002
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08008D78: .4byte gVideoRegBuffer
_08008D7C: .4byte 0x0000C1FF
_08008D80: .4byte gOverworld
_08008D84: .4byte 0x000007D4
_08008D88: .4byte gStageTilesetOffsets
_08008D8C: .4byte 0x000007D6
_08008D90: .4byte 0x0000F0FF
_08008D94: .4byte 0x000007DA
_08008D98: .4byte 0x0002C002
