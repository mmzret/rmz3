	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r0, [r0, #0x54]
	mov sl, r0
	mov r1, ip
	ldr r0, [r1, #0x58]
	ldr r2, _08027128 @ =0xFFFFF100
	adds r2, r2, r0
	mov sb, r2
	movs r1, #0xc6
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	ldr r2, _0802712C @ =gOverworld
	movs r3, #0xe9
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r4, r0
	bhs _0802711A
	adds r6, r2, #0
	adds r5, r1, #0
	mov r8, r0
_080270B6:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r2, r0, #3
	ldr r7, _08027130 @ =0x020023DC
	adds r0, r2, r7
	ldr r1, [r0]
	mov r0, sl
	subs r1, r0, r1
	adds r3, r2, r6
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	movs r7, #0xf8
	lsls r7, r7, #5
	adds r0, r7, r0
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027110
	ldr r1, _08027134 @ =0x020023E0
	adds r0, r2, r1
	ldr r1, [r0]
	mov r2, sb
	subs r1, r2, r1
	movs r7, #0xed
	lsls r7, r7, #1
	adds r0, r3, r7
	ldrh r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #5
	adds r0, r2, r0
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08027110
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, ip
	ldrb r3, [r5]
	adds r0, r0, r3
	strb r4, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08027110:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r8
	blo _080270B6
_0802711A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027128: .4byte 0xFFFFF100
_0802712C: .4byte gOverworld
_08027130: .4byte 0x020023DC
_08027134: .4byte 0x020023E0
