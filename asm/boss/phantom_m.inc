	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08060410
FUN_08060410: @ 0x08060410
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _0806044A
	cmp r0, #1
	bgt _08060424
	cmp r0, #0
	beq _0806042E
	b _080604D2
_08060424:
	cmp r0, #2
	beq _0806045C
	cmp r0, #3
	beq _08060494
	b _080604D2
_0806042E:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08060458 @ =sCollisions+(6*24)
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_0806044A:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080604D2
	b _0806047E
	.align 2, 0
_08060458: .4byte sCollisions+(6*24)
_0806045C:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08060488 @ =sCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	ldr r1, _0806048C @ =0xFFFFB000
	adds r0, r0, r1
	str r0, [r4, #0x58]
	ldr r1, _08060490 @ =0x0000BC17
	adds r0, r4, #0
	bl SetMotion
_0806047E:
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _080604D2
	.align 2, 0
_08060488: .4byte sCollisions
_0806048C: .4byte 0xFFFFB000
_08060490: .4byte 0x0000BC17
_08060494:
	ldr r0, [r4, #0x70]
	ldr r1, _080604D8 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _080604DC @ =0x00010500
	cmp r0, r1
	bne _080604BE
	movs r0, #0xfc
	bl PlaySound
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809142c
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0809142c
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809142c
_080604BE:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _080604D2
	movs r0, #0
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_080604D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080604D8: .4byte 0x00FFFF00
_080604DC: .4byte 0x00010500

	thumb_func_start FUN_080604e0
FUN_080604e0: @ 0x080604E0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xf]
	cmp r0, #1
	beq _08060514
	cmp r0, #1
	bgt _080604F4
	cmp r0, #0
	beq _080604FE
	b _08060556
_080604F4:
	cmp r0, #2
	beq _08060524
	cmp r0, #3
	beq _08060540
	b _08060556
_080604FE:
	ldr r1, _08060510 @ =0x0000BC18
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08060556
	.align 2, 0
_08060510: .4byte 0x0000BC18
_08060514:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060556
	movs r0, #2
	strb r0, [r4, #0xf]
	b _08060556
_08060524:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _0806055C @ =sCollisions+(6*24)
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0x18
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
_08060540:
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08060556
	strb r0, [r4, #0xf]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08060556:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806055C: .4byte sCollisions+(6*24)

	thumb_func_start FUN_08060560
FUN_08060560: @ 0x08060560
	push {r4, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #0xf]
	cmp r1, #0
	beq _08060570
	cmp r1, #1
	beq _08060638
	b _08060648
_08060570:
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _080605AC @ =sCollisions
	bl SetDDP
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	ldr r0, [r4, #0x58]
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r0, r1
	str r0, [r4, #0x58]
	adds r0, r4, #0
	adds r0, #0xe0
	ldr r1, [r4, #0x54]
	ldr r0, [r0]
	cmp r1, r0
	bge _080605B4
	ldr r0, _080605B0 @ =0xFFFFC000
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r0, [r0]
	cmp r2, r0
	bge _080605D0
	movs r2, #0x80
	lsls r2, r2, #7
	b _080605C6
	.align 2, 0
_080605AC: .4byte sCollisions
_080605B0: .4byte 0xFFFFC000
_080605B4:
	movs r0, #0x80
	lsls r0, r0, #7
	adds r2, r1, r0
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r0, [r0]
	cmp r2, r0
	ble _080605D0
	ldr r2, _080605CC @ =0xFFFFC000
_080605C6:
	adds r0, r1, r2
	str r0, [r4, #0x54]
	b _080605D2
	.align 2, 0
_080605CC: .4byte 0xFFFFC000
_080605D0:
	str r2, [r4, #0x54]
_080605D2:
	movs r3, #0
	ldr r0, _08060618 @ =pZero2
	ldr r2, [r0]
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _080605E2
	movs r3, #1
_080605E2:
	adds r0, r4, #0
	adds r0, #0x4c
	strb r3, [r0]
	movs r3, #0
	ldr r1, [r4, #0x54]
	ldr r0, [r2, #0x54]
	cmp r1, r0
	bge _080605F4
	movs r3, #1
_080605F4:
	movs r0, #0x4a
	adds r0, r0, r4
	mov ip, r0
	lsls r2, r3, #4
	ldrb r1, [r0]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	mov r1, ip
	strb r0, [r1]
	cmp r3, #0
	beq _0806061C
	ldrb r0, [r4, #0xa]
	movs r1, #0x10
	orrs r0, r1
	b _08060622
	.align 2, 0
_08060618: .4byte pZero2
_0806061C:
	ldrb r1, [r4, #0xa]
	movs r0, #0xef
	ands r0, r1
_08060622:
	strb r0, [r4, #0xa]
	ldr r1, _08060634 @ =0x0000BC19
	adds r0, r4, #0
	bl SetMotion
	ldrb r0, [r4, #0xf]
	adds r0, #1
	strb r0, [r4, #0xf]
	b _08060648
	.align 2, 0
_08060634: .4byte 0x0000BC19
_08060638:
	adds r0, r4, #0
	adds r0, #0x73
	ldrb r0, [r0]
	cmp r0, #3
	bne _08060648
	movs r0, #0
	strb r1, [r4, #0xd]
	strh r0, [r4, #0xe]
_08060648:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
