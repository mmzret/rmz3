	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807562c
FUN_0807562c: @ 0x0807562C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807563C
	cmp r0, #1
	beq _08075656
	b _080756DA
_0807563C:
	movs r1, #0xa4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080756E0 @ =0x0836705C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08075656:
	ldr r1, [r4, #0x5c]
	movs r0, #0xd0
	lsls r0, r0, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xc0
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _080756E4 @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #8
	adds r2, r0, #0
	muls r2, r1, r2
	asrs r2, r2, #8
	str r2, [r4, #0x60]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r0, r2, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r3, r4, #0
	adds r3, #0xbc
	ldr r0, [r3]
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r3]
	muls r0, r6, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080756DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080756E0: .4byte sCollisions+(24*1)
_080756E4: .4byte gSineTable

