	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CapsuleCannon_Die
CapsuleCannon_Die: @ 0x08085874
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _080858BC @ =gCurStory
	ldrb r1, [r0, #8]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080858C4
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r2, #0
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r7, #0xa]
	adds r0, r7, #0
	adds r0, #0x8c
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	adds r0, #4
	strb r2, [r0]
	ldrb r1, [r7, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _080858C0 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	b _080859F0
	.align 2, 0
_080858BC: .4byte gCurStory
_080858C0: .4byte gEnemyFnTable
_080858C4:
	ldrb r1, [r7, #0xe]
	cmp r1, #1
	beq _080858F4
	cmp r1, #1
	bgt _080858D4
	cmp r1, #0
	beq _080858DA
	b _080859F2
_080858D4:
	cmp r1, #2
	beq _08085904
	b _080859F2
_080858DA:
	movs r0, #1
	strb r0, [r7, #0xe]
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
_080858F4:
	ldr r0, [r7, #0x54]
	str r0, [sp]
	ldr r0, [r7, #0x58]
	str r0, [sp, #4]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
	b _080859F2
_08085904:
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08085918
	ldr r0, [r7, #0x5c]
	ldr r1, _08085914 @ =0xFFFFF800
	b _0808591E
	.align 2, 0
_08085914: .4byte 0xFFFFF800
_08085918:
	ldr r0, [r7, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #4
_0808591E:
	adds r0, r0, r1
	str r0, [sp]
	ldr r0, [r7, #0x60]
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldr r2, _08085990 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _08085994 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08085998 @ =0x00269EC3
	adds r4, r4, r0
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r7, #0x54]
	str r0, [sp, #8]
	ldr r0, [r7, #0x58]
	add r6, sp, #8
	str r0, [r6, #4]
	adds r5, r7, #0
	adds r5, #0xb8
	ldrb r1, [r5]
	ldr r2, _0808599C @ =0x00006803
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	ldrb r1, [r5]
	ldr r2, _080859A0 @ =0x00006804
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	ldrb r1, [r5]
	ldr r2, _080859A4 @ =0x00006805
	adds r0, r6, #0
	adds r3, r4, #0
	bl CreateVFX60
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r7, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080859AC
	ldr r0, [r7, #0x54]
	ldr r1, _080859A8 @ =0xFFFFF400
	b _080859B2
	.align 2, 0
_08085990: .4byte RNG_0202f388
_08085994: .4byte 0x000343FD
_08085998: .4byte 0x00269EC3
_0808599C: .4byte 0x00006803
_080859A0: .4byte 0x00006804
_080859A4: .4byte 0x00006805
_080859A8: .4byte 0xFFFFF400
_080859AC:
	ldr r0, [r7, #0x54]
	movs r1, #0xc0
	lsls r1, r1, #4
_080859B2:
	adds r0, r0, r1
	str r0, [r7, #0x54]
	adds r4, r7, #0
	adds r4, #0x54
	movs r0, #3
	adds r1, r4, #0
	bl TryDropItem
	ldr r2, _080859FC @ =gScore
	ldrh r1, [r2, #0xc]
	ldr r0, _08085A00 @ =0x0000270E
	cmp r1, r0
	bhi _080859D0
	adds r0, r1, #1
	strh r0, [r2, #0xc]
_080859D0:
	adds r0, r7, #0
	adds r1, r4, #0
	bl TryDropZakoDisk
	ldrb r1, [r7, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #0xa]
	ldr r1, _08085A04 @ =gEnemyFnTable
	ldrb r0, [r7, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	str r1, [r7, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
_080859F0:
	str r0, [r7, #0x14]
_080859F2:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080859FC: .4byte gScore
_08085A00: .4byte 0x0000270E
_08085A04: .4byte gEnemyFnTable
