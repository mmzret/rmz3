	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c2500
FUN_080c2500: @ 0x080C2500
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080C2516
	cmp r0, #1
	beq _080C258A
	b _080C25D2
_080C2516:
	ldr r4, _080C25E0 @ =PTR_s32_ARRAY_0836f2f0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	mov r8, r0
	ldrb r2, [r7, #0x11]
	lsls r2, r2, #3
	add r2, r8
	ldr r3, _080C25E4 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C25E8 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C25EC @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #3
	add r0, r8
	ldr r2, [r0]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	mov r0, sb
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C258A:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C25A0
	str r1, [r7, #0x60]
_080C25A0:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080C25C0
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C25D2
_080C25C0:
	ldr r1, _080C25F0 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080C25D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C25E0: .4byte PTR_s32_ARRAY_0836f2f0
_080C25E4: .4byte RNG_0202f388
_080C25E8: .4byte 0x000343FD
_080C25EC: .4byte 0x00269EC3
_080C25F0: .4byte gVFXFnTable

	thumb_func_start FUN_080c25f4
FUN_080c25f4: @ 0x080C25F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080C260A
	cmp r0, #1
	beq _080C267E
	b _080C26C6
_080C260A:
	ldr r4, _080C26D4 @ =PTR_s32_ARRAY_0836f2f0
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	mov r8, r0
	ldrb r2, [r7, #0x11]
	lsls r2, r2, #3
	add r2, r8
	ldr r3, _080C26D8 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r6, _080C26DC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r5, _080C26E0 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r4, r1, #1
	str r4, [r3]
	lsrs r1, r1, #0x11
	movs r0, #0x1f
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0x11]
	lsls r0, r0, #3
	add r0, r8
	ldr r2, [r0]
	subs r2, #0x20
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	mov r0, sb
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x50
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080C267E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080C2694
	str r1, [r7, #0x60]
_080C2694:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _080C26B4
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C26C6
_080C26B4:
	ldr r1, _080C26E4 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_080C26C6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C26D4: .4byte PTR_s32_ARRAY_0836f2f0
_080C26D8: .4byte RNG_0202f388
_080C26DC: .4byte 0x000343FD
_080C26E0: .4byte 0x00269EC3
_080C26E4: .4byte gVFXFnTable
