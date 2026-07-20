#include "boss.h"
#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

struct BossPhantom {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 unk_b4[20];         // 0xB4
  u8 unk_c8;             // 0xC8
  u8 unk_c9;             // 0xC9
  u8 unk_ca;             // 0xCA
  bool8 isRight;         // 0xCB
  u8 unk_cc[4];          // 0xCC
  void* unk_d0;          // 0xD0
  u8 unk_d4[16];         // 0xD4
};
static_assert(sizeof(struct BossPhantom) == sizeof(struct Boss));

void FUN_080c4be0(s32 x, s32 y);

void phantom_080607e4(struct Entity* p);
static void onCollision(struct Body* body, Coords32* c1, Coords32* c2);
void FUN_080607a0(struct BossPhantom* p, s32 anim);

static const motion_t sMotions[];
static const struct Collision sCollisions[];

void FUN_0805ecc8(struct Entity* p) {
  s32 i;
  for (i = 0; i < 4; i++) {
    s32 x = (p->coord).x + PIXEL((RANDOM(RNG_0202f388) % 24) - 12);
    s32 y = (p->coord).y - PIXEL(-RANDOM(RNG_0202f388) & 0x1F);
    FUN_080c4be0(x, y);
  }
}

static void Phantom_Init(struct Boss* p);
static void Phantom_Update(struct BossPhantom* p);
void Phantom_Die(struct Boss* p);

