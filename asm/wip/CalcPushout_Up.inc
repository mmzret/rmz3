	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r5, r1, #0
	ldr r6, _0800AD2C @ =gOverworld
_0800ACD8:
	movs r4, #0
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _0800AD3E
	mov sb, r0
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r3, r3, r6
	mov r8, r3
	movs r0, #0xee
	lsls r0, r0, #1
	adds r7, r6, r0
	mov ip, r6
_0800ACF8:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	lsls r2, r1, #1
	ldr r0, [r7]
	mov r3, sl
	subs r0, r3, r0
	adds r0, r0, r1
	cmp r2, r0
	bls _0800AD30
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r2, [r0]
	lsls r1, r2, #1
	mov r0, r8
	ldr r3, [r0]
	subs r0, r5, r3
	adds r0, r0, r2
	subs r0, #1
	cmp r1, r0
	bls _0800AD30
	subs r5, r3, r2
	b _0800ACD8
	.align 2, 0
_0800AD2C: .4byte gOverworld
_0800AD30:
	movs r1, #0x18
	add r8, r1
	adds r7, #0x18
	add ip, r1
	adds r4, #1
	cmp r4, sb
	blt _0800ACF8
_0800AD3E:
	adds r0, r5, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
