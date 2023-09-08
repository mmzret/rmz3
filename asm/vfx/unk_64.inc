	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start oz_080c39a0
oz_080c39a0: @ 0x080C39A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C39E0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C39DA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C39E4 @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x28]
	strb r0, [r3, #0x10]
_080C39DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C39E0: .4byte gVFXHeaderPtr
_080C39E4: .4byte gVFXFnTable

	thumb_func_start FUN_080c39e8
FUN_080c39e8: @ 0x080C39E8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080C3A4C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080C3A44
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080C3A50 @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r4, #9]
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	str r5, [r4, #0x28]
	strb r2, [r4, #0x10]
	ldr r3, [r5, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080C3A3A
	ldr r0, _080C3A54 @ =0xFFFFF400
	adds r2, r3, r0
_080C3A3A:
	str r2, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, _080C3A58 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080C3A44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3A4C: .4byte gVFXHeaderPtr
_080C3A50: .4byte gVFXFnTable
_080C3A54: .4byte 0xFFFFF400
_080C3A58: .4byte 0xFFFFE000

	thumb_func_start oz_Rekkoha_080c3a5c
oz_Rekkoha_080c3a5c: @ 0x080C3A5C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080C3AC4 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C3ABC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C3AC8 @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	str r4, [r3, #0x28]
	movs r0, #3
	strb r0, [r3, #0x10]
	ldr r5, [r4, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	str r0, [r3, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080C3AB2
	ldr r0, _080C3ACC @ =0xFFFFF400
	adds r2, r5, r0
_080C3AB2:
	str r2, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080C3AD0 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080C3ABC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3AC4: .4byte gVFXHeaderPtr
_080C3AC8: .4byte gVFXFnTable
_080C3ACC: .4byte 0xFFFFF400
_080C3AD0: .4byte 0xFFFFE000

	thumb_func_start ozMessenkou2
ozMessenkou2: @ 0x080C3AD4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080C3B38 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C3B32
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080C3B3C @ =gVFXFnTable
	movs r0, #0x40
	strb r0, [r3, #9]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
	ldr r0, [r1]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3, #0x10]
	ldr r4, [r5, #0x54]
	ldr r1, _080C3B40 @ =0xFFFFFB00
	adds r0, r4, r1
	str r0, [r3, #0x54]
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080C3B2A
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r2, r4, r0
_080C3B2A:
	str r2, [r3, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r3, #0x58]
_080C3B32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C3B38: .4byte gVFXHeaderPtr
_080C3B3C: .4byte gVFXFnTable
_080C3B40: .4byte 0xFFFFFB00

	thumb_func_start oz_080c3b44
oz_080c3b44: @ 0x080C3B44
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C3B90 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C3B8A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C3B94 @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080C3B98 @ =0xFFFFEA00
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080C3B8A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3B90: .4byte gVFXHeaderPtr
_080C3B94: .4byte gVFXFnTable
_080C3B98: .4byte 0xFFFFEA00

	thumb_func_start oz_080c3b9c
oz_080c3b9c: @ 0x080C3B9C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080C3BE8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C3BE2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C3BEC @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _080C3BF0 @ =0xFFFFEA00
	adds r0, r0, r1
	str r0, [r3, #0x58]
_080C3BE2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3BE8: .4byte gVFXHeaderPtr
_080C3BEC: .4byte gVFXFnTable
_080C3BF0: .4byte 0xFFFFEA00

	thumb_func_start FUN_080c3bf4
FUN_080c3bf4: @ 0x080C3BF4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080C3C3C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080C3C34
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080C3C40 @ =gVFXFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
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
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
_080C3C34:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3C3C: .4byte gVFXHeaderPtr
_080C3C40: .4byte gVFXFnTable

	thumb_func_start Ghost64_Init
Ghost64_Init: @ 0x080C3C44
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080C3C84 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080C3C88 @ =0x0836F57C
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
	bl Ghost64_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3C84: .4byte gVFXFnTable
_080C3C88: .4byte 0x0836F57C

	thumb_func_start Ghost64_Update
Ghost64_Update: @ 0x080C3C8C
	push {lr}
	ldr r2, _080C3CA0 @ =0x0836F558
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080C3CA0: .4byte 0x0836F558

	thumb_func_start Ghost64_Die
Ghost64_Die: @ 0x080C3CA4
	ldr r2, _080C3CB8 @ =gVFXFnTable
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
_080C3CB8: .4byte gVFXFnTable

	thumb_func_start FUN_080c3cbc
FUN_080c3cbc: @ 0x080C3CBC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r6, [r4, #0x28]
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3CD6
	cmp r0, #1
	beq _080C3CDE
	b _080C3D78
_080C3CD6:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3CDE:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
	movs r2, #0x9c
	lsls r2, r2, #1
	ldr r1, _080C3D80 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080C3D0A
	adds r0, #0xf
_080C3D0A:
	asrs r0, r0, #4
	adds r2, r0, r2
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C3D22
	adds r1, #0xff
_080C3D22:
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	cmp r0, #0
	bge _080C3D3C
	adds r0, #0xff
_080C3D3C:
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r7, #8]
	str r0, [r5, #8]
	ldrb r0, [r7, #0x1a]
	strb r0, [r5, #0x1a]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	strb r0, [r5, #0x18]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	lsls r1, r1, #4
	ldrb r2, [r5, #0x16]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #0x16]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _080C3D78
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080C3D78:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3D80: .4byte gSineTable

	thumb_func_start FUN_080c3d84
FUN_080c3d84: @ 0x080C3D84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x34
	ldr r7, [r5, #0x28]
	movs r0, #0x34
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080C3DA6
	cmp r0, #1
	beq _080C3DC8
	b _080C3E7E
_080C3DA6:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, _080C3E8C @ =gSineTable
	adds r0, #0x78
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080C3DB8
	adds r0, #0x1f
_080C3DB8:
	asrs r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080C3DC8:
	ldr r0, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	subs r4, r1, r0
	cmp r4, #0
	bge _080C3DD8
	adds r4, #0xf
_080C3DD8:
	asrs r4, r4, #4
	adds r4, r0, r4
	str r4, [r5, #0x5c]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r5, #0x13]
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r4, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C3E02
	adds r1, #0xff
_080C3E02:
	asrs r1, r1, #8
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #4
	mov r1, r8
	subs r0, r1, r0
	ldr r1, [r5, #0x5c]
	muls r0, r1, r0
	cmp r0, #0
	bge _080C3E1C
	adds r0, #0xff
_080C3E1C:
	asrs r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x52
	strh r0, [r2]
	mov r1, sb
	ldr r0, [r1, #8]
	str r0, [r6, #8]
	ldrb r0, [r1, #0x1a]
	strb r0, [r6, #0x1a]
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	strb r0, [r6, #0x18]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	lsls r1, r1, #4
	ldrb r2, [r6, #0x16]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #0x16]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C3E60
	ldr r1, [r5, #0x5c]
	ldr r0, _080C3E90 @ =0x0000010F
	cmp r1, r0
	bgt _080C3E7E
_080C3E60:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _080C3E94 @ =gVFXFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_080C3E7E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3E8C: .4byte gSineTable
_080C3E90: .4byte 0x0000010F
_080C3E94: .4byte gVFXFnTable

	thumb_func_start FUN_080c3e98
FUN_080c3e98: @ 0x080C3E98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3EAA
	cmp r0, #1
	beq _080C3EBE
	b _080C3EEE
_080C3EAA:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3EBE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3EEE
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F18 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3EEE:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080C3F12
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F18 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3F12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F18: .4byte gVFXFnTable

	thumb_func_start FUN_080c3f1c
FUN_080c3f1c: @ 0x080C3F1C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3F2C
	cmp r0, #1
	beq _080C3F3A
	b _080C3F66
_080C3F2C:
	ldr r1, _080C3F6C @ =0x00008004
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3F3A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C3F66
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3F70 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3F66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F6C: .4byte 0x00008004
_080C3F70: .4byte gVFXFnTable

	thumb_func_start FUN_080c3f74
FUN_080c3f74: @ 0x080C3F74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C3F86
	cmp r0, #1
	beq _080C3F98
	b _080C3FC8
_080C3F86:
	ldr r1, _080C3FF4 @ =0x0000800A
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xe
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C3F98:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3FC8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3FF8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3FC8:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _080C3FEC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C3FF8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C3FEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3FF4: .4byte 0x0000800A
_080C3FF8: .4byte gVFXFnTable

	thumb_func_start FUN_080c3ffc
FUN_080c3ffc: @ 0x080C3FFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C400C
	cmp r0, #1
	beq _080C401A
	b _080C406A
_080C400C:
	adds r0, r4, #0
	movs r1, #8
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C401A:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080C403C
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
_080C403C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080C406A
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C4070 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C406A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C4070: .4byte gVFXFnTable

	thumb_func_start FUN_080c4074
FUN_080c4074: @ 0x080C4074
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C4084
	cmp r0, #1
	beq _080C4092
	b _080C40E2
_080C4084:
	adds r0, r4, #0
	movs r1, #0x12
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C4092:
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	ble _080C40B4
	adds r0, r4, #0
	bl GetEntityPalID
	adds r1, r0, #0
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
_080C40B4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #4
	bne _080C40E2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C40E8 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C40E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C40E8: .4byte gVFXFnTable

	thumb_func_start FUN_080c40ec
FUN_080c40ec: @ 0x080C40EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C40FC
	cmp r0, #1
	beq _080C410A
	b _080C4136
_080C40FC:
	ldr r1, _080C413C @ =0x00008006
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C410A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _080C4136
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080C4140 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080C4136:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C413C: .4byte 0x00008006
_080C4140: .4byte gVFXFnTable

	thumb_func_start FUN_080c4144
FUN_080c4144: @ 0x080C4144
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x34
	ldr r6, [r4, #0x28]
	adds r7, r6, #0
	adds r7, #0x34
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080C415E
	cmp r0, #1
	beq _080C41A4
	b _080C4242
_080C415E:
	adds r0, r4, #0
	bl InitScalerotMotion1
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r1, #0x2b
	movs r3, #0
	adds r0, #0xe7
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r5, #0x15]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0xd0
	orrs r0, r1
	strb r0, [r5, #0x15]
	adds r0, r6, #0
	adds r0, #0x54
	str r0, [r5, #0xc]
	ldrh r1, [r7, #0x14]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #0x14]
	ldr r0, _080C4248 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #0x14]
	strb r3, [r4, #0x12]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080C41A4:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
	ldr r1, _080C424C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsrs r0, r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080C41D4
	adds r0, #0xff
_080C41D4:
	asrs r0, r0, #8
	adds r2, r0, #0
	adds r2, #0xf0
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x88
	lsls r0, r0, #1
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r0, r1
	cmp r1, #0
	bge _080C41EE
	adds r1, #0xff
_080C41EE:
	asrs r1, r1, #8
	adds r0, r4, #0
	adds r0, #0x50
	movs r3, #0
	strh r1, [r0]
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	muls r0, r2, r0
	cmp r0, #0
	bge _080C420A
	adds r0, #0xff
_080C420A:
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r0, [r7, #8]
	str r0, [r5, #8]
	ldrb r0, [r7, #0x1a]
	strb r0, [r5, #0x1a]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	strb r0, [r5, #0x18]
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	ands r1, r2
	lsls r1, r1, #4
	ldrb r2, [r5, #0x16]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #0x16]
	ldrb r0, [r4, #0x12]
	cmp r0, #0x8f
	bls _080C4242
	strb r3, [r4, #0xd]
	strb r3, [r4, #0xe]
_080C4242:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4248: .4byte 0xFFFFFC00
_080C424C: .4byte gSineTable
