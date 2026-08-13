	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a6d3c
FUN_080a6d3c: @ 0x080A6D3C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _080A6D4C
	b _080A6EB4
_080A6D4C:
	adds r0, r1, #0
	adds r0, #0xc0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6D58
	b _080A6EB4
_080A6D58:
	ldrb r0, [r1, #0xd]
	cmp r0, #0xb
	bne _080A6D60
	b _080A6EB4
_080A6D60:
	ldrb r0, [r5, #0xe]
	cmp r0, #7
	bls _080A6D68
	b _080A6EC6
_080A6D68:
	lsls r0, r0, #2
	ldr r1, _080A6D74 @ =_080A6D78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A6D74: .4byte _080A6D78
_080A6D78: @ jump table
	.4byte _080A6D98 @ case 0
	.4byte _080A6DB6 @ case 1
	.4byte _080A6E3C @ case 2
	.4byte _080A6E46 @ case 3
	.4byte _080A6E50 @ case 4
	.4byte _080A6E64 @ case 5
	.4byte _080A6E9A @ case 6
	.4byte _080A6EA4 @ case 7
_080A6D98:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #9
	strb r0, [r5, #0x12]
	movs r0, #1
	strb r0, [r5, #0x13]
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6DB6:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080A6DC8
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A6DC8
	b _080A6EC6
_080A6DC8:
	ldrb r1, [r5, #0x12]
	movs r0, #9
	subs r6, r0, r1
	ldr r1, [r5, #0x28]
	ldr r4, [r1, #0x54]
	str r4, [sp]
	ldr r3, [r1, #0x58]
	str r3, [sp, #4]
	ldrb r2, [r1, #0xa]
	movs r0, #0x10
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _080A6DFC
	ldr r1, _080A6DF8 @ =0x0836BD74
	lsls r2, r6, #3
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, r0, r4
	str r0, [sp]
	adds r1, #4
	adds r2, r2, r1
	ldr r0, [r2]
	b _080A6E12
	.align 2, 0
_080A6DF8: .4byte sCoords+(10*8)
_080A6DFC:
	ldr r2, _080A6E38 @ =0x0836BD74
	movs r1, #8
	subs r1, r1, r6
	lsls r1, r1, #3
	adds r0, r1, r2
	ldr r0, [r0]
	adds r0, r0, r4
	str r0, [sp]
	adds r2, #4
	adds r1, r1, r2
	ldr r0, [r1]
_080A6E12:
	adds r0, r0, r3
	str r0, [sp, #4]
	ldrb r2, [r7, #0xa]
	lsrs r2, r2, #4
	movs r4, #1
	ands r2, r4
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	mov r1, sp
	bl FUN_080a6014
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6E92
	subs r0, #1
	b _080A6E8A
	.align 2, 0
_080A6E38: .4byte sCoords+(10*8)
_080A6E3C:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6E46:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6E92
	subs r0, #1
	b _080A6E8A
_080A6E50:
	movs r1, #0
	movs r0, #0x20
	strb r0, [r5, #0x12]
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0xb5
	strb r1, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6E64:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _080A6E74
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6E74:
	adds r1, r5, #0
	adds r1, #0xb5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r5, #0x12]
	strb r1, [r5, #0x13]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _080A6E92
	subs r0, r1, #1
_080A6E8A:
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6E92:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080A6EC6
_080A6E9A:
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080A6EA4:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080A6EB4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6EC6
_080A6EB4:
	ldr r1, _080A6ED0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_080A6EC6:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A6ED0: .4byte gProjectileFnTable
