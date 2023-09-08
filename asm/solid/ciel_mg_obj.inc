	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createCielMiniObj
createCielMiniObj: @ 0x080DDD04
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080DDD58 @ =gSolidHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080DDD52
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _080DDD5C @ =gSolidFnTable
	movs r1, #0x2a
	strb r1, [r3, #9]
	adds r0, #0xa8
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldrb r1, [r3, #0xb]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r3, #0xb]
	ldrb r0, [r3, #0x1c]
	strb r0, [r3, #0x1d]
	str r6, [r3, #0x28]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080DDD52:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DDD58: .4byte gSolidHeaderPtr
_080DDD5C: .4byte gSolidFnTable

	thumb_func_start CielMinigameObj_Init
CielMinigameObj_Init: @ 0x080DDD60
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _080DDD72
	adds r0, r1, #0
	bl FUN_080dddb0
	b _080DDD78
_080DDD72:
	adds r0, r1, #0
	bl FUN_080dde48
_080DDD78:
	pop {r0}
	bx r0

	thumb_func_start CielMinigameObj_Update
CielMinigameObj_Update: @ 0x080DDD7C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x10]
	cmp r0, #0
	bne _080DDD8E
	adds r0, r1, #0
	bl FUN_080ddec0
	b _080DDD94
_080DDD8E:
	adds r0, r1, #0
	bl FUN_080ddef4
_080DDD94:
	pop {r0}
	bx r0

	thumb_func_start CielMinigameObj_Die
CielMinigameObj_Die: @ 0x080DDD98
	ldr r2, _080DDDAC @ =gSolidFnTable
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
_080DDDAC: .4byte gSolidFnTable

	thumb_func_start FUN_080dddb0
FUN_080dddb0: @ 0x080DDDB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080DDE38 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DDE3C @ =0x0000E80A
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	subs r2, #1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080DDE40 @ =0x083716D0
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r1, _080DDE44 @ =0x083716F8
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl CielMinigameObj_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDE38: .4byte gSolidFnTable
_080DDE3C: .4byte 0x0000E80A
_080DDE40: .4byte 0x083716D0
_080DDE44: .4byte 0x083716F8

	thumb_func_start FUN_080dde48
FUN_080dde48: @ 0x080DDE48
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080DDEB8 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080DDEBC @ =0x0000E80C
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	movs r2, #0
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	subs r2, #1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl CielMinigameObj_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDEB8: .4byte gSolidFnTable
_080DDEBC: .4byte 0x0000E80C

	thumb_func_start FUN_080ddec0
FUN_080ddec0: @ 0x080DDEC0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x11]
	lsls r0, r0, #1
	movs r1, #0xdf
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r4, r4, r0
	ldrh r0, [r4]
	cmp r0, #0xff
	bne _080DDEE4
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	b _080DDEEA
_080DDEE4:
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080DDEEA:
	strb r0, [r5, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ddef4
FUN_080ddef4: @ 0x080DDEF4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	ldr r1, _080DDF28 @ =0x00000DCC
	adds r2, r0, r1
	adds r1, #0x22
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r0, _080DDF2C @ =0x083716D0
	lsls r1, r1, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [r4, #0x54]
	ldr r0, _080DDF30 @ =0x083716F8
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r4, #0x58]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _080DDF38
	ldrb r5, [r2, #5]
	cmp r5, #1
	bne _080DDF48
	ldr r1, _080DDF34 @ =0x0000E80B
	b _080DDF40
	.align 2, 0
_080DDF28: .4byte 0x00000DCC
_080DDF2C: .4byte 0x083716D0
_080DDF30: .4byte 0x083716F8
_080DDF34: .4byte 0x0000E80B
_080DDF38:
	ldrb r5, [r2, #5]
	cmp r5, #0
	bne _080DDF48
	ldr r1, _080DDF54 @ =0x0000E80C
_080DDF40:
	adds r0, r4, #0
	bl SetMotion
	strb r5, [r4, #0xd]
_080DDF48:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DDF54: .4byte 0x0000E80C
