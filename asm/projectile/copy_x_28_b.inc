	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a9ef8
FUN_080a9ef8: @ 0x080A9EF8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080A9F28 @ =gStageRun
	ldrh r1, [r0, #8]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080A9F30
	ldr r1, _080A9F2C @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile28_Die
	b _080A9FD8
	.align 2, 0
_080A9F28: .4byte gStageRun
_080A9F2C: .4byte gProjectileFnTable
_080A9F30:
	ldrb r6, [r5, #0xd]
	cmp r6, #1
	beq _080A9F84
	cmp r6, #1
	bgt _080A9F40
	cmp r6, #0
	beq _080A9F46
	b _080A9FD2
_080A9F40:
	cmp r6, #2
	beq _080A9FB0
	b _080A9FD2
_080A9F46:
	ldrb r0, [r5, #0x13]
	adds r0, #4
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080A9FD2
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080A9F80 @ =0x0836C25C
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	b _080A9FD2
	.align 2, 0
_080A9F80: .4byte sCollisions+(24*2)
_080A9F84:
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080A9FD2
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
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
	b _080A9FD2
_080A9FB0:
	ldrb r0, [r5, #0x13]
	subs r0, #4
	strb r0, [r5, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A9FD2
	ldr r1, _080A9FE0 @ =gProjectileFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r6, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
	adds r0, r5, #0
	bl Projectile28_Die
_080A9FD2:
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080A9FD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9FE0: .4byte gProjectileFnTable

	thumb_func_start FUN_080a9fe4
FUN_080a9fe4: @ 0x080A9FE4
	push {r4, r5, r6, lr}
	adds r3, r1, #0
	adds r3, #8
	ldr r2, [r0, #8]
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bhi _080AA082
	ldr r0, [r2, #0x54]
	ldr r1, [r1, #8]
	subs r0, r0, r1
	asrs r5, r0, #8
	ldr r0, [r2, #0x58]
	ldr r1, [r3, #4]
	subs r0, r0, r1
	asrs r0, r0, #8
	adds r4, r0, #2
	ldrb r1, [r2, #0xf]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bls _080AA01C
	ldr r1, _080AA014 @ =gPaletteManager
	ldr r3, _080AA018 @ =0x00007FFF
	b _080AA022
	.align 2, 0
_080AA014: .4byte gPaletteManager
_080AA018: .4byte 0x00007FFF
_080AA01C:
	ldr r1, _080AA040 @ =gPaletteManager
	movs r3, #0xf8
	lsls r3, r3, #7
_080AA022:
	adds r0, r3, #0
	strh r0, [r1]
	ldrb r0, [r2, #0x13]
	subs r1, r5, r0
	lsls r1, r1, #0x10
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bge _080AA044
	movs r6, #0
	b _080AA04A
	.align 2, 0
_080AA040: .4byte gPaletteManager
_080AA044:
	cmp r1, #0xf0
	ble _080AA04A
	movs r6, #0xf0
_080AA04A:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _080AA056
	movs r5, #0
	b _080AA05C
_080AA056:
	cmp r0, #0xf0
	ble _080AA05C
	movs r5, #0xf0
_080AA05C:
	cmp r4, #0
	bge _080AA064
	movs r4, #0
	b _080AA06A
_080AA064:
	cmp r4, #0xa0
	ble _080AA06A
	movs r4, #0xa0
_080AA06A:
	ldr r2, _080AA088 @ =gWindowRegBuffer
	movs r3, #0xff
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xff
	ands r1, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #8
	orrs r1, r0
	strh r1, [r2, #6]
	ands r4, r3
	strh r4, [r2, #0xa]
_080AA082:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA088: .4byte gWindowRegBuffer

	thumb_func_start FUN_080aa08c
FUN_080aa08c: @ 0x080AA08C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x28]
	ldr r1, _080AA10C @ =gProjectileFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, _080AA110 @ =FUN_080aa15c
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r4, #0x54]
	str r1, [r4, #0x58]
	ldr r1, _080AA114 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x31
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, _080AA118 @ =gPaletteManager
	ldr r2, _080AA11C @ =0x00007FFF
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xb4
	ldr r0, [r4, #0x54]
	str r0, [r1]
	adds r1, #4
	ldr r0, [r4, #0x58]
	str r0, [r1]
	strb r3, [r4, #0x13]
	strb r3, [r4, #0x12]
	adds r0, r4, #0
	bl Projectile28_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA10C: .4byte gProjectileFnTable
_080AA110: .4byte FUN_080aa15c
_080AA114: .4byte gWindowRegBuffer
_080AA118: .4byte gPaletteManager
_080AA11C: .4byte 0x00007FFF

