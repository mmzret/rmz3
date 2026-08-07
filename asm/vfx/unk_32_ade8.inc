	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BAEA0
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	ldr r2, _080BAE7C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BAE80 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _080BAE84 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE88 @ =0x00002710
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE8C @ =0x00002711
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE90 @ =0x00002712
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE94 @ =0x00002713
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE98 @ =0x00002714
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAE9C @ =0x00002715
	mov r0, sp
	adds r3, r4, #0
	bl FUN_080ba81c
	movs r0, #0x31
	bl PlaySound
	b _080BAF36
	.align 2, 0
_080BAE7C: .4byte RNG_0202f388
_080BAE80: .4byte 0x000343FD
_080BAE84: .4byte 0x00269EC3
_080BAE88: .4byte 0x00002710
_080BAE8C: .4byte 0x00002711
_080BAE90: .4byte 0x00002712
_080BAE94: .4byte 0x00002713
_080BAE98: .4byte 0x00002714
_080BAE9C: .4byte 0x00002715
_080BAEA0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080BAF74
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080BAF74
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _080BAF4C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080BAF50 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _080BAF54 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF58 @ =0x00002710
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF5C @ =0x00002711
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF60 @ =0x00002712
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF64 @ =0x00002713
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF68 @ =0x00002714
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
	ldrb r1, [r7, #0x10]
	ldr r2, _080BAF6C @ =0x00002715
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080ba81c
_080BAF36:
	ldr r1, _080BAF70 @ =gVFXFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	b _080BB022
	.align 2, 0
_080BAF4C: .4byte RNG_0202f388
_080BAF50: .4byte 0x000343FD
_080BAF54: .4byte 0x00269EC3
_080BAF58: .4byte 0x00002710
_080BAF5C: .4byte 0x00002711
_080BAF60: .4byte 0x00002712
_080BAF64: .4byte 0x00002713
_080BAF68: .4byte 0x00002714
_080BAF6C: .4byte 0x00002715
_080BAF70: .4byte gVFXFnTable
_080BAF74:
	ldrb r1, [r7, #0xe]
	cmp r1, #0
	beq _080BAF80
	cmp r1, #1
	beq _080BAF96
	b _080BB022
_080BAF80:
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	str r1, [r7, #0x60]
	strb r1, [r7, #0x13]
	ldr r1, _080BB030 @ =0x0000270A
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_080BAF96:
	ldr r0, [r7, #0x60]
	adds r0, #8
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BAFA6
	str r1, [r7, #0x60]
_080BAFA6:
	ldrb r0, [r7, #0x12]
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080BB00C
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r3, _080BB034 @ =RNG_0202f388
	mov sb, r3
	ldr r0, [r3]
	ldr r6, _080BB038 @ =0x000343FD
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r3, _080BB03C @ =0x00269EC3
	adds r1, r1, r3
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	ldr r5, _080BB040 @ =0x000007FF
	ands r1, r5
	add r4, sp, #0x10
	ldr r0, [r4, #4]
	subs r0, r0, r1
	str r0, [r4, #4]
	ldr r2, [sp, #0x10]
	ldr r1, _080BB044 @ =0xFFFFFC00
	adds r2, r2, r1
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, sb
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r2, r2, r0
	str r2, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ba9f4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ba9f4
_080BB00C:
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
_080BB022:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB030: .4byte 0x0000270A
_080BB034: .4byte RNG_0202f388
_080BB038: .4byte 0x000343FD
_080BB03C: .4byte 0x00269EC3
_080BB040: .4byte 0x000007FF
_080BB044: .4byte 0xFFFFFC00
