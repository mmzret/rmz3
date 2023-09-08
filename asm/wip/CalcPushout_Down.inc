	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	ldr r0, _0800ADC8 @ =gOverworld
	mov ip, r0
_0800AD62:
	movs r5, #0
	movs r0, #0xe9
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r5, r0
	bge _0800ADDA
	movs r1, #0xf0
	lsls r1, r1, #1
	add r1, ip
	mov r8, r1
	movs r7, #0xee
	lsls r7, r7, #1
	add r7, ip
	mov r3, ip
	mov sb, r0
_0800AD82:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r7]
	mov r4, sl
	subs r0, r4, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800ADCC
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r2, [r0]
	lsls r1, r2, #1
	mov r0, r8
	ldr r4, [r0]
	subs r0, r6, r4
	adds r0, r0, r2
	subs r0, #1
	cmp r1, r0
	bls _0800ADCC
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800ADCC
	adds r0, r4, r2
	adds r6, r0, #1
	b _0800AD62
	.align 2, 0
_0800ADC8: .4byte gOverworld
_0800ADCC:
	movs r4, #0x18
	add r8, r4
	adds r7, #0x18
	adds r3, #0x18
	adds r5, #1
	cmp r5, sb
	blt _0800AD82
_0800ADDA:
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
