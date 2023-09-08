	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #4]
	lsls r0, r0, #0xa
	lsrs r3, r0, #0xa
	cmp r3, #0
	bne _080037D8
	b _08003928
_080037D8:
	ldrh r1, [r4, #6]
	lsrs r1, r1, #6
	ldrh r2, [r4, #0xa]
	movs r0, #0xff
	lsls r0, r0, #3
	ands r0, r2
	muls r0, r1, r0
	adds r6, r6, r0
	ldrb r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080038E2
	ldr r0, [r4]
	adds r5, r4, r0
	adds r7, r3, #0
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08003868
	cmp r3, #0
	bgt _08003806
	b _08003928
_08003806:
	movs r0, #0xc0
	lsls r0, r0, #0x13
	mov r8, r0
_0800380C:
	ldr r0, [r5]
	cmp r0, #0
	bge _0800383A
	ldrh r0, [r4, #8]
	add r0, r8
	adds r0, r6, r0
	mov r1, sp
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #4
	mov r2, r8
	adds r1, r6, r2
	bl LZ77UnCompVram
	ldrh r1, [r4, #8]
	add r1, r8
	adds r1, r6, r1
	mov r0, sp
	movs r2, #8
	bl CpuFastSet
	b _0800384A
_0800383A:
	adds r0, r5, #4
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r6, r2
	ldrh r2, [r4, #8]
	lsrs r2, r2, #2
	bl CpuFastSet
_0800384A:
	ldrh r0, [r4, #0xa]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r6, r6, r0
	ldr r1, [r5]
	ldr r0, _08003864 @ =0x7FFFFFFF
	ands r1, r0
	subs r7, r7, r1
	adds r5, r5, r1
	cmp r7, #0
	bgt _0800380C
	b _08003928
	.align 2, 0
_08003864: .4byte 0x7FFFFFFF
_08003868:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080038B8
	cmp r3, #0
	ble _08003928
_08003876:
	ldr r0, [r5]
	cmp r0, #0
	bge _0800388A
	adds r0, r5, #4
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r6, r2
	bl RLUnCompVram
	b _0800389A
_0800388A:
	adds r0, r5, #4
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r6, r2
	ldrh r2, [r4, #8]
	lsrs r2, r2, #2
	bl CpuFastSet
_0800389A:
	ldrh r0, [r4, #0xa]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r6, r6, r0
	ldr r1, [r5]
	ldr r0, _080038B4 @ =0x7FFFFFFF
	ands r1, r0
	subs r7, r7, r1
	adds r5, r5, r1
	cmp r7, #0
	bgt _08003876
	b _08003928
	.align 2, 0
_080038B4: .4byte 0x7FFFFFFF
_080038B8:
	cmp r3, #0
	ble _08003928
_080038BC:
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r6, r0
	ldrh r2, [r4, #8]
	lsrs r2, r2, #2
	adds r0, r5, #0
	bl CpuFastSet
	ldrh r0, [r4, #0xa]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r6, r6, r0
	ldrh r0, [r4, #8]
	adds r5, r5, r0
	subs r7, r7, r0
	cmp r7, #0
	bgt _080038BC
	b _08003928
_080038E2:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080038FA
	ldr r0, [r4]
	adds r0, r4, r0
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r6, r2
	bl LZ77UnCompVram
	b _08003928
_080038FA:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08003914
	ldr r0, [r4]
	adds r0, r4, r0
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r6, r2
	bl RLUnCompVram
	b _08003928
_08003914:
	ldr r0, [r4]
	adds r4, r4, r0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r6, r0
	adds r0, r3, #0
	lsrs r2, r0, #2
	adds r0, r4, #0
	bl CpuFastSet
_08003928:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
