	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08063174
FUN_08063174: @ 0x08063174
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bls _08063182
	b _0806328C
_08063182:
	lsls r0, r0, #2
	ldr r1, _0806318C @ =_08063190
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806318C: .4byte _08063190
_08063190: @ jump table
	.4byte _080631A4 @ case 0
	.4byte _080631E8 @ case 1
	.4byte _0806320C @ case 2
	.4byte _08063216 @ case 3
	.4byte _0806328C @ case 4
_080631A4:
	ldr r3, _08063204 @ =gStageRun
	ldrh r2, [r3, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _080631C6
	ldrb r1, [r3, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080631C6
	ldr r0, _08063208 @ =0x0000FFFE
	ands r0, r2
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r3, #8]
_080631C6:
	movs r1, #0
	movs r0, #0x3c
	strb r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x8c
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080631E8:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806328C
	adds r2, r4, #0
	adds r2, #0xbc
	ldr r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2]
	b _08063286
	.align 2, 0
_08063204: .4byte gStageRun
_08063208: .4byte 0x0000FFFE
_0806320C:
	movs r0, #0x28
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08063216:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0806328C
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #0x10
	bl TryDropItem
	ldr r0, [r4, #0x54]
	str r0, [sp]
	ldr r0, [r4, #0x58]
	ldr r1, _08063294 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x8c
	str r5, [r0]
	adds r0, #4
	str r5, [r0]
	adds r0, #4
	strb r5, [r0]
	ldrb r1, [r4, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r4, #0xa]
	ldr r1, _08063298 @ =gBossFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r4, #0x14]
	ldr r2, _0806329C @ =gStageRun
	ldrb r0, [r2, #0x12]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x12]
_08063286:
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_0806328C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063294: .4byte 0xFFFFF400
_08063298: .4byte gBossFnTable
_0806329C: .4byte gStageRun

	thumb_func_start FUN_080632a0
FUN_080632a0: @ 0x080632A0
	push {r4, r5, lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	bne _080632EA
	ldr r4, _080632F0 @ =gStageRun
	ldrh r3, [r4, #8]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _080632CC
	ldrb r1, [r4, #0x12]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080632CC
	ldr r0, _080632F4 @ =0x0000FFFE
	ands r0, r3
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r4, #8]
_080632CC:
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	strb r1, [r0]
	ldrb r1, [r2, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2, #0xa]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_080632EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080632F0: .4byte gStageRun
_080632F4: .4byte 0x0000FFFE

	thumb_func_start FUN_080632f8
FUN_080632f8: @ 0x080632F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	mov r8, r0
	ldrb r4, [r6, #0xe]
	cmp r4, #1
	beq _0806334A
	cmp r4, #1
	bgt _08063316
	cmp r4, #0
	beq _08063324
	b _080634FA
_08063316:
	cmp r4, #2
	bne _0806331C
	b _0806342C
_0806331C:
	cmp r4, #3
	bne _08063322
	b _0806343A
_08063322:
	b _080634FA
_08063324:
	ldr r1, _08063418 @ =0x0000D601
	adds r0, r6, #0
	bl SetMotion
	strb r4, [r6, #0x12]
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806334A:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08063402
	ldr r5, _0806341C @ =RNG_0202f388
	ldr r0, [r5]
	ldr r4, _08063420 @ =0x000343FD
	muls r0, r4, r0
	ldr r3, _08063424 @ =0x00269EC3
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r2, r0, #1
	lsrs r0, r0, #0x11
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	lsls r7, r0, #8
	str r7, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r0, r0, r3
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r5]
	lsrs r0, r0, #0x11
	movs r1, #0x3f
	ands r0, r1
	rsbs r0, r0, #0
	lsls r3, r0, #8
	str r3, [sp, #4]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsrs r1, r0, #8
	ldr r5, _08063428 @ =gSineTable
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, r4, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _080633AE
	adds r0, #0xff
_080633AE:
	asrs r2, r0, #8
	str r2, [sp, #8]
	lsls r0, r1, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	rsbs r0, r1, #0
	muls r0, r3, r0
	cmp r0, #0
	bge _080633C4
	adds r0, #0xff
_080633C4:
	asrs r0, r0, #8
	adds r0, r0, r2
	str r0, [sp, #8]
	adds r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge _080633D4
	adds r0, #0xff
_080633D4:
	asrs r1, r0, #8
	add r2, sp, #8
	str r1, [r2, #4]
	ldr r0, [sp, #4]
	muls r0, r4, r0
	cmp r0, #0
	bge _080633E4
	adds r0, #0xff
_080633E4:
	asrs r0, r0, #8
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, [r6, #0x54]
	ldr r1, [sp, #8]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [r6, #0x58]
	ldr r1, [r2, #4]
	adds r0, r0, r1
	str r0, [r2, #4]
	movs r0, #2
	adds r1, r2, #0
	bl CreateSmoke
_08063402:
	mov r0, r8
	adds r0, #0xbc
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080634FA
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
	b _080634FA
	.align 2, 0
_08063418: .4byte 0x0000D601
_0806341C: .4byte RNG_0202f388
_08063420: .4byte 0x000343FD
_08063424: .4byte 0x00269EC3
_08063428: .4byte gSineTable
_0806342C:
	movs r0, #0
	strb r0, [r6, #0x12]
	strb r0, [r6, #0x13]
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0xe]
	adds r0, #1
	strb r0, [r6, #0xe]
_0806343A:
	ldrb r0, [r6, #0x12]
	adds r0, #1
	strb r0, [r6, #0x12]
	ldrb r0, [r6, #0x12]
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080634FA
	ldr r5, _08063508 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [r6, #0x64]
	muls r0, r2, r0
	cmp r0, #0
	bge _08063470
	adds r0, #0xff
_08063470:
	asrs r1, r0, #8
	ldr r0, [r6, #0x54]
	adds r0, r0, r1
	str r0, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	bge _0806348E
	adds r0, #0xff
_0806348E:
	asrs r1, r0, #8
	ldr r0, [r6, #0x58]
	subs r0, r0, r1
	str r0, [sp, #4]
	movs r0, #1
	mov r1, sp
	bl CreateSmoke
	ldrb r1, [r6, #0x13]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080634AE
	movs r0, #0x2a
	bl PlaySound
_080634AE:
	ldr r0, [r6, #0x64]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r6, #0x64]
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _080634FA
	ldrb r1, [r6, #0xa]
	movs r0, #0xfe
	ands r0, r1
	movs r1, #0xfd
	ands r0, r1
	strb r0, [r6, #0xa]
	adds r0, r6, #0
	adds r0, #0x8c
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	adds r0, #4
	strb r4, [r0]
	ldrb r1, [r6, #0xa]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r6, #0xa]
	ldr r1, _0806350C @ =gBossFnTable
	ldrb r0, [r6, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #3
	str r1, [r6, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	str r0, [r6, #0x14]
_080634FA:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063508: .4byte gSineTable
_0806350C: .4byte gBossFnTable
