#include "story.h"

#include "game.h"
#include "global.h"

void resetCurStory(u8 stageID, struct Story *src) {
  s16 i;
  gCurStory.s.id = stageID;
  CpuFastCopy(src, &gCurStory.s.gameflags[0], 64);
  CpuCopy32((u8 *)src + 64, (u8 *)&gCurStory.s.gameflags[0] + 64, 20);
  CLEAR_FLAG(gCurStory.s.gameflags, IN_CYBERSPACE);
  CLEAR_FLAG(gCurStory.s.gameflags, ARMOR_ELF_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, GIANT_ELF_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, TIME_ELF_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, ELF_B4_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, DYLPHINA_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, METTAUR_ENABLED);
  CLEAR_FLAG(gCurStory.s.gameflags, FLAG_49);
  for (i = 29; i < 70; i++) {
    ENEMY_KILLCOUNT(i - 29) = 0;
  }
  gCurStory.unk_54 = 0;
}

void FUN_08019678(struct Story *p) {
  CpuFastFill(0, p, 64);
  CpuFill32(0, &p->counts[52], 20);
  SET_FLAG(p->gameflags, SUNKEN_ANALYZE);
  SET_FLAG(p->gameflags, FLAG_19);
}

void saveCurStory(struct Story *dst) {
  CpuFastCopy(&gCurStory.s.gameflags[0], dst, 64);
  CpuCopy32((u8 *)&gCurStory.s.gameflags[0] + 64, (u8 *)dst + 64, 20);
}

void ClearPlayInfo(struct PlayInfo *p) {
  s32 i;

  p->extraLife = 2;
  p->rank = RANK_F;
  p->codenameSuffix = WARRIOR;
  p->pad_03 = 0;
  p->clearCodenameSuffix = WARRIOR;
  p->codenamePrefix = CODENAME_NO_PREFIX;
  p->pad_05 = 0;
  p->clearCodenamePrefix = CODENAME_NO_PREFIX;
  p->allElfCompleted = 0;
  p->collectFlag = 0;
  p->scoreSum = 0;
  p->playTime = 0;
  p->clearCount = 0;
  p->unusedClearCount = 0;
  p->unk_12 = 0;
  p->lastStage = 0;
  p->missionDones = 0;
  p->unusedMissionDones = 0;
  p->unk_1c = 0;
  p->fusionCount = 0;
  for (i = 0; i < 20; i++) {
    p->unk_20[i] = 0;
  }
  for (i = 0; i < 8; i++) {
    p->suffixIdx[i] = 0;
  }
  for (i = 0; i < 16; i++) {
    p->unk_3a[i] = 0;
  }
}
