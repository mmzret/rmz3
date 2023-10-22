#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "vfx.h"

static const struct Collision sCollisions[2 * 4];
static const u8 sInitModes[4];

static void ChildreObj_Init(struct Enemy* p);
static void ChildreObj_Update(struct Enemy* p);
static void ChildreObj_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gChildreObjRoutine = {
    [ENTITY_INIT] =      ChildreObj_Init,
    [ENTITY_UPDATE] =    ChildreObj_Update,
    [ENTITY_DIE] =       ChildreObj_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// スプリットマインの爆弾を1つ作成
void CreateSplitMineBomb(s32 x, s32 y) {
  struct Enemy* p;

  CreateVFX31_1(x, y);
  p = (struct Enemy*)AllocEntityLast(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
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
	ldr r0, _08073770 @ =gZakoHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityLast\n\
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
_08073770: .4byte gZakoHeaderPtr\n\
_08073774: .4byte gEnemyFnTable\n\
_08073778: .4byte gSineTable\n\
 .syntax divided\n");
}

void CreateChildreScrewIce(s32 x, s32 y, u8 n) {
  struct Enemy* p;

  CreateVFX31_1(x, y);
  p = (struct Enemy*)AllocEntityLast(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = n;
  }
}

void CreateChildreMissile(s32 x, s32 y, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_CHILDRE_OBJ);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 3;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    (p->s).work[2] = n;
  }
}

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  // NOP
  return;
}

static bool8 FUN_0807383c(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_DEAD) {
    SET_ZAKO_ROUTINE(p, ENTITY_DIE);
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
void FUN_08073b28(struct Enemy* p);

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

INCASM("asm/enemy/childre_obj.inc");

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
    MOTION(SM036_UNK, 0x08),
    MOTION(SM036_UNK, 0x07),
    MOTION(SM036_UNK, 0x06),
    MOTION(SM036_UNK, 0x05),
    MOTION(SM036_UNK, 0x04),
    MOTION(SM036_UNK, 0x0B),
    MOTION(SM036_UNK, 0x0A),
    MOTION(SM036_UNK, 0x09),
};
// clang-format on

static const s8 s8_ARRAY_ARRAY_08366e08[8][2] = {
    {-6, 0}, {-4, 4}, {0, 6}, {4, 4}, {6, 0}, {4, -4}, {0, -6}, {-4, -4},
};

static const s32 s32_08366e18 = 0x240C;
