#include "boss.h"
#include "global.h"
#include "vfx.h"

struct VFX25 {
  struct Entity s;
  // props (16bytes, offset: 0x74..)
  Coords32 c;  // 0x74
  u8 unk_7c[4];
  u16 unk_80;
  u16 unk_82;
};
static_assert(sizeof(struct VFX25) == sizeof(struct VFX));

static void VFX25_Init(struct VFX25* p);
static void VFX25_Update(struct Entity* p);
static void VFX25_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX25Routine = {
    [ENTITY_INIT] =      (VFXFunc)VFX25_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX25_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX25_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080b9184(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_025);
    p->work[0] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

struct Entity* omegaWhite_080b91d4(Coords32* c, u8 n, struct Entity* omega) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_025);
    p->work[0] = n;
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->unk_28 = (void*)omega;
  }
  return p;
}

struct Entity* FUN_080b9228(Coords32* c) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_025);
    p->work[0] = 4;
    (p->coord).x = c->x, (p->coord).y = c->y;
  }
  return p;
}

// --------------------------------------------

static void VFX25_Init(struct VFX25* p) {
  if ((p->s).work[0] == 0) {
    EnableSpriteAnimation_Normal(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    (p->s).work[2] = 8;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 0, (p->s).mode[2] = 0, (p->s).mode[3] = 0;

  } else if ((p->s).work[0] == 1) {
    EnableSpriteAnimation_Normal(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    (p->s).work[2] = 8;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 1, (p->s).mode[2] = 0, (p->s).mode[3] = 0;

  } else if ((p->s).work[0] == 2) {
    EnableSpriteAnimation_Normal(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    (p->c).x = 0, (p->c).y = 0;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 2, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
    (p->s).renderPrio = 24;

  } else if ((p->s).work[0] == 3) {
    EnableSpriteAnimation_Normal(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    (p->c).x = 0, (p->c).y = 0;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 3, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
    (p->s).renderPrio = 24;
    (p->s).work[2] = 160;

  } else if ((p->s).work[0] == 4) {
    struct VFX25* q;

    (p->s).work[2] = 60;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 4, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
    q = (struct VFX25*)AllocEntityLast(gVFXHeaderPtr);
    if (q != NULL) {
      INIT_VFX_ROUTINE(q, VFX_UNK_025);
      (q->s).work[0] = 5;
      (q->s).coord = (p->s).coord;
      (q->s).d.x = 0;
      q->unk_80 = 0xe000;
      (q->s).d.y = 0xC0;
    }

  } else if ((p->s).work[0] == 5) {
    EnableSpriteAnimation_Affine(p);
    (p->s).flags |= DISPLAY;
    (p->s).flags |= FLIPABLE;
    (p->s).work[2] = (RANDOM(RNG_0202f388) & 0x7) + 60;
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    (p->s).mode[1] = 5, (p->s).mode[2] = 0, (p->s).mode[3] = 0;
  }

  VFX25_Update((void*)p);
}

// --------------------------------------------

static void FUN_080b9494(struct Entity* p);
void FUN_080b94dc(struct Entity* p);
void FUN_080b9530(struct VFX* vfx);
void FUN_080b963c(struct VFX25* p);
void FUN_080b970c(struct VFX* vfx);
void FUN_080b9738(struct VFX* vfx);
static void FUN_080b97f4(struct Entity* p);

static void VFX25_Update(struct Entity* p) {
  // clang-format off
  static const EntityFunc sUpdates[7] = {
      (void*)FUN_080b9494,
      (void*)FUN_080b94dc,
      (void*)FUN_080b9530,
      (void*)FUN_080b963c,
      (void*)FUN_080b970c,
      (void*)FUN_080b9738,
      (void*)FUN_080b97f4,
  };
  // clang-format on
  (sUpdates[p->mode[1]])(p);
}

// --------------------------------------------

static void VFX25_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

// 0x080b9494
static void FUN_080b9494(struct Entity* p) {
  p->work[2]--;
  if (p->work[2] == 0) {
    p->work[2] = 8, p->mode[1] = 1, p->mode[2] = 0;
    return;
  }

  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 8));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

void FUN_080b94dc(struct Entity* p) {
  if (--p->work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  } else {
    switch (p->mode[2]) {
      case 0:
        SetSpriteAnimation(p, MOTION(SM010_OMEGA_RING, 9));
        p->mode[2]++;
        FALLTHROUGH;
      case 1:
        UpdateSpriteAnimation(p);
        break;
    }
  }
}

INCASM("asm/vfx/unk_25.inc");

// 0x080b963c
void FUN_080b963c(struct VFX25* p) {
  if ((p->s).unk_28->mode[0] > 1 || --(p->s).work[2] == 0) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
  } else {
    struct Entity* parent;
    switch ((p->s).mode[2]) {
      case 0:
        SetSpriteAnimation(p, MOTION(SM011_OMEGA_RECOVER, 1));
        (p->s).work[3] = 0;
        (p->s).mode[2]++;
        FALLTHROUGH;
      case 1: {
        u8 t;
        Object* obj;
        parent = (p->s).unk_28;
        (p->s).coord.x = parent->coord.x + p->c.x;
        (p->s).coord.y = parent->coord.y + p->c.y;
        t = (p->s).work[3]++ & 1;
        obj = (Object*)parent;
        if (t) {
          (p->s).flags |= DISPLAY;
        } else {
          (p->s).flags &= ~DISPLAY;
        }
        if (obj->body.invincibleTime != 0 ||
            (gWhitePaintFlags[obj->invincibleID >> 5] & (1 << (obj->invincibleID & 0x1F))) ||
            (obj->body.status & BODY_STATUS_WHITE)) {
          (p->s).flags &= ~DISPLAY;
        }
        UpdateSpriteAnimation(p);
        break;
      }
    }
  }
}

INCASM("asm/vfx/unk_25_b.inc");

static void FUN_080b97f4(struct Entity* p) {
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM224_RUBBLE, 0));
      p->work[2] = 40;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if (p->work[2] & 1) {
        p->flags |= DISPLAY;
      } else {
        p->flags &= ~DISPLAY;
      }
      if (p->work[2] > 0) {
        if (--p->work[2] == 0) SET_VFX_ROUTINE(p, ENTITY_DIE);
      }
      break;
    }
  }
}
