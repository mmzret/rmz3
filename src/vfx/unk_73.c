#include "global.h"
#include "vfx.h"
#include "story.h"

static const VFXFunc sInitializers[2];
static const VFXFunc sUpdates[2];

void Ghost73_Init(struct VFX* p);
void Ghost73_Update(struct VFX* p);
void Ghost73_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost73Routine = {
    [ENTITY_INIT] =      (void*)Ghost73_Init,
    [ENTITY_UPDATE] =    (void*)Ghost73_Update,
    [ENTITY_DIE] =       (void*)Ghost73_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};

void FUN_080c7250(struct VFX* p);
// clang-format on

struct VFX* FUN_080c6e24(struct Entity* e) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_073);
    (p->s).work[0] = 0;
    (p->s).unk_28 = e;
  }
  return p;
}

void FUN_080c6e70(struct Entity* e, struct Coord* c) {
  s32 i;
  for (i = 0; i < 3; i++) {
    struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
    if (p != NULL) {
      INIT_VFX_ROUTINE(p, VFX_UNK_073);
      (p->s).work[0] = 1;
      (p->s).work[1] = i;
      (p->s).unk_28 = e;
      (p->s).coord.x = c->x;
      (p->s).coord.y = c->y;
    }
  }
}

void Ghost73_Init(struct VFX* p) {
  (sInitializers[(p->s).work[0]])((void*)p);
}

void Ghost73_Update(struct VFX* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])((void*)p);
}

void Ghost73_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/unk_73_a.inc");

void FUN_080c7250(struct VFX* p) {
  (p->s).coord.x += (p->s).d.x;
  (p->s).coord.y += (p->s).d.y;
  (p->s).d.y += 0x40;
  UpdateEntityAnim(&p->s);
  (p->s).work[2]++;
  if ((p->s).work[2] & 1) {
    (p->s).flags |= DISPLAY;
  } else {
    (p->s).flags &= ~DISPLAY;
  }
  if (FUN_080098a4((p->s).coord.x, (p->s).coord.y)) {
    CreateSmoke(3, &(p->s).coord);
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  }
}

// --------------------------------------------

void FUN_080c6f60(struct VFX* p);
void FUN_080c7120(struct VFX* p);

static const VFXFunc sInitializers[2] = {
    FUN_080c6f60,
    FUN_080c7120,
};

// --------------------------------------------

void FUN_080c705c(struct VFX* p);
void FUN_080c7250(struct VFX* p);

static const VFXFunc sUpdates[2] = {
    FUN_080c705c,
    FUN_080c7250,
};

// --------------------------------------------

const motion_t motion_t_ARRAY_0836f884[3] = {
    MOTION(SM220_CANNON_HOPPER, 8),
    MOTION(SM220_CANNON_HOPPER, 8),
    MOTION(SM220_CANNON_HOPPER, 9),
};
