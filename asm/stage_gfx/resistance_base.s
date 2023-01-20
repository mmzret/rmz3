	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start initRBase
initRBase: @ 0x080160BC
	push {r4, r5, lr}
	ldr r1, _08016138 @ =0x02002200
	ldr r2, _0801613C @ =0x0002D024
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08016140 @ =0x0002D025
	adds r0, r1, r3
	strb r2, [r0]
	ldr r5, _08016144 @ =0x0002D028
	adds r0, r1, r5
	strb r2, [r0]
	ldr r4, _08016148 @ =0x020021B0
	adds r0, r4, #0
	adds r0, #0x47
	ldrb r0, [r0]
	adds r5, #1
	adds r3, r1, r5
	strb r0, [r3]
	ldr r0, _0801614C @ =0x0002D02A
	adds r1, r1, r0
	strb r2, [r1]
	ldr r0, _08016150 @ =0x0202FE60
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _080160F4
	movs r0, #3
	strb r0, [r3]
_080160F4:
	ldrb r1, [r4, #0xb]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08016108
	movs r0, #5
	movs r1, #6
	movs r2, #7
	bl loadScreenIntoBlockMap
_08016108:
	ldrb r1, [r4, #0xc]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08016130
	movs r0, #6
	movs r1, #2
	movs r2, #0x56
	bl loadScreenIntoBlockMap
	movs r0, #6
	movs r1, #3
	movs r2, #0x57
	bl loadScreenIntoBlockMap
	movs r0, #7
	movs r1, #3
	movs r2, #0x58
	bl loadScreenIntoBlockMap
_08016130:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016138: .4byte 0x02002200
_0801613C: .4byte 0x0002D024
_08016140: .4byte 0x0002D025
_08016144: .4byte 0x0002D028
_08016148: .4byte 0x020021B0
_0801614C: .4byte 0x0002D02A
_08016150: .4byte 0x0202FE60

	thumb_func_start FUN_08016154
FUN_08016154: @ 0x08016154
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r2, _08016194 @ =0x02002200
	ldr r1, _08016198 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0x11
	bne _080161A0
	movs r0, #0xff
	ands r0, r1
	cmp r0, #1
	bne _080161A0
	ldr r1, _0801619C @ =0x0002D028
	adds r2, r2, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0801618A
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x6a
	movs r1, #0
	bl loadBlink
_0801618A:
	movs r0, #0x6a
	bl FUN_08004068
	b _080161BE
	.align 2, 0
_08016194: .4byte 0x02002200
_08016198: .4byte 0x000007D4
_0801619C: .4byte 0x0002D028
_080161A0:
	ldr r0, _080161F8 @ =0x02002200
	ldr r2, _080161FC @ =0x0002D028
	adds r4, r0, r2
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080161BE
	movs r0, #0x6a
	bl clearBlink
	ldrb r0, [r4]
	movs r1, #1
	eors r0, r1
	strb r0, [r4]
_080161BE:
	ldr r2, _080161F8 @ =0x02002200
	ldr r1, _08016200 @ =0x000007D4
	adds r0, r2, r1
	ldrh r1, [r0]
	lsrs r0, r1, #8
	cmp r0, #0x11
	bne _08016204
	movs r0, #0xff
	ands r0, r1
	cmp r0, #4
	bne _08016204
	ldr r0, _080161FC @ =0x0002D028
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080161F0
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x68
	movs r1, #0
	bl loadBlink
_080161F0:
	movs r0, #0x68
	bl FUN_08004068
	b _08016222
	.align 2, 0
_080161F8: .4byte 0x02002200
_080161FC: .4byte 0x0002D028
_08016200: .4byte 0x000007D4
_08016204:
	ldr r0, _08016298 @ =0x02002200
	ldr r1, _0801629C @ =0x0002D028
	adds r4, r0, r1
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08016222
	movs r0, #0x68
	bl clearBlink
	ldrb r0, [r4]
	movs r1, #2
	eors r0, r1
	strb r0, [r4]
_08016222:
	ldr r0, _08016298 @ =0x02002200
	ldr r2, _080162A0 @ =0x0002D029
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #2
	beq _08016232
	b _08016360
_08016232:
	ldr r1, _080162A4 @ =0x0002D02A
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r0, _080162A8 @ =0x00031FFF
	ldr r3, [r5, #4]
	cmp r3, r0
	bgt _080162BC
	ldr r2, [r5]
	ldr r0, _080162AC @ =0x0001DFFF
	cmp r2, r0
	ble _080162BC
	movs r0, #0x87
	lsls r0, r0, #0xc
	cmp r2, r0
	bgt _080162BC
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _0801625E
	b _08016360
_0801625E:
	ldr r2, _080162B0 @ =0x0202F388
	ldr r1, [r2]
	ldr r0, _080162B4 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _080162B8 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	lsls r1, r1, #2
	bl __umodsi3
	lsls r0, r0, #8
	movs r2, #0x96
	lsls r2, r2, #0xb
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0xa0
	lsls r0, r0, #8
	str r0, [sp, #4]
	movs r1, #0xe0
	lsls r1, r1, #2
	mov r0, sp
	bl FUN_080c9144
	b _08016360
	.align 2, 0
_08016298: .4byte 0x02002200
_0801629C: .4byte 0x0002D028
_080162A0: .4byte 0x0002D029
_080162A4: .4byte 0x0002D02A
_080162A8: .4byte 0x00031FFF
_080162AC: .4byte 0x0001DFFF
_080162B0: .4byte 0x0202F388
_080162B4: .4byte 0x000343FD
_080162B8: .4byte 0x00269EC3
_080162BC:
	ldr r0, _08016308 @ =0x00045FFF
	cmp r3, r0
	bgt _0801631C
	ldr r1, _0801630C @ =0x0002D02A
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08016360
	ldr r2, _08016310 @ =0x0202F388
	ldr r1, [r2]
	ldr r0, _08016314 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08016318 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	bl __umodsi3
	lsls r0, r0, #8
	movs r2, #0xb4
	lsls r2, r2, #0xa
	adds r0, r0, r2
	str r0, [sp, #8]
	movs r1, #0xc8
	lsls r1, r1, #0xa
	add r0, sp, #8
	str r1, [r0, #4]
	movs r1, #0xa0
	lsls r1, r1, #1
	bl FUN_080c9144
	b _08016360
	.align 2, 0
_08016308: .4byte 0x00045FFF
_0801630C: .4byte 0x0002D02A
_08016310: .4byte 0x0202F388
_08016314: .4byte 0x000343FD
_08016318: .4byte 0x00269EC3
_0801631C:
	ldr r1, _08016368 @ =0x0002D02A
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08016360
	ldr r2, _0801636C @ =0x0202F388
	ldr r1, [r2]
	ldr r0, _08016370 @ =0x000343FD
	muls r0, r1, r0
	ldr r1, _08016374 @ =0x00269EC3
	adds r0, r0, r1
	lsls r0, r0, #1
	lsrs r1, r0, #1
	str r1, [r2]
	lsrs r0, r0, #0x11
	movs r1, #0xf0
	lsls r1, r1, #1
	bl __umodsi3
	lsls r0, r0, #8
	movs r2, #0x87
	lsls r2, r2, #0xc
	adds r0, r0, r2
	str r0, [sp, #0x10]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	add r0, sp, #0x10
	str r1, [r0, #4]
	movs r1, #0xa0
	lsls r1, r1, #1
	bl FUN_080c9144
_08016360:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016368: .4byte 0x0002D02A
_0801636C: .4byte 0x0202F388
_08016370: .4byte 0x000343FD
_08016374: .4byte 0x00269EC3

	thumb_func_start nop_08016378
nop_08016378: @ 0x08016378
	bx lr
	.align 2, 0

	thumb_func_start exitResistanceBase
exitResistanceBase: @ 0x0801637C
	push {lr}
	movs r0, #0x68
	bl clearBlink
	movs r0, #0x6a
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start rbase_08016390
rbase_08016390: @ 0x08016390
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #4
	bls _0801639C
	b _080164D2
_0801639C:
	lsls r0, r0, #2
	ldr r1, _080163A8 @ =_080163AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080163A8: .4byte _080163AC
_080163AC: @ jump table
	.4byte _080163C0 @ case 0
	.4byte _08016438 @ case 1
	.4byte _08016452 @ case 2
	.4byte _08016480 @ case 3
	.4byte _080164B8 @ case 4
_080163C0:
	ldr r1, [r5, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _080164A0 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _080164A4 @ =0x0000FFFC
	ands r0, r2
	movs r2, #3
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _080164A8 @ =0x02002200
	ldr r1, _080164AC @ =0x0002D025
	adds r0, r0, r1
	movs r4, #0
	strb r4, [r0]
	ldr r1, _080164B0 @ =0x02002180
	movs r0, #0xfd
	lsls r0, r0, #6
	strh r0, [r1]
	movs r0, #0x6b
	movs r1, #0
	bl loadBlink
	movs r0, #0x6c
	movs r1, #0
	bl loadBlink
	movs r0, #0x6d
	movs r1, #0
	bl loadBlink
	movs r0, #0x6e
	movs r1, #0
	bl loadBlink
	movs r0, #0x6f
	movs r1, #0
	bl loadBlink
	movs r0, #0x70
	movs r1, #0
	bl loadBlink
	movs r0, #0x74
	movs r1, #0
	bl loadBlink
	movs r0, #0x75
	movs r1, #0
	bl loadBlink
	movs r0, #0x76
	movs r1, #0
	bl loadBlink
	strh r4, [r5, #0x10]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08016438:
	ldr r0, _080164A8 @ =0x02002200
	ldr r1, _080164B4 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080164D2
	movs r0, #0x72
	movs r1, #0
	bl loadBlink
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08016452:
	movs r0, #0x72
	bl FUN_08004068
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _080164D2
	ldr r0, _080164A8 @ =0x02002200
	ldr r1, _080164B4 @ =0x0002D024
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _080164D2
	movs r0, #0x72
	bl clearBlink
	movs r0, #0x73
	movs r1, #0
	bl loadBlink
	ldrb r0, [r5, #0xe]
	adds r0, #1
	strb r0, [r5, #0xe]
_08016480:
	movs r0, #0x73
	bl FUN_08004068
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080164D2
	movs r0, #0x73
	bl clearBlink
	movs r0, #0x78
	strh r0, [r5, #0x12]
	ldrb r0, [r5, #0xe]
	adds r0, #1
	b _080164D0
	.align 2, 0
_080164A0: .4byte 0x02002144
_080164A4: .4byte 0x0000FFFC
_080164A8: .4byte 0x02002200
_080164AC: .4byte 0x0002D025
_080164B0: .4byte 0x02002180
_080164B4: .4byte 0x0002D024
_080164B8:
	ldrh r0, [r5, #0x12]
	subs r0, #1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080164D2
	ldr r0, _08016514 @ =0x02002200
	ldr r1, _08016518 @ =0x0002D024
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
_080164D0:
	strb r0, [r5, #0xe]
_080164D2:
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	movs r0, #0x6b
	bl FUN_08004068
	movs r0, #0x6c
	bl FUN_08004068
	movs r0, #0x6d
	bl FUN_08004068
	movs r0, #0x6e
	bl FUN_08004068
	movs r0, #0x6f
	bl FUN_08004068
	movs r0, #0x70
	bl FUN_08004068
	movs r0, #0x74
	bl FUN_08004068
	movs r0, #0x75
	bl FUN_08004068
	movs r0, #0x76
	bl FUN_08004068
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016514: .4byte 0x02002200
_08016518: .4byte 0x0002D024

	thumb_func_start rbase_0801651c
rbase_0801651c: @ 0x0801651C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	mov sb, r1
	ldr r0, _0801657C @ =0x087044F8
	mov r8, r0
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	movs r6, #7
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r5, _08016580 @ =0x08704980
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	bl appendGraphicTask
	ldrh r0, [r4, #0x10]
	lsrs r0, r0, #2
	ands r0, r6
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0xc
	movs r1, #0
	bl transferPalette
	adds r0, r4, #0
	mov r1, sb
	bl variousStageFunc_080093b8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801657C: .4byte 0x087044F8
_08016580: .4byte 0x08704980

	thumb_func_start rbase_08016584
rbase_08016584: @ 0x08016584
	push {lr}
	ldr r1, _080165D4 @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x6b
	bl clearBlink
	movs r0, #0x6c
	bl clearBlink
	movs r0, #0x6d
	bl clearBlink
	movs r0, #0x6e
	bl clearBlink
	movs r0, #0x6f
	bl clearBlink
	movs r0, #0x70
	bl clearBlink
	movs r0, #0x74
	bl clearBlink
	movs r0, #0x75
	bl clearBlink
	movs r0, #0x76
	bl clearBlink
	movs r0, #0x72
	bl clearBlink
	movs r0, #0x73
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_080165D4: .4byte 0x02002180

	thumb_func_start FUN_080165d8
FUN_080165d8: @ 0x080165D8
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _080165FE
	ldr r1, [r3, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _08016604 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08016608 @ =0x0000FFFC
	ands r0, r2
	movs r2, #3
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_080165FE:
	pop {r0}
	bx r0
	.align 2, 0
_08016604: .4byte 0x02002144
_08016608: .4byte 0x0000FFFC

	thumb_func_start FUN_0801660c
FUN_0801660c: @ 0x0801660C
	push {r4, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _08016666
	ldr r1, [r3, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _08016648 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _0801664C @ =0x0000FFFC
	ands r0, r2
	movs r2, #3
	orrs r0, r2
	strh r0, [r1]
	str r4, [r3, #0x40]
	str r4, [r3, #0x3c]
	movs r0, #0x80
	str r0, [r3, #0x44]
	str r0, [r3, #0x48]
	ldr r1, [r3, #0x34]
	ldr r0, _08016650 @ =0x0000059F
	cmp r1, r0
	bgt _08016654
	movs r0, #0xb4
	lsls r0, r0, #1
	str r0, [r3, #0x4c]
	adds r0, #0x28
	b _0801665E
	.align 2, 0
_08016648: .4byte 0x02002144
_0801664C: .4byte 0x0000FFFC
_08016650: .4byte 0x0000059F
_08016654:
	movs r0, #0x96
	lsls r0, r0, #3
	str r0, [r3, #0x4c]
	movs r0, #0xa0
	lsls r0, r0, #2
_0801665E:
	str r0, [r3, #0x50]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08016666:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801666c
FUN_0801666c: @ 0x0801666C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #0xe]
	cmp r3, #0
	bne _08016766
	ldr r1, [r4, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _080166C0 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _080166C4 @ =0x0000FFFC
	ands r0, r2
	movs r2, #3
	orrs r0, r2
	strh r0, [r1]
	str r3, [r4, #0x40]
	str r3, [r4, #0x3c]
	movs r0, #0x20
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	ldr r1, [r4, #0x34]
	ldr r0, _080166C8 @ =0x0000059F
	cmp r1, r0
	bgt _080166DC
	ldr r0, _080166CC @ =0x00000276
	str r0, [r4, #0x4c]
	adds r0, #0x46
	str r0, [r4, #0x50]
	ldr r1, _080166D0 @ =0x02002200
	ldr r0, _080166D4 @ =0x0002C014
	adds r2, r1, r0
	movs r0, #0xd0
	lsls r0, r0, #0xa
	str r0, [r2]
	ldr r2, _080166D8 @ =0x0002C01C
	adds r1, r1, r2
	movs r0, #0xf0
	lsls r0, r0, #0xe
	str r0, [r1]
	b _080166F8
	.align 2, 0
_080166C0: .4byte 0x02002144
_080166C4: .4byte 0x0000FFFC
_080166C8: .4byte 0x0000059F
_080166CC: .4byte 0x00000276
_080166D0: .4byte 0x02002200
_080166D4: .4byte 0x0002C014
_080166D8: .4byte 0x0002C01C
_080166DC:
	ldr r0, _08016708 @ =0x00000834
	str r0, [r4, #0x4c]
	movs r0, #0x8c
	lsls r0, r0, #3
	str r0, [r4, #0x50]
	ldr r0, _0801670C @ =0x02002200
	ldr r2, _08016710 @ =0x0002C014
	adds r1, r0, r2
	str r3, [r1]
	ldr r1, _08016714 @ =0x0002C01C
	adds r0, r0, r1
	movs r1, #0x9e
	lsls r1, r1, #0xc
	str r1, [r0]
_080166F8:
	ldr r0, _0801670C @ =0x02002200
	ldr r2, _08016718 @ =0x0002D029
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801671C
	movs r0, #0x69
	b _0801673A
	.align 2, 0
_08016708: .4byte 0x00000834
_0801670C: .4byte 0x02002200
_08016710: .4byte 0x0002C014
_08016714: .4byte 0x0002C01C
_08016718: .4byte 0x0002D029
_0801671C:
	cmp r0, #1
	bne _08016748
	ldr r0, [r4, #0x50]
	ldr r1, _08016744 @ =0xFFFFFEC0
	adds r0, r0, r1
	str r0, [r4, #0x50]
	movs r0, #0x78
	movs r1, #0
	bl loadBlink
	movs r0, #0x79
	movs r1, #0
	bl loadBlink
	movs r0, #0x7a
_0801673A:
	movs r1, #0
	bl loadBlink
	b _0801675C
	.align 2, 0
_08016744: .4byte 0xFFFFFEC0
_08016748:
	cmp r0, #2
	bne _0801675C
	movs r0, #0xc9
	movs r1, #0
	bl loadBlink
	movs r0, #0xca
	movs r1, #0
	bl loadBlink
_0801675C:
	movs r0, #0
	strh r0, [r4, #0x10]
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r4, #0xe]
_08016766:
	ldr r0, _0801677C @ =0x02002200
	ldr r2, _08016780 @ =0x0002D029
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08016784
	movs r0, #0x69
	bl FUN_08004068
	b _080167D4
	.align 2, 0
_0801677C: .4byte 0x02002200
_08016780: .4byte 0x0002D029
_08016784:
	cmp r0, #1
	bne _080167C4
	movs r0, #0x78
	bl FUN_08004068
	movs r0, #0x79
	bl FUN_08004068
	movs r0, #0x7a
	bl FUN_08004068
	movs r0, #0x7b
	bl FUN_08004068
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	movs r1, #0xe1
	lsls r1, r1, #0x14
	cmp r0, r1
	bne _080167D4
	movs r0, #0x7b
	bl clearBlink
	movs r0, #0x7b
	movs r1, #0
	bl loadBlink
	movs r0, #0
	strh r0, [r4, #0x10]
	b _080167D4
_080167C4:
	cmp r0, #2
	bne _080167D4
	movs r0, #0xc9
	bl FUN_08004068
	movs r0, #0xca
	bl FUN_08004068
_080167D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080167dc
FUN_080167dc: @ 0x080167DC
	push {lr}
	ldr r1, _08016830 @ =0x02002200
	ldr r2, _08016834 @ =0x0002C014
	adds r0, r1, r2
	movs r2, #0
	str r2, [r0]
	ldr r3, _08016838 @ =0x0002C018
	adds r0, r1, r3
	str r2, [r0]
	ldr r0, _0801683C @ =0x0002C01C
	adds r2, r1, r0
	movs r0, #0xf0
	lsls r0, r0, #0xe
	str r0, [r2]
	ldr r2, _08016840 @ =0x0002C020
	adds r1, r1, r2
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [r1]
	movs r0, #0x69
	bl clearBlink
	movs r0, #0x78
	bl clearBlink
	movs r0, #0x79
	bl clearBlink
	movs r0, #0x7a
	bl clearBlink
	movs r0, #0x7b
	bl clearBlink
	movs r0, #0xc9
	bl clearBlink
	movs r0, #0xca
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_08016830: .4byte 0x02002200
_08016834: .4byte 0x0002C014
_08016838: .4byte 0x0002C018
_0801683C: .4byte 0x0002C01C
_08016840: .4byte 0x0002C020

	thumb_func_start FUN_08016844
FUN_08016844: @ 0x08016844
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _0801686A
	ldr r1, [r3, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _08016870 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08016874 @ =0x0000FFFC
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_0801686A:
	pop {r0}
	bx r0
	.align 2, 0
_08016870: .4byte 0x02002144
_08016874: .4byte 0x0000FFFC

	thumb_func_start FUN_08016878
FUN_08016878: @ 0x08016878
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r4, #0
	ldrb r0, [r2, #0xe]
	cmp r0, #0
	bne _08016892
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
_08016892:
	ldr r0, [r2, #0x34]
	ldr r1, _080168F4 @ =0xFFFFFA8F
	adds r0, r0, r1
	cmp r0, #0xee
	bhi _0801693A
	ldr r1, [r2, #0x38]
	ldr r0, _080168F8 @ =0x0000022F
	cmp r1, r0
	bgt _080168A6
	movs r4, #1
_080168A6:
	adds r0, r2, #0
	adds r0, #0x68
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	beq _0801693A
	cmp r4, #0
	beq _080168FC
	movs r0, #5
	movs r1, #2
	movs r2, #0x15
	bl loadScreenIntoBlockMap
	movs r0, #5
	movs r1, #3
	movs r2, #0x16
	bl loadScreenIntoBlockMap
	movs r0, #5
	movs r1, #4
	movs r2, #0x52
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #2
	movs r2, #0x17
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #3
	movs r2, #0x18
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #4
	movs r2, #0x53
	bl loadScreenIntoBlockMap
	b _08016938
	.align 2, 0
_080168F4: .4byte 0xFFFFFA8F
_080168F8: .4byte 0x0000022F
_080168FC:
	movs r0, #5
	movs r1, #2
	movs r2, #0x11
	bl loadScreenIntoBlockMap
	movs r0, #5
	movs r1, #3
	movs r2, #0x21
	bl loadScreenIntoBlockMap
	movs r0, #5
	movs r1, #4
	movs r2, #0x31
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #2
	movs r2, #0x14
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #3
	movs r2, #0x24
	bl loadScreenIntoBlockMap
	movs r0, #8
	movs r1, #4
	movs r2, #0x34
	bl loadScreenIntoBlockMap
_08016938:
	strb r4, [r5]
_0801693A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start rbase_08016940
rbase_08016940: @ 0x08016940
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08016952
	b _08016A5C
_08016952:
	ldr r0, [r7, #0x5c]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	mov sb, r0
	ldr r0, _080169CC @ =0x02002200
	ldr r1, _080169D0 @ =0x0002D029
	adds r1, r1, r0
	mov r8, r1
	ldrb r0, [r1]
	cmp r0, #1
	beq _08016A0C
	lsrs r5, r2, #0x14
	lsls r5, r5, #1
	ldr r0, _080169D4 @ =0x02002144
	adds r5, r5, r0
	ldr r1, [r7, #0x60]
	ldr r0, [r7, #0x64]
	orrs r1, r0
	ldr r2, _080169D8 @ =0x00004044
	adds r0, r2, #0
	orrs r1, r0
	strh r1, [r5]
	ldr r0, _080169DC @ =0x08522388
	ldr r0, [r0]
	ldr r2, _080169E0 @ =0x08522390
	adds r0, r0, r2
	movs r4, #0xf8
	lsls r4, r4, #5
	ands r1, r4
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r6, #0x80
	lsls r6, r6, #2
	adds r2, r6, #0
	bl CpuFastSet
	ldr r0, _080169E4 @ =0x0852238C
	ldr r0, [r0]
	ldr r1, _080169E8 @ =0x08522394
	adds r0, r0, r1
	ldrh r1, [r5]
	ands r4, r1
	lsls r4, r4, #3
	ldr r2, _080169EC @ =0x06000800
	adds r4, r4, r2
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #2
	bne _080169F0
	movs r0, #0xc7
	movs r1, #0
	bl loadBlink
	movs r0, #0xc8
	b _08016A00
	.align 2, 0
_080169CC: .4byte 0x02002200
_080169D0: .4byte 0x0002D029
_080169D4: .4byte 0x02002144
_080169D8: .4byte 0x00004044
_080169DC: .4byte 0x08522388
_080169E0: .4byte 0x08522390
_080169E4: .4byte 0x0852238C
_080169E8: .4byte 0x08522394
_080169EC: .4byte 0x06000800
_080169F0:
	cmp r0, #3
	bne _08016A46
	movs r0, #0x89
	lsls r0, r0, #1
	movs r1, #0
	bl loadBlink
	ldr r0, _08016A08 @ =0x00000113
_08016A00:
	movs r1, #0
	bl loadBlink
	b _08016A46
	.align 2, 0
_08016A08: .4byte 0x00000113
_08016A0C:
	lsrs r2, r2, #0x14
	lsls r2, r2, #1
	ldr r0, _08016A78 @ =0x02002144
	adds r2, r2, r0
	ldr r1, [r7, #0x60]
	ldr r0, [r7, #0x64]
	orrs r1, r0
	movs r0, #0x44
	orrs r1, r0
	strh r1, [r2]
	ldr r0, _08016A7C @ =0x08522390
	ldr r0, [r0]
	ldr r2, _08016A80 @ =0x08522398
	adds r0, r0, r2
	movs r2, #0xf8
	lsls r2, r2, #5
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #2
	bl CpuFastSet
	movs r0, #0x77
	movs r1, #0
	bl loadBlink
_08016A46:
	mov r1, sb
	lsrs r0, r1, #4
	lsls r0, r0, #2
	ldr r1, _08016A84 @ =0x0200214C
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	str r1, [r7, #0x68]
	ldrb r0, [r7, #0xe]
	adds r0, #1
	strb r0, [r7, #0xe]
_08016A5C:
	ldr r0, _08016A88 @ =0x02002200
	ldr r2, _08016A8C @ =0x0002D029
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08016A90
	movs r0, #0xc7
	bl FUN_08004068
	movs r0, #0xc8
	bl FUN_08004068
	b _08016AA2
	.align 2, 0
_08016A78: .4byte 0x02002144
_08016A7C: .4byte 0x08522390
_08016A80: .4byte 0x08522398
_08016A84: .4byte 0x0200214C
_08016A88: .4byte 0x02002200
_08016A8C: .4byte 0x0002D029
_08016A90:
	cmp r0, #3
	bne _08016AA2
	movs r0, #0x89
	lsls r0, r0, #1
	bl FUN_08004068
	ldr r0, _08016AB4 @ =0x00000113
	bl FUN_08004068
_08016AA2:
	ldr r0, [r7, #0x68]
	adds r0, #1
	str r0, [r7, #0x68]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016AB4: .4byte 0x00000113

	thumb_func_start FUN_08016ab8
FUN_08016ab8: @ 0x08016AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldrh r0, [r6, #0x34]
	mov sl, r0
	ldr r0, [r6, #0x38]
	subs r0, #0xa0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	bl malloc
	mov sb, r0
	cmp r0, #0
	bne _08016AE4
	b _08016CE6
_08016AE4:
	ldr r2, _08016C44 @ =0x03001590
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	mov r3, sb
	str r3, [r0]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r2, r5
	ldr r0, _08016C48 @ =0x0400001C
	str r0, [r1]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r1, r2, r7
	ldr r0, _08016C4C @ =0xA6600001
	str r0, [r1]
	ldr r0, _08016C50 @ =0x02002200
	ldr r1, _08016C54 @ =0x0002D029
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08016B12
	b _08016C64
_08016B12:
	movs r4, #0x2c
	mov r0, sl
	muls r0, r4, r0
	movs r1, #0x64
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	muls r0, r4, r0
	movs r1, #0x64
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	movs r0, #0x48
	subs r0, r0, r1
	cmp r2, r0
	bge _08016B60
	lsls r2, r1, #0x10
	str r2, [sp]
	ldr r3, _08016C58 @ =0x0000FFFF
	mov ip, r3
	adds r4, r0, #0
	mov r3, sb
	adds r2, r4, #0
_08016B48:
	ldr r0, [r6, #0x68]
	lsrs r0, r0, #1
	adds r0, r5, r0
	mov r7, ip
	ands r0, r7
	ldr r7, [sp]
	orrs r0, r7
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bne _08016B48
	adds r2, r4, #0
_08016B60:
	movs r0, #0x68
	subs r0, r0, r1
	cmp r2, r0
	bge _08016B92
	lsls r3, r1, #0x10
	str r3, [sp]
	ldr r7, _08016C58 @ =0x0000FFFF
	mov ip, r7
	adds r4, r0, #0
	lsls r0, r2, #2
	mov r7, sb
	adds r3, r0, r7
	subs r2, r4, r2
_08016B7A:
	ldr r0, [r6, #0x68]
	lsrs r0, r0, #2
	adds r0, r5, r0
	mov r7, ip
	ands r0, r7
	ldr r7, [sp]
	orrs r0, r7
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bne _08016B7A
	adds r2, r4, #0
_08016B92:
	movs r0, #0x80
	subs r0, r0, r1
	cmp r2, r0
	bge _08016BC4
	lsls r3, r1, #0x10
	str r3, [sp]
	ldr r7, _08016C58 @ =0x0000FFFF
	mov ip, r7
	adds r4, r0, #0
	lsls r0, r2, #2
	mov r7, sb
	adds r3, r0, r7
	subs r2, r4, r2
_08016BAC:
	ldr r0, [r6, #0x68]
	lsrs r0, r0, #3
	adds r0, r5, r0
	mov r7, ip
	ands r0, r7
	ldr r7, [sp]
	orrs r0, r7
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bne _08016BAC
	adds r2, r4, #0
_08016BC4:
	movs r0, #0xa0
	subs r0, r0, r1
	cmp r2, r0
	bge _08016BF2
	lsls r4, r1, #0x10
	ldr r1, _08016C58 @ =0x0000FFFF
	mov ip, r1
	adds r3, r0, #0
	lsls r0, r2, #2
	mov r7, sb
	adds r1, r0, r7
	subs r2, r3, r2
_08016BDC:
	ldr r0, [r6, #0x68]
	lsrs r0, r0, #4
	adds r0, r5, r0
	mov r7, ip
	ands r0, r7
	orrs r0, r4
	stm r1!, {r0}
	subs r2, #1
	cmp r2, #0
	bne _08016BDC
	adds r2, r3, #0
_08016BF2:
	cmp r2, #0x9f
	bgt _08016CE6
	mov r1, r8
	adds r0, r1, r2
	ldr r4, _08016C5C @ =0x0000015F
	cmp r0, r4
	bgt _08016C22
	lsls r0, r2, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	mov r5, sb
	adds r3, r0, r5
	ldr r5, _08016C60 @ =0xFFFF0000
_08016C10:
	stm r3!, {r1}
	adds r1, r1, r5
	adds r2, #1
	cmp r2, #0x9f
	bgt _08016CE6
	mov r6, r8
	adds r0, r6, r2
	cmp r0, r4
	ble _08016C10
_08016C22:
	cmp r2, #0x9f
	bgt _08016CE6
	mov r0, r8
	adds r0, #0x40
	lsls r1, r0, #0x10
	mov r7, sl
	lsls r0, r7, #1
	add r0, sl
	lsrs r0, r0, #2
	orrs r1, r0
	lsls r0, r2, #2
	add r0, sb
_08016C3A:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _08016C3A
	b _08016CE6
	.align 2, 0
_08016C44: .4byte 0x03001590
_08016C48: .4byte 0x0400001C
_08016C4C: .4byte 0xA6600001
_08016C50: .4byte 0x02002200
_08016C54: .4byte 0x0002D029
_08016C58: .4byte 0x0000FFFF
_08016C5C: .4byte 0x0000015F
_08016C60: .4byte 0xFFFF0000
_08016C64:
	mov r1, r8
	lsls r0, r1, #5
	add r0, r8
	movs r1, #0x64
	bl __divsi3
	adds r0, #0x28
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0
	movs r0, #0xa0
	subs r0, r0, r1
	cmp r2, r0
	bge _08016C90
	lsls r3, r1, #0x10
	mov r1, sb
	adds r2, r0, #0
_08016C86:
	stm r1!, {r3}
	subs r2, #1
	cmp r2, #0
	bne _08016C86
	adds r2, r0, #0
_08016C90:
	cmp r2, #0x9f
	bgt _08016CE0
	mov r3, r8
	adds r0, r3, r2
	ldr r4, _08016CF8 @ =0x00000167
	cmp r0, r4
	bgt _08016CC0
	lsls r0, r2, #0x10
	movs r1, #0xa8
	lsls r1, r1, #0x10
	subs r1, r1, r0
	lsls r0, r2, #2
	mov r5, sb
	adds r3, r0, r5
	ldr r5, _08016CFC @ =0xFFFF0000
_08016CAE:
	stm r3!, {r1}
	adds r1, r1, r5
	adds r2, #1
	cmp r2, #0x9f
	bgt _08016CE0
	mov r6, r8
	adds r0, r6, r2
	cmp r0, r4
	ble _08016CAE
_08016CC0:
	cmp r2, #0x9f
	bgt _08016CE0
	mov r0, r8
	adds r0, #0x40
	lsls r1, r0, #0x10
	mov r7, sl
	lsls r0, r7, #1
	add r0, sl
	lsrs r0, r0, #2
	orrs r1, r0
	lsls r0, r2, #2
	add r0, sb
_08016CD8:
	stm r0!, {r1}
	adds r2, #1
	cmp r2, #0x9f
	ble _08016CD8
_08016CE0:
	movs r0, #0x77
	bl FUN_08004068
_08016CE6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016CF8: .4byte 0x00000167
_08016CFC: .4byte 0xFFFF0000

	thumb_func_start FUN_08016d00
FUN_08016d00: @ 0x08016D00
	push {lr}
	movs r0, #0x77
	bl clearBlink
	movs r0, #0xc7
	bl clearBlink
	movs r0, #0xc8
	bl clearBlink
	movs r0, #0x89
	lsls r0, r0, #1
	bl clearBlink
	ldr r0, _08016D28 @ =0x00000113
	bl clearBlink
	pop {r0}
	bx r0
	.align 2, 0
_08016D28: .4byte 0x00000113

	thumb_func_start base_08016d2c
base_08016d2c: @ 0x08016D2C
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _08016D5C
	ldr r1, [r3, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _08016D60 @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08016D64 @ =0x0000FFFC
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _08016D68 @ =0x02002180
	ldr r0, _08016D6C @ =0x00003748
	strh r0, [r1]
	ldr r0, _08016D70 @ =0x00000808
	strh r0, [r1, #2]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08016D5C:
	pop {r0}
	bx r0
	.align 2, 0
_08016D60: .4byte 0x02002144
_08016D64: .4byte 0x0000FFFC
_08016D68: .4byte 0x02002180
_08016D6C: .4byte 0x00003748
_08016D70: .4byte 0x00000808

	thumb_func_start FUN_08016d74
FUN_08016d74: @ 0x08016D74
	ldr r1, _08016D7C @ =0x02002180
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_08016D7C: .4byte 0x02002180

	thumb_func_start base_08016d80
base_08016d80: @ 0x08016D80
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0xe]
	cmp r0, #0
	bne _08016DA6
	ldr r1, [r3, #0x5c]
	lsrs r1, r1, #4
	lsls r1, r1, #1
	ldr r0, _08016DAC @ =0x02002144
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _08016DB0 @ =0x0000FFFC
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, #0xe]
	adds r0, #1
	strb r0, [r3, #0xe]
_08016DA6:
	pop {r0}
	bx r0
	.align 2, 0
_08016DAC: .4byte 0x02002144
_08016DB0: .4byte 0x0000FFFC
