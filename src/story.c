#include "story.h"

#include "game.h"
#include "global.h"

void resetCurStory(u8 stageID, struct Story *src) {
  s16 i;
  gCurStory.s.id = stageID;
  CpuFastCopy(src, &gCurStory.s.f0, 64);
  CpuCopy32((u8 *)src + 64, (u8 *)&gCurStory.s.f0 + 64, 20);
  gCurStory.s.f0 &= ~STORY_CYBER;
  gCurStory.s.elfFlags &= ~ARMOR_ELF_ENABLED;
  gCurStory.s.elfFlags &= ~GIANT_ELF_ENABLED;
  gCurStory.s.elfFlags &= ~TIME_ELF_ENABLED;
  gCurStory.s.elfFlags &= ~ELF_B4_ENABLED;
  gCurStory.s.elfFlags &= ~DYLPHINA_ENABLED;
  gCurStory.s.elfFlags &= ~METTAUR_ENABLED;
  gCurStory.s.unk_0a &= ~(1 << 1);
  for (i = 29; i < 70; i++) {
    ENEMY_KILLCOUNT(i - 29) = 0;
  }
  gCurStory.unk_54 = 0;
}

void FUN_08019678(struct Story *p) {
  CpuFastFill(0, p, 64);
  CpuFill32(0, &p->flags[52], 20);
  p->f2 |= SUNKEN_ANALYZE;
  p->f2 |= (1 << 3);
}

void saveCurStory(struct Story *dst) {
  CpuFastCopy(&gCurStory.s.f0, dst, 64);
  CpuCopy32((u8 *)&gCurStory.s.f0 + 64, (u8 *)dst + 64, 20);
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
