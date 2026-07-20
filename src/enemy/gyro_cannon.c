#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "mod.h"
#include "story.h"
#include "vfx.h"

struct GyroCannon {
  COLLISION_OBJECT_HDR;
  struct {
    struct VFX* elfx;  // 0xB4
    s32 init_y;        // 0xB8
    bool8 is_right;    // 0xBC
    u8 unk_bd;         // 0xBD
    u8 unk_be;         // 0xBE
    u8 unk_bf;         // 0xBF
    u32 unk_c0;        // 0xC0
  } props;             // props (16bytes, offset: 0xB4..)
};
static_assert(sizeof(struct GyroCannon) == sizeof(struct Enemy));

static const struct Collision sCollisions[];

static void GyroCannon_Init(struct Enemy* p);
static void GyroCannon_Update(struct Enemy* p);
static void GyroCannon_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gGyroCannonRoutine = {
    [ENTITY_INIT] =      (void*)GyroCannon_Init,
    [ENTITY_UPDATE] =    (void*)GyroCannon_Update,
    [ENTITY_DIE] =       (void*)GyroCannon_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static struct Entity* CreateGyroCannon(struct Entity* e, bool8 isPropeller, u8 r2) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_GYRO_CANNON);
    p->unk_28 = e;
    p->work[0] = isPropeller, p->work[1] = r2;
  }
  return p;
}

// --------------------------------------------

static void initGyroCannonMainBody(struct GyroCannon* p);
static void initGyroCannonPropeller(struct GyroCannon* p);

static void GyroCannon_Init(struct Enemy* p) {
  SET_ENEMY_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  if ((p->s).work[0] != 0) {  // propeller
    initGyroCannonPropeller((void*)p);
  } else {
    initGyroCannonMainBody((void*)p);
  }
  GyroCannon_Update(p);
}

// --------------------------------------------

void gyrocannon_0806d32c(struct Enemy* p);
static void gyrocannon_0806d1b4(struct Enemy* p);

static void GyroCannon_Update(struct Enemy* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((p->s).work[0] != 0) {
    gyrocannon_0806d32c(p);  // propeller
  } else {
    gyrocannon_0806d1b4(p);
  }
}

// --------------------------------------------

void FUN_0806d524(struct Enemy* p);
void FUN_0806d470(struct Enemy* p);

static void GyroCannon_Die(struct Enemy* p) {
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  if ((p->s).work[0] != 0) {
    FUN_0806d524(p);  // propeller
  } else {
    FUN_0806d470(p);
  }
}

// --------------------------------------------

static void FUN_0806df10(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

// 0x0806d0a8
static void initGyroCannonMainBody(struct GyroCannon* p) {
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 0));
  UpdateSpriteAnimation(p);
  if (FLAG(gSystemSavedata.flags, MOD_120) && !FLAG(gCurStory.s.gameflags, DEMO_PLAY)) {
    _INIT_BODY(p, sCollisions, 20);
  } else {
    _INIT_BODY(p, sCollisions, 16);
  }
  SET_BODY_INTERSECT_HANDLER(p, FUN_0806df10);
  p->unk_2c = CreateGyroCannon((void*)p, TRUE, 0);
  (&p->props)->unk_bd = 0;
  (&p->props)->init_y = p->coord.y;
  (&p->props)->unk_be = 0, (&p->props)->unk_bf = 0;
  p->d.y = 0;
  p->work[3] = 0;
  (&p->props)->elfx = NULL;
  p->mode[1] = 2;
}

static void initGyroCannonPropeller(struct GyroCannon* p) {
  SetSpriteAnimation(p, MOTION(SM023_GYRO_CANNON, 6));
  UpdateSpriteAnimation(p);
  INIT_BODY(p, &sCollisions[2], 6, NULL);
  p->flags &= ~X_FLIP;
  p->spr.xflip = FALSE, p->spr.oam.xflip = FALSE;
  (p->props).elfx = NULL;
}

static const Coords32 sElementCoord;
static const EnemyFunc PTR_ARRAY_0836666c[10];

