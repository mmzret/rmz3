	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r2, [r5, #0x58]
	adds r2, r2, r0
	ldrh r0, [r1, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r2, r2, r0
	adds r6, r2, #1
	ldr r1, [r5, #0x54]
	adds r0, r5, #0
	adds r2, r6, #0
	bl AppendHazardID
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	cmp r1, #0
	bne _08026DEE
	ldr r0, [r5, #0x54]
	adds r1, r6, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	ldr r1, _08026D98 @ =0x800E0000
	cmp r0, r1
	beq _08026DFA
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026D9C
	ldr r0, [r5, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r4, r0, r1
	b _08026DA2
	.align 2, 0
_08026D98: .4byte 0x800E0000
_08026D9C:
	ldr r0, [r5, #0x54]
	ldr r2, _08026DC8 @ =0xFFFFFB00
	adds r4, r0, r2
_08026DA2:
	adds r0, r4, #0
	adds r1, r6, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08026DCC @ =0x0000800E
	cmp r1, r0
	beq _08026DF8
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08026DD4
	ldr r0, [r5, #0x54]
	ldr r1, _08026DD0 @ =0xFFFFFE00
	adds r4, r0, r1
	b _08026DDC
	.align 2, 0
_08026DC8: .4byte 0xFFFFFB00
_08026DCC: .4byte 0x0000800E
_08026DD0: .4byte 0xFFFFFE00
_08026DD4:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r4, r0, r2
_08026DDC:
	adds r0, r4, #0
	adds r1, r6, #0
	bl GetMetatileAttr
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08026DF4 @ =0x0000800E
	cmp r1, r0
	beq _08026DF8
_08026DEE:
	movs r0, #0
	b _08026DFC
	.align 2, 0
_08026DF4: .4byte 0x0000800E
_08026DF8:
	str r4, [r5, #0x54]
_08026DFA:
	movs r0, #2
_08026DFC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
