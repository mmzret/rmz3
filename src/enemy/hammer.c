#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "story.h"

// Hammer in Repair Factory

struct Entity* CreateBallChain(Coords32* c, struct Entity* e, u8 n);

static const struct Collision sCollisions[5];

static void Enemy21_Init(struct Enemy* p);
static void Enemy21_Update(struct Enemy* p);
static void Enemy21_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gHammerRoutine = {
    [ENTITY_INIT] =      (void*)Enemy21_Init,
    [ENTITY_UPDATE] =    (void*)Enemy21_Update,
    [ENTITY_DIE] =       (void*)Enemy21_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* unused_080752cc(Coords32* c, u8 n) {
  struct Entity* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HAMMER);
    p->coord = *c;
    p->work[0] = n, p->work[1] = 0;
  }
  return p;
}

static struct Enemy* FUN_0807532c(struct Entity* e, u8 n) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_HAMMER);
    (p->s).unk_28 = e;
    (p->s).work[0] = n, (p->s).work[1] = 1;
  }
  return p;
}

// --------------------------------------------

NAKED static void Enemy21_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #1\n\
	bne _08075474\n\
	adds r0, r5, #0\n\
	bl InitScalerotMotion1\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08075460 @ =0x0836705C\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	ldr r0, _08075464 @ =FUN_08075a5c\n\
	str r0, [r4, #0x24]\n\
	ldrb r0, [r5, #0x11]\n\
	cmp r0, #1\n\
	bne _08075474\n\
	ldr r0, [r5, #0x28]\n\
	ldr r1, [r0, #0x58]\n\
	ldr r0, [r0, #0x54]\n\
	str r0, [r5, #0x54]\n\
	str r1, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb8\n\
	strb r6, [r0]\n\
	str r6, [r5, #0x60]\n\
	adds r0, #8\n\
	movs r4, #0\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #5\n\
	str r0, [r5, #0x5c]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb5\n\
	strb r4, [r0]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, _08075468 @ =0xFFFFF800\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_0800a134\n\
	adds r1, r0, #0\n\
	movs r0, #0x98\n\
	lsls r0, r0, #7\n\
	adds r1, r1, r0\n\
	str r1, [r5, #0x58]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x64]\n\
	bl FUN_0800a134\n\
	str r0, [r5, #0x68]\n\
	adds r2, r5, #0\n\
	adds r2, #0xbc\n\
	ldr r1, [r5, #0x58]\n\
	subs r1, r1, r0\n\
	str r1, [r2]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	str r0, [sp]\n\
	str r1, [sp, #4]\n\
	ldr r0, [sp, #4]\n\
	ldr r1, _0807546C @ =0xFFFFF000\n\
	adds r0, r0, r1\n\
	str r0, [sp, #4]\n\
	mov r0, sp\n\
	adds r1, r5, #0\n\
	movs r2, #0\n\
	bl CreateBallChain\n\
	ldrb r2, [r5, #0x11]\n\
	cmp r2, #1\n\
	bne _08075474\n\
	ldr r1, _08075470 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r2, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	strb r2, [r5, #0xd]\n\
	strb r4, [r5, #0xe]\n\
	strb r4, [r5, #0xf]\n\
	b _08075498\n\
	.align 2, 0\n\
_08075460: .4byte sCollisions+24\n\
_08075464: .4byte FUN_08075a5c\n\
_08075468: .4byte 0xFFFFF800\n\
_0807546C: .4byte 0xFFFFF000\n\
_08075470: .4byte gEnemyFnTable\n\
_08075474:\n\
	ldrb r1, [r5, #0x10]\n\
	adds r0, r5, #0\n\
	bl FUN_0807532c\n\
	ldr r1, _080754A8 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	movs r1, #0\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	strb r1, [r5, #0xe]\n\
	strb r1, [r5, #0xf]\n\
_08075498:\n\
	adds r0, r5, #0\n\
	bl Enemy21_Update\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080754A8: .4byte gEnemyFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static bool8 FUN_080755e8(struct Enemy* p);
static bool8 FUN_08075628(struct Enemy* p);
bool8 FUN_080756e8(struct Enemy* p);
static bool8 FUN_080755f0(struct Enemy* p);

static void FUN_080755ec(struct Enemy* p);
void FUN_0807562c(struct Enemy* p);
void FUN_080756ec(struct Enemy* p);
static void FUN_080755f4(struct Enemy* p);
bool8 FUN_08075a30(struct Enemy* p);

static void Enemy21_Update(struct Enemy* p) {
  static const EnemyFunc sUpdates1[4] = {
      (EnemyFunc)FUN_080755e8,
      (EnemyFunc)FUN_08075628,
      (EnemyFunc)FUN_080756e8,
      (EnemyFunc)FUN_080755f0,
  };
  static const EnemyFunc sUpdates2[4] = {
      FUN_080755ec,
      FUN_0807562c,
      FUN_080756ec,
      FUN_080755f4,
  };

  if ((p->s).work[1] == 1) {
    if (((p->s).unk_28)->mode[0] == ENTITY_EXIT) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      return;
    }
    if ((p->body).status & BODY_STATUS_DEAD) {
      SET_ENEMY_ROUTINE(p, ENTITY_DIE);
      Enemy21_Die(p);
      return;
    }
    FUN_08075a30(p);
  }
  (sUpdates1[(p->s).mode[1]])((void*)p);
  (sUpdates2[(p->s).mode[1]])((void*)p);
}

// --------------------------------------------

static void Enemy21_Die(struct Enemy* p) {
  if ((p->s).work[1] == 1) {
    if (IS_METTAUR) {
      (p->s).flags &= ~DISPLAY;
      (p->s).flags &= ~FLIPABLE;
      EXIT_BODY(p);
      SET_ENEMY_ROUTINE(p, ENTITY_DISAPPEAR);
      return;
    }

    switch ((p->s).mode[2]) {
      case 0: {
        (p->s).mode[2] = 1;
        EXIT_BODY(p);
        FALLTHROUGH;
      }
      case 1: {
        (p->s).mode[2]++;
        return;
      }

      case 2: {
        break;
      }

      default: {
        return;
      }
    }
  }

  (p->s).flags &= ~DISPLAY;
  SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static bool8 FUN_080755e8(struct Enemy* p) { return TRUE; }

static void FUN_080755ec(struct Enemy* p) {
  // nop
  return;
}

static bool8 FUN_080755f0(struct Enemy* p) { return TRUE; }

static void FUN_080755f4(struct Enemy* p) {
  if ((p->s).mode[2] == 0) {
    (p->s).flags &= ~DISPLAY;
    EXIT_BODY(p);
    (p->s).mode[2]++;
  }
}

static bool8 FUN_08075628(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hammer_a.inc");

bool8 FUN_080756e8(struct Enemy* p) { return TRUE; }

INCASM("asm/enemy/hammer_b.inc");

bool8 FUN_08075a30(struct Enemy* p) {
  if ((p->body).status & BODY_STATUS_B3) {
    if ((s8)p->buffer[1] == 1) {
      (p->s).mode[1] = 2;
      (p->s).mode[2] = 0;
      p->buffer[1] = 0;
    }
  }
  return TRUE;
}

void FUN_08075a5c(struct Body* body) {
  const struct Collision* c = (body->enemy)->processing;
  if (c->special == 1) {
    if ((*(u32*)&c->atkType & 0x000200FF) == 0x00020002) {
      ((struct Enemy*)body->parent)->buffer[1] = 1;
    }
  }
}

struct Entity* FUN_080b9228(struct Coord* c, s32 a2);

bool8 FUN_08075a84(struct Enemy* p) {
  struct Coord c;
  c.x = (p->s).coord.x;
  c.y = (p->s).coord.y - PIXEL(16);
  FUN_080b9228(&c, 0);
  return TRUE;
}

// --------------------------------------------

// 0x08367044
static const struct Collision sCollisions[5] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      special : 0,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(0), PIXEL(30), PIXEL(22)},
    },
};