NAKED static void gyrocannon_0806d1b4(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, _0806D204 @ =0xFFFFE800\n\
	adds r1, r1, r2\n\
	bl IsVoidSpace\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _0806D20C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0806D208 @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D204: .4byte 0xFFFFE800\n\
_0806D208: .4byte gEnemyFnTable\n\
_0806D20C:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r1, r0, #0\n\
	cmp r1, #1\n\
	beq _0806D246\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	beq _0806D222\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _0806D222\n\
	str r2, [r4, #0x2c]\n\
_0806D222:\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	beq _0806D246\n\
	adds r3, r4, #0\n\
	adds r3, #0x8c\n\
	ldr r0, [r3]\n\
	ldr r1, _0806D250 @ =0x00020001\n\
	ands r0, r1\n\
	cmp r0, r1\n\
	bne _0806D240\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_0806D240:\n\
	ldrb r2, [r4, #0xd]\n\
	cmp r2, #1\n\
	bne _0806D254\n\
_0806D246:\n\
	adds r0, r4, #0\n\
	bl FUN_0806d684\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D250: .4byte 0x00020001\n\
_0806D254:\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806D280\n\
	ldr r1, _0806D27C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl GyroCannon_Die\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D27C: .4byte gEnemyFnTable\n\
_0806D280:\n\
	adds r5, r4, #0\n\
	adds r5, #0xb4\n\
	cmp r2, #8\n\
	beq _0806D2AC\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0806D2AC\n\
	ldr r6, [r5]\n\
	cmp r6, #0\n\
	bne _0806D2B2\n\
	ldr r2, _0806D2D0 @ =0x083666A0\n\
	movs r0, #0\n\
	adds r1, r4, #0\n\
	bl ApplyElementEffect\n\
	str r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
	movs r0, #8\n\
	strb r0, [r4, #0xd]\n\
	strb r6, [r4, #0xe]\n\
_0806D2AC:\n\
	ldr r0, [r5]\n\
	cmp r0, #0\n\
	beq _0806D2DC\n\
_0806D2B2:\n\
	ldr r1, _0806D2D4 @ =0x0836666C\n\
	ldrb r0, [r4, #0xd]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D2D8 @ =0x083666C0\n\
	bl SetDDP\n\
	b _0806D31C\n\
	.align 2, 0\n\
_0806D2D0: .4byte sElementCoord\n\
_0806D2D4: .4byte PTR_ARRAY_0836666c\n\
_0806D2D8: .4byte sCollisions+(24*1)\n\
_0806D2DC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _0806D324 @ =sCollisions\n\
	bl SetDDP\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	bne _0806D31C\n\
	ldrb r0, [r5, #0xb]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	beq _0806D306\n\
	ldr r0, [r4, #0x2c]\n\
	cmp r0, #0\n\
	bne _0806D306\n\
	strb r0, [r4, #0xd]\n\
	strb r0, [r4, #0xe]\n\
_0806D306:\n\
	ldr r0, _0806D328 @ =0x0836666C\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_0806D31C:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806D324: .4byte sCollisions\n\
_0806D328: .4byte PTR_ARRAY_0836666c\n\
 .syntax divided\n");
}

INCASM("asm/enemy/gyro_cannon.inc");

NAKED static void FUN_0806ddfc(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #0\n\
	bne _0806DE2E\n\
	ldr r1, _0806DE64 @ =0x00001708\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r1, [r4, #0xa]\n\
	lsrs r1, r1, #4\n\
	movs r2, #1\n\
	ands r1, r2\n\
	movs r2, #0\n\
	bl CreateGhost27\n\
	movs r0, #0x30\n\
	strb r0, [r4, #0x12]\n\
	ldrb r0, [r4, #0xf]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xf]\n\
_0806DE2E:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _0806DEFA\n\
	adds r7, r4, #0\n\
	adds r7, #0x54\n\
	ldr r0, _0806DE68 @ =0x08366758\n\
	mov ip, r0\n\
	adds r2, r4, #0\n\
	adds r2, #0xb4\n\
	ldrb r5, [r2, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	adds r6, r7, #0\n\
	mov r8, r2\n\
	cmp r0, #0\n\
	beq _0806DE6C\n\
	orrs r3, r5\n\
	b _0806DE6E\n\
	.align 2, 0\n\
_0806DE64: .4byte 0x00001708\n\
_0806DE68: .4byte sSlashedEnemies +(28*2)\n\
_0806DE6C:\n\
	adds r3, r5, #0\n\
_0806DE6E:\n\
	adds r0, r7, #0\n\
	mov r1, ip\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	adds r5, r6, #0\n\
	ldr r7, _0806DE90 @ =0x08366774\n\
	mov r0, r8\n\
	ldrb r2, [r0, #8]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r3, #0x10\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DE94\n\
	orrs r3, r2\n\
	b _0806DE96\n\
	.align 2, 0\n\
_0806DE90: .4byte sSlashedEnemies +(28*3)\n\
_0806DE94:\n\
	adds r3, r2, #0\n\
_0806DE96:\n\
	adds r0, r5, #0\n\
	adds r1, r7, #0\n\
	movs r2, #0\n\
	bl CreateSlashedEnemy\n\
	movs r0, #1\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0806DEBC\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
	b _0806DEC4\n\
_0806DEBC:\n\
	movs r0, #2\n\
	adds r1, r6, #0\n\
	bl CreateSmoke\n\
_0806DEC4:\n\
	adds r1, r6, #0\n\
	movs r0, #4\n\
	bl TryDropItem\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	ldr r2, _0806DF04 @ =gScore\n\
	ldrh r1, [r2, #0xc]\n\
	ldr r0, _0806DF08 @ =0x0000270E\n\
	cmp r1, r0\n\
	bhi _0806DEE0\n\
	adds r0, r1, #1\n\
	strh r0, [r2, #0xc]\n\
_0806DEE0:\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl TryDropZakoDisk\n\
	ldr r1, _0806DF0C @ =gEnemyFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r4, #0x14]\n\
_0806DEFA:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0806DF04: .4byte gScore\n\
_0806DF08: .4byte 0x0000270E\n\
_0806DF0C: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// 0x0806df10
static void FUN_0806df10(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    struct Entity* q = (struct Entity*)body->enemy->parent;
    struct GyroCannon* p = (struct GyroCannon*)body->parent;
    (&p->props)->is_right = (q->coord).x > (p->coord).x;
  }
}

void FUN_0806d618(struct Enemy* p);
void FUN_0806d684(struct Enemy* p);
void FUN_0806d7e0(struct Enemy* p);
void FUN_0806d8b0(struct Enemy* p);
void FUN_0806d998(struct Enemy* p);
void FUN_0806d9d4(struct Enemy* p);
void FUN_0806da20(struct Enemy* p);
void FUN_0806da5c(struct Enemy* p);
void FUN_0806dab8(struct Enemy* p);
void FUN_0806db58(struct Enemy* p);

// clang-format off
static const EnemyFunc PTR_ARRAY_0836666c[10] = {
    FUN_0806d618,
    FUN_0806d684,
    FUN_0806d7e0,
    FUN_0806d8b0,
    FUN_0806d998,
    FUN_0806d9d4,
    FUN_0806da20,
    FUN_0806da5c,
    FUN_0806dab8,
    FUN_0806db58,
};
// clang-format on

void gyroCannon_0806db8c(struct Enemy* p);
void gyroCannon_0806dccc(struct Enemy* p);
static void FUN_0806ddfc(struct Enemy* p);

static const EnemyFunc sUpdates2[3] = {
    gyroCannon_0806db8c,
    gyroCannon_0806dccc,
    FUN_0806ddfc,
};

static const Coords32 sElementCoord = {PIXEL(0), PIXEL(0)};

// 0x083666a8
static const struct Collision sCollisions[5] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 2,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(20), PIXEL(32), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 2,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(4), PIXEL(32), PIXEL(24)},
    },
};

// 0x08366720
static const struct SlashedEnemy sSlashedEnemies[4] = {
    {
      m : 0x170B,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170C,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170D,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0400},
      unk_coord_0c : {0x03FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
    {
      m : 0x170E,
      unk_02 : {255, 17},
      c : {0x0000, 0x0000},
      d : {0x0100, -0x0300},
      unk_coord_0c : {0x01FF, 0x01FF},
      unk_10 : {0x0000, 0x0040},
      unk_14 : {0, 0},
    },
};
