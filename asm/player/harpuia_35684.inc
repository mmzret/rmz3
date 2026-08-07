	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x58]
	movs r2, #0x96
	lsls r2, r2, #9
	cmp r1, r2
	ble _0803569E
	ldr r0, [r4, #0x54]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	b _080356A6
_0803569E:
	ldr r0, [r4, #0x54]
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r0, r0, r2
_080356A6:
	bl PushoutToLeft2
	adds r5, r0, #0
	cmp r5, #0
	beq _080356B6
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_080356B6:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _080356E4
	ldr r0, [r4, #0x28]
	movs r2, #4
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bne _080356E4
	ldr r0, _08035778 @ =gJoypad
	ldrh r0, [r0, #4]
	movs r2, #1
	ands r1, r0
	cmp r1, #0
	beq _080356E4
	strb r2, [r3]
	ldr r3, _0803577C @ =0x00000285
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _08035780 @ =0xFFFFFAC0
	str r0, [r4, #0x60]
_080356E4:
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrb r1, [r6]
	cmp r1, #1
	beq _080356F2
	b _08035814
_080356F2:
	ldr r0, _08035778 @ =gJoypad
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _0803570A
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bge _0803570A
	str r1, [r4, #0x60]
	ldr r2, _0803577C @ =0x00000285
	adds r0, r4, r2
	strb r1, [r0]
_0803570A:
	ldr r3, _0803577C @ =0x00000285
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #1
	bne _08035720
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08035720
	movs r0, #0
	str r0, [r4, #0x60]
	strb r0, [r1]
_08035720:
	ldr r0, [r4, #0x60]
	adds r0, #0x2c
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08035730
	str r1, [r4, #0x60]
_08035730:
	ldr r0, [r4, #0x58]
	ldr r3, [r4, #0x60]
	adds r1, r0, r3
	str r1, [r4, #0x58]
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r7, r4, r0
	ldr r2, [r7]
	ldr r0, _08035784 @ =0x7FFFFFFF
	cmp r2, r0
	bne _08035748
	b _08035870
_08035748:
	cmp r1, r2
	ble _0803574E
	b _08035870
_0803574E:
	ldr r0, [r4, #0x54]
	ldr r6, _08035788 @ =0xFFFFE600
	adds r0, r0, r6
	adds r1, r1, r3
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _0803578C
	ldr r0, [r7]
	cmp r1, r0
	bgt _0803578C
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	b _080357EC
	.align 2, 0
_08035778: .4byte gJoypad
_0803577C: .4byte 0x00000285
_08035780: .4byte 0xFFFFFAC0
_08035784: .4byte 0x7FFFFFFF
_08035788: .4byte 0xFFFFE600
_0803578C:
	ldr r0, [r4, #0x54]
	movs r6, #0xd0
	lsls r6, r6, #5
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _080357C2
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _080357C2
	ldr r0, [r4, #0x54]
	adds r0, r0, r6
	b _080357EC
_080357C2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl PushoutToUp2
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r1, r0, #0
	cmp r5, #0
	beq _08035870
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _08035870
	ldr r0, [r4, #0x54]
_080357EC:
	ldr r1, [r4, #0x58]
	ldr r2, _0803580C @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_0800a05c
	str r0, [r4, #0x58]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08035810 @ =0x00000285
	adds r0, r4, r2
	strb r1, [r0]
	b _08035870
	.align 2, 0
_0803580C: .4byte 0xFFFFF000
_08035810: .4byte 0x00000285
_08035814:
	ldr r0, [r4, #0x54]
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r1, [r4, #0x58]
	cmp r5, r1
	beq _08035870
	ldr r0, [r4, #0x54]
	ldr r2, _08035878 @ =0xFFFFE600
	adds r0, r0, r2
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r1, [r4, #0x58]
	cmp r5, r1
	beq _08035870
	ldr r0, [r4, #0x54]
	bl FUN_0800a05c
	adds r5, r0, #0
	ldr r0, [r4, #0x58]
	cmp r5, r0
	beq _08035870
	movs r2, #0
	movs r1, #1
	strb r1, [r6]
	ldr r3, _0803587C @ =0x00000285
	adds r0, r4, r3
	strb r1, [r0]
	str r2, [r4, #0x60]
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r5, r0
	ble _08035870
	ldr r0, _08035880 @ =0x7FFFFFFF
	str r0, [r1]
	ldr r2, _08035884 @ =0x00000286
	adds r1, r4, r2
	movs r0, #0x78
	strb r0, [r1]
_08035870:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035878: .4byte 0xFFFFE600
_0803587C: .4byte 0x00000285
_08035880: .4byte 0x7FFFFFFF
_08035884: .4byte 0x00000286
