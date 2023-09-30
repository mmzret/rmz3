	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cbe38
FUN_080cbe38: @ 0x080CBE38
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x2c]
	cmp r3, #0
	beq _080CBE78
	ldr r3, [r3, #0x58]
	ldr r4, [r2, #0x58]
	subs r1, r3, r4
	movs r0, #0x80
	lsls r0, r0, #5
	cmp r1, r0
	ble _080CBE68
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CBE60
	str r1, [r2, #0x60]
_080CBE60:
	ldr r0, [r2, #0x60]
	adds r0, r4, r0
	str r0, [r2, #0x58]
	b _080CBE9E
_080CBE68:
	ldr r1, _080CBE74 @ =0xFFFFF000
	adds r0, r3, r1
	str r0, [r2, #0x58]
	movs r0, #0
	str r0, [r2, #0x60]
	b _080CBE9E
	.align 2, 0
_080CBE74: .4byte 0xFFFFF000
_080CBE78:
	ldr r0, [r2, #0x60]
	adds r0, #0x40
	str r0, [r2, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _080CBE88
	str r1, [r2, #0x60]
_080CBE88:
	ldr r0, [r2, #0x58]
	ldr r1, [r2, #0x60]
	adds r0, r0, r1
	str r0, [r2, #0x58]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r1, [r1]
	cmp r0, r1
	ble _080CBE9E
	str r1, [r2, #0x58]
	str r3, [r2, #0x60]
_080CBE9E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start nop_080cbea4
nop_080cbea4: @ 0x080CBEA4
	bx lr
	.align 2, 0

	thumb_func_start initHeavyCannon
initHeavyCannon: @ 0x080CBEA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080CBFCC @ =gSolidFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	mov r8, r1
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r6, #0x14]
	ldr r1, _080CBFD0 @ =0x0836FF1C
	ldrb r0, [r6, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #0xd]
	ldrb r0, [r6, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	bl InitNonAffineMotion
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	bls _080CBEF2
	b _080CC07C
_080CBEF2:
	ldr r1, _080CBFD4 @ =0x00003801
	adds r0, r6, #0
	bl SetMotion
	adds r0, r6, #0
	bl UpdateMotionGraphic
	adds r5, r6, #0
	str r4, [r6, #0x28]
	ldrb r0, [r6, #0x10]
	cmp r0, #3
	beq _080CBFDC
	ldrb r1, [r6, #0xa]
	movs r0, #0xdf
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_08009f6c
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0xb4
	str r4, [r0]
	ldrb r0, [r6, #0x10]
	adds r0, #1
	lsls r0, r0, #0xc
	subs r4, r4, r0
	str r4, [r6, #0x58]
	movs r3, #0
	ldrb r0, [r6, #0x10]
	adds r0, #1
	adds r7, r6, #0
	adds r7, #0x74
	movs r1, #0x54
	adds r1, r1, r6
	mov sl, r1
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
	cmp r3, r0
	bge _080CC022
	mov r8, r3
_080CBF5C:
	ldr r0, _080CBFD8 @ =gSolidHeaderPtr
	ldr r0, [r0]
	str r3, [sp]
	bl AllocEntityFirst
	adds r2, r0, #0
	ldr r3, [sp]
	cmp r2, #0
	beq _080CBFC0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r4, r4, r0
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _080CBFCC @ =gSolidFnTable
	movs r0, #5
	strb r0, [r2, #9]
	ldr r0, [r1, #0x14]
	ldr r0, [r0]
	str r0, [r2, #0x14]
	mov r1, r8
	strh r1, [r2, #0x20]
	adds r0, r2, #0
	adds r0, #0x22
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r2, #0xb]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xb]
	ldrb r0, [r2, #0x1c]
	strb r0, [r2, #0x1d]
	movs r0, #4
	strb r0, [r2, #0x10]
	ldr r0, [r6, #0x54]
	str r0, [r2, #0x54]
	str r4, [r2, #0x58]
	adds r1, r2, #0
	adds r1, #0xb4
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r0, [r0]
	str r0, [r1]
	str r5, [r2, #0x28]
	str r2, [r5, #0x2c]
	mov r0, r8
	str r0, [r2, #0x2c]
	adds r5, r2, #0
_080CBFC0:
	adds r3, #1
	ldrb r0, [r6, #0x10]
	adds r0, #1
	cmp r3, r0
	blt _080CBF5C
	b _080CC022
	.align 2, 0
_080CBFCC: .4byte gSolidFnTable
_080CBFD0: .4byte 0x0836FF1C
_080CBFD4: .4byte 0x00003801
_080CBFD8: .4byte gSolidHeaderPtr
_080CBFDC:
	ldrb r0, [r6, #0xa]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x4d
	mov r1, r8
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #0x4a
	movs r2, #0x20
	ldrb r1, [r3]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldr r0, [r6, #0x54]
	ldr r1, [r6, #0x58]
	bl FUN_0800a134
	str r0, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0xb4
	str r0, [r1]
	str r4, [r6, #0x2c]
	str r4, [r6, #0x28]
	adds r7, r6, #0
	adds r7, #0x74
	movs r0, #0x54
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
_080CC022:
	ldr r0, _080CC050 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CC05C
	ldr r0, _080CC054 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080CC05C
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r1, r0
	strb r1, [r6, #0xa]
	ldr r1, _080CC058 @ =0x0836FE8C
	adds r0, r7, #0
	mov r2, sl
	movs r3, #0x14
	b _080CC06E
	.align 2, 0
_080CC050: .4byte gSystemSavedataManager
_080CC054: .4byte gCurStory
_080CC058: .4byte 0x0836FE8C
_080CC05C:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _080CC078 @ =0x0836FE8C
	adds r0, r7, #0
	mov r2, sl
	movs r3, #0x10
_080CC06E:
	bl InitBody
	str r6, [r7, #0x2c]
	str r4, [r7, #0x24]
	b _080CC0F4
	.align 2, 0
_080CC078: .4byte 0x0836FE8C
_080CC07C:
	ldr r0, _080CC0C0 @ =gSystemSavedataManager
	ldrb r1, [r0, #0x15]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CC0CC
	ldr r0, _080CC0C4 @ =gCurStory
	ldrb r1, [r0, #4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080CC0CC
	ldrb r0, [r6, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080CC0C8 @ =0x0836FE8C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0x10
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r7, r4, #0
	movs r0, #0xb8
	adds r0, r0, r6
	mov sb, r0
	b _080CC0F4
	.align 2, 0
_080CC0C0: .4byte gSystemSavedataManager
_080CC0C4: .4byte gCurStory
_080CC0C8: .4byte 0x0836FE8C
_080CC0CC:
	ldrb r1, [r6, #0xa]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strb r0, [r6, #0xa]
	adds r4, r6, #0
	adds r4, #0x74
	ldr r1, _080CC118 @ =0x0836FE8C
	adds r2, r6, #0
	adds r2, #0x54
	adds r0, r4, #0
	movs r3, #0xc
	bl InitBody
	str r6, [r4, #0x2c]
	str r5, [r4, #0x24]
	adds r7, r4, #0
	movs r1, #0xb8
	adds r1, r1, r6
	mov sb, r1
_080CC0F4:
	ldr r0, _080CC11C @ =nop_080cbea4
	str r0, [r7, #0x24]
	movs r0, #0
	mov r1, sb
	str r0, [r1]
	str r0, [r6, #0x60]
	adds r0, r6, #0
	bl heavyCannonAI
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC118: .4byte 0x0836FE8C
_080CC11C: .4byte nop_080cbea4

	thumb_func_start heavyCannonAI
heavyCannonAI: @ 0x080CC120
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	bne _080CC190
	ldr r0, _080CC144 @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _080CC148
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	b _080CC15A
	.align 2, 0
_080CC144: .4byte gCurStory
_080CC148:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _080CC190
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _080CC190
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_080CC15A:
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
	ldr r1, _080CC18C @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	b _080CC1BC
	.align 2, 0
_080CC18C: .4byte gSolidFnTable
_080CC190:
	adds r0, r4, #0
	bl FUN_080cbdc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CC1BC
	ldr r1, _080CC1C4 @ =0x0836FE74
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CC1C8 @ =0x0836FE80
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080CC1BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC1C4: .4byte 0x0836FE74
_080CC1C8: .4byte 0x0836FE80

	thumb_func_start killHeavyCannon
killHeavyCannon: @ 0x080CC1CC
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #0xb]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r0, [r4, #0xa]
	movs r1, #0xfb
	ands r1, r0
	movs r0, #0xfe
	ands r1, r0
	strb r1, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r3, [r4, #0x58]
	ldr r2, _080CC270 @ =0xFFFFF800
	adds r0, r3, r2
	str r0, [sp, #4]
	adds r2, r0, #0
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CC212
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r3, r0
_080CC212:
	str r2, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080CC274 @ =0x0836FF22
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b82c0
	ldrb r0, [r4, #0x10]
	cmp r0, #4
	beq _080CC256
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #0
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080CC278 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080CC27C @ =0x0000270E
	cmp r1, r0
	bhi _080CC24E
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080CC24E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
_080CC256:
	ldr r1, _080CC280 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC270: .4byte 0xFFFFF800
_080CC274: .4byte 0x0836FF22
_080CC278: .4byte gMission
_080CC27C: .4byte 0x0000270E
_080CC280: .4byte gSolidFnTable

	thumb_func_start FUN_080cc284
FUN_080cc284: @ 0x080CC284
	push {lr}
	ldrb r2, [r0, #0xb]
	movs r1, #0xf7
	ands r1, r2
	strb r1, [r0, #0xb]
	bl DeleteSolid
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc298
FUN_080cc298: @ 0x080CC298
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r6, [r5]
	cmp r6, #0
	bne _080CC2C8
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CC2C8
	ldr r2, _080CC2D0 @ =0x0836FF28
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _080CC2C8
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xf]
_080CC2C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC2D0: .4byte 0x0836FF28

	thumb_func_start FUN_080cc2d4
FUN_080cc2d4: @ 0x080CC2D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb8
	ldr r0, [r5]
	cmp r0, #0
	beq _080CC2EA
	bl isKilled
	cmp r0, #0
	beq _080CC316
_080CC2EA:
	movs r1, #0
	str r1, [r5]
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bhi _080CC308
	strb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC304 @ =0x0836FED4
	bl SetDDP
	b _080CC316
	.align 2, 0
_080CC304: .4byte 0x0836FED4
_080CC308:
	movs r0, #1
	strb r0, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC31C @ =0x0836FEA4
	bl SetDDP
_080CC316:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC31C: .4byte 0x0836FEA4

	thumb_func_start FUN_080cc320
FUN_080cc320: @ 0x080CC320
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #6
	bls _080CC32C
	b _080CC4C4
_080CC32C:
	lsls r0, r0, #2
	ldr r1, _080CC338 @ =_080CC33C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CC338: .4byte _080CC33C
_080CC33C: @ jump table
	.4byte _080CC358 @ case 0
	.4byte _080CC37A @ case 1
	.4byte _080CC392 @ case 2
	.4byte _080CC3EA @ case 3
	.4byte _080CC3FC @ case 4
	.4byte _080CC468 @ case 5
	.4byte _080CC4AC @ case 6
_080CC358:
	movs r0, #0x30
	strb r0, [r4, #0x12]
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r1, _080CC3AC @ =0x0836FF30
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bne _080CC36E
	adds r1, #8
_080CC36E:
	str r1, [r4, #0x30]
	ldr r0, _080CC3B0 @ =0x00000801
	strh r0, [r4, #0x26]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC37A:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC3B4 @ =0x0836FED4
	bl SetDDP
	ldr r1, _080CC3B8 @ =0x00003801
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC392:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _080CC3BC
	movs r0, #5
	strb r0, [r4, #0xe]
	b _080CC4CA
	.align 2, 0
_080CC3AC: .4byte 0x0836FF30
_080CC3B0: .4byte 0x00000801
_080CC3B4: .4byte 0x0836FED4
_080CC3B8: .4byte 0x00003801
_080CC3BC:
	movs r2, #0
	ldr r0, _080CC3DC @ =pZero2
	ldr r0, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r0, #0x54]
	cmp r1, r0
	bge _080CC3CC
	movs r2, #1
_080CC3CC:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CC3E0
	cmp r2, #0
	beq _080CC3E4
	b _080CC4C4
	.align 2, 0
_080CC3DC: .4byte pZero2
_080CC3E0:
	cmp r2, #0
	beq _080CC4C4
_080CC3E4:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	b _080CC4C2
_080CC3EA:
	ldr r1, _080CC418 @ =0x00003803
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC3FC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080CC4C4
	ldrb r0, [r4, #0x13]
	cmp r0, #1
	bne _080CC41C
	movs r0, #0
	strb r0, [r4, #0xe]
	b _080CC4CA
	.align 2, 0
_080CC418: .4byte 0x00003803
_080CC41C:
	ldrb r2, [r4, #0xa]
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _080CC42E
	movs r0, #0x10
	orrs r0, r2
	b _080CC432
_080CC42E:
	movs r0, #0xef
	ands r0, r2
_080CC432:
	strb r0, [r4, #0xa]
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
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	ldr r1, _080CC464 @ =0x00003808
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	bl UpdateMotionGraphic
	b _080CC4C4
	.align 2, 0
_080CC464: .4byte 0x00003808
_080CC468:
	ldr r1, [r4, #0x54]
	ldr r0, _080CC4D0 @ =0xFFFFE800
	adds r5, r1, r0
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080CC47E
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r5, r1, r0
_080CC47E:
	ldr r3, [r4, #0x58]
	ldr r0, _080CC4D4 @ =0xFFFFF700
	adds r1, r3, r0
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080CC492
	movs r0, #0x90
	lsls r0, r0, #4
	adds r1, r3, r0
_080CC492:
	lsrs r2, r2, #4
	movs r0, #1
	ands r2, r0
	adds r0, r5, #0
	bl CreateHeavyCannonBall
	ldr r1, _080CC4D8 @ =0x00003802
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC4AC:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080CC4C4
	movs r0, #0x70
	strb r0, [r4, #0x12]
	movs r0, #1
_080CC4C2:
	strb r0, [r4, #0xe]
_080CC4C4:
	adds r0, r4, #0
	bl FUN_080cbe38
_080CC4CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC4D0: .4byte 0xFFFFE800
_080CC4D4: .4byte 0xFFFFF700
_080CC4D8: .4byte 0x00003802

	thumb_func_start FUN_080cc4dc
FUN_080cc4dc: @ 0x080CC4DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CC4EC
	cmp r0, #1
	beq _080CC506
	b _080CC50C
_080CC4EC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC518 @ =0x0836FEA4
	bl SetDDP
	movs r1, #0xe0
	lsls r1, r1, #6
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CC506:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CC50C:
	adds r0, r4, #0
	bl FUN_080cbe38
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC518: .4byte 0x0836FEA4

	thumb_func_start FUN_080cc51c
FUN_080cc51c: @ 0x080CC51C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _080CC54C
	ldrb r0, [r4, #0x10]
	cmp r0, #3
	bhi _080CC53C
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC538 @ =0x0836FF04
	bl SetDDP
	b _080CC546
	.align 2, 0
_080CC538: .4byte 0x0836FF04
_080CC53C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CC558 @ =0x0836FEBC
	bl SetDDP
_080CC546:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_080CC54C:
	adds r0, r4, #0
	bl FUN_080cbe38
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC558: .4byte 0x0836FEBC

