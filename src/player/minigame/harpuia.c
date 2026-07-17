#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "zero.h"

struct Enemy* FUN_0809af20(struct Zero* z, Coords32* c, u8 n);

static const struct Collision sCollisions[7];

static void Harpuia_Init(struct Zero* z);
void Harpuia_Update(struct Zero* z);
void Harpuia_Die(struct Zero* z);

// clang-format off
const ZeroRoutine gHarpuiaRoutine = {
  [ENTITY_INIT] =       (void*)Harpuia_Init,
  [ENTITY_UPDATE] =     (void*)Harpuia_Update,
  [ENTITY_DIE]  =       (void*)Harpuia_Die,
  [ENTITY_DISAPPEAR] =  (void*)RemovePlayer,
  [ENTITY_EXIT] =       (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreatePlayerHarpuia(void* q, Coords32* c, u8 n) {
  struct Entity* p = AllocPlayer();
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_PLAYER_ROUTINE(p, PLAYER_MINIGAME_HARPUIA);
    p->coord = *c;
    p->work[0] = n;
    p->unk_28 = q;
  }
  return p;
}

static void Harpuia_Init(struct Zero* z) {
  Coords32 c, *d, *uc;
  s32 x, y;

  EnableSpriteAnimation_Normal(z);
  SetSpriteTableDynamic(z);
  (z->s).flags |= DISPLAY;
  (z->s).flags |= FLIPABLE;

  (z->s).spr.xflip = TRUE;
  (z->s).spr.oam.xflip = TRUE;
  (z->s).flags |= X_FLIP;
  INIT_BODY(z, &sCollisions[0], 32, NULL);
  (z->s).coord.y = FUN_0800a05c((z->s).coord.x, (z->s).coord.y);
  SET_PLAYER_ROUTINE(z, ENTITY_UPDATE);
  (z->s).mode[1] = 0;
  (z->s).mode[2] = 0;
  (z->s).mode[3] = 0;

  c = (z->s).coord;
  (z->mg).harpuia.enemy = FUN_0809af20(z, &c, 0);
  (z->mg).harpuia.unk_a = 0;
  (z->mg).harpuia.x = (z->s).coord.x;
  (z->mg).harpuia.y = (z->s).coord.y;
  (z->mg).harpuia.unk_8 = 0;
  (z->mg).harpuia.unk_9 = 0;

  d = &(z->s).d;
  d->x = d->y = 0;
  uc = &(z->s).unk_coord;
  uc->x = uc->y = 0;

  (z->mg).harpuia.unk_b = 0;

  Harpuia_Update(z);
}

INCASM("asm/player/harpuia_a.inc");

void Harpuia_Die(struct Zero* z) {
  (z->s).flags &= ~DISPLAY;
  (z->s).flags &= ~FLIPABLE;
  EXIT_BODY(z);
  SET_PLAYER_ROUTINE(z, ENTITY_DISAPPEAR);
}

bool8 FUN_0803532c(struct Zero* z) { return TRUE; }

void FUN_08035330(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      (z->s).work[2] = 0x3c;
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&z->s);
      if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_0803537c(struct Zero* z) {
  if (((struct MinigameState*)(z->s).unk_28)->unk_04 == 1 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

void FUN_080353a8(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      SetDDP(&z->body, &sCollisions[0]);
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&z->s);
      break;
  }
}

bool8 FUN_080353e4(struct Zero* z) {
  if ((z->s).mode[2] > 1 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[1] = 3;
    (z->s).mode[2] = 0;
  }
  return TRUE;
}

void FUN_0803540c(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      (z->s).work[2] = 0xa;
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&z->s);
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).work[2] = 0xa;
        (z->s).mode[2]++;
      } else if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[2]++;
      }
      break;
    case 2:
      UpdateSpriteAnimation(&z->s);
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).work[2] = 0xa;
        (z->s).mode[2]++;
      }
      break;
    case 3:
      UpdateSpriteAnimation(&z->s);
      if ((z->s).work[2] == 0 || --(z->s).work[2] == 0) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_080354a4(struct Zero* z) {
  if ((z->s).mode[2] == 1 && *(s8*)((u8*)z + 0x71) > 3 && (gJoypad[0].pressed & B_BUTTON)) {
    (z->s).mode[3] = (z->s).mode[2];
  }
  return TRUE;
}

