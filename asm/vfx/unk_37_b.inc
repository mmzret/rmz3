	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bc7a4
FUN_080bc7a4: @ 0x080BC7A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	ldr r0, [sp, #0x1c]
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	mov r8, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r0, _080BC83C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC830
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC840 @ =gVFXFnTable
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
	movs r0, #6
	strb r0, [r3, #0x10]
	str r6, [r3, #0x54]
	str r7, [r3, #0x58]
	ldr r1, _080BC844 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	bge _080BC810
	adds r0, #0xff
_080BC810:
	asrs r0, r0, #8
	str r0, [r3, #0x5c]
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	bge _080BC826
	adds r0, #0xff
_080BC826:
	asrs r0, r0, #8
	rsbs r0, r0, #0
	str r0, [r3, #0x60]
	mov r2, sb
	strb r2, [r3, #0x12]
_080BC830:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC83C: .4byte gVFXHeaderPtr
_080BC840: .4byte gVFXFnTable
_080BC844: .4byte gSineTable

