	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08082e38
FUN_08082e38: @ 0x08082E38
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x1e
	bls _08082E44
	b _0808324E
_08082E44:
	lsls r0, r0, #2
	ldr r1, _08082E50 @ =_08082E54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08082E50: .4byte _08082E54
_08082E54: @ jump table
	.4byte _08082ED0 @ case 0
	.4byte _08082FF4 @ case 1
	.4byte _08082FFE @ case 2
	.4byte _08083018 @ case 3
	.4byte _0808324E @ case 4
	.4byte _0808324E @ case 5
	.4byte _0808324E @ case 6
	.4byte _0808324E @ case 7
	.4byte _0808324E @ case 8
	.4byte _0808324E @ case 9
	.4byte _08083070 @ case 10
	.4byte _08082FFE @ case 11
	.4byte _08083074 @ case 12
	.4byte _08083088 @ case 13
	.4byte _0808324E @ case 14
	.4byte _080830C0 @ case 15
	.4byte _08083106 @ case 16
	.4byte _08083138 @ case 17
	.4byte _0808324E @ case 18
	.4byte _0808324E @ case 19
	.4byte _08083156 @ case 20
	.4byte _08083160 @ case 21
	.4byte _08083174 @ case 22
	.4byte _0808324E @ case 23
	.4byte _0808324E @ case 24
	.4byte _0808324E @ case 25
	.4byte _0808324E @ case 26
	.4byte _0808324E @ case 27
	.4byte _0808324E @ case 28
	.4byte _0808324E @ case 29
	.4byte _080831E0 @ case 30
_08082ED0:
	ldrb r6, [r5, #0x10]
	cmp r6, #1
	bne _08082F2C
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r4, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r4, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	ldr r1, _08082F28 @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x60]
	strb r6, [r5, #0xf]
	strb r6, [r5, #0xe]
	b _08082FC4
	.align 2, 0
_08082F28: .4byte 0x00000901
_08082F2C:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r2, #0
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x24
	strb r2, [r0]
	ldr r0, [r5, #0x28]
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #1
	bne _08082F94
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x58]
	ldr r1, _08082F90 @ =0xFFFFCE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08082FB6
	.align 2, 0
_08082F90: .4byte 0xFFFFCE00
_08082F94:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08082FB6
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x58]
	ldr r2, _08082FEC @ =0xFFFFDE00
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, _08082FF0 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r5, #0x54]
_08082FB6:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r5, #0xe]
_08082FC4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r5, #0xa]
	str r1, [r5, #0x5c]
	str r1, [r5, #0x60]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _0808324E
	.align 2, 0
_08082FEC: .4byte 0xFFFFDE00
_08082FF0: .4byte 0xFFFFE200
_08082FF4:
	movs r0, #0x14
_08082FF6:
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08082FFE:
	ldr r0, [r5, #0x60]
	adds r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808300E
	str r1, [r5, #0x60]
_0808300E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	b _08083160
_08083018:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	beq _08083020
	b _080831D2
_08083020:
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08083030
	str r1, [r5, #0x60]
_08083030:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0808304C
	b _080831D2
_0808304C:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, _0808306C @ =0xFFFFFEE0
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	movs r1, #0xa
	b _080831C6
	.align 2, 0
_0808306C: .4byte 0xFFFFFEE0
_08083070:
	movs r0, #0xc
	b _08082FF6
_08083074:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08083086
	b _0808324E
_08083086:
	b _08083160
_08083088:
	ldr r0, [r5, #0x28]
	adds r0, #0xc8
	ldr r0, [r0]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x54]
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r1, _080830B8 @ =0xFFFFD200
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r2, _080830BC @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _08083150
	.align 2, 0
_080830B8: .4byte 0xFFFFD200
_080830BC: .4byte 0xFFFFF000
_080830C0:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080830D2
	b _0808324E
_080830D2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080830E4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080830E4
	b _0808324E
_080830E4:
	ldrb r1, [r5, #0x13]
	cmp r1, #0xfb
	bhi _080830F0
	adds r0, r1, #3
	strb r0, [r5, #0x13]
	b _080830FC
_080830F0:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080830FC:
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	b _0808324E
_08083106:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xa
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083138:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08083150
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083150
	b _0808324E
_08083150:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0808324E
_08083156:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083160:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808324E
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808324E
_08083174:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080831D2
	ldr r0, [r5, #0x60]
	adds r0, #0x10
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08083190
	str r1, [r5, #0x60]
_08083190:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _080831D2
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r0, _080831DC @ =0xFFFFFE40
	str r0, [r5, #0x60]
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #4
	bl AppendQuake
	movs r0, #0x91
	bl PlaySound
	movs r1, #0xf3
_080831C6:
	strb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	movs r0, #0x1e
	strb r0, [r5, #0xe]
_080831D2:
	adds r0, r5, #0
	bl UpdateEntityAnim
	b _0808324E
	.align 2, 0
_080831DC: .4byte 0xFFFFFE40
_080831E0:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x60]
	adds r0, #0xc
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080831F6
	str r1, [r5, #0x60]
_080831F6:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08083218
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808322C
	ldrb r0, [r5, #0x13]
	subs r0, #1
	b _0808322A
_08083218:
	ldrb r0, [r5, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808322C
	ldrb r0, [r5, #0x13]
	adds r0, #1
_0808322A:
	strb r0, [r5, #0x13]
_0808322C:
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	ldr r0, _08083254 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl Camera_GetDistance
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808324E
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808324E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08083254: .4byte gStageRun+232

