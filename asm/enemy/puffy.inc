	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreatePuffy
CreatePuffy: @ 0x0807C584
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0807C5DC @ =gZakoHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _0807C5D2
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0807C5E0 @ =gEnemyFnTable
	movs r1, #0x20
	strb r1, [r3, #9]
	adds r0, #0x80
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
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r4, [r3, #0x10]
_0807C5D2:
	adds r0, r3, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807C5DC: .4byte gZakoHeaderPtr
_0807C5E0: .4byte gEnemyFnTable

	thumb_func_start Puffy_Init
Puffy_Init: @ 0x0807C5E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl InitNonAffineMotion
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r6, #0
	movs r1, #0xef
	ands r0, r1
	movs r7, #0
	strb r0, [r5, #0xa]
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x4c
	strb r7, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #0xa]
	movs r0, #4
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r4, r5, #0
	adds r4, #0x74
	ldr r1, _0807C680 @ =0x08367B0C
	adds r2, #0xa
	adds r0, r4, #0
	movs r3, #6
	bl InitBody
	str r5, [r4, #0x2c]
	ldr r0, _0807C684 @ =FUN_0807cba4
	str r0, [r4, #0x24]
	ldr r0, _0807C688 @ =gOverworld
	ldr r1, _0807C68C @ =0x0002C00C
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r5, #0x58]
	cmp r0, r1
	ble _0807C694
	ldrb r1, [r5, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x8c
	str r7, [r0]
	adds r0, #4
	str r7, [r0]
	adds r0, #4
	strb r7, [r0]
	ldrb r1, [r5, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r5, #0xa]
	ldr r1, _0807C690 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0x14]
	b _0807C6E8
	.align 2, 0
_0807C680: .4byte 0x08367B0C
_0807C684: .4byte FUN_0807cba4
_0807C688: .4byte gOverworld
_0807C68C: .4byte 0x0002C00C
_0807C690: .4byte gEnemyFnTable
_0807C694:
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r5, #0x68]
	str r1, [r0]
	subs r0, #0x58
	str r6, [r0, #4]
	str r6, [r5, #0x5c]
	adds r0, #0x60
	str r6, [r0]
	subs r0, #4
	strb r6, [r0]
	adds r0, #8
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0807C6F4 @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r1, r8
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r5, #0x14]
	strb r6, [r5, #0xd]
	strb r6, [r5, #0xe]
	strb r6, [r5, #0xf]
	adds r0, r5, #0
	bl isFrozen
	cmp r0, #0
	beq _0807C6E2
	movs r1, #0x82
	lsls r1, r1, #7
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	bl UpdateMotionGraphic
_0807C6E2:
	adds r0, r5, #0
	bl Puffy_Update
_0807C6E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807C6F4: .4byte gEnemyFnTable

	thumb_func_start Puffy_Update
Puffy_Update: @ 0x0807C6F8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C728
	ldr r1, _0807C724 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl Puffy_Die
	b _0807C768
	.align 2, 0
_0807C724: .4byte gEnemyFnTable
_0807C728:
	ldr r1, _0807C754 @ =0x08367AEC
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0807cb50
	adds r0, r4, #0
	bl isFrozen
	cmp r0, #0
	beq _0807C758
	ldrb r1, [r4, #0xd]
	adds r0, r4, #0
	adds r0, #0xba
	strb r1, [r0]
	b _0807C768
	.align 2, 0
_0807C754: .4byte 0x08367AEC
_0807C758:
	ldr r0, _0807C770 @ =0x08367AFC
	ldrb r1, [r4, #0xd]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0807C768:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C770: .4byte 0x08367AFC

	thumb_func_start Puffy_Die
Puffy_Die: @ 0x0807C774
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _0807C7A8 @ =gStageRun
	ldr r0, [r0, #0x30]
	cmp r0, #0
	beq _0807C7B4
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C7AC @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C7B0 @ =0x0000270E
	cmp r1, r0
	bhi _0807C7A2
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C7A2:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C936
	.align 2, 0
_0807C7A8: .4byte gStageRun
_0807C7AC: .4byte gMission
_0807C7B0: .4byte 0x0000270E
_0807C7B4:
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _0807C7BC
	b _0807C954
_0807C7BC:
	lsls r0, r0, #2
	ldr r1, _0807C7C8 @ =_0807C7CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807C7C8: .4byte _0807C7CC
_0807C7CC: @ jump table
	.4byte _0807C7E0 @ case 0
	.4byte _0807C890 @ case 1
	.4byte _0807C8C0 @ case 2
	.4byte _0807C8D0 @ case 3
	.4byte _0807C90C @ case 4
_0807C7E0:
	ldr r1, _0807C840 @ =0x00004101
	adds r0, r4, #0
	bl SetMotion
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r2, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r2
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x5c
	str r1, [r0, #4]
	str r1, [r4, #0x5c]
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C848
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C844 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #4]
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #4
	movs r0, #1
	ands r1, r0
	mov r0, sp
	bl createGhost44
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #5
	bl TryDropItem
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C890
	.align 2, 0
_0807C840: .4byte 0x00004101
_0807C844: .4byte 0xFFFFFA00
_0807C848:
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _0807C884 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	adds r5, r4, #0
	adds r5, #0x54
	movs r0, #5
	adds r1, r5, #0
	bl TryDropItem
	ldr r2, _0807C888 @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C88C @ =0x0000270E
	cmp r1, r0
	bhi _0807C87C
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C87C:
	adds r0, r4, #0
	adds r1, r5, #0
	b _0807C936
	.align 2, 0
_0807C884: .4byte 0xFFFFFA00
_0807C888: .4byte gMission
_0807C88C: .4byte 0x0000270E
_0807C890:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C8B0
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C8B6
_0807C8B0:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C8B6:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C954
	b _0807C904
_0807C8C0:
	adds r0, r4, #0
	bl PaintEntityWhite
	movs r0, #0xa
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C8D0:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	movs r1, #0xff
	ands r0, r1
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807C8EA
	ldrb r0, [r4, #0xa]
	movs r1, #1
	orrs r0, r1
	b _0807C8F0
_0807C8EA:
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
_0807C8F0:
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0807C954
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x3c
	strb r0, [r4, #0x12]
_0807C904:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
	b _0807C954
_0807C90C:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807C91C
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C954
_0807C91C:
	movs r0, #0
	bl PlaySound
	ldr r2, _0807C95C @ =gMission
	ldrh r1, [r2, #0xc]
	ldr r0, _0807C960 @ =0x0000270E
	cmp r1, r0
	bhi _0807C930
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_0807C930:
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r4, #0
_0807C936:
	bl TryDropZakoDisk
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _0807C964 @ =gEnemyFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r4, #0x14]
_0807C954:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C95C: .4byte gMission
_0807C960: .4byte 0x0000270E
_0807C964: .4byte gEnemyFnTable

	thumb_func_start nop_0807c968
nop_0807c968: @ 0x0807C968
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807c96c
FUN_0807c96c: @ 0x0807C96C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r5, [r4, #0xe]
	cmp r5, #0
	beq _0807C97E
	cmp r5, #1
	beq _0807C994
	b _0807CA8A
_0807C97E:
	movs r1, #0x82
	lsls r1, r1, #7
	adds r0, r4, #0
	bl SetMotion
	movs r0, #0xc4
	strb r0, [r4, #0x12]
	str r5, [r4, #0x5c]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807C994:
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r0, [r0]
	ldr r2, [r4, #0x68]
	subs r0, r0, r2
	lsls r0, r0, #4
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r4, #0x68]
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	ldr r1, _0807C9F0 @ =gSineTable
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, r2, r0
	str r2, [r4, #0x58]
	adds r0, r4, #0
	bl dragInSea
	ldr r0, _0807C9F4 @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	ble _0807C9F8
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _0807CA30
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807CA12
	movs r0, #0x10
	orrs r0, r2
	b _0807CA16
	.align 2, 0
_0807C9F0: .4byte gSineTable
_0807C9F4: .4byte pZero2
_0807C9F8:
	ldrb r2, [r4, #0xa]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807CA30
	lsrs r0, r2, #4
	movs r1, #1
	bics r1, r0
	cmp r1, #0
	beq _0807CA12
	movs r0, #0x10
	orrs r0, r2
	b _0807CA16
_0807CA12:
	movs r0, #0xef
	ands r0, r2
_0807CA16:
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
_0807CA30:
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _0807CA46
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807CA8A
_0807CA46:
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0807CA5C
	ldr r0, [r4, #0x54]
	ldr r2, _0807CA58 @ =0xFFFFEA00
	adds r0, r0, r2
	b _0807CA64
	.align 2, 0
_0807CA58: .4byte 0xFFFFEA00
_0807CA5C:
	ldr r0, [r4, #0x54]
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r0, r3
_0807CA64:
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r2, _0807CA94 @ =0xFFFFFC00
	adds r0, r0, r2
	str r0, [sp, #4]
	lsls r3, r1, #0x18
	lsrs r3, r3, #0x1c
	movs r0, #1
	ands r3, r0
	adds r0, r4, #0
	mov r1, sp
	mov r2, sp
	bl FUN_080a2838
	movs r0, #0
	bl PlaySound
	movs r0, #0xc4
	strb r0, [r4, #0x12]
_0807CA8A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CA94: .4byte 0xFFFFFC00

	thumb_func_start nop_0807ca98
nop_0807ca98: @ 0x0807CA98
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807ca9c
FUN_0807ca9c: @ 0x0807CA9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _0807CAAA
	movs r0, #1
	strb r0, [r4, #0xe]
_0807CAAA:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807CAC0
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807CAC0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start nop_0807cac8
nop_0807cac8: @ 0x0807CAC8
	movs r0, #1
	bx lr

	thumb_func_start nop_0807cacc
nop_0807cacc: @ 0x0807CACC
	bx lr
	.align 2, 0

	thumb_func_start nop_0807cad0
nop_0807cad0: @ 0x0807CAD0
	movs r0, #1
	bx lr

	thumb_func_start FUN_0807cad4
FUN_0807cad4: @ 0x0807CAD4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0807CAE4
	cmp r0, #1
	beq _0807CAEC
	b _0807CB30
_0807CAE4:
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0807CAEC:
	ldr r0, [r4, #0x60]
	adds r0, #0x10
	str r0, [r4, #0x60]
	movs r1, #0xe0
	lsls r1, r1, #3
	cmp r0, r1
	ble _0807CAFC
	str r1, [r4, #0x60]
_0807CAFC:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	ldr r2, [r4, #0x60]
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0807CB28
	movs r0, #0
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	bl FUN_08009f6c
	ldr r1, _0807CB24 @ =0xFFFFF000
	b _0807CB2C
	.align 2, 0
_0807CB24: .4byte 0xFFFFF000
_0807CB28:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
_0807CB2C:
	adds r0, r0, r1
	str r0, [r4, #0x58]
_0807CB30:
	adds r5, r4, #0
	adds r5, #0xbc
	ldr r0, [r5]
	bl isKilled
	cmp r0, #0
	beq _0807CB4A
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x68]
	movs r0, #0
	str r0, [r5]
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_0807CB4A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807cb50
FUN_0807cb50: @ 0x0807CB50
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xbc
	ldr r5, [r6]
	cmp r5, #0
	bne _0807CB9A
	adds r0, #0x8c
	ldr r0, [r0]
	movs r7, #1
	ands r0, r7
	cmp r0, #0
	beq _0807CB9A
	ldr r2, _0807CB8C @ =0x08367B3C
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r6]
	cmp r0, #0
	beq _0807CB9A
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _0807CB90
	strb r7, [r4, #0xd]
	b _0807CB98
	.align 2, 0
_0807CB8C: .4byte 0x08367B3C
_0807CB90:
	cmp r1, #0x30
	bne _0807CB9A
	movs r0, #3
	strb r0, [r4, #0xd]
_0807CB98:
	strb r5, [r4, #0xe]
_0807CB9A:
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807cba4
FUN_0807cba4: @ 0x0807CBA4
	push {lr}
	ldr r2, [r0, #0x2c]
	adds r0, r2, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	ldr r0, _0807CBD0 @ =gCollisionManager
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0807CBCC
	adds r1, r2, #0
	adds r1, #0xc0
	movs r0, #0
	strb r0, [r1]
_0807CBCC:
	pop {r0}
	bx r0
	.align 2, 0
_0807CBD0: .4byte gCollisionManager

	thumb_func_start dragInSea
dragInSea: @ 0x0807CBD4
	push {lr}
	adds r3, r0, #0
	ldr r1, _0807CBEC @ =gOverworld
	ldr r2, _0807CBF0 @ =0x0002C00C
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r1, [r3, #0x58]
	cmp r2, r1
	ble _0807CBE8
	str r2, [r3, #0x58]
_0807CBE8:
	pop {r1}
	bx r1
	.align 2, 0
_0807CBEC: .4byte gOverworld
_0807CBF0: .4byte 0x0002C00C
