	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, [sp, #0x28]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	mov r2, sb
	str r2, [sp]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	str r0, [sp, #4]
	asrs r0, r7, #4
	movs r2, #1
	mov sl, r2
	cmp r0, #0
	beq _08024D4A
	mov sl, r0
_08024D4A:
	cmp r5, #0
	bne _08024D56
	adds r0, r7, #0
	mov r1, sb
	mov r2, r8
	b _08024D9C
_08024D56:
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r6, #0
	muls r0, r5, r0
	cmp r0, r4
	bne _08024D72
	movs r0, #0x34
	bl PlaySound
_08024D72:
	mov r0, sl
	muls r0, r6, r0
	adds r2, r0, #0
	cmp r0, #0
	bge _08024D7E
	rsbs r2, r0, #0
_08024D7E:
	adds r1, r7, #0
	cmp r7, #0
	bge _08024D86
	rsbs r1, r7, #0
_08024D86:
	cmp r2, r1
	bgt _08024D96
	mov r1, sb
	mov r2, r8
	bl printNumOnResultScreen
	movs r0, #1
	b _08024DA2
_08024D96:
	adds r0, r7, #0
	ldr r1, [sp]
	ldr r2, [sp, #4]
_08024D9C:
	bl printNumOnResultScreen
	movs r0, #0
_08024DA2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
