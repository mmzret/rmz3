	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r3, _08003758 @ =gGraphicTransferManager
	ldr r5, [r3]
	adds r0, r3, #0
	adds r0, #0xc8
	ldr r4, [r0]
	cmp r4, #0
	beq _08003718
	ldr r1, _0800375C @ =0x040000D4
	str r4, [r1]
	adds r0, #4
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	str r0, [r1, #4]
	adds r0, r3, #0
	adds r0, #0xc4
	ldr r2, [r0]
	lsrs r2, r2, #2
	movs r0, #0x84
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r0, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	str r0, [sp]
	mov r3, sp
	str r3, [r1]
	str r4, [r1, #4]
	movs r0, #0x85
	lsls r0, r0, #0x18
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08003718:
	cmp r5, #0
	beq _080037AE
	ldr r7, _08003760 @ =0x001FFFFF
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r6, r0, #2
_08003724:
	subs r6, #0xc
	subs r5, #1
	ldr r0, _08003764 @ =0x02001F04
	adds r3, r6, r0
	ldrb r0, [r3]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1e
	cmp r0, #0
	beq _080037A2
	cmp r0, #1
	bne _08003780
	ldr r0, [r3]
	lsrs r2, r0, #2
	cmp r2, #0x1f
	bgt _08003768
	ldr r0, [r3, #8]
	ldr r1, [r3, #4]
	movs r3, #0xc0
	lsls r3, r3, #0x13
	adds r1, r1, r3
	lsrs r2, r2, #1
	ands r2, r7
	bl CpuSet
	b _080037AA
	.align 2, 0
_08003758: .4byte gGraphicTransferManager
_0800375C: .4byte 0x040000D4
_08003760: .4byte 0x001FFFFF
_08003764: .4byte gGraphicTransferManager+4
_08003768:
	ldr r4, [r3, #8]
	ldr r0, [r3, #4]
	movs r3, #0xc0
	lsls r3, r3, #0x13
	adds r1, r0, r3
	adds r0, r2, #0
	asrs r2, r0, #2
	ands r2, r7
	adds r0, r4, #0
	bl CpuFastSet
	b _080037AA
_08003780:
	ldr r0, [r3, #8]
	str r0, [sp]
	ldr r0, [r3, #4]
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r0, r2
	ldr r0, [r3]
	lsrs r0, r0, #2
	asrs r2, r0, #2
	ands r2, r7
	movs r0, #0x80
	lsls r0, r0, #0x11
	orrs r2, r0
	mov r0, sp
	bl CpuFastSet
	b _080037AA
_080037A2:
	ldr r0, [r3, #8]
	ldr r1, [r3, #4]
	bl LoadGraphic
_080037AA:
	cmp r5, #0
	bne _08003724
_080037AE:
	ldr r1, _080037BC @ =gGraphicTransferManager
	movs r0, #0
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080037BC: .4byte gGraphicTransferManager