// clang-format off
const BossRoutine gPhantomBossRoutine = {
    [ENTITY_INIT] =      (void*)Phantom_Init,
    [ENTITY_UPDATE] =    (void*)Phantom_Update,
    [ENTITY_DIE] =       (void*)Phantom_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

NAKED static void Phantom_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _0805EEAC @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	movs r0, #5\n\
	strb r0, [r7, #0xd]\n\
	movs r0, #0\n\
	strh r0, [r7, #0xe]\n\
	movs r1, #0\n\
	strb r1, [r7, #0x10]\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r4, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	adds r0, r4, #0\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	str r1, [r7, #0x58]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl __divsi3\n\
	lsls r1, r0, #4\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #0xc\n\
	ldr r0, _0805EEB0 @ =0xFFFF9000\n\
	adds r2, r1, r0\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #7\n\
	adds r1, r1, r0\n\
	adds r0, r7, #0\n\
	adds r0, #0xd4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	subs r1, r1, r2\n\
	adds r0, #4\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	asrs r1, r1, #1\n\
	adds r2, r2, r1\n\
	str r2, [r0]\n\
	subs r0, #0x1c\n\
	movs r1, #0\n\
	str r1, [r0]\n\
	ldr r5, _0805EEB4 @ =0x00000A78\n\
	ldr r2, _0805EEB8 @ =gStaticMotionGraphics\n\
	mov r8, r2\n\
	adds r0, r5, r2\n\
	ldr r1, _0805EEBC @ =wStaticGraphicTilenums\n\
	mov sb, r1\n\
	movs r4, #0x86\n\
	lsls r4, r4, #1\n\
	adds r1, r1, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _0805EEC0 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	ldr r6, _0805EEC4 @ =wStaticMotionPalIDs\n\
	adds r4, r6, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sl, r2\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	ldr r5, _0805EEC8 @ =0x00000A8C\n\
	mov r1, r8\n\
	adds r0, r5, r1\n\
	movs r4, #0x87\n\
	lsls r4, r4, #1\n\
	mov r2, sb\n\
	adds r1, r2, r4\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _0805EEC0 @ =gStaticMotionGraphics+12\n\
	adds r5, r5, r0\n\
	adds r4, r6, r4\n\
	ldrh r1, [r4]\n\
	ldrb r0, [r5, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r5, #0\n\
	bl LoadPalette\n\
	movs r4, #0xaa\n\
	lsls r4, r4, #4\n\
	add r8, r4\n\
	movs r5, #0x88\n\
	lsls r5, r5, #1\n\
	add sb, r5\n\
	mov r2, sb\n\
	ldrh r1, [r2]\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	ldr r1, _0805EEC0 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r1\n\
	adds r6, r6, r5\n\
	ldrh r1, [r6]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sl\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r1, _0805EECC @ =sCollisions\n\
	adds r0, r7, #0\n\
	movs r2, #0x60\n\
	bl ResetBossBody\n\
	ldr r1, _0805EED0 @ =onCollision\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x5c\n\
	movs r2, #0\n\
	str r2, [r0]\n\
	movs r0, #0\n\
	strb r0, [r7, #0x10]\n\
	adds r0, r7, #0\n\
	bl Phantom_Update\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805EEAC: .4byte gBossFnTable\n\
_0805EEB0: .4byte 0xFFFF9000\n\
_0805EEB4: .4byte 0x00000A78\n\
_0805EEB8: .4byte gStaticMotionGraphics\n\
_0805EEBC: .4byte wStaticGraphicTilenums\n\
_0805EEC0: .4byte gStaticMotionGraphics+12\n\
_0805EEC4: .4byte wStaticMotionPalIDs\n\
_0805EEC8: .4byte 0x00000A8C\n\
_0805EECC: .4byte sCollisions\n\
_0805EED0: .4byte onCollision\n\
 .syntax divided\n");
}

// 0x0805eed4
static void onCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  struct BossPhantom* p = (struct BossPhantom*)body->parent;
  if (body->hitboxFlags & BODY_STATUS_WHITE) PlaySound(SE_PHANTOM_DAMAGE);
  p->isRight = ((pZero2->s).coord.x - (p->coord).x) > 0;
}

static const EntityFunc sUpdates[1];

static void Phantom_Update(struct BossPhantom* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    if (p->unk_d0 != NULL) p->unk_d0 = NULL;
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    p->mode[1] = 0;
    Phantom_Die((void*)p);
    return;
  }
  sUpdates[p->work[0]]((void*)p);
  phantom_080607e4((void*)p);
}

static const EntityFunc _sUpdates[7];

static void callPhantomBossModeTable(struct Entity* p) { _sUpdates[p->mode[1]](p); }

static const EntityFunc PTR_ARRAY_08365434[2];

static void phantom_0805efa4(struct Entity* p) { PTR_ARRAY_08365434[p->mode[2]](p); }

static void FUN_0805f004(Object* p);

static void FUN_0805efbc(Object* p) {
  SetDDP(&p->body, &sCollisions[0]);
  *((u16*)&p->mode[2]) = 1;
  FUN_080607a0((void*)p, 0);
  RANDOM(RNG_0202f388);
  p->work[2] = 1;
  FUN_0805f004(p);
}

void FUN_080607f0(void*);

static void FUN_0805f004(Object* p) {
  s32 i;
  FUN_080607f0(p);
  i = p->work[2] - 1;
  p->work[2] = i;
  if (i) {
    return;
  }
  if ((p->body).hp < 48) {
    u32 idx = RANDOM(RNG_0202f388) & 0x1F;
    if (idx < 10) {
      p->mode[1] = 1, *((u16*)&p->mode[2]) = 0;
    } else if (idx < 17) {
      p->mode[1] = 3, *((u16*)&p->mode[2]) = 0;
    } else if (idx < 24) {
      p->mode[1] = 4, *((u16*)&p->mode[2]) = 0;
    } else {
      p->mode[1] = 6, *((u16*)&p->mode[2]) = 0;
    }
  } else {
    u32 idx = RANDOM(RNG_0202f388) & 0x1F;
    if (idx < 14) {
      p->mode[1] = 1, *((u16*)&p->mode[2]) = 0;
    } else if (idx < 23) {
      p->mode[1] = 3, *((u16*)&p->mode[2]) = 0;
    } else {
      p->mode[1] = 4, *((u16*)&p->mode[2]) = 0;
    }
  }
}

INCASM("asm/boss/phantom.inc");

// --------------------------------------------

// clang-format off
// 0x08365214
static const motion_t sMotions[21] = {
    MOTION(DM188_PHANTOM, 0x00),
    MOTION(DM188_PHANTOM, 0x0B),
    MOTION(DM188_PHANTOM, 0x0D),
    MOTION(DM188_PHANTOM, 0x03),
    MOTION(DM188_PHANTOM, 0x0A),
    MOTION(DM188_PHANTOM, 0x11),
    MOTION(DM188_PHANTOM, 0x12),
    MOTION(DM188_PHANTOM, 0x0C),
    MOTION(DM188_PHANTOM, 0x06),
    MOTION(DM188_PHANTOM, 0x04),
    MOTION(DM188_PHANTOM, 0x05),
    MOTION(DM188_PHANTOM, 0x07),
    MOTION(DM188_PHANTOM, 0x08),
    MOTION(DM188_PHANTOM, 0x09),
    MOTION(DM188_PHANTOM, 0x01),
    MOTION(DM188_PHANTOM, 0x02),
    MOTION(DM188_PHANTOM, 0x10),
    MOTION(DM188_PHANTOM, 0x0E),
    MOTION(DM188_PHANTOM, 0x0F),
    MOTION(DM188_PHANTOM, 0x13),
    MOTION(DM188_PHANTOM, 0x14),
};
// clang-format on

// 0x08365240
static const s32 s32_ARRAY_08365240[32] = {
    0x00000000, 0x00000040, 0x000000C0, 0x00000180, 0x00000280, 0x000003C0, 0x00000540, 0x00000700, 0x00000900, 0x00000B40, 0x00000DC0, 0x00001080, 0x00001380, 0x000016C0, 0x00001A40, 0x00001E00, 0x00002200, 0x00002640, 0x00002AC0, 0x00002F80, 0x00003480, 0x000039C0, 0x00003F40, 0x00004500, 0x00004B00, 0x00005140, 0x000057C0, 0x00005E80, 0x00006580, 0x00006CC0, 0x00007440, 0x00007C00,
};

// 0x083652c0
static const struct Collision sCollisions[14] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(14), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(14), PIXEL(16), PIXEL(28)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(16), -PIXEL(9), PIXEL(48), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {-PIXEL(5), -PIXEL(12), PIXEL(26), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(16), PIXEL(16), PIXEL(32)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(19), PIXEL(16), PIXEL(38)},
    },
};

// --------------------------------------------

void phantom_08060668(struct Boss* p);

static const BossFunc sDeads[1] = {
    phantom_08060668,
};  // 0x08365410

// --------------------------------------------

static void callPhantomBossModeTable(struct Entity* p);

// 0x08365414
static const EntityFunc sUpdates[1] = {
    callPhantomBossModeTable,
};

static void phantom_0805efa4(struct Entity* p);
void phantom_0805f0a0(struct Boss* p);
void FUN_0805f3d0(struct Boss* p);
void FUN_0805f54c(struct Boss* p);
void FUN_0805fa10(struct Boss* p);
void phantom_08060244(struct Boss* p);
void FUN_080603b8(struct Boss* p);

// clang-format off
static const EntityFunc _sUpdates[7] = {
    (void*)phantom_0805efa4,
    (void*)phantom_0805f0a0,
    (void*)FUN_0805f3d0,
    (void*)FUN_0805f54c,
    (void*)FUN_0805fa10,
    (void*)phantom_08060244,
    (void*)FUN_080603b8,
}; // 0x08365418
// clang-format on

static void FUN_0805efbc(Object* p);
static void FUN_0805f004(Object* p);

// 0x08365434
static const EntityFunc PTR_ARRAY_08365434[2] = {
    (void*)FUN_0805efbc,
    (void*)FUN_0805f004,
};

void FUN_0805f0f4(struct Boss* p);
void FUN_0805f180(struct Boss* p);
void FUN_0805f26c(struct Boss* p);
void FUN_0805f338(struct Boss* p);

static const BossFunc PTR_ARRAY_0836543c[4] = {
    FUN_0805f0f4,
    FUN_0805f180,
    FUN_0805f26c,
    FUN_0805f338,
};

void phantom_0805f198(struct Boss* p);
void FUN_0805f214(struct Boss* p);

static const BossFunc PTR_ARRAY_0836544c[2] = {
    phantom_0805f198,
    FUN_0805f214,
};

void FUN_0805f284(struct Boss* p);
void FUN_0805f2e0(struct Boss* p);

static const BossFunc PTR_ARRAY_08365454[2] = {
    FUN_0805f284,
    FUN_0805f2e0,
};

void FUN_0805f350(struct Boss* p);
void FUN_0805f394(struct Boss* p);

static const BossFunc PTR_ARRAY_0836545c[2] = {
    FUN_0805f350,
    FUN_0805f394,
};

void FUN_0805f3e8(struct Boss* p);
void FUN_0805f444(struct Boss* p);
void FUN_0805f464(struct Boss* p);
void FUN_0805f488(struct Boss* p);
void FUN_0805f4a4(struct Boss* p);
void FUN_0805f52c(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365464[6] = {
    FUN_0805f3e8,
    FUN_0805f444,
    FUN_0805f464,
    FUN_0805f488,
    FUN_0805f4a4,
    FUN_0805f52c,
};
// clang-format on

void FUN_0805f564(struct Boss* p);
void FUN_0805f6b0(struct Boss* p);
void FUN_0805f738(struct Boss* p);
void FUN_0805f76c(struct Boss* p);
void FUN_0805f820(struct Boss* p);
void FUN_0805f934(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_0836547c[6] = {
    FUN_0805f564,
    FUN_0805f6b0,
    FUN_0805f738,
    FUN_0805f76c,
    FUN_0805f820,
    FUN_0805f934,
};
// clang-format on

void FUN_0805f57c(struct Boss* p);
void FUN_0805f5a8(struct Boss* p);
void FUN_0805f630(struct Boss* p);
void FUN_0805f660(struct Boss* p);
void FUN_0805f690(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365494[5] = {
    FUN_0805f57c,
    FUN_0805f5a8,
    FUN_0805f630,
    FUN_0805f660,
    FUN_0805f690,
};
// clang-format on

void FUN_0805f6c8(struct Boss* p);
void FUN_0805f6e0(struct Boss* p);
void FUN_0805f6fc(struct Boss* p);
void FUN_0805f71c(struct Boss* p);

static const BossFunc PTR_ARRAY_083654a8[4] = {
    FUN_0805f6c8,
    FUN_0805f6e0,
    FUN_0805f6fc,
    FUN_0805f71c,
};

void FUN_0805f784(struct Boss* p);
void FUN_0805f794(struct Boss* p);
void FUN_0805f7d0(struct Boss* p);

static const BossFunc PTR_ARRAY_083654b8[3] = {
    FUN_0805f784,
    FUN_0805f794,
    FUN_0805f7d0,
};

void FUN_0805f838(struct Boss* p);
void FUN_0805f85c(struct Boss* p);
void FUN_0805f870(struct Boss* p);
void FUN_0805f8c4(struct Boss* p);
void nop_0805f930(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654c4[5] = {
    FUN_0805f838,
    FUN_0805f85c,
    FUN_0805f870,
    FUN_0805f8c4,
    nop_0805f930,
};
// clang-format on

void FUN_0805f94c(struct Boss* p);
void FUN_0805f97c(struct Boss* p);
void FUN_0805f9a0(struct Boss* p);
void FUN_0805f9dc(struct Boss* p);
void FUN_0805f9f4(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654d8[5] = {
    FUN_0805f94c,
    FUN_0805f97c,
    FUN_0805f9a0,
    FUN_0805f9dc,
    FUN_0805f9f4,
};
// clang-format on

void FUN_0805fa28(struct Boss* p);
void FUN_0805fa44(struct Boss* p);
void FUN_0805fc7c(struct Boss* p);
void FUN_0805fd5c(struct Boss* p);
void FUN_0805ff64(struct Boss* p);
void FUN_080600fc(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_083654ec[6] = {
    FUN_0805fa28,
    FUN_0805fa44,
    FUN_0805fc7c,
    FUN_0805fd5c,
    FUN_0805ff64,
    FUN_080600fc,
};
// clang-format on

void FUN_0805fa5c(struct Boss* p);
void FUN_0805fac4(struct Boss* p);
void FUN_0805fadc(struct Boss* p);
void FUN_0805fafc(struct Boss* p);
void FUN_0805fb24(struct Boss* p);
void FUN_0805fb8c(struct Boss* p);
void FUN_0805fc1c(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365504[7] = {
    FUN_0805fa5c,
    FUN_0805fac4,
    FUN_0805fadc,
    FUN_0805fafc,
    FUN_0805fb24,
    FUN_0805fb8c,
    FUN_0805fc1c,
};
// clang-format on

void FUN_0805fd74(struct Boss* p);
void FUN_0805fdac(struct Boss* p);
void FUN_0805feac(struct Boss* p);

static const BossFunc PTR_ARRAY_08365520[3] = {
    FUN_0805fd74,
    FUN_0805fdac,
    FUN_0805feac,
};

void FUN_0805ff7c(struct Boss* p);
void FUN_0805ffb4(struct Boss* p);
void FUN_0805ffec(struct Boss* p);
void FUN_08060040(struct Boss* p);
void FUN_080600c8(struct Boss* p);
void FUN_080600e0(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_0836552c[6] = {
    FUN_0805ff7c,
    FUN_0805ffb4,
    FUN_0805ffec,
    FUN_08060040,
    FUN_080600c8,
    FUN_080600e0,
};
// clang-format on

void FUN_08060114(struct Boss* p);
void FUN_0806016c(struct Boss* p);
void FUN_0806019c(struct Boss* p);
void FUN_080601f0(struct Boss* p);
void FUN_08060208(struct Boss* p);

// clang-format off
static const BossFunc PTR_ARRAY_08365544[5] = {
    FUN_08060114,
    FUN_0806016c,
    FUN_0806019c,
    FUN_080601f0,
    FUN_08060208,
};
// clang-format on

void FUN_080603d0(struct Boss* p);
void FUN_08060410(struct Boss* p);
void FUN_080604e0(struct Boss* p);
void FUN_08060560(struct Boss* p);

static const BossFunc PTR_ARRAY_08365558[4] = {
    FUN_080603d0,
    FUN_08060410,
    FUN_080604e0,
    FUN_08060560,
};

void FUN_080afdf0(struct Boss* p);
void FUN_080afe38(struct Boss* p);

static const BossFunc PTR_ARRAY_08365568[2] = {
    FUN_080afdf0,
    FUN_080afe38,
};
