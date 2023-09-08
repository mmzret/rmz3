#ifndef GUARD_RMZ3_VFX_H
#define GUARD_RMZ3_VFX_H

#include "collision.h"
#include "constants/constants.h"
#include "entity.h"
#include "types.h"

#if MODERN
#define SET_VFX_ROUTINE(vfx, routine)                                         \
  {                                                                           \
    *(u32 *)(&((vfx)->s).mode[0]) = routine;                                  \
    ((vfx)->s).onUpdate = (void *)((*gVFXFnTable[(((vfx)->s).id)])[routine]); \
  }
#else
#define SET_VFX_ROUTINE(vfx, routine)            \
  {                                              \
    u32 tbl, id;                                 \
    VFXFunc **r;                                 \
    tbl = (u32)gVFXFnTable;                      \
    id = (((vfx)->s).id) << 2;                   \
    r = (VFXFunc **)(tbl + id);                  \
                                                 \
    *(u32 *)((vfx)->s).mode = routine;           \
    ((vfx)->s).onUpdate = (void *)(*r)[routine]; \
  }
#endif

#if MODERN
#define INIT_VFX_ROUTINE(vfx, ghostID)                                            \
  {                                                                               \
    ((vfx)->s).id = ghostID;                                                      \
    ((vfx)->s).onUpdate = (void *)((*gVFXFnTable[(((vfx)->s).id)])[ENTITY_INIT]); \
  }
#else
#define INIT_VFX_ROUTINE(vfx, ghostID)               \
  {                                                  \
    u32 tbl;                                         \
    VFXFunc **r;                                     \
    tbl = (u32)gVFXFnTable;                          \
    ((vfx)->s).id = ghostID;                         \
                                                     \
    r = (VFXFunc **)(tbl + (ghostID << 2));          \
    ((vfx)->s).onUpdate = (void *)(*r)[ENTITY_INIT]; \
  }
#endif

extern const VFXRoutine *const gVFXFnTable[85];
extern const VFXRoutine gSmokeRoutine;
extern const VFXRoutine gSeaEnemyRoutine;
extern const VFXRoutine gChargeEffectRoutine;
extern const VFXRoutine gZeroDeathEffectRoutine;
extern const VFXRoutine gParticleRoutine;
extern const VFXRoutine gDashAfterImageRoutine;
extern const VFXRoutine gGhost7Routine;
extern const VFXRoutine gGhost8Routine;
extern const VFXRoutine gThunderEffectRoutine;
extern const VFXRoutine gFlameEffectRoutine;
extern const VFXRoutine gIceEffectRoutine;
extern const VFXRoutine gRippleRoutine;
extern const VFXRoutine gMissionAlertRoutine;
extern const VFXRoutine gEmotionBubbleRoutine;
extern const VFXRoutine gSlashedEnemyRoutine;
extern const VFXRoutine gGhost17Routine;
extern const VFXRoutine gGhost18Routine;
extern const VFXRoutine gGhost19Routine;
extern const VFXRoutine gGhost20Routine;
extern const VFXRoutine gGhost21Routine;
extern const VFXRoutine gGhost22Routine;
extern const VFXRoutine gNecroRoutine;
extern const VFXRoutine gShrimporinVFXRoutine;
extern const VFXRoutine gVFX25Routine;
extern const VFXRoutine gIcebonIcedustRoutine;
extern const VFXRoutine gGhost27Routine;
extern const VFXRoutine gGhost28Routine;
extern const VFXRoutine gGhost29Routine;
extern const VFXRoutine gGhost30Routine;
extern const VFXRoutine gGhost31Routine;
extern const VFXRoutine gGhost32Routine;
extern const VFXRoutine gGhost33Routine;
extern const VFXRoutine gGhost34Routine;
extern const VFXRoutine gVFX35Routine;
extern const VFXRoutine gVFX36Routine;
extern const VFXRoutine gVFX37Routine;
extern const VFXRoutine gVFX38Routine;
extern const VFXRoutine gVFX39Routine;
extern const VFXRoutine gVFX40Routine;
extern const VFXRoutine gVFX41Routine;
extern const VFXRoutine gExlifeIndicatorRoutine;
extern const VFXRoutine gVFX43Routine;
extern const VFXRoutine gVFX44Routine;
extern const VFXRoutine gVFX45Routine;
extern const VFXRoutine gVFX46Routine;
extern const VFXRoutine gVFX47Routine;
extern const VFXRoutine gElfParticleRoutine;
extern const VFXRoutine gVFX49Routine;
extern const VFXRoutine gVFX50Routine;
extern const VFXRoutine gVFX51Routine;
extern const VFXRoutine gVFX52Routine;
extern const VFXRoutine gVFX53Routine;
extern const VFXRoutine gVFX54Routine;
extern const VFXRoutine gVFX55Routine;
extern const VFXRoutine gVFX56Routine;
extern const VFXRoutine gVFX57Routine;
extern const VFXRoutine gVFX58Routine;
extern const VFXRoutine gVFX59Routine;
extern const VFXRoutine gVFX60Routine;
extern const VFXRoutine gVFX61Routine;
extern const VFXRoutine gVFX62Routine;
extern const VFXRoutine gVFX63Routine;
extern const VFXRoutine gGhost64Routine;
extern const VFXRoutine gGhost65Routine;
extern const VFXRoutine gGhost66Routine;
extern const VFXRoutine gGhost67Routine;
extern const VFXRoutine gGhost68Routine;
extern const VFXRoutine gGhost69Routine;
extern const VFXRoutine gGhost70Routine;
extern const VFXRoutine gGhost71Routine;
extern const VFXRoutine gGhost72Routine;
extern const VFXRoutine gGhost73Routine;
extern const VFXRoutine gCyberSpaceElfRoutine;
extern const VFXRoutine gGhost75Routine;
extern const VFXRoutine gBossExplosionRoutine;
extern const VFXRoutine gMinigameIconRoutine;
extern const VFXRoutine gGhost78Routine;
extern const VFXRoutine gGhost79Routine;
extern const VFXRoutine gSnowRoutine;
extern const VFXRoutine gSmallNumberRoutine;
extern const VFXRoutine gGhost82Routine;
extern const VFXRoutine gGhost83Routine;
extern const VFXRoutine gGhost84Routine;

void DeleteVFX(struct VFX *p);

struct VFX *CreateSmoke(u8 kind, struct Coord *c);
struct VFX *CreateChargeEffect(struct Zero *z, struct VFX *v, u8 r2);
struct VFX *CreateAfterImages(struct Entity *p);
void CreateParticle(struct Coord *c, u8 action, bool8 isRight);
void oz_080b3820(struct Coord *omegaCoord, bool8 isRight);
void CreateWallDust(struct Coord *c, bool8 isRight);
struct VFX *CreateRipple(struct Zero *z, bool8 outOfSea);
struct VFX *CreateEmotionBubble(u8 kind, struct Coord *target, struct Coord *c);
struct VFX *CreateCopyXIcon(struct Zero *z, struct Coord *c, u8 n);
struct VFX *CreateExlifeIndicator(u8 extraLife);
struct VFX *CreateMissionAlert(u8 kind);
struct VFX *CreateSlashedEnemy(struct Coord *c, const struct SlashedEnemy *data, u8 r2, u8 r3);

#endif  // GUARD_RMZ3_VFX_H
