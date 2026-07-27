	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start shotcounter_080667bc
shotcounter_080667bc: @ 0x080667BC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #8
	bls _080667CA
	b _08066964
_080667CA:
	lsls r0, r0, #2
	ldr r1, _080667D4 @ =_080667D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080667D4: .4byte _080667D8
_080667D8: @ jump table
	.4byte _080667FC @ case 0
	.4byte _08066826 @ case 1
	.4byte _08066900 @ case 2
	.4byte _0806686C @ case 3
	.4byte _0806687E @ case 4
	.4byte _080668F6 @ case 5
	.4byte _08066900 @ case 6
	.4byte _08066928 @ case 7
	.4byte _0806693C @ case 8
_080667FC:
	ldr r1, _08066860 @ =0x00000401
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08066864 @ =0x00000103
	bl PlaySound
	adds r1, r5, #0
	adds r1, #0xbd
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066868 @ =0x08365E0C
	bl SetDDP
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066826:
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08066846
	adds r1, r5, #0
	adds r1, #0xbd
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066868 @ =0x08365E0C
	bl SetDDP
_08066846:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08066858
	b _08066964
_08066858:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	b _08066920
	.align 2, 0
_08066860: .4byte 0x00000401
_08066864: .4byte 0x00000103
_08066868: .4byte sCollisions+(24*7)
_0806686C:
	ldr r1, _080668B0 @ =0x00000402
	adds r0, r5, #0
	bl SetMotion
	movs r0, #2
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806687E:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _080668E4
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080668E4
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	add r1, sp, #8
	str r2, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xbc
	ldrb r2, [r0]
	adds r3, r0, #0
	cmp r2, #0
	bne _080668BC
	ldr r0, [r5, #0x54]
	ldr r2, _080668B4 @ =0xFFFFF200
	adds r0, r0, r2
	str r0, [sp]
	ldr r0, _080668B8 @ =0xFFFFFD80
	b _080668CA
	.align 2, 0
_080668B0: .4byte 0x00000402
_080668B4: .4byte 0xFFFFF200
_080668B8: .4byte 0xFFFFFD80
_080668BC:
	ldr r0, [r5, #0x54]
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #2
_080668CA:
	str r0, [sp, #8]
	ldrb r2, [r3]
	mov r0, sp
	movs r3, #0
	bl CreateShotcounterBullet
	movs r0, #3
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2c
	bl PlaySound
_080668E4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08066964
	b _08066920
_080668F6:
	movs r0, #0xc
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08066900:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	beq _08066920
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08066964
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08066964
_08066920:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08066964
_08066928:
	ldr r1, _0806696C @ =0x00000403
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _08066970 @ =0x00000103
	bl PlaySound
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0806693C:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x73
	ldrb r6, [r0]
	cmp r6, #3
	bne _08066964
	adds r1, r5, #0
	adds r1, #0xbd
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08066974 @ =sCollisions
	bl SetDDP
	strb r6, [r5, #0xd]
	strb r4, [r5, #0xe]
_08066964:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806696C: .4byte 0x00000403
_08066970: .4byte 0x00000103
_08066974: .4byte sCollisions
