	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807ffd8
FUN_0807ffd8: @ 0x0807FFD8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807FFE8
	cmp r5, #1
	beq _08080002
	b _0808004C
_0807FFE8:
	ldr r1, _08080014 @ =0x00004C02
	adds r0, r4, #0
	bl SetMotion
	str r5, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08080018 @ =0x08367F00
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080002:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808001C
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	b _08080044
	.align 2, 0
_08080014: .4byte 0x00004C02
_08080018: .4byte 0x08367F00
_0808001C:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0808002C
	str r1, [r4, #0x60]
_0808002C:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08080046
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
_08080044:
	str r0, [r4, #0x58]
_08080046:
	adds r0, r4, #0
	bl UpdateEntityAnim
_0808004C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08080054
FUN_08080054: @ 0x08080054
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r7, [r4, #0x28]
	adds r0, r7, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080074
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08080070 @ =0x08367EE8
	bl SetDDP
	b _0808007E
	.align 2, 0
_08080070: .4byte 0x08367EE8
_08080074:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080800BC @ =0x08367F18
	bl SetDDP
_0808007E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _080800AA
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r1, r2
	bl GetMetatileAttr
	movs r2, #0
	ldr r1, _080800C0 @ =0x0000FFF0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	bne _080800A8
	movs r2, #1
_080800A8:
	strb r2, [r6]
_080800AA:
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _080800F0
	cmp r5, #1
	bgt _080800C4
	cmp r5, #0
	beq _080800CC
	b _080801EE
	.align 2, 0
_080800BC: .4byte 0x08367F18
_080800C0: .4byte 0x0000FFF0
_080800C4:
	cmp r5, #2
	bne _080800CA
	b _080801CC
_080800CA:
	b _080801EE
_080800CC:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r1, #0x98
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0x12]
	strb r5, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080800F0:
	ldrb r0, [r6]
	cmp r0, #0
	beq _080800FA
	movs r0, #1
	strb r0, [r4, #0x13]
_080800FA:
	ldr r0, _0808014C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r5, r1, r0
	cmp r5, #0
	bge _08080158
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	movs r1, #0
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
	strb r0, [r2]
	ldr r0, [r4, #0x54]
	ldr r1, _08080150 @ =0xFFFFF800
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08080154 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080142
	ldrb r0, [r6]
	cmp r0, #0
	beq _080801A8
_08080142:
	ldr r0, [r4, #0x54]
	subs r0, #0x40
	str r0, [r4, #0x54]
	movs r0, #0
	b _080801AC
	.align 2, 0
_0808014C: .4byte pZero2
_08080150: .4byte 0xFFFFF800
_08080154: .4byte 0xFFFFF000
_08080158:
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
	ldr r0, [r4, #0x54]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _080801A4 @ =0xFFFFF000
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08080198
	ldrb r0, [r6]
	cmp r0, #0
	beq _080801A8
_08080198:
	ldr r0, [r4, #0x54]
	adds r0, #0x40
	str r0, [r4, #0x54]
	movs r0, #0
	b _080801AC
	.align 2, 0
_080801A4: .4byte 0xFFFFF000
_080801A8:
	ldrb r0, [r4, #0x12]
	adds r0, #1
_080801AC:
	strb r0, [r4, #0x12]
	movs r0, #0xa0
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, _080801C8 @ =0x000013FF
	cmp r1, r0
	bhi _080801C0
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080801C0:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080801EE
	.align 2, 0
_080801C8: .4byte 0x000013FF
_080801CC:
	adds r0, r4, #0
	bl UpdateEntityAnim
	ldr r0, _0808020C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	subs r5, r1, r0
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0xa0
	lsls r0, r0, #5
	cmp r1, r0
	bls _080801EE
	movs r0, #0
	strb r0, [r4, #0xe]
_080801EE:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	adds r5, r0, #0
	ldr r2, [r4, #0x58]
	subs r1, r5, r2
	ldr r0, _08080210 @ =0x00000DFF
	cmp r1, r0
	ble _08080214
	movs r1, #0
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
	b _08080276
	.align 2, 0
_0808020C: .4byte pZero2
_08080210: .4byte 0x00000DFF
_08080214:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08080274
	adds r0, r2, #0
	adds r0, #0x20
	str r0, [r4, #0x58]
	subs r0, r5, r0
	ldr r1, _0808026C @ =0xFFFFA000
	cmp r0, r1
	bge _08080276
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
	ldr r1, _08080270 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	adds r1, r7, #0
	adds r1, #0xcb
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08080276
	.align 2, 0
_0808026C: .4byte 0xFFFFA000
_08080270: .4byte gEnemyFnTable
_08080274:
	str r5, [r4, #0x58]
_08080276:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808027c
FUN_0808027c: @ 0x0808027C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0808028C
	cmp r0, #1
	beq _08080304
	b _08080318
_0808028C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r2, #0
	bl FUN_080bf48c
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	movs r2, #0
	bl FUN_080bf438
	movs r2, #0
	ldr r0, _080802CC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080802BE
	movs r2, #1
_080802BE:
	cmp r2, #0
	beq _080802D0
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _080802D6
	.align 2, 0
_080802CC: .4byte pZero2
_080802D0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_080802D6:
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
	ldr r1, _08080320 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080304:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08080318
	movs r0, #3
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08080318:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080320: .4byte 0xFFFFF000

	thumb_func_start FUN_08080324
FUN_08080324: @ 0x08080324
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08080364
	cmp r5, #1
	bgt _08080338
	cmp r5, #0
	beq _08080342
	b _080803D0
_08080338:
	cmp r5, #2
	beq _080803A4
	cmp r5, #3
	beq _080803B6
	b _080803D0
_08080342:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808039C @ =0x08367EE8
	bl SetDDP
	str r5, [r4, #0x60]
	ldr r1, _080803A0 @ =0x00004C02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080364:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08080374
	str r1, [r4, #0x60]
_08080374:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _08080394
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080394:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _080803D0
	.align 2, 0
_0808039C: .4byte 0x08367EE8
_080803A0: .4byte 0x00004C02
_080803A4:
	ldr r1, _080803D8 @ =0x00004C04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080803B6:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080803CA
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080803CA:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080803D0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080803D8: .4byte 0x00004C04

	thumb_func_start FUN_080803dc
FUN_080803dc: @ 0x080803DC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080803EC
	cmp r5, #1
	beq _08080468
	b _08080494
_080803EC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808042C @ =0x08367F48
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	ldr r0, _08080430 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	ble _08080434
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
	movs r0, #0x80
	lsls r0, r0, #4
	b _08080458
	.align 2, 0
_0808042C: .4byte 0x08367F48
_08080430: .4byte pZero2
_08080434:
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
	ldr r0, _0808049C @ =0xFFFFF800
_08080458:
	str r0, [r4, #0x64]
	ldr r1, _080804A0 @ =0x00004C03
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080468:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080478
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	str r0, [r4, #0x58]
_08080478:
	ldr r0, _080804A4 @ =pZero2
	ldr r2, [r0]
	ldr r0, [r2, #0x54]
	ldr r1, [r4, #0x64]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r2, #0x58]
	ldr r1, [r4, #0x58]
	cmp r0, r1
	ble _0808048E
	str r1, [r2, #0x58]
_0808048E:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08080494:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808049C: .4byte 0xFFFFF800
_080804A0: .4byte 0x00004C03
_080804A4: .4byte pZero2

	thumb_func_start FUN_080804a8
FUN_080804a8: @ 0x080804A8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #1
	beq _08080520
	cmp r5, #1
	bgt _080804BC
	cmp r5, #0
	beq _080804CA
	b _08080608
_080804BC:
	cmp r5, #2
	bne _080804C2
	b _080805C8
_080804C2:
	cmp r5, #3
	bne _080804C8
	b _080805DA
_080804C8:
	b _08080608
_080804CA:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080804F4 @ =0x08367EE8
	bl SetDDP
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	strb r5, [r4, #0x13]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080804F8
	movs r0, #1
	strb r0, [r4, #0x13]
	movs r0, #2
	strb r0, [r4, #0xe]
	b _08080608
	.align 2, 0
_080804F4: .4byte 0x08367EE8
_080804F8:
	ldr r0, _080805A8 @ =0xFFFFFE80
	str r0, [r4, #0x60]
	movs r0, #0xa0
	lsls r0, r0, #2
	str r0, [r4, #0x5c]
	adds r2, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08080510
	ldr r2, _080805AC @ =0xFFFFFD80
_08080510:
	str r2, [r4, #0x5c]
	ldr r1, _080805B0 @ =0x00004C01
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08080520:
	ldr r2, [r4, #0x54]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08080536
	ldr r0, _080805B4 @ =0xFFFFF800
	adds r3, r2, r0
_08080536:
	ldr r1, [r4, #0x58]
	ldr r2, _080805B8 @ =0xFFFFF000
	adds r1, r1, r2
	adds r0, r3, #0
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08080550
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
_08080550:
	ldr r0, [r4, #0x60]
	adds r0, #0x40
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08080560
	str r1, [r4, #0x60]
_08080560:
	ldr r2, _080805BC @ =gStageRun+232
	ldr r0, [r2, #0x38]
	ldr r3, _080805C0 @ =0x000077FF
	adds r1, r0, r3
	ldr r0, [r4, #0x54]
	cmp r0, r1
	ble _08080570
	str r1, [r4, #0x54]
_08080570:
	ldr r0, [r2, #0x38]
	ldr r2, _080805C4 @ =0xFFFF8800
	adds r1, r0, r2
	ldr r0, [r4, #0x54]
	cmp r0, r1
	bge _0808057E
	str r1, [r4, #0x54]
_0808057E:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0808059E
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808059E:
	adds r0, r4, #0
	bl UpdateEntityAnim
	b _08080608
	.align 2, 0
_080805A8: .4byte 0xFFFFFE80
_080805AC: .4byte 0xFFFFFD80
_080805B0: .4byte 0x00004C01
_080805B4: .4byte 0xFFFFF800
_080805B8: .4byte 0xFFFFF000
_080805BC: .4byte gStageRun+232
_080805C0: .4byte 0x000077FF
_080805C4: .4byte 0xFFFF8800
_080805C8:
	ldr r1, _080805FC @ =0x00004C04
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080805DA:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08080602
	movs r2, #1
	strb r2, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080600
	strb r1, [r4, #0x12]
	strb r2, [r4, #0xe]
	b _08080602
	.align 2, 0
_080805FC: .4byte 0x00004C04
_08080600:
	strb r0, [r4, #0xe]
_08080602:
	adds r0, r4, #0
	bl UpdateEntityAnim
_08080608:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

