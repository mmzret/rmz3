#include "collision.h"
#include "global.h"
#include "score.h"
#include "weapon.h"

// A firework of Burst shot

// 0x083615ac
static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ALLY,
  special : HALFABLE,
  damage : 2,
  atkType : 6,
  nature : ELEMENT_ENCHANTABLE,
  comboLv : 2,
  layer : 0x00000008,
  range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
};

// --------------------------------------------

static void BurstShot_Init(Weapon* p);
static void BurstShot_Update(struct Entity* p);
static void BurstShot_Die(struct Entity* p);

// clang-format off
const WeaponRoutine gBurstShotRoutine = {
    [ENTITY_INIT] =      (void*)BurstShot_Init,
    [ENTITY_UPDATE] =    (void*)BurstShot_Update,
    [ENTITY_DIE] =       (void*)BurstShot_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

// --------------------------------------------

void MenuExit_BurstShot(Weapon* p) {
  Player* z = (Player*)p->unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_FLAME || (z->unk_136 & (1 << 0))) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

Weapon* CreateBurstShot(struct Zero* z, Weapon* q, u8 n, s32 x, s32 y) {
  Weapon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_BURST_SHOT);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_BURST_SHOT);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    p->unk_28 = &z->s;
    p->unk_2c = (void*)q;
    p->coord = q->coord;
    p->work[0] = n, p->work[1] = 0;
    p->coord.x += x;
    p->coord.y += y;
  }
  return p;
}

static const motion_t sBurstShotAnimations[3];
static void BurstShot_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void BurstShot_Init(Weapon* p) {
  struct Body* body;
  Player* z = (Player*)p->unk_28;
  struct Entity* parent = (struct Entity*)p->unk_2c;

  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, sBurstShotAnimations[p->work[0]]);
  _INIT_BODY(p, &sCollision, 1);
  body = &p->body;
  InitWeaponBody(body, &sCollision, (u8)(CalcBusterBonus(z) + 2), ELEMENT_FLAME, 2, (parent->work[3] >> 2) + 2);
  body->fn = BurstShot_OnCollision;
  BurstShot_Update((struct Entity*)p);
}

static void BurstShot_Update(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if (IsSpriteAnimEnd(p)) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
    BurstShot_Die(p);
  }
}

static void BurstShot_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// 0x0803B73C
static void BurstShot_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) IncWeaponUseCount(WEAPON_BUSTER);
}

// 0x083615d8
static const motion_t sBurstShotAnimations[3] = {
    MOTION(DM083_BURST_SHOT_FIREWORK, 0),
    MOTION(DM083_BURST_SHOT_FIREWORK, 1),
    MOTION(DM083_BURST_SHOT_FIREWORK, 2),
};
