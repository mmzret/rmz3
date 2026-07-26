	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateBirdElf
CreateBirdElf: @ 0x080E5928
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080E5980 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080E5990
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E5984 @ =gElfFnTable
	movs r0, #0xc
	strb r0, [r3, #9]
	ldr r0, [r1, #0x30]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r4, [r0]
	strb r7, [r3, #0x10]
	strb r6, [r3, #0x11]
	strb r5, [r3, #0x12]
	cmp r5, #0
	bne _080E5988
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	b _080E598E
	.align 2, 0
_080E5980: .4byte gElfHeaderPtr
_080E5984: .4byte gElfFnTable
_080E5988:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0, #1]
_080E598E:
	strb r0, [r3, #0x13]
_080E5990:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start BirdElf_Init
BirdElf_Init: @ 0x080E5998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0xb4
	ldr r6, [r0]
	ldr r1, _080E5A64 @ =gZeroRanges
	ldr r2, _080E5A68 @ =0x00000147
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r7, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	ldrb r1, [r7, #0xa]
	movs r0, #1
	movs r2, #0
	mov r8, r2
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r0, #1
	bl GetElfMotion
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x54]
	asrs r4, r4, #0x10
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [r7, #0x58]
	adds r0, r7, #0
	adds r0, #0xb8
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r7, #0x58]
	str r0, [r1]
	adds r2, #0x78
	movs r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0xc1
	movs r0, #0x20
	strb r0, [r1]
	mov r2, r8
	str r2, [r7, #0x2c]
	ldr r1, _080E5A6C @ =gElfFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl BirdElf_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E5A64: .4byte gZeroRanges
_080E5A68: .4byte 0x00000147
_080E5A6C: .4byte gElfFnTable

	thumb_func_start BirdElf_Update
BirdElf_Update: @ 0x080E5A70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r5, [r0]
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _080E5AC8 @ =gPause
	ldrb r2, [r0]
	cmp r2, #0
	bne _080E5B38
	ldr r1, _080E5ACC @ =0x00000232
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E5AD4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E5AD0 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080E5B38
	.align 2, 0
_080E5AC8: .4byte gPause
_080E5ACC: .4byte 0x00000232
_080E5AD0: .4byte gElfFnTable
_080E5AD4:
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080E5AF0
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080E5B08
_080E5AF0:
	ldr r1, _080E5B04 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080E5B38
	.align 2, 0
_080E5B04: .4byte gElfFnTable
_080E5B08:
	ldr r1, _080E5B40 @ =0x08371F94
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r5, r4, #0
	adds r5, #0xc1
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080E5B38
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #2
	bl FUN_080bfc94
	movs r0, #0x20
	strb r0, [r5]
_080E5B38:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5B40: .4byte sUpdates

