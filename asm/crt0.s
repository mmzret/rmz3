	.include "asm/macros.inc"

	.syntax unified
	
	.text
	.arm

	.global Init
Init:
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
	b Init
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
_080001B4: .4byte INTR_VECTOR
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
	ldr r1, _080002D8 @ =gIntrManager
	add r1, r1, r2
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, #0x0 @ =0x080002B0
	bx r0
intr_return:
	ldmia sp!, {lr}
	mrs r3, cpsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x92
	msr cpsr, r3
	ldmia sp!, {r0, r1, r3, lr}
	strh r1, [r3]
	msr spsr, r0
	bx lr
_080002D4: .4byte 0x000029CE
_080002D8: .4byte gIntrManager

	thumb_func_start CallProcess
CallProcess: @ 0x080002DC
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	mov r4, sp
	str r4, [r3]
	mov lr, r1
	mov sp, r2
	pop {r4, r5, r6, r7}
	mov fp, r7
	mov sl, r6
	mov sb, r5
	mov r8, r4
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0

	thumb_func_start returnCallProcess
returnCallProcess: @ 0x08000300
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	mov r3, lr
	str r3, [r0]
	mov r3, sp
	str r3, [r1]
	mov sp, r2
	pop {r4, r5, r6, r7}
	mov fp, r7
	mov sl, r6
	mov sb, r5
	mov r8, r4
	pop {r4, r5, r6, r7}
	pop {r3}
	mov lr, r3
	bx lr

	thumb_func_start ReturnToGameLoop
ReturnToGameLoop: @ 0x08000328
	mov sp, r0
	pop {r4, r5, r6, r7}
	mov fp, r7
	mov sl, r6
	mov sb, r5
	mov r8, r4
	pop {r4, r5, r6, r7}
	pop {r3}
	mov lr, r3
	bx lr
	.align 2, 0
