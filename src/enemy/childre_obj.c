#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

void FUN_080b834c(struct Entity* e, struct Coord* c, struct Coord* dc, s32 y, motion_t* motions, u8 frame);

static const struct Collision sCollisions[2 * 4];
static const u8 sInitModes[4];

NAKED static void ChildreObj_Init(struct Enemy* p);
static void ChildreObj_Update(struct Enemy* p);
static void ChildreObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gChildreObjRoutine = {
    [ENTITY_INIT] =      ChildreObj_Init,
    [ENTITY_UPDATE] =    ChildreObj_Update,
    [ENTITY_DIE] =       ChildreObj_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// スプリットマインの爆弾を1つ作成
void CreateSplitMineBomb(s32 x, s32 y) {
  struct Enemy* p;

  CreateVFX31_1(x, y);
  p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).work[0] = 0;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
  }
}

// スプリットマインを爆発させて破片にさせる
NAKED void ExplodeSplitMine(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	mov sb, r0\n\
	mov r8, r1\n\
	movs r4, #0\n\
	movs r6, #0xf6\n\
	lsls r6, r6, #0x18\n\
	movs r5, #0\n\
_080736CE:\n\
	ldr r0, _08073770 @ =gEnemyHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _08073752\n\
	adds r1, r2, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	ldr r1, _08073774 @ =gEnemyFnTable\n\
	movs r0, #0x13\n\
	strb r0, [r2, #9]\n\
	ldr r0, [r1, #0x4c]\n\
	ldr r0, [r0]\n\
	str r0, [r2, #0x14]\n\
	movs r1, #0\n\
	strh r1, [r2, #0x20]\n\
	adds r0, r2, #0\n\
	adds r0, #0x22\n\
	movs r3, #0\n\
	strb r3, [r0]\n\
	ldrb r0, [r2, #0xb]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r2, #0xb]\n\
	ldrb r0, [r2, #0x1c]\n\
	strb r0, [r2, #0x1d]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x10]\n\
	strb r4, [r2, #0x11]\n\
	mov r7, sb\n\
	str r7, [r2, #0x54]\n\
	mov r0, r8\n\
	str r0, [r2, #0x58]\n\
	ldr r3, _08073778 @ =gSineTable\n\
	lsrs r0, r6, #0x18\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	movs r7, #0\n\
	ldrsh r1, [r0, r7]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _0807372E\n\
	adds r0, #0xff\n\
_0807372E:\n\
	asrs r0, r0, #8\n\
	str r0, [r2, #0x5c]\n\
	adds r0, r5, #0\n\
	subs r0, #0x4a\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #7\n\
	cmp r0, #0\n\
	bge _0807374C\n\
	adds r0, #0xff\n\
_0807374C:\n\
	asrs r0, r0, #8\n\
	rsbs r0, r0, #0\n\
	str r0, [r2, #0x60]\n\
_08073752:\n\
	movs r7, #0xa0\n\
	lsls r7, r7, #0x14\n\
	adds r6, r6, r7\n\
	adds r5, #0xa\n\
	adds r4, #1\n\
	cmp r4, #2\n\
	ble _080736CE\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08073770: .4byte gEnemyHeaderPtr\n\
_08073774: .4byte gEnemyFnTable\n\
_08073778: .4byte gSineTable\n\
 .syntax divided\n");
}

void CreateChildreScrewIce(s32 x, s32 y, u8 n) {
  struct Enemy* p;

  CreateVFX31_1(x, y);
  p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).work[0] = 2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = n;
  }
}

void CreateChildreMissile(s32 x, s32 y, u8 n) {
  struct Enemy* p = AllocEntityFirst(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).work[0] = 3;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = n;
  }
}

static void onCollision(struct Body* body UNUSED, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  // NOP
  return;
}

static bool8 FUN_0807383c(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    (p->s).mode[1] = (p->s).work[0];
    ChildreObj_Die(p);
    return TRUE;
  }
  return FALSE;
}

// --------------------------------------------

NAKED static void ChildreObj_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080738C0 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	ldr r1, _080738C4 @ =sInitModes\n\
	ldrb r0, [r5, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	movs r6, #0\n\
	strb r0, [r5, #0xd]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #1\n\
	beq _080738EC\n\
	cmp r0, #1\n\
	bgt _080738C8\n\
	cmp r0, #0\n\
	beq _080738D6\n\
	b _080738D0\n\
	.align 2, 0\n\
_080738C0: .4byte gEnemyFnTable\n\
_080738C4: .4byte sInitModes\n\
_080738C8:\n\
	cmp r0, #2\n\
	beq _08073900\n\
	cmp r0, #3\n\
	beq _0807391C\n\
_080738D0:\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	b _0807393A\n\
_080738D6:\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080738E8 @ =sCollisions\n\
	b _0807392A\n\
	.align 2, 0\n\
_080738E8: .4byte sCollisions\n\
_080738EC:\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080738FC @ =sCollisions+48\n\
	b _0807392A\n\
	.align 2, 0\n\
_080738FC: .4byte sCollisions+48\n\
_08073900:\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08073918 @ =sCollisions+96\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #7\n\
	b _08073932\n\
	.align 2, 0\n\
_08073918: .4byte sCollisions+96\n\
_0807391C:\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _0807394C @ =sCollisions+144\n\
_0807392A:\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #6\n\
_08073932:\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
_0807393A:\n\
	ldr r0, _08073950 @ =onCollision\n\
	str r0, [r4, #0x24]\n\
	adds r0, r5, #0\n\
	bl ChildreObj_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807394C: .4byte sCollisions+144\n\
_08073950: .4byte onCollision\n\
 .syntax divided\n");
}

// --------------------------------------------

static void nop_080739a8(struct Enemy* p);

void FUN_080739ac(struct Enemy* p);
void FUN_08073a0c(struct Enemy* p);
void FUN_08073a74(struct Enemy* p);
NON_MATCH void FUN_08073b28(struct Enemy* p);

static void ChildreObj_Update(struct Enemy* p) {
  static const EnemyFunc sUpdates1[4] = {
      nop_080739a8,
      nop_080739a8,
      nop_080739a8,
      nop_080739a8,
  };
  static const EnemyFunc sUpdates2[4] = {
      FUN_080739ac,
      FUN_08073a0c,
      FUN_08073a74,
      FUN_08073b28,
  };

  bool8 isDead = FUN_0807383c(p);
  if (!isDead) {
    (sUpdates1[(p->s).mode[1]])(p);
    (sUpdates2[(p->s).mode[1]])(p);
  }
}

// --------------------------------------------

void FUN_08073d88(struct Enemy* p);
void FUN_08073dd8(struct Enemy* p);
void FUN_08073e18(struct Enemy* p);
void FUN_08073e60(struct Enemy* p);

static void ChildreObj_Die(struct Enemy* p) {
  static const EnemyFunc sDeads[4] = {
      FUN_08073d88,
      FUN_08073dd8,
      FUN_08073e18,
      FUN_08073e60,
  };
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void nop_080739a8(struct Enemy* p) {
  // nop
  return;
}

void FUN_080739ac(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      (p->s).work[2] = 0x40;
      SetMotion(&p->s, MOTION(0x24, 0));
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        ExplodeSplitMine((p->s).coord.x, (p->s).coord.y);
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = (p->s).work[0];
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_08073a0c(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0:
      SetMotion(&p->s, MOTION(0x24, 1) + (p->s).work[1]);
      (p->s).mode[2]++;
      // fallthrough
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      if (FUN_080098a4((p->s).coord.x, (p->s).coord.y)) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = (p->s).work[0];
      }
      UpdateEntityAnim(&p->s);
      break;
  }
}

void FUN_08073a74(struct Enemy* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      const s16* st;
      InitRotatableMotion(&p->s);
      (p->s).angle = 0x80 - (p->s).work[2];
      SetMotion(&p->s, MOTION(0x25, 0x02));
      st = gSineTable;
      (p->s).d.x = (st[(u8)((p->s).work[2] + 0x40)] * 5 << 7) / 0x100;
      (p->s).d.y = -((st[(p->s).work[2]] * 5 << 7) / 0x100);
      (p->s).mode[2]++;
    }
      // fallthrough
    case 1: {
      s32 x = (p->s).coord.x + (p->s).d.x;
      s32 y;
      (p->s).coord.x = x;
      y = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = y;
      if (((u16)FUN_080098a4(x, y) << 16) != 0) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = (p->s).work[0];
      }
      UpdateEntityAnim(&p->s);
      break;
    }
  }
}

NON_MATCH void FUN_08073b28(struct Enemy* p) {
#if MODERN
  struct Coord c;
  struct Coord dc;
  u8 m2 = (p->s).mode[2];
  u32 oct;
  switch (m2) {
    case 0: {
      s32* pb = (s32*)((u8*)p + 0xb4);
      (p->s).work[3] = m2;
      *pb = ((p->s).coord.x / 0xF000) * 0xF000 + 0x7800;
      *(s32*)((u8*)p + 0xb8) = FUN_08009f6c((p->s).coord.x, (p->s).coord.y);
      SetMotion(&p->s, 0x2406);
      UpdateEntityAnim(&p->s);
      (p->s).d.x = ((p->s).work[2] << 9) + -0x100;
      (p->s).d.y = -0x400;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 ny;
      (p->s).unk_coord.x = (p->s).coord.x;
      (p->s).unk_coord.y = (p->s).coord.y;
      (p->s).coord.x += (p->s).d.x;
      {
        s32 g = (p->s).d.y + 0x40;
        (p->s).d.y = g;
        if (g > 0x700) {
          (p->s).d.y = 0x700;
        }
      }
      ny = (p->s).coord.y + (p->s).d.y;
      (p->s).coord.y = ny;
      if ((p->s).d.y > 0) {
        goto seachk;
      }
      break;
    seachk:
      if (ny > gOverworld.sea) {
        (p->s).mode[2]++;
      }
      break;
    }
    case 2:
      (p->s).d.x = ((p->s).work[2] << 10) + -0x200;
      (p->s).mode[2]++;
      FALLTHROUGH;
    case 3: {
      s32 ox = (p->s).coord.x;
      s32 cy;
      s32 dy, a, b, vy, ny2, kb;
      u16 mag;
      s32 m8;
      (p->s).unk_coord.x = ox;
      cy = (p->s).coord.y;
      (p->s).unk_coord.y = cy;
      ox = (pZero2->s).coord.x - ox;
      cy += 0x1800;
      dy = (pZero2->s).coord.y - cy;
      a = ox >> 8;
      b = dy >> 8;
      mag = Sqrt(a * a + b * b);
      m8 = mag << 8;
      vy = (dy << 8) / m8;
      vy <<= 1;
      {
        s32 nd = (p->s).d.y + (vy - (p->s).d.y) / 8;
        (p->s).d.y = nd;
        (p->s).coord.x += (p->s).d.x;
        (p->s).coord.y += (nd * 448) / 256;
      }
      ny2 = (p->s).coord.y;
      if (ny2 < gOverworld.sea) {
        (p->s).coord.y = gOverworld.sea;
      }
      if ((p->s).coord.y > *(s32*)((u8*)p + 0xb8)) {
        (p->s).coord.y = *(s32*)((u8*)p + 0xb8);
      }
      kb = *(s32*)((u8*)p + 0xb4) - (p->s).coord.x + 0x6800;
      if ((u32)kb > 0xD000 || ((p->body).status & 4)) {
        SET_ENEMY_ROUTINE(p, ENTITY_DIE);
        (p->s).mode[1] = (p->s).work[0];
      }
      break;
    }
  }
  {
    s32 dx16 = (p->s).coord.x - (p->s).unk_coord.x;
    s32 dy16 = (p->s).unk_coord.y - (p->s).coord.y;
    u32 a8 = ((u16)ArcTan2(dx16, dy16)) >> 8;
    oct = ((u8)(a8 + 0x10)) >> 5;
    GotoMotion(&p->s, sMotions[oct], (u16)(p->s).motion.cmdIdx, (u16)(p->s).motion.duration);
  }
  UpdateEntityAnim(&p->s);
  (p->s).work[3]++;
  {
    u8 r6v = (p->s).work[3] % 6;
    if (r6v == 0) {
      c.x = (p->s).coord.x + (s8_ARRAY_ARRAY_08366e08[oct][0] << 8);
      c.y = (p->s).coord.y + (s8_ARRAY_ARRAY_08366e08[oct][1] << 8);
      dc.x = r6v;
      dc.y = r6v;
      FUN_080b834c(&p->s, &c, &dc, 0, (motion_t*)&s32_08366e18, 0xF);
    }
  }
#else
  INCCODE("asm/enemy/childre_obj_3b28.inc");
#endif
}

void FUN_08073d88(struct Enemy* p) {
  CreateVFX31_1((p->s).coord.x, (p->s).coord.y);
  EXIT_BODY(p);
  CreateSmoke(1, &(p->s).coord);
  PlaySound(0x2a);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_08073dd8(struct Enemy* p) {
  EXIT_BODY(p);
  CreateSmoke(2, &(p->s).coord);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_08073e18(struct Enemy* p) {
  PlaySound(0x3f);
  CreateVFX31_2((p->s).coord.x, (p->s).coord.y);
  EXIT_BODY(p);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

void FUN_08073e60(struct Enemy* p) {
  EXIT_BODY(p);
  CreateSmoke(2, &(p->s).coord);
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
  PlaySound(0x35);
}

// --------------------------------------------

static const struct Collision sCollisions[2 * 4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

// --------------------------------------------

static const u8 sInitModes[4] = {0, 1, 2, 3};

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(SM036_UNK, 8),
    MOTION(SM036_UNK, 7),
    MOTION(SM036_UNK, 6),
    MOTION(SM036_UNK, 5),
    MOTION(SM036_UNK, 4),
    MOTION(SM036_UNK, 11),
    MOTION(SM036_UNK, 10),
    MOTION(SM036_UNK, 9),
}; // 0x08366DF8
// clang-format on

static const s8 s8_ARRAY_ARRAY_08366e08[8][2] = {
    {-6, 0}, {-4, 4}, {0, 6}, {4, 4}, {6, 0}, {4, -4}, {0, -6}, {-4, -4},
};  // 0x08366E08

static const s32 s32_08366e18 = MOTION(SM036_UNK, 12);  // 0x08366E18
