	.include "asm/macros.inc"

	.syntax unified
	
	.text
	
	thumb_func_start umul3232H32
umul3232H32: @ 0x080FC44C
	add r2, pc, #0x0 @ =sub_080FC450
	bx r2

	arm_func_start sub_080FC450
sub_080FC450: @ 0x080FC450
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr

	thumb_func_start SoundMain
SoundMain: @ 0x080FC45C
	ldr r0, _080FC4C8 @ =0x03007FF0
	ldr r0, [r0]
	ldr r2, _080FC4CC @ =0x68736D53
	ldr r3, [r0]
	cmp r2, r3
	beq _080FC46A
	bx lr
_080FC46A:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq _080FC48E
	ldr r2, _080FC4D4 @ =0x04000006
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs _080FC48C
	adds r2, #0xe4
_080FC48C:
	adds r1, r1, r2
_080FC48E:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq _080FC49E
	ldr r0, [r0, #0x24]
	bl m4a_bxR3
	ldr r0, [sp, #0x18]
_080FC49E:
	ldr r3, [r0, #0x28]
	bl m4a_bxR3
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, _080FC4D8 @ =0x00000350
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls _080FC4BE
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
_080FC4BE:
	str r5, [sp, #8]
	ldr r6, _080FC4DC @ =0x00000630
	ldr r3, _080FC4D0 @ =0x03000001
	bx r3
	.align 2, 0
_080FC4C8: .4byte 0x03007FF0
_080FC4CC: .4byte 0x68736D53
_080FC4D0: .4byte 0x03000001
_080FC4D4: .4byte 0x04000006
_080FC4D8: .4byte 0x00000350
_080FC4DC: .4byte 0x00000630

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x080FC4E0
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq sub_080FC52C
	add r1, pc, #0x4 @ =sub_080FC4EC
	bx r1
	.align 2, 0

	arm_func_start sub_080FC4EC
sub_080FC4EC: @ 0x080FC4EC
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
_080FC4FC:
	ldrsb r0, [r5]
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #8
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt _080FC4FC
	add r0, pc, #0x1F @ =sub_080FC54A
	bx r0

	thumb_func_start sub_080FC52C
sub_080FC52C: @ 0x080FC52C
	movs r0, #0
	mov r1, r8
	lsrs r1, r1, #3
	blo _080FC536
	stm r5!, {r0}
_080FC536:
	lsrs r1, r1, #1
	blo _080FC53E
	stm r5!, {r0}
	stm r5!, {r0}
_080FC53E:
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	stm r5!, {r0}
	subs r1, #1
	bgt _080FC53E

	non_word_aligned_thumb_func_start sub_080FC54A
sub_080FC54A: @ 0x080FC54A
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
_080FC554:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _080FC574
	ldr r1, _080FC570 @ =0x04000006
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs _080FC568
	adds r1, #0xe4
_080FC568:
	cmp r1, r0
	blo _080FC574
	b _080FC7F6
	.align 2, 0
_080FC570: .4byte 0x04000006
_080FC574:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne _080FC57E
	b sub_080FC7EC
_080FC57E:
	movs r0, #0x80
	tst r0, r6
	beq _080FC5AE
	movs r0, #0x40
	tst r0, r6
	bne _080FC5BE
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq _080FC606
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b _080FC606
_080FC5AE:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq _080FC5C4
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi _080FC614
_080FC5BE:
	movs r0, #0
	strb r0, [r4]
	b sub_080FC7EC
_080FC5C4:
	movs r0, #0x40
	tst r0, r6
	beq _080FC5E4
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi _080FC614
_080FC5D6:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq _080FC5BE
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b _080FC614
_080FC5E4:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne _080FC602
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi _080FC614
	adds r5, r0, #0
	beq _080FC5D6
	subs r6, #1
	strb r6, [r4]
	b _080FC614
_080FC602:
	cmp r2, #3
	bne _080FC614
_080FC606:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo _080FC614
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
_080FC614:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	ldrb r1, [r4, #3]
	adds r0, r0, r1
	muls r0, r5, r0
	lsrs r0, r0, #9
	strb r0, [r4, #0xa]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq _080FC644
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
_080FC644:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #0x4 @ =sub_080FC650
	bx r0
	.align 2, 0

	arm_func_start sub_080FC650
sub_080FC650: @ 0x080FC650
	str r8, [sp]
	ldrb sl, [r4, #0xa]
	lsl sl, sl, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq _080FC758
_080FC668:
	cmp r2, #4
	ble _080FC6C4
	subs r2, r2, r8
	movgt lr, #0
	bgt _080FC694
	mov lr, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub lr, lr, r8
	ands r2, r2, #3
	moveq r2, #4
_080FC694:
	ldr r6, [r5]
_080FC698:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	adds r5, r5, #0x40000000
	blo _080FC698
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _080FC694
	adds r8, r8, lr
	beq _080FC7D8
_080FC6C4:
	ldr r6, [r5]
_080FC6C8:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	subs r2, r2, #1
	beq _080FC728
_080FC6E0:
	adds r5, r5, #0x40000000
	blo _080FC6C8
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _080FC668
	b _080FC7D8
_080FC6F8:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _080FC71C
	ldr r3, [sp, #0x14]
	rsb sb, r2, #0
_080FC70C:
	adds r2, r0, r2
	bgt _080FC7AC
	sub sb, sb, r0
	b _080FC70C
_080FC71C:
	pop {r4, ip}
	mov r2, #0
	b _080FC738
_080FC728:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne _080FC6E0
_080FC738:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	str r6, [r5], #4
	b _080FC7E0
_080FC758:
	push {r4, ip}
	ldr lr, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_080FC774:
	ldr r6, [r5]
_080FC778:
	mul sb, lr, r1
	add sb, r0, sb, asr #23
	mul ip, sl, sb
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	add lr, lr, r4
	lsrs sb, lr, #0x17
	beq _080FC7B8
	bic lr, lr, #0x3f800000
	subs r2, r2, sb
	ble _080FC6F8
	subs sb, sb, #1
	addeq r0, r0, r1
_080FC7AC:
	ldrsbne r0, [r3, sb]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_080FC7B8:
	adds r5, r5, #0x40000000
	blo _080FC778
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _080FC774
	sub r3, r3, #1
	pop {r4, ip}
	str lr, [r4, #0x1c]
_080FC7D8:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
_080FC7E0:
	ldr r8, [sp]
	add r0, pc, #0x1 @ =sub_080FC7EC
	bx r0

	thumb_func_start sub_080FC7EC
sub_080FC7EC: @ 0x080FC7EC
	ldr r0, [sp, #4]
	subs r0, #1
	ble _080FC7F6
	adds r4, #0x40
	b _080FC554
_080FC7F6:
	ldr r0, [sp, #0x18]
	ldr r3, _080FC80C @ =0x68736D53
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	non_word_aligned_thumb_func_start m4a_bxR3
m4a_bxR3: @ 0x080FC80A
	bx r3
	.align 2, 0
_080FC80C: .4byte 0x68736D53

	thumb_func_start SoundMainBTM
SoundMainBTM: @ 0x080FC810
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.align 2, 0

	thumb_func_start RealClearChain
RealClearChain: @ 0x080FC828
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq _080FC846
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x30]
	cmp r2, #0
	beq _080FC83A
	str r1, [r2, #0x34]
	b _080FC83C
_080FC83A:
	str r1, [r3, #0x20]
_080FC83C:
	cmp r1, #0
	beq _080FC842
	str r2, [r1, #0x30]
_080FC842:
	movs r1, #0
	str r1, [r0, #0x2c]
_080FC846:
	bx lr
_080FC848:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _080FC86C
_080FC852:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080FC860
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
_080FC860:
	adds r0, r4, #0
	bl RealClearChain
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _080FC852
_080FC86C:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x080FC878
	mov ip, lr
	movs r1, #0x24
	ldr r2, _080FC8A8 @ =0x0810E2CC
_080FC87E:
	ldr r3, [r2]
	bl _080FC892
	stm r0!, {r3}
	adds r2, #4
	subs r1, #1
	bgt _080FC87E
	bx ip
	.align 2, 0

	thumb_func_start FUN_080fc890
FUN_080fc890: @ 0x080FC890
	ldrb r3, [r2]
_080FC892:
	push {r0}
	lsrs r0, r2, #0x19
	bne _080FC8A4
	ldr r0, _080FC8A8 @ =0x0810E2CC
	cmp r2, r0
	blo _080FC8A2
	lsrs r0, r2, #0xe
	beq _080FC8A4
_080FC8A2:
	movs r3, #0
_080FC8A4:
	pop {r0}
	bx lr
	.align 2, 0
_080FC8A8: .4byte 0x0810E2CC

	thumb_func_start FUN_080fc8ac
FUN_080fc8ac: @ 0x080FC8AC
	ldr r2, [r1, #0x40]

	non_word_aligned_thumb_func_start FUN_080fc8ae
FUN_080fc8ae: @ 0x080FC8AE
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	b _080FC892
	.align 2, 0
_080FC8B8:
	push {lr}
_080FC8BA:
	ldr r2, [r1, #0x40]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldrb r3, [r2, #2]
	orrs r0, r3
	lsls r0, r0, #8
	ldrb r3, [r2, #1]
	orrs r0, r3
	lsls r0, r0, #8
	bl FUN_080fc890
	orrs r0, r3
	str r0, [r1, #0x40]
	pop {r0}
	bx r0

	thumb_func_start ply_patt
ply_patt: @ 0x080FC8D8
	ldrb r2, [r1, #2]
	cmp r2, #3
	bhs _080FC8F0
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r1, #0x40]
	adds r2, #4
	str r2, [r3, #0x44]
	ldrb r2, [r1, #2]
	adds r2, #1
	strb r2, [r1, #2]
	b _080FC8B8
_080FC8F0:
	b _080FC848
	.align 2, 0

	thumb_func_start ply_pend
ply_pend: @ 0x080FC8F4
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _080FC906
	subs r2, #1
	strb r2, [r1, #2]
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r3, #0x44]
	str r2, [r1, #0x40]
_080FC906:
	bx lr

	thumb_func_start ply_rept
ply_rept: @ 0x080FC908
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0
	bne _080FC918
	adds r2, #1
	str r2, [r1, #0x40]
	b _080FC8BA
_080FC918:
	ldrb r3, [r1, #3]
	adds r3, #1
	strb r3, [r1, #3]
	mov ip, r3
	bl FUN_080fc8ac
	cmp ip, r3
	bhs _080FC92A
	b _080FC8BA
_080FC92A:
	movs r3, #0
	strb r3, [r1, #3]
	adds r2, #5
	str r2, [r1, #0x40]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ply_prio
ply_prio: @ 0x080FC938
	mov ip, lr
	bl FUN_080fc8ac
	strb r3, [r1, #0x1d]
	bx ip
	.align 2, 0

	thumb_func_start ply_tempo
ply_tempo: @ 0x080FC944
	mov ip, lr
	bl FUN_080fc8ac
	lsls r3, r3, #1
	strh r3, [r0, #0x1c]
	ldrh r2, [r0, #0x1e]
	muls r3, r2, r3
	lsrs r3, r3, #8
	strh r3, [r0, #0x20]
	bx ip

	thumb_func_start ply_keysh
ply_keysh: @ 0x080FC958
	mov ip, lr
	bl FUN_080fc8ac
	strb r3, [r1, #0xa]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_voice
ply_voice: @ 0x080FC96C
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r3, [r0, #0x30]
	adds r2, r2, r3
	ldr r3, [r2]
	bl _080FC892
	str r3, [r1, #0x24]
	ldr r3, [r2, #4]
	bl _080FC892
	str r3, [r1, #0x28]
	ldr r3, [r2, #8]
	bl _080FC892
	str r3, [r1, #0x2c]
	bx ip
	.align 2, 0

	thumb_func_start ply_vol
ply_vol: @ 0x080FC99C
	mov ip, lr
	bl FUN_080fc8ac
	strb r3, [r1, #0x12]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_pan
ply_pan: @ 0x080FC9B0
	mov ip, lr
	bl FUN_080fc8ac
	subs r3, #0x40
	strb r3, [r1, #0x14]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bend
ply_bend: @ 0x080FC9C4
	mov ip, lr
	bl FUN_080fc8ac
	subs r3, #0x40
	strb r3, [r1, #0xe]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_bendr
ply_bendr: @ 0x080FC9D8
	mov ip, lr
	bl FUN_080fc8ac
	strb r3, [r1, #0xf]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0

	thumb_func_start ply_lfodl
ply_lfodl: @ 0x080FC9EC
	mov ip, lr
	bl FUN_080fc8ac
	strb r3, [r1, #0x1b]
	bx ip
	.align 2, 0

	thumb_func_start ply_modt
ply_modt: @ 0x080FC9F8
	mov ip, lr
	bl FUN_080fc8ac
	ldrb r0, [r1, #0x18]
	cmp r0, r3
	beq _080FCA0E
	strb r3, [r1, #0x18]
	ldrb r3, [r1]
	movs r2, #0xf
	orrs r3, r2
	strb r3, [r1]
_080FCA0E:
	bx ip

	thumb_func_start ply_tune
ply_tune: @ 0x080FCA10
	mov ip, lr
	bl FUN_080fc8ac
	subs r3, #0x40
	strb r3, [r1, #0xc]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip

	thumb_func_start ply_port
ply_port: @ 0x080FCA24
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	ldr r0, _080FCA38 @ =0x04000060
	adds r0, r0, r3
	bl FUN_080fc8ae
	strb r3, [r0]
	bx ip
	.align 2, 0
_080FCA38: .4byte 0x04000060

	thumb_func_start m4aSoundVSync
m4aSoundVSync: @ 0x080FCA3C
	ldr r0, _080FCCD8 @ =0x03007FF0
	ldr r0, [r0]
	ldr r2, _080FCCDC @ =0x68736D53
	ldr r3, [r0]
	subs r3, r3, r2
	cmp r3, #1
	bhi _080FCA6E
	ldrb r1, [r0, #4]
	subs r1, #1
	strb r1, [r0, #4]
	bgt _080FCA6E
	ldrb r1, [r0, #0xb]
	strb r1, [r0, #4]
	ldr r2, _080FCA70 @ =0x040000BC
	ldr r1, [r2, #8]
	lsls r1, r1, #7
	blo _080FCA62
	ldr r1, _080FCA74 @ =0x84400004
	str r1, [r2, #8]
_080FCA62:
	movs r1, #4
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
	movs r1, #0xb6
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
_080FCA6E:
	bx lr
	.align 2, 0
_080FCA70: .4byte 0x040000BC
_080FCA74: .4byte 0x84400004

	thumb_func_start MPlayMain
MPlayMain: @ 0x080FCA78
	ldr r2, _080FCCDC @ =0x68736D53
	ldr r3, [r0, #0x34]
	cmp r2, r3
	beq _080FCA82
	bx lr
_080FCA82:
	adds r3, #1
	str r3, [r0, #0x34]
	push {r0, lr}
	ldr r3, [r0, #0x38]
	cmp r3, #0
	beq _080FCA94
	ldr r0, [r0, #0x3c]
	bl call_r3
_080FCA94:
	pop {r0}
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _080FCAAC
	b _080FCCC0
_080FCAAC:
	ldr r0, _080FCCD8 @ =0x03007FF0
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, #0
	bl FadeOutBody
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _080FCAC0
	b _080FCCC0
_080FCAC0:
	ldrh r0, [r7, #0x22]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	b _080FCC10
_080FCAC8:
	ldrb r6, [r7, #8]
	ldr r5, [r7, #0x2c]
	movs r3, #1
	movs r4, #0
_080FCAD0:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	bne _080FCADA
	b _080FCBEC
_080FCADA:
	mov sl, r3
	orrs r4, r3
	mov fp, r4
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _080FCB0E
_080FCAE6:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080FCB02
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _080FCB08
	subs r0, #1
	strb r0, [r4, #0x10]
	bne _080FCB08
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
	b _080FCB08
_080FCB02:
	adds r0, r4, #0
	bl ClearChain
_080FCB08:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _080FCAE6
_080FCB0E:
	ldrb r3, [r5]
	movs r0, #0x40
	tst r0, r3
	beq _080FCB8C
	adds r0, r5, #0
	bl Clear64byte
	movs r0, #0x80
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x19]
	movs r0, #1
	adds r1, r5, #6
	strb r0, [r1, #0x1e]
	b _080FCB8C
_080FCB34:
	ldr r2, [r5, #0x40]
	ldrb r1, [r2]
	cmp r1, #0x80
	bhs _080FCB40
	ldrb r1, [r5, #7]
	b _080FCB4A
_080FCB40:
	adds r2, #1
	str r2, [r5, #0x40]
	cmp r1, #0xbd
	blo _080FCB4A
	strb r1, [r5, #7]
_080FCB4A:
	cmp r1, #0xcf
	blo _080FCB60
	mov r0, r8
	ldr r3, [r0, #0x38]
	adds r0, r1, #0
	subs r0, #0xcf
	adds r1, r7, #0
	adds r2, r5, #0
	bl call_r3
	b _080FCB8C
_080FCB60:
	cmp r1, #0xb0
	bls _080FCB82
	adds r0, r1, #0
	subs r0, #0xb1
	strb r0, [r7, #0xa]
	mov r3, r8
	ldr r3, [r3, #0x34]
	lsls r0, r0, #2
	ldr r3, [r3, r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl call_r3
	ldrb r0, [r5]
	cmp r0, #0
	beq _080FCBE8
	b _080FCB8C
_080FCB82:
	ldr r0, _080FCCD4 @ =0x0810E540
	subs r1, #0x80
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r5, #1]
_080FCB8C:
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080FCB34
	subs r0, #1
	strb r0, [r5, #1]
	ldrb r1, [r5, #0x19]
	cmp r1, #0
	beq _080FCBE8
	ldrb r0, [r5, #0x17]
	cmp r0, #0
	beq _080FCBE8
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _080FCBAE
	subs r0, #1
	strb r0, [r5, #0x1c]
	b _080FCBE8
_080FCBAE:
	ldrb r0, [r5, #0x1a]
	adds r0, r0, r1
	strb r0, [r5, #0x1a]
	adds r1, r0, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	bpl _080FCBC2
	lsls r2, r1, #0x18
	asrs r2, r2, #0x18
	b _080FCBC6
_080FCBC2:
	movs r0, #0x80
	subs r2, r0, r1
_080FCBC6:
	ldrb r0, [r5, #0x17]
	muls r0, r2, r0
	asrs r2, r0, #6
	ldrb r0, [r5, #0x16]
	eors r0, r2
	lsls r0, r0, #0x18
	beq _080FCBE8
	strb r2, [r5, #0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, #0x18]
	cmp r1, #0
	bne _080FCBE2
	movs r1, #0xc
	b _080FCBE4
_080FCBE2:
	movs r1, #3
_080FCBE4:
	orrs r0, r1
	strb r0, [r5]
_080FCBE8:
	mov r3, sl
	mov r4, fp
_080FCBEC:
	subs r6, #1
	ble _080FCBF8
	movs r0, #0x50
	adds r5, r5, r0
	lsls r3, r3, #1
	b _080FCAD0
_080FCBF8:
	ldr r0, [r7, #0xc]
	adds r0, #1
	str r0, [r7, #0xc]
	cmp r4, #0
	bne _080FCC0A
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	b _080FCCC0
_080FCC0A:
	str r4, [r7, #4]
	ldrh r0, [r7, #0x22]
	subs r0, #0x96
_080FCC10:
	strh r0, [r7, #0x22]
	cmp r0, #0x96
	blo _080FCC18
	b _080FCAC8
_080FCC18:
	ldrb r2, [r7, #8]
	ldr r5, [r7, #0x2c]
_080FCC1C:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	beq _080FCCB6
	movs r1, #0xf
	tst r1, r0
	beq _080FCCB6
	mov sb, r2
	adds r0, r7, #0
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _080FCCAC
_080FCC3A:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	bne _080FCC4A
	adds r0, r4, #0
	bl ClearChain
	b _080FCCA6
_080FCC4A:
	ldrb r0, [r4, #1]
	movs r6, #7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, #3
	tst r0, r3
	beq _080FCC68
	bl ChnVolSetAsm
	cmp r6, #0
	beq _080FCC68
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_080FCC68:
	ldrb r3, [r5]
	movs r0, #0xc
	tst r0, r3
	beq _080FCCA6
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _080FCC7C
	movs r2, #0
_080FCC7C:
	cmp r6, #0
	beq _080FCC9A
	mov r0, r8
	ldr r3, [r0, #0x30]
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	adds r0, r6, #0
	bl call_r3
	str r0, [r4, #0x20]
	ldrb r0, [r4, #0x1d]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0x1d]
	b _080FCCA6
_080FCC9A:
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	ldr r0, [r4, #0x24]
	bl MidiKeyToFreq
	str r0, [r4, #0x20]
_080FCCA6:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _080FCC3A
_080FCCAC:
	ldrb r0, [r5]
	movs r1, #0xf0
	ands r0, r1
	strb r0, [r5]
	mov r2, sb
_080FCCB6:
	subs r2, #1
	ble _080FCCC0
	movs r0, #0x50
	adds r5, r5, r0
	bgt _080FCC1C
_080FCCC0:
	ldr r0, _080FCCDC @ =0x68736D53
	str r0, [r7, #0x34]
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}

	thumb_func_start call_r3
call_r3: @ 0x080FCCD0
	bx r3
	.align 2, 0
_080FCCD4: .4byte 0x0810E540
_080FCCD8: .4byte 0x03007FF0
_080FCCDC: .4byte 0x68736D53

	thumb_func_start TrackStop
TrackStop: @ 0x080FCCE0
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrb r1, [r5]
	movs r0, #0x80
	tst r0, r1
	beq _080FCD18
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _080FCD16
	movs r6, #0
_080FCCF4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080FCD0E
	ldrb r0, [r4, #1]
	movs r3, #7
	ands r0, r3
	beq _080FCD0C
	ldr r3, _080FCD20 @ =0x03007FF0
	ldr r3, [r3]
	ldr r3, [r3, #0x2c]
	bl call_r3
_080FCD0C:
	strb r6, [r4]
_080FCD0E:
	str r6, [r4, #0x2c]
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _080FCCF4
_080FCD16:
	str r4, [r5, #0x20]
_080FCD18:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080FCD20: .4byte 0x03007FF0

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 0x080FCD24
	ldrb r1, [r4, #0x12]
	movs r0, #0x14
	ldrsb r2, [r4, r0]
	movs r3, #0x80
	adds r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x10]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _080FCD3C
	movs r0, #0xff
_080FCD3C:
	strb r0, [r4, #2]
	movs r3, #0x7f
	subs r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x11]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _080FCD50
	movs r0, #0xff
_080FCD50:
	strb r0, [r4, #3]
	bx lr

	thumb_func_start ply_note
ply_note: @ 0x080FCD54
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	sub sp, #0x18
	str r1, [sp]
	adds r5, r2, #0
	ldr r1, _080FCF4C @ =0x03007FF0
	ldr r1, [r1]
	str r1, [sp, #4]
	ldr r1, _080FCF50 @ =0x0810E540
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	ldr r3, [r5, #0x40]
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080FCD9A
	strb r0, [r5, #5]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080FCD98
	strb r0, [r5, #6]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _080FCD98
	ldrb r1, [r5, #4]
	adds r1, r1, r0
	strb r1, [r5, #4]
	adds r3, #1
_080FCD98:
	str r3, [r5, #0x40]
_080FCD9A:
	movs r0, #0
	str r0, [sp, #0x14]
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r0, #0xc0
	tst r0, r2
	beq _080FCDEC
	ldrb r3, [r5, #5]
	movs r0, #0x40
	tst r0, r2
	beq _080FCDBA
	ldr r1, [r5, #0x2c]
	adds r1, r1, r3
	ldrb r0, [r1]
	b _080FCDBC
_080FCDBA:
	adds r0, r3, #0
_080FCDBC:
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r5, #0x28]
	adds r1, r1, r0
	mov sb, r1
	mov r6, sb
	ldrb r1, [r6]
	movs r0, #0xc0
	tst r0, r1
	beq _080FCDD4
	b _080FCF3A
_080FCDD4:
	movs r0, #0x80
	tst r0, r2
	beq _080FCDF0
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	beq _080FCDE8
	subs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp, #0x14]
_080FCDE8:
	ldrb r3, [r6, #1]
	b _080FCDF0
_080FCDEC:
	mov sb, r4
	ldrb r3, [r5, #5]
_080FCDF0:
	str r3, [sp, #8]
	ldr r6, [sp]
	ldrb r1, [r6, #9]
	ldrb r0, [r5, #0x1d]
	adds r0, r0, r1
	cmp r0, #0xff
	bls _080FCE00
	movs r0, #0xff
_080FCE00:
	str r0, [sp, #0x10]
	mov r6, sb
	ldrb r0, [r6]
	movs r6, #7
	ands r6, r0
	str r6, [sp, #0xc]
	beq _080FCE40
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _080FCE18
	b _080FCF3A
_080FCE18:
	subs r6, #1
	lsls r0, r6, #6
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080FCE94
	movs r0, #0x40
	tst r0, r1
	bne _080FCE94
	ldrb r1, [r4, #0x13]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo _080FCE94
	beq _080FCE38
	b _080FCF3A
_080FCE38:
	ldr r0, [r4, #0x2c]
	cmp r0, r5
	bhs _080FCE94
	b _080FCF3A
_080FCE40:
	ldr r6, [sp, #0x10]
	adds r7, r5, #0
	movs r2, #0
	mov r8, r2
	ldr r4, [sp, #4]
	ldrb r3, [r4, #6]
	adds r4, #0x50
_080FCE4E:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _080FCE94
	movs r0, #0x40
	tst r0, r1
	beq _080FCE68
	cmp r2, #0
	bne _080FCE6C
	adds r2, #1
	ldrb r6, [r4, #0x13]
	ldr r7, [r4, #0x2c]
	b _080FCE86
_080FCE68:
	cmp r2, #0
	bne _080FCE88
_080FCE6C:
	ldrb r0, [r4, #0x13]
	cmp r0, r6
	bhs _080FCE78
	adds r6, r0, #0
	ldr r7, [r4, #0x2c]
	b _080FCE86
_080FCE78:
	bhi _080FCE88
	ldr r0, [r4, #0x2c]
	cmp r0, r7
	bls _080FCE84
	adds r7, r0, #0
	b _080FCE86
_080FCE84:
	blo _080FCE88
_080FCE86:
	mov r8, r4
_080FCE88:
	adds r4, #0x40
	subs r3, #1
	bgt _080FCE4E
	mov r4, r8
	cmp r4, #0
	beq _080FCF3A
_080FCE94:
	adds r0, r4, #0
	bl ClearChain
	movs r1, #0
	str r1, [r4, #0x30]
	ldr r3, [r5, #0x20]
	str r3, [r4, #0x34]
	cmp r3, #0
	beq _080FCEA8
	str r4, [r3, #0x30]
_080FCEA8:
	str r4, [r5, #0x20]
	str r5, [r4, #0x2c]
	ldrb r0, [r5, #0x1b]
	strb r0, [r5, #0x1c]
	cmp r0, r1
	beq _080FCEBA
	adds r1, r5, #0
	bl clear_modM
_080FCEBA:
	ldr r0, [sp]
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r0, [r5, #4]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x10]
	strb r0, [r4, #0x13]
	ldr r0, [sp, #8]
	strb r0, [r4, #8]
	ldr r0, [sp, #0x14]
	strb r0, [r4, #0x14]
	mov r6, sb
	ldrb r0, [r6]
	strb r0, [r4, #1]
	ldr r7, [r6, #4]
	str r7, [r4, #0x24]
	ldr r0, [r6, #8]
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	strh r0, [r4, #0xc]
	bl ChnVolSetAsm
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _080FCEF4
	movs r3, #0
_080FCEF4:
	ldr r6, [sp, #0xc]
	cmp r6, #0
	beq _080FCF22
	mov r6, sb
	ldrb r0, [r6, #2]
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	bne _080FCF0E
	movs r0, #0x70
	tst r0, r1
	bne _080FCF10
_080FCF0E:
	movs r1, #8
_080FCF10:
	strb r1, [r4, #0x1f]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #4]
	ldr r3, [r3, #0x30]
	bl call_r3
	b _080FCF2C
_080FCF22:
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	adds r0, r7, #0
	bl MidiKeyToFreq
_080FCF2C:
	str r0, [r4, #0x20]
	movs r0, #0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	strb r0, [r5]
_080FCF3A:
	add sp, #0x18
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r0}
	bx r0
	.align 2, 0
_080FCF4C: .4byte 0x03007FF0
_080FCF50: .4byte 0x0810E540

	thumb_func_start ply_endtie
ply_endtie: @ 0x080FCF54
	push {r4, r5}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0x80
	bhs _080FCF66
	strb r3, [r1, #5]
	adds r2, #1
	str r2, [r1, #0x40]
	b _080FCF68
_080FCF66:
	ldrb r3, [r1, #5]
_080FCF68:
	ldr r1, [r1, #0x20]
	cmp r1, #0
	beq _080FCF90
	movs r4, #0x83
	movs r5, #0x40
_080FCF72:
	ldrb r2, [r1]
	tst r2, r4
	beq _080FCF8A
	tst r2, r5
	bne _080FCF8A
	ldrb r0, [r1, #0x11]
	cmp r0, r3
	bne _080FCF8A
	movs r0, #0x40
	orrs r2, r0
	strb r2, [r1]
	b _080FCF90
_080FCF8A:
	ldr r1, [r1, #0x34]
	cmp r1, #0
	bne _080FCF72
_080FCF90:
	pop {r4, r5}
	bx lr

	thumb_func_start clear_modM
clear_modM: @ 0x080FCF94
	movs r2, #0
	strb r2, [r1, #0x16]
	strb r2, [r1, #0x1a]
	ldrb r2, [r1, #0x18]
	cmp r2, #0
	bne _080FCFA4
	movs r2, #0xc
	b _080FCFA6
_080FCFA4:
	movs r2, #3
_080FCFA6:
	ldrb r3, [r1]
	orrs r3, r2
	strb r3, [r1]
	bx lr
	.align 2, 0

	thumb_func_start ld_r3_tp_adr_i_unchecked
ld_r3_tp_adr_i_unchecked: @ 0x080FCFB0
	ldr r2, [r1, #0x40]
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	bx lr
	.align 2, 0

	thumb_func_start ply_lfos
ply_lfos: @ 0x080FCFBC
	mov ip, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, #0x19]
	cmp r3, #0
	bne _080FCFCC
	bl clear_modM
_080FCFCC:
	bx ip
	.align 2, 0

	thumb_func_start ply_mod
ply_mod: @ 0x080FCFD0
	mov ip, lr
	bl ld_r3_tp_adr_i_unchecked
	strb r3, [r1, #0x17]
	cmp r3, #0
	bne _080FCFE0
	bl clear_modM
_080FCFE0:
	bx ip
	.align 2, 0
