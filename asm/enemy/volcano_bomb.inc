	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVolcanoBomb
CreateVolcanoBomb: @ 0x08071240
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _0807128C @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r5, r0, #0
	cmp r5, #0
	beq _08071286
	adds r2, r5, #0
	adds r2, #0x25
	movs r4, #0
	movs r1, #0x18
	strb r1, [r2]
	ldr r3, _08071290 @ =gEnemyFnTable
	movs r2, #0x10
	movs r1, #0x10
	strb r1, [r5, #9]
	ldr r1, [r3, #0x40]
	ldr r1, [r1]
	str r1, [r5, #0x14]
	movs r3, #0
	strh r4, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x22
	strb r3, [r1]
	ldrb r1, [r5, #0xb]
	orrs r2, r1
	strb r2, [r5, #0xb]
	ldrb r1, [r5, #0x1c]
	strb r1, [r5, #0x1d]
	str r6, [r5, #0x54]
	str r7, [r5, #0x58]
	strb r3, [r5, #0x10]
_08071286:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807128C: .4byte gZakoHeaderPtr
_08071290: .4byte gEnemyFnTable

	thumb_func_start nop_08071294
nop_08071294: @ 0x08071294
	bx lr
	.align 2, 0

	thumb_func_start FUN_08071298
FUN_08071298: @ 0x08071298
	push {lr}
	adds r2, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080712AE
	movs r0, #0
	b _080712C8
_080712AE:
	ldr r1, _080712CC @ =gEnemyFnTable
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
	adds r0, r2, #0
	bl VolcanoBomb_Die
	movs r0, #1
_080712C8:
	pop {r1}
	bx r1
	.align 2, 0
_080712CC: .4byte gEnemyFnTable

	thumb_func_start VolcanoBomb_Init
VolcanoBomb_Init: @ 0x080712D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08071338 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _0807133C @ =0x08366B28
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
	ldrb r1, [r4, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _08071340 @ =0x08366AE0
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #4
	bl InitBody
	str r4, [r5, #0x2c]
	ldr r0, _08071344 @ =nop_08071294
	str r0, [r5, #0x24]
	ldr r0, _08071348 @ =gStageRun+232
	ldr r0, [r0, #0x3c]
	ldr r1, _0807134C @ =0xFFFF9000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl VolcanoBomb_Update
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071338: .4byte gEnemyFnTable
_0807133C: .4byte 0x08366B28
_08071340: .4byte 0x08366AE0
_08071344: .4byte nop_08071294
_08071348: .4byte gStageRun+232
_0807134C: .4byte 0xFFFF9000

	thumb_func_start VolcanoBomb_Update
VolcanoBomb_Update: @ 0x08071350
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08071298
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807137E
	ldr r1, _08071384 @ =0x08366AD8
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _08071388 @ =0x08366ADC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0807137E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08071384: .4byte 0x08366AD8
_08071388: .4byte 0x08366ADC

	thumb_func_start VolcanoBomb_Die
VolcanoBomb_Die: @ 0x0807138C
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
	movs r1, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	str r0, [sp, #4]
	ldr r2, _080713E0 @ =0x08366B2A
	adds r0, r4, #0
	mov r1, sp
	movs r3, #4
	bl FUN_080b7ffc
	movs r0, #0x41
	bl PlaySound
	ldr r1, _080713E4 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080713E0: .4byte 0x08366B2A
_080713E4: .4byte gEnemyFnTable

	thumb_func_start FUN_080713e8
FUN_080713e8: @ 0x080713E8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080713ec
FUN_080713ec: @ 0x080713EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _080713FC
	cmp r5, #1
	beq _08071418
	b _08071460
_080713FC:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08071468 @ =0x08366AF8
	bl SetDDP
	str r5, [r4, #0x60]
	movs r1, #0xf8
	lsls r1, r1, #5
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08071418:
	ldr r0, [r4, #0x60]
	adds r0, #0x20
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _08071428
	str r1, [r4, #0x60]
_08071428:
	ldr r1, [r4, #0x58]
	ldr r0, [r4, #0x60]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl PushoutToUp1
	adds r1, r0, #0
	cmp r1, #0
	bge _0807145A
	ldr r0, [r4, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _0807146C @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
_0807145A:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_08071460:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08071468: .4byte 0x08366AF8
_0807146C: .4byte gEnemyFnTable
