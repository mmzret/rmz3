	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08040A6E
	b _08040D02
_08040A6E:
	lsls r0, r0, #2
	ldr r1, _08040A78 @ =_08040A7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040A78: .4byte _08040A7C
_08040A7C: @ jump table
	.4byte _08040AAC @ case 0
	.4byte _08040ABC @ case 1
	.4byte _08040AD2 @ case 2
	.4byte _08040AEA @ case 3
	.4byte _08040B04 @ case 4
	.4byte _08040B20 @ case 5
	.4byte _08040B84 @ case 6
	.4byte _08040B96 @ case 7
	.4byte _08040BB0 @ case 8
	.4byte _08040BC2 @ case 9
	.4byte _08040CDC @ case 10
	.4byte _08040CEC @ case 11
_08040AAC:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040ABC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08040AD0
	b _08040D02
_08040AD0:
	b _08040CB8
_08040AD2:
	movs r0, #0x65
	bl PlaySound
	movs r0, #4
	strb r0, [r7, #0x12]
	ldr r1, _08040B00 @ =0x0000A41B
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040AEA:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040AFE
	b _08040D02
_08040AFE:
	b _08040CB8
	.align 2, 0
_08040B00: .4byte 0x0000A41B
_08040B04:
	movs r0, #0x67
	bl PlaySound
	ldr r0, _08040B78 @ =0xFFFFFE00
	str r0, [r7, #0x60]
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _08040B7C @ =0x0000A41C
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B20:
	ldr r0, [r7, #0x60]
	adds r0, #0x40
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08040B30
	str r1, [r7, #0x60]
_08040B30:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08040B4E
	cmp r1, #0
	ble _08040B4E
	movs r0, #1
	strb r0, [r7, #0x12]
	ldr r1, _08040B80 @ =0x0000A41D
	adds r0, r7, #0
	bl SetMotion
_08040B4E:
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldr r2, [r7, #0x58]
	subs r1, r0, r2
	str r1, [sp, #0xc]
	cmp r1, #0
	bge _08040B6E
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ble _08040B6E
	adds r0, r2, r1
	str r0, [r7, #0x58]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B6E:
	adds r0, r7, #0
	bl UpdateEntityAnim
	b _08040D02
	.align 2, 0
_08040B78: .4byte 0xFFFFFE00
_08040B7C: .4byte 0x0000A41C
_08040B80: .4byte 0x0000A41D
_08040B84:
	movs r0, #4
	strb r0, [r7, #0x12]
	ldr r1, _08040BAC @ =0x0000A41B
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040B96:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040BAA
	b _08040D02
_08040BAA:
	b _08040CB8
	.align 2, 0
_08040BAC: .4byte 0x0000A41B
_08040BB0:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldr r1, _08040CC0 @ =0x0000A419
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040BC2:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _08040BDC
	movs r0, #0x66
	bl PlaySound
_08040BDC:
	ldrb r0, [r7, #0x12]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040CAE
	adds r0, r7, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08040C00
	cmp r0, #4
	beq _08040C00
	cmp r0, #5
	bne _08040CAE
_08040C00:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r7, #0x58]
	ldr r1, _08040CC4 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #0x14]
	ldr r6, _08040CC8 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _08040CCC @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _08040CD0 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r0, r0, #1
	add r1, sp, #0x14
	mov r8, r1
	movs r2, #0x55
	rsbs r2, r2, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	mov r0, r8
	str r2, [r0, #4]
	ldr r1, _08040CD4 @ =0x0836206C
	mov sl, r1
	str r1, [sp]
	movs r0, #0x18
	mov sb, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #0xc
	mov r2, r8
	movs r3, #0
	bl FUN_080b834c
	ldr r0, [r7, #0x54]
	ldr r1, _08040CD8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r7, #0x58]
	ldr r1, _08040CC4 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #0x60
	str r0, [sp, #0x14]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r0, r0, #1
	movs r2, #0x20
	rsbs r2, r2, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	movs r1, #0xff
	ands r0, r1
	subs r2, r2, r0
	mov r0, r8
	str r2, [r0, #4]
	mov r1, sl
	str r1, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #0x19
	str r0, [sp, #8]
	adds r0, r7, #0
	add r1, sp, #0xc
	mov r2, r8
	movs r3, #0
	bl FUN_080b8454
_08040CAE:
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08040D02
_08040CB8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08040D02
	.align 2, 0
_08040CC0: .4byte 0x0000A419
_08040CC4: .4byte 0xFFFFEC00
_08040CC8: .4byte RNG_0202f388
_08040CCC: .4byte 0x000343FD
_08040CD0: .4byte 0x00269EC3
_08040CD4: .4byte 0x0836206C
_08040CD8: .4byte 0xFFFFF800
_08040CDC:
	movs r1, #0xa4
	lsls r1, r1, #8
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08040CEC:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, _08040D14 @ =gStageRun
	ldrb r0, [r0, #0x12]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08040D02
	strb r1, [r7, #0xd]
	strb r1, [r7, #0xe]
_08040D02:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040D14: .4byte gStageRun