void harpuia_080354d4(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x22));
      SetDDP(&z->body, &sCollisions[1]);
      PlaySound(0xf9);
      *(u8*)((u8*)z + 0xf) = 0;
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(&z->s);
      if ((*(u32*)((u8*)z + 0x70) & 0x00FFFF00) == 0x00010500) {
        SetDDP(&z->body, &sCollisions[0]);
      }
      if (*(u8*)((u8*)z + 0x73) == 3) {
        if (*(u8*)((u8*)z + 0xf) == 1) {
          (z->s).mode[2]++;
        } else {
          (z->s).mode[1] = 1;
          (z->s).mode[2] = 0;
        }
      }
      break;
    case 2:
      SetMotion(&z->s, MOTION(0xBE, 0x23));
      SetDDP(&z->body, &sCollisions[1]);
      PlaySound(0xf9);
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 3:
      UpdateSpriteAnimation(&z->s);
      if ((*(u32*)((u8*)z + 0x70) & 0x00FFFF00) == 0x00010400) {
        SetDDP(&z->body, &sCollisions[0]);
      }
      if (*(u8*)((u8*)z + 0x73) == 3) {
        (z->s).mode[1] = 1;
        (z->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_080355c0(struct Zero* z) { return TRUE; }

void FUN_080355c4(struct Zero* z) {
  switch ((z->s).mode[2]) {
    case 0:
      SetMotion(&z->s, MOTION(0xBE, 0x21));
      *(u32*)((u8*)z + 0x8c) = 0;
      *(u32*)((u8*)z + 0x90) = 0;
      *(u8*)((u8*)z + 0x94) = 0;
      (z->s).flags &= ~COLLIDABLE;
      (z->s).d.y = 0;
      (z->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 push;
      (z->s).d.y += 0x40;
      if ((z->s).d.y > 0x700) {
        (z->s).d.y = 0x700;
      }
      (z->s).coord.y += (z->s).d.y;
      if ((z->s).coord.y <= 0x12C00) {
        push = PushoutToUp2((z->s).coord.x, (z->s).coord.y);
        if (push == 0) {
          push = PushoutToUp2((z->s).coord.x + 0x1A00, (z->s).coord.y);
          if (push == 0) {
            push = PushoutToUp2((z->s).coord.x - 0x1A00, (z->s).coord.y);
          }
        }
        if (push != 0) {
          (z->s).coord.y += push;
        }
      }
      if ((z->s).coord.y - 0x6400 > 0x14000) {
        (z->s).d.y = 0;
        (z->s).flags &= ~DISPLAY;
      }
      UpdateSpriteAnimation(&z->s);
      break;
    }
  }
}

INCASM("asm/player/harpuia_b.inc");

// --------------------------------------------

bool8 FUN_0803532c(struct Zero* z);
bool8 FUN_0803537c(struct Zero* z);
bool8 FUN_080353e4(struct Zero* z);
bool8 FUN_080354a4(struct Zero* z);
bool8 FUN_080355c0(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates1[5] = {
    FUN_0803532c,
    FUN_0803537c,
    FUN_080353e4,
    FUN_080354a4,
    FUN_080355c0,
};
// clang-format on

// --------------------------------------------

void FUN_08035330(struct Zero* z);
void FUN_080353a8(struct Zero* z);
void FUN_0803540c(struct Zero* z);
void harpuia_080354d4(struct Zero* z);
void FUN_080355c4(struct Zero* z);

// clang-format off
const ZeroFunc sHarpuiaUpdates2[5] = {
    FUN_08035330,
    FUN_080353a8,
    FUN_0803540c,
    harpuia_080354d4,
    FUN_080355c4,
};
// clang-format on

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x1700, -0x3800, 0x1A00, 0x3800},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 32,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0700, -0x4C00, 0x2400, 0x1700},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      remaining : 0,
      range : {0x0000, -0x2400, 0x1C00, 0x3200},
    },
};
