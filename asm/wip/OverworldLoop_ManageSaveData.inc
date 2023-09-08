	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrb r0, [r6, #3]
	subs r0, #0x3f
	cmp r0, #0x37
	bls _080F0672
	bl _RETURN
_080F0672:
	lsls r0, r0, #2
	ldr r1, _080F067C @ =_080F0680
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F067C: .4byte _080F0680
_080F0680: @ jump table
	.4byte _080F0760 @ case 0
	.4byte _080F0780 @ case 1
	.4byte _080F07A0 @ case 2
	.4byte _080F07F4 @ case 3
	.4byte _080F080C @ case 4
	.4byte _080F08B0 @ case 5
	.4byte _080F08C2 @ case 6
	.4byte _080F0C74 @ case 7
	.4byte _080F0C84 @ case 8
	.4byte _080F0D20 @ case 9
	.4byte _080F07FC @ case 10
	.4byte _080F080C @ case 11
	.4byte _080F08B0 @ case 12
	.4byte _080F08C2 @ case 13
	.4byte _080F0D4C @ case 14
	.4byte _080F0D5C @ case 15
	.4byte _080F0DE0 @ case 16
	.4byte _080F0E36 @ case 17
	.4byte _080F0E7C @ case 18
	.4byte _080F0804 @ case 19
	.4byte _080F080C @ case 20
	.4byte _080F08B0 @ case 21
	.4byte _080F08C2 @ case 22
	.4byte _080F0FE0 @ case 23
	.4byte _080F0FF0 @ case 24
	.4byte _RETURN @ case 25
	.4byte _RETURN @ case 26
	.4byte _RETURN @ case 27
	.4byte _RETURN @ case 28
	.4byte _RETURN @ case 29
	.4byte _RETURN @ case 30
	.4byte _RETURN @ case 31
	.4byte _RETURN @ case 32
	.4byte _080F07FC @ case 33
	.4byte _080F080C @ case 34
	.4byte _080F08B0 @ case 35
	.4byte _080F08C2 @ case 36
	.4byte _080F0D4C @ case 37
	.4byte _080F0D5C @ case 38
	.4byte _080F0DE0 @ case 39
	.4byte _080F0E36 @ case 40
	.4byte _080F0E7C @ case 41
	.4byte _080F106A @ case 42
	.4byte _RETURN @ case 43
	.4byte _RETURN @ case 44
	.4byte _RETURN @ case 45
	.4byte _RETURN @ case 46
	.4byte _RETURN @ case 47
	.4byte _RETURN @ case 48
	.4byte _080F07F4 @ case 49
	.4byte _080F080C @ case 50
	.4byte _080F08B0 @ case 51
	.4byte _080F08C2 @ case 52
	.4byte _080F0C74 @ case 53
	.4byte _080F0C84 @ case 54
	.4byte _080F0D20 @ case 55
_080F0760:
	ldr r2, _080F0774 @ =gTextWindow+8
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq _080F0778
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	bl _RETURN
	.align 2, 0
_080F0774: .4byte gTextWindow+8
_080F0778:
	movs r1, #0x80
	lsls r1, r1, #3
	bl _080f0fd4
_080F0780:
	ldr r0, _080F07D4 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080F0790
	cmp r0, #4
	beq _080F0790
	bl _RETURN
_080F0790:
	movs r0, #2
	bl PrintOptionMessage1
	movs r0, #0
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F07A0:
	ldr r0, _080F07D4 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080F07B0
	cmp r0, #4
	beq _080F07B0
	bl _RETURN
_080F07B0:
	adds r0, r6, #0
	bl save_080f32f8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bne _080F07C2
	bl _RETURN
_080F07C2:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _080F07D8
	movs r0, #0x42
	strb r0, [r6, #3]
	bl _RETURN
	.align 2, 0
_080F07D4: .4byte gTextWindow+8
_080F07D8:
	cmp r0, #2
	bne _080F07E4
	movs r0, #0x49
	strb r0, [r6, #3]
	bl _RETURN
_080F07E4:
	cmp r0, #3
	bne _080F07EC
	bl _080F1064
_080F07EC:
	movs r0, #0x3f
	strb r0, [r6, #3]
	bl _RETURN
_080F07F4:
	movs r0, #3
	bl PrintOptionMessage1
	b _080F0DC0
_080F07FC:
	movs r0, #5
	bl PrintOptionMessage1
	b _080F0DC0
_080F0804:
	movs r0, #7
	bl PrintOptionMessage1
	b _080F0DC0
_080F080C:
	movs r4, #0
	ldr r0, _080F083C @ =0x020005F8
	mov sl, r0
	ldr r7, _080F0840 @ =0x0200055C
	ldr r1, _080F0844 @ =0xFFFFFE4C
	adds r1, r1, r7
	mov sb, r1
_080F081A:
	lsls r0, r4, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	movs r1, #0x94
	lsls r1, r1, #2
	bl CheckSavedataCorrect
	adds r2, r0, #0
	cmp r2, #0
	bne _080F0848
	lsls r1, r4, #0x10
	asrs r0, r1, #0x10
	add r0, sl
	strb r2, [r0]
	mov r8, r1
	b _080F089C
	.align 2, 0
_080F083C: .4byte 0x020005F8
_080F0840: .4byte 0x0200055C
_080F0844: .4byte 0xFFFFFE4C
_080F0848:
	lsls r4, r4, #0x10
	asrs r0, r4, #0x10
	add r0, sl
	movs r1, #1
	strb r1, [r0]
	adds r0, r5, #0
	ldr r1, _080F09CC @ =0x020003A8
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003378
	mov r8, r4
	ldr r4, _080F09D0 @ =gSramState
_080F0862:
	bl sramScript
	ldrb r0, [r4]
	cmp r0, #1
	beq _080F0862
	movs r2, #0x1e
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _080F0862
	ldr r1, _080F09D4 @ =0x02000600
	mov r5, r8
	asrs r3, r5, #0x10
	lsls r2, r3, #2
	adds r1, r2, r1
	ldr r0, [r7, #0xc]
	str r0, [r1]
	ldr r0, _080F09D8 @ =0x02000618
	adds r2, r2, r0
	ldrb r0, [r7, #1]
	str r0, [r2]
	ldr r0, _080F09DC @ =0x0200062C
	adds r0, r3, r0
	mov r2, sb
	ldrh r1, [r2]
	strb r1, [r0]
	ldr r0, _080F09E0 @ =0x02000634
	adds r3, r3, r0
	ldrh r0, [r2, #2]
	strb r0, [r3]
_080F089C:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _080F081A
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F08B0:
	movs r0, #0
	strh r0, [r6, #4]
	strh r0, [r6, #6]
	strh r0, [r6, #8]
	movs r0, #0xf
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F08C2:
	ldr r0, _080F09E4 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080F08D2
	cmp r0, #4
	beq _080F08D2
	bl _RETURN
_080F08D2:
	movs r5, #4
	ldrsh r0, [r6, r5]
	cmp r0, #3
	bgt _080F08F2
	ldr r0, _080F09E8 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080F08F2
	movs r0, #1
	bl PlaySound
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_080F08F2:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0
	ble _080F0912
	ldr r0, _080F09E8 @ =gJoypad
	ldrh r1, [r0, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080F0912
	movs r0, #1
	bl PlaySound
	ldrh r0, [r6, #4]
	subs r0, #1
	strh r0, [r6, #4]
_080F0912:
	ldrh r3, [r6, #4]
	movs r2, #4
	ldrsh r1, [r6, r2]
	movs r5, #6
	ldrsh r0, [r6, r5]
	adds r2, r3, #0
	cmp r1, r0
	bge _080F0924
	strh r2, [r6, #6]
_080F0924:
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #6
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	ble _080F0936
	subs r0, r3, #1
	strh r0, [r6, #6]
_080F0936:
	movs r4, #0
_080F0938:
	lsls r0, r4, #0x10
	asrs r5, r0, #0x10
	movs r2, #6
	ldrsh r1, [r6, r2]
	subs r1, r5, r1
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x18
	mov ip, r1
	lsls r7, r1, #0x18
	lsrs r1, r7, #0x18
	mov r8, r0
	cmp r1, #2
	bhi _080F0A26
	ldr r0, _080F09EC @ =0x020005F8
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F09F8
	ldr r1, _080F09F0 @ =StringOfsTable
	adds r0, r5, #0
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080F09F4 @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r1, _080F09E4 @ =gTextWindow+8
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _080F097C
	ldrb r0, [r1, #4]
	cmp r0, #1
	bne _080F097E
_080F097C:
	movs r2, #1
_080F097E:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #9
	subs r1, r1, r0
	ldr r5, _080F09E4 @ =gTextWindow+8
	mov r0, ip
	lsls r4, r0, #0x18
	asrs r2, r4, #0x18
	adds r2, #2
	ldrb r0, [r5, #5]
	adds r2, r2, r0
	adds r0, r3, #0
	bl PrintString
	ldr r0, _080F09F0 @ =StringOfsTable
	ldrh r1, [r0, #2]
	ldr r0, _080F09F4 @ =gStringData
	adds r3, r1, r0
	movs r1, #0
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _080F09B0
	ldrb r0, [r5, #4]
	cmp r0, #1
	bne _080F09B2
_080F09B0:
	movs r1, #1
_080F09B2:
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xb
	subs r1, r1, r0
	ldr r0, _080F09E4 @ =gTextWindow+8
	asrs r2, r4, #0x18
	adds r2, #2
	ldrb r0, [r0, #5]
	adds r2, r2, r0
	adds r0, r3, #0
	bl PrintString
	b _080F0A26
	.align 2, 0
_080F09CC: .4byte 0x020003A8
_080F09D0: .4byte gSramState
_080F09D4: .4byte 0x02000600
_080F09D8: .4byte 0x02000618
_080F09DC: .4byte 0x0200062C
_080F09E0: .4byte 0x02000634
_080F09E4: .4byte gTextWindow+8
_080F09E8: .4byte gJoypad
_080F09EC: .4byte 0x020005F8
_080F09F0: .4byte StringOfsTable
_080F09F4: .4byte gStringData
_080F09F8:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080F0B00 @ =0x02000618
	lsls r3, r5, #2
	adds r1, r3, r1
	ldrb r1, [r1]
	ldr r2, _080F0B04 @ =0x02000600
	adds r3, r3, r2
	ldr r2, [r3]
	ldr r3, _080F0B08 @ =0x0200062C
	adds r3, r5, r3
	ldrb r3, [r3]
	ldr r4, _080F0B0C @ =0x02000634
	adds r4, r5, r4
	ldrb r4, [r4]
	str r4, [sp]
	movs r5, #0x80
	lsls r5, r5, #0x12
	adds r4, r7, r5
	lsrs r4, r4, #0x18
	str r4, [sp, #4]
	bl PrintSaveDataRow
_080F0A26:
	movs r0, #0x80
	lsls r0, r0, #9
	add r0, r8
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _080F0A36
	b _080F0938
_080F0A36:
	ldr r0, _080F0B10 @ =StringOfsTable
	ldrh r1, [r0]
	ldr r0, _080F0B14 @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r0, _080F0B18 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0A50
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0A52
_080F0A50:
	movs r2, #1
_080F0A52:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	movs r0, #4
	ldrsh r2, [r6, r0]
	movs r5, #6
	ldrsh r0, [r6, r5]
	subs r2, r2, r0
	lsls r2, r2, #1
	adds r2, #2
	ldrb r0, [r4, #5]
	adds r2, r2, r0
	adds r0, r3, #0
	bl PrintString
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080F0A82
	b _080F0B84
_080F0A82:
	movs r2, #0
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _080F0A90
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0A92
_080F0A90:
	movs r2, #1
_080F0A92:
	lsls r1, r2, #3
	subs r1, r1, r2
	movs r0, #8
	subs r0, r0, r1
	cmp r0, #3
	ble _080F0B24
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _080F0ACE
	ldr r3, _080F0B1C @ =Unicode_CursorUp
	movs r2, #0
	ldr r0, _080F0B18 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0ABA
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0ABC
_080F0ABA:
	movs r2, #1
_080F0ABC:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #0x1c
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r2, #2
	adds r0, r3, #0
	bl PrintUnicodeString
_080F0ACE:
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #3
	beq _080F0B84
	ldr r3, _080F0B20 @ =Unicode_CursorDown
	movs r2, #0
	ldr r0, _080F0B18 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0AEA
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0AEC
_080F0AEA:
	movs r2, #1
_080F0AEC:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #0x1c
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r2, #5
	adds r0, r3, #0
	bl PrintUnicodeString
	b _080F0B84
	.align 2, 0
_080F0B00: .4byte 0x02000618
_080F0B04: .4byte 0x02000600
_080F0B08: .4byte 0x0200062C
_080F0B0C: .4byte 0x02000634
_080F0B10: .4byte StringOfsTable
_080F0B14: .4byte gStringData
_080F0B18: .4byte gTextWindow+8
_080F0B1C: .4byte Unicode_CursorUp
_080F0B20: .4byte Unicode_CursorDown
_080F0B24:
	movs r5, #6
	ldrsh r0, [r6, r5]
	cmp r0, #0
	beq _080F0B54
	ldr r3, _080F0B94 @ =Unicode_CursorUp
	movs r2, #0
	ldr r0, _080F0B98 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0B40
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0B42
_080F0B40:
	movs r2, #1
_080F0B42:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #7
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r2, #2
	adds r0, r3, #0
	bl PrintUnicodeString
_080F0B54:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #3
	beq _080F0B84
	ldr r3, _080F0B9C @ =Unicode_CursorDown
	movs r2, #0
	ldr r0, _080F0B98 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0B70
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0B72
_080F0B70:
	movs r2, #1
_080F0B72:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #7
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r2, #5
	adds r0, r3, #0
	bl PrintUnicodeString
_080F0B84:
	ldrh r1, [r6, #0xa]
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq _080F0BA0
	subs r0, r1, #1
	strh r0, [r6, #0xa]
	b _RETURN
	.align 2, 0
_080F0B94: .4byte Unicode_CursorUp
_080F0B98: .4byte gTextWindow+8
_080F0B9C: .4byte Unicode_CursorDown
_080F0BA0:
	ldr r0, _080F0BCC @ =gJoypad
	ldrh r1, [r0, #4]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080F0BE0
	movs r0, #3
	bl PlaySound
	ldrb r0, [r6, #3]
	cmp r0, #0x63
	bne _080F0BD4
	ldr r0, _080F0BD0 @ =gStageRun
	movs r5, #0xaa
	lsls r5, r5, #1
	adds r0, r0, r5
	str r4, [r0]
	movs r0, #0x69
	strb r0, [r6, #3]
	b _RETURN
	.align 2, 0
_080F0BCC: .4byte gJoypad
_080F0BD0: .4byte gStageRun
_080F0BD4:
	cmp r0, #0x73
	beq _080F0BDA
	b _080F1050
_080F0BDA:
	movs r0, #0x7c
	strb r0, [r6, #3]
	b _RETURN
_080F0BE0:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080F0BEA
	b _RETURN
_080F0BEA:
	ldrb r0, [r6, #3]
	cmp r0, #0x45
	beq _080F0BF4
	cmp r0, #0x73
	bne _080F0C52
_080F0BF4:
	movs r0, #2
	bl PlaySound
	ldr r0, _080F0C38 @ =0x020005F8
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F0C0A
	b _080F0DC0
_080F0C0A:
	ldr r5, _080F0C3C @ =0x00006270
	adds r0, r6, r5
	bl saveCurStory
	ldr r1, _080F0C40 @ =0x000064AC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _080F0C44 @ =0x00006460
	adds r1, r6, r2
	bl CopyZeroStatus
	ldrb r0, [r6, #4]
	ldr r1, _080F0C48 @ =0x02036DBC
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003330
	ldrb r0, [r6, #3]
	cmp r0, #0x45
	bne _080F0C4C
	movs r0, #0x48
	strb r0, [r6, #3]
	b _RETURN
	.align 2, 0
_080F0C38: .4byte 0x020005F8
_080F0C3C: .4byte 0x00006270
_080F0C40: .4byte 0x000064AC
_080F0C44: .4byte 0x00006460
_080F0C48: .4byte 0x02036DBC
_080F0C4C:
	movs r0, #0x76
	strb r0, [r6, #3]
	b _RETURN
_080F0C52:
	ldr r0, _080F0C68 @ =0x020005F8
	movs r5, #4
	ldrsh r1, [r6, r5]
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080F0C6C
	movs r0, #4
	bl PlaySound
	b _RETURN
	.align 2, 0
_080F0C68: .4byte 0x020005F8
_080F0C6C:
	movs r0, #2
	bl PlaySound
	b _080F0DC0
_080F0C74:
	movs r0, #4
	bl PrintOptionMessage1
	movs r0, #1
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F0C84:
	ldr r1, _080F0D04 @ =StringOfsTable
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080F0D08 @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r0, _080F0D0C @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0CA8
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0CAA
_080F0CA8:
	movs r2, #1
_080F0CAA:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r0, r3, #0
	bl PrintString
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _080F0CC6
	cmp r0, #4
	beq _080F0CC6
	b _RETURN
_080F0CC6:
	adds r0, r6, #0
	bl handleWrapTwoChoice
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bne _080F0CD6
	b _RETURN
_080F0CD6:
	lsls r0, r4, #0x10
	cmp r0, #0
	bgt _080F0CDE
	b _080F0DD8
_080F0CDE:
	ldr r5, _080F0D10 @ =0x00006270
	adds r0, r6, r5
	bl saveCurStory
	ldr r1, _080F0D14 @ =0x000064AC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _080F0D18 @ =0x00006460
	adds r1, r6, r2
	bl CopyZeroStatus
	ldrb r0, [r6, #4]
	ldr r1, _080F0D1C @ =0x02036DBC
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003330
	b _080F0DC0
	.align 2, 0
_080F0D04: .4byte StringOfsTable
_080F0D08: .4byte gStringData
_080F0D0C: .4byte gTextWindow+8
_080F0D10: .4byte 0x00006270
_080F0D14: .4byte 0x000064AC
_080F0D18: .4byte 0x00006460
_080F0D1C: .4byte 0x02036DBC
_080F0D20:
	ldr r1, _080F0D48 @ =gSramState
	ldrb r0, [r1]
	cmp r0, #2
	bne _080F0D2A
	b _RETURN
_080F0D2A:
	movs r5, #0x1c
	ldrsh r0, [r1, r5]
	cmp r0, #0
	bne _080F0D34
	b _RETURN
_080F0D34:
	movs r0, #9
	bl PrintOptionMessage2
	ldrb r0, [r6, #3]
	cmp r0, #0x48
	bne _080F0D42
	b _080F1050
_080F0D42:
	movs r0, #0x77
	strb r0, [r6, #3]
	b _RETURN
	.align 2, 0
_080F0D48: .4byte gSramState
_080F0D4C:
	movs r0, #6
	bl PrintOptionMessage1
	movs r0, #0
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F0D5C:
	ldr r1, _080F0DC8 @ =StringOfsTable
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080F0DCC @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r0, _080F0DD0 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0D80
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0D82
_080F0D80:
	movs r2, #1
_080F0D82:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r0, r3, #0
	bl PrintString
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _080F0D9E
	cmp r0, #4
	beq _080F0D9E
	b _RETURN
_080F0D9E:
	adds r0, r6, #0
	bl handleWrapTwoChoice
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	bne _080F0DAE
	b _RETURN
_080F0DAE:
	lsls r0, r4, #0x10
	cmp r0, #0
	ble _080F0DD8
	ldrb r0, [r6, #4]
	ldr r1, _080F0DD4 @ =0x02036DBC
	movs r2, #0x94
	lsls r2, r2, #2
	bl sram_08003378
_080F0DC0:
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
	b _RETURN
	.align 2, 0
_080F0DC8: .4byte StringOfsTable
_080F0DCC: .4byte gStringData
_080F0DD0: .4byte gTextWindow+8
_080F0DD4: .4byte 0x02036DBC
_080F0DD8:
	ldrb r0, [r6, #3]
	subs r0, #5
	strb r0, [r6, #3]
	b _RETURN
_080F0DE0:
	ldr r1, _080F0F00 @ =StringOfsTable
	movs r5, #4
	ldrsh r0, [r6, r5]
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080F0F04 @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r0, _080F0F08 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F0E04
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F0E06
_080F0E04:
	movs r2, #1
_080F0E06:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r0, r3, #0
	bl PrintString
	ldr r1, _080F0F0C @ =gSramState
	ldrb r0, [r1]
	cmp r0, #1
	bne _080F0E20
	b _RETURN
_080F0E20:
	movs r2, #0x1e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080F0E2A
	b _RETURN
_080F0E2A:
	movs r0, #0xa
	bl PrintOptionMessage2
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F0E36:
	ldr r0, _080F0F08 @ =gTextWindow+8
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080F0E44
	cmp r0, #4
	beq _080F0E44
	b _RETURN
_080F0E44:
	ldr r5, _080F0F10 @ =0x00006260
	adds r4, r6, r5
	ldrb r0, [r4]
	ldr r2, _080F0F14 @ =0x00006410
	adds r1, r6, r2
	bl InitMissionInfo
	ldr r5, _080F0F18 @ =0x000064AC
	adds r0, r6, r5
	ldr r0, [r0]
	ldr r2, _080F0F1C @ =0x00006460
	adds r1, r6, r2
	bl SaveZeroStatus
	ldrb r0, [r4]
	ldr r5, _080F0F20 @ =0x00006270
	adds r1, r6, r5
	bl resetCurStory
	ldr r0, _080F0F24 @ =gStageRun
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #2
	str r1, [r0]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F0E7C:
	ldr r7, _080F0F24 @ =gStageRun
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r0, [r5]
	movs r4, #1
	rsbs r4, r4, #0
	cmp r0, r4
	beq _080F0E98
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl fadeoutBGM
	str r4, [r5]
_080F0E98:
	ldr r2, _080F0F08 @ =gTextWindow+8
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0xaa
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	cmp r0, #0
	beq _080F0EB0
	b _RETURN
_080F0EB0:
	ldr r0, _080F0F28 @ =gMission
	ldr r0, [r0]
	ldrb r0, [r0, #0x10]
	cmp r0, #0
	bne _080F0F34
	ldr r4, _080F0F2C @ =gCurStory
	ldrb r2, [r4, #4]
	movs r1, #0xf7
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r4, #4]
	ldr r2, _080F0F20 @ =0x00006270
	adds r3, r6, r2
	ldrb r2, [r3]
	ands r1, r2
	strb r1, [r3]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080F0EDE
	ldr r5, _080F0F30 @ =0x0000625C
	adds r0, r6, r5
	strh r2, [r0, #2]
_080F0EDE:
	ldrb r1, [r4, #4]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080F0EF0
	ldr r1, _080F0F30 @ =0x0000625C
	adds r0, r6, r1
	strh r3, [r0, #2]
_080F0EF0:
	ldr r5, _080F0F10 @ =0x00006260
	adds r0, r6, r5
	strh r2, [r0]
	movs r0, #1
	bl InitStageRun
	b _080F0FD0
	.align 2, 0
_080F0F00: .4byte StringOfsTable
_080F0F04: .4byte gStringData
_080F0F08: .4byte gTextWindow+8
_080F0F0C: .4byte gSramState
_080F0F10: .4byte 0x00006260
_080F0F14: .4byte 0x00006410
_080F0F18: .4byte 0x000064AC
_080F0F1C: .4byte 0x00006460
_080F0F20: .4byte 0x00006270
_080F0F24: .4byte gStageRun
_080F0F28: .4byte gMission
_080F0F2C: .4byte gCurStory
_080F0F30: .4byte 0x0000625C
_080F0F34:
	ldr r3, _080F0F60 @ =gCurStory
	ldrb r2, [r3, #4]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080F0F6C
	movs r1, #0xf7
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #4]
	ldr r0, _080F0F64 @ =0x00006270
	adds r2, r6, r0
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	ldr r1, _080F0F68 @ =0x00006260
	adds r0, r6, r1
	ldrb r0, [r0]
	bl InitStageRun
	b _080F0FD0
	.align 2, 0
_080F0F60: .4byte gCurStory
_080F0F64: .4byte 0x00006270
_080F0F68: .4byte 0x00006260
_080F0F6C:
	ldrb r1, [r3, #5]
	movs r0, #0x18
	ands r0, r1
	cmp r0, #8
	bne _080F0F88
	ldr r2, _080F0F84 @ =0x00006260
	adds r0, r6, r2
	movs r1, #0x11
	strh r1, [r0]
	movs r0, #0x11
	movs r1, #0xa
	b _080F0FCC
	.align 2, 0
_080F0F84: .4byte 0x00006260
_080F0F88:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0x10
	bne _080F0FA4
	ldr r5, _080F0FA0 @ =0x00006260
	adds r0, r6, r5
	movs r1, #0x11
	strh r1, [r0]
	movs r0, #0x11
	movs r1, #0xe
	b _080F0FCC
	.align 2, 0
_080F0FA0: .4byte 0x00006260
_080F0FA4:
	ldrb r1, [r3, #6]
	movs r0, #0x14
	ands r0, r1
	cmp r0, #4
	bne _080F0FC0
	ldr r1, _080F0FBC @ =0x00006260
	adds r0, r6, r1
	movs r1, #0x11
	strh r1, [r0]
	movs r0, #0x11
	b _080F0FCC
	.align 2, 0
_080F0FBC: .4byte 0x00006260
_080F0FC0:
	ldr r2, _080F0FDC @ =0x00006260
	adds r0, r6, r2
	movs r1, #0x11
	strh r1, [r0]
	movs r0, #0x11
	movs r1, #2
_080F0FCC:
	bl LoadStageRun
_080F0FD0:
	movs r1, #0xc0
	lsls r1, r1, #2
_080f0fd4: @ 0x080F0FD4
	adds r0, r6, #0
	bl SetGameMode
	b _RETURN
	.align 2, 0
_080F0FDC: .4byte 0x00006260
_080F0FE0:
	movs r0, #8
	bl PrintOptionMessage1
	movs r0, #1
	strh r0, [r6, #0xa]
	ldrb r0, [r6, #3]
	adds r0, #1
	strb r0, [r6, #3]
_080F0FF0:
	ldr r1, _080F1058 @ =StringOfsTable
	movs r5, #4
	ldrsh r0, [r6, r5]
	adds r0, #0x1f
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080F105C @ =gStringData
	adds r3, r1, r0
	movs r2, #0
	ldr r0, _080F1060 @ =gTextWindow+8
	ldrb r1, [r0, #6]
	adds r4, r0, #0
	cmp r1, #0
	bne _080F1014
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _080F1016
_080F1014:
	movs r2, #1
_080F1016:
	lsls r0, r2, #3
	subs r0, r0, r2
	movs r1, #8
	subs r1, r1, r0
	ldrb r2, [r4, #5]
	adds r0, r3, #0
	bl PrintString
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _080F1030
	cmp r0, #4
	bne _RETURN
_080F1030:
	adds r0, r6, #0
	bl handleWrapTwoChoice
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0
	beq _RETURN
	lsls r0, r4, #0x10
	cmp r0, #0
	ble _080F1064
	ldrb r0, [r6, #4]
	bl WriteSramINTI
	movs r0, #0xb
	bl PrintOptionMessage2
_080F1050:
	movs r0, #0x40
	strb r0, [r6, #3]
	b _RETURN
	.align 2, 0
_080F1058: .4byte StringOfsTable
_080F105C: .4byte gStringData
_080F1060: .4byte gTextWindow+8
_080F1064:
	movs r0, #0x52
	strb r0, [r6, #3]
	b _RETURN
_080F106A:
	ldr r6, _080F10B0 @ =gStageRun
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, [r5]
	movs r4, #1
	rsbs r4, r4, #0
	cmp r0, r4
	beq _080F1086
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl fadeoutBGM
	str r4, [r5]
_080F1086:
	ldr r2, _080F10B4 @ =gTextWindow+8
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _RETURN
	bl ExitProcess
_RETURN:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F10B0: .4byte gStageRun
_080F10B4: .4byte gTextWindow+8
