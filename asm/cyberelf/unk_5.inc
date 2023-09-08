	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateElf5
CreateElf5: @ 0x080E3468
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080E34B4 @ =gElfHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080E34AC
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080E34B8 @ =gElfFnTable
	movs r0, #5
	strb r0, [r3, #9]
	ldr r0, [r1, #0x14]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb4
	str r6, [r0]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
_080E34AC:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080E34B4: .4byte gElfHeaderPtr
_080E34B8: .4byte gElfFnTable

	thumb_func_start Elf5_Init
Elf5_Init: @ 0x080E34BC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _080E356C @ =gZeroRanges
	ldr r0, _080E3570 @ =0x00000147
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp]
	str r2, [sp, #4]
	ldr r0, _080E3574 @ =gPause
	movs r5, #1
	strb r5, [r0]
	ldr r1, _080E3578 @ =gElfFnTable
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
	adds r0, r4, #0
	bl ResetDynamicMotion
	ldrb r0, [r4, #0xa]
	movs r6, #0
	orrs r5, r0
	movs r0, #2
	orrs r5, r0
	strb r5, [r4, #0xa]
	movs r1, #0x90
	lsls r1, r1, #8
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x4c
	strb r6, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xa]
	subs r2, #1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r2, [sp]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	mov r2, r8
	ldr r0, [r2, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [sp]
	asrs r1, r0, #0x10
	ldr r0, [r2, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl Elf5_Update
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E356C: .4byte gZeroRanges
_080E3570: .4byte 0x00000147
_080E3574: .4byte gPause
_080E3578: .4byte gElfFnTable

	thumb_func_start Elf5_Update
Elf5_Update: @ 0x080E357C
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMotionGraphic
	ldr r1, _080E35A4 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Elf5_Die
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E35A4: .4byte gElfFnTable

	thumb_func_start Elf5_Die
Elf5_Die: @ 0x080E35A8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r2, [r0]
	ldr r1, _080E3610 @ =gPause
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080E3614 @ =gUnlockedElfPtr
	adds r3, r2, #0
	adds r3, #0xb4
	ldr r5, _080E3618 @ =0x00000121
	adds r0, r2, r5
	ldrb r0, [r0]
	ldr r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	ldrh r0, [r3, #4]
	adds r0, #3
	strh r0, [r3, #4]
	ldr r0, _080E361C @ =gMission
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x4c
	ldrb r0, [r1]
	cmp r0, #0x62
	bhi _080E35E6
	adds r0, #1
	strb r0, [r1]
_080E35E6:
	adds r0, r4, #0
	adds r0, #0x54
	movs r1, #0
	bl FUN_080bfce8
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _080E3620 @ =gElfFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E3610: .4byte gPause
_080E3614: .4byte gUnlockedElfPtr
_080E3618: .4byte 0x00000121
_080E361C: .4byte gMission
_080E3620: .4byte gElfFnTable
