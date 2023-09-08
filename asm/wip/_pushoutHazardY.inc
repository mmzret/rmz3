	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	str r1, [sp]
	adds r6, r2, #0
	mov sb, r3
	movs r0, #0
	str r0, [sp, #4]
	str r0, [r3, #4]
	str r0, [r3]
	mov sl, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #4]
	ldrb r0, [r0]
	cmp r2, r0
	bhs _08028010
_08027F38:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r7, r3
	add r0, sl
	ldrb r0, [r0]
	mov r8, r0
	lsls r0, r0, #1
	add r0, r8
	lsls r2, r0, #3
	ldr r4, _08027FAC @ =gOverworld
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r3, [sp]
	subs r1, r3, r1
	adds r3, r2, r4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027FFA
	ldr r0, _08027FB0 @ =0x020023E0
	adds r5, r2, r0
	ldr r1, [r5]
	subs r1, r6, r1
	movs r2, #0xed
	lsls r2, r2, #1
	adds r4, r3, r2
	ldrh r0, [r4]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027FFA
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl appendHazardID
	ldr r1, [r5]
	cmp r1, r6
	bge _08027FC0
	ldr r0, [r7, #0x58]
	cmp r6, r0
	bne _08027FB4
	ldrh r0, [r4]
	subs r0, r1, r0
	subs r0, r0, r6
	subs r0, #1
	mov r2, sb
	str r0, [r2, #4]
	b _08027FCC
	.align 2, 0
_08027FAC: .4byte gOverworld
_08027FB0: .4byte 0x020023E0
_08027FB4:
	ldrh r0, [r4]
	adds r0, r1, r0
	subs r0, r0, r6
	mov r3, sb
	str r0, [r3, #4]
	b _08027FCC
_08027FC0:
	ldrh r0, [r4]
	subs r0, r1, r0
	subs r0, r0, r6
	subs r0, #1
	mov r4, sb
	str r0, [r4, #4]
_08027FCC:
	mov r0, sb
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _08027FFA
	mov r2, r8
	lsls r0, r2, #1
	add r0, r8
	lsls r0, r0, #3
	ldr r3, _08028024 @ =gOverworld
	adds r0, r0, r3
	movs r4, #0xeb
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r6, r6, r1
	ldr r0, _08028028 @ =0x0000018F
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_08027FFA:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp sl, r0
	blo _08027F38
_08028010:
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
_08028024: .4byte gOverworld
_08028028: .4byte 0x0000018F
