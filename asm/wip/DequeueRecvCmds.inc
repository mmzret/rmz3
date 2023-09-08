	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r2, _080028A8 @ =0x02000004
	ldr r1, _080028AC @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080028B0 @ =gLink
	ldr r3, _080028B4 @ =0x00000995
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	bne _080028B8
	movs r3, #0
	mov r8, r7
	ldrb r6, [r7, #3]
_08002874:
	movs r2, #0
	adds r5, r3, #1
	cmp r2, r6
	bhs _08002898
	lsls r0, r3, #3
	mov r1, ip
	adds r3, r0, r1
	movs r4, #0
	mov r0, r8
	ldrb r1, [r0, #3]
_08002888:
	lsls r0, r2, #1
	adds r0, r0, r3
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r1
	blo _08002888
_08002898:
	lsls r0, r5, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _08002874
	movs r0, #1
	strb r0, [r7, #0xc]
	b _08002930
	.align 2, 0
_080028A8: .4byte 0x02000004
_080028AC: .4byte 0x04000208
_080028B0: .4byte gLink
_080028B4: .4byte 0x00000995
_080028B8:
	movs r3, #0
	ldrb r1, [r7, #3]
	mov sb, r1
	movs r2, #0x85
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	mov sl, r7
_080028C8:
	movs r2, #0
	adds r5, r3, #1
	cmp r2, sb
	bhs _08002904
	lsls r0, r3, #3
	mov r1, ip
	adds r6, r0, r1
	ldr r0, _08002948 @ =0x02001EA4
	ldrb r1, [r0]
	lsls r1, r1, #1
	mov r0, sl
	ldrb r4, [r0, #3]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r3, r1, r0
_080028E8:
	lsls r1, r2, #1
	adds r1, r1, r6
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #5
	adds r0, r3, r0
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r4
	blo _080028E8
_08002904:
	lsls r0, r5, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _080028C8
	adds r2, r7, #0
	ldr r3, _0800294C @ =0x00000995
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	movs r3, #0
	strb r0, [r1]
	ldr r0, _08002950 @ =0x00000994
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _0800292E
	strb r3, [r2]
_0800292E:
	strb r3, [r7, #0xc]
_08002930:
	ldr r1, _08002954 @ =0x04000208
	ldr r2, _08002958 @ =0x02000004
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002948: .4byte 0x02001EA4
_0800294C: .4byte 0x00000995
_08002950: .4byte 0x00000994
_08002954: .4byte 0x04000208
_08002958: .4byte 0x02000004
