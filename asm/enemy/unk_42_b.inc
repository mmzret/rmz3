	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808537c
FUN_0808537c: @ 0x0808537C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	movs r2, #1
	cmp r0, #0
	beq _08085398
	movs r2, #0xff
_08085398:
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _08085560 @ =RNG_0202f388
	ldr r0, [r6]
	ldr r5, _08085564 @ =0x000343FD
	muls r0, r5, r0
	ldr r4, _08085568 @ =0x00269EC3
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r3, #0x7f
	ands r0, r3
	adds r0, #0x80
	lsls r2, r2, #0x18
	mov r8, r2
	asrs r2, r2, #0x18
	mov r8, r2
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #0
	bl CreateVFX57
	ldr r0, [sp, #8]
	ldr r3, _08085570 @ =0xFFFFF000
	mov sl, r3
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #2
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xff
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	mov sb, r3
	add r0, sb
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #3
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldr r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	lsrs r0, r0, #0x11
	movs r2, #0xff
	ands r0, r2
	add r0, sb
	mov r3, r8
	muls r3, r0, r3
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r0, r4
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r6]
	lsrs r0, r0, #0x11
	ldr r1, _0808556C @ =0x000003FF
	ands r0, r1
	add r0, sb
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #4
	movs r1, #1
	movs r2, #1
	bl CreateVFX57
	ldr r0, [sp, #8]
	add r0, sl
	str r0, [sp, #8]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08085574 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	str r0, [r7, #0x14]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085560: .4byte RNG_0202f388
_08085564: .4byte 0x000343FD
_08085568: .4byte 0x00269EC3
_0808556C: .4byte 0x000003FF
_08085570: .4byte 0xFFFFF000
_08085574: .4byte gEnemyFnTable
