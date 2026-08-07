	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CannonHopper_Update
CannonHopper_Update: @ 0x080975FC
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
	bl CannonHopper_Die
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
	bl UpdateEntityAnim
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
	bl IsFrozen
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
	bl UpdateEntityAnim
	movs r0, #2
	strb r0, [r4, #0xf]
_08097740:
	adds r0, r4, #0
	bl IsFrozen
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
_08097794: .4byte sElementCoord
_08097798: .4byte sCollisions+(10*24)
_0809779C: .4byte 0x00020001
_080977A0: .4byte sUpdates1
_080977A4: .4byte sUpdates2
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
	bl IsFrozen
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
_08097850: .4byte sCollisions
_08097854: .4byte 0xFFFFF900
_08097858: .4byte 0xFFFFFF00
_0809785C: .4byte 0x00020001
