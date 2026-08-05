#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "script.h"
#include "trig.h"

void OmegaGoldHand_Init(struct Enemy* p);
void OmegaGoldHand_Update(struct Enemy* p);
void OmegaGoldHand_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gOmegaGoldHandRoutine = {
    [ENTITY_INIT] =      (void*)OmegaGoldHand_Init,
    [ENTITY_UPDATE] =    (void*)OmegaGoldHand_Update,
    [ENTITY_DIE] =       (void*)OmegaGoldHand_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_08082b58(Coords32* c, bool8 isLeftHand, Omega1* omega) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->coord = *c;
    p->work[0] = isLeftHand, p->work[1] = 0;
    p->unk_28 = (void*)omega;
  }
  return p;
}

struct Entity* FUN_08082bbc(struct Entity* q, u8 kind) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1G_HAND);
    p->work[0] = kind, p->work[1] = 1;
    p->unk_28 = q;
  }
  return p;
}

INCASM("asm/enemy/omega1g_hand_a.inc");

static const EnemyFunc PTR_ARRAY_08368218[2];
static const struct Collision sCollisions[7];

void OmegaGoldHand_Die(struct Enemy* p) { (PTR_ARRAY_08368218[(p->s).mode[1]])(p); }

INCASM("asm/enemy/omega1g_hand_b.inc");

void FUN_08083258(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).flags &= ~DISPLAY;
    SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  }
}

bool8 FUN_08083284(struct Enemy* p) { return TRUE; }

void FUN_08083288(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags2 |= WHITE_PAINTABLE;
      (p->s).invincibleID = ((p->s).unk_28)->uniqueID;
      SetSpriteAnimation(p, 0x900);
      SET_XFLIP(p, FALSE);
      SET_YFLIP(p, FALSE);
      (p->s).coord.y = *(s32*)((u8*)p + 0xb8) + ((p->s).unk_28)->coord.y;
      (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + ((p->s).unk_28)->coord.x;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if (((p->s).unk_28)->scriptEntity->flags & 1) {
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
  }
}

void FUN_08083328(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags2 |= WHITE_PAINTABLE;
      (p->s).invincibleID = ((p->s).unk_28)->uniqueID;
      SetSpriteAnimation(p, MOTION(SM009_OMEGA_HAND, 1));
      SET_XFLIP(p, FALSE);
      SET_YFLIP(p, FALSE);
      (p->s).coord.y = *(s32*)((u8*)p + 0xb8) + ((p->s).unk_28)->coord.y;
      (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + ((p->s).unk_28)->coord.x;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      if (((p->s).unk_28)->scriptEntity->flags & 1) {
        (p->s).mode[1] = 1, (p->s).mode[2] = 0;
      }
      break;
  }
}

bool8 FUN_080833c8(struct Enemy* p) { return TRUE; }

void FUN_080833cc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      (p->s).mode[1] = 2, (p->s).mode[2] = 0;
      break;
  }
}

void FUN_080833ec(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).mode[2] = 1;
      FALLTHROUGH;
    case 1:
      (p->s).mode[1] = 2, (p->s).mode[2] = 0;
      break;
  }
}

bool8 FUN_0808340c(struct Enemy* p) {
  if (((struct Entity*)(p->s).unk_28)->mode[1] == 5) {
    (p->s).mode[1] = 4;
    (p->s).mode[2] = 0;
  }
  return TRUE;
}

INCASM("asm/enemy/omega1g_hand_c.inc");

