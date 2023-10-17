#include "collision.h"
#include "enemy.h"
#include "global.h"

void Volcaire_Init(struct Enemy* p);
void Volcaire_Update(struct Enemy* p);
void Volcaire_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gVolcaireRoutine = {
    [ENTITY_INIT] =      Volcaire_Init,
    [ENTITY_UPDATE] =    Volcaire_Update,
    [ENTITY_DIE] =       Volcaire_Die,
    [ENTITY_DISAPPEAR] = DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

s32 FUN_08077110(struct Enemy* p, s32 x) {
  s32 dx;

  if (x != 0) {
    (p->s).coord.x += x;
    if (x < 0) {
      dx = PushoutToRight1((p->s).coord.x - PIXEL(2), (p->s).coord.y - PIXEL(8));
      if (dx > 0) {
        (p->s).coord.x += dx;
        return 1;
      }
    } else {
      dx = PushoutToLeft1((p->s).coord.x + PIXEL(2), (p->s).coord.y - PIXEL(8));
      if (dx < 0) {
        (p->s).coord.x += dx;
        return 2;
      }
    }
  }

  return 0;
}

void FUN_08077174(struct Enemy* e) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_VOLCAIRE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 1;
    (p->s).coord.x = (e->s).coord.x;
    (p->s).coord.y = (e->s).coord.y;
    (p->s).unk_28 = &e->s;
  }
}

void FUN_080771cc(struct Enemy* e, s32 x, s32 y, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityFirst(gZakoHeaderPtr);
  if (p != NULL) {
    (p->s).taskCol = 24;
    INIT_ZAKO_ROUTINE(p, ENEMY_VOLCAIRE);
    (p->s).tileNum = 0;
    (p->s).palID = 0;
    (p->s).flags2 |= WHITE_PAINTABLE;
    (p->s).invincibleID = (p->s).uniqueID;
    (p->s).work[0] = 2;
    (p->s).coord.x = x;
    (p->s).coord.y = y;
    if (n == 0) {
      (p->s).coord.x = x - PIXEL(2);
      (p->s).coord.y = y + PIXEL(8);
    } else {
      (p->s).coord.x = x + PIXEL(2);
      (p->s).coord.y = y + PIXEL(7);
    }
    (p->s).work[2] = n;
    if (e != NULL) {
      e->props.raw[4]++;
    }
    (p->s).unk_28 = &e->s;
  }
}

static void onCollision(struct Body* body UNUSED, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  // NOP
  return;
}

NAKED static bool8 FUN_08077260(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r2, r0, #0\n\
	adds r3, r2, #0\n\
	adds r3, #0x8c\n\
	ldr r0, [r3]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080772F0\n\
	ldrb r4, [r2, #0x10]\n\
	cmp r4, #1\n\
	bne _080772B0\n\
	ldr r1, _080772A8 @ =gEnemyFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r5, #2\n\
	str r5, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #0x14]\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080772DC\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xa\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080772AC\n\
	strb r5, [r2, #0xd]\n\
	b _080772E6\n\
	.align 2, 0\n\
_080772A8: .4byte gEnemyFnTable\n\
_080772AC:\n\
	strb r0, [r2, #0xd]\n\
	b _080772E6\n\
_080772B0:\n\
	ldr r1, [r2, #0x28]\n\
	cmp r1, #0\n\
	beq _080772BE\n\
	adds r1, #0xb8\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
_080772BE:\n\
	ldr r1, _080772E0 @ =gEnemyFnTable\n\
	ldrb r0, [r2, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r4, #2\n\
	str r4, [r2, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #0x14]\n\
	ldr r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0xa\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080772E4\n\
_080772DC:\n\
	strb r4, [r2, #0xd]\n\
	b _080772E6\n\
	.align 2, 0\n\
_080772E0: .4byte gEnemyFnTable\n\
_080772E4:\n\
	strb r1, [r2, #0xd]\n\
_080772E6:\n\
	adds r0, r2, #0\n\
	bl Volcaire_Die\n\
	movs r0, #1\n\
	b _080772F2\n\
_080772F0:\n\
	movs r0, #0\n\
_080772F2:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

INCASM("asm/enemy/volcaire.inc");

// --------------------------------------------

void FUN_0807762c(struct Enemy* p);
void nop_08077608(struct Enemy* p);
void FUN_0807760c(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates1[8] = {
    FUN_0807762c,
    nop_08077608,
    FUN_0807760c,
    FUN_0807760c,
    FUN_0807760c,
    FUN_0807760c,
    FUN_0807760c,
    nop_08077608,
};
// clang-format on

void FUN_080776ac(struct Enemy* p);
void FUN_080777cc(struct Enemy* p);
void FUN_08077834(struct Enemy* p);
void FUN_08077910(struct Enemy* p);
void FUN_08077af8(struct Enemy* p);
void FUN_08077b38(struct Enemy* p);
void FUN_08077ca4(struct Enemy* p);
void FUN_08077dd0(struct Enemy* p);

// clang-format off
static const EnemyFunc sUpdates2[8] = {
    FUN_080776ac,
    FUN_080777cc,
    FUN_08077834,
    FUN_08077910,
    FUN_08077af8,
    FUN_08077b38,
    FUN_08077ca4,
    FUN_08077dd0,
};
// clang-format on

// --------------------------------------------

void MaybeKillVolcaire(struct Enemy* p);
void FUN_08077fa4(struct Enemy* p);
void FUN_08077dd0(struct Enemy* p);

static const EnemyFunc sDeads[3] = {
    MaybeKillVolcaire,
    FUN_08077fa4,
    FUN_08077dd0,
};

// --------------------------------------------

static const struct Collision sCollisions[13] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(8), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(5), -PIXEL(8), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(5), -PIXEL(8), PIXEL(11), PIXEL(18)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(11), PIXEL(12), PIXEL(24)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      atkType : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 3,
      hardness : 8,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(5), PIXEL(20), PIXEL(10)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      remaining : 0,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(5), PIXEL(20), PIXEL(10)},
    },
};

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(4)};

static const u8 sInitModes[4] = {1, 2, 3, 0};

static const motion_t sMotions[4] = {
    MOTION(SM046_VOLCAIRE, 9),
    MOTION(SM046_VOLCAIRE, 10),
    MOTION(SM046_VOLCAIRE, 11),
    MOTION(SM046_VOLCAIRE, 8),
};
