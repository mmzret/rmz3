	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateMothjiro
CreateMothjiro: @ 0x08087B9C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08087BF4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08087BEA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08087BF8 @ =gEnemyFnTable
	movs r1, #0x2f
	strb r1, [r3, #9]
	adds r0, #0xbc
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_08087BEA:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08087BF4: .4byte gZakoHeaderPtr
_08087BF8: .4byte gEnemyFnTable

	thumb_func_start Mothjiro_Init
Mothjiro_Init: @ 0x08087BFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _08087C48 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08087C54
	ldr r0, _08087C4C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08087C54
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087C50 @ =0x083687C8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	b _08087C6C
	.align 2, 0
_08087C48: .4byte gSystemSavedataManager
_08087C4C: .4byte gCurStory
_08087C50: .4byte 0x083687C8
_08087C54:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08087CE8 @ =0x083687C8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_08087C6C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08087CEC @ =FUN_08088b0c
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0xc0
	movs r4, #0
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	ldr r0, [r6, #0x54]
	ldr r2, _08087CF0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	adds r1, #4
	ldr r0, [r6, #0x58]
	ldr r2, _08087CF4 @ =0xFFFFB000
	adds r0, r0, r2
	str r0, [r1]
	ldr r1, _08087CF8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _08087CD8
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08087CD8:
	strb r4, [r6, #0x11]
	adds r0, r6, #0
	bl Mothjiro_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087CE8: .4byte 0x083687C8
_08087CEC: .4byte FUN_08088b0c
_08087CF0: .4byte 0xFFFFC000
_08087CF4: .4byte 0xFFFFB000
_08087CF8: .4byte gEnemyFnTable

	thumb_func_start Mothjiro_Update
Mothjiro_Update: @ 0x08087CFC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r6, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r6, r0
	cmp r6, #0
	beq _08087D2C
	ldr r1, _08087D28 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Mothjiro_Die
	b _08087D8C
	.align 2, 0
_08087D28: .4byte gEnemyFnTable
_08087D2C:
	ldr r1, _08087D74 @ =0x08368778
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl mothjiro_08088a74
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08087D5C
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08087D8C
	ldr r0, [r5]
	cmp r0, #0
	beq _08087D7C
_08087D5C:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08087D8C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08087D78 @ =0x083687C8
	bl SetDDP
	str r6, [r5]
	b _08087D8C
	.align 2, 0
_08087D74: .4byte 0x08368778
_08087D78: .4byte 0x083687C8
_08087D7C:
	ldr r0, _08087D94 @ =0x08368794
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08087D8C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087D94: .4byte 0x08368794

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	ldr r2, _0808803C @ =gMission
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
_0808803C: .4byte gMission
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
	ldr r2, _080880F4 @ =gMission
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
_080880F4: .4byte gMission
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
	ldr r2, _080881CC @ =gMission
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
_080881CC: .4byte gMission
_080881D0: .4byte 0x0000270E
_080881D4: .4byte gEnemyFnTable

	thumb_func_start nop_080881d8
nop_080881d8: @ 0x080881D8
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_080881dc
mothjiro_080881dc: @ 0x080881DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080881EC
	cmp r0, #1
	beq _0808827E
	b _08088496
_080881EC:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088240 @ =0x083687C8
	bl SetDDP
	ldr r2, _08088244 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08088248 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808824C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0x10]
	cmp r2, #0
	bne _08088250
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
	b _08088272
	.align 2, 0
_08088240: .4byte 0x083687C8
_08088244: .4byte RNG_0202f388
_08088248: .4byte 0x000343FD
_0808824C: .4byte 0x00269EC3
_08088250:
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
_08088272:
	movs r0, #0
	strb r0, [r4, #0x13]
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808827E:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _080882EA
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _080882C4
	ldr r0, [r4, #0x54]
	ldr r2, _080882BC @ =0xFFFFFE80
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _0808836A
	ldr r1, _080882C0 @ =0xFFFF4000
	adds r0, r2, r1
	str r0, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r5, #0
	orrs r0, r3
	b _08088350
	.align 2, 0
_080882BC: .4byte 0xFFFFFE80
_080882C0: .4byte 0xFFFF4000
_080882C4:
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r1, r0
	cmp r0, #0
	bge _0808836A
	str r1, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r3, #0
	orrs r0, r5
	b _08088350
_080882EA:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _08088320
	ldr r0, [r4, #0x54]
	ldr r1, _0808831C @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	subs r0, r0, r1
	cmp r0, #0
	bge _0808836A
	str r1, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r5, #0
	orrs r0, r3
	b _08088350
	.align 2, 0
_0808831C: .4byte 0xFFFFFE80
_08088320:
	ldr r0, [r4, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _0808836A
	adds r0, r2, r1
	str r0, [r4, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808834C
	adds r0, r3, #0
	orrs r0, r5
	b _08088350
_0808834C:
	movs r0, #0xef
	ands r0, r3
_08088350:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0808836A:
	ldrb r5, [r4, #0x13]
	cmp r5, #7
	bhi _080883C8
	ldrb r3, [r4, #0x12]
	cmp r3, #0
	bne _080883A4
	ldr r0, [r4, #0x58]
	ldr r1, _0808839C @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808841E
	ldr r1, _080883A0 @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	b _0808841C
	.align 2, 0
_0808839C: .4byte 0xFFFFFB00
_080883A0: .4byte 0xFFFFF400
_080883A4:
	ldr r0, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808841E
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	b _0808841C
_080883C8:
	ldrb r3, [r4, #0x12]
	cmp r3, #0
	bne _080883F0
	ldr r0, [r4, #0x58]
	ldr r1, _080883E8 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088414
	ldr r1, _080883EC @ =0xFFFFE800
	b _08088406
	.align 2, 0
_080883E8: .4byte 0xFFFFFB00
_080883EC: .4byte 0xFFFFE800
_080883F0:
	ldr r0, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088414
_08088406:
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r4, #0x12]
	adds r0, r5, #1
	strb r0, [r4, #0x13]
_08088414:
	ldrb r0, [r4, #0x13]
	cmp r0, #0xa
	bls _0808841E
	movs r0, #0
_0808841C:
	strb r0, [r4, #0x13]
_0808841E:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08088444
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_08088444:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	bl FUN_08088ae0
	cmp r0, #0
	beq _08088496
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	subs r6, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	subs r7, r1, r0
	asrs r0, r6, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r7, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #0xe
	ldr r0, _0808849C @ =0x000077FF
	cmp r1, r0
	bgt _08088496
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08088496:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808849C: .4byte 0x000077FF

	thumb_func_start nop_080884a0
nop_080884a0: @ 0x080884A0
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_080884a4
mothjiro_080884a4: @ 0x080884A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _080884B4
	cmp r6, #1
	beq _08088566
	b _080885E8
_080884B4:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r1, [r1]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _0808850C
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_0808850C:
	ldr r1, [r4, #0x5c]
	lsls r1, r1, #9
	asrs r1, r1, #8
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	cmp r1, #0
	ble _08088544
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
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
	b _08088560
_08088544:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08088560:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08088566:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080885A2
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_080885A2:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r2, [r4, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080885B2
	subs r1, r2, r0
_080885B2:
	ldr r0, _080885F0 @ =0x00004FFF
	cmp r1, r0
	bgt _080885D6
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r0, [r0]
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080885C8
	subs r1, r2, r0
_080885C8:
	ldr r0, _080885F4 @ =0x000017FF
	cmp r1, r0
	bgt _080885D6
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_080885D6:
	adds r0, r4, #0
	bl FUN_08088ae0
	adds r1, r0, #0
	cmp r1, #0
	bne _080885E8
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080885E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080885F0: .4byte 0x00004FFF
_080885F4: .4byte 0x000017FF

	thumb_func_start nop_080885f8
nop_080885f8: @ 0x080885F8
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_080885fc
mothjiro_080885fc: @ 0x080885FC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r7, [r6, #0xe]
	cmp r7, #0
	beq _0808860C
	cmp r7, #1
	beq _08088688
	b _08088894
_0808860C:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080886C8 @ =0x083687C8
	bl SetDDP
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x5c]
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x54]
	str r0, [r6, #0x64]
	ldr r0, [r6, #0x58]
	str r0, [r6, #0x68]
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, _080886CC @ =0xFFFFF000
	adds r1, r1, r0
	ldr r5, _080886D0 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r3, _080886D4 @ =0x000343FD
	muls r0, r3, r0
	ldr r2, _080886D8 @ =0x00269EC3
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsls r0, r0, #2
	lsrs r0, r0, #0x13
	adds r1, r1, r0
	str r1, [r6, #0x64]
	adds r1, r6, #0
	adds r1, #0xbc
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsls r0, r0, #3
	lsrs r0, r0, #0x14
	ldr r1, [r1]
	adds r1, r1, r0
	str r1, [r6, #0x68]
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r0, r2
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	strb r0, [r6, #0x12]
	strb r7, [r6, #0x13]
	strb r7, [r6, #0xf]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08088688:
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08088710
	ldrb r3, [r6, #0xa]
	movs r4, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _080886E4
	ldr r0, [r6, #0x54]
	ldr r1, _080886DC @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	ldr r1, _080886E0 @ =0xFFFFD000
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r4, #0
	orrs r0, r3
	b _08088780
	.align 2, 0
_080886C8: .4byte 0x083687C8
_080886CC: .4byte 0xFFFFF000
_080886D0: .4byte RNG_0202f388
_080886D4: .4byte 0x000343FD
_080886D8: .4byte 0x00269EC3
_080886DC: .4byte 0xFFFFFE80
_080886E0: .4byte 0xFFFFD000
_080886E4:
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r3, #0
	orrs r0, r4
	b _08088780
_08088710:
	ldrb r3, [r6, #0xa]
	movs r4, #0x10
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	bne _08088750
	ldr r0, [r6, #0x54]
	ldr r1, _08088748 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	ldr r1, _0808874C @ =0xFFFFD000
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r4, #0
	orrs r0, r3
	b _08088780
	.align 2, 0
_08088748: .4byte 0xFFFFFE80
_0808874C: .4byte 0xFFFFD000
_08088750:
	ldr r0, [r6, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r2, [r6, #0x64]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	ble _0808879A
	adds r0, r2, r1
	str r0, [r6, #0x54]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x1c
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0808877C
	adds r0, r3, #0
	orrs r0, r4
	b _08088780
_0808877C:
	movs r0, #0xef
	ands r0, r3
_08088780:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0808879A:
	ldrb r4, [r6, #0x13]
	cmp r4, #7
	bhi _080887F8
	ldrb r3, [r6, #0x12]
	cmp r3, #0
	bne _080887D4
	ldr r0, [r6, #0x58]
	ldr r1, _080887CC @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808884E
	ldr r1, _080887D0 @ =0xFFFFF400
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	b _0808884C
	.align 2, 0
_080887CC: .4byte 0xFFFFFB00
_080887D0: .4byte 0xFFFFF400
_080887D4:
	ldr r0, [r6, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	ble _0808884E
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	b _0808884C
_080887F8:
	ldrb r3, [r6, #0x12]
	cmp r3, #0
	bne _08088820
	ldr r0, [r6, #0x58]
	ldr r1, _08088818 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r2, r0
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088844
	ldr r1, _0808881C @ =0xFFFFE800
	b _08088836
	.align 2, 0
_08088818: .4byte 0xFFFFFB00
_0808881C: .4byte 0xFFFFE800
_08088820:
	ldr r0, [r6, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r2, [r6, #0x68]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	ble _08088844
_08088836:
	adds r0, r2, r1
	str r0, [r6, #0x58]
	movs r0, #1
	eors r0, r3
	strb r0, [r6, #0x12]
	adds r0, r4, #1
	strb r0, [r6, #0x13]
_08088844:
	ldrb r0, [r6, #0x13]
	cmp r0, #0xa
	bls _0808884E
	movs r0, #0
_0808884C:
	strb r0, [r6, #0x13]
_0808884E:
	ldrb r0, [r6, #0xf]
	adds r0, #1
	strb r0, [r6, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08088874
	adds r0, r6, #0
	adds r0, #0x54
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_08088874:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	bl FUN_08088ae0
	adds r2, r0, #0
	cmp r2, #0
	bne _08088894
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	str r0, [r6, #0x64]
	str r1, [r6, #0x68]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r2, [r6, #0xe]
_08088894:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0808889c
nop_0808889c: @ 0x0808889C
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_080888a0
mothjiro_080888a0: @ 0x080888A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	mov r8, r0
	cmp r0, #0
	beq _080888B6
	cmp r0, #1
	beq _0808896A
	b _08088A08
_080888B6:
	movs r1, #0xd6
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _08088906
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_08088906:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08088946
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
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
	b _08088964
_08088946:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	mov r1, r8
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_08088964:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808896A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xf]
	adds r0, #1
	movs r2, #0
	mov r8, r2
	strb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080889AA
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	ands r1, r2
	bl FUN_080c2f3c
_080889AA:
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	ldr r1, _08088A14 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5]
	cmp r0, #0
	bgt _080889C0
	mov r2, r8
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_080889C0:
	adds r0, r4, #0
	bl FUN_08088ae0
	cmp r0, #0
	beq _08088A08
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r4, #0x54]
	subs r6, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	ldr r0, [r4, #0x58]
	subs r7, r1, r0
	asrs r0, r6, #2
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r7, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r1, r0, #0xe
	ldr r0, _08088A18 @ =0x000077FF
	cmp r1, r0
	bgt _08088A08
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	mov r0, r8
	strb r0, [r4, #0xe]
_08088A08:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08088A14: .4byte 0xFFFFFE00
_08088A18: .4byte 0x000077FF

	thumb_func_start nop_08088a1c
nop_08088a1c: @ 0x08088A1C
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_08088a20
mothjiro_08088a20: @ 0x08088A20
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08088A3A
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088A40 @ =0x083687E0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08088A3A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088A40: .4byte 0x083687E0

	thumb_func_start nop_08088a44
nop_08088a44: @ 0x08088A44
	movs r0, #1
	bx lr

	thumb_func_start nop_08088a48
nop_08088a48: @ 0x08088A48
	bx lr
	.align 2, 0

	thumb_func_start nop_08088a4c
nop_08088a4c: @ 0x08088A4C
	movs r0, #1
	bx lr

	thumb_func_start mothjiro_08088a50
mothjiro_08088a50: @ 0x08088A50
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08088A6A
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088A70 @ =0x083687E0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08088A6A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088A70: .4byte 0x083687E0

	thumb_func_start mothjiro_08088a74
mothjiro_08088a74: @ 0x08088A74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08088AD2
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088AD2
	ldr r2, _08088ABC @ =0x083687F8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _08088AD2
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08088AC4
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088AC0 @ =0x083687E0
	bl SetDDP
	b _08088AD2
	.align 2, 0
_08088ABC: .4byte 0x083687F8
_08088AC0: .4byte 0x083687E0
_08088AC4:
	cmp r1, #0x30
	bne _08088AD2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088ADC @ =0x083687E0
	bl SetDDP
_08088AD2:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08088ADC: .4byte 0x083687E0

	thumb_func_start FUN_08088ae0
FUN_08088ae0: @ 0x08088AE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x54
	bl FUN_08012a64
	adds r2, r0, #0
	cmp r2, #0
	bne _08088AF4
	movs r0, #0
	b _08088B04
_08088AF4:
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r0, [r2]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r2, #4]
	str r0, [r1]
	movs r0, #1
_08088B04:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08088b0c
FUN_08088b0c: @ 0x08088B0C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _08088B24
	cmp r0, #0xe
	beq _08088B24
	cmp r0, #0xf
	bne _08088B46
_08088B24:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08088B46
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _08088B42
	movs r0, #0xff
	b _08088B44
_08088B42:
	movs r0, #0xfe
_08088B44:
	strb r0, [r2, #0x11]
_08088B46:
	pop {r0}
	bx r0
	.align 2, 0
_08088B4C:
	.byte 0x70, 0xB5, 0x05, 0x1C
	.byte 0x0E, 0x1C, 0x12, 0x06, 0x14, 0x0E, 0x12, 0x48, 0x00, 0x68, 0x7E, 0xF7, 0x19, 0xFA, 0x03, 0x1C
	.byte 0x00, 0x2B, 0x19, 0xD0, 0x19, 0x1C, 0x25, 0x31, 0x00, 0x22, 0x18, 0x20, 0x08, 0x70, 0x0D, 0x48
	.byte 0x30, 0x21, 0x59, 0x72, 0xC0, 0x30, 0x00, 0x68, 0x00, 0x68, 0x58, 0x61, 0x00, 0x20, 0x1A, 0x84
	.byte 0x19, 0x1C, 0x22, 0x31, 0x08, 0x70, 0xD9, 0x7A, 0x10, 0x20, 0x08, 0x43, 0xD8, 0x72, 0x18, 0x7F
	.byte 0x58, 0x77, 0x5D, 0x65, 0x9E, 0x65, 0x1C, 0x74, 0x18, 0x1C, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0xA8, 0x02, 0x03, 0x02, 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_08088ba8
FUN_08088ba8: @ 0x08088BA8
	push {lr}
	ldr r2, [r0, #0x54]
	ldr r1, [r0, #0x58]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r2, #0
	bl PushoutToUp1
	cmp r0, #0
	blt _08088BC2
	movs r0, #0
	b _08088BC4
_08088BC2:
	movs r0, #1
_08088BC4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08088bc8
FUN_08088bc8: @ 0x08088BC8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _08088C06
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	cmp r2, #0
	bge _08088BF4
	ldr r0, [r4, #0x54]
	ldr r2, _08088BF0 @ =0xFFFFF000
	adds r1, r1, r2
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C06
	b _08088C00
	.align 2, 0
_08088BF0: .4byte 0xFFFFF000
_08088BF4:
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C06
_08088C00:
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	str r1, [r4, #0x58]
_08088C06:
	cmp r5, #0
	beq _08088C42
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
	cmp r5, #0
	bge _08088C2C
	ldr r1, [r4, #0x58]
	ldr r2, _08088C28 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToRight1
	adds r2, r0, #0
	cmp r2, #0
	ble _08088C42
	b _08088C3C
	.align 2, 0
_08088C28: .4byte 0xFFFFF800
_08088C2C:
	ldr r1, [r4, #0x58]
	ldr r2, _08088C48 @ =0xFFFFF800
	adds r1, r1, r2
	bl PushoutToLeft1
	adds r2, r0, #0
	cmp r2, #0
	bge _08088C42
_08088C3C:
	ldr r1, [r4, #0x54]
	adds r1, r1, r2
	str r1, [r4, #0x54]
_08088C42:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08088C48: .4byte 0xFFFFF800

	thumb_func_start FUN_08088c4c
FUN_08088c4c: @ 0x08088C4C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r7, #0
	adds r6, r4, #0
	adds r6, #0xc2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08088CBC
	cmp r1, #0
	beq _08088C8C
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _08088C7A
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088C8C
	b _08088C86
_08088C7A:
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088C8C
_08088C86:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08088C8C:
	cmp r5, #0
	beq _08088CD4
	ldr r0, [r4, #0x58]
	adds r1, r0, r5
	str r1, [r4, #0x58]
	cmp r5, #0
	ble _08088CA8
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08088CD4
	b _08088CB4
_08088CA8:
	ldr r0, [r4, #0x54]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r1, #0
	ble _08088CD4
_08088CB4:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _08088CD4
_08088CBC:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	str r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088CD4
	strb r7, [r6]
_08088CD4:
	ldr r0, _08088CF4 @ =gOverworld
	ldr r1, _08088CF8 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r0, r2
	ldr r0, [r4, #0x58]
	cmp r0, r1
	bge _08088CEC
	str r1, [r4, #0x58]
	movs r7, #1
_08088CEC:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08088CF4: .4byte gOverworld
_08088CF8: .4byte 0x0002C00C

	thumb_func_start FUN_08088cfc
FUN_08088cfc: @ 0x08088CFC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	mov r2, sp
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #1]
	strb r0, [r2]
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, _08088D50 @ =0xFFFFF000
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _08088D24
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08088D24:
	ldr r2, [r4, #0x54]
	ldr r0, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	adds r0, r2, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _08088D3E
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08088D3E:
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0]
	ldrb r1, [r1, #1]
	ands r0, r1
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08088D50: .4byte 0xFFFFF000

	thumb_func_start FUN_08088d54
FUN_08088d54: @ 0x08088D54
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08088D80 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl CreateVFX62
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088D80: .4byte 0xFFFFEC00

	thumb_func_start initMetallSwim
initMetallSwim: @ 0x08088D84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08088DE8
	ldr r0, _08088DDC @ =gOverworld
	ldr r1, _08088DE0 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	cmp r1, r0
	bge _08088DE8
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08088DE4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _08088F6E
	.align 2, 0
_08088DDC: .4byte gOverworld
_08088DE0: .4byte 0x0002C00C
_08088DE4: .4byte gEnemyFnTable
_08088DE8:
	ldr r1, _08088E50 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r6, #1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08088E54 @ =0x08368948
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08088E58 @ =0x08368814
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #2
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08088E5C @ =FUN_08089218
	str r0, [r4, #0x24]
	adds r1, r5, #0
	adds r1, #0xb8
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08088E60
	adds r0, r5, #0
	adds r0, #0xc2
	strb r6, [r0]
	b _08088E66
	.align 2, 0
_08088E50: .4byte gEnemyFnTable
_08088E54: .4byte 0x08368948
_08088E58: .4byte 0x08368814
_08088E5C: .4byte FUN_08089218
_08088E60:
	adds r1, r5, #0
	adds r1, #0xc2
	strb r0, [r1]
_08088E66:
	ldrb r0, [r5, #0x10]
	cmp r0, #4
	beq _08088ECE
	adds r0, r5, #0
	bl InitNonAffineMotion
	movs r2, #0
	ldr r0, _08088E90 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08088E84
	movs r2, #1
_08088E84:
	cmp r2, #0
	beq _08088E94
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08088E9A
	.align 2, 0
_08088E90: .4byte pZero2
_08088E94:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08088E9A:
	strb r0, [r5, #0xa]
	movs r3, #1
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5, #0xa]
	orrs r3, r0
	strb r3, [r5, #0xa]
	ldr r1, _08088F74 @ =0x0836894E
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_08088ECE:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08088F16
	ldr r0, _08088F78 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08088F16
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08088F7C @ =gEnemyFnTable
	movs r1, #0x30
	strb r1, [r3, #9]
	adds r0, #0xc0
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
	movs r0, #4
	strb r0, [r3, #0x10]
	str r5, [r3, #0x28]
_08088F16:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _08088F20
	cmp r0, #3
	bne _08088F3E
_08088F20:
	ldr r1, [r5, #0x58]
	ldr r0, _08088F80 @ =0x000007FF
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088F3E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_08088F3E:
	adds r0, r5, #0
	bl isFrozen
	cmp r0, #0
	beq _08088F68
	ldr r1, _08088F84 @ =0x083688D4
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _08088F88 @ =0x08368908
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08088F68:
	adds r0, r5, #0
	bl metallSwimAI
_08088F6E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08088F74: .4byte 0x0836894E
_08088F78: .4byte gZakoHeaderPtr
_08088F7C: .4byte gEnemyFnTable
_08088F80: .4byte 0x000007FF
_08088F84: .4byte 0x083688D4
_08088F88: .4byte 0x08368908

	thumb_func_start metallSwimAI
metallSwimAI: @ 0x08088F8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08088FA0
	cmp r0, #3
	bne _08088FDC
_08088FA0:
	ldr r0, _08088FD4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bhi _08088FF4
	adds r0, r4, #0
	bl FUN_08088cfc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08088FDC
	ldr r1, _08088FD8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	b _08089128
	.align 2, 0
_08088FD4: .4byte gStageRun+232
_08088FD8: .4byte gEnemyFnTable
_08088FDC:
	ldrb r3, [r4, #0x10]
	cmp r3, #4
	beq _08088FE4
	b _080890E8
_08088FE4:
	ldrb r0, [r7, #0xc]
	cmp r0, #2
	bhi _08088FF4
	cmp r0, #1
	bls _08089030
	adds r0, r7, #0
	bl FUN_08088d54
_08088FF4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808902C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080891E8
	.align 2, 0
_0808902C: .4byte gEnemyFnTable
_08089030:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	adds r0, r7, #0
	bl FUN_08088d54
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, _080890C8 @ =gEnemyFnTable
	mov r8, r0
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldr r5, [r7, #0x54]
	ldr r6, [r7, #0x58]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08088bc8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08088bc8
	orrs r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r5, [r7, #0x54]
	str r6, [r7, #0x58]
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _080890CC
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl killMetallSwim
	b _080891E8
	.align 2, 0
_080890C8: .4byte gEnemyFnTable
_080890CC:
	ldr r1, _080890E4 @ =0x0000DD07
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #8
	strb r0, [r7, #0xd]
	strb r4, [r7, #0xe]
	b _080891E8
	.align 2, 0
_080890E4: .4byte 0x0000DD07
_080890E8:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	adds r6, r0, #0
	cmp r1, #0
	beq _08089130
	ldr r1, _08089120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08089124
	cmp r3, #2
	beq _08089124
	movs r0, #1
	b _08089126
	.align 2, 0
_08089120: .4byte gEnemyFnTable
_08089124:
	movs r0, #0
_08089126:
	strb r0, [r4, #0xd]
_08089128:
	adds r0, r4, #0
	bl killMetallSwim
	b _080891E8
_08089130:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xc
	beq _080891C8
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08089150
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808914A
	movs r0, #1
	strb r0, [r4, #0xf]
_0808914A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080891C8
_08089150:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0808915A
	cmp r0, #3
	bne _08089192
_0808915A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r1, r5
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _08089176
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08088bc8
_08089176:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	adds r1, r1, r5
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808919C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	b _0808919C
_08089192:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08088c4c
_0808919C:
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	bne _080891AC
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r4, #0xf]
_080891AC:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080891B8
	strb r0, [r4, #0xf]
_080891B8:
	ldr r0, [r6]
	ldr r1, _080891F4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080891E8
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _080891E8
_080891C8:
	ldr r1, _080891F8 @ =0x083688D4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080891FC @ =0x08368908
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080891E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080891F4: .4byte 0x00020001
_080891F8: .4byte 0x083688D4
_080891FC: .4byte 0x08368908

	thumb_func_start killMetallSwim
killMetallSwim: @ 0x08089200
	push {lr}
	ldr r2, _08089214 @ =0x0836893C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08089214: .4byte 0x0836893C

	thumb_func_start FUN_08089218
FUN_08089218: @ 0x08089218
	push {lr}
	ldr r3, [r0, #0x2c]
	ldr r1, [r0, #0xc]
	ldr r2, [r1, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08089248
	ldrh r1, [r2, #8]
	ldr r0, _0808925C @ =0x00001206
	cmp r1, r0
	bne _08089248
	ldr r1, _08089260 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
	movs r0, #0
	strb r0, [r3, #0xd]
_08089248:
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, _08089264 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0808925C: .4byte 0x00001206
_08089260: .4byte gEnemyFnTable
_08089264: .4byte pZero2

	thumb_func_start nop_08089268
nop_08089268: @ 0x08089268
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808926c
FUN_0808926c: @ 0x0808926C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089282
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089282:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080892A0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08089298
	movs r1, #0
	movs r0, #0xc
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089298:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080892A0: .4byte 0x00020001

	thumb_func_start FUN_080892a4
FUN_080892a4: @ 0x080892A4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080892C0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080892BC
	movs r1, #0
	movs r0, #0xc
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080892BC:
	pop {r0}
	bx r0
	.align 2, 0
_080892C0: .4byte 0x00020001

	thumb_func_start FUN_080892c4
FUN_080892c4: @ 0x080892C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080892D4
	cmp r0, #1
	beq _080892F2
	b _08089358
_080892D4:
	str r0, [r4, #0x5c]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089300 @ =0x08368814
	bl SetDDP
	ldr r1, _08089304 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080892F2:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08089308
	subs r0, #1
	strb r0, [r4, #0x12]
	ldr r3, [r4, #0x54]
	b _08089338
	.align 2, 0
_08089300: .4byte 0x08368814
_08089304: .4byte 0x0000DD02
_08089308:
	ldr r0, _08089320 @ =pZero2
	ldr r0, [r0]
	ldr r2, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r1, r2, r0
	adds r3, r0, #0
	cmp r1, #0
	blt _08089328
	ldr r0, _08089324 @ =0x00005FFF
	cmp r1, r0
	ble _08089330
	b _08089338
	.align 2, 0
_08089320: .4byte pZero2
_08089324: .4byte 0x00005FFF
_08089328:
	subs r1, r3, r2
	ldr r0, _08089360 @ =0x00005FFF
	cmp r1, r0
	bgt _08089338
_08089330:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089338:
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r0, r3, #0
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08089358:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089360: .4byte 0x00005FFF

	thumb_func_start FUN_08089364
FUN_08089364: @ 0x08089364
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089374
	cmp r0, #1
	beq _080893FE
	b _0808949E
_08089374:
	movs r2, #0
	ldr r0, _08089394 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08089386
	movs r2, #1
_08089386:
	adds r5, r2, #0
	cmp r5, #0
	beq _08089398
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808939E
	.align 2, 0
_08089394: .4byte pZero2
_08089398:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808939E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r6, #0
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #0xa
	ldr r0, _080893E8 @ =0xFFFFF600
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080893EC @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080893F0
	strb r6, [r4, #0xd]
	strb r6, [r4, #0xe]
	adds r0, r4, #0
	bl FUN_080892c4
	b _0808949E
	.align 2, 0
_080893E8: .4byte 0xFFFFF600
_080893EC: .4byte 0xFFFFF800
_080893F0:
	ldr r1, _0808942C @ =0x0000DD03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080893FE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089484
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r3, r1, r0
	lsrs r2, r3, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08089430
	cmp r2, #0
	beq _08089434
	b _0808944E
	.align 2, 0
_0808942C: .4byte 0x0000DD03
_08089430:
	cmp r2, #0
	beq _0808944E
_08089434:
	adds r1, r3, #0
	cmp r1, #0
	bge _0808943C
	rsbs r1, r1, #0
_0808943C:
	movs r0, #0xe0
	lsls r0, r0, #7
	cmp r1, r0
	ble _0808944E
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0808949E
_0808944E:
	ldr r2, _08089470 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08089474 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08089478 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	cmp r0, #9
	bhi _0808947C
	movs r1, #0
	movs r0, #3
	b _08089480
	.align 2, 0
_08089470: .4byte RNG_0202f388
_08089474: .4byte 0x000343FD
_08089478: .4byte 0x00269EC3
_0808947C:
	movs r1, #0
	movs r0, #4
_08089480:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089484:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
_0808949E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080894a4
FUN_080894a4: @ 0x080894A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bhi _08089578
	lsls r0, r0, #2
	ldr r1, _080894B8 @ =_080894BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080894B8: .4byte _080894BC
_080894BC: @ jump table
	.4byte _080894DC @ case 0
	.4byte _080894EA @ case 1
	.4byte _08089504 @ case 2
	.4byte _08089512 @ case 3
	.4byte _0808952C @ case 4
	.4byte _0808953A @ case 5
	.4byte _08089554 @ case 6
	.4byte _08089562 @ case 7
_080894DC:
	ldr r1, _08089500 @ =0x0000DD01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080894EA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089500: .4byte 0x0000DD01
_08089504:
	ldr r1, _08089528 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089512:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089528: .4byte 0x0000DD02
_0808952C:
	ldr r1, _08089550 @ =0x0000DD0D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808953A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08089576
	.align 2, 0
_08089550: .4byte 0x0000DD0D
_08089554:
	ldr r1, _08089598 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089562:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089578
	movs r0, #0
	strb r0, [r4, #0xd]
_08089576:
	strb r0, [r4, #0xe]
_08089578:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089598: .4byte 0x0000DD02

	thumb_func_start FUN_0808959c
FUN_0808959c: @ 0x0808959C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080895AC
	cmp r0, #1
	beq _080895F0
	b _08089688
_080895AC:
	ldr r0, _08089614 @ =0xFFFFFE80
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080895C4
	movs r2, #0xc0
	lsls r2, r2, #1
_080895C4:
	str r2, [r4, #0x5c]
	ldr r0, _08089618 @ =0xFFFFF600
	str r0, [r4, #0x64]
	cmp r1, #0
	beq _080895D2
	movs r0, #0xa0
	lsls r0, r0, #4
_080895D2:
	str r0, [r4, #0x64]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808961C @ =0x08368844
	bl SetDDP
	ldr r1, _08089620 @ =0x0000DD05
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x5a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080895F0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	subs r3, r1, r0
	lsrs r2, r3, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08089624
	cmp r2, #0
	beq _08089628
	b _08089642
	.align 2, 0
_08089614: .4byte 0xFFFFFE80
_08089618: .4byte 0xFFFFF600
_0808961C: .4byte 0x08368844
_08089620: .4byte 0x0000DD05
_08089624:
	cmp r2, #0
	beq _08089642
_08089628:
	adds r1, r3, #0
	cmp r1, #0
	bge _08089630
	rsbs r1, r1, #0
_08089630:
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _08089642
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08089688
_08089642:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089664
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08089690 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808966C
_08089664:
	movs r0, #2
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_0808966C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	ldr r1, [r4, #0x5c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl FUN_08088bc8
_08089688:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089690: .4byte 0xFFFFF800

	thumb_func_start FUN_08089694
FUN_08089694: @ 0x08089694
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080896A6
	cmp r0, #1
	beq _08089710
	b _0808977E
_080896A6:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080896D8 @ =0x08368844
	bl SetDDP
	ldr r1, _080896DC @ =0x0000DD04
	adds r0, r5, #0
	bl SetMotion
	movs r2, #0
	ldr r0, _080896E0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080896CA
	movs r2, #1
_080896CA:
	cmp r2, #0
	beq _080896E4
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080896EA
	.align 2, 0
_080896D8: .4byte 0x08368844
_080896DC: .4byte 0x0000DD04
_080896E0: .4byte pZero2
_080896E4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080896EA:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089710:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne _08089752
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldr r1, [r5, #0x54]
	ldr r0, _08089788 @ =0xFFFFFA00
	adds r1, r1, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #0xa
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808978C @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	movs r1, #0x80
	lsls r1, r1, #2
	lsls r4, r4, #7
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_08089752:
	ldrb r1, [r5, #0x12]
	cmp r1, #0
	bne _0808975E
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808975E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r5, #0
	bl FUN_08088bc8
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0808977E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089788: .4byte 0xFFFFFA00
_0808978C: .4byte 0xFFFFFE00

	thumb_func_start FUN_08089790
FUN_08089790: @ 0x08089790
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0808979C
	b _080898B2
_0808979C:
	lsls r0, r0, #2
	ldr r1, _080897A8 @ =_080897AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080897A8: .4byte _080897AC
_080897AC: @ jump table
	.4byte _080897C4 @ case 0
	.4byte _080897E0 @ case 1
	.4byte _08089830 @ case 2
	.4byte _0808983E @ case 3
	.4byte _08089874 @ case 4
	.4byte _08089882 @ case 5
_080897C4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089828 @ =0x08368814
	bl SetDDP
	ldr r1, _0808982C @ =0x0000DD01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080897E0:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08088bc8
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _080897F8
	adds r0, #0xff
_080897F8:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808980C
	str r1, [r4, #0x60]
_0808980C:
	adds r0, r4, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808981E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808981E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080898B2
	.align 2, 0
_08089828: .4byte 0x08368814
_0808982C: .4byte 0x0000DD01
_08089830:
	ldr r1, _08089870 @ =0x0000DD02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808983E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089854
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089854:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl FUN_08088bc8
	b _080898B2
	.align 2, 0
_08089870: .4byte 0x0000DD02
_08089874:
	ldr r1, _080898B8 @ =0x0000DD0D
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089882:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089898
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_08089898:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl FUN_08088bc8
_080898B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080898B8: .4byte 0x0000DD0D

	thumb_func_start FUN_080898bc
FUN_080898bc: @ 0x080898BC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _080898CE
	cmp r4, #1
	beq _080898F2
	b _080899EA
_080898CE:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808994C @ =0x08368844
	bl SetDDP
	ldr r1, _08089950 @ =0x0000DD06
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	adds r1, r6, #0
	adds r1, #0xc0
	movs r0, #0x78
	strh r0, [r1]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080898F2:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r2, [r6, #0x12]
	adds r3, r2, #0
	cmp r2, #0
	bne _08089908
	ldrb r0, [r6, #0x13]
	movs r1, #1
	eors r0, r1
	strb r0, [r6, #0x13]
_08089908:
	ldrb r0, [r6, #0x13]
	cmp r0, #0
	beq _08089958
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r4, r0, r1
	ldr r3, _08089954 @ =gSineTable
	movs r1, #0x80
	subs r1, r1, r2
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	b _0808998A
	.align 2, 0
_0808994C: .4byte 0x08368844
_08089950: .4byte 0x0000DD06
_08089954: .4byte gSineTable
_08089958:
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r5, _080899F4 @ =0xFFFFE800
	adds r4, r0, r5
	ldr r2, _080899F8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	str r4, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r4, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
_0808998A:
	lsls r0, r0, #5
	adds r4, r4, r0
	str r4, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xc0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080899E4
	movs r0, #0x78
	strh r0, [r1]
	movs r0, #0x2c
	bl PlaySound
	ldr r0, [r6, #0x54]
	ldr r2, _080899FC @ =0xFFFFF800
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, [r6, #0x58]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r5, #0x80
	lsls r5, r5, #2
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xe0
	bl CreateLemon
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0xa0
	bl CreateLemon
_080899E4:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080899EA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080899F4: .4byte 0xFFFFE800
_080899F8: .4byte gSineTable
_080899FC: .4byte 0xFFFFF800

	thumb_func_start FUN_08089a00
FUN_08089a00: @ 0x08089A00
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089A12
	cmp r0, #1
	beq _08089A22
	b _08089A2A
_08089A12:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089A30 @ =0x08368874
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089A22:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_08089A2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089A30: .4byte 0x08368874

	thumb_func_start FUN_08089a34
FUN_08089a34: @ 0x08089A34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #5
	bls _08089A40
	b _08089B3E
_08089A40:
	lsls r0, r0, #2
	ldr r1, _08089A4C @ =_08089A50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08089A4C: .4byte _08089A50
_08089A50: @ jump table
	.4byte _08089A68 @ case 0
	.4byte _08089A88 @ case 1
	.4byte _08089AB8 @ case 2
	.4byte _08089AC6 @ case 3
	.4byte _08089B00 @ case 4
	.4byte _08089B0E @ case 5
_08089A68:
	movs r4, #0
	strb r4, [r5, #0x10]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08089AB0 @ =0x08368814
	bl SetDDP
	ldr r1, _08089AB4 @ =0x0000DD07
	adds r0, r5, #0
	bl SetMotion
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089A88:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089AA2
	str r1, [r5, #0x60]
_08089AA2:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089AF2
	b _08089AEC
	.align 2, 0
_08089AB0: .4byte 0x08368814
_08089AB4: .4byte 0x0000DD07
_08089AB8:
	ldr r1, _08089AFC @ =0x0000DD08
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089AC6:
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089AE0
	str r1, [r5, #0x60]
_08089AE0:
	adds r0, r5, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089AF2
_08089AEC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089AF2:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08089B3E
	.align 2, 0
_08089AFC: .4byte 0x0000DD08
_08089B00:
	ldr r1, _08089B44 @ =0x0000DD0E
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08089B0E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089B2E
	str r1, [r5, #0x60]
_08089B2E:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089B3E
	movs r0, #0
	strb r0, [r5, #0xd]
	strb r0, [r5, #0xe]
_08089B3E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089B44: .4byte 0x0000DD0E

	thumb_func_start FUN_08089b48
FUN_08089b48: @ 0x08089B48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089B58
	cmp r0, #1
	beq _08089C0E
	b _08089C84
_08089B58:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089BC0 @ =0x08368844
	bl SetDDP
	ldr r1, _08089BC4 @ =0x0000DD09
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _08089BC8 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	ldr r2, _08089BCC @ =0xFFFFF000
	adds r1, r1, r2
	lsls r0, r0, #8
	asrs r0, r0, #0x10
	lsls r1, r1, #8
	asrs r1, r1, #0x10
	bl ArcTan2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	adds r0, #0x10
	movs r5, #0xe0
	ands r5, r0
	ldr r1, _08089BD0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	movs r1, #0
	cmp r0, #0
	ble _08089BB2
	movs r1, #1
_08089BB2:
	adds r2, r1, #0
	cmp r2, #0
	beq _08089BD4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08089BDA
	.align 2, 0
_08089BC0: .4byte 0x08368844
_08089BC4: .4byte 0x0000DD09
_08089BC8: .4byte pZero2
_08089BCC: .4byte 0xFFFFF000
_08089BD0: .4byte gSineTable
_08089BD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08089BDA:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08089C8C @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089C0E:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08088c4c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089C28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _08089C28
	subs r0, #1
	strb r0, [r4, #0x12]
_08089C28:
	adds r3, r4, #0
	adds r3, #0xb8
	ldr r0, [r4, #0x54]
	ldr r1, [r3]
	subs r2, r0, r1
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	ble _08089C3E
	adds r0, r1, r0
	str r0, [r4, #0x54]
_08089C3E:
	ldr r0, _08089C90 @ =0xFFFF6000
	cmp r2, r0
	bge _08089C4C
	ldr r0, [r3]
	ldr r5, _08089C90 @ =0xFFFF6000
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08089C4C:
	ldr r0, [r4, #0x5c]
	movs r1, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	bge _08089C58
	adds r0, #0xff
_08089C58:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	muls r0, r1, r0
	cmp r0, #0
	bge _08089C66
	adds r0, #0xff
_08089C66:
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089C7E
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089C7E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08089C84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089C8C: .4byte gSineTable
_08089C90: .4byte 0xFFFF6000

	thumb_func_start FUN_08089c94
FUN_08089c94: @ 0x08089C94
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bls _08089CA0
	b _08089E56
_08089CA0:
	lsls r0, r0, #2
	ldr r1, _08089CAC @ =_08089CB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08089CAC: .4byte _08089CB0
_08089CB0: @ jump table
	.4byte _08089CD8 @ case 0
	.4byte _08089CF2 @ case 1
	.4byte _08089D6A @ case 2
	.4byte _08089DD4 @ case 3
	.4byte _08089D74 @ case 4
	.4byte _08089D82 @ case 5
	.4byte _08089DBC @ case 6
	.4byte _08089DD4 @ case 7
	.4byte _08089E10 @ case 8
	.4byte _08089E22 @ case 9
_08089CD8:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089D10 @ =0x08368844
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089CF2:
	movs r2, #0
	ldr r0, _08089D14 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08089D04
	movs r2, #1
_08089D04:
	cmp r2, #0
	beq _08089D18
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08089D1E
	.align 2, 0
_08089D10: .4byte 0x08368844
_08089D14: .4byte pZero2
_08089D18:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08089D1E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089D54
	str r1, [r4, #0x60]
_08089D54:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089DAE
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08089DAE
_08089D6A:
	ldr r1, _08089D70 @ =0x0000DD0A
	b _08089DC8
	.align 2, 0
_08089D70: .4byte 0x0000DD0A
_08089D74:
	ldr r1, _08089DB8 @ =0x0000DD0B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089D82:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088bc8
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08089D9C
	str r1, [r4, #0x60]
_08089D9C:
	adds r0, r4, #0
	bl FUN_08088ba8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08089DAE
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089DAE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08089E56
	.align 2, 0
_08089DB8: .4byte 0x0000DD0B
_08089DBC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089E08 @ =0x08368814
	bl SetDDP
	ldr r1, _08089E0C @ =0x0000DD0F
_08089DC8:
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089DD4:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089DEE
	str r1, [r4, #0x60]
_08089DEE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089E56
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08089E56
	.align 2, 0
_08089E08: .4byte 0x08368814
_08089E0C: .4byte 0x0000DD0F
_08089E10:
	ldr r1, _08089E5C @ =0x0000DD0B
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089E22:
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08088c4c
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _08089E3C
	str r1, [r4, #0x60]
_08089E3C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08089E50
	movs r0, #0xb
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089E50:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08089E56:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089E5C: .4byte 0x0000DD0B

	thumb_func_start FUN_08089e60
FUN_08089e60: @ 0x08089E60
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08089E70
	cmp r0, #1
	beq _08089E88
	b _08089EA0
_08089E70:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08089EA8 @ =0x08368814
	bl SetDDP
	ldr r1, _08089EAC @ =0x0000DD0C
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08089E88:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08089EA0
	movs r1, #0
	movs r0, #9
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08089EA0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089EA8: .4byte 0x08368814
_08089EAC: .4byte 0x0000DD0C

	thumb_func_start FUN_08089eb0
FUN_08089eb0: @ 0x08089EB0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r2, [r5, #0xe]
	cmp r2, #0
	beq _08089EC2
	cmp r2, #1
	beq _08089F40
	b _08089F52
_08089EC2:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08089F04 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08089F08
	movs r0, #0x31
	bl PlaySound
	b _08089F0E
	.align 2, 0
_08089F04: .4byte 0xFFFFF800
_08089F08:
	movs r0, #0x2a
	bl PlaySound
_08089F0E:
	ldr r2, _08089F38 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08089F3C @ =0x0000270E
	cmp r1, r0
	bhi _08089F1C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08089F1C:
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08089F52
	.align 2, 0
_08089F38: .4byte gMission
_08089F3C: .4byte 0x0000270E
_08089F40:
	ldr r1, _08089F5C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08089F52:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089F5C: .4byte gEnemyFnTable

	thumb_func_start FUN_08089f60
FUN_08089f60: @ 0x08089F60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08089F70
	cmp r0, #1
	beq _0808A002
	b _0808A05E
_08089F70:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08089FE4 @ =0x083688A4
	bl SetDDP
	ldr r1, _08089FE8 @ =0x0000DD02
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08089FEC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08089FF0 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08089FF4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08089FFC
	.align 2, 0
_08089FE4: .4byte 0x083688A4
_08089FE8: .4byte 0x0000DD02
_08089FEC: .4byte pZero2
_08089FF0: .4byte 0xFFFFE800
_08089FF4:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08089FFC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808A002:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808A020
	str r1, [r5, #0x60]
_0808A020:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808A042
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0808A05E
_0808A042:
	movs r0, #0
	strb r0, [r5, #0xe]
	adds r0, r5, #0
	bl FUN_08089eb0
	ldr r1, _0808A064 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_0808A05E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A064: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a068
FUN_0808a068: @ 0x0808A068
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _0808A07A
	cmp r2, #1
	beq _0808A0CE
	b _0808A0E0
_0808A07A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0808A0BC @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	bne _0808A0C0
	movs r0, #0x31
	bl PlaySound
	b _0808A0C6
	.align 2, 0
_0808A0BC: .4byte 0xFFFFF800
_0808A0C0:
	movs r0, #0x2a
	bl PlaySound
_0808A0C6:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808A0E0
_0808A0CE:
	ldr r1, _0808A0E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0808A0E0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A0E8: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a0ec
FUN_0808a0ec: @ 0x0808A0EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808A138 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A130
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A13C @ =gEnemyFnTable
	movs r1, #0x31
	strb r1, [r4, #9]
	adds r0, #0xc4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x28]
_0808A130:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808A138: .4byte gZakoHeaderPtr
_0808A13C: .4byte gEnemyFnTable

	thumb_func_start nop_0808a140
nop_0808a140: @ 0x0808A140
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808a144
FUN_0808a144: @ 0x0808A144
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808A18C
	ldr r1, _0808A17C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808A180
	movs r0, #1
	strb r0, [r2, #0xd]
	b _0808A182
	.align 2, 0
_0808A17C: .4byte gEnemyFnTable
_0808A180:
	strb r1, [r2, #0xd]
_0808A182:
	adds r0, r2, #0
	bl killPantheonBase
	movs r0, #1
	b _0808A18E
_0808A18C:
	movs r0, #0
_0808A18E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start pBase_0808a194
pBase_0808a194: @ 0x0808A194
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _0808A208
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808A1AE
	cmp r0, #1
	beq _0808A1F0
	b _0808A208
_0808A1AE:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808A208
	ldr r1, _0808A1E8 @ =0x0836896C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808A1EC @ =0x08368974
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #1
	b _0808A20A
	.align 2, 0
_0808A1E8: .4byte 0x0836896C
_0808A1EC: .4byte 0x08368974
_0808A1F0:
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808A206
	movs r0, #1
	b _0808A20A
_0808A206:
	strb r0, [r4, #0xf]
_0808A208:
	movs r0, #0
_0808A20A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start pBase_0808a210
pBase_0808a210: @ 0x0808A210
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r5, [r6]
	cmp r5, #0
	bne _0808A23E
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808A23E
	ldr r2, _0808A244 @ =0x08368BDC
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808A23E
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808A23E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A244: .4byte 0x08368BDC

	thumb_func_start initPantheonBase
initPantheonBase: @ 0x0808A248
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808A2B0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _0808A2B4 @ =0x08368BE4
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldr r0, _0808A2B8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x10]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0808A2C4
	ldr r0, _0808A2BC @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808A2C4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A2C0 @ =0x08368984
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _0808A2DC
	.align 2, 0
_0808A2B0: .4byte gEnemyFnTable
_0808A2B4: .4byte 0x08368BE4
_0808A2B8: .4byte gSystemSavedataManager
_0808A2BC: .4byte gCurStory
_0808A2C0: .4byte 0x08368984
_0808A2C4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A2FC @ =0x08368984
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_0808A2DC:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808A300 @ =nop_0808a140
	str r0, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	adds r0, r6, #0
	bl pantheonBaseAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808A2FC: .4byte 0x08368984
_0808A300: .4byte nop_0808a140

	thumb_func_start pantheonBaseAI
pantheonBaseAI: @ 0x0808A304
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808A320 @ =gCurStory
	ldrb r0, [r0, #8]
	movs r2, #0x42
	ands r2, r0
	cmp r2, #0
	beq _0808A324
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0808A332
	.align 2, 0
_0808A320: .4byte gCurStory
_0808A324:
	ldr r5, [r4, #0x28]
	ldrb r0, [r5, #0xc]
	cmp r0, #2
	bls _0808A368
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808A332:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808A364 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808A3CE
	.align 2, 0
_0808A364: .4byte gEnemyFnTable
_0808A368:
	adds r0, r4, #0
	bl FUN_0808a144
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0808A3CE
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0808A39C
	ldr r1, _0808A398 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
	adds r0, r4, #0
	bl killPantheonBase
	b _0808A3CE
	.align 2, 0
_0808A398: .4byte gEnemyFnTable
_0808A39C:
	adds r0, r4, #0
	bl pBase_0808a210
	adds r0, r4, #0
	bl pBase_0808a194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808A3CE
	ldr r1, _0808A3D4 @ =0x0836896C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808A3D8 @ =0x08368974
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808A3CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A3D4: .4byte 0x0836896C
_0808A3D8: .4byte 0x08368974

	thumb_func_start killPantheonBase
killPantheonBase: @ 0x0808A3DC
	push {lr}
	ldr r2, _0808A3F0 @ =0x0836897C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808A3F0: .4byte 0x0836897C

	thumb_func_start nop_0808a3f4
nop_0808a3f4: @ 0x0808A3F4
	bx lr
	.align 2, 0

	thumb_func_start pBase_0808a3f8
pBase_0808a3f8: @ 0x0808A3F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808A40E
	bl isKilled
	cmp r0, #0
	beq _0808A42E
_0808A40E:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808A434 @ =0x08368984
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808A42E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808A42E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A434: .4byte 0x08368984

	thumb_func_start pBase_0808a438
pBase_0808a438: @ 0x0808A438
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808A44A
	cmp r0, #1
	beq _0808A46A
	b _0808A472
_0808A44A:
	movs r1, #0xda
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808A478 @ =0x083689CC
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808A46A:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_0808A472:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A478: .4byte 0x083689CC

	thumb_func_start pBase_0808a47c
pBase_0808a47c: @ 0x0808A47C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808A48E
	cmp r0, #1
	beq _0808A49E
	b _0808A50C
_0808A48E:
	movs r1, #0xda
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808A49E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808A4D4 @ =0x08368BE5
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808A4D8 @ =0x08368984
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0808A4DC
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808A4E2
	.align 2, 0
_0808A4D4: .4byte 0x08368BE5
_0808A4D8: .4byte 0x08368984
_0808A4DC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808A4E2:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808A50C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start pBase_0808a514
pBase_0808a514: @ 0x0808A514
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808A5B4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r4, _0808A5B8 @ =0x08368BEE
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r2, r4, #6
	adds r0, r5, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r4, #0xc
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #4
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808A5BC @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808A5C0 @ =0x0000270E
	cmp r1, r0
	bhi _0808A590
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808A590:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _0808A5C4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808A5B4: .4byte 0xFFFFF000
_0808A5B8: .4byte 0x08368BEE
_0808A5BC: .4byte gMission
_0808A5C0: .4byte 0x0000270E
_0808A5C4: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a5c8
FUN_0808a5c8: @ 0x0808A5C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r7, [r5, #0x28]
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808A5DC
	cmp r6, #1
	beq _0808A65A
	b _0808A6A4
_0808A5DC:
	movs r4, #0
	ldr r0, _0808A6AC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808A5EE
	movs r4, #1
_0808A5EE:
	lsls r0, r4, #8
	subs r0, r1, r0
	str r0, [r5, #0x54]
	ldr r1, _0808A6B0 @ =0x00006D01
	adds r0, r5, #0
	bl SetMotion
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
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	ldr r0, [r7, #0x5c]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [sp, #8]
	movs r0, #0x60
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808A6B4 @ =0x08368C00
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0x40
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldr r0, [r7, #0x5c]
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808A65A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x20
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808A672
	str r1, [r5, #0x60]
_0808A672:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808A69E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _0808A6B8 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808A6A4
_0808A69E:
	adds r0, r5, #0
	bl pBase_0808a514
_0808A6A4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A6AC: .4byte pZero2
_0808A6B0: .4byte 0x00006D01
_0808A6B4: .4byte 0x08368C00
_0808A6B8: .4byte 0xFFFFF000

	thumb_func_start FUN_0808a6bc
FUN_0808a6bc: @ 0x0808A6BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808A724 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	mov ip, r0
	cmp r0, #0
	beq _0808A75A
	mov r1, ip
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A728 @ =gEnemyFnTable
	movs r1, #0x32
	mov r3, ip
	strb r1, [r3, #9]
	adds r0, #0xc8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	mov r1, ip
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r3, #0xb]
	movs r3, #0x10
	orrs r0, r3
	mov r1, ip
	strb r0, [r1, #0xb]
	ldrb r0, [r1, #0x1c]
	strb r0, [r1, #0x1d]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	mov r2, ip
	str r0, [r2, #0x54]
	str r1, [r2, #0x58]
	str r4, [r2, #0x28]
	ldrb r0, [r4, #0xa]
	lsrs r2, r0, #4
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0808A72C
	mov r1, ip
	ldrb r0, [r1, #0xa]
	orrs r0, r3
	strb r0, [r1, #0xa]
	b _0808A736
	.align 2, 0
_0808A724: .4byte gZakoHeaderPtr
_0808A728: .4byte gEnemyFnTable
_0808A72C:
	mov r3, ip
	ldrb r1, [r3, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r3, #0xa]
_0808A736:
	adds r1, r2, #0
	mov r0, ip
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	mov r4, ip
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r0, ip
	strb r3, [r0, #0x10]
	strb r3, [r0, #0x11]
	b _0808A75C
_0808A75A:
	movs r0, #0
_0808A75C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808A764:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0xAC, 0x6A, 0x8C, 0xF7, 0xCB, 0xFD, 0x28, 0x1C
	.byte 0x8C, 0xF7, 0xF0, 0xFE, 0xA9, 0x7A, 0x01, 0x20, 0x08, 0x43, 0x02, 0x21, 0x08, 0x43, 0xA8, 0x72
	.byte 0x09, 0x49, 0x28, 0x1C, 0x8C, 0xF7, 0xF0, 0xFE, 0xE9, 0x7A, 0x10, 0x20, 0x08, 0x43, 0xE8, 0x72
	.byte 0x20, 0x7F, 0x68, 0x77, 0xA9, 0x7A, 0x10, 0x20, 0x08, 0x40, 0x00, 0x28, 0x06, 0xD0, 0x40, 0x20
	.byte 0x40, 0x42, 0xE8, 0x65, 0x01, 0x20, 0x04, 0xE0, 0x04, 0xB5, 0x00, 0x00, 0x40, 0x20, 0xE8, 0x65
	.byte 0x41, 0x38, 0x68, 0x66, 0x00, 0x20, 0xA8, 0x74, 0x07, 0x49, 0x68, 0x7A, 0x80, 0x00, 0x40, 0x18
	.byte 0x01, 0x21, 0xE9, 0x60, 0x00, 0x68, 0x40, 0x68, 0x68, 0x61, 0x28, 0x1C, 0x00, 0xF0, 0x06, 0xF8
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0808a7dc
FUN_0808a7dc: @ 0x0808A7DC
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldrb r2, [r4, #0xf]
	adds r3, r2, #0
	cmp r3, #0
	bne _0808A810
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x64]
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bls _0808A82A
	adds r0, r2, #1
	strb r0, [r4, #0xf]
	strb r3, [r4, #0x12]
	b _0808A82A
_0808A810:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #2
	bls _0808A82A
	ldr r1, _0808A830 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808A82A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A830: .4byte gEnemyFnTable
_0808A834:
	.byte 0x82, 0x7A, 0xFE, 0x21, 0x11, 0x40, 0x81, 0x72, 0x04, 0x4A, 0x41, 0x7A
	.byte 0x89, 0x00, 0x89, 0x18, 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69, 0x41, 0x61, 0x70, 0x47
	.byte 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0808a854
FUN_0808a854: @ 0x0808A854
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808A8A8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A89E
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A8AC @ =gEnemyFnTable
	movs r1, #0x33
	strb r1, [r4, #9]
	adds r0, #0xcc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
_0808A89E:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808A8A8: .4byte gZakoHeaderPtr
_0808A8AC: .4byte gEnemyFnTable

	thumb_func_start FUN_0808a8b0
FUN_0808a8b0: @ 0x0808A8B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808A900 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808A8F6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808A904 @ =gEnemyFnTable
	movs r1, #0x33
	strb r1, [r3, #9]
	adds r0, #0xcc
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
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_0808A8F6:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808A900: .4byte gZakoHeaderPtr
_0808A904: .4byte gEnemyFnTable

	thumb_func_start initCarrybeeG
initCarrybeeG: @ 0x0808A908
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r0, _0808A974 @ =nop_0808b534
	adds r4, r6, #0
	adds r4, #0x74
	str r0, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808a8b0
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA00
	adds r1, r6, #0
	adds r1, #0xc3
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0808A978 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808A984
	ldr r0, _0808A97C @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808A984
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808A980 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x40
	b _0808A99C
	.align 2, 0
_0808A974: .4byte nop_0808b534
_0808A978: .4byte gSystemSavedataManager
_0808A97C: .4byte gCurStory
_0808A980: .4byte 0x08368C6C
_0808A984:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808A9F8 @ =0x08368C6C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x30
_0808A99C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xbc
	movs r2, #0
	str r2, [r0]
	str r2, [r6, #0x2c]
	str r2, [r6, #0x28]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r1, _0808A9FC @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x14
	strb r0, [r1]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AA5C
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0808AA5C
	.align 2, 0
_0808A9F8: .4byte 0x08368C6C
_0808A9FC: .4byte gEnemyFnTable
_0808AA00:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0808AA88 @ =0x08368C54
	bl SetDDP
	ldr r1, _0808AA8C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AA5C
	ldrb r0, [r6, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r1, [r6, #0x28]
	ldrb r0, [r1, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r1, _0808AA90 @ =0x00006E06
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0808AA5C:
	movs r0, #0
	strb r0, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808AA72
	ldr r1, _0808AA94 @ =gOverworld
	ldr r0, _0808AA98 @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0808AA72:
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x58]
	str r0, [r1]
	adds r0, r6, #0
	bl carrybeeGAI
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AA88: .4byte 0x08368C54
_0808AA8C: .4byte gEnemyFnTable
_0808AA90: .4byte 0x00006E06
_0808AA94: .4byte gOverworld
_0808AA98: .4byte 0x0002D02C

	thumb_func_start carrybeeGAI
carrybeeGAI: @ 0x0808AA9C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808AAD4
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0808AAD4
	ldr r1, _0808AAD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl killCarrybeeG
	b _0808AC28
	.align 2, 0
_0808AAD0: .4byte gEnemyFnTable
_0808AAD4:
	ldr r1, _0808AB30 @ =0x08368C2C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0808AB82
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808AB82
	ldr r1, [r4, #0x28]
	ldrb r0, [r1, #0xc]
	cmp r0, #2
	bls _0808AB38
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808AB34 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0x11]
	b _0808AC28
	.align 2, 0
_0808AB30: .4byte 0x08368C2C
_0808AB34: .4byte gEnemyFnTable
_0808AB38:
	cmp r0, #1
	bls _0808AB82
	ldr r0, [r1, #0x54]
	ldr r1, [r1, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808AB5C
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0808AB62
_0808AB5C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808AB62:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808AB82:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _0808AC28
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _0808AC18
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	cmp r0, #0
	beq _0808ABC0
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABA4
	str r1, [r2]
_0808ABA4:
	adds r1, r4, #0
	adds r1, #0xc0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ABB8
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808ABC0
_0808ABB8:
	ldr r0, [r2]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808ABC0:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0808ABEC
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABD0
	movs r0, #0
	str r0, [r4, #0x2c]
_0808ABD0:
	adds r1, r4, #0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ABE4
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808ABEC
_0808ABE4:
	ldr r0, [r4, #0x2c]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808ABEC:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0808AC18
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808ABFC
	movs r0, #0
	str r0, [r4, #0x28]
_0808ABFC:
	adds r1, r4, #0
	adds r1, #0xc2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808AC10
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AC18
_0808AC10:
	ldr r0, [r4, #0x28]
	adds r0, #0x25
	movs r1, #0x18
	strb r1, [r0]
_0808AC18:
	ldr r0, _0808AC30 @ =0x08368C40
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0808AC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808AC30: .4byte 0x08368C40

	thumb_func_start killCarrybeeG
killCarrybeeG: @ 0x0808AC34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r2, [r7, #0x10]
	cmp r2, #0
	beq _0808AC4A
	b _0808AEC8
_0808AC4A:
	ldr r0, _0808AC8C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808AC94
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
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
	ldr r1, _0808AC90 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808AF2C
	.align 2, 0
_0808AC8C: .4byte gCurStory
_0808AC90: .4byte gEnemyFnTable
_0808AC94:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xc
	bls _0808AC9C
	b _0808AF2E
_0808AC9C:
	lsls r0, r0, #2
	ldr r1, _0808ACA8 @ =_0808ACAC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808ACA8: .4byte _0808ACAC
_0808ACAC: @ jump table
	.4byte _0808ACE0 @ case 0
	.4byte _0808AD0C @ case 1
	.4byte _0808AF2E @ case 2
	.4byte _0808AF2E @ case 3
	.4byte _0808AF2E @ case 4
	.4byte _0808AF2E @ case 5
	.4byte _0808AF2E @ case 6
	.4byte _0808AF2E @ case 7
	.4byte _0808AF2E @ case 8
	.4byte _0808AF2E @ case 9
	.4byte _0808AD0C @ case 10
	.4byte _0808AD40 @ case 11
	.4byte _0808AE80 @ case 12
_0808ACE0:
	ldr r1, _0808AD34 @ =0x00006E09
	adds r0, r7, #0
	bl SetMotion
	movs r2, #0
	movs r0, #0xa
	strb r0, [r7, #0xe]
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
	adds r0, r7, #0
	adds r0, #0x5c
	str r2, [r0, #4]
	str r2, [r7, #0x5c]
_0808AD0C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r2, #0
	movs r0, #0x78
	strb r0, [r7, #0x12]
	str r2, [r7, #0x60]
	movs r0, #0x80
	str r0, [r7, #0x5c]
	ldr r1, _0808AD38 @ =gOverworld
	ldr r0, _0808AD3C @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc3
	strb r2, [r0]
	b _0808AE78
	.align 2, 0
_0808AD34: .4byte 0x00006E09
_0808AD38: .4byte gOverworld
_0808AD3C: .4byte 0x0002D02C
_0808AD40:
	ldr r0, [r7, #0x60]
	adds r0, #0x10
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #1
	cmp r0, r1
	ble _0808AD50
	str r1, [r7, #0x60]
_0808AD50:
	ldr r1, [r7, #0x58]
	ldr r0, [r7, #0x60]
	adds r5, r1, r0
	str r5, [r7, #0x58]
	ldr r1, [r7, #0x54]
	ldr r0, [r7, #0x5c]
	adds r4, r1, r0
	str r4, [r7, #0x54]
	ldrb r0, [r7, #0x12]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AE2C
	str r4, [sp]
	str r5, [sp, #4]
	ldr r1, _0808AE44 @ =0xFFFFD800
	adds r4, r4, r1
	ldr r2, _0808AE48 @ =RNG_0202f388
	mov sl, r2
	ldr r0, [r2]
	ldr r1, _0808AE4C @ =0x000343FD
	mov sb, r1
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _0808AE50 @ =0x00269EC3
	mov r8, r1
	add r0, r8
	lsls r0, r0, #1
	lsrs r6, r0, #1
	mov r2, sl
	str r6, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xa0
	lsls r1, r1, #7
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp]
	ldr r0, _0808AE54 @ =0xFFFFE800
	adds r4, r5, r0
	mov r0, sb
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, sl
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #6
	bl __umodsi3
	adds r4, r4, r0
	str r4, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	mov r1, sl
	ldr r0, [r1]
	mov r4, sb
	muls r4, r0, r4
	add r4, r8
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r1]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [sp]
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r2, #1
	mov sb, r2
	ands r1, r2
	ldr r0, _0808AE58 @ =0x00006E07
	mov r8, r0
	adds r0, r6, #0
	mov r2, r8
	adds r3, r4, #0
	bl CreateVFX63
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	mov r2, sb
	ands r1, r2
	ldr r2, _0808AE5C @ =0x00006E08
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX63
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	mov r0, sb
	ands r1, r0
	adds r0, r6, #0
	mov r2, r8
	adds r3, r4, #0
	bl CreateVFX63
_0808AE2C:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r1, [r7, #0x12]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808AE60
	ldrb r1, [r7, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0808AE66
	.align 2, 0
_0808AE44: .4byte 0xFFFFD800
_0808AE48: .4byte RNG_0202f388
_0808AE4C: .4byte 0x000343FD
_0808AE50: .4byte 0x00269EC3
_0808AE54: .4byte 0xFFFFE800
_0808AE58: .4byte 0x00006E07
_0808AE5C: .4byte 0x00006E08
_0808AE60:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808AE66:
	strb r0, [r7, #0xa]
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0808AE78
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808AF2E
_0808AE78:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808AF2E
_0808AE80:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r7, #0x11]
	cmp r0, #0
	bne _0808AF14
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #0
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808AEC0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808AEC4 @ =0x0000270E
	cmp r1, r0
	bhi _0808AEB6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808AEB6:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	b _0808AF14
	.align 2, 0
_0808AEC0: .4byte gMission
_0808AEC4: .4byte 0x0000270E
_0808AEC8:
	ldr r0, _0808AF0C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808AF14
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
	ldr r1, _0808AF10 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808AF2C
	.align 2, 0
_0808AF0C: .4byte gCurStory
_0808AF10: .4byte gEnemyFnTable
_0808AF14:
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808AF40 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0808AF2C:
	str r0, [r7, #0x14]
_0808AF2E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AF40: .4byte gEnemyFnTable

	thumb_func_start FUN_0808af44
FUN_0808af44: @ 0x0808AF44
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	bne _0808AF64
	adds r0, r2, #0
	adds r0, #0xc3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0808AF64
	ldr r1, _0808AF70 @ =gOverworld
	ldr r0, _0808AF74 @ =0x0002D02C
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0808AF64:
	adds r0, r2, #0
	bl DeleteEnemy
	pop {r0}
	bx r0
	.align 2, 0
_0808AF70: .4byte gOverworld
_0808AF74: .4byte 0x0002D02C

	thumb_func_start FUN_0808af78
FUN_0808af78: @ 0x0808AF78
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808af7c
FUN_0808af7c: @ 0x0808AF7C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808AF9C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808AFA0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808AFA4
	cmp r5, #1
	beq _0808AFD4
	b _0808AFF8
	.align 2, 0
_0808AF9C: .4byte gStageRun+232
_0808AFA0: .4byte 0xFFFFC000
_0808AFA4:
	adds r0, r4, #0
	adds r0, #0xb8
	str r5, [r0]
	ldr r0, _0808B000 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x8c
	lsls r0, r0, #7
	str r0, [r4, #0x5c]
	movs r1, #0xdc
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B004 @ =0x08368C6C
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808AFD4:
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r1, r0
	ble _0808AFF2
	str r1, [r4, #0x68]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808AFF2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808AFF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B000: .4byte pZero2
_0808B004: .4byte 0x08368C6C

	thumb_func_start FUN_0808b008
FUN_0808b008: @ 0x0808B008
	movs r0, #1
	bx lr

	thumb_func_start carrybeeg_0808b00c
carrybeeg_0808b00c: @ 0x0808B00C
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xb4
	ldr r0, _0808B02C @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B030 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _0808B034
	cmp r0, #1
	beq _0808B03E
	b _0808B100
	.align 2, 0
_0808B02C: .4byte gStageRun+232
_0808B030: .4byte 0xFFFFC000
_0808B034:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0808B03E:
	ldrb r0, [r3, #0x12]
	adds r4, r0, #1
	strb r4, [r3, #0x12]
	adds r0, r3, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r3, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r3, #0x68]
	ldr r2, _0808B0D0 @ =gSineTable
	ldrb r0, [r3, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r2, [r0, r5]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r3, #0x58]
	ldrb r0, [r3, #0x13]
	cmp r0, #0
	beq _0808B07A
	subs r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B0EA
_0808B07A:
	adds r0, r3, #0
	adds r0, #0xbc
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _0808B090
	ldr r0, [r3, #0x28]
	cmp r0, #0
	bne _0808B0E4
_0808B090:
	ldr r0, _0808B0D4 @ =gZakoHeaderPtr
	ldr r1, [r0]
	movs r2, #8
	ldrsh r0, [r1, r2]
	movs r5, #0xa
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #5
	bgt _0808B0E4
	ldr r2, _0808B0D8 @ =gCurStory
	ldrb r1, [r2, #8]
	movs r0, #0x42
	ands r0, r1
	cmp r0, #0
	bne _0808B0E4
	ldrb r1, [r2, #4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808B0C6
	ldr r0, _0808B0DC @ =gSystemSavedataManager
	ldr r1, [r0, #0x40]
	ldr r0, _0808B0E0 @ =0x000032DA
	cmp r1, r0
	beq _0808B0C6
	cmp r1, #0
	bne _0808B0E4
_0808B0C6:
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	b _0808B0FA
	.align 2, 0
_0808B0D0: .4byte gSineTable
_0808B0D4: .4byte gZakoHeaderPtr
_0808B0D8: .4byte gCurStory
_0808B0DC: .4byte gSystemSavedataManager
_0808B0E0: .4byte 0x000032DA
_0808B0E4:
	movs r0, #0x40
	strb r0, [r3, #0x13]
	b _0808B0FA
_0808B0EA:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0808B0FA
	movs r0, #3
	strb r0, [r3, #0xd]
	movs r0, #0
	strb r0, [r3, #0xe]
_0808B0FA:
	adds r0, r3, #0
	bl UpdateMotionGraphic
_0808B100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B108:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808b10c
FUN_0808b10c: @ 0x0808B10C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B134 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B138 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B128
	b _0808B2A8
_0808B128:
	lsls r0, r0, #2
	ldr r1, _0808B13C @ =_0808B140
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B134: .4byte gStageRun+232
_0808B138: .4byte 0xFFFFC000
_0808B13C: .4byte _0808B140
_0808B140: @ jump table
	.4byte _0808B15C @ case 0
	.4byte _0808B16A @ case 1
	.4byte _0808B1B4 @ case 2
	.4byte _0808B24C @ case 3
	.4byte _0808B1BA @ case 4
	.4byte _0808B24C @ case 5
	.4byte _0808B2A0 @ case 6
_0808B15C:
	ldr r1, _0808B1AC @ =0x00006E01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B16A:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B1B0 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808B1A8
	b _0808B2A8
_0808B1A8:
	b _0808B28E
	.align 2, 0
_0808B1AC: .4byte 0x00006E01
_0808B1B0: .4byte gSineTable
_0808B1B4:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B246
_0808B1BA:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0808B1FC @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xd8
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	cmp r0, #0
	bne _0808B200
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r5]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	b _0808B23A
	.align 2, 0
_0808B1FC: .4byte 0xFFFFF600
_0808B200:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	bne _0808B21E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x2c]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc1
	b _0808B23A
_0808B21E:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _0808B23E
	mov r0, sp
	movs r1, #2
	movs r2, #0
	bl CreatePantheonHunter
	str r0, [r4, #0x28]
	adds r0, #0x25
	movs r1, #0x15
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc2
_0808B23A:
	movs r0, #0x20
	strb r0, [r1]
_0808B23E:
	ldr r1, _0808B298 @ =0x00006E03
	adds r0, r4, #0
	bl SetMotion
_0808B246:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B24C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B29C @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0808B28E
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B2A8
_0808B28E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B2A8
	.align 2, 0
_0808B298: .4byte 0x00006E03
_0808B29C: .4byte gSineTable
_0808B2A0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B2A8:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
_0808B2B0:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808b2b4
FUN_0808b2b4: @ 0x0808B2B4
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, _0808B2DC @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _0808B2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0808B2D0
	b _0808B40A
_0808B2D0:
	lsls r0, r0, #2
	ldr r1, _0808B2E4 @ =_0808B2E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808B2DC: .4byte gStageRun+232
_0808B2E0: .4byte 0xFFFFC000
_0808B2E4: .4byte _0808B2E8
_0808B2E8: @ jump table
	.4byte _0808B304 @ case 0
	.4byte _0808B312 @ case 1
	.4byte _0808B354 @ case 2
	.4byte _0808B390 @ case 3
	.4byte _0808B35A @ case 4
	.4byte _0808B390 @ case 5
	.4byte _0808B3DC @ case 6
_0808B304:
	ldr r1, _0808B34C @ =0x00006E04
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B312:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B350 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808B40A
	b _0808B3CC
	.align 2, 0
_0808B34C: .4byte 0x00006E04
_0808B350: .4byte gSineTable
_0808B354:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	b _0808B38A
_0808B35A:
	movs r0, #0xa
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r1, #0xac
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r1, #0
	bl FUN_080adad0
	ldr r1, _0808B3D4 @ =0x00006E05
	adds r0, r4, #0
	bl SetMotion
_0808B38A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B390:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B3D8 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0808B3CC
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B40A
_0808B3CC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B40A
	.align 2, 0
_0808B3D4: .4byte 0x00006E05
_0808B3D8: .4byte gSineTable
_0808B3DC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	subs r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x68]
	ldr r2, _0808B414 @ =gSineTable
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	str r1, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808B40A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B414: .4byte gSineTable
_0808B418:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808b41c
FUN_0808b41c: @ 0x0808B41C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r2, #0xc]
	cmp r0, #2
	bls _0808B442
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	b _0808B46A
_0808B442:
	ldr r0, _0808B48C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808B494
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
_0808B46A:
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808B490 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	bl killCarrybeeG
	b _0808B52E
	.align 2, 0
_0808B48C: .4byte gCurStory
_0808B490: .4byte gEnemyFnTable
_0808B494:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0808B4D0
	cmp r5, #1
	bgt _0808B4A4
	cmp r5, #0
	beq _0808B4AA
	b _0808B52E
_0808B4A4:
	cmp r5, #2
	beq _0808B4F8
	b _0808B52E
_0808B4AA:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r1, _0808B4F0 @ =0x00006E06
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808B4F4 @ =0x08368C54
	bl SetDDP
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B4D0:
	ldr r0, [r4, #0x28]
	ldr r1, [r0, #0x58]
	ldr r0, [r0, #0x54]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808B52E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808B52E
	.align 2, 0
_0808B4F0: .4byte 0x00006E06
_0808B4F4: .4byte 0x08368C54
_0808B4F8:
	ldr r0, [r2, #0x54]
	ldr r1, [r2, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B518
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0808B51E
_0808B518:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808B51E:
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808B52E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0808b534
nop_0808b534: @ 0x0808B534
	bx lr
	.align 2, 0

	thumb_func_start CreateOzChargeSaberRock
CreateOzChargeSaberRock: @ 0x0808B538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	adds r7, r5, #0
	ldr r0, _0808B5C4 @ =0xFFFFD000
	adds r5, r5, r0
	ldr r2, _0808B5C8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808B5CC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808B5D0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xc0
	lsls r1, r1, #7
	bl __umodsi3
	adds r5, r5, r0
	ldr r0, _0808B5D4 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0808B5D8 @ =0xFFFF9000
	adds r6, r0, r1
	ldr r0, _0808B5DC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0808B5BA
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808B5E0 @ =gEnemyFnTable
	movs r1, #0x34
	strb r1, [r4, #9]
	adds r0, #0xd0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	str r5, [r4, #0x54]
	str r6, [r4, #0x58]
	str r7, [r4, #0x64]
	mov r0, r8
	strb r0, [r4, #0x13]
_0808B5BA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B5C4: .4byte 0xFFFFD000
_0808B5C8: .4byte RNG_0202f388
_0808B5CC: .4byte 0x000343FD
_0808B5D0: .4byte 0x00269EC3
_0808B5D4: .4byte gStageRun+232
_0808B5D8: .4byte 0xFFFF9000
_0808B5DC: .4byte gZakoHeaderPtr
_0808B5E0: .4byte gEnemyFnTable

	thumb_func_start nop_0808b5e4
nop_0808b5e4: @ 0x0808B5E4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808b5e8
FUN_0808b5e8: @ 0x0808B5E8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808B5FE
	movs r0, #0
	b _0808B618
_0808B5FE:
	ldr r1, _0808B61C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl FUN_0808b6cc
	movs r0, #1
_0808B618:
	pop {r1}
	bx r1
	.align 2, 0
_0808B61C: .4byte gEnemyFnTable

	thumb_func_start FUN_0808b620
FUN_0808b620: @ 0x0808B620
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808B680 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0808B684 @ =0x08368D78
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _0808B688 @ =0x08368D48
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #5
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0808B68C @ =nop_0808b5e4
	str r0, [r5, #0x24]
	adds r0, r4, #0
	bl FUN_0808b690
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B680: .4byte gEnemyFnTable
_0808B684: .4byte 0x08368D78
_0808B688: .4byte 0x08368D48
_0808B68C: .4byte nop_0808b5e4

	thumb_func_start FUN_0808b690
FUN_0808b690: @ 0x0808B690
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b5e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B6BE
	ldr r1, _0808B6C4 @ =0x08368D40
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808B6C8 @ =0x08368D44
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808B6BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6C4: .4byte 0x08368D40
_0808B6C8: .4byte 0x08368D44

	thumb_func_start FUN_0808b6cc
FUN_0808b6cc: @ 0x0808B6CC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x41
	bl PlaySound
	adds r1, r4, #0
	adds r1, #0x54
	ldr r2, _0808B6FC @ =0x08368D7A
	adds r0, r4, #0
	movs r3, #3
	bl FUN_080b7ffc
	ldr r1, _0808B700 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6FC: .4byte 0x08368D7A
_0808B700: .4byte gEnemyFnTable

	thumb_func_start nop_0808b704
nop_0808b704: @ 0x0808B704
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808b708
FUN_0808b708: @ 0x0808B708
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808B718
	cmp r0, #1
	beq _0808B72E
	b _0808B78E
_0808B718:
	str r0, [r4, #0x60]
	movs r0, #0x10
	strb r0, [r4, #0x12]
	movs r1, #0xed
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808B72E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808B73E
	str r1, [r4, #0x60]
_0808B73E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0808B76A
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808B788
	ldrb r1, [r4, #0x13]
	cmp r1, #1
	bhi _0808B788
	ldr r0, [r4, #0x64]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateOzChargeSaberRock
	b _0808B788
_0808B76A:
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808B788
	ldr r1, _0808B794 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0808B788:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808B78E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B794: .4byte gEnemyFnTable

	thumb_func_start FUN_0808b798
FUN_0808b798: @ 0x0808B798
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0808B7F4 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808B7EA
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808B7F8 @ =gEnemyFnTable
	movs r1, #0x35
	strb r1, [r3, #9]
	adds r0, #0xd4
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
	str r6, [r3, #0x28]
_0808B7EA:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0808B7F4: .4byte gZakoHeaderPtr
_0808B7F8: .4byte gEnemyFnTable

	thumb_func_start FUN_0808b7fc
FUN_0808b7fc: @ 0x0808B7FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	movs r5, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r2, #1
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r7, #0xa]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _0808B8A4 @ =0x08368DC4
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	ldr r0, _0808B8A8 @ =nop_0808c384
	str r0, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	ldr r1, _0808B8AC @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _0808B8B0 @ =0xFFFFED00
	str r0, [r1]
	adds r1, #4
	ldr r0, _0808B8B4 @ =0xFFFFC600
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc0
	strb r5, [r0]
	ldrb r1, [r7, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	bl FUN_0808b8b8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B8A4: .4byte 0x08368DC4
_0808B8A8: .4byte nop_0808c384
_0808B8AC: .4byte gEnemyFnTable
_0808B8B0: .4byte 0xFFFFED00
_0808B8B4: .4byte 0xFFFFC600

	thumb_func_start FUN_0808b8b8
FUN_0808b8b8: @ 0x0808B8B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808B8F0
	adds r2, r4, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0808B8EC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_0808b920
	b _0808B910
	.align 2, 0
_0808B8EC: .4byte gEnemyFnTable
_0808B8F0:
	ldr r1, _0808B918 @ =0x08368D94
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808B91C @ =0x08368DA8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808B910:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B918: .4byte 0x08368D94
_0808B91C: .4byte 0x08368DA8

	thumb_func_start FUN_0808b920
FUN_0808b920: @ 0x0808B920
	push {lr}
	ldr r2, _0808B934 @ =0x08368DBC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808B934: .4byte 0x08368DBC

	thumb_func_start FUN_0808b938
FUN_0808b938: @ 0x0808B938
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	ldrb r2, [r5, #0xe]
	cmp r2, #1
	bne _0808B94E
	b _0808BB14
_0808B94E:
	cmp r2, #1
	bgt _0808B958
	cmp r2, #0
	beq _0808B966
	b _0808BB46
_0808B958:
	cmp r2, #2
	bne _0808B95E
	b _0808BB26
_0808B95E:
	cmp r2, #3
	bne _0808B964
	b _0808BB3E
_0808B964:
	b _0808BB46
_0808B966:
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	str r2, [r5, #0x5c]
	str r2, [r5, #0x60]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	adds r2, r5, #0
	adds r2, #0x70
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _0808BA24 @ =0xFFFF9AFA
	adds r0, r0, r1
	str r2, [sp, #0x14]
	cmp r0, #1
	bhi _0808BA3C
	ldr r2, _0808BA28 @ =RNG_0202f388
	mov sl, r2
	mov r0, sp
	str r0, [sp, #0x10]
	movs r1, #0
	mov sb, r1
	ldr r7, _0808BA2C @ =0x08368E54
	movs r2, #3
	mov r8, r2
	ldr r6, _0808BA30 @ =0x08368E74
_0808B9AE:
	mov r0, sl
	ldr r1, [r0]
	ldr r0, _0808BA34 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808BA38 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	mov r2, sl
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	ldr r1, [r7]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, [r7, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, [sp, #0x10]
	str r0, [r2, #4]
	ldrh r3, [r6]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	ldr r0, _0808BA30 @ =0x08368E74
	adds r0, #2
	add r0, sb
	ldrh r3, [r0]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	ldrh r3, [r6, #4]
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl FUN_080c1cf4
	adds r6, #6
	movs r0, #6
	add sb, r0
	adds r7, #8
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _0808B9AE
	b _0808BAC0
	.align 2, 0
_0808BA24: .4byte 0xFFFF9AFA
_0808BA28: .4byte RNG_0202f388
_0808BA2C: .4byte 0x08368E54
_0808BA30: .4byte 0x08368E74
_0808BA34: .4byte 0x000343FD
_0808BA38: .4byte 0x00269EC3
_0808BA3C:
	add r6, sp, #8
	movs r0, #0
	mov sl, r0
	ldr r1, _0808BAE0 @ =0x08368E8C
	mov r8, r1
	movs r2, #3
	mov sb, r2
	ldr r7, _0808BAE4 @ =0x08368EAC
_0808BA4C:
	ldr r0, _0808BAE8 @ =RNG_0202f388
	ldr r1, [r0]
	ldr r0, _0808BAEC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808BAF0 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	ldr r2, _0808BAE8 @ =RNG_0202f388
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	mov r2, r8
	ldr r1, [r2]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r6, #4]
	ldrh r3, [r7]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	ldr r0, _0808BAE4 @ =0x08368EAC
	adds r0, #2
	add r0, sl
	ldrh r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	ldrh r3, [r7, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080c1cf4
	adds r7, #6
	movs r2, #6
	add sl, r2
	movs r0, #8
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	cmp r2, #0
	bge _0808BA4C
_0808BAC0:
	ldrb r0, [r5, #0x1e]
	lsls r0, r0, #8
	ldr r2, [sp, #0x14]
	ldrb r1, [r2]
	orrs r0, r1
	ldr r1, _0808BAF4 @ =0x00006501
	cmp r0, r1
	bne _0808BAF8
	ldrb r0, [r5, #0xa]
	movs r1, #0xfe
	ands r1, r0
	strb r1, [r5, #0xa]
	movs r0, #2
	strb r0, [r5, #0xe]
	b _0808BB46
	.align 2, 0
_0808BAE0: .4byte 0x08368E8C
_0808BAE4: .4byte 0x08368EAC
_0808BAE8: .4byte RNG_0202f388
_0808BAEC: .4byte 0x000343FD
_0808BAF0: .4byte 0x00269EC3
_0808BAF4: .4byte 0x00006501
_0808BAF8:
	ldr r1, _0808BB10 @ =0x00006505
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	b _0808BB36
	.align 2, 0
_0808BB10: .4byte 0x00006505
_0808BB14:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808BB46
	b _0808BB36
_0808BB26:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808BB46
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808BB46
_0808BB36:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808BB46
_0808BB3E:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808BB46:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BB58:
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x90, 0x7B, 0x00, 0x28
	.byte 0x0C, 0xD1, 0x91, 0x7A, 0xFE, 0x20, 0x08, 0x40, 0x90, 0x72, 0x05, 0x49, 0x50, 0x7A, 0x80, 0x00
	.byte 0x40, 0x18, 0x04, 0x21, 0xD1, 0x60, 0x00, 0x68, 0x00, 0x69, 0x50, 0x61, 0x01, 0xBC, 0x00, 0x47
	.byte 0x48, 0x59, 0x36, 0x08, 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808bb88
FUN_0808bb88: @ 0x0808BB88
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808BB98
	cmp r0, #1
	beq _0808BBBE
	b _0808BBDA
_0808BB98:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xca
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808BBE0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r4, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808BBBE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808BBDA
	movs r0, #0
	strb r2, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808BBDA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808BBE0: .4byte 0xFFFFC000
_0808BBE4:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808bbe8
FUN_0808bbe8: @ 0x0808BBE8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808BC34
	cmp r0, #1
	bgt _0808BC04
	cmp r0, #0
	beq _0808BC0A
	b _0808BCD0
_0808BC04:
	cmp r0, #2
	beq _0808BC58
	b _0808BCD0
_0808BC0A:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xca
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	ldr r1, [r5, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808BC54 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r5, #0x54]
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808BC34:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0808BC4A
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808BCD0
_0808BC4A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808BCD0
	.align 2, 0
_0808BC54: .4byte 0xFFFFC000
_0808BC58:
	ldr r1, _0808BCE0 @ =0x00006501
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x41
	bl PlaySound
	ldr r0, _0808BCE4 @ =RNG_0202f388
	mov r8, r0
	mov sb, sp
	ldr r6, _0808BCE8 @ =0x08368EC4
	movs r7, #5
_0808BC70:
	mov r2, r8
	ldr r1, [r2]
	ldr r0, _0808BCEC @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0808BCF0 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	ldr r1, [r6]
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, [r6, #4]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r0, r1
	mov r2, sb
	str r0, [r2, #4]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCF4 @ =0x0000650E
	bl FUN_080c1c94
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCF8 @ =0x0000650F
	bl FUN_080c1c94
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0808BCFC @ =0x00006510
	bl FUN_080c1c94
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _0808BC70
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808BCD0:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BCE0: .4byte 0x00006501
_0808BCE4: .4byte RNG_0202f388
_0808BCE8: .4byte 0x08368EC4
_0808BCEC: .4byte 0x000343FD
_0808BCF0: .4byte 0x00269EC3
_0808BCF4: .4byte 0x0000650E
_0808BCF8: .4byte 0x0000650F
_0808BCFC: .4byte 0x00006510

	thumb_func_start FUN_0808bd00
FUN_0808bd00: @ 0x0808BD00
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #6
	bne _0808BD14
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808BD14:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_0808BD1C:
	.byte 0x30, 0xB5, 0x04, 0x1C
	.byte 0xA5, 0x7B, 0x00, 0x2D, 0x02, 0xD0, 0x01, 0x2D, 0x1F, 0xD0, 0x28, 0xE0, 0xE1, 0x7A, 0x10, 0x20
	.byte 0x08, 0x43, 0xE0, 0x72, 0xA0, 0x6A, 0x00, 0x7F, 0x60, 0x77, 0x12, 0x49, 0x20, 0x1C, 0x8B, 0xF7
	.byte 0x13, 0xFC, 0xA1, 0x7A, 0xEF, 0x20, 0x08, 0x40, 0xA0, 0x72, 0x20, 0x1C, 0x4C, 0x30, 0x05, 0x70
	.byte 0x22, 0x1C, 0x4A, 0x32, 0x11, 0x78, 0x11, 0x20, 0x40, 0x42, 0x08, 0x40, 0x10, 0x70, 0x25, 0x66
	.byte 0xE5, 0x65, 0xA5, 0x74, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x6A, 0x81, 0x6D, 0x06, 0x4A
	.byte 0x89, 0x18, 0xA1, 0x65, 0x40, 0x6D, 0x60, 0x65, 0x20, 0x1C, 0x8B, 0xF7, 0x6F, 0xFC, 0x30, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x01, 0x65, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF

	thumb_func_start FUN_0808bd8c
FUN_0808bd8c: @ 0x0808BD8C
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808bd90
FUN_0808bd90: @ 0x0808BD90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0x1e
	bls _0808BDA2
	b _0808C31C
_0808BDA2:
	lsls r0, r0, #2
	ldr r1, _0808BDAC @ =_0808BDB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808BDAC: .4byte _0808BDB0
_0808BDB0: @ jump table
	.4byte _0808BE2C @ case 0
	.4byte _0808C2C2 @ case 1
	.4byte _0808BE44 @ case 2
	.4byte _0808BE56 @ case 3
	.4byte _0808BE70 @ case 4
	.4byte _0808BE82 @ case 5
	.4byte _0808BEA8 @ case 6
	.4byte _0808BEB2 @ case 7
	.4byte _0808BEC8 @ case 8
	.4byte _0808BEE0 @ case 9
	.4byte _0808BF12 @ case 10
	.4byte _0808BF48 @ case 11
	.4byte _0808BF64 @ case 12
	.4byte _0808BF9C @ case 13
	.4byte _0808BFAC @ case 14
	.4byte _0808BFF2 @ case 15
	.4byte _0808C010 @ case 16
	.4byte _0808C06C @ case 17
	.4byte _0808C194 @ case 18
	.4byte _0808C1B6 @ case 19
	.4byte _0808C1D0 @ case 20
	.4byte _0808C1EC @ case 21
	.4byte _0808C218 @ case 22
	.4byte _0808C24E @ case 23
	.4byte _0808C298 @ case 24
	.4byte _0808C2B4 @ case 25
	.4byte _0808C2E4 @ case 26
	.4byte _0808C31C @ case 27
	.4byte _0808C31C @ case 28
	.4byte _0808C31C @ case 29
	.4byte _0808C2F4 @ case 30
_0808BE2C:
	ldr r1, _0808BE40 @ =0x00006502
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808C2C2
	.align 2, 0
_0808BE40: .4byte 0x00006502
_0808BE44:
	ldr r1, _0808BE6C @ =0x00006503
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BE56:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BE6A
	b _0808C31C
_0808BE6A:
	b _0808C2D2
	.align 2, 0
_0808BE6C: .4byte 0x00006503
_0808BE70:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BE82:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BEA6
	b _0808C31C
_0808BEA6:
	b _0808C2D2
_0808BEA8:
	movs r0, #0xa
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BEB2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BEC6
	b _0808C31C
_0808BEC6:
	b _0808C2D2
_0808BEC8:
	movs r0, #0x80
	rsbs r0, r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	adds r0, #0x60
	str r0, [r7, #0x64]
	str r0, [r7, #0x68]
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BEE0:
	ldr r2, [r7, #0x5c]
	ldr r0, [r7, #0x64]
	adds r2, r2, r0
	str r2, [r7, #0x5c]
	ldr r1, [r7, #0x60]
	ldr r0, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldr r0, [r7, #0x54]
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BF10
	b _0808C31C
_0808BF10:
	b _0808C2D2
_0808BF12:
	ldr r1, _0808BF88 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808BF8C @ =0x08368DDC
	bl SetDDP
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0808BF90 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0808BF94 @ =0xFFFF2000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #3
	strb r0, [r7, #0x13]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BF48:
	ldr r1, _0808BF88 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r2, _0808BF98 @ =0xFFFF7000
	adds r0, r0, r2
	str r0, [r7, #0x68]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BF64:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BF86
	b _0808C31C
_0808BF86:
	b _0808C2D2
	.align 2, 0
_0808BF88: .4byte 0x00006506
_0808BF8C: .4byte 0x08368DDC
_0808BF90: .4byte pZero2
_0808BF94: .4byte 0xFFFF2000
_0808BF98: .4byte 0xFFFF7000
_0808BF9C:
	movs r0, #0
	str r0, [r7, #0x5c]
	str r0, [r7, #0x60]
	movs r0, #0x40
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808BFAC:
	ldr r0, _0808BFBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r7, #0x54]
	cmp r2, r0
	ble _0808BFC4
	ldr r0, _0808BFC0 @ =0xFFFFFE00
	b _0808BFC8
	.align 2, 0
_0808BFBC: .4byte pZero2
_0808BFC0: .4byte 0xFFFFFE00
_0808BFC4:
	movs r0, #0x80
	lsls r0, r0, #2
_0808BFC8:
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x5c]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	adds r1, r2, r1
	str r1, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BFF0
	b _0808C31C
_0808BFF0:
	b _0808C2D2
_0808BFF2:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0808C04C @ =0x0000012F
	bl PlaySound
	movs r0, #0xc0
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C010:
	ldr r0, [r7, #0x60]
	adds r0, #0x80
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808C020
	str r1, [r7, #0x60]
_0808C020:
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r1, r0, r1
	str r1, [r7, #0x58]
	ldrb r0, [r7, #0x13]
	cmp r0, #1
	bne _0808C050
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C042
	b _0808C31C
_0808C042:
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _0808C2D2
	.align 2, 0
_0808C04C: .4byte 0x0000012F
_0808C050:
	ldr r0, [r7, #0x54]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C064
	b _0808C31C
_0808C064:
	ldr r0, [r7, #0x58]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	b _0808C2D2
_0808C06C:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r1, _0808C168 @ =0x00006507
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0x13]
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C17C
	movs r0, #8
	mov r1, sp
	bl AppendQuake
	movs r0, #0x41
	bl PlaySound
	ldr r4, _0808C16C @ =0x00000C01
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	mov r0, sp
	movs r1, #1
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	ldr r5, _0808C170 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r2, _0808C174 @ =0x000343FD
	mov r8, r2
	mov r1, r8
	muls r1, r0, r1
	ldr r6, _0808C178 @ =0x00269EC3
	adds r1, r1, r6
	lsls r1, r1, #1
	lsrs r0, r1, #1
	str r0, [r5]
	lsrs r1, r1, #0x11
	movs r0, #1
	ands r1, r0
	adds r1, #2
	mov r0, sp
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080ac9b4
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r5]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r4, #0xf
	ands r0, r4
	subs r0, #8
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r1, r1, r0
	str r1, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #0xa
	lsls r0, r0, #8
	ldr r1, [sp, #4]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	ldr r0, [r5]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #8
	lsls r0, r0, #8
	ldr r1, [sp]
	adds r1, r1, r0
	str r1, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	ands r0, r4
	subs r0, #0xa
	lsls r0, r0, #8
	ldr r1, [sp, #4]
	adds r1, r1, r0
	str r1, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	b _0808C184
	.align 2, 0
_0808C168: .4byte 0x00006507
_0808C16C: .4byte 0x00000C01
_0808C170: .4byte RNG_0202f388
_0808C174: .4byte 0x000343FD
_0808C178: .4byte 0x00269EC3
_0808C17C:
	movs r0, #4
	mov r1, sp
	bl AppendQuake
_0808C184:
	movs r0, #0x14
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C194:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808C1A6
	b _0808C31C
_0808C1A6:
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808C1B4
	b _0808C31C
_0808C1B4:
	b _0808C2D2
_0808C1B6:
	adds r2, r7, #0
	adds r2, #0x49
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	bne _0808C1CA
	b _0808C2D2
_0808C1CA:
	movs r0, #0xb
	strb r0, [r7, #0xe]
	b _0808C31C
_0808C1D0:
	ldr r1, _0808C210 @ =0x00006506
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x58]
	ldr r1, _0808C214 @ =0xFFFF6600
	adds r0, r0, r1
	str r0, [r7, #0x68]
	movs r0, #0x1e
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C1EC:
	ldr r0, [r7, #0x68]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808C20E
	b _0808C31C
_0808C20E:
	b _0808C2D2
	.align 2, 0
_0808C210: .4byte 0x00006506
_0808C214: .4byte 0xFFFF6600
_0808C218:
	ldr r1, _0808C288 @ =0x00006503
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808C28C @ =0x08368DC4
	bl SetDDP
	adds r1, r7, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0808C290 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x54]
	ldr r0, [r1, #0x58]
	ldr r1, _0808C294 @ =0xFFFF8000
	adds r0, r0, r1
	str r0, [r7, #0x58]
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C24E:
	ldr r3, [r7, #0x28]
	ldr r0, [r3, #0x54]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r1, [r7, #0x58]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r1, r0
	ldr r0, [r3, #0x58]
	subs r0, r0, r2
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C31C
	b _0808C2D2
	.align 2, 0
_0808C288: .4byte 0x00006503
_0808C28C: .4byte 0x08368DC4
_0808C290: .4byte 0xFFFFC000
_0808C294: .4byte 0xFFFF8000
_0808C298:
	ldr r1, _0808C2DC @ =0x00006504
	adds r0, r7, #0
	bl SetMotion
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808C2B4:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C2E0 @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
_0808C2C2:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808C31C
_0808C2D2:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808C31C
	.align 2, 0
_0808C2DC: .4byte 0x00006504
_0808C2E0: .4byte 0xFFFFC000
_0808C2E4:
	ldr r1, _0808C328 @ =0x00006501
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r7, #0x12]
	movs r0, #0x1e
	strb r0, [r7, #0xe]
_0808C2F4:
	ldr r1, [r7, #0x28]
	ldr r0, [r1, #0x58]
	ldr r2, _0808C32C @ =0xFFFFC000
	adds r0, r0, r2
	str r0, [r7, #0x58]
	ldr r0, [r1, #0x54]
	str r0, [r7, #0x54]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808C31C
	movs r0, #2
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
_0808C31C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C328: .4byte 0x00006501
_0808C32C: .4byte 0xFFFFC000
_0808C330:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0808c334
FUN_0808c334: @ 0x0808C334
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0xe]
	cmp r3, #0
	beq _0808C344
	cmp r3, #1
	beq _0808C364
	b _0808C380
_0808C344:
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
_0808C364:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	cmp r0, #0x40
	ble _0808C372
	movs r0, #0x40
	str r0, [r2, #0x60]
_0808C372:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r0, r2, #0
	bl UpdateMotionGraphic
_0808C380:
	pop {r0}
	bx r0

	thumb_func_start nop_0808c384
nop_0808c384: @ 0x0808C384
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808c388
FUN_0808c388: @ 0x0808C388
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0808C3E0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808C3D8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808C3E4 @ =gEnemyFnTable
	movs r1, #0x36
	strb r1, [r3, #9]
	adds r0, #0xd8
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
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_0808C3D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808C3E0: .4byte gZakoHeaderPtr
_0808C3E4: .4byte gEnemyFnTable

	thumb_func_start nop_0808c3e8
nop_0808c3e8: @ 0x0808C3E8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808c3ec
FUN_0808c3ec: @ 0x0808C3EC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808C448
	ldr r1, _0808C428 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #0
	beq _0808C43C
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0808C42C
	strb r4, [r2, #0xd]
	b _0808C43E
	.align 2, 0
_0808C428: .4byte gEnemyFnTable
_0808C42C:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0808C43A
	movs r0, #3
	b _0808C43C
_0808C43A:
	movs r0, #1
_0808C43C:
	strb r0, [r2, #0xd]
_0808C43E:
	adds r0, r2, #0
	bl killGeneratorCannon
	movs r0, #1
	b _0808C44A
_0808C448:
	movs r0, #0
_0808C44A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808c450
FUN_0808c450: @ 0x0808C450
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _0808C4DE
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _0808C4DE
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808C470
	cmp r0, #1
	beq _0808C4B4
	b _0808C4DE
_0808C470:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808C4DE
	ldr r1, _0808C4AC @ =0x08368F08
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808C4B0 @ =0x08368F28
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808C4A6:
	movs r0, #1
	b _0808C4E0
	.align 2, 0
_0808C4AC: .4byte 0x08368F08
_0808C4B0: .4byte 0x08368F28
_0808C4B4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808C4DC
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808C4A6
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C4D8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C4A6
	strb r5, [r4, #0xf]
	b _0808C4DE
	.align 2, 0
_0808C4D8: .4byte 0x00020001
_0808C4DC:
	strb r0, [r4, #0xf]
_0808C4DE:
	movs r0, #0
_0808C4E0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c4e8
FUN_0808c4e8: @ 0x0808C4E8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0x10]
	cmp r1, #1
	bne _0808C52C
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0808C52C
	adds r0, #0x8c
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0808C52C
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r0
	cmp r5, #0
	beq _0808C518
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0808C52C
_0808C518:
	ldr r2, _0808C534 @ =0x08369108
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808C52C
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808C52C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808C534: .4byte 0x08369108

	thumb_func_start initGeneratorCannon
initGeneratorCannon: @ 0x0808C538
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808C5C8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _0808C5CC @ =0x08369110
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r5, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	adds r0, r6, #0
	adds r0, #0xb4
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _0808C604
	ldrb r0, [r6, #0xb]
	movs r1, #8
	orrs r0, r1
	strb r0, [r6, #0xb]
	ldr r0, _0808C5D0 @ =0x08369114
	str r0, [r6, #0x30]
	ldr r0, _0808C5D4 @ =0x00000801
	strh r0, [r6, #0x26]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldr r0, _0808C5D8 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x13]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808C5E4
	ldr r0, _0808C5DC @ =gCurStory
	ldrb r1, [r0, #4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0808C5E4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C5E0 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	b _0808C620
	.align 2, 0
_0808C5C8: .4byte gEnemyFnTable
_0808C5CC: .4byte 0x08369110
_0808C5D0: .4byte 0x08369114
_0808C5D4: .4byte 0x00000801
_0808C5D8: .4byte gSystemSavedataManager
_0808C5DC: .4byte gCurStory
_0808C5E0: .4byte 0x08368F58
_0808C5E4:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C600 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x14
	b _0808C620
	.align 2, 0
_0808C600: .4byte 0x08368F58
_0808C604:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r5, [r0]
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808C638 @ =0x08368F58
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #5
_0808C620:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808C63C @ =nop_0808c3e8
	str r0, [r4, #0x24]
	adds r0, r6, #0
	bl generatorCannonAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808C638: .4byte 0x08368F58
_0808C63C: .4byte nop_0808c3e8

	thumb_func_start generatorCannonAI
generatorCannonAI: @ 0x0808C640
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808C660 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0808C664
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _0808C678
	.align 2, 0
_0808C660: .4byte gCurStory
_0808C664:
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808C6AC
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808C6AC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0808C678:
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808C6A8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808C6EA
	.align 2, 0
_0808C6A8: .4byte gEnemyFnTable
_0808C6AC:
	adds r0, r4, #0
	bl FUN_0808c3ec
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C6EA
	adds r0, r4, #0
	bl FUN_0808c4e8
	adds r0, r4, #0
	bl FUN_0808c450
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C6EA
	ldr r1, _0808C6F0 @ =0x08368F08
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808C6F4 @ =0x08368F28
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808C6EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C6F0: .4byte 0x08368F08
_0808C6F4: .4byte 0x08368F28

	thumb_func_start killGeneratorCannon
killGeneratorCannon: @ 0x0808C6F8
	push {lr}
	adds r3, r0, #0
	ldr r0, _0808C740 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808C748
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0808C744 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _0808C758
	.align 2, 0
_0808C740: .4byte gCurStory
_0808C744: .4byte gEnemyFnTable
_0808C748:
	ldr r0, _0808C75C @ =0x08368F48
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_0808C758:
	pop {r0}
	bx r0
	.align 2, 0
_0808C75C: .4byte 0x08368F48
_0808C760:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0808c764
FUN_0808c764: @ 0x0808C764
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C780 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C77C
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808C77C:
	pop {r0}
	bx r0
	.align 2, 0
_0808C780: .4byte 0x00020001

	thumb_func_start FUN_0808c784
FUN_0808c784: @ 0x0808C784
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808C79A
	bl isKilled
	cmp r0, #0
	beq _0808C7BA
_0808C79A:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C7D8 @ =0x08368F70
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808C7BA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C7BA:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808C7DC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808C7D0
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C7D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C7D8: .4byte 0x08368F70
_0808C7DC: .4byte 0x00020001

	thumb_func_start generatorcannon_0808c7e0
generatorcannon_0808c7e0: @ 0x0808C7E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808C7F0
	cmp r5, #1
	beq _0808C814
	b _0808C85A
_0808C7F0:
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	str r5, [r4, #0x60]
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C860 @ =0x08368F88
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C814:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _0808C85A
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0808C83C
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808C834
	str r1, [r4, #0x60]
_0808C834:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0808C83C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808C85A
	movs r0, #1
	strb r0, [r4, #0x12]
	ldr r0, _0808C864 @ =0xFFFFF800
	cmp r1, r0
	ble _0808C85A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0808C85A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C860: .4byte 0x08368F88
_0808C864: .4byte 0xFFFFF800

	thumb_func_start generatorcannon_0808c868
generatorcannon_0808c868: @ 0x0808C868
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808C878
	cmp r0, #1
	beq _0808C894
	b _0808C8CE
_0808C878:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808C8B4 @ =0x08369090
	bl SetDDP
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldr r1, _0808C8B8 @ =0x00007106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C894:
	ldrb r0, [r4, #0x12]
	adds r5, r0, #0
	cmp r5, #0
	bne _0808C8C4
	ldr r0, _0808C8BC @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _0808C8C0 @ =0x00000FFF
	cmp r0, r1
	bhi _0808C8C8
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _0808C8C8
	.align 2, 0
_0808C8B4: .4byte 0x08369090
_0808C8B8: .4byte 0x00007106
_0808C8BC: .4byte gStageRun+232
_0808C8C0: .4byte 0x00000FFF
_0808C8C4:
	subs r0, #1
	strb r0, [r4, #0x12]
_0808C8C8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808C8CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start generatorcannon_0808c8d4
generatorcannon_0808c8d4: @ 0x0808C8D4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0808C8E4
	cmp r1, #1
	beq _0808C8FA
	b _0808C95E
_0808C8E4:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	movs r1, #0xe2
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C8FA:
	ldrb r0, [r4, #0x12]
	movs r1, #0xc
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C922
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bhi _0808C922
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, _0808C964 @ =0xFFFFF000
	adds r1, r1, r2
	ldrb r2, [r4, #0x13]
	bl FUN_0808c388
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_0808C922:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808C936
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808C936:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808C968 @ =0x0836911C
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808C96C @ =0x08368F58
	adds r1, r1, r2
	bl SetDDP
_0808C95E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C964: .4byte 0xFFFFF000
_0808C968: .4byte 0x0836911C
_0808C96C: .4byte 0x08368F58

	thumb_func_start generatorcannon_0808c970
generatorcannon_0808c970: @ 0x0808C970
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808C99C
	cmp r0, #1
	bgt _0808C984
	cmp r0, #0
	beq _0808C98E
	b _0808CA1A
_0808C984:
	cmp r0, #2
	beq _0808C9E4
	cmp r0, #3
	beq _0808CA00
	b _0808CA1A
_0808C98E:
	ldr r1, _0808C9D8 @ =0x00007101
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C99C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808C9B2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808C9B2:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808C9DC @ =0x08369120
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808C9E0 @ =0x08368F58
	adds r1, r1, r2
	bl SetDDP
	b _0808CA1A
	.align 2, 0
_0808C9D8: .4byte 0x00007101
_0808C9DC: .4byte 0x08369120
_0808C9E0: .4byte 0x08368F58
_0808C9E4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808CA20 @ =0x08369090
	bl SetDDP
	movs r0, #0x50
	strb r0, [r4, #0x12]
	ldr r1, _0808CA24 @ =0x00007106
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CA00:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CA14
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808CA14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808CA1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808CA20: .4byte 0x08369090
_0808CA24: .4byte 0x00007106

	thumb_func_start generatorcannon_0808ca28
generatorcannon_0808ca28: @ 0x0808CA28
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0808CA4E
	cmp r0, #1
	bgt _0808CA3E
	cmp r0, #0
	beq _0808CA44
	b _0808CAD0
_0808CA3E:
	cmp r0, #2
	beq _0808CA9A
	b _0808CAD0
_0808CA44:
	movs r0, #3
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0808CA4E:
	movs r0, #0x2c
	bl PlaySound
	ldr r0, [r6, #0x54]
	ldr r1, _0808CAC0 @ =0xFFFFDB00
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r4, _0808CAC4 @ =0xFFFFF200
	adds r0, r0, r4
	str r0, [sp, #4]
	movs r5, #0xc0
	lsls r5, r5, #2
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0
	bl CreateLemon
	ldr r0, [r6, #0x54]
	movs r1, #0x94
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r6, #0x58]
	adds r0, r0, r4
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	movs r2, #0x80
	bl CreateLemon
	ldr r1, _0808CAC8 @ =0x00007102
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0808CA9A:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808CAD0
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CACC
	movs r0, #1
	strb r0, [r6, #0xd]
	strb r1, [r6, #0xe]
	b _0808CAD0
	.align 2, 0
_0808CAC0: .4byte 0xFFFFDB00
_0808CAC4: .4byte 0xFFFFF200
_0808CAC8: .4byte 0x00007102
_0808CACC:
	movs r0, #1
	strb r0, [r6, #0xe]
_0808CAD0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start generatorcannon_0808cad8
generatorcannon_0808cad8: @ 0x0808CAD8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808CB24
	cmp r0, #1
	bgt _0808CAEC
	cmp r0, #0
	beq _0808CAF6
	b _0808CC00
_0808CAEC:
	cmp r0, #2
	beq _0808CB90
	cmp r0, #3
	beq _0808CBA2
	b _0808CC00
_0808CAF6:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808CB40 @ =0x08368F70
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldrb r1, [r4, #0x12]
	movs r0, #2
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x10
	strb r0, [r4, #0x13]
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CB24:
	movs r2, #0
	ldr r0, _0808CB44 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808CB34
	movs r2, #1
_0808CB34:
	cmp r2, #0
	beq _0808CB48
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808CB4E
	.align 2, 0
_0808CB40: .4byte 0x08368F70
_0808CB44: .4byte pZero2
_0808CB48:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CB4E:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	ldr r1, _0808CB8C @ =0xFFFFFD00
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808CC00
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808CC00
	.align 2, 0
_0808CB8C: .4byte 0xFFFFFD00
_0808CB90:
	ldrb r0, [r4, #0x12]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x18
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808CBA2:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808CBB6
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808CBB6:
	movs r2, #0
	ldr r0, _0808CBD4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808CBC6
	movs r2, #1
_0808CBC6:
	cmp r2, #0
	beq _0808CBD8
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0808CBDE
	.align 2, 0
_0808CBD4: .4byte pZero2
_0808CBD8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CBDE:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808CC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start generatorcannon_0808cc08
generatorcannon_0808cc08: @ 0x0808CC08
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0808CC18
	cmp r0, #1
	beq _0808CCF0
	b _0808CD4E
_0808CC18:
	ldr r0, _0808CCB0 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _0808CCB4 @ =0x00003FFF
	cmp r0, r1
	bhi _0808CC30
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound
_0808CC30:
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x93
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r1, _0808CCB8 @ =0x08368F70
	bl SetDDP
	ldr r0, _0808CCBC @ =pZero2
	ldr r1, [r0]
	ldr r5, [r1, #0x54]
	ldr r0, [r7, #0x54]
	subs r5, r5, r0
	ldr r0, [r7, #0x58]
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r0, r2
	ldr r6, [r1, #0x58]
	subs r6, r6, r0
	asrs r0, r5, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r1, r6, #8
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #8
	lsls r5, r5, #8
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	lsls r6, r6, #8
	adds r0, r6, #0
	adds r1, r4, #0
	bl __divsi3
	lsls r5, r5, #2
	str r5, [r7, #0x5c]
	lsls r0, r0, #2
	str r0, [r7, #0x60]
	movs r1, #0
	cmp r5, #0
	ble _0808CCA0
	movs r1, #1
_0808CCA0:
	adds r2, r1, #0
	cmp r2, #0
	beq _0808CCC0
	ldrb r0, [r7, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0808CCC6
	.align 2, 0
_0808CCB0: .4byte gStageRun+232
_0808CCB4: .4byte 0x00003FFF
_0808CCB8: .4byte 0x08368F70
_0808CCBC: .4byte pZero2
_0808CCC0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808CCC6:
	strb r0, [r7, #0xa]
	adds r1, r2, #0
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0808CD54 @ =0x00007201
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808CCF0:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, _0808CD58 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808CD4E
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
	ldr r1, _0808CD5C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808CD4E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CD54: .4byte 0x00007201
_0808CD58: .4byte gStageRun+232
_0808CD5C: .4byte gEnemyFnTable

	thumb_func_start generatorcannon_0808cd60
generatorcannon_0808cd60: @ 0x0808CD60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808CD70
	cmp r0, #1
	beq _0808CE06
	b _0808CE46
_0808CD70:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0808CDEC @ =0x083690F0
	bl SetDDP
	movs r1, #0xe4
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0808CDF0 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0808CDF4 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0808CDF8
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0808CE00
	.align 2, 0
_0808CDEC: .4byte 0x083690F0
_0808CDF0: .4byte pZero2
_0808CDF4: .4byte 0xFFFFE800
_0808CDF8:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0808CE00:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808CE06:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808CE1E
	str r1, [r5, #0x60]
_0808CE1E:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808CE40
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0808CE46
_0808CE40:
	adds r0, r5, #0
	bl FUN_0808cefc
_0808CE46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ce4c
FUN_0808ce4c: @ 0x0808CE4C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r1, [r5, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xb]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _0808CEE8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r4, _0808CEEC @ =0x08369124
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	movs r3, #3
	bl FUN_080b7f70
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _0808CEF0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808CEF4 @ =0x0000270E
	cmp r1, r0
	bhi _0808CEC4
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808CEC4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldr r1, _0808CEF8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CEE8: .4byte 0xFFFFF000
_0808CEEC: .4byte 0x08369124
_0808CEF0: .4byte gMission
_0808CEF4: .4byte 0x0000270E
_0808CEF8: .4byte gEnemyFnTable

	thumb_func_start FUN_0808cefc
FUN_0808cefc: @ 0x0808CEFC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0808CF80 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808CF84 @ =0x0836912A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #0
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808CF88 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808CF8C @ =0x0000270E
	cmp r1, r0
	bhi _0808CF5C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808CF5C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0808CF90 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CF80: .4byte 0xFFFFF000
_0808CF84: .4byte 0x0836912A
_0808CF88: .4byte gMission
_0808CF8C: .4byte 0x0000270E
_0808CF90: .4byte gEnemyFnTable

	thumb_func_start FUN_0808cf94
FUN_0808cf94: @ 0x0808CF94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808CFA6
	cmp r6, #1
	beq _0808D05E
	b _0808D0A4
_0808CFA6:
	movs r7, #0
	ldr r0, _0808D020 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808CFB8
	movs r7, #1
_0808CFB8:
	lsls r4, r7, #8
	subs r0, r1, r4
	str r0, [r5, #0x54]
	ldr r1, _0808D024 @ =0x00007202
	adds r0, r5, #0
	bl SetMotion
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
	ldr r0, [r5, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0x10]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #0xc
	adds r3, r7, #0
	bl FUN_080b2b40
	movs r0, #0x80
	subs r0, r0, r4
	str r0, [sp, #0xc]
	movs r0, #0x60
	str r0, [sp, #0x10]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D02C
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808D028 @ =0x08369130
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #0xc
	movs r3, #0x20
	bl FUN_080b84f4
	b _0808D046
	.align 2, 0
_0808D020: .4byte pZero2
_0808D024: .4byte 0x00007202
_0808D028: .4byte 0x08369130
_0808D02C:
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808D0AC @ =0x08369130
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x19
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	movs r3, #0x20
	bl FUN_080b85fc
_0808D046:
	ldr r0, [sp, #0xc]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r5, #0x5c]
	movs r0, #0
	str r0, [r5, #0x60]
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808D05E:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x15
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808D076
	str r1, [r5, #0x60]
_0808D076:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808D09E
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808D0A4
_0808D09E:
	adds r0, r5, #0
	bl FUN_0808cefc
_0808D0A4:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D0AC: .4byte 0x08369130

	thumb_func_start FUN_0808d0b0
FUN_0808d0b0: @ 0x0808D0B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0808D104 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808D0FC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808D108 @ =gEnemyFnTable
	movs r1, #0x37
	strb r1, [r3, #9]
	adds r0, #0xdc
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
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_0808D0FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D104: .4byte gZakoHeaderPtr
_0808D108: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d10c
FUN_0808d10c: @ 0x0808D10C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808D158 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808D152
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808D15C @ =gEnemyFnTable
	movs r1, #0x37
	strb r1, [r3, #9]
	adds r0, #0xdc
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
	movs r0, #9
	strb r0, [r3, #0x10]
	str r4, [r3, #0x28]
_0808D152:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D158: .4byte gZakoHeaderPtr
_0808D15C: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d160
FUN_0808d160: @ 0x0808D160
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	cmp r1, #0
	bge _0808D1E8
	ldr r4, _0808D1DC @ =0xFFFFEE00
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToRight1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E0 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D1E4 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToRight1
	str r0, [sp, #8]
	movs r0, #0
_0808D19E:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D1C4
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D1B0:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	bge _0808D1BC
	str r2, [r5]
	str r1, [r0]
_0808D1BC:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D1B0
_0808D1C4:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D19E
	ldr r1, [sp]
	cmp r1, #0
	ble _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #1
	b _0808D25E
	.align 2, 0
_0808D1DC: .4byte 0xFFFFEE00
_0808D1E0: .4byte 0xFFFFF100
_0808D1E4: .4byte 0xFFFFE200
_0808D1E8:
	movs r4, #0x90
	lsls r4, r4, #5
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	bl PushoutToLeft1
	str r0, [sp]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D254 @ =0xFFFFF100
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	adds r0, r0, r4
	ldr r1, [r6, #0x58]
	ldr r2, _0808D258 @ =0xFFFFE200
	adds r1, r1, r2
	bl PushoutToLeft1
	str r0, [sp, #8]
	movs r0, #0
_0808D218:
	adds r4, r0, #1
	adds r3, r4, #0
	cmp r4, #2
	bgt _0808D23E
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r1, r0
	lsls r0, r4, #2
	add r0, sp
_0808D22A:
	ldr r1, [r5]
	ldr r2, [r0]
	cmp r1, r2
	ble _0808D236
	str r2, [r5]
	str r1, [r0]
_0808D236:
	adds r0, #4
	adds r3, #1
	cmp r3, #2
	ble _0808D22A
_0808D23E:
	adds r0, r4, #0
	cmp r0, #1
	ble _0808D218
	ldr r1, [sp]
	cmp r1, #0
	bge _0808D25C
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	movs r0, #2
	b _0808D25E
	.align 2, 0
_0808D254: .4byte 0xFFFFF100
_0808D258: .4byte 0xFFFFE200
_0808D25C:
	movs r0, #0
_0808D25E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d268
FUN_0808d268: @ 0x0808D268
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x58]
	adds r2, r0, r1
	str r2, [r7, #0x58]
	cmp r1, #0
	bge _0808D2B4
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2AC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r4, _0808D2B0 @ =0xFFFFE200
	adds r1, r2, r4
	bl PushoutToDown1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	adds r1, r1, r4
	bl PushoutToDown1
	adds r6, r0, #0
	cmp r5, r6
	bge _0808D29E
	adds r5, r0, #0
_0808D29E:
	cmp r5, #0
	ble _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #1
	b _0808D2EE
	.align 2, 0
_0808D2AC: .4byte 0xFFFFEE00
_0808D2B0: .4byte 0xFFFFE200
_0808D2B4:
	ldr r0, [r7, #0x54]
	ldr r1, _0808D2E8 @ =0xFFFFEE00
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r7, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r5, r6
	ble _0808D2D8
	adds r5, r0, #0
_0808D2D8:
	cmp r5, #0
	bge _0808D2EC
	ldr r0, [r7, #0x58]
	adds r0, r0, r5
	str r0, [r7, #0x58]
	movs r0, #2
	b _0808D2EE
	.align 2, 0
_0808D2E8: .4byte 0xFFFFEE00
_0808D2EC:
	movs r0, #0
_0808D2EE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start nop_0808d2f4
nop_0808d2f4: @ 0x0808D2F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808d2f8
FUN_0808d2f8: @ 0x0808D2F8
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808D368
	ldr r1, _0808D328 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #9
	bne _0808D32C
	movs r0, #0
	b _0808D35C
	.align 2, 0
_0808D328: .4byte gEnemyFnTable
_0808D32C:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r1, r0
	cmp r1, #0
	beq _0808D344
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #1
	strb r0, [r1]
	strb r4, [r2, #0xd]
	b _0808D35E
_0808D344:
	adds r0, r2, #0
	adds r0, #0xbb
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0808D35A
	movs r0, #3
	b _0808D35C
_0808D35A:
	movs r0, #1
_0808D35C:
	strb r0, [r2, #0xd]
_0808D35E:
	adds r0, r2, #0
	bl killDeathlock
	movs r0, #1
	b _0808D36A
_0808D368:
	movs r0, #0
_0808D36A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808d370
FUN_0808d370: @ 0x0808D370
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _0808D37C
	b _0808D496
_0808D37C:
	ldrb r0, [r4, #0x10]
	cmp r0, #9
	bne _0808D384
	b _0808D496
_0808D384:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	beq _0808D390
	b _0808D496
_0808D390:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808D39C
	cmp r0, #1
	beq _0808D420
	b _0808D496
_0808D39C:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808D496
	ldr r1, _0808D40C @ =0x08369148
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D410 @ =0x08369168
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xd]
	cmp r0, #3
	bne _0808D3FA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D414 @ =0x0836930C
	adds r5, r4, #0
	adds r5, #0xb9
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D418 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldr r1, _0808D41C @ =0x08369300
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
_0808D3FA:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808D406:
	movs r0, #1
	b _0808D498
	.align 2, 0
_0808D40C: .4byte 0x08369148
_0808D410: .4byte 0x08369168
_0808D414: .4byte 0x0836930C
_0808D418: .4byte 0x08369198
_0808D41C: .4byte 0x08369300
_0808D420:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808D494
	ldr r0, [r4, #0x54]
	ldr r1, _0808D48C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D45C
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808D462
_0808D45C:
	adds r0, r4, #0
	bl FUN_0808d160
_0808D462:
	ldrb r1, [r4, #0xd]
	cmp r1, #3
	bne _0808D46C
	ldr r0, [r4, #0x54]
	str r0, [r4, #0x64]
_0808D46C:
	ldrb r0, [r4, #0x10]
	cmp r0, #8
	beq _0808D406
	cmp r1, #3
	beq _0808D406
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D490 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D406
	movs r0, #0
	strb r0, [r4, #0xf]
	b _0808D498
	.align 2, 0
_0808D48C: .4byte 0xFFFFEE00
_0808D490: .4byte 0x00020001
_0808D494:
	strb r0, [r4, #0xf]
_0808D496:
	movs r0, #0
_0808D498:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808d4a0
FUN_0808d4a0: @ 0x0808D4A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0808D4EE
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _0808D4EE
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808D4EE
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _0808D4DA
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _0808D4EE
_0808D4DA:
	ldr r2, _0808D4F4 @ =0x08369314
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808D4EE
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808D4EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D4F4: .4byte 0x08369314

	thumb_func_start initDeathlock
initDeathlock: @ 0x0808D4F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0808D524 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r1, [r6, #0x11]
	ldrb r0, [r6, #0x10]
	cmp r0, #8
	bne _0808D52C
	movs r0, #7
	strb r0, [r6, #0xd]
	ldr r0, [r6, #0x58]
	ldr r1, _0808D528 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r6, #0x58]
	b _0808D538
	.align 2, 0
_0808D524: .4byte gEnemyFnTable
_0808D528: .4byte 0xFFFFF800
_0808D52C:
	cmp r0, #9
	bne _0808D536
	movs r0, #5
	strb r0, [r6, #0xd]
	b _0808D538
_0808D536:
	strb r1, [r6, #0xd]
_0808D538:
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r1, r0
	movs r0, #1
	movs r4, #0
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #7
	bhi _0808D5C0
	ldr r0, _0808D58C @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808D598
	ldr r0, _0808D590 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0808D598
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D594 @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	bl InitBody
	str r6, [r4, #0x2c]
	movs r0, #0
	str r0, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D58C: .4byte gSystemSavedataManager
_0808D590: .4byte gCurStory
_0808D594: .4byte 0x08369198
_0808D598:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D5BC @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	b _0808D5E0
	.align 2, 0
_0808D5BC: .4byte 0x08369198
_0808D5C0:
	cmp r0, #9
	bne _0808D5E4
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808D600 @ =0x08369198
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
_0808D5E0:
	ldr r0, _0808D604 @ =nop_0808d2f4
	str r0, [r4, #0x24]
_0808D5E4:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bhi _0808D608
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	b _0808D618
	.align 2, 0
_0808D600: .4byte 0x08369198
_0808D604: .4byte nop_0808d2f4
_0808D608:
	subs r1, r0, #4
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0808D618
	strb r1, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #0x11]
_0808D618:
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, r6, #0
	bl deathlockAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start deathlockAI
deathlockAI: @ 0x0808D638
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #8
	beq _0808D690
	ldr r0, _0808D688 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808D690
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808D68C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _0808D6CE
	.align 2, 0
_0808D688: .4byte gCurStory
_0808D68C: .4byte gEnemyFnTable
_0808D690:
	adds r0, r4, #0
	bl FUN_0808d2f8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D6CE
	adds r0, r4, #0
	bl FUN_0808d4a0
	adds r0, r4, #0
	bl FUN_0808d370
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D6CE
	ldr r1, _0808D6D4 @ =0x08369148
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808D6D8 @ =0x08369168
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0808D6CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D6D4: .4byte 0x08369148
_0808D6D8: .4byte 0x08369168

	thumb_func_start killDeathlock
killDeathlock: @ 0x0808D6DC
	push {lr}
	ldr r2, _0808D6F0 @ =0x08369188
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0808D6F0: .4byte 0x08369188
_0808D6F4:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0808d6f8
FUN_0808d6f8: @ 0x0808D6F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808D70E
	bl isKilled
	cmp r0, #0
	beq _0808D742
_0808D70E:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D760 @ =0x0836930C
	adds r1, r4, #0
	adds r1, #0xb9
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D764 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D742
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808D742:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D768 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D758
	movs r1, #0
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808D758:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D760: .4byte 0x0836930C
_0808D764: .4byte 0x08369198
_0808D768: .4byte 0x00020001

	thumb_func_start FUN_0808d76c
FUN_0808d76c: @ 0x0808D76C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0808D788 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0808D784
	movs r1, #0
	movs r0, #6
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0808D784:
	pop {r0}
	bx r0
	.align 2, 0
_0808D788: .4byte 0x00020001

	thumb_func_start FUN_0808d78c
FUN_0808d78c: @ 0x0808D78C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808D79C
	cmp r5, #1
	beq _0808D7D8
	b _0808D88C
_0808D79C:
	ldr r1, _0808D850 @ =0x08369300
	adds r6, r4, #0
	adds r6, #0xb9
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808D854 @ =0x0836931C
	ldrb r1, [r6]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D858 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808D7D8:
	ldr r0, [r4, #0x54]
	ldr r1, _0808D85C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r5, r0, #0
	cmp r5, #0
	bne _0808D80A
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r5, r0, #0
	cmp r5, #0
	beq _0808D812
_0808D80A:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d160
_0808D812:
	adds r0, r4, #0
	bl isFrozen
	adds r6, r0, #0
	cmp r6, #0
	bne _0808D88C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808D860
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808D83C
	str r1, [r4, #0x60]
_0808D83C:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	b _0808D88C
	.align 2, 0
_0808D850: .4byte 0x08369300
_0808D854: .4byte 0x0836931C
_0808D858: .4byte 0x08369198
_0808D85C: .4byte 0xFFFFEE00
_0808D860:
	str r6, [r4, #0x60]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0808D88C
	cmp r5, #0
	bne _0808D88C
	adds r0, r4, #0
	adds r0, #0xbb
	strb r5, [r0]
	adds r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0808D894 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808D88C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D894: .4byte gEnemyFnTable

	thumb_func_start FUN_0808d898
FUN_0808d898: @ 0x0808D898
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xe]
	cmp r6, #0
	beq _0808D8A8
	cmp r6, #1
	beq _0808D958
	b _0808DA12
_0808D8A8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _0808D8F0 @ =0x0836930C
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808D8F4 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0808D8D0
	cmp r0, #2
	bne _0808D8F8
_0808D8D0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0808D91A
	.align 2, 0
_0808D8F0: .4byte 0x0836930C
_0808D8F4: .4byte 0x08369198
_0808D8F8:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
_0808D91A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808D930
	ldr r0, _0808D92C @ =0x08369300
	ldrb r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	b _0808D938
	.align 2, 0
_0808D92C: .4byte 0x08369300
_0808D930:
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0808D944
	ldr r1, _0808D940 @ =0x00007402
_0808D938:
	adds r0, r5, #0
	bl SetMotion
	b _0808D94C
	.align 2, 0
_0808D940: .4byte 0x00007402
_0808D944:
	ldr r1, _0808D9CC @ =0x00007401
	adds r0, r5, #0
	bl SetMotion
_0808D94C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808D958:
	ldr r0, [r5, #0x54]
	ldr r1, _0808D9D0 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808D98A
	ldr r0, [r5, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808D9A4
_0808D98A:
	adds r0, r5, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808D99E
	movs r1, #0
	movs r0, #3
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808D99E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0808D9A4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808D9BA
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808D9BA:
	adds r1, r5, #0
	adds r1, #0xba
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808D9D4
	subs r0, #1
	strb r0, [r1]
	b _0808DA12
	.align 2, 0
_0808D9CC: .4byte 0x00007401
_0808D9D0: .4byte 0xFFFFEE00
_0808D9D4:
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r3, [r0]
	cmp r3, #0
	bne _0808DA12
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bhi _0808DA12
	ldr r0, _0808DA18 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, _0808DA1C @ =0x00008FFF
	cmp r0, r1
	bhi _0808DA12
	ldr r0, [r2, #0x58]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	ldr r1, _0808DA20 @ =0x00003FFF
	cmp r0, r1
	bhi _0808DA12
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r3, [r5, #0xe]
_0808DA12:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DA18: .4byte pZero2
_0808DA1C: .4byte 0x00008FFF
_0808DA20: .4byte 0x00003FFF

	thumb_func_start FUN_0808da24
FUN_0808da24: @ 0x0808DA24
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0808DA34
	cmp r5, #1
	beq _0808DA88
	b _0808DB56
_0808DA34:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808DA6C @ =0x0836930C
	adds r6, r4, #0
	adds r6, #0xb9
	ldrb r1, [r6]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808DA70 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r6]
	cmp r0, #0
	beq _0808DA78
	ldr r0, _0808DA74 @ =0x08369300
	ldrb r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r4, #0
	bl SetMotion
	b _0808DA82
	.align 2, 0
_0808DA6C: .4byte 0x0836930C
_0808DA70: .4byte 0x08369198
_0808DA74: .4byte 0x08369300
_0808DA78:
	movs r1, #0xe8
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_0808DA82:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DA88:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808DA98
	str r1, [r4, #0x60]
_0808DA98:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DB0E
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x54]
	ldr r1, _0808DAE8 @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	bne _0808DADE
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	cmp r0, #0
	beq _0808DAEC
_0808DADE:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
	b _0808DB0E
	.align 2, 0
_0808DAE8: .4byte 0xFFFFEE00
_0808DAEC:
	adds r1, r4, #0
	adds r1, #0xbb
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0808DB5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808DB0E:
	ldr r0, _0808DB60 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DB56
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808DB5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808DB56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DB5C: .4byte gEnemyFnTable
_0808DB60: .4byte gStageRun+232

	thumb_func_start FUN_0808db64
FUN_0808db64: @ 0x0808DB64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0808DB7C
	cmp r0, #1
	beq _0808DBC8
	b _0808DD4E
_0808DB7C:
	ldr r0, [r7, #0x54]
	str r0, [r7, #0x64]
	ldr r1, _0808DBA0 @ =0x08369300
	adds r4, r7, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl SetMotion
	ldrb r0, [r4]
	cmp r0, #0
	bne _0808DBA4
	movs r0, #8
	b _0808DBA6
	.align 2, 0
_0808DBA0: .4byte 0x08369300
_0808DBA4:
	movs r0, #0x18
_0808DBA6:
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x74
	ldr r2, _0808DC14 @ =0x0836930C
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808DC18 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0808DBC8:
	ldr r0, [r7, #0x54]
	ldr r1, _0808DC1C @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808DBF6
	ldr r0, [r7, #0x54]
	movs r3, #0x90
	lsls r3, r3, #5
	adds r0, r0, r3
	ldr r1, [r7, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
_0808DBF6:
	ldr r0, [r7, #0x64]
	str r0, [r7, #0x54]
	cmp r1, #0
	beq _0808DC0A
	adds r0, r7, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DC20
_0808DC0A:
	movs r1, #0
	movs r0, #1
	strb r0, [r7, #0xd]
	strb r1, [r7, #0xe]
	b _0808DC40
	.align 2, 0
_0808DC14: .4byte 0x0836930C
_0808DC18: .4byte 0x08369198
_0808DC1C: .4byte 0xFFFFEE00
_0808DC20:
	ldr r2, [r7, #0x54]
	ldr r3, _0808DD5C @ =0xFFFFFE00
	adds r2, r2, r3
	ldr r3, _0808DD60 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _0808DD64 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808DD68 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r7, #0x54]
_0808DC40:
	ldrb r0, [r7, #0x12]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DC94
	ldr r1, [r7, #0x54]
	ldr r2, _0808DD6C @ =0xFFFFF000
	mov r8, r2
	add r1, r8
	ldr r3, _0808DD60 @ =RNG_0202f388
	mov sb, r3
	ldr r0, [r3]
	ldr r6, _0808DD64 @ =0x000343FD
	muls r0, r6, r0
	ldr r3, _0808DD68 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r4, r0, #1
	lsrs r0, r0, #0x11
	ldr r5, _0808DD70 @ =0x00001FFF
	ands r0, r5
	adds r0, r0, r1
	str r0, [sp]
	ldr r2, [r7, #0x58]
	add r2, r8
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, sb
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r5
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
_0808DC94:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _0808DD06
	movs r0, #0x56
	bl PlaySound
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	adds r5, r7, #0
	adds r5, #0xb9
	ldrb r2, [r5]
	ldrb r3, [r7, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r6, [r7, #0xe]
	ldrb r0, [r5]
	cmp r0, #5
	bls _0808DD06
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808DD74 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808DD06:
	ldr r0, _0808DD78 @ =gStageRun+232
	adds r1, r7, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DD4E
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
	ldr r1, _0808DD74 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r7, #0x14]
_0808DD4E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DD5C: .4byte 0xFFFFFE00
_0808DD60: .4byte RNG_0202f388
_0808DD64: .4byte 0x000343FD
_0808DD68: .4byte 0x00269EC3
_0808DD6C: .4byte 0xFFFFF000
_0808DD70: .4byte 0x00001FFF
_0808DD74: .4byte gEnemyFnTable
_0808DD78: .4byte gStageRun+232

	thumb_func_start FUN_0808dd7c
FUN_0808dd7c: @ 0x0808DD7C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808DDAC
	cmp r0, #1
	bgt _0808DD90
	cmp r0, #0
	beq _0808DD9A
	b _0808DDFE
_0808DD90:
	cmp r0, #2
	beq _0808DDD0
	cmp r0, #3
	beq _0808DDDE
	b _0808DDFE
_0808DD9A:
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r1, _0808DDCC @ =0x00007402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDAC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808DDC4
	adds r0, r4, #0
	bl FUN_0808d10c
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDC4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808DDFE
	.align 2, 0
_0808DDCC: .4byte 0x00007402
_0808DDD0:
	ldr r1, _0808DEA8 @ =0x00007403
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DDDE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808DDFE
	adds r2, r4, #0
	adds r2, #0xba
	movs r0, #0
	movs r1, #0x20
	strb r1, [r2]
	movs r1, #1
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808DDFE:
	ldr r0, [r4, #0x54]
	ldr r1, _0808DEAC @ =0xFFFFEE00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	bne _0808DE30
	ldr r0, [r4, #0x54]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl FUN_0800a40c
	adds r1, r0, #0
	cmp r1, #0
	beq _0808DE44
_0808DE30:
	adds r0, r4, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DE44
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808DE44:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808d268
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808DE5A
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808DE5A:
	ldr r0, _0808DEB0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808DEA2
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808DEB4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808DEA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DEA8: .4byte 0x00007403
_0808DEAC: .4byte 0xFFFFEE00
_0808DEB0: .4byte gStageRun+232
_0808DEB4: .4byte gEnemyFnTable

	thumb_func_start FUN_0808deb8
FUN_0808deb8: @ 0x0808DEB8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _0808DECC
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0808DECC
	movs r5, #0
	str r5, [r4, #0x28]
_0808DECC:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808DF16
	cmp r0, #1
	bgt _0808DEDC
	cmp r0, #0
	beq _0808DEE6
	b _0808E006
_0808DEDC:
	cmp r0, #2
	beq _0808DF7C
	cmp r0, #3
	beq _0808DFB6
	b _0808E006
_0808DEE6:
	movs r0, #0x83
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808DF60 @ =0x083691B0
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, _0808DF64 @ =0xFFFFE400
	str r0, [r4, #0x68]
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldr r1, _0808DF68 @ =0x00007410
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DF16:
	ldr r2, [r5, #0x54]
	ldr r0, _0808DF6C @ =0xFFFFFE00
	adds r2, r2, r0
	ldr r3, _0808DF70 @ =RNG_0202f388
	ldr r1, [r3]
	ldr r0, _0808DF74 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808DF78 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	str r2, [r4, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	subs r1, #0x80
	str r1, [r4, #0x68]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808DF52
	cmp r5, #0
	bne _0808DF58
_0808DF52:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DF58:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808E006
	.align 2, 0
_0808DF60: .4byte 0x083691B0
_0808DF64: .4byte 0xFFFFE400
_0808DF68: .4byte 0x00007410
_0808DF6C: .4byte 0xFFFFFE00
_0808DF70: .4byte RNG_0202f388
_0808DF74: .4byte 0x000343FD
_0808DF78: .4byte 0x00269EC3
_0808DF7C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E00C @ =0x08369198
	bl SetDDP
	ldr r0, _0808E010 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldr r0, _0808E014 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _0808DF9C
	movs r2, #0x80
	lsls r2, r2, #2
_0808DF9C:
	str r2, [r4, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl Sqrt
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808DFB6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808DFD4
	str r1, [r4, #0x60]
_0808DFD4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808E006
	adds r1, r4, #0
	adds r1, #0xbc
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808E018 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xd]
_0808E006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E00C: .4byte 0x08369198
_0808E010: .4byte 0xFFFFFE00
_0808E014: .4byte pZero2
_0808E018: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e01c
FUN_0808e01c: @ 0x0808E01C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808E02C
	cmp r0, #1
	beq _0808E0E2
	b _0808E17C
_0808E02C:
	ldr r1, _0808E0C0 @ =0x08369300
	adds r4, r5, #0
	adds r4, #0xb9
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r2, _0808E0C4 @ =0x0836930C
	ldrb r1, [r4]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808E0C8 @ =0x08369198
	adds r1, r1, r2
	bl SetDDP
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0808E0CC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _0808E0D0 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _0808E0D4
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0808E0DC
	.align 2, 0
_0808E0C0: .4byte 0x08369300
_0808E0C4: .4byte 0x0836930C
_0808E0C8: .4byte 0x08369198
_0808E0CC: .4byte pZero2
_0808E0D0: .4byte 0xFFFFE800
_0808E0D4:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0808E0DC:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808E0E2:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_0808d160
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808E0FE
	adds r6, r5, #0
	adds r6, #0x8c
	ldr r4, [r6]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	beq _0808E10E
_0808E0FE:
	adds r1, r5, #0
	adds r1, #0xbb
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl maybeKillDeathlock
	b _0808E17C
_0808E10E:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E11E
	str r1, [r5, #0x60]
_0808E11E:
	ldr r1, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_0808d268
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E138
	adds r0, r5, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r5, #0
	bl maybeKillDeathlock
_0808E138:
	ldr r0, _0808E184 @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808E17C
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0x90
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0808E188 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0808E17C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E184: .4byte gStageRun+232
_0808E188: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e18c
FUN_0808e18c: @ 0x0808E18C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0808E19C
	cmp r1, #1
	beq _0808E1BA
	b _0808E222
_0808E19C:
	movs r0, #0x40
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	movs r1, #0xec
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x17
	strb r0, [r1]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808E1BA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808E21C
	movs r0, #0xc0
	strb r0, [r4, #0x12]
	ldr r0, _0808E1F0 @ =pZero2
	ldr r0, [r0]
	ldr r3, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r3, r0
	bge _0808E1F4
	ldr r0, [r4, #0x58]
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r0, r2
	ldrb r0, [r4, #0x13]
	movs r2, #7
	cmp r0, #1
	bne _0808E1E8
	movs r2, #5
_0808E1E8:
	adds r0, r3, #0
	bl FUN_0808d0b0
	b _0808E20C
	.align 2, 0
_0808E1F0: .4byte pZero2
_0808E1F4:
	ldr r0, [r4, #0x58]
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r0, r2
	ldrb r0, [r4, #0x13]
	movs r2, #6
	cmp r0, #1
	bne _0808E206
	movs r2, #4
_0808E206:
	adds r0, r3, #0
	bl FUN_0808d0b0
_0808E20C:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #0x13]
_0808E21C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808E222:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808e228
FUN_0808e228: @ 0x0808E228
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0808E288 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808E28C @ =0x08369322
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	ldr r1, _0808E290 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E288: .4byte 0xFFFFF000
_0808E28C: .4byte 0x08369322
_0808E290: .4byte gEnemyFnTable

	thumb_func_start maybeKillDeathlock
maybeKillDeathlock: @ 0x0808E294
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _0808E348 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r0, r6, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E2FC
	adds r0, r6, #0
	adds r0, #0xb9
	ldrb r5, [r0]
	cmp r5, #5
	bgt _0808E2FC
_0808E2E2:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r6, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	adds r5, #1
	cmp r5, #5
	ble _0808E2E2
_0808E2FC:
	adds r0, r6, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E32E
	ldrb r0, [r6, #0x10]
	adds r4, r6, #0
	adds r4, #0x54
	cmp r0, #9
	beq _0808E318
	movs r0, #0
	adds r1, r4, #0
	bl TryDropItem
_0808E318:
	ldr r2, _0808E34C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808E350 @ =0x0000270E
	cmp r1, r0
	bhi _0808E326
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808E326:
	adds r0, r6, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
_0808E32E:
	ldr r1, _0808E354 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E348: .4byte 0xFFFFF000
_0808E34C: .4byte gMission
_0808E350: .4byte 0x0000270E
_0808E354: .4byte gEnemyFnTable

	thumb_func_start FUN_0808e358
FUN_0808e358: @ 0x0808E358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808E372
	cmp r0, #1
	beq _0808E45E
	b _0808E4BC
_0808E372:
	adds r0, r5, #0
	adds r0, #0xb9
	ldrb r6, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	movs r0, #0x90
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0x94
	adds r2, r2, r5
	mov sb, r2
	movs r0, #0x54
	adds r0, r0, r5
	mov sl, r0
	cmp r6, #5
	bgt _0808E3AC
_0808E392:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r5, #0xa]
	lsrs r3, r3, #4
	movs r4, #1
	ands r3, r4
	bl CreateGhost65
	adds r6, #1
	cmp r6, #5
	ble _0808E392
_0808E3AC:
	movs r4, #0
	ldr r0, _0808E434 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808E3BE
	movs r4, #1
_0808E3BE:
	lsls r0, r4, #8
	subs r0, r1, r0
	str r0, [r5, #0x54]
	ldr r1, _0808E438 @ =0x0000740F
	adds r0, r5, #0
	bl SetMotion
	movs r6, #0
	str r6, [r7]
	mov r2, r8
	str r6, [r2]
	mov r0, sb
	strb r6, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_080b2b40
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r1, r2
	bl PushoutToUp1
	mvns r0, r0
	lsrs r0, r0, #0x1f
	strb r0, [r5, #0x13]
	movs r2, #0x60
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #6
	subs r1, r2, r1
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	cmp r0, #0
	beq _0808E440
	ldr r0, _0808E43C @ =0x08369328
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sl
	add r2, sp, #8
	movs r3, #0x20
	bl FUN_080b857c
	str r6, [r5, #0x60]
	b _0808E454
	.align 2, 0
_0808E434: .4byte pZero2
_0808E438: .4byte 0x0000740F
_0808E43C: .4byte 0x08369328
_0808E440:
	ldr r0, _0808E4AC @ =0x08369328
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r5, #0
	mov r1, sl
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_0808E454:
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808E45E:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0808E47C
	ldr r0, [r5, #0x60]
	adds r0, #0x15
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E474
	str r1, [r5, #0x60]
_0808E474:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_0808E47C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r1, r0, #1
	strb r1, [r5, #0x12]
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0808E4B0
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0808E4A2
	ldr r1, [r5, #0x54]
	adds r0, r1, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808E4BC
_0808E4A2:
	adds r0, r5, #0
	bl maybeKillDeathlock
	b _0808E4BC
	.align 2, 0
_0808E4AC: .4byte 0x08369328
_0808E4B0:
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _0808E4BC
	adds r0, r5, #0
	bl maybeKillDeathlock
_0808E4BC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808e4cc
FUN_0808e4cc: @ 0x0808E4CC
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0808E524 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808E51A
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808E528 @ =gEnemyFnTable
	movs r1, #0x38
	strb r1, [r3, #9]
	adds r0, #0xe0
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_0808E51A:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808E524: .4byte gZakoHeaderPtr
_0808E528: .4byte gEnemyFnTable

	thumb_func_start initClaveker
initClaveker: @ 0x0808E52C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	adds r2, r0, #0
	orrs r2, r1
	movs r0, #2
	orrs r2, r0
	orrs r2, r3
	strb r2, [r6, #0xa]
	ldr r0, _0808E578 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x13]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808E584
	ldr r0, _0808E57C @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808E584
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E580 @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xe
	b _0808E59C
	.align 2, 0
_0808E578: .4byte gSystemSavedataManager
_0808E57C: .4byte gCurStory
_0808E580: .4byte 0x08369388
_0808E584:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0808E60C @ =0x08369388
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xa
_0808E59C:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _0808E610 @ =FUN_0808f234
	str r0, [r4, #0x24]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	ldr r0, [r6, #0x54]
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r4, #0
	strb r4, [r0]
	adds r0, #4
	str r4, [r0]
	ldr r1, _0808E614 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r4, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E5F8
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0808E5F8:
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	adds r0, r6, #0
	bl clavekerAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E60C: .4byte 0x08369388
_0808E610: .4byte FUN_0808f234
_0808E614: .4byte gEnemyFnTable

	thumb_func_start clavekerAI
clavekerAI: @ 0x0808E618
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _0808E648
	ldr r1, _0808E644 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl killClaveker
	b _0808E6FC
	.align 2, 0
_0808E644: .4byte gEnemyFnTable
_0808E648:
	ldr r1, _0808E6A0 @ =0x08369340
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0808f1e0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E67E
	ldrb r0, [r4, #0xd]
	cmp r0, #2
	beq _0808E67E
	cmp r0, #3
	beq _0808E67E
	cmp r0, #5
	beq _0808E67E
	cmp r0, #4
	beq _0808E67E
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808E67E:
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0808E6A4
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E6A4
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0808E6FC
	.align 2, 0
_0808E6A0: .4byte 0x08369340
_0808E6A4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808E6B4
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808E6B4:
	ldr r0, [r5]
	cmp r0, #0
	beq _0808E6EC
	bl isKilled
	cmp r0, #0
	beq _0808E6DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E6D8 @ =0x08369388
	bl SetDDP
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	b _0808E6FC
	.align 2, 0
_0808E6D8: .4byte 0x08369388
_0808E6DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808E6E8 @ =0x083693A0
	bl SetDDP
	b _0808E6FC
	.align 2, 0
_0808E6E8: .4byte 0x083693A0
_0808E6EC:
	ldr r0, _0808E704 @ =0x08369358
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0808E6FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E704: .4byte 0x08369358

	thumb_func_start killClaveker
killClaveker: @ 0x0808E708
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _0808E754 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808E75C
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
	ldr r1, _0808E758 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0808EAEE
	.align 2, 0
_0808E754: .4byte gCurStory
_0808E758: .4byte gEnemyFnTable
_0808E75C:
	ldrb r0, [r7, #0xe]
	cmp r0, #0xb
	bls _0808E764
	b _0808EAF0
_0808E764:
	lsls r0, r0, #2
	ldr r1, _0808E770 @ =_0808E774
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808E770: .4byte _0808E774
_0808E774: @ jump table
	.4byte _0808E7A4 @ case 0
	.4byte _0808E8C8 @ case 1
	.4byte _0808E7F4 @ case 2
	.4byte _0808E808 @ case 3
	.4byte _0808E8D0 @ case 4
	.4byte _0808EAF0 @ case 5
	.4byte _0808EAF0 @ case 6
	.4byte _0808EAF0 @ case 7
	.4byte _0808EAF0 @ case 8
	.4byte _0808EAF0 @ case 9
	.4byte _0808E8C8 @ case 10
	.4byte _0808EA50 @ case 11
_0808E7A4:
	ldr r1, _0808E7CC @ =0x00007505
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
	beq _0808E7D0
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _0808E7D0
	movs r0, #1
	b _0808E7D2
	.align 2, 0
_0808E7CC: .4byte 0x00007505
_0808E7D0:
	movs r0, #0xa
_0808E7D2:
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
	b _0808E8C8
_0808E7F4:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0808E806
	b _0808EAF0
_0808E806:
	b _0808E8C8
_0808E808:
	ldr r1, _0808E84C @ =0x00007505
	adds r0, r7, #0
	bl SetMotion
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r7, #0x13]
	str r0, [r7, #0x60]
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #0xb8
	ldrb r1, [r4]
	mov r0, sp
	bl FUN_080c4450
	ldrb r0, [r4]
	cmp r0, #0
	bne _0808E854
	ldr r0, [sp]
	ldr r1, _0808E850 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x80
	b _0808E868
	.align 2, 0
_0808E84C: .4byte 0x00007505
_0808E850: .4byte 0xFFFFF800
_0808E854:
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
_0808E868:
	str r0, [r7, #0x5c]
	adds r0, r7, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0808E894
	cmp r0, #0xfe
	bne _0808E888
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _0808E8B6
_0808E888:
	ldr r0, _0808E8A4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0808E8A8
_0808E894:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _0808E8B6
	.align 2, 0
_0808E8A4: .4byte pZero2
_0808E8A8:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_0808E8B6:
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl TryDropItem
	movs r0, #0x80
	str r0, [r7, #0x60]
	movs r0, #0x32
	strb r0, [r7, #0x12]
_0808E8C8:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0808EAF0
_0808E8D0:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldr r0, [r7, #0x60]
	adds r0, #0x20
	str r0, [r7, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808E8E6
	str r1, [r7, #0x60]
_0808E8E6:
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
	beq _0808E9A4
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0808E984 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808E988 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0808E98C @ =0x00269EC3
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
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808E990 @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808E994 @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808E998 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808E99C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808E9A0 @ =0x0000270E
	cmp r1, r0
	bhi _0808E97A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808E97A:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0808EAD2
	.align 2, 0
_0808E984: .4byte RNG_0202f388
_0808E988: .4byte 0x000343FD
_0808E98C: .4byte 0x00269EC3
_0808E990: .4byte 0x00007507
_0808E994: .4byte 0x00007508
_0808E998: .4byte 0x00007509
_0808E99C: .4byte gMission
_0808E9A0: .4byte 0x0000270E
_0808E9A4:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _0808E9AC
	b _0808EAF0
_0808E9AC:
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E9B8
	b _0808EAF0
_0808E9B8:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r2, _0808EA30 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808EA34 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808EA38 @ =0x00269EC3
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
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808EA3C @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EA40 @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EA44 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0808EA48 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808EA4C @ =0x0000270E
	cmp r1, r0
	bhi _0808EA28
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808EA28:
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	b _0808EAD2
	.align 2, 0
_0808EA30: .4byte RNG_0202f388
_0808EA34: .4byte 0x000343FD
_0808EA38: .4byte 0x00269EC3
_0808EA3C: .4byte 0x00007507
_0808EA40: .4byte 0x00007508
_0808EA44: .4byte 0x00007509
_0808EA48: .4byte gMission
_0808EA4C: .4byte 0x0000270E
_0808EA50:
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
	movs r0, #1
	mov r1, r8
	bl TryDropItem
	ldr r2, _0808EAFC @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808EB00 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _0808EB04 @ =0x00269EC3
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
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808EB08 @ =0x00007507
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EB0C @ =0x00007508
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldrb r1, [r5]
	ldr r2, _0808EB10 @ =0x00007509
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c44a8
	ldr r2, _0808EB14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808EB18 @ =0x0000270E
	cmp r1, r0
	bhi _0808EACE
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808EACE:
	adds r0, r7, #0
	mov r1, r8
_0808EAD2:
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _0808EB1C @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0808EAEE:
	str r0, [r7, #0x14]
_0808EAF0:
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EAFC: .4byte RNG_0202f388
_0808EB00: .4byte 0x000343FD
_0808EB04: .4byte 0x00269EC3
_0808EB08: .4byte 0x00007507
_0808EB0C: .4byte 0x00007508
_0808EB10: .4byte 0x00007509
_0808EB14: .4byte gMission
_0808EB18: .4byte 0x0000270E
_0808EB1C: .4byte gEnemyFnTable

	thumb_func_start FUN_0808eb20
FUN_0808eb20: @ 0x0808EB20
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808eb24
FUN_0808eb24: @ 0x0808EB24
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808EB5C
	cmp r0, #1
	bgt _0808EB38
	cmp r0, #0
	beq _0808EB3E
	b _0808EBAA
_0808EB38:
	cmp r0, #2
	beq _0808EB90
	b _0808EBAA
_0808EB3E:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EB84 @ =0x08369388
	bl SetDDP
	movs r0, #0x20
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EB5C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, _0808EB88 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	ldr r1, _0808EB8C @ =0x00003FFF
	cmp r0, r1
	bhi _0808EBAA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_0800a134
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EBAA
	.align 2, 0
_0808EB84: .4byte 0x08369388
_0808EB88: .4byte gStageRun+232
_0808EB8C: .4byte 0x00003FFF
_0808EB90:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808EBAA
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EBAA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ebb0
FUN_0808ebb0: @ 0x0808EBB0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808ebb4
FUN_0808ebb4: @ 0x0808EBB4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _0808EBC0
	b _0808EFEE
_0808EBC0:
	lsls r0, r0, #2
	ldr r1, _0808EBCC @ =_0808EBD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808EBCC: .4byte _0808EBD0
_0808EBD0: @ jump table
	.4byte _0808EBE8 @ case 0
	.4byte _0808EC98 @ case 1
	.4byte _0808EF6E @ case 2
	.4byte _0808EF8A @ case 3
	.4byte _0808EFA4 @ case 4
	.4byte _0808EFAA @ case 5
_0808EBE8:
	ldr r1, _0808EC1C @ =0x00007501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808EC20 @ =0x08369388
	bl SetDDP
	ldr r0, _0808EC24 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EC40
	ldr r3, _0808EC28 @ =0xFFFFD000
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EC30
	ldr r0, _0808EC2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC38
	b _0808EC6C
	.align 2, 0
_0808EC1C: .4byte 0x00007501
_0808EC20: .4byte 0x08369388
_0808EC24: .4byte pZero2
_0808EC28: .4byte 0xFFFFD000
_0808EC2C: .4byte 0x00002FFF
_0808EC30:
	subs r1, r1, r0
	ldr r0, _0808EC3C @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC38:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC3C: .4byte 0x00002FFF
_0808EC40:
	movs r3, #0xc0
	lsls r3, r3, #6
	adds r0, r0, r3
	str r0, [r4, #0x64]
	ldr r0, [r2, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EC5C
	ldr r0, _0808EC58 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EC64
	b _0808EC6C
	.align 2, 0
_0808EC58: .4byte 0x00002FFF
_0808EC5C:
	subs r1, r0, r1
	ldr r0, _0808EC68 @ =0x00002FFF
	cmp r1, r0
	ble _0808EC6C
_0808EC64:
	movs r0, #0
	b _0808EC6E
	.align 2, 0
_0808EC68: .4byte 0x00002FFF
_0808EC6C:
	movs r0, #1
_0808EC6E:
	strb r0, [r4, #0xf]
	ldr r2, _0808ECC8 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0808ECCC @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0808ECD0 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0x3c
	movs r1, #0
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EC98:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808ECA0
	b _0808EDB8
_0808ECA0:
	ldr r5, _0808ECD4 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808ED3C
	movs r2, #0xa0
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r1, [r4, #0x58]
	movs r3, #0xa0
	lsls r3, r3, #4
	adds r1, r1, r3
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ECD8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ECC8: .4byte RNG_0202f388
_0808ECCC: .4byte 0x000343FD
_0808ECD0: .4byte 0x00269EC3
_0808ECD4: .4byte pZero2
_0808ECD8:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED02
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808ED02:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808ED1C
	ldr r0, _0808ED18 @ =0x00002FFF
	cmp r2, r0
	ble _0808ED26
	b _0808EECC
	.align 2, 0
_0808ED18: .4byte 0x00002FFF
_0808ED1C:
	subs r1, r1, r0
	ldr r0, _0808ED30 @ =0x00002FFF
	cmp r1, r0
	ble _0808ED26
	b _0808EECC
_0808ED26:
	ldr r0, _0808ED34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808ED38 @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808ED30: .4byte 0x00002FFF
_0808ED34: .4byte pZero2
_0808ED38: .4byte 0xFFFFD000
_0808ED3C:
	ldr r3, _0808ED58 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808ED5C
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED58: .4byte 0xFFFFEC00
_0808ED5C:
	ldr r0, [r4, #0x54]
	ldr r3, _0808ED84 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808ED88 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808ED8C
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808ED84: .4byte 0xFFFFFD00
_0808ED88: .4byte 0xFFFFE900
_0808ED8C:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EDA8
	ldr r0, _0808EDA4 @ =0x00002FFF
	cmp r2, r0
	bgt _0808EDA0
	b _0808EEB8
_0808EDA0:
	b _0808EECC
	.align 2, 0
_0808EDA4: .4byte 0x00002FFF
_0808EDA8:
	subs r1, r0, r1
	ldr r0, _0808EDB4 @ =0x00002FFF
	cmp r1, r0
	ble _0808EDB2
	b _0808EECC
_0808EDB2:
	b _0808EEB8
	.align 2, 0
_0808EDB4: .4byte 0x00002FFF
_0808EDB8:
	ldr r5, _0808EDE0 @ =pZero2
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	cmp r0, r1
	ble _0808EE50
	ldr r3, _0808EDE4 @ =0xFFFFEC00
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EDE8
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EDE0: .4byte pZero2
_0808EDE4: .4byte 0xFFFFEC00
_0808EDE8:
	ldr r0, [r4, #0x54]
	ldr r3, _0808EE10 @ =0xFFFFFD00
	adds r1, r0, r3
	str r1, [r4, #0x54]
	ldr r1, _0808EE14 @ =0xFFFFE900
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE18
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
	.align 2, 0
_0808EE10: .4byte 0xFFFFFD00
_0808EE14: .4byte 0xFFFFE900
_0808EE18:
	ldr r0, [r5]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r1, r0
	cmp r2, #0
	ble _0808EE30
	ldr r0, _0808EE2C @ =0x00002FFF
	cmp r2, r0
	bgt _0808EE38
	b _0808EECC
	.align 2, 0
_0808EE2C: .4byte 0x00002FFF
_0808EE30:
	subs r1, r0, r1
	ldr r0, _0808EE44 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EE38:
	ldr r0, _0808EE48 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, _0808EE4C @ =0xFFFFD000
	b _0808EEC2
	.align 2, 0
_0808EE44: .4byte 0x00002FFF
_0808EE48: .4byte pZero2
_0808EE4C: .4byte 0xFFFFD000
_0808EE50:
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r0, r1, r3
	ldr r1, [r4, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_0800a134
	ldr r2, [r4, #0x58]
	cmp r0, r2
	bge _0808EE6C
	movs r0, #3
	b _0808EECA
_0808EE6C:
	ldr r0, [r4, #0x54]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	str r1, [r4, #0x54]
	movs r1, #0xb8
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0808EE96
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	movs r0, #3
	b _0808EECA
_0808EE96:
	ldr r0, [r5]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0808EEB0
	ldr r0, _0808EEAC @ =0x00002FFF
	cmp r2, r0
	bgt _0808EEB8
	b _0808EECC
	.align 2, 0
_0808EEAC: .4byte 0x00002FFF
_0808EEB0:
	subs r1, r1, r0
	ldr r0, _0808EEE8 @ =0x00002FFF
	cmp r1, r0
	ble _0808EECC
_0808EEB8:
	ldr r0, _0808EEEC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #6
_0808EEC2:
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0xe]
	adds r0, #1
_0808EECA:
	strb r0, [r4, #0xe]
_0808EECC:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r4, #0x54]
	ldr r1, [r0]
	subs r2, r3, r1
	adds r5, r0, #0
	cmp r2, #0
	ble _0808EEF0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _0808EEFA
	b _0808EF48
	.align 2, 0
_0808EEE8: .4byte 0x00002FFF
_0808EEEC: .4byte pZero2
_0808EEF0:
	subs r1, r1, r3
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _0808EF48
_0808EEFA:
	ldr r0, [r4, #0x54]
	ldr r1, [r5]
	cmp r0, r1
	ble _0808EF0A
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r1, r3
	b _0808EF0E
_0808EF0A:
	ldr r2, _0808EF28 @ =0xFFFF6000
	adds r0, r1, r2
_0808EF0E:
	str r0, [r4, #0x54]
	ldr r0, _0808EF2C @ =pZero2
	ldr r0, [r0]
	ldr r3, [r4, #0x54]
	ldr r1, [r0, #0x54]
	subs r2, r3, r1
	cmp r2, #0
	ble _0808EF34
	ldr r0, _0808EF30 @ =0x00002FFF
	cmp r2, r0
	ble _0808EF3C
	b _0808EF44
	.align 2, 0
_0808EF28: .4byte 0xFFFF6000
_0808EF2C: .4byte pZero2
_0808EF30: .4byte 0x00002FFF
_0808EF34:
	subs r1, r1, r3
	ldr r0, _0808EF40 @ =0x00002FFF
	cmp r1, r0
	bgt _0808EF44
_0808EF3C:
	movs r0, #2
	b _0808EF46
	.align 2, 0
_0808EF40: .4byte 0x00002FFF
_0808EF44:
	movs r0, #3
_0808EF46:
	strb r0, [r4, #0xe]
_0808EF48:
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bne _0808EF66
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0808EF66
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
_0808EF66:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808EFEE
_0808EF6E:
	adds r5, r4, #0
	adds r5, #0x71
	movs r1, #0
	ldrsb r1, [r5, r1]
	cmp r1, #0
	beq _0808EFE8
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #7
	bne _0808EFEE
	b _0808EFE6
_0808EF8A:
	ldr r1, _0808EFA0 @ =0x0000750B
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808EFEE
	.align 2, 0
_0808EFA0: .4byte 0x0000750B
_0808EFA4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808EFAA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r0]
	movs r3, #0xa0
	lsls r3, r3, #8
	adds r0, r2, r3
	ldr r1, [r4, #0x54]
	cmp r1, r0
	bne _0808EFD8
	ldr r0, _0808EFD4 @ =pZero2
	ldr r0, [r0]
	movs r3, #0xd0
	lsls r3, r3, #8
	adds r1, r2, r3
	ldr r0, [r0, #0x54]
	cmp r0, r1
	bge _0808EFEE
	b _0808EFE6
	.align 2, 0
_0808EFD4: .4byte pZero2
_0808EFD8:
	ldr r0, _0808EFF4 @ =pZero2
	ldr r0, [r0]
	ldr r2, _0808EFF8 @ =0xFFFFD000
	adds r1, r1, r2
	ldr r0, [r0, #0x54]
	cmp r0, r1
	ble _0808EFEE
_0808EFE6:
	movs r1, #0
_0808EFE8:
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808EFEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EFF4: .4byte pZero2
_0808EFF8: .4byte 0xFFFFD000

	thumb_func_start FUN_0808effc
FUN_0808effc: @ 0x0808EFFC
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f000
FUN_0808f000: @ 0x0808F000
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _0808F00E
	b _0808F14E
_0808F00E:
	lsls r0, r0, #2
	ldr r1, _0808F018 @ =_0808F01C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808F018: .4byte _0808F01C
_0808F01C: @ jump table
	.4byte _0808F04C @ case 0
	.4byte _0808F12C @ case 1
	.4byte _0808F05A @ case 2
	.4byte _0808F068 @ case 3
	.4byte _0808F080 @ case 4
	.4byte _0808F092 @ case 5
	.4byte _0808F0C4 @ case 6
	.4byte _0808F0F4 @ case 7
	.4byte _0808F102 @ case 8
	.4byte _0808F118 @ case 9
	.4byte _0808F12C @ case 10
	.4byte _0808F146 @ case 11
_0808F04C:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	b _0808F124
_0808F05A:
	ldr r1, _0808F07C @ =0x00007502
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F068:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F07C: .4byte 0x00007502
_0808F080:
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb9
	strb r1, [r0]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F092:
	ldr r1, _0808F0EC @ =0x00007503
	adds r0, r4, #0
	bl SetMotion
	movs r0, #6
	strb r0, [r4, #0x13]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0xd0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	mov r2, sp
	movs r3, #0
	bl FUN_080aed8c
	ldr r0, _0808F0F0 @ =0x00000145
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F0C4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	movs r1, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ands r0, r1
	cmp r0, #0
	beq _0808F13E
	movs r0, #5
	strb r0, [r4, #0xe]
	b _0808F14E
	.align 2, 0
_0808F0EC: .4byte 0x00007503
_0808F0F0: .4byte 0x00000145
_0808F0F4:
	ldr r1, _0808F114 @ =0x00007504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F102:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808F14E
	b _0808F13E
	.align 2, 0
_0808F114: .4byte 0x00007504
_0808F118:
	movs r1, #0xea
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x20
_0808F124:
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F12C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F14E
_0808F13E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808F14E
_0808F146:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808F14E:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f158
FUN_0808f158: @ 0x0808F158
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f15c
FUN_0808f15c: @ 0x0808F15C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F176
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F194 @ =0x083693A0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F176:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0808F18C
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F18C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F194: .4byte 0x083693A0

	thumb_func_start FUN_0808f198
FUN_0808f198: @ 0x0808F198
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f19c
FUN_0808f19c: @ 0x0808F19C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808f1a0
FUN_0808f1a0: @ 0x0808F1A0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0808f1a4
FUN_0808f1a4: @ 0x0808F1A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F1BE
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F1DC @ =0x083693A0
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F1BE:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0808F1D4
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F1D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F1DC: .4byte 0x083693A0

	thumb_func_start FUN_0808f1e0
FUN_0808f1e0: @ 0x0808F1E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0808F22A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F22A
	ldr r2, _0808F21C @ =0x083693B8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808F22A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0808F220
	movs r0, #3
	b _0808F226
	.align 2, 0
_0808F21C: .4byte 0x083693B8
_0808F220:
	cmp r1, #0x30
	bne _0808F22A
	movs r0, #5
_0808F226:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808F22A:
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808f234
FUN_0808f234: @ 0x0808F234
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, [r2, #0xc]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #3
	beq _0808F24C
	cmp r0, #0xe
	beq _0808F24C
	cmp r0, #0xf
	bne _0808F276
_0808F24C:
	ldr r2, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F276
	ldr r1, [r2, #0x54]
	ldr r0, [r3]
	cmp r1, r0
	bge _0808F26E
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xff
	b _0808F274
_0808F26E:
	adds r1, r2, #0
	adds r1, #0xbb
	movs r0, #0xfe
_0808F274:
	strb r0, [r1]
_0808F276:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f27c
FUN_0808f27c: @ 0x0808F27C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0808F2DC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0808F2D2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808F2E0 @ =gEnemyFnTable
	movs r1, #0x39
	strb r1, [r3, #9]
	adds r0, #0xe4
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
	movs r0, #1
	strb r0, [r3, #0x10]
	str r4, [r3, #0x64]
	str r4, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r5, [r3, #0x12]
	str r7, [r3, #0x28]
_0808F2D2:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808F2DC: .4byte gZakoHeaderPtr
_0808F2E0: .4byte gEnemyFnTable

	thumb_func_start FUN_0808f2e4
FUN_0808f2e4: @ 0x0808F2E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0808F33C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _0808F334
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808F340 @ =gEnemyFnTable
	movs r1, #0x39
	strb r1, [r3, #9]
	adds r0, #0xe4
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
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
_0808F334:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F33C: .4byte gZakoHeaderPtr
_0808F340: .4byte gEnemyFnTable
_0808F344:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0808f348
FUN_0808f348: @ 0x0808F348
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F3A2
	ldr r1, _0808F390 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldrb r0, [r2, #0x10]
	cmp r0, #2
	beq _0808F394
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	beq _0808F394
	adds r0, r2, #0
	adds r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #9
	bls _0808F394
	movs r0, #1
	b _0808F396
	.align 2, 0
_0808F390: .4byte gEnemyFnTable
_0808F394:
	movs r0, #0
_0808F396:
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl killSeimeran
	movs r0, #1
	b _0808F3A4
_0808F3A2:
	movs r0, #0
_0808F3A4:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808f3a8
FUN_0808f3a8: @ 0x0808F3A8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808F41C
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _0808F41C
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0808F3C8
	cmp r0, #1
	beq _0808F40C
	b _0808F41C
_0808F3C8:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808F41C
	ldr r1, _0808F404 @ =0x083693D4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808F408 @ =0x083693F4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #1
	b _0808F41E
	.align 2, 0
_0808F404: .4byte 0x083693D4
_0808F408: .4byte 0x083693F4
_0808F40C:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0808F41A
	movs r0, #1
	b _0808F41E
_0808F41A:
	strb r0, [r4, #0xf]
_0808F41C:
	movs r0, #0
_0808F41E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808f424
FUN_0808f424: @ 0x0808F424
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r5, [r6]
	cmp r5, #0
	bne _0808F464
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808F464
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0808F464
	cmp r0, #6
	beq _0808F464
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F464
	ldr r2, _0808F46C @ =0x08369594
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0808F464
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0808F464:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F46C: .4byte 0x08369594

	thumb_func_start initSeimeran
initSeimeran: @ 0x0808F470
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0808F4C4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0808F4C8 @ =0x0836959C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _0808F4D0
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0808F4CC @ =0x0836941C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	b _0808F4E6
	.align 2, 0
_0808F4C4: .4byte gEnemyFnTable
_0808F4C8: .4byte 0x0836959C
_0808F4CC: .4byte 0x0836941C
_0808F4D0:
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0808F528 @ =0x0836941C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
_0808F4E6:
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, _0808F52C @ =0x0808F345
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	movs r4, #0
	str r4, [r0]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0808F514
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0xb8
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
_0808F514:
	adds r0, r5, #0
	adds r0, #0xc0
	strb r4, [r0]
	adds r0, r5, #0
	bl seimeranAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F528: .4byte 0x0836941C
_0808F52C: .4byte 0x0808F345

	thumb_func_start seimeranAI
seimeranAI: @ 0x0808F530
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808F564 @ =gCurStory
	ldrb r3, [r0, #8]
	movs r0, #2
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0808F568
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _0808F68E
	.align 2, 0
_0808F564: .4byte gCurStory
_0808F568:
	ldrb r1, [r4, #0x10]
	cmp r1, #0
	bne _0808F5C8
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	cmp r0, #0
	beq _0808F580
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808F580
	str r1, [r2]
_0808F580:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	cmp r0, #0
	beq _0808F594
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0808F594
	movs r0, #0
	str r0, [r1]
_0808F594:
	ldr r0, _0808F5C4 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808F61C
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _0808F68E
	.align 2, 0
_0808F5C4: .4byte gStageRun+232
_0808F5C8:
	movs r0, #0x40
	ands r0, r3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0808F5F0
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	b _0808F68E
_0808F5F0:
	cmp r1, #1
	bne _0808F61C
	ldr r5, [r4, #0x28]
	cmp r5, #0
	bne _0808F614
	ldr r0, _0808F610 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #5
	cmp r0, r1
	bls _0808F61C
	b _0808F674
	.align 2, 0
_0808F610: .4byte gStageRun+232
_0808F614:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _0808F61C
	str r3, [r4, #0x28]
_0808F61C:
	adds r0, r4, #0
	bl FUN_0808f348
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F6A8
	adds r0, r4, #0
	bl FUN_0808f424
	adds r0, r4, #0
	bl FUN_0808f3a8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0808F6A8
	ldr r1, _0808F6B0 @ =0x083693D4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0808F6B4 @ =0x083693F4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _0808F6A8
	ldr r0, _0808F6B8 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _0808F6A8
_0808F674:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
_0808F68E:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0808F6BC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0808F6A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F6B0: .4byte 0x083693D4
_0808F6B4: .4byte 0x083693F4
_0808F6B8: .4byte gStageRun+232
_0808F6BC: .4byte gEnemyFnTable

	thumb_func_start killSeimeran
killSeimeran: @ 0x0808F6C0
	push {lr}
	adds r3, r0, #0
	ldr r0, _0808F708 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808F710
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0808F70C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _0808F720
	.align 2, 0
_0808F708: .4byte gCurStory
_0808F70C: .4byte gEnemyFnTable
_0808F710:
	ldr r0, _0808F724 @ =0x08369414
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_0808F720:
	pop {r0}
	bx r0
	.align 2, 0
_0808F724: .4byte 0x08369414

	thumb_func_start FUN_0808f728
FUN_0808f728: @ 0x0808F728
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808f72c
FUN_0808f72c: @ 0x0808F72C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0808F742
	bl isKilled
	cmp r0, #0
	beq _0808F7A4
_0808F742:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xc
	bne _0808F760
	subs r0, #0x4c
	ldr r1, _0808F75C @ =0x08369524
	bl SetDDP
	b _0808F77A
	.align 2, 0
_0808F75C: .4byte 0x08369524
_0808F760:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F794 @ =0x08369584
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F798 @ =0x0836941C
	adds r1, r1, r2
	bl SetDDP
_0808F77A:
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _0808F7A4
	ldrb r0, [r5]
	cmp r0, #0xc
	bne _0808F79C
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _0808F7A4
	.align 2, 0
_0808F794: .4byte 0x08369584
_0808F798: .4byte 0x0836941C
_0808F79C:
	movs r0, #1
	strb r0, [r4, #0xd]
	movs r0, #3
	strb r0, [r4, #0xe]
_0808F7A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f7ac
FUN_0808f7ac: @ 0x0808F7AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0808F812
	adds r5, r4, #0
	adds r5, #0xc0
	ldrb r0, [r5]
	cmp r0, #0xc
	bne _0808F7E0
	movs r1, #0xee
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F7DC @ =0x0836953C
	bl SetDDP
	b _0808F80C
	.align 2, 0
_0808F7DC: .4byte 0x0836953C
_0808F7E0:
	ldr r1, _0808F818 @ =0x00007701
	ldrb r2, [r5]
	adds r0, r4, #0
	movs r3, #3
	bl GotoMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F81C @ =0x08369584
	ldrb r1, [r5]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F820 @ =0x08369434
	adds r1, r1, r2
	bl SetDDP
_0808F80C:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F812:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F818: .4byte 0x00007701
_0808F81C: .4byte 0x08369584
_0808F820: .4byte 0x08369434

	thumb_func_start FUN_0808f824
FUN_0808f824: @ 0x0808F824
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808F85E
	cmp r0, #1
	bgt _0808F838
	cmp r0, #0
	beq _0808F842
	b _0808F8CC
_0808F838:
	cmp r0, #2
	beq _0808F880
	cmp r0, #3
	beq _0808F88E
	b _0808F8CC
_0808F842:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F878 @ =0x08369434
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r1, _0808F87C @ =0x00007707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F85E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808F870
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F870:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0808F8CC
	.align 2, 0
_0808F878: .4byte 0x08369434
_0808F87C: .4byte 0x00007707
_0808F880:
	ldr r1, _0808F8D4 @ =0x00007701
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F88E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _0808F8A4
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_0808F8A4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r2, _0808F8D8 @ =0x08369584
	adds r5, r4, #0
	adds r5, #0x71
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _0808F8DC @ =0x0836941C
	adds r1, r1, r2
	bl SetDDP
	ldrb r1, [r5]
	adds r0, r4, #0
	adds r0, #0xc0
	strb r1, [r0]
_0808F8CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F8D4: .4byte 0x00007701
_0808F8D8: .4byte 0x08369584
_0808F8DC: .4byte 0x0836941C

	thumb_func_start FUN_0808f8e0
FUN_0808f8e0: @ 0x0808F8E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808F8F0
	cmp r0, #1
	beq _0808F90E
	b _0808F928
_0808F8F0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808F930 @ =0x08369524
	bl SetDDP
	movs r0, #0xa0
	strb r0, [r4, #0x12]
	movs r1, #0xee
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808F90E:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808F922
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808F922:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808F928:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F930: .4byte 0x08369524

	thumb_func_start FUN_0808f934
FUN_0808f934: @ 0x0808F934
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _0808F96A
	cmp r0, #1
	bgt _0808F948
	cmp r0, #0
	beq _0808F952
	b _0808FA16
_0808F948:
	cmp r0, #2
	beq _0808F98C
	cmp r0, #3
	beq _0808F9FE
	b _0808FA16
_0808F952:
	ldr r0, _0808F984 @ =0x00000103
	bl PlaySound
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldr r1, _0808F988 @ =0x00007702
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F96A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808FA16
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0808FA16
	.align 2, 0
_0808F984: .4byte 0x00000103
_0808F988: .4byte 0x00007702
_0808F98C:
	adds r6, r5, #0
	adds r6, #0xb8
	ldr r0, [r6]
	cmp r0, #0
	bne _0808F9D0
	adds r7, r5, #0
	adds r7, #0xbc
	ldr r0, [r7]
	cmp r0, #0
	bne _0808F9D0
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0808F9D0
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	ldr r4, _0808F9CC @ =0xFFFFE400
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0808f27c
	str r0, [r6]
	ldr r1, [r5, #0x54]
	ldr r2, [r5, #0x58]
	adds r2, r2, r4
	adds r0, r5, #0
	movs r3, #1
	bl FUN_0808f27c
	str r0, [r7]
	b _0808F9F0
	.align 2, 0
_0808F9CC: .4byte 0xFFFFE400
_0808F9D0:
	movs r0, #0x2d
	bl PlaySound
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r4, _0808FA1C @ =0xFFFFE400
	adds r1, r1, r4
	movs r2, #0
	bl FUN_0808f2e4
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	movs r2, #1
	bl FUN_0808f2e4
_0808F9F0:
	ldr r1, _0808FA20 @ =0x00007703
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808F9FE:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FA16
	movs r1, #0
	movs r0, #4
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_0808FA16:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FA1C: .4byte 0xFFFFE400
_0808FA20: .4byte 0x00007703

	thumb_func_start FUN_0808fa24
FUN_0808fa24: @ 0x0808FA24
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FA34
	cmp r0, #1
	beq _0808FA48
	b _0808FA60
_0808FA34:
	ldr r0, _0808FA68 @ =0x00000103
	bl PlaySound
	ldr r1, _0808FA6C @ =0x00007704
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FA48:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FA60
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FA60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FA68: .4byte 0x00000103
_0808FA6C: .4byte 0x00007704

	thumb_func_start FUN_0808fa70
FUN_0808fa70: @ 0x0808FA70
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FA80
	cmp r0, #1
	beq _0808FAE0
	b _0808FB06
_0808FA80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808FA98 @ =0x08369434
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0808FA9C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FAA2
	.align 2, 0
_0808FA98: .4byte 0x08369434
_0808FA9C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FAA2:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	bl Sqrt
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _0808FB0C @ =0x00007707
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FAE0:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0808FAF4
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FAF4:
	ldr r1, [r4, #0x60]
	adds r1, #0x40
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808FB06:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FB0C: .4byte 0x00007707

	thumb_func_start FUN_0808fb10
FUN_0808fb10: @ 0x0808FB10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0808FB46
	cmp r0, #1
	bgt _0808FB24
	cmp r0, #0
	beq _0808FB2E
	b _0808FB7C
_0808FB24:
	cmp r0, #2
	beq _0808FB68
	cmp r0, #3
	beq _0808FB76
	b _0808FB7C
_0808FB2E:
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #9
	ldr r1, _0808FB60 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, _0808FB64 @ =0x00007708
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FB46:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0808FB7C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0808FB7C
	.align 2, 0
_0808FB60: .4byte 0xFFFFFF00
_0808FB64: .4byte 0x00007708
_0808FB68:
	ldr r1, _0808FB9C @ =0x00007709
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FB76:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0808FB7C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0808FBA0
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808FBB6
	b _0808FBB0
	.align 2, 0
_0808FB9C: .4byte 0x00007709
_0808FBA0:
	ldr r1, _0808FC08 @ =0xFFFFFA00
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _0808FBB6
_0808FBB0:
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0808FBB6:
	ldr r0, [r4, #0x60]
	adds r0, #0x15
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808FBC6
	str r1, [r4, #0x60]
_0808FBC6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808FBE8
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0808FBE8:
	ldr r2, [r4, #0x64]
	ldr r3, _0808FC0C @ =0xFFFFD400
	adds r0, r2, r3
	ldr r1, [r4, #0x54]
	cmp r1, r0
	blt _0808FBFE
	movs r3, #0xb0
	lsls r3, r3, #6
	adds r0, r2, r3
	cmp r1, r0
	ble _0808FC00
_0808FBFE:
	str r0, [r4, #0x54]
_0808FC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FC08: .4byte 0xFFFFFA00
_0808FC0C: .4byte 0xFFFFD400

	thumb_func_start FUN_0808fc10
FUN_0808fc10: @ 0x0808FC10
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808FC20
	cmp r0, #1
	beq _0808FC8E
	b _0808FCD8
_0808FC20:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808FC38 @ =0x08369554
	bl SetDDP
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0808FC3C
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FC42
	.align 2, 0
_0808FC38: .4byte 0x08369554
_0808FC3C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FC42:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r1, _0808FCE0 @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #2
	bl Sqrt
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #6
	rsbs r0, r0, #0
	str r0, [r4, #0x60]
	ldr r1, _0808FCE4 @ =0x0000770B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808FC8E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r2, #0xe0
	lsls r2, r2, #3
	cmp r0, r2
	ble _0808FCAC
	str r2, [r4, #0x60]
_0808FCAC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0808FCD8
	ldr r1, _0808FCE8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
_0808FCD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FCE0: .4byte 0xFFFFFE80
_0808FCE4: .4byte 0x0000770B
_0808FCE8: .4byte gEnemyFnTable

	thumb_func_start maybeKillSeimeran
maybeKillSeimeran: @ 0x0808FCEC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r1, [r4, #0x58]
	str r1, [sp, #4]
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808FD20
	ldr r2, _0808FD58 @ =0xFFFFF000
	adds r0, r1, r2
	str r0, [sp, #4]
_0808FD20:
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _0808FD64
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0808FD5C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0808FD60 @ =0x0000270E
	cmp r1, r0
	bhi _0808FD4E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0808FD4E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	b _0808FD6A
	.align 2, 0
_0808FD58: .4byte 0xFFFFF000
_0808FD5C: .4byte gMission
_0808FD60: .4byte 0x0000270E
_0808FD64:
	movs r0, #0x35
	bl PlaySound
_0808FD6A:
	ldr r1, _0808FD84 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808FD84: .4byte gEnemyFnTable

	thumb_func_start FUN_0808fd88
FUN_0808fd88: @ 0x0808FD88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0808FD9A
	cmp r0, #1
	beq _0808FE4C
	b _0808FE64
_0808FD9A:
	movs r3, #0
	ldr r0, _0808FDBC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0808FDAC
	movs r3, #1
_0808FDAC:
	adds r6, r3, #0
	adds r2, r6, #0
	cmp r6, #0
	beq _0808FDC0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0808FDC6
	.align 2, 0
_0808FDBC: .4byte pZero2
_0808FDC0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0808FDC6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r6, #8
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0808FE6C @ =0x00007706
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _0808FE70 @ =0x083695A0
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0808FE4C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808FE64
	adds r0, r5, #0
	bl maybeKillSeimeran
_0808FE64:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE6C: .4byte 0x00007706
_0808FE70: .4byte 0x083695A0

	thumb_func_start FUN_0808fe74
FUN_0808fe74: @ 0x0808FE74
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0808FECC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0808FEC2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0808FED0 @ =gEnemyFnTable
	movs r1, #0x3a
	strb r1, [r3, #9]
	adds r0, #0xe8
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_0808FEC2:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808FECC: .4byte gZakoHeaderPtr
_0808FED0: .4byte gEnemyFnTable

	thumb_func_start initPetatria
initPetatria: @ 0x0808FED4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r3, #0
	movs r2, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0808FF14 @ =nop_0809127c
	adds r0, r6, #0
	adds r0, #0x74
	str r1, [r0, #0x24]
	adds r0, #0x4c
	str r2, [r0]
	subs r0, #7
	strb r2, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0808FF50
	ldr r0, _0808FF18 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r6, #0x54]
	cmp r2, r0
	ble _0808FF1C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FF1E
	.align 2, 0
_0808FF14: .4byte nop_0809127c
_0808FF18: .4byte pZero2
_0808FF1C:
	movs r0, #0xcc
_0808FF1E:
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x58]
	adds r0, r2, #0
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0808FF4C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r2, [r6, #0xd]
	strb r2, [r6, #0xe]
	strb r2, [r6, #0xf]
	b _0808FFE6
	.align 2, 0
_0808FF4C: .4byte gEnemyFnTable
_0808FF50:
	cmp r0, #0
	bne _0808FF74
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x54]
	ldr r1, _0808FF6C @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a22c
	ldr r1, _0808FF70 @ =0xFFFFE000
	b _0808FFAE
	.align 2, 0
_0808FF6C: .4byte 0xFFFFF600
_0808FF70: .4byte 0xFFFFE000
_0808FF74:
	adds r0, r6, #0
	adds r0, #0xb8
	strb r2, [r0]
	movs r2, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r6, #0x58]
	bl FUN_0800a31c
	movs r1, #0x80
	lsls r1, r1, #6
_0808FFAE:
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, _0808FFC4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r6, #0x58]
	ldr r0, [r0, #0x58]
	cmp r1, r0
	ble _0808FFC8
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _0808FFCA
	.align 2, 0
_0808FFC4: .4byte pZero2
_0808FFC8:
	movs r0, #0xcc
_0808FFCA:
	str r0, [r6, #0x60]
	ldr r1, _0809000C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
_0808FFE6:
	adds r0, r6, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	beq _08090060
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _08090014
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090010 @ =0x08369608
	b _08090024
	.align 2, 0
_0809000C: .4byte gEnemyFnTable
_08090010: .4byte 0x08369608
_08090014:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090048 @ =0x08369638
_08090024:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809004C
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r6, #0
	bl SetMotion
	b _08090054
	.align 2, 0
_08090048: .4byte 0x08369638
_0809004C:
	ldr r1, _0809005C @ =0x00007E06
	adds r0, r6, #0
	bl SetMotion
_08090054:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0809009A
	.align 2, 0
_0809005C: .4byte 0x00007E06
_08090060:
	ldrb r0, [r6, #0x10]
	cmp r0, #2
	bne _0809007C
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08090078 @ =0x08369608
	b _0809008A
	.align 2, 0
_08090078: .4byte 0x08369608
_0809007C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080900A8 @ =0x08369638
_0809008A:
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
_0809009A:
	adds r0, r6, #0
	bl petatriaAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080900A8: .4byte 0x08369638

	thumb_func_start petatriaAI
petatriaAI: @ 0x080900AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080900DC
	ldr r1, _080900D8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl killPetatria
	b _08090122
	.align 2, 0
_080900D8: .4byte gEnemyFnTable
_080900DC:
	ldr r0, _08090128 @ =0x083695B8
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08091188
	adds r0, r4, #0
	bl isFrozen
	adds r6, r0, #0
	cmp r6, #0
	bne _08090122
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	beq _08090112
	bl isKilled
	cmp r0, #0
	beq _08090122
	str r6, [r5]
_08090112:
	ldr r0, _0809012C @ =0x083695E0
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08090122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090128: .4byte 0x083695B8
_0809012C: .4byte 0x083695E0

	thumb_func_start killPetatria
killPetatria: @ 0x08090130
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0809017C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08090184
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
	ldr r1, _08090180 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _08090270
	.align 2, 0
_0809017C: .4byte gCurStory
_08090180: .4byte gEnemyFnTable
_08090184:
	ldrb r2, [r7, #0xe]
	cmp r2, #1
	beq _080901BC
	cmp r2, #1
	bgt _08090194
	cmp r2, #0
	beq _0809019E
	b _08090272
_08090194:
	cmp r2, #0xa
	beq _080901BC
	cmp r2, #0xb
	beq _080901C4
	b _08090272
_0809019E:
	movs r0, #0xa
	strb r0, [r7, #0xe]
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
	str r2, [r7, #0x60]
	str r2, [r7, #0x5c]
_080901BC:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _08090272
_080901C4:
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
	movs r0, #4
	mov r1, r8
	bl TryDropItem
	ldr r2, _08090280 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090284 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r1, _08090288 @ =0x00269EC3
	adds r4, r4, r1
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	ldr r1, _0809028C @ =0xFFFFF400
	adds r0, r0, r1
	add r6, sp, #8
	str r0, [r6, #4]
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	movs r5, #1
	ands r1, r5
	ldr r2, _08090290 @ =0x00007E1A
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090294 @ =0x00007E1B
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #4
	ands r1, r5
	ldr r2, _08090298 @ =0x00007E1C
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_080c4914
	ldr r2, _0809029C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080902A0 @ =0x0000270E
	cmp r1, r0
	bhi _08090250
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08090250:
	adds r0, r7, #0
	mov r1, r8
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080902A4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_08090270:
	str r0, [r7, #0x14]
_08090272:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090280: .4byte RNG_0202f388
_08090284: .4byte 0x000343FD
_08090288: .4byte 0x00269EC3
_0809028C: .4byte 0xFFFFF400
_08090290: .4byte 0x00007E1A
_08090294: .4byte 0x00007E1B
_08090298: .4byte 0x00007E1C
_0809029C: .4byte gMission
_080902A0: .4byte 0x0000270E
_080902A4: .4byte gEnemyFnTable

	thumb_func_start FUN_080902a8
FUN_080902a8: @ 0x080902A8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080902C0
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080902C0:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080902c8
FUN_080902c8: @ 0x080902C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x17
	bls _080902D4
	b _080906E0
_080902D4:
	lsls r0, r0, #2
	ldr r1, _080902E0 @ =_080902E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080902E0: .4byte _080902E4
_080902E4: @ jump table
	.4byte _08090344 @ case 0
	.4byte _0809039A @ case 1
	.4byte _080903AE @ case 2
	.4byte _08090490 @ case 3
	.4byte _080904D8 @ case 4
	.4byte _0809051C @ case 5
	.4byte _080906E0 @ case 6
	.4byte _080906E0 @ case 7
	.4byte _080906E0 @ case 8
	.4byte _080906E0 @ case 9
	.4byte _080906E0 @ case 10
	.4byte _080906E0 @ case 11
	.4byte _080906E0 @ case 12
	.4byte _080906E0 @ case 13
	.4byte _080906E0 @ case 14
	.4byte _080906E0 @ case 15
	.4byte _080906E0 @ case 16
	.4byte _080906E0 @ case 17
	.4byte _080906E0 @ case 18
	.4byte _080906E0 @ case 19
	.4byte _08090548 @ case 20
	.4byte _0809062C @ case 21
	.4byte _0809068C @ case 22
	.4byte _080906BC @ case 23
_08090344:
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
	adds r0, #0x74
	ldr r1, _080903A4 @ =0x08369608
	bl SetDDP
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x64]
	movs r1, #0xfc
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809039A:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _080903A8
	movs r0, #2
	b _080903AA
	.align 2, 0
_080903A4: .4byte 0x08369608
_080903A8:
	movs r0, #0x14
_080903AA:
	strb r0, [r5, #0xe]
	b _08090680
_080903AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _080903F4
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080903D4
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5, #0x13]
_080903D4:
	ldr r1, _08090478 @ =0x0836978C
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _0809047C @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_080903F4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _08090432
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090480 @ =0x08369728
	ldr r2, _08090484 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090488 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809048C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08090432
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_08090432:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _0809043A
	b _080906E0
_0809043A:
	ldr r0, [r5, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809045A
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809045A:
	ldr r0, [r5, #0x54]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	bne _08090472
	b _080906E0
_08090472:
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090604
	.align 2, 0
_08090478: .4byte 0x0836978C
_0809047C: .4byte 0x08369768
_08090480: .4byte 0x08369728
_08090484: .4byte RNG_0202f388
_08090488: .4byte 0x000343FD
_0809048C: .4byte 0x00269EC3
_08090490:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _080904D0 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bhi _080904A6
	b _08090646
_080904A6:
	ldr r0, _080904D4 @ =0x00007E05
	cmp r1, r0
	bne _080904AE
	b _08090646
_080904AE:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080904BA
	b _08090680
_080904BA:
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bhi _080904CA
	b _08090670
_080904CA:
	movs r0, #0
	b _0809066E
	.align 2, 0
_080904D0: .4byte 0xFFFF8200
_080904D4: .4byte 0x00007E05
_080904D8:
	movs r2, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
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
	ldr r1, _08090544 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809051C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _0809052E
	b _080906E0
_0809052E:
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	strb r1, [r5, #0xd]
	strb r2, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090544: .4byte 0x00007E0C
_08090548:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0xb9
	cmp r0, #3
	bne _0809058A
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08090560
	subs r0, #1
	b _08090568
_08090560:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #5
_08090568:
	strb r0, [r5, #0x13]
	ldr r1, _0809060C @ =0x08369774
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x64]
	ldr r0, [r0]
	subs r1, r1, r0
	str r1, [r5, #0x64]
	ldr r1, _08090610 @ =0x08369768
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
_0809058A:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x64]
	str r0, [r5, #0x54]
	ldrb r0, [r4]
	cmp r0, #3
	bls _080905C8
	movs r6, #0
	strb r6, [r4]
	ldr r3, _08090614 @ =0x08369728
	ldr r2, _08090618 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809061C @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090620 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080905C8
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r6, [r5, #0xe]
_080905C8:
	ldrb r0, [r5, #0xd]
	cmp r0, #2
	bne _080905D0
	b _080906E0
_080905D0:
	ldr r0, [r5, #0x54]
	ldr r2, _08090624 @ =0xFFFFE000
	adds r0, r0, r2
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	beq _080905EE
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080905EE:
	ldr r0, [r5, #0x54]
	ldr r1, _08090628 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r5, #0x58]
	cmp r1, r0
	beq _080906E0
	movs r0, #0xcc
_08090604:
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_0809060C: .4byte 0x08369774
_08090610: .4byte 0x08369768
_08090614: .4byte 0x08369728
_08090618: .4byte RNG_0202f388
_0809061C: .4byte 0x000343FD
_08090620: .4byte 0x00269EC3
_08090624: .4byte 0xFFFFE000
_08090628: .4byte 0xFFFFF000
_0809062C:
	ldrb r0, [r5, #0x1e]
	lsls r1, r0, #8
	adds r0, r5, #0
	adds r0, #0x70
	ldrb r0, [r0]
	orrs r1, r0
	ldr r2, _08090650 @ =0xFFFF8200
	adds r0, r1, r2
	cmp r0, #1
	bls _08090646
	ldr r0, _08090654 @ =0x00007E05
	cmp r1, r0
	bne _08090658
_08090646:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080906E0
	.align 2, 0
_08090650: .4byte 0xFFFF8200
_08090654: .4byte 0x00007E05
_08090658:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090680
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _0809066C
	subs r0, #1
	b _0809066E
_0809066C:
	movs r0, #5
_0809066E:
	strb r0, [r5, #0x13]
_08090670:
	ldr r0, _08090688 @ =0x08369768
	ldrb r1, [r5, #0x13]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_08090680:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080906E0
	.align 2, 0
_08090688: .4byte 0x08369768
_0809068C:
	movs r2, #1
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
	ldr r1, _080906E8 @ =0x00007E0C
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080906BC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080906E0
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcc
	rsbs r0, r0, #0
	str r0, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080906E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080906E8: .4byte 0x00007E0C

	thumb_func_start FUN_080906ec
FUN_080906ec: @ 0x080906EC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08090704
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08090704:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_0809070C:
	.byte 0x70, 0xB5, 0x04, 0x1C
	.byte 0xA0, 0x7B, 0x17, 0x28, 0x00, 0xD9, 0x00, 0xE2, 0x80, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68
	.byte 0x87, 0x46, 0x00, 0x00, 0x28, 0x07, 0x09, 0x08, 0x88, 0x07, 0x09, 0x08, 0xA8, 0x07, 0x09, 0x08
	.byte 0xC6, 0x07, 0x09, 0x08, 0xCC, 0x08, 0x09, 0x08, 0x22, 0x09, 0x09, 0x08, 0x30, 0x09, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08
	.byte 0x1A, 0x0B, 0x09, 0x08, 0x1A, 0x0B, 0x09, 0x08, 0x58, 0x09, 0x09, 0x08, 0x74, 0x0A, 0x09, 0x08
	.byte 0xDC, 0x0A, 0x09, 0x08, 0xEA, 0x0A, 0x09, 0x08, 0x20, 0x1C, 0x74, 0x30, 0x09, 0x49, 0x76, 0xF7
	.byte 0x41, 0xFD, 0x00, 0x20, 0xE0, 0x74, 0xA0, 0x6D, 0xA0, 0x66, 0x07, 0x49, 0x20, 0x1C, 0x86, 0xF7
	.byte 0xE3, 0xFE, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x6E, 0x00, 0x28, 0x06, 0xDD, 0x02, 0x20
	.byte 0x05, 0xE0, 0x00, 0x00, 0x38, 0x96, 0x36, 0x08, 0x06, 0x7E, 0x00, 0x00, 0x14, 0x20, 0xA0, 0x73
	.byte 0x20, 0x1C, 0x86, 0xF7, 0x4B, 0xFF, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x25, 0x1C, 0xB9, 0x35
	.byte 0x03, 0x28, 0x19, 0xD1, 0xE0, 0x7C, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x38, 0x03, 0xE0, 0x28, 0x78
	.byte 0x01, 0x30, 0x28, 0x70, 0x05, 0x20, 0xE0, 0x74, 0x29, 0x49, 0xE0, 0x7C, 0x80, 0x00, 0x40, 0x18
	.byte 0xA1, 0x6E, 0x00, 0x68, 0x09, 0x1A, 0xA1, 0x66, 0x26, 0x49, 0xE0, 0x7C, 0x40, 0x00, 0x40, 0x18
	.byte 0x01, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0xB0, 0xFE, 0x20, 0x1C, 0x86, 0xF7, 0x27, 0xFF, 0xA0, 0x6E
	.byte 0xA0, 0x65, 0x28, 0x78, 0x03, 0x28, 0x16, 0xD9, 0x00, 0x26, 0x2E, 0x70, 0x1E, 0x4B, 0x1F, 0x4A
	.byte 0x11, 0x68, 0x1F, 0x48, 0x48, 0x43, 0x1F, 0x49, 0x40, 0x18, 0x40, 0x00, 0x41, 0x08, 0x11, 0x60
	.byte 0x40, 0x0C, 0x0F, 0x21, 0x08, 0x40, 0x80, 0x00, 0xC0, 0x18, 0x00, 0x68, 0x00, 0x28, 0x02, 0xD0
	.byte 0x03, 0x20, 0x60, 0x73, 0xA6, 0x73, 0x60, 0x7B, 0x03, 0x28, 0x00, 0xD1, 0x65, 0xE1, 0x60, 0x6D
	.byte 0xA1, 0x6D, 0x79, 0xF7, 0x9D, 0xF8, 0x01, 0x1C, 0x00, 0x29, 0x05, 0xD0, 0xA0, 0x6D, 0x40, 0x18
	.byte 0xA0, 0x65, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0xB8, 0x30, 0x05, 0x78, 0x01, 0x2D
	.byte 0x1A, 0xD1, 0x60, 0x6D, 0xA1, 0x6D, 0x79, 0xF7, 0xD9, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x80, 0x22
	.byte 0x92, 0x01, 0x80, 0x18, 0x81, 0x42, 0x00, 0xD1, 0x47, 0xE1, 0xCC, 0x20, 0x40, 0x42, 0xCA, 0xE0
	.byte 0xB0, 0x97, 0x36, 0x08, 0xA4, 0x97, 0x36, 0x08, 0x28, 0x97, 0x36, 0x08, 0x88, 0xF3, 0x02, 0x02
	.byte 0xFD, 0x43, 0x03, 0x00, 0xC3, 0x9E, 0x26, 0x00, 0x60, 0x6D, 0xA1, 0x6D, 0x79, 0xF7, 0x36, 0xFD
	.byte 0x01, 0x1C, 0x60, 0x6D, 0x04, 0x4A, 0x80, 0x18, 0x81, 0x42, 0x00, 0xD1, 0x2D, 0xE1, 0xCC, 0x20
	.byte 0x40, 0x42, 0x20, 0x66, 0x01, 0x20, 0x27, 0xE1, 0x00, 0xE0, 0xFF, 0xFF, 0xA0, 0x7F, 0x01, 0x02
	.byte 0x20, 0x1C, 0x70, 0x30, 0x00, 0x78, 0x01, 0x43, 0x04, 0x4A, 0x88, 0x18, 0x01, 0x28, 0x02, 0xD9
	.byte 0x03, 0x48, 0x81, 0x42, 0x06, 0xD1, 0xA0, 0x7B, 0x01, 0x30, 0x15, 0xE1, 0xFA, 0x81, 0xFF, 0xFF
	.byte 0x0B, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x00, 0xD0, 0xE6, 0xE0
	.byte 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0x01, 0x28, 0x04, 0xD1, 0xE0, 0x7C, 0x00, 0x28, 0x06, 0xD0
	.byte 0x01, 0x38, 0xD3, 0xE0, 0xE0, 0x7C, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x38, 0xCE, 0xE0, 0x05, 0x20
	.byte 0xCC, 0xE0, 0x0C, 0x49, 0x20, 0x1C, 0x86, 0xF7, 0x1F, 0xFE, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73
	.byte 0x20, 0x1C, 0x86, 0xF7, 0x93, 0xFE, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x00, 0xD0
	.byte 0xEB, 0xE0, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0x01, 0x28, 0x00, 0xD0, 0xE0, 0xE0, 0xCC, 0x20
	.byte 0x40, 0x42, 0xDE, 0xE0, 0x0D, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x25, 0x1C
	.byte 0xB9, 0x35, 0x03, 0x28, 0x1B, 0xD1, 0xE0, 0x7C, 0x01, 0x30, 0xE0, 0x74, 0x00, 0x06, 0x00, 0x0E
	.byte 0x05, 0x28, 0x04, 0xD9, 0x28, 0x78, 0x01, 0x30, 0x28, 0x70, 0x00, 0x20, 0xE0, 0x74, 0x2B, 0x49
	.byte 0xE0, 0x7C, 0x80, 0x00, 0x40, 0x18, 0xA1, 0x6E, 0x00, 0x68, 0x09, 0x18, 0xA1, 0x66, 0x28, 0x49
	.byte 0xE0, 0x7C, 0x40, 0x00, 0x40, 0x18, 0x01, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0xE5, 0xFD, 0x20, 0x1C
	.byte 0x86, 0xF7, 0x5C, 0xFE, 0xA0, 0x6E, 0xA0, 0x65, 0x28, 0x78, 0x03, 0x28, 0x16, 0xD9, 0x00, 0x26
	.byte 0x2E, 0x70, 0x20, 0x4B, 0x20, 0x4A, 0x11, 0x68, 0x20, 0x48, 0x48, 0x43, 0x20, 0x49, 0x40, 0x18
	.byte 0x40, 0x00, 0x41, 0x08, 0x11, 0x60, 0x40, 0x0C, 0x0F, 0x21, 0x08, 0x40, 0x80, 0x00, 0xC0, 0x18
	.byte 0x00, 0x68, 0x00, 0x28, 0x02, 0xD0, 0x03, 0x20, 0x60, 0x73, 0xA6, 0x73, 0x60, 0x7B, 0x03, 0x28
	.byte 0x00, 0xD1, 0x9A, 0xE0, 0x60, 0x6D, 0xA1, 0x6D, 0x16, 0x4A, 0x89, 0x18, 0x79, 0xF7, 0x84, 0xF8
	.byte 0x01, 0x1C, 0x00, 0x29, 0x03, 0xD0, 0xCC, 0x20, 0x20, 0x66, 0x01, 0x20, 0xA0, 0x73, 0x20, 0x1C
	.byte 0xB8, 0x30, 0x05, 0x78, 0x01, 0x2D, 0x21, 0xD1, 0x60, 0x6D, 0xA1, 0x6D, 0x0E, 0x4A, 0x89, 0x18
	.byte 0x79, 0xF7, 0x0C, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x80, 0x22, 0x92, 0x01, 0x80, 0x18, 0x81, 0x42
	.byte 0x00, 0xD1, 0x7A, 0xE0, 0xCC, 0x20, 0x20, 0x66, 0xA5, 0x73, 0x76, 0xE0, 0xC8, 0x97, 0x36, 0x08
	.byte 0xA4, 0x97, 0x36, 0x08, 0x28, 0x97, 0x36, 0x08, 0x88, 0xF3, 0x02, 0x02, 0xFD, 0x43, 0x03, 0x00
	.byte 0xC3, 0x9E, 0x26, 0x00, 0x00, 0xA0, 0xFF, 0xFF, 0x00, 0xD0, 0xFF, 0xFF, 0x60, 0x6D, 0xA1, 0x6D
	.byte 0x06, 0x4A, 0x89, 0x18, 0x79, 0xF7, 0x62, 0xFC, 0x01, 0x1C, 0x60, 0x6D, 0x04, 0x4A, 0x80, 0x18
	.byte 0x81, 0x42, 0x5A, 0xD0, 0xCC, 0x20, 0x20, 0x66, 0x01, 0x20, 0x55, 0xE0, 0x00, 0xD0, 0xFF, 0xFF
	.byte 0x00, 0xE0, 0xFF, 0xFF, 0xA0, 0x7F, 0x01, 0x02, 0x20, 0x1C, 0x70, 0x30, 0x00, 0x78, 0x01, 0x43
	.byte 0x04, 0x4A, 0x88, 0x18, 0x01, 0x28, 0x02, 0xD9, 0x03, 0x48, 0x81, 0x42, 0x06, 0xD1, 0xA0, 0x7B
	.byte 0x01, 0x30, 0x41, 0xE0, 0xFA, 0x81, 0xFF, 0xFF, 0x0B, 0x7E, 0x00, 0x00, 0x20, 0x1C, 0x73, 0x30
	.byte 0x00, 0x78, 0x03, 0x28, 0x13, 0xD1, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78, 0xE0, 0x7C, 0x01, 0x30
	.byte 0xE0, 0x74, 0x00, 0x06, 0x00, 0x0E, 0x05, 0x28, 0x01, 0xD9, 0x00, 0x20, 0xE0, 0x74, 0x06, 0x48
	.byte 0xE1, 0x7C, 0x49, 0x00, 0x09, 0x18, 0x09, 0x88, 0x20, 0x1C, 0x86, 0xF7, 0x4D, 0xFD, 0x20, 0x1C
	.byte 0x86, 0xF7, 0xC4, 0xFD, 0x21, 0xE0, 0x00, 0x00, 0xA4, 0x97, 0x36, 0x08, 0x0B, 0x49, 0x20, 0x1C
	.byte 0x86, 0xF7, 0x42, 0xFD, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x20, 0x1C, 0x86, 0xF7, 0xB6, 0xFD
	.byte 0x20, 0x1C, 0x73, 0x30, 0x00, 0x78, 0x03, 0x28, 0x0F, 0xD1, 0x20, 0x1C, 0xB8, 0x30, 0x00, 0x78
	.byte 0x01, 0x28, 0x05, 0xD1, 0xCC, 0x20, 0x40, 0x42, 0x03, 0xE0, 0x00, 0x00, 0x0D, 0x7E, 0x00, 0x00
	.byte 0xCC, 0x20, 0xE0, 0x65, 0x00, 0x20, 0x60, 0x73, 0xA0, 0x73, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090b24
FUN_08090b24: @ 0x08090B24
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090B32
	b _08090C54
_08090B32:
	lsls r0, r0, #2
	ldr r1, _08090B3C @ =_08090B40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090B3C: .4byte _08090B40
_08090B40: @ jump table
	.4byte _08090B64 @ case 0
	.4byte _08090B7C @ case 1
	.4byte _08090BA0 @ case 2
	.4byte _08090BB8 @ case 3
	.4byte _08090BE0 @ case 4
	.4byte _08090C00 @ case 5
	.4byte _08090C12 @ case 6
	.4byte _08090C30 @ case 7
	.4byte _08090C3E @ case 8
_08090B64:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090B98 @ =0x08369668
	bl SetDDP
	ldr r1, _08090B9C @ =0x00007E0E
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090B7C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090B98: .4byte 0x08369668
_08090B9C: .4byte 0x00007E0E
_08090BA0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
_08090BB8:
	ldr r1, _08090BF8 @ =0x00007E0F
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090BFC @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809118c
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090BE0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090C52
	.align 2, 0
_08090BF8: .4byte 0x00007E0F
_08090BFC: .4byte 0xFFFFE400
_08090C00:
	ldr r1, _08090C2C @ =0x00007E10
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090C24
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C24:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08090C54
	.align 2, 0
_08090C2C: .4byte 0x00007E10
_08090C30:
	ldr r1, _08090C5C @ =0x00007E11
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090C3E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090C54
	movs r0, #0
	strb r0, [r4, #0xd]
_08090C52:
	strb r0, [r4, #0xe]
_08090C54:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090C5C: .4byte 0x00007E11
_08090C60:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090c64
FUN_08090c64: @ 0x08090C64
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090C72
	b _08090D96
_08090C72:
	lsls r0, r0, #2
	ldr r1, _08090C7C @ =_08090C80
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090C7C: .4byte _08090C80
_08090C80: @ jump table
	.4byte _08090CA4 @ case 0
	.4byte _08090CBC @ case 1
	.4byte _08090D52 @ case 2
	.4byte _08090CDC @ case 3
	.4byte _08090D20 @ case 4
	.4byte _08090D40 @ case 5
	.4byte _08090D52 @ case 6
	.4byte _08090D70 @ case 7
	.4byte _08090D7E @ case 8
_08090CA4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090CD4 @ =0x083696B0
	bl SetDDP
	ldr r1, _08090CD8 @ =0x00007E12
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090CBC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	b _08090D30
	.align 2, 0
_08090CD4: .4byte 0x083696B0
_08090CD8: .4byte 0x00007E12
_08090CDC:
	ldr r1, _08090CF8 @ =0x00007E13
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090CFC
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	b _08090D00
	.align 2, 0
_08090CF8: .4byte 0x00007E13
_08090CFC:
	ldr r0, [r4, #0x54]
	ldr r1, _08090D38 @ =0xFFFFFC00
_08090D00:
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08090D3C @ =0xFFFFE700
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0809118c
	movs r0, #0x2c
	bl PlaySound
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D20:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
_08090D30:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08090D96
	.align 2, 0
_08090D38: .4byte 0xFFFFFC00
_08090D3C: .4byte 0xFFFFE700
_08090D40:
	ldr r1, _08090D6C @ =0x00007E14
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D52:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090D64
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D64:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08090D96
	.align 2, 0
_08090D6C: .4byte 0x00007E14
_08090D70:
	ldr r1, _08090DA0 @ =0x00007E15
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090D7E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090D96
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08090D96:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090DA0: .4byte 0x00007E15
_08090DA4:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090da8
FUN_08090da8: @ 0x08090DA8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _08090DB4
	b _08090ED0
_08090DB4:
	lsls r0, r0, #2
	ldr r1, _08090DC0 @ =_08090DC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090DC0: .4byte _08090DC4
_08090DC4: @ jump table
	.4byte _08090DE4 @ case 0
	.4byte _08090DF8 @ case 1
	.4byte _08090E10 @ case 2
	.4byte _08090E2C @ case 3
	.4byte _08090E58 @ case 4
	.4byte _08090E84 @ case 5
	.4byte _08090EAC @ case 6
	.4byte _08090EBA @ case 7
_08090DE4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E0C @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090DF8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E0C: .4byte 0x08369710
_08090E10:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090E50 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090E54 @ =0x00007E16
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090E2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E50: .4byte 0x083696F8
_08090E54: .4byte 0x00007E16
_08090E58:
	ldr r1, _08090E9C @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _08090EA0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08090EA4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08090EA8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090E84:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08090ED0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08090ECE
	.align 2, 0
_08090E9C: .4byte 0x00007E18
_08090EA0: .4byte RNG_0202f388
_08090EA4: .4byte 0x000343FD
_08090EA8: .4byte 0x00269EC3
_08090EAC:
	ldr r1, _08090ED8 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090EBA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08090ED0
	movs r0, #0
	strb r0, [r4, #0xd]
_08090ECE:
	strb r0, [r4, #0xe]
_08090ED0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090ED8: .4byte 0x00007E19
_08090EDC:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08090ee0
FUN_08090ee0: @ 0x08090EE0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #8
	bls _08090EEC
	b _0809105C
_08090EEC:
	lsls r0, r0, #2
	ldr r1, _08090EF8 @ =_08090EFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08090EF8: .4byte _08090EFC
_08090EFC: @ jump table
	.4byte _08090F20 @ case 0
	.4byte _08090F34 @ case 1
	.4byte _08090F4C @ case 2
	.4byte _08090F8A @ case 3
	.4byte _08090FC2 @ case 4
	.4byte _08090FE4 @ case 5
	.4byte _08091010 @ case 6
	.4byte _08091038 @ case 7
	.4byte _08091046 @ case 8
_08090F20:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F48 @ =0x08369710
	bl SetDDP
	movs r0, #4
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F34:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08090F42
	b _0809105C
_08090F42:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08090F48: .4byte 0x08369710
_08090F4C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08090F74 @ =0x083696F8
	bl SetDDP
	ldr r1, _08090F78 @ =0x00007E17
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x60
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #1
	bne _08090F7C
	movs r0, #0xcc
	rsbs r0, r0, #0
	b _08090F7E
	.align 2, 0
_08090F74: .4byte 0x083696F8
_08090F78: .4byte 0x00007E17
_08090F7C:
	movs r0, #0xcc
_08090F7E:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08090F8A:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08090F9A
	str r1, [r4, #0x60]
_08090F9A:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809105C
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FC2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
_08090FE4:
	ldr r1, _08091028 @ =0x00007E18
	adds r0, r4, #0
	bl SetMotion
	ldr r2, _0809102C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08091030 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08091034 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x14
	bl __umodsi3
	adds r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091010:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809105C
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809105A
	.align 2, 0
_08091028: .4byte 0x00007E18
_0809102C: .4byte RNG_0202f388
_08091030: .4byte 0x000343FD
_08091034: .4byte 0x00269EC3
_08091038:
	ldr r1, _08091064 @ =0x00007E19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091046:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _0809105C
	movs r0, #0
	strb r0, [r4, #0xd]
_0809105A:
	strb r0, [r4, #0xe]
_0809105C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091064: .4byte 0x00007E19
_08091068:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0809106c
FUN_0809106c: @ 0x0809106C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r6, [r4, #0xe]
	cmp r6, #0
	beq _0809107C
	cmp r6, #1
	beq _08091124
	b _08091146
_0809107C:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x60]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _080910C2
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x60]
_080910C2:
	ldr r0, [r4, #0x5c]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	lsls r0, r0, #9
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0xb4
	str r5, [r0]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08091102
	movs r2, #1
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
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
	b _0809111E
_08091102:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809111E:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091124:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r1]
	ldr r2, _0809114C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r1]
_08091146:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809114C: .4byte 0xFFFFFE00
_08091150:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_08091154
FUN_08091154: @ 0x08091154
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _08091162
	movs r0, #1
	strb r0, [r1, #0xe]
_08091162:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091168
FUN_08091168: @ 0x08091168
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809116c
FUN_0809116c: @ 0x0809116C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08091170
FUN_08091170: @ 0x08091170
	movs r0, #1
	bx lr

	thumb_func_start FUN_08091174
FUN_08091174: @ 0x08091174
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	bne _08091182
	movs r0, #1
	strb r0, [r1, #0xe]
_08091182:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091188
FUN_08091188: @ 0x08091188
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809118c
FUN_0809118c: @ 0x0809118C
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r0, _080911F8 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r2, #0x54]
	ldr r0, [r7]
	subs r4, r1, r0
	ldr r0, [r7, #4]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	subs r5, r1, r0
	asrs r0, r4, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r5, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xe
	cmp r6, #0
	beq _080911D8
	lsls r0, r4, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	lsls r0, r5, #8
	adds r1, r6, #0
	bl __divsi3
	adds r5, r0, #0
_080911D8:
	cmp r4, #0
	ble _0809122A
	cmp r5, #0
	ble _08091206
	ldr r0, _080911FC @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091200
	movs r0, #0x7e
	subs r0, r0, r2
	b _0809123E
	.align 2, 0
_080911F8: .4byte pZero2
_080911FC: .4byte gSineTable
_08091200:
	adds r0, r2, #0
	adds r0, #0x7e
	b _0809123E
_08091206:
	ldr r0, _08091220 @ =gSineTable
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08091224
	adds r0, r2, #0
	adds r0, #0x7f
	b _0809123E
	.align 2, 0
_08091220: .4byte gSineTable
_08091224:
	rsbs r0, r2, #0
	adds r0, #0x7f
	b _0809123E
_0809122A:
	cmp r5, #0
	ble _08091248
	ldr r0, _08091244 @ =gSineTable
	adds r1, r5, #0
	adds r1, #0x40
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r1, r1, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
_0809123E:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _08091256
	.align 2, 0
_08091244: .4byte gSineTable
_08091248:
	ldr r1, _08091278 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrb r2, [r0]
_08091256:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl CreateLemon
	adds r1, r0, #0
	cmp r1, #0
	beq _08091272
	lsls r0, r4, #9
	asrs r0, r0, #8
	str r0, [r1, #0x5c]
	lsls r0, r5, #9
	asrs r0, r0, #8
	str r0, [r1, #0x60]
_08091272:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091278: .4byte gSineTable

	thumb_func_start nop_0809127c
nop_0809127c: @ 0x0809127C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08091280
FUN_08091280: @ 0x08091280
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov sl, r0
	ldr r0, _08091300 @ =RNG_0202f388
	mov sb, r0
	ldr r0, [r0]
	ldr r6, _08091304 @ =0x000343FD
	muls r0, r6, r0
	ldr r4, _08091308 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	lsls r0, r0, #8
	mov r1, sl
	ldr r5, [r1, #0x54]
	adds r5, r5, r0
	adds r0, r2, #0
	muls r0, r6, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r2, r0, #1
	mov r8, r2
	mov r1, sb
	str r2, [r1]
	lsrs r0, r0, #0x11
	rsbs r0, r0, #0
	movs r1, #0x30
	bl __umodsi3
	lsls r0, r0, #8
	mov r2, sl
	ldr r1, [r2, #0x58]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #1
	mov r3, r8
	muls r3, r6, r3
	adds r3, r3, r4
	lsls r3, r3, #1
	lsrs r0, r3, #1
	mov r4, sb
	str r0, [r4]
	lsrs r3, r3, #0x11
	movs r0, #0x7f
	ands r3, r0
	movs r0, #0x80
	orrs r3, r0
	adds r0, r5, #0
	bl FUN_080c4c2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091300: .4byte RNG_0202f388
_08091304: .4byte 0x000343FD
_08091308: .4byte 0x00269EC3

	thumb_func_start FUN_0809130c
FUN_0809130c: @ 0x0809130C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	adds r7, r6, #0
	ldr r0, _080913B8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080913B2
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080913BC @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r4, #9]
	adds r0, #0xec
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	cmp r6, #3
	bhi _08091372
	subs r0, r6, #2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x64]
_08091372:
	cmp r6, #4
	bls _0809138A
	subs r0, r6, #7
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0xc
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r1, r1, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_0809138A:
	str r5, [r4, #0x28]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldr r0, [r5, #8]
	str r0, [r4, #0x3c]
	ldrb r1, [r5, #0x15]
	adds r3, r4, #0
	adds r3, #0x49
	lsrs r1, r1, #4
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	strb r7, [r4, #0x10]
_080913B2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080913B8: .4byte gZakoHeaderPtr
_080913BC: .4byte gEnemyFnTable

	thumb_func_start FUN_080913c0
FUN_080913c0: @ 0x080913C0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _08091424 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809141E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08091428 @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r3, #9]
	adds r0, #0xec
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	str r0, [r3, #0x58]
	strb r5, [r3, #0x10]
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809141C
	movs r1, #1
_0809141C:
	strb r1, [r3, #0x13]
_0809141E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091424: .4byte gZakoHeaderPtr
_08091428: .4byte gEnemyFnTable

	thumb_func_start FUN_0809142c
FUN_0809142c: @ 0x0809142C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809148C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08091484
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08091490 @ =gEnemyFnTable
	movs r1, #0x3b
	strb r1, [r3, #9]
	adds r0, #0xec
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
	ldr r0, [r4, #0x54]
	str r0, [r3, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, _08091494 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [r3, #0x58]
	movs r0, #0xc
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x12]
	str r4, [r3, #0x28]
_08091484:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809148C: .4byte gZakoHeaderPtr
_08091490: .4byte gEnemyFnTable
_08091494: .4byte 0xFFFFF600

	thumb_func_start FUN_08091498
FUN_08091498: @ 0x08091498
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #0xc
	bne _08091500
	ldr r1, _080914F0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080914F4 @ =0x08369864
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080914F8 @ =FUN_08091790
	str r0, [r4, #0x24]
	ldr r1, _080914FC @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl FUN_0809159c
	b _08091586
	.align 2, 0
_080914F0: .4byte gEnemyFnTable
_080914F4: .4byte 0x08369864
_080914F8: .4byte FUN_08091790
_080914FC: .4byte 0x08369A14
_08091500:
	cmp r0, #8
	bls _0809153C
	ldr r1, _08091534 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08091538 @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl FUN_08091778
	b _08091586
	.align 2, 0
_08091534: .4byte gEnemyFnTable
_08091538: .4byte 0x08369A14
_0809153C:
	ldr r1, _0809158C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08091590 @ =0x08369864
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08091594 @ =FUN_08091790
	str r0, [r4, #0x24]
	ldr r1, _08091598 @ =0x08369A14
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	adds r0, r5, #0
	bl FUN_0809159c
_08091586:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809158C: .4byte gEnemyFnTable
_08091590: .4byte 0x08369864
_08091594: .4byte FUN_08091790
_08091598: .4byte 0x08369A14

	thumb_func_start FUN_0809159c
FUN_0809159c: @ 0x0809159C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r4, [r6, #0x28]
	adds r5, r6, #0
	adds r5, #0x34
	ldrb r0, [r6, #0x10]
	cmp r0, #0xc
	bne _080915E8
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080915C4
	b _080916F4
_080915C4:
	ldr r1, _080915E4 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	adds r0, r6, #0
	bl FUN_08091778
	b _0809175E
	.align 2, 0
_080915E4: .4byte gEnemyFnTable
_080915E8:
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bls _08091614
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	b _080916DC
_08091614:
	adds r1, r6, #0
	adds r1, #0x8c
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	mov r8, r2
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _080916F4
	adds r0, r6, #0
	bl FUN_08091280
	adds r2, r4, #0
	adds r2, #0xc4
	ldr r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	ldr r1, _08091680 @ =0xFFFFEC00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #9
	ands r0, r1
	cmp r0, #0
	beq _080916A6
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08091660
	movs r3, #1
_08091660:
	movs r0, #0
	mov r1, sp
	mov r2, r8
	bl FUN_080b2b40
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091684
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_080913c0
	b _080916AE
	.align 2, 0
_08091680: .4byte 0xFFFFEC00
_08091684:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	ldr r1, [r6, #0x58]
	cmp r1, r0
	bne _0809169C
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080913c0
	b _080916AE
_0809169C:
	adds r0, r6, #0
	movs r1, #9
	bl FUN_080913c0
	b _080916AE
_080916A6:
	adds r0, r6, #0
	movs r1, #9
	bl FUN_080913c0
_080916AE:
	movs r3, #0
	str r3, [r7]
	adds r5, r6, #0
	adds r5, #0x90
	str r3, [r5]
	adds r4, r6, #0
	adds r4, #0x94
	strb r3, [r4]
	ldrb r1, [r6, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	str r3, [r7]
	str r3, [r5]
	strb r3, [r4]
	ldrb r0, [r6, #0xa]
	ands r2, r0
	strb r2, [r6, #0xa]
_080916DC:
	ldr r1, _080916F0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _0809175E
	.align 2, 0
_080916F0: .4byte gEnemyFnTable
_080916F4:
	ldr r1, _0809176C @ =0x083699B4
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, _08091770 @ =0x083699DC
	ldrb r0, [r6, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldrb r0, [r6, #0x10]
	cmp r0, #0xc
	beq _0809175E
	adds r0, r4, #0
	adds r0, #0x70
	ldrb r1, [r0]
	ldr r0, [r4, #0x6c]
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0x1a]
	adds r1, r4, #0
	adds r1, #0x34
	ldr r0, [r1, #8]
	str r0, [r5, #8]
	ldrh r1, [r1, #0x14]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #0x14]
	ldr r0, _08091774 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #0x14]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x23
	strb r1, [r0]
_0809175E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809176C: .4byte 0x083699B4
_08091770: .4byte 0x083699DC
_08091774: .4byte 0xFFFFFC00

	thumb_func_start FUN_08091778
FUN_08091778: @ 0x08091778
	push {lr}
	ldr r2, _0809178C @ =0x08369A04
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809178C: .4byte 0x08369A04

	thumb_func_start FUN_08091790
FUN_08091790: @ 0x08091790
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, [r1, #0xc]
	ldr r4, [r0, #0x2c]
	ldr r3, [r1, #0x2c]
	ldrb r0, [r3, #0x10]
	cmp r0, #0xc
	bne _080917F4
	ldr r0, [r1, #0x14]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091804
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _08091804
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	bne _08091804
	ldrb r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08091804
	ldrb r0, [r4, #9]
	cmp r0, #0x15
	bne _08091804
	ldr r0, [r3, #0xc]
	ldr r1, _080917F0 @ =0x00FFFF00
	ands r0, r1
	movs r1, #0xc2
	lsls r1, r1, #0xa
	cmp r0, r1
	bne _08091804
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, [r4, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #9
	strb r0, [r3, #0xd]
	strb r1, [r3, #0xe]
	b _08091804
	.align 2, 0
_080917F0: .4byte 0x00FFFF00
_080917F4:
	adds r2, r3, #0
	adds r2, #0xb4
	ldr r0, _0809180C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r3, #0x54]
	subs r0, r0, r1
	str r0, [r2]
_08091804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809180C: .4byte pZero2

	thumb_func_start FUN_08091810
FUN_08091810:
  bx lr
	.align 2, 0

	thumb_func_start FUN_08091814
FUN_08091814: @ 0x08091814
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, #0x34
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _0809182C
	cmp r1, #1
	beq _0809183C
	b _080918E2
_0809182C:
	ldr r1, [r2, #8]
	adds r2, r4, #0
	adds r2, #0x54
	bl InitNonAffineSprite
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809183C:
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r1, [r0]
	movs r2, #8
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _08091856
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091868 @ =0x08369864
	bl SetDDP
_08091856:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _0809186C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091872
	.align 2, 0
_08091868: .4byte 0x08369864
_0809186C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091872:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08091884
	strb r2, [r4, #0x12]
_08091884:
	adds r3, r5, #0
	ldr r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080918C4
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080918E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_080918C4:
	ldr r0, [r3]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080918D4
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_080918D4:
	ldr r0, [r5]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080918E2
	strb r1, [r4, #0xd]
	strb r2, [r4, #0xe]
_080918E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080918E8: .4byte gEnemyFnTable

	thumb_func_start FUN_080918ec
FUN_080918ec: @ 0x080918EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080918FC
	cmp r5, #1
	beq _08091924
	b _0809197A
_080918FC:
	movs r6, #0
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809190A
	movs r6, #1
_0809190A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091934 @ =0x08369894
	bl SetDDP
	lsls r0, r6, #9
	ldr r1, _08091938 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091924:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _0809193C
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091942
	.align 2, 0
_08091934: .4byte 0x08369894
_08091938: .4byte 0xFFFFFF00
_0809193C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091942:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _08091954
	movs r0, #0
	strb r0, [r4, #0x12]
_08091954:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r1, r0, r1
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x64]
	subs r2, r0, r1
	adds r3, r0, #0
	cmp r2, #0
	blt _0809196C
	cmp r2, #0xff
	ble _08091972
	b _0809197A
_0809196C:
	subs r0, r1, r3
	cmp r0, #0xff
	bgt _0809197A
_08091972:
	str r3, [r4, #0x54]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0809197A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08091980
FUN_08091980: @ 0x08091980
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #7
	bls _0809198C
	b _08091AA6
_0809198C:
	lsls r0, r0, #2
	ldr r1, _08091998 @ =_0809199C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08091998: .4byte _0809199C
_0809199C: @ jump table
	.4byte _080919BC @ case 0
	.4byte _080919D0 @ case 1
	.4byte _080919E0 @ case 2
	.4byte _080919EA @ case 3
	.4byte _08091A08 @ case 4
	.4byte _08091A12 @ case 5
	.4byte _08091A3C @ case 6
	.4byte _08091A46 @ case 7
_080919BC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080919DC @ =0x08369894
	bl SetDDP
	movs r0, #0x1b
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	b _08091A30
	.align 2, 0
_080919DC: .4byte 0x08369894
_080919E0:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080919EA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _08091A26
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A2C
_08091A08:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A12:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091A26
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _08091A2C
_08091A26:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A2C:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
_08091A30:
	cmp r0, #0
	bne _08091AA6
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08091AA6
_08091A3C:
	movs r0, #0xf
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091A46:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08091A64
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _08091A6A
_08091A64:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091A6A:
	strb r0, [r4, #0xa]
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	bne _08091AA6
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091AAC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091AA6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091AAC: .4byte gEnemyFnTable

	thumb_func_start FUN_08091ab0
FUN_08091ab0: @ 0x08091AB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	adds r0, #0x34
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r4, #0xe]
	cmp r1, #0
	beq _08091AC8
	cmp r1, #1
	beq _08091AE2
	b _08091B56
_08091AC8:
	ldr r1, [r2, #8]
	adds r2, r4, #0
	adds r2, #0x54
	bl InitNonAffineSprite
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091AF4 @ =0x08369894
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091AE2:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _08091AF8
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091AFE
	.align 2, 0
_08091AF4: .4byte 0x08369894
_08091AF8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091AFE:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	movs r2, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _08091B10
	strb r2, [r4, #0x12]
_08091B10:
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
	adds r0, r5, #0
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091B56
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091B5C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091B56:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091B5C: .4byte gEnemyFnTable

	thumb_func_start FUN_08091b60
FUN_08091b60: @ 0x08091B60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x34
	mov r6, r8
	adds r6, #0x34
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08091B80
	cmp r5, #1
	beq _08091BB8
	b _08091C46
_08091B80:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091BD0 @ =0x08369894
	bl SetDDP
	ldr r1, [r6, #8]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r7, #0
	bl InitScalerotSprite1
	ldrb r1, [r4, #0xa]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	strb r5, [r4, #0x12]
	movs r0, #0x20
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091BB8:
	ldrb r0, [r4, #0x12]
	adds r3, r0, #0
	ldrb r2, [r4, #0x13]
	cmp r3, #0
	bne _08091BD4
	cmp r2, #0x55
	bhi _08091BD4
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091BDA
	.align 2, 0
_08091BD0: .4byte 0x08369894
_08091BD4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091BDA:
	strb r0, [r4, #0xa]
	adds r0, r3, #1
	movs r3, #0
	strb r0, [r4, #0x12]
	lsls r1, r2, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r1, #0x1c
	cmp r0, r1
	bne _08091BF4
	adds r0, r2, #3
	strb r0, [r4, #0x13]
	strb r3, [r4, #0x12]
_08091BF4:
	mov r0, r8
	adds r0, #0x52
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08091C46
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r3, [r0]
	adds r0, #4
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091C50 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091C46:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091C50: .4byte gEnemyFnTable

	thumb_func_start FUN_08091c54
FUN_08091c54: @ 0x08091C54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x34
	mov r6, r8
	adds r6, #0x34
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08091C74
	cmp r5, #1
	beq _08091CAC
	b _08091D00
_08091C74:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091CBC @ =0x08369894
	bl SetDDP
	ldr r1, [r6, #8]
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r7, #0
	bl InitScalerotSprite1
	ldrb r1, [r4, #0xa]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldrb r1, [r4, #0xb]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	strb r5, [r4, #0x12]
	movs r0, #0x59
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091CAC:
	ldrb r0, [r4, #0x12]
	adds r2, r0, #0
	cmp r2, #0
	bne _08091CC0
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08091CC6
	.align 2, 0
_08091CBC: .4byte 0x08369894
_08091CC0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08091CC6:
	strb r0, [r4, #0xa]
	adds r0, r2, #1
	strb r0, [r4, #0x12]
	ldrb r2, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r2, #4
	cmp r0, r1
	bne _08091CE0
	movs r0, #0
	strb r0, [r4, #0x12]
	subs r0, r2, #3
	strb r0, [r4, #0x13]
_08091CE0:
	mov r0, r8
	adds r0, #0x52
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	movs r2, #0
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08091D00
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
_08091D00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091D0C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x25, 0xD0, 0x3B, 0xE0, 0x20, 0x1C, 0x74, 0x30
	.byte 0x1E, 0x49, 0x75, 0xF7, 0x77, 0xFA, 0x20, 0x1C, 0x85, 0xF7, 0xEC, 0xFA, 0xA1, 0x7C, 0x49, 0x06
	.byte 0xF8, 0x20, 0x80, 0x05, 0x09, 0x18, 0x1A, 0x4A, 0x80, 0x23, 0xDB, 0x05, 0xC8, 0x18, 0xC0, 0x0D
	.byte 0x80, 0x18, 0x00, 0x23, 0xC0, 0x5E, 0x80, 0x00, 0xE0, 0x65, 0xC9, 0x0D, 0x89, 0x18, 0x00, 0x22
	.byte 0x88, 0x5E, 0x80, 0x00, 0x20, 0x66, 0x88, 0x21, 0x09, 0x02, 0x20, 0x1C, 0x85, 0xF7, 0x04, 0xFC
	.byte 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0x60, 0x6D, 0xE1, 0x6D, 0x40, 0x18, 0x60, 0x65, 0xA1, 0x6D
	.byte 0x22, 0x6E, 0x89, 0x18, 0xA1, 0x65, 0x77, 0xF7, 0x0B, 0xFE, 0x01, 0x1C, 0x00, 0x29, 0x06, 0xDA
	.byte 0xA0, 0x6D, 0x40, 0x18, 0xA0, 0x65, 0x00, 0x21, 0x07, 0x20, 0x60, 0x73, 0xA1, 0x73, 0x20, 0x1C
	.byte 0x85, 0xF7, 0x64, 0xFC, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xF4, 0x98, 0x36, 0x08
	.byte 0x74, 0xEA, 0x0F, 0x08

	thumb_func_start FUN_08091da4
FUN_08091da4: @ 0x08091DA4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08091DB4
	cmp r0, #1
	beq _08091E26
	b _08091E4E
_08091DB4:
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08091DE8 @ =0x08369924
	bl SetDDP
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	ldr r1, _08091DEC @ =0xFFFFFE80
	adds r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _08091DF0 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0x12]
	lsrs r2, r0, #1
	cmp r2, #0
	beq _08091DF4
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08091DFA
	.align 2, 0
_08091DE8: .4byte 0x08369924
_08091DEC: .4byte 0xFFFFFE80
_08091DF0: .4byte 0xFFFFFC00
_08091DF4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08091DFA:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08091E54 @ =0x00008801
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091E26:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	cmp r0, #0
	ble _08091E40
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08091E40:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08091E4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091E54: .4byte 0x00008801

	thumb_func_start FUN_08091e58
FUN_08091e58: @ 0x08091E58
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x28]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08091E86
	cmp r0, #1
	bgt _08091E6E
	cmp r0, #0
	beq _08091E78
	b _08091EF6
_08091E6E:
	cmp r0, #2
	beq _08091EC4
	cmp r0, #3
	beq _08091ECE
	b _08091EF6
_08091E78:
	ldr r1, _08091EC0 @ =0x00008802
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091E86:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r2, [r4, #0x60]
	adds r2, #0x40
	str r2, [r4, #0x60]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	cmp r5, #0
	bge _08091EB8
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091EB8:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _08091EF6
	.align 2, 0
_08091EC0: .4byte 0x00008802
_08091EC4:
	movs r0, #0xc0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091ECE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08091EE0
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bls _08091EF6
_08091EE0:
	ldr r1, _08091EFC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #3
	strb r0, [r4, #0xd]
_08091EF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091EFC: .4byte gEnemyFnTable

	thumb_func_start FUN_08091f00
FUN_08091f00: @ 0x08091F00
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08091F10
	cmp r0, #1
	beq _08091F38
	b _08091F90
_08091F10:
	movs r0, #0x80
	lsls r0, r0, #1
	bl PlaySound
	ldr r0, _08091F98 @ =0xFFFFFD00
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bge _08091F2C
	movs r1, #0xc0
	lsls r1, r1, #2
_08091F2C:
	str r1, [r4, #0x5c]
	ldr r0, _08091F9C @ =0xFFFFFE00
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08091F38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _08091FA0 @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bls _08091F90
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08091FA4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08091F90:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091F98: .4byte 0xFFFFFD00
_08091F9C: .4byte 0xFFFFFE00
_08091FA0: .4byte gStageRun+232
_08091FA4: .4byte gEnemyFnTable

	thumb_func_start FUN_08091fa8
FUN_08091fa8: @ 0x08091FA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #1
	beq _08092016
	cmp r0, #1
	bgt _08091FC2
	cmp r0, #0
	beq _08091FCC
	b _080921A6
_08091FC2:
	cmp r0, #2
	beq _08092044
	cmp r0, #3
	beq _0809204E
	b _080921A6
_08091FCC:
	adds r0, r7, #0
	bl InitNonAffineMotion
	ldrb r2, [r7, #0x13]
	cmp r2, #0
	beq _08091FE0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08091FE6
_08091FE0:
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
_08091FE6:
	strb r0, [r7, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r7, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08092040 @ =0x00001303
	adds r0, r7, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08092016:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08092030
	adds r0, r7, #0
	bl FUN_08091280
_08092030:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _08092038
	b _080921A6
_08092038:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080921A6
	.align 2, 0
_08092040: .4byte 0x00001303
_08092044:
	movs r0, #0
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809204E:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	bne _08092060
	movs r0, #0x2a
	bl PlaySound
_08092060:
	ldrb r0, [r7, #0x12]
	adds r0, #1
	strb r0, [r7, #0x12]
	adds r0, r7, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08092072
	b _080921A6
_08092072:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _08092094 @ =0xFFFFE800
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r4, _08092098 @ =0x083697F4
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0809209C
	orrs r3, r2
	b _0809209E
	.align 2, 0
_08092094: .4byte 0xFFFFE800
_08092098: .4byte 0x083697F4
_0809209C:
	adds r3, r2, #0
_0809209E:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r5, _080920C0 @ =0x08369810
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080920C4
	orrs r3, r2
	b _080920C6
	.align 2, 0
_080920C0: .4byte 0x08369810
_080920C4:
	adds r3, r2, #0
_080920C6:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl CreateSlashedEnemy
	mov r4, sp
	ldr r5, _080920E8 @ =0x0836982C
	ldrb r2, [r7, #0x13]
	ldrb r1, [r7, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080920EC
	orrs r3, r2
	b _080920EE
	.align 2, 0
_080920E8: .4byte 0x0836982C
_080920EC:
	adds r3, r2, #0
_080920EE:
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r0, [r7, #0x58]
	ldr r1, _080921B4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r3, _080921B8 @ =RNG_0202f388
	ldr r0, [r3]
	ldr r2, _080921BC @ =0x000343FD
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r5, _080921C0 @ =0x00269EC3
	adds r1, r1, r5
	lsls r1, r1, #1
	lsrs r0, r1, #1
	mov r8, r0
	lsrs r1, r1, #0x11
	movs r6, #0x1f
	ands r1, r6
	movs r4, #0x10
	subs r1, r4, r1
	lsls r1, r1, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	bl CreateSmoke
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	ands r0, r6
	subs r4, r4, r0
	lsls r4, r4, #8
	ldr r0, [r7, #0x54]
	adds r0, r0, r4
	str r0, [sp]
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r3]
	lsrs r0, r0, #0x11
	ands r0, r6
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _080921C4 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
_080921A6:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080921B4: .4byte 0xFFFFF000
_080921B8: .4byte RNG_0202f388
_080921BC: .4byte 0x000343FD
_080921C0: .4byte 0x00269EC3
_080921C4: .4byte gEnemyFnTable

	thumb_func_start FUN_080921c8
FUN_080921c8: @ 0x080921C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08092230
	cmp r0, #1
	bgt _080921DC
	cmp r0, #0
	beq _080921E6
	b _080922D6
_080921DC:
	cmp r0, #2
	beq _0809225C
	cmp r0, #3
	beq _08092266
	b _080922D6
_080921E6:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	beq _080921FA
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08092200
_080921FA:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08092200:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08092258 @ =0x00001303
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092230:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809224A
	adds r0, r5, #0
	bl FUN_08091280
_0809224A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080922D6
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080922D6
	.align 2, 0
_08092258: .4byte 0x00001303
_0809225C:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092266:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08092278
	movs r0, #0x2a
	bl PlaySound
_08092278:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080922D6
	adds r4, r5, #0
	adds r4, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldrb r3, [r5, #0x13]
	adds r0, r4, #0
	movs r1, #0
	bl CreateGhost18
	ldr r6, _080922B4 @ =0x08369848
	ldrb r2, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080922B8
	orrs r3, r2
	b _080922BA
	.align 2, 0
_080922B4: .4byte 0x08369848
_080922B8:
	adds r3, r2, #0
_080922BA:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r1, _080922DC @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080922D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080922DC: .4byte gEnemyFnTable

	thumb_func_start FUN_080922e0
FUN_080922e0: @ 0x080922E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08092348
	cmp r0, #1
	bgt _080922F4
	cmp r0, #0
	beq _080922FE
	b _080923E2
_080922F4:
	cmp r0, #2
	beq _08092374
	cmp r0, #3
	beq _0809237E
	b _080923E2
_080922FE:
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r2, [r5, #0x13]
	cmp r2, #0
	beq _08092312
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08092318
_08092312:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08092318:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08092370 @ =0x00001303
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x12
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092348:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08092362
	adds r0, r5, #0
	bl FUN_08091280
_08092362:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080923E2
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _080923E2
	.align 2, 0
_08092370: .4byte 0x00001303
_08092374:
	movs r0, #0
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809237E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08092390
	movs r0, #0x2a
	bl PlaySound
_08092390:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	adds r4, r5, #0
	adds r4, #0x54
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldrb r3, [r5, #0x13]
	adds r0, r4, #0
	movs r1, #0
	bl CreateGhost18
	ldr r6, _080923C0 @ =0x08369848
	ldrb r2, [r5, #0x13]
	ldrb r1, [r5, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080923C4
	orrs r3, r2
	b _080923C6
	.align 2, 0
_080923C0: .4byte 0x08369848
_080923C4:
	adds r3, r2, #0
_080923C6:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl CreateSlashedEnemy
	ldr r1, _080923E8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_080923E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080923E8: .4byte gEnemyFnTable

	thumb_func_start FUN_080923ec
FUN_080923ec: @ 0x080923EC
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0809243C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _08092440 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809243C: .4byte 0xFFFFF800
_08092440: .4byte gEnemyFnTable

	thumb_func_start FUN_08092444
FUN_08092444: @ 0x08092444
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r2, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080924A0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08092498
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080924A4 @ =gEnemyFnTable
	movs r1, #0x3c
	strb r1, [r4, #9]
	adds r0, #0xf0
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r5, [r4, #0x10]
	strb r2, [r4, #0x11]
	str r7, [r4, #0x28]
_08092498:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080924A0: .4byte gZakoHeaderPtr
_080924A4: .4byte gEnemyFnTable

	thumb_func_start FUN_080924a8
FUN_080924a8: @ 0x080924A8
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _080924FC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080924F4
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08092500 @ =gEnemyFnTable
	movs r1, #0x3c
	strb r1, [r3, #9]
	adds r0, #0xf0
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
_080924F4:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080924FC: .4byte gZakoHeaderPtr
_08092500: .4byte gEnemyFnTable

	thumb_func_start FUN_08092504
FUN_08092504: @ 0x08092504
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl InitNonAffineMotion
	adds r0, r7, #0
	bl ResetDynamicMotion
	movs r5, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r6, #1
	adds r0, r7, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080925A8 @ =0x08369A8C
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	ldr r0, _080925AC @ =nop_08093578
	str r0, [r4, #0x24]
	adds r0, r7, #0
	adds r0, #0x5c
	str r5, [r0, #4]
	str r5, [r7, #0x5c]
	ldr r1, _080925B0 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r7, #0x14]
	strb r5, [r7, #0xd]
	strb r5, [r7, #0xe]
	strb r5, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0xb4
	str r5, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	str r5, [r0]
	ldr r2, [r7, #0x28]
	ldr r0, [r2, #0x58]
	str r0, [r7, #0x58]
	ldr r0, [r1]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldrb r1, [r7, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r7, #0x1d]
	adds r0, r7, #0
	bl FUN_080925b4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080925A8: .4byte 0x08369A8C
_080925AC: .4byte nop_08093578
_080925B0: .4byte gEnemyFnTable

	thumb_func_start FUN_080925b4
FUN_080925b4: @ 0x080925B4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov ip, r0
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _08092624
	mov r0, ip
	ldrb r1, [r0, #0xa]
	movs r2, #0xfe
	mov r8, r2
	mov r0, r8
	ands r0, r1
	movs r3, #0
	mov r1, ip
	strb r0, [r1, #0xa]
	mov r6, ip
	adds r6, #0x8c
	str r3, [r6]
	mov r5, ip
	adds r5, #0x90
	str r3, [r5]
	mov r4, ip
	adds r4, #0x94
	strb r3, [r4]
	ldrb r1, [r1, #0xa]
	movs r2, #0xfb
	adds r0, r2, #0
	ands r0, r1
	mov r1, r8
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #0xa]
	str r3, [r6]
	str r3, [r5]
	strb r3, [r4]
	ldrb r0, [r1, #0xa]
	ands r2, r0
	strb r2, [r1, #0xa]
	ldr r1, _08092620 @ =gEnemyFnTable
	mov r2, ip
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _0809263E
	.align 2, 0
_08092620: .4byte gEnemyFnTable
_08092624:
	ldr r1, _08092648 @ =0x08369A78
	mov r2, ip
	ldrb r0, [r2, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r2, #0xd]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	mov r0, ip
	bl _call_via_r1
_0809263E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092648: .4byte 0x08369A78

	thumb_func_start FUN_0809264c
FUN_0809264c: @ 0x0809264C
	push {lr}
	ldr r2, _08092660 @ =0x08369A84
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08092660: .4byte 0x08369A84

	thumb_func_start FUN_08092664
FUN_08092664: @ 0x08092664
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0x1e
	bls _08092670
	b _08092910
_08092670:
	lsls r0, r0, #2
	ldr r1, _0809267C @ =_08092680
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809267C: .4byte _08092680
_08092680: @ jump table
	.4byte _080926FC @ case 0
	.4byte _080927BC @ case 1
	.4byte _08092910 @ case 2
	.4byte _08092910 @ case 3
	.4byte _08092910 @ case 4
	.4byte _08092910 @ case 5
	.4byte _08092910 @ case 6
	.4byte _08092910 @ case 7
	.4byte _08092910 @ case 8
	.4byte _08092910 @ case 9
	.4byte _080927E4 @ case 10
	.4byte _0809280C @ case 11
	.4byte _08092910 @ case 12
	.4byte _08092910 @ case 13
	.4byte _08092910 @ case 14
	.4byte _08092838 @ case 15
	.4byte _0809287A @ case 16
	.4byte _080928AC @ case 17
	.4byte _08092910 @ case 18
	.4byte _08092910 @ case 19
	.4byte _080928C8 @ case 20
	.4byte _08092910 @ case 21
	.4byte _08092910 @ case 22
	.4byte _08092910 @ case 23
	.4byte _08092910 @ case 24
	.4byte _08092910 @ case 25
	.4byte _08092910 @ case 26
	.4byte _08092910 @ case 27
	.4byte _08092910 @ case 28
	.4byte _08092910 @ case 29
	.4byte _08092908 @ case 30
_080926FC:
	ldrb r3, [r5, #0x10]
	cmp r3, #0
	bne _08092754
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r4, #1
	adds r0, r5, #0
	adds r0, #0x4c
	strb r3, [r0]
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
	strb r3, [r0]
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	strb r3, [r0]
	ldr r1, _08092750 @ =0x0000B601
	adds r0, r5, #0
	bl SetMotion
	strb r4, [r5, #0xe]
	b _08092794
	.align 2, 0
_08092750: .4byte 0x0000B601
_08092754:
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
_08092794:
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
	b _08092910
_080927BC:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _080927DC
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x58]
	movs r3, #0xe0
	lsls r3, r3, #6
	adds r0, r2, r3
	ldr r1, [r1, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
_080927DC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08092910
_080927E4:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _080927F6
	b _08092910
_080927F6:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08092804
	b _08092910
_08092804:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08092910
_0809280C:
	ldr r0, [r5, #0x54]
	ldr r1, _0809282C @ =0xFFFFD200
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, _08092830 @ =0xFFFFB000
	adds r0, r0, r3
	str r0, [r5, #0x58]
	ldr r1, _08092834 @ =0x0000B601
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _080928C2
	.align 2, 0
_0809282C: .4byte 0xFFFFD200
_08092830: .4byte 0xFFFFB000
_08092834: .4byte 0x0000B601
_08092838:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08092910
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08092858
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092910
_08092858:
	ldrb r1, [r5, #0x13]
	cmp r1, #0xfb
	bhi _08092864
	adds r0, r1, #3
	strb r0, [r5, #0x13]
	b _08092870
_08092864:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08092870:
	ldrb r1, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	b _08092910
_0809287A:
	movs r1, #0xb6
	lsls r1, r1, #8
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
_080928AC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080928C2
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092910
_080928C2:
	movs r0, #0x14
	strb r0, [r5, #0xe]
	b _08092910
_080928C8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x10]
	cmp r0, #1
	bne _08092910
	ldr r3, [r5, #0x28]
	ldr r2, [r5, #0x54]
	movs r1, #0x98
	lsls r1, r1, #5
	adds r0, r2, r1
	ldr r1, [r3, #0x54]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r2, [r5, #0x58]
	movs r1, #0xe8
	lsls r1, r1, #6
	adds r0, r2, r1
	ldr r1, [r3, #0x58]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	b _08092910
_08092908:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08092910:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08092918
FUN_08092918: @ 0x08092918
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0809296C
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08092974 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08092978 @ =0x0000270E
	cmp r1, r0
	bhi _08092948
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08092948:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809297C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809296C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08092974: .4byte gMission
_08092978: .4byte 0x0000270E
_0809297C: .4byte gEnemyFnTable

	thumb_func_start FUN_08092980
FUN_08092980: @ 0x08092980
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08092990
	cmp r0, #1
	beq _08092994
	b _080929C2
_08092990:
	movs r0, #1
	strb r0, [r5, #0xe]
_08092994:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080929C2
	ldrb r1, [r5, #0xa]
	movs r4, #0
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xb6
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	strb r6, [r5, #0xd]
	strb r4, [r5, #0xe]
_080929C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080929c8
FUN_080929c8: @ 0x080929C8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080929D8
	cmp r0, #1
	beq _080929DC
	b _080929E4
_080929D8:
	movs r0, #1
	strb r0, [r2, #0xe]
_080929DC:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080929E4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080929e8
FUN_080929e8: @ 0x080929E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080929F8
	cmp r5, #1
	beq _08092A34
	b _08092A54
_080929F8:
	movs r1, #0xb6
	lsls r1, r1, #8
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
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08092A5C @ =0x08369AD4
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092A34:
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
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08092A54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092A5C: .4byte 0x08369AD4

	thumb_func_start FUN_08092a60
FUN_08092a60: @ 0x08092A60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08092A70
	cmp r0, #1
	beq _08092A74
	b _08092AA0
_08092A70:
	movs r0, #1
	strb r0, [r5, #0xe]
_08092A74:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08092AA0
	ldrb r1, [r5, #0xa]
	movs r4, #0
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08092AA8 @ =0x0000B601
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	strb r6, [r5, #0xd]
	strb r4, [r5, #0xe]
_08092AA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092AA8: .4byte 0x0000B601

	thumb_func_start FUN_08092aac
FUN_08092aac: @ 0x08092AAC
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08092ABC
	cmp r0, #1
	beq _08092AC0
	b _08092AC8
_08092ABC:
	movs r0, #1
	strb r0, [r2, #0xe]
_08092AC0:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08092AC8:
	pop {r0}
	bx r0

	thumb_func_start FUN_08092acc
FUN_08092acc: @ 0x08092ACC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08092ADC
	cmp r5, #1
	beq _08092B16
	b _08092B46
_08092ADC:
	ldr r1, _08092B4C @ =0x0000B601
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
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08092B50 @ =0x08369B04
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092B16:
	ldrb r0, [r4, #0x12]
	adds r0, #2
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08092B46:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092B4C: .4byte 0x0000B601
_08092B50: .4byte 0x08369B04

	thumb_func_start FUN_08092b54
FUN_08092b54: @ 0x08092B54
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08092B64
	cmp r0, #1
	beq _08092B68
	b _08092B94
_08092B64:
	movs r0, #1
	strb r0, [r5, #0xe]
_08092B68:
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08092B94
	ldrb r1, [r5, #0xa]
	movs r4, #0
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08092B9C @ =0x0000B602
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	strb r6, [r5, #0xd]
	strb r4, [r5, #0xe]
_08092B94:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092B9C: .4byte 0x0000B602

	thumb_func_start FUN_08092ba0
FUN_08092ba0: @ 0x08092BA0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _08092BB0
	cmp r0, #1
	beq _08092BB4
	b _08092BBC
_08092BB0:
	movs r0, #1
	strb r0, [r2, #0xe]
_08092BB4:
	movs r1, #0
	movs r0, #2
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08092BBC:
	pop {r0}
	bx r0

	thumb_func_start FUN_08092bc0
FUN_08092bc0: @ 0x08092BC0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08092BD0
	cmp r5, #1
	beq _08092C0C
	b _08092C56
_08092BD0:
	ldr r1, _08092C3C @ =0x0000B602
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
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08092C40 @ =0x08369AA4
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	str r5, [r4, #0x2c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092C0C:
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
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #4
	beq _08092C44
	cmp r0, #8
	beq _08092C4C
	b _08092C56
	.align 2, 0
_08092C3C: .4byte 0x0000B602
_08092C40: .4byte 0x08369AA4
_08092C44:
	movs r1, #0
	str r1, [r4, #0x2c]
	movs r0, #3
	b _08092C52
_08092C4C:
	movs r1, #0
	str r1, [r4, #0x2c]
	movs r0, #7
_08092C52:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08092C56:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08092c5c
FUN_08092c5c: @ 0x08092C5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08092C7C
	ldrb r0, [r4, #0xe]
	cmp r0, #9
	bhi _08092C7C
	movs r0, #0xa
	strb r0, [r4, #0xe]
_08092C7C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xb
	bls _08092C84
	b _08092F04
_08092C84:
	lsls r0, r0, #2
	ldr r1, _08092C90 @ =_08092C94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08092C90: .4byte _08092C94
_08092C94: @ jump table
	.4byte _08092CC4 @ case 0
	.4byte _08092D08 @ case 1
	.4byte _08092DE0 @ case 2
	.4byte _08092DF6 @ case 3
	.4byte _08092E74 @ case 4
	.4byte _08092F04 @ case 5
	.4byte _08092F04 @ case 6
	.4byte _08092F04 @ case 7
	.4byte _08092F04 @ case 8
	.4byte _08092F04 @ case 9
	.4byte _08092EC2 @ case 10
	.4byte _08092ED0 @ case 11
_08092CC4:
	ldr r1, _08092DC0 @ =0x0000B603
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
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
	ldr r0, _08092DC4 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _08092DC8 @ =0x00001DFF
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldr r0, [r2, #0x54]
	str r0, [r4, #0x64]
	movs r0, #0x98
	lsls r0, r0, #1
	bl PlaySound
_08092D08:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	adds r1, r0, #1
	strb r1, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092DB2
	movs r5, #0
	ldr r2, _08092DCC @ =0x08369CCC
	mov sl, r2
	ldr r6, _08092DD0 @ =RNG_0202f388
	ldr r0, _08092DD4 @ =0x000343FD
	mov sb, r0
	ldr r1, _08092DD8 @ =0x00269EC3
	mov r8, r1
	movs r7, #7
_08092D52:
	adds r0, r5, #0
	movs r1, #5
	bl __modsi3
	lsls r0, r0, #3
	mov r2, sl
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r6]
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	add r1, r8
	lsls r1, r1, #1
	lsrs r2, r1, #1
	str r2, [r6]
	lsrs r1, r1, #0x11
	ands r1, r7
	subs r1, #3
	adds r1, r1, r3
	lsls r1, r1, #8
	str r1, [sp]
	ldr r1, _08092DDC @ =0x08369CD0
	adds r0, r0, r1
	ldr r3, [r0]
	mov r0, sb
	muls r0, r2, r0
	add r0, r8
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ands r0, r7
	subs r0, #3
	adds r0, r0, r3
	lsls r0, r0, #8
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_080c4eac
	adds r5, #1
	cmp r5, #4
	ble _08092D52
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
_08092DB2:
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xe]
	cmp r0, #1
	bhi _08092DBC
	b _08092F04
_08092DBC:
	b _08092E62
	.align 2, 0
_08092DC0: .4byte 0x0000B603
_08092DC4: .4byte gStageRun+232
_08092DC8: .4byte 0x00001DFF
_08092DCC: .4byte 0x08369CCC
_08092DD0: .4byte RNG_0202f388
_08092DD4: .4byte 0x000343FD
_08092DD8: .4byte 0x00269EC3
_08092DDC: .4byte 0x08369CD0
_08092DE0:
	ldr r1, _08092E6C @ =0x0000B602
	adds r0, r4, #0
	bl SetMotion
	movs r0, #3
	strb r0, [r4, #0x12]
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092DF6:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _08092F04
	subs r0, #1
	strb r0, [r4, #0x13]
	movs r5, #0xff
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08092F04
	ldr r0, [r4, #0x54]
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r0, r2
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r0, r1
	add r1, sp, #8
	str r0, [r1, #4]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080afe84
	ldr r0, _08092E70 @ =0x00000131
	bl PlaySound
	movs r0, #8
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08092F04
	subs r0, #1
	strb r0, [r4, #0x12]
	ands r0, r5
	cmp r0, #0
	bne _08092F04
_08092E62:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08092F04
	.align 2, 0
_08092E6C: .4byte 0x0000B602
_08092E70: .4byte 0x00000131
_08092E74:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r3, [r4, #0x28]
	ldr r1, [r0]
	ldr r0, [r3, #0x54]
	adds r1, r1, r0
	ldr r2, [r4, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r3, #0x58]
	adds r1, r1, r0
	ldr r2, [r4, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #4
	beq _08092F04
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08092F04
_08092EC2:
	ldr r1, _08092F14 @ =0x0000B602
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08092ED0:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r2, [r4, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08092F04:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092F14: .4byte 0x0000B602

	thumb_func_start FUN_08092f18
FUN_08092f18: @ 0x08092F18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _08092F38
	ldrb r0, [r5, #0xe]
	cmp r0, #0x13
	bhi _08092F38
	movs r0, #0x14
	strb r0, [r5, #0xe]
_08092F38:
	ldr r0, _08092F70 @ =gGameState
	ldr r1, _08092F74 @ =0x000064AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08092F5E
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _08092F54
	strb r2, [r5, #0xf]
_08092F54:
	ldrb r0, [r5, #0xe]
	cmp r0, #0x13
	bhi _08092F5E
	movs r0, #0x14
	strb r0, [r5, #0xe]
_08092F5E:
	ldrb r0, [r5, #0xe]
	cmp r0, #0x15
	bls _08092F66
	b _0809355C
_08092F66:
	lsls r0, r0, #2
	ldr r1, _08092F78 @ =_08092F7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08092F70: .4byte gGameState
_08092F74: .4byte 0x000064AC
_08092F78: .4byte _08092F7C
_08092F7C: @ jump table
	.4byte _08092FD4 @ case 0
	.4byte _08093000 @ case 1
	.4byte _0809304C @ case 2
	.4byte _080930DC @ case 3
	.4byte _080930F2 @ case 4
	.4byte _08093146 @ case 5
	.4byte _080932E0 @ case 6
	.4byte _0809355C @ case 7
	.4byte _0809355C @ case 8
	.4byte _0809355C @ case 9
	.4byte _08093498 @ case 10
	.4byte _080934BA @ case 11
	.4byte _0809355C @ case 12
	.4byte _0809355C @ case 13
	.4byte _0809355C @ case 14
	.4byte _0809355C @ case 15
	.4byte _0809355C @ case 16
	.4byte _0809355C @ case 17
	.4byte _0809355C @ case 18
	.4byte _0809355C @ case 19
	.4byte _08093510 @ case 20
	.4byte _08093528 @ case 21
_08092FD4:
	ldr r1, _0809303C @ =0x0000B603
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x28
	strb r0, [r5, #0x12]
	movs r0, #0x90
	lsls r0, r0, #5
	str r0, [r5, #0x5c]
	ldr r0, _08093040 @ =0xFFFFF800
	str r0, [r5, #0x60]
	ldr r0, _08093044 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r2, _08093048 @ =0xFFFFF7FF
	adds r0, r0, r2
	str r0, [r5, #0x68]
	ldr r0, [r5, #0x28]
	ldr r0, [r0, #0x54]
	str r0, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093000:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08093024
	b _0809355C
_08093024:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08093030
	b _0809355C
_08093030:
	movs r0, #0x98
	lsls r0, r0, #1
	bl PlaySound
	b _080934AE
	.align 2, 0
_0809303C: .4byte 0x0000B603
_08093040: .4byte 0xFFFFF800
_08093044: .4byte gStageRun+232
_08093048: .4byte 0xFFFFF7FF
_0809304C:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080930BE
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r7, #0xe0
	lsls r7, r7, #3
	adds r0, r0, r7
	str r0, [sp, #4]
	movs r4, #0
	ldr r7, _080930D8 @ =0x08369CF4
	add r6, sp, #8
_0809309E:
	ldr r0, [r7]
	lsls r0, r0, #8
	str r0, [sp, #8]
	ldr r0, [r7, #4]
	lsls r0, r0, #8
	str r0, [r6, #4]
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	mov r1, sp
	adds r2, r6, #0
	bl FUN_080c4f60
	adds r4, #1
	cmp r4, #5
	ble _0809309E
_080930BE:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080930C6
	b _0809355C
_080930C6:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080930D2
	b _0809355C
_080930D2:
	movs r0, #0xe
	b _080934B0
	.align 2, 0
_080930D8: .4byte 0x08369CF4
_080930DC:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _080930E4
	b _0809355C
_080930E4:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080930F0
	b _0809355C
_080930F0:
	b _080934B2
_080930F2:
	ldr r1, _0809325C @ =0x0000B602
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	ldr r0, _08093260 @ =gGameState
	ldr r1, _08093264 @ =0x000064AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r0, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093132
	ldr r0, [r5, #0x28]
	bl FUN_080b009c
	cmp r0, #0
	beq _0809311C
	str r5, [r0, #0x2c]
_0809311C:
	ldr r0, [r5, #0x28]
	bl CreateGhost83
	str r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809312A
	str r5, [r0, #0x2c]
_0809312A:
	ldr r1, _08093268 @ =gPaletteManager
	ldr r2, _0809326C @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
_08093132:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #0
	str r0, [r1]
	ldr r0, _08093270 @ =0x00000135
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093146:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r4, r5, #0
	adds r4, #0xbc
	ldr r1, [r4]
	movs r0, #0x88
	lsls r0, r0, #6
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4]
	asrs r1, r1, #9
	adds r0, r5, #0
	adds r0, #0x74
	movs r2, #0x17
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	ldr r2, _08093274 @ =0x08369A8C
	adds r1, r1, r2
	bl SetDDP
	ldr r2, _08093278 @ =0x020302B0
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	asrs r6, r0, #9
	str r6, [r2]
	ldr r0, _08093260 @ =gGameState
	ldr r3, _08093264 @ =0x000064AC
	adds r3, r3, r0
	mov sb, r3
	ldr r0, [r3]
	ldrb r1, [r0, #0xa]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	mov r8, r4
	cmp r0, #0
	beq _080931F6
	ldr r4, _0809327C @ =gWindowRegBuffer
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, _08093280 @ =gStageRun+232
	ldr r1, [r2, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	movs r3, #0xff
	ands r0, r3
	strh r0, [r4, #6]
	ldr r1, [r5, #0x60]
	ldr r0, [r5, #0x58]
	adds r1, r1, r0
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	ldr r0, [r2, #0x3c]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r1, r2
	asrs r0, r0, #8
	subs r0, r0, r6
	ands r0, r3
	asrs r1, r1, #8
	adds r1, r6, r1
	lsls r1, r1, #8
	orrs r0, r1
	strh r0, [r4, #0xa]
_080931F6:
	ldr r3, _08093284 @ =0x020302B4
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x58]
	adds r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r2, _08093280 @ =gStageRun+232
	ldr r1, [r2, #0x3c]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r3]
	ldr r3, _08093288 @ =0x020302AC
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x54]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r2, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r3]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	mov r2, sb
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08093296
	ldr r1, _08093268 @ =gPaletteManager
	ldr r3, _0809326C @ =0x0000FFFF
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r1, [r5, #0x12]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0809328C
	ldr r0, _0809327C @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	strb r7, [r0, #0xd]
	b _08093296
	.align 2, 0
_0809325C: .4byte 0x0000B602
_08093260: .4byte gGameState
_08093264: .4byte 0x000064AC
_08093268: .4byte gPaletteManager
_0809326C: .4byte 0x0000FFFF
_08093270: .4byte 0x00000135
_08093274: .4byte 0x08369A8C
_08093278: .4byte 0x020302B0
_0809327C: .4byte gWindowRegBuffer
_08093280: .4byte gStageRun+232
_08093284: .4byte 0x020302B4
_08093288: .4byte 0x020302AC
_0809328C:
	ldr r2, _080932CC @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _080932D0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
_08093296:
	ldr r1, [r5, #0x2c]
	cmp r1, #0
	beq _080932B2
	ldr r0, _080932D4 @ =0x020302AC
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r5, #0x2c]
	ldr r0, _080932D8 @ =0x020302B4
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r5, #0x2c]
	ldr r0, _080932DC @ =0x020302B0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
_080932B2:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	mov r7, r8
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080932C6
	b _0809355C
_080932C6:
	str r1, [r7]
	movs r0, #0x3c
	b _080934B0
	.align 2, 0
_080932CC: .4byte gWindowRegBuffer
_080932D0: .4byte 0x0000BFFF
_080932D4: .4byte 0x020302AC
_080932D8: .4byte 0x020302B4
_080932DC: .4byte 0x020302B0
_080932E0:
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	ldr r0, [r5, #0x68]
	adds r0, #0xbb
	str r0, [r5, #0x68]
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r6, r5, #0
	adds r6, #0xbc
	ldr r1, [r6]
	subs r1, #0x66
	str r1, [r6]
	asrs r1, r1, #9
	adds r4, r5, #0
	adds r4, #0x74
	movs r0, #0x17
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080933FC @ =0x08369A8C
	adds r1, r1, r0
	adds r0, r4, #0
	bl SetDDP
	ldrb r1, [r5, #0x12]
	movs r0, #1
	ands r0, r1
	str r4, [sp, #0x10]
	ldr r2, _08093400 @ =0x020302B0
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	subs r0, r0, r1
	asrs r0, r0, #9
	str r0, [r2]
	ldr r1, _08093404 @ =0x0203700C
	ldr r0, [r1]
	ldrb r1, [r0, #0xa]
	movs r3, #1
	mov sl, r3
	mov r0, sl
	ands r0, r1
	ldr r7, [r5, #0x54]
	mov sb, r7
	ldr r1, [r5, #0x58]
	str r1, [sp, #0x14]
	ldr r3, _08093408 @ =gStageRun+232
	mov ip, r3
	ldr r7, [r5, #0x5c]
	mov r8, r7
	ldr r6, [r5, #0x60]
	cmp r0, #0
	beq _0809339E
	ldr r4, _0809340C @ =gWindowRegBuffer
	mov r0, r8
	add r0, sb
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r3, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	movs r3, #0xff
	ands r0, r3
	strh r0, [r4, #6]
	ldr r7, [sp, #0x14]
	adds r1, r6, r7
	movs r0, #0xa0
	lsls r0, r0, #7
	adds r1, r1, r0
	mov r7, ip
	ldr r0, [r7, #0x3c]
	subs r1, r1, r0
	movs r7, #0x80
	lsls r7, r7, #6
	adds r0, r1, r7
	asrs r0, r0, #8
	ldr r2, [r2]
	subs r0, r0, r2
	ands r0, r3
	asrs r1, r1, #8
	adds r2, r2, r1
	lsls r2, r2, #8
	orrs r0, r2
	strh r0, [r4, #0xa]
_0809339E:
	ldr r2, _08093410 @ =0x020302B4
	ldr r1, [sp, #0x14]
	adds r0, r6, r1
	movs r3, #0xa0
	lsls r3, r3, #7
	adds r0, r0, r3
	mov r7, ip
	ldr r1, [r7, #0x3c]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r2]
	ldr r2, _08093414 @ =0x020302AC
	mov r0, r8
	add r0, sb
	movs r1, #0xf0
	lsls r1, r1, #7
	adds r0, r0, r1
	ldr r1, [r7, #0x38]
	subs r0, r0, r1
	asrs r0, r0, #8
	str r0, [r2]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r2, _08093404 @ =0x0203700C
	ldr r0, [r2]
	ldrb r1, [r0, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08093436
	ldr r1, _08093418 @ =gPaletteManager
	ldr r3, _0809341C @ =0x0000FFFF
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r1, [r5, #0x12]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08093424
	ldr r2, _0809340C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093420 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _08093436
	.align 2, 0
_080933FC: .4byte 0x08369A8C
_08093400: .4byte 0x020302B0
_08093404: .4byte 0x0203700C
_08093408: .4byte gStageRun+232
_0809340C: .4byte gWindowRegBuffer
_08093410: .4byte 0x020302B4
_08093414: .4byte 0x020302AC
_08093418: .4byte gPaletteManager
_0809341C: .4byte 0x0000FFFF
_08093420: .4byte 0x0000BFFF
_08093424:
	ldr r0, _08093480 @ =gWindowRegBuffer
	ldrh r2, [r0]
	movs r7, #0x80
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r1, r2
	strh r1, [r0]
	mov r1, sl
	strb r1, [r0, #0xd]
_08093436:
	ldr r1, [r5, #0x2c]
	cmp r1, #0
	beq _08093452
	ldr r0, _08093484 @ =0x020302AC
	ldr r0, [r0]
	str r0, [r1, #0x74]
	ldr r1, [r5, #0x2c]
	ldr r0, _08093488 @ =0x020302B4
	ldr r0, [r0]
	str r0, [r1, #0x78]
	ldr r1, [r5, #0x2c]
	ldr r0, _0809348C @ =0x020302B0
	ldr r0, [r0]
	str r0, [r1, #0x7c]
_08093452:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _0809345A
	b _0809355C
_0809345A:
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809355C
	ldr r2, _08093480 @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093490 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08093494 @ =0x08369AA4
	ldr r0, [sp, #0x10]
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _0809355C
	.align 2, 0
_08093480: .4byte gWindowRegBuffer
_08093484: .4byte 0x020302AC
_08093488: .4byte 0x020302B4
_0809348C: .4byte 0x020302B0
_08093490: .4byte 0x0000BFFF
_08093494: .4byte 0x08369AA4
_08093498:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809355C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809355C
_080934AE:
	movs r0, #0x28
_080934B0:
	strb r0, [r5, #0x12]
_080934B2:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809355C
_080934BA:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r3, [r5, #0x28]
	ldr r1, [r0]
	ldr r0, [r3, #0x54]
	adds r1, r1, r0
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r1, [r0]
	ldr r0, [r3, #0x58]
	adds r1, r1, r0
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809355C
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809355C
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
	b _0809355C
_08093510:
	ldr r2, _0809356C @ =gWindowRegBuffer
	ldrh r1, [r2]
	ldr r0, _08093570 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08093574 @ =0x0000B602
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08093528:
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r2, [r5, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x54]
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	ldr r1, [r5, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0809355C:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809356C: .4byte gWindowRegBuffer
_08093570: .4byte 0x0000BFFF
_08093574: .4byte 0x0000B602

	thumb_func_start nop_08093578
nop_08093578: @ 0x08093578
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809357c
FUN_0809357c: @ 0x0809357C
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	beq _0809358C
	cmp r0, #1
	beq _08093590
	b _080935B0
_0809358C:
	movs r0, #1
	strb r0, [r3, #0xe]
_08093590:
	adds r0, r3, #0
	adds r0, #0xb8
	ldr r2, [r3, #0x28]
	ldr r0, [r0]
	ldr r1, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r1, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r3, #0x54]
	adds r0, r3, #0
	bl UpdateMotionGraphic
_080935B0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080935b4
FUN_080935b4: @ 0x080935B4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _08093620 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08093618
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093624 @ =gEnemyFnTable
	movs r1, #0x3d
	strb r1, [r4, #9]
	adds r0, #0xf4
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	strb r2, [r4, #0x10]
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	lsls r1, r6, #0xc
	subs r0, r0, r1
	ldr r1, _08093628 @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [r4, #0x58]
	strb r7, [r4, #0x12]
	str r5, [r4, #0x28]
_08093618:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093620: .4byte gZakoHeaderPtr
_08093624: .4byte gEnemyFnTable
_08093628: .4byte 0xFFFFE400

	thumb_func_start nop_0809362c
nop_0809362c: @ 0x0809362C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093630
FUN_08093630: @ 0x08093630
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080936A0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080936A4 @ =0x08369E00
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080936A8 @ =0x08369D40
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _080936AC @ =nop_0809362c
	str r0, [r5, #0x24]
	adds r2, r4, #0
	adds r2, #0xb4
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_080936b0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080936A0: .4byte gEnemyFnTable
_080936A4: .4byte 0x08369E00
_080936A8: .4byte 0x08369D40
_080936AC: .4byte nop_0809362c

	thumb_func_start FUN_080936b0
FUN_080936b0: @ 0x080936B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _080936D4
	ldr r1, _080936D0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _080936F4
	.align 2, 0
_080936D0: .4byte gEnemyFnTable
_080936D4:
	ldr r1, _080936FC @ =0x08369D38
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093700 @ =0x08369D3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080936F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080936FC: .4byte 0x08369D38
_08093700: .4byte 0x08369D3C

	thumb_func_start FUN_08093704
FUN_08093704: @ 0x08093704
	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x28]
	ldrb r1, [r2, #0xe]
	cmp r1, #0
	beq _08093716
	cmp r1, #1
	beq _08093732
	b _0809374A
_08093716:
	adds r0, r2, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08093732:
	ldrb r0, [r3, #0xc]
	cmp r0, #2
	bls _0809374A
	ldr r1, _08093750 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r2, #0x14]
_0809374A:
	pop {r0}
	bx r0
	.align 2, 0
_08093750: .4byte gEnemyFnTable

	thumb_func_start FUN_08093754
FUN_08093754: @ 0x08093754
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093758
FUN_08093758: @ 0x08093758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08093770
	cmp r0, #1
	beq _0809377C
	b _08093926
_08093770:
	str r0, [r6, #0x5c]
	str r0, [r6, #0x64]
	str r0, [r6, #0x68]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809377C:
	ldr r3, [r6, #0x68]
	cmp r3, #0
	bne _080937AC
	adds r2, r6, #0
	adds r2, #0xb4
	ldr r0, [r2]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x64]
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldr r1, _080937A8 @ =0x000021BF
	adds r4, r2, #0
	cmp r0, r1
	ble _080937B4
	str r3, [r6, #0x64]
	movs r0, #0x3c
	str r0, [r6, #0x68]
	b _080937B4
	.align 2, 0
_080937A8: .4byte 0x000021BF
_080937AC:
	subs r0, r3, #1
	str r0, [r6, #0x68]
	adds r4, r6, #0
	adds r4, #0xb4
_080937B4:
	ldr r0, [r4]
	ldr r5, _08093808 @ =0x0000CA80
	adds r1, r5, #0
	bl __umodsi3
	str r0, [r4]
	movs r4, #0x87
	lsls r4, r4, #4
	adds r7, r0, r4
	adds r0, r7, #0
	adds r1, r5, #0
	bl __umodsi3
	adds r7, r0, #0
	adds r1, r4, #0
	bl __udivsi3
	adds r7, r0, #0
	movs r0, #0x17
	subs r7, r0, r7
	ldrb r0, [r6, #0x12]
	mov r1, r8
	adds r1, #0xb4
	adds r2, r1, r0
	ldrb r4, [r2]
	adds r3, r1, #0
	cmp r4, #0
	beq _0809381A
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093810
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0809380C
	movs r0, #0
	b _0809380E
	.align 2, 0
_08093808: .4byte 0x0000CA80
_0809380C:
	subs r0, r4, #1
_0809380E:
	strb r0, [r2]
_08093810:
	ldrb r0, [r6, #0x12]
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809381E
_0809381A:
	movs r4, #2
	b _08093826
_0809381E:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	movs r1, #1
	subs r4, r1, r0
_08093826:
	subs r0, r7, #4
	cmp r0, #3
	bhi _08093858
	ldrb r0, [r6, #0x12]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08093848
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093844 @ =0x08369DB8
	bl SetDDP
	b _08093896
	.align 2, 0
_08093844: .4byte 0x08369DB8
_08093848:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093854 @ =0x08369D58
	bl SetDDP
	b _08093896
	.align 2, 0
_08093854: .4byte 0x08369D58
_08093858:
	adds r0, r7, #0
	subs r0, #0x11
	cmp r0, #3
	bhi _0809388C
	ldrb r0, [r6, #0x12]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809387C
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093878 @ =0x08369DD0
	bl SetDDP
	b _08093896
	.align 2, 0
_08093878: .4byte 0x08369DD0
_0809387C:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _08093888 @ =0x08369D88
	bl SetDDP
	b _08093896
	.align 2, 0
_08093888: .4byte 0x08369D88
_0809388C:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _080938B8 @ =0x08369D40
	bl SetDDP
_08093896:
	adds r0, r7, #0
	subs r0, #0xb
	cmp r0, #2
	bhi _080938A2
	cmp r4, #2
	bne _080938AE
_080938A2:
	adds r0, r7, #0
	subs r0, #0xa
	cmp r0, #4
	bhi _080938BC
	cmp r4, #2
	bne _080938BC
_080938AE:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08093904
	.align 2, 0
_080938B8: .4byte 0x08369D40
_080938BC:
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0xa]
	cmp r4, #2
	bne _080938D0
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	b _080938D6
_080938D0:
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #0
_080938D6:
	strb r0, [r1]
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	movs r2, #0x8b
	lsls r2, r2, #8
	adds r0, r7, r2
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r6, #0
	bl SetMotion
	ldr r0, _08093918 @ =0x08369DE8
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r0, #0x18
	adds r1, r6, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08093904:
	ldr r0, [r6, #0x5c]
	cmp r0, r4
	beq _08093926
	str r4, [r6, #0x5c]
	cmp r4, #1
	bne _0809391C
	movs r0, #0x91
	bl PlaySound
	b _08093926
	.align 2, 0
_08093918: .4byte 0x08369DE8
_0809391C:
	cmp r4, #2
	bne _08093926
	movs r0, #0x93
	bl PlaySound
_08093926:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08093930
FUN_08093930: @ 0x08093930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809398C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08093984
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08093990 @ =gEnemyFnTable
	movs r1, #0x3e
	strb r1, [r3, #9]
	adds r0, #0xf8
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
	movs r0, #2
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xbd
	strb r4, [r0]
_08093984:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809398C: .4byte gZakoHeaderPtr
_08093990: .4byte gEnemyFnTable

	thumb_func_start FUN_08093994
FUN_08093994: @ 0x08093994
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080939E0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _080939DA
	adds r2, r4, #0
	adds r2, #0x25
	movs r3, #0
	movs r1, #0x18
	strb r1, [r2]
	ldr r1, _080939E4 @ =gEnemyFnTable
	movs r2, #0x3e
	strb r2, [r4, #9]
	adds r1, #0xf8
	ldr r1, [r1]
	ldr r1, [r1]
	str r1, [r4, #0x14]
	movs r1, #0
	strh r3, [r4, #0x20]
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	ldrb r2, [r4, #0xb]
	movs r1, #0x10
	orrs r1, r2
	strb r1, [r4, #0xb]
	ldrb r1, [r4, #0x1c]
	strb r1, [r4, #0x1d]
	movs r1, #1
	strb r1, [r4, #0x10]
	str r5, [r4, #0x28]
_080939DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080939E0: .4byte gZakoHeaderPtr
_080939E4: .4byte gEnemyFnTable

	thumb_func_start FUN_080939e8
FUN_080939e8: @ 0x080939E8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08093A14 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _080939FC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_080939FC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093A18
	movs r0, #0
	b _08093A1A
	.align 2, 0
_08093A14: .4byte 0xFFFFF200
_08093A18:
	movs r0, #1
_08093A1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a20
FUN_08093a20: @ 0x08093A20
	push {lr}
	movs r3, #0
	ldr r1, _08093A50 @ =pZero2
	ldr r1, [r1]
	ldr r2, [r0, #0x54]
	ldr r0, [r1, #0x54]
	cmp r2, r0
	ble _08093A32
	movs r3, #1
_08093A32:
	ldr r1, _08093A54 @ =0xFFFFA000
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #0xe
	adds r0, r0, r1
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _08093A58 @ =0x00000FFF
	cmp r0, r1
	bls _08093A5C
	adds r0, r3, #0
	b _08093A5E
	.align 2, 0
_08093A50: .4byte pZero2
_08093A54: .4byte 0xFFFFA000
_08093A58: .4byte 0x00000FFF
_08093A5C:
	movs r0, #2
_08093A5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093a64
FUN_08093a64: @ 0x08093A64
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _08093A90
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08093A8C @ =0x000007FF
	cmp r1, r0
	bgt _08093A90
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _08093A92
	.align 2, 0
_08093A8C: .4byte 0x000007FF
_08093A90:
	movs r0, #0
_08093A92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093a98
FUN_08093a98: @ 0x08093A98
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _08093AEE
	cmp r5, #0
	bge _08093AC8
	ldr r0, [r4, #0x54]
	ldr r1, _08093AC0 @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AC4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #1
	b _08093AF0
	.align 2, 0
_08093AC0: .4byte 0xFFFFF200
_08093AC4: .4byte 0xFFFFF600
_08093AC8:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08093AE4 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08093AE8
	movs r0, #2
	b _08093AF0
	.align 2, 0
_08093AE4: .4byte 0xFFFFF600
_08093AE8:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_08093AEE:
	movs r0, #0
_08093AF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_08093af8
nop_08093af8: @ 0x08093AF8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08093afc
FUN_08093afc: @ 0x08093AFC
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08093B48
	ldr r1, _08093B3C @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08093B40
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08093B42
	strb r4, [r2, #0xd]
	b _08093B44
	.align 2, 0
_08093B3C: .4byte gEnemyFnTable
_08093B40:
	movs r0, #1
_08093B42:
	strb r0, [r2, #0xd]
_08093B44:
	movs r0, #1
	b _08093B4A
_08093B48:
	movs r0, #0
_08093B4A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08093b50
FUN_08093b50: @ 0x08093B50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _08093BD6
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _08093BD6
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08093B70
	cmp r0, #1
	beq _08093BB4
	b _08093BD6
_08093B70:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08093BD6
	ldr r1, _08093BAC @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093BB0 @ =0x08369E3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08093BA6:
	movs r0, #1
	b _08093BD8
	.align 2, 0
_08093BAC: .4byte 0x08369E18
_08093BB0: .4byte 0x08369E3C
_08093BB4:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08093BD4
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093BD0 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093BA6
	strb r5, [r4, #0xf]
	b _08093BD6
	.align 2, 0
_08093BD0: .4byte 0x00020001
_08093BD4:
	strb r0, [r4, #0xf]
_08093BD6:
	movs r0, #0
_08093BD8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08093be0
FUN_08093be0: @ 0x08093BE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _08093C20
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093C20
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _08093C0C
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _08093C20
_08093C0C:
	ldr r2, _08093C28 @ =0x08369EB4
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _08093C20
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08093C20:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093C28: .4byte 0x08369EB4

	thumb_func_start FUN_08093c2c
FUN_08093c2c: @ 0x08093C2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x10]
	cmp r0, #2
	bne _08093C3E
	movs r0, #0
	strb r0, [r5, #0x10]
	movs r0, #1
	b _08093C40
_08093C3E:
	movs r0, #0
_08093C40:
	strb r0, [r5, #0x11]
	ldr r1, _08093CC0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08093CC4 @ =0x08369EBC
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r6, [r5, #0x10]
	cmp r6, #0
	bne _08093D12
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08093CC8 @ =0x08369E6C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08093CCC @ =nop_08093af8
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, #4
	str r6, [r0]
	movs r2, #0
	ldr r0, _08093CD0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08093CB2
	movs r2, #1
_08093CB2:
	cmp r2, #0
	beq _08093CD4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08093CDA
	.align 2, 0
_08093CC0: .4byte gEnemyFnTable
_08093CC4: .4byte 0x08369EBC
_08093CC8: .4byte 0x08369E6C
_08093CCC: .4byte nop_08093af8
_08093CD0: .4byte pZero2
_08093CD4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08093CDA:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	bl FUN_08093994
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08093D0A
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #0
	b _08093D10
_08093D0A:
	adds r1, r5, #0
	adds r1, #0xbc
	movs r0, #3
_08093D10:
	strb r0, [r1]
_08093D12:
	adds r0, r5, #0
	bl FUN_08093d20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08093d20
FUN_08093d20: @ 0x08093D20
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08093afc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08093D66
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08093D46
	adds r0, r4, #0
	bl FUN_08093be0
	adds r0, r4, #0
	bl FUN_08093b50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08093D66
_08093D46:
	ldr r1, _08093D6C @ =0x08369E18
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08093D70 @ =0x08369E3C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08093D66:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093D6C: .4byte 0x08369E18
_08093D70: .4byte 0x08369E3C

	thumb_func_start FUN_08093d74
FUN_08093d74: @ 0x08093D74
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08093DC8
	ldr r0, _08093DC0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08093DC8
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
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
	ldr r1, _08093DC4 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _08093DD8
	.align 2, 0
_08093DC0: .4byte gCurStory
_08093DC4: .4byte gEnemyFnTable
_08093DC8:
	ldr r0, _08093DDC @ =0x08369E60
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_08093DD8:
	pop {r0}
	bx r0
	.align 2, 0
_08093DDC: .4byte 0x08369E60
_08093DE0:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08093de4
FUN_08093de4: @ 0x08093DE4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093E00 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093DFC
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08093DFC:
	pop {r0}
	bx r0
	.align 2, 0
_08093E00: .4byte 0x00020001

	thumb_func_start FUN_08093e04
FUN_08093e04: @ 0x08093E04
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _08093E1A
	bl isKilled
	cmp r0, #0
	beq _08093E3A
_08093E1A:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08093E58 @ =0x08369E6C
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08093E3A
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093E3A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08093E5C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08093E50
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093E50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093E58: .4byte 0x08369E6C
_08093E5C: .4byte 0x00020001

	thumb_func_start FUN_08093e60
FUN_08093e60: @ 0x08093E60
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08093E70
	cmp r5, #1
	beq _08093E98
	b _08093ED6
_08093E70:
	ldr r1, _08093EDC @ =0x00008E04
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08093EE0 @ =0x08369E84
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08093E98:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _08093ED0
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08093EB4
	str r1, [r4, #0x60]
_08093EB4:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08093ED0
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08093ED0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08093ED6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093EDC: .4byte 0x00008E04
_08093EE0: .4byte 0x08369E84

	thumb_func_start FUN_08093ee4
FUN_08093ee4: @ 0x08093EE4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08093EF4
	cmp r0, #1
	beq _08093F14
	b _08093FDA
_08093EF4:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x28
	strb r0, [r4, #0x12]
	movs r1, #0x8e
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08093F14:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _08093F3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08093F2A
	movs r2, #1
_08093F2A:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08093F40
	cmp r2, #0
	beq _08093F44
	b _08093F4A
	.align 2, 0
_08093F3C: .4byte pZero2
_08093F40:
	cmp r2, #0
	beq _08093F4A
_08093F44:
	movs r1, #0
	movs r0, #4
	b _08093FD6
_08093F4A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08093FC4
	adds r0, r4, #0
	bl FUN_08093a20
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bne _08093F6E
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08093FC4
_08093F6E:
	ldr r0, _08093FB4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, _08093FB8 @ =0xFFFFA000
	adds r1, r1, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xe
	adds r1, r1, r0
	ldr r0, [r4, #0x54]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r1
	bge _08093F8C
	movs r5, #1
_08093F8C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08093FBC
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080939e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08093FBC
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	b _08093FC4
	.align 2, 0
_08093FB4: .4byte pZero2
_08093FB8: .4byte 0xFFFFA000
_08093FBC:
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093FC4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08093FDA
	movs r0, #5
_08093FD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08093FDA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08093fe0
FUN_08093fe0: @ 0x08093FE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08093FF0
	cmp r5, #1
	beq _08094016
	b _0809410A
_08093FF0:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094058 @ =0x00008E06
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	str r5, [r4, #0x5c]
	strb r5, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094016:
	adds r0, r4, #0
	bl FUN_08093a20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	ldr r0, _0809405C @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	ldr r0, _08094060 @ =0xFFFFA000
	adds r5, r5, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0xe
	adds r5, r5, r0
	ldr r0, [r4, #0x54]
	subs r1, r5, r0
	cmp r1, #0
	bge _0809403E
	adds r1, #0x1f
_0809403E:
	asrs r5, r1, #5
	cmp r2, #2
	beq _08094052
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080939e8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094064
_08094052:
	movs r1, #0
	movs r0, #1
	b _08094106
	.align 2, 0
_08094058: .4byte 0x00008E06
_0809405C: .4byte pZero2
_08094060: .4byte 0xFFFFA000
_08094064:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080940EC
	ldr r0, [r4, #0x5c]
	adds r1, r0, r5
	str r1, [r4, #0x5c]
	movs r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, r2
	ble _08094090
	ldr r2, _0809408C @ =0xFFFFFF00
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	b _080940A0
	.align 2, 0
_0809408C: .4byte 0xFFFFFF00
_08094090:
	ldr r0, _080940C0 @ =0xFFFFFF00
	cmp r1, r0
	bge _0809409C
	adds r0, r1, r2
	str r0, [r4, #0x5c]
	movs r3, #1
_0809409C:
	cmp r3, #0
	beq _080940F4
_080940A0:
	ldrb r0, [r4, #0x12]
	movs r1, #7
	ands r0, r1
	strb r0, [r4, #0x12]
	movs r2, #0
	cmp r5, #0
	ble _080940B0
	movs r2, #1
_080940B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080940C4
	cmp r2, #0
	beq _080940C8
	b _080940CE
	.align 2, 0
_080940C0: .4byte 0xFFFFFF00
_080940C4:
	cmp r2, #0
	beq _080940CE
_080940C8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	b _080940D2
_080940CE:
	ldrb r0, [r4, #0x12]
	adds r0, #1
_080940D2:
	strb r0, [r4, #0x12]
	ldr r1, _080940E8 @ =0x00008E06
	ldrb r2, [r4, #0x12]
	adds r0, r4, #0
	movs r3, #1
	bl GotoMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080940F4
	.align 2, 0
_080940E8: .4byte 0x00008E06
_080940EC:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080940F4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809410A
	movs r0, #5
_08094106:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809410A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094110
FUN_08094110: @ 0x08094110
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08094120
	cmp r0, #1
	beq _0809413E
	b _0809416C
_08094120:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08094174 @ =0x00008E02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809413E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08094156
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08094156:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809416C
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809416C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094174: .4byte 0x00008E02

	thumb_func_start FUN_08094178
FUN_08094178: @ 0x08094178
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #0xe]
	cmp r3, #0
	beq _08094188
	cmp r3, #1
	beq _080941A6
	b _0809421E
_08094188:
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	strb r3, [r4, #0x12]
	ldr r1, _080941D4 @ =0x00008E08
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080941A6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080941F6
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _080941F6
	movs r1, #1
	strb r1, [r4, #0x12]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _080941D8
	movs r0, #0x10
	orrs r0, r2
	b _080941DC
	.align 2, 0
_080941D4: .4byte 0x00008E08
_080941D8:
	movs r0, #0xef
	ands r0, r2
_080941DC:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080941F6:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08094208
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08094208:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809421E
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809421E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094224
FUN_08094224: @ 0x08094224
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08094268
	cmp r5, #1
	bgt _08094238
	cmp r5, #0
	beq _08094242
	b _0809431A
_08094238:
	cmp r5, #2
	beq _080942D0
	cmp r5, #3
	beq _080942DE
	b _0809431A
_08094242:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080942C8 @ =0x00008E04
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094268:
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809428E
	ldr r3, [r4, #0x54]
	ldr r1, _080942CC @ =0xFFFFFF00
	adds r0, r3, r1
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809428C
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r3, r0
_0809428C:
	str r2, [r4, #0x54]
_0809428E:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809429E
	str r1, [r4, #0x60]
_0809429E:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809431A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809431A
	.align 2, 0
_080942C8: .4byte 0x00008E04
_080942CC: .4byte 0xFFFFFF00
_080942D0:
	ldr r1, _08094300 @ =0x00008E05
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080942DE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _08094312
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r0, [r1]
	cmp r0, #0
	bne _08094304
	movs r0, #1
	strb r0, [r1]
	movs r0, #8
	b _0809430C
	.align 2, 0
_08094300: .4byte 0x00008E05
_08094304:
	cmp r0, #2
	bne _0809430A
	strb r2, [r1]
_0809430A:
	movs r0, #1
_0809430C:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08094312:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
_0809431A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094320
FUN_08094320: @ 0x08094320
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r0, [r6, #0xc]
	cmp r0, #1
	bls _08094374
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08094370 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08094522
	.align 2, 0
_08094370: .4byte gEnemyFnTable
_08094374:
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094380
	cmp r5, #1
	beq _080943BC
	b _08094522
_08094380:
	adds r0, r4, #0
	bl InitRotatableMotion
	ldr r1, _080944B4 @ =0x00008E01
	adds r0, r4, #0
	bl SetMotion
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x1a
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	eors r0, r1
	ands r0, r1
	strb r0, [r4, #0x12]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #9
	subs r1, r1, r0
	str r1, [r4, #0x64]
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x12]
	lsls r0, r0, #7
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080943BC:
	ldr r0, [r6, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r6, #0x58]
	ldr r1, _080944B8 @ =0xFFFFF300
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080943D4
	b _080944F4
_080943D4:
	adds r7, r6, #0
	adds r7, #0xb8
	ldr r2, [r7]
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _080944CC
	ldrb r1, [r4, #0xa]
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x54]
	mov r8, r2
	ldr r3, [r4, #0x58]
	mov sb, r3
	ldr r0, _080944BC @ =pZero2
	ldr r0, [r0]
	ldr r5, [r0, #0x54]
	subs r5, r5, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #5
	cmp r0, #0
	bge _08094404
	adds r0, #0xff
_08094404:
	asrs r5, r0, #8
	adds r0, r5, #0
	movs r1, #0x1e
	bl __divsi3
	adds r5, r0, #0
	ldr r0, _080944C0 @ =0xFFFFFD00
	cmp r5, r0
	bge _08094418
	adds r5, r0, #0
_08094418:
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r5, r0
	ble _08094422
	adds r5, r0, #0
_08094422:
	ldr r0, _080944C4 @ =0xFFFFFC40
	mov sl, r0
	ldr r1, [r4, #0x64]
	subs r0, r5, r1
	cmp r0, #0
	bge _08094430
	adds r0, #0xf
_08094430:
	asrs r0, r0, #4
	adds r0, r1, r0
	str r0, [r4, #0x64]
	ldr r2, [r4, #0x68]
	mov r3, sl
	subs r1, r3, r2
	cmp r1, #0
	bge _08094442
	adds r1, #0xf
_08094442:
	asrs r1, r1, #4
	adds r1, r2, r1
	str r1, [r4, #0x68]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2
	lsrs r0, r0, #8
	strb r0, [r4, #0x13]
	ldr r0, [r7]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08094512
	movs r0, #0x2d
	bl PlaySound
	ldr r0, [r7]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r2, _080944C8 @ =gSineTable
	ldrb r0, [r4, #0x13]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	add r8, r0
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	add sb, r0
	ldrb r0, [r6, #0x11]
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	adds r2, r5, #0
	mov r3, sl
	bl FUN_080b1234
	b _08094512
	.align 2, 0
_080944B4: .4byte 0x00008E01
_080944B8: .4byte 0xFFFFF300
_080944BC: .4byte pZero2
_080944C0: .4byte 0xFFFFFD00
_080944C4: .4byte 0xFFFFFC40
_080944C8: .4byte gSineTable
_080944CC:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x64]
	adds r3, r0, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080944E0
	ldr r3, _080944F0 @ =0xFFFFFF00
_080944E0:
	str r3, [r4, #0x64]
	str r2, [r4, #0x68]
	adds r0, r3, #0
	movs r1, #0
	bl ArcTan2
	strb r0, [r4, #0x13]
	b _0809450A
	.align 2, 0
_080944F0: .4byte 0xFFFFFF00
_080944F4:
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809450A
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _08094510
_0809450A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08094510:
	strb r0, [r4, #0xa]
_08094512:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x13]
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x24
	strb r0, [r1]
_08094522:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094534:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0xA8, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28
	.byte 0x4B, 0xD0, 0x9C, 0xE0, 0x28, 0x1C, 0x74, 0x30, 0x1C, 0x49, 0x72, 0xF7, 0x63, 0xFE, 0x1C, 0x49
	.byte 0x28, 0x1C, 0x83, 0xF7, 0x09, 0xF8, 0x28, 0x1C, 0x83, 0xF7, 0x80, 0xF8, 0x19, 0x48, 0x02, 0x68
	.byte 0x69, 0x6D, 0x50, 0x6D, 0x09, 0x1A, 0xE9, 0x65, 0xA8, 0x6D, 0x17, 0x4B, 0xC0, 0x18, 0x92, 0x6D
	.byte 0x80, 0x1A, 0x28, 0x66, 0x09, 0x12, 0x0E, 0x1C, 0x4E, 0x43, 0x00, 0x12, 0x01, 0x1C, 0x41, 0x43
	.byte 0x08, 0x1C, 0x36, 0x18, 0x30, 0x1C, 0x69, 0xF0, 0xE1, 0xFF, 0x00, 0x04, 0x06, 0x0A, 0x00, 0x2E
	.byte 0x1C, 0xD0, 0xE8, 0x6D, 0x00, 0x02, 0x31, 0x1C, 0x6A, 0xF0, 0xC2, 0xF8, 0x04, 0x1C, 0xEC, 0x65
	.byte 0x28, 0x6E, 0x00, 0x02, 0x31, 0x1C, 0x6A, 0xF0, 0xBB, 0xF8, 0x61, 0x00, 0x09, 0x19, 0x49, 0x00
	.byte 0xE9, 0x65, 0x41, 0x00, 0x09, 0x18, 0x49, 0x00, 0x29, 0x66, 0x0B, 0xE0, 0x9C, 0x9E, 0x36, 0x08
	.byte 0x09, 0x8E, 0x00, 0x00, 0x40, 0xF3, 0x02, 0x02, 0x00, 0xE8, 0xFF, 0xFF, 0xC0, 0x20, 0xC0, 0x00
	.byte 0xE8, 0x65, 0x2E, 0x66, 0xA8, 0x7B, 0x01, 0x30, 0xA8, 0x73, 0x28, 0x1C, 0x83, 0xF7, 0x3E, 0xF8
	.byte 0xE9, 0x6D, 0x28, 0x1C, 0xFF, 0xF7, 0x58, 0xFA, 0x00, 0x06, 0x00, 0x28, 0x06, 0xD1, 0x2E, 0x1C
	.byte 0x8C, 0x36, 0x34, 0x68, 0x04, 0x20, 0x04, 0x40, 0x00, 0x2C, 0x03, 0xD0, 0x28, 0x1C, 0x00, 0xF0
	.byte 0xE1, 0xF8, 0x3C, 0xE0, 0x28, 0x6E, 0x40, 0x30, 0x28, 0x66, 0xE0, 0x21, 0xC9, 0x00, 0x88, 0x42
	.byte 0x00, 0xDD, 0x29, 0x66, 0xA9, 0x6D, 0x28, 0x6E, 0x09, 0x18, 0xA9, 0x65, 0x68, 0x6D, 0x75, 0xF7
	.byte 0xB7, 0xF9, 0x01, 0x1C, 0x00, 0x29, 0x05, 0xDA, 0xA8, 0x6D, 0x40, 0x18, 0xA8, 0x65, 0x28, 0x1C
	.byte 0x00, 0xF0, 0xC8, 0xF8, 0x68, 0x7C, 0x00, 0x28, 0x21, 0xD0, 0x12, 0x48, 0x29, 0x1C, 0x54, 0x31
	.byte 0x86, 0xF7, 0xE6, 0xF8, 0xC0, 0x21, 0xC9, 0x01, 0x88, 0x42, 0x18, 0xD9, 0xA9, 0x7A, 0xFE, 0x20
	.byte 0x08, 0x40, 0xFD, 0x21, 0x08, 0x40, 0xA8, 0x72, 0x34, 0x60, 0x28, 0x1C, 0x90, 0x30, 0x04, 0x60
	.byte 0x04, 0x30, 0x04, 0x70, 0xA9, 0x7A, 0xFB, 0x20, 0x08, 0x40, 0xA8, 0x72, 0x06, 0x49, 0x68, 0x7A
	.byte 0x80, 0x00, 0x40, 0x18, 0x03, 0x21, 0xE9, 0x60, 0x00, 0x68, 0xC0, 0x68, 0x68, 0x61, 0x70, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x48, 0xFF, 0x02, 0x02, 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0809468c
FUN_0809468c: @ 0x0809468C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809469C
	cmp r0, #1
	beq _08094714
	b _080947B8
_0809469C:
	adds r2, r5, #0
	adds r2, #0xb8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080946CC @ =0x00008E06
	adds r0, r5, #0
	bl SetMotion
	adds r2, r5, #0
	adds r2, #0xbd
	ldrb r1, [r2]
	movs r0, #1
	adds r3, r0, #0
	eors r3, r1
	adds r6, r2, #0
	cmp r3, #0
	beq _080946D0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080946D6
	.align 2, 0
_080946CC: .4byte 0x00008E06
_080946D0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080946D6:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r3
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	ldrb r0, [r6]
	lsls r0, r0, #9
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	str r4, [r5, #0x60]
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08094714:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08093a98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809479A
	movs r4, #0
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x5c]
	adds r2, r0, r1
	str r2, [r5, #0x60]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r6, r1, #0
	cmp r2, r3
	ble _08094744
	ldr r1, _08094740 @ =0xFFFFFF00
	adds r0, r2, r1
	str r0, [r5, #0x60]
	b _08094754
	.align 2, 0
_08094740: .4byte 0xFFFFFF00
_08094744:
	ldr r0, _08094774 @ =0xFFFFFF00
	cmp r2, r0
	bge _08094750
	adds r0, r2, r3
	str r0, [r5, #0x60]
	movs r4, #1
_08094750:
	cmp r4, #0
	beq _0809479A
_08094754:
	ldrb r0, [r5, #0x12]
	movs r1, #7
	ands r0, r1
	strb r0, [r5, #0x12]
	movs r2, #0
	cmp r6, #0
	ble _08094764
	movs r2, #1
_08094764:
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08094778
	cmp r2, #0
	beq _0809477C
	b _08094782
	.align 2, 0
_08094774: .4byte 0xFFFFFF00
_08094778:
	cmp r2, #0
	beq _08094782
_0809477C:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	b _08094786
_08094782:
	ldrb r0, [r5, #0x12]
	adds r0, #1
_08094786:
	strb r0, [r5, #0x12]
	ldr r1, _080947C0 @ =0x00008E06
	ldrb r2, [r5, #0x12]
	adds r0, r5, #0
	movs r3, #1
	bl GotoMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0809479A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080947B8
	adds r0, r5, #0
	adds r0, #0xbc
	movs r1, #2
	strb r1, [r0]
	movs r0, #5
	strb r0, [r5, #0xd]
	strb r2, [r5, #0xe]
_080947B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080947C0: .4byte 0x00008E06

	thumb_func_start FUN_080947c4
FUN_080947c4: @ 0x080947C4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08094814 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _0809481C
	ldr r2, _08094818 @ =0x08369EBE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7f70
	b _08094828
	.align 2, 0
_08094814: .4byte 0xFFFFF000
_08094818: .4byte 0x08369EBE
_0809481C:
	ldr r2, _08094864 @ =0x08369EBE
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7ffc
_08094828:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08094868 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0809486C @ =0x0000270E
	cmp r1, r0
	bhi _08094842
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08094842:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08094870 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094864: .4byte 0x08369EBE
_08094868: .4byte gMission
_0809486C: .4byte 0x0000270E
_08094870: .4byte gEnemyFnTable

	thumb_func_start FUN_08094874
FUN_08094874: @ 0x08094874
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094888
	cmp r5, #1
	bne _08094886
	b _08094988
_08094886:
	b _080949C6
_08094888:
	movs r6, #0
	ldr r0, _0809490C @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809489A
	movs r6, #1
_0809489A:
	ldr r1, _08094910 @ =0x00008E0A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r1, r1, r0
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08093a64
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094934
	movs r0, #0x20
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08094918
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094914 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b84f4
	b _0809496E
	.align 2, 0
_0809490C: .4byte pZero2
_08094910: .4byte 0x00008E0A
_08094914: .4byte 0x08369EC6
_08094918:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094930 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b857c
	b _0809496E
	.align 2, 0
_08094930: .4byte 0x08369EC6
_08094934:
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08094958
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08094954 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	b _0809496E
	.align 2, 0
_08094954: .4byte 0x08369EC6
_08094958:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _080949D0 @ =0x08369EC6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_0809496E:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _08094976
	adds r0, #3
_08094976:
	asrs r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094988:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _080949AC
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080949A4
	str r1, [r4, #0x60]
_080949A4:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08093a64
_080949AC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080949C6
	adds r0, r4, #0
	bl FUN_080947c4
_080949C6:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080949D0: .4byte 0x08369EC6

	thumb_func_start FUN_080949d4
FUN_080949d4: @ 0x080949D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08094A48 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08094A40
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094A4C @ =gEnemyFnTable
	movs r1, #0x3f
	strb r1, [r3, #9]
	adds r0, #0xfc
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
	movs r0, #4
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x11]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	ldr r1, _08094A50 @ =0x08369F44
	lsls r2, r4, #2
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [r3, #0x5c]
	adds r1, #2
	adds r2, r2, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	str r0, [r3, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #1
	str r0, [r3, #0x64]
_08094A40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094A48: .4byte gZakoHeaderPtr
_08094A4C: .4byte gEnemyFnTable
_08094A50: .4byte 0x08369F44

	thumb_func_start FUN_08094a54
FUN_08094a54: @ 0x08094A54
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _08094ACC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _08094AC4
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094AD0 @ =gEnemyFnTable
	movs r1, #0x3f
	strb r1, [r4, #9]
	adds r0, #0xfc
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #5
	strb r0, [r4, #0x10]
	str r6, [r4, #0x54]
	str r7, [r4, #0x58]
	ldr r2, _08094AD4 @ =0x08369F44
	lsls r3, r5, #2
	adds r0, r3, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	adds r2, #2
	adds r3, r3, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r4, #0x60]
_08094AC4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094ACC: .4byte gZakoHeaderPtr
_08094AD0: .4byte gEnemyFnTable
_08094AD4: .4byte 0x08369F44

	thumb_func_start nop_08094ad8
nop_08094ad8: @ 0x08094AD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08094adc
FUN_08094adc: @ 0x08094ADC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08094B6C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08094B70 @ =0x08369F54
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08094B74 @ =0x08369EFC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08094B78 @ =nop_08094ad8
	str r0, [r4, #0x24]
	ldrb r0, [r5, #0x10]
	cmp r0, #3
	bhi _08094B5E
	ldr r2, _08094B7C @ =0x08369F5A
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #8
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r0, #0x1e
	strb r0, [r5, #0x12]
_08094B5E:
	adds r0, r5, #0
	bl FUN_08094b80
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094B6C: .4byte gEnemyFnTable
_08094B70: .4byte 0x08369F54
_08094B74: .4byte 0x08369EFC
_08094B78: .4byte nop_08094ad8
_08094B7C: .4byte 0x08369F5A

	thumb_func_start FUN_08094b80
FUN_08094b80: @ 0x08094B80
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08094BAC @ =0x08369EDC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08094BB0 @ =0x08369EEC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094BAC: .4byte 0x08369EDC
_08094BB0: .4byte 0x08369EEC

	thumb_func_start FUN_08094bb4
FUN_08094bb4: @ 0x08094BB4
	ldr r2, _08094BC8 @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_08094BC8: .4byte gEnemyFnTable

	thumb_func_start nop_08094bcc
nop_08094bcc: @ 0x08094BCC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08094bd0
FUN_08094bd0: @ 0x08094BD0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08094BEA
	movs r1, #0
	movs r0, #3
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_08094BEA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094bf0
FUN_08094bf0: @ 0x08094BF0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08094C16
	ldr r0, _08094C70 @ =pZero2
	ldr r0, [r0]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08094C68
_08094C16:
	movs r0, #0x3f
	bl PlaySound
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08094C74 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	ldr r2, _08094C78 @ =0x08369F62
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7ffc
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r2, [r5]
	adds r0, r4, #0
	adds r0, #0x90
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08094C7C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08094C68:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094C70: .4byte pZero2
_08094C74: .4byte 0xFFFFF000
_08094C78: .4byte 0x08369F62
_08094C7C: .4byte gEnemyFnTable

	thumb_func_start FUN_08094c80
FUN_08094c80: @ 0x08094C80
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bhi _08094D40
	lsls r0, r0, #2
	ldr r1, _08094C94 @ =_08094C98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08094C94: .4byte _08094C98
_08094C98: @ jump table
	.4byte _08094CB0 @ case 0
	.4byte _08094CC2 @ case 1
	.4byte _08094CD0 @ case 2
	.4byte _08094CE4 @ case 3
	.4byte _08094D0A @ case 4
	.4byte _08094D14 @ case 5
_08094CB0:
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094CC2:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	b _08094CFC
_08094CD0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x10]
	bl FUN_08094a54
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094CE4:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D04
_08094CFC:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08094D40
_08094D04:
	movs r0, #2
	strb r0, [r4, #0xe]
	b _08094D40
_08094D0A:
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094D14:
	ldrb r0, [r4, #0x12]
	movs r1, #9
	bl __umodsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D2C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldrb r2, [r4, #0x10]
	bl FUN_080949d4
_08094D2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08094D40
	strb r0, [r4, #0xe]
	movs r0, #0x78
	strb r0, [r4, #0x12]
_08094D40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094d48
FUN_08094d48: @ 0x08094D48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094D58
	cmp r5, #1
	beq _08094D6A
	b _08094DFC
_08094D58:
	movs r1, #0xc8
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094D6A:
	ldr r0, _08094D84 @ =pZero2
	ldr r0, [r0]
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _08094D8C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08094D88 @ =0x08369EFC
	bl SetDDP
	b _08094D96
	.align 2, 0
_08094D84: .4byte pZero2
_08094D88: .4byte 0x08369EFC
_08094D8C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08094E04 @ =0x08369F14
	bl SetDDP
_08094D96:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	adds r5, r1, r0
	str r5, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r3, r1, r0
	str r3, [r4, #0x58]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x68]
	movs r1, #0xe0
	lsls r1, r1, #6
	cmp r0, r1
	ble _08094DF6
	ldrb r2, [r4, #0x11]
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_08094a54
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08094E08 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08094DF6:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08094DFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094E04: .4byte 0x08369F14
_08094E08: .4byte gEnemyFnTable

	thumb_func_start FUN_08094e0c
FUN_08094e0c: @ 0x08094E0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08094E34
	cmp r0, #1
	bgt _08094E20
	cmp r0, #0
	beq _08094E26
	b _08094E96
_08094E20:
	cmp r0, #2
	beq _08094E60
	b _08094E96
_08094E26:
	ldr r1, _08094E5C @ =0x0000C801
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094E34:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08094E96
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08094E96
	.align 2, 0
_08094E5C: .4byte 0x0000C801
_08094E60:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08094E9C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08094E96:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094E9C: .4byte gEnemyFnTable

	thumb_func_start FUN_08094ea0
FUN_08094ea0: @ 0x08094EA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08094EB0
	cmp r5, #1
	beq _08094EDA
	b _08094F38
_08094EB0:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	movs r0, #0x40
	bl PlaySound
	strb r5, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08094F14 @ =0x08369F2C
	bl SetDDP
	movs r1, #0xb0
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08094EDA:
	ldr r2, _08094F18 @ =pZero2
	ldr r0, [r2]
	ldr r1, _08094F1C @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r5, #1
	orrs r0, r5
	strb r0, [r3]
	ldr r0, [r2]
	ldr r1, _08094F1C @ =0x00000143
	adds r3, r0, r1
	ldrb r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08094F20
	ldrb r0, [r4, #0xa]
	orrs r0, r5
	b _08094F26
	.align 2, 0
_08094F14: .4byte 0x08369F2C
_08094F18: .4byte pZero2
_08094F1C: .4byte 0x00000143
_08094F20:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_08094F26:
	strb r0, [r4, #0xa]
	ldr r0, [r2]
	ldr r1, [r0, #0x54]
	str r1, [r4, #0x54]
	ldr r0, [r0, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08094F38:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start createPantheonFistInElevator
createPantheonFistInElevator: @ 0x08094F40
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08094FA0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08094F96
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094FA4 @ =gEnemyFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
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
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08094F96:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094FA0: .4byte gZakoHeaderPtr
_08094FA4: .4byte gEnemyFnTable

	thumb_func_start FUN_08094fa8
FUN_08094fa8: @ 0x08094FA8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08094FD4 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _08094FBC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_08094FBC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08094FD8
	movs r0, #0
	b _08094FDA
	.align 2, 0
_08094FD4: .4byte 0xFFFFF200
_08094FD8:
	movs r0, #1
_08094FDA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08094fe0
FUN_08094fe0: @ 0x08094FE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _0809500C
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08095008 @ =0x000007FF
	cmp r1, r0
	bgt _0809500C
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _0809500E
	.align 2, 0
_08095008: .4byte 0x000007FF
_0809500C:
	movs r0, #0
_0809500E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095014
FUN_08095014: @ 0x08095014
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _0809506A
	cmp r5, #0
	bge _08095044
	ldr r0, [r4, #0x54]
	ldr r1, _0809503C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095040 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #1
	b _0809506C
	.align 2, 0
_0809503C: .4byte 0xFFFFF200
_08095040: .4byte 0xFFFFF600
_08095044:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095060 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #2
	b _0809506C
	.align 2, 0
_08095060: .4byte 0xFFFFF600
_08095064:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809506A:
	movs r0, #0
_0809506C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08095074
FUN_08095074: @ 0x08095074
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	beq _080950C4
	cmp r1, #0
	bge _080950A4
	ldr r0, [r2, #0x54]
	ldr r1, _0809509C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950A0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #1
	b _080950C6
	.align 2, 0
_0809509C: .4byte 0xFFFFF200
_080950A0: .4byte 0xFFFFF600
_080950A4:
	ldr r0, [r2, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950C0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #2
	b _080950C6
	.align 2, 0
_080950C0: .4byte 0xFFFFF600
_080950C4:
	movs r0, #0
_080950C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080950cc
nop_080950cc: @ 0x080950CC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080950d0
FUN_080950d0: @ 0x080950D0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809511C
	ldr r1, _08095110 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #2
	str r4, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	bne _08095114
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08095116
	strb r4, [r2, #0xd]
	b _08095118
	.align 2, 0
_08095110: .4byte gEnemyFnTable
_08095114:
	movs r0, #1
_08095116:
	strb r0, [r2, #0xd]
_08095118:
	movs r0, #1
	b _0809511E
_0809511C:
	movs r0, #0
_0809511E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095124
FUN_08095124: @ 0x08095124
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xd]
	cmp r0, #7
	beq _080951AA
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r5, [r0]
	cmp r5, #0
	bne _080951AA
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08095144
	cmp r0, #1
	beq _08095188
	b _080951AA
_08095144:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080951AA
	ldr r1, _08095180 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08095184 @ =0x08369FA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809517A:
	movs r0, #1
	b _080951AC
	.align 2, 0
_08095180: .4byte 0x08369F80
_08095184: .4byte 0x08369FA4
_08095188:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _080951A8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080951A4 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809517A
	strb r5, [r4, #0xf]
	b _080951AA
	.align 2, 0
_080951A4: .4byte 0x00020001
_080951A8:
	strb r0, [r4, #0xf]
_080951AA:
	movs r0, #0
_080951AC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080951b4
FUN_080951b4: @ 0x080951B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r2, [r6]
	cmp r2, #0
	bne _080951F4
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080951F4
	movs r5, #0x80
	lsls r5, r5, #0xa
	ands r5, r1
	cmp r5, #0
	beq _080951E0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
	b _080951F4
_080951E0:
	ldr r2, _080951FC @ =0x0836A064
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _080951F4
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_080951F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080951FC: .4byte 0x0836A064

	thumb_func_start initPantheonFist
initPantheonFist: @ 0x08095200
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r1, [r5, #0x10]
	cmp r1, #1
	bne _08095212
	movs r0, #0
	strb r0, [r5, #0x10]
	strb r1, [r5, #0x11]
	b _08095216
_08095212:
	movs r0, #0
	strb r0, [r5, #0x11]
_08095216:
	ldr r1, _0809527C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _08095280 @ =0x0836A06C
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _08095284 @ =0x08369FD4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _08095288 @ =nop_080950cc
	str r0, [r4, #0x24]
	adds r0, r5, #0
	adds r0, #0xb4
	str r6, [r0]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _0809528C
	adds r0, r5, #0
	adds r0, #0xb8
	strb r6, [r0]
	b _0809529E
	.align 2, 0
_0809527C: .4byte gEnemyFnTable
_08095280: .4byte 0x0836A06C
_08095284: .4byte 0x08369FD4
_08095288: .4byte nop_080950cc
_0809528C:
	adds r1, r5, #0
	adds r1, #0xb8
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	str r0, [r5, #0x58]
_0809529E:
	movs r2, #0
	ldr r0, _080952BC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080952AE
	movs r2, #1
_080952AE:
	cmp r2, #0
	beq _080952C0
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080952C6
	.align 2, 0
_080952BC: .4byte pZero2
_080952C0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080952C6:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	bl pantheonFistAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start pantheonFistAI
pantheonFistAI: @ 0x080952F0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080950d0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	adds r0, r4, #0
	bl FUN_080951b4
	adds r0, r4, #0
	bl FUN_08095124
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095330
	ldr r1, _08095338 @ =0x08369F80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809533C @ =0x08369FA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08095330:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095338: .4byte 0x08369F80
_0809533C: .4byte 0x08369FA4

	thumb_func_start killPantheonFist
killPantheonFist: @ 0x08095340
	push {lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x11]
	cmp r3, #0
	bne _08095394
	ldr r0, _0809538C @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08095394
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
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
	ldr r1, _08095390 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
	b _080953A4
	.align 2, 0
_0809538C: .4byte gCurStory
_08095390: .4byte gEnemyFnTable
_08095394:
	ldr r0, _080953A8 @ =0x08369FC8
	ldrb r1, [r2, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_080953A4:
	pop {r0}
	bx r0
	.align 2, 0
_080953A8: .4byte 0x08369FC8
_080953AC:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080953b0
FUN_080953b0: @ 0x080953B0
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080953CC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080953C8
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080953C8:
	pop {r0}
	bx r0
	.align 2, 0
_080953CC: .4byte 0x00020001

	thumb_func_start FUN_080953d0
FUN_080953d0: @ 0x080953D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _080953E6
	bl isKilled
	cmp r0, #0
	beq _08095406
_080953E6:
	movs r0, #0
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095424 @ =0x08369FEC
	bl SetDDP
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08095406
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095406:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08095428 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809541C
	movs r1, #0
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809541C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095424: .4byte 0x08369FEC
_08095428: .4byte 0x00020001

	thumb_func_start FUN_0809542c
FUN_0809542c: @ 0x0809542C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809543C
	cmp r5, #1
	beq _08095456
	b _08095494
_0809543C:
	ldr r1, _0809549C @ =0x0000D406
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080954A0 @ =0x0836A004
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095456:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _0809548E
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095472
	str r1, [r4, #0x60]
_08095472:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809548E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_0809548E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08095494:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809549C: .4byte 0x0000D406
_080954A0: .4byte 0x0836A004

	thumb_func_start FUN_080954a4
FUN_080954a4: @ 0x080954A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080954B4
	cmp r0, #1
	beq _080954D2
	b _08095572
_080954B4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080954F8 @ =0x08369FEC
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	movs r1, #0xd4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080954D2:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldr r0, _080954FC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080954E8
	movs r2, #1
_080954E8:
	adds r5, r2, #0
	cmp r5, #0
	beq _08095500
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095506
	.align 2, 0
_080954F8: .4byte 0x08369FEC
_080954FC: .4byte pZero2
_08095500:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095506:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809555C
	lsls r0, r5, #1
	subs r5, r0, #1
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08095074
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08095550
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095556
_08095550:
	movs r0, #0x10
	strb r0, [r4, #0x12]
	b _0809555C
_08095556:
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0809555C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08095572
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08095578
FUN_08095578: @ 0x08095578
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080955A8
	cmp r5, #1
	bgt _0809558C
	cmp r5, #0
	beq _08095596
	b _0809565E
_0809558C:
	cmp r5, #2
	beq _08095614
	cmp r5, #3
	beq _08095622
	b _0809565E
_08095596:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095610 @ =0x08369FEC
	bl SetDDP
	str r5, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080955A8:
	movs r1, #0xd4
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #2
	bne _080955D6
	ldr r3, [r4, #0x54]
	adds r0, r3, #0
	subs r0, #0x80
	str r0, [r4, #0x54]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080955D4
	adds r2, r3, #0
	adds r2, #0x80
_080955D4:
	str r2, [r4, #0x54]
_080955D6:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080955E6
	str r1, [r4, #0x60]
_080955E6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095606
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095606:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809565E
	.align 2, 0
_08095610: .4byte 0x08369FEC
_08095614:
	ldr r1, _08095644 @ =0x0000D401
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095622:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r2, [r0]
	cmp r2, #3
	bne _08095656
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r1]
	cmp r0, #0
	bne _08095648
	movs r0, #1
	strb r0, [r1]
	movs r0, #8
	b _08095650
	.align 2, 0
_08095644: .4byte 0x0000D401
_08095648:
	cmp r0, #2
	bne _0809564E
	strb r2, [r1]
_0809564E:
	movs r0, #1
_08095650:
	strb r0, [r4, #0xd]
	movs r0, #0
	strb r0, [r4, #0xe]
_08095656:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_0809565E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08095664
FUN_08095664: @ 0x08095664
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095674
	cmp r0, #1
	beq _080956B8
	b _0809576E
_08095674:
	movs r2, #0
	ldr r0, _0809569C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _08095684
	movs r2, #1
_08095684:
	lsls r1, r2, #8
	subs r1, #0x80
	adds r0, r4, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080956A0
	movs r0, #1
	b _0809576A
	.align 2, 0
_0809569C: .4byte pZero2
_080956A0:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080956DC @ =0x08369FEC
	bl SetDDP
	ldr r1, _080956E0 @ =0x0000D402
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080956B8:
	movs r3, #0
	ldr r1, _080956E4 @ =pZero2
	ldr r0, [r1]
	ldr r2, [r4, #0x54]
	ldr r0, [r0, #0x54]
	mov ip, r1
	cmp r2, r0
	bge _080956CA
	movs r3, #1
_080956CA:
	adds r5, r3, #0
	adds r2, r5, #0
	cmp r5, #0
	beq _080956E8
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _080956EE
	.align 2, 0
_080956DC: .4byte 0x08369FEC
_080956E0: .4byte 0x0000D402
_080956E4: .4byte pZero2
_080956E8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080956EE:
	strb r0, [r4, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r6, #0
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	mov r1, ip
	ldr r0, [r1]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	movs r1, #0xc8
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r1, _08095774 @ =0x000063FF
	cmp r0, r1
	bhi _0809572C
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
_0809572C:
	lsls r0, r5, #8
	adds r5, r0, #0
	subs r5, #0x80
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809574E
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08095752
_0809574E:
	strb r7, [r4, #0xd]
	strb r6, [r4, #0xe]
_08095752:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809576E
	movs r0, #2
_0809576A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809576E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08095774: .4byte 0x000063FF

	thumb_func_start FUN_08095778
FUN_08095778: @ 0x08095778
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095788
	cmp r0, #1
	beq _080957A4
	b _080957C6
_08095788:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080957CC @ =0x08369FEC
	bl SetDDP
	ldr r1, _080957D0 @ =0x0000D403
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080957A4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080957BE
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080957BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_080957C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080957CC: .4byte 0x08369FEC
_080957D0: .4byte 0x0000D403

	thumb_func_start FUN_080957d4
FUN_080957d4: @ 0x080957D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080957E8
	cmp r0, #1
	beq _0809583E
	b _08095900
_080957E8:
	ldr r0, _08095820 @ =0x00000109
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08095824 @ =0x0836A01C
	bl SetDDP
	movs r4, #0x10
	str r4, [r5, #0x64]
	movs r0, #0xa0
	lsls r0, r0, #3
	bl Sqrt
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	ldr r2, [r5, #0x64]
	adds r1, r0, #0
	muls r1, r2, r1
	str r1, [r5, #0x5c]
	ldrb r0, [r5, #0xa]
	ands r4, r0
	cmp r4, #0
	bne _08095828
	rsbs r0, r1, #0
	str r0, [r5, #0x5c]
	b _0809582C
	.align 2, 0
_08095820: .4byte 0x00000109
_08095824: .4byte 0x0836A01C
_08095828:
	rsbs r0, r2, #0
	str r0, [r5, #0x64]
_0809582C:
	movs r0, #0
	strb r0, [r5, #0x13]
	ldr r1, _0809590C @ =0x0000D404
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809583E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r7, _08095910 @ =pZero2
	ldr r0, [r7]
	adds r0, #0x8c
	ldr r0, [r0]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _0809588C
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	mov r8, r1
	ands r0, r1
	cmp r0, #0
	beq _0809588C
	ldrb r0, [r5, #0x12]
	cmp r0, #0x10
	bls _0809588C
	ldrb r4, [r5, #0x13]
	cmp r4, #0
	bne _0809588C
	movs r0, #0x52
	bl PlaySound
	strb r6, [r5, #0x13]
	ldr r0, [r7]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r6, [r0]
	ldr r0, [r7]
	mov r1, r8
	strb r1, [r0, #0xd]
	ldr r0, [r7]
	strb r4, [r0, #0xe]
_0809588C:
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x64]
	adds r0, r0, r1
	str r0, [r5, #0x5c]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	ldrb r1, [r5, #0x12]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080958B2
	cmp r1, #8
	bls _080958B2
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #3
	bl CreateSmoke
_080958B2:
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08094fa8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080958D4
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080958D4
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080958DC
_080958D4:
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080958DC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080958F8
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080958F8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08094fe0
_08095900:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809590C: .4byte 0x0000D404
_08095910: .4byte pZero2

	thumb_func_start FUN_08095914
FUN_08095914: @ 0x08095914
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095924
	cmp r0, #1
	beq _0809593C
	b _0809595C
_08095924:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095964 @ =0x08369FEC
	bl SetDDP
	ldr r1, _08095968 @ =0x0000D405
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809593C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08095954
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08095954:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
_0809595C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095964: .4byte 0x08369FEC
_08095968: .4byte 0x0000D405

	thumb_func_start FUN_0809596c
FUN_0809596c: @ 0x0809596C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809597C
	cmp r0, #1
	beq _08095A12
	b _08095AB6
_0809597C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080959F4 @ =0x0836A04C
	bl SetDDP
	ldr r1, _080959F8 @ =0x0000D406
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080959FC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08095A00 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08095A04
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08095A0C
	.align 2, 0
_080959F4: .4byte 0x0836A04C
_080959F8: .4byte 0x0000D406
_080959FC: .4byte pZero2
_08095A00: .4byte 0xFFFFE800
_08095A04:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08095A0C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08095A12:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r1, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095014
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095A34
	adds r6, r5, #0
	adds r6, #0x8c
	ldr r4, [r6]
	movs r0, #4
	ands r4, r0
	cmp r4, #0
	beq _08095A3C
_08095A34:
	adds r0, r5, #0
	bl FUN_08095b70
	b _08095AB6
_08095A3C:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095A4C
	str r1, [r5, #0x60]
_08095A4C:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095A6C
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl FUN_08095b70
_08095A6C:
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _08095AB6
	ldr r0, _08095ABC @ =gStageRun+232
	adds r1, r5, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #7
	cmp r0, r1
	bls _08095AB6
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	str r4, [r6]
	adds r0, r5, #0
	adds r0, #0x90
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _08095AC0 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_08095AB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095ABC: .4byte gStageRun+232
_08095AC0: .4byte gEnemyFnTable

	thumb_func_start FUN_08095ac4
FUN_08095ac4: @ 0x08095AC4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08095AD4
	cmp r0, #1
	beq _08095B3E
	b _08095B68
_08095AD4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08095B00 @ =0x08369FEC
	bl SetDDP
	ldr r1, _08095B04 @ =0x0000D402
	adds r0, r4, #0
	bl SetMotion
	adds r2, r4, #0
	adds r2, #0xb9
	ldrb r1, [r2]
	movs r0, #1
	adds r3, r0, #0
	eors r3, r1
	adds r5, r2, #0
	cmp r3, #0
	beq _08095B08
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095B0E
	.align 2, 0
_08095B00: .4byte 0x08369FEC
_08095B04: .4byte 0x0000D402
_08095B08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095B0E:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r3
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x80
	str r1, [r4, #0x5c]
	ldrb r0, [r5]
	lsls r0, r0, #8
	subs r1, r1, r0
	str r1, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095B3E:
	ldr r1, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_08095014
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08095B68
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #2
	strb r0, [r1]
	strb r0, [r4, #0xd]
	strb r2, [r4, #0xe]
_08095B68:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08095b70
FUN_08095b70: @ 0x08095B70
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08095BC0 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095BC8
	ldr r2, _08095BC4 @ =0x0836A06E
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	b _08095BD4
	.align 2, 0
_08095BC0: .4byte 0xFFFFF000
_08095BC4: .4byte 0x0836A06E
_08095BC8:
	ldr r2, _08095C10 @ =0x0836A06E
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7ffc
_08095BD4:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #4
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08095C14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08095C18 @ =0x0000270E
	cmp r1, r0
	bhi _08095BEE
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08095BEE:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08095C1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08095C10: .4byte 0x0836A06E
_08095C14: .4byte gMission
_08095C18: .4byte 0x0000270E
_08095C1C: .4byte gEnemyFnTable

	thumb_func_start FUN_08095c20
FUN_08095c20: @ 0x08095C20
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08095C34
	cmp r5, #1
	bne _08095C32
	b _08095D34
_08095C32:
	b _08095D72
_08095C34:
	movs r6, #0
	ldr r0, _08095CB8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08095C46
	movs r6, #1
_08095C46:
	ldr r1, _08095CBC @ =0x0000D408
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r0, r1, r0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08094fe0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095CE0
	movs r0, #0x20
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095CC4
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095CC0 @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b84f4
	b _08095D1A
	.align 2, 0
_08095CB8: .4byte pZero2
_08095CBC: .4byte 0x0000D408
_08095CC0: .4byte 0x0836A074
_08095CC4:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095CDC @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0x15
	bl FUN_080b857c
	b _08095D1A
	.align 2, 0
_08095CDC: .4byte 0x0836A074
_08095CE0:
	str r5, [r4, #0x68]
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	bne _08095D04
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095D00 @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	b _08095D1A
	.align 2, 0
_08095D00: .4byte 0x0836A074
_08095D04:
	adds r1, r4, #0
	adds r1, #0x54
	ldr r0, _08095D7C @ =0x0836A074
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b83d4
_08095D1A:
	ldr r0, [sp, #8]
	cmp r0, #0
	bge _08095D22
	adds r0, #3
_08095D22:
	asrs r0, r0, #2
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08095D34:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _08095D58
	ldr r0, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08095D50
	str r1, [r4, #0x60]
_08095D50:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08094fe0
_08095D58:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095D72
	adds r0, r4, #0
	bl FUN_08095b70
_08095D72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095D7C: .4byte 0x0836A074

	thumb_func_start FUN_08095d80
FUN_08095d80: @ 0x08095D80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	subs r0, r2, r1
	ldr r6, _08095DC0 @ =0x0000043F
	cmp r0, r6
	bgt _08095DA2
	movs r5, #1
_08095DA2:
	ldr r0, [r4, #0x54]
	ldr r2, _08095DC4 @ =0xFFFFF600
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	subs r0, r2, r0
	cmp r0, r6
	bgt _08095DB8
	movs r5, #1
_08095DB8:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095DC0: .4byte 0x0000043F
_08095DC4: .4byte 0xFFFFF600

	thumb_func_start FUN_08095dc8
FUN_08095dc8: @ 0x08095DC8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, _08095E00 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	cmp r5, r1
	bge _08095E08
	cmp r5, #0
	bge _08095E1A
	ldr r0, _08095E04 @ =0xFFFFFC00
	cmp r5, r0
	ble _08095E1A
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _08095E16
	.align 2, 0
_08095E00: .4byte 0xFFFFF600
_08095E04: .4byte 0xFFFFFC00
_08095E08:
	cmp r1, #0
	bge _08095E1A
	ldr r0, _08095E24 @ =0xFFFFFC00
	cmp r1, r0
	ble _08095E1A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
_08095E16:
	str r0, [r4, #0x58]
	movs r6, #1
_08095E1A:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08095E24: .4byte 0xFFFFFC00

	thumb_func_start FUN_08095e28
FUN_08095e28: @ 0x08095E28
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	ldr r0, [r5, #0x58]
	subs r0, r4, r0
	ldr r1, _08095E74 @ =0x0000043F
	cmp r0, r1
	bgt _08095E42
	str r4, [r5, #0x58]
_08095E42:
	movs r2, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _08095E4C
	movs r2, #1
_08095E4C:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #0xa
	ldr r1, _08095E78 @ =0xFFFFF600
	adds r6, r0, r1
	ldr r0, [r5, #0x58]
	ldr r1, _08095E7C @ =0xFFFFF800
	adds r4, r0, r1
	cmp r2, #0
	beq _08095E80
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl PushoutToLeft1
	adds r1, r0, #0
	cmp r1, #0
	bge _08095E9A
	b _08095E90
	.align 2, 0
_08095E74: .4byte 0x0000043F
_08095E78: .4byte 0xFFFFF600
_08095E7C: .4byte 0xFFFFF800
_08095E80:
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl PushoutToRight1
	adds r1, r0, #0
	cmp r1, #0
	ble _08095E9A
_08095E90:
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	movs r0, #1
	b _08095EB6
_08095E9A:
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095EB4
	movs r0, #0
	b _08095EB6
_08095EB4:
	movs r0, #2
_08095EB6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start initShellcrawler
initShellcrawler: @ 0x08095EBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08095F04 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldrb r0, [r6, #0x10]
	cmp r0, #4
	bne _08095F10
	movs r0, #9
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095F08 @ =0x0836A11C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08095F0C @ =FUN_08096348
	str r0, [r4, #0x24]
	b _0809604E
	.align 2, 0
_08095F04: .4byte gEnemyFnTable
_08095F08: .4byte 0x0836A11C
_08095F0C: .4byte FUN_08096348
_08095F10:
	movs r0, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r4, #0
	adds r2, r1, #0
	orrs r2, r0
	strb r2, [r6, #0xa]
	ldr r0, _08095F60 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x13]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08095F6C
	ldr r0, _08095F64 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08095F6C
	movs r0, #4
	orrs r2, r0
	strb r2, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095F68 @ =0x0836A08C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	b _08095F84
	.align 2, 0
_08095F60: .4byte gSystemSavedataManager
_08095F64: .4byte gCurStory
_08095F68: .4byte 0x0836A08C
_08095F6C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08095FC8 @ =0x0836A08C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
_08095F84:
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	ldr r0, _08095FCC @ =FUN_08096348
	str r0, [r4, #0x24]
	ldr r1, _08095FD0 @ =0x0000DB01
	adds r0, r6, #0
	bl SetMotion
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	str r0, [r6, #0x58]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08095FFA
	movs r2, #0
	ldr r0, _08095FD4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r6, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _08095FBA
	movs r2, #1
_08095FBA:
	cmp r2, #0
	beq _08095FD8
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _08095FDE
	.align 2, 0
_08095FC8: .4byte 0x0836A08C
_08095FCC: .4byte FUN_08096348
_08095FD0: .4byte 0x0000DB01
_08095FD4: .4byte pZero2
_08095FD8:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_08095FDE:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	b _0809603E
_08095FFA:
	cmp r0, #2
	bne _0809601E
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08096040
_0809601E:
	movs r2, #1
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
_0809603E:
	strb r0, [r3]
_08096040:
	movs r0, #0
	strb r0, [r6, #0x10]
	adds r1, r6, #0
	adds r1, #0xbc
	strb r0, [r1]
	subs r1, #4
	str r0, [r1]
_0809604E:
	adds r0, r6, #0
	bl shellcrawlerAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start shellcrawlerAI
shellcrawlerAI: @ 0x0809605C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080960AC @ =0x080FF05C
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r5, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _080960CC
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _08096084
	b _080961D6
_08096084:
	ldrb r3, [r4, #0xd]
	ldr r1, _080960B0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	ldr r2, [r6]
	movs r0, #0xc0
	lsls r0, r0, #9
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bne _080960B4
	movs r0, #1
	b _080960C0
	.align 2, 0
_080960AC: .4byte 0x080FF05C
_080960B0: .4byte gEnemyFnTable
_080960B4:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r2
	cmp r0, #0
	beq _080960C0
	movs r0, #3
_080960C0:
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xf]
	adds r0, r4, #0
	bl killShellcrawler
	b _080962CA
_080960CC:
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _080960D4
	b _080961D6
_080960D4:
	ldr r0, _0809611C @ =gStageRun+232
	adds r1, r4, #0
	adds r1, #0x54
	bl CalcFromCamera
	movs r1, #0x80
	lsls r1, r1, #8
	cmp r0, r1
	bls _08096124
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r6]
	adds r0, r4, #0
	adds r0, #0x90
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08096120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080962CA
	.align 2, 0
_0809611C: .4byte gStageRun+232
_08096120: .4byte gEnemyFnTable
_08096124:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0809617A
	ldr r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809617A
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080961CA
	movs r0, #0
	adds r1, r4, #0
	mov r2, sp
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _0809617A
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08096168
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096164 @ =0x0836A0EC
	bl SetDDP
	b _08096172
	.align 2, 0
_08096164: .4byte 0x0836A0EC
_08096168:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080961F8 @ =0x0836A1AC
	bl SetDDP
_08096172:
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r4, #0x60]
_0809617A:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	beq _080961CA
	ldr r0, [r5]
	cmp r0, #0
	bne _080961D0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _080961A0
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0809619A
	movs r0, #1
	strb r0, [r4, #0xf]
_0809619A:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _080961CA
_080961A0:
	cmp r0, #1
	bne _080961AE
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r4, #0xf]
_080961AE:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080961BA
	strb r0, [r4, #0xf]
_080961BA:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080961FC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	beq _080961CA
	b _080962CA
_080961CA:
	ldr r0, [r5]
	cmp r0, #0
	beq _080961D6
_080961D0:
	ldrb r0, [r4, #0xd]
	cmp r0, #0xa
	bne _08096208
_080961D6:
	ldr r1, _08096200 @ =0x0836A20C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08096204 @ =0x0836A238
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _080962CA
	.align 2, 0
_080961F8: .4byte 0x0836A1AC
_080961FC: .4byte 0x00020001
_08096200: .4byte 0x0836A20C
_08096204: .4byte 0x0836A238
_08096208:
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08096240
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _08096228
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096224 @ =0x0836A08C
	bl SetDDP
	b _08096232
	.align 2, 0
_08096224: .4byte 0x0836A08C
_08096228:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809623C @ =0x0836A0BC
	bl SetDDP
_08096232:
	movs r0, #0
	str r0, [r5]
	ldr r0, [r4, #0x68]
	str r0, [r4, #0x60]
	b _080962B4
	.align 2, 0
_0809623C: .4byte 0x0836A0BC
_08096240:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _080962B4
	ldr r0, [r4, #0x54]
	ldr r1, _080962D4 @ =0xFFFFF600
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	blt _080962B4
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	blt _080962B4
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809627C
	str r1, [r4, #0x60]
_0809627C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _080962D8 @ =0xFFFFF800
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809629A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809629A:
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _080962B4
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080962B4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080962DC @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080962CA
	movs r1, #0
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080962CA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080962D4: .4byte 0xFFFFF600
_080962D8: .4byte 0xFFFFF800
_080962DC: .4byte 0x00020001

	thumb_func_start killShellcrawler
killShellcrawler: @ 0x080962E0
	push {lr}
	adds r3, r0, #0
	ldr r0, _08096328 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08096330
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0809632C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _08096340
	.align 2, 0
_08096328: .4byte gCurStory
_0809632C: .4byte gEnemyFnTable
_08096330:
	ldr r0, _08096344 @ =0x0836A264
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_08096340:
	pop {r0}
	bx r0
	.align 2, 0
_08096344: .4byte 0x0836A264

	thumb_func_start FUN_08096348
FUN_08096348: @ 0x08096348
	push {r4, lr}
	ldr r4, [r0, #0x2c]
	adds r3, r4, #0
	adds r3, #0xb4
	ldr r1, _08096370 @ =pZero2
	ldr r1, [r1]
	ldr r1, [r1, #0x54]
	ldr r2, [r4, #0x54]
	subs r1, r1, r2
	str r1, [r3]
	ldr r0, [r0, #0x14]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809642E
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _08096374
	ldr r4, [r4, #0x28]
	b _08096384
	.align 2, 0
_08096370: .4byte pZero2
_08096374:
	ldrb r1, [r4, #0xd]
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0809642E
	cmp r1, #8
	beq _0809642E
_08096384:
	adds r1, r4, #0
	adds r1, #0xbc
	ldrb r2, [r1]
	cmp r2, #0
	bne _0809642E
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	beq _080963D2
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _080963D2
	str r2, [r4, #0x2c]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #0x8c
	str r2, [r0]
	movs r0, #0x90
	str r2, [r0]
	movs r0, #0x94
	strb r2, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldr r1, _08096404 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r2, #0x14]
_080963D2:
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0x10]
	movs r0, #7
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	ldr r1, _08096408 @ =0x0000DB08
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	bne _08096410
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809640C @ =0x0836A0BC
	bl SetDDP
	b _0809641A
	.align 2, 0
_08096404: .4byte gEnemyFnTable
_08096408: .4byte 0x0000DB08
_0809640C: .4byte 0x0836A0BC
_08096410:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096434 @ =0x0836A1AC
	bl SetDDP
_0809641A:
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096428
	movs r1, #1
_08096428:
	adds r0, r4, #0
	bl FUN_080c6934
_0809642E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096434: .4byte 0x0836A1AC

	thumb_func_start FUN_08096438
FUN_08096438: @ 0x08096438
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809644C
	movs r0, #1
	b _0809645E
_0809644C:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08096462
	movs r1, #0
	movs r0, #5
_0809645E:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08096462:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08096468
FUN_08096468: @ 0x08096468
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809647E
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809647E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08096484
FUN_08096484: @ 0x08096484
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08095d80
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0809649A
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0809649A:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _080964B8 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080964B0
	movs r1, #0
	movs r0, #0xa
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080964B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080964B8: .4byte 0x00020001
_080964BC:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080964c0
FUN_080964c0: @ 0x080964C0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _080964F8
	cmp r0, #1
	bgt _080964D4
	cmp r0, #0
	beq _080964DA
	b _08096568
_080964D4:
	cmp r0, #2
	beq _0809652A
	b _08096568
_080964DA:
	movs r0, #0x60
	strb r0, [r4, #0x12]
	subs r0, #0xa0
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080964F0
	movs r2, #0x40
_080964F0:
	str r2, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080964F8:
	ldr r0, [r4, #0x5c]
	lsrs r2, r0, #0x1f
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809650C
	cmp r2, #0
	beq _08096510
	b _0809651C
_0809650C:
	cmp r2, #0
	beq _0809651C
_08096510:
	movs r1, #0xdb
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	b _08096524
_0809651C:
	ldr r1, _08096540 @ =0x0000DB02
	adds r0, r4, #0
	bl SetMotion
_08096524:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809652A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08096544
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08096568
	.align 2, 0
_08096540: .4byte 0x0000DB02
_08096544:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096562
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r0, #1
	strb r0, [r4, #0xe]
_08096562:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096568:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096570:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xA0, 0x7B, 0x00, 0x28, 0x02, 0xD0, 0x01, 0x28, 0x1F, 0xD0, 0x40, 0xE0
	.byte 0x20, 0x66, 0x20, 0x7C, 0x00, 0x28, 0x09, 0xD1, 0xE0, 0x6D, 0x00, 0x28, 0x02, 0xDA, 0xDB, 0x21
	.byte 0x09, 0x02, 0x07, 0xE0, 0x00, 0x49, 0x05, 0xE0, 0x02, 0xDB, 0x00, 0x00, 0xE0, 0x6D, 0x00, 0x28
	.byte 0x06, 0xDA, 0x02, 0x49, 0x20, 0x1C, 0x80, 0xF7, 0xDF, 0xFF, 0x05, 0xE0, 0x0F, 0xDB, 0x00, 0x00
	.byte 0x15, 0x49, 0x20, 0x1C, 0x80, 0xF7, 0xD8, 0xFF, 0xA0, 0x7B, 0x01, 0x30, 0xA0, 0x73, 0xA0, 0x6D
	.byte 0x21, 0x6E, 0x40, 0x18, 0xA0, 0x65, 0x40, 0x31, 0x21, 0x66, 0xE0, 0x20, 0xC0, 0x00, 0x81, 0x42
	.byte 0x00, 0xDD, 0x20, 0x66, 0x60, 0x6D, 0xE1, 0x6D, 0x40, 0x18, 0x60, 0x65, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x23, 0xFC, 0x20, 0x1C, 0xFF, 0xF7, 0xF0, 0xFB, 0x00, 0x06, 0x00, 0x28, 0x06, 0xD0, 0x20, 0x7C
	.byte 0x00, 0x28, 0x00, 0xD0, 0x06, 0x20, 0x60, 0x73, 0x01, 0x20, 0xA0, 0x73, 0x20, 0x1C, 0x81, 0xF7
	.byte 0x2D, 0xF8, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x05, 0xDB, 0x00, 0x00

	thumb_func_start FUN_0809660c
FUN_0809660c: @ 0x0809660C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809661C
	cmp r0, #1
	beq _0809662A
	b _08096640
_0809661C:
	ldr r1, _08096648 @ =0x0000DB03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809662A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r1, [r0]
	cmp r1, #3
	bne _08096640
	movs r0, #0
	strb r1, [r4, #0xd]
	strb r0, [r4, #0xe]
_08096640:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096648: .4byte 0x0000DB03

	thumb_func_start FUN_0809664c
FUN_0809664c: @ 0x0809664C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809665C
	cmp r5, #1
	beq _080966BC
	b _080966E2
_0809665C:
	ldr r0, _080966E8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r2, r0, #0
	cmp r2, #0
	beq _0809669E
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _080966EC @ =gEnemyFnTable
	movs r1, #0x41
	strb r1, [r2, #9]
	adds r1, #0xc3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	movs r0, #0
	strh r5, [r2, #0x20]
	adds r1, r2, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r2, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #4
	strb r0, [r2, #0x10]
	str r4, [r2, #0x28]
_0809669E:
	str r2, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080966F0 @ =0x0836A14C
	bl SetDDP
	ldr r1, _080966F4 @ =0x0000DB0E
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080966BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bne _080966D0
	ldr r0, _080966F8 @ =0x00000107
	bl PlaySound
_080966D0:
	ldrb r1, [r4, #0x12]
	cmp r1, #0
	bne _080966DC
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080966DC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080966E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080966E8: .4byte gZakoHeaderPtr
_080966EC: .4byte gEnemyFnTable
_080966F0: .4byte 0x0836A14C
_080966F4: .4byte 0x0000DB0E
_080966F8: .4byte 0x00000107

	thumb_func_start FUN_080966fc
FUN_080966fc: @ 0x080966FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809670C
	cmp r0, #1
	beq _0809671A
	b _0809677A
_0809670C:
	ldr r1, _08096780 @ =0x0000DB10
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809671A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r5, [r0]
	cmp r5, #3
	bne _0809677A
	adds r0, #1
	ldr r1, _08096784 @ =0x0836A08C
	bl SetDDP
	ldr r3, [r4, #0x2c]
	cmp r3, #0
	beq _0809676E
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08096788 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	str r2, [r4, #0x2c]
_0809676E:
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	movs r0, #0x60
	strb r0, [r4, #0x12]
_0809677A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096780: .4byte 0x0000DB10
_08096784: .4byte 0x0836A08C
_08096788: .4byte gEnemyFnTable

	thumb_func_start FUN_0809678c
FUN_0809678c: @ 0x0809678C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809679C
	cmp r0, #1
	beq _080967C8
	b _08096804
_0809679C:
	ldr r1, _0809680C @ =0x0000DB01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _080967BC
	ldr r1, _08096810 @ =0xFFFFFF00
_080967BC:
	str r1, [r4, #0x5c]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080967C8:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080967E0
	subs r0, #1
	strb r0, [r4, #0x12]
_080967E0:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080967FE
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080967F8
	movs r0, #6
_080967F8:
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
_080967FE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809680C: .4byte 0x0000DB01
_08096810: .4byte 0xFFFFFF00

	thumb_func_start FUN_08096814
FUN_08096814: @ 0x08096814
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r1, [r5, #0xe]
	cmp r1, #1
	beq _08096866
	cmp r1, #1
	bgt _0809682A
	cmp r1, #0
	beq _08096830
	b _08096936
_0809682A:
	cmp r1, #2
	beq _0809688A
	b _08096936
_08096830:
	movs r0, #0x3c
	strb r0, [r5, #0x12]
	movs r0, #6
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	adds r0, #0xbd
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	cmp r0, #0
	beq _08096852
	subs r1, #2
_08096852:
	str r1, [r5, #0x5c]
	str r2, [r5, #0x64]
	movs r1, #0x10
	cmp r0, #0
	beq _0809685E
	subs r1, #0x20
_0809685E:
	str r1, [r5, #0x64]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096866:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _0809687C
	ldr r1, _08096878 @ =0x0000DB0F
	adds r0, r5, #0
	bl SetMotion
	b _08096884
	.align 2, 0
_08096878: .4byte 0x0000DB0F
_0809687C:
	ldr r1, _08096898 @ =0x0000DB05
	adds r0, r5, #0
	bl SetMotion
_08096884:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809688A:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _0809689C
	subs r0, #1
	strb r0, [r5, #0x12]
	b _080968FE
	.align 2, 0
_08096898: .4byte 0x0000DB05
_0809689C:
	ldrb r0, [r5, #0x13]
	subs r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080968FE
	movs r0, #6
	strb r0, [r5, #0x13]
	adds r1, r5, #0
	adds r1, #0xbd
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080968C6
	strb r2, [r1]
	movs r0, #0x3c
	strb r0, [r5, #0x12]
_080968C6:
	ldrb r4, [r5, #0xa]
	lsrs r4, r4, #4
	movs r0, #1
	ands r4, r0
	ldr r1, [r5, #0x54]
	ldr r0, _08096940 @ =0xFFFFF400
	adds r1, r1, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #0xb
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096944 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	ldr r1, _08096948 @ =0xFFFFFD00
	lsls r4, r4, #7
	subs r4, #0x80
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_080968FE:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	adds r2, r1, #0
	cmp r1, #0
	bge _0809690E
	rsbs r2, r1, #0
_0809690E:
	ldr r0, _0809694C @ =0x0000013F
	cmp r2, r0
	bgt _0809691A
	ldr r0, [r5, #0x64]
	adds r0, r1, r0
	str r0, [r5, #0x5c]
_0809691A:
	adds r0, r5, #0
	bl FUN_08095e28
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096930
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r5, #0xe]
_08096930:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08096936:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096940: .4byte 0xFFFFF400
_08096944: .4byte 0xFFFFF600
_08096948: .4byte 0xFFFFFD00
_0809694C: .4byte 0x0000013F

	thumb_func_start FUN_08096950
FUN_08096950: @ 0x08096950
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08096960
	cmp r0, #1
	beq _0809698C
	b _080969C2
_08096960:
	ldr r1, _080969C8 @ =0x0000DB08
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x5c]
	str r0, [r4, #0x64]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x5c]
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096980
	ldr r1, _080969CC @ =0xFFFFFF00
_08096980:
	str r1, [r4, #0x5c]
	movs r0, #2
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809698C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	adds r0, r4, #0
	bl FUN_08095e28
	ldrb r0, [r4, #0x12]
	cmp r0, #1
	bls _080969A4
	subs r0, #1
	strb r0, [r4, #0x12]
_080969A4:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080969BC
	ldr r0, [r4, #0x64]
	str r0, [r4, #0x5c]
	movs r0, #6
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080969BC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080969C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080969C8: .4byte 0x0000DB08
_080969CC: .4byte 0xFFFFFF00

	thumb_func_start FUN_080969d0
FUN_080969d0: @ 0x080969D0
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08096A08
	cmp r0, #1
	bgt _080969E6
	cmp r0, #0
	beq _080969F0
	b _08096A7A
_080969E6:
	cmp r0, #2
	beq _08096A20
	cmp r0, #3
	beq _08096A2A
	b _08096A7A
_080969F0:
	ldr r1, _08096A1C @ =0x0000DB04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #8
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08096A08:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096A7A
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08096A78
	.align 2, 0
_08096A1C: .4byte 0x0000DB04
_08096A20:
	movs r0, #0
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096A2A:
	ldrb r0, [r4, #0x12]
	cmp r0, #2
	bne _08096A5C
	ldrb r2, [r4, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	ldr r1, [r4, #0x54]
	ldr r0, _08096A84 @ =0xFFFFF000
	adds r1, r1, r0
	lsls r0, r2, #0xd
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08096A88 @ =0xFFFFF600
	adds r0, r0, r1
	str r0, [sp, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #9
	ldr r0, _08096A8C @ =0xFFFFFD00
	adds r1, r1, r0
	mov r0, sp
	bl FUN_080b145c
_08096A5C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08096A7A
	movs r0, #4
	strb r0, [r4, #0xd]
	movs r0, #0
_08096A78:
	strb r0, [r4, #0xe]
_08096A7A:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096A84: .4byte 0xFFFFF000
_08096A88: .4byte 0xFFFFF600
_08096A8C: .4byte 0xFFFFFD00

	thumb_func_start FUN_08096a90
FUN_08096a90: @ 0x08096A90
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r0, _08096AE0 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08096AE8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08096AE4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _08096B7A
	.align 2, 0
_08096AE0: .4byte gCurStory
_08096AE4: .4byte gEnemyFnTable
_08096AE8:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bls _08096B22
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08096B30 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_08096B22:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08096B34
	cmp r0, #1
	beq _08096B4C
	b _08096B7A
	.align 2, 0
_08096B30: .4byte gEnemyFnTable
_08096B34:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B64 @ =0x0836A08C
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096B4C:
	adds r0, r5, #0
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	bne _08096B68
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B64 @ =0x0836A08C
	bl SetDDP
	b _08096B72
	.align 2, 0
_08096B64: .4byte 0x0836A08C
_08096B68:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08096B80 @ =0x0836A1DC
	bl SetDDP
_08096B72:
	ldr r0, [r5, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r5, #0x58]
	str r0, [r4, #0x58]
_08096B7A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096B80: .4byte 0x0836A1DC

	thumb_func_start FUN_08096b84
FUN_08096b84: @ 0x08096B84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #0
	beq _08096B96
	cmp r2, #1
	beq _08096BBA
	b _08096C10
_08096B96:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096BBA:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08096C18 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c68cc
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08096C1C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096C20 @ =0x0000270E
	cmp r1, r0
	bhi _08096BF6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096BF6:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _08096C24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08096C10:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096C18: .4byte 0xFFFFF800
_08096C1C: .4byte gMission
_08096C20: .4byte 0x0000270E
_08096C24: .4byte gEnemyFnTable

	thumb_func_start FUN_08096c28
FUN_08096c28: @ 0x08096C28
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	beq _08096CC4
	cmp r0, #1
	bgt _08096C3E
	cmp r0, #0
	beq _08096C46
	b _08096D76
_08096C3E:
	cmp r0, #2
	bne _08096C44
	b _08096D50
_08096C44:
	b _08096D76
_08096C46:
	adds r1, r5, #0
	adds r1, #0xbc
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0xb4
	cmp r0, #0
	bne _08096C68
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	ldr r0, [r4]
	cmp r0, #0
	ble _08096C62
	movs r1, #1
_08096C62:
	adds r0, r5, #0
	bl FUN_080c6934
_08096C68:
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096D40 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r6, #0
	ldr r0, [r4]
	cmp r0, #0
	ble _08096C7E
	movs r6, #1
_08096C7E:
	movs r4, #0x80
	lsls r4, r4, #2
	movs r0, #0
	mov r1, sp
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080b2b40
	ldr r1, _08096D44 @ =0x0000DB09
	adds r0, r5, #0
	bl SetMotion
	lsls r0, r6, #0xa
	subs r4, r4, r0
	str r4, [r5, #0x5c]
	movs r1, #0
	movs r0, #0x14
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl FUN_080c6880
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096CC4:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08096CD8
	adds r0, #0xff
_08096CD8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	adds r0, r5, #0
	bl FUN_08095e28
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096D38
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08096D40 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #2
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _08096D48 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096D4C @ =0x0000270E
	cmp r1, r0
	bhi _08096D2A
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096D2A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096D38:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08096D76
	.align 2, 0
_08096D40: .4byte 0xFFFFF800
_08096D44: .4byte 0x0000DB09
_08096D48: .4byte gMission
_08096D4C: .4byte 0x0000270E
_08096D50:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08096D64
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08096D76
_08096D64:
	ldr r1, _08096D80 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08096D76:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096D80: .4byte gEnemyFnTable

	thumb_func_start FUN_08096d84
FUN_08096d84: @ 0x08096D84
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r1, [r4, #0xe]
	cmp r1, #1
	beq _08096DE0
	cmp r1, #1
	bgt _08096D9A
	cmp r1, #0
	beq _08096DA0
	b _08096E9E
_08096D9A:
	cmp r1, #2
	beq _08096E78
	b _08096E9E
_08096DA0:
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _08096DC4
	movs r2, #1
_08096DC4:
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #8
	movs r0, #0xa0
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _08096E6C @ =0xFFFFFB80
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08096DE0:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08096DFE
	str r0, [r4, #0x60]
_08096DFE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096E1E
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08096E9E
_08096E1E:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c68cc
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #2
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08096E70 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08096E74 @ =0x0000270E
	cmp r1, r0
	bhi _08096E5C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08096E5C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08096E9E
	.align 2, 0
_08096E6C: .4byte 0xFFFFFB80
_08096E70: .4byte gMission
_08096E74: .4byte 0x0000270E
_08096E78:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08096E8C
	subs r0, #1
	strb r0, [r4, #0x12]
	b _08096E9E
_08096E8C:
	ldr r1, _08096EA8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_08096E9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096EA8: .4byte gEnemyFnTable

	thumb_func_start FUN_08096eac
FUN_08096eac: @ 0x08096EAC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08096EBC
	cmp r0, #1
	beq _08096F6A
	b _08096FAA
_08096EBC:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08096ED8 @ =0x0836A17C
	bl SetDDP
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _08096EE0
	ldr r1, _08096EDC @ =0x0000DB04
	adds r0, r5, #0
	bl SetMotion
	b _08096EE8
	.align 2, 0
_08096ED8: .4byte 0x0836A17C
_08096EDC: .4byte 0x0000DB04
_08096EE0:
	ldr r1, _08096F50 @ =0x0000DB0F
	adds r0, r5, #0
	bl SetMotion
_08096EE8:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _08096F54 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08096F58 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08096F5C
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _08096F64
	.align 2, 0
_08096F50: .4byte 0x0000DB0F
_08096F54: .4byte pZero2
_08096F58: .4byte 0xFFFFE800
_08096F5C:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_08096F64:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08096F6A:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08096F82
	str r1, [r5, #0x60]
_08096F82:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08096FA4
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08096FAA
_08096FA4:
	adds r0, r5, #0
	bl FUN_08096b84
_08096FAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08096fb0
FUN_08096fb0: @ 0x08096FB0
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x54]
	str r1, [r3, #0x64]
	ldr r1, [r3, #0x58]
	str r1, [r3, #0x68]
	adds r2, r3, #0
	adds r2, #0xc0
	movs r1, #0
	str r1, [r2]
	ldr r1, _08096FF4 @ =0xFFFFFE00
	str r1, [r3, #0x5c]
	adds r4, r1, #0
	ldrb r2, [r3, #0xa]
	movs r1, #0x10
	ands r1, r2
	cmp r1, #0
	beq _08096FD8
	movs r4, #0x80
	lsls r4, r4, #2
_08096FD8:
	str r4, [r3, #0x5c]
	ldr r1, _08096FF8 @ =0xFFFFFC00
	str r1, [r3, #0x60]
	adds r4, r1, #0
	movs r1, #0x20
	ands r1, r2
	cmp r1, #0
	beq _08096FEC
	movs r4, #0x80
	lsls r4, r4, #3
_08096FEC:
	str r4, [r3, #0x60]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08096FF4: .4byte 0xFFFFFE00
_08096FF8: .4byte 0xFFFFFC00

	thumb_func_start FUN_08096ffc
FUN_08096ffc: @ 0x08096FFC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r6, #0
	cmp r2, #0
	bne _0809700A
	b _08097118
_0809700A:
	ldr r0, [r5, #0x68]
	adds r1, r0, r2
	str r1, [r5, #0x68]
	movs r2, #0
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0809701A
	movs r2, #1
_0809701A:
	adds r4, r2, #0
	ldr r0, [r5, #0x64]
	ldr r2, _08097044 @ =0xFFFFF900
	adds r3, r0, r2
	adds r2, r1, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08097048 @ =0xFFFFD100
	cmp r0, #0
	beq _0809704C
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _0809704C
	adds r0, r1, #0
	muls r0, r4, r0
	b _08097052
	.align 2, 0
_08097044: .4byte 0xFFFFF900
_08097048: .4byte 0xFFFFD100
_0809704C:
	movs r0, #1
	eors r0, r4
	muls r0, r1, r0
_08097052:
	adds r2, r2, r0
	cmp r4, #0
	beq _08097074
	ldr r0, _08097070 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097094
	ldr r0, [r5, #0x68]
	movs r1, #0x80
	lsls r1, r1, #1
	b _0809708A
	.align 2, 0
_08097070: .4byte 0xFFFFFF00
_08097074:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097094
	ldr r0, [r5, #0x68]
	ldr r1, _080970C8 @ =0xFFFFFF00
_0809708A:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r5, #0x68]
	movs r0, #1
	orrs r6, r0
_08097094:
	movs r1, #0
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _0809709E
	movs r1, #1
_0809709E:
	adds r4, r1, #0
	ldr r0, [r5, #0x64]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r3, r0, r2
	ldr r2, [r5, #0x68]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080970CC @ =0xFFFFD100
	cmp r0, #0
	beq _080970D0
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _080970D0
	adds r0, r1, #0
	muls r0, r4, r0
	b _080970D6
	.align 2, 0
_080970C8: .4byte 0xFFFFFF00
_080970CC: .4byte 0xFFFFD100
_080970D0:
	movs r0, #1
	eors r0, r4
	muls r0, r1, r0
_080970D6:
	adds r2, r2, r0
	cmp r4, #0
	beq _080970F8
	ldr r0, _080970F4 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097118
	ldr r0, [r5, #0x68]
	movs r1, #0x80
	lsls r1, r1, #1
	b _0809710E
	.align 2, 0
_080970F4: .4byte 0xFFFFFF00
_080970F8:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097118
	ldr r0, [r5, #0x68]
	ldr r1, _08097154 @ =0xFFFFFF00
_0809710E:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r5, #0x68]
	movs r0, #1
	orrs r6, r0
_08097118:
	cmp r7, #0
	beq _080971E8
	ldr r0, [r5, #0x64]
	adds r1, r0, r7
	str r1, [r5, #0x64]
	movs r2, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _0809712C
	movs r2, #1
_0809712C:
	adds r4, r2, #0
	ldr r2, _08097158 @ =0xFFFFF900
	adds r3, r1, r2
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r0, [r5, #0x68]
	ldr r1, _0809715C @ =0xFFFFFE00
	adds r2, r0, r1
	cmp r4, #0
	beq _08097160
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _0809717C
	b _0809716E
	.align 2, 0
_08097154: .4byte 0xFFFFFF00
_08097158: .4byte 0xFFFFF900
_0809715C: .4byte 0xFFFFFE00
_08097160:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _0809717C
_0809716E:
	ldr r0, [r5, #0x64]
	adds r0, r0, r3
	str r0, [r5, #0x64]
	movs r0, #2
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_0809717C:
	movs r1, #0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	ble _08097186
	movs r1, #1
_08097186:
	adds r4, r1, #0
	ldr r3, [r5, #0x64]
	ldr r2, _080971AC @ =0xFFFFF900
	adds r3, r3, r2
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r2, [r5, #0x68]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080971B0
	movs r0, #0xb4
	lsls r0, r0, #6
	adds r2, r2, r0
	b _080971B4
	.align 2, 0
_080971AC: .4byte 0xFFFFF900
_080971B0:
	ldr r1, _080971C8 @ =0xFFFFD300
	adds r2, r2, r1
_080971B4:
	cmp r4, #0
	beq _080971CC
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _080971E8
	b _080971DA
	.align 2, 0
_080971C8: .4byte 0xFFFFD300
_080971CC:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _080971E8
_080971DA:
	ldr r0, [r5, #0x64]
	adds r0, r0, r3
	str r0, [r5, #0x64]
	movs r0, #2
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_080971E8:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _08097208
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _08097208
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _08097208
	adds r1, r5, #0
	adds r1, #0xc0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0809720E
_08097208:
	movs r0, #0
	str r0, [r5, #0x5c]
	str r0, [r5, #0x60]
_0809720E:
	movs r0, #2
	ands r6, r0
	cmp r6, #0
	beq _0809721C
	ldr r0, [r5, #0x5c]
	rsbs r0, r0, #0
	str r0, [r5, #0x5c]
_0809721C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08097224
FUN_08097224: @ 0x08097224
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r7, #0
	cmp r2, #0
	bne _08097232
	b _08097340
_08097232:
	ldr r0, [r4, #0x58]
	adds r1, r0, r2
	str r1, [r4, #0x58]
	movs r2, #0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _08097242
	movs r2, #1
_08097242:
	adds r5, r2, #0
	ldr r0, [r4, #0x54]
	ldr r2, _0809726C @ =0xFFFFF900
	adds r3, r0, r2
	adds r2, r1, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08097270 @ =0xFFFFD100
	cmp r0, #0
	beq _08097274
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _08097274
	adds r0, r1, #0
	muls r0, r5, r0
	b _0809727A
	.align 2, 0
_0809726C: .4byte 0xFFFFF900
_08097270: .4byte 0xFFFFD100
_08097274:
	movs r0, #1
	eors r0, r5
	muls r0, r1, r0
_0809727A:
	adds r2, r2, r0
	cmp r5, #0
	beq _0809729C
	ldr r0, _08097298 @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _080972BC
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	b _080972B2
	.align 2, 0
_08097298: .4byte 0xFFFFFF00
_0809729C:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _080972BC
	ldr r0, [r4, #0x58]
	ldr r1, _080972F0 @ =0xFFFFFF00
_080972B2:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #1
	orrs r7, r0
_080972BC:
	movs r1, #0
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _080972C6
	movs r1, #1
_080972C6:
	adds r5, r1, #0
	ldr r0, [r4, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r3, r0, r2
	ldr r2, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080972F4 @ =0xFFFFD100
	cmp r0, #0
	beq _080972F8
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, #0
	beq _080972F8
	adds r0, r1, #0
	muls r0, r5, r0
	b _080972FE
	.align 2, 0
_080972F0: .4byte 0xFFFFFF00
_080972F4: .4byte 0xFFFFD100
_080972F8:
	movs r0, #1
	eors r0, r5
	muls r0, r1, r0
_080972FE:
	adds r2, r2, r0
	cmp r5, #0
	beq _08097320
	ldr r0, _0809731C @ =0xFFFFFF00
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	bge _08097340
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	b _08097336
	.align 2, 0
_0809731C: .4byte 0xFFFFFF00
_08097320:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r2, r0
	adds r0, r3, #0
	bl PushoutToDown1
	adds r2, r0, #0
	cmp r2, #0
	ble _08097340
	ldr r0, [r4, #0x58]
	ldr r1, _0809738C @ =0xFFFFFF00
_08097336:
	adds r0, r0, r1
	adds r0, r0, r2
	str r0, [r4, #0x58]
	movs r0, #1
	orrs r7, r0
_08097340:
	cmp r6, #0
	beq _08097420
	ldr r0, [r4, #0x54]
	adds r1, r0, r6
	str r1, [r4, #0x54]
	movs r2, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08097354
	movs r2, #1
_08097354:
	adds r5, r2, #0
	ldr r2, _08097390 @ =0xFFFFF900
	adds r3, r1, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r6, [r4, #0x58]
	ldr r0, _08097394 @ =0xFFFFFE00
	adds r2, r6, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097378
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, r6, r1
_08097378:
	cmp r5, #0
	beq _08097398
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _080973B4
	b _080973A6
	.align 2, 0
_0809738C: .4byte 0xFFFFFF00
_08097390: .4byte 0xFFFFF900
_08097394: .4byte 0xFFFFFE00
_08097398:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _080973B4
_080973A6:
	ldr r0, [r4, #0x54]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	movs r0, #2
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_080973B4:
	movs r1, #0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080973BE
	movs r1, #1
_080973BE:
	adds r5, r1, #0
	ldr r3, [r4, #0x54]
	ldr r2, _080973E4 @ =0xFFFFF900
	adds r3, r3, r2
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #9
	adds r3, r3, r0
	ldr r2, [r4, #0x58]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080973E8
	movs r0, #0xb4
	lsls r0, r0, #6
	adds r2, r2, r0
	b _080973EC
	.align 2, 0
_080973E4: .4byte 0xFFFFF900
_080973E8:
	ldr r1, _08097400 @ =0xFFFFD300
	adds r2, r2, r1
_080973EC:
	cmp r5, #0
	beq _08097404
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToLeft1
	adds r3, r0, #0
	cmp r3, #0
	bge _08097420
	b _08097412
	.align 2, 0
_08097400: .4byte 0xFFFFD300
_08097404:
	adds r0, r3, #0
	adds r1, r2, #0
	bl PushoutToRight1
	adds r3, r0, #0
	cmp r3, #0
	ble _08097420
_08097412:
	ldr r0, [r4, #0x54]
	adds r0, r0, r3
	str r0, [r4, #0x54]
	movs r0, #2
	orrs r7, r0
	lsls r0, r7, #0x18
	lsrs r7, r0, #0x18
_08097420:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08097428
FUN_08097428: @ 0x08097428
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	mov r2, sp
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #1]
	strb r0, [r2]
	ldr r0, [r5, #0x54]
	ldr r1, _08097454 @ =0xFFFFF900
	adds r2, r0, r1
	ldr r4, [r5, #0x58]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097458
	movs r0, #0xb8
	lsls r0, r0, #6
	adds r4, r4, r0
	b _0809745C
	.align 2, 0
_08097454: .4byte 0xFFFFF900
_08097458:
	ldr r1, _080974B8 @ =0xFFFFD200
	adds r4, r4, r1
_0809745C:
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _0809746E
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0809746E:
	ldr r2, [r5, #0x54]
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _08097482
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_08097482:
	ldr r0, [r5, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToDown1
	cmp r0, #0
	ble _0809749C
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0809749C:
	ldr r0, [r5, #0x54]
	ldr r1, _080974BC @ =0xFFFFF900
	adds r2, r0, r1
	ldr r4, [r5, #0x58]
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080974C0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
	b _080974C4
	.align 2, 0
_080974B8: .4byte 0xFFFFD200
_080974BC: .4byte 0xFFFFF900
_080974C0:
	ldr r1, _08097518 @ =0xFFFFFF00
	adds r4, r4, r1
_080974C4:
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _080974D6
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_080974D6:
	ldr r2, [r5, #0x54]
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _080974EA
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_080974EA:
	ldr r0, [r5, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	bl PushoutToUp1
	cmp r0, #0
	bge _08097504
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_08097504:
	mov r0, sp
	mov r1, sp
	ldrb r0, [r0]
	ldrb r1, [r1, #1]
	ands r0, r1
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08097518: .4byte 0xFFFFFF00

	thumb_func_start initCannonHopper
initCannonHopper: @ 0x0809751C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080975A8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _080975AC @ =0x0836A418
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0xa]
	movs r1, #1
	movs r6, #0
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080975B0 @ =0x0836A288
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080975B4 @ =0x080978C9
	str r0, [r4, #0x24]
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_08009f6c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r5, #0x58]
	movs r2, #0
	ldr r0, _080975B8 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _0809759C
	movs r2, #1
_0809759C:
	cmp r2, #0
	beq _080975BC
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080975C2
	.align 2, 0
_080975A8: .4byte gEnemyFnTable
_080975AC: .4byte 0x0836A418
_080975B0: .4byte 0x0836A288
_080975B4: .4byte 0x080978C9
_080975B8: .4byte pZero2
_080975BC:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_080975C2:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	str r3, [r0]
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x28]
	adds r0, r5, #0
	adds r0, #0xbf
	strb r3, [r0]
	adds r0, r5, #0
	bl cannonHopperAI
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start cannonHopperAI
cannonHopperAI: @ 0x080975FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x8c
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08097620
	adds r0, r4, #0
	bl FUN_08097428
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08097682
_08097620:
	ldrb r2, [r4, #0xd]
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809763E
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0809763C
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
_0809763C:
	movs r2, #1
_0809763E:
	ldr r1, _08097668 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	strb r2, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0809766C
	movs r0, #1
	b _08097678
	.align 2, 0
_08097668: .4byte gEnemyFnTable
_0809766C:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _08097678
	movs r0, #3
_08097678:
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl killCannonHopper
	b _08097844
_08097682:
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r5, [r0]
	adds r7, r0, #0
	cmp r5, #0
	bne _08097702
	ldr r0, [r6]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _08097702
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0809775A
	ldr r2, _08097794 @ =0x0836A41C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r7]
	cmp r0, #0
	beq _08097702
	adds r0, r4, #0
	adds r0, #0xbf
	strb r6, [r0]
	subs r0, #0x4b
	ldr r1, _08097798 @ =0x0836A378
	bl SetDDP
	str r5, [r4, #0x60]
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080976E2
	ldr r0, [r4, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r4, #0x58]
_080976E2:
	ldrb r1, [r4, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_08097702:
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	beq _0809775A
	ldr r0, [r7]
	cmp r0, #0
	bne _0809776A
	adds r0, r4, #0
	adds r0, #0xbf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809775A
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08097732
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0809772C
	movs r0, #1
	strb r0, [r4, #0xf]
_0809772C:
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0809775A
_08097732:
	cmp r0, #1
	bne _08097740
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r0, #2
	strb r0, [r4, #0xf]
_08097740:
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _0809774C
	strb r0, [r4, #0xf]
_0809774C:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0809779C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08097844
_0809775A:
	ldr r0, [r7]
	cmp r0, #0
	bne _0809776A
	adds r0, r4, #0
	adds r0, #0xbf
	ldrb r0, [r0]
	cmp r0, #0
	beq _08097770
_0809776A:
	ldrb r0, [r4, #0xd]
	cmp r0, #5
	bne _080977A8
_08097770:
	ldr r1, _080977A0 @ =0x0836A3D8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080977A4 @ =0x0836A3F0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08097844
	.align 2, 0
_08097794: .4byte 0x0836A41C
_08097798: .4byte 0x0836A378
_0809779C: .4byte 0x00020001
_080977A0: .4byte 0x0836A3D8
_080977A4: .4byte 0x0836A3F0
_080977A8:
	ldr r0, [r7]
	cmp r0, #0
	beq _080977C4
	bl isKilled
	cmp r0, #0
	beq _080977C4
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097850 @ =0x0836A288
	bl SetDDP
	movs r0, #0
	str r0, [r7]
_080977C4:
	adds r0, r4, #0
	bl isFrozen
	adds r5, r0, #0
	cmp r5, #0
	bne _0809782E
	adds r6, r4, #0
	adds r6, #0xbf
	ldrb r0, [r6]
	cmp r0, #0
	beq _0809782E
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r7, #0xe0
	lsls r7, r7, #3
	cmp r0, r7
	ble _080977EA
	str r7, [r4, #0x60]
_080977EA:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08097854 @ =0xFFFFF900
	adds r0, r0, r2
	ldr r2, _08097858 @ =0xFFFFFF00
	mov r8, r2
	add r1, r8
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08097812
	str r5, [r4, #0x60]
	strb r5, [r6]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_08097812:
	ldr r0, [r4, #0x54]
	adds r0, r0, r7
	ldr r1, [r4, #0x58]
	add r1, r8
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809782E
	str r5, [r4, #0x60]
	strb r5, [r6]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809782E:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _0809785C @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _08097844
	movs r1, #0
	movs r0, #5
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097844:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097850: .4byte 0x0836A288
_08097854: .4byte 0xFFFFF900
_08097858: .4byte 0xFFFFFF00
_0809785C: .4byte 0x00020001

	thumb_func_start killCannonHopper
killCannonHopper: @ 0x08097860
	push {lr}
	adds r3, r0, #0
	ldr r0, _080978A8 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080978B0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _080978AC @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
	b _080978C0
	.align 2, 0
_080978A8: .4byte gCurStory
_080978AC: .4byte gEnemyFnTable
_080978B0:
	ldr r0, _080978C4 @ =0x0836A408
	ldrb r1, [r3, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl _call_via_r1
_080978C0:
	pop {r0}
	bx r0
	.align 2, 0
_080978C4: .4byte 0x0836A408
_080978C8:
	.byte 0xC1, 0x6A, 0x0A, 0x1C, 0xB4, 0x32, 0x03, 0x48
	.byte 0x00, 0x68, 0x40, 0x6D, 0x49, 0x6D, 0x40, 0x1A, 0x10, 0x60, 0x70, 0x47, 0x40, 0xF3, 0x02, 0x02
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080978e4
FUN_080978e4: @ 0x080978E4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08097900 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _080978FC
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080978FC:
	pop {r0}
	bx r0
	.align 2, 0
_08097900: .4byte 0x00020001

	thumb_func_start FUN_08097904
FUN_08097904: @ 0x08097904
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r1, _08097920 @ =0x00020001
	ands r0, r1
	cmp r0, r1
	bne _0809791C
	movs r1, #0
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0809791C:
	pop {r0}
	bx r0
	.align 2, 0
_08097920: .4byte 0x00020001

	thumb_func_start FUN_08097924
FUN_08097924: @ 0x08097924
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097934
	cmp r0, #1
	beq _080979E8
	b _08097A0C
_08097934:
	adds r1, r4, #0
	adds r1, #0xbe
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08096fb0
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097974 @ =0x0836A288
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bne _08097994
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _08097978
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r2, r0
	bgt _08097982
	b _080979E2
	.align 2, 0
_08097974: .4byte 0x0836A288
_08097978:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	ble _080979E2
_08097982:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_08097994:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	blt _080979A8
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r2, r0
	bgt _080979B2
	b _080979E2
_080979A8:
	subs r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	ble _080979E2
_080979B2:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080979C4
	movs r0, #0x10
	orrs r0, r2
	b _080979C8
_080979C4:
	movs r0, #0xef
	ands r0, r2
_080979C8:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080979E2:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080979E8:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08096ffc
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08097A06
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097A06:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097a14
cannonHopper_08097a14: @ 0x08097A14
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097A24
	cmp r0, #1
	beq _08097A60
	b _08097AF0
_08097A24:
	ldr r1, _08097A7C @ =0x0000DC01
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x15
	strb r0, [r4, #0x12]
	ldr r0, _08097A80 @ =0xFFFFFE00
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08097A44
	movs r2, #0x80
	lsls r2, r2, #2
_08097A44:
	str r2, [r4, #0x5c]
	ldr r0, _08097A84 @ =0xFFFFFC00
	str r0, [r4, #0x60]
	adds r2, r0, #0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097A58
	movs r2, #0x80
	lsls r2, r2, #3
_08097A58:
	str r2, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08097A60:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08097A8C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08097AEA
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08097A88 @ =0x0836A2B8
	bl SetDDP
	b _08097AEA
	.align 2, 0
_08097A7C: .4byte 0x0000DC01
_08097A80: .4byte 0xFFFFFE00
_08097A84: .4byte 0xFFFFFC00
_08097A88: .4byte 0x0836A2B8
_08097A8C:
	ldr r1, [r4, #0x5c]
	ldr r2, [r4, #0x60]
	adds r0, r4, #0
	bl FUN_08097224
	movs r1, #2
	ands r1, r0
	cmp r1, #0
	beq _08097AD4
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097AB0
	movs r0, #0x10
	orrs r0, r2
	b _08097AB4
_08097AB0:
	movs r0, #0xef
	ands r0, r2
_08097AB4:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
_08097AD4:
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #9
	bgt _08097AEA
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097AEA:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097AF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start cannonHopper_08097af8
cannonHopper_08097af8: @ 0x08097AF8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r4, [r6, #0xe]
	cmp r4, #0
	beq _08097B08
	cmp r4, #1
	beq _08097B20
	b _08097CBC
_08097B08:
	adds r0, r6, #0
	adds r0, #0xbe
	strb r4, [r0]
	ldr r1, _08097B40 @ =0x0000DC02
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	strb r4, [r6, #0x13]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_08097B20:
	ldrb r0, [r6, #0x13]
	cmp r0, #8
	bls _08097B48
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08097B44 @ =0x0836A348
	adds r0, r4, #0
	bl SetDDP
	adds r1, r6, #0
	adds r1, #0xbe
	movs r0, #4
	strb r0, [r1]
	adds r7, r1, #0
	adds r5, r4, #0
	b _08097B72
	.align 2, 0
_08097B40: .4byte 0x0000DC02
_08097B44: .4byte 0x0836A348
_08097B48:
	adds r5, r6, #0
	adds r5, #0x74
	ldr r4, _08097BB0 @ =0x0836A424
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _08097BB4 @ =0x0836A288
	adds r1, r1, r0
	adds r0, r5, #0
	bl SetDDP
	ldrb r0, [r6, #0x13]
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0xbe
	strb r1, [r0]
	adds r7, r0, #0
_08097B72:
	ldrb r0, [r6, #0x13]
	adds r0, #1
	movs r4, #0
	strb r0, [r6, #0x13]
	ldr r1, [r6, #0x5c]
	ldr r2, [r6, #0x60]
	adds r0, r6, #0
	bl FUN_08097224
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08097B98
	str r4, [r6, #0x5c]
	str r4, [r6, #0x60]
	strb r1, [r6, #0x12]
_08097B98:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08097BDC
	ldrb r2, [r6, #0xa]
	lsrs r0, r2, #4
	bics r1, r0
	cmp r1, #0
	beq _08097BB8
	movs r0, #0x10
	orrs r0, r2
	b _08097BBC
	.align 2, 0
_08097BB0: .4byte 0x0836A424
_08097BB4: .4byte 0x0836A288
_08097BB8:
	movs r0, #0xef
	ands r0, r2
_08097BBC:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r6, #0x5c]
	rsbs r0, r0, #0
	str r0, [r6, #0x5c]
_08097BDC:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08097C64
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08097C64
	movs r0, #0
	strb r0, [r6, #0xd]
	strb r0, [r6, #0xe]
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08097C06
	ldr r0, [r6, #0x58]
	movs r1, #0xbc
	lsls r1, r1, #6
	b _08097C0A
_08097C06:
	ldr r0, [r6, #0x58]
	ldr r1, _08097C20 @ =0xFFFFD100
_08097C0A:
	adds r0, r0, r1
	str r0, [r6, #0x58]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x1d
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _08097C24
	movs r0, #0x20
	orrs r0, r2
	b _08097C28
	.align 2, 0
_08097C20: .4byte 0xFFFFD100
_08097C24:
	movs r0, #0xdf
	ands r0, r2
_08097C28:
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	movs r4, #0
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _08097C60 @ =0x0836A288
	adds r0, r5, #0
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r7]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _08097CBC
	.align 2, 0
_08097C60: .4byte 0x0836A288
_08097C64:
	ldrb r1, [r6, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097C7E
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r1, r0
	b _08097C8C
_08097C7E:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	adds r1, r0, #0
	ldr r0, [r6, #0x58]
	subs r1, r0, r1
_08097C8C:
	ldr r0, _08097CC4 @ =0x00001FFF
	cmp r1, r0
	bgt _08097CB6
	ldr r1, [r6, #0x5c]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CA0
	adds r0, #0xff
_08097CA0:
	asrs r0, r0, #8
	str r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	bge _08097CB2
	adds r0, #0xff
_08097CB2:
	asrs r0, r0, #8
	str r0, [r6, #0x60]
_08097CB6:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_08097CBC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097CC4: .4byte 0x00001FFF

	thumb_func_start FUN_08097cc8
FUN_08097cc8: @ 0x08097CC8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097CD8
	cmp r0, #1
	beq _08097CEA
	b _08097D04
_08097CD8:
	ldr r1, _08097D0C @ =0x0000DC03
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08097CEA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08097CFE
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08097CFE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08097D04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097D0C: .4byte 0x0000DC03

	thumb_func_start cannonHopper_08097d10
cannonHopper_08097d10: @ 0x08097D10
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _08097D1E
	b _08097F34
_08097D1E:
	lsls r0, r0, #2
	ldr r1, _08097D28 @ =_08097D2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08097D28: .4byte _08097D2C
_08097D2C: @ jump table
	.4byte _08097D40 @ case 0
	.4byte _08097D98 @ case 1
	.4byte _08097DB4 @ case 2
	.4byte _08097E88 @ case 3
	.4byte _08097E9C @ case 4
_08097D40:
	ldrb r0, [r5, #0xa]
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0xbd
	strb r0, [r1]
	ldr r0, _08097D68 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	lsrs r2, r0, #0x1f
	cmp r2, #0
	beq _08097D6C
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08097D72
	.align 2, 0
_08097D68: .4byte pZero2
_08097D6C:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08097D72:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097D98:
	ldr r0, _08097E6C @ =0x0000DC14
	adds r1, r0, #0
	ldrb r0, [r5, #0x13]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097DB4:
	ldr r1, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_08096ffc
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bne _08097E52
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _08097E52
	ldr r0, _08097E70 @ =0x0836A42D
	ldrb r1, [r5, #0x13]
	subs r2, r1, #1
	adds r0, r2, r0
	ldrb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08097DF2
	movs r0, #0x80
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08097DF2:
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08097E06
	movs r0, #0xff
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08097E06:
	ldr r1, [r5, #0x54]
	str r1, [sp]
	ldr r0, _08097E74 @ =0x0836A434
	lsls r3, r2, #2
	adds r2, r3, r0
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [sp]
	adds r1, r0, #0
	cmp r6, #0
	beq _08097E22
	ldr r0, [r2]
	lsls r0, r0, #1
	subs r1, r1, r0
_08097E22:
	str r1, [sp]
	ldr r1, [r5, #0x58]
	str r1, [sp, #4]
	ldr r0, _08097E78 @ =0x0836A448
	adds r3, r3, r0
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r2, r0, #0
	cmp r7, #0
	beq _08097E3E
	ldr r0, [r3]
	lsls r0, r0, #1
	subs r2, r2, r0
_08097E3E:
	str r2, [sp, #4]
	movs r0, #0x2c
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #2
	mov r0, sp
	adds r2, r4, #0
	bl CreateLemon
_08097E52:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	bne _08097E80
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08097E7C
	movs r0, #3
	b _08097E7E
	.align 2, 0
_08097E6C: .4byte 0x0000DC14
_08097E70: .4byte 0x0836A42D
_08097E74: .4byte 0x0836A434
_08097E78: .4byte 0x0836A448
_08097E7C:
	movs r0, #1
_08097E7E:
	strb r0, [r5, #0xe]
_08097E80:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08097F34
_08097E88:
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x18
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08097E9C:
	ldr r1, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_08096ffc
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08097F2E
	adds r0, r5, #0
	adds r0, #0xbd
	ldrb r2, [r0]
	cmp r2, #0
	beq _08097EC4
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08097ECA
_08097EC4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_08097ECA:
	strb r0, [r5, #0xa]
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	adds r4, r5, #0
	adds r4, #0x4c
	strb r1, [r4]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	adds r6, r3, #0
	cmp r0, #0x4f
	bgt _08097F00
	movs r0, #3
	strb r0, [r5, #0xd]
	movs r0, #0
	strb r0, [r5, #0xe]
	b _08097F2E
_08097F00:
	ldrb r2, [r5, #0xa]
	lsrs r0, r2, #4
	adds r1, r7, #0
	bics r1, r0
	cmp r1, #0
	beq _08097F12
	movs r0, #0x10
	orrs r0, r2
	b _08097F16
_08097F12:
	movs r0, #0xef
	ands r0, r2
_08097F16:
	strb r0, [r5, #0xa]
	movs r3, #0
	strb r1, [r4]
	lsls r1, r1, #4
	ldrb r2, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	strb r3, [r5, #0xd]
	strb r3, [r5, #0xe]
_08097F2E:
	adds r0, r5, #0
	bl UpdateMotionGraphic
_08097F34:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08097f3c
FUN_08097f3c: @ 0x08097F3C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08097F50
	cmp r0, #1
	bne _08097F4E
	b _0809805E
_08097F4E:
	b _080980FA
_08097F50:
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08097F8C
	cmp r0, #2
	bgt _08097F64
	cmp r0, #1
	beq _08097F6E
	b _08098038
_08097F64:
	cmp r0, #3
	beq _08097FB0
	cmp r0, #4
	beq _08097FE4
	b _08098038
_08097F6E:
	ldr r3, [r4, #0x58]
	ldr r1, _08097F88 @ =0xFFFFEE00
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FA6
	movs r0, #0x90
	lsls r0, r0, #5
	b _08097FA4
	.align 2, 0
_08097F88: .4byte 0xFFFFEE00
_08097F8C:
	ldr r3, [r4, #0x58]
	ldr r1, _08097FAC @ =0xFFFFE800
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FA6
	movs r0, #0xc0
	lsls r0, r0, #5
_08097FA4:
	adds r2, r3, r0
_08097FA6:
	str r2, [r4, #0x58]
	b _08098038
	.align 2, 0
_08097FAC: .4byte 0xFFFFE800
_08097FB0:
	ldr r3, [r4, #0x58]
	ldr r1, _08097FE0 @ =0xFFFFDD00
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FCA
	movs r0, #0x8c
	lsls r0, r0, #6
	adds r2, r3, r0
_08097FCA:
	str r2, [r4, #0x58]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1d
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _08098018
	movs r0, #0x20
	orrs r0, r1
	b _0809801C
	.align 2, 0
_08097FE0: .4byte 0xFFFFDD00
_08097FE4:
	ldr r3, [r4, #0x58]
	ldr r1, _08098014 @ =0xFFFFD500
	adds r0, r3, r1
	str r0, [r4, #0x58]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08097FFE
	movs r0, #0xac
	lsls r0, r0, #6
	adds r2, r3, r0
_08097FFE:
	str r2, [r4, #0x58]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x1d
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _08098018
	movs r0, #0x20
	orrs r0, r1
	b _0809801C
	.align 2, 0
_08098014: .4byte 0xFFFFD500
_08098018:
	movs r0, #0xdf
	ands r0, r1
_0809801C:
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_08098038:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809805E:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _080980B0 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c6e70
	movs r0, #0x2a
	bl PlaySound
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080980C6
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r5, #0
	bgt _080980C0
	cmp r1, #0
	bge _080980B4
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _080980C4
	.align 2, 0
_080980B0: .4byte 0xFFFFF800
_080980B4:
	rsbs r0, r5, #0
	cmp r0, r1
	bge _080980C0
	ldr r0, [r4, #0x58]
	adds r0, r0, r5
	b _080980C4
_080980C0:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
_080980C4:
	str r0, [r4, #0x58]
_080980C6:
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08098104 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098108 @ =0x0000270E
	cmp r1, r0
	bhi _080980E0
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080980E0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _0809810C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080980FA:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098104: .4byte gMission
_08098108: .4byte 0x0000270E
_0809810C: .4byte gEnemyFnTable

	thumb_func_start FUN_08098110
FUN_08098110: @ 0x08098110
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #1
	bne _0809811E
	b _080982FA
_0809811E:
	cmp r0, #1
	bgt _08098128
	cmp r0, #0
	beq _08098130
	b _08098406
_08098128:
	cmp r0, #2
	bne _0809812E
	b _080983E0
_0809812E:
	b _08098406
_08098130:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098170
	cmp r0, #2
	bgt _08098146
	cmp r0, #1
	beq _08098154
	b _0809814E
_08098146:
	cmp r0, #3
	beq _0809818C
	cmp r0, #4
	beq _080981B0
_0809814E:
	adds r6, r5, #0
	adds r6, #0x4a
	b _080981F6
_08098154:
	ldr r4, _0809816C @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0x90
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_0809816C: .4byte 0xFFFFEE00
_08098170:
	ldr r4, _08098188 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x4a
	cmp r0, #0
	beq _080981F6
	movs r4, #0xc0
	lsls r4, r4, #5
	b _080981F6
	.align 2, 0
_08098188: .4byte 0xFFFFE800
_0809818C:
	ldr r4, _080981AC @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809819C
	movs r4, #0x8c
	lsls r4, r4, #6
_0809819C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981AC: .4byte 0xFFFFDD00
_080981B0:
	ldr r4, _080981D0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080981C0
	movs r4, #0xac
	lsls r4, r4, #6
_080981C0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080981D4
	movs r0, #0x20
	orrs r0, r1
	b _080981D8
	.align 2, 0
_080981D0: .4byte 0xFFFFD500
_080981D4:
	movs r0, #0xdf
	ands r0, r1
_080981D8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	adds r6, r3, #0
_080981F6:
	ldr r1, [r5, #0x58]
	adds r1, r1, r4
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0809823C
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp1
	adds r4, r0, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToDown1
	adds r1, r0, #0
	cmp r4, #0
	bgt _08098236
	cmp r1, #0
	bge _0809822A
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_0809822A:
	rsbs r0, r4, #0
	cmp r0, r1
	bge _08098236
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	b _0809823A
_08098236:
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
_0809823A:
	str r0, [r5, #0x58]
_0809823C:
	ldr r1, _08098270 @ =0x0000DC07
	adds r0, r5, #0
	bl SetMotion
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _08098274 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809825E
	movs r4, #1
_0809825E:
	movs r0, #1
	adds r2, r4, #0
	eors r2, r0
	cmp r2, #0
	beq _08098278
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809827E
	.align 2, 0
_08098270: .4byte 0x0000DC07
_08098274: .4byte 0xFFFFF000
_08098278:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809827E:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r7, #0
	strb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	adds r3, r4, #0
	bl FUN_080b2b40
	movs r0, #0x80
	lsls r0, r0, #1
	lsls r4, r4, #9
	subs r0, r0, r4
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	asrs r0, r0, #1
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_080c6e24
	ldr r0, [r5, #0x5c]
	movs r1, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	bge _080982C8
	adds r0, #0xff
_080982C8:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	muls r0, r1, r0
	cmp r0, #0
	bge _080982D6
	adds r0, #0xff
_080982D6:
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0x14
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080982FA:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl PushoutToUp1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098314
	ldr r0, [r5, #0x58]
	adds r0, r0, r4
	str r0, [r5, #0x58]
_08098314:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _0809832E
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r4, r0, #0
	cmp r4, #0
	bge _08098340
	b _0809833A
_0809832E:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r4, r0, #0
	cmp r4, #0
	ble _08098340
_0809833A:
	ldr r0, [r5, #0x54]
	adds r0, r0, r4
	str r0, [r5, #0x54]
_08098340:
	ldr r1, [r5, #0x5c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r1
	cmp r0, #0
	bge _08098350
	adds r0, #0xff
_08098350:
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r2, [r5, #0x60]
	cmp r2, #0
	bne _08098364
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098374
_08098364:
	adds r0, r2, #0
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098374
	str r1, [r5, #0x60]
_08098374:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080983CA
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	ldr r1, _080983D4 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r4, r5, #0
	adds r4, #0x54
	movs r0, #1
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080983D8 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080983DC @ =0x0000270E
	cmp r1, r0
	bhi _080983BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080983BC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080983CA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	b _08098406
	.align 2, 0
_080983D4: .4byte 0xFFFFF000
_080983D8: .4byte gMission
_080983DC: .4byte 0x0000270E
_080983E0:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080983F4
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08098406
_080983F4:
	ldr r1, _08098410 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
_08098406:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098410: .4byte gEnemyFnTable

	thumb_func_start FUN_08098414
FUN_08098414: @ 0x08098414
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	bne _08098422
	b _08098538
_08098422:
	cmp r0, #1
	bgt _0809842C
	cmp r0, #0
	beq _08098434
	b _080985FE
_0809842C:
	cmp r0, #2
	bne _08098432
	b _080985D8
_08098432:
	b _080985FE
_08098434:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809846C
	cmp r0, #2
	bgt _0809844A
	cmp r0, #1
	beq _08098454
	b _080984EC
_0809844A:
	cmp r0, #3
	beq _08098484
	cmp r0, #4
	beq _080984A8
	b _080984EC
_08098454:
	ldr r5, _08098468 @ =0xFFFFEE00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0x90
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098468: .4byte 0xFFFFEE00
_0809846C:
	ldr r5, _08098480 @ =0xFFFFE800
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984EC
	movs r5, #0xc0
	lsls r5, r5, #5
	b _080984EC
	.align 2, 0
_08098480: .4byte 0xFFFFE800
_08098484:
	ldr r5, _080984A4 @ =0xFFFFDD00
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08098494
	movs r5, #0x8c
	lsls r5, r5, #6
_08098494:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984A4: .4byte 0xFFFFDD00
_080984A8:
	ldr r5, _080984C8 @ =0xFFFFD500
	ldrb r1, [r4, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080984B8
	movs r5, #0xac
	lsls r5, r5, #6
_080984B8:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080984CC
	movs r0, #0x20
	orrs r0, r1
	b _080984D0
	.align 2, 0
_080984C8: .4byte 0xFFFFD500
_080984CC:
	movs r0, #0xdf
	ands r0, r1
_080984D0:
	strb r0, [r4, #0xa]
	adds r0, r2, #0
	adds r1, r4, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080984EC:
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_08097224
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _0809851C
	movs r2, #1
_0809851C:
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #8
	movs r0, #0xa0
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r4, #0x5c]
	ldr r0, _080985CC @ =0xFFFFFB80
	str r0, [r4, #0x60]
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08098538:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x40
	str r1, [r4, #0x60]
	movs r0, #0xe0
	lsls r0, r0, #3
	cmp r1, r0
	ble _08098556
	str r0, [r4, #0x60]
_08098556:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098576
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080985FE
_08098576:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080c6e70
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080985D0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080985D4 @ =0x0000270E
	cmp r1, r0
	bhi _080985BC
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080985BC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _080985FE
	.align 2, 0
_080985CC: .4byte 0xFFFFFB80
_080985D0: .4byte gMission
_080985D4: .4byte 0x0000270E
_080985D8:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080985EC
	subs r0, #1
	strb r0, [r4, #0x12]
	b _080985FE
_080985EC:
	ldr r1, _08098608 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_080985FE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098608: .4byte gEnemyFnTable

	thumb_func_start FUN_0809860c
FUN_0809860c: @ 0x0809860C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809861E
	cmp r0, #1
	bne _0809861C
	b _08098772
_0809861C:
	b _0809882C
_0809861E:
	movs r6, #0
	adds r0, r5, #0
	adds r0, #0xbe
	ldrb r0, [r0]
	cmp r0, #2
	beq _08098654
	cmp r0, #2
	bgt _08098634
	cmp r0, #1
	beq _0809863E
	b _080986D4
_08098634:
	cmp r0, #3
	beq _0809866C
	cmp r0, #4
	beq _08098690
	b _080986D4
_0809863E:
	ldr r6, _08098650 @ =0xFFFFEE00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0x90
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098650: .4byte 0xFFFFEE00
_08098654:
	ldr r6, _08098668 @ =0xFFFFE800
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986D4
	movs r6, #0xc0
	lsls r6, r6, #5
	b _080986D4
	.align 2, 0
_08098668: .4byte 0xFFFFE800
_0809866C:
	ldr r6, _0809868C @ =0xFFFFDD00
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809867C
	movs r6, #0x8c
	lsls r6, r6, #6
_0809867C:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_0809868C: .4byte 0xFFFFDD00
_08098690:
	ldr r6, _080986B0 @ =0xFFFFD500
	ldrb r1, [r5, #0xa]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080986A0
	movs r6, #0xac
	lsls r6, r6, #6
_080986A0:
	lsrs r0, r1, #5
	movs r2, #1
	bics r2, r0
	cmp r2, #0
	beq _080986B4
	movs r0, #0x20
	orrs r0, r1
	b _080986B8
	.align 2, 0
_080986B0: .4byte 0xFFFFD500
_080986B4:
	movs r0, #0xdf
	ands r0, r1
_080986B8:
	strb r0, [r5, #0xa]
	adds r0, r2, #0
	adds r1, r5, #0
	adds r1, #0x4d
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r0, r0, #5
	ldrb r2, [r3]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_080986D4:
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_08097224
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08098758 @ =0x0836A3A8
	bl SetDDP
	movs r1, #0xdc
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _0809875C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08098760 @ =0xFFFFE800
	adds r0, r0, r3
	ldr r2, [r2, #0x58]
	subs r0, r0, r2
	str r0, [r5, #0x60]
	asrs r1, r1, #8
	adds r6, r1, #0
	muls r6, r1, r6
	asrs r0, r0, #8
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r6, r0
	adds r0, r6, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #8
	cmp r6, #0
	beq _08098764
	ldr r0, [r5, #0x5c]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	adds r4, r0, #0
	str r4, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	lsls r0, r0, #8
	adds r1, r6, #0
	bl __divsi3
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	str r1, [r5, #0x5c]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	str r1, [r5, #0x60]
	b _0809876C
	.align 2, 0
_08098758: .4byte 0x0836A3A8
_0809875C: .4byte pZero2
_08098760: .4byte 0xFFFFE800
_08098764:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r5, #0x5c]
	str r6, [r5, #0x60]
_0809876C:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08098772:
	movs r4, #0
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	cmp r1, #0
	ble _08098798
	ldr r1, [r5, #0x58]
	bl PushoutToLeft1
	adds r6, r0, #0
	cmp r6, #0
	bge _080987B0
	ldr r0, _08098794 @ =0xFFFFF800
	cmp r6, r0
	ble _080987B0
	b _080987A8
	.align 2, 0
_08098794: .4byte 0xFFFFF800
_08098798:
	ldr r1, [r5, #0x58]
	bl PushoutToRight1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _080987E4 @ =0x000007FE
	cmp r1, r0
	bhi _080987B0
_080987A8:
	movs r4, #1
	ldr r0, [r5, #0x54]
	adds r0, r0, r6
	str r0, [r5, #0x54]
_080987B0:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080987C0
	str r1, [r5, #0x60]
_080987C0:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r2, r0, r1
	str r2, [r5, #0x58]
	cmp r1, #0
	ble _080987EC
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToUp1
	adds r6, r0, #0
	cmp r6, #0
	bge _08098806
	ldr r0, _080987E8 @ =0xFFFFF800
	cmp r6, r0
	ble _08098806
	b _080987FE
	.align 2, 0
_080987E4: .4byte 0x000007FE
_080987E8: .4byte 0xFFFFF800
_080987EC:
	ldr r0, [r5, #0x54]
	adds r1, r2, #0
	bl PushoutToDown1
	adds r6, r0, #0
	subs r1, r6, #1
	ldr r0, _08098834 @ =0x000007FE
	cmp r1, r0
	bhi _08098806
_080987FE:
	movs r4, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r6
	str r0, [r5, #0x58]
_08098806:
	cmp r4, #0
	bne _08098826
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08098826
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809882C
_08098826:
	adds r0, r5, #0
	bl FUN_08097f3c
_0809882C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098834: .4byte 0x000007FE

	thumb_func_start FUN_08098838
FUN_08098838: @ 0x08098838
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _08098894 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809888C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08098898 @ =gEnemyFnTable
	movs r1, #0x43
	strb r1, [r3, #9]
	adds r1, #0xc9
	adds r0, r0, r1
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
	movs r0, #1
	strb r0, [r3, #0x11]
_0809888C:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08098894: .4byte gZakoHeaderPtr
_08098898: .4byte gEnemyFnTable

	thumb_func_start initCattatank
initCattatank: @ 0x0809889C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #0
	mov r8, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _08098910 @ =0x0836A4D8
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	ldr r0, _08098914 @ =FUN_08099eb4
	str r0, [r4, #0x24]
	adds r7, r6, #0
	adds r7, #0xb8
	strb r5, [r7]
	adds r0, r6, #0
	adds r0, #0xbc
	str r5, [r0]
	ldrb r0, [r6, #0x10]
	cmp r0, #0
	bne _08098918
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	subs r4, #0x28
	strb r5, [r4]
	adds r2, r6, #0
	adds r2, #0x4a
	movs r3, #0x10
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	strb r5, [r7]
	adds r3, r2, #0
	b _0809893A
	.align 2, 0
_08098910: .4byte 0x0836A4D8
_08098914: .4byte FUN_08099eb4
_08098918:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r3, r6, #0
	adds r3, #0x4c
	strb r5, [r3]
	adds r1, r6, #0
	adds r1, #0x4a
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	strb r5, [r7]
	adds r4, r3, #0
	adds r3, r1, #0
_0809893A:
	ldrb r5, [r6, #0x11]
	cmp r5, #1
	bne _080989A4
	ldr r0, _08098968 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	bge _0809896C
	movs r2, #0
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r6, #0xa]
	strb r2, [r4]
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	strb r2, [r7]
	b _08098986
	.align 2, 0
_08098968: .4byte pZero2
_0809896C:
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r6, #0xa]
	strb r5, [r4]
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	strb r5, [r7]
_08098986:
	ldr r1, _080989A0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r0, [r6, #0xd]
	b _080989BA
	.align 2, 0
_080989A0: .4byte gEnemyFnTable
_080989A4:
	ldr r1, _08098A00 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
_080989BA:
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	movs r4, #0
	str r4, [r6, #0x60]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xbb
	strb r4, [r0]
	str r4, [r6, #0x5c]
	adds r0, r6, #0
	bl isFrozen
	cmp r0, #0
	beq _080989E4
	ldr r1, _08098A04 @ =0x0000D503
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
_080989E4:
	adds r0, r6, #0
	adds r0, #0xc0
	strb r4, [r0]
	subs r0, #6
	strb r4, [r0]
	adds r0, r6, #0
	bl cattatankAI
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098A00: .4byte gEnemyFnTable
_08098A04: .4byte 0x0000D503

	thumb_func_start cattatankAI
cattatankAI: @ 0x08098A08
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08098A4C
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	bne _08098A2A
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _08098AD0
_08098A2A:
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08098A48 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl killCattatank
	b _08098B10
	.align 2, 0
_08098A48: .4byte gEnemyFnTable
_08098A4C:
	ldr r6, _08098ABC @ =gStageRun+232
	adds r5, r4, #0
	adds r5, #0x54
	adds r0, r6, #0
	adds r1, r5, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	cmp r0, r1
	bls _08098AD0
	ldr r1, [r6, #0x3c]
	ldr r0, _08098AC0 @ =0x00004FFF
	adds r1, r1, r0
	ldr r0, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	cmp r1, r0
	bge _08098AD0
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08098AD0
	strb r0, [r4, #0xf]
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _08098AC4 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098AC8 @ =0x0000270E
	cmp r1, r0
	bhi _08098A98
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098A98:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08098ACC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	b _08098B10
	.align 2, 0
_08098ABC: .4byte gStageRun+232
_08098AC0: .4byte 0x00004FFF
_08098AC4: .4byte gMission
_08098AC8: .4byte 0x0000270E
_08098ACC: .4byte gEnemyFnTable
_08098AD0:
	ldr r1, _08098B18 @ =0x0836A470
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl cattatank_08099e20
	ldrb r1, [r4, #0xd]
	subs r0, r1, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08098B00
	cmp r1, #9
	beq _08098B00
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08098B10
_08098B00:
	ldr r0, _08098B1C @ =0x0836A498
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_08098B10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098B18: .4byte 0x0836A470
_08098B1C: .4byte 0x0836A498

	thumb_func_start killCattatank
killCattatank: @ 0x08098B20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08098B78 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08098B80
	ldrb r0, [r6, #0x11]
	cmp r0, #1
	beq _08098B80
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08098B7C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _0809906E
	.align 2, 0
_08098B78: .4byte gCurStory
_08098B7C: .4byte gEnemyFnTable
_08098B80:
	ldr r5, _08098C44 @ =gStageRun+232
	adds r4, r6, #0
	adds r4, #0x54
	adds r0, r5, #0
	adds r1, r4, #0
	bl CalcFromCamera
	movs r1, #0xc0
	lsls r1, r1, #6
	mov sb, r4
	cmp r0, r1
	bls _08098C78
	ldr r1, [r5, #0x3c]
	ldr r0, _08098C48 @ =0x00004FFF
	adds r1, r1, r0
	ldr r2, [r6, #0x58]
	movs r3, #0x80
	lsls r3, r3, #6
	mov sl, r3
	adds r0, r2, r3
	cmp r1, r0
	bge _08098C78
	ldr r0, [r6, #0x54]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	beq _08098BD0
	b _08099040
_08098BD0:
	ldr r2, _08098C4C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098C50 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08098C54 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	add r5, sp, #8
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08098C58 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08098C5C @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08098C60 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08098C68
	ldr r0, [r6, #0x54]
	ldr r1, _08098C64 @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #8]
	b _08098FF0
	.align 2, 0
_08098C44: .4byte gStageRun+232
_08098C48: .4byte 0x00004FFF
_08098C4C: .4byte RNG_0202f388
_08098C50: .4byte 0x000343FD
_08098C54: .4byte 0x00269EC3
_08098C58: .4byte 0x0000D50F
_08098C5C: .4byte 0x0000D50E
_08098C60: .4byte 0x0000D510
_08098C64: .4byte 0xFFFFE000
_08098C68:
	ldr r0, [r6, #0x54]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r0, r8
	ldrb r1, [r0]
	b _08099036
_08098C78:
	ldrb r0, [r6, #0xe]
	cmp r0, #0xb
	bls _08098C80
	b _08099070
_08098C80:
	lsls r0, r0, #2
	ldr r1, _08098C8C @ =_08098C90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08098C8C: .4byte _08098C90
_08098C90: @ jump table
	.4byte _08098CC0 @ case 0
	.4byte _08098E24 @ case 1
	.4byte _08098D08 @ case 2
	.4byte _08098D1C @ case 3
	.4byte _08098E44 @ case 4
	.4byte _08099070 @ case 5
	.4byte _08099070 @ case 6
	.4byte _08099070 @ case 7
	.4byte _08099070 @ case 8
	.4byte _08099070 @ case 9
	.4byte _08098E24 @ case 10
	.4byte _08098F20 @ case 11
_08098CC0:
	ldr r1, _08098CE8 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r1, r6, #0
	adds r1, #0x8c
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _08098CEC
	movs r0, #0x80
	lsls r0, r0, #9
	ands r2, r0
	cmp r2, #0
	beq _08098CEC
	movs r0, #1
	b _08098CEE
	.align 2, 0
_08098CE8: .4byte 0x0000D505
_08098CEC:
	movs r0, #0xa
_08098CEE:
	strb r0, [r6, #0xe]
	movs r1, #0
	str r1, [r3]
	adds r0, r6, #0
	adds r0, #0x90
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	b _08098E24
_08098D08:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r0, r6, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08098D1A
	b _08099070
_08098D1A:
	b _08098E24
_08098D1C:
	ldr r1, _08098D68 @ =0x0000D505
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	movs r0, #0
	strb r0, [r6, #0x13]
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r6, #0xf]
	adds r7, r6, #0
	adds r7, #0xb8
	cmp r0, #0
	bne _08098D4A
	ldrb r1, [r7]
	mov r0, sp
	bl FUN_080c7518
_08098D4A:
	ldrb r0, [r7]
	cmp r0, #0
	bne _08098D70
	ldr r0, [sp]
	ldr r1, _08098D6C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp, #4]
	movs r0, #0x80
	b _08098D84
	.align 2, 0
_08098D68: .4byte 0x0000D505
_08098D6C: .4byte 0xFFFFF800
_08098D70:
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
_08098D84:
	str r0, [r6, #0x5c]
	adds r0, r6, #0
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08098DB0
	cmp r0, #0xfe
	bne _08098DA4
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
	b _08098DD2
_08098DA4:
	ldr r0, _08098DC0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r6, #0x54]
	cmp r1, r0
	ble _08098DC4
_08098DB0:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #1
	bl FUN_080b2b40
	b _08098DD2
	.align 2, 0
_08098DC0: .4byte pZero2
_08098DC4:
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	mov r1, sp
	movs r3, #0
	bl FUN_080b2b40
_08098DD2:
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08098E1C
	ldr r2, _08098E2C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08098E30 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08098E34 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x10
	str r0, [r5, #4]
	ldrb r1, [r7]
	ldr r2, _08098E38 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
	ldrb r1, [r7]
	ldr r2, _08098E3C @ =0x0000D510
	adds r0, r5, #0
	adds r3, r4, #0
	bl FUN_080c7570
_08098E1C:
	ldr r0, _08098E40 @ =0xFFFFFE00
	str r0, [r6, #0x60]
	movs r0, #0x1e
	strb r0, [r6, #0x12]
_08098E24:
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _08099070
	.align 2, 0
_08098E2C: .4byte RNG_0202f388
_08098E30: .4byte 0x000343FD
_08098E34: .4byte 0x00269EC3
_08098E38: .4byte 0x0000D50F
_08098E3C: .4byte 0x0000D510
_08098E40: .4byte 0xFFFFFE00
_08098E44:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098E5A
	str r1, [r6, #0x60]
_08098E5A:
	ldr r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	adds r1, r1, r0
	str r1, [r6, #0x58]
	ldr r2, [r6, #0x5c]
	rsbs r0, r2, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r2
	str r0, [r6, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x60]
	cmp r0, #0
	ble _08098ED8
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	beq _08098ED8
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _08098F14 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08098F18 @ =0x0000270E
	cmp r1, r0
	bhi _08098EB6
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_08098EB6:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _08098F1C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r6, #0x14]
_08098ED8:
	ldrb r0, [r6, #0x12]
	cmp r0, #0
	beq _08098EEA
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08098EEA
	b _08099070
_08098EEA:
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098EFA
	b _08099070
_08098EFA:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	b _08099040
	.align 2, 0
_08098F14: .4byte gMission
_08098F18: .4byte 0x0000270E
_08098F1C: .4byte gEnemyFnTable
_08098F20:
	ldr r0, [r6, #0x60]
	adds r0, #0x20
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08098F30
	str r1, [r6, #0x60]
_08098F30:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	ldr r1, [r6, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl isKilled
	cmp r0, #0
	bne _08098F5A
	b _08099070
_08098F5A:
	ldr r0, [r6, #0x54]
	str r0, [sp]
	ldr r0, [r6, #0x58]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	movs r0, #1
	mov r1, sb
	bl TryDropItem
	ldrb r0, [r6, #0xf]
	cmp r0, #0
	bne _08099040
	ldr r2, _08099004 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08099008 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809900C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r7, r0, #0x11
	movs r0, #3
	ands r7, r0
	ldr r0, [r6, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	add r5, sp, #0x18
	str r0, [r5, #4]
	movs r3, #0xb8
	adds r3, r3, r6
	mov r8, r3
	ldrb r1, [r3]
	ldr r2, _08099010 @ =0x0000D50F
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	ldr r4, _08099014 @ =0x0000D50E
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099018 @ =0x0000D510
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_080c7570
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099024
	ldr r0, [r6, #0x54]
	ldr r1, _0809901C @ =0xFFFFE000
	adds r0, r0, r1
	str r0, [sp, #0x18]
_08098FF0:
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
	ldr r2, _08099020 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
	b _08099040
	.align 2, 0
_08099004: .4byte RNG_0202f388
_08099008: .4byte 0x000343FD
_0809900C: .4byte 0x00269EC3
_08099010: .4byte 0x0000D50F
_08099014: .4byte 0x0000D50E
_08099018: .4byte 0x0000D510
_0809901C: .4byte 0xFFFFE000
_08099020: .4byte 0x0000D50D
_08099024:
	ldr r0, [r6, #0x54]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r6, #0x58]
	str r0, [r5, #4]
	mov r3, r8
	ldrb r1, [r3]
_08099036:
	ldr r2, _08099080 @ =0x0000D50D
	adds r0, r5, #0
	adds r3, r7, #0
	bl FUN_080c7570
_08099040:
	ldr r2, _08099084 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _08099088 @ =0x0000270E
	cmp r1, r0
	bhi _0809904E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0809904E:
	adds r0, r6, #0
	mov r1, sb
	bl TryDropZakoDisk
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809908C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_0809906E:
	str r0, [r6, #0x14]
_08099070:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099080: .4byte 0x0000D50D
_08099084: .4byte gMission
_08099088: .4byte 0x0000270E
_0809908C: .4byte gEnemyFnTable

	thumb_func_start nop_08099090
nop_08099090: @ 0x08099090
	movs r0, #1
	bx lr

	thumb_func_start cattatank_08099094
cattatank_08099094: @ 0x08099094
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	beq _080990A4
	cmp r0, #1
	beq _080990B6
	b _080990CE
_080990A4:
	ldrb r1, [r2, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2, #0xa]
	movs r0, #0x32
	strb r0, [r2, #0x12]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080990B6:
	ldrb r0, [r2, #0x12]
	cmp r0, #0
	beq _080990C6
	subs r0, #1
	strb r0, [r2, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080990CE
_080990C6:
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_080990CE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_080990d4
nop_080990d4: @ 0x080990D4
	movs r0, #1
	bx lr

	thumb_func_start FUN_080990d8
FUN_080990d8: @ 0x080990D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #5
	bls _080990E4
	b _08099256
_080990E4:
	lsls r0, r0, #2
	ldr r1, _080990F0 @ =_080990F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080990F0: .4byte _080990F4
_080990F4: @ jump table
	.4byte _0809910C @ case 0
	.4byte _080991A0 @ case 1
	.4byte _080991F2 @ case 2
	.4byte _0809920A @ case 3
	.4byte _08099228 @ case 4
	.4byte _0809923C @ case 5
_0809910C:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809915C @ =0x0000D503
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099160 @ =0x0836A4D8
	bl SetDDP
	ldr r0, _08099164 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099168
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
	b _08099194
	.align 2, 0
_0809915C: .4byte 0x0000D503
_08099160: .4byte 0x0836A4D8
_08099164: .4byte pZero2
_08099168:
	movs r3, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
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
	adds r0, r4, #0
	adds r0, #0xb8
	strb r3, [r0]
_08099194:
	ldr r0, [r4, #0x5c]
	asrs r0, r0, #1
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080991A0:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080991B6
	str r1, [r4, #0x60]
_080991B6:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r2, r1, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _080991D4
	ldr r1, _080991D0 @ =0xFFFFF800
	b _080991D8
	.align 2, 0
_080991D0: .4byte 0xFFFFF800
_080991D4:
	movs r1, #0x80
	lsls r1, r1, #4
_080991D8:
	adds r0, r0, r1
	adds r1, r2, #0
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099256
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	b _0809921A
_080991F2:
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08099224 @ =0x0000D504
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809920A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099256
_0809921A:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099256
	.align 2, 0
_08099224: .4byte 0x0000D504
_08099228:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809923C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099256
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099256:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_0809925c
nop_0809925c: @ 0x0809925C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099260
FUN_08099260: @ 0x08099260
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _0809926C
	b _080994E2
_0809926C:
	lsls r0, r0, #2
	ldr r1, _08099278 @ =_0809927C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099278: .4byte _0809927C
_0809927C: @ jump table
	.4byte _080992B4 @ case 0
	.4byte _080992EE @ case 1
	.4byte _080994E2 @ case 2
	.4byte _080994E2 @ case 3
	.4byte _080994E2 @ case 4
	.4byte _080994E2 @ case 5
	.4byte _080994E2 @ case 6
	.4byte _080994E2 @ case 7
	.4byte _080994E2 @ case 8
	.4byte _080994E2 @ case 9
	.4byte _0809944C @ case 10
	.4byte _0809945A @ case 11
	.4byte _08099474 @ case 12
	.4byte _080994CE @ case 13
_080992B4:
	ldr r1, _080992DC @ =0x0000D501
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080992E0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0
	str r0, [r4, #0x60]
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080992E4
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _080992E6
	.align 2, 0
_080992DC: .4byte 0x0000D501
_080992E0: .4byte 0x0836A4D8
_080992E4:
	movs r0, #0xc0
_080992E6:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080992EE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	cmp r1, #0
	ble _0809930E
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _08099318
_0809930E:
	ldr r2, _08099354 @ =0xFFFFF600
	adds r0, r0, r2
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_08099318:
	adds r2, r0, #0
	cmp r2, #0
	beq _08099324
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_08099324:
	ldrb r0, [r4, #0x11]
	adds r6, r0, #0
	cmp r6, #1
	bne _08099360
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	ldr r2, [r4, #0x54]
	ldr r5, [r4, #0x5c]
	ldr r3, [r4, #0x58]
	cmp r0, #1
	bls _0809938E
	ldr r0, _08099358 @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _0809938E
	cmp r5, #0
	ble _0809935C
	ldr r0, [r1, #0x54]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099354: .4byte 0xFFFFF600
_08099358: .4byte pZero2
_0809935C:
	ldr r0, [r1, #0x54]
	b _08099386
_08099360:
	ldr r5, [r4, #0x5c]
	cmp r5, #0
	ble _0809937C
	ldr r0, _08099378 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
	cmp r0, r2
	bge _0809938E
	b _0809938A
	.align 2, 0
_08099378: .4byte pZero2
_0809937C:
	ldr r0, _080993BC @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	ldr r3, [r4, #0x58]
_08099386:
	cmp r0, r2
	ble _0809938E
_0809938A:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809938E:
	ldrb r0, [r4, #0xe]
	cmp r0, #0xa
	beq _080993EC
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080993C0
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _080993EC
	ldr r0, _080993BC @ =pZero2
	ldr r1, [r0]
	ldr r0, [r1, #0x58]
	cmp r3, r0
	blt _080993EC
	ldr r0, [r1, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	bgt _080993CC
	b _080993DC
	.align 2, 0
_080993BC: .4byte pZero2
_080993C0:
	ldr r0, _080993D4 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r1, r0, r2
	cmp r1, #0
	ble _080993DC
_080993CC:
	ldr r0, _080993D8 @ =0x00003BFF
	cmp r1, r0
	ble _080993E4
	b _080993EC
	.align 2, 0
_080993D4: .4byte pZero2
_080993D8: .4byte 0x00003BFF
_080993DC:
	subs r1, r2, r0
	ldr r0, _0809940C @ =0x00003BFF
	cmp r1, r0
	bgt _080993EC
_080993E4:
	movs r1, #0
	movs r0, #4
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080993EC:
	cmp r5, #0
	ble _08099414
	ldr r1, _08099410 @ =0xFFFFF600
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	b _0809942C
	.align 2, 0
_0809940C: .4byte 0x00003BFF
_08099410: .4byte 0xFFFFF600
_08099414:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r1, [r4, #0x58]
	cmp r2, r1
	beq _080994E2
	ldr r0, [r4, #0x54]
	ldr r2, _08099448 @ =0xFFFFF600
_0809942C:
	adds r0, r0, r2
	bl FUN_08009f6c
	adds r2, r0, #0
	ldr r0, [r4, #0x58]
	cmp r2, r0
	beq _080994E2
	movs r1, #0
	str r1, [r4, #0x60]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _080994E2
	.align 2, 0
_08099448: .4byte 0xFFFFF600
_0809944C:
	ldr r1, _08099470 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809945A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080994E0
	.align 2, 0
_08099470: .4byte 0x0000D511
_08099474:
	ldr r1, _080994A8 @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _080994AC
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _080994C6
	.align 2, 0
_080994A8: .4byte 0x0000D512
_080994AC:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_080994C6:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080994CE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080994E2
	movs r0, #0
_080994E0:
	strb r0, [r4, #0xe]
_080994E2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start nop_080994e8
nop_080994e8: @ 0x080994E8
	movs r0, #1
	bx lr

	thumb_func_start FUN_080994ec
FUN_080994ec: @ 0x080994EC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0xd
	bls _080994F8
	b _08099736
_080994F8:
	lsls r0, r0, #2
	ldr r1, _08099504 @ =_08099508
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099504: .4byte _08099508
_08099508: @ jump table
	.4byte _08099540 @ case 0
	.4byte _0809954A @ case 1
	.4byte _08099584 @ case 2
	.4byte _08099670 @ case 3
	.4byte _08099684 @ case 4
	.4byte _08099736 @ case 5
	.4byte _08099736 @ case 6
	.4byte _08099736 @ case 7
	.4byte _08099736 @ case 8
	.4byte _08099736 @ case 9
	.4byte _080996A0 @ case 10
	.4byte _080996AE @ case 11
	.4byte _080996C8 @ case 12
	.4byte _08099722 @ case 13
_08099540:
	movs r0, #0
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809954A:
	ldr r1, _0809956C @ =0x0000D502
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099570 @ =0x0836A4D8
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08099574
	movs r0, #0x80
	lsls r0, r0, #1
	b _08099576
	.align 2, 0
_0809956C: .4byte 0x0000D502
_08099570: .4byte 0x0836A4D8
_08099574:
	ldr r0, _080995B0 @ =0xFFFFFF00
_08099576:
	str r0, [r4, #0x5c]
	movs r0, #0
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099584:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r2, r0, r1
	str r2, [r4, #0x54]
	ldr r0, [r4, #0x64]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r4, #0x64]
	cmp r1, #0
	ble _080995B4
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	b _080995BE
	.align 2, 0
_080995B0: .4byte 0xFFFFFF00
_080995B4:
	ldr r3, _080995DC @ =0xFFFFF600
	adds r0, r2, r3
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
_080995BE:
	adds r1, r0, #0
	cmp r1, #0
	beq _080995CA
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_080995CA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080995E0
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080995E6
	.align 2, 0
_080995DC: .4byte 0xFFFFF600
_080995E0:
	ldr r0, [r4, #0x54]
	ldr r3, _08099628 @ =0xFFFFF600
	adds r0, r0, r3
_080995E6:
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r1, r0, #0
	ldr r0, [r4, #0x58]
	cmp r1, r0
	beq _080995FC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	subs r0, r0, r1
	str r0, [r4, #0x54]
_080995FC:
	ldrb r0, [r4, #0x11]
	cmp r0, #1
	bne _08099634
	adds r0, r4, #0
	adds r0, #0xbb
	ldrb r0, [r0]
	cmp r0, #1
	bls _0809965C
	ldr r0, _0809962C @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x58]
	ldr r0, [r2, #0x58]
	cmp r1, r0
	blt _0809965C
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099630
	ldr r1, [r2, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099628: .4byte 0xFFFFF600
_0809962C: .4byte pZero2
_08099630:
	ldr r1, [r2, #0x54]
	b _08099652
_08099634:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809964C
	ldr r0, _08099648 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0809965C
	b _08099658
	.align 2, 0
_08099648: .4byte pZero2
_0809964C:
	ldr r0, _0809966C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
_08099652:
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _0809965C
_08099658:
	movs r0, #0xa
	strb r0, [r4, #0xe]
_0809965C:
	ldr r1, [r4, #0x64]
	movs r0, #0xc0
	lsls r0, r0, #5
	cmp r1, r0
	ble _08099736
	movs r0, #3
	b _08099734
	.align 2, 0
_0809966C: .4byte pZero2
_08099670:
	movs r1, #0xd5
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099684:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099736
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08099736
_080996A0:
	ldr r1, _080996C4 @ =0x0000D511
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080996AE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _08099734
	.align 2, 0
_080996C4: .4byte 0x0000D511
_080996C8:
	ldr r1, _080996FC @ =0x0000D512
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	bne _08099700
	movs r1, #1
	movs r0, #0x10
	orrs r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	b _0809971A
	.align 2, 0
_080996FC: .4byte 0x0000D512
_08099700:
	movs r1, #0
	movs r0, #0xef
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_0809971A:
	strb r0, [r2]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099722:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099736
	movs r0, #1
_08099734:
	strb r0, [r4, #0xe]
_08099736:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_0809973c
nop_0809973c: @ 0x0809973C
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099740
FUN_08099740: @ 0x08099740
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _0809974C
	b _08099948
_0809974C:
	lsls r0, r0, #2
	ldr r1, _08099758 @ =_0809975C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099758: .4byte _0809975C
_0809975C: @ jump table
	.4byte _08099778 @ case 0
	.4byte _08099794 @ case 1
	.4byte _080997A4 @ case 2
	.4byte _080997C4 @ case 3
	.4byte _08099858 @ case 4
	.4byte _08099878 @ case 5
	.4byte _0809990C @ case 6
_08099778:
	ldr r1, _0809979C @ =0x0000D507
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080997A0 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099794:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080998E6
	.align 2, 0
_0809979C: .4byte 0x0000D507
_080997A0: .4byte 0x0836A4D8
_080997A4:
	ldr r1, _08099844 @ =0x0000D508
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099848 @ =0x0836A520
	bl SetDDP
	movs r1, #0
	movs r0, #0x32
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080997C4:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080997E4
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080997E4
	movs r0, #0x52
	bl PlaySound
_080997E4:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #4
	bne _0809980C
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0809980C
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809984C @ =0x0836A568
	bl SetDDP
_0809980C:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bne _08099828
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _08099828
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099850 @ =0x0836A5B0
	bl SetDDP
_08099828:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #2
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099854 @ =0x0836A5F8
	b _080998D8
	.align 2, 0
_08099844: .4byte 0x0000D508
_08099848: .4byte 0x0836A520
_0809984C: .4byte 0x0836A568
_08099850: .4byte 0x0836A5B0
_08099854: .4byte 0x0836A5F8
_08099858:
	ldr r1, _080998FC @ =0x0000D509
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099900 @ =0x0836A5B0
	bl SetDDP
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0x12]
	strb r1, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099878:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08099898
	adds r0, r4, #0
	adds r0, #0x90
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08099898
	movs r0, #0x52
	bl PlaySound
_08099898:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r5, r0, #0
	cmp r1, #1
	bne _080998C0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080998C0
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099904 @ =0x0836A568
	bl SetDDP
_080998C0:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _080998DC
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080998DC
	adds r0, #1
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099908 @ =0x0836A520
_080998D8:
	bl SetDDP
_080998DC:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099948
_080998E6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099948
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _08099948
	.align 2, 0
_080998FC: .4byte 0x0000D509
_08099900: .4byte 0x0836A5B0
_08099904: .4byte 0x0836A568
_08099908: .4byte 0x0836A520
_0809990C:
	ldr r0, _08099924 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r4, #0x54]
	subs r2, r0, r1
	cmp r2, #0
	ble _0809992C
	ldr r0, _08099928 @ =0x000039FF
	cmp r2, r0
	ble _08099934
	b _08099940
	.align 2, 0
_08099924: .4byte pZero2
_08099928: .4byte 0x000039FF
_0809992C:
	subs r1, r1, r0
	ldr r0, _0809993C @ =0x000039FF
	cmp r1, r0
	bgt _08099940
_08099934:
	movs r1, #0
	movs r0, #3
	b _08099944
	.align 2, 0
_0809993C: .4byte 0x000039FF
_08099940:
	movs r1, #0
	movs r0, #2
_08099944:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099948:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_08099950
nop_08099950: @ 0x08099950
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099954
FUN_08099954: @ 0x08099954
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08099964
	cmp r0, #1
	beq _080999A4
	b _08099A88
_08099964:
	ldr r1, _0809998C @ =0x0000D50C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099990 @ =0x0836A4D8
	bl SetDDP
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldr r0, _08099994 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099998
	movs r0, #0x60
	b _0809999C
	.align 2, 0
_0809998C: .4byte 0x0000D50C
_08099990: .4byte 0x0836A4D8
_08099994: .4byte pZero2
_08099998:
	movs r0, #0x60
	rsbs r0, r0, #0
_0809999C:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080999A4:
	ldr r1, [r4, #0x5c]
	rsbs r0, r1, #0
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080999C6
	str r1, [r4, #0x60]
_080999C6:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _080999E0
	ldr r0, [r4, #0x54]
	ldr r2, _080999DC @ =0xFFFFF600
	b _080999E6
	.align 2, 0
_080999DC: .4byte 0xFFFFF600
_080999E0:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_080999E6:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099A06
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099A06:
	ldrb r3, [r4, #0xa]
	movs r5, #0x10
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	bne _08099A40
	ldr r0, _08099A3C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099A6E
	movs r2, #1
	movs r0, #0x10
	orrs r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r5
	b _08099A66
	.align 2, 0
_08099A3C: .4byte pZero2
_08099A40:
	ldr r0, _08099A90 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bge _08099A6E
	movs r2, #0
	movs r0, #0xef
	ands r0, r3
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_08099A66:
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xb8
	strb r2, [r0]
_08099A6E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08099A88
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099A88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A90: .4byte pZero2

	thumb_func_start nop_08099a94
nop_08099a94: @ 0x08099A94
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099a98
FUN_08099a98: @ 0x08099A98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _08099B08
	cmp r0, #1
	bgt _08099AAC
	cmp r0, #0
	beq _08099AB8
	b _08099CDA
_08099AAC:
	cmp r0, #2
	beq _08099BA6
	cmp r0, #3
	bne _08099AB6
	b _08099BB4
_08099AB6:
	b _08099CDA
_08099AB8:
	ldr r1, _08099AE0 @ =0x0000D50A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099AE4 @ =0x0836A640
	bl SetDDP
	ldr r0, _08099AE8 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _08099AF0
	ldr r0, _08099AEC @ =0xFFFFFA00
	str r0, [r4, #0x5c]
	movs r0, #0xc0
	rsbs r0, r0, #0
	b _08099AF8
	.align 2, 0
_08099AE0: .4byte 0x0000D50A
_08099AE4: .4byte 0x0836A640
_08099AE8: .4byte pZero2
_08099AEC: .4byte 0xFFFFFA00
_08099AF0:
	movs r0, #0xc0
	lsls r0, r0, #3
	str r0, [r4, #0x5c]
	movs r0, #0xc0
_08099AF8:
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x60]
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B08:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099B30
	str r1, [r4, #0x60]
_08099B30:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08099B52
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099B52:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099B64
	ldr r0, [r4, #0x54]
	ldr r1, _08099B60 @ =0xFFFFF600
	adds r0, r0, r1
	b _08099B6C
	.align 2, 0
_08099B60: .4byte 0xFFFFF600
_08099B64:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r0, r0, r2
_08099B6C:
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099B8A
	adds r1, r4, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r5, [r4, #0x60]
_08099B8A:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	bne _08099B9A
	b _08099CDA
_08099B9A:
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
	b _08099CDA
_08099BA6:
	ldr r1, _08099BF0 @ =0x0000D50B
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099BB4:
	ldr r1, [r4, #0x64]
	ldr r2, [r4, #0x5c]
	subs r1, r1, r2
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099BDC
	str r1, [r4, #0x60]
_08099BDC:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r1, r0, r1
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _08099BF8
	ldr r0, [r4, #0x54]
	ldr r2, _08099BF4 @ =0xFFFFF600
	b _08099BFE
	.align 2, 0
_08099BF0: .4byte 0x0000D50B
_08099BF4: .4byte 0xFFFFF600
_08099BF8:
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
_08099BFE:
	adds r0, r0, r2
	bl PushoutToUp1
	adds r2, r0, #0
	cmp r2, #0
	beq _08099C1E
	adds r3, r4, #0
	adds r3, #0xbb
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x60]
_08099C1E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099C36
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08099C36:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08099CDA
	ldr r1, [r5]
	cmp r1, #0
	beq _08099CAC
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _08099C6C
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C66
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099C66:
	movs r1, #0
	movs r0, #7
	b _08099CD6
_08099C6C:
	cmp r2, #2
	bne _08099C96
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _08099C90
	movs r0, #0
	strb r0, [r4, #0xf]
	ldr r1, _08099C8C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08099CC6
	.align 2, 0
_08099C8C: .4byte gEnemyFnTable
_08099C90:
	movs r1, #0
	movs r0, #9
	b _08099CD6
_08099C96:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CA8
	movs r0, #0
	strb r0, [r4, #0xf]
	b _08099CBA
_08099CA8:
	movs r1, #0
	b _08099CD4
_08099CAC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08099CD4
	strb r1, [r4, #0xf]
_08099CBA:
	ldr r1, _08099CD0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08099CC6:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _08099CDA
	.align 2, 0
_08099CD0: .4byte gEnemyFnTable
_08099CD4:
	movs r0, #1
_08099CD6:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099CDA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start nop_08099ce0
nop_08099ce0: @ 0x08099CE0
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099ce4
FUN_08099ce4: @ 0x08099CE4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099CF4
	cmp r5, #1
	beq _08099D08
	b _08099D4E
_08099CF4:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099D74 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099D08:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099D18
	str r1, [r4, #0x60]
_08099D18:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099D78 @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099D44
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099D4E
_08099D44:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099D4E:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099D6C
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099D6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099D74: .4byte 0x0836A550
_08099D78: .4byte 0xFFFFF600

	thumb_func_start nop_08099d7c
nop_08099d7c: @ 0x08099D7C
	movs r0, #1
	bx lr

	thumb_func_start nop_08099d80
nop_08099d80: @ 0x08099D80
	bx lr
	.align 2, 0

	thumb_func_start nop_08099d84
nop_08099d84: @ 0x08099D84
	movs r0, #1
	bx lr

	thumb_func_start FUN_08099d88
FUN_08099d88: @ 0x08099D88
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _08099D98
	cmp r5, #1
	beq _08099DAC
	b _08099DF2
_08099D98:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08099E18 @ =0x0836A550
	bl SetDDP
	str r5, [r4, #0x60]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08099DAC:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08099DBC
	str r1, [r4, #0x60]
_08099DBC:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	ldr r2, _08099E1C @ =0xFFFFF600
	adds r0, r0, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bne _08099DE8
	ldr r0, [r4, #0x54]
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _08099DF2
_08099DE8:
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0
	str r0, [r4, #0x60]
_08099DF2:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08099E10
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #0
	strb r1, [r0]
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099E10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099E18: .4byte 0x0836A550
_08099E1C: .4byte 0xFFFFF600

	thumb_func_start cattatank_08099e20
cattatank_08099e20: @ 0x08099E20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _08099EAA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _08099EAA
	ldr r2, _08099E6C @ =0x0836A670
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099E84
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E70
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #7
	b _08099E7E
	.align 2, 0
_08099E6C: .4byte 0x0836A670
_08099E70:
	cmp r1, #0x30
	bne _08099EAA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #9
_08099E7E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _08099EAA
_08099E84:
	cmp r1, #0
	beq _08099EAA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08099E9E
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _08099EAA
_08099E9E:
	cmp r1, #0x30
	bne _08099EAA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_08099EAA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08099eb4
FUN_08099eb4: @ 0x08099EB4
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _08099ECC
	cmp r0, #0xe
	beq _08099ECC
	cmp r0, #0xf
	bne _08099EF6
_08099ECC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF6
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _08099EEE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08099EF4
_08099EEE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08099EF4:
	strb r0, [r1]
_08099EF6:
	ldr r0, [r3, #4]
	ldr r1, _08099F28 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _08099F2C
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #6
	beq _08099F4E
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08099F20
	adds r0, r4, #0
	bl isFrozen
_08099F20:
	movs r1, #0
	movs r0, #6
	b _08099F4A
	.align 2, 0
_08099F28: .4byte 0x000200FF
_08099F2C:
	ldr r4, [r2, #0x2c]
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp r0, #2
	bne _08099F4E
	ldrb r0, [r3, #6]
	cmp r0, #0x40
	beq _08099F4E
	adds r0, r4, #0
	bl isFrozen
	adds r1, r0, #0
	cmp r1, #0
	bne _08099F4E
	movs r0, #5
_08099F4A:
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08099F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08099f54
FUN_08099f54: @ 0x08099F54
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, _08099FB0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _08099FA8
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08099FB4 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
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
	movs r0, #6
	strb r0, [r3, #0x10]
	str r4, [r3, #0x54]
	str r5, [r3, #0x58]
	str r6, [r3, #0x68]
	str r7, [r3, #0x5c]
_08099FA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099FB0: .4byte gZakoHeaderPtr
_08099FB4: .4byte gEnemyFnTable

	thumb_func_start FUN_08099fb8
FUN_08099fb8: @ 0x08099FB8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809A024 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809A01E
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A028 @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r3, #9]
	adds r1, #0xcc
	adds r0, r0, r1
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
	strb r5, [r3, #0x10]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	subs r0, r0, r4
	lsls r0, r0, #0xc
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r0, r1
	str r0, [r3, #0x54]
	str r6, [r3, #0x58]
	strb r4, [r3, #0x12]
	str r7, [r3, #0x28]
_0809A01E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A024: .4byte gZakoHeaderPtr
_0809A028: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a02c
FUN_0809a02c: @ 0x0809A02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _0809A0A8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809A0A0
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809A0AC @ =gEnemyFnTable
	movs r1, #0x44
	strb r1, [r4, #9]
	adds r1, #0xcc
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #0
	strh r2, [r4, #0x20]
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	movs r0, #4
	strb r0, [r4, #0x10]
	movs r0, #0xb4
	lsls r0, r0, #9
	str r0, [r4, #0x54]
	movs r1, #0x82
	lsls r1, r1, #0xb
	str r1, [r4, #0x58]
	bl FUN_08009f6c
	str r0, [r4, #0x58]
	ldr r1, [r4, #0x54]
	ldr r0, _0809A0B0 @ =0xFFFF6800
	adds r1, r1, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	subs r0, r0, r5
	lsls r0, r0, #0xc
	adds r1, r1, r0
	str r1, [r4, #0x54]
	strb r5, [r4, #0x12]
	str r6, [r4, #0x28]
_0809A0A0:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809A0A8: .4byte gZakoHeaderPtr
_0809A0AC: .4byte gEnemyFnTable
_0809A0B0: .4byte 0xFFFF6800

	thumb_func_start nop_0809a0b4
nop_0809a0b4: @ 0x0809A0B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a0b8
FUN_0809a0b8: @ 0x0809A0B8
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0809A0CE
	movs r0, #0
	b _0809A0FA
_0809A0CE:
	ldr r0, [r2, #0x28]
	adds r0, #0x31
	movs r1, #0xa
	strb r1, [r0]
	ldr r1, _0809A100 @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	ldr r1, _0809A104 @ =0x0836A764
	ldrb r0, [r2, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	adds r0, r2, #0
	bl FUN_0809a1d4
	movs r0, #1
_0809A0FA:
	pop {r1}
	bx r1
	.align 2, 0
_0809A100: .4byte gEnemyFnTable
_0809A104: .4byte 0x0836A764

	thumb_func_start FUN_0809a108
FUN_0809a108: @ 0x0809A108
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809A184 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r1, _0809A188 @ =0x0836A76A
	ldrb r0, [r5, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	ldrb r0, [r5, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r0, [r5, #0x10]
	cmp r0, #6
	beq _0809A152
	ldr r0, _0809A18C @ =0x0836A772
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r5, #0
	bl SetMotion
_0809A152:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809A190 @ =0x0836A6D4
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0809A194 @ =nop_0809a0b4
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl FUN_0809a198
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A184: .4byte gEnemyFnTable
_0809A188: .4byte 0x0836A76A
_0809A18C: .4byte 0x0836A772
_0809A190: .4byte 0x0836A6D4
_0809A194: .4byte nop_0809a0b4

	thumb_func_start FUN_0809a198
FUN_0809a198: @ 0x0809A198
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809a0b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A1C6
	ldr r1, _0809A1CC @ =0x0836A68C
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809A1D0 @ =0x0836A6A8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809A1C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A1CC: .4byte 0x0836A68C
_0809A1D0: .4byte 0x0836A6A8

	thumb_func_start FUN_0809a1d4
FUN_0809a1d4: @ 0x0809A1D4
	push {lr}
	ldr r2, _0809A1E8 @ =0x0836A6C4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809A1E8: .4byte 0x0836A6C4

	thumb_func_start nop_0809a1ec
nop_0809a1ec: @ 0x0809A1EC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809a1f0
FUN_0809a1f0: @ 0x0809A1F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A210
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A20C @ =0x0836A6D4
	bl SetDDP
	b _0809A30A
	.align 2, 0
_0809A20C: .4byte 0x0836A6D4
_0809A210:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809A228 @ =0x0836A6EC
	bl SetDDP
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0809A22C
	cmp r0, #1
	beq _0809A292
	b _0809A30A
	.align 2, 0
_0809A228: .4byte 0x0836A6EC
_0809A22C:
	adds r1, r5, #0
	adds r1, #0x22
	movs r4, #1
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0x12]
	eors r4, r0
	cmp r4, #0
	beq _0809A250
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A256
_0809A250:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A256:
	strb r0, [r5, #0xa]
	movs r1, #1
	ands r1, r4
	adds r0, r5, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r4]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r5, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r5, #0x5c]
	strb r3, [r5, #0x13]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809A292:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _0809A310 @ =gSineTable
	ldrb r0, [r5, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x13]
	adds r0, #4
	movs r4, #0
	strb r0, [r5, #0x13]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, [r5, #0x54]
	ldr r1, _0809A314 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A30A
	str r4, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0809A318 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
_0809A30A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A310: .4byte gSineTable
_0809A314: .4byte 0xFFFF3000
_0809A318: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a31c
FUN_0809a31c: @ 0x0809A31C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A33C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A338 @ =0x0836A6D4
	bl SetDDP
	b _0809A49A
	.align 2, 0
_0809A338: .4byte 0x0836A6D4
_0809A33C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A354 @ =0x0836A704
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A358
	cmp r0, #1
	beq _0809A3BE
	b _0809A49A
	.align 2, 0
_0809A354: .4byte 0x0836A704
_0809A358:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0809A378 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
	ldrb r2, [r4, #0x12]
	cmp r2, #0
	beq _0809A37C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A382
	.align 2, 0
_0809A378: .4byte 0x00003501
_0809A37C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A382:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r0, #0x3c
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A3BE:
	ldrb r0, [r4, #0x13]
	subs r0, #1
	movs r5, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A3F2
	ldr r2, _0809A4A4 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A4A8 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A4AC @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r4, #0x13]
	ldr r1, _0809A4B0 @ =0x00003501
	adds r0, r4, #0
	bl SetMotion
_0809A3F2:
	ldr r1, [r4, #0x5c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	bge _0809A400
	adds r0, #0xff
_0809A400:
	asrs r1, r0, #8
	str r1, [r4, #0x5c]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0809A422
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0809A422:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _0809A450
	ldr r0, _0809A4A0 @ =0xFFFFFEC0
	str r0, [r4, #0x60]
	movs r2, #0x80
	lsls r2, r2, #2
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	subs r2, r2, r0
	str r2, [r4, #0x5c]
_0809A450:
	ldr r0, [r4, #0x54]
	ldr r1, _0809A4B4 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A49A
	str r5, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0x32
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A4B8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A49A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A4A0: .4byte 0xFFFFFEC0
_0809A4A4: .4byte RNG_0202f388
_0809A4A8: .4byte 0x000343FD
_0809A4AC: .4byte 0x00269EC3
_0809A4B0: .4byte 0x00003501
_0809A4B4: .4byte 0xFFFF3000
_0809A4B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a4bc
FUN_0809a4bc: @ 0x0809A4BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A4DC
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4D8 @ =0x0836A6D4
	bl SetDDP
	b _0809A5CC
	.align 2, 0
_0809A4D8: .4byte 0x0836A6D4
_0809A4DC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A4F4 @ =0x0836A71C
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A4F8
	cmp r0, #1
	beq _0809A55C
	b _0809A5CC
	.align 2, 0
_0809A4F4: .4byte 0x0836A71C
_0809A4F8:
	movs r1, #0xf0
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A516
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A51C
_0809A516:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A51C:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xb0
	lsls r2, r2, #1
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A55C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A5D4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A5D8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A5CC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A5DC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A5CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5D4: .4byte gSineTable
_0809A5D8: .4byte 0xFFFF3000
_0809A5DC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a5e0
FUN_0809a5e0: @ 0x0809A5E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A600
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A5FC @ =0x0836A6D4
	bl SetDDP
	b _0809A6EC
	.align 2, 0
_0809A5FC: .4byte 0x0836A6D4
_0809A600:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809A618 @ =0x0836A734
	bl SetDDP
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A61C
	cmp r0, #1
	beq _0809A67A
	b _0809A6EC
	.align 2, 0
_0809A618: .4byte 0x0836A734
_0809A61C:
	movs r1, #0xef
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r1, [r4, #0x12]
	movs r0, #1
	adds r2, r0, #0
	eors r2, r1
	cmp r2, #0
	beq _0809A63A
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A640
_0809A63A:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A640:
	strb r0, [r4, #0xa]
	movs r1, #1
	ands r1, r2
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	strb r1, [r0]
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r1, r1, #4
	ldrb r2, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	movs r2, #0xe0
	ldrb r1, [r4, #0x12]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #6
	subs r2, r2, r0
	str r2, [r4, #0x5c]
	strb r3, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A67A:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809A6F4 @ =gSineTable
	ldrb r0, [r4, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0809A694
	adds r1, #3
_0809A694:
	asrs r1, r1, #2
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x13]
	adds r0, #3
	movs r5, #0
	strb r0, [r4, #0x13]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x54]
	ldr r1, _0809A6F8 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A6EC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809A6FC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A6EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A6F4: .4byte gSineTable
_0809A6F8: .4byte 0xFFFF3000
_0809A6FC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a700
FUN_0809a700: @ 0x0809A700
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A724
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A720 @ =0x0836A6D4
	bl SetDDP
	b _0809A8F4
	.align 2, 0
_0809A720: .4byte 0x0836A6D4
_0809A724:
	adds r0, r6, #0
	adds r0, #0x74
	ldr r1, _0809A740 @ =0x0836A74C
	bl SetDDP
	ldrb r0, [r6, #0xe]
	cmp r0, #1
	beq _0809A782
	cmp r0, #1
	bgt _0809A744
	cmp r0, #0
	beq _0809A750
	b _0809A8F4
	.align 2, 0
_0809A740: .4byte 0x0836A74C
_0809A744:
	cmp r0, #2
	beq _0809A7A8
	cmp r0, #3
	bne _0809A74E
	b _0809A894
_0809A74E:
	b _0809A8F4
_0809A750:
	movs r1, #0xf1
	lsls r1, r1, #8
	adds r0, r6, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A79C @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A7A0 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A7A4 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A782:
	ldrb r0, [r6, #0x12]
	subs r0, #1
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A794
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A794:
	adds r0, r6, #0
	bl UpdateMotionGraphic
	b _0809A8F4
	.align 2, 0
_0809A79C: .4byte RNG_0202f388
_0809A7A0: .4byte 0x000343FD
_0809A7A4: .4byte 0x00269EC3
_0809A7A8:
	movs r0, #0x1e
	strb r0, [r6, #0x12]
	ldr r2, _0809A800 @ =RNG_0202f388
	mov r8, r2
	ldr r0, [r2]
	ldr r7, _0809A804 @ =0x000343FD
	muls r0, r7, r0
	ldr r5, _0809A808 @ =0x00269EC3
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r4, r0, #1
	str r4, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x1e
	bl __umodsi3
	adds r0, #0x1e
	strb r0, [r6, #0x12]
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r3, r0, #1
	mov r1, r8
	str r3, [r1]
	lsrs r0, r0, #0x11
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0809A810
	adds r0, r3, #0
	muls r0, r7, r0
	adds r0, r0, r5
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r2, r8
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #0xa
	ldr r3, _0809A80C @ =0xFFFFFE00
	adds r0, r0, r3
	b _0809A846
	.align 2, 0
_0809A800: .4byte RNG_0202f388
_0809A804: .4byte 0x000343FD
_0809A808: .4byte 0x00269EC3
_0809A80C: .4byte 0xFFFFFE00
_0809A810:
	movs r2, #0x80
	rsbs r2, r2, #0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r1, _0809A860 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r3, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r2, r2, r0
	adds r0, r3, #0
	muls r0, r7, r0
	ldr r3, _0809A860 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	mov r3, r8
	str r1, [r3]
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r1, r0
_0809A846:
	str r0, [r6, #0x5c]
	movs r1, #0
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	ble _0809A852
	movs r1, #1
_0809A852:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A864
	ldrb r1, [r6, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0809A86A
	.align 2, 0
_0809A860: .4byte 0x00269EC3
_0809A864:
	ldrb r1, [r6, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A86A:
	strb r0, [r6, #0xa]
	adds r1, r2, #0
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r1, _0809A900 @ =0x0000F101
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0809A894:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldrb r0, [r6, #0x12]
	subs r0, #1
	movs r2, #0
	strb r0, [r6, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809A8AC
	strb r2, [r6, #0xe]
_0809A8AC:
	ldr r0, [r6, #0x54]
	ldr r1, _0809A904 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A8EE
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0809A908 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_0809A8EE:
	adds r0, r6, #0
	bl UpdateMotionGraphic
_0809A8F4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A900: .4byte 0x0000F101
_0809A904: .4byte 0xFFFF3000
_0809A908: .4byte gEnemyFnTable

	thumb_func_start FUN_0809a90c
FUN_0809a90c: @ 0x0809A90C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AA02
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809A926
	cmp r0, #1
	beq _0809A9B2
	b _0809AA02
_0809A926:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x19
	strb r0, [r1]
	movs r3, #0x80
	rsbs r3, r3, #0
	ldr r2, _0809A974 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809A978 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _0809A97C @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0x7f
	ands r0, r1
	subs r3, r3, r0
	ldrb r0, [r4, #0x12]
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #1
	movs r0, #1
	subs r0, r0, r1
	muls r0, r3, r0
	str r0, [r4, #0x5c]
	movs r1, #0
	cmp r0, #0
	ble _0809A964
	movs r1, #1
_0809A964:
	adds r2, r1, #0
	cmp r2, #0
	beq _0809A980
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _0809A986
	.align 2, 0
_0809A974: .4byte RNG_0202f388
_0809A978: .4byte 0x000343FD
_0809A97C: .4byte 0x00269EC3
_0809A980:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_0809A986:
	strb r0, [r4, #0xa]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0xf2
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809A9B2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, _0809AA08 @ =0xFFFF3000
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #9
	cmp r0, r1
	bls _0809A9FC
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809AA0C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809A9FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809AA02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA08: .4byte 0xFFFF3000
_0809AA0C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aa10
FUN_0809aa10: @ 0x0809AA10
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AA2E
	adds r0, r5, #7
_0809AA2E:
	asrs r5, r0, #3
	cmp r5, #0
	bge _0809AA38
	movs r5, #0
	b _0809AA40
_0809AA38:
	adds r0, r5, #4
	cmp r0, #0x1e
	ble _0809AA40
	movs r5, #0x1a
_0809AA40:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AA4A
	adds r0, r4, #7
_0809AA4A:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AA54
	movs r4, #1
	b _0809AA5A
_0809AA54:
	cmp r4, #0x11
	ble _0809AA5A
	movs r4, #0x11
_0809AA5A:
	ldr r0, _0809AA88 @ =0x080FF064
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, _0809AA8C @ =0x080FF06C
	adds r1, r5, #2
	adds r4, #1
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl minigame_str_080e9d04
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AA88: .4byte 0x080FF064
_0809AA8C: .4byte 0x080FF06C

	thumb_func_start FUN_0809aa90
FUN_0809aa90: @ 0x0809AA90
	push {r4, r5, r6, lr}
	ldr r6, [r0, #8]
	ldr r0, [r6, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	asrs r5, r0, #8
	ldr r0, [r6, #0x58]
	ldr r1, [r1, #0xc]
	subs r0, r0, r1
	asrs r4, r0, #8
	subs r5, #0x10
	adds r0, r5, #0
	cmp r5, #0
	bge _0809AAAE
	adds r0, r5, #7
_0809AAAE:
	asrs r5, r0, #3
	ldrb r1, [r6, #0x13]
	subs r0, r5, r1
	adds r0, #1
	cmp r0, #0
	bge _0809AABE
	subs r5, r1, #1
	b _0809AAC6
_0809AABE:
	adds r0, r5, #7
	cmp r0, #0x1e
	ble _0809AAC6
	movs r5, #0x17
_0809AAC6:
	adds r4, #0x10
	adds r0, r4, #0
	cmp r4, #0
	bge _0809AAD0
	adds r0, r4, #7
_0809AAD0:
	asrs r4, r0, #3
	cmp r4, #0
	bgt _0809AADA
	movs r4, #1
	b _0809AAE0
_0809AADA:
	cmp r4, #0x11
	ble _0809AAE0
	movs r4, #0x11
_0809AAE0:
	ldr r0, [r6, #0x68]
	cmp r0, #1
	ble _0809AAFC
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	bl minigame_str_080e9d04
	ldr r0, _0809AB20 @ =0x080FF070
	adds r1, r5, #2
	adds r2, r4, #0
	bl PrintUnicodeString
_0809AAFC:
	ldr r0, _0809AB24 @ =0x080FF078
	adds r4, #1
	adds r1, r5, #0
	adds r2, r4, #0
	bl PrintUnicodeString
	ldr r0, [r6, #0x5c]
	adds r1, r5, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r2, r4, #0
	bl minigame_str_080e9d04
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AB20: .4byte 0x080FF070
_0809AB24: .4byte 0x080FF078

	thumb_func_start FUN_0809ab28
FUN_0809ab28: @ 0x0809AB28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _0809ABA6
	cmp r5, #1
	bgt _0809AB3C
	cmp r5, #0
	beq _0809AB46
	b _0809AC1E
_0809AB3C:
	cmp r5, #2
	beq _0809ABBC
	cmp r5, #3
	beq _0809ABC6
	b _0809AC1E
_0809AB46:
	ldr r1, [r4, #0x68]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0809AB6C
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809AB68 @ =FUN_0809aa10
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	b _0809AB9C
	.align 2, 0
_0809AB68: .4byte FUN_0809aa10
_0809AB6C:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _0809ABB8 @ =FUN_0809aa90
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xa]
	strb r5, [r4, #0x13]
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _0809AB9C
_0809AB88:
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	adds r1, r0, #0
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	cmp r1, #0
	bne _0809AB88
_0809AB9C:
	movs r0, #0x1e
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABA6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0
	bne _0809AC1E
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0809AC1E
	.align 2, 0
_0809ABB8: .4byte FUN_0809aa90
_0809ABBC:
	movs r0, #0x18
	str r0, [r4, #0x64]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ABC6:
	ldr r0, [r4, #0x64]
	subs r0, #1
	str r0, [r4, #0x64]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809ABDC
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	b _0809ABE2
_0809ABDC:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809ABE2:
	strb r0, [r4, #0xa]
	ldr r2, [r4, #0x64]
	cmp r2, #0
	bne _0809AC1E
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0809AC24 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
_0809AC1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AC24: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ac28
FUN_0809ac28: @ 0x0809AC28
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AC7A
	ldr r0, [r4, #0x20]
	adds r0, #0x3c
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #1
	bl FUN_08099f54
	ldr r1, [r4, #0x1c]
	adds r1, #1
	cmp r1, #4
	ble _0809AC70
	movs r1, #4
_0809AC70:
	ldrb r0, [r6]
	muls r1, r0, r1
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AC7A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809ACD4 @ =0x0836A77E
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809ACD8 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809ACD4: .4byte 0x0836A77E
_0809ACD8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809acdc
FUN_0809acdc: @ 0x0809ACDC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AD2A
	ldr r0, [r4, #0x20]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x20]
	adds r6, r4, #0
	adds r6, #0x35
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, [r4, #0x1c]
	movs r3, #5
	bl FUN_08099f54
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	ldr r0, [r4, #0x24]
	adds r0, r0, r1
	str r0, [r4, #0x24]
_0809AD2A:
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #4]
	ldr r0, [r5, #0x58]
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #4
	bl CreateSmoke
	movs r0, #0x31
	bl PlaySound
	ldr r2, _0809AD84 @ =0x0836A784
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	movs r3, #3
	bl FUN_080b822c
	ldr r1, _0809AD88 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r5, #0x14]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AD84: .4byte 0x0836A784
_0809AD88: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ad8c
FUN_0809ad8c: @ 0x0809AD8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AD9E
	cmp r5, #1
	beq _0809ADF0
	b _0809AE5C
_0809AD9E:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809ADCC
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AE04 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809ADCC:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	str r5, [r4, #0x60]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809ADF0:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AE08
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AE0E
	.align 2, 0
_0809AE04: .4byte 0xFFFFFED4
_0809AE08:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AE0E:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AE5C
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AE38
	ldr r1, _0809AE64 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AE38:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0809AE4C
	adds r0, #0xff
_0809AE4C:
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r1, #0x10
	str r1, [r4, #0x60]
_0809AE5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE64: .4byte gEnemyFnTable

	thumb_func_start FUN_0809ae68
FUN_0809ae68: @ 0x0809AE68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x28]
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0809AE7A
	cmp r5, #1
	beq _0809AECA
	b _0809AF14
_0809AE7A:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AEA8
	adds r0, r6, #0
	adds r0, #0x35
	strb r5, [r0]
	str r5, [r6, #0x1c]
	subs r0, #3
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #1
	rsbs r2, r2, #0
	movs r3, #5
	rsbs r3, r3, #0
	bl FUN_08099f54
	ldr r0, [r6, #0x20]
	ldr r1, _0809AEE0 @ =0xFFFFFED4
	adds r0, r0, r1
	str r0, [r6, #0x20]
_0809AEA8:
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809AECA:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809AEE4
	ldrb r0, [r4, #0xa]
	orrs r0, r1
	b _0809AEEA
	.align 2, 0
_0809AEE0: .4byte 0xFFFFFED4
_0809AEE4:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0809AEEA:
	strb r0, [r4, #0xa]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809AF14
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809AF14
	ldr r1, _0809AF1C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0809AF14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AF1C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809af20
FUN_0809af20: @ 0x0809AF20
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _0809AF80 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809AF76
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AF84 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r4, #9]
	adds r1, #0xcf
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	strb r6, [r4, #0x11]
	str r7, [r4, #0x28]
_0809AF76:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809AF80: .4byte gZakoHeaderPtr
_0809AF84: .4byte gEnemyFnTable

	thumb_func_start FUN_0809af88
FUN_0809af88: @ 0x0809AF88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r0, _0809AFE8 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809AFE0
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809AFEC @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #1
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	str r6, [r3, #0x28]
_0809AFE0:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AFE8: .4byte gZakoHeaderPtr
_0809AFEC: .4byte gEnemyFnTable

	thumb_func_start FUN_0809aff0
FUN_0809aff0: @ 0x0809AFF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B05C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B052
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B060 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #2
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B052:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B05C: .4byte gZakoHeaderPtr
_0809B060: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b064
FUN_0809b064: @ 0x0809B064
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _0809B0D0 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809B0C6
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809B0D4 @ =gEnemyFnTable
	movs r1, #0x45
	strb r1, [r3, #9]
	adds r1, #0xcf
	adds r0, r0, r1
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
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	movs r0, #3
	strb r0, [r3, #0x10]
	strb r5, [r3, #0x11]
	adds r0, r3, #0
	adds r0, #0xb4
	strb r6, [r0]
	str r7, [r3, #0x28]
_0809B0C6:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B0D0: .4byte gZakoHeaderPtr
_0809B0D4: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b0d8
FUN_0809b0d8: @ 0x0809B0D8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldrb r7, [r6, #0x10]
	cmp r7, #0
	bne _0809B160
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0x11
	strb r0, [r1]
	movs r5, #1
	ldrb r0, [r6, #0xa]
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	strb r5, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	mov r1, sp
	movs r2, #0
	bl FUN_0809af88
	str r0, [r6, #0x2c]
	ldrb r0, [r6, #0xb]
	orrs r4, r0
	strb r4, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B15C @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	strb r7, [r6, #0xd]
	strb r7, [r6, #0xe]
	strb r7, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B15C: .4byte gEnemyFnTable
_0809B160:
	cmp r7, #1
	bne _0809B1D4
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl ResetDynamicMotion
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldrb r0, [r6, #0xa]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4c
	movs r4, #0
	strb r7, [r0]
	adds r5, r6, #0
	adds r5, #0x4a
	movs r3, #0x10
	ldrb r1, [r5]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r5]
	ldrb r0, [r6, #0xb]
	orrs r2, r0
	strb r2, [r6, #0xb]
	ldr r0, [r6, #0x28]
	ldr r0, [r0, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r6, #0x1d]
	ldr r1, _0809B1D0 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r7, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #3
	strb r0, [r6, #0xd]
	strb r4, [r6, #0xe]
	strb r4, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B1D0: .4byte gEnemyFnTable
_0809B1D4:
	cmp r7, #2
	bne _0809B278
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r2, #0
	movs r5, #0
	orrs r1, r0
	movs r0, #2
	orrs r1, r0
	orrs r1, r2
	strb r1, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B224
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B220 @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x18
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r7, [r0]
	b _0809B248
	.align 2, 0
_0809B220: .4byte 0x0836A7D0
_0809B224:
	movs r0, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B26C @ =0x0836A7D0
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #8
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #1
	strb r0, [r1]
_0809B248:
	ldr r0, _0809B270 @ =FUN_0809bd2c
	str r0, [r4, #0x24]
	ldr r1, _0809B274 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	movs r1, #4
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #0
	strb r1, [r6, #0xd]
	strb r0, [r6, #0xe]
	strb r0, [r6, #0xf]
	b _0809B2C6
	.align 2, 0
_0809B26C: .4byte 0x0836A7D0
_0809B270: .4byte FUN_0809bd2c
_0809B274: .4byte gEnemyFnTable
_0809B278:
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r1, [r6, #0xa]
	movs r0, #1
	movs r5, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _0809B2D4 @ =0x0836A818
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #4
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _0809B2D8 @ =gEnemyFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	movs r0, #5
	strb r0, [r6, #0xd]
	strb r5, [r6, #0xe]
	strb r5, [r6, #0xf]
_0809B2C6:
	adds r0, r6, #0
	bl FUN_0809b2dc
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2D4: .4byte 0x0836A818
_0809B2D8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b2dc
FUN_0809b2dc: @ 0x0809B2DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809B308 @ =0x0836A7A0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0809B30C @ =0x0836A7B8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B308: .4byte 0x0836A7A0
_0809B30C: .4byte 0x0836A7B8

	thumb_func_start FUN_0809b310
FUN_0809b310: @ 0x0809B310
	adds r3, r0, #0
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _0809B34C @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r3, #0x14]
	strb r2, [r3, #0xd]
	strb r2, [r3, #0xe]
	strb r2, [r3, #0xf]
	bx lr
	.align 2, 0
_0809B34C: .4byte gEnemyFnTable
_0809B350:
	.byte 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0809b354
FUN_0809b354: @ 0x0809B354
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B380
	ldr r1, _0809B37C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B400
	.align 2, 0
_0809B37C: .4byte gEnemyFnTable
_0809B380:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B3A8
	cmp r0, #1
	bgt _0809B390
	cmp r0, #0
	beq _0809B39A
	b _0809B400
_0809B390:
	cmp r0, #2
	beq _0809B3D0
	cmp r0, #3
	beq _0809B3E0
	b _0809B400
_0809B39A:
	ldr r1, _0809B3CC @ =0x0000BF01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3A8:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B400
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B3FE
	.align 2, 0
_0809B3CC: .4byte 0x0000BF01
_0809B3D0:
	movs r1, #0xbf
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B3E0:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B400
_0809B3FE:
	strb r0, [r4, #0xe]
_0809B400:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B408:
	.byte 0x01, 0x20, 0x70, 0x47, 0x70, 0x47, 0x00, 0x00
	.byte 0x01, 0x20, 0x70, 0x47, 0x70, 0x47, 0x00, 0x00, 0x01, 0x20, 0x70, 0x47

	thumb_func_start FUN_0809b41c
FUN_0809b41c: @ 0x0809B41C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bls _0809B448
	ldr r1, _0809B444 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	b _0809B4CC
	.align 2, 0
_0809B444: .4byte gEnemyFnTable
_0809B448:
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0809B470
	cmp r0, #1
	bgt _0809B458
	cmp r0, #0
	beq _0809B462
	b _0809B4CC
_0809B458:
	cmp r0, #2
	beq _0809B49C
	cmp r0, #3
	beq _0809B4AA
	b _0809B4CC
_0809B462:
	ldr r1, _0809B498 @ =0x0000BF02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B470:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809B4CC
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _0809B4CA
	.align 2, 0
_0809B498: .4byte 0x0000BF02
_0809B49C:
	ldr r1, _0809B4D4 @ =0x0000BF03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809B4AA:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	str r0, [r4, #0x54]
	ldr r0, [r1, #0x58]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x28]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B4CC
_0809B4CA:
	strb r0, [r4, #0xe]
_0809B4CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809B4D4: .4byte 0x0000BF03

	thumb_func_start FUN_0809b4d8
FUN_0809b4d8: @ 0x0809B4D8
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b4dc
FUN_0809b4dc: @ 0x0809B4DC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809B5D8
	adds r2, r5, #0
	adds r2, #0xb6
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809B512
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r6, r5, #0
	adds r6, #0xb4
	cmp r0, #2
	beq _0809B552
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldrh r2, [r1, #0x38]
	adds r0, r0, r2
	b _0809B52C
_0809B512:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne _0809B53C
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #5
_0809B52C:
	strh r0, [r1, #0x38]
	ldr r0, _0809B538 @ =0x00000137
	bl PlaySound
	b _0809B552
	.align 2, 0
_0809B538: .4byte 0x00000137
_0809B53C:
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _0809B5BC @ =0x00000137
	bl PlaySound
_0809B552:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0809B5C0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B5C4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _0809B5C8 @ =0x00269EC3
	adds r4, r4, r3
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5CC @ =0x00004707
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D0 @ =0x00004708
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D4 @ =0x00004709
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	b _0809B924
	.align 2, 0
_0809B5BC: .4byte 0x00000137
_0809B5C0: .4byte RNG_0202f388
_0809B5C4: .4byte 0x000343FD
_0809B5C8: .4byte 0x00269EC3
_0809B5CC: .4byte 0x00004707
_0809B5D0: .4byte 0x00004708
_0809B5D4: .4byte 0x00004709
_0809B5D8:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0809B5F8
	movs r1, #1
	ands r2, r1
	cmp r2, #0
	beq _0809B5F8
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809B5F8
	strb r1, [r3]
	movs r0, #0xa
	strb r0, [r5, #0xe]
_0809B5F8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _0809B600
	b _0809B936
_0809B600:
	lsls r0, r0, #2
	ldr r1, _0809B60C @ =_0809B610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B60C: .4byte _0809B610
_0809B610: @ jump table
	.4byte _0809B640 @ case 0
	.4byte _0809B6B6 @ case 1
	.4byte _0809B6F6 @ case 2
	.4byte _0809B700 @ case 3
	.4byte _0809B936 @ case 4
	.4byte _0809B73E @ case 5
	.4byte _0809B7F2 @ case 6
	.4byte _0809B936 @ case 7
	.4byte _0809B936 @ case 8
	.4byte _0809B936 @ case 9
	.4byte _0809B818 @ case 10
	.4byte _0809B8C0 @ case 11
_0809B640:
	movs r4, #0
	str r4, [r5, #0x2c]
	strb r4, [r3]
	adds r0, r5, #0
	adds r0, #0xb6
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r1, _0809B688 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0809B68C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0809B690
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
	b _0809B6AC
	.align 2, 0
_0809B688: .4byte 0x00004703
_0809B68C: .4byte pZero2
_0809B690:
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
_0809B6AC:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B6B6:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B6EE
	b _0809B936
_0809B6EE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809B936
_0809B6F6:
	movs r0, #0x30
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B700:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B738
	b _0809B936
_0809B738:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0809B936
_0809B73E:
	movs r0, #0
	str r0, [r5, #0x2c]
	strb r0, [r3]
	ldr r1, _0809B7A0 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r6, _0809B7A4 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B7A8
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B7C4
	.align 2, 0
_0809B7A0: .4byte 0x00004703
_0809B7A4: .4byte pZero2
_0809B7A8:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B7BC
	ldr r0, _0809B7B8 @ =0xFFFFFF00
	b _0809B7C0
	.align 2, 0
_0809B7B8: .4byte 0xFFFFFF00
_0809B7BC:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B7C0:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B7C4:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B7F2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B816
	b _0809B936
_0809B816:
	b _0809B924
_0809B818:
	ldr r6, _0809B86C @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B870
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B88C
	.align 2, 0
_0809B86C: .4byte pZero2
_0809B870:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B884
	ldr r0, _0809B880 @ =0xFFFFFF00
	b _0809B888
	.align 2, 0
_0809B880: .4byte 0xFFFFFF00
_0809B884:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B888:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B88C:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldr r1, _0809B940 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809B944 @ =0x0836A800
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B8C0:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, [r5, #0x60]
	adds r0, r0, r3
	str r0, [r5, #0x58]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x5c]
	rsbs r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809B936
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B914
	ldrh r0, [r1, #0x38]
	adds r0, #5
	strh r0, [r1, #0x38]
	ldr r0, _0809B948 @ =0x00000137
	bl PlaySound
_0809B914:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_0809B924:
	ldr r1, _0809B94C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809B936:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B940: .4byte 0x00004703
_0809B944: .4byte 0x0836A800
_0809B948: .4byte 0x00000137
_0809B94C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809b950
FUN_0809b950: @ 0x0809B950
	movs r0, #1
	bx lr

	thumb_func_start FUN_0809b954
FUN_0809b954: @ 0x0809B954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BA0C
	adds r1, r7, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	ldr r2, _0809B9F0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B9F4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _0809B9F8 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldr r2, _0809B9FC @ =0x00004707
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA00 @ =0x00004708
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	ldr r2, _0809BA04 @ =0x00004709
	mov r0, sp
	movs r1, #0
	adds r3, r4, #0
	bl CreateGhost82_2
	adds r1, r0, #0
	ldr r0, [r7, #0x28]
	str r0, [r1, #0x28]
	movs r0, #0x2a
	bl PlaySound
	ldr r1, _0809BA08 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
	adds r0, r7, #0
	bl FUN_0809b310
	b _0809BD16
	.align 2, 0
_0809B9F0: .4byte RNG_0202f388
_0809B9F4: .4byte 0x000343FD
_0809B9F8: .4byte 0x00269EC3
_0809B9FC: .4byte 0x00004707
_0809BA00: .4byte 0x00004708
_0809BA04: .4byte 0x00004709
_0809BA08: .4byte gEnemyFnTable
_0809BA0C:
	ldrb r0, [r7, #0xe]
	cmp r0, #6
	bls _0809BA14
	b _0809BD16
_0809BA14:
	lsls r0, r0, #2
	ldr r1, _0809BA20 @ =_0809BA24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BA20: .4byte _0809BA24
_0809BA24: @ jump table
	.4byte _0809BA40 @ case 0
	.4byte _0809BAFC @ case 1
	.4byte _0809BBD0 @ case 2
	.4byte _0809BBDA @ case 3
	.4byte _0809BD16 @ case 4
	.4byte _0809BC08 @ case 5
	.4byte _0809BCD2 @ case 6
_0809BA40:
	ldr r1, _0809BA80 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	ldr r0, _0809BA84 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r7, #0x54]
	cmp r1, r0
	ble _0809BA88
	movs r2, #1
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r7, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _0809BAA6
	.align 2, 0
_0809BA80: .4byte 0x00004703
_0809BA84: .4byte pZero2
_0809BA88:
	movs r2, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r7, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809BAA6:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	movs r0, #4
	strb r0, [r7, #0x13]
	ldr r4, _0809BB44 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r1, _0809BB48 @ =0x000343FD
	mov r8, r1
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r6, _0809BB4C @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x54]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x58]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BAFC:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BB18
	ldr r0, [r7, #0x54]
	ldr r1, _0809BB50 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x64]
	adds r0, r0, r1
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x5c]
_0809BB18:
	ldrb r0, [r7, #0x12]
	cmp r0, #0
	beq _0809BB28
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BBAC
_0809BB28:
	movs r0, #0xb
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0x13]
	cmp r0, #0
	beq _0809BB3C
	subs r0, #1
	strb r0, [r7, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BB54
_0809BB3C:
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BBC8
	.align 2, 0
_0809BB44: .4byte RNG_0202f388
_0809BB48: .4byte 0x000343FD
_0809BB4C: .4byte 0x00269EC3
_0809BB50: .4byte 0xFFFC4000
_0809BB54:
	ldr r4, _0809BBA0 @ =RNG_0202f388
	ldr r0, [r4]
	ldr r3, _0809BBA4 @ =0x000343FD
	mov r8, r3
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _0809BBA8 @ =0x00269EC3
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r5, r0, #1
	str r5, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x64]
	adds r1, r1, r0
	str r1, [r7, #0x5c]
	mov r0, r8
	muls r0, r5, r0
	adds r0, r0, r6
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r4]
	lsrs r0, r0, #0x11
	movs r1, #0x50
	bl __umodsi3
	subs r0, #0x28
	lsls r0, r0, #8
	ldr r1, [r7, #0x68]
	adds r1, r1, r0
	str r1, [r7, #0x60]
	b _0809BBC8
	.align 2, 0
_0809BBA0: .4byte RNG_0202f388
_0809BBA4: .4byte 0x000343FD
_0809BBA8: .4byte 0x00269EC3
_0809BBAC:
	ldr r0, [r7, #0x5c]
	ldr r1, [r7, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x54]
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #5
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r7, #0x58]
_0809BBC8:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	b _0809BD16
_0809BBD0:
	movs r0, #7
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_0809BBDA:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BBEA
	ldr r0, [r7, #0x54]
	ldr r2, _0809BC04 @ =0xFFFC4000
	adds r0, r0, r2
	str r0, [r7, #0x54]
_0809BBEA:
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809BBFE
	b _0809BD16
_0809BBFE:
	movs r0, #5
	strb r0, [r7, #0xe]
	b _0809BD16
	.align 2, 0
_0809BC04: .4byte 0xFFFC4000
_0809BC08:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BC18
	ldr r0, [r7, #0x54]
	ldr r3, _0809BC74 @ =0xFFFC4000
	adds r0, r0, r3
	str r0, [r7, #0x54]
_0809BC18:
	ldr r1, _0809BC78 @ =0x00004703
	adds r0, r7, #0
	bl SetMotion
	ldr r5, _0809BC7C @ =pZero2
	ldr r2, [r5]
	ldr r0, [r7, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r7, #0x64]
	ldr r1, [r7, #0x58]
	movs r3, #0xd8
	lsls r3, r3, #6
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r7, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809BC80
	ldr r0, [r7, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x64]
	ldr r0, [r7, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r7, #0x68]
	b _0809BC9C
	.align 2, 0
_0809BC74: .4byte 0xFFFC4000
_0809BC78: .4byte 0x00004703
_0809BC7C: .4byte pZero2
_0809BC80:
	ldr r0, [r5]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809BC94
	ldr r0, _0809BC90 @ =0xFFFFFF00
	b _0809BC98
	.align 2, 0
_0809BC90: .4byte 0xFFFFFF00
_0809BC94:
	movs r0, #0x80
	lsls r0, r0, #1
_0809BC98:
	str r0, [r7, #0x64]
	str r4, [r7, #0x68]
_0809BC9C:
	ldr r1, [r7, #0x64]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x5c]
	ldr r1, [r7, #0x68]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #6
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r7, #0x60]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	movs r0, #0x78
	strb r0, [r7, #0x12]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _0809BD16
_0809BCD2:
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	bne _0809BCE2
	ldr r0, [r7, #0x54]
	ldr r1, _0809BD24 @ =0xFFFC4000
	adds r0, r0, r1
	str r0, [r7, #0x54]
_0809BCE2:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x5c]
	adds r0, r0, r1
	str r0, [r7, #0x54]
	ldr r0, [r7, #0x58]
	ldr r1, [r7, #0x60]
	adds r0, r0, r1
	str r0, [r7, #0x58]
	adds r0, r7, #0
	bl UpdateMotionGraphic
	ldrb r0, [r7, #0x12]
	subs r0, #1
	strb r0, [r7, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809BD16
	ldr r1, _0809BD28 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r7, #0x14]
_0809BD16:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BD24: .4byte 0xFFFC4000
_0809BD28: .4byte gEnemyFnTable

	thumb_func_start FUN_0809bd2c
FUN_0809bd2c: @ 0x0809BD2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0xc]
	ldr r3, [r2, #4]
	ldr r0, [r4, #0x2c]
	mov ip, r0
	ldr r0, [r3, #4]
	ldr r1, _0809BD58 @ =0x00FF00FF
	ands r0, r1
	ldr r1, _0809BD5C @ =0x00020002
	cmp r0, r1
	bne _0809BD60
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD94
	ldr r0, [r2, #0x2c]
	mov r1, ip
	str r0, [r1, #0x2c]
	b _0809BD94
	.align 2, 0
_0809BD58: .4byte 0x00FF00FF
_0809BD5C: .4byte 0x00020002
_0809BD60:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BD94
	mov r0, ip
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809BD8C
	mov r1, ip
	adds r1, #0xa4
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0x10
	bgt _0809BD94
	adds r0, r2, #0
	adds r0, #8
	strh r0, [r1]
	b _0809BD94
_0809BD8C:
	mov r1, ip
	adds r1, #0xb6
	movs r0, #1
	strb r0, [r1]
_0809BD94:
	ldrb r0, [r3, #4]
	cmp r0, #2
	beq _0809BDCC
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _0809BDCC
	ldr r0, [r4, #0xc]
	ldr r3, [r0, #0x2c]
	adds r0, r3, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809BDCC
	ldr r0, [r4, #4]
	ldrb r2, [r0, #1]
	cmp r2, #2
	bne _0809BDCC
	mov r1, ip
	adds r1, #0xb7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809BDC8
	adds r0, r3, #0
	adds r0, #0xb6
	strb r2, [r0]
	b _0809BDCC
_0809BDC8:
	adds r0, #1
	strb r0, [r1]
_0809BDCC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809bdd4
FUN_0809bdd4: @ 0x0809BDD4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809BE2C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BE24
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809BE30 @ =gEnemyFnTable
	movs r1, #0x46
	strb r1, [r3, #9]
	adds r1, #0xd2
	adds r0, r0, r1
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
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_0809BE24:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809BE2C: .4byte gZakoHeaderPtr
_0809BE30: .4byte gEnemyFnTable

	thumb_func_start FUN_0809be34
FUN_0809be34: @ 0x0809BE34
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _0809BEC4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0xe9
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r1, [r4, #0x11]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #5
	adds r0, #0x18
	lsls r0, r0, #8
	str r0, [r4, #0x54]
	str r2, [r4, #0x58]
	movs r0, #0xe1
	lsls r0, r0, #4
	adds r5, r5, r0
	ldrh r0, [r5]
	str r0, [r4, #0x60]
	ldrh r0, [r5]
	str r0, [r4, #0x5c]
	strb r2, [r4, #0x13]
	adds r0, r4, #0
	bl FUN_0809bec8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809BEC4: .4byte gEnemyFnTable

	thumb_func_start FUN_0809bec8
FUN_0809bec8: @ 0x0809BEC8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bls _0809BEE4
	b _0809C06A
_0809BEE4:
	lsls r0, r0, #2
	ldr r1, _0809BEF0 @ =_0809BEF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809BEF0: .4byte _0809BEF4
_0809BEF4: @ jump table
	.4byte _0809BF08 @ case 0
	.4byte _0809BF2C @ case 1
	.4byte _0809BF46 @ case 2
	.4byte _0809BF62 @ case 3
	.4byte _0809BFE4 @ case 4
_0809BF08:
	ldr r0, [r4, #0x58]
	adds r0, #0x80
	str r0, [r4, #0x58]
	ldr r1, _0809BF28 @ =0x000006FF
	cmp r0, r1
	bgt _0809BF16
	b _0809C06A
_0809BF16:
	movs r0, #0xe0
	lsls r0, r0, #3
	str r0, [r4, #0x58]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BF28: .4byte 0x000006FF
_0809BF2C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF3C
	b _0809C06A
_0809BF3C:
	movs r0, #0x14
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF46:
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0809BF5C
	b _0809C06A
_0809BF5C:
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
_0809BF62:
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r5, r0, r2
	str r5, [r4, #0x58]
	ldr r1, _0809BFC0 @ =0x00000DCC
	adds r0, r7, r1
	ldrb r0, [r0, #4]
	adds r3, r2, #0
	cmp r0, #3
	bhi _0809BF9A
	ldr r6, _0809BFC4 @ =gJoypad
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809BF88
	adds r0, r5, r3
	str r0, [r4, #0x58]
_0809BF88:
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809BF9A
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
_0809BF9A:
	adds r0, r4, #0
	bl FUN_0809c110
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0809C06A
	cmp r0, #1
	bne _0809BFC8
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r1, r2
	str r1, [r0]
	ldr r0, [r4, #0x60]
	b _0809BFD8
	.align 2, 0
_0809BFC0: .4byte 0x00000DCC
_0809BFC4: .4byte gJoypad
_0809BFC8:
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r4, #0x54]
	ldr r3, _0809BFE0 @ =0xFFFFE000
	adds r1, r1, r3
	str r1, [r0]
	ldr r0, [r4, #0x60]
	rsbs r0, r0, #0
_0809BFD8:
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C068
	.align 2, 0
_0809BFE0: .4byte 0xFFFFE000
_0809BFE4:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r3, r0, r1
	str r3, [r4, #0x54]
	ldr r5, _0809C038 @ =0x00000DCC
	adds r0, r7, r5
	ldrb r0, [r0, #4]
	adds r2, r1, #0
	cmp r0, #3
	bhi _0809C01C
	ldr r5, _0809C03C @ =gJoypad
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C00A
	adds r0, r3, r2
	str r0, [r4, #0x54]
_0809C00A:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C01C
	ldr r0, [r4, #0x54]
	adds r0, r0, r2
	str r0, [r4, #0x54]
_0809C01C:
	cmp r2, #0
	ble _0809C044
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	ble _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r3, _0809C040 @ =0x00000E04
	adds r1, r7, r3
	b _0809C058
	.align 2, 0
_0809C038: .4byte 0x00000DCC
_0809C03C: .4byte gJoypad
_0809C040: .4byte 0x00000E04
_0809C044:
	adds r2, r4, #0
	adds r2, #0xc0
	ldr r1, [r4, #0x54]
	ldr r0, [r2]
	cmp r1, r0
	bge _0809C06A
	adds r0, r4, #0
	adds r0, #0xbc
	ldr r5, _0809C0BC @ =0x00000E04
	adds r1, r7, r5
_0809C058:
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	str r0, [r4, #0x54]
	movs r0, #3
_0809C068:
	strb r0, [r4, #0xd]
_0809C06A:
	ldr r1, [r4, #0x58]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _0809C0E8
	ldr r0, _0809C0C0 @ =0x00000DCC
	adds r3, r7, r0
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r4, #0x54]
	asrs r1, r0, #8
	adds r2, r1, #0
	subs r2, #0x18
	adds r0, r2, #0
	cmp r2, #0
	bge _0809C08E
	adds r0, r1, #7
_0809C08E:
	asrs r1, r0, #5
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	ldrb r5, [r4, #0x11]
	cmp r0, r5
	bne _0809C0CC
	ldr r2, _0809C0C4 @ =0x00000DE9
	adds r0, r7, r2
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r3, #4]
	cmp r0, #3
	bhi _0809C0D6
	ldr r0, [r3, #8]
	adds r0, #0xa
	str r0, [r3, #8]
	ldr r1, _0809C0C8 @ =0x0001869F
	cmp r0, r1
	bls _0809C0D6
	str r1, [r3, #8]
	b _0809C0D6
	.align 2, 0
_0809C0BC: .4byte 0x00000E04
_0809C0C0: .4byte 0x00000DCC
_0809C0C4: .4byte 0x00000DE9
_0809C0C8: .4byte 0x0001869F
_0809C0CC:
	ldr r3, _0809C0F0 @ =0x00000E13
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809C0D6:
	ldr r1, _0809C0F4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C0E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809C0F0: .4byte 0x00000E13
_0809C0F4: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c0f8
FUN_0809c0f8: @ 0x0809C0F8
	ldr r2, _0809C10C @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0809C10C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c110
FUN_0809c110: @ 0x0809C110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r5, [r0, #0x28]
	ldr r0, [r0, #0x54]
	asrs r1, r0, #8
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0
	bge _0809C12C
	adds r0, r1, #7
_0809C12C:
	asrs r0, r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0
	ldr r1, _0809C1A4 @ =0x0836A85C
	mov r8, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r6, r1, #1
	ldr r2, _0809C1A8 @ =0x0836A87A
	mov sb, r2
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sl, r1
_0809C148:
	adds r0, r4, r6
	mov r7, r8
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0809C1BA
	ldrb r2, [r1]
	lsrs r0, r2, #1
	lsls r0, r0, #0xc
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r3, r0, r1
	lsls r1, r2, #1
	movs r7, #0xdf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0xff
	beq _0809C1B0
	mov r0, ip
	adds r0, #0xb8
	ldr r0, [r0]
	cmp r0, r3
	bge _0809C1B0
	mov r1, ip
	ldr r0, [r1, #0x58]
	cmp r0, r3
	blt _0809C1B0
	mov r0, ip
	adds r0, #0xbc
	strb r2, [r0]
	ldr r2, _0809C1AC @ =0x00000E04
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r7, ip
	str r3, [r7, #0x58]
	mov r1, sl
	adds r0, r4, r1
	add r0, sb
	ldrb r0, [r0]
	b _0809C1BC
	.align 2, 0
_0809C1A4: .4byte 0x0836A85C
_0809C1A8: .4byte 0x0836A87A
_0809C1AC: .4byte 0x00000E04
_0809C1B0:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _0809C148
_0809C1BA:
	movs r0, #0
_0809C1BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809c1cc
FUN_0809c1cc: @ 0x0809C1CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _0809C224 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0809C21C
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C228 @ =gEnemyFnTable
	movs r1, #0x47
	strb r1, [r3, #9]
	adds r1, #0xd5
	adds r0, r0, r1
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
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_0809C21C:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C224: .4byte gZakoHeaderPtr
_0809C228: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c22c
FUN_0809c22c: @ 0x0809C22C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldr r1, _0809C2D4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	movs r1, #0xe9
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	subs r2, #1
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xde
	lsls r0, r0, #4
	adds r4, r4, r0
	ldrb r0, [r5, #0x10]
	adds r4, r4, r0
	ldrb r1, [r4]
	strb r1, [r5, #0x12]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl ForceEntityPalette
	movs r0, #0xd8
	lsls r0, r0, #8
	str r0, [r5, #0x54]
	ldrb r1, [r5, #0x10]
	lsls r1, r1, #4
	movs r0, #0x30
	subs r0, r0, r1
	lsls r0, r0, #8
	str r0, [r5, #0x58]
	ldrb r0, [r5, #0x10]
	cmp r0, #3
	bne _0809C2C6
	movs r0, #0xe8
	lsls r0, r0, #8
	str r0, [r5, #0x54]
_0809C2C6:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0809C2D0
	cmp r0, #3
	bne _0809C2DC
_0809C2D0:
	ldr r0, _0809C2D8 @ =0xFFFFFF00
	b _0809C2DE
	.align 2, 0
_0809C2D4: .4byte gEnemyFnTable
_0809C2D8: .4byte 0xFFFFFF00
_0809C2DC:
	movs r0, #0
_0809C2DE:
	str r0, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r5, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r5, #0x58]
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl FUN_0809c300
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809c300
FUN_0809c300: @ 0x0809C300
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x28]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0809C312
	cmp r0, #1
	beq _0809C350
	b _0809C38E
_0809C312:
	ldr r1, _0809C344 @ =0x00000E0F
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r0, _0809C348 @ =gZakoHeaderPtr
	ldr r0, [r0]
	movs r3, #0xa
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bgt _0809C38E
	ldr r1, _0809C34C @ =0x00000E12
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C38E
	movs r3, #0xde
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	b _0809C38C
	.align 2, 0
_0809C344: .4byte 0x00000E0F
_0809C348: .4byte gZakoHeaderPtr
_0809C34C: .4byte 0x00000E12
_0809C350:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	cmp r1, r0
	blt _0809C38E
	ldrb r1, [r4, #0x12]
	adds r1, #5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ForceEntityPalette
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r0, [r5]
	str r0, [r4, #0x58]
	movs r0, #0
_0809C38C:
	strb r0, [r4, #0xd]
_0809C38E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809c39c
FUN_0809c39c:
	.byte 0x04, 0x4A, 0x41, 0x7A
	.byte 0x89, 0x00, 0x89, 0x18, 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69, 0x41, 0x61, 0x70, 0x47
	.byte 0x48, 0x59, 0x36, 0x08

	thumb_func_start FUN_0809c3b4
FUN_0809c3b4: @ 0x0809C3B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _0809C428 @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C41A
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C42C @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r5, [r4, #0x10]
	strb r2, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0xb4
	strh r7, [r0]
	mov r0, r8
	str r0, [r4, #0x28]
_0809C41A:
	adds r0, r4, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809C428: .4byte gZakoHeaderPtr
_0809C42C: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c430
FUN_0809c430: @ 0x0809C430
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, _0809C48C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0809C484
	adds r1, r4, #0
	adds r1, #0x25
	movs r3, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0809C490 @ =gEnemyFnTable
	movs r1, #0x48
	strb r1, [r4, #9]
	adds r1, #0xd8
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r2, #0
	strh r3, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x22
	strb r2, [r0]
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	strb r2, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #0x11]
	str r6, [r4, #0x28]
_0809C484:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C48C: .4byte gZakoHeaderPtr
_0809C490: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c494
FUN_0809c494: @ 0x0809C494
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	movs r4, #0
	movs r6, #0
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl ResetDynamicMotion
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	bne _0809C534
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _0809C4DE
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x80
	b _0809C504
_0809C4DE:
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
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
	movs r0, #0x80
	rsbs r0, r0, #0
_0809C504:
	str r0, [r5, #0x5c]
	ldrb r1, [r5, #0xb]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strb r0, [r5, #0xb]
	ldr r0, [r5, #0x28]
	ldrb r0, [r0, #0x1c]
	strb r0, [r5, #0x1d]
	ldr r1, _0809C530 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r2, [r5, #0xd]
	strb r2, [r5, #0xe]
	strb r2, [r5, #0xf]
	b _0809C56E
	.align 2, 0
_0809C530: .4byte gEnemyFnTable
_0809C534:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0809C57C @ =0x0836A8DC
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r1, _0809C580 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r1, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
_0809C56E:
	adds r0, r5, #0
	bl FUN_0809c584
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C57C: .4byte 0x0836A8DC
_0809C580: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c584
FUN_0809c584: @ 0x0809C584
	push {lr}
	ldr r2, _0809C598 @ =0x0836A8BC
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0809C598: .4byte 0x0836A8BC

	thumb_func_start FUN_0809c59c
FUN_0809c59c: @ 0x0809C59C
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _0809C5B8 @ =gEnemyFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_0809C5B8: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c5bc
FUN_0809c5bc: @ 0x0809C5BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #0xe]
	cmp r2, #1
	beq _0809C614
	cmp r2, #1
	bgt _0809C5D0
	cmp r2, #0
	beq _0809C5D6
	b _0809C65A
_0809C5D0:
	cmp r2, #2
	beq _0809C63C
	b _0809C65A
_0809C5D6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C5F6
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	movs r2, #0xc0
	lsls r2, r2, #4
	b _0809C5FC
_0809C5F6:
	ldr r1, [r4, #0x28]
	ldr r0, [r1, #0x54]
	ldr r2, _0809C638 @ =0xFFFFF400
_0809C5FC:
	adds r0, r0, r2
	str r0, [r4, #0x64]
	movs r0, #0x80
	str r0, [r4, #0x60]
	ldr r0, [r1, #0x58]
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #0x68]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C614:
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x54]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x58]
	subs r0, r0, r1
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _0809C65A
	.align 2, 0
_0809C638: .4byte 0xFFFFF400
_0809C63C:
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x18]
	ldrb r1, [r0, #9]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809C65A
	ldr r1, _0809C660 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte gEnemyFnTable

	thumb_func_start FUN_0809c664
FUN_0809c664: @ 0x0809C664
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bhi _0809C6C8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0809C6BC
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp]
	ldr r1, _0809C6B4 @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #2
	mov r1, sp
	bl CreateSmoke
	ldr r0, [sp]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, _0809C6B8 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #2
	mov r1, sp
	b _0809C6CE
	.align 2, 0
_0809C6B4: .4byte 0xFFFFF800
_0809C6B8: .4byte 0xFFFFFC00
_0809C6BC:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C6EC
_0809C6C8:
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #2
_0809C6CE:
	bl CreateSmoke
	ldr r1, _0809C6E8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0809C852
	.align 2, 0
_0809C6E8: .4byte gEnemyFnTable
_0809C6EC:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0809C6F8
	cmp r0, #1
	beq _0809C76C
	b _0809C852
_0809C6F8:
	ldr r1, _0809C734 @ =0x0000A304
	adds r0, r4, #0
	bl SetMotion
	ldr r0, [r4, #0x28]
	ldrb r1, [r0, #0xa]
	movs r3, #0x10
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0809C738
	movs r0, #0xc0
	str r0, [r4, #0x5c]
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
	b _0809C75C
	.align 2, 0
_0809C734: .4byte 0x0000A304
_0809C738:
	movs r0, #0xc0
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	movs r2, #1
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
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
	orrs r0, r3
_0809C75C:
	strb r0, [r2]
	ldr r0, _0809C7EC @ =0xFFFFFC00
	str r0, [r4, #0x60]
	movs r0, #0x28
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0809C76C:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	beq _0809C786
	subs r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809C786
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0809C7F0 @ =0x0836A8DC
	bl SetDDP
_0809C786:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0809C796
	str r1, [r4, #0x60]
_0809C796:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	str r1, [r4, #0x58]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	beq _0809C7BA
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r0, _0809C7F4 @ =0xFFFFFD00
	str r0, [r4, #0x60]
_0809C7BA:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	ble _0809C7F8
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToLeft1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C7EC: .4byte 0xFFFFFC00
_0809C7F0: .4byte 0x0836A8DC
_0809C7F4: .4byte 0xFFFFFD00
_0809C7F8:
	ldr r0, [r4, #0x54]
	ldr r1, _0809C824 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	bl PushoutToRight1
	adds r5, r0, #0
	cmp r5, #0
	beq _0809C84C
	ldr r0, [r4, #0x5c]
	rsbs r0, r0, #0
	str r0, [r4, #0x5c]
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0809C828
	movs r0, #0x10
	orrs r0, r2
	b _0809C82C
	.align 2, 0
_0809C824: .4byte 0xFFFFF800
_0809C828:
	movs r0, #0xef
	ands r0, r2
_0809C82C:
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809C84C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_0809C852:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
