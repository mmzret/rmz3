	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	movs r1, #2
	ldrsh r2, [r5, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	ldrh r2, [r5, #6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x11
	adds r1, r1, r2
	adds r1, #1
	bl GetGroundMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08026D0C @ =0x0000800E
	cmp r1, r0
	beq _08026D40
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _08026D10
	movs r0, #0xf
	ands r1, r0
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _08026D10
	movs r0, #3
	b _08026D42
	.align 2, 0
_08026D0C: .4byte 0x0000800E
_08026D10:
	ldr r0, [r4, #0x54]
	movs r1, #2
	ldrsh r2, [r5, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08026D2C @ =0x0000800F
	cmp r1, r0
	bne _08026D30
	movs r0, #1
	b _08026D42
	.align 2, 0
_08026D2C: .4byte 0x0000800F
_08026D30:
	ldr r0, _08026D3C @ =0x0000800E
	cmp r1, r0
	beq _08026D40
	movs r0, #0
	b _08026D42
	.align 2, 0
_08026D3C: .4byte 0x0000800E
_08026D40:
	movs r0, #2
_08026D42:
	pop {r4, r5}
	pop {r1}
	bx r1
