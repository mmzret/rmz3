#include "entity.h"
#include "global.h"
#include "vfx.h"

/*
  さまざまな海の雑魚
*/

static void SeaEnemy_Init(struct VFX* p);
static void SeaEnemy_Update(struct VFX* p);
static void SeaEnemy_Die(struct VFX* p);

// clang-format off
const VFXRoutine gSeaEnemyRoutine = {
    [ENTITY_INIT] =      SeaEnemy_Init,
    [ENTITY_MAIN] =      SeaEnemy_Update,
    [ENTITY_DIE] =       SeaEnemy_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateSeaEnemy(s32 x, s32 y, u8 kind) {
  struct VFX* vfx = (struct VFX*)AllocEntityFirst(gVFXHeaderPtr);
  if (vfx != NULL) {
    (vfx->s).taskCol = 1;
    INIT_VFX_ROUTINE(vfx, 1);
    (vfx->s).tileNum = 0;
    (vfx->s).palID = 0;
    (vfx->s).work[0] = kind;
    ((vfx->s).coord).x = x;
    ((vfx->s).coord).y = y;
  }
}

// --------------------------------------------

void FUN_080b2e50(struct VFX* p);
void FUN_080b2ef0(struct VFX* p);
void FUN_080b2f7c(struct VFX* p);
void FUN_080b3024(struct VFX* p);

static void SeaEnemy_Init(struct VFX* p) {
  static const VFXFunc sInitializers[] = {
      FUN_080b2e50,
      FUN_080b2ef0,
      FUN_080b2f7c,
      FUN_080b3024,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080b30b4(struct VFX* p);
void FUN_080b3144(struct VFX* p);
void FUN_080b31d8(struct VFX* p);
void FUN_080b3278(struct VFX* p);

static void SeaEnemy_Update(struct VFX* p) {
  static const VFXFunc sUpdates[] = {
      FUN_080b30b4,
      FUN_080b3144,
      FUN_080b31d8,
      FUN_080b3278,
  };
  if ((p->props).seaEnemy.unk_4 != 0) {
    if ((p->props).seaEnemy.unk_4-- < 32) {
      if ((p->props).seaEnemy.unk_4 & 1) {
        (p->s).flags |= DISPLAY;
      } else {
        (p->s).flags &= ~DISPLAY;
      }
    }
  } else {
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

static void SeaEnemy_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/sea_enemy.inc");
