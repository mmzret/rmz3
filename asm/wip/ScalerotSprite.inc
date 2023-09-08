	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r7, _0800067C @ =gOamManager
	ldr r0, [r5, #0x10]
	lsls r0, r0, #2
	lsrs r0, r0, #0x1b
	lsls r0, r0, #5
	adds r7, r7, r0
	strb r6, [r5, #0x1b]
	lsls r6, r6, #1
	ldrb r0, [r5, #0x18]
	ldrb r1, [r5, #0x19]
	eors r0, r1
	beq _080005B8
	rsbs r6, r6, #0
	lsls r6, r6, #0x17
	lsrs r6, r6, #0x17
_080005B8:
	movs r1, #0x80
	adds r1, r1, r6
	lsls r1, r1, #0x17
	lsrs r1, r1, #0x17
	mov r8, r1
	ldrb r0, [r5, #0x18]
	orrs r0, r0
	beq _080005F2
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1c]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r7, #6]
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1c]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r7, #0xe]
	b _08000616
_080005F2:
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1c]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	strh r0, [r7, #6]
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1c]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	strh r0, [r7, #0xe]
_08000616:
	ldrb r0, [r5, #0x19]
	orrs r0, r0
	beq _08000646
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1e]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	strh r0, [r7, #0x16]
	mov r1, r8
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1e]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r7, #0x1e]
	b _0800066E
_08000646:
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1e]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	rsbs r0, r0, #0
	strh r0, [r7, #0x16]
	mov r1, r8
	ldr r0, _08000678 @ =gSineTable
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x1e]
	movs r2, #0x16
	adds r1, r1, r2
	bl __divsi3
	strh r0, [r7, #0x1e]
_0800066E:
	pop {r7}
	mov r8, r7
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08000678: .4byte gSineTable
_0800067C: .4byte gOamManager
_08000680: .4byte gOamManager+1024
_08000684: .4byte 0x176
