	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080bf634
FUN_080bf634: @ 0x080BF634
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080BF646
	cmp r0, #1
	beq _080BF696
	b _080BF6CC
_080BF646:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF664
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1a
	strb r0, [r1]
	ldr r1, _080BF660 @ =0x00004B01
	adds r0, r4, #0
	bl SetMotion
	b _080BF690
	.align 2, 0
_080BF660: .4byte 0x00004B01
_080BF664:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x46
	bl StartPaletteAnimation
_080BF690:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF696:
	ldr r1, [r5, #0x54]
	ldr r0, _080BF6D4 @ =0xFFFFFD00
	adds r1, r1, r0
	ldrb r2, [r4, #0x12]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #9
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF6C0
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_080BF6C0:
	movs r0, #0x46
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl UpdateEntityAnim
_080BF6CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF6D4: .4byte 0xFFFFFD00

	thumb_func_start FUN_080bf6d8
FUN_080bf6d8: @ 0x080BF6D8
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _080BF6E6
	b _080BF886
_080BF6E6:
	lsls r0, r0, #2
	ldr r1, _080BF6F0 @ =_080BF6F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080BF6F0: .4byte _080BF6F4
_080BF6F4: @ jump table
	.4byte _080BF71C @ case 0
	.4byte _080BF75E @ case 1
	.4byte _080BF78C @ case 2
	.4byte _080BF79E @ case 3
	.4byte _080BF7B0 @ case 4
	.4byte _080BF7BA @ case 5
	.4byte _080BF7D8 @ case 6
	.4byte _080BF7EE @ case 7
	.4byte _080BF83A @ case 8
	.4byte _080BF844 @ case 9
_080BF71C:
	movs r0, #0x80
	bl PlaySound
	movs r0, #0x46
	bl RemovePaletteAnimation
	adds r0, r4, #0
	bl _GetEntityPaletteID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x47
	bl StartPaletteAnimation
	ldr r1, [r4, #0x54]
	ldr r0, _080BF788 @ =0xFFFFF600
	adds r1, r1, r0
	ldrb r2, [r4, #0x12]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #0xa
	adds r1, r1, r0
	str r1, [r4, #0x54]
	movs r0, #6
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF75E:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF770
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF770:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF82C
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF82C
	adds r0, r4, #0
	bl FUN_080bf390
	b _080BF82C
	.align 2, 0
_080BF788: .4byte 0xFFFFF600
_080BF78C:
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #7
	subs r0, #0x40
	str r0, [r4, #0x5c]
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF79E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF812
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF812
	b _080BF80C
_080BF7B0:
	movs r0, #0x50
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF7BA:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF7D0
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF7D0
	adds r0, r4, #0
	bl FUN_080bf390
_080BF7D0:
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	b _080BF81A
_080BF7D8:
	movs r1, #0x75
	ldrb r2, [r4, #0x12]
	movs r0, #0xea
	muls r0, r2, r0
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	movs r0, #0x30
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF7EE:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080BF812
	ldrb r0, [r4, #0x13]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080BF812
	ldr r0, [r4, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	ble _080BF812
_080BF80C:
	adds r0, r4, #0
	bl FUN_080bf390
_080BF812:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080BF81A:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF82C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF82C:
	movs r0, #0x47
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080BF886
_080BF83A:
	movs r0, #0x50
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080BF844:
	movs r0, #0x47
	bl StepPaletteAnimation
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, [r4, #0x58]
	subs r0, #0xc0
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BF886
	movs r0, #0x47
	bl RemovePaletteAnimation
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080BF88C @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080BF886:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF88C: .4byte gVFXFnTable

	thumb_func_start FUN_080bf890
FUN_080bf890: @ 0x080BF890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [sp]
	ldr r1, [r7, #0x2c]
	mov sl, r1
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _080BF8B2
	cmp r0, #1
	beq _080BF960
	b _080BF9FA
_080BF8B2:
	str r0, [r7, #0x64]
	ldr r0, _080BF900 @ =0xFFFFE800
	mov sb, r0
	str r0, [r7, #0x68]
	ldr r4, _080BF904 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _080BF908 @ =0x000343FD
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _080BF90C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	add r0, sb
	str r0, [r7, #0x68]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	adds r6, r4, #0
	cmp r0, #0
	beq _080BF910
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x17
	b _080BF916
	.align 2, 0
_080BF900: .4byte 0xFFFFE800
_080BF904: .4byte RNG_0202f388
_080BF908: .4byte 0x000343FD
_080BF90C: .4byte 0x00269EC3
_080BF910:
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x19
_080BF916:
	strb r0, [r1]
	ldr r0, [r6]
	ldr r4, _080BF974 @ =0x000343FD
	adds r2, r0, #0
	muls r2, r4, r2
	ldr r3, _080BF978 @ =0x00269EC3
	adds r2, r2, r3
	lsls r2, r2, #1
	lsrs r1, r2, #1
	lsrs r2, r2, #0x11
	movs r0, #1
	ands r2, r0
	strb r2, [r7, #0x13]
	ldr r5, _080BF97C @ =0xFFFFFE00
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	subs r0, r5, r0
	str r0, [r7, #0x5c]
	cmp r2, #0
	beq _080BF94E
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
_080BF94E:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _080BF980 @ =0x00004B04
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BF960:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF984
	ldrb r0, [r7, #0xa]
	orrs r0, r1
	b _080BF98A
	.align 2, 0
_080BF974: .4byte 0x000343FD
_080BF978: .4byte 0x00269EC3
_080BF97C: .4byte 0xFFFFFE00
_080BF980: .4byte 0x00004B04
_080BF984:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080BF98A:
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _080BF9BA
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [sp]
	ldr r2, [r1, #0x54]
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	mov r1, sl
	ldr r0, [r1, #0x54]
	cmp r2, r0
	bge _080BF9FA
	b _080BF9DA
_080BF9BA:
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	mov r1, sl
	ldr r2, [r1, #0x54]
	adds r2, r2, r0
	str r2, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, [r7, #0x68]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldr r1, [sp]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _080BF9FA
_080BF9DA:
	str r0, [r7, #0x54]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080BFA0C @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_080BF9FA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BFA0C: .4byte gVFXFnTable
