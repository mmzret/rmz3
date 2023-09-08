#include "blink.h"
#include "collision.h"
#include "game.h"
#include "global.h"
#include "hud.h"
#include "mission.h"
#include "overworld.h"
#include "story.h"
#include "task.h"
#include "zero.h"

static bool8 CheckMissionFail(struct StageRun* p);
static void trySkipEventScene(void);

const u8 gStageID8s[STAGE_COUNT] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
};
const u32 gStageID32s[STAGE_COUNT] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
};

// --------------------------------------------

// clang-format off
const StageRunFunc gMissionUpdate[STAGE_COUNT] = {
    Stage0_MissionUpdate,
    SpaceCraft_MissionUpdate,
    Volcano_MissionUpdate,
    Ocean_MissionUpdate,
    RepairFactory_MissionUpdate,
    OldLifeSpace_MissionUpdate,
    MissileFactory_MissionUpdate,
    TwilightDesert_MissionUpdate,
    AnatreForest_MissionUpdate,
    IceBase_MissionUpdate,
    AreaX2_MissionUpdate,
    EnergyFacility_MissionUpdate,
    SnowyPlains_MissionUpdate,
    SunkenLib_MissionUpdate,
    GiantElevator_MissionUpdate,
    SubArcadia_MissionUpdate,
    WeilLabo_MissionUpdate,
    ResistanceBase_Update,
};
// clang-format on

// --------------------------------------------

// clang-format off
const StageRunFunc gFreerunUpdate[STAGE_COUNT] = {
    Stage0_MissionUpdate,
    SpaceCraft_FreeUpdate,
    Volcano_FreeUpdate,
    Ocean_FreeUpdate,
    RepairFactory_FreeUpdate,
    OldLifeSpace_FreeUpdate,
    MissileFactory_FreeUpdate,
    TwilightDesert_FreeUpdate,
    AnatreForest_FreeUpdate,
    IceBase_FreeUpdate,
    AreaX2_FreeUpdate,
    EnergyFacility_FreeUpdate,
    SnowyPlains_FreeUpdate,
    SunkenLib_FreeUpdate,
    GiantElevator_FreeUpdate,
    SubArcadia_FreeUpdate,
    WeilLabo_MissionUpdate,
    ResistanceBase_Update,
};
// clang-format on

static const u8 gStageMissionBitTable[STAGE_COUNT] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
};

static const struct CameraTemplate gDefaultCameraTemplate = {};

// ------------------------------------------------------------------------------------------------------------------------------------

void InitStageRun(u8 stageID) {
  LoadStageRun(stageID, 0);
  return;
}

void LoadStageRun(u8 stageID, u8 checkPoint) {
  gStageRun.id = stageID;
  gStageRun.checkpoint = checkPoint;
  gStageRun.checkpointBuffer = 0xFF;
  gStageRun.unk_0a = 0;
  FUN_080322c4(&gGameState.save.status);
  InitMissionInfo(stageID, &gGameState.save.playinfo);

  if (((gMission.unk_00)->missionDones & (1 << gStageMissionBitTable[stageID])) == 0) {
    *(u8*)&gGameState.save.story.id &= ~STAGE_DONE;
  } else {
    *(u8*)&gGameState.save.story.id |= STAGE_DONE;
  }

  resetCurStory(stageID, &gGameState.save.story);
  clearStageDisk();

  CpuFastCopy(&gGameState.save.status, &gGameState.save.zeroAsset, 0);
  CpuCopy32(&gGameState.save.status, &gGameState.save.zeroAsset, 12);

  gGameState.save.savedRank = (gMission.unk_00)->rank;
  saveCurStory(&gGameState.save.savedStory);

  CpuFastCopy(gGameState.save.disk, gGameState.save.savedDisk, 32);
  CpuCopy32(&gGameState.save.disk[32], &gGameState.save.savedDisk[32], 16);

  CpuFastCopy(gGameState.save.elf, gGameState.save.savedElf, 64);
  CpuCopy32(&gGameState.save.elf[64], &gGameState.save.savedElf[64], 12);
}

void ClearStageRun(struct TaskManager* tm) {
  const u8 id = gStageRun.id;
  gStageRun.checkpointBuffer = 0xFF;
  gStageRun.frame = 0;
  gStageRun.taskManager = tm;
  gStageRun.missionStatus = 0;
  gStageRun.unk_17d = 0;
  gStageRun.stageEventPhase = 0;
  gStageRun.remainingTimeFrame = 0xffffffff;
  ClearQuakeManager();
  ResetCamera(&gStageRun.vm.camera, &gDefaultCameraTemplate, tm);
  ResetLandscape(gStageID32s[id], &gStageRun.vm.camera.viewport);

  if (((gMission.unk_00)->missionDones & (1 << gStageMissionBitTable[id])) == 0) {
    InitStageEntityManager(gStageID8s[id], FALSE);
  } else {
    InitStageEntityManager(gStageID8s[id], TRUE);
  }
  ClearVM(&gStageRun.vm, id);
}

