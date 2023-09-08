	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	movs r1, #2
	ldrsh r2, [r5, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08026BD4 @ =0x0000800F
	cmp r1, r0
	bne _08026BD8
	movs r0, #1
	b _08026C02
	.align 2, 0
_08026BD4: .4byte 0x0000800F
_08026BD8:
	ldr r6, _08026BE4 @ =0x0000800E
	cmp r1, r6
	bne _08026BE8
	movs r0, #2
	b _08026C02
	.align 2, 0
_08026BE4: .4byte 0x0000800E
_08026BE8:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	movs r3, #2
	ldrsh r2, [r5, r3]
	ldr r1, [r1, #4]
	adds r1, r1, r2
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #3
_08026C02:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
