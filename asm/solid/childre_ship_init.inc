	.include "asm/macros.inc"

	.syntax unified
	
	.text

	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080E0390 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080E03D8
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	beq _080E02F2
	ldr r0, _080E0394 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bgt _080E03D8
_080E02F2:
	ldrb r1, [r6, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	movs r1, #0xb4
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x25
	strb r5, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080E0398 @ =0x083719D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r1, [r6, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xb]
	ldrb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	movs r4, #0xe1
	lsls r4, r4, #4
	ldr r1, _080E039C @ =gStaticMotionGraphics
	adds r0, r4, r1
	ldr r1, _080E03A0 @ =wStaticGraphicTilenums
	movs r5, #0xb4
	lsls r5, r5, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080E03A4 @ =gStaticMotionGraphics+12
	adds r4, r4, r0
	ldr r0, _080E03A8 @ =wStaticMotionPalIDs
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r4, #7]
	subs r1, r1, r0
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r0, r4, #0
	bl LoadPalette
	ldrb r1, [r6, #0x10]
	cmp r1, #0
	bne _080E03AC
	str r1, [r6, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r6, #0x68]
	str r1, [r6, #0x64]
	b _080E03BA
	.align 2, 0
_080E0390: .4byte gCurStory
_080E0394: .4byte pZero2
_080E0398: .4byte 0x083719D0
_080E039C: .4byte gStaticMotionGraphics
_080E03A0: .4byte wStaticGraphicTilenums
_080E03A4: .4byte gStaticMotionGraphics+12
_080E03A8: .4byte wStaticMotionPalIDs
_080E03AC:
	movs r0, #0x80
	str r0, [r6, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [r6, #0x68]
	movs r0, #3
	str r0, [r6, #0x64]
_080E03BA:
	movs r0, #0
	strb r0, [r6, #0x12]
	movs r2, #1
	strb r2, [r6, #0x13]
	movs r0, #0x96
	lsls r0, r0, #2
	str r0, [r6, #0x60]
	ldr r1, _080E03E0 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
_080E03D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E03E0: .4byte gSolidFnTable
