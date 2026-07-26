#include "boss/omega1.h"
#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "trig.h"
#include "vfx.h"

typedef struct {
  COLLISION_OBJECT_HDR;
  Coords32 unk_b4;  // 0xB4, オメガ本体からの距離?
  u8 unk_bc[8];     // 0xBC
} Omega1wHand;
static_assert(sizeof(Omega1wHand) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void OmegaWhiteHand_Init(Omega1wHand* p);
static void OmegaWhiteHand_Update(Omega1wHand* p);
static void OmegaWhiteHand_Die(struct Entity* p);

// clang-format off
const EnemyRoutine gOmegaWhiteHandRoutine = {
    [ENTITY_INIT] =      (void*)OmegaWhiteHand_Init,
    [ENTITY_UPDATE] =    (void*)OmegaWhiteHand_Update,
    [ENTITY_DIE] =       (void*)OmegaWhiteHand_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateOmega1wHand(Coords32* c, bool8 isLeftHand, struct Entity* omega) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_OMEGA1W_HAND);
    p->coord = *c;
    p->work[0] = isLeftHand;
    p->unk_28 = omega;
  }
  return p;
}

// --------------------------------------------

static void Omega1wHand_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void OmegaWhiteHand_Init(Omega1wHand* p) {
  EnableSpriteAnimation_Affine(p);
  p->angle = 0;
  SET_XFLIP(p, FALSE);
  p->flags &= ~DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, sCollisions, 1, Omega1wHand_OnCollision);
  (&p->d)->x = (&p->d)->y = 0;
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 1;
  if (p->work[0] == 0) {  // 右手
    p->spr.oam.priority = 3;
    (p->unk_b4).x = -PIXEL(19);
    (p->unk_b4).y = -PIXEL(58);
  } else {               // 左手
    p->renderPrio = 23;  // 重なったら、右手の方が見えるようにする
    (p->unk_b4).x = PIXEL(21);
    (p->unk_b4).y = -PIXEL(56);
    SET_YFLIP(p, FALSE);  // 左手は上下反転させない
  }
  p->flags2 |= WHITE_PAINTABLE;
  p->invincibleID = (p->unk_28)->uniqueID;  // オメガが白くなったら、手も白くするで

  OmegaWhiteHand_Update(p);
}

// --------------------------------------------

bool8 FUN_0806aa9c(struct Enemy* p);
bool8 FUN_0806ae90(struct Enemy* p);
bool8 FUN_0806af24(struct Enemy* p);
bool8 FUN_0806b094(struct Enemy* p);
bool8 FUN_0806b120(struct Enemy* p);
bool8 FUN_0806b8cc(struct Enemy* p);

void FUN_0806aaa0(struct Enemy* p);
void FUN_0806ae94(struct Enemy* p);
void FUN_0806af40(struct Enemy* p);
void FUN_0806b098(struct Enemy* p);
void FUN_0806b124(struct Enemy* p);
void FUN_0806b8d0(struct Enemy* p);

void FUN_0806ac98(struct Enemy* p);
void FUN_0806aedc(struct Enemy* p);
void FUN_0806afdc(struct Enemy* p);
void FUN_0806b0dc(struct Enemy* p);
void FUN_0806b4cc(struct Enemy* p);
void FUN_0806bb8c(struct Enemy* p);

