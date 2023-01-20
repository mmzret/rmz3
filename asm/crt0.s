	.include "asm/macros.inc"

	.syntax unified
	
	.text

	arm_func_start sub_08000000
sub_08000000: @ 0x08000000
	b _080000C0
_08000004:
	.byte 0x24, 0xFF, 0xAE, 0x51, 0x69, 0x9A, 0xA2, 0x21, 0x3D, 0x84, 0x82, 0x0A
	.byte 0x84, 0xE4, 0x09, 0xAD, 0x11, 0x24, 0x8B, 0x98, 0xC0, 0x81, 0x7F, 0x21, 0xA3, 0x52, 0xBE, 0x19
	.byte 0x93, 0x09, 0xCE, 0x20, 0x10, 0x46, 0x4A, 0x4A, 0xF8, 0x27, 0x31, 0xEC, 0x58, 0xC7, 0xE8, 0x33
	.byte 0x82, 0xE3, 0xCE, 0xBF, 0x85, 0xF4, 0xDF, 0x94, 0xCE, 0x4B, 0x09, 0xC1, 0x94, 0x56, 0x8A, 0xC0
	.byte 0x13, 0x72, 0xA7, 0xFC, 0x9F, 0x84, 0x4D, 0x73, 0xA3, 0xCA, 0x9A, 0x61, 0x58, 0x97, 0xA3, 0x27
	.byte 0xFC, 0x03, 0x98, 0x76, 0x23, 0x1D, 0xC7, 0x61, 0x03, 0x04, 0xAE, 0x56, 0xBF, 0x38, 0x84, 0x00
	.byte 0x40, 0xA7, 0x0E, 0xFD, 0xFF, 0x52, 0xFE, 0x03, 0x6F, 0x95, 0x30, 0xF1, 0x97, 0xFB, 0xC0, 0x85
	.byte 0x60, 0xD6, 0x80, 0x25, 0xA9, 0x63, 0xBE, 0x03, 0x01, 0x4E, 0x38, 0xE2, 0xF9, 0xA2, 0x34, 0xFF
	.byte 0xBB, 0x3E, 0x03, 0x44, 0x78, 0x00, 0x90, 0xCB, 0x88, 0x11, 0x3A, 0x94, 0x65, 0xC0, 0x7C, 0x63
	.byte 0x87, 0xF0, 0x3C, 0xAF, 0xD6, 0x25, 0xE4, 0x8B, 0x38, 0x0A, 0xAC, 0x72, 0x21, 0xD4, 0xF8, 0x07
	.byte 0x52, 0x4F, 0x43, 0x4B, 0x4D, 0x41, 0x4E, 0x5A, 0x45, 0x52, 0x4F, 0x33, 0x42, 0x5A, 0x33, 0x4A
	.byte 0x30, 0x38, 0x96, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x00, 0x00
_080000C0:
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080000F8 @ =0x03007FA0
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080000F4 @ =0x03007DA0
	ldr r1, _080001B4 @ =0x03007FFC
	add r0, pc, #0x18 @ =MaybeIntrMain
	str r0, [r1]
	ldr r1, _080001B8 @ =AgbMain
	mov lr, pc
	bx r1
_080000F0:
	.byte 0xF2, 0xFF, 0xFF, 0xEA
_080000F4: .4byte 0x03007DA0
_080000F8: .4byte 0x03007FA0

	arm_func_start MaybeIntrMain
MaybeIntrMain: @ 0x080000FC
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	and r1, r2, r2, lsr #16
	ands r0, r1, #0x2000
_08000110:
	bne _08000110
	mov r2, #0
	ands r0, r1, #1
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #2
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #4
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #8
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x10
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x20
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x40
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x80
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x100
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x200
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x400
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x800
	bne _080001AC
	add r2, r2, #4
	ands r0, r1, #0x1000
_080001AC:
	strh r0, [r3, #2]
	bx lr
	.align 2, 0
_080001B4: .4byte 0x03007FFC
_080001B8: .4byte AgbMain

	arm_func_start IntrMain
IntrMain: @ 0x080001BC
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	lsl r1, r2, #0x10
	lsr r1, r1, #0x10
	mrs r0, spsr
	push {r0, r1, r3, lr}
	and r1, r2, r2, lsr #16
	ands r0, r1, #0x2000
_080001E0:
	bne _080001E0
	mov r2, #0x1c
	ands r0, r1, #0x80
	bne _0800027C
	mov r2, #0x18
	ands r0, r1, #0x40
	bne _0800027C
	mov r2, #0
	ands r0, r1, #1
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #2
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #4
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #8
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #0x10
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #0x20
	bne _0800027C
	mov r2, #0x24
	ands r0, r1, #0x200
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #0x400
	bne _0800027C
	mov r2, #0x20
	ands r0, r1, #0x100
	bne _0800027C
	mov r2, #0x2c
	ands r0, r1, #0x800
	bne _0800027C
	add r2, r2, #4
	ands r0, r1, #0x1000
_0800027C:
	strh r0, [r3, #2]
	ldr r1, _080002D4 @ =0x000029CE
	strh r1, [r3]
	mrs r3, cpsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x1f
	msr cpsr_fc, r3
	ldr r1, _080002D8 @ =0x03001590
	add r1, r1, r2
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, #0x0 @ =0x080002B0
	bx r0
_080002B0:
	.byte 0x00, 0x40, 0xBD, 0xE8, 0x00, 0x30, 0x0F, 0xE1, 0xDF, 0x30, 0xC3, 0xE3, 0x92, 0x30, 0x83, 0xE3
	.byte 0x03, 0xF0, 0x29, 0xE1, 0x0B, 0x40, 0xBD, 0xE8, 0xB0, 0x10, 0xC3, 0xE1, 0x00, 0xF0, 0x69, 0xE1
	.byte 0x1E, 0xFF, 0x2F, 0xE1
_080002D4: .4byte 0x000029CE
_080002D8: .4byte 0x03001590
