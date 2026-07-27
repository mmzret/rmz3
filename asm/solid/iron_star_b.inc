	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cbcc4
FUN_080cbcc4: @ 0x080CBCC4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CBCD4
	cmp r0, #1
	beq _080CBCFE
	b _080CBD5C
_080CBCD4:
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CBD20 @ =0x0836FE58
	str r0, [r4, #0x30]
	ldr r0, _080CBD24 @ =0x00000801
	strh r0, [r4, #0x26]
	ldr r1, _080CBD28 @ =0x00002D01
	adds r0, r4, #0
	bl SetMotion
	ldr r0, _080CBD2C @ =gOverworld
	ldr r1, _080CBD30 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CBCFE:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	ldr r2, [r4, #0x58]
	cmp r0, #0
	beq _080CBD38
	ldr r0, _080CBD34 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x58]
	cmp r2, r0
	ble _080CBD38
	movs r0, #0x80
	lsls r0, r0, #4
	b _080CBD3A
	.align 2, 0
_080CBD20: .4byte 0x0836FE58
_080CBD24: .4byte 0x00000801
_080CBD28: .4byte 0x00002D01
_080CBD2C: .4byte gOverworld
_080CBD30: .4byte 0x0002C00C
_080CBD34: .4byte pZero2
_080CBD38:
	movs r0, #0
_080CBD3A:
	str r0, [r4, #0x68]
	ldr r0, _080CBD64 @ =gOverworld
	ldr r1, _080CBD68 @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r4, #0x68]
	adds r0, r0, r1
	subs r0, r0, r2
	cmp r0, #0
	bge _080CBD50
	adds r0, #7
_080CBD50:
	asrs r0, r0, #3
	adds r0, r2, r0
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateEntityAnim
_080CBD5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBD64: .4byte gOverworld
_080CBD68: .4byte 0x0002C00C

	thumb_func_start FUN_080cbd6c
FUN_080cbd6c: @ 0x080CBD6C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CBD7C
	cmp r0, #1
	beq _080CBD96
	b _080CBDAC
_080CBD7C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CBDB4 @ =0x0836FE40
	bl SetDDP
	movs r1, #0xb4
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CBD96:
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	beq _080CBDA6
	ldr r0, _080CBDB8 @ =gOverworld
	ldr r1, _080CBDBC @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x58]
_080CBDA6:
	adds r0, r4, #0
	bl UpdateEntityAnim
_080CBDAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBDB4: .4byte 0x0836FE40
_080CBDB8: .4byte gOverworld
_080CBDBC: .4byte 0x0002C00C
