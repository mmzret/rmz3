#include "vfx.h"

#include "entity.h"
#include "global.h"

// clang-format off
const VFXRoutine* const gVFXFnTable[VFX_COUNT] = {
    [VFX_SMOKE] =  &gSmokeRoutine,
    [VFX_BUBBLE] = &gBubbleRoutine,
    [VFX_CHARGE_EFFECT] =  &gChargeEffectRoutine,
    [VFX_UNK_003] =  &gSmokeRoutine,
    [VFX_DEATH_EFFECT] =  &gZeroDeathEffectRoutine,
    [VFX_PARTICLE] =  &gParticleRoutine,
    [VFX_AFTER_IMAGE] =  &gDashAfterImageRoutine,
    [VFX_UNK_007] =  &gGhost7Routine,
    [VFX_UNK_008] =  &gGhost8Routine,
    [VFX_THUNDER_EFFECT] =  &gThunderEffectRoutine,
    [VFX_FLAME_EFFECT] = &gFlameEffectRoutine,
    [VFX_ICE_EFFECT] = &gIceEffectRoutine,
    [VFX_RIPPLE] = &gRippleRoutine,
    [VFX_UNK_013] = &gSmokeRoutine,
    [VFX_MISSION_ALERT] = &gMissionAlertRoutine,
    [VFX_EMOTION_BUBBLE] = &gEmotionBubbleRoutine,
    [VFX_SLASHED_ENEMY] = &gSlashedEnemyRoutine,
    [VFX_UNK_017] = &gGhost17Routine,
    [VFX_UNK_018] = &gGhost18Routine,
    [VFX_UNK_019] = &gGhost19Routine,
    [VFX_UNK_020] = &gGhost20Routine,
    [VFX_BATRING_NECRO] = &gBatringNecroRoutine,
    [VFX_UNK_022] = &gGhost22Routine,
    [VFX_NECRO] = &gNecroRoutine,
    [VFX_SHRIMPORIN] = &gShrimporinVFXRoutine,
    [VFX_UNK_025] = &gVFX25Routine,
    [VFX_UNK_026] = &gIcebonIcedustRoutine,
    [VFX_UNK_027] = &gGhost27Routine,
    [VFX_UNK_028] = &gGhost28Routine,
    [VFX_UNK_029] = &gGhost29Routine,
    [VFX_UNK_030] = &gGhost30Routine,
    [VFX_UNK_031] = &gGhost31Routine,
    [VFX_UNK_032] = &gGhost32Routine,
    [VFX_UNK_033] = &gGhost33Routine,
    [VFX_UNK_034] = &gGhost34Routine,
    [VFX_UNK_035] = &gVFX35Routine,
    [VFX_UNK_036] = &gVFX36Routine,
    [VFX_UNK_037] = &gVFX37Routine,
    [VFX_UNK_038] = &gVFX38Routine,
    [VFX_UNK_039] = &gVFX39Routine,
    [VFX_UNK_040] = &gVFX40Routine,
    [VFX_UNK_041] = &gVFX41Routine,
    [VFX_EXLIFE_INDICATOR] = &gExlifeIndicatorRoutine,
    [VFX_UNK_043] = &gVFX43Routine,
    [VFX_UNK_044] = &gVFX44Routine,
    [VFX_UNK_045] = &gVFX45Routine,
    [VFX_UNK_046] = &gVFX46Routine,
    [VFX_UNK_047] = &gVFX47Routine,
    [VFX_ELF_PARTICLE] = &gElfParticleRoutine,
    [VFX_UNK_049] = &gVFX49Routine,
    [VFX_UNK_050] = &gVFX50Routine,
    [VFX_UNK_051] = &gVFX51Routine,
    [VFX_UNK_052] = &gVFX52Routine,
    [VFX_UNK_053] = &gVFX53Routine,
    [VFX_UNK_054] = &gVFX54Routine,
    [VFX_UNK_055] = &gVFX55Routine,
    [VFX_UNK_056] = &gVFX56Routine,
    [VFX_UNK_057] = &gVFX57Routine,
    [VFX_UNK_058] = &gVFX58Routine,
    [VFX_UNK_059] = &gVFX59Routine,
    [VFX_UNK_060] = &gVFX60Routine,
    [VFX_UNK_061] = &gVFX61Routine,
    [VFX_UNK_062] = &gVFX62Routine,
    [VFX_UNK_063] = &gVFX63Routine,
    [VFX_UNK_064] = &gGhost64Routine,
    [VFX_UNK_065] = &gGhost65Routine,
    [VFX_UNK_066] = &gGhost66Routine,
    [VFX_UNK_067] = &gGhost67Routine,
    [VFX_UNK_068] = &gGhost68Routine,
    [VFX_UNK_069] = &gGhost69Routine,
    [VFX_UNK_070] = &gGhost70Routine,
    [VFX_MISSION_INFO] = &gGhost71Routine,
    [VFX_UNK_072] = &gGhost72Routine,
    [VFX_UNK_073] = &gGhost73Routine,
    [VFX_CS_ELF] = &gCyberSpaceElfRoutine,
    [VFX_UNK_075] = &gGhost75Routine,
    [VFX_BOSS_EXPLOSION] = &gBossExplosionRoutine,
    [VFX_MINIGAME_ICON] = &gMinigameIconRoutine,
    [VFX_UNK_078] = &gGhost78Routine,
    [VFX_UNK_079] = &gGhost79Routine,
    [VFX_UNK_080] = &gSnowRoutine,
    [VFX_SMALL_NUMBER] = &gSmallNumberRoutine,
    [VFX_UNK_082] = &gGhost82Routine,
    [VFX_UNK_083] = &gGhost83Routine,
    [VFX_UNK_084] = &gGhost84Routine,
};
// clang-format on

void InitVFXHeader(struct EntityHeader *h, struct VFX *p, s16 len) {
  s16 i;

  InitEntityHeader(h, ENTITY_VFX, &p->s, sizeof(struct VFX), len);
  for (i = 0; i < len; i++) {
    p[i].s.uniqueID = gEntityIDGenerator + i;
  }
  gEntityIDGenerator += len;
  gVFXHeaderPtr = h;
}

void UpdateVFXs(void) {
  struct Entity *p;
  struct EntityHeader *h = gVFXHeaderPtr;
  setCurProcessedEntityHeader(h);

  while (TRUE) {
    p = h->last = h->last->prev;
    if (p == (struct Entity *)&h->next) {
      break;
    }

    if (gPause) {
      if (p->id == 48) {
        ((EntityFunc)(p->onUpdate))(p);
      }
    } else {
      ((EntityFunc)(p->onUpdate))(p);
    }
  }
}

void DeleteVFX(struct VFX *p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
