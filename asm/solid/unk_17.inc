	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Solid17_Init
Solid17_Init: @ 0x080CF0FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CF190 @ =gSolidFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	ldr r1, _080CF194 @ =0x08370624
	ldrb r0, [r4, #0x10]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xa]
	movs r1, #2
	orrs r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	bl InitNonAffineMotion
	ldrb r0, [r4, #0xa]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r5, r4, #0
	adds r5, #0x74
	ldr r1, _080CF198 @ =0x083705BC
	adds r2, r4, #0
	adds r2, #0x54
	adds r0, r5, #0
	movs r3, #1
	bl InitBody
	str r4, [r5, #0x2c]
	str r6, [r5, #0x24]
	ldrb r1, [r4, #0xb]
	movs r0, #0xef
	ands r0, r1
	strb r0, [r4, #0xb]
	ldrb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	ldr r0, _080CF19C @ =FUN_080cf098
	str r0, [r5, #0x24]
	ldrb r1, [r4, #0xb]
	movs r0, #8
	orrs r0, r1
	strb r0, [r4, #0xb]
	ldr r0, _080CF1A0 @ =0x0837061C
	str r0, [r4, #0x30]
	movs r3, #0
	ldr r0, _080CF1A4 @ =0x00002001
	strh r0, [r4, #0x26]
	ldr r1, [r4, #0x54]
	ldr r2, _080CF1A8 @ =0xFFFFF800
	adds r1, r1, r2
	str r1, [r4, #0x54]
	ldr r0, [r4, #0x58]
	adds r0, r0, r2
	str r0, [r4, #0x58]
	str r1, [r4, #0x64]
	str r0, [r4, #0x68]
	strb r3, [r4, #0x13]
	adds r0, r4, #0
	bl Solid17_Update
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF190: .4byte gSolidFnTable
_080CF194: .4byte 0x08370624
_080CF198: .4byte 0x083705BC
_080CF19C: .4byte FUN_080cf098
_080CF1A0: .4byte 0x0837061C
_080CF1A4: .4byte 0x00002001
_080CF1A8: .4byte 0xFFFFF800

	thumb_func_start Solid17_Update
Solid17_Update: @ 0x080CF1AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CF1E0 @ =0x083705A4
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r1, _080CF1E4 @ =0x083705B0
	ldrb r0, [r4, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x12]
	movs r1, #0
	strb r0, [r4, #0x13]
	strb r1, [r4, #0x12]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF1E0: .4byte 0x083705A4
_080CF1E4: .4byte 0x083705B0

	thumb_func_start Solid17_Die
Solid17_Die:
	.byte 0xC2, 0x7A, 0xF7, 0x21, 0x11, 0x40, 0xC1, 0x72
	.byte 0x04, 0x4A, 0x41, 0x7A, 0x89, 0x00, 0x89, 0x18, 0x04, 0x22, 0xC2, 0x60, 0x09, 0x68, 0x09, 0x69
	.byte 0x41, 0x61, 0x70, 0x47, 0x24, 0xFB, 0x36, 0x08

	thumb_func_start nop_080cf208
nop_080cf208:
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cf20c
FUN_080cf20c: @ 0x080CF20C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CF21C
	cmp r0, #1
	beq _080CF23C
	b _080CF242
_080CF21C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080CF248 @ =0x083705D4
	bl SetDDP
	ldr r1, _080CF24C @ =0x08370604
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CF23C:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CF242:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF248: .4byte 0x083705D4
_080CF24C: .4byte 0x08370604

	thumb_func_start FUN_080cf250
FUN_080cf250: @ 0x080CF250
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CF260
	cmp r0, #1
	beq _080CF292
	b _080CF35C
_080CF260:
	ldr r1, _080CF364 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl SetMotion
	ldr r1, _080CF368 @ =0x08370628
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r4, #0x5c]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x60]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080CF292:
	ldr r5, _080CF36C @ =0x0000FFFF
	ldrh r0, [r4, #0x12]
	cmp r0, #1
	bne _080CF2C0
	ldr r1, _080CF364 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF2C0:
	ldrh r0, [r4, #0x12]
	ands r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r5, r0
	bne _080CF2F2
	ldr r1, _080CF370 @ =0x08370614
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF2F2:
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x5c]
	adds r0, r0, r1
	str r0, [r4, #0x54]
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #0x60]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl UpdateMotionGraphic
	ldr r5, _080CF374 @ =0x08370638
	ldrb r2, [r4, #0x10]
	lsls r2, r2, #3
	adds r0, r2, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	adds r1, r5, #2
	adds r2, r2, r1
	movs r1, #0
	ldrsh r2, [r2, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CF354
	ldrb r2, [r4, #0x10]
	lsls r2, r2, #3
	adds r0, r5, #4
	adds r0, r2, r0
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	adds r1, r5, #6
	adds r2, r2, r1
	movs r1, #0
	ldrsh r2, [r2, r1]
	ldr r1, [r4, #0x58]
	adds r1, r1, r2
	bl FUN_080098a4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080CF35C
_080CF354:
	movs r1, #0
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r1, [r4, #0xe]
_080CF35C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF364: .4byte 0x0837060C
_080CF368: .4byte 0x08370628
_080CF36C: .4byte 0x0000FFFF
_080CF370: .4byte 0x08370614
_080CF374: .4byte 0x08370638

	thumb_func_start FUN_080cf378
FUN_080cf378: @ 0x080CF378
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080CF388
	cmp r0, #1
	beq _080CF38C
	b _080CF414
_080CF388:
	movs r0, #1
	strb r0, [r4, #0xe]
_080CF38C:
	ldr r5, _080CF41C @ =0x0000FFFF
	ldrh r0, [r4, #0x12]
	cmp r0, #1
	bne _080CF3BA
	ldr r1, _080CF420 @ =0x0837060C
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF3BA:
	ldrh r0, [r4, #0x12]
	ands r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r5, r0
	bne _080CF3EC
	ldr r1, _080CF424 @ =0x08370614
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x71
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, #1
	movs r3, #0
	ldrsb r3, [r0, r3]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl GotoMotion
_080CF3EC:
	ldr r1, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	subs r1, r1, r0
	str r1, [r4, #0x54]
	ldr r2, [r4, #0x58]
	ldr r0, [r4, #0x60]
	subs r2, r2, r0
	str r2, [r4, #0x58]
	ldr r0, [r4, #0x64]
	cmp r1, r0
	bne _080CF40E
	ldr r0, [r4, #0x68]
	cmp r2, r0
	bne _080CF40E
	movs r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xe]
_080CF40E:
	adds r0, r4, #0
	bl UpdateMotionGraphic
_080CF414:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF41C: .4byte 0x0000FFFF
_080CF420: .4byte 0x0837060C
_080CF424: .4byte 0x08370614
