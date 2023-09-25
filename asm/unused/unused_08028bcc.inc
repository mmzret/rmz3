	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	mov r0, sp
	movs r1, #0
	movs r2, #4
	bl memset
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08028BFA
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r6, r1, r0
	b _08028C0A
_08028BFA:
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
_08028C0A:
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0xf
	ands r2, r1
	cmp r2, #1
	bne _08028C48
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08028C48
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08028C48
	mov r0, sp
	strb r2, [r0]
	b _08028C5E
_08028C48:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028C5E
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08028C5E:
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0xf
	ands r2, r1
	cmp r2, #1
	bne _08028C9C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08028C9C
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08028C9C
	mov r0, sp
	strb r2, [r0, #1]
	b _08028CB2
_08028C9C:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028CB2
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08028CB2:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08028CCE
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r6, r1, r0
	b _08028CDE
_08028CCE:
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r6, r1, r0
_08028CDE:
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0xf
	ands r2, r1
	cmp r2, #1
	bne _08028D1C
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08028D1C
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08028D1C
	mov r0, sp
	strb r2, [r0, #2]
	b _08028D32
_08028D1C:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028D32
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #2]
_08028D32:
	movs r1, #2
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	ldrh r0, [r4, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0xf
	ands r2, r1
	cmp r2, #1
	bne _08028D70
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08028D70
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08028D70
	mov r0, sp
	strb r2, [r0, #3]
	b _08028D86
_08028D70:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl IsInHazard
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08028D86
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #3]
_08028D86:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08028DA6
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _08028DA6
	mov r0, sp
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _08028DA6
	mov r0, sp
	ldrb r0, [r0, #3]
	cmp r0, #0
	beq _08028DAA
_08028DA6:
	movs r0, #1
	b _08028DAC
_08028DAA:
	movs r0, #0
_08028DAC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
