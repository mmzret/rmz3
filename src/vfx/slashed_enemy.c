#include "entity.h"
#include "global.h"
#include "random.h"
#include "story.h"
#include "vfx.h"

struct Ghost16 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  s16 unk_74[2];
  bool8 unk_78[2];
  u16 unk_7a;
  const struct SlashedEnemy* data;
  u8 work[4];
};
static_assert(sizeof(struct Ghost16) == sizeof(struct VFX));

static void SlashedEnemy_Init(struct Ghost16* p);
static void SlashedEnemy_Update(struct Ghost16* p);
static void SlashedEnemy_Die(struct Ghost16* p);

// clang-format off
const VFXRoutine gSlashedEnemyRoutine = {
    [ENTITY_INIT] =      (void*)SlashedEnemy_Init,
    [ENTITY_UPDATE] =    (void*)SlashedEnemy_Update,
    [ENTITY_DIE] =       (void*)SlashedEnemy_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct VFX* CreateSlashedEnemy(Coords32* c, const struct SlashedEnemy* data, u8 kind, u8 r3) {
  struct Ghost16* p = (struct Ghost16*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_SLASHED_ENEMY);
    (p->s).coord = *c;
    (p->s).work[0] = kind, (p->s).work[1] = 0;
    p->unk_78[0] = (r3 >> 4) & 1;
    p->unk_78[1] = r3 & 1;
    p->data = data;
  }
  return (struct VFX*)p;
}

static void SlashedEnemy_Init(struct Ghost16* p) {
  const struct SlashedEnemy* data = p->data;
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, data->m);
  UpdateSpriteAnimation(p);
  SET_XFLIP(p, p->unk_78[0]);
  if (p->unk_78[0]) {
    (p->s).coord.x -= (data->c).x;
  } else {
    (p->s).coord.x += (data->c).x;
  }
  if (p->unk_78[1] != 0) {
    (p->s).d.x = -(data->d).x - (RANDOM(RNG_0202f388) & (data->unk_coord_0c).x);
    (p->s).unk_coord.x = -(data->unk_10).x;
  } else {
    (p->s).d.x = (data->d).x + (RANDOM(RNG_0202f388) & (data->unk_coord_0c).x);
    (p->s).unk_coord.x = (data->unk_10).x;
  }
  (p->s).coord.y += (data->c).y;
  (p->s).d.y = (data->d).y + (RANDOM(RNG_0202f388) & (data->unk_coord_0c).y);
  (p->s).unk_coord.y = (data->unk_10).y;
  p->unk_74[0] = data->unk_14[0], p->unk_74[1] = data->unk_14[1];
  (p->s).work[2] = data->unk_02[0];
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  SlashedEnemy_Update(p);
}

static void FUN_080b6744(struct Ghost16* p);
static void FUN_080b6834(void* _ UNUSED);

static void SlashedEnemy_Update(struct Ghost16* p) {
  static VFXFunc const sUpdates[] = {
      (VFXFunc)FUN_080b6744,
      (VFXFunc)FUN_080b6834,
  };
  if ((((p->data)->unk_02[1] & 0x40) == 0) && IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[1]])((void*)p);
}

static void SlashedEnemy_Die(struct Ghost16* p) {
  const struct SlashedEnemy* data = p->data;
  if (data->unk_02[1] & (1 << 0)) {
    CreateSmoke(3, &(p->s).coord);
  }
  if (data->unk_02[1] & (1 << 1)) {
    CreateSmoke(2, &(p->s).coord);
  }
  if (data->unk_02[1] & (1 << 2)) {
    CreateSmoke(1, &(p->s).coord);
    PlaySound(SE_ZAKO_EXPLODE);
  }
  if (data->unk_02[1] & (1 << 3)) {
    CreateSmoke(1, &(p->s).coord);
    PlaySound(SE_UNK_35);
  }
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

NON_MATCH static void FUN_080b6744(struct Ghost16* p) {
#if MODERN
  const struct SlashedEnemy* data = p->data;
  UpdateSpriteAnimation(p);
  if (data->unk_02[1] & (1 << 4)) {
    if ((p->s).work[2] & (1 << 0)) {
      (p->s).flags |= DISPLAY;
    } else {
      (p->s).flags &= ~DISPLAY;
    }
  }
  (p->s).d.y += (p->s).unk_coord.y;
  (p->s).coord.y += (p->s).d.y;
  if (!(data->unk_02[1] & (1 << 5))) {  // ここのコンパイル結果が合わない
    s32 x, y;
    if ((p->s).d.y > 0) {
      y = (p->s).coord.y + p->unk_74[1];
    } else {
      y = (p->s).coord.y - p->unk_74[1];
    }
    if (FUN_080098a4((p->s).coord.x, y)) (p->s).work[2] = 0;
    (p->s).d.x += (p->s).unk_coord.x;
    (p->s).coord.x += (p->s).d.x;
    if ((p->s).d.x > 0) {
      x = (p->s).coord.x + p->unk_74[0];
    } else {
      x = (p->s).coord.x - p->unk_74[0];
    }
    if (FUN_080098a4(x, (p->s).coord.y)) (p->s).work[2] = 0;
  } else {
    (p->s).d.x += (p->s).unk_coord.x;
    (p->s).coord.x += (p->s).d.x;
  }
  if (--(p->s).work[2] == 0xFF) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    SlashedEnemy_Die(p);
  }
#else
  INCCODE("asm/wip/FUN_080b6744.inc");
#endif
}

static void FUN_080b6834(void* _) {}
