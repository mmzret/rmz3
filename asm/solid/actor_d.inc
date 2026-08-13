	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Actor41_Update
Actor41_Update: @ 0x080D4F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #4
	bls _080D4F14
	b _080D50D2
_080D4F14:
	lsls r0, r0, #2
	ldr r1, _080D4F20 @ =_080D4F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4F20: .4byte _080D4F24
_080D4F24: @ jump table
	.4byte _080D4F38 @ case 0
	.4byte _080D4FAC @ case 1
	.4byte _080D5008 @ case 2
	.4byte _080D5036 @ case 3
	.4byte _080D505C @ case 4
_080D4F38:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x5c]
	ldr r0, [r7, #0x58]
	str r0, [r7, #0x60]
	ldr r1, _080D4FF0 @ =0xFFFFB800
	adds r0, r0, r1
	str r0, [r7, #0x68]
	ldr r0, _080D4FF4 @ =wStaticGraphicTilenums
	adds r0, #0xa2
	movs r6, #0
	movs r1, #0x8c
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r5, _080D4FF8 @ =wStaticMotionPalIDs
	adds r5, #0xa2
	movs r0, #5
	strh r0, [r5]
	ldr r4, _080D4FFC @ =0x00000654
	ldr r2, _080D5000 @ =gStaticMotionGraphics
	adds r0, r4, r2
	ldrh r2, [r0, #6]
	lsrs r2, r2, #6
	subs r1, r1, r2
	lsls r1, r1, #5
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	bl LoadGraphic
	ldr r0, _080D5004 @ =gStaticMotionGraphics+12
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
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x12
	strb r0, [r1]
	adds r0, r7, #0
	bl InitScalerotMotion1
	movs r1, #0xa2
	lsls r1, r1, #7
	adds r0, r7, #0
	bl SetMotion
	strb r6, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080D4FAC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r1, [r7, #0x13]
	movs r0, #0x13
	ldrsb r0, [r7, r0]
	cmp r0, #0
	blt _080D4FD2
	adds r0, r1, #1
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, r7, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrb r0, [r7, #0x13]
	lsls r0, r0, #1
	adds r1, #2
	strh r0, [r1]
_080D4FD2:
	ldr r1, [r7, #0x60]
	lsls r0, r1, #6
	subs r0, r0, r1
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	asrs r0, r0, #6
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5050
	.align 2, 0
_080D4FF0: .4byte 0xFFFFB800
_080D4FF4: .4byte wStaticGraphicTilenums
_080D4FF8: .4byte wStaticMotionPalIDs
_080D4FFC: .4byte 0x00000654
_080D5000: .4byte gStaticMotionGraphics
_080D5004: .4byte gStaticMotionGraphics+12
_080D5008:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080D5028
	ldr r2, [r7, #0x54]
	ldr r3, [r7, #0x58]
	movs r0, #5
	movs r1, #0
	bl FUN_080c5628
_080D5028:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	b _080D5054
_080D5036:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	ldr r0, [r7, #0x5c]
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x60]
	str r0, [r7, #0x68]
_080D5050:
	movs r0, #0
	strb r0, [r7, #0x13]
_080D5054:
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
	b _080D50D2
_080D505C:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r6, _080D510C @ =RNG_0202f388
	ldr r0, [r6]
	ldr r4, _080D5110 @ =0x000343FD
	mov r8, r4
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r5, _080D5114 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r6]
	lsrs r0, r0, #0x11
	movs r1, #5
	bl __umodsi3
	subs r0, #2
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D50D2
	mov r1, r8
	muls r1, r4, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r6]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #5
	adds r0, r7, #0
	bl _ForceEntityPalette
_080D50D2:
	ldrb r0, [r7, #0x12]
	adds r2, r0, #1
	strb r2, [r7, #0x12]
	ldr r3, _080D5118 @ =gSineTable
	adds r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	lsls r2, r2, #0x19
	lsrs r2, r2, #0x17
	adds r2, r2, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r1, r1, #2
	ldr r0, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D510C: .4byte RNG_0202f388
_080D5110: .4byte 0x000343FD
_080D5114: .4byte 0x00269EC3
_080D5118: .4byte gSineTable
