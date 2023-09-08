	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08011838 @ =gOverworld
	ldr r1, _0801183C @ =0x0002D02A
	adds r0, r0, r1
	ldrb r3, [r0]
	cmp r3, #0x3f
	bhi _08011840
	movs r3, #0
	b _08011862
	.align 2, 0
_08011838: .4byte gOverworld
_0801183C: .4byte 0x0002D02A
_08011840:
	cmp r3, #0x7f
	bhi _0801184C
	adds r0, r3, #0
	subs r0, #0x40
	lsls r0, r0, #0xe
	b _08011860
_0801184C:
	cmp r3, #0xbf
	bhi _08011854
	movs r3, #0x10
	b _08011862
_08011854:
	adds r1, r3, #0
	subs r1, #0xc0
	asrs r1, r1, #2
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
_08011860:
	lsrs r3, r0, #0x10
_08011862:
	ldr r2, _08011880 @ =gBlendRegBuffer
	movs r1, #0x1f
	ands r1, r3
	movs r0, #0x10
	subs r0, r0, r3
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #2]
	adds r0, r4, #0
	adds r1, r5, #0
	bl DrawGeneralStageLayer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011880: .4byte gBlendRegBuffer
