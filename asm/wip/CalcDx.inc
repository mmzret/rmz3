	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xb4
	ldr r1, _08032A54 @ =0x00000216
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08032A58
	movs r0, #0x80
	lsls r0, r0, #2
	b _08032AAC
	.align 2, 0
_08032A54: .4byte 0x00000216
_08032A58:
	movs r5, #0x80
	lsls r5, r5, #2
	ldrb r0, [r2, #0x11]
	cmp r0, #4
	beq _08032A74
	cmp r0, #7
	beq _08032A74
	adds r0, r4, #0
	movs r1, #0x1c
	bl IsElfUsed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08032A78
_08032A74:
	movs r5, #0xa0
	lsls r5, r5, #2
_08032A78:
	ldr r2, _08032A90 @ =0x0000011D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08032A94
	movs r1, #0xc7
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	asrs r5, r0
	adds r0, r5, #0
	b _08032AAC
	.align 2, 0
_08032A90: .4byte 0x0000011D
_08032A94:
	ldrb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	subs r1, r1, r0
	adds r0, r5, #0
	muls r0, r1, r0
	asrs r0, r0, #8
	movs r2, #0xc7
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	asrs r0, r1
_08032AAC:
	pop {r4, r5}
	pop {r1}
	bx r1
  .align 2, 0
