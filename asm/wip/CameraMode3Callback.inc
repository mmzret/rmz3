	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0x1c]
	adds r1, r0, #0
	cmp r1, #0
	bne _0801A8FC
	strh r1, [r7, #0x22]
	adds r0, #1
	strb r0, [r7, #0x1c]
_0801A8FC:
	ldr r2, [r7, #0x48]
	ldr r1, [r2]
	ldr r0, [r7, #0x4c]
	adds r5, r1, r0
	ldr r1, [r2, #4]
	ldr r0, [r7, #0x54]
	adds r6, r1, r0
	ldr r0, [r7, #0x30]
	str r0, [sp]
	ldr r1, [r7, #0x34]
	str r1, [sp, #4]
	subs r2, r0, r5
	cmp r2, #0
	ble _0801A91C
	subs r0, r0, r2
	str r0, [sp]
_0801A91C:
	cmp r2, #0
	bge _0801A926
	ldr r0, [sp]
	subs r0, r0, r2
	str r0, [sp]
_0801A926:
	subs r1, r1, r6
	ldr r0, _0801A960 @ =0xFFFFF000
	cmp r1, r0
	ble _0801A938
	ldr r0, [sp, #4]
	ldr r2, _0801A960 @ =0xFFFFF000
	adds r0, r0, r2
	subs r0, r0, r1
	str r0, [sp, #4]
_0801A938:
	ldr r0, _0801A964 @ =0xFFFFE800
	cmp r1, r0
	bge _0801A948
	ldr r0, [sp, #4]
	ldr r2, _0801A964 @ =0xFFFFE800
	adds r0, r0, r2
	subs r0, r0, r1
	str r0, [sp, #4]
_0801A948:
	add r4, sp, #8
	mov r0, sp
	adds r1, r4, #0
	bl CalcCameraDelta
	ldrb r1, [r7, #0x19]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801A968
	ldr r5, [sp]
	b _0801A96E
	.align 2, 0
_0801A960: .4byte 0xFFFFF000
_0801A964: .4byte 0xFFFFE800
_0801A968:
	ldr r1, [sp]
	ldr r0, [sp, #8]
	adds r5, r1, r0
_0801A96E:
	ldrb r1, [r7, #0x19]
	movs r0, #0x20
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _0801A97E
	ldr r6, [sp, #4]
	b _0801A984
_0801A97E:
	ldr r1, [sp, #4]
	ldr r0, [r4, #4]
	adds r6, r1, r0
_0801A984:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0801A992
	str r6, [r7, #0x34]
	str r5, [r7, #0x30]
	b _0801A9CE
_0801A992:
	ldr r1, [r7, #0x30]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	cmp r0, r5
	blt _0801A9A6
	ldr r2, _0801A9AC @ =0xFFFFFC00
	adds r0, r1, r2
	cmp r0, r5
	ble _0801A9B0
_0801A9A6:
	str r0, [r7, #0x30]
	b _0801A9B2
	.align 2, 0
_0801A9AC: .4byte 0xFFFFFC00
_0801A9B0:
	str r5, [r7, #0x30]
_0801A9B2:
	ldr r1, [r7, #0x34]
	subs r0, r1, r6
	cmp r0, #0
	blt _0801A9C2
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r6
	b _0801A9CA
_0801A9C2:
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r6
	adds r0, #7
_0801A9CA:
	asrs r0, r0, #3
	str r0, [r7, #0x34]
_0801A9CE:
	ldrb r1, [r7, #0x19]
	adds r0, r7, #0
	bl focus
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
