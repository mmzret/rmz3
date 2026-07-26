	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080e3f70
FUN_080e3f70: @ 0x080E3F70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r0, #0xb4
	ldr r5, [r0]
	ldr r1, _080E3FD8 @ =gZeroRanges
	ldr r2, _080E3FDC @ =0x00000147
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, [r0, #4]
	mov r1, sb
	adds r1, #0xc0
	ldr r0, [r1]
	subs r0, #0x60
	str r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #4
	cmp r0, r2
	bgt _080E3FB8
	str r2, [r1]
	ldr r1, _080E3FE0 @ =gElfFnTable
	mov r2, sb
	ldrb r0, [r2, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r2, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r2, #0x14]
_080E3FB8:
	mov r0, sb
	adds r0, #0xba
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E3FE8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	asrs r1, r3, #0x10
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	ldr r1, _080E3FE4 @ =0xFFFFFE00
	adds r7, r0, r1
	b _080E4006
	.align 2, 0
_080E3FD8: .4byte gZeroRanges
_080E3FDC: .4byte 0x00000147
_080E3FE0: .4byte gElfFnTable
_080E3FE4: .4byte 0xFFFFFE00
_080E3FE8:
	cmp r0, #1
	bne _080E3FF8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	ldr r7, [r5, #0x58]
	b _080E4006
_080E3FF8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x54]
	adds r2, r1, r0
	asrs r1, r4, #0x10
	ldr r0, [r5, #0x58]
	subs r7, r0, r1
_080E4006:
	mov r0, sb
	ldr r6, [r0, #0x54]
	subs r2, r2, r6
	ldr r1, [r0, #0x58]
	mov r8, r1
	subs r7, r7, r1
	adds r0, #0xc0
	ldr r4, [r0]
	movs r5, #0xa0
	lsls r5, r5, #6
	subs r4, r5, r4
	adds r0, r2, #0
	muls r0, r4, r0
	adds r1, r5, #0
	bl __divsi3
	adds r2, r0, #0
	adds r0, r7, #0
	muls r0, r4, r0
	adds r1, r5, #0
	str r2, [sp]
	bl __divsi3
	adds r7, r0, #0
	ldr r2, [sp]
	adds r6, r6, r2
	mov r2, sb
	str r6, [r2, #0x54]
	add r8, r7
	mov r0, r8
	str r0, [r2, #0x58]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

