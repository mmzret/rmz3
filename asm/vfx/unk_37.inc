	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bc540
FUN_080bc540: @ 0x080BC540
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _080BC58C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC584
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC590 @ =gVFXFnTable
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
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x5c]
	str r7, [r3, #0x60]
_080BC584:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC58C: .4byte gVFXHeaderPtr
_080BC590: .4byte gVFXFnTable

	thumb_func_start FUN_080bc594
FUN_080bc594: @ 0x080BC594
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080BC5F4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r4, r0, #0
	cmp r4, #0
	beq _080BC5E8
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BC5F8 @ =gVFXFnTable
	movs r1, #0x25
	strb r1, [r4, #9]
	adds r0, #0x94
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r2, [r4, #0x10]
	str r6, [r4, #0x54]
	str r7, [r4, #0x58]
	mov r0, r8
	str r0, [r4, #0x5c]
	mov r0, sb
	str r0, [r4, #0x60]
	strb r5, [r4, #0x12]
_080BC5E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC5F4: .4byte gVFXHeaderPtr
_080BC5F8: .4byte gVFXFnTable

	thumb_func_start FUN_080bc5fc
FUN_080bc5fc: @ 0x080BC5FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r4, #0
	movs r5, #0
	ldr r0, _080BC658 @ =0x0836D994
	mov r8, r0
_080BC610:
	ldr r0, _080BC65C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r1, r0, #0
	cmp r1, #0
	beq _080BC646
	adds r2, r1, #0
	adds r2, #0x25
	movs r0, #1
	strb r0, [r2]
	movs r0, #0x25
	strb r0, [r1, #9]
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0]
	str r0, [r1, #0x14]
	strh r5, [r1, #0x20]
	adds r0, r1, #0
	adds r0, #0x22
	strb r5, [r0]
	movs r0, #2
	strb r0, [r1, #0x10]
	str r7, [r1, #0x28]
	strb r4, [r1, #0x12]
	adds r0, r6, r4
	strb r0, [r1, #0x13]
_080BC646:
	adds r4, #1
	cmp r4, #5
	ble _080BC610
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BC658: .4byte 0x0836D994
_080BC65C: .4byte gVFXHeaderPtr

	thumb_func_start FUN_080bc660
FUN_080bc660: @ 0x080BC660
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080BC6A4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC69E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC6A8 @ =gVFXFnTable
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
	movs r0, #3
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080BC69E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC6A4: .4byte gVFXHeaderPtr
_080BC6A8: .4byte gVFXFnTable

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
	bl AllocEntityLast
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

	thumb_func_start FUN_080bc758
FUN_080bc758: @ 0x080BC758
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080BC79C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BC796
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC7A0 @ =gVFXFnTable
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
	movs r0, #5
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080BC796:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC79C: .4byte gVFXHeaderPtr
_080BC7A0: .4byte gVFXFnTable

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
	bl AllocEntityLast
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

	thumb_func_start VFX37_Init
VFX37_Init: @ 0x080BC848
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC888 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BC88C @ =0x0836EDF0
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl VFX37_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC888: .4byte gVFXFnTable
_080BC88C: .4byte 0x0836EDF0

	thumb_func_start VFX37_Update
VFX37_Update: @ 0x080BC890
	push {lr}
	ldr r2, _080BC8A4 @ =0x0836EDD4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BC8A4: .4byte 0x0836EDD4

	thumb_func_start VFX37_Die
VFX37_Die: @ 0x080BC8A8
	ldr r2, _080BC8BC @ =gVFXFnTable
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
_080BC8BC: .4byte gVFXFnTable

	thumb_func_start FUN_080bc8c0
FUN_080bc8c0: @ 0x080BC8C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BC8D0
	cmp r0, #1
	beq _080BC8EA
	b _080BC968
_080BC8D0:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _080BC924 @ =0x00003001
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BC8EA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x60]
	adds r1, #3
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r1, r0, #1
	movs r2, #0
	strb r1, [r4, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _080BC928
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _080BC93C
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BC942
	.align 2, 0
_080BC924: .4byte 0x00003001
_080BC928:
	cmp r0, #0xf
	bhi _080BC944
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080BC93C
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BC942
_080BC93C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BC942:
	strb r0, [r4, #0xa]
_080BC944:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080BC968
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BC970 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BC968:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BC970: .4byte gVFXFnTable

	thumb_func_start FUN_080bc974
FUN_080bc974: @ 0x080BC974
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080BC984
	cmp r0, #1
	beq _080BC9C4
	b _080BCA50
_080BC984:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r0, [r5, #0x12]
	subs r1, #3
	strb r0, [r1]
	ldr r4, _080BCA00 @ =0x0836EDF8
	ldr r2, _080BCA04 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BCA08 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BCA0C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BC9C4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x60]
	adds r1, #0xc
	str r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	subs r1, r0, #1
	movs r2, #0
	strb r1, [r5, #0x12]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _080BCA10
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _080BCA24
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BCA2A
	.align 2, 0
_080BCA00: .4byte 0x0836EDF8
_080BCA04: .4byte RNG_0202f388
_080BCA08: .4byte 0x000343FD
_080BCA0C: .4byte 0x00269EC3
_080BCA10:
	cmp r0, #0xf
	bhi _080BCA2C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080BCA24
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BCA2A
_080BCA24:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCA2A:
	strb r0, [r5, #0xa]
_080BCA2C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080BCA50
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080BCA58 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080BCA50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BCA58: .4byte gVFXFnTable

	thumb_func_start FUN_080bca5c
FUN_080bca5c: @ 0x080BCA5C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov r8, r0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BCA74
	cmp r0, #1
	beq _080BCA88
	b _080BCB5E
_080BCA74:
	ldr r0, _080BCB0C @ =0x00003302
	adds r1, r0, #0
	ldrb r0, [r4, #0x12]
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCA88:
	ldr r1, _080BCB10 @ =gStageRun+232
	mov ip, r1
	ldr r1, [r1, #0x38]
	subs r0, r1, #1
	adds r5, r0, r1
	lsrs r0, r5, #0x1f
	adds r0, r5, r0
	asrs r0, r0, #1
	adds r5, r0, #0
	mov r0, ip
	ldr r1, [r0, #0x3c]
	subs r0, r1, #1
	adds r3, r0, r1
	lsrs r0, r3, #0x1f
	adds r0, r3, r0
	asrs r7, r0, #1
	adds r3, r7, #0
	mov r1, r8
	ldr r0, [r1, #0x54]
	subs r2, r0, r5
	ldr r1, _080BCB14 @ =0x0836EDFE
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r2, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _080BCAC6
	adds r0, #0xff
_080BCAC6:
	asrs r2, r0, #8
	mov r1, r8
	ldr r0, [r1, #0x58]
	subs r1, r0, r7
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	bge _080BCAD8
	adds r0, #0xff
_080BCAD8:
	asrs r1, r0, #8
	adds r0, r5, r2
	str r0, [r4, #0x54]
	adds r0, r3, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	mov r1, r8
	adds r1, #0x54
	mov r0, ip
	bl CalcFromCamera
	cmp r0, #0
	bne _080BCB00
	ldrb r1, [r4, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BCB18
_080BCB00:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080BCB24
	.align 2, 0
_080BCB0C: .4byte 0x00003302
_080BCB10: .4byte gStageRun+232
_080BCB14: .4byte 0x0836EDFE
_080BCB18:
	ldrb r0, [r4, #0xa]
	movs r1, #0xfe
	ands r1, r0
	movs r0, #1
	orrs r1, r0
	strb r1, [r4, #0xa]
_080BCB24:
	mov r0, r8
	adds r0, #0xc8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080BCB3A
	mov r1, r8
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bhi _080BCB3A
	cmp r0, #4
	bne _080BCB58
_080BCB3A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BCB68 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BCB58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BCB5E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BCB68: .4byte gVFXFnTable

	thumb_func_start FUN_080bcb6c
FUN_080bcb6c: @ 0x080BCB6C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080BCB78
	b _080BCC8E
_080BCB78:
	lsls r0, r0, #2
	ldr r1, _080BCB84 @ =_080BCB88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080BCB84: .4byte _080BCB88
_080BCB88: @ jump table
	.4byte _080BCBA0 @ case 0
	.4byte _080BCBBC @ case 1
	.4byte _080BCBEA @ case 2
	.4byte _080BCC12 @ case 3
	.4byte _080BCC2E @ case 4
	.4byte _080BCC3E @ case 5
_080BCBA0:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	movs r0, #6
	strb r0, [r4, #0x12]
	movs r1, #0xcc
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCBBC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCBCE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCBCE:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BCBE0
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BCBE6
_080BCBE0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCBE6:
	strb r0, [r4, #0xa]
	b _080BCC26
_080BCBEA:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x18
	bl LoadBlink
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCC12:
	movs r0, #0x18
	bl GetBlinkMotionState
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080BCC26
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCC26:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080BCC8E
_080BCC2E:
	movs r0, #0x18
	bl ClearBlink
	movs r0, #6
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCC3E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCC68
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BCC7C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BCC68:
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BCC80
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BCC86
	.align 2, 0
_080BCC7C: .4byte gVFXFnTable
_080BCC80:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCC86:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BCC8E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bcc94
FUN_080bcc94: @ 0x080BCC94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080BCCCE
	cmp r0, #1
	bgt _080BCCAA
	cmp r0, #0
	beq _080BCCB4
	b _080BCD90
_080BCCAA:
	cmp r0, #2
	beq _080BCD08
	cmp r0, #3
	beq _080BCD12
	b _080BCD90
_080BCCB4:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1a
	strb r0, [r1]
	movs r0, #0x12
	strb r0, [r4, #0x12]
	ldr r1, _080BCD04 @ =0x0000330B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCCCE:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCCE0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCCE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _080BCCFC
	movs r0, #0x19
	bl GetBlinkMotionState
_080BCCFC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080BCD90
	.align 2, 0
_080BCD04: .4byte 0x0000330B
_080BCD08:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCD12:
	ldrb r0, [r4, #0x12]
	adds r5, r0, #0
	cmp r5, #8
	bls _080BCD2A
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _080BCD40
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BCD46
_080BCD2A:
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCD40
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BCD46
_080BCD40:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCD46:
	strb r0, [r4, #0xa]
	subs r0, r5, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCD7A
	adds r1, r6, #0
	adds r1, #0xcf
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BCD98 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BCD7A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080BCD90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BCD98: .4byte gVFXFnTable

	thumb_func_start FUN_080bcd9c
FUN_080bcd9c: @ 0x080BCD9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BCDAC
	cmp r0, #1
	beq _080BCDE0
	b _080BCE3C
_080BCDAC:
	ldr r1, _080BCE00 @ =0x0000330C
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x1a
	bl LoadBlink
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BCDE0:
	movs r0, #0x1a
	bl GetBlinkMotionState
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BCE04
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BCE0A
	.align 2, 0
_080BCE00: .4byte 0x0000330C
_080BCE04:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCE0A:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCE3C
	movs r0, #0x1a
	bl ClearBlink
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BCE44 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BCE3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCE44: .4byte gVFXFnTable

	thumb_func_start FUN_080bce48
FUN_080bce48: @ 0x080BCE48
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _080BCEA6
	cmp r0, #1
	bgt _080BCE5C
	cmp r0, #0
	beq _080BCE66
	b _080BCF5E
_080BCE5C:
	cmp r0, #2
	beq _080BCEE0
	cmp r0, #3
	beq _080BCEEA
	b _080BCF5E
_080BCE66:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r0, [r5, #0x12]
	subs r1, #3
	strb r0, [r1]
	ldr r4, _080BCED0 @ =0x0836EE0A
	ldr r2, _080BCED4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BCED8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080BCEDC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BCEA6:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCEB8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BCEB8:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080BCF5E
	.align 2, 0
_080BCED0: .4byte 0x0836EE0A
_080BCED4: .4byte RNG_0202f388
_080BCED8: .4byte 0x000343FD
_080BCEDC: .4byte 0x00269EC3
_080BCEE0:
	movs r0, #0x10
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080BCEEA:
	ldrb r0, [r5, #0x12]
	adds r4, r0, #0
	cmp r4, #8
	bls _080BCF02
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080BCF18
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BCF1E
_080BCF02:
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCF18
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BCF1E
_080BCF18:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BCF1E:
	strb r0, [r5, #0xa]
	subs r0, r4, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BCF48
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080BCF64 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080BCF48:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_080BCF5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BCF64: .4byte gVFXFnTable
