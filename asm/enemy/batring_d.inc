	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08068018
FUN_08068018: @ 0x08068018
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08068028
	cmp r0, #1
	beq _0806803C
	b _0806812A
_08068028:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080680C4 @ =sCollisions+(24*12)
	bl SetDDP
	movs r0, #0x1a
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806803C:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	beq _0806810C
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r1, r0
	asrs r0, r0, #8
	adds r1, r1, r0
	str r1, [r4, #0x5c]
	lsls r0, r2, #4
	subs r0, r2, r0
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x60]
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _08068096
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
	str r0, [r5]
_08068096:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0806812A
	ldr r1, [r5]
	cmp r1, #0
	beq _08068100
	adds r0, r4, #0
	adds r0, #0xc0
	ldrb r2, [r0]
	cmp r2, #1
	bne _080680C8
	subs r0, #0x1c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	ble _0806810C
	movs r0, #5
	b _080680FA
	.align 2, 0
_080680C4: .4byte sCollisions+(24*12)
_080680C8:
	cmp r2, #2
	bne _080680EC
	adds r0, r4, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bgt _080680E8
	ldr r1, _080680E4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r4, #0xc]
	b _08068118
	.align 2, 0
_080680E4: .4byte gEnemyFnTable
_080680E8:
	movs r0, #7
	b _080680FA
_080680EC:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	ble _0806810C
	movs r0, #2
_080680FA:
	strb r0, [r4, #0xd]
	strb r3, [r4, #0xe]
	b _0806812A
_08068100:
	adds r0, r4, #0
	adds r0, #0xa4
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #1
	bgt _08068124
_0806810C:
	ldr r1, _08068120 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
_08068118:
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	b _0806812A
	.align 2, 0
_08068120: .4byte gEnemyFnTable
_08068124:
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0806812A:
	pop {r4, r5}
	pop {r0}
	bx r0
