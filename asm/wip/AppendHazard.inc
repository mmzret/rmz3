	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r2
	mov r8, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0800A6C4 @ =gOverworld
	movs r0, #0xe9
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrb r3, [r4]
	adds r0, r3, #1
	mov ip, r2
	cmp r0, #0x1f
	ble _0800A61A
	b _0800A728
_0800A61A:
	strb r0, [r4]
	adds r6, r3, #0
	lsls r2, r6, #1
	mov sl, r2
	adds r0, r2, r6
	lsls r4, r0, #3
	mov r3, ip
	adds r0, r4, r3
	movs r2, #0xea
	lsls r2, r2, #1
	adds r7, r0, r2
	strh r5, [r7]
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	add r1, ip
	adds r1, r4, r1
	mov r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r2
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #1
	add r1, ip
	adds r1, r4, r1
	mov r0, r8
	movs r3, #2
	ldrsh r2, [r0, r3]
	mov r3, sb
	ldr r0, [r3, #4]
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0
	ldr r0, _0800A6C8 @ =0x000001D3
	add r0, ip
	ldrb r0, [r0]
	cmp r3, r0
	bge _0800A6D4
	mov r5, ip
	mov sb, r4
	ldrh r4, [r7]
	mov r1, ip
	ldr r7, _0800A6CC @ =0x000004D4
	adds r2, r0, #0
_0800A67E:
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, r4
	beq _0800A68E
	adds r1, #0x18
	adds r3, #1
	cmp r3, r2
	blt _0800A67E
_0800A68E:
	ldr r1, _0800A6C8 @ =0x000001D3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _0800A6D4
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r2, r5, r0
	add r2, sb
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #3
	ldr r3, _0800A6D0 @ =0x000004DC
	adds r0, r5, r3
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r0, #0xf4
	lsls r0, r0, #1
	adds r2, r5, r0
	add r2, sb
	adds r3, #4
	adds r0, r5, r3
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0800A704
	.align 2, 0
_0800A6C4: .4byte gOverworld
_0800A6C8: .4byte 0x000001D3
_0800A6CC: .4byte 0x000004D4
_0800A6D0: .4byte 0x000004DC
_0800A6D4:
	lsls r3, r6, #1
	adds r1, r3, r6
	lsls r1, r1, #3
	movs r2, #0xf2
	lsls r2, r2, #1
	add r2, ip
	adds r2, r1, r2
	movs r0, #0xee
	lsls r0, r0, #1
	add r0, ip
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r2]
	movs r2, #0xf4
	lsls r2, r2, #1
	add r2, ip
	adds r2, r1, r2
	movs r0, #0xf0
	lsls r0, r0, #1
	add r0, ip
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	mov sl, r3
_0800A704:
	mov r1, sl
	adds r0, r1, r6
	lsls r0, r0, #3
	mov r3, ip
	adds r2, r0, r3
	mov r1, r8
	ldrh r0, [r1, #4]
	lsrs r0, r0, #1
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #6]
	lsrs r0, r0, #1
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
_0800A728:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0