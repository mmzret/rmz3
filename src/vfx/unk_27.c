#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

// gyro cannon?

static void Ghost27_Init(struct Entity* p);
static void Ghost27_Update(struct Entity* p);
static void Ghost27_Die(struct Entity* p);

// clang-format off
const VFXRoutine gGhost27Routine = {
    [ENTITY_INIT] =      (void*)Ghost27_Init,
    [ENTITY_UPDATE] =    (void*)Ghost27_Update,
    [ENTITY_DIE] =       (void*)Ghost27_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};

extern const struct SlashedEnemy sSlashedEnemies[4];
// clang-format on

void CreateGhost27(Coords32* c, u8 r1, u8 r2) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_027);
    p->coord = *c;
    SET_XFLIP(p, r1);
    p->work[0] = r2;
  }
}

// --------------------------------------------

static void FUN_080b9b9c(struct Entity* p);
static void FUN_080b9c08(struct Entity* p);

static void Ghost27_Init(struct Entity* p) {
  static const EntityFunc sInitializers[] = {
      (void*)FUN_080b9b9c,
      (void*)FUN_080b9c08,
  };
  (sInitializers[p->work[0]])(p);
}

void FUN_080b9c50(struct VFX* p);
void FUN_080b9ca4(struct VFX* p);

static void Ghost27_Update(struct Entity* p) {
  static const EntityFunc sUpdates[] = {
      (void*)FUN_080b9c50,
      (void*)FUN_080b9ca4,
  };
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[p->work[0]])(p);
}

// --------------------------------------------

void FUN_080b9cf8(struct VFX* p);
void FUN_080b9db0(struct VFX* p);

static void Ghost27_Die(struct Entity* p) {
  static const EntityFunc sDeinitializers[] = {
      (void*)FUN_080b9cf8,
      (void*)FUN_080b9db0,
  };
  if (IS_METTAUR) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeinitializers[p->work[0]])(p);
}

// --------------------------------------------

static void FUN_080b9b9c(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 1));
  if (p->flags & X_FLIP) {
    (p->d).x = PIXEL(1) / 4;
    (p->unk_coord).x = -2;
  } else {
    (p->d).x = -PIXEL(1) / 4;
    (p->unk_coord).x = 2;
  }
  (p->d).y = PIXEL(1) / 4;
  (p->unk_coord).y = -2;
  p->work[2] = 32;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost27_Update(p);
}

static void FUN_080b9c08(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 8));
  (p->d).y = 0;
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  Ghost27_Update(p);
}

void FUN_080b9c50(struct VFX* p) {
  UpdateEntityAnim(&p->s);
  (p->s).d.x += (p->s).unk_coord.x;
  (p->s).d.y += (p->s).unk_coord.y;
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  (p->s).work[2]--;
  if ((p->s).work[2] == 0xff) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost27_Die((struct Entity*)p);
  }
}

void FUN_080b9ca4(struct VFX* p) {
  UpdateEntityAnim(&p->s);
  (p->s).d.y += 0x40;
  if ((p->s).d.y > 0x700) {
    (p->s).d.y = 0x700;
  }
  (p->s).coord.y += (p->s).d.y;
  if (FUN_080098a4((p->s).coord.x, (p->s).coord.y + 0xa00)) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    Ghost27_Die((struct Entity*)p);
  }
}

void FUN_080b9cf8(struct VFX* p) {
  struct Coord* sc;
  {
    struct Coord* c = &(p->s).coord;
    const struct SlashedEnemy* d = &sSlashedEnemies[2];
    u8 f = (p->s).flags & X_FLIP;
    u32 hi = f ? 0x10 : 0;
    u8 arg;
    if (f) {
      arg = 1;
      arg |= hi;
    } else {
      arg = hi;
    }
    CreateSlashedEnemy(c, d, 0, arg);
  }
  {
    struct Coord* c = &(p->s).coord;
    const struct SlashedEnemy* d = &sSlashedEnemies[3];
    u8 f = (p->s).flags & X_FLIP;
    u32 hi = f ? 0x10 : 0;
    u8 arg;
    sc = c;
    if (f) {
      arg = 1;
      arg |= hi;
    } else {
      arg = hi;
    }
    CreateSlashedEnemy(c, d, 0, arg);
  }
  CreateSmoke(1, sc);
  if ((p->s).flags & X_FLIP) {
    CreateSmoke(2, sc);
  } else {
    CreateSmoke(2, sc);
  }
  PlaySound(0x2A);
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

void FUN_080b9db0(struct VFX* p) {
  struct Coord* sc;
  {
    struct Coord* c = &(p->s).coord;
    const struct SlashedEnemy* d = &sSlashedEnemies[2];
    u8 f = (p->s).flags & X_FLIP;
    u32 hi = f ? 0x10 : 0;
    u8 arg;
    if (f) {
      arg = 1;
      arg |= hi;
    } else {
      arg = hi;
    }
    CreateSlashedEnemy(c, d, 0, arg);
  }
  {
    struct Coord* c = &(p->s).coord;
    const struct SlashedEnemy* d = &sSlashedEnemies[3];
    u8 f = (p->s).flags & X_FLIP;
    u32 hi = f ? 0x10 : 0;
    u8 arg;
    sc = c;
    if (f) {
      arg = 1;
      arg |= hi;
    } else {
      arg = hi;
    }
    CreateSlashedEnemy(c, d, 0, arg);
  }
  CreateSmoke(1, sc);
  if ((p->s).flags & X_FLIP) {
    CreateSmoke(2, sc);
  } else {
    CreateSmoke(2, sc);
  }
  PlaySound(0x2A);
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
