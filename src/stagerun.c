#include "collision.h"
#include "game.h"
#include "global.h"
#include "hud.h"
#include "overworld.h"
#include "palette_animation.h"
#include "renderer.h"
#include "score.h"
#include "spawn.h"
#include "story.h"
#include "zero.h"

extern const GameCommand Script_MissionFail[];
extern const GameCommand Script_MissionFail2[];

void RenderWipeZ(struct VM* vm);
void FUN_08021b88(struct VM* _);

static bool32 CheckMissionFail(struct StageRun* p);
static void trySkipEventScene(void* _);

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
    OldResidential_MissionUpdate,
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
    OldResidential_FreeUpdate,
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
  gStageRun.checkpointResultScreen = 0xFF;
  gStageRun.unk_0a = 0;
  FUN_080322c4(&gGameState.save.status);
  ResetMissionScore(stageID, &gGameState.save.playinfo);

  if (!(gMissionDones & (1 << gStageMissionBitTable[stageID]))) {
    CLEAR_FLAG(gGameState.save.story.gameflags, IS_FREERUN);
  } else {
    SET_FLAG(gGameState.save.story.gameflags, IS_FREERUN);
  }

  LoadStoryData(stageID, &gGameState.save.story);
  clearStageDisk();

  MemCopy32(&gGameState.save.status, &gGameState.save.zeroAsset, sizeof(struct ZeroAsset));

  gGameState.save.savedRank = (gScore.total)->rank;
  StoreStoryData(&gGameState.save.savedStory);

  MemCopy32(gGameState.save.disk, gGameState.save.savedDisk, 48);
  MemCopy32(gGameState.save.elf, gGameState.save.savedElf, 76);
}

void ClearStageRun(Renderer* r) {
  const u8 id = gStageRun.id;
  gStageRun.checkpointResultScreen = 0xFF;
  gStageRun.frame = 0;
  gStageRun.renderer = r;
  gStageRun.missionStatus = 0;
  gStageRun.unk_17d = 0;
  gStageRun.stageEventPhase = 0;
  gStageRun.remainingTimeFrame = 0xFFFFFFFF;
  ClearQuakeManager();
  Camera_Reset(&gStageRun.vm.camera, &gDefaultCameraTemplate, r);
  ResetLandscape(gStageID32s[id], &gStageRun.vm.camera.viewport);

  if (!(gMissionDones & (1 << gStageMissionBitTable[id]))) {
    InitSpawnManager(gStageID8s[id], FALSE);
  } else {
    InitSpawnManager(gStageID8s[id], TRUE);
  }
  ClearVM(&gStageRun.vm, id);
}

// 0x0801a068
bool32 StageRun_Update(bool8 paused) {
  bool32 exit = FALSE;
  bool32 running = FALSE;
  if (paused) {
    return FALSE;
  }

  {
    bool32 cameraEnabled;
    gStageRun.frame++;

    cameraEnabled = (&gStageRun.vm.camera)->mode != CM0_DISABLED;
    do {
      if (!CheckMissionFail(&gStageRun)) {
        if (!(gStageRun.vm.active & VM_ACTIVE)) {
          if (FLAG(gCurStory.s.gameflags, IS_FREERUN)) {
            (gFreerunUpdate[gStageRun.id])(&gStageRun);
          } else {
            (gMissionUpdate[gStageRun.id])(&gStageRun);
          }
        } else {
          running = TRUE;
        }
      }

      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        exit = !(gStageRun.missionStatus & MISSION_STAY);
      }

      if (RunVM(&gStageRun.vm)) {
        exit = !(gStageRun.missionStatus & MISSION_STAY);
      } else {
        running = FALSE;
        trySkipEventScene(&gStageRun);
      }
    } while (running);

    if (!paused) {  // paused が TRUE のときは早期リターンしてるので、 ここでは paused は絶対 FALSE なので、条件は常に真
      Camera_Update(&gStageRun.vm.camera);
      // Update objects
      {
        void* src = gOverworld.terrain.objects;
        void* dst = gOverworld.terrain.objectsPrev;
        u32 bytesize = gOverworld.terrain.objectLen * sizeof(struct Hazard);
        u32 fastsize = bytesize & ~31;
        CpuFastCopy(src, dst, fastsize);
        if (bytesize & 31) CpuCopy32(src + fastsize, dst + fastsize, bytesize & 31);
        gOverworld.terrain.objectLenPrev = gOverworld.terrain.objectLen;
        gOverworld.terrain.objectLen = 0;
      }
      if (gStageRun.vm.camera.mode != CM0_DISABLED) UpdateStageLandscape(&gStageRun.vm.camera.viewport);
    }
    ApplyGiantElf(&gStageRun);
    if (cameraEnabled && ((&gStageRun.vm.camera)->mode != CM0_DISABLED)) UpdateSpawnManager(&gStageRun.vm.camera.viewport);
  }
  return exit;
}

