	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cff48
FUN_080cff48: @ 0x080CFF48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	movs r1, #0
	strb r1, [r4, #0x12]
	adds r5, r0, #0
	adds r5, #0xbd
	ldrb r0, [r5]
	cmp r0, #0
	beq _080CFFD2
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r5]
	cmp r0, #1
	bne _080CFF80
	movs r1, #0x89
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	b _080CFFAC
_080CFF80:
	movs r1, #0x8a
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xbb
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r4, #0
	adds r1, #0xc2
	strb r0, [r1]
	ldrb r0, [r4, #0x12]
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	orrs r1, r2
	bl StartPaletteAnimation
_080CFFAC:
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
_080CFFD2:
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080D0000 @ =Rect_08370730
	str r0, [r4, #0x30]
	movs r2, #1
	strh r2, [r4, #0x26]
	ldr r1, _080D0004 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl BaseElevator_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0000: .4byte Rect_08370730
_080D0004: .4byte gSolidFnTable

