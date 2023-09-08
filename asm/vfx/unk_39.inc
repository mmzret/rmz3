	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CreateVFX39
CreateVFX39: @ 0x080BD3BC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _080BD41C @ =gVFXHeaderPtr
	ldr r0, [r0]
	bl AllocEntityFirst
	adds r3, r0, #0
	cmp r3, #0
	beq _080BD412
	adds r1, r3, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BD420 @ =gVFXFnTable
	movs r1, #0x27
	strb r1, [r3, #9]
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r0, [r0]
	str r0, [r3, #0x14]
	movs r0, #0
	strh r2, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r3, #0x54]
	str r1, [r3, #0x58]
	strb r5, [r3, #0x10]
	strb r4, [r3, #0x11]
	adds r1, r3, #0
	adds r1, #0x7c
	movs r0, #0x31
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xe
	strb r0, [r1]
_080BD412:
	adds r0, r3, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BD41C: .4byte gVFXHeaderPtr
_080BD420: .4byte gVFXFnTable

	thumb_func_start VFX39_Init
VFX39_Init: @ 0x080BD424
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x34
	ldr r1, _080BD46C @ =FUN_080bd610
	bl SetTaskCallback
	str r4, [r4, #0x3c]
	ldrb r1, [r4, #0xa]
	movs r0, #0xf7
	ands r0, r1
	movs r2, #0
	movs r1, #1
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
	adds r0, r4, #0
	adds r0, #0x77
	strb r2, [r0]
	str r2, [r4, #0x60]
	ldr r1, _080BD470 @ =gVFXFnTable
	ldrb r0, [r4, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r4, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	str r0, [r4, #0x14]
	adds r0, r4, #0
	bl VFX39_Update
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BD46C: .4byte FUN_080bd610
_080BD470: .4byte gVFXFnTable

	thumb_func_start VFX39_Update
VFX39_Update: @ 0x080BD474
	push {lr}
	ldr r2, _080BD488 @ =0x0836EEB0
	ldrb r1, [r0, #0x10]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080BD488: .4byte 0x0836EEB0

	thumb_func_start FUN_080bd48c
FUN_080bd48c: @ 0x080BD48C
	push {lr}
	mov ip, r0
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	bne _080BD4CE
	ldr r1, _080BD4E4 @ =gWindowRegBuffer
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x31
	strb r0, [r1, #0xd]
	ldrb r2, [r1, #0xe]
	movs r0, #0xe
	orrs r0, r2
	strb r0, [r1, #0xe]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r1, ip
	str r0, [r1, #0x78]
	mov r0, ip
	adds r0, #0x74
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	ldrb r0, [r1, #0xe]
	adds r0, #1
	strb r0, [r1, #0xe]
_080BD4CE:
	ldr r1, _080BD4E8 @ =gJoypad
	ldrh r2, [r1]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080BD4EC
	mov r2, ip
	ldr r0, [r2, #0x78]
	movs r3, #0x80
	lsls r3, r3, #1
	b _080BD4FA
	.align 2, 0
_080BD4E4: .4byte gWindowRegBuffer
_080BD4E8: .4byte gJoypad
_080BD4EC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080BD4FE
	mov r2, ip
	ldr r0, [r2, #0x78]
	ldr r3, _080BD514 @ =0xFFFFFF00
_080BD4FA:
	adds r0, r0, r3
	str r0, [r2, #0x78]
_080BD4FE:
	ldrh r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r1, #0
	ands r0, r2
	cmp r0, r1
	bne _080BD518
	movs r0, #0
	mov r1, ip
	str r0, [r1, #0x60]
	b _080BD53E
	.align 2, 0
_080BD514: .4byte 0xFFFFFF00
_080BD518:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080BD52C
	mov r2, ip
	ldr r0, [r2, #0x60]
	adds r0, #0x10
	str r0, [r2, #0x60]
	b _080BD53E
_080BD52C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080BD53E
	mov r3, ip
	ldr r0, [r3, #0x60]
	subs r0, #0x10
	str r0, [r3, #0x60]
_080BD53E:
	mov r1, ip
	ldrb r0, [r1, #0x13]
	adds r0, #1
	strb r0, [r1, #0x13]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080BD55E
	mov r0, ip
	adds r0, #0x74
	movs r1, #0x1f
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	b _080BD572
_080BD55E:
	mov r0, ip
	adds r0, #0x74
	movs r1, #0x18
	strb r1, [r0]
	mov r2, ip
	adds r2, #0x75
	movs r0, #0x1f
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x76
_080BD572:
	strb r1, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_080bd578
FUN_080bd578: @ 0x080BD578
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0xe]
	cmp r4, #0
	bne _080BD5A8
	ldr r2, _080BD5CC @ =gWindowRegBuffer
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #7
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	adds r1, r3, #0
	adds r1, #0x7d
	ldrb r0, [r2, #0xe]
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #0xe]
	adds r0, r4, #1
	strb r0, [r3, #0xe]
_080BD5A8:
	adds r0, r3, #0
	adds r0, #0x77
	ldrb r0, [r0]
	cmp r0, #0
	beq _080BD5C4
	ldr r1, _080BD5D0 @ =gVFXFnTable
	ldrb r0, [r3, #9]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #2
	str r1, [r3, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	str r0, [r3, #0x14]
_080BD5C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD5CC: .4byte gWindowRegBuffer
_080BD5D0: .4byte gVFXFnTable

	thumb_func_start VFX39_Die
VFX39_Die: @ 0x080BD5D4
	ldr r2, _080BD600 @ =gPaletteManager
	movs r1, #0
	strh r1, [r2]
	ldr r3, _080BD604 @ =gWindowRegBuffer
	ldrh r2, [r3]
	ldr r1, _080BD608 @ =0x0000BFFF
	ands r1, r2
	strh r1, [r3]
	ldrb r2, [r0, #0xa]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0, #0xa]
	ldr r2, _080BD60C @ =gVFXFnTable
	ldrb r1, [r0, #9]
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #4
	str r2, [r0, #0xc]
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.align 2, 0
_080BD600: .4byte gPaletteManager
_080BD604: .4byte gWindowRegBuffer
_080BD608: .4byte 0x0000BFFF
_080BD60C: .4byte gVFXFnTable

	thumb_func_start FUN_080bd610
FUN_080bd610: @ 0x080BD610
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r0, [r0, #8]
	str r0, [sp]
	ldr r0, [r0, #0x78]
	asrs r0, r0, #8
	str r0, [sp, #4]
	ldr r2, [sp]
	ldr r0, [r2, #0x54]
	ldr r2, [r1, #8]
	subs r0, r0, r2
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldr r3, [sp]
	ldr r2, [r3, #0x58]
	ldr r0, [r1, #0xc]
	subs r2, r2, r0
	lsls r2, r2, #8
	ldr r3, _080BD68C @ =gPaletteManager
	ldr r0, [sp]
	adds r0, #0x76
	ldrb r1, [r0]
	lsls r1, r1, #0xa
	ldr r0, [sp]
	adds r0, #0x75
	ldrb r0, [r0]
	lsls r0, r0, #5
	orrs r1, r0
	ldr r0, [sp]
	adds r0, #0x74
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r3]
	lsrs r4, r2, #0x10
	str r4, [sp, #0xc]
	asrs r2, r2, #0x10
	rsbs r5, r2, #0
	str r5, [sp, #0x18]
	cmp r2, #0
	blt _080BD676
	movs r7, #0
	str r7, [sp, #0x18]
	cmp r2, #0x9f
	ble _080BD676
	subs r2, #0xa0
	str r2, [sp, #0x18]
_080BD676:
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _080BD682
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bgt _080BD694
_080BD682:
	ldr r1, _080BD690 @ =gWindowRegBuffer
	movs r0, #0
	strh r0, [r1, #6]
	b _080BDAD6
	.align 2, 0
_080BD68C: .4byte gPaletteManager
_080BD690: .4byte gWindowRegBuffer
_080BD694:
	ldr r2, [sp, #4]
	ldr r3, [sp, #0x18]
	subs r7, r2, r3
	cmp r7, #0xa0
	ble _080BD6A0
	movs r7, #0xa0
_080BD6A0:
	ldr r4, [sp, #4]
	asrs r0, r4, #5
	cmp r0, #4
	ble _080BD6AE
	movs r5, #4
	str r5, [sp, #0x10]
	b _080BD6B4
_080BD6AE:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
_080BD6B4:
	adds r0, r7, #1
	lsls r4, r0, #1
	adds r0, r4, #0
	bl Malloc
	mov sl, r0
	cmp r0, #0
	bne _080BD6C6
	b _080BDAD8
_080BD6C6:
	movs r0, #0
	mov r1, sl
	adds r2, r4, #0
	bl FillMemory
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _080BD6EE
	ldr r1, [sp, #4]
	adds r0, r1, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x18]
	adds r1, r2, #0
	muls r1, r2, r1
	subs r0, r0, r1
	bl Sqrt
	mov r3, sl
	strh r0, [r3]
	b _080BD6F6
_080BD6EE:
	mov r4, sp
	ldrh r5, [r4, #4]
	mov r4, sl
	strh r5, [r4]
_080BD6F6:
	movs r0, #0
	mov r8, r0
	movs r6, #0
	movs r1, #0
	movs r0, #1
	ldr r2, [sp, #0x10]
	lsls r0, r2
	cmp r7, r0
	ble _080BD70A
	movs r1, #1
_080BD70A:
	str r1, [sp, #0x14]
	cmp r1, #0
	beq _080BD780
	cmp r8, r7
	bhi _080BD770
	mov sb, r0
	mov r5, sl
	lsls r0, r0, #1
	adds r4, r0, r5
	ldr r0, [sp, #4]
	adds r3, r0, #0
	muls r3, r0, r3
	str r3, [sp, #0x1c]
_080BD724:
	adds r1, r6, #0
	add r1, sb
	mov r8, r1
	ldr r0, [sp, #0x18]
	add r0, r8
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r3, [sp, #0x1c]
	subs r0, r3, r0
	bl Sqrt
	strh r0, [r4]
	ldrh r1, [r5]
	ldrh r0, [r4]
	subs r0, r1, r0
	lsls r3, r0, #0x10
	ldr r0, [sp, #0x10]
	asrs r3, r0
	lsls r1, r1, #0x10
	adds r5, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	bhs _080BD76C
	lsls r2, r6, #1
	add r2, sl
_080BD75A:
	subs r1, r1, r3
	lsrs r0, r1, #0x10
	strh r0, [r2]
	adds r2, #2
	adds r5, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	blo _080BD75A
_080BD76C:
	cmp r6, r7
	bls _080BD724
_080BD770:
	ldr r1, [sp, #0x14]
	cmp r1, #0
	beq _080BD780
	movs r0, #1
	ldr r2, [sp, #0x10]
	lsls r0, r2
	subs r6, r7, r0
	b _080BD782
_080BD780:
	movs r6, #0
_080BD782:
	cmp r6, r7
	bhi _080BD7AC
	ldr r3, [sp, #4]
	adds r5, r3, #0
	muls r5, r3, r5
	lsls r0, r6, #1
	mov r1, sl
	adds r4, r0, r1
_080BD792:
	ldr r2, [sp, #0x18]
	adds r0, r6, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	subs r0, r5, r0
	bl Sqrt
	strh r0, [r4]
	adds r4, #2
	adds r6, #1
	cmp r6, r7
	bls _080BD792
_080BD7AC:
	movs r0, #2
	ldr r4, [sp, #0x10]
	lsls r0, r4
	movs r6, #0
	cmp r8, r0
	bls _080BD7BC
	mov r5, r8
	subs r6, r5, r0
_080BD7BC:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _080BD7CE
	movs r0, #1
	ldr r1, [sp, #0x10]
	lsls r0, r1
	subs r0, r7, r0
	mov r8, r0
	b _080BD7D2
_080BD7CE:
	movs r2, #0
	mov r8, r2
_080BD7D2:
	cmp r6, r8
	beq _080BD80C
	lsls r0, r6, #1
	add r0, sl
	ldrh r4, [r0]
	mov r3, r8
	lsls r0, r3, #1
	add r0, sl
	ldrh r0, [r0]
	subs r0, r4, r0
	lsls r0, r0, #0x10
	subs r1, r3, r6
	bl __udivsi3
	adds r3, r0, #0
	lsls r1, r4, #0x10
	adds r6, #1
	cmp r6, r8
	bhs _080BD80C
	lsls r0, r6, #1
	mov r4, sl
	adds r2, r0, r4
_080BD7FE:
	subs r1, r1, r3
	lsrs r0, r1, #0x10
	strh r0, [r2]
	adds r2, #2
	adds r6, #1
	cmp r6, r8
	blo _080BD7FE
_080BD80C:
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r0, r4, #0
	bl Malloc
	mov sb, r0
	cmp r0, #0
	bne _080BD81E
	b _080BDAD2
_080BD81E:
	movs r0, #0
	mov r1, sb
	adds r2, r4, #0
	bl FillMemory
	ldr r5, [sp, #0xc]
	lsls r0, r5, #0x10
	lsrs r1, r0, #0x10
	mov ip, r0
	cmp r1, #0x9f
	bhi _080BD87A
	mov r7, sl
	ldrh r2, [r7, #2]
	ldr r1, [sp, #8]
	subs r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _080BD846
	movs r1, #0
_080BD846:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD850
	movs r1, #0xf0
_080BD850:
	ldr r3, [sp, #8]
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _080BD85E
	movs r3, #0
_080BD85E:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD868
	movs r3, #0xf0
_080BD868:
	mov r4, ip
	asrs r2, r4, #0xf
	add r2, sb
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r2]
_080BD87A:
	mov r5, ip
	asrs r1, r5, #0x10
	ldr r7, [sp, #4]
	rsbs r7, r7, #0
	str r7, [sp, #0x20]
	cmp r1, #0
	blt _080BD97E
	ldr r0, [sp, #4]
	adds r0, #0xa0
	cmp r1, r0
	bge _080BD97E
	adds r6, r1, #0
	subs r6, #0xa0
	cmp r1, #0x9f
	bgt _080BD89A
	movs r6, #1
_080BD89A:
	ldr r2, [sp, #4]
	subs r0, r1, r2
	mov r8, r2
	cmp r0, #0
	bge _080BD8A8
	adds r3, r1, #1
	mov r8, r3
_080BD8A8:
	ldr r4, [sp]
	ldr r4, [r4, #0x60]
	str r4, [sp, #0x24]
	cmp r4, #0
	beq _080BD920
	cmp r6, r8
	bhs _080BD97E
	lsls r0, r6, #1
	lsls r1, r1, #1
	add r1, sb
	subs r5, r1, r0
	ldr r7, [sp, #0x18]
	lsls r1, r7, #1
	mov r2, sl
	subs r1, r2, r1
	adds r4, r0, r1
_080BD8C8:
	ldrh r3, [r4]
	ldr r7, [sp, #8]
	subs r0, r7, r3
	ldr r2, [sp, #0x18]
	adds r1, r2, r6
	ldr r7, [sp, #0x24]
	muls r1, r7, r1
	lsrs r2, r1, #8
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _080BD8E4
	movs r1, #0
_080BD8E4:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD8EE
	movs r1, #0xf0
_080BD8EE:
	ldr r7, [sp, #8]
	adds r0, r3, r7
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _080BD8FE
	movs r3, #0
_080BD8FE:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD908
	movs r3, #0xf0
_080BD908:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r5]
	subs r5, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	blo _080BD8C8
	b _080BD97E
_080BD920:
	cmp r6, r8
	bhs _080BD97E
	lsls r0, r6, #1
	lsls r1, r1, #1
	add r1, sb
	subs r5, r1, r0
	ldr r2, [sp, #0x18]
	lsls r1, r2, #1
	mov r3, sl
	subs r1, r3, r1
	adds r4, r0, r1
_080BD936:
	ldrh r2, [r4]
	ldr r7, [sp, #8]
	subs r0, r7, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _080BD946
	movs r1, #0
_080BD946:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD950
	movs r1, #0xf0
_080BD950:
	ldr r3, [sp, #8]
	adds r0, r2, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _080BD95E
	movs r3, #0
_080BD95E:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD968
	movs r3, #0xf0
_080BD968:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r5]
	subs r5, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	blo _080BD936
_080BD97E:
	mov r4, ip
	asrs r1, r4, #0x10
	ldr r5, [sp, #0x20]
	cmp r1, r5
	blt _080BDA80
	cmp r1, #0x9f
	bgt _080BDA80
	rsbs r6, r1, #0
	cmp r1, #0
	blt _080BD994
	movs r6, #1
_080BD994:
	ldr r7, [sp, #4]
	adds r0, r1, r7
	cmp r0, #0x9f
	ble _080BD9A2
	movs r0, #0xa0
	subs r0, r0, r1
	b _080BD9A4
_080BD9A2:
	ldr r0, [sp, #4]
_080BD9A4:
	mov r8, r0
	ldr r1, [sp]
	ldr r1, [r1, #0x60]
	str r1, [sp, #0x24]
	cmp r1, #0
	beq _080BDA20
	cmp r6, r8
	bhs _080BDA80
	lsls r0, r6, #1
	mov r2, ip
	asrs r1, r2, #0xf
	add r1, sb
	adds r2, r0, r1
	ldr r3, [sp, #0x18]
	lsls r1, r3, #1
	mov r4, sl
	subs r1, r4, r1
	adds r5, r0, r1
_080BD9C8:
	ldrh r4, [r5]
	ldr r7, [sp, #8]
	subs r0, r7, r4
	ldr r3, [sp, #0x18]
	adds r1, r3, r6
	ldr r7, [sp, #0x24]
	muls r1, r7, r1
	lsrs r3, r1, #8
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _080BD9E4
	movs r1, #0
_080BD9E4:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BD9EE
	movs r1, #0xf0
_080BD9EE:
	ldr r7, [sp, #8]
	adds r0, r4, r7
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _080BD9FE
	movs r3, #0
_080BD9FE:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BDA08
	movs r3, #0xf0
_080BDA08:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r5, #2
	adds r6, #1
	cmp r6, r8
	blo _080BD9C8
	b _080BDA80
_080BDA20:
	cmp r6, r8
	bhs _080BDA80
	lsls r0, r6, #1
	mov r2, ip
	asrs r1, r2, #0xf
	add r1, sb
	adds r2, r0, r1
	ldr r3, [sp, #0x18]
	lsls r1, r3, #1
	mov r4, sl
	subs r1, r4, r1
	adds r4, r0, r1
_080BDA38:
	ldrh r3, [r4]
	ldr r5, [sp, #8]
	subs r0, r5, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge _080BDA48
	movs r1, #0
_080BDA48:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BDA52
	movs r1, #0xf0
_080BDA52:
	ldr r7, [sp, #8]
	adds r0, r3, r7
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r0, #0
	bge _080BDA60
	movs r3, #0
_080BDA60:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _080BDA6A
	movs r3, #0xf0
_080BDA6A:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r2]
	adds r2, #2
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	blo _080BDA38
_080BDA80:
	ldr r1, [sp]
	ldrb r0, [r1, #0x10]
	cmp r0, #3
	bne _080BDAB0
	ldr r2, _080BDAA8 @ =gIntrManager
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r2, r3
	mov r4, sb
	str r4, [r0]
	movs r5, #0xca
	lsls r5, r5, #1
	adds r1, r2, r5
	ldr r0, _080BDAAC @ =0x04000042
	str r0, [r1]
	movs r7, #0xcc
	lsls r7, r7, #1
	adds r1, r2, r7
	b _080BDACE
	.align 2, 0
_080BDAA8: .4byte gIntrManager
_080BDAAC: .4byte 0x04000042
_080BDAB0:
	ldr r1, _080BDAE8 @ =gIntrManager
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, sb
	str r3, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r1, r4
	ldr r0, _080BDAEC @ =0x04000042
	str r0, [r1]
	ldr r5, _080BDAE8 @ =gIntrManager
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r1, r5, r7
_080BDACE:
	ldr r0, _080BDAF0 @ =0xA2600001
	str r0, [r1]
_080BDAD2:
	ldr r1, _080BDAF4 @ =gWindowRegBuffer
	movs r0, #0xa0
_080BDAD6:
	strh r0, [r1, #0xa]
_080BDAD8:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BDAE8: .4byte gIntrManager
_080BDAEC: .4byte 0x04000042
_080BDAF0: .4byte 0xA2600001
_080BDAF4: .4byte gWindowRegBuffer
