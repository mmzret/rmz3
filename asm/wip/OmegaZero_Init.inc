	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _0805D8D8 @ =gBossFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	movs r4, #4
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	ldr r1, _0805D8DC @ =0x083651EC
	ldrb r0, [r7, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r7, #0xd]
	ldrb r0, [r7, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldr r1, _0805D8E0 @ =0x0836512C
	adds r0, r7, #0
	movs r2, #0x60
	bl resetBossData
	ldr r1, _0805D8E4 @ =onCollision
	adds r0, r7, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	subs r0, #0x52
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r7, #0x20]
	ldrb r0, [r7, #0x10]
	str r0, [sp]
	cmp r0, #0
	bne _0805D8C2
	movs r5, #0xa0
	lsls r5, r5, #4
	ldr r1, _0805D8E8 @ =gStaticMotionGraphics
	mov sb, r1
	adds r0, r5, r1
	ldr r2, _0805D8EC @ =wStaticGraphicTilenums
	mov r8, r2
	adds r4, #0xfc
	adds r1, r2, r4
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _0805D8F0 @ =gStaticMotionGraphics+12
	mov sl, r0
	add r5, sl
	ldr r6, _0805D8F4 @ =wStaticMotionPalIDs
	adds r4, r6, r4
	ldrh r1, [r4]
	ldrb r0, [r5, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r5, #0
	bl LoadPalette
	ldr r4, _0805D8F8 @ =0x00001284
	add sb, r4
	movs r5, #0xed
	lsls r5, r5, #1
	add r8, r5
	mov r0, r8
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2, #6]
	lsrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	mov r0, sb
	bl LoadGraphic
	add r4, sl
	adds r6, r6, r5
	ldrh r1, [r6]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	adds r4, r7, #0
	adds r4, #0xb4
	ldr r0, [r7, #0x54]
	asrs r0, r0, #8
	str r0, [r4]
	movs r1, #0xf0
	bl __divsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #0xc
	str r1, [r4]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_08009f6c
	adds r2, r7, #0
	adds r2, #0xb8
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	ldr r1, [sp]
	str r1, [r0]
	adds r3, r7, #0
	adds r3, #0xc5
	ldrb r0, [r3]
	movs r1, #0xff
	orrs r0, r1
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0xc6
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r2]
	str r0, [r7, #0x58]
	movs r0, #0
	movs r1, #8
	bl LoadZeroPalette
	movs r0, #2
	movs r1, #4
	bl SetWeaponElement
_0805D8C2:
	adds r0, r7, #0
	bl OmegaZero_Update
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805D8D8: .4byte gBossFnTable
_0805D8DC: .4byte 0x083651EC
_0805D8E0: .4byte 0x0836512C
_0805D8E4: .4byte onCollision
_0805D8E8: .4byte gStaticMotionGraphics
_0805D8EC: .4byte wStaticGraphicTilenums
_0805D8F0: .4byte gStaticMotionGraphics+12
_0805D8F4: .4byte wStaticMotionPalIDs
_0805D8F8: .4byte 0x00001284
