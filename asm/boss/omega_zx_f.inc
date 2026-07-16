	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080616fc
FUN_080616fc: @ 0x080616FC
	push {r4, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	strh r0, [r1]
	ldr r1, _08061754 @ =gSineTable
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r3, r0, #2
	mov r4, ip
	ldr r0, [r4, #0x68]
	adds r0, r0, r3
	str r0, [r4, #0x58]
	mov r3, ip
	adds r3, #0xc2
	ldrh r0, [r3]
	adds r0, #2
	ands r0, r2
	strh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r3, r0, #3
	ldr r2, [r4, #0x64]
	adds r2, r2, r3
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x60]
	str r2, [r4, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061754: .4byte gSineTable
