	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createGhost44
createGhost44: @ 0x080BE818
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080BE864 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BE85C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BE868 @ =gVFXFnTable
	movs r1, #0x2c
	strb r1, [r3, #9]
	adds r0, #0xb0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
_080BE85C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BE864: .4byte gVFXHeaderPtr
_080BE868: .4byte gVFXFnTable

	thumb_func_start VFX44_Init
VFX44_Init: @ 0x080BE86C
	push {r4, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r4, #0xa]
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _080BE8A8
	movs r0, #0xef
	ands r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _080BE8C8
_080BE8A8:
	movs r1, #1
	movs r0, #0x10
	orrs r2, r0
	strb r2, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_080BE8C8:
	movs r2, #0
	str r2, [r4, #0x60]
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BE8F4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	adds r0, r4, #0
	bl VFX44_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE8F4: .4byte gVFXFnTable

	thumb_func_start VFX44_Update
VFX44_Update: @ 0x080BE8F8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BE930 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _080BE910
	ldr r0, _080BE934 @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _080BE93C
_080BE910:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _080BE938 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080BE94C
	.align 2, 0
_080BE930: .4byte gCurStory
_080BE934: .4byte gStageRun
_080BE938: .4byte gVFXFnTable
_080BE93C:
	ldr r0, _080BE950 @ =0x0836EFE0
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080BE94C:
	pop {r0}
	bx r0
	.align 2, 0
_080BE950: .4byte 0x0836EFE0

	thumb_func_start VFX44_Die
VFX44_Die: @ 0x080BE954
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BE970 @ =gVFXFnTable
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
_080BE970: .4byte gVFXFnTable

	thumb_func_start FUN_080be974
FUN_080be974: @ 0x080BE974
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080BE9A6
	cmp r0, #1
	bgt _080BE988
	cmp r0, #0
	beq _080BE992
	b _080BEA1A
_080BE988:
	cmp r0, #2
	beq _080BE9D4
	cmp r0, #3
	beq _080BE9F8
	b _080BEA1A
_080BE992:
	movs r1, #0xf4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BE9A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x12]
	adds r0, r1, #0
	adds r0, #0xff
	strb r0, [r4, #0x12]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BE9C4
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080BE9CA
_080BE9C4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BE9CA:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080BEA1A
	b _080BE9EA
_080BE9D4:
	ldr r1, _080BE9F4 @ =0x00003D01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x62
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
_080BE9EA:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080BEA1A
	.align 2, 0
_080BE9F4: .4byte 0x00003D01
_080BE9F8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080BEA1A
	ldr r1, _080BEA20 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BEA1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BEA20: .4byte gVFXFnTable
