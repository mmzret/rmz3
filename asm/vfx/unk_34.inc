	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bbcf4
FUN_080bbcf4: @ 0x080BBCF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080BBD44 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BBD3C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BBD48 @ =gVFXFnTable
	movs r1, #0x22
	strb r1, [r3, #9]
	adds r0, #0x88
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r6, [r3, #0x28]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080BBD3C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BBD44: .4byte gVFXHeaderPtr
_080BBD48: .4byte gVFXFnTable

	thumb_func_start Ghost34_Init
Ghost34_Init: @ 0x080BBD4C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r4, #0x60]
	adds r0, #0x18
	strb r5, [r0]
	ldrb r2, [r4, #0x11]
	cmp r2, #6
	bhi _080BBD9C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #4]
	ldr r1, _080BBDE0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	adds r1, r4, #0
	bl FUN_080bbcf4
_080BBD9C:
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x7c]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	adds r1, r4, #0
	adds r1, #0x80
	str r0, [r1]
	ldr r1, [r4, #0x58]
	subs r1, r1, r0
	str r1, [r4, #0x78]
	ldr r1, _080BBDE4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	strb r5, [r4, #0xe]
	strb r5, [r4, #0xf]
	adds r0, r4, #0
	bl Ghost34_Update
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BBDE0: .4byte 0xFFFFF800
_080BBDE4: .4byte gVFXFnTable

	thumb_func_start Ghost34_Update
Ghost34_Update: @ 0x080BBDE8
	push {lr}
	ldr r2, _080BBDFC @ =0x0836ED80
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BBDFC: .4byte 0x0836ED80

	thumb_func_start Ghost34_Die
Ghost34_Die: @ 0x080BBE00
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BBE1C @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BBE1C: .4byte gVFXFnTable

	thumb_func_start nop_080bbe20
nop_080bbe20: @ 0x080BBE20
	bx lr
	.align 2, 0

	thumb_func_start FUN_080bbe24
FUN_080bbe24: @ 0x080BBE24
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080BBE48
	ldr r1, _080BBE44 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080BBEB6
	.align 2, 0
_080BBE44: .4byte gVFXFnTable
_080BBE48:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BBE54
	cmp r0, #1
	beq _080BBE62
	b _080BBEB6
_080BBE54:
	ldr r1, _080BBEBC @ =0x00002901
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BBE62:
	ldr r0, [r4, #0x28]
	adds r0, #0x24
	ldrb r0, [r0]
	rsbs r0, r0, #0
	adds r3, r4, #0
	adds r3, #0x74
	strb r0, [r3]
	ldr r2, _080BBEC0 @ =gSineTable
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r2
	movs r7, #0
	ldrsh r5, [r1, r7]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r1, #0
	ldrsh r6, [r0, r1]
	ldr r2, [r4, #0x78]
	adds r0, r2, #0
	muls r0, r5, r0
	asrs r0, r0, #8
	ldr r1, [r4, #0x7c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x80
	ldr r1, [r1]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r3]
	rsbs r0, r0, #0
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BBEB6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BBEBC: .4byte 0x00002901
_080BBEC0: .4byte gSineTable
