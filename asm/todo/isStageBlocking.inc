	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	mov r8, r1
	mov ip, r2
	adds r4, #1
	ldr r2, _0800A5D0 @ =gOverworld
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r4, r1
	bge _0800A5E0
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r2, r3
	mov sb, r1
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r6, r1, r0
	movs r7, #0xee
	lsls r7, r7, #1
	adds r0, r1, r7
	adds r5, r0, r2
	adds r3, r1, r2
_0800A59C:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r5]
	mov r7, r8
	subs r0, r7, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800A5D4
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	lsls r2, r0, #1
	ldr r1, [r6]
	mov r7, ip
	subs r1, r7, r1
	adds r1, r1, r0
	subs r1, #1
	cmp r2, r1
	bls _0800A5D4
	adds r0, r4, #0
	b _0800A5E4
	.align 2, 0
_0800A5D0: .4byte gOverworld
_0800A5D4:
	adds r6, #0x18
	adds r5, #0x18
	adds r3, #0x18
	adds r4, #1
	cmp r4, sb
	blt _0800A59C
_0800A5E0:
	movs r0, #1
	rsbs r0, r0, #0
_0800A5E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
