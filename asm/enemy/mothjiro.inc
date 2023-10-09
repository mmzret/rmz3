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
