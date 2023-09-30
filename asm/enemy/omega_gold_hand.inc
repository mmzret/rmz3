	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08082bbc
FUN_08082bbc: @ 0x08082BBC
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08082C10 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08082C08
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08082C14 @ =gEnemyFnTable
	movs r1, #0x28
	strb r1, [r3, #9]
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	strb r4, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
	str r5, [r3, #0x28]
_08082C08:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08082C10: .4byte gZakoHeaderPtr
_08082C14: .4byte gEnemyFnTable

	thumb_func_start OmegaGoldHand_Init
OmegaGoldHand_Init: @ 0x08082C18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl InitScalerotMotion1
	adds r0, r5, #0
	adds r0, #0x24
	movs r6, #0
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r7, #0
	strb r0, [r5, #0xa]
	movs r2, #1
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r5, #0xa]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08082CA0 @ =0x08368220
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08082CA4 @ =nop_08083eac
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0x5c
	str r7, [r0, #4]
	str r7, [r5, #0x5c]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _08082CAC
	ldr r1, _08082CA8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r7, [r5, #0xd]
	strb r7, [r5, #0xe]
	strb r7, [r5, #0xf]
	b _08082CE2
	.align 2, 0
_08082CA0: .4byte 0x08368220
_08082CA4: .4byte nop_08083eac
_08082CA8: .4byte gEnemyFnTable
_08082CAC:
	adds r0, r5, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0xc1
	strb r6, [r0]
	ldr r1, _08082D0C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
_08082CE2:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08082D18
	adds r2, r5, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, _08082D10 @ =0xFFFFED00
	str r0, [r1]
	adds r1, #4
	ldr r0, _08082D14 @ =0xFFFFC600
	str r0, [r1]
	adds r1, #8
	movs r0, #1
	strb r0, [r1]
	b _08082D4C
	.align 2, 0
_08082D0C: .4byte gEnemyFnTable
_08082D10: .4byte 0xFFFFED00
_08082D14: .4byte 0xFFFFC600
_08082D18:
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0x8f
	movs r0, #0xa8
	lsls r0, r0, #5
	str r0, [r1]
	adds r1, #4
	ldr r0, _08082D6C @ =0xFFFFC800
	str r0, [r1]
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	strb r2, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08082D4C:
	ldrb r1, [r5, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r5, #0x1d]
	adds r0, r5, #0
	bl OmegaGoldHand_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082D6C: .4byte 0xFFFFC800

	thumb_func_start OmegaGoldHand_Update
OmegaGoldHand_Update: @ 0x08082D70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08082D9C
	ldr r1, _08082D98 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl OmegaGoldHand_Die
	b _08082E14
	.align 2, 0
_08082D98: .4byte gEnemyFnTable
_08082D9C:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08082DB8
	ldr r0, _08082DB4 @ =0x08368188
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	b _08082DC8
	.align 2, 0
_08082DB4: .4byte 0x08368188
_08082DB8:
	ldr r0, _08082DD8 @ =0x083681A0
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08082DC8:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08082DE8
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08082DE0
	ldr r0, _08082DDC @ =0x083681B8
	b _08082DF0
	.align 2, 0
_08082DD8: .4byte 0x083681A0
_08082DDC: .4byte 0x083681B8
_08082DE0:
	ldr r0, _08082DE4 @ =0x083681E8
	b _08082DF0
	.align 2, 0
_08082DE4: .4byte 0x083681E8
_08082DE8:
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08082E04
	ldr r0, _08082E00 @ =0x083681D0
_08082DF0:
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	b _08082E14
	.align 2, 0
_08082E00: .4byte 0x083681D0
_08082E04:
	ldr r0, _08082E1C @ =0x08368200
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08082E14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08082E1C: .4byte 0x08368200

	thumb_func_start OmegaGoldHand_Die
OmegaGoldHand_Die: @ 0x08082E20
	push {lr}
	ldr r2, _08082E34 @ =0x08368218
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08082E34: .4byte 0x08368218

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
	b _08083150
	.align 2, 0
_080830B8: .4byte 0xFFFFD200
_080830BC: .4byte 0xFFFFF000
_080830C0:
	adds r0, r5, #0
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl CalcFromCamera
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

	thumb_func_start FUN_08083258
FUN_08083258: @ 0x08083258
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	bne _0808327C
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08083280 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
_0808327C:
	pop {r0}
	bx r0
	.align 2, 0
_08083280: .4byte gEnemyFnTable

	thumb_func_start FUN_08083284
FUN_08083284:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083288
FUN_08083288: @ 0x08083288
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08083298
	cmp r5, #1
	beq _08083304
	b _08083320
_08083298:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08083304:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08083320
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_08083320:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08083328
FUN_08083328:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0xA5, 0x7B, 0x00, 0x2D
	.byte 0x02, 0xD0, 0x01, 0x2D, 0x35, 0xD0, 0x42, 0xE0, 0xE1, 0x7A, 0x10, 0x20, 0x08, 0x43, 0xE0, 0x72
	.byte 0xA0, 0x6A, 0x00, 0x7F, 0x60, 0x77, 0x1F, 0x49, 0x20, 0x1C, 0x94, 0xF7, 0x0D, 0xF9, 0xA1, 0x7A
	.byte 0xEF, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x20, 0x1C, 0x4C, 0x30, 0x05, 0x70, 0x22, 0x1C, 0x4A, 0x32
	.byte 0x11, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x70, 0xA1, 0x7A, 0xDF, 0x20, 0x08, 0x40
	.byte 0xA0, 0x72, 0x20, 0x1C, 0x4D, 0x30, 0x05, 0x70, 0x11, 0x78, 0x21, 0x20, 0x40, 0x42, 0x08, 0x40
	.byte 0x10, 0x70, 0x20, 0x1C, 0xB8, 0x30, 0xA2, 0x6A, 0x00, 0x68, 0x91, 0x6D, 0x40, 0x18, 0xA0, 0x65
	.byte 0x20, 0x1C, 0xB4, 0x30, 0x00, 0x68, 0x51, 0x6D, 0x40, 0x18, 0x60, 0x65, 0xA0, 0x7B, 0x01, 0x30
	.byte 0xA0, 0x73, 0x20, 0x1C, 0x94, 0xF7, 0x5A, 0xF9, 0xA0, 0x6A, 0x80, 0x69, 0x41, 0x7A, 0x01, 0x22
	.byte 0x10, 0x1C, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x00, 0x20, 0x62, 0x73, 0xA0, 0x73, 0x30, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x01, 0x09
	.align 2, 0

	thumb_func_start FUN_080833c8
FUN_080833c8:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080833cc
FUN_080833cc: @ 0x080833CC
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080833DC
	cmp r0, #1
	beq _080833E0
	b _080833E8
_080833DC:
	movs r0, #1
	strb r0, [r2, #0xe]
_080833E0:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080833E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080833ec
FUN_080833ec: @ 0x080833EC
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080833FC
	cmp r0, #1
	beq _08083400
	b _08083408
_080833FC:
	movs r0, #1
	strb r0, [r2, #0xe]
_08083400:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08083408:
	pop {r0}
	bx r0

	thumb_func_start FUN_0808340c
FUN_0808340c: @ 0x0808340C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	bne _08083420
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08083420:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08083428
FUN_08083428:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0xA5, 0x7B, 0x00, 0x2D
	.byte 0x02, 0xD0, 0x01, 0x2D, 0x25, 0xD0, 0x5E, 0xE0, 0xE1, 0x7A, 0x10, 0x20, 0x08, 0x43, 0xE0, 0x72
	.byte 0xA0, 0x6A, 0x00, 0x7F, 0x60, 0x77, 0x90, 0x21, 0x09, 0x01, 0x20, 0x1C, 0x94, 0xF7, 0x8C, 0xF8
	.byte 0xA1, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x20, 0x1C, 0x4C, 0x30, 0x05, 0x70, 0x22, 0x1C
	.byte 0x4A, 0x32, 0x11, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x70, 0x20, 0x1C, 0x74, 0x30
	.byte 0x19, 0x49, 0x83, 0xF7, 0xCF, 0xFE, 0x25, 0x66, 0xE5, 0x65, 0xA5, 0x74, 0xA0, 0x7B, 0x01, 0x30
	.byte 0xA0, 0x73, 0xA0, 0x7C, 0x02, 0x30, 0xA0, 0x74, 0x14, 0x49, 0xA0, 0x7C, 0x40, 0x00, 0x40, 0x18
	.byte 0x00, 0x21, 0x43, 0x5E, 0x20, 0x1C, 0xB8, 0x30, 0xA2, 0x6A, 0x00, 0x68, 0x91, 0x6D, 0x40, 0x18
	.byte 0xC0, 0x18, 0xA0, 0x65, 0x20, 0x1C, 0xB4, 0x30, 0x00, 0x68, 0x51, 0x6D, 0x40, 0x18, 0x60, 0x65
	.byte 0x50, 0x7B, 0x06, 0x28, 0x14, 0xD1, 0x25, 0x1C, 0xC0, 0x35, 0x28, 0x78, 0x00, 0x28, 0x04, 0xD0
	.byte 0x20, 0x1C, 0x74, 0x30, 0x04, 0x49, 0x83, 0xF7, 0xA5, 0xFE, 0x00, 0x20, 0x28, 0x70, 0xA1, 0x7A
	.byte 0xFE, 0x20, 0x08, 0x40, 0x0B, 0xE0, 0x00, 0x00, 0x20, 0x82, 0x36, 0x08, 0x74, 0xEA, 0x0F, 0x08
	.byte 0x21, 0x1C, 0xC0, 0x31, 0x01, 0x22, 0x01, 0x20, 0x08, 0x70, 0xA0, 0x7A, 0x10, 0x43, 0xA0, 0x72
	.byte 0x20, 0x1C, 0x94, 0xF7, 0xB3, 0xF8, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080834fc
FUN_080834fc: @ 0x080834FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808350C
	cmp r5, #1
	beq _0808356C
	b _080835A2
_0808350C:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _080835A8 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080835AC @ =0x08368268
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808356C:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _080835B0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r3, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r3, #0x58]
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080835A2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080835A8: .4byte 0x00000901
_080835AC: .4byte 0x08368268
_080835B0: .4byte gSineTable

	thumb_func_start FUN_080835b4
FUN_080835b4:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080835b8
FUN_080835b8: @ 0x080835B8
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _080835C8
	cmp r3, #1
	beq _080835F2
	b _080835F8
_080835C8:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080835F2:
	adds r0, r2, #0
	bl UpdateMotionGraphic
_080835F8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080835fc
FUN_080835fc: @ 0x080835FC
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0808360C
	cmp r3, #1
	beq _08083636
	b _0808363C
_0808360C:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083636:
	adds r0, r2, #0
	bl UpdateMotionGraphic
_0808363C:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08083640
FUN_08083640:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083644
FUN_08083644: @ 0x08083644
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08083652
	b _080839F6
_08083652:
	lsls r0, r0, #2
	ldr r1, _0808365C @ =_08083660
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808365C: .4byte _08083660
_08083660: @ jump table
	.4byte _080836C4 @ case 0
	.4byte _080836D4 @ case 1
	.4byte _0808370C @ case 2
	.4byte _08083722 @ case 3
	.4byte _0808373A @ case 4
	.4byte _08083784 @ case 5
	.4byte _080837F4 @ case 6
	.4byte _0808381A @ case 7
	.4byte _080839F6 @ case 8
	.4byte _080839F6 @ case 9
	.4byte _080838A4 @ case 10
	.4byte _080838E8 @ case 11
	.4byte _08083908 @ case 12
	.4byte _080839F6 @ case 13
	.4byte _080839F6 @ case 14
	.4byte _080839F6 @ case 15
	.4byte _080839F6 @ case 16
	.4byte _080839F6 @ case 17
	.4byte _080839F6 @ case 18
	.4byte _080839F6 @ case 19
	.4byte _08083922 @ case 20
	.4byte _08083958 @ case 21
	.4byte _08083998 @ case 22
	.4byte _080839D0 @ case 23
	.4byte _080839D6 @ case 24
_080836C4:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x68]
	str r0, [r5, #0x68]
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080836D4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, _08083704 @ =0xFFFFFD00
	cmp r0, r1
	bge _080836E8
	str r1, [r5, #0x60]
_080836E8:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	ldr r2, _08083708 @ =0xFFFF8600
	adds r1, r1, r2
	cmp r0, r1
	blt _080836FC
	b _080839F6
_080836FC:
	str r1, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _080839C4
	.align 2, 0
_08083704: .4byte 0xFFFFFD00
_08083708: .4byte 0xFFFF8600
_0808370C:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083714
	b _080839F6
_08083714:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083720
	b _080839F6
_08083720:
	b _080839C4
_08083722:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080837D8 @ =0x08368238
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808373A:
	ldr r1, _080837DC @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _080837E0 @ =0x08368298
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _080837E4 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083784:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _080837E8 @ =0xFFFF8800
	adds r4, r0, #0
	cmp r2, r1
	bge _080837A2
	ldr r0, [r5, #0x5c]
	subs r0, #0x40
	str r0, [r5, #0x5c]
	movs r1, #0x80
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080837A2
	str r1, [r5, #0x5c]
_080837A2:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r1, _080837EC @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r4]
	ldr r0, _080837F0 @ =0xFFFF8000
	cmp r1, r0
	bge _0808388A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083884
	movs r0, #6
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_080837D8: .4byte 0x08368238
_080837DC: .4byte 0x00000902
_080837E0: .4byte 0x08368298
_080837E4: .4byte 0xFFFFFE00
_080837E8: .4byte 0xFFFF8800
_080837EC: .4byte 0xFFFFED00
_080837F0: .4byte 0xFFFF8000
_080837F4:
	ldr r1, _08083870 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083874 @ =0x08368298
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _08083878 @ =0xFFFF8000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808381A:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _0808387C @ =0xFFFFF800
	adds r4, r0, #0
	cmp r2, r1
	ble _08083836
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	str r0, [r5, #0x5c]
	cmp r0, #0x80
	ble _08083836
	movs r0, #0x80
	str r0, [r5, #0x5c]
_08083836:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r4, _08083880 @ =0xFFFFED00
	adds r0, r0, r4
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0808388A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083884
	movs r0, #4
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_08083870: .4byte 0x00000902
_08083874: .4byte 0x08368298
_08083878: .4byte 0xFFFF8000
_0808387C: .4byte 0xFFFFF800
_08083880: .4byte 0xFFFFED00
_08083884:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _080839F6
_0808388A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083892
	b _080839F6
_08083892:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808389E
	b _080839F6
_0808389E:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _080839F6
_080838A4:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080838BC
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r0, r2
	b _080838C2
_080838BC:
	ldr r0, [r5, #0x54]
	ldr r1, _08083900 @ =0xFFFFFA00
	adds r0, r0, r1
_080838C2:
	str r0, [sp]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp, #4]
	ldr r0, _08083904 @ =0x0000012D
	bl PlaySound
	movs r1, #0xfa
	lsls r1, r1, #1
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac818
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080838E8:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080838F0
	b _080839F6
_080838F0:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080838FC
	b _080839F6
_080838FC:
	b _080839C4
	.align 2, 0
_08083900: .4byte 0xFFFFFA00
_08083904: .4byte 0x0000012D
_08083908:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808391C
	movs r0, #7
	strb r0, [r5, #0xe]
	b _080839F6
_0808391C:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _080839F6
_08083922:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	movs r4, #0
	strb r4, [r0]
	adds r0, #0x50
	ldr r1, _08083950 @ =0x08368238
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r1, _08083954 @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	b _080839C4
	.align 2, 0
_08083950: .4byte 0x08368238
_08083954: .4byte 0xFFFFED00
_08083958:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080839F6
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080839F6
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083994 @ =0x08368220
	bl SetDDP
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
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
	b _080839C4
	.align 2, 0
_08083994: .4byte 0x08368220
_08083998:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x80
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _080839AE
	str r1, [r5, #0x60]
_080839AE:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _080839CC @ =0xFFFFC600
	adds r0, r0, r2
	cmp r1, r0
	ble _080839F6
	str r0, [r5, #0x58]
_080839C4:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080839F6
	.align 2, 0
_080839CC: .4byte 0xFFFFC600
_080839D0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080839D6:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _08083A00 @ =0xFFFFC600
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _080839F6
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080839F6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083A00: .4byte 0xFFFFC600

	thumb_func_start FUN_08083a04
FUN_08083a04: @ 0x08083A04
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08083A12
	b _08083E06
_08083A12:
	lsls r0, r0, #2
	ldr r1, _08083A1C @ =_08083A20
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083A1C: .4byte _08083A20
_08083A20: @ jump table
	.4byte _08083A84 @ case 0
	.4byte _08083AF4 @ case 1
	.4byte _08083B48 @ case 2
	.4byte _08083B5E @ case 3
	.4byte _08083B6C @ case 4
	.4byte _08083BB2 @ case 5
	.4byte _08083C1C @ case 6
	.4byte _08083C42 @ case 7
	.4byte _08083E06 @ case 8
	.4byte _08083E06 @ case 9
	.4byte _08083CC8 @ case 10
	.4byte _08083CF2 @ case 11
	.4byte _08083D10 @ case 12
	.4byte _08083E06 @ case 13
	.4byte _08083E06 @ case 14
	.4byte _08083E06 @ case 15
	.4byte _08083E06 @ case 16
	.4byte _08083E06 @ case 17
	.4byte _08083E06 @ case 18
	.4byte _08083E06 @ case 19
	.4byte _08083D2A @ case 20
	.4byte _08083D94 @ case 21
	.4byte _08083DA6 @ case 22
	.4byte _08083DE0 @ case 23
	.4byte _08083DE6 @ case 24
_08083A84:
	ldr r1, _08083B3C @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r3, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r5
	mov ip, r0
	movs r2, #0x10
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4d
	movs r4, #0
	strb r3, [r0]
	movs r2, #0x20
	mov r0, ip
	ldrb r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083B40 @ =0x08368298
	bl SetDDP
	strb r4, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r4, [r0]
	str r4, [r5, #0x60]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x68]
	str r0, [r5, #0x68]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083AF4:
	ldrb r0, [r5, #0x13]
	cmp r0, #0x3f
	bhi _08083AFE
	adds r0, #4
	strb r0, [r5, #0x13]
_08083AFE:
	ldrb r0, [r5, #0x13]
	mvns r0, r0
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08083B1E
	str r1, [r5, #0x60]
_08083B1E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldr r1, [r5, #0x68]
	ldr r2, _08083B44 @ =0xFFFFFE00
	adds r1, r1, r2
	cmp r0, r1
	bgt _08083B32
	b _08083E06
_08083B32:
	str r1, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083B3C: .4byte 0x00000902
_08083B40: .4byte 0x08368298
_08083B44: .4byte 0xFFFFFE00
_08083B48:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083B50
	b _08083E06
_08083B50:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083B5C
	b _08083E06
_08083B5C:
	b _08083DD2
_08083B5E:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x50
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083B6C:
	ldr r1, _08083C04 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C08 @ =0x08368298
	bl SetDDP
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	ldr r0, _08083C0C @ =0xFFFFFF00
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083BB2:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083C10 @ =0xFFFFD180
	adds r4, r0, #0
	cmp r2, r1
	bge _08083BD0
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0x40
	rsbs r1, r1, #0
	cmp r0, r1
	ble _08083BD0
	str r1, [r5, #0x60]
_08083BD0:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r1, _08083C14 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r4]
	ldr r0, _08083C18 @ =0xFFFFD000
	cmp r1, r0
	bge _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #6
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C04: .4byte 0x00000902
_08083C08: .4byte 0x08368298
_08083C0C: .4byte 0xFFFFFF00
_08083C10: .4byte 0xFFFFD180
_08083C14: .4byte 0xFFFFFE00
_08083C18: .4byte 0xFFFFD000
_08083C1C:
	ldr r1, _08083C94 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08083C98 @ =0x08368298
	bl SetDDP
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _08083C9C @ =0xFFFFD000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083C42:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08083CA0 @ =0xFFFFFE80
	adds r4, r0, #0
	cmp r2, r1
	ble _08083C5E
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, #0x3f
	bgt _08083C5E
	movs r0, #0x40
	str r0, [r5, #0x60]
_08083C5E:
	ldr r0, [r4]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x68]
	adds r0, r0, r1
	ldr r4, _08083CA4 @ =0xFFFFFE00
	adds r0, r0, r4
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x68]
	adds r0, r0, r4
	ldr r1, [r5, #0x58]
	cmp r1, r0
	ble _08083CAE
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CA8
	movs r0, #4
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083C94: .4byte 0x00000902
_08083C98: .4byte 0x08368298
_08083C9C: .4byte 0xFFFFD000
_08083CA0: .4byte 0xFFFFFE80
_08083CA4: .4byte 0xFFFFFE00
_08083CA8:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _08083E06
_08083CAE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CB6
	b _08083E06
_08083CB6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083CC2
	b _08083E06
_08083CC2:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _08083E06
_08083CC8:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, [r5, #0x54]
	ldr r2, _08083D08 @ =0xFFFFEE00
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldr r0, _08083D0C @ =0x0000012D
	bl PlaySound
	movs r1, #0xc8
	lsls r1, r1, #2
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac880
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083CF2:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08083CFA
	b _08083E06
_08083CFA:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08083D06
	b _08083E06
_08083D06:
	b _08083DD2
	.align 2, 0
_08083D08: .4byte 0xFFFFEE00
_08083D0C: .4byte 0x0000012D
_08083D10:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08083D24
	movs r0, #7
	strb r0, [r5, #0xe]
	b _08083E06
_08083D24:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _08083E06
_08083D2A:
	ldr r1, _08083D8C @ =0x00000901
	adds r0, r5, #0
	bl SetMotion
	movs r4, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
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
	adds r0, #0x50
	ldr r1, _08083D90 @ =0x08368268
	bl SetDDP
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x54]
	str r4, [r5, #0x60]
	movs r0, #0x32
	strb r0, [r5, #0x12]
	b _08083DD2
	.align 2, 0
_08083D8C: .4byte 0x00000901
_08083D90: .4byte 0x08368268
_08083D94:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08083E06
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08083E06
	b _08083DD2
_08083DA6:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	subs r0, #4
	str r0, [r5, #0x60]
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08083DBC
	str r1, [r5, #0x60]
_08083DBC:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _08083DDC @ =0xFFFFC800
	adds r0, r0, r2
	cmp r1, r0
	bge _08083E06
	str r0, [r5, #0x58]
_08083DD2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08083E06
	.align 2, 0
_08083DDC: .4byte 0xFFFFC800
_08083DE0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08083DE6:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _08083E10 @ =0xFFFFC800
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #5
	beq _08083E06
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08083E06:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083E10: .4byte 0xFFFFC800

	thumb_func_start FUN_08083e14
FUN_08083e14:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083e18
FUN_08083e18: @ 0x08083E18
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _08083E28
	cmp r3, #1
	beq _08083E48
	b _08083E64
_08083E28:
	adds r0, r2, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r0, #4
	strb r3, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	str r3, [r2, #0x5c]
	str r3, [r2, #0x60]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083E48:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	cmp r0, #0x40
	ble _08083E56
	movs r0, #0x40
	str r0, [r2, #0x60]
_08083E56:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0
	bl UpdateMotionGraphic
_08083E64:
	pop {r0}
	bx r0

	thumb_func_start FUN_08083e68
FUN_08083e68: @ 0x08083E68
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _08083E78
	cmp r3, #1
	beq _08083EA2
	b _08083EA8
_08083E78:
	ldrb r1, [r2, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r0, #0x4a
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	str r3, [r2, #0x60]
	str r3, [r2, #0x5c]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08083EA2:
	adds r0, r2, #0
	bl UpdateMotionGraphic
_08083EA8:
	pop {r0}
	bx r0

	thumb_func_start nop_08083eac
nop_08083eac: @ 0x08083EAC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083eb0
FUN_08083eb0: @ 0x08083EB0
	adds r3, r0, #0
	adds r3, #0xc1
	movs r2, #0
	movs r1, #1
	strb r1, [r3]
	movs r1, #4
	strb r1, [r0, #0xd]
	strb r2, [r0, #0xe]
	movs r0, #1
	bx lr

	thumb_func_start FUN_08083ec4
FUN_08083ec4: @ 0x08083EC4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08083ED4
	cmp r5, #1
	beq _08083F0C
	b _08083F40
_08083ED4:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc1
	strb r5, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08083F0C:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _08083F48 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	adds r0, r0, r3
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08083F40:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083F48: .4byte gSineTable

	thumb_func_start FUN_08083f4c
FUN_08083f4c: @ 0x08083F4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08083F5C
	cmp r5, #1
	beq _08083FAA
	b _08083FE0
_08083F5C:
	ldr r1, _08083FE8 @ =0x00000901
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xc1
	strb r5, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08083FAA:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	ldr r1, _08083FEC @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r3, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r3, #0x58]
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08083FE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08083FE8: .4byte 0x00000901
_08083FEC: .4byte gSineTable

	thumb_func_start FUN_08083ff0
FUN_08083ff0:
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08083ff4
FUN_08083ff4: @ 0x08083FF4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x18
	bls _08084002
	b _0808433E
_08084002:
	lsls r0, r0, #2
	ldr r1, _0808400C @ =_08084010
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808400C: .4byte _08084010
_08084010: @ jump table
	.4byte _08084074 @ case 0
	.4byte _0808407E @ case 1
	.4byte _080840B8 @ case 2
	.4byte _080840CE @ case 3
	.4byte _080840DC @ case 4
	.4byte _0808411C @ case 5
	.4byte _08084184 @ case 6
	.4byte _080841A0 @ case 7
	.4byte _0808433E @ case 8
	.4byte _0808433E @ case 9
	.4byte _08084224 @ case 10
	.4byte _08084262 @ case 11
	.4byte _08084278 @ case 12
	.4byte _0808433E @ case 13
	.4byte _0808433E @ case 14
	.4byte _0808433E @ case 15
	.4byte _0808433E @ case 16
	.4byte _0808433E @ case 17
	.4byte _0808433E @ case 18
	.4byte _0808433E @ case 19
	.4byte _08084292 @ case 20
	.4byte _080842BC @ case 21
	.4byte _080842EC @ case 22
	.4byte _08084324 @ case 23
	.4byte _0808432A @ case 24
_08084074:
	movs r0, #0
	str r0, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808407E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	subs r0, #0x40
	str r0, [r5, #0x60]
	ldr r1, _080840B0 @ =0xFFFFFD00
	cmp r0, r1
	bge _08084092
	str r1, [r5, #0x60]
_08084092:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _080840B4 @ =0xFFFF8600
	adds r0, r0, r2
	cmp r1, r0
	blt _080840A8
	b _0808433E
_080840A8:
	str r0, [r5, #0x58]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	b _08084318
	.align 2, 0
_080840B0: .4byte 0xFFFFFD00
_080840B4: .4byte 0xFFFF8600
_080840B8:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080840C0
	b _0808433E
_080840C0:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080840CC
	b _0808433E
_080840CC:
	b _08084318
_080840CE:
	movs r0, #4
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080840DC:
	ldr r1, _08084170 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r2, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	movs r2, #0x10
	ldrb r1, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0x24
	strb r3, [r0]
	adds r0, #0x98
	str r3, [r0]
	ldr r0, _08084174 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808411C:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _08084178 @ =0xFFFF8800
	adds r4, r0, #0
	cmp r2, r1
	bge _0808413A
	ldr r0, [r5, #0x5c]
	subs r0, #0x40
	str r0, [r5, #0x5c]
	movs r1, #0x80
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0808413A
	str r1, [r5, #0x5c]
_0808413A:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r1, _0808417C @ =0xFFFFED00
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r4]
	ldr r0, _08084180 @ =0xFFFF8000
	cmp r1, r0
	bge _0808420A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08084204
	movs r0, #6
	strb r0, [r5, #0xe]
	b _0808433E
	.align 2, 0
_08084170: .4byte 0x00000902
_08084174: .4byte 0xFFFFFE00
_08084178: .4byte 0xFFFF8800
_0808417C: .4byte 0xFFFFED00
_08084180: .4byte 0xFFFF8000
_08084184:
	ldr r1, _080841F4 @ =0x00000902
	adds r0, r5, #0
	bl SetMotion
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, _080841F8 @ =0xFFFF8000
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080841A0:
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r2, [r0]
	ldr r1, _080841FC @ =0xFFFFF800
	adds r4, r0, #0
	cmp r2, r1
	ble _080841BC
	ldr r0, [r5, #0x5c]
	adds r0, #0x40
	str r0, [r5, #0x5c]
	cmp r0, #0x80
	ble _080841BC
	movs r0, #0x80
	str r0, [r5, #0x5c]
_080841BC:
	ldr r0, [r4]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, [r5, #0x28]
	ldr r1, [r1, #0x54]
	adds r0, r0, r1
	ldr r4, _08084200 @ =0xFFFFED00
	adds r0, r0, r4
	str r0, [r5, #0x54]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	adds r0, r0, r4
	ldr r1, [r5, #0x54]
	cmp r1, r0
	ble _0808420A
	ldrb r0, [r5, #0xf]
	subs r0, #1
	strb r0, [r5, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08084204
	movs r0, #4
	strb r0, [r5, #0xe]
	b _0808433E
	.align 2, 0
_080841F4: .4byte 0x00000902
_080841F8: .4byte 0xFFFF8000
_080841FC: .4byte 0xFFFFF800
_08084200: .4byte 0xFFFFED00
_08084204:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _0808433E
_0808420A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08084212
	b _0808433E
_08084212:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808421E
	b _0808433E
_0808421E:
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0808433E
_08084224:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808423C
	ldr r0, [r5, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #3
	adds r0, r0, r2
	b _08084242
_0808423C:
	ldr r0, [r5, #0x54]
	ldr r1, _08084274 @ =0xFFFFFA00
	adds r0, r0, r1
_08084242:
	str r0, [sp]
	ldr r0, [r5, #0x58]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r1, #0xa0
	lsls r1, r1, #1
	mov r0, sp
	movs r2, #7
	adds r3, r5, #0
	bl FUN_080ac8e8
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08084262:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808433E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808433E
	b _08084318
	.align 2, 0
_08084274: .4byte 0xFFFFFA00
_08084278:
	movs r0, #0x40
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0xf]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808428C
	movs r0, #7
	strb r0, [r5, #0xe]
	b _0808433E
_0808428C:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0808433E
_08084292:
	movs r1, #0x90
	lsls r1, r1, #4
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x24
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	ldr r2, _080842B8 @ =0xFFFFED00
	adds r0, r0, r2
	str r0, [r5, #0x54]
	str r1, [r5, #0x60]
	movs r0, #0x28
	strb r0, [r5, #0x12]
	b _08084318
	.align 2, 0
_080842B8: .4byte 0xFFFFED00
_080842BC:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808433E
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0808433E
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
	b _08084318
_080842EC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x60]
	adds r0, #0x80
	str r0, [r5, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #2
	cmp r0, r1
	ble _08084302
	str r1, [r5, #0x60]
_08084302:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _08084320 @ =0xFFFFC600
	adds r0, r0, r2
	cmp r1, r0
	ble _0808433E
	str r0, [r5, #0x58]
_08084318:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808433E
	.align 2, 0
_08084320: .4byte 0xFFFFC600
_08084324:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808432A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0xc1
	movs r1, #0
	strb r1, [r0]
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808433E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084348
FUN_08084348:
	.byte 0x30, 0xB5, 0x82, 0xB0, 0x05, 0x1C, 0xA8, 0x7B
	.byte 0x18, 0x28, 0x00, 0xD9, 0xCD, 0xE1, 0x80, 0x00, 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46
	.byte 0x64, 0x43, 0x08, 0x08, 0xC8, 0x43, 0x08, 0x08, 0x20, 0x44, 0x08, 0x08, 0x70, 0x44, 0x08, 0x08
	.byte 0x86, 0x44, 0x08, 0x08, 0x94, 0x44, 0x08, 0x08, 0xD0, 0x44, 0x08, 0x08, 0x38, 0x45, 0x08, 0x08
	.byte 0x54, 0x45, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08, 0xD8, 0x45, 0x08, 0x08
	.byte 0xFC, 0x45, 0x08, 0x08, 0x14, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08
	.byte 0xF2, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08, 0xF2, 0x46, 0x08, 0x08
	.byte 0xF2, 0x46, 0x08, 0x08, 0x2E, 0x46, 0x08, 0x08, 0x8C, 0x46, 0x08, 0x08, 0x9E, 0x46, 0x08, 0x08
	.byte 0xD8, 0x46, 0x08, 0x08, 0xDE, 0x46, 0x08, 0x08, 0x27, 0x49, 0x28, 0x1C, 0x93, 0xF7, 0xCC, 0xF8
	.byte 0x01, 0x23, 0xA9, 0x7A, 0x10, 0x20, 0x08, 0x43, 0xA8, 0x72, 0x28, 0x1C, 0x4C, 0x30, 0x03, 0x70
	.byte 0x2C, 0x1C, 0x4A, 0x34, 0x10, 0x22, 0x21, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43
	.byte 0x20, 0x70, 0xA9, 0x7A, 0x20, 0x20, 0x08, 0x43, 0xA8, 0x72, 0x28, 0x1C, 0x4D, 0x30, 0x00, 0x22
	.byte 0x03, 0x70, 0x20, 0x23, 0x21, 0x78, 0x21, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x43, 0x20, 0x70
	.byte 0xEA, 0x74, 0x28, 0x1C, 0x24, 0x30, 0x02, 0x70, 0x2A, 0x66, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73
	.byte 0xE8, 0x7C, 0x3F, 0x28, 0x01, 0xD8, 0x04, 0x30, 0xE8, 0x74, 0xE8, 0x7C, 0xC0, 0x43, 0x29, 0x1C
	.byte 0x24, 0x31, 0x08, 0x70, 0x28, 0x1C, 0x93, 0xF7, 0x11, 0xF9, 0x28, 0x6E, 0x20, 0x30, 0x28, 0x66
	.byte 0xC0, 0x21, 0x89, 0x00, 0x88, 0x42, 0x00, 0xDD, 0x29, 0x66, 0xA9, 0x6D, 0x28, 0x6E, 0x09, 0x18
	.byte 0xA9, 0x65, 0xA8, 0x6A, 0x80, 0x6D, 0x05, 0x4A, 0x80, 0x18, 0x81, 0x42, 0x00, 0xDC, 0x48, 0xE1
	.byte 0xA8, 0x65, 0x14, 0x20, 0xA8, 0x74, 0x30, 0xE1, 0x02, 0x09, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF
	.byte 0xA8, 0x7C, 0x00, 0x28, 0x00, 0xD1, 0x3C, 0xE1, 0x01, 0x38, 0xA8, 0x74, 0x00, 0x06, 0x00, 0x28
	.byte 0x00, 0xD0, 0x36, 0xE1, 0x21, 0xE1, 0x04, 0x20, 0xE8, 0x73, 0x50, 0x20, 0xA8, 0x74, 0xA8, 0x7B
	.byte 0x01, 0x30, 0xA8, 0x73, 0x23, 0x49, 0x28, 0x1C, 0x93, 0xF7, 0x66, 0xF8, 0x01, 0x22, 0xA9, 0x7A
	.byte 0x10, 0x20, 0x08, 0x43, 0xA8, 0x72, 0x28, 0x1C, 0x4C, 0x30, 0x00, 0x23, 0x02, 0x70, 0x2C, 0x1C
	.byte 0x4A, 0x34, 0x10, 0x22, 0x21, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x43, 0x20, 0x70
	.byte 0x28, 0x1C, 0xBC, 0x30, 0x03, 0x60, 0x18, 0x48, 0x28, 0x66, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73
	.byte 0x28, 0x1C, 0xBC, 0x30, 0x02, 0x68, 0x15, 0x49, 0x04, 0x1C, 0x8A, 0x42, 0x07, 0xDA, 0x28, 0x6E
	.byte 0x40, 0x30, 0x28, 0x66, 0x40, 0x21, 0x49, 0x42, 0x88, 0x42, 0x00, 0xDD, 0x29, 0x66, 0x20, 0x68
	.byte 0x29, 0x6E, 0x40, 0x18, 0x20, 0x60, 0xA9, 0x6A, 0x89, 0x6D, 0x40, 0x18, 0x0C, 0x49, 0x40, 0x18
	.byte 0xA8, 0x65, 0x28, 0x1C, 0x93, 0xF7, 0xAA, 0xF8, 0x21, 0x68, 0x0A, 0x48, 0x81, 0x42, 0x56, 0xDA
	.byte 0xE8, 0x7B, 0x01, 0x38, 0xE8, 0x73, 0x00, 0x06, 0x00, 0x28, 0x4D, 0xD0, 0x06, 0x20, 0xA8, 0x73
	.byte 0xE7, 0xE0, 0x00, 0x00, 0x02, 0x09, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x80, 0xD1, 0xFF, 0xFF
	.byte 0x00, 0xFE, 0xFF, 0xFF, 0x00, 0xD0, 0xFF, 0xFF, 0x1B, 0x49, 0x28, 0x1C, 0x93, 0xF7, 0x14, 0xF8
	.byte 0x29, 0x1C, 0xBC, 0x31, 0x19, 0x48, 0x08, 0x60, 0x80, 0x20, 0x40, 0x00, 0x28, 0x66, 0xA8, 0x7B
	.byte 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C, 0xBC, 0x30, 0x02, 0x68, 0x15, 0x49, 0x04, 0x1C, 0x8A, 0x42
	.byte 0x06, 0xDD, 0x28, 0x6E, 0x40, 0x38, 0x28, 0x66, 0x3F, 0x28, 0x01, 0xDC, 0x40, 0x20, 0x28, 0x66
	.byte 0x20, 0x68, 0x29, 0x6E, 0x40, 0x18, 0x20, 0x60, 0xA9, 0x6A, 0x89, 0x6D, 0x40, 0x18, 0x0D, 0x4C
	.byte 0x00, 0x19, 0xA8, 0x65, 0x28, 0x1C, 0x93, 0xF7, 0x69, 0xF8, 0xA8, 0x6A, 0x80, 0x6D, 0x00, 0x19
	.byte 0xA9, 0x6D, 0x81, 0x42, 0x13, 0xDD, 0xE8, 0x7B, 0x01, 0x38, 0xE8, 0x73, 0x00, 0x06, 0x00, 0x28
	.byte 0x0A, 0xD0, 0x04, 0x20, 0xA8, 0x73, 0xA4, 0xE0, 0x02, 0x09, 0x00, 0x00, 0x00, 0xD0, 0xFF, 0xFF
	.byte 0x80, 0xFE, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x14, 0x20, 0xA8, 0x73, 0x99, 0xE0, 0xA8, 0x7C
	.byte 0x00, 0x28, 0x00, 0xD1, 0x95, 0xE0, 0x01, 0x38, 0xA8, 0x74, 0x00, 0x06, 0x00, 0x28, 0x00, 0xD0
	.byte 0x8F, 0xE0, 0x0A, 0x20, 0xA8, 0x73, 0x8C, 0xE0, 0x3C, 0x20, 0xA8, 0x74, 0x68, 0x6D, 0x0C, 0x4A
	.byte 0x80, 0x18, 0x00, 0x90, 0xA8, 0x6D, 0x01, 0x90, 0x80, 0x21, 0x89, 0x00, 0x68, 0x46, 0x07, 0x22
	.byte 0x2B, 0x1C, 0x28, 0xF0, 0xAD, 0xF9, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0xA8, 0x7C, 0x00, 0x28
	.byte 0x77, 0xD0, 0x01, 0x38, 0xA8, 0x74, 0x00, 0x06, 0x00, 0x28, 0x72, 0xD1, 0x5D, 0xE0, 0x00, 0x00
	.byte 0x00, 0xEE, 0xFF, 0xFF, 0x40, 0x20, 0xA8, 0x74, 0xE9, 0x7B, 0x01, 0x20, 0x08, 0x40, 0x00, 0x28
	.byte 0x02, 0xD0, 0x07, 0x20, 0xA8, 0x73, 0x64, 0xE0, 0x05, 0x20, 0xA8, 0x73, 0x61, 0xE0, 0x16, 0x49
	.byte 0x28, 0x1C, 0x92, 0xF7, 0x99, 0xFF, 0x00, 0x22, 0xA9, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA8, 0x72
	.byte 0x28, 0x1C, 0x4C, 0x30, 0x02, 0x70, 0x2B, 0x1C, 0x4A, 0x33, 0x19, 0x78, 0x11, 0x20, 0x40, 0x42
	.byte 0x08, 0x40, 0x18, 0x70, 0xA9, 0x7A, 0xDF, 0x20, 0x08, 0x40, 0xA8, 0x72, 0x28, 0x1C, 0x4D, 0x30
	.byte 0x02, 0x70, 0x19, 0x78, 0x21, 0x20, 0x40, 0x42, 0x08, 0x40, 0x18, 0x70, 0x28, 0x1C, 0x24, 0x30
	.byte 0x02, 0x70, 0xA8, 0x6A, 0x40, 0x6D, 0xA8, 0x21, 0x49, 0x01, 0x40, 0x18, 0x68, 0x65, 0x2A, 0x66
	.byte 0x32, 0x20, 0xA8, 0x74, 0x21, 0xE0, 0x00, 0x00, 0x01, 0x09, 0x00, 0x00, 0xA8, 0x7C, 0x00, 0x28
	.byte 0x2F, 0xD0, 0x01, 0x38, 0xA8, 0x74, 0x00, 0x06, 0x00, 0x28, 0x2A, 0xD1, 0x15, 0xE0, 0x28, 0x1C
	.byte 0x92, 0xF7, 0xDC, 0xFF, 0x28, 0x6E, 0x04, 0x38, 0x28, 0x66, 0xA0, 0x21, 0x49, 0x42, 0x88, 0x42
	.byte 0x00, 0xDA, 0x29, 0x66, 0xA9, 0x6D, 0x28, 0x6E, 0x09, 0x18, 0xA9, 0x65, 0xA8, 0x6A, 0x80, 0x6D
	.byte 0x04, 0x4A, 0x80, 0x18, 0x81, 0x42, 0x14, 0xDA, 0xA8, 0x65, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73
	.byte 0x0F, 0xE0, 0x00, 0x00, 0x00, 0xC8, 0xFF, 0xFF, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C
	.byte 0x92, 0xF7, 0xBC, 0xFF, 0x28, 0x1C, 0xC1, 0x30, 0x00, 0x21, 0x01, 0x70, 0x02, 0x20, 0x68, 0x73
	.byte 0xA9, 0x73, 0x02, 0xB0, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_080846fc
FUN_080846fc:
  movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_08084700
FUN_08084700:
	bx lr
	.align 2, 0
