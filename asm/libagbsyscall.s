	.include "asm/macros.inc"

	.syntax unified
	
	.text
	
	thumb_func_start ArcTan2
ArcTan2: @ 0x080FE534
	svc #0xa
	bx lr

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x080FE538
	svc #0xc
	bx lr

	thumb_func_start CpuSet
CpuSet: @ 0x080FE53C
	svc #0xb
	bx lr

	thumb_func_start LZ77UnCompVram
LZ77UnCompVram: @ 0x080FE540
	svc #0x12
	bx lr

	thumb_func_start LZ77UnCompWram
LZ77UnCompWram: @ 0x080FE544
	svc #0x11
	bx lr

	thumb_func_start RLUnCompVram
RLUnCompVram: @ 0x080FE548
	svc #0x15
	bx lr

	thumb_func_start Sqrt
Sqrt: @ 0x080FE54C
	svc #8
	bx lr
