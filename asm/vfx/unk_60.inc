	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c2d48
FUN_080c2d48: @ 0x080C2D48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080C2D7E
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080C2DA0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080C2DA0
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080C2DA0
_080C2D7E:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080C2D9C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080C2E6E
	.align 2, 0
_080C2D9C: .4byte gVFXFnTable
_080C2DA0:
	ldrb r0, [r7, #0xe]
	mov sb, r0
	cmp r0, #0
	beq _080C2DAE
	cmp r0, #1
	beq _080C2E18
	b _080C2E6E
_080C2DAE:
	ldr r4, _080C2E30 @ =0x0836F404
	movs r1, #0x74
	adds r1, r1, r7
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r3, _080C2E34 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C2E38 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C2E3C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	adds r0, r0, r1
	str r0, [r7, #0x60]
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x3f
	ands r1, r0
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	mov r1, sb
	strb r1, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C2E18:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C2E40
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080C2E46
	.align 2, 0
_080C2E30: .4byte PTR_s32_ARRAY_0836f404
_080C2E34: .4byte RNG_0202f388
_080C2E38: .4byte 0x000343FD
_080C2E3C: .4byte 0x00269EC3
_080C2E40:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080C2E46:
	strb r0, [r7, #0xa]
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C2E58
	str r1, [r7, #0x60]
_080C2E58:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateEntityAnim
_080C2E6E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
