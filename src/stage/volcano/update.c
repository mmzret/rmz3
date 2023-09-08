#include "global.h"
#include "hud.h"
#include "overworld.h"

/*
gStageRun.checkpoint (0202fe62):
  0: ステージ読み込み中
  1: ブリーフィング
  2: スタートポイント
  3: 中ボス部屋前のガーダールーム
  4: 中ボス部屋
  5: 中ボス部屋抜けた直後
  6: ボス戦, ボス戦で死んだ時のガーダールーム
  7: ボスとの会話

gStageRun.stageEventPhase (0202ffdc):
  00:
  01:
  06: (ボスと出会う前の)ガーダールーム
  08: ボス戦中
*/
NAKED s16 Volcano_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	mov sl, r0\n\
	ldr r0, [r0, #0x20]\n\
	str r0, [sp]\n\
	movs r6, #0xbe\n\
	lsls r6, r6, #1\n\
	add r6, sl\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0801B2E8\n\
	b _0801B450\n\
_0801B2E8:\n\
	ldr r2, _0801B324 @ =gStageRun\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2, #8]\n\
	ldr r5, _0801B328 @ =gCurStory\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #0xfb\n\
	ands r1, r0\n\
	strb r1, [r5, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801B330\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B32C @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x34]\n\
	bl SetScript\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #3\n\
	str r0, [r1]\n\
	movs r0, #0x14\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B324: .4byte gStageRun\n\
_0801B328: .4byte gCurStory\n\
_0801B32C: .4byte gStageScriptList\n\
_0801B330:\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801B380\n\
	adds r0, r5, #0\n\
	adds r0, #0x52\n\
	strb r3, [r0]\n\
	adds r0, #1\n\
	strb r3, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801B35C\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B358 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _0801B36A\n\
	.align 2, 0\n\
_0801B358: .4byte gStageScriptList\n\
_0801B35C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B37C @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x38]\n\
	bl SetScript\n\
_0801B36A:\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B37C: .4byte gStageScriptList\n\
_0801B380:\n\
	cmp r4, #1\n\
	bne _0801B3A0\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B39C @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B39C: .4byte gStageScriptList\n\
_0801B3A0:\n\
	cmp r4, #2\n\
	bne _0801B3B4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B3B0 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #8]\n\
	b _0801B3CC\n\
	.align 2, 0\n\
_0801B3B0: .4byte gStageScriptList\n\
_0801B3B4:\n\
	cmp r4, #3\n\
	bne _0801B3D8\n\
	adds r0, r5, #0\n\
	adds r0, #0x52\n\
	strb r3, [r0]\n\
	adds r0, #1\n\
	strb r3, [r0]\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B3D4 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0xc]\n\
_0801B3CC:\n\
	bl SetScript\n\
	strb r4, [r6]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B3D4: .4byte gStageScriptList\n\
_0801B3D8:\n\
	cmp r4, #4\n\
	bne _0801B3F4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B3F0 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #3\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B3F0: .4byte gStageScriptList\n\
