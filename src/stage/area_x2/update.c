#include "global.h"
#include "overworld.h"
#include "story.h"

s16 AreaX2_MissionUpdate(struct StageRun* p) {
  struct Zero* z = (struct Zero*)(p->vm).entities[0].entity;

  if (p->stageEventPhase == 0) {
    gStageRun.missionStatus |= MISSION_STAY;

    if (gStageRun.checkpoint == 0) {
      if (IS_MISSION) {
        SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][0]);
      } else {
        SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][11]);
      }
      setStageCheckpoint(1);
      p->stageEventPhase = 1;

    } else if (gStageRun.checkpoint == 1) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][1]);
      setStageCheckpoint(2);
      p->stageEventPhase = 2;

    } else if (gStageRun.checkpoint == 2) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][2]);
      p->stageEventPhase = 2;

    } else if (gStageRun.checkpoint == 3) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][3]);
      p->stageEventPhase = 3;

    } else if (gStageRun.checkpoint == 4) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][4]);
      p->stageEventPhase = 5;

    } else if (gStageRun.checkpoint == 5) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][7]);
      p->stageEventPhase = 6;

    } else if (gStageRun.checkpoint == 6) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][9]);
      p->stageEventPhase = 8;

    } else if (gStageRun.checkpoint == 7) {
      gStageRun.missionStatus &= ~MISSION_STAY;
      p->stageEventPhase = 9;
    }

  } else if (p->stageEventPhase == 1) {
    setStageCheckpoint(2);
    p->stageEventPhase = 2;

  } else if (p->stageEventPhase == 2 && (z->s).coord.y <= PIXEL(2080)) {
    setStageCheckpoint(3);
    p->stageEventPhase = 3;

  } else if (p->stageEventPhase == 3 && (z->s).coord.y < PIXEL(480)) {
    // Enter Boss door
    if ((z->s).coord.x >= PIXEL(3824)) {
      if (IS_MISSION) {
        if (gStageRun.vm.bgm != MUS_NONE) {
          fadeoutBGM(gStageRun.vm.bgm);
          gStageRun.vm.bgm = MUS_NONE;
        }
      } else {
        FUN_080186c8(gStageEntityManager.dynamicEntityRange[0], PIXEL(480));
        gCollisionManager.sweep |= (1 << LAYER_ENEMY);
        p->stageEventPhase = 4;
      }
    }

    // Leave Boss door (= into Guarder room)
    if ((z->s).coord.x >= PIXEL(3856)) {
      FUN_080186c8(gStageEntityManager.dynamicEntityRange[0], PIXEL(480));
      gCollisionManager.sweep |= (1 << LAYER_ENEMY);
      if (gStageRun.vm.bgm != BGM_GUARDER_ROOM) {
        if (gStageRun.vm.bgm != MUS_NONE) {
          fadeoutBGM(gStageRun.vm.bgm);
          gStageRun.vm.bgm = MUS_NONE;
        }
        playBGM(BGM_GUARDER_ROOM);
        gStageRun.vm.bgm = BGM_GUARDER_ROOM;
      }
      p->stageEventPhase = 4;
    }

  } else if (p->stageEventPhase == 4 && (z->s).coord.x >= PIXEL(4080)) {
    gCollisionManager.sweep = 0;
    if (IS_MISSION) {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][5]);
    } else {
      SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][12]);
      gStageRun.missionStatus &= ~MISSION_STAY;
    }
    setStageCheckpoint(5);
    p->stageEventPhase = 6;

  } else if (p->stageEventPhase == 5 && (z->s).coord.x >= PIXEL(4080)) {
    gCollisionManager.sweep = 0;
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][6]);
    setStageCheckpoint(5);
    p->stageEventPhase = 6;

  } else if (p->stageEventPhase == 6) {
    setStageCheckpoint(4);
    p->stageEventPhase = 7;

  } else if (p->stageEventPhase == 7 && (gStageRun.missionStatus & MISSION_SUCCESS)) {
    gCollisionManager.disabled |= (1 << 7);
    gCollisionManager.sweep |= (1 << LAYER_ENEMY);
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][8]);
    gStageRun.missionStatus &= ~MISSION_SUCCESS;
    gStageRun.vm.active &= 0xFD;
    gStageRun.missionStatus |= STOP_TIME_COUNT;
    gStageRun.missionStatus |= MISSION_STAY;
    setStageCheckpoint2(6);
    p->stageEventPhase = 8;

  } else if (p->stageEventPhase == 8) {
    gCollisionManager.disabled &= 0x7F;
    gCollisionManager.sweep = 0;
    SetScript(&gStageRun.vm, gStageScriptList[STAGE_AREA_X2][10]);
    setStageCheckpoint(7);
    gStageRun.missionStatus &= ~MISSION_STAY;
    p->stageEventPhase = 9;
  }

  return 0;
}

s16 AreaX2_FreeUpdate(struct StageRun* p) { return AreaX2_MissionUpdate(p); }