static void OmegaWhiteHand_Update(Omega1wHand* p) {
  // clang-format off
  static const EnemyFunc sUpdates[6] = {
      (EnemyFunc)FUN_0806aa9c,
      (EnemyFunc)FUN_0806ae90,
      (EnemyFunc)FUN_0806af24,
      (EnemyFunc)FUN_0806b094,
      (EnemyFunc)FUN_0806b120,
      (EnemyFunc)FUN_0806b8cc,
  }; // 0x083663e0
  // clang-format on

  // clang-format off
  static const EnemyFunc sUpdateRights[6] = {
      (EnemyFunc)FUN_0806aaa0,
      (EnemyFunc)FUN_0806ae94,
      (EnemyFunc)FUN_0806af40,
      (EnemyFunc)FUN_0806b098,
      (EnemyFunc)FUN_0806b124,
      (EnemyFunc)FUN_0806b8d0,
  }; // 0x083663f8
  // clang-format on

  // clang-format off
  static const EnemyFunc sUpdateLefts[6] = {
      (EnemyFunc)FUN_0806ac98,
      (EnemyFunc)FUN_0806aedc,
      (EnemyFunc)FUN_0806afdc,
      (EnemyFunc)FUN_0806b0dc,
      (EnemyFunc)FUN_0806b4cc,
      (EnemyFunc)FUN_0806bb8c,
  }; // 0x08366410
  // clang-format on

  Omega1* omega = (Omega1*)p->unk_28;
  if (omega->mode[0] >= ENTITY_DISAPPEAR) {
    // 本体が消えるときは、手も消える
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((omega->unk_d4 & 2) && (p->mode[1] != 5)) {
    p->mode[1] = 5, p->mode[2] = 0;
  }
  (sUpdates[p->mode[1]])((void*)p);

  if (p->work[0] == 0) {  // 右手
    (sUpdateRights[p->mode[1]])((void*)p);
  } else {  // 左手
    (sUpdateLefts[p->mode[1]])((void*)p);
  }
}

// --------------------------------------------

void FUN_0806a8fc(struct Enemy* p);
void FUN_0806aa54(struct Enemy* p);

static void OmegaWhiteHand_Die(struct Entity* p) {
  static const EnemyFunc sDeinitializers[2] = {
      (EnemyFunc)FUN_0806a8fc,
      (EnemyFunc)FUN_0806aa54,
  };  // 0x08366428
  (sDeinitializers[(p->mode)[1]])((void*)p);
}

// --------------------------------------------

INCASM("asm/enemy/omega1w_hand_a.inc");

void FUN_0806aa54(struct Enemy* p) {
  struct Coord c;
  if ((p->s).mode[2] == 0) {
    c.x = (p->s).coord.x;
    c.y = (p->s).coord.y;
    CreateSmoke(1, &c);
    PlaySound(0x2a);
    (p->s).flags &= ~DISPLAY;
    SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  }
}

bool8 FUN_0806aa9c(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/omega1w_hand_b.inc");

bool8 FUN_0806ae90(struct Enemy* p) { return TRUE; }

void FUN_0806ae94(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags |= 1;
      (p->s).coord.y = ((struct Enemy*)(p->s).unk_28)->s.coord.y;
      (p->s).coord.x = ((struct Enemy*)(p->s).unk_28)->s.coord.x;
      SetSpriteAnimation(p, MOTION(0x9, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
  }
}

void FUN_0806aedc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags |= 1;
      (p->s).coord.y = ((struct Enemy*)(p->s).unk_28)->s.coord.y;
      (p->s).coord.x = ((struct Enemy*)(p->s).unk_28)->s.coord.x;
      SetSpriteAnimation(p, MOTION(0x9, 1));
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      break;
  }
}

bool8 FUN_0806af24(struct Enemy* p) {
  if (((p->s).unk_28)->mode[1] == 5) {
    (p->s).mode[1] = 4;
    (p->s).mode[2] = 0;
  }
  return TRUE;
}

void FUN_0806af40(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).flags2 |= WHITE_PAINTABLE;
      (p->s).invincibleID = ((p->s).unk_28)->uniqueID;
      SetSpriteAnimation(p, 0x900);
      SET_XFLIP(p, FALSE);
      SetDDP(&p->body, &sCollisions[0]);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).work[2] = 0;
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

void FUN_0806afdc(struct Enemy* p) {
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

bool8 FUN_0806b094(struct Enemy* p) { return TRUE; }

void FUN_0806b098(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SET_XFLIP(p, FALSE);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

void FUN_0806b0dc(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SET_XFLIP(p, FALSE);
      (p->s).d.y = 0;
      (p->s).d.x = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateSpriteAnimation(p);
      break;
  }
}

bool8 FUN_0806b120(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/omega1w_hand_c.inc");

bool8 FUN_0806b8cc(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/omega1w_hand_d.inc");

// 0x0806be0c
static void Omega1wHand_OnCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {}

// 0x08366430
static const struct Collision sCollisions[7] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0100, 0x1600, 0x2900},
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
      range : {0x0000, 0x0100, 0x1800, 0x2B00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0400, 0x0200, 0x1E00, 0x2800},
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
      range : {0x0400, 0x0200, 0x2000, 0x2A00},
    },
};
