	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	mov r8, r1
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _0802721C @ =0x0000018F
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	str r3, [sp]
	movs r4, #0
	str r4, [sp, #8]
	movs r6, #0
	str r6, [sp, #4]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	ldr r2, _08027220 @ =0x0000FFFF
	cmp r0, r2
	bne _08027174
	b _0802745C
_08027174:
	ldr r3, _08027224 @ =gOverworld
	str r3, [sp, #0x14]
	str r1, [sp, #0x18]
_0802717A:
	movs r4, #0
	mov sl, r4
	movs r5, #1
	ldr r6, _08027228 @ =0x020023D2
	ldrb r1, [r6]
	ldr r0, [sp, #4]
	lsls r3, r0, #1
	cmp sl, r1
	bhs _080271B8
	ldr r4, _08027224 @ =gOverworld
	ldr r2, [sp, #0x18]
	adds r0, r2, r3
	ldrh r2, [r0]
_08027194:
	mov r6, sl
	lsls r0, r6, #1
	add r0, sl
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r6, #0xea
	lsls r6, r6, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, r2
	beq _08027234
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp sl, r1
	blo _08027194
_080271B8:
	ldr r0, [sp, #0x18]
	adds r1, r0, r3
	ldr r0, _08027220 @ =0x0000FFFF
	strh r0, [r1]
	cmp r5, #0
	beq _080271C6
	b _0802743E
_080271C6:
	mov r1, sl
	lsls r3, r1, #1
	adds r1, r3, r1
	lsls r1, r1, #3
	ldr r2, [sp, #0x14]
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r0, r1, r0
	ldr r6, _0802722C @ =gOverworld+484
	adds r1, r1, r6
	ldr r2, [r0]
	ldr r0, [r1]
	subs r4, r2, r0
	str r3, [sp, #0x1c]
	cmp r4, #0
	bne _080271EA
	b _08027408
_080271EA:
	adds r1, r4, #0
	cmp r4, #0
	bge _080271F2
	rsbs r1, r4, #0
_080271F2:
	ldr r0, _08027230 @ =0x00000FFF
	cmp r1, r0
	ble _080271FA
	b _08027408
_080271FA:
	ldr r0, [r7, #0x54]
	adds r2, r0, r4
	str r2, [r7, #0x54]
	cmp r4, #0
	ble _0802724A
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027238
	mov r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r1, r2, r1
	ldrh r0, [r0, #4]
	b _08027242
	.align 2, 0
_0802721C: .4byte 0x0000018F
_08027220: .4byte 0x0000FFFF
_08027224: .4byte gOverworld
_08027228: .4byte 0x020023D2
_0802722C: .4byte gOverworld+484
_08027230: .4byte 0x00000FFF
_08027234:
	movs r5, #0
	b _080271B8
_08027238:
	mov r6, r8
	movs r0, #0
	ldrsh r1, [r6, r0]
	adds r1, r2, r1
	ldrh r0, [r6, #4]
_08027242:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	b _08027270
_0802724A:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027260
	mov r3, r8
	movs r6, #0
	ldrsh r1, [r3, r6]
	subs r1, r2, r1
	ldrh r0, [r3, #4]
	b _0802726A
_08027260:
	mov r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r1, r2, r1
	ldrh r0, [r0, #4]
_0802726A:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
_08027270:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bne _08027334
	ldr r0, [r7, #0x54]
	cmp r0, r5
	ble _08027286
	mov r6, r8
	movs r1, #4
	ldrsh r0, [r6, r1]
	adds r0, r0, r5
	b _0802728E
_08027286:
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r0, r5, r0
_0802728E:
	mov sb, r0
	mov r6, r8
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r6, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080272C0
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080272E2
_080272C0:
	mov r0, sb
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080272D0
	b _0802778E
_080272D0:
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080272E2
	b _0802778E
_080272E2:
	mov r2, r8
	movs r3, #2
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r2, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08027312
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08027334
_08027312:
	mov r0, sb
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08027322
	b _0802778E
_08027322:
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08027334
	b _0802778E
_08027334:
	cmp r4, #0
	ble _0802739E
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToLeft2
	adds r4, r0, #0
	cmp r4, #0
	bge _0802735E
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
_0802735E:
	mov r0, r8
	movs r2, #2
	ldrsh r1, [r0, r2]
	ldr r0, [r7, #0x58]
	adds r6, r0, r1
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToLeft2
	adds r4, r0, #0
	cmp r4, #0
	bge _0802737C
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
_0802737C:
	mov r3, r8
	movs r4, #2
	ldrsh r0, [r3, r4]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r3, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToLeft2
	adds r4, r0, #0
	cmp r4, #0
	bge _08027408
	b _08027402
_0802739E:
	mov r6, r8
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r6, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToRight2
	adds r4, r0, #0
	cmp r4, #0
	ble _080273C4
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
_080273C4:
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	ldr r0, [r7, #0x58]
	adds r6, r0, r1
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToRight2
	adds r4, r0, #0
	cmp r4, #0
	ble _080273E2
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
_080273E2:
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToRight2
	adds r4, r0, #0
	cmp r4, #0
	ble _08027408
_08027402:
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [r7, #0x54]
_08027408:
	ldr r0, [sp, #0x1c]
	add r0, sl
	lsls r0, r0, #3
	ldr r2, [sp, #0x14]
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r1, r2, r3
	adds r1, r0, r1
	ldr r4, _080274EC @ =gOverworld+488
	adds r0, r0, r4
	ldr r1, [r1]
	ldr r0, [r0]
	subs r4, r1, r0
	cmp r4, #0
	beq _0802743E
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	beq _08027432
	ldr r0, [r7, #0x58]
	cmp r0, r1
	bgt _0802743E
_08027432:
	ldr r6, [sp]
	cmp r6, #0
	beq _0802743C
	cmp r6, r4
	ble _0802743E
_0802743C:
	str r4, [sp]
_0802743E:
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, #0xf
	bhi _0802745C
	lsls r0, r0, #1
	ldr r1, [sp, #0x18]
	adds r0, r1, r0
	ldrh r0, [r0]
	ldr r2, _080274F0 @ =0x0000FFFF
	cmp r0, r2
	beq _0802745C
	b _0802717A
_0802745C:
	ldr r3, [sp]
	cmp r3, #0
	bne _08027464
	b _08027952
_08027464:
	adds r1, r3, #0
	cmp r3, #0
	bge _0802746C
	rsbs r1, r3, #0
_0802746C:
	ldr r0, _080274F4 @ =0x00000FFF
	cmp r1, r0
	ble _08027474
	b _08027952
_08027474:
	ldr r0, [r7, #0x58]
	ldr r4, [sp]
	adds r2, r0, r4
	str r2, [r7, #0x58]
	ldr r6, _080274F8 @ =0x0000018D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027488
	b _08027792
_08027488:
	cmp r4, #0
	bgt _0802748E
	b _08027692
_0802748E:
	ldr r0, [r7, #0x54]
	adds r1, r2, #0
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _080274C2
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _080274C2
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _080274CC
_080274C2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl PushoutToUp2
	str r0, [sp]
_080274CC:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080274FC
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	b _0802750E
	.align 2, 0
_080274EC: .4byte gOverworld+488
_080274F0: .4byte 0x0000FFFF
_080274F4: .4byte 0x00000FFF
_080274F8: .4byte 0x0000018D
_080274FC:
	mov r4, r8
	movs r6, #0
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
_0802750E:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _08027542
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _08027542
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _08027554
_08027542:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl PushoutToUp2
	adds r4, r0, #0
	ldr r0, [sp]
	cmp r0, r4
	ble _08027554
	str r4, [sp]
_08027554:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027574
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	b _08027586
_08027574:
	mov r4, r8
	movs r6, #0
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
_08027586:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _080275BA
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _080275BA
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _080275CC
_080275BA:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl PushoutToUp2
	adds r4, r0, #0
	ldr r0, [sp]
	cmp r0, r4
	ble _080275CC
	str r4, [sp]
_080275CC:
	ldr r1, [sp]
	cmp r1, #0
	blt _080275D4
	b _08027952
_080275D4:
	ldr r1, [sp, #0x10]
	adds r1, #1
	ldr r0, [sp, #0xc]
	bl PushoutToUp2
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0802768C
	mov r2, r8
	movs r3, #2
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r2, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027614
	movs r4, #0
	ldrsh r0, [r2, r4]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	b _08027628
_08027614:
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
_08027628:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl hazard_08028338
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802763A
	b _0802778E
_0802763A:
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027668
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	b _0802767A
_08027668:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
_0802767A:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl hazard_08028338
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802768C
	b _0802778E
_0802768C:
	ldr r0, [r7, #0x58]
	ldr r4, [sp]
	b _0802794E
_08027692:
	ldr r6, [sp]
	cmp r6, #0
	blt _0802769A
	b _08027952
_0802769A:
	mov r0, r8
	movs r3, #2
	ldrsh r1, [r0, r3]
	adds r1, r2, r1
	ldrh r0, [r0, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080276C8
	mov r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	b _080276DA
_080276C8:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
_080276DA:
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _0802770E
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0802770E
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _0802771A
_0802770E:
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToDown2
	cmp r0, #0
	bgt _0802778E
_0802771A:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027738
	mov r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	b _0802774A
_08027738:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
_0802774A:
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _08027780
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _08027780
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bhi _08027780
	b _08027952
_08027780:
	adds r0, r5, #0
	adds r1, r6, #0
	bl PushoutToDown2
	cmp r0, #0
	bgt _0802778E
	b _08027952
_0802778E:
	movs r0, #1
	b _0802796C
_08027792:
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	beq _0802779A
	b _080278A8
_0802779A:
	ldr r4, [sp]
	cmp r4, #0
	ble _08027864
	ldr r0, [r7, #0x54]
	adds r1, r2, #0
	bl PushoutToUp2
	str r0, [sp]
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080277C8
	mov r6, r8
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	b _080277DA
_080277C8:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
_080277DA:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl PushoutToUp2
	adds r4, r0, #0
	ldr r6, [sp]
	cmp r6, r4
	ble _080277EC
	str r4, [sp]
_080277EC:
	ldr r2, [r7, #0x58]
	adds r0, r7, #0
	adds r1, r5, #0
	bl hazard_08028114
	adds r4, r0, #0
	ldr r0, [sp]
	cmp r0, r4
	ble _08027800
	str r4, [sp]
_08027800:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08027820
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	b _08027832
_08027820:
	mov r4, r8
	movs r6, #0
	ldrsh r0, [r4, r6]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
_08027832:
	ldr r1, [r7, #0x58]
	adds r0, r5, #0
	bl PushoutToUp2
	adds r4, r0, #0
	ldr r0, [sp]
	cmp r0, r4
	ble _08027844
	str r4, [sp]
_08027844:
	ldr r2, [r7, #0x58]
	adds r0, r7, #0
	adds r1, r5, #0
	bl hazard_08028114
	adds r4, r0, #0
	ldr r1, [sp]
	cmp r1, r4
	ble _08027858
	str r4, [sp]
_08027858:
	ldr r2, [sp]
	cmp r2, #0
	bge _08027952
	ldr r0, [r7, #0x58]
	adds r0, r0, r2
	b _08027950
_08027864:
	ldr r3, [sp]
	cmp r3, #0
	bge _08027952
	ldr r0, [r7, #0x54]
	ldr r4, _080278A4 @ =0xFFFFE200
	adds r1, r2, r4
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08027952
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl PushoutToDown2
	adds r4, r0, #0
	cmp r4, #0
	ble _08027894
	ldr r0, [r7, #0x58]
	adds r0, #1
	adds r0, r0, r4
	str r0, [r7, #0x58]
_08027894:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq _08027952
	movs r6, #2
	str r6, [sp, #8]
	b _08027952
	.align 2, 0
_080278A4: .4byte 0xFFFFE200
_080278A8:
	ldr r0, [sp]
	cmp r0, #0
	bge _08027902
	ldr r0, [r7, #0x54]
	ldr r5, _0802797C @ =0xFFFFE200
	adds r1, r2, r5
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _080278E8
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r5
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _080278E8
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r1, r1, r5
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _08027902
_080278E8:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _0802797C @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToDown2
	adds r4, r0, #0
	cmp r4, #0
	ble _08027902
	ldr r0, [r7, #0x58]
	adds r0, #1
	adds r0, r0, r4
	str r0, [r7, #0x58]
_08027902:
	ldr r3, [sp]
	cmp r3, #0
	ble _08027952
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _0802793C
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0802793C
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _08027952
_0802793C:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl PushoutToUp2
	adds r4, r0, #0
	cmp r4, #0
	bge _08027952
	ldr r0, [r7, #0x58]
	subs r0, #1
_0802794E:
	adds r0, r0, r4
_08027950:
	str r0, [r7, #0x58]
_08027952:
	ldr r0, [r7, #0x54]
	ldr r4, [sp, #0xc]
	cmp r4, r0
	bne _08027962
	ldr r0, [r7, #0x58]
	ldr r6, [sp, #0x10]
	cmp r6, r0
	beq _0802796A
_08027962:
	ldr r0, _08027980 @ =0x0000018F
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0802796A:
	ldr r0, [sp, #8]
_0802796C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802797C: .4byte 0xFFFFE200
_08027980: .4byte 0x0000018F
