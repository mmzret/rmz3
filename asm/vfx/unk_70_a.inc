	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c598c
FUN_080c598c: @ 0x080C598C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xd]
	cmp r0, #0
	beq _080C59A2
	cmp r0, #1
	beq _080C59F4
	b _080C5B1E
_080C59A2:
	ldr r1, _080C5A60 @ =0x00005103
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x1f
	strb r0, [r1]
	ldr r6, _080C5A64 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _080C5A68 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r5, r1
	ldr r2, _080C5A6C @ =0x00269EC3
	adds r1, r1, r2
	lsls r1, r1, #1
	lsrs r3, r1, #1
	lsrs r1, r1, #0x11
	ldr r4, _080C5A70 @ =0x00000FFF
	ands r1, r4
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	ldr r1, _080C5A74 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r7, #0x64]
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r4
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x68]
	movs r0, #0x5a
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xd]
	adds r0, #1
	strb r0, [r7, #0xd]
_080C59F4:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r2, [r7, #0x68]
	adds r2, #0x80
	str r2, [r7, #0x68]
	ldr r0, _080C5A64 @ =RNG_0202f388
	mov sb, r0
	ldr r0, [r0]
	ldr r4, _080C5A68 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r4, r1
	ldr r3, _080C5A6C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	ldr r6, _080C5A70 @ =0x00000FFF
	ands r1, r6
	ldr r5, _080C5A74 @ =0xFFFFF800
	adds r1, r1, r5
	ldr r0, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	mov r0, r8
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	adds r0, r0, r5
	adds r2, r2, r0
	str r2, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, sb
	str r1, [r2]
	lsrs r2, r0, #0x11
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080C5A78
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C5A7E
	.align 2, 0
_080C5A60: .4byte 0x00005103
_080C5A64: .4byte RNG_0202f388
_080C5A68: .4byte 0x000343FD
_080C5A6C: .4byte 0x00269EC3
_080C5A70: .4byte 0x00000FFF
_080C5A74: .4byte 0xFFFFF800
_080C5A78:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C5A7E:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r2, _080C5AC4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C5AC8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C5ACC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080C5AD0
	ldrb r0, [r7, #0xa]
	movs r1, #0x20
	orrs r0, r1
	b _080C5AD6
	.align 2, 0
_080C5AC4: .4byte RNG_0202f388
_080C5AC8: .4byte 0x000343FD
_080C5ACC: .4byte 0x00269EC3
_080C5AD0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xdf
	ands r0, r1
_080C5AD6:
	strb r0, [r7, #0xa]
	movs r0, #0
	adds r1, r7, #0
	adds r1, #0x4d
	strb r0, [r1]
	ldrb r1, [r3]
	subs r0, #0x21
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r7, #0x12]
	cmp r1, #0x1d
	bhi _080C5B06
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080C5AFE
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080C5B04
_080C5AFE:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C5B04:
	strb r0, [r7, #0xa]
_080C5B06:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _080C5B1E
	ldr r1, _080C5B2C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080C5B1E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5B2C: .4byte gVFXFnTable
