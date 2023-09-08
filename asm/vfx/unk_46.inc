	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bec34
FUN_080bec34: @ 0x080BEC34
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _080BEC84 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BEC7C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BEC88 @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
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
	str r6, [r3, #0x28]
_080BEC7C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEC84: .4byte gVFXHeaderPtr
_080BEC88: .4byte gVFXFnTable

	thumb_func_start FUN_080bec8c
FUN_080bec8c: @ 0x080BEC8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r3
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _080BECF0 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080BECE2
	adds r0, #0x25
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080BECF4 @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r4, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r3, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r6, [r4, #0x10]
	strb r2, [r4, #0x11]
	ldr r0, [r5]
	str r0, [r4, #0x54]
	ldr r0, [r5, #4]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0x74
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x78]
_080BECE2:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BECF0: .4byte gVFXHeaderPtr
_080BECF4: .4byte gVFXFnTable

	thumb_func_start FUN_080becf8
FUN_080becf8: @ 0x080BECF8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r3, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r0, _080BED54 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BED4C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BED58 @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	movs r0, #2
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0x74
	strh r6, [r0]
	str r7, [r3, #0x78]
_080BED4C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BED54: .4byte gVFXHeaderPtr
_080BED58: .4byte gVFXFnTable

	thumb_func_start FUN_080bed5c
FUN_080bed5c: @ 0x080BED5C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080BEDB8 @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BEDB0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BEDBC @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x7c
	strb r6, [r0]
	movs r0, #2
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080BEDB0:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BEDB8: .4byte gVFXHeaderPtr
_080BEDBC: .4byte gVFXFnTable

	thumb_func_start FUN_080bedc0
FUN_080bedc0: @ 0x080BEDC0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _080BEE1C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BEE14
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BEE20 @ =gVFXFnTable
	movs r1, #0x2e
	strb r1, [r3, #9]
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r5, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x7c
	strb r6, [r0]
	movs r0, #3
	strb r0, [r3, #0x11]
	ldr r0, [r4]
	str r0, [r3, #0x54]
	ldr r0, [r4, #4]
	str r0, [r3, #0x58]
	str r7, [r3, #0x28]
_080BEE14:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080BEE1C: .4byte gVFXHeaderPtr
_080BEE20: .4byte gVFXFnTable

	thumb_func_start VFX46_Init
VFX46_Init: @ 0x080BEE24
	push {r4, r5, lr}
	adds r4, r0, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #1
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0xa]
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _080BEE66
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _080BEE8C
_080BEE66:
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	movs r0, #0x80
	rsbs r0, r0, #0
_080BEE8C:
	str r0, [r4, #0x5c]
	movs r3, #0
	str r3, [r4, #0x60]
	ldrb r2, [r4, #0x11]
	cmp r2, #0
	bne _080BEEB8
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BEEB4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _080BEEF8
	.align 2, 0
_080BEEB4: .4byte gVFXFnTable
_080BEEB8:
	cmp r2, #1
	bne _080BEED8
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BEED4 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r3, [r4, #0xd]
	b _080BEEF8
	.align 2, 0
_080BEED4: .4byte gVFXFnTable
_080BEED8:
	cmp r2, #2
	beq _080BEEE0
	cmp r2, #3
	bne _080BEEFC
_080BEEE0:
	movs r0, #0xff
	strb r0, [r4, #0x12]
	ldr r1, _080BEF08 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_080BEEF8:
	strb r3, [r4, #0xe]
	strb r3, [r4, #0xf]
_080BEEFC:
	adds r0, r4, #0
	bl VFX46_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEF08: .4byte gVFXFnTable

	thumb_func_start VFX46_Update
VFX46_Update: @ 0x080BEF0C
	push {lr}
	ldr r2, _080BEF20 @ =0x0836F01C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BEF20: .4byte 0x0836F01C

	thumb_func_start VFX46_Die
VFX46_Die: @ 0x080BEF24
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BEF40 @ =gVFXFnTable
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
_080BEF40: .4byte gVFXFnTable

	thumb_func_start FUN_080bef44
FUN_080bef44: @ 0x080BEF44
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
	beq _080BEF7A
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BEF9C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BEF9C
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BEF9C
_080BEF7A:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080BEF98 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BF092
	.align 2, 0
_080BEF98: .4byte gVFXFnTable
_080BEF9C:
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080BEFA8
	cmp r6, #1
	beq _080BF032
	b _080BF092
_080BEFA8:
	ldr r4, _080BF050 @ =0x0836F0CC
	movs r0, #0x74
	adds r0, r0, r7
	mov r8, r0
	ldrh r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [r7, #0x78]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldr r4, _080BF054 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080BF058 @ =0x000343FD
	mov sb, r1
	mov r1, sb
	muls r1, r0, r1
	ldr r5, _080BF05C @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r3, r1, #1
	str r3, [r4]
	lsrs r1, r1, #0x11
	movs r0, #0xff
	ands r1, r0
	ldr r0, [r2, #4]
	subs r0, r0, r1
	str r0, [r7, #0x60]
	ldr r2, [r2]
	ldr r0, _080BF060 @ =0xFFFFFE80
	adds r2, r2, r0
	mov r0, sb
	muls r0, r3, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldr r0, [r4]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x1e
	str r0, [r7, #0x64]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BF032:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldrb r1, [r7, #0x13]
	ldr r0, [r7, #0x64]
	cmp r1, r0
	ble _080BF06C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BF064
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BF06A
	.align 2, 0
_080BF050: .4byte 0x0836F0CC
_080BF054: .4byte RNG_0202f388
_080BF058: .4byte 0x000343FD
_080BF05C: .4byte 0x00269EC3
_080BF060: .4byte 0xFFFFFE80
_080BF064:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BF06A:
	strb r0, [r7, #0xa]
_080BF06C:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BF07C
	str r1, [r7, #0x60]
_080BF07C:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BF092:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bf0a0
FUN_080bf0a0: @ 0x080BF0A0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080BF0FA
	cmp r5, #1
	bgt _080BF0B4
	cmp r5, #0
	beq _080BF0BA
	b _080BF170
_080BF0B4:
	cmp r5, #2
	beq _080BF142
	b _080BF170
_080BF0BA:
	ldr r1, _080BF0D8 @ =0x0000AB27
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080BF0DC
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _080BF0E2
	.align 2, 0
_080BF0D8: .4byte 0x0000AB27
_080BF0DC:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _080BF134 @ =0xFFFFF400
_080BF0E2:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF0FA:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF138
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	b _080BF170
	.align 2, 0
_080BF134: .4byte 0xFFFFF400
_080BF138:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	b _080BF170
_080BF142:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080BF170
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080BF178 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_080BF170:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF178: .4byte gVFXFnTable

	thumb_func_start FUN_080bf17c
FUN_080bf17c: @ 0x080BF17C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080BF1B4
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BF1D8
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BF1D8
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _080BF1D8
_080BF1B4:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r1, _080BF1D4 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BF2E2
	.align 2, 0
_080BF1D4: .4byte gVFXFnTable
_080BF1D8:
	ldrb r6, [r7, #0xe]
	cmp r6, #0
	beq _080BF1E4
	cmp r6, #1
	beq _080BF286
	b _080BF2E2
_080BF1E4:
	ldr r4, _080BF2A4 @ =0x0836F0CC
	movs r0, #0x74
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xe
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r4, [r7, #0x78]
	lsls r4, r4, #3
	adds r4, r4, r0
	ldr r1, _080BF2A8 @ =RNG_0202f388
	mov sl, r1
	ldr r0, [r1]
	ldr r2, _080BF2AC @ =0x000343FD
	muls r0, r2, r0
	ldr r1, _080BF2B0 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r5, r0, #1
	mov r2, sl
	str r5, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	bl __umodsi3
	ldr r3, [r4, #4]
	subs r3, r3, r0
	str r3, [r7, #0x60]
	ldr r2, [r4]
	subs r2, #0x80
	ldr r4, _080BF2AC @ =0x000343FD
	adds r0, r5, #0
	muls r0, r4, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r4, sl
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	adds r2, r2, r0
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #6
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	mov r0, sb
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r7, #0x12]
	strb r6, [r7, #0x13]
	ldr r0, [r4]
	ldr r1, _080BF2AC @ =0x000343FD
	muls r0, r1, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #7
	ands r0, r1
	adds r0, #0x1e
	str r0, [r7, #0x64]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BF286:
	ldrb r0, [r7, #0x13]
	adds r0, #1
	strb r0, [r7, #0x13]
	ldrb r1, [r7, #0x13]
	ldr r0, [r7, #0x64]
	cmp r1, r0
	ble _080BF2BC
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080BF2B4
	ldrb r0, [r7, #0xa]
	movs r1, #1
	orrs r0, r1
	b _080BF2BA
	.align 2, 0
_080BF2A4: .4byte 0x0836F0CC
_080BF2A8: .4byte RNG_0202f388
_080BF2AC: .4byte 0x000343FD
_080BF2B0: .4byte 0x00269EC3
_080BF2B4:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BF2BA:
	strb r0, [r7, #0xa]
_080BF2BC:
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BF2CC
	str r1, [r7, #0x60]
_080BF2CC:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
_080BF2E2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bf2f0
FUN_080bf2f0: @ 0x080BF2F0
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _080BF300
	cmp r0, #1
	beq _080BF34A
	b _080BF386
_080BF300:
	adds r0, r3, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	movs r2, #1
	ands r2, r0
	cmp r2, #0
	beq _080BF316
	ldrb r1, [r3, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080BF31C
_080BF316:
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
_080BF31C:
	strb r0, [r3, #0xa]
	adds r1, r2, #0
	adds r0, r3, #0
	adds r0, #0x4c
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r3
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r0, #3
	strb r0, [r3, #0x13]
	movs r0, #0xa
	strb r0, [r3, #0x12]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080BF34A:
	ldrb r0, [r3, #0x12]
	cmp r0, #0
	beq _080BF35A
	subs r0, #1
	strb r0, [r3, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF380
_080BF35A:
	movs r0, #0xa
	strb r0, [r3, #0x12]
	ldrb r0, [r3, #0x13]
	cmp r0, #0
	beq _080BF36E
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF380
_080BF36E:
	ldr r1, _080BF38C @ =gVFXFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
_080BF380:
	adds r0, r3, #0
	bl UpdateMotionGraphic
_080BF386:
	pop {r0}
	bx r0
	.align 2, 0
_080BF38C: .4byte gVFXFnTable
