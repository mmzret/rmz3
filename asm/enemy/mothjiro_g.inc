	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start mothjiro_08088a74
mothjiro_08088a74: @ 0x08088A74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xc0
	ldr r0, [r5]
	cmp r0, #0
	bne _08088AD2
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088AD2
	ldr r2, _08088ABC @ =0x083687F8
	movs r0, #0
	adds r1, r4, #0
	bl ApplyElementEffect
	str r0, [r5]
	cmp r0, #0
	beq _08088AD2
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x10
	bne _08088AC4
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088AC0 @ =0x083687E0
	bl SetDDP
	b _08088AD2
	.align 2, 0
_08088ABC: .4byte 0x083687F8
_08088AC0: .4byte 0x083687E0
_08088AC4:
	cmp r1, #0x30
	bne _08088AD2
	adds r0, r4, #0
	adds r0, #0x74
	ldr r1, _08088ADC @ =0x083687E0
	bl SetDDP
_08088AD2:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08088ADC: .4byte 0x083687E0

