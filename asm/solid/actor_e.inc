	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start ActorLastFefnir_Update
ActorLastFefnir_Update: @ 0x080D5444
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xa
	bls _080D5450
	b _080D55A2
_080D5450:
	lsls r0, r0, #2
	ldr r1, _080D545C @ =_080D5460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D545C: .4byte _080D5460
_080D5460: @ jump table
	.4byte _080D548C @ case 0
	.4byte _080D54A8 @ case 1
	.4byte _080D5528 @ case 2
	.4byte _080D553A @ case 3
	.4byte _080D5574 @ case 4
	.4byte _080D553A @ case 5
	.4byte _080D5574 @ case 6
	.4byte _080D553A @ case 7
	.4byte _080D5574 @ case 8
	.4byte _080D558C @ case 9
	.4byte _080D559C @ case 10
_080D548C:
	ldr r0, _080D5508 @ =wDynamicGraphicTilenums
	movs r2, #0xa1
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xd0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D550C @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #8
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D54A8:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D55A2
	ldr r1, _080D5510 @ =0x0000A109
	adds r0, r6, #0
	bl SetMotion
	ldr r1, _080D5514 @ =wStaticGraphicTilenums
	adds r1, #0x42
	ldr r0, _080D5518 @ =0x00000327
	strh r0, [r1]
	ldr r5, _080D551C @ =wStaticMotionPalIDs
	adds r5, #0x42
	movs r0, #7
	strh r0, [r5]
	movs r4, #0xa5
	lsls r4, r4, #2
	ldr r2, _080D5520 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5524 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	b _080D5584
	.align 2, 0
_080D5508: .4byte wDynamicGraphicTilenums
_080D550C: .4byte wDynamicMotionPalIDs
_080D5510: .4byte 0x0000A109
_080D5514: .4byte wStaticGraphicTilenums
_080D5518: .4byte 0x00000327
_080D551C: .4byte wStaticMotionPalIDs
_080D5520: .4byte gStaticMotionGraphics
_080D5524: .4byte gStaticMotionGraphics+12
_080D5528:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D55A2
	b _080D5584
