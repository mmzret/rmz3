#include "collision.h"
#include "global.h"
#include "score.h"
#include "weapon.h"

// Saber wave by cyberelf, Cottus
typedef struct {
  COLLISION_OBJECT_HDR;
  struct SaberWave_b4 {
    Weapon* saber;  // 0xB4, projectile -> saber (if saber, this is null)
    Player* z;      // 0xB8
    u8 props[4];    // 0xBC
    u8 element;     // 0xC0
    u8 atk;         // 0xC1
    u8 flags;       // 0xC2
    bool8 unk;      // 0xC3
    u8 unk_c4[40];  // 0xC4
  } props;          // props (56bytes, offset: 0xB4..)
} SaverWave;
static_assert(sizeof(SaverWave) == sizeof(Weapon));

// 0x08361338
static const struct Collision sCollisions[16] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x1000, 0x0000, 0x2000, 0x0800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0F00, 0x0000, 0x1E00, 0x0800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0E00, 0x0000, 0x1C00, 0x0C00},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0D00, 0x0000, 0x1A00, 0x1000},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0C00, 0x0000, 0x1800, 0x1400},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0B00, 0x0000, 0x1600, 0x1800},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [13] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0A00, 0x0000, 0x1400, 0x1C00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 3,
      remaining : 1,
      layer : 0x00000020,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0700, 0x0000, 0x1000, 0x2000},
    },
};

void Weapon5_Init(SaverWave* p);
void Weapon5_Update(SaverWave* p);
void Weapon5_Die(SaverWave* p);

// clang-format off
const WeaponRoutine gSaberWaveRoutine = {
    [ENTITY_INIT] =      (void*)Weapon5_Init,
    [ENTITY_UPDATE] =    (void*)Weapon5_Update,
    [ENTITY_DIE] =       (void*)Weapon5_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

struct Entity* CreateSaberWave(Player* z, Weapon* saber, bool8 isProjectile) {
  SaverWave* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SABER_WAVE);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SABER_WAVE);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    (&p->props)->saber = saber;
    (&p->props)->z = z;
    p->work[0] = isProjectile, p->work[1] = 0;
    if (!isProjectile) CreateSaberWave(z, (void*)p, TRUE);
  }
  return (struct Entity*)p;
}

INCASM("asm/weapon/saber_wave_a.inc");

void Weapon5_Die(SaverWave* w) {
  EXIT_BODY(w);
  w->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void hitZSaber(struct Body* body) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    if (gScore.weaponCount[WEAPON_SABER] <= 0xFFFE) {
      gScore.weaponCount[WEAPON_SABER]++;
    }
  }
}
