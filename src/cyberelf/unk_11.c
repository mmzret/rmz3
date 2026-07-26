#include "collision.h"
#include "cyberelf.h"
#include "global.h"
#include "zero.h"

// Bee?

struct CyberElf11 {
  COLLISION_OBJECT_HDR;
  Player* player;   // 0xB4
  void* parent_b8;  // 0xB8
  u8 unk_bc[8];     // 0xBC
};
static_assert(sizeof(struct CyberElf11) == sizeof(CyberElf));

static const CyberElfFunc sUpdates[4];
static const struct Collision sCollisions[15];

static void Elf11_Init(struct Entity* p);
void Elf11_Update(CyberElf* p);
void Elf11_Die(CyberElf* p);

// clang-format off
const ElfRoutine gElf11Routine = {
    [ENTITY_INIT] =      (void*)Elf11_Init,
    [ENTITY_UPDATE] =    (void*)Elf11_Update,
    [ENTITY_DIE] =       (void*)Elf11_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* FUN_080e5048(Player* player, struct Entity* q, u8 kind) {
  struct CyberElf11* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 11);
    p->player = player;
    p->parent_b8 = q;
    p->work[0] = kind, p->work[1] = 0;
  }
  return (struct Entity*)p;
}

// --------------------------------------------

void FUN_080e51b0(CyberElf* p);
void FUN_080e5300(CyberElf* p);
void FUN_080e54ac(CyberElf* p);
void FUN_080e5608(CyberElf* p);

static void Elf11_Init(struct Entity* p) {
  static const EntityFunc sInitializers[4] = {
      (void*)FUN_080e51b0,
      (void*)FUN_080e5300,
      (void*)FUN_080e54ac,
      (void*)FUN_080e5608,
  };  // 0x08371df8

  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  p->palID = 1;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags2 &= ~DYNAMIC;
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  (sInitializers[(p->work)[0]])((void*)p);
  Elf11_Update((CyberElf*)p);
}

INCASM("asm/cyberelf/unk_11_a.inc");

void Elf11_Die(CyberElf* p) {
  (p->body).status = 0;
  (p->body).prevStatus = 0;
  (p->body).invincibleTime = 0;
  p->flags &= ~COLLIDABLE;
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/cyberelf/unk_11_b.inc");

void FUN_080e56a0(CyberElf* p);
void FUN_080e5718(CyberElf* p);
void FUN_080e5798(CyberElf* p);
void FUN_080e5818(CyberElf* p);

// 0x08371e08
static const CyberElfFunc sUpdates[4] = {
    FUN_080e56a0,
    FUN_080e5718,
    FUN_080e5798,
    FUN_080e5818,
};

// --------------------------------------------

// 0x08371e18
static const struct Collision sCollisions[15] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 2,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [5] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [6] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 5,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [7] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 6,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 5,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 6,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 7,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1600, 0x1600},
    },
};