WIP bool32 OverworldUpdate(bool8 paused) {
#if MODERN
  if (paused) {
    return FALSE;
  }
  gStageRun.frame++;

  bool32 exit = FALSE;
  bool8 running = FALSE;
  s32 cameraMode = gStageRun.vm.camera.mode;
  do {
    bool8 failed = CheckMissionFail(&gStageRun);
    if (!failed) {
      if (!(gStageRun.vm.active & 1)) {
        const StageRunFunc* fn;
        if (gCurStory.s.f0 & STORY_CLEAR) {
          fn = gFreerunUpdate;
        } else {
          fn = gMissionUpdate;
        }
        (fn[gStageRun.id])(&gStageRun);
      }
    }

    if (!(gStageRun.vm.active & 1)) {
      exit = (gStageRun.missionStatus & MISSION_STAY) == 0;
    }

    bool32 done = RunVM(&gStageRun.vm);
    if (!done) {
      running = FALSE;
      trySkipEventScene();
    } else {
      exit = (gStageRun.missionStatus & MISSION_STAY) == 0;
    }
  } while (running);

  RunCameraCallback(&gStageRun.vm.camera);

  // Update hazards
  {
    u32 fastcopysize = (gOverworld.unk_1c8.hazardLength * sizeof(struct Hazard)) & ~(0x1F);
    CpuFastCopy(gOverworld.unk_1c8.hazards, gOverworld.unk_1c8.nextBlockings, fastcopysize);

    u32 copysize = (gOverworld.unk_1c8.hazardLength * sizeof(struct Hazard)) & 0x1F;
    if (copysize > 0) {
      CpuCopy32((void*)gOverworld.unk_1c8.hazards + fastcopysize, (void*)gOverworld.unk_1c8.nextBlockings + fastcopysize, copysize);
    }
    gOverworld.unk_1c8.hazardActive = gOverworld.unk_1c8.hazardLength;
    gOverworld.unk_1c8.hazardLength = 0;
  }

  if (gStageRun.vm.camera.mode != 0) {
    UpdateStageLandscape(&gStageRun.vm.camera.viewport);
  }
  ApplyGiantElf(&gStageRun);

  if (((s32)((-cameraMode) | cameraMode) < 0) && (gStageRun.vm.camera.mode != 0)) {
    UpdateStageEntities(&gStageRun.vm.camera.viewport);
  }

  return exit;
#else
  INCCODE("asm/wip/OverworldUpdate.inc");
#endif
}

// 基本的に、毎フレーム呼び出される
void CameraUpdate(bool8 paused) {
  struct Camera* camera;
  struct StageRun* ow = &gStageRun;
  struct TaskManager* tm = ow->taskManager;

  if (!paused) {
    quake_0801a604(&(ow->vm).camera);
  }

  camera = &(ow->vm).camera;
  if (camera->mode != 0) {
    DrawOverworld(tm);
  }
  FUN_08021ca0(&ow->vm);
  RunAllDrawTasks(camera);
}

// ミッションの終了状況を見てフラグを立てる
void UpdateStoryFlag(void) {
  ExitStageLandscape();
  FUN_08021b88(&gStageRun.vm);
  ClearBlinkings();

  if ((gStageRun.missionStatus & MISSION_FAIL) == 0) {
    if ((gMission.unk_00)->missionDones & SPACE_CRAFT) {
      gCurStory.s.f0 |= (1 << 7);
    }
    if (((gMission.unk_00)->missionDones & FIRST4) == FIRST4) {
      gCurStory.s.f1 |= STORY_F1_B3;
    }
    if ((gMission.unk_00)->missionDones & MISSILE_FACTORY) {
      gCurStory.s.f1 |= STORY_F1_B4;
    }
    if (((gMission.unk_00)->missionDones & MEDIUM3) == MEDIUM3) {
      gCurStory.s.f1 |= STORY_F1_B7;
    }
    if ((gMission.unk_00)->missionDones & AREA_X2) {
      gCurStory.s.f2 |= NO_HARPUIA;
    }
    if (((gMission.unk_00)->missionDones & LATER4) == LATER4) {
      gCurStory.s.f2 |= SUNKEN_ANALYZE;
    }
    if ((gMission.unk_00)->missionDones & SUB_ARCADIA) {
      gCurStory.s.f2 |= WEIL_LABO;
    }
    saveCurStory(&gGameState.save.story);
  } else {
    resetCurStory((u8)gStageRun.id, &gGameState.save.story);
  }
  CopyZeroStatus(gGameState.z2, &gGameState.save.status);
  FUN_080322c4(&gGameState.save.status);
}