_080D553A:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r1, _080D5570 @ =0x0000A10B
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	movs r1, #0x2c
	bl CreateScriptActor
	ldrb r1, [r6, #0xd]
	subs r1, #3
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	strb r1, [r0, #0x11]
	movs r0, #0xf5
	bl PlaySound
	adds r1, r6, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	b _080D5584
	.align 2, 0
_080D5570: .4byte 0x0000A10B
_080D5574:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D55A2
_080D5584:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D55A2
_080D558C:
	movs r1, #0xa1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D559C:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D55A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ActorLastFefnirFireball_Update
ActorLastFefnirFireball_Update: @ 0x080D55A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	ldrb r4, [r5, #0xd]
	cmp r4, #0
	beq _080D55BA
	cmp r4, #1
	beq _080D5614
	b _080D569C
_080D55BA:
	adds r0, r5, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x50
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #6
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	movs r1, #0xf0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080D56A4 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x58]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080D5614:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	movs r6, #0
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _080D565C
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldrb r0, [r5, #0x11]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080D56A8 @ =0x08370D28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
_080D565C:
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080D569C
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r6, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080D56AC @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080D569C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D56A4: .4byte 0xFFFFE200
_080D56A8: .4byte sCollisions_08370C68+(24*8)
_080D56AC: .4byte gSolidFnTable

	thumb_func_start ActorLastLeviathan_Update
ActorLastLeviathan_Update: @ 0x080D56B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xd]
	cmp r0, #0xd
	bls _080D56BE
	b _080D59CC
_080D56BE:
	lsls r0, r0, #2
	ldr r1, _080D56C8 @ =_080D56CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D56C8: .4byte _080D56CC
_080D56CC: @ jump table
	.4byte _080D5704 @ case 0
	.4byte _080D5720 @ case 1
	.4byte _080D5770 @ case 2
	.4byte _080D57C0 @ case 3
	.4byte _080D5810 @ case 4
	.4byte _080D5838 @ case 5
	.4byte _080D5860 @ case 6
	.4byte _080D58A4 @ case 7
	.4byte _080D58CA @ case 8
	.4byte _080D5904 @ case 9
	.4byte _080D5944 @ case 10
	.4byte _080D5974 @ case 11
	.4byte _080D59A4 @ case 12
	.4byte _080D59C6 @ case 13
_080D5704:
	ldr r0, _080D5760 @ =wDynamicGraphicTilenums
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5764 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #7
	strh r1, [r0]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5720:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r0, #1
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #8
	ldr r3, _080D5768 @ =0x08370E10
	movs r1, #1
	mov r2, sp
	bl AppendHazard
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080D5750
	b _080D59CC
_080D5750:
	ldr r1, _080D576C @ =0x0000BD05
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5760: .4byte wDynamicGraphicTilenums
_080D5764: .4byte wDynamicMotionPalIDs
_080D5768: .4byte Rect_08370e10
_080D576C: .4byte 0x0000BD05
_080D5770:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D5786
	b _080D59CC
_080D5786:
	ldr r1, _080D57B8 @ =0x0000BD09
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D57BC @ =0x08370D70
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0x14
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D57B8: .4byte 0x0000BD09
_080D57BC: .4byte sCollisions_08370C68+(24*11)
_080D57C0:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D57D6
	b _080D59CC
_080D57D6:
	ldr r1, _080D5808 @ =0x0000BD0B
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D580C @ =0x08370D88
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5808: .4byte 0x0000BD0B
_080D580C: .4byte sCollisions_08370C68+(24*12)
_080D5810:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D5824
	b _080D59CC
_080D5824:
	ldr r1, _080D5834 @ =0x0000BD0C
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D5834: .4byte 0x0000BD0C
_080D5838:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _080D584E
	b _080D59CC
_080D584E:
	ldr r1, _080D585C @ =0x0000BD14
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	b _080D59BE
	.align 2, 0
_080D585C: .4byte 0x0000BD14
_080D5860:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	beq _080D5876
	b _080D59CC
_080D5876:
	movs r0, #0xf7
	bl PlaySound
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58A0 @ =0x08370DA0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _080D59BE
	.align 2, 0
_080D58A0: .4byte sCollisions_08370C68+(24*13)
_080D58A4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080D58F8 @ =0x08370DB8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D58CA:
	adds r0, r6, #0
	bl UpdateEntityAnim
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D59CC
	ldr r1, _080D58FC @ =0x0000BD10
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0xf6
	bl PlaySound
	movs r0, #0xa0
	lsls r0, r0, #3
	str r0, [r6, #0x5c]
	ldr r0, _080D5900 @ =0xFFFFFEC0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D58F8: .4byte sCollisions_08370C68+(24*14)
_080D58FC: .4byte 0x0000BD10
_080D5900: .4byte 0xFFFFFEC0
_080D5904:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	ldr r2, [r6, #0x60]
	adds r1, r1, r2
	str r1, [r6, #0x58]
	adds r2, #0x40
	str r2, [r6, #0x60]
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	cmp r0, #0
	beq _080D59CC
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D5940 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	movs r0, #0
	str r0, [r6, #0x60]
	b _080D59BE
	.align 2, 0
_080D5940: .4byte 0xFFFFEC00
_080D5944:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D59CC
	movs r1, #0xbd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r6, #0x12]
	b _080D59BE
_080D5974:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D59CC
	ldr r1, _080D59A0 @ =0x0000BD0F
	adds r0, r6, #0
	bl SetMotion
	b _080D59BE
	.align 2, 0
_080D59A0: .4byte 0x0000BD0F
_080D59A4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x5c]
	lsls r1, r0, #3
	subs r1, r1, r0
	asrs r1, r1, #3
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	subs r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #3
	bgt _080D59CC
_080D59BE:
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D59CC
_080D59C6:
	adds r0, r6, #0
	bl UpdateEntityAnim
_080D59CC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ActorLastX_Update
ActorLastX_Update: @ 0x080D59D4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xd]
	cmp r7, #1
	beq _080D5A78
	cmp r7, #1
	bgt _080D59E8
	cmp r7, #0
	beq _080D59EE
	b _080D5AE8
_080D59E8:
	cmp r7, #2
	beq _080D5AB4
	b _080D5AE8
_080D59EE:
	movs r4, #0xfd
	ldr r1, _080D5AA0 @ =wStaticGraphicTilenums
	lsls r2, r4, #1
	adds r1, r1, r2
	ldr r0, _080D5AA4 @ =0x000002B7
	strh r0, [r1]
	ldr r5, _080D5AA8 @ =wStaticMotionPalIDs
	adds r5, r5, r2
	movs r0, #0xa
	strh r0, [r5]
	lsls r4, r4, #4
	movs r0, #0xfd
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, _080D5AAC @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5AB0 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldrh r1, [r5]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	movs r1, #0xfd
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	str r7, [r6, #0x60]
	movs r0, #0x10
	str r0, [r6, #0x68]
	movs r2, #0
	movs r3, #0x10
_080D5A56:
	ldr r0, [r6, #0x60]
	adds r0, r0, r3
	str r0, [r6, #0x60]
	ldr r1, [r6, #0x58]
	subs r1, r1, r0
	str r1, [r6, #0x58]
	lsls r0, r2, #0x10
	movs r4, #0x80
	lsls r4, r4, #9
	adds r0, r0, r4
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x5f
	ble _080D5A56
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
_080D5A78:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r2, r0, r1
	str r2, [r6, #0x58]
	ldr r0, [r6, #0x68]
	subs r1, r1, r0
	str r1, [r6, #0x60]
	cmp r1, #0
	bne _080D5AE8
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	str r2, [r6, #0x68]
	strb r1, [r6, #0x13]
	ldrb r0, [r6, #0xd]
	adds r0, #1
	strb r0, [r6, #0xd]
	b _080D5AE8
	.align 2, 0
_080D5AA0: .4byte wStaticGraphicTilenums
_080D5AA4: .4byte 0x000002B7
_080D5AA8: .4byte wStaticMotionPalIDs
_080D5AAC: .4byte gStaticMotionGraphics
_080D5AB0: .4byte gStaticMotionGraphics+12
_080D5AB4:
	adds r0, r6, #0
	bl UpdateEntityAnim
	ldrb r0, [r6, #0x13]
	adds r2, r0, #1
	strb r2, [r6, #0x13]
	ldr r3, _080D5AF0 @ =gSineTable
	adds r0, #0x81
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r6, #0x68]
	adds r0, r0, r1
	str r0, [r6, #0x58]
_080D5AE8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5AF0: .4byte gSineTable

	thumb_func_start Actor47_Update
Actor47_Update: @ 0x080D5AF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5B32
	cmp r0, #1
	bgt _080D5B08
	cmp r0, #0
	beq _080D5B0E
	b _080D5C08
_080D5B08:
	cmp r0, #2
	beq _080D5BE8
	b _080D5C08
_080D5B0E:
	ldr r0, _080D5B60 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xb6
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r0, _080D5B64 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldr r1, _080D5B68 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5B32:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5B78
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5B6C @ =0x0000C502
	cmp r0, r1
	bne _080D5B70
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5B78
	.align 2, 0
_080D5B60: .4byte wDynamicGraphicTilenums
_080D5B64: .4byte wDynamicMotionPalIDs
_080D5B68: .4byte 0x0000C501
_080D5B6C: .4byte 0x0000C502
_080D5B70:
	ldr r1, _080D5BE0 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5B78:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5BA8
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE0 @ =0x0000C501
	cmp r0, r1
	bne _080D5B9C
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5B9C:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5BBE
_080D5BA8:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5BE4 @ =0x0000C503
	cmp r0, r1
	bne _080D5BBE
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5BBE:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D5C08
	ldrb r0, [r4, #0x1e]
	lsls r1, r0, #8
	ldrb r0, [r5]
	orrs r1, r0
	ldr r0, _080D5BE0 @ =0x0000C501
	cmp r1, r0
	beq _080D5C02
	adds r0, #2
	cmp r1, r0
	bne _080D5C08
	b _080D5C02
	.align 2, 0
_080D5BE0: .4byte 0x0000C501
_080D5BE4: .4byte 0x0000C503
_080D5BE8:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	orrs r1, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0934
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D5C08
_080D5C02:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5C08:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Actor48_Update
Actor48_Update: @ 0x080D5C10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _080D5C20
	cmp r0, #1
	beq _080D5C44
	b _080D5C4A
_080D5C20:
	ldr r0, _080D5C50 @ =wDynamicGraphicTilenums
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5C54 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #4
	strh r1, [r0]
	ldr r1, _080D5C58 @ =0x0000B31D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5C44:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D5C4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D5C50: .4byte wDynamicGraphicTilenums
_080D5C54: .4byte wDynamicMotionPalIDs
_080D5C58: .4byte 0x0000B31D

	thumb_func_start FUN_080d5c5c
FUN_080d5c5c: @ 0x080D5C5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _080D5D18
	lsls r0, r0, #2
	ldr r1, _080D5C70 @ =_080D5C74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5C70: .4byte _080D5C74
_080D5C74: @ jump table
	.4byte _080D5C88 @ case 0
	.4byte _080D5CB8 @ case 1
	.4byte _080D5CE0 @ case 2
	.4byte _080D5CF8 @ case 3
	.4byte _080D5D12 @ case 4
_080D5C88:
	ldr r0, _080D5CD4 @ =wDynamicGraphicTilenums
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5CD8 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #5
	strh r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5CB8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D5D18
	ldr r1, _080D5CDC @ =0x0000BE20
	adds r0, r4, #0
	bl SetMotion
	b _080D5CF0
	.align 2, 0
_080D5CD4: .4byte wDynamicGraphicTilenums
_080D5CD8: .4byte wDynamicMotionPalIDs
_080D5CDC: .4byte 0x0000BE20
_080D5CE0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5D18
_080D5CF0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5D18
_080D5CF8:
	movs r1, #0xbe
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D12:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080D5D18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d5d20
FUN_080d5d20: @ 0x080D5D20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _080D5D56
	cmp r0, #1
	bgt _080D5D34
	cmp r0, #0
	beq _080D5D3A
	b _080D5DFA
_080D5D34:
	cmp r0, #2
	beq _080D5D7C
	b _080D5DFA
_080D5D3A:
	ldr r0, _080D5D70 @ =wDynamicGraphicTilenums
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r0, _080D5D74 @ =wDynamicMotionPalIDs
	adds r0, r0, r2
	movs r1, #6
	strh r1, [r0]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5D56:
	ldr r1, _080D5D78 @ =0x0000C501
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080d0aa0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D5DFA
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5DFA
	.align 2, 0
_080D5D70: .4byte wDynamicGraphicTilenums
_080D5D74: .4byte wDynamicMotionPalIDs
_080D5D78: .4byte 0x0000C501
_080D5D7C:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r5, r4, #0
	adds r5, #0x70
	cmp r0, #3
	bne _080D5DB4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5DA8 @ =0x0000C502
	cmp r0, r1
	bne _080D5DAC
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5DB4
	.align 2, 0
_080D5DA8: .4byte 0x0000C502
_080D5DAC:
	ldr r1, _080D5E00 @ =0x0000C501
	adds r0, r4, #0
	bl SetMotion
_080D5DB4:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080D5DE4
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E00 @ =0x0000C501
	cmp r0, r1
	bne _080D5DD8
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DD8:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080D5DFA
_080D5DE4:
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #8
	ldrb r1, [r5]
	orrs r0, r1
	ldr r1, _080D5E04 @ =0x0000C503
	cmp r0, r1
	bne _080D5DFA
	adds r1, #1
	adds r0, r4, #0
	bl SetMotion
_080D5DFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E00: .4byte 0x0000C501
_080D5E04: .4byte 0x0000C503

	thumb_func_start FUN_080d5e08
FUN_080d5e08: @ 0x080D5E08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #9
	bls _080D5E14
	b _080D5FC0
_080D5E14:
	lsls r0, r0, #2
	ldr r1, _080D5E20 @ =_080D5E24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5E20: .4byte _080D5E24
_080D5E24: @ jump table
	.4byte _080D5E4C @ case 0
	.4byte _080D5E7A @ case 1
	.4byte _080D5E8E @ case 2
	.4byte _080D5ED4 @ case 3
	.4byte _080D5F18 @ case 4
	.4byte _080D5F34 @ case 5
	.4byte _080D5F56 @ case 6
	.4byte _080D5F78 @ case 7
	.4byte _080D5FA0 @ case 8
	.4byte _080D5FB8 @ case 9
_080D5E4C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080D5ED0 @ =0x00003503
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E7A:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D5E88
	b _080D5FC0
_080D5E88:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_080D5E8E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D5EA2
	b _080D5FC0
_080D5EA2:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r1, #1
	ands r2, r1
	movs r1, #0
	bl CreateParticle
	movs r0, #8
	bl PlaySound
	movs r0, #0
	str r0, [r4, #0x2c]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	b _080D5FB0
	.align 2, 0
_080D5ED0: .4byte 0x00003503
_080D5ED4:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _080D5EE8
	adds r0, r4, #0
	bl CreateAfterImages
	str r0, [r4, #0x2c]
_080D5EE8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080D5F08
	movs r0, #1
	strb r0, [r1, #0x11]
_080D5F08:
	ldr r1, _080D5F14 @ =0x00000301
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F14: .4byte 0x00000301
_080D5F18:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D5FC0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F34:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D5FC0
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x2a
	strb r0, [r4, #0x12]
	b _080D5FB0
_080D5F56:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D5FC0
	movs r1, #0xd0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
_080D5F78:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D5FC0
	movs r0, #0x9a
	bl PlaySound
	ldr r1, _080D5F9C @ =0x00003401
	adds r0, r4, #0
	bl SetMotion
	b _080D5FB0
	.align 2, 0
_080D5F9C: .4byte 0x00003401
_080D5FA0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D5FC0
_080D5FB0:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
	b _080D5FC0
_080D5FB8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
_080D5FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start omega1_080d5fc8
omega1_080d5fc8: @ 0x080D5FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0xa
	bls _080D5FDC
	b _080D6446
_080D5FDC:
	lsls r0, r0, #2
	ldr r1, _080D5FE8 @ =_080D5FEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5FE8: .4byte _080D5FEC
_080D5FEC: @ jump table
	.4byte _080D6018 @ case 0
	.4byte _080D60DC @ case 1
	.4byte _080D6114 @ case 2
	.4byte _080D6130 @ case 3
	.4byte _080D6186 @ case 4
	.4byte _080D62A4 @ case 5
	.4byte _080D62E8 @ case 6
	.4byte _080D6302 @ case 7
	.4byte _080D6338 @ case 8
	.4byte _080D6370 @ case 9
	.4byte _080D63A8 @ case 10
_080D6018:
	movs r1, #0x85
	lsls r1, r1, #2
	ldr r0, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r0, #0x16]
	ldr r2, _080D60FC @ =wStaticMotionPalIDs
	mov sl, r2
	movs r0, #5
	strh r0, [r2, #0x16]
	ldr r5, _080D6100 @ =gStaticMotionGraphics
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	mov sb, r2
	add r1, sb
	bl LoadGraphic
	ldr r4, _080D6104 @ =gStaticMotionGraphics+12
	adds r0, r4, #0
	adds r0, #0xdc
	mov r2, sl
	ldrh r1, [r2, #0x16]
	ldrb r2, [r0, #7]
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	add r1, r8
	bl LoadPalette
	movs r0, #0xa
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r2, _080D60F8 @ =wStaticGraphicTilenums
	strh r1, [r2, #0x14]
	mov r2, sl
	strh r0, [r2, #0x14]
	adds r5, #0xc8
	ldrh r0, [r5, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, sb
	adds r0, r5, #0
	bl LoadGraphic
	adds r4, #0xc8
	mov r0, sl
	ldrh r1, [r0, #0x14]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	bl LoadPalette
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	ldr r1, _080D6108 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, [r7, #0x54]
	str r1, [r7, #0x64]
	str r0, [r7, #0x68]
	adds r0, r7, #0
	movs r1, #0x35
	bl CreateScriptActor
	adds r0, r7, #0
	movs r1, #0x36
	bl CreateScriptActor
	adds r0, r7, #0
	bl FUN_0800f894
	ldr r0, _080D610C @ =gOverworld
	ldr r2, _080D6110 @ =0x0002D026
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	strb r0, [r7, #0x12]
	strb r0, [r7, #0x11]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D60DC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D60F2
	b _080D6446
_080D60F2:
	strb r2, [r7, #0xe]
	b _080D6398
	.align 2, 0
_080D60F8: .4byte wStaticGraphicTilenums
_080D60FC: .4byte wStaticMotionPalIDs
_080D6100: .4byte gStaticMotionGraphics
_080D6104: .4byte gStaticMotionGraphics+12
_080D6108: .4byte 0xFFFFFE80
_080D610C: .4byte gOverworld
_080D6110: .4byte 0x0002D026
_080D6114:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080D612A
	b _080D6446
_080D612A:
	strb r2, [r7, #0xe]
	movs r0, #6
	b _080D6396
_080D6130:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080D6146
	b _080D6446
_080D6146:
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #8
	adds r1, r4, #0
	bl AppendQuake
	movs r0, #0x8d
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl CreateVFX39
	str r0, [r7, #0x28]
	adds r0, #0x7c
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x74
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x75
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	adds r0, #0x76
	strb r5, [r0]
	ldr r0, [r7, #0x28]
	str r5, [r0, #0x78]
	strb r5, [r7, #0x12]
	strb r5, [r7, #0x13]
	b _080D6398
_080D6186:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _080D619E
	movs r0, #0x7e
	strb r0, [r7, #0x13]
_080D619E:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D61F8
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bls _080D61CC
	ldr r0, _080D61D8 @ =0x00000135
	bl PlaySound
	movs r0, #0x8a
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl StartPaletteAnimation
	movs r0, #0x8b
	lsls r0, r0, #1
	movs r1, #0xe0
	bl StartPaletteAnimation
_080D61CC:
	ldrb r0, [r7, #0x12]
	cmp r0, #8
	bls _080D61DC
	subs r0, #8
	b _080D6200
	.align 2, 0
_080D61D8: .4byte 0x00000135
_080D61DC:
	ldr r1, [r7, #0x28]
	cmp r1, #0
	beq _080D61E8
	adds r1, #0x77
	movs r0, #1
	strb r0, [r1]
_080D61E8:
	movs r0, #0
	str r0, [r7, #0x28]
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6202
_080D61F8:
	ldrb r0, [r7, #0x12]
	cmp r0, #0x3f
	bhi _080D6202
	adds r0, #0x10
_080D6200:
	strb r0, [r7, #0x12]
_080D6202:
	ldr r3, [r7, #0x28]
	cmp r3, #0
	beq _080D627A
	ldrb r1, [r7, #0x13]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6254
	cmp r1, #3
	bls _080D6232
	ldr r2, _080D6244 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080D6248 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080D624C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	cmp r0, #0
	bne _080D6254
_080D6232:
	ldr r0, _080D6250 @ =gSineTable
	ldrb r1, [r7, #0x12]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #6
	str r0, [r3, #0x78]
	b _080D627A
	.align 2, 0
_080D6244: .4byte RNG_0202f388
_080D6248: .4byte 0x000343FD
_080D624C: .4byte 0x00269EC3
_080D6250: .4byte gSineTable
_080D6254:
	ldr r1, _080D62A0 @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	str r0, [r3, #0x78]
	ldr r2, [r7, #0x28]
	ldrb r0, [r7, #0x13]
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #0xb
	ldr r0, [r2, #0x78]
	adds r0, r0, r1
	str r0, [r2, #0x78]
_080D627A:
	movs r0, #0x8a
	lsls r0, r0, #1
	bl StepPaletteAnimation
	movs r0, #0x8b
	lsls r0, r0, #1
	bl StepPaletteAnimation
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080D6298
	b _080D6446
_080D6298:
	ldr r0, [r7, #0x64]
	subs r0, #8
	b _080D6444
	.align 2, 0
_080D62A0: .4byte gSineTable
_080D62A4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62B4
	subs r0, #1
	strb r0, [r7, #0x13]
_080D62B4:
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r0, r5, #0
	bl StepPaletteAnimation
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r0, r4, #0
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _080D62D2
	b _080D6446
_080D62D2:
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D62DA
	b _080D6446
_080D62DA:
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	b _080D6398
_080D62E8:
	movs r0, #0x88
	lsls r0, r0, #1
	movs r1, #0xa8
	lsls r1, r1, #2
	bl StartPaletteAnimation
	ldr r0, _080D6334 @ =0x00000117
	movs r1, #0xe0
	bl StartPaletteAnimation
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6302:
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r5, #0
	bl StepPaletteAnimation
	ldr r4, _080D6334 @ =0x00000117
	adds r0, r4, #0
	bl StepPaletteAnimation
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _080D6324
	b _080D6446
_080D6324:
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	b _080D6398
	.align 2, 0
_080D6334: .4byte 0x00000117
_080D6338:
	ldr r5, _080D63A0 @ =0x0000010F
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r5, #0
	bl StartPaletteAnimation
	ldr r4, _080D63A4 @ =0x00000115
	adds r0, r4, #0
	movs r1, #0xe0
	bl StartPaletteAnimation
	adds r0, r5, #0
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl StepPaletteAnimation
	adds r0, r5, #0
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl RemovePaletteAnimation
	movs r0, #0x3c
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D6370:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r2, r0, #0
	cmp r2, #0
	bne _080D63B4
	movs r0, #3
	strb r0, [r7, #0xe]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6446
	movs r0, #4
	strb r0, [r7, #0xe]
	str r2, [r7, #0x5c]
	movs r0, #0x1e
_080D6396:
	strb r0, [r7, #0x13]
_080D6398:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D6446
	.align 2, 0
_080D63A0: .4byte 0x0000010F
_080D63A4: .4byte 0x00000115
_080D63A8:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _080D63BA
_080D63B4:
	subs r0, #1
	strb r0, [r7, #0x13]
	b _080D6446
_080D63BA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080D63DA
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x1e
	bl CreateOmegaWhiteHoop
_080D63DA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D63FA
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x28
	bl CreateOmegaWhiteHoop
_080D63FA:
	ldr r2, [r7, #0x18]
	ldrb r1, [r2, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080D641A
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #9]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	ldr r2, _080D6430 @ =0xFFFF9C00
	adds r1, r1, r2
	movs r2, #0x32
	bl CreateOmegaWhiteHoop
_080D641A:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080D6434
	ldr r0, [r7, #0x5c]
	cmp r0, #0x5f
	bgt _080D643E
	adds r0, #8
	b _080D643C
	.align 2, 0
_080D6430: .4byte 0xFFFF9C00
_080D6434:
	ldr r0, [r7, #0x5c]
	cmp r0, #0
	beq _080D643E
	subs r0, #4
_080D643C:
	str r0, [r7, #0x5c]
_080D643E:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
_080D6444:
	str r0, [r7, #0x64]
_080D6446:
	ldrb r0, [r7, #0x11]
	adds r0, #1
	strb r0, [r7, #0x11]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D645A
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080D6460
_080D645A:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080D6460:
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0xd]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080D6490
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	ldr r0, [r7, #0x64]
	str r0, [r7, #0x54]
	ldr r1, _080D648C @ =gSineTable
	ldrb r0, [r7, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _080D64E0
	.align 2, 0
_080D648C: .4byte gSineTable
_080D6490:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl AppendQuake
	ldr r0, _080D64F0 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r5, _080D64F4 @ =0x000343FD
	muls r0, r5, r0
	ldr r3, _080D64F8 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ldr r4, _080D64FC @ =0x000001FF
	ands r0, r4
	ldr r1, [r7, #0x64]
	adds r6, r1, r0
	str r6, [r7, #0x54]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x28]
	cmp r2, #0
	beq _080D64E0
	str r6, [r2, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, _080D6500 @ =0xFFFFC000
	adds r0, r0, r1
	str r0, [r2, #0x58]
_080D64E0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D64F0: .4byte RNG_0202f388
_080D64F4: .4byte 0x000343FD
_080D64F8: .4byte 0x00269EC3
_080D64FC: .4byte 0x000001FF
_080D6500: .4byte 0xFFFFC000
