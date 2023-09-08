	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start grandcannonMoveTurret
grandcannonMoveTurret: @ 0x08069408
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x28]
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _0806941A
	cmp r0, #1
	beq _08069450
	b _08069544
_0806941A:
	adds r0, r5, #0
	bl InitRotatableMotion
	ldr r1, _080694B8 @ =0x00000703
	adds r0, r5, #0
	bl SetMotion
	movs r0, #0x78
	strb r0, [r5, #0x12]
	ldr r1, [r4, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r4, #0x58]
	ldr r2, _080694BC @ =0xFFFFFA00
	adds r0, r0, r2
	str r0, [r5, #0x58]
	ldr r0, _080694C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08069450:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _08069544
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	bne _08069544
	ldr r1, [r4, #0x54]
	str r1, [r5, #0x54]
	ldr r0, [r4, #0x58]
	ldr r3, _080694BC @ =0xFFFFFA00
	adds r0, r0, r3
	str r0, [r5, #0x58]
	ldr r0, _080694C0 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	subs r2, r0, r1
	ldr r1, [r5, #0x64]
	subs r2, r2, r1
	adds r0, r2, #0
	cmp r2, #0
	bge _0806948A
	adds r0, #0xf
_0806948A:
	asrs r2, r0, #4
	adds r2, r1, r2
	str r2, [r5, #0x64]
	ldr r3, _080694C4 @ =gSineTable
	adds r4, r5, #0
	adds r4, #0xb8
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r1, #4
	strb r1, [r4]
	cmp r2, #0
	ble _080694F4
	ldr r0, _080694C8 @ =0x00000FFF
	cmp r2, r0
	bgt _080694CC
	movs r2, #0x80
	lsls r2, r2, #5
	b _080694D6
	.align 2, 0
_080694B8: .4byte 0x00000703
_080694BC: .4byte 0xFFFFFA00
_080694C0: .4byte pZero2
_080694C4: .4byte gSineTable
_080694C8: .4byte 0x00000FFF
_080694CC:
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r2, r0
	ble _080694D6
	adds r2, r0, #0
_080694D6:
	ldr r0, _080694F0 @ =0xFFFFF000
	adds r2, r2, r0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	movs r1, #0xd0
	lsls r1, r1, #7
	bl __divsi3
	movs r1, #0x40
	subs r2, r1, r0
	b _08069518
	.align 2, 0
_080694F0: .4byte 0xFFFFF000
_080694F4:
	ldr r0, _0806954C @ =0xFFFFF000
	cmp r2, r0
	bgt _08069500
	ldr r0, _08069550 @ =0xFFFF8800
	cmp r2, r0
	bge _08069502
_08069500:
	adds r2, r0, #0
_08069502:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r2, r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08069554 @ =0xFFFF9800
	bl __divsi3
	adds r2, r0, #0
	adds r2, #0x40
_08069518:
	rsbs r0, r2, #0
	subs r0, #0x80
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _08069544
	ldr r0, _08069558 @ =gStageRun+232
	adds r1, #0x30
	bl CalcFromCamera
	ldr r1, _0806955C @ =0x00000FFF
	cmp r0, r1
	bhi _08069544
	movs r0, #2
	strb r0, [r5, #0xd]
	strb r4, [r5, #0xe]
_08069544:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806954C: .4byte 0xFFFFF000
_08069550: .4byte 0xFFFF8800
_08069554: .4byte 0xFFFF9800
_08069558: .4byte gStageRun+232
_0806955C: .4byte 0x00000FFF

	thumb_func_start grandcannonBombShot
grandcannonBombShot: @ 0x08069560
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08069572
	cmp r0, #1
	beq _080695DC
	b _080695F6
_08069572:
	movs r0, #0x2d
	bl PlaySound
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x18
	ldr r2, [r5, #0x54]
	str r2, [sp]
	ldr r3, _08069600 @ =gSineTable
	lsrs r4, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x17
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp]
	ldr r2, [r5, #0x58]
	str r2, [sp, #4]
	lsls r0, r4, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r0, [sp, #4]
	movs r0, #0x2d
	bl PlaySound
	movs r1, #0xa0
	lsls r1, r1, #3
	mov r0, sp
	adds r2, r4, #0
	bl CreateGrandCannonBomb
	movs r0, #4
	strb r0, [r5, #0x12]
	ldr r1, _08069604 @ =0x00000704
	adds r0, r5, #0
	bl SetMotion
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_080695DC:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080695F6
	movs r0, #1
	strb r0, [r5, #0xd]
	strb r1, [r5, #0xe]
_080695F6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08069600: .4byte gSineTable
_08069604: .4byte 0x00000704

	thumb_func_start grandcannon_08069608
grandcannon_08069608: @ 0x08069608
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _08069622
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08069628 @ =sCollisions+48
	bl SetDDP
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08069622:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069628: .4byte sCollisions+48

	thumb_func_start explodeGrandCannon
explodeGrandCannon: @ 0x0806962C
	push {r4, r5, lr}
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
	ldr r1, _080696B8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _080696BC @ =sMotions
	adds r0, r4, #0
	mov r1, sp
	movs r3, #3
	bl FUN_080b7f70
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #3
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _080696C0 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _080696C4 @ =0x0000270E
	cmp r1, r0
	bhi _0806968C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0806968C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl TryDropZakoDisk
	ldr r1, _080696C8 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	ldrb r1, [r4, #0xb]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r4, #0xb]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080696B8: .4byte 0xFFFFF000
_080696BC: .4byte sMotions
_080696C0: .4byte gMission
_080696C4: .4byte 0x0000270E
_080696C8: .4byte gEnemyFnTable

	thumb_func_start slashGrandCannon
slashGrandCannon: @ 0x080696CC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080696DE
	cmp r0, #1
	beq _08069792
	b _080697AA
_080696DE:
	movs r3, #0
	ldr r0, _08069700 @ =pZero2
	ldr r0, [r0]
	ldr r0, [r0, #0x54]
	ldr r1, [r5, #0x54]
	subs r0, r0, r1
	cmp r0, #0
	ble _080696F0
	movs r3, #1
_080696F0:
	adds r6, r3, #0
	adds r2, r6, #0
	cmp r6, #0
	beq _08069704
	ldrb r1, [r5, #0xa]
	movs r0, #0x10
	orrs r0, r1
	b _0806970A
	.align 2, 0
_08069700: .4byte pZero2
_08069704:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
_0806970A:
	strb r0, [r5, #0xa]
	adds r1, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	movs r4, #0
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	lsls r1, r6, #8
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x54]
	ldr r1, _080697B4 @ =0x00000701
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x54]
	str r0, [sp, #8]
	ldr r0, [r5, #0x58]
	str r0, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	movs r0, #0
	add r1, sp, #8
	adds r3, r6, #0
	bl FUN_080b2b40
	movs r1, #0x60
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #6
	subs r1, r1, r0
	str r1, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	adds r1, r5, #0
	adds r1, #0x54
	ldr r0, _080697B8 @ =0x083662C2
	str r0, [sp]
	movs r4, #0x18
	str r4, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_080b834c
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08069792:
	adds r0, r5, #0
	bl UpdateMotionGraphic
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080697AA
	adds r0, r5, #0
	bl explodeGrandCannon
_080697AA:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080697B4: .4byte 0x00000701
_080697B8: .4byte sMotions+6

	thumb_func_start FUN_080697bc
FUN_080697bc: @ 0x080697BC
	push {lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #0xc]
	cmp r0, #4
	bne _080697FE
	ldrb r1, [r3, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r3, #0xa]
	adds r0, r3, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r3, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3, #0xa]
	ldr r1, _08069804 @ =gEnemyFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r3, #0x14]
_080697FE:
	pop {r0}
	bx r0
	.align 2, 0
_08069804: .4byte gEnemyFnTable
