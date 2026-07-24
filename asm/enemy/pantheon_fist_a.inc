	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start createPantheonFistInElevator
createPantheonFistInElevator: @ 0x08094F40
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08094FA0 @ =gEnemyHeaderPtr
	ldr r0, [r0]
	bl AllocEntityLast
	adds r3, r0, #0
	cmp r3, #0
	beq _08094F96
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08094FA4 @ =gEnemyFnTable
	movs r1, #0x40
	strb r1, [r3, #9]
	adds r1, #0xc0
	adds r0, r0, r1
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
	movs r0, #1
	strb r0, [r3, #0x10]
	str r5, [r3, #0x54]
	str r6, [r3, #0x58]
	adds r0, r3, #0
	adds r0, #0xb9
	strb r4, [r0]
_08094F96:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08094FA0: .4byte gEnemyHeaderPtr
_08094FA4: .4byte gEnemyFnTable

	thumb_func_start FUN_08094fa8
FUN_08094fa8: @ 0x08094FA8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x54]
	ldr r3, _08094FD4 @ =0xFFFFF200
	adds r0, r0, r3
	cmp r1, #0
	ble _08094FBC
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, r0, r1
_08094FBC:
	ldr r1, [r2, #0x58]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08094FD8
	movs r0, #0
	b _08094FDA
	.align 2, 0
_08094FD4: .4byte 0xFFFFF200
_08094FD8:
	movs r0, #1
_08094FDA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08094fe0
FUN_08094fe0: @ 0x08094FE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	ble _0809500C
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x54]
	bl FUN_08009f6c
	ldr r2, [r4, #0x58]
	subs r1, r0, r2
	ldr r0, _08095008 @ =0x000007FF
	cmp r1, r0
	bgt _0809500C
	adds r0, r2, r1
	str r0, [r4, #0x58]
	movs r0, #1
	b _0809500E
	.align 2, 0
_08095008: .4byte 0x000007FF
_0809500C:
	movs r0, #0
_0809500E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095014
FUN_08095014: @ 0x08095014
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	beq _0809506A
	cmp r5, #0
	bge _08095044
	ldr r0, [r4, #0x54]
	ldr r1, _0809503C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095040 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #1
	b _0809506C
	.align 2, 0
_0809503C: .4byte 0xFFFFF200
_08095040: .4byte 0xFFFFF600
_08095044:
	ldr r0, [r4, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r4, #0x58]
	ldr r2, _08095060 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08095064
	movs r0, #2
	b _0809506C
	.align 2, 0
_08095060: .4byte 0xFFFFF600
_08095064:
	ldr r0, [r4, #0x54]
	adds r0, r0, r5
	str r0, [r4, #0x54]
_0809506A:
	movs r0, #0
_0809506C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08095074
FUN_08095074: @ 0x08095074
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	beq _080950C4
	cmp r1, #0
	bge _080950A4
	ldr r0, [r2, #0x54]
	ldr r1, _0809509C @ =0xFFFFF200
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950A0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #1
	b _080950C6
	.align 2, 0
_0809509C: .4byte 0xFFFFF200
_080950A0: .4byte 0xFFFFF600
_080950A4:
	ldr r0, [r2, #0x54]
	movs r1, #0xe0
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r2, #0x58]
	ldr r2, _080950C0 @ =0xFFFFF600
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080950C4
	movs r0, #2
	b _080950C6
	.align 2, 0
_080950C0: .4byte 0xFFFFF600
_080950C4:
	movs r0, #0
_080950C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start nop_080950cc
nop_080950cc: @ 0x080950CC
	bx lr
	.align 2, 0
