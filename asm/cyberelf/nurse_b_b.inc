	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e284c
FUN_080e284c: @ 0x080E284C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r1, [r0]
	ldr r0, [r1, #0x54]
	str r0, [sp, #4]
	ldr r0, [r1, #0x58]
	str r0, [sp, #8]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E2876
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
	lsls r2, r2, #1
	b _080E2884
_080E2876:
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
_080E2884:
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080E289E
	ldrb r0, [r4, #0xd]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4, #0xd]
_080E289E:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080e28a8
FUN_080e28a8: @ 0x080E28A8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _080E28E8 @ =gZeroRanges
	ldr r2, _080E28EC @ =0x00000147
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r3, #0x54]
	str r0, [sp, #4]
	asrs r1, r1, #0x10
	ldr r0, [r3, #0x58]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E28F0
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
	lsls r2, r2, #1
	b _080E28FE
	.align 2, 0
_080E28E8: .4byte gZeroRanges
_080E28EC: .4byte 0x00000147
_080E28F0:
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
_080E28FE:
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080E2918
	ldrb r0, [r4, #0xd]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4, #0xd]
_080E2918:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080e2920
FUN_080e2920: @ 0x080E2920
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r3, [r0]
	ldr r1, _080E2960 @ =gZeroRanges
	ldr r2, _080E2964 @ =0x00000147
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r3, #0x54]
	str r0, [sp, #4]
	asrs r1, r2, #0x10
	ldr r0, [r3, #0x58]
	subs r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080E2968
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
	lsls r2, r2, #1
	b _080E2976
	.align 2, 0
_080E2960: .4byte gZeroRanges
_080E2964: .4byte 0x00000147
_080E2968:
	adds r0, r4, #0
	adds r0, #0xbc
	adds r1, r4, #0
	adds r1, #0x64
	adds r3, r4, #0
	adds r3, #0xba
	movs r2, #0xc0
_080E2976:
	str r2, [sp]
	add r2, sp, #4
	bl FUN_080e1578
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _080E2990
	ldrb r0, [r4, #0xd]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4, #0xd]
_080E2990:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

