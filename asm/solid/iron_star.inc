	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initIronStar
initIronStar: @ 0x080CBB28
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, _080CBBB0 @ =gSolidFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r2, #1
	str r2, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	ldr r0, _080CBBB4 @ =gCurStory
	ldrb r1, [r0, #9]
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x19
	ands r4, r2
	lsrs r0, r1, #0x1a
	ands r0, r2
	adds r4, r4, r0
	lsrs r0, r1, #0x1b
	ands r0, r2
	adds r4, r4, r0
	lsrs r1, r1, #0x1c
	ands r1, r2
	adds r4, r4, r1
	ldrb r1, [r5, #0x10]
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080CBB6A
	cmp r4, #2
	bgt _080CBB78
_080CBB6A:
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080CBBB8
	cmp r4, #2
	bgt _080CBBB8
_080CBB78:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _080CBC06
	.align 2, 0
_080CBBB0: .4byte gSolidFnTable
_080CBBB4: .4byte gCurStory
_080CBBB8:
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _080CBBC6
	cmp r0, #3
	beq _080CBBC6
	cmp r0, #5
	bne _080CBBCA
_080CBBC6:
	movs r0, #0
	b _080CBBCC
_080CBBCA:
	movs r0, #1
_080CBBCC:
	strb r0, [r5, #0xd]
	ldrb r1, [r5, #0xa]
	movs r0, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080CBC0C @ =0x0836FE10
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _080CBC10 @ =onCollision
	str r0, [r4, #0x24]
	adds r0, r5, #0
	bl ironStarAI
_080CBC06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CBC0C: .4byte 0x0836FE10
_080CBC10: .4byte onCollision

	thumb_func_start ironStarAI
ironStarAI: @ 0x080CBC14
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #2
	bne _080CBC72
	ldr r3, [r4, #0x28]
	ldr r0, [r3, #8]
	ldr r0, [r0, #0x54]
	ldr r2, [r4, #0x54]
	subs r0, r0, r2
	movs r1, #0xc0
	lsls r1, r1, #8
	cmp r0, r1
	ble _080CBC6C
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
	ldr r1, _080CBC68 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080CBC92
	.align 2, 0
_080CBC68: .4byte gSolidFnTable
_080CBC6C:
	ldr r0, [r3, #0x14]
	adds r0, r2, r0
	str r0, [r4, #0x54]
_080CBC72:
	ldr r1, _080CBC98 @ =0x0836FE00
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CBC9C @ =0x0836FE08
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080CBC92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBC98: .4byte 0x0836FE00
_080CBC9C: .4byte 0x0836FE08

	thumb_func_start killIronStar
killIronStar: @ 0x080CBCA0
	ldrb r2, [r0, #0xb]
	movs r1, #0xf7
	ands r1, r2
	strb r1, [r0, #0xb]
	ldr r2, _080CBCBC @ =gSolidFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080CBCBC: .4byte gSolidFnTable

	thumb_func_start nop_080cbcc0
nop_080cbcc0: @ 0x080CBCC0
	bx lr
	.align 2, 0

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
	bl UpdateMotionGraphic
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
	bl UpdateMotionGraphic
_080CBDAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBDB4: .4byte 0x0836FE40
_080CBDB8: .4byte gOverworld
_080CBDBC: .4byte 0x0002C00C

