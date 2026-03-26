	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r2, #0
	ldr r4, _08009244 @ =gOverworld
	movs r3, #0xe8
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrb r3, [r2]
	movs r2, #0x7f
	ands r2, r3
	ldr r3, _08009248 @ =gStageLandscape
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r3, [r2]
	ldr r2, _0800924C @ =0x000007E4
	adds r7, r4, r2
	ldrh r2, [r5]
	lsls r2, r2, #0x11
	lsrs r6, r2, #0x10
	adds r5, #2
	ldrh r2, [r5]
	mov r8, r2
	adds r5, #2
	ldr r2, [r3, #0xc]
	ldrb r3, [r2, #2]
	lsls r2, r3, #4
	subs r2, r2, r3
	muls r1, r2, r1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r7, r1, r7
	mov r3, r8
	lsls r0, r3, #0x10
	movs r4, #0
	cmp r0, #0
	ble _08009228
	lsls r6, r6, #0x10
	asrs r0, r6, #0x10
	mov sl, r0
	lsls r2, r2, #1
	mov sb, r2
_08009208:
	adds r0, r5, #0
	adds r1, r7, #0
	asrs r2, r6, #0x10
	bl CopyMemory
	add r5, sl
	add r7, sb
	lsls r1, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r1, r2
	lsrs r4, r1, #0x10
	mov r3, r8
	lsls r0, r3, #0x10
	cmp r1, r0
	blt _08009208
_08009228:
	ldr r0, _08009244 @ =gOverworld
	movs r1, #0xb0
	lsls r1, r1, #0xa
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009244: .4byte gOverworld
_08009248: .4byte gStageLandscape
_0800924C: .4byte 0x000007E4