/**
 * @note 0x0801a1e8
 */
void StageRun_Render(bool8 paused) {
  Renderer* r = gStageRun.renderer;

  if (!paused) {
    Camera_Shake(&gStageRun.vm.camera);
  }
  if ((&gStageRun.vm.camera)->mode != CM0_DISABLED) {
    DrawOverworld(r);  // -> RenderTask_Overworld
  }
  RenderWipeZ(&gStageRun.vm);  // wipe by "Z" and print string (if any)
  Camera_Render(&gStageRun.vm.camera);
}

// ミッションの終了状況を見てフラグを立てる
// GameLoop_EndRun からのみ呼び出される
void UpdateStoryFlag(void) {
  ExitStageLandscape();
  FUN_08021b88(&gStageRun.vm);
  RemoveAllPaletteAnimations();

  if (!(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    if (gMissionDones & (1 << STAGE_SPACE_CRAFT)) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_SPACE_CRAFT_DONE);
    }
    if ((gMissionDones & ((1 << STAGE_OLD_RESIDENTIAL) | (1 << STAGE_REPAIR_FACTORY) | (1 << STAGE_OCEAN) | (1 << STAGE_VOLCANO))) == ((1 << STAGE_OLD_RESIDENTIAL) | (1 << STAGE_REPAIR_FACTORY) | (1 << STAGE_OCEAN) | (1 << STAGE_VOLCANO))) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_FIRST4_DONE);  // First 4 missions
    }
    if (gMissionDones & (1 << STAGE_MISSILE_FACTORY)) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_MISSILE_DONE);
    }
    if ((gMissionDones & ((1 << STAGE_ICE_BASE) | (1 << STAGE_ANATRE_FOREST) | (1 << STAGE_TWILIGHT_DESERT))) == ((1 << STAGE_ICE_BASE) | (1 << STAGE_ANATRE_FOREST) | (1 << STAGE_TWILIGHT_DESERT))) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_MID3_DONE);  // Medium 3 missions
    }
    if (gMissionDones & (1 << STAGE_AREA_X2)) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_AREAX2_DONE);
    }
    if ((gMissionDones & ((1 << STAGE_GIANT_ELEVATOR) | (1 << STAGE_SUNKEN_LIBRARY) | (1 << STAGE_SNOWY_PLAINS) | (1 << STAGE_E_FACILITY))) == ((1 << STAGE_GIANT_ELEVATOR) | (1 << STAGE_SUNKEN_LIBRARY) | (1 << STAGE_SNOWY_PLAINS) | (1 << STAGE_E_FACILITY))) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_LATER4_DONE);  // Later 4 missions
    }
    if (gMissionDones & (1 << STAGE_SUB_ARCADIA)) {
      SET_FLAG(gCurStory.s.gameflags, FLAG_SUBARCADIA_DONE);
    }
    StoreStoryData(&gGameState.save.story);
  } else {
    LoadStoryData((u8)gStageRun.id, &gGameState.save.story);
  }
  StoreZeroStatus(gGameState.z2, &gGameState.save.status);
  FUN_080322c4(&gGameState.save.status);
}

