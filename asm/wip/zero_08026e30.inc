	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bge _08026F44
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026E66
	movs r0, #0
	ldrsh r1, [r7, r0]
	rsbs r1, r1, #0
	b _08026E6A
_08026E66:
	movs r2, #0
	ldrsh r1, [r7, r2]
_08026E6A:
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r4, r1, r0
	adds r5, r1, r0
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r2, [r1]
	cmp r2, r0
	ble _08026E8A
	subs r0, r2, r4
	adds r0, #1
	str r0, [r6, #0x54]
_08026E8A:
	mov r2, r8
	cmp r2, #0
	beq _08026EDA
	ldr r3, [r6, #0x54]
	adds r0, r3, r4
	subs r0, #1
	ldr r1, [r1]
	cmp r1, r0
	ble _08026EDA
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r2, r1, r0
	adds r1, r3, r5
	adds r0, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08026F40
	movs r2, #2
	ldrsh r0, [r7, r2]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r2, r1, r0
	ldr r1, [r6, #0x54]
	adds r1, r1, r5
	adds r0, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08026F40
_08026EDA:
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r6, #0x54]
	adds r0, r0, r5
	ldr r2, [r1]
	cmp r2, r0
	bge _08026EF0
	subs r0, r2, r5
	subs r0, #1
	str r0, [r6, #0x54]
_08026EF0:
	mov r2, r8
	cmp r2, #0
	beq _08026F44
	ldr r3, [r6, #0x54]
	adds r0, r3, r5
	adds r0, #1
	ldr r1, [r1]
	cmp r1, r0
	bge _08026F44
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r2, r1, r0
	adds r1, r3, r4
	adds r0, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08026F40
	movs r2, #2
	ldrsh r0, [r7, r2]
	ldr r1, [r6, #0x58]
	adds r1, r1, r0
	ldrh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r2, r1, r0
	ldr r1, [r6, #0x54]
	adds r1, r1, r4
	adds r0, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08026F44
_08026F40:
	movs r0, #1
	b _08026F7E
_08026F44:
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bge _08026F7C
	movs r0, #6
	ldrsh r1, [r7, r0]
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	cmp r2, r0
	ble _08026F7C
	adds r0, r2, r1
	str r0, [r6, #0x58]
	ldr r0, [r6, #0xc]
	ldr r1, _08026F88 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _08026F8C @ =0x00010100
	cmp r0, r1
	bne _08026F7C
	movs r1, #0
	movs r0, #2
	strb r0, [r6, #0xe]
	strb r1, [r6, #0xf]
_08026F7C:
	movs r0, #0
_08026F7E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08026F88: .4byte 0x00FFFF00
_08026F8C: .4byte 0x00010100
