	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bc6ac
FUN_080bc6ac: @ 0x080BC6AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov sb, r4
	ldr r0, _080BC74C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC73E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC750 @ =gVFXFnTable
	movs r1, #0x25
	strb r1, [r3, #9]
	adds r0, #0x94
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #4
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	ldr r1, _080BC754 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	bge _080BC714
	adds r0, #0xff
_080BC714:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	mov r2, sb
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	bge _080BC72A
	adds r0, #0xff
_080BC72A:
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r3, #0x60]
	mov r2, r8
	str r2, [r3, #0x28]
	mov r1, r8
	adds r1, #0xcf
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080BC73E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC74C: .4byte gVFXHeaderPtr
_080BC750: .4byte gVFXFnTable
_080BC754: .4byte gSineTable

