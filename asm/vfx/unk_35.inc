	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateGhost35
CreateGhost35: @ 0x080BBEC4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080BBF0C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _080BBF06
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BBF10 @ =gVFXFnTable
	movs r1, #0x23
	strb r1, [r3, #9]
	adds r0, #0x8c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	strb r0, [r3, #0x10]
	strb r4, [r3, #0x12]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
_080BBF06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BBF0C: .4byte gVFXHeaderPtr
_080BBF10: .4byte gVFXFnTable

	thumb_func_start Ghost35_Init
Ghost35_Init: @ 0x080BBF14
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BBF54 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080BBF58 @ =0x0836EDA0
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	adds r0, r4, #0
	bl Ghost35_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BBF54: .4byte gVFXFnTable
_080BBF58: .4byte 0x0836EDA0

	thumb_func_start Ghost35_Update
Ghost35_Update: @ 0x080BBF5C
	push {lr}
	ldr r2, _080BBF70 @ =0x0836ED9C
	ldrb r1, [r0, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BBF70: .4byte 0x0836ED9C

	thumb_func_start Ghost35_Die
Ghost35_Die: @ 0x080BBF74
	ldr r2, _080BBF88 @ =gVFXFnTable
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
_080BBF88: .4byte gVFXFnTable

	thumb_func_start FUN_080bbf8c
FUN_080bbf8c: @ 0x080BBF8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _080BBF9C
	cmp r0, #1
	beq _080BBFE4
	b _080BC03A
_080BBF9C:
	ldrb r0, [r6, #0x12]
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r5, _080BC040 @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _080BC044 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _080BC048 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsls r0, r0, #5
	lsrs r0, r0, #0x16
	ldr r2, _080BC04C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r6, #0x5c]
	ldr r2, _080BC050 @ =0xFFFFFF00
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsls r0, r0, #6
	lsrs r0, r0, #0x17
	subs r2, r2, r0
	str r2, [r6, #0x60]
	movs r1, #0xb0
	lsls r1, r1, #6
	adds r0, r6, #0
	bl SetMotion
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_080BBFE4:
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x5c]
	adds r0, r0, r1
	str r0, [r6, #0x54]
	ldr r0, [r6, #0x60]
	adds r0, #0x40
	str r0, [r6, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080BBFFC
	str r1, [r6, #0x60]
_080BBFFC:
	ldr r0, [r6, #0x58]
	ldr r1, [r6, #0x60]
	adds r0, r0, r1
	str r0, [r6, #0x58]
	adds r0, r6, #0
	bl UpdateMotionGraphic
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl PushoutToUp1
	cmp r0, #0
	bge _080BC03A
	ldr r0, [r6, #0x60]
	cmp r0, #0
	ble _080BC03A
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080BC054 @ =gVFXFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080BC03A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BC040: .4byte RNG_0202f388
_080BC044: .4byte 0x000343FD
_080BC048: .4byte 0x00269EC3
_080BC04C: .4byte 0xFFFFFE00
_080BC050: .4byte 0xFFFFFF00
_080BC054: .4byte gVFXFnTable