void FUN_080834fc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags2 |= WHITE_PAINTABLE;
      (p->s).invincibleID = ((p->s).unk_28)->uniqueID;
      SetSpriteAnimation(p, 0x901);
      SET_XFLIP(p, FALSE);
      SET_YFLIP(p, FALSE);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      SetDDP(&p->body, &sCollisions[3]);
      (p->s).work[2] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 wob;
      (p->s).work[2] += 2;
      wob = gSineTable[(p->s).work[2]] << 1;
      (p->s).coord.y = *(s32*)((u8*)p + 0xb8) + ((p->s).unk_28)->coord.y + wob;
      (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + ((p->s).unk_28)->coord.x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 FUN_080835b4(struct Enemy* p) { return TRUE; }

void FUN_080835b8(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SET_XFLIP(p, 0);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_080835fc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SET_XFLIP(p, 0);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

bool8 FUN_08083640(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/omega1g_hand_d.inc");

bool8 FUN_08083e14(struct Enemy* p) { return TRUE; }

void FUN_08083e18(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      EXIT_BODY(p);
      (p->s).d.x = 0;
      (p->s).d.y = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      (p->s).d.y += 0x40;
      if ((p->s).d.y > 0x40) {
        (p->s).d.y = 0x40;
      }
      (p->s).coord.y += (p->s).d.y;
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_08083e68(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SET_XFLIP(p, 0);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

void nop_08083eac(struct Enemy* p) {}

bool8 FUN_08083eb0(struct Enemy* p) {
  p->buffer[0xd] = 1;
  (p->s).mode[1] = 4;
  (p->s).mode[2] = 0;
  return TRUE;
}

void FUN_08083ec4(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(SM009_OMEGA_HAND, 0));
      SET_XFLIP(p, FALSE);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[2] = 0;
      p->buffer[0xd] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 wob;
      (p->s).work[2] += 2;
      wob = gSineTable[(p->s).work[2]];
      (p->s).coord.y = *(s32*)((u8*)p + 0xb8) + ((p->s).unk_28)->coord.y + wob;
      (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + ((p->s).unk_28)->coord.x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

void FUN_08083f4c(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetSpriteAnimation(p, MOTION(SM009_OMEGA_HAND, 1));
      SET_XFLIP(p, FALSE);
      SET_YFLIP(p, FALSE);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[2] = 0;
      p->buffer[0xd] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1: {
      s32 wob;
      (p->s).work[2] += 2;
      wob = gSineTable[(p->s).work[2]] << 1;
      (p->s).coord.y = *(s32*)((u8*)p + 0xb8) + ((p->s).unk_28)->coord.y + wob;
      (p->s).coord.x = *(s32*)((u8*)p + 0xb4) + ((p->s).unk_28)->coord.x;
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

bool8 FUN_08083ff0(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/omega1g_hand_e.inc");

bool8 FUN_080846fc(struct Enemy* p) { return TRUE; }

void FUN_08084700(struct Enemy* p) {}


// clang-format off
static const EnemyFunc PTR_ARRAY_08368188[6] = {
    (EnemyFunc)FUN_08083284,
    (EnemyFunc)FUN_080833c8,
    (EnemyFunc)FUN_0808340c,
    (EnemyFunc)FUN_080835b4,
    (EnemyFunc)FUN_08083640,
    (EnemyFunc)FUN_08083e14,
};
// clang-format on


// clang-format off
static const EnemyFunc PTR_ARRAY_083681a0[6] = {
    (EnemyFunc)FUN_080846fc,
    (EnemyFunc)FUN_080846fc,
    (EnemyFunc)FUN_08083eb0,
    (EnemyFunc)FUN_080846fc,
    (EnemyFunc)FUN_08083ff0,
    (EnemyFunc)FUN_080846fc,
};
// clang-format on

void FUN_08083428(struct Enemy* p);
void FUN_08083644(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681b8[6] = {
    FUN_08083288,
    FUN_080833cc,
    FUN_08083428,
    FUN_080835b8,
    FUN_08083644,
    FUN_08083e18,
};
// clang-format on

void FUN_08083a04(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681d0[6] = {
    FUN_08083328,
    FUN_080833ec,
    FUN_080834fc,
    FUN_080835fc,
    FUN_08083a04,
    FUN_08083e68,
};
// clang-format on

void FUN_08083ff4(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_083681e8[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083ec4,
    FUN_08084700,
    FUN_08083ff4,
    FUN_08084700,
};
// clang-format on

void FUN_08083f4c(struct Enemy* p);
void FUN_08084348(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_08368200[6] = {
    FUN_08084700,
    FUN_08084700,
    FUN_08083f4c,
    FUN_08084700,
    FUN_08084348,
    FUN_08084700,
};
// clang-format on

void FUN_08082e38(struct Enemy* p);
void FUN_08083258(struct Enemy* p);

static const EnemyFunc PTR_ARRAY_08368218[2] = {
    FUN_08082e38,
    FUN_08083258,
};

// --------------------------------------------

static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(1), PIXEL(22), PIXEL(41)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(1), PIXEL(24), PIXEL(43)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), PIXEL(2), PIXEL(30), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(4), PIXEL(2), PIXEL(32), PIXEL(42)},
    },
};
