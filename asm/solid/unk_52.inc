	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid52_Init
Solid52_Init: @ 0x080DFB04
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	movs r0, #1
	mov r8, r0
	ldrb r0, [r4, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x4d
	movs r6, #0
	mov r1, r8
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080DFB94 @ =0x0837191C
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #0
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _080DFB98 @ =0x00000201
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _080DFB9C @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Solid52_Update
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DFB94: .4byte 0x0837191C
_080DFB98: .4byte 0x00000201
_080DFB9C: .4byte gSolidFnTable

	thumb_func_start Solid52_Update
Solid52_Update: @ 0x080DFBA0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _080DFBEE
	cmp r0, #1
	bgt _080DFBB4
	cmp r0, #0
	beq _080DFBBA
	b _080DFC6A
_080DFBB4:
	cmp r0, #2
	beq _080DFC54
	b _080DFC6A
_080DFBBA:
	ldr r0, _080DFBD4 @ =gOverworld
	ldr r1, _080DFBD8 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #0x10]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DFBE0
	ldr r1, _080DFBDC @ =0x0000D201
	adds r0, r4, #0
	bl SetMotion
	b _080DFBE8
	.align 2, 0
_080DFBD4: .4byte gOverworld
_080DFBD8: .4byte 0x0002D024
_080DFBDC: .4byte 0x0000D201
_080DFBE0:
	ldr r1, _080DFC2C @ =0x0000D202
	adds r0, r4, #0
	bl SetMotion
_080DFBE8:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080DFBEE:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080DFC10
	ldr r0, _080DFC30 @ =gOverworld
	ldr r1, _080DFC34 @ =0x0002D024
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r2, #1
	eors r1, r2
	strb r1, [r0]
_080DFC10:
	ldr r0, _080DFC30 @ =gOverworld
	ldr r1, _080DFC34 @ =0x0002D024
	adds r0, r0, r1
	ldrb r1, [r4, #0x10]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080DFC6A
	cmp r1, #0
	bne _080DFC3C
	ldr r1, _080DFC38 @ =0x0000D203
	adds r0, r4, #0
	bl SetMotion
	b _080DFC44
	.align 2, 0
_080DFC2C: .4byte 0x0000D202
_080DFC30: .4byte gOverworld
_080DFC34: .4byte 0x0002D024
_080DFC38: .4byte 0x0000D203
_080DFC3C:
	ldr r1, _080DFC50 @ =0x0000D204
	adds r0, r4, #0
	bl SetMotion
_080DFC44:
	movs r0, #0x1e
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	b _080DFC68
	.align 2, 0
_080DFC50: .4byte 0x0000D204
_080DFC54:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080DFC6A
_080DFC68:
	strb r0, [r4, #0xf]
_080DFC6A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Solid52_Die
Solid52_Die: @ 0x080DFC70
	bx lr
	.align 2, 0
