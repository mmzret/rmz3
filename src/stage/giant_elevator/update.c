#include "global.h"
#include "overworld.h"

/*
checkpoint (0202fe62):
  00: ステージ読み込み中
  01: スタートポイント
  02: スタートポイント
  03: エレベーター前
  04: エレベーター後
  05: ボス部屋ガーダールーム
  06: ボス戦

StageEventPhase (0202ffdc):
  00:
  01:
*/
NAKED s16 GiantElevator_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0801F854\n\
	b _0801F950\n\
_0801F854:\n\
	ldr r2, _0801F880 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801F8B4\n\
	ldr r0, _0801F884 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801F88C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F888 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801F89A\n\
	.align 2, 0\n\
_0801F880: .4byte gStageRun\n\
_0801F884: .4byte gCurStory\n\
_0801F888: .4byte gStageScriptList\n\
_0801F88C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F8B0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x34]\n\
	bl SetScript\n\
_0801F89A:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r2, #0xbe\n\
	lsls r2, r2, #1\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	bl _080200D2\n\
	.align 2, 0\n\
_0801F8B0: .4byte gStageScriptList\n\
_0801F8B4:\n\
	cmp r4, #1\n\
	bne _0801F8CC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F8C8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _0801F954\n\
	.align 2, 0\n\
_0801F8C8: .4byte gStageScriptList\n\
_0801F8CC:\n\
	cmp r4, #2\n\
	bne _0801F8E0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F8DC @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #8]\n\
	b _0801F8EE\n\
	.align 2, 0\n\
_0801F8DC: .4byte gStageScriptList\n\
_0801F8E0:\n\
	cmp r4, #3\n\
	bne _0801F8FC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F8F8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0xc]\n\
_0801F8EE:\n\
	bl SetScript\n\
	strb r4, [r6]\n\
	bl _080200D2\n\
	.align 2, 0\n\
_0801F8F8: .4byte gStageScriptList\n\
_0801F8FC:\n\
	cmp r4, #4\n\
	bne _0801F914\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F910 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	b _0801FF0C\n\
	.align 2, 0\n\
_0801F910: .4byte gStageScriptList\n\
_0801F914:\n\
	cmp r4, #5\n\
	bne _0801F934\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F930 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #7\n\
	strb r0, [r6]\n\
	bl _080200D2\n\
	.align 2, 0\n\
_0801F930: .4byte gStageScriptList\n\
_0801F934:\n\
	cmp r4, #6\n\
	beq _0801F93A\n\
	b _080200D2\n\
_0801F93A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801F94C @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	b _08020062\n\
	.align 2, 0\n\
_0801F94C: .4byte gStageScriptList\n\
_0801F950:\n\
	cmp r0, #1\n\
	bne _0801F960\n\
_0801F954:\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	strb r0, [r6]\n\
	b _080200D2\n\
_0801F960:\n\
	cmp r0, #2\n\
	beq _0801F966\n\
	b _0801FA60\n\
