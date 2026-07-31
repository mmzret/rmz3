	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809b4dc
FUN_0809b4dc: @ 0x0809B4DC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x8c
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809B5D8
	adds r2, r5, #0
	adds r2, #0xb6
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809B512
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r6, r5, #0
	adds r6, #0xb4
	cmp r0, #2
	beq _0809B552
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldrh r2, [r1, #0x38]
	adds r0, r0, r2
	b _0809B52C
_0809B512:
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #1
	bne _0809B53C
	ldr r1, [r5, #0x28]
	movs r3, #4
	ldrsh r0, [r1, r3]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #5
_0809B52C:
	strh r0, [r1, #0x38]
	ldr r0, _0809B538 @ =0x00000137
	bl PlaySound
	b _0809B552
	.align 2, 0
_0809B538: .4byte 0x00000137
_0809B53C:
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B552
	ldrh r0, [r1, #0x38]
	adds r0, #1
	strh r0, [r1, #0x38]
	ldr r0, _0809B5BC @ =0x00000137
	bl PlaySound
_0809B552:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
	ldr r2, _0809B5C0 @ =RNG_0202f388
	ldr r1, [r2]
	ldr r0, _0809B5C4 @ =0x000343FD
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r3, _0809B5C8 @ =0x00269EC3
	adds r4, r4, r3
	lsls r4, r4, #1
	lsrs r0, r4, #1
	str r0, [r2]
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r4, r0
	ldr r0, [r5, #0x54]
	str r0, [sp]
	ldr r0, [r5, #0x58]
	str r0, [sp, #4]
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5CC @ =0x00004707
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D0 @ =0x00004708
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	ldrb r1, [r6]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0809B5D4 @ =0x00004709
	mov r0, sp
	adds r3, r4, #0
	bl CreateGhost82_2
	b _0809B924
	.align 2, 0
_0809B5BC: .4byte 0x00000137
_0809B5C0: .4byte RNG_0202f388
_0809B5C4: .4byte 0x000343FD
_0809B5C8: .4byte 0x00269EC3
_0809B5CC: .4byte 0x00004707
_0809B5D0: .4byte 0x00004708
_0809B5D4: .4byte 0x00004709
_0809B5D8:
	adds r0, r5, #0
	adds r0, #0xb5
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0809B5F8
	movs r1, #1
	ands r2, r1
	cmp r2, #0
	beq _0809B5F8
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0809B5F8
	strb r1, [r3]
	movs r0, #0xa
	strb r0, [r5, #0xe]
_0809B5F8:
	ldrb r0, [r5, #0xe]
	cmp r0, #0xb
	bls _0809B600
	b _0809B936
_0809B600:
	lsls r0, r0, #2
	ldr r1, _0809B60C @ =_0809B610
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B60C: .4byte _0809B610
_0809B610: @ jump table
	.4byte _0809B640 @ case 0
	.4byte _0809B6B6 @ case 1
	.4byte _0809B6F6 @ case 2
	.4byte _0809B700 @ case 3
	.4byte _0809B936 @ case 4
	.4byte _0809B73E @ case 5
	.4byte _0809B7F2 @ case 6
	.4byte _0809B936 @ case 7
	.4byte _0809B936 @ case 8
	.4byte _0809B936 @ case 9
	.4byte _0809B818 @ case 10
	.4byte _0809B8C0 @ case 11
_0809B640:
	movs r4, #0
	str r4, [r5, #0x2c]
	strb r4, [r3]
	adds r0, r5, #0
	adds r0, #0xb6
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r1, _0809B688 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r0, _0809B68C @ =pZero2
	ldr r0, [r0]
	ldr r1, [r0, #0x54]
	ldr r0, [r5, #0x54]
	cmp r1, r0
	ble _0809B690
	movs r2, #1
	ldrb r0, [r5, #0xa]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r3, r5, #0
	adds r3, #0x4a
	movs r2, #0x10
	ldrb r1, [r3]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	b _0809B6AC
	.align 2, 0
_0809B688: .4byte 0x00004703
_0809B68C: .4byte pZero2
_0809B690:
	ldrb r1, [r5, #0xa]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r5, #0xa]
	adds r0, r5, #0
	adds r0, #0x4c
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x4a
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0809B6AC:
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B6B6:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B6EE
	b _0809B936
_0809B6EE:
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
	b _0809B936
_0809B6F6:
	movs r0, #0x30
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B700:
	ldr r1, [r5, #0x64]
	ldr r2, [r5, #0x54]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x54]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x58]
	subs r1, r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B738
	b _0809B936
_0809B738:
	movs r0, #5
	strb r0, [r5, #0xe]
	b _0809B936
_0809B73E:
	movs r0, #0
	str r0, [r5, #0x2c]
	strb r0, [r3]
	ldr r1, _0809B7A0 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	ldr r6, _0809B7A4 @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B7A8
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B7C4
	.align 2, 0
_0809B7A0: .4byte 0x00004703
_0809B7A4: .4byte pZero2
_0809B7A8:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B7BC
	ldr r0, _0809B7B8 @ =0xFFFFFF00
	b _0809B7C0
	.align 2, 0
_0809B7B8: .4byte 0xFFFFFF00
_0809B7BC:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B7C0:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B7C4:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #7
	rsbs r0, r0, #0
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound
	movs r0, #0xb4
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B7F2:
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x5c]
	adds r0, r0, r1
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r1, [r5, #0x60]
	adds r0, r0, r1
	str r0, [r5, #0x58]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809B816
	b _0809B936
_0809B816:
	b _0809B924
_0809B818:
	ldr r6, _0809B86C @ =pZero2
	ldr r2, [r6]
	ldr r0, [r5, #0x54]
	ldr r1, [r2, #0x54]
	subs r0, r0, r1
	str r0, [r5, #0x64]
	ldr r1, [r5, #0x58]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r2, [r2, #0x58]
	subs r1, r1, r2
	str r1, [r5, #0x68]
	asrs r0, r0, #2
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	asrs r1, r1, #2
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0xe
	cmp r4, #0
	beq _0809B870
	ldr r0, [r5, #0x64]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	lsls r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	str r0, [r5, #0x68]
	b _0809B88C
	.align 2, 0
_0809B86C: .4byte pZero2
_0809B870:
	ldr r0, [r6]
	ldrb r1, [r0, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809B884
	ldr r0, _0809B880 @ =0xFFFFFF00
	b _0809B888
	.align 2, 0
_0809B880: .4byte 0xFFFFFF00
_0809B884:
	movs r0, #0x80
	lsls r0, r0, #1
_0809B888:
	str r0, [r5, #0x64]
	str r4, [r5, #0x68]
_0809B88C:
	ldr r1, [r5, #0x64]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x5c]
	ldr r1, [r5, #0x68]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #8
	asrs r0, r0, #8
	str r0, [r5, #0x60]
	ldr r1, _0809B940 @ =0x00004703
	adds r0, r5, #0
	bl SetMotion
	adds r0, r5, #0
	adds r0, #0x74
	ldr r1, _0809B944 @ =0x0836A800
	bl SetDDP
	movs r0, #0x1e
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_0809B8C0:
	ldr r0, [r5, #0x54]
	ldr r2, [r5, #0x5c]
	adds r0, r0, r2
	str r0, [r5, #0x54]
	ldr r0, [r5, #0x58]
	ldr r3, [r5, #0x60]
	adds r0, r0, r3
	str r0, [r5, #0x58]
	rsbs r1, r2, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r2, r2, r0
	str r2, [r5, #0x5c]
	rsbs r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #8
	adds r3, r3, r0
	str r3, [r5, #0x60]
	adds r0, r5, #0
	bl UpdateEntityAnim
	ldrb r0, [r5, #0x12]
	subs r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0809B936
	ldr r1, [r5, #0x28]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #2
	beq _0809B914
	ldrh r0, [r1, #0x38]
	adds r0, #5
	strh r0, [r1, #0x38]
	ldr r0, _0809B948 @ =0x00000137
	bl PlaySound
_0809B914:
	adds r1, r5, #0
	adds r1, #0x54
	movs r0, #1
	bl CreateSmoke
	movs r0, #0x2a
	bl PlaySound
_0809B924:
	ldr r1, _0809B94C @ =gEnemyFnTable
	ldrb r0, [r5, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r5, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r5, #0x14]
_0809B936:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B940: .4byte 0x00004703
_0809B944: .4byte 0x0836A800
_0809B948: .4byte 0x00000137
_0809B94C: .4byte gEnemyFnTable