_0801B3F4:\n\
	cmp r4, #5\n\
	bne _0801B418\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B414 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrb r0, [r5, #4]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #4]\n\
	strb r4, [r6]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B414: .4byte gStageScriptList\n\
_0801B418:\n\
	cmp r4, #6\n\
	bne _0801B434\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B430 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	movs r0, #7\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B430: .4byte gStageScriptList\n\
_0801B434:\n\
	cmp r4, #7\n\
	beq _0801B43A\n\
	b _0801BA1E\n\
_0801B43A:\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801B44C @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	movs r0, #8\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B44C: .4byte gStageScriptList\n\
_0801B450:\n\
	cmp r0, #1\n\
	bne _0801B45E\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801BA1C\n\
_0801B45E:\n\
	cmp r0, #2\n\
	bne _0801B4BC\n\
	ldr r2, [sp]\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801B47C @ =0x001DFFFF\n\
	cmp r1, r0\n\
	ble _0801B494\n\
	ldr r1, [r2, #0x58]\n\
	ldr r0, _0801B480 @ =0x00031FFF\n\
	cmp r1, r0\n\
	bgt _0801B48C\n\
	ldr r1, _0801B484 @ =gStageRun+328\n\
	ldr r0, _0801B488 @ =0x0020D000\n\
	b _0801B492\n\
	.align 2, 0\n\
_0801B47C: .4byte 0x001DFFFF\n\
_0801B480: .4byte 0x00031FFF\n\
_0801B484: .4byte gStageRun+328\n\
_0801B488: .4byte 0x0020D000\n\
_0801B48C:\n\
	ldr r1, _0801B4B4 @ =gStageRun+328\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
_0801B492:\n\
	str r0, [r1]\n\
_0801B494:\n\
	ldr r3, [sp]\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, _0801B4B8 @ =0x0020DFFF\n\
	cmp r1, r0\n\
	bgt _0801B4A0\n\
	b _0801BA1E\n\
_0801B4A0:\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B4B4: .4byte gStageRun+328\n\
_0801B4B8: .4byte 0x0020DFFF\n\
_0801B4BC:\n\
	cmp r0, #3\n\
	beq _0801B4C2\n\
	b _0801B798\n\
_0801B4C2:\n\
	ldr r0, [sp]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, _0801B4E4 @ =0x0021CFFF\n\
	cmp r1, r0\n\
	bgt _0801B4CE\n\
	b _0801BA1E\n\
_0801B4CE:\n\
	ldr r1, _0801B4E8 @ =0x0000017D\n\
	add r1, sl\n\
	mov r8, r1\n\
	ldrb r7, [r1]\n\
	cmp r7, #1\n\
	beq _0801B5A4\n\
	cmp r7, #1\n\
	bgt _0801B4EC\n\
	cmp r7, #0\n\
	beq _0801B4FA\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B4E4: .4byte 0x0021CFFF\n\
_0801B4E8: .4byte 0x0000017D\n\
_0801B4EC:\n\
	cmp r7, #2\n\
	bne _0801B4F2\n\
	b _0801B704\n\
_0801B4F2:\n\
	cmp r7, #3\n\
	bne _0801B4F8\n\
	b _0801B768\n\
_0801B4F8:\n\
	b _0801BA1E\n\
_0801B4FA:\n\
	ldr r5, _0801B580 @ =gStageRun+16\n\
	ldr r0, _0801B584 @ =gStageScriptList\n\
	ldr r0, [r0, #8]\n\
	ldr r1, [r0, #0x14]\n\
	adds r0, r5, #0\n\
	bl SetScript\n\
	ldr r2, _0801B588 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	ldr r4, _0801B58C @ =0x0000053C\n\
	ldr r2, _0801B590 @ =gStaticMotionGraphics\n\
	adds r0, r4, r2\n\
	ldr r1, _0801B594 @ =wStaticGraphicTilenums\n\
	adds r1, #0x86\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	bl LoadGraphic\n\
	ldr r0, _0801B598 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r0\n\
	ldr r0, _0801B59C @ =wStaticMotionPalIDs\n\
	adds r0, #0x86\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	strh r7, [r0]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	str r7, [r0]\n\
	movs r3, #0xbc\n\
	lsls r3, r3, #1\n\
	adds r5, r5, r3\n\
	strh r7, [r5]\n\
	movs r1, #0xc2\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #3\n\
	str r0, [r1]\n\
	ldr r0, _0801B5A0 @ =gHUD\n\
	str r1, [r0, #0x10]\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	mov r1, r8\n\
	b _0801B750\n\
	.align 2, 0\n\
_0801B580: .4byte gStageRun+16\n\
_0801B584: .4byte gStageScriptList\n\
_0801B588: .4byte gCurStory\n\
_0801B58C: .4byte 0x0000053C\n\
_0801B590: .4byte gStaticMotionGraphics\n\
_0801B594: .4byte wStaticGraphicTilenums\n\
_0801B598: .4byte gStaticMotionGraphics+12\n\
_0801B59C: .4byte wStaticMotionPalIDs\n\
_0801B5A0: .4byte gHUD\n\
_0801B5A4:\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #1\n\
	add r2, sl\n\
	str r2, [sp, #4]\n\
	ldr r0, [r2]\n\
	cmp r0, #0x2c\n\
	bhi _0801B5B8\n\
	adds r0, #1\n\
	str r0, [r2]\n\
	b _0801B642\n\
_0801B5B8:\n\
	movs r3, #0xbf\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	mov sb, r3\n\
	ldrh r1, [r3]\n\
	ldr r0, _0801B674 @ =0x000003E7\n\
	cmp r1, r0\n\
	bhi _0801B642\n\
	ldr r5, _0801B678 @ =RNG_0202f388\n\
	ldr r0, [r5]\n\
	ldr r1, _0801B67C @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r2, _0801B680 @ =0x00269EC3\n\
	mov r8, r2\n\
	add r0, r8\n\
	lsls r0, r0, #1\n\
	lsrs r6, r0, #1\n\
	str r6, [r5]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #7\n\
	bl __umodsi3\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #1\n\
	ldr r3, _0801B684 @ =0x0021E000\n\
	adds r4, r4, r3\n\
	ldr r1, _0801B67C @ =0x000343FD\n\
	adds r0, r6, #0\n\
	muls r0, r1, r0\n\
	add r0, r8\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #7\n\
	bl __umodsi3\n\
	adds r1, r0, #0\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #0xa\n\
	adds r1, r1, r2\n\
	mov r3, sb\n\
	ldrh r0, [r3]\n\
	bics r7, r0\n\
	adds r0, r4, #0\n\
	adds r2, r7, #0\n\
	bl FUN_0807cbf4\n\
	ldr r2, _0801B688 @ =gStageRun\n\
	mov r3, sb\n\
	ldrh r1, [r3]\n\
	adds r1, #1\n\
	lsls r1, r1, #2\n\
	movs r3, #0xc4\n\
	lsls r3, r3, #1\n\
	adds r2, r2, r3\n\
	adds r1, r1, r2\n\
	str r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801B642\n\
	movs r0, #0\n\
	ldr r1, [sp, #4]\n\
	str r0, [r1]\n\
	mov r2, sb\n\
	ldrh r0, [r2]\n\
	adds r0, #1\n\
	strh r0, [r2]\n\
_0801B642:\n\
	movs r1, #0\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldr r5, _0801B688 @ =gStageRun\n\
	ldrh r3, [r0]\n\
	cmp r1, r3\n\
	bge _0801B6A8\n\
	movs r2, #0xc4\n\
	lsls r2, r2, #1\n\
	adds r3, r5, r2\n\
	movs r4, #0\n\
	adds r6, r0, #0\n\
_0801B65C:\n\
	lsls r1, r1, #0x10\n\
	asrs r0, r1, #0xe\n\
	adds r0, #4\n\
	adds r0, r0, r3\n\
	ldr r2, [r0]\n\
	cmp r2, #0\n\
	beq _0801B698\n\
	ldrb r2, [r2, #0xc]\n\
	cmp r2, #2\n\
	bls _0801B68C\n\
	str r4, [r0]\n\
	b _0801B698\n\
	.align 2, 0\n\
_0801B674: .4byte 0x000003E7\n\
_0801B678: .4byte RNG_0202f388\n\
_0801B67C: .4byte 0x000343FD\n\
_0801B680: .4byte 0x00269EC3\n\
_0801B684: .4byte 0x0021E000\n\
_0801B688: .4byte gStageRun\n\
_0801B68C:\n\
	cmp r2, #1\n\
	bls _0801B698\n\
	str r4, [r0]\n\
	ldrh r0, [r3]\n\
	adds r0, #1\n\
	strh r0, [r3]\n\
_0801B698:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r1, r2\n\
	lsrs r1, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldrh r2, [r6]\n\
	cmp r0, r2\n\
	blt _0801B65C\n\
_0801B6A8:\n\
	movs r1, #0xc2\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	ldr r0, [r1]\n\
	subs r0, #1\n\
	str r0, [r1]\n\
	cmp r0, #0\n\
	ble _0801B6C6\n\
	movs r3, #0xc4\n\
	lsls r3, r3, #1\n\
	adds r0, r5, r3\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x18\n\
	bhi _0801B6C6\n\
	b _0801BA1E\n\
_0801B6C6:\n\
	ldr r1, _0801B700 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x80\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	ldrb r2, [r1, #1]\n\
	movs r0, #2\n\
	orrs r0, r2\n\
	strb r0, [r1, #1]\n\
	movs r0, #0xb4\n\
	lsls r0, r0, #1\n\
	adds r5, r5, r0\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801B6F2\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5]\n\
_0801B6F2:\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #0x5a\n\
	str r0, [r1]\n\
	b _0801B74C\n\
	.align 2, 0\n\
_0801B700: .4byte gCollisionManager\n\
_0801B704:\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	ldr r1, [r0]\n\
	movs r0, #0xc\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0801B724\n\
	ldr r1, _0801B720 @ =gHUD\n\
	movs r0, #0xc2\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	str r0, [r1, #0x10]\n\
	b _0801B728\n\
	.align 2, 0\n\
_0801B720: .4byte gHUD\n\
_0801B724:\n\
	ldr r0, _0801B758 @ =gHUD\n\
	str r1, [r0, #0x10]\n\
_0801B728:\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801B736\n\
	b _0801B9C8\n\
_0801B736:\n\
	ldr r0, _0801B75C @ =gStageRun+16\n\
	ldr r1, _0801B760 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	ldr r1, _0801B758 @ =gHUD\n\
	movs r0, #0xc2\n\
	lsls r0, r0, #1\n\
	add r0, sl\n\
	str r0, [r1, #0x10]\n\
_0801B74C:\n\
	ldr r1, _0801B764 @ =0x0000017D\n\
	add r1, sl\n\
_0801B750:\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B758: .4byte gHUD\n\
_0801B75C: .4byte gStageRun+16\n\
_0801B760: .4byte gStageScriptList\n\
_0801B764: .4byte 0x0000017D\n\
_0801B768:\n\
	ldr r1, _0801B78C @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	ldr r3, _0801B790 @ =gCurStory\n\
	ldrb r1, [r3, #4]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #4]\n\
	ldr r0, _0801B794 @ =gHUD\n\
	str r2, [r0, #0x10]\n\
	mov r1, r8\n\
	strb r2, [r1]\n\
	movs r0, #4\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B78C: .4byte gCollisionManager\n\
_0801B790: .4byte gCurStory\n\
_0801B794: .4byte gHUD\n\
_0801B798:\n\
	cmp r0, #4\n\
	bne _0801B7C4\n\
	ldr r2, [sp]\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801B7BC @ =0x0022BFFF\n\
	cmp r1, r0\n\
	ble _0801B7C4\n\
	ldr r2, _0801B7C0 @ =gCurStory\n\
	ldrb r1, [r2, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2, #4]\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #5\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B7BC: .4byte 0x0022BFFF\n\
_0801B7C0: .4byte gCurStory\n\
_0801B7C4:\n\
	movs r3, #0xbe\n\
	lsls r3, r3, #1\n\
	add r3, sl\n\
	ldrb r0, [r3]\n\
	cmp r0, #5\n\
	bne _0801B87C\n\
	ldr r5, _0801B804 @ =gStageRun+324\n\
	ldr r0, _0801B808 @ =0x0020D000\n\
	str r0, [r5]\n\
	ldr r0, [sp]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, _0801B80C @ =0x002BFFFF\n\
	cmp r1, r0\n\
	ble _0801B822\n\
	ldr r0, _0801B810 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801B814\n\
	ldr r0, [r5, #0x24]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801B822\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r4, [r5, #0x24]\n\
	b _0801B822\n\
	.align 2, 0\n\
_0801B804: .4byte gStageRun+324\n\
_0801B808: .4byte 0x0020D000\n\
_0801B80C: .4byte 0x002BFFFF\n\
_0801B810: .4byte gCurStory\n\
_0801B814:\n\
	ldr r2, _0801B870 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #6\n\
	strb r0, [r3]\n\
_0801B822:\n\
	ldr r2, [sp]\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801B874 @ =0x002C1FFF\n\
	cmp r1, r0\n\
	bgt _0801B82E\n\
	b _0801BA1E\n\
_0801B82E:\n\
	ldr r2, _0801B870 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801B878 @ =gStageRun\n\
	movs r3, #0xb4\n\
	lsls r3, r3, #1\n\
	adds r4, r0, r3\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801B862\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801B858\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r4]\n\
_0801B858:\n\
	movs r0, #0xa1\n\
	bl playBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801B862:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B870: .4byte gCollisionManager\n\
_0801B874: .4byte 0x002C1FFF\n\
_0801B878: .4byte gStageRun\n\
_0801B87C:\n\
	cmp r0, #6\n\
	bne _0801B8F8\n\
	ldr r0, [sp]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, _0801B8AC @ =0x002CFFFF\n\
	cmp r1, r0\n\
	ble _0801B8F8\n\
	ldr r1, _0801B8B0 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801B8B4 @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0801B8C0\n\
	ldr r0, _0801B8B8 @ =gStageRun+16\n\
	ldr r1, _0801B8BC @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	b _0801B8D8\n\
	.align 2, 0\n\
_0801B8AC: .4byte 0x002CFFFF\n\
_0801B8B0: .4byte gCollisionManager\n\
_0801B8B4: .4byte gCurStory\n\
_0801B8B8: .4byte gStageRun+16\n\
_0801B8BC: .4byte gStageScriptList\n\
_0801B8C0:\n\
	ldr r4, _0801B8EC @ =gStageRun+16\n\
	ldr r0, _0801B8F0 @ =gStageScriptList\n\
	ldr r0, [r0, #8]\n\
	ldr r1, [r0, #0x3c]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0801B8F4 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801B8D8:\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B8EC: .4byte gStageRun+16\n\
_0801B8F0: .4byte gStageScriptList\n\
_0801B8F4: .4byte 0x0000FFFE\n\
_0801B8F8:\n\
	movs r4, #0xbe\n\
	lsls r4, r4, #1\n\
	add r4, sl\n\
	ldrb r0, [r4]\n\
	cmp r0, #7\n\
	bne _0801B93C\n\
	ldr r2, [sp]\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, _0801B92C @ =0x002CFFFF\n\
	cmp r1, r0\n\
	ble _0801B93C\n\
	ldr r1, _0801B930 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801B934 @ =gStageRun+16\n\
	ldr r1, _0801B938 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #7\n\
	bl setStageCheckpoint\n\
	movs r0, #8\n\
	strb r0, [r4]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B92C: .4byte 0x002CFFFF\n\
_0801B930: .4byte gCollisionManager\n\
_0801B934: .4byte gStageRun+16\n\
_0801B938: .4byte gStageScriptList\n\
_0801B93C:\n\
	movs r5, #0xbe\n\
	lsls r5, r5, #1\n\
	add r5, sl\n\
	ldrb r0, [r5]\n\
	cmp r0, #8\n\
	bne _0801B954\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	movs r0, #9\n\
	strb r0, [r5]\n\
	b _0801BA1E\n\
_0801B954:\n\
	cmp r0, #9\n\
	bne _0801B9B0\n\
	ldr r4, _0801B9A0 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801B9B0\n\
	ldr r1, _0801B9A4 @ =gCollisionManager\n\
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
	ldr r1, _0801B9A8 @ =gStageScriptList\n\
	ldr r1, [r1, #8]\n\
	ldr r1, [r1, #0x30]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801B9AC @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0xa\n\
	strb r0, [r5]\n\
	b _0801BA1E\n\
	.align 2, 0\n\
_0801B9A0: .4byte gStageRun\n\
_0801B9A4: .4byte gCollisionManager\n\
_0801B9A8: .4byte gStageScriptList\n\
_0801B9AC: .4byte 0x0000FFEF\n\
_0801B9B0:\n\
	movs r6, #0xbe\n\
	lsls r6, r6, #1\n\
	add r6, sl\n\
	ldrb r0, [r6]\n\
	cmp r0, #0x14\n\
	bne _0801B9FC\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #1\n\
	add r1, sl\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801B9CE\n\
_0801B9C8:\n\
	subs r0, #1\n\
	str r0, [r1]\n\
	b _0801BA1E\n\
_0801B9CE:\n\
	ldr r4, _0801B9F8 @ =gStageRun\n\
	movs r3, #0xb4\n\
	lsls r3, r3, #1\n\
	adds r7, r4, r3\n\
	ldr r0, [r7]\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801B9EA\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl fadeoutBGM\n\
	str r5, [r7]\n\
_0801B9EA:\n\
	movs r1, #0xaa\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	movs r1, #2\n\
	str r1, [r0]\n\
	movs r0, #0x15\n\
	b _0801BA1C\n\
	.align 2, 0\n\
_0801B9F8: .4byte gStageRun\n\
_0801B9FC:\n\
	cmp r0, #0x15\n\
	bne _0801BA1E\n\
	ldr r2, _0801BA44 @ =gStageRun\n\
	movs r3, #0xaa\n\
	lsls r3, r3, #1\n\
	adds r0, r2, r3\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	bne _0801BA1E\n\
	ldrh r1, [r2, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801BA48 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r2, #8]\n\
	movs r0, #0x16\n\
_0801BA1C:\n\
	strb r0, [r6]\n\
_0801BA1E:\n\
	ldr r0, [sp]\n\
	ldr r2, [r0, #0x54]\n\
	ldr r3, _0801BA4C @ =0xFFE77000\n\
	adds r1, r2, r3\n\
	movs r0, #0xec\n\
	lsls r0, r0, #0xa\n\
	cmp r1, r0\n\
	bhi _0801BA58\n\
	ldr r1, _0801BA50 @ =0x0202FF94\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _0801BAB0\n\
	ldr r0, _0801BA54 @ =0x001A4FFF\n\
	cmp r2, r0\n\
	bgt _0801BA84\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	b _0801BA86\n\
	.align 2, 0\n\
_0801BA44: .4byte gStageRun\n\
_0801BA48: .4byte 0x0000FFFE\n\
_0801BA4C: .4byte 0xFFE77000\n\
_0801BA50: .4byte 0x0202FF94\n\
_0801BA54: .4byte 0x001A4FFF\n\
_0801BA58:\n\
	ldr r0, _0801BA78 @ =0xFFDA5000\n\
	adds r1, r2, r0\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #0xb\n\
	cmp r1, r0\n\
	bhi _0801BA9C\n\
	ldr r1, _0801BA7C @ =0x0202FF94\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _0801BAB0\n\
	ldr r0, _0801BA80 @ =0x00276FFF\n\
	cmp r2, r0\n\
	bgt _0801BA84\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	b _0801BA86\n\
	.align 2, 0\n\
_0801BA78: .4byte 0xFFDA5000\n\
_0801BA7C: .4byte 0x0202FF94\n\
_0801BA80: .4byte 0x00276FFF\n\
_0801BA84:\n\
	ldr r0, _0801BA94 @ =0xFFFFC000\n\
_0801BA86:\n\
	str r0, [r1]\n\
	ldr r0, _0801BA98 @ =gStageRun+232\n\
	movs r2, #0\n\
	movs r1, #4\n\
	strb r1, [r0, #0x19]\n\
	strh r2, [r0, #0x22]\n\
	b _0801BAB0\n\
	.align 2, 0\n\
_0801BA94: .4byte 0xFFFFC000\n\
_0801BA98: .4byte gStageRun+232\n\
_0801BA9C:\n\
	ldr r1, _0801BAC4 @ =0x0202FF94\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	beq _0801BAB0\n\
	movs r2, #0\n\
	str r2, [r1]\n\
	subs r1, #0x4c\n\
	movs r0, #4\n\
	strb r0, [r1, #0x19]\n\
	strh r2, [r1, #0x22]\n\
_0801BAB0:\n\
	movs r0, #0\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801BAC4: .4byte 0x0202FF94\n\
 .syntax divided\n");
}

s16 Volcano_FreeUpdate(struct StageRun* p) { return Volcano_MissionUpdate(p); }
