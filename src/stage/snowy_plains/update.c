#include "global.h"
#include "overworld.h"

NAKED s16 SnowyPlains_MissionUpdate(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r0, #0\n\
	ldr r7, [r6, #0x20]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0801EDFC\n\
	ldr r2, _0801ED4C @ =gStageRun\n\
	ldrh r0, [r2, #8]\n\
	movs r6, #1\n\
	movs r3, #0\n\
	adds r1, r6, #0\n\
	orrs r1, r0\n\
	strh r1, [r2, #8]\n\
	ldrb r4, [r2, #2]\n\
	cmp r4, #0\n\
	bne _0801ED54\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801ED50 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	movs r0, #1\n\
	bl setStageCheckpoint\n\
	strb r6, [r5]\n\
	b _0801F078\n\
	.align 2, 0\n\
_0801ED4C: .4byte gStageRun\n\
_0801ED50: .4byte gStageScriptList\n\
_0801ED54:\n\
	cmp r4, #1\n\
	bne _0801ED74\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801ED70 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801ED70: .4byte gStageScriptList\n\
_0801ED74:\n\
	cmp r4, #2\n\
	bne _0801ED90\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801ED8C @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	strb r4, [r5]\n\
	b _0801F078\n\
	.align 2, 0\n\
_0801ED8C: .4byte gStageScriptList\n\
_0801ED90:\n\
	cmp r4, #3\n\
	bne _0801EDAC\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801EDA8 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x14]\n\
	bl SetScript\n\
	movs r0, #6\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EDA8: .4byte gStageScriptList\n\
_0801EDAC:\n\
	cmp r4, #4\n\
	bne _0801EDC8\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801EDC4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	movs r0, #8\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EDC4: .4byte gStageScriptList\n\
_0801EDC8:\n\
	cmp r4, #5\n\
	bne _0801EDE4\n\
	adds r0, r2, #0\n\
	adds r0, #0x10\n\
	ldr r1, _0801EDE0 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	movs r0, #9\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EDE0: .4byte gStageScriptList\n\
_0801EDE4:\n\
	cmp r4, #6\n\
	beq _0801EDEA\n\
	b _0801F078\n\
_0801EDEA:\n\
	movs r0, #4\n\
	orrs r1, r0\n\
	orrs r1, r3\n\
	ldr r0, _0801EDF8 @ =0x0000FFFE\n\
	ands r1, r0\n\
	strh r1, [r2, #8]\n\
	b _0801F074\n\
	.align 2, 0\n\
_0801EDF8: .4byte 0x0000FFFE\n\
_0801EDFC:\n\
	cmp r0, #1\n\
	bne _0801EE0A\n\
	movs r0, #2\n\
	bl setStageCheckpoint\n\
	movs r0, #2\n\
	b _0801F076\n\
_0801EE0A:\n\
	cmp r0, #2\n\
	bne _0801EE2C\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801EE24 @ =0x001FFFFF\n\
	cmp r1, r0\n\
	ble _0801EE2C\n\
	ldr r2, _0801EE28 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	movs r0, #3\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EE24: .4byte 0x001FFFFF\n\
_0801EE28: .4byte gCollisionManager\n\
_0801EE2C:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #3\n\
	bne _0801EE5C\n\
	ldr r1, _0801EE50 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801EE54 @ =gStageRun+16\n\
	ldr r1, _0801EE58 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	movs r0, #4\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EE50: .4byte gCollisionManager\n\
_0801EE54: .4byte gStageRun+16\n\
_0801EE58: .4byte gStageScriptList\n\
_0801EE5C:\n\
	cmp r0, #4\n\
	bne _0801EEB4\n\
	ldr r4, _0801EEA4 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801EEB4\n\
	ldr r1, _0801EEA8 @ =gCollisionManager\n\
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
	ldr r1, _0801EEAC @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801EEB0 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #5\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801EEA4: .4byte gStageRun\n\
_0801EEA8: .4byte gCollisionManager\n\
_0801EEAC: .4byte gStageScriptList\n\
_0801EEB0: .4byte 0x0000FFEF\n\
_0801EEB4:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r4, r6, r0\n\
	ldrb r0, [r4]\n\
	cmp r0, #5\n\
	bne _0801EEE0\n\
	ldr r1, _0801EEDC @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	movs r0, #3\n\
	bl setStageCheckpoint\n\
	movs r0, #6\n\
	strb r0, [r4]\n\
	b _0801F078\n\
	.align 2, 0\n\
_0801EEDC: .4byte gCollisionManager\n\
_0801EEE0:\n\
	cmp r0, #6\n\
	bne _0801EF64\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801EF54 @ =0x00337FFF\n\
	cmp r1, r0\n\
	ble _0801EF08\n\
	ldr r0, _0801EF58 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r5, r0, r1\n\
	ldr r0, [r5]\n\
	movs r4, #1\n\
	rsbs r4, r4, #0\n\
	cmp r0, r4\n\
	beq _0801EF08\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl FadeOutBGM\n\
	str r4, [r5]\n\
_0801EF08:\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801EF5C @ =0x00339FFF\n\
	cmp r1, r0\n\
	bgt _0801EF12\n\
	b _0801F078\n\
_0801EF12:\n\
	ldr r2, _0801EF60 @ =gCollisionManager\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #1]\n\
	ldr r0, _0801EF58 @ =gStageRun\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #1\n\
	adds r4, r0, r1\n\
	ldr r0, [r4]\n\
	cmp r0, #0xa1\n\
	beq _0801EF46\n\
	movs r5, #1\n\
	rsbs r5, r5, #0\n\
	cmp r0, r5\n\
	beq _0801EF3C\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	bl FadeOutBGM\n\
	str r5, [r4]\n\
_0801EF3C:\n\
	movs r0, #0xa1\n\
	bl PlayBGM\n\
	movs r0, #0xa1\n\
	str r0, [r4]\n\
_0801EF46:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r6, r0\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	b _0801F078\n\
	.align 2, 0\n\
_0801EF54: .4byte 0x00337FFF\n\
_0801EF58: .4byte gStageRun\n\
_0801EF5C: .4byte 0x00339FFF\n\
_0801EF60: .4byte gCollisionManager\n\
_0801EF64:\n\
	cmp r0, #7\n\
	bne _0801EF90\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801EF80 @ =0x00347FFF\n\
	cmp r1, r0\n\
	ble _0801EF90\n\
	ldr r1, _0801EF84 @ =gCollisionManager\n\
	movs r0, #0\n\
	strb r0, [r1, #1]\n\
	ldr r0, _0801EF88 @ =gStageRun+16\n\
	ldr r1, _0801EF8C @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x1c]\n\
	b _0801EFAC\n\
	.align 2, 0\n\
_0801EF80: .4byte 0x00347FFF\n\
_0801EF84: .4byte gCollisionManager\n\
_0801EF88: .4byte gStageRun+16\n\
_0801EF8C: .4byte gStageScriptList\n\
_0801EF90:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r4, r6, r1\n\
	ldrb r0, [r4]\n\
	cmp r0, #8\n\
	bne _0801EFC8\n\
	ldr r1, [r7, #0x54]\n\
	ldr r0, _0801EFBC @ =0x00347FFF\n\
	cmp r1, r0\n\
	ble _0801EFC8\n\
	ldr r0, _0801EFC0 @ =gStageRun+16\n\
	ldr r1, _0801EFC4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x20]\n\
_0801EFAC:\n\
	bl SetScript\n\
	movs r0, #5\n\
	bl setStageCheckpoint\n\
	movs r0, #9\n\
	strb r0, [r4]\n\
	b _0801F078\n\
	.align 2, 0\n\
_0801EFBC: .4byte 0x00347FFF\n\
_0801EFC0: .4byte gStageRun+16\n\
_0801EFC4: .4byte gStageScriptList\n\
_0801EFC8:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r5, r6, r0\n\
	ldrb r0, [r5]\n\
	cmp r0, #9\n\
	bne _0801EFDE\n\
	movs r0, #4\n\
	bl setStageCheckpoint\n\
	movs r0, #0xa\n\
	b _0801F076\n\
_0801EFDE:\n\
	cmp r0, #0xa\n\
	bne _0801F038\n\
	ldr r4, _0801F028 @ =gStageRun\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0801F038\n\
	ldr r1, _0801F02C @ =gCollisionManager\n\
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
	ldr r1, _0801F030 @ =gStageScriptList\n\
	ldr r1, [r1, #0x30]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, _0801F034 @ =0x0000FFEF\n\
	ands r1, r0\n\
	ldrb r2, [r4, #0x12]\n\
	movs r0, #0xfd\n\
	ands r0, r2\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strh r1, [r4, #8]\n\
	movs r0, #0xb\n\
	b _0801F076\n\
	.align 2, 0\n\
_0801F028: .4byte gStageRun\n\
_0801F02C: .4byte gCollisionManager\n\
_0801F030: .4byte gStageScriptList\n\
_0801F034: .4byte 0x0000FFEF\n\
_0801F038:\n\
	movs r1, #0xbe\n\
	lsls r1, r1, #1\n\
	adds r5, r6, r1\n\
	ldrb r0, [r5]\n\
	cmp r0, #0xb\n\
	bne _0801F078\n\
	ldr r1, _0801F080 @ =gCollisionManager\n\
	ldrb r2, [r1]\n\
	movs r0, #0x7f\n\
	ands r0, r2\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	strb r2, [r1, #1]\n\
	ldr r4, _0801F084 @ =gStageRun+16\n\
	ldr r0, _0801F088 @ =gStageScriptList\n\
	ldr r0, [r0, #0x30]\n\
	ldr r1, [r0, #0x2c]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	movs r0, #6\n\
	bl setStageCheckpoint\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	ldr r1, _0801F08C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
_0801F074:\n\
	movs r0, #0xc\n\
_0801F076:\n\
	strb r0, [r5]\n\
_0801F078:\n\
	movs r0, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801F080: .4byte gCollisionManager\n\
_0801F084: .4byte gStageRun+16\n\
_0801F088: .4byte gStageScriptList\n\
_0801F08C: .4byte 0x0000FFFE\n\
 .syntax divided\n");
}

s16 SnowyPlains_FreeUpdate(struct StageRun* p) {
  struct Entity* z = (p->vm).entities[0].entity;
  if (p->stageEventPhase == 0) {
    gStageRun.missionStatus |= MISSION_STAY;
    if (gStageRun.checkpoint == 0) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][12]);  // 0x0835653c
      setStageCheckpoint(1);
      p->stageEventPhase = 1;
    } else if (gStageRun.checkpoint == 2) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][2]);  // 0x08355f04
      p->stageEventPhase = 2;
    } else if (gStageRun.checkpoint == 3) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][5]);  // 0x0835603c
      p->stageEventPhase = 6;
    }
  } else if (p->stageEventPhase == 1) {
    setStageCheckpoint(2);
    p->stageEventPhase = 2;
  } else if (p->stageEventPhase == 2 && ((z->coord).x >= PIXEL(8192))) {
    gCollisionManager.sweep |= SWEEP_ALL_ENEMY;
    p->stageEventPhase = 3;
  } else if (p->stageEventPhase == 3) {
    gCollisionManager.sweep = 0;
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][3]);  // 0x08355f5c
    p->stageEventPhase = 4;
  } else if (p->stageEventPhase == 4 && (gStageRun.missionStatus & MISSION_SUCCESS)) {
    gCollisionManager.disabled |= COLLMAN_DISABLED;
    gCollisionManager.sweep |= SWEEP_ALL_ENEMY;
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][4]);
    gStageRun.missionStatus &= ~MISSION_SUCCESS;
    gStageRun.vm.active &= ~VM_FLAG1;
    gStageRun.missionStatus |= MISSION_STAY;
    p->stageEventPhase = 5;
  } else if (p->stageEventPhase == 5) {
    gCollisionManager.disabled &= ~COLLMAN_DISABLED;
    gCollisionManager.sweep = 0;
    setStageCheckpoint(3);
    p->stageEventPhase = 6;
  } else if (p->stageEventPhase == 6) {
    if ((z->coord).x >= PIXEL(13184)) {
      gCollisionManager.sweep |= SWEEP_ALL_ENEMY;
      p->stageEventPhase = 7;
    }
  } else if (p->stageEventPhase == 7) {
    if ((z->coord).x >= PIXEL(13440)) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_SNOWY_PLAINS][13]);  // 0x083565b4
      gStageRun.missionStatus &= ~MISSION_STAY;
      p->stageEventPhase = 9;
    }
  }
  return 0;
}
