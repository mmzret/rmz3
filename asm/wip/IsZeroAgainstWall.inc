	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r0, #0x94
	ldrb r0, [r0]
	ldr r1, _080268A0 @ =0x0000881F
	mov r8, r1
	cmp r0, #0
	beq _08026882
	ldr r0, _080268A4 @ =0x0000880F
	mov r8, r0
_08026882:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080268A8
	movs r1, #0
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x54]
	subs r1, r1, r0
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r1, r1, r0
	adds r5, r1, #1
	b _080268BA
	.align 2, 0
_080268A0: .4byte 0x0000881F
_080268A4: .4byte 0x0000880F
_080268A8:
	movs r1, #0
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x54]
	adds r1, r1, r0
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r1, r1, r0
	subs r5, r1, #1
_080268BA:
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r1, r1, r0
	ldr r0, _08026960 @ =0xFFFFFE00
	adds r4, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl IsAgainstHazard
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026964
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetMetatileAttr
	mov r1, r8
	ands r1, r0
	cmp r1, #1
	bne _08026902
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08026964
_08026902:
	movs r0, #2
	ldrsh r1, [r7, r0]
	ldr r0, [r6, #0x58]
	adds r4, r0, r1
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl IsAgainstHazard
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026964
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetMetatileAttr
	mov r1, r8
	ands r1, r0
	cmp r1, #1
	beq _08026964
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl IsAgainstHazard
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08026964
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetMetatileAttr
	mov r1, r8
	ands r1, r0
	cmp r1, #1
	beq _08026964
	movs r0, #0
	b _08026966
	.align 2, 0
_08026960: .4byte 0xFFFFFE00
_08026964:
	movs r0, #1
_08026966:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
