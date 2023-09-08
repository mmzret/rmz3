	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08017B38 @ =gStaticMotionGraphics
	ldr r0, [r4]
	movs r1, #0x14
	bl __udivsi3
	lsls r0, r0, #0x10
	ldr r1, _08017B3C @ =0xFFFF0000
	adds r0, r0, r1
	cmp r0, #0
	blt _08017AF0
	ldr r7, _08017B40 @ =wStaticGraphicTilenums
	ldr r6, _08017B44 @ =wStaticMotionPalIDs
	adds r5, r4, #0
_08017ACA:
	asrs r2, r0, #0x10
	lsls r3, r2, #1
	adds r4, r3, r7
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r0, r1, r5
	ldrh r0, [r0, #6]
	lsrs r0, r0, #6
	strh r0, [r4]
	adds r3, r3, r6
	ldr r0, _08017B48 @ =gStaticMotionGraphics+12
	adds r1, r1, r0
	ldrb r0, [r1, #7]
	strh r0, [r3]
	subs r2, #1
	lsls r0, r2, #0x10
	cmp r0, #0
	bge _08017ACA
_08017AF0:
	ldr r1, _08017B4C @ =gDynamicMotionGraphicOffsets
	ldr r0, [r1]
	lsls r0, r0, #0xe
	asrs r0, r0, #0x10
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r0, r6, #0x10
	cmp r0, #0
	blt _08017B7E
	ldr r2, _08017B50 @ =wDynamicGraphicTilenums
	mov sb, r2
	mov r8, r1
	movs r1, #0
	mov ip, r1
	ldr r7, _08017B54 @ =wDynamicMotionPalIDs
_08017B10:
	asrs r2, r0, #0x10
	lsls r3, r2, #1
	mov r1, sb
	adds r0, r3, r1
	lsls r4, r2, #2
	mov r1, r8
	adds r5, r4, r1
	ldr r1, [r5]
	adds r1, r4, r1
	add r1, r8
	ldrh r1, [r1, #6]
	lsrs r1, r1, #6
	strh r1, [r0]
	cmp r2, #0x4f
	bgt _08017B58
	adds r0, r3, r7
	mov r2, ip
	strh r2, [r0]
	b _08017B70
	.align 2, 0
_08017B38: .4byte gStaticMotionGraphics
_08017B3C: .4byte 0xFFFF0000
_08017B40: .4byte wStaticGraphicTilenums
_08017B44: .4byte wStaticMotionPalIDs
_08017B48: .4byte gStaticMotionGraphics+12
_08017B4C: .4byte gDynamicMotionGraphicOffsets
_08017B50: .4byte wDynamicGraphicTilenums
_08017B54: .4byte wDynamicMotionPalIDs
_08017B58:
	cmp r2, #0x8f
	bgt _08017B62
	adds r0, r3, r7
	mov r1, ip
	b _08017B6E
_08017B62:
	adds r0, r3, r7
	ldr r1, [r5]
	adds r1, r4, r1
	ldr r2, _08017B8C @ =0x083B8C98
	adds r1, r1, r2
	ldrb r1, [r1, #7]
_08017B6E:
	strh r1, [r0]
_08017B70:
	lsls r0, r6, #0x10
	ldr r1, _08017B90 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	lsls r0, r6, #0x10
	cmp r0, #0
	bge _08017B10
_08017B7E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017B8C: .4byte gDynamicMotionGraphicOffsets+(4*3)
_08017B90: .4byte 0xFFFF0000
