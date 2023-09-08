	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov sb, r2
	adds r0, r6, #0
	movs r1, #0xf
	bl __udivsi3
	adds r4, r0, #0
	mov r0, sb
	movs r1, #0xa
	bl __udivsi3
	ldr r2, [r5, #0xc]
	ldrb r1, [r2]
	muls r0, r1, r0
	adds r0, r0, r4
	adds r0, r0, r2
	ldrb r0, [r0, #4]
	mov r8, r0
	adds r0, r6, #0
	movs r1, #0xf
	bl __umodsi3
	adds r4, r0, #0
	mov r0, sb
	movs r1, #0xa
	bl __umodsi3
	lsls r1, r0, #4
	subs r1, r1, r0
	movs r0, #0x96
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r4
	adds r1, r1, r0
	ldr r0, [r5, #8]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