void setStageCheckpoint(u8 cp) {
  gStageRun.checkpoint = cp;
  gStageRun.checkpointBuffer = 0xFF;
  saveCurStory(&gGameState.save.story);
  CopyZeroStatus(gGameState.z2, &gGameState.save.status);
}

void setStageCheckpoint2(u8 cp) {
  gStageRun.checkpointBuffer = cp;
  saveCurStory(&gGameState.save.story);
  CopyZeroStatus(gGameState.z2, &gGameState.save.status);
}

// ハンマーガなどのサイバーエルフの適用(ついでにストパーラ系のエルフの適用終了)
void ApplyGiantElf(struct StageRun* p) {
  struct Boss* boss = (struct Boss*)(p->vm).entities[1].entity;
  if (boss != NULL) {
    if (gTimeElfTimer != 0) {
      gCurStory.s.elfFlags &= ~TIME_ELF_ENABLED;
      TurnUpBGM();
      gTimeElfTimer = 0;
    }
    stopSound(SE_TIME_ELF);
    stopSound(SE_TIME_ELF_HURRY);

    if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & 1) && (gCurStory.s.elfFlags & GIANT_ELF_ENABLED)) {
      if ((boss->s).kind == ENTITY_BOSS) {
        const u8 id = (boss->s).id;
        if (id != BOSS_MEGAMILPA) {
          if (id != BOSS_WORMER) {
            if (id != BOSS_BEE_SERVER) {
              if (id != BOSS_PANTHEON_AQUA_MOD) {
                if (id != BOSS_LOCOMO_IF) {
                  if (id != BOSS_PHANTOM) {
                    if (id != BOSS_REACTOR_CORE) {
                      if (id != BOSS_UNK24) {
                        if ((boss->s).flags & COLLIDABLE) {
                          struct Story* story;
                          (boss->body).hp = ((u16)(boss->body).hp + 1) >> 1;
                          gCurStory.s.elfFlags &= ~GIANT_ELF_ENABLED;
                          story = &gGameState.save.story;
                          story->f0 &= ~STORY_F0_B2;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

static bool8 CheckMissionFail(struct StageRun* p) {
  const struct Command* c;
  struct Zero* z = (struct Zero*)(p->vm).entities[0].entity;
  if ((z != NULL) && ((((z->body).status & BODY_STATUS_DEAD) || ((z->body).hp == 0)))) {
    gStageRun.missionStatus &= ~MISSION_STAY;
    gStageRun.missionStatus |= MISSION_FAIL;
  }

  if ((gStageRun.missionStatus & MISSION_STAY) == 0) {
    if (gStageRun.missionStatus & MISSION_FAIL) {
      gCollisionManager.disabled |= (1 << 7);
      gHUD.timeLeft = 0;
      c = (p->vm).start;
      if ((c != Script_MissionFail) && (c != Script_MissionFail2)) {
        if (gStageRun.vm.screenEffect != NO_SCREEN_EFFECT) {
          SetScript(&gStageRun.vm, Script_MissionFail2);
        } else {
          SetScript(&gStageRun.vm, Script_MissionFail);
        }
      }
      return TRUE;
    }
  }
  return FALSE;
}

static void trySkipEventScene(void) {
  struct GameState* g = &gGameState;

  if ((gJoypad[0].pressed & START_BUTTON) && (gStageRun.missionStatus & EVENT_SCENE)) {
    if (gStageRun.checkpointBuffer != 0xFF) {
      gStageRun.checkpoint = gStageRun.checkpointBuffer;
    }
    skipEventScene(g->z2, &(g->save).status);
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = 0;
    SetGameMode(g, GAMEMODE(MAINGAME, SKIP_EVENT, 0, 0));
  }
}

s16 Stage0_MissionUpdate(struct StageRun* p) {
  if (p->stageEventPhase == 0) {
    gStageRun.missionStatus |= MISSION_STAY;
    SetScript(&gStageRun.vm, *gStageScriptList[p->id]);
    p->stageEventPhase = 1;
  }
  return 0;
}
