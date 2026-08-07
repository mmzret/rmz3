	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xb4
	ldr r4, [r0]
	ldr r1, _080E3D48 @ =gPause
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E3D4C @ =0x00000121
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #5
	cmp r0, #0x2f
	bls _080E3D3C
	b _080E3EB0
_080E3D3C:
	lsls r0, r0, #2
	ldr r1, _080E3D50 @ =_080E3D54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E3D48: .4byte gPause
_080E3D4C: .4byte 0x00000121
_080E3D50: .4byte _080E3D54
_080E3D54: @ jump table
	.4byte _080E3E14 @ case 0
	.4byte _080E3E24 @ case 1
	.4byte _080E3E40 @ case 2
	.4byte _080E3E40 @ case 3
	.4byte _080E3EB0 @ case 4
	.4byte _080E3EB0 @ case 5
	.4byte _080E3EB0 @ case 6
	.4byte _080E3EB0 @ case 7
	.4byte _080E3EB0 @ case 8
	.4byte _080E3EB0 @ case 9
	.4byte _080E3EB0 @ case 10
	.4byte _080E3EB0 @ case 11
	.4byte _080E3EB0 @ case 12
	.4byte _080E3EB0 @ case 13
	.4byte _080E3EB0 @ case 14
	.4byte _080E3EB0 @ case 15
	.4byte _080E3EB0 @ case 16
	.4byte _080E3EB0 @ case 17
	.4byte _080E3EB0 @ case 18
	.4byte _080E3EB0 @ case 19
	.4byte _080E3EB0 @ case 20
	.4byte _080E3EB0 @ case 21
	.4byte _080E3E9C @ case 22
	.4byte _080E3EA6 @ case 23
	.4byte _080E3EA6 @ case 24
	.4byte _080E3EA6 @ case 25
	.4byte _080E3EA6 @ case 26
	.4byte _080E3EB0 @ case 27
	.4byte _080E3EB0 @ case 28
	.4byte _080E3EB0 @ case 29
	.4byte _080E3EB0 @ case 30
	.4byte _080E3EB0 @ case 31
	.4byte _080E3EB0 @ case 32
	.4byte _080E3EB0 @ case 33
	.4byte _080E3EB0 @ case 34
	.4byte _080E3EB0 @ case 35
	.4byte _080E3EB0 @ case 36
	.4byte _080E3EB0 @ case 37
	.4byte _080E3EA6 @ case 38
	.4byte _080E3EB0 @ case 39
	.4byte _080E3EA6 @ case 40
	.4byte _080E3EB0 @ case 41
	.4byte _080E3EB0 @ case 42
	.4byte _080E3EB0 @ case 43
	.4byte _080E3EB0 @ case 44
	.4byte _080E3EB0 @ case 45
	.4byte _080E3EB0 @ case 46
	.4byte _080E3EB0 @ case 47
_080E3E14:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
	movs r2, #0
	strh r0, [r1, #4]
	strb r2, [r1, #0xa]
	b _080E3E32
_080E3E24:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
	movs r2, #0
	strh r0, [r1, #4]
	strb r2, [r1, #0xb]
_080E3E32:
	ldr r0, _080E3E3C @ =0x00000103
	movs r1, #0x5a
	bl PrintTextWindow
	b _080E3EB0
	.align 2, 0
_080E3E3C: .4byte 0x00000103
_080E3E40:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #5
	strh r0, [r1, #4]
	movs r0, #6
	bl PlaySound
	ldr r2, _080E3E98 @ =gScore
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3E76
	adds r0, #1
	strb r0, [r1]
_080E3E76:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _080E3EB0
	ldr r2, _080E3E98 @ =gScore
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3EB0
	adds r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, #8
	bhi _080E3EB0
	adds r0, #1
	strb r0, [r1]
	b _080E3EB0
	.align 2, 0
_080E3E98: .4byte gScore
_080E3E9C:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #5
	b _080E3EAE
_080E3EA6:
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1, #4]
	adds r0, #3
_080E3EAE:
	strh r0, [r1, #4]
_080E3EB0:
	ldr r0, _080E3F14 @ =gScore
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E3EC2
	adds r0, #1
	strb r0, [r1]
_080E3EC2:
	ldr r1, _080E3F18 @ =gElfAvailability
	ldr r2, _080E3F1C @ =0x00000121
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080E3F20 @ =gElfFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E3F14: .4byte gScore
_080E3F18: .4byte gElfAvailability
_080E3F1C: .4byte 0x00000121
_080E3F20: .4byte gElfFnTable
