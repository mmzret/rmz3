#include "entity.h"
#include "global.h"
#include "vfx.h"

void Ghost77_Init(struct VFX* p);
void Ghost77_Update(struct VFX* p);
void Ghost77_Die(struct VFX* p);

// clang-format off
const VFXRoutine gMinigameIconRoutine = {
    [ENTITY_INIT] =      (void*)Ghost77_Init,
    [ENTITY_UPDATE] =    (void*)Ghost77_Update,
    [ENTITY_DIE] =       (void*)Ghost77_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateMinigameIcon_1(Coords32* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 0;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

static const VFXFunc sUpdates[5];

struct VFX* CreateCopyXIcon(struct Zero* z, struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 1;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = (struct Entity*)z;
  }
  return p;
}

struct VFX* FUN_080c8204(struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 2;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
  }
  return p;
}

struct VFX* FUN_080c825c(struct Entity* e, struct Coord* c, u8 n) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 3;
    (p->s).work[1] = n;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = e;
  }
  return p;
}

struct Unk77Props { u32 unk_0; u8 unk_4[4]; u8 unk_8; };

struct VFX* FUN_080c82b8(struct Entity* e, struct Coord* c, u8 a2, u32 a3, u8 a4) {
  struct VFX* p = (struct VFX*)AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_MINIGAME_ICON);
    (p->s).work[0] = 4;
    (p->s).work[1] = a2;
    (p->s).coord.x = c->x;
    (p->s).coord.y = c->y;
    (p->s).unk_28 = e;
    ((struct Unk77Props*)p->buffer)->unk_0 = a3;
    ((struct Unk77Props*)p->buffer)->unk_8 = a4;
  }
  return p;
}

INCASM("asm/vfx/minigame_icon_a.inc");

void Ghost77_Update(struct VFX* p) {
  (sUpdates[(p->s).mode[1]])((void*)p);
}


void Ghost77_Die(struct VFX* p) {
  (p->s).flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/vfx/minigame_icon_b.inc");

// --------------------------------------------

void FUN_080c843c(struct VFX* p);
void FUN_080c8488(struct VFX* p);
void FUN_080c8628(struct VFX* p);
void FUN_080c8684(struct VFX* p);
void FUN_080c8744(struct VFX* p);

// clang-format off
static const VFXFunc sUpdates[5] = {
    FUN_080c843c,
    FUN_080c8488,
    FUN_080c8628,
    FUN_080c8684,
    FUN_080c8744,
};
// clang-format on

// --------------------------------------------

// 0x0836f998
const motion_t motion_t_ARRAY_0836f998[3] = {
    MOTION(SM014_CHIPICON, 8),
    MOTION(SM014_CHIPICON, 7),
    MOTION(SM014_CHIPICON, 9),
};
