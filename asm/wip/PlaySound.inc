	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r1, _080045CC @ =gSongTable
	lsls r0, r4, #3
	adds r0, r0, r1
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080045D4
	ldr r1, _080045D0 @ =SoundID2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080045C6
	cmp r0, #0x29
	bne _080045DE
_080045C6:
	strh r4, [r1]
	b _080045DE
	.align 2, 0
_080045CC: .4byte gSongTable
_080045D0: .4byte SoundID2
_080045D4:
	cmp r4, #0
	beq _080045E4
	adds r0, r4, #0
	bl m4aSongNumStart
_080045DE:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b _080045E6
_080045E4:
	movs r0, #0
_080045E6:
	pop {r4}
	pop {r1}
	bx r1
