#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "palette_animation.h"

// I call Omega Second Form "Omega ZX" because his shoulder pads look like Zero and X.

struct OmegaZXProjectileTemplate {
  motion_t motions[2];
  u8 unk_4;
  u8 _;
} PACKED;

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[4];          // 0xB4
  s32 unk_y;             // 0xB8
  Entity* unk_bc;        // 0xBC
  u16 unk_c0;            // 0xC0
  u16 unk_c2;            // 0xC2
  Entity* unk_c4;        // 0xC4
  u8 unk_c8[4];          // 0xC8
  Entity* enemy60;       // 0xCC
  s32 y_d0;              // 0xD0
  u8 unk_d4[16];         // 0xD4
} OmegaZX;
static_assert(sizeof(OmegaZX) == sizeof(Boss));

Entity* FUN_08092444(Coords32* c, u8 kind, Entity* boss);

static void OmegaZX_Init(OmegaZX* p);
static void OmegaZX_Update(OmegaZX* p);
static void OmegaZX_Die(OmegaZX* p);
static void OmegaZX_Disappear(OmegaZX* p);

// clang-format off
const BossRoutine gOmegaZXRoutine = {
    [ENTITY_INIT] =      (void*)OmegaZX_Init,
    [ENTITY_UPDATE] =    (void*)OmegaZX_Update,
    [ENTITY_DIE] =       (void*)OmegaZX_Die,
    [ENTITY_DISAPPEAR] = (void*)OmegaZX_Disappear,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static Entity* Unused_CreateOmegaZX(Coords32* c, u8 n) {
  Entity* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_OMEGA_ZX);
    p->coord = *c;
    p->work[0] = n;
  }
  return p;
}

// --------------------------------------------

static const struct Collision sCollisions[];

