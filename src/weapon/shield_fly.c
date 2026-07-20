#include "collision.h"
#include "global.h"
#include "score.h"
#include "sound.h"
#include "weapon.h"

static const u8 sShieldFlyElements[4];
static const motion_t sShieldFlyMotions[3][4];
static const WeaponFunc sShieldFlyUpdates[5];

bool32 shield_0803a5fc(WeaponCommon* w);
static void onHit(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void ShieldFly_Init(WeaponCommon* p);
static void ShieldFly_Update(WeaponCommon* p);
static void ShieldFly_Die(struct Entity* p);

// 0x080399fc
void DeleteFlyingShield(Object* p) {
  if (p->id == WEAPON_MOVE_SHIELD_FLY) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

NAKED void MenuExit_ShieldFly(Weapon* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r3, r0, #0\n\
	adds r4, r3, #0\n\
	adds r4, #0xb4\n\
	ldr r1, [r4]\n\
	adds r5, r1, #0\n\
	adds r5, #0xb4\n\
	ldr r2, _08039A68 @ =0x00000232\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _08039A6C\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	b _08039A8A\n\
	.align 2, 0\n\
_08039A68: .4byte 0x00000232\n\
_08039A6C:\n\
	ldrb r0, [r5, #0xe]\n\
	ldrb r4, [r4, #0xd]\n\
	cmp r0, r4\n\
	bne _08039A84\n\
	movs r4, #0x9b\n\
	lsls r4, r4, #1\n\
	adds r0, r1, r4\n\
	ldrb r1, [r0]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08039AB8\n\
_08039A84:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_08039A8A:\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	adds r0, r3, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	ldr r1, _08039AC0 @ =gWeaponFnTable\n\
	ldrb r0, [r3, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r3, #0x14]\n\
_08039AB8:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08039AC0: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

struct Entity* CreateWeaponShieldFly(struct Zero* z, u8 r1) {
  WeaponCommon* p;

  KillAllWeapons(DeleteSaber);
  p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    u8 element;

    if ((z->unk_b4).mainCopy == WEAPON_SHIELD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_FLY);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
      element = sShieldFlyElements[((&z->unk_b4)->status).element];
      SetWeaponElement(0, element);

    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_FLY);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
      element = sShieldFlyElements[((&z->unk_b4)->status).element];
      SetWeaponElement(1, element);
    }

    (p->props).z = z;
    p->work[0] = z->unk_127, p->work[1] = r1;
    (&p->props)->props[1][1] = ((&z->unk_b4)->status).element;
  }
  return (void*)p;
}

static void ShieldFly_Init(WeaponCommon* p) {
  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, sShieldFlyMotions[p->work[1]][p->work[0]]);
  PlaySound(SE_CHARGE_SHIELD_VOICE);
  (&p->props)->props[1][2] = 1;
  ShieldFly_Update(p);
}

static void ShieldFly_Update(WeaponCommon* p) {
  struct WeaponCommonProps* b4 = &p->props;
  struct Zero* z = (p->props).z;
  if (z->elfMotion != 0) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
    return;
  }
  if (((z->body).status & BODY_STATUS_DEAD) || ((z->body).hp == 0)) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
    return;
  }
  if ((b4->props[1][2] != 0) && ((p->body).status & BODY_STATUS_BLOCKED)) {
    PlaySound(SE_BLOCKED);
    b4->props[1][2] = 0;
  }

  {
    struct Zero_b4* b4 = &z->unk_b4;
    if ((b4->status).weapons[0] == WEAPON_SHIELD) {
      (z->restriction).mainCharge = TRUE;
    } else {
      (z->restriction).subCharge = TRUE;
    }
  }
  (sShieldFlyUpdates[p->mode[1]])((void*)p);
  UpdateSpriteAnimation(p);

  if ((p->mode[1] == 2) && shield_0803a5fc(p)) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
  }
}

static void ShieldFly_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

static void onHit(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) IncWeaponUseCount(WEAPON_SHIELD);
}

INCASM("asm/weapon/shield_fly.inc");

// 0x0836126c
static const motion_t sShieldFlyMotions[3][4] = {
    {
        MOTION(DM109_UNK, 0),
        MOTION(DM112_UNK, 0),
        MOTION(DM114_UNK, 0),
        MOTION(DM116_UNK, 0),
    },
    {
        MOTION(DM109_UNK, 3),
        MOTION(DM112_UNK, 1),
        MOTION(DM114_UNK, 1),
        MOTION(DM116_UNK, 1),
    },
    {
        MOTION(DM109_UNK, 3),
        MOTION(DM112_UNK, 1),
        MOTION(DM114_UNK, 1),
        MOTION(DM116_UNK, 1),
    },
};

static const u8 sShieldFlyElements[4] = {0, 1, 2, 3};  // 0x08361284

const u8 u8_ARRAY_08361288[4] = {5, 8, 11, 0};  // 0x08361288

const s8_8 sShieldFlyOffsetY[8] = {
    PIXEL(28), -PIXEL(19), PIXEL(26), -PIXEL(21), PIXEL(24), -PIXEL(20), PIXEL(26), -PIXEL(16),
};  // 0x0836128c

static const s8_8 sShieldFlyOffsetX[8] = {
    PIXEL(28), -PIXEL(18), PIXEL(28), -PIXEL(21), PIXEL(22), -PIXEL(20), PIXEL(27), -PIXEL(15),
};  // 0x0836129c

const struct Collision Collision_ARRAY_083612ac[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_UNK3,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00010000,
      range : {PIXEL(0), PIXEL(0), PIXEL(38), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(38), PIXEL(16)},
    },
};

const struct Collision Collision_ARRAY_083612dc[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_UNK3,
      nature : (BODY_NATURE_CUT | ELEMENT_ENCHANTABLE),
      comboLv : 1,
      remaining : 1,
      layer : 0x00010000,
      range : {PIXEL(0), PIXEL(0), PIXEL(34), PIXEL(34)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(34), PIXEL(34)},
    },
};

// --------------------------------------------

void shield_08039d3c(Weapon* w);
void shield_08039e28(Weapon* w);
void shield_08039ffc(Weapon* w);
void shield_0803a108(Weapon* w);
void shield_0803a3b4(Weapon* w);

// clang-format off
static const WeaponFunc sShieldFlyUpdates[5] = {
    shield_08039d3c,
    shield_08039e28,
    shield_08039ffc,
    shield_0803a108,
    shield_0803a3b4,
};
// clang-format on

// --------------------------------------------

// clang-format off
const WeaponRoutine gShieldFlyRoutine = {
    [ENTITY_INIT] =      (void*)ShieldFly_Init,
    [ENTITY_UPDATE] =    (void*)ShieldFly_Update,
    [ENTITY_DIE] =       (void*)ShieldFly_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

const u8 u8_ARRAY_08361334[4] = {1, 3, 4, 0};  // 0x08361334
