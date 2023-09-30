	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPantheonZombie
createPantheonZombie: @ 0x0807FD20
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _0807FD7C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r4, r0, #0
	cmp r4, #0
	beq _0807FD76
	adds r1, r5, #0
	adds r1, #0xcb
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0807FD80 @ =gEnemyFnTable
	movs r1, #0x25
	strb r1, [r4, #9]
	adds r0, #0x94
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
	str r6, [r4, #0x54]
	str r7, [r4, #0x58]
_0807FD76:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD7C: .4byte gZakoHeaderPtr
_0807FD80: .4byte gEnemyFnTable

	thumb_func_start FUN_0807fd84
FUN_0807fd84: @ 0x0807FD84
	push {lr}
	ldr r2, [r0, #0x2c]
	ldr r0, [r0, #0x14]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0807FDA2
	ldrb r0, [r2, #0xd]
	cmp r0, #4
	beq _0807FDA2
	movs r1, #0
	movs r0, #4
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807FDA2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807fda8
FUN_0807fda8: @ 0x0807FDA8
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x8c
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807FDF0
	ldr r1, _0807FDE0 @ =gEnemyFnTable
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
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0807FDE4
	strb r4, [r2, #0xd]
	b _0807FDE6
	.align 2, 0
_0807FDE0: .4byte gEnemyFnTable
_0807FDE4:
	strb r1, [r2, #0xd]
_0807FDE6:
	adds r0, r2, #0
	bl PantheonZombie_Die
	movs r0, #1
	b _0807FDF2
_0807FDF0:
	movs r0, #0
_0807FDF2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0807fdf8
FUN_0807fdf8: @ 0x0807FDF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xb4
	ldr r5, [r6]
	cmp r5, #0
	bne _0807FE26
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807FE26
	ldr r2, _0807FE2C @ =0x08367F90
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807FE26
	strb r5, [r4, #0xd]
	strb r5, [r4, #0xe]
_0807FE26:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FE2C: .4byte 0x08367F90

	thumb_func_start PantheonZombie_Init
PantheonZombie_Init: @ 0x0807FE30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0807FE9C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807FEA0 @ =0x08367F98
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
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
	ldr r1, _0807FEA4 @ =0x08367ED0
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0x14
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _0807FEA8 @ =FUN_0807fd84
	str r0, [r5, #0x24]
	adds r0, r4, #0
	adds r0, #0xb4
	str r6, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r0, r4, #0
	bl PantheonZombie_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FE9C: .4byte gEnemyFnTable
_0807FEA0: .4byte 0x08367F98
_0807FEA4: .4byte 0x08367ED0
_0807FEA8: .4byte FUN_0807fd84

	thumb_func_start PantheonZombie_Update
PantheonZombie_Update: @ 0x0807FEAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	adds r0, #0xc0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0807FEE4
	ldr r1, _0807FEE0 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	bl PantheonZombie_Die
	b _0807FF16
	.align 2, 0
_0807FEE0: .4byte gEnemyFnTable
_0807FEE4:
	adds r0, r4, #0
	bl FUN_0807fda8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807FF16
	adds r0, r4, #0
	bl FUN_0807fdf8
	ldr r1, _0807FF1C @ =0x08367E84
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _0807FF20 @ =0x08367EA4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807FF16:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807FF1C: .4byte 0x08367E84
_0807FF20: .4byte 0x08367EA4

	thumb_func_start PantheonZombie_Die
PantheonZombie_Die: @ 0x0807FF24
	push {lr}
	ldr r2, _0807FF38 @ =0x08367EC4
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0807FF38: .4byte 0x08367EC4

	thumb_func_start nop_0807ff3c
nop_0807ff3c: @ 0x0807FF3C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0807ff40
FUN_0807ff40: @ 0x0807FF40
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807FF66
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0807FF5E
	movs r0, #7
	b _0807FF60
_0807FF5E:
	movs r0, #6
_0807FF60:
	strb r0, [r2, #0xd]
	movs r0, #0
	strb r0, [r2, #0xe]
_0807FF66:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807ff6c
FUN_0807ff6c: @ 0x0807FF6C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807FF8E
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r1, r0
	cmp r1, #0
	beq _0807FF8E
	movs r1, #0
	movs r0, #7
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807FF8E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807ff94
FUN_0807ff94: @ 0x0807FF94
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	bne _0807FFAC
	movs r0, #5
	strb r0, [r2, #0xd]
	strb r1, [r2, #0xe]
_0807FFAC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0807ffb0
FUN_0807ffb0: @ 0x0807FFB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r0, [r5]
	cmp r0, #0
	beq _0807FFC6
	bl isKilled
	cmp r0, #0
	beq _0807FFD0
_0807FFC6:
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_0807FFD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
	b _080801EE
	.align 2, 0
_080801C8: .4byte 0x000013FF
_080801CC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
_08080608:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08080610
FUN_08080610: @ 0x08080610
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08080620
	cmp r0, #1
	beq _0808063C
	b _08080666
_08080620:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0808066C @ =0x08367EE8
	bl SetDDP
	movs r0, #0x10
	strb r0, [r4, #0x12]
	ldr r1, _08080670 @ =0x00004C02
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0808063C:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08080650
	movs r0, #1
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_08080650:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080660
	ldr r0, [r4, #0x58]
	adds r0, #0x20
	str r0, [r4, #0x58]
_08080660:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08080666:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808066C: .4byte 0x08367EE8
_08080670: .4byte 0x00004C02

	thumb_func_start FUN_08080674
FUN_08080674: @ 0x08080674
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
	ldr r1, _080806D8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x56
	bl PlaySound
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_080bf52c
	ldr r1, _080806DC @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x28]
	adds r1, #0xcb
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080806D8: .4byte 0xFFFFF000
_080806DC: .4byte gEnemyFnTable

	thumb_func_start FUN_080806e0
FUN_080806e0: @ 0x080806E0
	push {r4, lr}
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
	ldr r1, [r4, #0x58]
	ldr r2, _0808072C @ =0xFFFFF000
	adds r1, r1, r2
	movs r2, #1
	bl FUN_080bf48c
	ldr r1, [r4, #0x28]
	adds r1, #0xcb
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _08080730 @ =gEnemyFnTable
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
_0808072C: .4byte 0xFFFFF000
_08080730: .4byte gEnemyFnTable

	thumb_func_start FUN_08080734
FUN_08080734: @ 0x08080734
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08080744
	cmp r0, #1
	beq _080807B6
	b _080807EE
_08080744:
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _080807F4 @ =0x08367F78
	bl SetDDP
	ldr r1, _080807F8 @ =0x00004C02
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _080807FC @ =pZero2
	ldr r2, [r0]
	ldr r1, [r5, #0x54]
	ldr r0, [r2, #0x54]
	subs r1, r1, r0
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	ldr r3, _08080800 @ =0xFFFFE800
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
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080807B6:
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
	ble _080807D4
	str r1, [r5, #0x60]
_080807D4:
	ldr r1, [r5, #0x58]
	ldr r0, [r5, #0x60]
	adds r1, r1, r0
	str r1, [r5, #0x58]
	ldr r0, [r5, #0x54]
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080807EE
	adds r0, r5, #0
	bl FUN_08080674
_080807EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080807F4: .4byte 0x08367F78
_080807F8: .4byte 0x00004C02
_080807FC: .4byte pZero2
_08080800: .4byte 0xFFFFE800
