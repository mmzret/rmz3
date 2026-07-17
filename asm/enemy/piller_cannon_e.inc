	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068784
FUN_08068784: @ 0x08068784
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08068790
	b _08068AC8
_08068790:
	lsls r0, r0, #2
	ldr r1, _0806879C @ =_080687A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806879C: .4byte _080687A0
_080687A0: @ jump table
	.4byte _080687D0 @ case 0
	.4byte _080688FC @ case 1
	.4byte _08068994 @ case 2
	.4byte _08068AC8 @ case 3
	.4byte _08068AC8 @ case 4
	.4byte _08068AC8 @ case 5
	.4byte _08068AC8 @ case 6
	.4byte _08068AC8 @ case 7
	.4byte _08068AC8 @ case 8
	.4byte _08068AC8 @ case 9
	.4byte _08068A58 @ case 10
	.4byte _08068AA8 @ case 11
_080687D0:
	ldrb r3, [r4, #0x10]
	cmp r3, #0
	bne _0806883E
	ldr r0, _0806880C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08068810
	adds r2, r4, #0
	adds r2, #0xb8
	strb r3, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	b _080688A2
	.align 2, 0
_0806880C: .4byte pZero2
_08068810:
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #1
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	b _080688A0
_0806883E:
	ldr r0, _08068878 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _0806887C
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #1
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	b _080688A0
	.align 2, 0
_08068878: .4byte pZero2
_0806887C:
	adds r3, r4, #0
	adds r3, #0xb8
	movs r2, #0
	strb r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_080688A0:
	adds r2, r3, #0
_080688A2:
	ldrb r2, [r2]
	cmp r2, #0
	bne _080688AE
	strb r2, [r4, #0x13]
	movs r0, #1
	b _080688B4
_080688AE:
	movs r0, #6
	strb r0, [r4, #0x13]
	movs r0, #2
_080688B4:
	strb r0, [r4, #0xe]
	ldr r1, _080688F0 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _080688F4 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _080688F8 @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
	movs r0, #6
	strb r0, [r4, #0x12]
	b _08068A50
	.align 2, 0
_080688F0: .4byte sMotions
_080688F4: .4byte 0x08366204
_080688F8: .4byte sCollisions
_080688FC:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068976
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08068976
	ldrb r0, [r4, #0x13]
	cmp r0, #5
	bls _08068918
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068976
_08068918:
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08068946
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08068946:
	ldr r1, _08068984 @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068988 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0806898C @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068976:
	ldr r0, _08068990 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bgt _08068A16
	b _08068A3C
	.align 2, 0
_08068984: .4byte sMotions
_08068988: .4byte 0x08366204
_0806898C: .4byte sCollisions
_08068990: .4byte pZero2
_08068994:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068A0A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08068A0A
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080689B2
	movs r0, #0xa
	strb r0, [r4, #0xe]
	b _08068A0A
_080689B2:
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080689DA
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_080689DA:
	ldr r1, _08068A2C @ =0x083661F4
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _08068A30 @ =0x08366204
	ldrb r1, [r4, #0x13]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08068A34 @ =0x0836609C
	adds r1, r1, r2
	bl SetDDP
_08068A0A:
	ldr r0, _08068A38 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08068A3C
_08068A16:
	ldrb r2, [r4, #0x13]
	cmp r2, #2
	bne _08068A50
	adds r0, r4, #0
	adds r0, #0xbb
	movs r1, #0
	strb r2, [r0]
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08068A50
	.align 2, 0
_08068A2C: .4byte sMotions
_08068A30: .4byte 0x08366204
_08068A34: .4byte sCollisions
_08068A38: .4byte pZero2
_08068A3C:
	ldrb r3, [r4, #0x13]
	adds r2, r3, #0
	cmp r2, #4
	bne _08068A50
	adds r1, r4, #0
	adds r1, #0xbb
	movs r0, #0
	strb r3, [r1]
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_08068A50:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08068AC8
_08068A58:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08068AD0 @ =0x0836609C
	bl SetDDP
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r3, [r5]
	cmp r3, #0
	beq _08068A9E
	ldrb r2, [r3, #0xa]
	movs r1, #0xfe
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xa]
	ldr r2, [r5]
	ldrb r0, [r2, #0xa]
	ands r1, r0
	movs r0, #0xfd
	ands r1, r0
	strb r1, [r2, #0xa]
	ldr r1, _08068AD4 @ =gVFXFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_08068A9E:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08068AA8:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08068AC8
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08068AC8
	ldrb r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08068AC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08068AD0: .4byte sCollisions
_08068AD4: .4byte gVFXFnTable

