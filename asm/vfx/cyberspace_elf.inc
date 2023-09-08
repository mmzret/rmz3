	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CyberSpaceElf_Update
CyberSpaceElf_Update: @ 0x080C73A0
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	beq _080C73FC
	cmp r0, #1
	bgt _080C73B8
	cmp r0, #0
	beq _080C73C2
	b _080C7488
_080C73B8:
	cmp r0, #2
	beq _080C7434
	cmp r0, #3
	beq _080C7450
	b _080C7488
_080C73C2:
	ldr r2, _080C73F8 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #5
	ldr r0, [r4, #0x74]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r4, #0x78]
	adds r1, r1, r0
	ldrb r2, [r4, #0x13]
	movs r0, #0x80
	subs r0, r0, r2
	lsls r0, r0, #9
	adds r1, r1, r0
	b _080C7486
	.align 2, 0
_080C73F8: .4byte gSineTable
_080C73FC:
	ldr r2, _080C7430 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #5
	ldr r0, [r4, #0x74]
	subs r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r4, #0x78]
	adds r1, r1, r0
	ldrb r2, [r4, #0x13]
	movs r0, #0x80
	subs r0, r0, r2
	lsls r0, r0, #9
	adds r1, r1, r0
	b _080C7486
	.align 2, 0
_080C7430: .4byte gSineTable
_080C7434:
	ldr r2, _080C744C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, [r4, #0x74]
	adds r0, r0, r1
	b _080C7466
	.align 2, 0
_080C744C: .4byte gSineTable
_080C7450:
	ldr r2, _080C74A4 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, [r4, #0x74]
	subs r0, r0, r1
_080C7466:
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	ldr r1, [r4, #0x78]
	subs r1, r1, r0
	ldrb r2, [r4, #0x13]
	movs r0, #0x80
	subs r0, r0, r2
	lsls r0, r0, #0xa
	subs r1, r1, r0
_080C7486:
	str r1, [r4, #0x58]
_080C7488:
	ldrb r0, [r4, #0x12]
	subs r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bhi _080C74A8
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	b _080C74B4
	.align 2, 0
_080C74A4: .4byte gSineTable
_080C74A8:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r0, [r4, #0x13]
	adds r0, #1
_080C74B4:
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	adds r0, #8
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C74E0
	movs r0, #0x23
	bl PlaySound
	ldr r1, _080C74E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl CyberSpaceElf_Die
_080C74E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C74E8: .4byte gVFXFnTable

	thumb_func_start CyberSpaceElf_Die
CyberSpaceElf_Die: @ 0x080C74EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x54
	ldrb r2, [r4, #0x11]
	movs r1, #1
	bl FUN_080bfd98
	ldr r1, _080C7514 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C7514: .4byte gVFXFnTable


