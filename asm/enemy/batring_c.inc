	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08067c4c
FUN_08067c4c: @ 0x08067C4C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #6
	bls _08067C58
	b _08067F10
_08067C58:
	lsls r0, r0, #2
	ldr r1, _08067C64 @ =_08067C68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08067C64: .4byte _08067C68
_08067C68: @ jump table
	.4byte _08067C84 @ case 0
	.4byte _08067E82 @ case 1
	.4byte _08067CB0 @ case 2
	.4byte _08067CF4 @ case 3
	.4byte _08067E00 @ case 4
	.4byte _08067E20 @ case 5
	.4byte _08067EA0 @ case 6
_08067C84:
	movs r4, #0
	str r4, [r5, #0x5c]
	str r4, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0xb9
	strb r4, [r0]
	subs r0, #0x45
	ldr r1, _08067CAC @ =sCollisions+(24*8)
	bl SetDDP
	movs r0, #4
	strb r0, [r5, #0x12]
	adds r0, r5, #0
	adds r0, #0xbb
	strb r4, [r0]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067E82
	.align 2, 0
_08067CAC: .4byte sCollisions+(24*8)
_08067CB0:
	movs r0, #0
	str r0, [r5, #0x60]
	ldr r0, _08067CD0 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	bge _08067CDC
	ldr r0, _08067CD4 @ =0xFFFFFE00
	str r0, [r5, #0x5c]
	ldr r1, _08067CD8 @ =0x00000603
	adds r0, r5, #0
	bl SetMotion
	b _08067CEA
	.align 2, 0
_08067CD0: .4byte pZero2
_08067CD4: .4byte 0xFFFFFE00
_08067CD8: .4byte 0x00000603
_08067CDC:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [r5, #0x5c]
	ldr r1, _08067D08 @ =0x00000605
	adds r0, r5, #0
	bl SetMotion
_08067CEA:
	movs r0, #0xff
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067CF4:
	movs r4, #0
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x5c]
	cmp r2, #0
	bge _08067D10
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	ldr r2, _08067D0C @ =0xFFFFF200
	b _08067D18
	.align 2, 0
_08067D08: .4byte 0x00000605
_08067D0C: .4byte 0xFFFFF200
_08067D10:
	ldr r0, [r5, #0x54]
	adds r0, r0, r2
	movs r2, #0xe0
	lsls r2, r2, #4
_08067D18:
	adds r0, r0, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	bne _08067D30
	movs r4, #1
	b _08067DA6
_08067D30:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	ldr r2, _08067D78 @ =0xFFFFF800
	adds r1, r1, r2
	bl FUN_08009f6c
	ldr r1, _08067D7C @ =0xFFFFF200
	adds r2, r0, r1
	ldr r0, [r5, #0x58]
	subs r0, r2, r0
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08067D8A
	ldr r0, [r5, #0x60]
	adds r0, #0x40
	str r0, [r5, #0x60]
	cmp r0, r1
	ble _08067D5E
	str r1, [r5, #0x60]
_08067D5E:
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	cmp r0, r2
	bls _08067D6C
	str r2, [r5, #0x58]
_08067D6C:
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _08067D84
	ldr r0, _08067D80 @ =0xFFFFFF00
	b _08067DA4
	.align 2, 0
_08067D78: .4byte 0xFFFFF800
_08067D7C: .4byte 0xFFFFF200
_08067D80: .4byte 0xFFFFFF00
_08067D84:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08067DA4
_08067D8A:
	movs r0, #0
	str r0, [r5, #0x60]
	str r2, [r5, #0x58]
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	bge _08067DA0
	ldr r0, _08067D9C @ =0xFFFFFE00
	b _08067DA4
	.align 2, 0
_08067D9C: .4byte 0xFFFFFE00
_08067DA0:
	movs r0, #0x80
	lsls r0, r0, #2
_08067DA4:
	str r0, [r5, #0x5c]
_08067DA6:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08067DB2
	subs r0, #1
	strb r0, [r5, #0x12]
	b _08067DB4
_08067DB2:
	movs r4, #1
_08067DB4:
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067DD8
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067DE8
_08067DD8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067DE4 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067DF2
	.align 2, 0
_08067DE4: .4byte sCollisions+(24*10)
_08067DE8:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067DFC @ =sCollisions+(24*8)
	bl SetDDP
_08067DF2:
	cmp r4, #1
	beq _08067DF8
	b _08067F10
_08067DF8:
	b _08067E92
	.align 2, 0
_08067DFC: .4byte sCollisions+(24*8)
_08067E00:
	movs r1, #0
	str r1, [r5, #0x5c]
	ldr r0, _08067E68 @ =0xFFFFFF00
	str r0, [r5, #0x60]
	adds r0, r5, #0
	adds r0, #0xb9
	strb r1, [r0]
	subs r0, #0x45
	ldr r1, _08067E6C @ =sCollisions+(24*8)
	bl SetDDP
	movs r0, #8
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08067E20:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	ldr r2, _08067E70 @ =0xFFFFF200
	adds r1, r1, r2
	bl PushoutToDown1
	ldr r1, [r5, #0x58]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	adds r0, r5, #0
	adds r0, #0x71
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r0, r1, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08067E5C
	adds r0, r1, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08067E78
_08067E5C:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067E74 @ =sCollisions+(24*10)
	bl SetDDP
	b _08067E82
	.align 2, 0
_08067E68: .4byte 0xFFFFFF00
_08067E6C: .4byte sCollisions+(24*8)
_08067E70: .4byte 0xFFFFF200
_08067E74: .4byte sCollisions+(24*10)
_08067E78:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _08067E9C @ =sCollisions+(24*8)
	bl SetDDP
_08067E82:
	ldrb r0, [r5, #0x12]
	cmp r0, #0
	beq _08067F10
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08067F10
_08067E92:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _08067F10
	.align 2, 0
_08067E9C: .4byte sCollisions+(24*8)
_08067EA0:
	ldr r1, _08067EBC @ =pZero2
	ldr r0, [r1]
	ldr r3, [r5, #0x54]
	ldr r0, [r0, #0x54]
	subs r2, r3, r0
	adds r4, r1, #0
	cmp r2, #0
	ble _08067EC0
	movs r0, #0xf0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08067EEA
	b _08067ECA
	.align 2, 0
_08067EBC: .4byte pZero2
_08067EC0:
	subs r1, r0, r3
	movs r0, #0xf0
	lsls r0, r0, #8
	cmp r1, r0
	bgt _08067EEA
_08067ECA:
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	ldr r0, [r0, #0x58]
	subs r2, r1, r0
	cmp r2, #0
	ble _08067EE0
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r2, r0
	bgt _08067EEA
	b _08067F08
_08067EE0:
	subs r1, r0, r1
	movs r0, #0xa0
	lsls r0, r0, #8
	cmp r1, r0
	ble _08067F08
_08067EEA:
	movs r0, #1
	strb r0, [r5, #0x11]
	ldr r1, _08067F04 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	b _08067F10
	.align 2, 0
_08067F04: .4byte gEnemyFnTable
_08067F08:
	movs r1, #0
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_08067F10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