NAKED static void OmegaZX_Init(OmegaZX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	adds r2, r5, #0\n\
	adds r2, #0x5c\n\
	bl FUN_08016094\n\
	ldr r0, _08060C04 @ =gOverworld\n\
	ldr r1, _08060C08 @ =0x0002D025\n\
	adds r0, r0, r1\n\
	movs r4, #0\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _08060C0C @ =sCollisions\n\
	adds r0, r5, #0\n\
	movs r2, #0x60\n\
	bl ResetBossBody\n\
	ldr r1, _08060C10 @ =FUN_080616b8\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x40\n\
	strb r4, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb5\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r3, r5, #0\n\
	adds r3, #0xbc\n\
	str r4, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb7\n\
	strb r4, [r0]\n\
	adds r0, #9\n\
	movs r1, #0\n\
	mov ip, r1\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, _08060C14 @ =0xFFFFB000\n\
	adds r7, r0, r1\n\
	ldr r0, _08060C18 @ =gStageRun+232\n\
	ldr r0, [r0, #0x3c]\n\
	ldr r1, _08060C1C @ =0x00003FFF\n\
	adds r7, r0, r1\n\
	ldr r1, _08060C20 @ =0xFFFFD800\n\
	adds r0, r7, r1\n\
	str r0, [r5, #0x58]\n\
	adds r2, r5, #0\n\
	adds r2, #0xb8\n\
	str r0, [r2]\n\
	ldr r0, [r5, #0x58]\n\
	movs r1, #0xb4\n\
	lsls r1, r1, #8\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [r5, #0x5c]\n\
	str r1, [r5, #0x60]\n\
	ldr r0, [r2]\n\
	str r0, [r5, #0x68]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	str r4, [r5, #0x2c]\n\
	str r4, [r3]\n\
	adds r0, r5, #0\n\
	adds r0, #0xc4\n\
	str r4, [r0]\n\
	adds r0, #8\n\
	str r4, [r0]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	bne _08060C28\n\
	ldr r1, _08060C24 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	mov r0, ip\n\
	strb r0, [r5, #0xd]\n\
	strb r0, [r5, #0xe]\n\
	strb r0, [r5, #0xf]\n\
	b _08060C44\n\
	.align 2, 0\n\
_08060C04: .4byte gOverworld\n\
_08060C08: .4byte 0x0002D025\n\
_08060C0C: .4byte sCollisions\n\
_08060C10: .4byte FUN_080616b8\n\
_08060C14: .4byte 0xFFFFB000\n\
_08060C18: .4byte gStageRun+232\n\
_08060C1C: .4byte 0x00003FFF\n\
_08060C20: .4byte 0xFFFFD800\n\
_08060C24: .4byte gBossFnTable\n\
_08060C28:\n\
	ldr r1, _08060CA0 @ =gBossFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	mov r1, ip\n\
	strb r1, [r5, #0xe]\n\
	strb r1, [r5, #0xf]\n\
_08060C44:\n\
	mov r0, sp\n\
	movs r1, #0\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	mov r0, sp\n\
	movs r1, #1\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	mov r0, sp\n\
	movs r1, #2\n\
	adds r2, r5, #0\n\
	bl FUN_08092444\n\
	adds r1, r5, #0\n\
	adds r1, #0xcc\n\
	str r0, [r1]\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #2\n\
	movs r0, #0xa7\n\
	adds r1, r4, #0\n\
	bl StartPaletteAnimation\n\
	movs r1, #0xb8\n\
	lsls r1, r1, #2\n\
	movs r0, #0xa8\n\
	bl StartPaletteAnimation\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #2\n\
	movs r0, #0xa9\n\
	bl StartPaletteAnimation\n\
	movs r0, #0xaa\n\
	adds r1, r4, #0\n\
	bl StartPaletteAnimation\n\
	adds r0, r5, #0\n\
	bl OmegaZX_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08060CA0: .4byte gBossFnTable\n\
 .syntax divided\n");
}

static bool8 FUN_08060f98(OmegaZX* p);
static bool8 FUN_08060fd8(OmegaZX* p);
static bool8 FUN_08061064(OmegaZX* p);
bool8 FUN_080610a8(OmegaZX* p);
static bool8 FUN_08061230(OmegaZX* p);
static bool8 FUN_080612d4(OmegaZX* p);
static bool8 FUN_080613b8(OmegaZX* p);
static bool8 FUN_080614a4(OmegaZX* p);
static bool8 FUN_080615d8(OmegaZX* p);

static void FUN_08060f9c(OmegaZX* p);
static void FUN_08060fdc(OmegaZX* p);
static void FUN_08061068(OmegaZX* p);
void Boss22Neutral(OmegaZX* p);
void FUN_08061234(OmegaZX* p);
void FUN_080612d8(OmegaZX* p);
void FUN_080613bc(OmegaZX* p);
void FUN_080614a8(OmegaZX* p);
void FUN_080615dc(OmegaZX* p);

static void OmegaZX_Update(OmegaZX* p) {
  // clang-format off
  static bool8 (*const sUpdates1[9])(OmegaZX*) = {
      FUN_08060f98,
      FUN_08060fd8,
      FUN_08061064,
      FUN_080610a8,
      FUN_08061230,
      FUN_080612d4,
      FUN_080613b8,
      FUN_080614a4,
      FUN_080615d8,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[9])(OmegaZX*) = {
      FUN_08060f9c,
      FUN_08060fdc,
      FUN_08061068,
      Boss22Neutral,
      FUN_08061234,
      FUN_080612d8,
      FUN_080613bc,
      FUN_080614a8,
      FUN_080615dc,
  };
  // clang-format on

  if (((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) {
    if (!(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
      SET_BOSS_ROUTINE(p, ENTITY_DIE);
      OmegaZX_Die(p);
      return;
    }
  }

  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

static void FUN_08060d60(OmegaZX* p);
void FUN_08060e14(OmegaZX* p);

static void OmegaZX_Die(OmegaZX* p) {
  static void (*const sDeads[2])(OmegaZX*) = {
      FUN_08060d60,
      FUN_08060e14,
  };
  (sDeads[p->mode[1]])(p);
}

static void OmegaZX_Disappear(OmegaZX* p) {
  RemovePaletteAnimation(167);
  RemovePaletteAnimation(168);
  RemovePaletteAnimation(169);
  RemovePaletteAnimation(170);
  DeleteBoss((void*)p);
}

// --------------------------------------------

static void FUN_08060d60(OmegaZX* p) {
  switch (p->mode[2]) {
    case 0: {
      if ((gStageRun.missionStatus & MISSION_STAY) && !(gStageRun.vm.active & VM_ACTIVE)) {
        gStageRun.missionStatus &= ~MISSION_STAY;
        gStageRun.missionStatus |= MISSION_SUCCESS;
      }
      EXIT_BODY(p);
      p->work[2] = 90;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      StepPaletteAnimation(167);
      StepPaletteAnimation(168);
      StepPaletteAnimation(169);
      StepPaletteAnimation(170);
      if (p->work[2] != 0) {
        p->work[2]--;
        if (p->work[2] == 0) p->mode[2]++;
      }
      break;
    }
    case 2: {
      if ((p->scriptEntity)->flags & (1 << 7)) {
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

INCASM("asm/boss/omega_zx_a.inc");

static bool8 FUN_08060f98(OmegaZX* p) { return TRUE; }

static void FUN_08060f9c(OmegaZX* p) {
  switch (p->mode[2]) {
    case 0: {
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->scriptEntity)->flags & (1 << 0)) {
        gOverworld.state[1] = 1;
        p->mode[1] = 1, p->mode[2] = 0;
      }
      break;
    }
  }
}

static bool8 FUN_08060fd8(OmegaZX* p) { return TRUE; }

static void FUN_08060fdc(OmegaZX* p) {
  switch (p->mode[2]) {
    case 0: {
      p->mode[2] = 1;
      p->y_d0 = 0x280;
      p->work[2] = 0xf0;
      FALLTHROUGH;
    }
    case 1: {
      s32 vy = p->y_d0;
      vy += ((0x98 - vy) * 10) >> 8;
      p->y_d0 = vy;
      p->coord.y -= vy;
      if (p->coord.y < p->unk_y) p->coord.y = p->unk_y;
      p->d = p->coord;
      if (p->work[2] == 0 || --p->work[2] == 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      p->mode[1] = p->mode[2];
      p->mode[2] = 0;
      break;
    }
  }
}

static bool8 FUN_08061064(OmegaZX* p) { return TRUE; }

Entity* FUN_080c4e58(Coords32* c, void* _, Entity* e);

static void FUN_08061068(OmegaZX* p) {
  switch (p->mode[2]) {
    case 0: {
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) {
        Coords32 c;
        p->unk_2c = FUN_080c4e58(&c, NULL, (void*)p);
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
    }
  }
}

INCASM("asm/boss/omega_zx_b.inc");

static bool8 FUN_08061230(OmegaZX* p) { return TRUE; }

INCASM("asm/boss/omega_zx_c.inc");

static bool8 FUN_080612d4(OmegaZX* p) { return TRUE; }

Projectile* FUN_080afedc(Entity* parent, Coords32* c, u8 n);

void FUN_080612d8(OmegaZX* p) {
  Coords32 c;
  switch (p->mode[2]) {
    case 0: {
      RemovePaletteAnimation(0xa7);
      RemovePaletteAnimation(0xa8);
      RemovePaletteAnimation(0xa9);
      RemovePaletteAnimation(170);
      StartPaletteAnimation(170, 0x2C0);
      FUN_080afedc((void*)p, &p->coord, 1);
      p->work[2] = 30;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      StepPaletteAnimation(170);
      if (p->work[2] != 0 && --p->work[2] == 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      c.x = -PIXEL(35);
      c.y = -PIXEL(86);
      p->unk_c4 = (Entity*)FUN_080afedc((void*)p, &c, 3);
      p->work[2] = 0xFF;
      p->work[3] = -1;
      p->mode[2]++;
      break;
    }
    case 3: {
      StepPaletteAnimation(170);
      if ((p->unk_c4)->mode[0] > 1) {
        p->unk_c4 = NULL;
        p->mode[2]++;
      }
      break;
    }
    case 4: {
      RemovePaletteAnimation(170);
      p->mode[1] = 3, p->mode[2] = 0;
      break;
    }
  }
}

static bool8 FUN_080613b8(OmegaZX* p) { return TRUE; }

Projectile* FUN_080aff34(Entity* parent, Coords32* c, u8 n);
Entity* FUN_080c4f04(Entity* parent, Coords32* c, u8 n);
void FUN_080616fc(OmegaZX* p);

void FUN_080613bc(OmegaZX* p) {
  Coords32 c;
  switch (p->mode[2]) {
    case 0: {
      RemovePaletteAnimation(167);
      RemovePaletteAnimation(168);
      RemovePaletteAnimation(169);
      RemovePaletteAnimation(170);
      StartPaletteAnimation(168, 0x2E0);
      FUN_080c4f04((void*)p, &p->coord, 0);
      p->work[2] = 30;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      FUN_080616fc(p);
      if (p->work[2] != 0 && --p->work[2] == 0) {
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      c.x = p->coord.x + 0xfffffc00;
      c.y = p->coord.y + 0xffffde00;
      p->unk_c4 = (Entity*)FUN_080aff34((void*)p, &c, 0);
      p->mode[2]++;
      break;
    }
    case 3: {
      FUN_080616fc(p);
      StepPaletteAnimation(168);
      if ((p->unk_c4)->mode[0] > 1) {
        p->unk_c4 = NULL;
        p->mode[2]++;
      }
      break;
    }
    case 4: {
      FUN_080616fc(p);
      RemovePaletteAnimation(168);
      p->mode[1] = 3, p->mode[2] = 0;
      break;
    }
  }
}

static bool8 FUN_080614a4(OmegaZX* p) { return TRUE; }

INCASM("asm/boss/omega_zx_d.inc");

static bool8 FUN_080615d8(OmegaZX* p) { return TRUE; }

void FUN_080615dc(OmegaZX* p) {
  switch (p->mode[2]) {
    case 0: {
      RemovePaletteAnimation(167);
      RemovePaletteAnimation(168);
      RemovePaletteAnimation(169);
      RemovePaletteAnimation(170);
      StartPaletteAnimation(167, 0x2C0);
      FUN_080616fc(p);
      p->mode[2]++;
      break;
    }
    case 1: {
      FUN_080616fc(p);
      StepPaletteAnimation(167);
      if ((p->enemy60)->mode[1] != 7) {
        RemovePaletteAnimation(167);
        p->mode[1] = 3, p->mode[2] = 0;
      }
      break;
    }
  }
}

INCASM("asm/boss/omega_zx_e.inc");

void FUN_080616b8(OmegaZX* p) {
  Entity* q = (Entity*)(p->unk_2c)->unk_2c;
  if (q != NULL) {
    if (q->mode[0] > 1) {
      (p->unk_2c)->unk_2c = NULL;
    } else {
      q->flags &= ~DISPLAY;
    }
  }

  q = *(struct Entity**)((u8*)p->unk_2c + 0xbc);
  if (q != NULL) {
    if (q->mode[0] > 1) {
      *(struct Entity**)((u8*)p->unk_2c + 0xbc) = NULL;
    } else {
      q->flags &= ~DISPLAY;
    }
  }
}

INCASM("asm/boss/omega_zx_f.inc");

// 0x083655d4
static const struct Collision sCollisions[3] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(3), PIXEL(24), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(33), PIXEL(16), PIXEL(16)},
    },
};

static const struct OmegaZXProjectileTemplate sOmegaZXProjectileTemplates[18] = {
    [0] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [1] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [2] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [3] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [4] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [5] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [6] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [7] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [8] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [9] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [10] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [11] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [12] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [13] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
    [14] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [15] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 4), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 5)},
      unk_4 : 2,
    },
    [16] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 2), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 3)},
      unk_4 : 1,
    },
    [17] = {
      motions : {MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 0), MOTION(DM187_OMEGA_ZX_TRIPLE_LASER, 1)},
      unk_4 : 0,
    },
};
