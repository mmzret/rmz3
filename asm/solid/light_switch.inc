	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid32_Update
Solid32_Update: @ 0x080DBEC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrb r6, [r5, #0xf]
	cmp r6, #1
	beq _080DBF2C
	cmp r6, #1
	bgt _080DBED4
	cmp r6, #0
	beq _080DBEDE
	b _080DBFDE
_080DBED4:
	cmp r6, #2
	beq _080DBF74
	cmp r6, #3
	beq _080DBFBA
	b _080DBFDE
_080DBEDE:
	movs r1, #0xdf
	lsls r1, r1, #8
	adds r0, r5, #0
	bl SetMotion
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _080DBF68 @ =sCollision
	adds r2, r5, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0
	bl InitBody
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	movs r0, #0xbd
	bl ClearBlink
	adds r0, r5, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xbe
	bl LoadBlink
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080DBF2C:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _080DBFDE
	movs r0, #0x3c
	bl PlaySound
	ldr r2, _080DBF6C @ =Coord_083714bc
	movs r0, #0
	adds r1, r5, #0
	bl ApplyElementEffect
	ldr r2, _080DBF70 @ =gCurStory
	adds r2, #0x54
	adds r0, r4, #0
	ldrb r1, [r5, #0x10]
	lsls r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
	b _080DBFDE
	.align 2, 0
_080DBF68: .4byte sCollision
_080DBF6C: .4byte Coord_083714bc
_080DBF70: .4byte gCurStory
_080DBF74:
	ldr r1, _080DBFF0 @ =0x0000DF01
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	movs r0, #0xbe
	bl ClearBlink
	adds r0, r5, #0
	bl GetEntityPalID
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0xbd
	bl LoadBlink
	ldrb r0, [r5, #0xf]
	adds r0, #1
	strb r0, [r5, #0xf]
_080DBFBA:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldr r0, _080DBFF4 @ =gCurStory
	adds r4, r0, #0
	adds r4, #0x54
	ldrb r2, [r4]
	ldrb r3, [r5, #0x10]
	adds r1, r2, #0
	asrs r1, r3
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _080DBFDE
	lsls r0, r3
	eors r2, r0
	strb r2, [r4]
	strb r1, [r5, #0xf]
_080DBFDE:
	movs r0, #0xbd
	bl UpdateBlinkMotionState
	movs r0, #0xbe
	bl UpdateBlinkMotionState
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DBFF0: .4byte 0x0000DF01
_080DBFF4: .4byte gCurStory

	thumb_func_start Solid32_Die
Solid32_Die:
	bx lr
	.align 2, 0

	thumb_func_start Solid32_Disappear
Solid32_Disappear: @ 0x080DBFFC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xbd
	bl ClearBlink
	movs r0, #0xbe
	bl ClearBlink
	adds r0, r4, #0
	bl DeleteSolid
	pop {r4}
	pop {r0}
	bx r0
