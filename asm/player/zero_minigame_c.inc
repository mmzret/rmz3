	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start recoil_minigame_08036938
recoil_minigame_08036938: @ 0x08036938
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _08036944
	b _08036B86
_08036944:
	lsls r0, r0, #2
	ldr r1, _08036950 @ =_08036954
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036950: .4byte _08036954
_08036954: @ jump table
	.4byte _08036984 @ case 0
	.4byte _080369F6 @ case 1
	.4byte _08036A32 @ case 2
	.4byte _08036AB6 @ case 3
	.4byte _08036B86 @ case 4
	.4byte _08036B86 @ case 5
	.4byte _08036B86 @ case 6
	.4byte _08036B86 @ case 7
	.4byte _08036B86 @ case 8
	.4byte _08036B86 @ case 9
	.4byte _08036AD4 @ case 10
	.4byte _08036B86 @ case 11
_08036984:
	ldr r0, _080369B8 @ =0x00000287
	adds r4, r5, r0
	ldrb r1, [r4]
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateWeaponMinigameRod
	ldr r1, _080369BC @ =sZeroMiniMotions
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r4]
	cmp r0, #5
	bhi _080369C0
	movs r0, #0x36
	bl PlaySound
	movs r0, #0
	b _080369C8
	.align 2, 0
_080369B8: .4byte 0x00000287
_080369BC: .4byte sZeroMiniMotions
_080369C0:
	movs r0, #0x37
	bl PlaySound
	movs r0, #2
_080369C8:
	strb r0, [r5, #0xf]
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r1, _080369E8 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080369F0
	ldr r0, _080369EC @ =0xFFFFFA80
	str r0, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateEntityAnim
	movs r0, #0xa
	strb r0, [r5, #0xe]
	b _08036B86
	.align 2, 0
_080369E8: .4byte 0x00000287
_080369EC: .4byte 0xFFFFFA80
_080369F0:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080369F6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	bne _08036A16
	adds r0, r5, #0
	adds r0, #0x71
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _08036A16
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08036A16:
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08036A22
	b _08036B86
_08036A22:
	ldrb r0, [r5, #0xf]
	cmp r0, #1
	beq _08036A2A
	b _08036B7C
_08036A2A:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08036B86
_08036A32:
	ldr r3, _08036AC8 @ =gJoypad
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08036A5A
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_08036A5A:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08036A7E
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_08036A7E:
	ldr r0, _08036ACC @ =0x00000287
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r2, [r5, #0xa]
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateWeaponMinigameRod
	ldr r1, _08036AD0 @ =sZeroMiniMotions
	ldrb r0, [r4]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x36
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08036AB6:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08036B86
	b _08036B7C
	.align 2, 0
_08036AC8: .4byte gJoypad
_08036ACC: .4byte 0x00000287
_08036AD0: .4byte sZeroMiniMotions
_08036AD4:
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08036AE4
	str r1, [r5, #0x60]
_08036AE4:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08036B10
	cmp r1, #0
	bge _08036B08
	ldr r1, _08036B04 @ =0x00000403
	adds r0, r5, #0
	bl SetMotion
	b _08036B10
	.align 2, 0
_08036B04: .4byte 0x00000403
_08036B08:
	ldr r1, _08036B8C @ =0x00000404
	adds r0, r5, #0
	bl SetMotion
_08036B10:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	ble _08036B62
	ldr r3, _08036B90 @ =gJoypad
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08036B3E
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	subs r0, #0x11
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
_08036B3E:
	ldrh r1, [r3]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08036B62
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xa]
	orrs r1, r0
	strb r1, [r5, #0xa]
_08036B62:
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	bl PushoutToUp2
	adds r1, r0, #0
	cmp r1, #0
	beq _08036B86
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r5, #0x58]
_08036B7C:
	movs r1, #0
	str r1, [r5, #0x60]
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08036B86:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036B8C: .4byte 0x00000404
_08036B90: .4byte gJoypad


