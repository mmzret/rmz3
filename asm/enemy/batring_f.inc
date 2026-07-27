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

	thumb_func_start batring_08068130
batring_08068130: @ 0x08068130
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _080681BA
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _080681BA
	ldr r2, _0806817C @ =sElementCoord
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	adds r1, r0, #0
	str r1, [r6]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _08068194
	cmp r1, #0
	beq _080681BA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08068180
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	movs r0, #5
	b _0806818E
	.align 2, 0
_0806817C: .4byte sElementCoord
_08068180:
	cmp r1, #0x30
	bne _080681BA
	adds r0, r4, #0
	adds r0, #0xc0
	movs r1, #2
	strb r1, [r0]
	movs r0, #7
_0806818E:
	strb r0, [r4, #0xd]
	strb r5, [r4, #0xe]
	b _080681BA
_08068194:
	cmp r1, #0
	beq _080681BA
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _080681AE
	adds r0, r4, #0
	adds r0, #0xc0
	strb r7, [r0]
	b _080681BA
_080681AE:
	cmp r1, #0x30
	bne _080681BA
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #2
	strb r0, [r1]
_080681BA:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start batring_080681c4
batring_080681c4: @ 0x080681C4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r0, [r2, #0xc]
	ldr r3, [r0, #4]
	ldrb r0, [r3, #4]
	cmp r0, #3
	beq _080681DC
	cmp r0, #0xe
	beq _080681DC
	cmp r0, #0xf
	bne _08068206
_080681DC:
	ldr r4, [r2, #0x2c]
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08068206
	ldr r1, [r4, #0x54]
	ldr r0, [r5]
	cmp r1, r0
	bge _080681FE
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xff
	b _08068204
_080681FE:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0xfe
_08068204:
	strb r0, [r1]
_08068206:
	ldr r0, [r3, #4]
	ldr r1, _08068284 @ =0x000200FF
	ands r0, r1
	subs r1, #0xfd
	cmp r0, r1
	bne _080682C8
	ldr r4, [r2, #0x2c]
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	beq _080682C8
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08068230
	adds r0, r4, #0
	bl IsFrozen
_08068230:
	ldr r6, _08068288 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r4, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r4, #0x64]
	ldr r1, [r4, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r4, #0x68]
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
	lsrs r5, r0, #0xe
	cmp r5, #0
	beq _0806828C
	ldr r0, [r4, #0x64]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	lsls r0, r0, #8
	adds r1, r5, #0
	bl __divsi3
	str r0, [r4, #0x68]
	b _080682A8
	.align 2, 0
_08068284: .4byte 0x000200FF
_08068288: .4byte pZero2
_0806828C:
	ldr r0, [r6]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _080682A0
	ldr r0, _0806829C @ =0xFFFFFF00
	b _080682A4
	.align 2, 0
_0806829C: .4byte 0xFFFFFF00
_080682A0:
	movs r0, #0x80
	lsls r0, r0, #1
_080682A4:
	str r0, [r4, #0x64]
	str r5, [r4, #0x68]
_080682A8:
	ldr r1, [r4, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x5c]
	ldr r1, [r4, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r4, #0x60]
	movs r1, #0
	movs r0, #8
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080682C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
