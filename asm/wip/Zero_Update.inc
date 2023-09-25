	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r1, [r6, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080292E6
	adds r0, r6, #0
	bl resetSateliteElfPosition
_080292E6:
	ldr r2, _08029304 @ =0x00000233
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08029308
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080292FC
	b _080299C8
_080292FC:
	movs r0, #0x21
	bl PlaySound
	b _080299C8
	.align 2, 0
_08029304: .4byte 0x00000233
_08029308:
	adds r4, r6, #0
	adds r4, #0xfa
	movs r3, #0
	ldrsh r1, [r4, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08029344
	ldrb r0, [r6, #0xd]
	cmp r0, #0xb
	beq _0802935E
	ldr r0, _08029338 @ =gOverworld
	ldr r7, _0802933C @ =0x0002C00C
	adds r0, r0, r7
	ldr r1, [r6, #0x58]
	ldr r2, _08029340 @ =0xFFFFE200
	adds r1, r1, r2
	ldr r0, [r0]
	cmp r0, r1
	bge _0802935E
	movs r0, #0x32
	bl PlaySound
	b _0802935C
	.align 2, 0
_08029338: .4byte gOverworld
_0802933C: .4byte 0x0002C00C
_08029340: .4byte 0xFFFFE200
_08029344:
	ldr r0, _080293A8 @ =gOverworld
	ldr r3, _080293AC @ =0x0002C00C
	adds r0, r0, r3
	ldr r1, [r0]
	ldr r0, [r6, #0x58]
	cmp r1, r0
	ble _0802935E
	movs r7, #0
	ldrsh r0, [r4, r7]
	bl stopSound
	ldr r0, _080293B0 @ =0x0000FFFF
_0802935C:
	strh r0, [r4]
_0802935E:
	ldrb r0, [r6, #0xd]
	adds r5, r6, #0
	adds r5, #0xe8
	strb r0, [r5]
	ldrb r0, [r6, #0xe]
	adds r4, r6, #0
	adds r4, #0xe9
	strb r0, [r4]
	adds r0, r6, #0
	bl HandlePlayerInput
	adds r0, r6, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r1, [r0, r2]
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	mov r8, r0
	ldr r3, _080293B4 @ =0x00000147
	adds r5, r6, r3
	cmp r1, #0
	beq _08029434
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r0, _080293B8 @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r6, #0
	bl RecoilFromFloor
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080293BC
	adds r0, r6, #0
	bl InstantlyKilling
	b _080293DE
	.align 2, 0
_080293A8: .4byte gOverworld
_080293AC: .4byte 0x0002C00C
_080293B0: .4byte 0x0000FFFF
_080293B4: .4byte 0x00000147
_080293B8: .4byte gZeroRanges
_080293BC:
	cmp r0, #2
	bne _080293DE
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r7, #0x8c
	lsls r7, r7, #1
	adds r1, r6, r7
	strb r0, [r1]
	movs r1, #0
	movs r0, #0
	mov r2, r8
	strh r0, [r2]
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_080293DE:
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	beq _08029434
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r0, _08029420 @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r6, #0
	bl RecoilFromHazards
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08029424
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	mov r3, r8
	strh r2, [r3]
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _0802942E
	.align 2, 0
_08029420: .4byte gZeroRanges
_08029424:
	cmp r0, #2
	bne _0802942E
	adds r0, r6, #0
	bl InstantlyKilling
_0802942E:
	adds r0, r6, #0
	bl CheckZeroHazard
_08029434:
	ldrb r0, [r6, #0xd]
	movs r7, #0xb4
	adds r7, r7, r6
	mov sl, r7
	cmp r0, #1
	beq _08029448
	cmp r0, #4
	beq _08029448
	movs r0, #0
	str r0, [r7, #0x54]
_08029448:
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08029458
	subs r0, #1
	b _08029476
_08029458:
	ldr r0, _0802957C @ =gOverworld
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #7
	bne _08029478
	bl FUN_080101a8
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08029478
	movs r0, #0x10
_08029476:
	strb r0, [r4]
_08029478:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r0, [r6, #0x1e]
	lsls r0, r0, #8
	adds r1, r6, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	movs r7, #0x9f
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r2, #0
	mov sb, r2
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x71
	ldrb r1, [r0]
	adds r3, #0x40
	adds r0, r6, r3
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x72
	ldrb r0, [r0]
	adds r7, #3
	adds r1, r6, r7
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r2, r6, r1
	strb r0, [r2]
	mov r3, sb
	strb r3, [r5]
	ldr r1, [r6, #0xc]
	ldr r0, _08029580 @ =0x00FFFF00
	ands r1, r0
	str r2, [sp, #0x14]
	movs r7, #0x80
	lsls r7, r7, #3
	cmp r1, r7
	beq _080294DA
	ldr r1, _08029584 @ =0x0000018D
	adds r0, r6, r1
	strb r3, [r0]
_080294DA:
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, sb
	strb r3, [r0]
	mov r7, r8
	movs r2, #0
	ldrsh r1, [r7, r2]
	str r0, [sp, #0x10]
	cmp r1, #0
	beq _080295D2
	ldrb r1, [r6, #0xd]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080295D2
	cmp r1, #0xa
	beq _080295D2
	ldr r7, _08029588 @ =gZeroRanges
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r7
	movs r3, #6
	ldrsh r1, [r0, r3]
	ldr r2, [r6, #0x58]
	subs r1, r2, r1
	ldr r4, _0802958C @ =0xFFFFF800
	adds r1, r1, r4
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r1, r0
	bgt _0802954A
	ldr r0, [r6, #0x54]
	adds r1, r2, #0
	bl IsVoidSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080295D2
	ldr r0, [r6, #0x54]
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r7
	movs r7, #6
	ldrsh r2, [r1, r7]
	ldr r1, [r6, #0x58]
	subs r1, r1, r2
	adds r1, r1, r4
	bl IsVoidSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080295D2
_0802954A:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, _08029590 @ =0xFFFFE200
	adds r1, r1, r2
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0
	beq _08029594
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r6, r3
	strb r0, [r1]
	movs r0, #0
	mov r7, r8
	strh r0, [r7]
	b _080295CA
	.align 2, 0
_0802957C: .4byte gOverworld
_08029580: .4byte 0x00FFFF00
_08029584: .4byte 0x0000018D
_08029588: .4byte gZeroRanges
_0802958C: .4byte 0xFFFFF800
_08029590: .4byte 0xFFFFE200
_08029594:
	mov r1, sl
	ldrb r0, [r1]
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080295AC
	ldrb r0, [r1, #1]
	cmp r0, #0x20
	beq _080295AC
	cmp r0, #0x21
	bne _080295B6
_080295AC:
	movs r1, #0
	movs r0, #8
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _080295D2
_080295B6:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r6, r3
	strb r0, [r1]
	mov r7, r8
	strh r2, [r7]
_080295CA:
	movs r0, #4
	strb r0, [r6, #0xd]
	mov r0, sb
	strb r0, [r6, #0xe]
_080295D2:
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrb r1, [r2]
	cmp r1, #0
	beq _080295F0
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080295EE
	movs r0, #0x80
	eors r0, r1
_080295EE:
	strb r0, [r2]
_080295F0:
	ldr r1, _080296C8 @ =sHandlePlayerInputs
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r2, _080296CC @ =0x00000113
	adds r0, r6, r2
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _0802965E
	mov r3, sl
	ldr r0, [r3, #0x60]
	ldr r1, [r6, #0x58]
	cmp r0, r1
	bhs _0802964C
	ldr r0, [r6, #0x54]
	bl GetGroundMetatileAttr
	movs r1, #0x80
	lsls r1, r1, #8
	ands r1, r0
	cmp r1, #0
	beq _08029648
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl GetGroundMetatileAttr
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _08029648
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl GetGroundMetatileAttr
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0xe
	bls _0802964C
_08029648:
	movs r0, #0
	strb r0, [r7]
_0802964C:
	mov r1, sl
	ldr r0, [r1, #0x60]
	ldr r2, _080296D0 @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r6, #0x58]
	cmp r0, r1
	bls _0802965E
	movs r0, #0
	strb r0, [r7]
_0802965E:
	ldrb r0, [r6, #0xd]
	cmp r0, #7
	beq _0802966C
	ldr r3, _080296D4 @ =0x00000143
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
_0802966C:
	ldrb r0, [r6, #0xd]
	cmp r0, #4
	beq _08029682
	mov r7, r8
	movs r0, #0
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bne _08029682
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
_08029682:
	ldr r1, _080296D8 @ =sZeroUpdates
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	movs r2, #0x97
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r3, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	adds r4, r2, #0
	ldr r1, _080296DC @ =0x00000125
	adds r2, r6, r1
	cmp r0, #0
	beq _080296FE
	ldrb r0, [r6, #0xd]
	ldr r7, [sp, #8]
	ldrb r7, [r7]
	cmp r0, r7
	beq _080296E0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080296F4
	b _080296F8
	.align 2, 0
_080296C8: .4byte sHandlePlayerInputs
_080296CC: .4byte 0x00000113
_080296D0: .4byte 0xFFFFE000
_080296D4: .4byte 0x00000143
_080296D8: .4byte sZeroUpdates
_080296DC: .4byte 0x00000125
_080296E0:
	cmp r0, #0
	bne _080296FE
	ldrb r0, [r6, #0xe]
	ldr r1, [sp, #0xc]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080296FE
	ldrb r0, [r2]
	cmp r0, #0
	beq _080296F8
_080296F4:
	movs r3, #1
	b _080296FE
_080296F8:
	adds r0, r6, #0
	adds r0, #0xec
	strb r3, [r0]
_080296FE:
	ldrb r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	strb r0, [r4]
	movs r0, #0
	strb r0, [r2]
	lsls r2, r3, #6
	ldrb r1, [r4]
	subs r0, #0x41
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _080297BC @ =0x00000127
	adds r1, r6, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r7, _080297C0 @ =0x0000013B
	adds r1, r6, r7
	ldrb r0, [r1]
	cmp r0, #0
	beq _08029748
	subs r0, #1
	strb r0, [r1]
_08029748:
	ldrb r0, [r5]
	ldr r1, _080297C4 @ =0x00000216
	adds r7, r6, r1
	cmp r0, #1
	bne _08029774
	ldrh r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08029774
	mov r2, sl
	ldrb r0, [r2, #0x11]
	cmp r0, #3
	beq _0802976A
	cmp r0, #7
	bne _08029774
_0802976A:
	ldr r3, [sp, #0x14]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08029774
	strb r0, [r5]
_08029774:
	ldrb r0, [r6, #0xd]
	cmp r0, #3
	bhi _080297D0
	ldr r0, _080297C8 @ =sZeroAttacks
	ldrb r1, [r6, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r0, _080297CC @ =0x00000232
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080297D8
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080297D8
	strb r0, [r1]
	mov r2, sl
	ldrb r1, [r2]
	adds r0, r6, #0
	movs r2, #0
	bl CreateSateliteElf
	mov r3, sl
	ldrb r1, [r3, #1]
	adds r0, r6, #0
	movs r2, #1
	bl CreateSateliteElf
	b _080297D8
	.align 2, 0
_080297BC: .4byte 0x00000127
_080297C0: .4byte 0x0000013B
_080297C4: .4byte 0x00000216
_080297C8: .4byte sZeroAttacks
_080297CC: .4byte 0x00000232
_080297D0:
	adds r1, r6, #0
	adds r1, #0xec
	movs r0, #0
	strb r0, [r1]
_080297D8:
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4]
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	ldrb r2, [r5]
	cmp r0, r2
	beq _08029836
	adds r0, r6, #0
	adds r0, #0x74
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08029820 @ =gZeroCollisions
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5]
	cmp r0, #3
	bne _08029824
	adds r0, r6, #0
	bl GetZeroColor
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl LoadShadowDashPalette
	b _08029836
	.align 2, 0
_08029820: .4byte gZeroCollisions
_08029824:
	adds r0, r6, #0
	bl GetZeroColor
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl LoadZeroPalette
_08029836:
	ldrb r1, [r6, #0xd]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08029882
	cmp r1, #0xa
	beq _08029882
	ldrb r1, [r5]
	lsls r1, r1, #3
	ldr r0, _080298C0 @ =gZeroRanges
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #1
	bl PushoutByBorder
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08029882
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	mov r0, r8
	strh r2, [r0]
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	ldr r1, [sp]
	ldr r2, [sp, #4]
	str r1, [r6, #0x54]
	str r2, [r6, #0x58]
_08029882:
	ldr r2, _080298C4 @ =0x0000011B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080298DC
	ldr r1, _080298C0 @ =gZeroRanges
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	ldr r3, [r6, #0x58]
	subs r2, r3, r0
	ldr r0, _080298C8 @ =gOverworld
	ldr r1, _080298CC @ =0x0002C00C
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r2, r1
	ble _080298D0
	movs r2, #6
	ldrsh r0, [r4, r2]
	subs r2, r3, r0
	cmp r2, r1
	bge _080298DC
	adds r0, r6, #0
	movs r1, #1
	bl CreateRipple
	b _080298DC
	.align 2, 0
_080298C0: .4byte gZeroRanges
_080298C4: .4byte 0x0000011B
_080298C8: .4byte gOverworld
_080298CC: .4byte 0x0002C00C
_080298D0:
	cmp r3, r1
	ble _080298DC
	adds r0, r6, #0
	movs r1, #0
	bl CreateRipple
_080298DC:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08029942
	mov r7, r8
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq _08029942
	ldr r1, [r6, #0x54]
	ldr r3, [sp]
	subs r2, r3, r1
	cmp r2, #0
	blt _08029910
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r2, r0
	bgt _0802991C
	b _08029942
_08029910:
	ldr r7, [sp]
	subs r1, r1, r7
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _08029942
_0802991C:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	mov r3, r8
	strh r2, [r3]
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
_08029942:
	ldr r1, _0802996C @ =0x0000018F
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080299A2
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _080299A2
	ldr r1, [r6, #0x58]
	ldr r7, [sp, #4]
	subs r2, r7, r1
	cmp r2, #0
	blt _08029970
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r2, r0
	bgt _0802997C
	b _080299A2
	.align 2, 0
_0802996C: .4byte 0x0000018F
_08029970:
	ldr r0, [sp, #4]
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080299A2
_0802997C:
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	mov r3, r8
	strh r2, [r3]
	movs r0, #4
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
_080299A2:
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne _080299B0
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080299B0:
	adds r0, r6, #0
	bl setStageElfFlags
	ldr r2, _080299D8 @ =0x00000149
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r3, [sp]
	subs r0, r0, r3
	mov r7, sl
	str r0, [r7, #0x58]
_080299C8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080299D8: .4byte 0x00000149
