	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [sp, #0x24]
	ldr r2, [sp, #0x28]
	lsls r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	str r3, [sp]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r1, _080EE198 @ =StringOfsTable
	mov r8, r1
	lsrs r0, r0, #0x17
	adds r0, #0x3e
	add r0, r8
	ldrh r0, [r0]
	ldr r7, _080EE19C @ =gStringData
	adds r0, r0, r7
	movs r1, #7
	adds r2, r6, #0
	bl PrintString
	adds r4, #0x28
	lsls r4, r4, #1
	add r4, r8
	ldrh r0, [r4]
	adds r0, r0, r7
	movs r1, #9
	adds r2, r6, #0
	bl PrintString
	ldr r1, _080EE1A0 @ =0x0020F580
	adds r0, r5, #0
	bl __udivsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0xe
	adds r2, r6, #0
	bl PrintString
	ldr r1, _080EE1A4 @ =0x00034BC0
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0xf
	adds r2, r6, #0
	bl PrintString
	mov r3, r8
	ldrh r0, [r3, #0xe]
	adds r0, r0, r7
	movs r1, #0x10
	adds r2, r6, #0
	bl PrintString
	ldr r1, _080EE1A8 @ =0x00008CA0
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #6
	bl __umodsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x11
	adds r2, r6, #0
	bl PrintString
	movs r1, #0xe1
	lsls r1, r1, #4
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x12
	adds r2, r6, #0
	bl PrintString
	mov r1, r8
	ldrh r0, [r1, #0x10]
	adds r0, r0, r7
	movs r1, #0x13
	adds r2, r6, #0
	bl PrintString
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r5, #0
	bl __udivsi3
	movs r1, #6
	bl __umodsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x14
	adds r2, r6, #0
	bl PrintString
	adds r0, r5, #0
	movs r1, #0x3c
	bl __udivsi3
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x1e
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x15
	adds r2, r6, #0
	bl PrintString
	mov r3, sb
	cmp r3, #0
	beq _080EE17E
	cmp r3, #9
	bls _080EE162
	mov r0, sb
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, #0x3c
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x17
	adds r2, r6, #0
	bl PrintString
_080EE162:
	ldr r0, [sp]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, #0x3c
	add r0, r8
	ldrh r0, [r0]
	adds r0, r0, r7
	movs r1, #0x18
	adds r2, r6, #0
	bl PrintString
_080EE17E:
	mov r0, sl
	cmp r0, #1
	bne _080EE1AC
	ldr r0, _080EE198 @ =StringOfsTable
	ldrh r0, [r0, #6]
	ldr r1, _080EE19C @ =gStringData
	adds r0, r0, r1
	movs r1, #7
	adds r1, #0x12
	adds r2, r6, #0
	bl PrintString
	b _080EE1C4
	.align 2, 0
_080EE198: .4byte StringOfsTable
_080EE19C: .4byte gStringData
_080EE1A0: .4byte 0x0020F580
_080EE1A4: .4byte 0x00034BC0
_080EE1A8: .4byte 0x00008CA0
_080EE1AC:
	mov r1, sl
	cmp r1, #2
	bne _080EE1C4
	ldr r0, _080EE1D4 @ =StringOfsTable
	ldrh r0, [r0, #8]
	ldr r1, _080EE1D8 @ =gStringData
	adds r0, r0, r1
	movs r1, #7
	adds r1, #0x12
	adds r2, r6, #0
	bl PrintString
_080EE1C4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EE1D4: .4byte StringOfsTable
_080EE1D8: .4byte gStringData
