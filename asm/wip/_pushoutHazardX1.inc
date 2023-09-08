	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r1
	str r2, [sp]
	mov sb, r3
	movs r0, #0
	str r0, [sp, #4]
	str r0, [r3, #4]
	str r0, [r3]
	mov sl, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [sp, #4]
	ldrb r0, [r0]
	cmp r2, r0
	bhs _08027EF0
_08027E28:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	add r0, sl
	ldrb r6, [r0]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r2, r0, #3
	ldr r1, _08027E98 @ =gOverworld
	adds r3, #0x80
	adds r0, r1, r3
	adds r7, r2, r0
	ldr r1, [r7]
	mov r0, r8
	subs r1, r0, r1
	ldr r0, _08027E98 @ =gOverworld
	adds r3, r2, r0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027EDA
	ldr r1, _08027E9C @ =0x020023E0
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r2, [sp]
	subs r1, r2, r1
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027EDA
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl appendHazardID
	ldr r1, [r7]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08027EA0
	ldrh r0, [r4]
	adds r0, r1, r0
	mov r2, r8
	subs r0, r0, r2
	mov r3, sb
	str r0, [r3]
	b _08027EAE
	.align 2, 0
_08027E98: .4byte gOverworld
_08027E9C: .4byte 0x020023E0
_08027EA0:
	ldrh r0, [r4]
	subs r0, r1, r0
	mov r1, r8
	subs r0, r0, r1
	subs r0, #1
	mov r2, sb
	str r0, [r2]
_08027EAE:
	mov r3, sb
	ldr r1, [r3]
	cmp r1, #0
	beq _08027EDA
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r2, _08027F04 @ =gOverworld
	adds r0, r0, r2
	movs r3, #0xeb
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	add r8, r1
	ldr r0, _08027F08 @ =0x0000018F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08027EDA:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp sl, r0
	blo _08027E28
_08027EF0:
	ldr r0, [sp, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08027F04: .4byte gOverworld
_08027F08: .4byte 0x0000018F
