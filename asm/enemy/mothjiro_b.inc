	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Mothjiro_Die
Mothjiro_Die: @ 0x08087D98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _08087DE4 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08087DEC
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08087DE8 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080881A4
	.align 2, 0
_08087DE4: .4byte gCurStory
_08087DE8: .4byte gEnemyFnTable
_08087DEC:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _08087DF4
	b _080881A6
_08087DF4:
	lsls r0, r0, #2
	ldr r1, _08087E00 @ =_08087E04
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087E00: .4byte _08087E04
_08087E04: @ jump table
	.4byte _08087E34 @ case 0
	.4byte _08087F5C @ case 1
	.4byte _08087E84 @ case 2
	.4byte _08087E98 @ case 3
	.4byte _08087F68 @ case 4
	.4byte _080881A6 @ case 5
	.4byte _080881A6 @ case 6
	.4byte _080881A6 @ case 7
	.4byte _080881A6 @ case 8
	.4byte _080881A6 @ case 9
	.4byte _08087F5C @ case 10
	.4byte _080880FC @ case 11
_08087E34:
	ldr r1, _08087E5C @ =0x00006B01
	adds r0, r7, #0
	bl SetMotion
	adds r1, r7, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08087E60
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08087E60
	movs r0, #1
	b _08087E62
	.align 2, 0
_08087E5C: .4byte 0x00006B01
_08087E60:
	movs r0, #0xa
_08087E62:
	strb r0, [r7, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r7, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r7, #0x5c]
	b _08087F5C
_08087E84:
	adds r0, r7, #0
	bl UpdateEntityAnim
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08087E96
	b _080881A6
_08087E96:
	b _08087F5C
_08087E98:
	ldr r1, _08087EE4 @ =0x00006B01
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateEntityAnim
	movs r0, #0
	strb r0, [r7, #0x13]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl FUN_080c2e7c
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08087EEC
	ldr r0, [sp]
	ldr r1, _08087EE8 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	b _08087F00
	.align 2, 0
_08087EE4: .4byte 0x00006B01
_08087EE8: .4byte 0xFFFFF800
_08087EEC:
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	rsbs r0, r0, #0
_08087F00:
	str r0, [r7, #0x5c]
	ldrb r0, [r7, #0x11]
	cmp r0, #0xff
	beq _08087F28
	cmp r0, #0xfe
	bne _08087F1C
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08087F4A
_08087F1C:
	ldr r0, _08087F38 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _08087F3C
_08087F28:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08087F4A
	.align 2, 0
_08087F38: .4byte pZero2
_08087F3C:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08087F4A:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #2
	bl TryDropItem
	ldr r0, _08087F64 @ =0xFFFFFE80
	str r0, [r7, #0x60]
	movs r0, #0x32
	strb r0, [r7, #0x12]
_08087F5C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080881A6
	.align 2, 0
_08087F64: .4byte 0xFFFFFE80
_08087F68:
	adds r0, r7, #0
	bl UpdateEntityAnim
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08087F7E
	str r1, [r7, #0x60]
_08087F7E:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r1, r1, r0
	str r1, [r7, #0x58]
	ldr r2, [r7, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088044
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08088024 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08088028 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0808802C @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08088030 @ =0x00006B04
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08088034 @ =0x00006B05
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08088038 @ =0x00006B06
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808803C @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08088040 @ =0x0000270E
	cmp r1, r0
	bhi _0808801C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808801C:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08088188
	.align 2, 0
_08088024: .4byte RNG_0202f388
_08088028: .4byte 0x000343FD
_0808802C: .4byte 0x00269EC3
_08088030: .4byte 0x00006B04
_08088034: .4byte 0x00006B05
_08088038: .4byte 0x00006B06
_0808803C: .4byte gScore
_08088040: .4byte 0x0000270E
_08088044:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _0808804C
	b _080881A6
_0808804C:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08088058
	b _080881A6
_08088058:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _080880DC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080880E0 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _080880E4 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x10
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _080880E8 @ =0x00006B04
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _080880EC @ =0x00006B05
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _080880F0 @ =0x00006B06
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080880F4 @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080880F8 @ =0x0000270E
	cmp r1, r0
	bhi _080880D2
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080880D2:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _08088188
	.align 2, 0
_080880DC: .4byte RNG_0202f388
_080880E0: .4byte 0x000343FD
_080880E4: .4byte 0x00269EC3
_080880E8: .4byte 0x00006B04
_080880EC: .4byte 0x00006B05
_080880F0: .4byte 0x00006B06
_080880F4: .4byte gScore
_080880F8: .4byte 0x0000270E
_080880FC:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #0x54
	adds r0, r0, r7
	mov r8, r0
	movs r0, #2
	mov r1, r8
	bl TryDropItem
	ldr r2, _080881B4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _080881B8 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _080881BC @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r7, #0x58]
	add r6, sp, #0x18
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _080881C0 @ =0x00006B04
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _080881C4 @ =0x00006B05
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _080881C8 @ =0x00006B06
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c2ed0
	ldr r2, _080881CC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _080881D0 @ =0x0000270E
	cmp r1, r0
	bhi _08088184
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08088184:
	adds r0, r7, #0
	mov r1, r8
_08088188:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080881D4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_080881A4:
	str r0, [r7, #0x14]
_080881A6:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080881B4: .4byte RNG_0202f388
_080881B8: .4byte 0x000343FD
_080881BC: .4byte 0x00269EC3
_080881C0: .4byte 0x00006B04
_080881C4: .4byte 0x00006B05
_080881C8: .4byte 0x00006B06
_080881CC: .4byte gScore
_080881D0: .4byte 0x0000270E
_080881D4: .4byte gEnemyFnTable

