	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r1, [r4]
	cmp r1, #5
	bne _080ECD3A
	b _080ECE76
_080ECD3A:
	cmp r1, #5
	bgt _080ECD5C
	cmp r1, #2
	beq _080ECDE4
	cmp r1, #2
	bgt _080ECD50
	cmp r1, #0
	beq _080ECD88
	cmp r1, #1
	beq _080ECDA8
	b _080ECFCC
_080ECD50:
	cmp r1, #3
	beq _080ECE08
	cmp r1, #4
	bne _080ECD5A
	b _080ECE4C
_080ECD5A:
	b _080ECFCC
_080ECD5C:
	cmp r1, #8
	bne _080ECD62
	b _080ECEC0
_080ECD62:
	cmp r1, #8
	bgt _080ECD74
	cmp r1, #6
	bne _080ECD6C
	b _080ECE80
_080ECD6C:
	cmp r1, #7
	bne _080ECD72
	b _080ECEB0
_080ECD72:
	b _080ECFCC
_080ECD74:
	cmp r1, #0xa
	bne _080ECD7A
	b _080ECF8A
_080ECD7A:
	cmp r1, #0xa
	bge _080ECD80
	b _080ECEDE
_080ECD80:
	cmp r1, #0x80
	bne _080ECD86
	b _080ECFB4
_080ECD86:
	b _080ECFCC
_080ECD88:
	ldr r2, _080ECDA0 @ =0x00000252
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080ECDA4 @ =0x00000251
	adds r1, r5, r3
	movs r0, #0x3c
	strb r0, [r1]
	movs r0, #1
	strb r0, [r4]
	bl sio_0800133c
	b _080ECFCC
	.align 2, 0
_080ECDA0: .4byte 0x00000252
_080ECDA4: .4byte 0x00000251
_080ECDA8:
	bl sio_080013a8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ECDCC
	movs r0, #6
	bl PlaySound
	ldr r1, _080ECDC8 @ =0x00000253
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #4
	strb r0, [r4]
	b _080ECFCC
	.align 2, 0
_080ECDC8: .4byte 0x00000253
_080ECDCC:
	ldr r2, _080ECDE0 @ =0x00000251
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080ECE38
	movs r0, #2
	strb r0, [r4]
	bl sio_0800100c
	b _080ECFCC
	.align 2, 0
_080ECDE0: .4byte 0x00000251
_080ECDE4:
	ldr r3, _080ECE00 @ =0x00000252
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080ECE04 @ =0x00000251
	adds r1, r5, r0
	movs r0, #0x3c
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4]
	bl sio_08001538
	b _080ECFCC
	.align 2, 0
_080ECE00: .4byte 0x00000252
_080ECE04: .4byte 0x00000251
_080ECE08:
	bl sio_080015e8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080ECE2C
	ldr r0, _080ECE24 @ =0x020014C0
	movs r1, #0
	strh r2, [r0, #0x10]
	ldr r2, _080ECE28 @ =0x00000253
	adds r0, r5, r2
	strb r1, [r0]
	b _080ECFA8
	.align 2, 0
_080ECE24: .4byte 0x020014C0
_080ECE28: .4byte 0x00000253
_080ECE2C:
	ldr r3, _080ECE40 @ =0x00000251
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r2, r0, #0
	cmp r2, #0
	beq _080ECE44
_080ECE38:
	subs r0, #1
	strb r0, [r1]
	b _080ECFCC
	.align 2, 0
_080ECE40: .4byte 0x00000251
_080ECE44:
	strb r2, [r4]
	bl sio_08001778
	b _080ECFCC
_080ECE4C:
	bl sio_080013d0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080ECE70
	ldr r1, _080ECE64 @ =0x00000253
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080ECE68
	movs r0, #5
	b _080ECE72
	.align 2, 0
_080ECE64: .4byte 0x00000253
_080ECE68:
	cmp r0, #2
	bne _080ECEBC
	movs r0, #7
	b _080ECE72
_080ECE70:
	movs r0, #0x80
_080ECE72:
	strb r0, [r4]
	b _080ECEBC
_080ECE76:
	movs r0, #6
	strb r0, [r4]
	bl sio_080014ec
	b _080ECEB8
_080ECE80:
	bl sio_08001410
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080ECEAA
	cmp r2, #1
	bne _080ECEBC
	movs r0, #2
	strb r0, [r4]
	bl sio_08001514
	movs r2, #0x93
	lsls r2, r2, #2
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
	bl sio_0800100c
	b _080ECEBC
_080ECEAA:
	movs r0, #0x80
	strb r0, [r4]
	b _080ECEBC
_080ECEB0:
	movs r0, #8
	strb r0, [r4]
	bl sio_0800100c
_080ECEB8:
	bl sio_080013d0
_080ECEBC:
	movs r0, #1
	b _080ECFCE
_080ECEC0:
	bl sio_080013f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080ECEBC
	movs r0, #0
	movs r1, #2
	strb r1, [r4]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r5, r3
	str r0, [r1]
	bl sio_0800100c
	b _080ECEBC
_080ECEDE:
	bl sio_08001570
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080ECF80
	ldr r0, _080ECF0C @ =0x020014C0
	ldrh r2, [r0, #0x10]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _080ECFCC
	adds r1, r2, #0
	cmp r1, #0xff
	bne _080ECF10
	movs r0, #0x93
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	b _080ECF3C
	.align 2, 0
_080ECF0C: .4byte 0x020014C0
_080ECF10:
	movs r0, #0x81
	lsls r0, r0, #1
	cmp r1, r0
	bne _080ECF22
	movs r2, #0x93
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #5
	b _080ECF3C
_080ECF22:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080ECF34
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #6
	b _080ECF3C
_080ECF34:
	movs r0, #0x93
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #3
_080ECF3C:
	str r0, [r1]
	ldr r1, _080ECF74 @ =gSystemSavedataManager
	ldr r2, _080ECF78 @ =0x08385F9C
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	subs r1, #0xd8
	ldrb r2, [r1]
	ldr r1, _080ECF7C @ =gSineTable
	adds r0, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	beq _080ECFCC
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0xa
	strb r0, [r1]
	bl sio_08001778
	b _080ECFCC
	.align 2, 0
_080ECF74: .4byte gSystemSavedataManager
_080ECF78: .4byte u8_ARRAY_08385f9c
_080ECF7C: .4byte gSineTable
_080ECF80:
	cmp r2, #1
	bne _080ECFCC
	movs r0, #0x80
	strb r0, [r4]
	b _080ECFCC
_080ECF8A:
	bl sio_08001570
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _080ECFA0 @ =0x00000253
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080ECFA4
	movs r0, #2
	b _080ECFCE
	.align 2, 0
_080ECFA0: .4byte 0x00000253
_080ECFA4:
	cmp r2, #0
	bne _080ECFAE
_080ECFA8:
	movs r0, #9
	strb r0, [r4]
	b _080ECFCC
_080ECFAE:
	movs r0, #0
	strb r0, [r4]
	b _080ECFCC
_080ECFB4:
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [r0]
	movs r0, #0
	strb r0, [r4]
	bl sio_0800100c
	bl sio_08001778
_080ECFCC:
	movs r0, #0
_080ECFCE:
	pop {r4, r5}
	pop {r1}
	bx r1
