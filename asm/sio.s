	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start SIO_FUN_0800244c
SIO_FUN_0800244c: @ 0x0800244C
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _080024A4 @ =0x02000004
	ldr r2, _080024A8 @ =0x04000208
	ldrh r4, [r2]
	strh r4, [r0]
	movs r5, #0
	strh r5, [r2]
	ldr r3, _080024AC @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _080024B0 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r3]
	strh r4, [r2]
	ldr r1, _080024B4 @ =0x04000128
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080024B8 @ =0x0400010E
	strh r5, [r0]
	adds r1, #0xda
	movs r0, #0xc0
	strh r0, [r1]
	movs r4, #0
	str r4, [sp]
	ldr r1, _080024BC @ =0x02001510
	ldr r2, _080024C0 @ =0x05000266
	mov r0, sp
	bl CpuSet
	add r0, sp, #4
	strh r4, [r0]
	ldr r4, _080024C4 @ =0x020014FC
	ldr r2, _080024C8 @ =0x01000002
	adds r1, r4, #0
	bl CpuSet
	strb r5, [r4, #1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080024A4: .4byte 0x02000004
_080024A8: .4byte 0x04000208
_080024AC: .4byte 0x04000200
_080024B0: .4byte 0x0000FF3F
_080024B4: .4byte 0x04000128
_080024B8: .4byte 0x0400010E
_080024BC: .4byte 0x02001510
_080024C0: .4byte 0x05000266
_080024C4: .4byte 0x020014FC
_080024C8: .4byte 0x01000002

	thumb_func_start SIO_FUN_080024cc
SIO_FUN_080024cc: @ 0x080024CC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r6, _08002560 @ =0x02000004
	ldr r3, _08002564 @ =0x04000208
	ldrh r2, [r3]
	movs r4, #0
	strh r4, [r3]
	ldr r5, _08002568 @ =0x04000200
	ldrh r1, [r5]
	ldr r0, _0800256C @ =0x0000FF3F
	ands r0, r1
	strh r0, [r5]
	strh r2, [r3]
	ldr r0, _08002570 @ =0x04000134
	strh r4, [r0]
	ldr r2, _08002574 @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r7, _08002578 @ =0x00004003
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r2, [r3]
	strh r2, [r6]
	strh r4, [r3]
	ldrh r0, [r5]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r5]
	strh r2, [r3]
	ldr r0, _0800257C @ =0x0400012A
	strh r4, [r0]
	ldr r2, _08002580 @ =0x04000120
	movs r0, #0
	movs r1, #0
	str r0, [r2]
	str r1, [r2, #4]
	movs r5, #0
	str r5, [sp]
	ldr r1, _08002584 @ =0x02001510
	ldr r2, _08002588 @ =0x05000266
	mov r0, sp
	bl CpuSet
	add r0, sp, #4
	strh r5, [r0]
	ldr r1, _0800258C @ =0x020014FC
	ldr r2, _08002590 @ =0x01000002
	bl CpuSet
	ldr r0, _08002594 @ =0x02000006
	strb r4, [r0]
	ldr r0, _08002598 @ =0x02000007
	strb r4, [r0]
	ldr r0, _0800259C @ =0x02000008
	strb r4, [r0]
	ldr r0, _080025A0 @ =0x020014F0
	strb r4, [r0]
	ldr r0, _080025A4 @ =0x020014F8
	strb r4, [r0]
	ldr r0, _080025A8 @ =0x02000009
	strb r4, [r0]
	ldr r0, _080025AC @ =0x0200000A
	strh r5, [r0]
	ldr r0, _080025B0 @ =0x0200000C
	strh r5, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002560: .4byte 0x02000004
_08002564: .4byte 0x04000208
_08002568: .4byte 0x04000200
_0800256C: .4byte 0x0000FF3F
_08002570: .4byte 0x04000134
_08002574: .4byte 0x04000128
_08002578: .4byte 0x00004003
_0800257C: .4byte 0x0400012A
_08002580: .4byte 0x04000120
_08002584: .4byte 0x02001510
_08002588: .4byte 0x05000266
_0800258C: .4byte 0x020014FC
_08002590: .4byte 0x01000002
_08002594: .4byte 0x02000006
_08002598: .4byte 0x02000007
_0800259C: .4byte 0x02000008
_080025A0: .4byte 0x020014F0
_080025A4: .4byte 0x020014F8
_080025A8: .4byte 0x02000009
_080025AC: .4byte 0x0200000A
_080025B0: .4byte 0x0200000C

	thumb_func_start FUN_080025b4
FUN_080025b4: @ 0x080025B4
	push {lr}
	bl SIO_FUN_080024cc
	bl SIO_FUN_0800244c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080025c4
FUN_080025c4: @ 0x080025C4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _080025E0 @ =0x02001510
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _08002676
	lsls r0, r0, #2
	ldr r1, _080025E4 @ =_080025E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080025E0: .4byte 0x02001510
_080025E4: .4byte _080025E8
_080025E8: @ jump table
	.4byte _080025FC @ case 0
	.4byte _0800260C @ case 1
	.4byte _08002624 @ case 2
	.4byte _08002660 @ case 3
	.4byte _0800266A @ case 4
_080025FC:
	bl SIO_FUN_0800244c
	ldr r1, _08002608 @ =0x02001510
	movs r0, #1
	strb r0, [r1, #1]
	b _08002676
	.align 2, 0
_08002608: .4byte 0x02001510
_0800260C:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08002676
	bl SIO_FUN_080024cc
	ldr r1, _08002620 @ =0x02001510
	movs r0, #2
	strb r0, [r1, #1]
	b _08002676
	.align 2, 0
_08002620: .4byte 0x02001510
_08002624:
	ldrb r1, [r4]
	cmp r1, #1
	beq _08002634
	cmp r1, #2
	beq _0800264C
	bl FUN_080026e4
	b _08002676
_08002634:
	ldr r2, _08002648 @ =0x02001510
	ldrb r0, [r2]
	cmp r0, #0
	beq _08002676
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _08002676
	strb r1, [r2, #0x10]
	b _08002676
	.align 2, 0
_08002648: .4byte 0x02001510
_0800264C:
	ldr r0, _08002658 @ =0x02001510
	movs r1, #0
	strb r1, [r0, #1]
	ldr r0, _0800265C @ =0x0400012A
	strh r1, [r0]
	b _08002676
	.align 2, 0
_08002658: .4byte 0x02001510
_0800265C: .4byte 0x0400012A
_08002660:
	bl EnableTimer3Irq
	ldr r1, _080026B8 @ =0x02001510
	movs r0, #4
	strb r0, [r1, #1]
_0800266A:
	adds r0, r5, #0
	bl FUN_08002760
	adds r0, r6, #0
	bl FUN_08002848
_08002676:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _080026B8 @ =0x02001510
	ldrb r2, [r1, #2]
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _0800268E
	movs r0, #0x20
	orrs r2, r0
_0800268E:
	ldrb r0, [r1, #0xc]
	lsls r3, r0, #8
	ldrb r0, [r1, #0x11]
	lsls r4, r0, #9
	ldrb r0, [r1, #0x12]
	lsls r5, r0, #0x10
	ldrb r0, [r1, #0x13]
	lsls r6, r0, #0x11
	ldrb r0, [r1, #0x14]
	lsls r7, r0, #0x12
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #0x14
	mov ip, r0
	ldrb r0, [r1, #1]
	cmp r0, #4
	bne _080026BC
	movs r0, #0x40
	orrs r0, r3
	orrs r0, r2
	b _080026C0
	.align 2, 0
_080026B8: .4byte 0x02001510
_080026BC:
	adds r0, r2, #0
	orrs r0, r3
_080026C0:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	mov r2, ip
	orrs r0, r2
	adds r2, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #3
	bls _080026DA
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r2, r0
_080026DA:
	adds r0, r2, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080026e4
FUN_080026e4: @ 0x080026E4
	push {lr}
	ldr r0, _08002700 @ =0x04000128
	ldr r1, [r0]
	movs r0, #0xc
	ands r1, r0
	ldr r2, _08002704 @ =0x02001510
	cmp r1, #8
	bne _08002708
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _08002708
	strb r1, [r2]
	b _0800270C
	.align 2, 0
_08002700: .4byte 0x04000128
_08002704: .4byte 0x02001510
_08002708:
	movs r0, #0
	strb r0, [r2]
_0800270C:
	pop {r0}
	bx r0

	thumb_func_start EnableTimer3Irq
EnableTimer3Irq: @ 0x08002710
	push {r4, lr}
	ldr r0, _08002748 @ =0x02001510
	ldrb r0, [r0]
	cmp r0, #0
	beq _08002740
	ldr r1, _0800274C @ =0x0400010C
	ldr r2, _08002750 @ =0x0000FF7C
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x41
	strh r0, [r1]
	ldr r0, _08002754 @ =0x02000004
	ldr r2, _08002758 @ =0x04000208
	ldrh r4, [r2]
	strh r4, [r0]
	movs r0, #0
	strh r0, [r2]
	ldr r3, _0800275C @ =0x04000200
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3]
	strh r4, [r2]
_08002740:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002748: .4byte 0x02001510
_0800274C: .4byte 0x0400010C
_08002750: .4byte 0x0000FF7C
_08002754: .4byte 0x02000004
_08002758: .4byte 0x04000208
_0800275C: .4byte 0x04000200

	thumb_func_start FUN_08002760
FUN_08002760: @ 0x08002760
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	ldr r2, _080027D8 @ =0x02000004
	ldr r1, _080027DC @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080027E0 @ =0x02001510
	ldr r4, _080027E4 @ =0x00000211
	adds r0, r1, r4
	ldrb r4, [r0]
	mov sl, r2
	adds r6, r1, #0
	cmp r4, #0x1d
	bhi _080027F0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _080027A0
	subs r0, #0x1e
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080027A0:
	movs r2, #0
	ldr r4, _080027E8 @ =0x0200000A
	mov r8, r4
	ldr r1, _080027EC @ =0x020014F0
	mov sb, r1
	lsls r5, r0, #1
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
_080027B4:
	ldrh r0, [r4]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r4]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r5, r0
	add r0, ip
	strh r1, [r0]
	strh r7, [r3]
	adds r3, #2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _080027B4
	b _08002800
	.align 2, 0
_080027D8: .4byte 0x02000004
_080027DC: .4byte 0x04000208
_080027E0: .4byte 0x02001510
_080027E4: .4byte 0x00000211
_080027E8: .4byte 0x0200000A
_080027EC: .4byte 0x020014F0
_080027F0:
	ldrb r1, [r6, #0x14]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6, #0x14]
	ldr r1, _08002838 @ =0x0200000A
	mov r8, r1
	ldr r2, _0800283C @ =0x020014F0
	mov sb, r2
_08002800:
	mov r4, r8
	ldrh r0, [r4]
	cmp r0, #0
	beq _08002816
	ldr r1, _08002840 @ =0x00000211
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strh r2, [r4]
_08002816:
	ldr r1, _08002844 @ =0x04000208
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r4, _08002840 @ =0x00000211
	adds r0, r6, r4
	ldrb r0, [r0]
	mov r1, sb
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002838: .4byte 0x0200000A
_0800283C: .4byte 0x020014F0
_08002840: .4byte 0x00000211
_08002844: .4byte 0x04000208

	thumb_func_start FUN_08002848
FUN_08002848: @ 0x08002848
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r2, _080028A8 @ =0x02000004
	ldr r1, _080028AC @ =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080028B0 @ =0x02001510
	ldr r3, _080028B4 @ =0x00000995
	adds r0, r1, r3
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	bne _080028B8
	movs r3, #0
	mov r8, r7
	ldrb r6, [r7, #3]
_08002874:
	movs r2, #0
	adds r5, r3, #1
	cmp r2, r6
	bhs _08002898
	lsls r0, r3, #3
	mov r1, ip
	adds r3, r0, r1
	movs r4, #0
	mov r0, r8
	ldrb r1, [r0, #3]
_08002888:
	lsls r0, r2, #1
	adds r0, r0, r3
	strh r4, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r1
	blo _08002888
_08002898:
	lsls r0, r5, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _08002874
	movs r0, #1
	strb r0, [r7, #0xc]
	b _08002930
	.align 2, 0
_080028A8: .4byte 0x02000004
_080028AC: .4byte 0x04000208
_080028B0: .4byte 0x02001510
_080028B4: .4byte 0x00000995
_080028B8:
	movs r3, #0
	ldrb r1, [r7, #3]
	mov sb, r1
	movs r2, #0x85
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	mov sl, r7
_080028C8:
	movs r2, #0
	adds r5, r3, #1
	cmp r2, sb
	bhs _08002904
	lsls r0, r3, #3
	mov r1, ip
	adds r6, r0, r1
	ldr r0, _08002948 @ =0x02001EA4
	ldrb r1, [r0]
	lsls r1, r1, #1
	mov r0, sl
	ldrb r4, [r0, #3]
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r3, r1, r0
_080028E8:
	lsls r1, r2, #1
	adds r1, r1, r6
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #5
	adds r0, r3, r0
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r4
	blo _080028E8
_08002904:
	lsls r0, r5, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _080028C8
	adds r2, r7, #0
	ldr r3, _0800294C @ =0x00000995
	adds r1, r2, r3
	ldrb r0, [r1]
	subs r0, #1
	movs r3, #0
	strb r0, [r1]
	ldr r0, _08002950 @ =0x00000994
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _0800292E
	strb r3, [r2]
_0800292E:
	strb r3, [r7, #0xc]
_08002930:
	ldr r1, _08002954 @ =0x04000208
	ldr r2, _08002958 @ =0x02000004
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002948: .4byte 0x02001EA4
_0800294C: .4byte 0x00000995
_08002950: .4byte 0x00000994
_08002954: .4byte 0x04000208
_08002958: .4byte 0x02000004

	thumb_func_start FUN_0800295c
FUN_0800295c: @ 0x0800295C
	push {r4, lr}
	ldr r4, _08002984 @ =0x02001510
	ldrb r3, [r4]
	cmp r3, #0
	beq _080029C8
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08002990
	cmp r0, #4
	bne _080029F4
	ldrb r0, [r4, #0xd]
	cmp r0, #8
	bhi _08002988
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08002990
	movs r0, #1
	strb r0, [r4, #0x15]
	b _080029F4
	.align 2, 0
_08002984: .4byte 0x02001510
_08002988:
	ldrb r0, [r4, #0x15]
	cmp r0, #0
	bne _080029F4
	strb r0, [r4, #0xd]
_08002990:
	bl startSIO
	ldr r0, _080029BC @ =0x02001500
	ldrb r2, [r0]
	cmp r2, #2
	bne _080029F4
	ldr r1, _080029C0 @ =0x02000006
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _080029F4
	ldr r0, _080029C4 @ =0x02001510
	movs r1, #0
	strb r2, [r0, #0x15]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #0x11]
	b _080029F4
	.align 2, 0
_080029BC: .4byte 0x02001500
_080029C0: .4byte 0x02000006
_080029C4: .4byte 0x02001510
_080029C8:
	ldrb r2, [r4, #1]
	cmp r2, #4
	beq _080029D2
	cmp r2, #2
	bne _080029F4
_080029D2:
	ldr r1, _080029FC @ =0x02000006
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bls _080029F4
	cmp r2, #4
	bne _080029EA
	movs r0, #2
	strb r0, [r4, #0x15]
_080029EA:
	cmp r2, #2
	bne _080029F4
	strb r3, [r4, #2]
	strb r3, [r4, #3]
	strb r3, [r4, #0x11]
_080029F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080029FC: .4byte 0x02000006

	thumb_func_start sio_08002a00
sio_08002a00: @ 0x08002A00
	push {lr}
	bl disableTimer3
	bl startSIO
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sio_08002a10
sio_08002a10: @ 0x08002A10
	push {r4, lr}
	ldr r0, _08002A44 @ =0x04000128
	ldr r1, [r0]
	ldr r4, _08002A48 @ =0x02001510
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1e
	strb r0, [r4, #2]
	ldrb r0, [r4, #1]
	cmp r0, #2
	beq _08002A4C
	cmp r0, #4
	bne _08002A84
	movs r0, #0x40
	ands r1, r0
	cmp r1, #0
	beq _08002A34
	movs r0, #1
	strb r0, [r4, #0x12]
_08002A34:
	bl sio_08002cb8
	bl sio_08002e94
	bl FUN_08002f88
	b _08002A84
	.align 2, 0
_08002A44: .4byte 0x04000128
_08002A48: .4byte 0x02001510
_08002A4C:
	bl sio_08002acc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08002A6C
	ldrb r0, [r4]
	cmp r0, #0
	beq _08002A66
	movs r0, #3
	strb r0, [r4, #1]
	movs r0, #8
	strb r0, [r4, #0xd]
	b _08002A84
_08002A66:
	movs r0, #4
	strb r0, [r4, #1]
	b _08002A84
_08002A6C:
	movs r2, #0
	adds r4, #0x2a
	movs r3, #0xff
_08002A72:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08002A72
_08002A84:
	ldr r3, _08002AAC @ =0x02001510
	ldrb r0, [r3, #0xd]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #0xd]
	ldr r1, _08002AB0 @ =0x02000006
	strb r2, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08002AA4
	ldr r0, _08002AB4 @ =0x020014F8
	ldr r2, _08002AB8 @ =0x00000995
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
_08002AA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002AAC: .4byte 0x02001510
_08002AB0: .4byte 0x02000006
_08002AB4: .4byte 0x020014F8
_08002AB8: .4byte 0x00000995

	thumb_func_start startSIO
startSIO: @ 0x08002ABC
	ldr r0, _08002AC8 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08002AC8: .4byte 0x04000128

	thumb_func_start sio_08002acc
sio_08002acc: @ 0x08002ACC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
	ldr r1, _08002B00 @ =0x0000FFFF
	mov ip, r1
	ldr r0, _08002B04 @ =0x02001500
	ldrb r0, [r0]
	cmp r0, #0
	beq _08002AEC
	cmp r0, #2
	beq _08002AEC
	b _08002C5C
_08002AEC:
	ldr r0, _08002B08 @ =0x02001510
	ldrb r1, [r0, #0x10]
	cmp r1, #1
	bne _08002B24
	ldr r1, _08002B0C @ =0x0400012A
	ldr r2, _08002B10 @ =0x00008FFF
	adds r0, r2, #0
	strh r0, [r1]
	b _08002B2C
	.align 2, 0
_08002B00: .4byte 0x0000FFFF
_08002B04: .4byte 0x02001500
_08002B08: .4byte 0x02001510
_08002B0C: .4byte 0x0400012A
_08002B10: .4byte 0x00008FFF
_08002B14:
	mov r0, sb
	adds r0, #0x2a
	adds r0, r4, r0
	movs r1, #0xff
	strb r1, [r0]
	movs r7, #0
	mov sl, r7
	b _08002BF6
_08002B24:
	ldr r2, _08002BA0 @ =0x0400012A
	ldr r1, _08002BA4 @ =0x020014F4
	ldrh r0, [r1]
	strh r0, [r2]
_08002B2C:
	movs r0, #0
	ldr r1, _08002BA8 @ =0x02001510
	strb r0, [r1, #0x10]
	movs r4, #0
	adds r2, r1, #0
	adds r2, #4
	adds r5, r1, #0
	adds r5, #0x2a
	movs r3, #0xff
_08002B3E:
	adds r0, r4, r5
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _08002B3E
	ldr r0, _08002BAC @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r4, #0
	movs r7, #4
	rsbs r7, r7, #0
	mov r8, r7
	subs r0, r2, #4
	mov sb, r0
	adds r5, r2, #0
	mov r6, sb
	adds r6, #0x2a
_08002B6C:
	ldr r2, _08002BA4 @ =0x020014F4
	ldrh r1, [r2]
	mov r7, r8
	ands r1, r7
	lsls r2, r4, #1
	adds r0, r2, r5
	ldrh r3, [r0]
	adds r0, r3, #0
	ands r0, r7
	cmp r1, r0
	beq _08002B90
	adds r0, r3, #0
	ldr r1, _08002BB0 @ =0x00008FFF
	cmp r0, r1
	beq _08002B90
	ldr r7, _08002BB4 @ =0x0000FFC6
	cmp r0, r7
	bne _08002BDA
_08002B90:
	adds r0, r2, r5
	ldrh r0, [r0]
	ldr r1, _08002BB4 @ =0x0000FFC6
	cmp r0, r1
	bne _08002BB8
	adds r1, r4, r6
	movs r0, #2
	b _08002BBC
	.align 2, 0
_08002BA0: .4byte 0x0400012A
_08002BA4: .4byte 0x020014F4
_08002BA8: .4byte 0x02001510
_08002BAC: .4byte 0x04000120
_08002BB0: .4byte 0x00008FFF
_08002BB4: .4byte 0x0000FFC6
_08002BB8:
	adds r1, r4, r6
	movs r0, #1
_08002BBC:
	strb r0, [r1]
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r0, r2, r5
	ldrh r1, [r0]
	cmp ip, r1
	bls _08002BEC
	cmp r1, #0
	beq _08002BEC
	adds r0, r1, #0
	mov ip, r0
	b _08002BEC
_08002BDA:
	ldr r2, _08002C18 @ =0x0000FFFF
	cmp r0, r2
	bne _08002B14
	mov r7, sb
	ldrb r7, [r7, #2]
	cmp r4, r7
	bne _08002BEC
	movs r0, #0
	mov sl, r0
_08002BEC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _08002B6C
_08002BF6:
	mov r2, sl
	ldr r1, _08002C1C @ =0x02001510
	strb r2, [r1, #3]
	mov r0, sl
	cmp r0, #1
	bls _08002C44
	ldr r7, _08002C20 @ =0x02000008
	ldrb r7, [r7]
	cmp r0, r7
	bne _08002C28
	ldrh r1, [r1, #4]
	ldr r0, _08002C24 @ =0x00008FFF
	cmp r1, r0
	bne _08002C28
	movs r0, #1
	b _08002C98
	.align 2, 0
_08002C18: .4byte 0x0000FFFF
_08002C1C: .4byte 0x02001510
_08002C20: .4byte 0x02000008
_08002C24: .4byte 0x00008FFF
_08002C28:
	ldr r1, _08002C40 @ =0x02001510
	ldrb r0, [r1, #3]
	cmp r0, #1
	bls _08002C44
	movs r0, #3
	mov r2, ip
	ands r2, r0
	mov ip, r2
	mov r0, ip
	adds r0, #1
	strb r0, [r1, #0x11]
	b _08002C4A
	.align 2, 0
_08002C40: .4byte 0x02001510
_08002C44:
	movs r0, #0
	ldr r7, _08002C54 @ =0x02001510
	strb r0, [r7, #0x11]
_08002C4A:
	ldr r1, _08002C54 @ =0x02001510
	ldrb r0, [r1, #3]
	ldr r2, _08002C58 @ =0x02000008
	strb r0, [r2]
	b _08002C96
	.align 2, 0
_08002C54: .4byte 0x02001510
_08002C58: .4byte 0x02000008
_08002C5C:
	ldr r0, _08002C70 @ =0x02001510
	ldrb r1, [r0, #0x10]
	cmp r1, #1
	bne _08002C7C
	ldr r1, _08002C74 @ =0x0400012A
	ldr r7, _08002C78 @ =0x00008FFF
	adds r0, r7, #0
	strh r0, [r1]
	b _08002C84
	.align 2, 0
_08002C70: .4byte 0x02001510
_08002C74: .4byte 0x0400012A
_08002C78: .4byte 0x00008FFF
_08002C7C:
	ldr r0, _08002CA8 @ =0x0400012A
	ldr r1, _08002CAC @ =0x020014F4
	ldrh r1, [r1]
	strh r1, [r0]
_08002C84:
	movs r0, #0
	ldr r1, _08002CB0 @ =0x02001510
	strb r0, [r1, #0x10]
	ldr r0, _08002CB4 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, _08002CB0 @ =0x02001510
	str r0, [r2, #4]
	str r1, [r2, #8]
_08002C96:
	movs r0, #0
_08002C98:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08002CA8: .4byte 0x0400012A
_08002CAC: .4byte 0x020014F4
_08002CB0: .4byte 0x02001510
_08002CB4: .4byte 0x04000120

	thumb_func_start sio_08002cb8
sio_08002cb8: @ 0x08002CB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08002D34 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	movs r4, #0
	ldr r5, _08002D38 @ =0x02001539
_08002CD0:
	lsls r0, r4, #1
	add r0, sp
	ldrh r0, [r0]
	ldrb r2, [r5]
	adds r1, r4, #0
	bl FUN_08000eac
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _08002CD0
	ldr r0, _08002D3C @ =0x02001510
	adds r6, r0, #0
	adds r0, #0x28
	ldrb r0, [r0]
	adds r3, r6, #0
	cmp r0, #0
	bne _08002D78
	movs r4, #0
	ldr r0, _08002D40 @ =0x02000009
	mov sb, r0
	ldrb r1, [r3, #3]
	cmp r4, r1
	bhs _08002D6C
	adds r5, r3, #0
	ldr r2, _08002D44 @ =0x0000FFC6
	mov r8, r2
	movs r7, #0x20
	adds r7, r7, r3
	mov ip, r7
_08002D0E:
	adds r0, r5, #0
	adds r0, #0x2a
	adds r0, r4, r0
	ldrb r2, [r0]
	cmp r2, #1
	bne _08002D48
	lsls r0, r4, #1
	mov r7, sp
	adds r1, r7, r0
	ldrh r0, [r6, #0x16]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08002D5E
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq _08002D5E
	strb r2, [r5, #0x13]
	b _08002D5E
	.align 2, 0
_08002D34: .4byte 0x04000120
_08002D38: .4byte 0x02001539
_08002D3C: .4byte 0x02001510
_08002D40: .4byte 0x02000009
_08002D44: .4byte 0x0000FFC6
_08002D48:
	cmp r2, #2
	bne _08002D5E
	lsls r1, r4, #1
	mov r2, sp
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, r8
	bne _08002D5E
	add r1, ip
	movs r0, #0
	strh r0, [r1]
_08002D5E:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r3, #0
	ldrb r7, [r3, #3]
	cmp r4, r7
	blo _08002D0E
_08002D6C:
	movs r0, #0
	strh r0, [r3, #0x16]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
	b _08002E7C
_08002D78:
	ldr r2, _08002DEC @ =0x00000994
	adds r1, r3, r2
	ldr r7, _08002DF0 @ =0x00000995
	adds r0, r3, r7
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r0, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _08002D94
	subs r0, #0x1e
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08002D94:
	cmp r2, #0x1d
	bhi _08002E4C
	movs r4, #0
	ldrb r1, [r3, #3]
	cmp r4, r1
	bhs _08002E54
	mov ip, r3
	lsls r7, r0, #1
	movs r2, #0x85
	lsls r2, r2, #2
	adds r2, r2, r3
	mov r8, r2
	ldr r6, _08002DF4 @ =0x0200000C
	adds r5, r3, #0
	adds r5, #0x20
_08002DB2:
	mov r0, ip
	adds r0, #0x2a
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #1
	bne _08002DF8
	lsls r0, r4, #1
	add r0, sp
	ldrh r2, [r0]
	ldrh r1, [r3, #0x16]
	adds r0, r2, r1
	strh r0, [r3, #0x16]
	ldrh r0, [r6]
	orrs r0, r2
	strh r0, [r6]
	adds r0, r3, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r7, r1
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #5
	adds r1, r1, r0
	add r1, r8
	strh r2, [r1]
	b _08002E3C
	.align 2, 0
_08002DEC: .4byte 0x00000994
_08002DF0: .4byte 0x00000995
_08002DF4: .4byte 0x0200000C
_08002DF8:
	cmp r0, #2
	bne _08002E3C
	mov r0, ip
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #4
	bne _08002E14
	lsls r0, r4, #1
	mov r1, ip
	adds r1, #0x18
	adds r1, r0, r1
	add r0, sp
	ldrh r0, [r0]
	b _08002E3A
_08002E14:
	cmp r0, #3
	bne _08002E2A
	lsls r1, r4, #1
	adds r2, r1, r5
	ldrh r0, [r2]
	add r1, sp
	adds r0, #1
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	b _08002E3C
_08002E2A:
	cmp r0, #5
	bne _08002E3C
	lsls r0, r4, #1
	adds r1, r0, r5
	add r0, sp
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
_08002E3A:
	strh r0, [r1]
_08002E3C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, ip
	ldrb r0, [r0, #3]
	cmp r4, r0
	blo _08002DB2
	b _08002E54
_08002E4C:
	ldrb r1, [r3, #0x14]
	movs r0, #2
	orrs r0, r1
	strb r0, [r3, #0x14]
_08002E54:
	adds r1, r3, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08002E7C
	ldr r2, _08002E8C @ =0x0200000C
	ldrh r0, [r2]
	cmp r0, #0
	beq _08002E7C
	ldr r1, _08002E90 @ =0x00000995
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_08002E7C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002E8C: .4byte 0x0200000C
_08002E90: .4byte 0x00000995

	thumb_func_start sio_08002e94
sio_08002e94: @ 0x08002E94
	push {lr}
	ldr r1, _08002ED8 @ =0x02001510
	adds r0, r1, #0
	adds r0, #0x28
	ldrb r0, [r0]
	mov ip, r1
	cmp r0, #8
	bne _08002EEC
	ldr r1, _08002EDC @ =0x0400012A
	mov r2, ip
	ldrh r0, [r2, #0x16]
	strh r0, [r1]
	ldr r1, _08002EE0 @ =0x02000007
	ldrb r2, [r1]
	cmp r2, #0
	bne _08002EE8
	ldr r1, _08002EE4 @ =0x00000211
	add r1, ip
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, ip
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1d
	bls _08002F4A
	strb r2, [r1]
	b _08002F4A
	.align 2, 0
_08002ED8: .4byte 0x02001510
_08002EDC: .4byte 0x0400012A
_08002EE0: .4byte 0x02000007
_08002EE4: .4byte 0x00000211
_08002EE8:
	movs r0, #0
	b _08002F48
_08002EEC:
	ldr r1, _08002F10 @ =0x02000007
	cmp r0, #0
	bne _08002F00
	ldr r0, _08002F14 @ =0x00000211
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #0
	bne _08002F00
	movs r0, #1
	strb r0, [r1]
_08002F00:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08002F1C
	ldr r1, _08002F18 @ =0x0400012A
	movs r0, #0
	strh r0, [r1]
	b _08002F40
	.align 2, 0
_08002F10: .4byte 0x02000007
_08002F14: .4byte 0x00000211
_08002F18: .4byte 0x0400012A
_08002F1C:
	ldr r3, _08002F50 @ =0x0400012A
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, ip
	ldrb r1, [r0]
	lsls r1, r1, #1
	mov r0, ip
	adds r0, #0x28
	ldrb r2, [r0]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	mov r0, ip
	adds r0, #0x30
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r3]
_08002F40:
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
_08002F48:
	strb r0, [r1]
_08002F4A:
	pop {r0}
	bx r0
	.align 2, 0
_08002F50: .4byte 0x0400012A

	thumb_func_start disableTimer3
disableTimer3: @ 0x08002F54
	push {lr}
	ldr r0, _08002F74 @ =0x02001510
	ldrb r0, [r0]
	cmp r0, #0
	beq _08002F70
	ldr r2, _08002F78 @ =0x0400010E
	ldrh r1, [r2]
	ldr r0, _08002F7C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08002F80 @ =0x0400010C
	ldr r2, _08002F84 @ =0x0000FF7C
	adds r0, r2, #0
	strh r0, [r1]
_08002F70:
	pop {r0}
	bx r0
	.align 2, 0
_08002F74: .4byte 0x02001510
_08002F78: .4byte 0x0400010E
_08002F7C: .4byte 0x0000FF7F
_08002F80: .4byte 0x0400010C
_08002F84: .4byte 0x0000FF7C

	thumb_func_start FUN_08002f88
FUN_08002f88: @ 0x08002F88
	push {lr}
	ldr r1, _08002FA0 @ =0x02001510
	adds r2, r1, #0
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #8
	bne _08002FA4
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
	b _08002FB4
	.align 2, 0
_08002FA0: .4byte 0x02001510
_08002FA4:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08002FB4
	ldr r0, _08002FB8 @ =0x0400010E
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
_08002FB4:
	pop {r0}
	bx r0
	.align 2, 0
_08002FB8: .4byte 0x0400010E

	thumb_func_start FUN_08002fbc
FUN_08002fbc: @ 0x08002FBC
	push {r4, r5, lr}
	ldr r1, _08003000 @ =0x02001510
	ldr r2, _08003004 @ =0x00000211
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	movs r3, #0x84
	lsls r3, r3, #2
	adds r0, r1, r3
	strb r2, [r0]
	adds r5, r1, #0
	adds r5, #0x30
	ldr r4, _08003008 @ =0x0000EFFF
_08002FD6:
	movs r3, #0
	lsls r0, r2, #4
	adds r1, r2, #1
	subs r0, r0, r2
	lsls r2, r0, #2
_08002FE0:
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r0, r0, r5
	strh r4, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x1d
	bls _08002FE0
	lsls r0, r1, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _08002FD6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08003000: .4byte 0x02001510
_08003004: .4byte 0x00000211
_08003008: .4byte 0x0000EFFF

	thumb_func_start FUN_0800300c
FUN_0800300c: @ 0x0800300C
	push {r4, r5, r6, r7, lr}
	ldr r1, _08003068 @ =0x02001510
	ldr r2, _0800306C @ =0x00000995
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08003070 @ =0x00000994
	adds r0, r1, r3
	strb r2, [r0]
	movs r3, #0
	movs r0, #0x85
	lsls r0, r0, #2
	adds r7, r1, r0
	ldr r6, _08003074 @ =0x0000EFFF
_08003028:
	movs r2, #0
	lsls r0, r3, #4
	adds r5, r3, #1
	subs r0, r0, r3
	lsls r4, r0, #5
_08003032:
	movs r3, #0
	lsls r0, r2, #4
	adds r1, r2, #1
	subs r0, r0, r2
	lsls r2, r0, #2
_0800303C:
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, r0, r7
	strh r6, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x1d
	bls _0800303C
	lsls r0, r1, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _08003032
	lsls r0, r5, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08003028
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08003068: .4byte 0x02001510
_0800306C: .4byte 0x00000995
_08003070: .4byte 0x00000994
_08003074: .4byte 0x0000EFFF

	thumb_func_start get0x02001511
get0x02001511: @ 0x08003078
	ldr r0, _08003080 @ =0x02001510
	ldrb r0, [r0, #1]
	bx lr
	.align 2, 0
_08003080: .4byte 0x02001510

	thumb_func_start get0x02001539
get0x02001539: @ 0x08003084
	ldr r0, _0800308C @ =0x02001510
	adds r0, #0x29
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0800308C: .4byte 0x02001510

	thumb_func_start set0x02001500
set0x02001500: @ 0x08003090
	ldr r1, _08003098 @ =0x02001500
	strb r0, [r1]
	bx lr
	.align 2, 0
_08003098: .4byte 0x02001500

	thumb_func_start FUN_0800309c
FUN_0800309c: @ 0x0800309C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080030AC @ =0x02001510
	adds r1, #0x2a
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080030AC: .4byte 0x02001510

	thumb_func_start Load0x020014f0
Load0x020014f0: @ 0x080030B0
	ldr r0, _080030B8 @ =0x020014F0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080030B8: .4byte 0x020014F0

	thumb_func_start Load0x020014f8
Load0x020014f8: @ 0x080030BC
	ldr r0, _080030C4 @ =0x020014F8
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080030C4: .4byte 0x020014F8

	thumb_func_start FUN_080030c8
FUN_080030c8: @ 0x080030C8
	push {lr}
	ldr r0, _080030E0 @ =0x020014F0
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080030E8
	ldr r0, _080030E4 @ =0x020014F8
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080030E8
	movs r0, #0
	b _080030EA
	.align 2, 0
_080030E0: .4byte 0x020014F0
_080030E4: .4byte 0x020014F8
_080030E8:
	movs r0, #1
_080030EA:
	pop {r1}
	bx r1
	.align 2, 0