_0801F966:\n\
	ldr r2, [r4, #0x54]\n\
	ldr r0, _0801F988 @ =0x00051FFF\n\
	cmp r2, r0\n\
	bgt _0801F994\n\
	ldr r1, [r4, #0x58]\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #9\n\
	cmp r1, r0\n\
	ble _0801FA30\n\
	ldr r0, _0801F98C @ =0x0003BFFF\n\
	cmp r2, r0\n\
	ble _0801FA04\n\
	ldr r1, _0801F990 @ =gStageRun+324\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xa\n\
	str r0, [r1]\n\
	b _0801FA3C\n\
	.align 2, 0\n\
_0801F988: .4byte 0x00051FFF\n\
_0801F98C: .4byte 0x0003BFFF\n\
_0801F990: .4byte gStageRun+324\n\
_0801F994:\n\
	ldr r0, _0801F9B4 @ =0x0006AFFF\n\
	cmp r2, r0\n\
	bgt _0801F9C0\n\
	ldr r1, [r4, #0x58]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #9\n\
	cmp r1, r0\n\
	ble _0801FA30\n\
	ldr r0, _0801F9B8 @ =0x00061FFF\n\
	cmp r2, r0\n\
	ble _0801FA04\n\
	ldr r1, _0801F9BC @ =gStageRun+324\n\
	movs r0, #0xc4\n\
	lsls r0, r0, #0xb\n\
	str r0, [r1]\n\
	b _0801FA3C\n\
	.align 2, 0\n\
_0801F9B4: .4byte 0x0006AFFF\n\
_0801F9B8: .4byte 0x00061FFF\n\
_0801F9BC: .4byte gStageRun+324\n\
_0801F9C0:\n\
	ldr r0, _0801F9E0 @ =0x00082FFF\n\
	cmp r2, r0\n\
	bgt _0801F9EC\n\
	ldr r1, [r4, #0x58]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #9\n\
	cmp r1, r0\n\
	ble _0801FA30\n\
	ldr r0, _0801F9E4 @ =0x0007AFFF\n\
	cmp r2, r0\n\
	ble _0801FA04\n\
	ldr r1, _0801F9E8 @ =gStageRun+324\n\
	movs r0, #0xf6\n\
	lsls r0, r0, #0xb\n\
	str r0, [r1]\n\
	b _0801FA3C\n\
	.align 2, 0\n\
_0801F9E0: .4byte 0x00082FFF\n\
_0801F9E4: .4byte 0x0007AFFF\n\
_0801F9E8: .4byte gStageRun+324\n\
_0801F9EC:\n\
	ldr r0, _0801FA0C @ =0x000B3FFF\n\
	cmp r2, r0\n\
	bgt _0801FA3C\n\
	ldr r0, [r4, #0x58]\n\
	ldr r7, _0801FA10 @ =0xFFFE4FFF\n\
	adds r0, r0, r7\n\
	ldr r1, _0801FA14 @ =0x00016FFE\n\
	cmp r0, r1\n\
	bhi _0801FA30\n\
	ldr r0, _0801FA18 @ =0x000AAFFF\n\
	cmp r2, r0\n\
	bgt _0801FA20\n\
_0801FA04:\n\
	ldr r1, _0801FA1C @ =gStageRun+328\n\
	adds r0, #1\n\
	str r0, [r1]\n\
	b _0801FA3C\n\
	.align 2, 0\n\
_0801FA0C: .4byte 0x000B3FFF\n\
_0801FA10: .4byte 0xFFFE4FFF\n\
_0801FA14: .4byte 0x00016FFE\n\
_0801FA18: .4byte 0x000AAFFF\n\
_0801FA1C: .4byte gStageRun+328\n\
_0801FA20:\n\
	ldr r1, _0801FA2C @ =gStageRun+324\n\
	movs r0, #0xab\n\
	lsls r0, r0, #0xc\n\
	str r0, [r1]\n\
	b _0801FA3C\n\
	.align 2, 0\n\
_0801FA2C: .4byte gStageRun+324\n\
_0801FA30:\n\
	ldr r0, _0801FA58 @ =gStageRun+324\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #0xe\n\
	str r1, [r0, #4]\n\
_0801FA3C:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FA5C @ =0x000D1FFF\n\
	cmp r1, r0\n\
	bgt _0801FA46\n\
	b _080200D2\n\
_0801FA46:\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FA58: .4byte gStageRun+324\n\
_0801FA5C: .4byte 0x000D1FFF\n\
_0801FA60:\n\
	cmp r0, #3\n\
	beq _0801FA66\n\
	b _0801FEF0\n\
_0801FA66:\n\
	ldr r1, _0801FA80 @ =gOverworld\n\
	ldr r2, _0801FA84 @ =0x0002D024\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	adds r3, r1, #0\n\
	cmp r0, #0xb\n\
	bls _0801FA76\n\
	b _080200D2\n\
_0801FA76:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0801FA88 @ =_0801FA8C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0801FA80: .4byte gOverworld\n\
_0801FA84: .4byte 0x0002D024\n\
_0801FA88: .4byte _0801FA8C\n\
_0801FA8C: @ jump table\n\
	.4byte _0801FABC @ case 0\n\
	.4byte _080200D2 @ case 1\n\
	.4byte _080200D2 @ case 2\n\
	.4byte _080200D2 @ case 3\n\
	.4byte _0801FAF8 @ case 4\n\
	.4byte _080200D2 @ case 5\n\
	.4byte _0801FC80 @ case 6\n\
	.4byte _080200D2 @ case 7\n\
	.4byte _0801FD28 @ case 8\n\
	.4byte _080200D2 @ case 9\n\
	.4byte _080200D2 @ case 10\n\
	.4byte _0801FEE4 @ case 11\n\
_0801FABC:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FAE8 @ =0x000E9FFF\n\
	cmp r1, r0\n\
	bgt _0801FAC6\n\
	b _080200D2\n\
_0801FAC6:\n\
	ldr r1, _0801FAEC @ =gStageRun+324\n\
	movs r0, #0xe3\n\
	lsls r0, r0, #0xc\n\
	str r0, [r1]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #0xc\n\
	str r0, [r1, #4]\n\
	ldr r7, _0801FAF0 @ =0x0002D024\n\
	adds r1, r3, r7\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	ldr r1, _0801FAF4 @ =0x0000017D\n\
	adds r0, r5, r1\n\
	strb r2, [r0]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FAE8: .4byte 0x000E9FFF\n\
_0801FAEC: .4byte gStageRun+324\n\
_0801FAF0: .4byte 0x0002D024\n\
_0801FAF4: .4byte 0x0000017D\n\
_0801FAF8:\n\
	ldr r2, _0801FB0C @ =0x0000017D\n\
	adds r4, r5, r2\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	beq _0801FB38\n\
	cmp r0, #1\n\
	bgt _0801FB10\n\
	cmp r0, #0\n\
	beq _0801FB1C\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FB0C: .4byte 0x0000017D\n\
_0801FB10:\n\
	cmp r0, #2\n\
	beq _0801FB5C\n\
	cmp r0, #3\n\
	bne _0801FB1A\n\
	b _0801FC38\n\
_0801FB1A:\n\
	b _080200D2\n\
_0801FB1C:\n\
	movs r0, #0\n\
	bl CreateSolid46\n\
	movs r0, #1\n\
	bl CreateSolid46\n\
	movs r7, #0xbf\n\
	lsls r7, r7, #1\n\
	adds r1, r5, r7\n\
	movs r0, #0x3c\n\
	strh r0, [r1]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
_0801FB38:\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	adds r2, r5, r0\n\
	ldrh r0, [r2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _0801FB48\n\
	b _0801FD7E\n\
_0801FB48:\n\
	strh r1, [r2]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	str r1, [r0]\n\
	ldr r7, _0801FB70 @ =0x0000017D\n\
	adds r1, r5, r7\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0801FB5C:\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801FB6A\n\
	b _0801FDA8\n\
_0801FB6A:\n\
	ldr r4, _0801FB74 @ =0x0834CFB4\n\
	adds r6, r4, #4\n\
	b _0801FB8A\n\
	.align 2, 0\n\
_0801FB70: .4byte 0x0000017D\n\
_0801FB74: .4byte 0x0834CFB4\n\
_0801FB78:\n\
	ldr r0, [r2]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r1, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801FB8A\n\
	b _0801FECC\n\
_0801FB8A:\n\
	ldr r0, _0801FBC4 @ =gZakoHeaderPtr\n\
	ldr r1, [r0]\n\
	movs r2, #8\n\
	ldrsh r0, [r1, r2]\n\
	movs r7, #0xa\n\
	ldrsh r1, [r1, r7]\n\
	subs r0, r0, r1\n\
	cmp r0, #3\n\
	ble _0801FB9E\n\
	b _080200D2\n\
_0801FB9E:\n\
	ldr r2, _0801FBC8 @ =0x0834CEE4\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	lsls r1, r0, #2\n\
	adds r0, r2, #1\n\
	adds r0, r1, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801FBCC\n\
	adds r0, r1, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r4\n\
	bl FUN_08098838\n\
	b _0801FBF6\n\
	.align 2, 0\n\
_0801FBC4: .4byte gZakoHeaderPtr\n\
_0801FBC8: .4byte 0x0834CEE4\n\
_0801FBCC:\n\
	cmp r0, #1\n\
	bne _0801FBE4\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #3\n\
	adds r0, r1, r4\n\
	ldr r0, [r0]\n\
	adds r1, r1, r6\n\
	ldr r1, [r1]\n\
	bl FUN_08093930\n\
	b _0801FBF6\n\
_0801FBE4:\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #3\n\
	adds r0, r1, r4\n\
	ldr r0, [r0]\n\
	adds r1, r1, r6\n\
	ldr r1, [r1]\n\
	bl createPantheonFistInElevator\n\
_0801FBF6:\n\
	movs r7, #0xc0\n\
	lsls r7, r7, #1\n\
	adds r2, r5, r7\n\
	ldr r1, [r2]\n\
	adds r0, r1, #1\n\
	str r0, [r2]\n\
	ldr r3, _0801FC34 @ =0x0834CEE4\n\
	lsls r1, r1, #2\n\
	adds r0, r3, #2\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	subs r7, #2\n\
	adds r1, r5, r7\n\
	strh r0, [r1]\n\
	adds r1, r3, #0\n\
	cmp r0, #0\n\
	beq _0801FB78\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r1, r3, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0801FC30\n\
	b _080200D2\n\
_0801FC30:\n\
	b _0801FECC\n\
	.align 2, 0\n\
_0801FC34: .4byte 0x0834CEE4\n\
_0801FC38:\n\
	ldr r0, _0801FC68 @ =gZakoHeaderPtr\n\
	ldr r0, [r0]\n\
	movs r7, #0xa\n\
	ldrsh r1, [r0, r7]\n\
	movs r2, #8\n\
	ldrsh r0, [r0, r2]\n\
	cmp r1, r0\n\
	bge _0801FC4A\n\
	b _080200D2\n\
_0801FC4A:\n\
	ldr r1, _0801FC6C @ =0x0834CEE4\n\
	movs r7, #0xc0\n\
	lsls r7, r7, #1\n\
	adds r0, r5, r7\n\
	ldr r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r1, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _0801FC70\n\
	movs r0, #2\n\
	strb r0, [r4]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FC68: .4byte gZakoHeaderPtr\n\
_0801FC6C: .4byte 0x0834CEE4\n\
_0801FC70:\n\
	movs r0, #0\n\
	strb r0, [r4]\n\
	ldr r0, _0801FC7C @ =0x0002D024\n\
	adds r1, r3, r0\n\
	b _0801FED0\n\
	.align 2, 0\n\
_0801FC7C: .4byte 0x0002D024\n\
_0801FC80:\n\
	ldr r1, _0801FC94 @ =0x0000017D\n\
	adds r4, r5, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	beq _0801FCB0\n\
	cmp r0, #1\n\
	bgt _0801FC98\n\
	cmp r0, #0\n\
	beq _0801FC9E\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FC94: .4byte 0x0000017D\n\
_0801FC98:\n\
	cmp r0, #2\n\
	beq _0801FD08\n\
	b _080200D2\n\
_0801FC9E:\n\
	ldr r0, _0801FCF4 @ =gStageRun+16\n\
	ldr r1, _0801FCF8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
_0801FCB0:\n\
	ldr r4, _0801FCFC @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801FCBE\n\
	b _080200D2\n\
_0801FCBE:\n\
	ldr r1, _0801FD00 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801FCF8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801FD04 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	b _0801FECC\n\
	.align 2, 0\n\
_0801FCF4: .4byte gStageRun+16\n\
_0801FCF8: .4byte gStageScriptList\n\
_0801FCFC: .4byte gStageRun\n\
_0801FD00: .4byte gCollisionManager\n\
_0801FD04: .4byte 0x0000FFEF\n\
_0801FD08:\n\
	ldr r1, _0801FD20 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	strb r2, [r4]\n\
	ldr r7, _0801FD24 @ =0x0002D024\n\
	adds r1, r3, r7\n\
	b _0801FED0\n\
	.align 2, 0\n\
_0801FD20: .4byte gCollisionManager\n\
_0801FD24: .4byte 0x0002D024\n\
_0801FD28:\n\
	ldr r1, _0801FD40 @ =0x0000017D\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #4\n\
	bls _0801FD34\n\
	b _080200D2\n\
_0801FD34:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0801FD44 @ =_0801FD48\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0801FD40: .4byte 0x0000017D\n\
_0801FD44: .4byte _0801FD48\n\
_0801FD48: @ jump table\n\
	.4byte _0801FD5C @ case 0\n\
	.4byte _0801FD70 @ case 1\n\
	.4byte _0801FD9C @ case 2\n\
	.4byte _0801FE80 @ case 3\n\
	.4byte _080200D2 @ case 4\n\
_0801FD5C:\n\
	movs r2, #0xbf\n\
	lsls r2, r2, #1\n\
	adds r1, r5, r2\n\
	movs r0, #0x3c\n\
	strh r0, [r1]\n\
	ldr r7, _0801FD84 @ =0x0000017D\n\
	adds r1, r5, r7\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0801FD70:\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	adds r2, r5, r0\n\
	ldrh r0, [r2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _0801FD88\n\
_0801FD7E:\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FD84: .4byte 0x0000017D\n\
_0801FD88:\n\
	strh r1, [r2]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	str r1, [r0]\n\
	ldr r7, _0801FDB0 @ =0x0000017D\n\
	adds r1, r5, r7\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0801FD9C:\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801FDB4\n\
_0801FDA8:\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FDB0: .4byte 0x0000017D\n\
_0801FDB4:\n\
	ldr r4, _0801FDBC @ =0x0834CFB4\n\
	adds r6, r4, #4\n\
	b _0801FDD2\n\
	.align 2, 0\n\
_0801FDBC: .4byte 0x0834CFB4\n\
_0801FDC0:\n\
	ldr r0, [r2]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r1, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801FDD2\n\
	b _0801FECC\n\
_0801FDD2:\n\
	ldr r0, _0801FE0C @ =gZakoHeaderPtr\n\
	ldr r1, [r0]\n\
	movs r2, #8\n\
	ldrsh r0, [r1, r2]\n\
	movs r7, #0xa\n\
	ldrsh r1, [r1, r7]\n\
	subs r0, r0, r1\n\
	cmp r0, #3\n\
	ble _0801FDE6\n\
	b _080200D2\n\
_0801FDE6:\n\
	ldr r2, _0801FE10 @ =0x0834CF30\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	lsls r1, r0, #2\n\
	adds r0, r2, #1\n\
	adds r0, r1, r0\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801FE14\n\
	adds r0, r1, r2\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r4\n\
	bl FUN_08098838\n\
	b _0801FE3E\n\
	.align 2, 0\n\
_0801FE0C: .4byte gZakoHeaderPtr\n\
_0801FE10: .4byte 0x0834CF30\n\
_0801FE14:\n\
	cmp r0, #1\n\
	bne _0801FE2C\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #3\n\
	adds r0, r1, r4\n\
	ldr r0, [r0]\n\
	adds r1, r1, r6\n\
	ldr r1, [r1]\n\
	bl FUN_08093930\n\
	b _0801FE3E\n\
_0801FE2C:\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	lsls r1, r2, #3\n\
	adds r0, r1, r4\n\
	ldr r0, [r0]\n\
	adds r1, r1, r6\n\
	ldr r1, [r1]\n\
	bl createPantheonFistInElevator\n\
_0801FE3E:\n\
	movs r7, #0xc0\n\
	lsls r7, r7, #1\n\
	adds r2, r5, r7\n\
	ldr r1, [r2]\n\
	adds r0, r1, #1\n\
	str r0, [r2]\n\
	ldr r3, _0801FE7C @ =0x0834CF30\n\
	lsls r1, r1, #2\n\
	adds r0, r3, #2\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	subs r7, #2\n\
	adds r1, r5, r7\n\
	strh r0, [r1]\n\
	adds r1, r3, #0\n\
	cmp r0, #0\n\
	beq _0801FDC0\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	ldr r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r1, r3, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0801FE78\n\
	b _080200D2\n\
_0801FE78:\n\
	b _0801FECC\n\
	.align 2, 0\n\
_0801FE7C: .4byte 0x0834CF30\n\
_0801FE80:\n\
	ldr r0, _0801FEB4 @ =gZakoHeaderPtr\n\
	ldr r0, [r0]\n\
	movs r7, #0xa\n\
	ldrsh r1, [r0, r7]\n\
	movs r2, #8\n\
	ldrsh r0, [r0, r2]\n\
	cmp r1, r0\n\
	bge _0801FE92\n\
	b _080200D2\n\
_0801FE92:\n\
	ldr r1, _0801FEB8 @ =0x0834CF30\n\
	movs r7, #0xc0\n\
	lsls r7, r7, #1\n\
	adds r0, r5, r7\n\
	ldr r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r1, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _0801FEC0\n\
	ldr r0, _0801FEBC @ =0x0000017D\n\
	adds r1, r5, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FEB4: .4byte gZakoHeaderPtr\n\
_0801FEB8: .4byte 0x0834CF30\n\
_0801FEBC: .4byte 0x0000017D\n\
_0801FEC0:\n\
	ldr r0, _0801FED8 @ =gStageRun+16\n\
	ldr r1, _0801FEDC @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
_0801FECC:\n\
	ldr r2, _0801FEE0 @ =0x0000017D\n\
	adds r1, r5, r2\n\
_0801FED0:\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FED8: .4byte gStageRun+16\n\
_0801FEDC: .4byte gStageScriptList\n\
_0801FEE0: .4byte 0x0000017D\n\
_0801FEE4:\n\
	movs r7, #0xbe\n\
	lsls r7, r7, #1\n\
	adds r1, r5, r7\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	b _080200D2\n\
_0801FEF0:\n\
	cmp r0, #4\n\
	bne _0801FF1C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FF14 @ =0x000FEFFF\n\
	cmp r1, r0\n\
	bgt _0801FEFE\n\
	b _080200D2\n\
_0801FEFE:\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	ldr r0, _0801FF18 @ =0x0000017D\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_0801FF0C:\n\
	movs r0, #5\n\
	strb r0, [r6]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FF14: .4byte 0x000FEFFF\n\
_0801FF18: .4byte 0x0000017D\n\
_0801FF1C:\n\
	cmp r0, #5\n\
	bne _0801FFC4\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FF54 @ =0x0012AFFF\n\
	cmp r1, r0\n\
	ble _0801FF6E\n\
	ldr r0, _0801FF58 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801FF60\n\
	ldr r0, _0801FF5C @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r7, r0, r1\n\
	ldr r0, [r7]\n\
	movs r6, #1\n\
	rsbs r6, r6, #0\n\
	cmp r0, r6\n\
	beq _0801FF6E\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r6, [r7]\n\
	b _0801FF6E\n\
	.align 2, 0\n\
_0801FF54: .4byte 0x0012AFFF\n\
_0801FF58: .4byte gCurStory\n\
_0801FF5C: .4byte gStageRun\n\
_0801FF60:\n\
	ldr r2, _0801FFB8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #6\n\
	strb r0, [r6]\n\
_0801FF6E:\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FFBC @ =0x0012CFFF\n\
	cmp r1, r0\n\
	bgt _0801FF78\n\
	b _080200D2\n\
_0801FF78:\n\
	ldr r2, _0801FFB8 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801FFC0 @ =gStageRun\n\
	movs r2, #0xb4\n\
	lsls r2, r2, #1\n\
	adds r4, r0, r2\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801FFAC\n\
	movs r6, #1\n\
	rsbs r6, r6, #0\n\
	cmp r0, r6\n\
	beq _0801FFA2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r6, [r4]\n\
_0801FFA2:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801FFAC:\n\
	movs r7, #0xbe\n\
	lsls r7, r7, #1\n\
	adds r1, r5, r7\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_0801FFB8: .4byte gCollisionManager\n\
_0801FFBC: .4byte 0x0012CFFF\n\
_0801FFC0: .4byte gStageRun\n\
_0801FFC4:\n\
	cmp r0, #6\n\
	bne _0802003C\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _0801FFF0 @ =0x0013AFFF\n\
	cmp r1, r0\n\
	ble _0802003C\n\
	ldr r1, _0801FFF4 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801FFF8 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08020004\n\
	ldr r0, _0801FFFC @ =gStageRun+16\n\
	ldr r1, _08020000 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	b _0802001C\n\
	.align 2, 0\n\
_0801FFF0: .4byte 0x0013AFFF\n\
_0801FFF4: .4byte gCollisionManager\n\
_0801FFF8: .4byte gCurStory\n\
_0801FFFC: .4byte gStageRun+16\n\
_08020000: .4byte gStageScriptList\n\
_08020004:\n\
	ldr r4, _08020030 @ =gStageRun+16\n\
	ldr r0, _08020034 @ =gStageScriptList\n\
	ldr r0, [r0, #0x38]\n\
	ldr r1, [r0, #0x38]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _08020038 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0802001C:\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	b _080200D2\n\
	.align 2, 0\n\
_08020030: .4byte gStageRun+16\n\
_08020034: .4byte gStageScriptList\n\
_08020038: .4byte 0x0000FFFE\n\
_0802003C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r6, r5, r1\n\
	ldrb r0, [r6]\n\
	cmp r0, #7\n\
	bne _08020074\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _08020068 @ =0x0013AFFF\n\
	cmp r1, r0\n\
	ble _08020074\n\
	ldr r0, _0802006C @ =gStageRun+16\n\
	ldr r1, _08020070 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
_08020062:\n\
	movs r0, #8\n\
	strb r0, [r6]\n\
	b _080200D2\n\
	.align 2, 0\n\
_08020068: .4byte 0x0013AFFF\n\
_0802006C: .4byte gStageRun+16\n\
_08020070: .4byte gStageScriptList\n\
_08020074:\n\
	movs r2, #0xbe\n\
	lsls r2, r2, #1\n\
	adds r5, r5, r2\n\
	ldrb r0, [r5]\n\
	cmp r0, #8\n\
	bne _0802008A\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #9\n\
	b _080200D0\n\
_0802008A:\n\
	cmp r0, #9\n\
	bne _080200D2\n\
	ldr r4, _080200DC @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080200D2\n\
	ldr r1, _080200E0 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080200E4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x38]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _080200E8 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #6\n\
_080200D0:\n\
	strb r0, [r5]\n\
_080200D2:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080200DC: .4byte gStageRun\n\
_080200E0: .4byte gCollisionManager\n\
_080200E4: .4byte gStageScriptList\n\
_080200E8: .4byte 0x0000FFEF\n\
 .syntax divided\n");
}

s16 GiantElevator_FreeUpdate(struct StageRun* p) { return GiantElevator_MissionUpdate(p); }

// ------------------------------------------------------------------------------------------------------------------------------------

// clang-format off
const u8 u8_ARRAY_ARRAY_0834cee4[19][4] = {
  {0x00, 0x00, 0x00, 0x00 },
  {0x01, 0x00, 0x00, 0x00 },
  {0x00, 0x00, 0x00, 0x01 },
  {0x01, 0x00, 0x3C, 0x00 },
  {0x00, 0x01, 0x00, 0x01 },
  {0x01, 0x01, 0x1E, 0x01 },
  {0x00, 0x01, 0x1E, 0x01 },
  {0x01, 0x01, 0x1E, 0x00 },
  {0x00, 0x00, 0x00, 0x01 },
  {0x01, 0x00, 0x00, 0x01 },
  {0x00, 0x01, 0x3C, 0x01 },
  {0x01, 0x01, 0x00, 0x01 },
  {0x00, 0x01, 0x00, 0x01 },
  {0x01, 0x01, 0x00, 0x01 },
  {0x00, 0x00, 0x00, 0x01 },
  {0x01, 0x00, 0x00, 0x01 },
  {0x00, 0x01, 0x00, 0x01 },
  {0x01, 0x01, 0x00, 0x00 },
  {0x01, 0x01, 0x00, 0xFF },
};
// clang-format on

// --------------------------------------------

// clang-format off
const u8 u8_ARRAY_ARRAY_0834cf30[33][4] = {
  { 0x00, 0x01, 0x00, 0x01 },
  { 0x01, 0x01, 0x00, 0x01 },
  { 0x00, 0x00, 0x1E, 0x01 },
  { 0x01, 0x00, 0x00, 0x01 },
  { 0x00, 0x01, 0x00, 0x01 },
  { 0x01, 0x01, 0x00, 0x00 },
  { 0x01, 0x02, 0x00, 0x01 },
  { 0x01, 0x02, 0x3C, 0x01 },
  { 0x00, 0x02, 0x78, 0x01 },
  { 0x00, 0x02, 0x3C, 0x00 },
  { 0x00, 0x02, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x01 },
  { 0x00, 0x01, 0x3C, 0x01 },
  { 0x01, 0x01, 0x00, 0x01 },
  { 0x00, 0x00, 0x00, 0x01 },
  { 0x00, 0x02, 0x00, 0x01 },
  { 0x01, 0x00, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x00 },
  { 0x00, 0x02, 0x00, 0x01 },
  { 0x01, 0x00, 0x00, 0x01 },
  { 0x00, 0x02, 0x1E, 0x01 },
  { 0x01, 0x01, 0x1E, 0x01 },
  { 0x00, 0x00, 0x00, 0x01 },
  { 0x01, 0x00, 0x00, 0x01 },
  { 0x00, 0x01, 0x00, 0x01 },
  { 0x01, 0x01, 0x00, 0x01 },
  { 0x00, 0x02, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x01 },
  { 0x00, 0x00, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x01 },
  { 0x01, 0x02, 0x00, 0x00 },
  { 0x01, 0x01, 0x00, 0xFF },
};
// clang-format on

// --------------------------------------------

const struct Coord sGiantElevatorZakoRushCoords[2] = {
    {0xE7000, 0x6B000},
    {0xF9000, 0x6B000},
};

// --------------------------------------------

const u16 u16_ARRAY_0834cfc4[8] = {
    0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
};
