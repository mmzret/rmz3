#include "game.h"
#include "global.h"
#include "hud.h"
#include "mission.h"
#include "overworld.h"
#include "script.h"
#include "system.h"
#include "text.h"
#include "zero.h"

static void OverworldLoop_Nop(struct GameState *_ UNUSED);
void OverworldLoop_CerveauTalk(struct GameState *);
void OverworldLoop_080f1fe4(struct GameState *);
void OverworldLoop_MissionSelect(struct GameState *);
void OverworldLoop_Computer(struct GameState *);
void OverworldLoop_SunkenLibrarySearch(struct GameState *);
void OverworldLoop_080f2c24(struct GameState *);
void OverworldLoop_AfterMissileTalk(struct GameState *);
void OverworldLoop_080f2e44(struct GameState *);
void OverworldLoop_080f2f44(struct GameState *);
void OverworldLoop_080f3044(struct GameState *);
void OverworldLoop_Save_080f3128(struct GameState *);

// clang-format off
// 00 04 xx nn
const GameLoopFunc gOverworldLoops[14] = {
    OverworldLoop_Nop,
		OverworldLoop_ManageSaveData,
		OverworldLoop_CmdRoomTalk,
		OverworldLoop_CerveauTalk,
		OverworldLoop_080f1fe4,
		OverworldLoop_MissionSelect,
		OverworldLoop_Computer,
		OverworldLoop_SunkenLibrarySearch,
		OverworldLoop_080f2c24,
		OverworldLoop_AfterMissileTalk,
		OverworldLoop_080f2e44,
		OverworldLoop_080f2f44,
		OverworldLoop_080f3044,
		OverworldLoop_Save_080f3128,
};
// clang-format on

// ------------------------------------------------------------------------------------------------------------------------------------

void CheckItemGain(struct GameState *p) {
  if ((gECrystalGainAmount != 0) && ((--gECrystalGainAmount & 3) == 3)) {
    bool8 ok = AddECrystal(p->z2, 4);
    if (ok) {
      PlaySound(SE_GAIN_ECRYSTAL);
    } else {
      gECrystalGainAmount = 0;
    }
  }

  if (!(gStageRun.missionStatus & MISSION_FAIL)) {
    if ((gLifeRecoverAmount != 0) && ((p->z2->body).hp) >= GetMaxHP(p->z2)) {
      gSubtankRecoverAmount += gLifeRecoverAmount;
      gLifeRecoverAmount = 0;
    }
    if ((gSubtankRecoverAmount != 0) && ((--gSubtankRecoverAmount & 3) == 3)) {
      bool8 ok = incrementSubtankHP(p->z2);
      if (!ok) {
        gSubtankRecoverAmount = 0;
      }
    }
    if ((gLifeRecoverAmount != 0) && ((--gLifeRecoverAmount & 3) == 3)) {
      bool8 ok = UseSubtank(p->z2);
      if (!ok) {
        gLifeRecoverAmount = 0;
      }
    }
  } else {
    gLifeRecoverAmount = 0;
  }
}

void DrawHUD(struct GameState *_ UNUSED) {
  s8 ok = FALSE;
  if ((!(gStageRun.vm.active & 1)) && (gStageRun.vm.indicator == NULL) && (gGameState.mode[2] == 0) && (gTextWindow.text.props.kind != MUGSHOT) && (gHUD.z != NULL)) {
    DrawStatus();
    ok = TRUE;
  }
  if (!ok) {
    gHUD.unk_02 = 0;
  }
  DrawLeftTime();
}

void RunOverworldLoop(struct GameState *p) {
  (gOverworldLoops[p->mode[2]])(p);
  return;
}

static void OverworldLoop_Nop(struct GameState *_ UNUSED) { return; }
