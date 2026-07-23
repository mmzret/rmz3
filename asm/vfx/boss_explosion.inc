	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c7a28
FUN_080c7a28: @ 0x080C7A28
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x28]
	movs r0, #0
	movs r2, #0x10
	strb r2, [r4, #0x12]
	strb r0, [r4, #0x13]
	strb r0, [r4, #0x11]
	ldr r1, _080C7A58 @ =gElFxManager
	movs r0, #4
	strb r0, [r1, #2]
	ldr r0, [r3, #0x54]
	ldr r1, [r3, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r3, #0xa]
	ands r2, r0
	cmp r2, #0
	beq _080C7A5C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	b _080C7A62
	.align 2, 0
_080C7A58: .4byte gElFxManager
_080C7A5C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
_080C7A62:
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080C7A8C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl BossExplosion_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C7A8C: .4byte gVFXFnTable

	thumb_func_start FUN_080c7a90
FUN_080c7a90: @ 0x080C7A90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	bl InitScalerotMotion1
	ldrb r0, [r7, #0xa]
	movs r4, #1
	movs r5, #0
	orrs r0, r4
	movs r1, #2
	orrs r0, r1
	strb r0, [r7, #0xa]
	movs r1, #0xee
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r2, _080C7AE0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080C7AE4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080C7AE8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r2, r0, #0x11
	ands r2, r4
	cmp r2, #0
	beq _080C7AEC
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080C7AF2
	.align 2, 0
_080C7AE0: .4byte RNG_0202f388
_080C7AE4: .4byte 0x000343FD
_080C7AE8: .4byte 0x00269EC3
_080C7AEC:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_080C7AF2:
	strb r0, [r7, #0xa]
	movs r4, #1
	mov sb, r4
	mov r1, sb
	ands r1, r2
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
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, _080C7BB4 @ =RNG_0202f388
	mov r8, r0
	ldr r0, [r0]
	ldr r5, _080C7BB8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r5, r1
	ldr r3, _080C7BBC @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r2, r1, #1
	lsrs r1, r1, #0x11
	movs r0, #0x7f
	ands r1, r0
	adds r4, #0xff
	adds r0, r4, #0
	adds r1, r1, r0
	ldrb r4, [r7, #0x11]
	lsls r4, r4, #6
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r6, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0x3f
	ands r0, r2
	adds r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r7, #0
	adds r0, #0x50
	strh r1, [r0]
	lsrs r1, r1, #1
	adds r0, #2
	strh r1, [r0]
	subs r0, #0x2e
	strb r4, [r0]
	adds r0, r6, #0
	muls r0, r5, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	strb r0, [r7, #0x12]
	strb r4, [r7, #0x13]
	movs r0, #0x80
	str r0, [r7, #0x64]
	movs r0, #0x10
	str r0, [r7, #0x68]
	ldr r1, _080C7BC0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r4, sb
	str r4, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl BossExplosion_Update
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7BB4: .4byte RNG_0202f388
_080C7BB8: .4byte 0x000343FD
_080C7BBC: .4byte 0x00269EC3
_080C7BC0: .4byte gVFXFnTable
