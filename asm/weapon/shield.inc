	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08039368
FUN_08039368: @ 0x08039368
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb4
	ldr r0, [r0]
	mov ip, r0
	ldrb r1, [r4, #0xa]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0803939C
	ldr r2, _08039398 @ =0x083603F0
	mov r3, ip
	adds r3, #0x71
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r5, ip
	ldr r0, [r5, #0x54]
	adds r0, r0, r1
	b _080393B4
	.align 2, 0
_08039398: .4byte 0x083603F0
_0803939C:
	ldr r2, _080393D4 @ =0x083603F0
	mov r3, ip
	adds r3, #0x71
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r5, ip
	ldr r0, [r5, #0x54]
	subs r0, r0, r1
_080393B4:
	str r0, [r4, #0x54]
	movs r0, #0
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r1, r2, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r5, ip
	ldr r0, [r5, #0x58]
	adds r0, r0, r1
	str r0, [r4, #0x58]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080393D4: .4byte 0x083603F0
