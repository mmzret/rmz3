	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	movs r0, #0
	mov sb, r0
	adds r0, r7, #0
	movs r2, #0
	bl PushoutByBorder
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08025AC2
	mov r1, sl
	cmp r1, #0
	bne _08025AB8
	movs r2, #0
	ldrsh r0, [r4, r2]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	b _08025AE2
_08025AB8:
	movs r3, #0
	ldrsh r0, [r4, r3]
	ldr r1, [r7, #0x54]
	subs r1, r1, r0
	b _08025AD0
_08025AC2:
	mov r0, sl
	cmp r0, #0
	bne _08025ADA
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
_08025AD0:
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	subs r5, r1, r0
	b _08025AEA
_08025ADA:
	movs r2, #0
	ldrsh r0, [r4, r2]
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
_08025AE2:
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r1, r0
_08025AEA:
	movs r3, #2
	ldrsh r0, [r4, r3]
	ldr r2, [r7, #0x58]
	adds r0, r2, r0
	str r0, [sp]
	movs r1, #2
	ldrsh r0, [r4, r1]
	adds r0, r2, r0
	ldrh r1, [r4, #6]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	subs r0, r0, r1
	str r0, [sp, #4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r2, r2, r0
	adds r2, r2, r1
	str r2, [sp, #8]
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08025BD6
	movs r2, #0
	mov r8, r2
	movs r0, #3
	mov r3, sl
	subs r0, r0, r3
	cmp r8, r0
	bge _08025BD6
_08025B28:
	mov r0, r8
	lsls r4, r0, #2
	mov r1, sp
	adds r0, r1, r4
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08025B58
	movs r0, #0xf
	ands r0, r6
	cmp r0, #0
	beq _08025B58
	cmp r0, #0xe
	bls _08025BC2
_08025B58:
	cmp r6, #0
	beq _08025BC2
	ldrb r0, [r7, #0xd]
	cmp r0, #2
	bne _08025B74
	mov r3, sp
	adds r0, r3, r4
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	add r3, sp, #0xc
	bl _pushoutHazardX1
	b _08025B98
_08025B74:
	mov r0, r8
	cmp r0, #0
	bne _08025B88
	ldr r2, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	add r3, sp, #0xc
	bl _pushoutHazardX1
	b _08025B98
_08025B88:
	mov r1, sp
	adds r0, r1, r4
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	add r3, sp, #0xc
	bl _pushoutHazardX2
_08025B98:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	add r2, sp, #0xc
	mov r3, sb
	cmp r3, #0
	beq _08025BC2
	ldr r0, [sp, #0xc]
	adds r5, r5, r0
	ldr r0, [sp]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [sp, #8]
_08025BC2:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #3
	mov r1, sl
	subs r0, r0, r1
	cmp r8, r0
	blt _08025B28
_08025BD6:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [sp, #8]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0xf
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #1
	bne _08025C18
	ldr r0, [r7, #0x54]
	ldr r1, [sp, #8]
	ldr r3, _08025C38 @ =0xFFFFFC00
	adds r1, r1, r3
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #2
	beq _08025C18
	cmp r0, #4
	beq _08025C18
	cmp r0, #9
	beq _08025C18
	cmp r0, #0xd
	beq _08025C18
	movs r6, #1
_08025C18:
	movs r0, #0xf
	ands r0, r6
	cmp r0, #1
	bls _08025C4E
	cmp r0, #7
	bhi _08025C3C
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	bics r1, r0
	movs r0, #3
	cmp r1, sl
	bne _08025C50
	movs r0, #2
	b _08025C50
	.align 2, 0
_08025C38: .4byte 0xFFFFFC00
_08025C3C:
	cmp r0, #0xd
	bhi _08025C4E
	ldrb r0, [r7, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	bics r1, r0
	movs r0, #2
	cmp r1, sl
	bne _08025C50
_08025C4E:
	movs r0, #3
_08025C50:
	lsls r0, r0, #0x10
	movs r1, #0
	mov r8, r1
	str r0, [sp, #0x14]
	cmp r0, #0
	beq _08025D26
_08025C5C:
	mov r2, r8
	lsls r0, r2, #2
	mov r3, sp
	adds r4, r3, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0xf
	ands r0, r6
	cmp r0, #1
	bne _08025CBE
	movs r0, #0x80
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08025D16
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08025D16
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08025CAE
	mov r3, sl
	cmp r3, #0
	beq _08025D02
	ldr r1, [r4]
	adds r0, r5, #0
	bl PushoutToRight2
	b _08025D0A
_08025CAE:
	mov r0, sl
	cmp r0, #0
	bne _08025D02
	ldr r1, [r4]
	adds r0, r5, #0
	bl PushoutToRight2
	b _08025D0A
_08025CBE:
	cmp r0, #0
	beq _08025D16
	cmp r0, #0xd
	bhi _08025D16
	cmp r0, #7
	bhi _08025CEC
	ldr r0, [r7, #0x54]
	cmp r0, r5
	ble _08025D16
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r1, [r4]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08025D16
	ldr r1, [r4]
	adds r0, r5, #0
	bl PushoutToRight2
	b _08025D0A
_08025CEC:
	ldr r0, [r7, #0x54]
	cmp r0, r5
	bge _08025D16
	ldr r2, _08025D38 @ =0xFFFFF000
	adds r0, r5, r2
	ldr r1, [r4]
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08025D16
_08025D02:
	ldr r1, [r4]
	adds r0, r5, #0
	bl PushoutToLeft2
_08025D0A:
	adds r1, r0, #0
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r5, r5, r1
	mov sb, r6
_08025D16:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r8, r3
	ldr r1, [sp, #0x14]
	cmp r0, r1
	blo _08025C5C
_08025D26:
	mov r0, sb
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08025D38: .4byte 0xFFFFF000
