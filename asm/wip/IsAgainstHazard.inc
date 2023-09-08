	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov sl, r2
	movs r5, #0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r5, r0
	bhs _0802854C
	ldr r1, _08028524 @ =gOverworld
	mov r8, r1
	mov sb, r0
_080284B0:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r3, r0, #3
	ldr r1, _08028528 @ =0x020023DC
	adds r0, r3, r1
	ldr r4, [r0]
	subs r1, r6, r4
	adds r0, r3, #0
	add r0, r8
	mov ip, r0
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, ip
	ldrh r2, [r0]
	adds r1, r1, r2
	lsls r0, r2, #1
	cmp r1, r0
	bhs _08028542
	ldr r1, _0802852C @ =0x020023E0
	adds r0, r3, r1
	ldr r1, [r0]
	mov r0, sl
	subs r1, r0, r1
	movs r0, #0xed
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r0, r0, #1
	cmp r1, r0
	bhs _08028542
	movs r0, #0xeb
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ldr r1, _08028530 @ =0x0000880F
	ands r0, r1
	cmp r0, #1
	bne _08028542
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08028538
	lsrs r0, r2, #1
	subs r0, r4, r0
	subs r1, r0, r6
	ldr r0, _08028534 @ =0xFFFFFF00
	cmp r1, r0
	ble _08028542
_0802851E:
	movs r0, #1
	b _0802854E
	.align 2, 0
_08028524: .4byte gOverworld
_08028528: .4byte 0x020023DC
_0802852C: .4byte 0x020023E0
_08028530: .4byte 0x0000880F
_08028534: .4byte 0xFFFFFF00
_08028538:
	lsrs r0, r2, #1
	adds r0, r4, r0
	subs r1, r0, r6
	cmp r1, #0xff
	ble _0802851E
_08028542:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, sb
	blo _080284B0
_0802854C:
	movs r0, #0
_0802854E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
