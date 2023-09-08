	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	mov sb, r1
	adds r6, r2, #0
	movs r2, #0
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r2, r0
	bhs _08028282
	ldr r5, _0802826C @ =gOverworld
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
_0802820E:
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, ip
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r3, r0, #3
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r0, r3, r0
	ldr r1, [r0]
	mov r7, sb
	subs r1, r7, r1
	adds r4, r3, r5
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r4, r7
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08028270
	mov r1, r8
	adds r0, r3, r1
	ldr r1, [r0]
	subs r1, r6, r1
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08028270
	subs r7, #4
	adds r0, r4, r7
	ldrh r1, [r0]
	mov r0, ip
	bl appendHazardID
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	b _08028284
	.align 2, 0
_0802826C: .4byte gOverworld
_08028270:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r2, r0
	blo _0802820E
_08028282:
	movs r0, #0
_08028284:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
