	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov r8, r1
	adds r7, r2, #0
	movs r2, #0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r2, r0
	bhs _0802847A
	ldr r5, _0802846C @ =gOverworld
	adds r1, #0x50
	adds r1, r1, r5
	mov sl, r1
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	adds r6, r0, #0
_0802841C:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r3, r0, #3
	mov r1, sl
	adds r0, r3, r1
	ldr r1, [r0]
	mov r0, r8
	subs r1, r0, r1
	adds r0, r3, r5
	mov ip, r0
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08028470
	mov r1, sb
	adds r0, r3, r1
	ldr r1, [r0]
	subs r1, r7, r1
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08028470
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	b _0802847C
	.align 2, 0
_0802846C: .4byte gOverworld
_08028470:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r6
	blo _0802841C
_0802847A:
	movs r0, #0
_0802847C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
