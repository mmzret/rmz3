#include "global.h"
#include "score.h"
#include "weapon.h"

// ラクサイガ雷が地面につくる電撃

static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

// 0x083616e0
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      element : ELEMENT_THUNDER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};

void SmashElec_Init(Weapon* w);
void SmashElec_Update(Weapon* w);
void SmashElec_Die(Weapon* w);
static void SmashElec_Disappear(struct Entity* p);

// clang-format off
const WeaponRoutine gSmashElecRoutine = {
    [ENTITY_INIT] =      (void*)SmashElec_Init,
    [ENTITY_UPDATE] =    (void*)SmashElec_Update,
    [ENTITY_DIE] =       (void*)SmashElec_Die,
    [ENTITY_DISAPPEAR] = (void*)SmashElec_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_SaberSmash(Weapon* p) {
  struct Zero* z = (struct Zero*)p->unk_28;
  if (P_ELEMENT(z) != ELEMENT_THUNDER || (z->unk_136 & (1 << 1))) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateSmashElec(struct Zero* z, Coords32* c, u8 leftOrRight) {
  struct Entity* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RAKUSAIGA);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_RAKUSAIGA);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    p->unk_28 = (void*)z;
    (p->coord) = *c;
    p->work[0] = leftOrRight, p->work[1] = 0;
    z->saberSmashElecCount++;
  }
  return p;
}

INCASM("asm/weapon/saber_smash_elec.inc");

static void SmashElec_Disappear(struct Entity* p) {
  Player* z = (Player*)(p->unk_28);
  if (z->saberSmashElecCount != 0) z->saberSmashElecCount--;
  p->flags &= ~DISPLAY;
  DeleteWeapon(p);
}

// 0x0803cb64
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    struct Entity* p = (struct Entity*)body->parent;
    IncWeaponUseCount(WEAPON_SABER);
    p->work[1] = 1;
  }
}
