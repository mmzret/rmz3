	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dac28
FUN_080dac28: @ 0x080DAC28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x10]
	cmp r0, #0x16
	bne _080DAC42
	ldr r0, _080DAC90 @ =gSystemSavedata
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080DAC58
_080DAC42:
	ldrb r0, [r6, #0x10]
	cmp r0, #0x19
	bne _080DAC98
	ldr r0, _080DAC90 @ =gSystemSavedata
	ldrb r1, [r0, #0xb]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080DAC98
_080DAC58:
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080DAC94 @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
	b _080DAD00
	.align 2, 0
_080DAC90: .4byte gSystemSavedata
_080DAC94: .4byte gSolidFnTable
_080DAC98:
	ldr r2, _080DAD08 @ =sMotions
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0xbe
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #2
	adds r1, #2
	strh r0, [r1]
	ldrb r0, [r6, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	ldrb r1, [r6, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080DAD0C @ =sCollisions
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r0, r6, #0
	adds r0, #0xb9
	movs r2, #1
	strb r2, [r0]
	adds r1, r6, #0
	adds r1, #0xb8
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xc0
	strh r0, [r1]
	strb r2, [r6, #0xd]
	adds r0, r6, #0
	bl MobNPC_Update
_080DAD00:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAD08: .4byte sMotions
_080DAD0C: .4byte sCollisions

	thumb_func_start colbor_080dad10
colbor_080dad10: @ 0x080DAD10
	push {lr}
	ldrb r0, [r0, #0x10]
	cmp r0, #0x17
	beq _080DAD50
	cmp r0, #0x17
	bgt _080DAD22
	cmp r0, #0x16
	beq _080DAD2C
	b _080DADF0
_080DAD22:
	cmp r0, #0x18
	beq _080DAD7C
	cmp r0, #0x19
	beq _080DADCE
	b _080DADF0
_080DAD2C:
	ldr r0, _080DAD44 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DAD48
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #2
	b _080DADF2
	.align 2, 0
_080DAD44: .4byte gCurStory
_080DAD48:
	ldr r0, _080DAD4C @ =0x000002B5
	b _080DADF2
	.align 2, 0
_080DAD4C: .4byte 0x000002B5
_080DAD50:
	ldr r2, _080DAD60 @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DAD68
	ldr r0, _080DAD64 @ =0x000002AF
	b _080DADF2
	.align 2, 0
_080DAD60: .4byte gCurStory
_080DAD64: .4byte 0x000002AF
_080DAD68:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DADF0
	ldr r0, _080DAD78 @ =0x000002AE
	b _080DADF2
	.align 2, 0
_080DAD78: .4byte 0x000002AE
_080DAD7C:
	ldr r2, _080DAD8C @ =gCurStory
	ldrb r1, [r2, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DAD94
	ldr r0, _080DAD90 @ =0x000002B3
	b _080DADF2
	.align 2, 0
_080DAD8C: .4byte gCurStory
_080DAD90: .4byte 0x000002B3
_080DAD94:
	ldrb r1, [r2, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080DADC8
	ldr r0, _080DADB8 @ =gStageDiskManager
	ldr r0, [r0]
	ldrb r1, [r0, #5]
	movs r0, #0xf
	ands r0, r1
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DADC0
	ldr r0, _080DADBC @ =0x000002B2
	b _080DADF2
	.align 2, 0
_080DADB8: .4byte gStageDiskManager
_080DADBC: .4byte 0x000002B2
_080DADC0:
	ldr r0, _080DADC4 @ =0x000002B1
	b _080DADF2
	.align 2, 0
_080DADC4: .4byte 0x000002B1
_080DADC8:
	movs r0, #0xac
	lsls r0, r0, #2
	b _080DADF2
_080DADCE:
	ldr r0, _080DADE4 @ =gCurStory
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _080DADE8
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #2
	b _080DADF2
	.align 2, 0
_080DADE4: .4byte gCurStory
_080DADE8:
	ldr r0, _080DADEC @ =0x000002B9
	b _080DADF2
	.align 2, 0
_080DADEC: .4byte 0x000002B9
_080DADF0:
	ldr r0, _080DADF8 @ =0x000002AD
_080DADF2:
	pop {r1}
	bx r1
	.align 2, 0
_080DADF8: .4byte 0x000002AD

	thumb_func_start FUN_080dadfc
FUN_080dadfc: @ 0x080DADFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r2, _080DAE70 @ =sMotions
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0xbe
	movs r6, #0
	movs r5, #0
	strh r0, [r1]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrb r0, [r7, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0xc2
	strh r0, [r1]
	ldrb r1, [r7, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r7, #0xa]
	adds r4, r7, #0
	adds r4, #0x74
	ldr r1, _080DAE74 @ =sCollisions+48
	adds r2, r7, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #1
	bl InitBody
	str r7, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r1, r7, #0
	adds r1, #0xb9
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb8
	strb r6, [r0]
	adds r0, #4
	strh r5, [r0]
	strb r6, [r7, #0xd]
	adds r0, r7, #0
	bl MobNPC_Update
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DAE70: .4byte sMotions
_080DAE74: .4byte sCollisions+48