void setStageCheckpoint(u8 cp) {
  gStageRun.checkpoint = cp;
  gStageRun.checkpointResultScreen = 0xFF;
  StoreStoryData(&gGameState.save.story);
  StoreZeroStatus(gGameState.z2, &gGameState.save.status);
}

// リザルト画面の前にカットシーンがある場合、カットシーンをスキップすると後続のリザルト画面を呼ぶコマンドもスキップしてしまうので、それを防ぐための(割と強引な)処理と思われる
void setStageCheckpoint2(u8 cp) {
  gStageRun.checkpointResultScreen = cp;
  StoreStoryData(&gGameState.save.story);
  StoreZeroStatus(gGameState.z2, &gGameState.save.status);
}

// ハンマーガなどのサイバーエルフの適用(ついでにストパーラ系のエルフの適用終了)
void ApplyGiantElf(struct StageRun* p) {
  struct Boss* boss = (struct Boss*)(p->vm).entities[1].entity;
  if (boss != NULL) {
    if (gTimeElfTimer != 0) {
      CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
      TurnUpBGM();
      gTimeElfTimer = 0;
    }
    StopSound(SE_TIME_ELF);
    StopSound(SE_TIME_ELF_HURRY);

    if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & VM_ACTIVE) && FLAG(gCurStory.s.gameflags, GIANT_ELF_ENABLED)) {
      if ((boss->s).kind == ENTITY_BOSS) {
        const u8 id = (boss->s).id;
        if (id != BOSS_MEGAMILPA) {
          if (id != BOSS_WORMER) {
            if (id != BOSS_BEE_SERVER) {
              if (id != BOSS_PANTHEON_AQUA_MOD) {
                if (id != BOSS_LOCOMO_IF) {
                  if (id != BOSS_PHANTOM) {
                    if (id != BOSS_REACTOR_CORE) {
                      if (id != BOSS_SPEAROOK) {
                        if ((boss->s).flags & COLLIDABLE) {
                          (boss->body).hp = ((u16)(boss->body).hp + 1) >> 1;
                          CLEAR_FLAG(gCurStory.s.gameflags, GIANT_ELF_ENABLED);
                          CLEAR_FLAG((&gGameState.save.story)->gameflags, GIANT_ELF_ENABLED);
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

static bool32 CheckMissionFail(struct StageRun* p) {
  const GameCommand* c;
  struct Zero* z = (struct Zero*)(p->vm).entities[0].entity;
  if ((z != NULL) && ((((z->body).status & BODY_STATUS_DEAD) || ((z->body).hp == 0)))) {
    gStageRun.missionStatus &= ~MISSION_STAY;
    gStageRun.missionStatus |= MISSION_PLAYER_DEAD;
  }

  if (!(gStageRun.missionStatus & MISSION_STAY)) {
    if (gStageRun.missionStatus & MISSION_PLAYER_DEAD) {
      gCollisionManager.disabled |= COLLMAN_DISABLED;
      gHUD.timeLeft = NULL;
      c = (p->vm).start;
      if ((c != Script_MissionFail) && (c != Script_MissionFail2)) {
        if (gStageRun.vm.transition != TRANSITION_NONE) {
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

static void trySkipEventScene(void* _) {
  struct GameState* g = &gGameState;

  if ((gJoypad[0].pressed & START_BUTTON) && (gStageRun.missionStatus & SKIPPABLE_CUTSCENE)) {
    if (gStageRun.checkpointResultScreen != 0xFF) {
      gStageRun.checkpoint = gStageRun.checkpointResultScreen;
    }
    CopyPlayerMaxHPChargeOnSkipEventScene(g->z2, &(g->save).status);
    gPaletteManager.filter[0] = gPaletteManager.filter[1] = gPaletteManager.filter[2] = FILTER_BLACK;
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
