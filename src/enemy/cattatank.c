#include "camera.h"
#include "collision.h"
#include "enemy.h"
#include "global.h"
#include "score.h"
#include "stagerun.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  u8 buffer[16];         // 0xB4
} Cattatank;
static_assert(sizeof(Cattatank) == sizeof(struct Enemy));

static void Cattatank_Init(Cattatank* p);
static void Cattatank_Update(Cattatank* p);
static void Cattatank_Die(Cattatank* p);

// clang-format off
const EnemyRoutine gCattatankRoutine = {
    [ENTITY_INIT] =      (void*)Cattatank_Init,
    [ENTITY_UPDATE] =    (void*)Cattatank_Update,
    [ENTITY_DIE] =       (void*)Cattatank_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

Cattatank* FUN_08098838(Coords32* c, u8 kind) {
  Cattatank* p = AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CATTATANK);
    p->coord = *c;
    p->work[0] = kind, p->work[1] = 1;
  }
  return p;
}

static void Cattatank_OnCollision(struct Body* body, Coords32* c1, Coords32* c2);

NAKED static void Cattatank_Init(Cattatank* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r0, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #0\n\
	mov r8, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r1, _08098910 @ =0x0836A4D8\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #8\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	ldr r0, _08098914 @ =Cattatank_OnCollision\n\
	str r0, [r4, #0x24]\n\
	adds r7, r6, #0\n\
	adds r7, #0xb8\n\
	strb r5, [r7]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbc\n\
	str r5, [r0]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _08098918\n\
	movs r5, #1\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	subs r4, #0x28\n\
	strb r5, [r4]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	movs r3, #0x10\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r3\n\
	strb r0, [r2]\n\
	strb r5, [r7]\n\
	adds r3, r2, #0\n\
	b _0809893A\n\
	.align 2, 0\n\
_08098910: .4byte sCollisions+(1*24)\n\
_08098914: .4byte Cattatank_OnCollision\n\
_08098918:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4c\n\
	strb r5, [r3]\n\
	adds r1, r6, #0\n\
	adds r1, #0x4a\n\
	ldrb r2, [r1]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	strb r5, [r7]\n\
	adds r4, r3, #0\n\
	adds r3, r1, #0\n\
_0809893A:\n\
	ldrb r5, [r6, #0x11]\n\
	cmp r5, #1\n\
	bne _080989A4\n\
	ldr r0, _08098968 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r6, #0x54]\n\
	cmp r1, r0\n\
	bge _0809896C\n\
	movs r2, #0\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r6, #0xa]\n\
	strb r2, [r4]\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3]\n\
	strb r2, [r7]\n\
	b _08098986\n\
	.align 2, 0\n\
_08098968: .4byte pZero2\n\
_0809896C:\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	strb r5, [r4]\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
	strb r5, [r7]\n\
_08098986:\n\
	ldr r1, _080989A0 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r6, #0xd]\n\
	b _080989BA\n\
	.align 2, 0\n\
_080989A0: .4byte gEnemyFnTable\n\
_080989A4:\n\
	ldr r1, _08098A00 @ =gEnemyFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	movs r0, #0\n\
	strb r1, [r6, #0xd]\n\
_080989BA:\n\
	strb r0, [r6, #0xe]\n\
	strb r0, [r6, #0xf]\n\
	movs r4, #0\n\
	str r4, [r6, #0x60]\n\
	str r4, [r6, #0x5c]\n\
	adds r0, r6, #0\n\
	adds r0, #0xbb\n\
	strb r4, [r0]\n\
	str r4, [r6, #0x5c]\n\
	adds r0, r6, #0\n\
	bl IsFrozen\n\
	cmp r0, #0\n\
	beq _080989E4\n\
	ldr r1, _08098A04 @ =0x0000D503\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	adds r0, r6, #0\n\
	bl UpdateEntityAnim\n\
_080989E4:\n\
	adds r0, r6, #0\n\
	adds r0, #0xc0\n\
	strb r4, [r0]\n\
	subs r0, #6\n\
	strb r4, [r0]\n\
	adds r0, r6, #0\n\
	bl Cattatank_Update\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08098A00: .4byte gEnemyFnTable\n\
_08098A04: .4byte 0x0000D503\n\
 .syntax divided\n");
}

void cattatank_08099e20(Cattatank* p);

bool8 nop_08099090(Cattatank* p);
bool8 nop_080990d4(Cattatank* p);
bool8 nop_0809925c(Cattatank* p);
bool8 nop_080994e8(Cattatank* p);
bool8 nop_0809973c(Cattatank* p);
bool8 nop_08099950(Cattatank* p);
bool8 nop_08099a94(Cattatank* p);
bool8 nop_08099ce0(Cattatank* p);
bool8 nop_08099d7c(Cattatank* p);
bool8 nop_08099d84(Cattatank* p);

void cattatank_08099094(Cattatank* p);
void FUN_080990d8(Cattatank* p);
void FUN_08099260(Cattatank* p);
void FUN_080994ec(Cattatank* p);
void FUN_08099740(Cattatank* p);
void FUN_08099954(Cattatank* p);
void FUN_08099a98(Cattatank* p);
void FUN_08099ce4(Cattatank* p);
void nop_08099d80(Cattatank* p);
void FUN_08099d88(Cattatank* p);

static void Cattatank_Update(Cattatank* p) {
  // clang-format off
  static bool8 (*const sUpdates1[10])(Cattatank*) = {
      nop_08099090,
      nop_080990d4,
      nop_0809925c,
      nop_080994e8,
      nop_0809973c,
      nop_08099950,
      nop_08099a94,
      nop_08099ce0,
      nop_08099d7c,
      nop_08099d84,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[10])(Cattatank*) = {
      cattatank_08099094,
      FUN_080990d8,
      FUN_08099260,
      FUN_080994ec,
      FUN_08099740,
      FUN_08099954,
      FUN_08099a98,
      FUN_08099ce4,
      nop_08099d80,
      FUN_08099d88,
  };
  // clang-format on

  u8 m;
  if ((p->body).status & BODY_STATUS_DEAD) {
    if (p->mode[1] == 6) {
      if (!IsFrozen(p)) {
        goto dispatch1;
      }
    }
    p->mode[3] = 0;
    SET_ENEMY_ROUTINE(p, ENTITY_DIE);
    Cattatank_Die(p);
    return;
  }
  if (Camera_GetDistance(&gStageRun.vm.camera, &p->coord) > 0x3000) {
    if (gStageRun.vm.camera.viewport.y + 0x4FFF < p->coord.y + 0x2000) {
      if (p->work[1] == 1) {
        p->mode[3] = 1;
        PlaySound(SE_ZAKO_EXPLODE);
        TryDropItem(1, &p->coord);
        if (gScore.enemyCount < 9999) gScore.enemyCount++;
        DropEnemyDisk(p, &p->coord);
        p->flags &= ~DISPLAY;
        SET_ENEMY_ROUTINE(p, ENTITY_EXIT);
        return;
      }
    }
  }
dispatch1:
  (sUpdates1[p->mode[1]])(p);
  cattatank_08099e20(p);
  m = p->mode[1];
  if (m == 6 || m == 7) goto dispatch2;
  if (m == 9) goto dispatch2;
  if (IsFrozen(p)) {
    return;
  }
dispatch2:
  (sUpdates2[p->mode[1]])(p);
}

NAKED static void Cattatank_Die(Cattatank* p) { INCCODE("asm/wip/Cattatank_Die.inc"); }

bool8 nop_08099090(Cattatank* _) { return TRUE; }

void cattatank_08099094(Cattatank* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags &= ~DISPLAY;
      p->work[2] = 50;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if (p->work[2] != 0) {
        if (--p->work[2] != 0) break;
      }
      p->mode[1] = 1;
      p->mode[2] = 0;
      break;
    }
  }
}

bool8 nop_080990d4(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_c.inc");

bool8 nop_0809925c(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_d.inc");

bool8 nop_080994e8(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_e.inc");

bool8 nop_0809973c(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_f.inc");

bool8 nop_08099950(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_g.inc");

bool8 nop_08099a94(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_h.inc");

bool8 nop_08099ce0(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_i.inc");

bool8 nop_08099d7c(Cattatank* _) { return TRUE; }

void nop_08099d80(Cattatank* p) {}

bool8 nop_08099d84(Cattatank* _) { return TRUE; }

INCASM("asm/enemy/cattatank_j.inc");

NAKED static void Cattatank_OnCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r2, r0, #0\n\
	adds r5, r1, #0\n\
	ldr r0, [r2, #0xc]\n\
	ldr r3, [r0, #4]\n\
	ldrb r0, [r3, #4]\n\
	cmp r0, #3\n\
	beq _08099ECC\n\
	cmp r0, #0xe\n\
	beq _08099ECC\n\
	cmp r0, #0xf\n\
	bne _08099EF6\n\
_08099ECC:\n\
	ldr r4, [r2, #0x2c]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08099EF6\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, [r5]\n\
	cmp r1, r0\n\
	bge _08099EEE\n\
	adds r1, r4, #0\n\
	adds r1, #0xba\n\
	movs r0, #0xff\n\
	b _08099EF4\n\
_08099EEE:\n\
	adds r1, r4, #0\n\
	adds r1, #0xba\n\
	movs r0, #0xfe\n\
_08099EF4:\n\
	strb r0, [r1]\n\
_08099EF6:\n\
	ldr r0, [r3, #4]\n\
	ldr r1, _08099F28 @ =0x000200FF\n\
	ands r0, r1\n\
	subs r1, #0xfd\n\
	cmp r0, r1\n\
	bne _08099F2C\n\
	ldr r4, [r2, #0x2c]\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #6\n\
	beq _08099F4E\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08099F20\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
_08099F20:\n\
	movs r1, #0\n\
	movs r0, #6\n\
	b _08099F4A\n\
	.align 2, 0\n\
_08099F28: .4byte 0x000200FF\n\
_08099F2C:\n\
	ldr r4, [r2, #0x2c]\n\
	ldr r0, [r2, #4]\n\
	ldrb r0, [r0]\n\
	cmp r0, #2\n\
	bne _08099F4E\n\
	ldrb r0, [r3, #6]\n\
	cmp r0, #0x40\n\
	beq _08099F4E\n\
	adds r0, r4, #0\n\
	bl IsFrozen\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _08099F4E\n\
	movs r0, #5\n\
_08099F4A:\n\
	strb r0, [r4, #0xd]\n\
	strb r1, [r4, #0xe]\n\
_08099F4E:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
   .syntax divided\n");
}

// --------------------------------------------

// 0x0836A4C0
static const struct Collision sCollisions[18] = {
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 0,
      priorityLayer : 0xFFFFFFFF,
      range : {PIXEL(0), PIXEL(11), PIXEL(30), PIXEL(22)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : METAL,
      remaining : 1,
      priorityLayer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP2,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(16), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(37), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 4,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(49), -PIXEL(21), PIXEL(14), PIXEL(14)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 4,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DDP,
      faction : FACTION_NEUTRAL,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
    {
      kind : DRP,
      faction : FACTION_NEUTRAL,
      LAYER(0xFFFFFFFF),
      hitzone : 1,
      remaining : 0,
      range : {-PIXEL(3), -PIXEL(19), PIXEL(27), PIXEL(40)},
    },
};

// 0x0836a670
static const Coords32 sElementCoords[1] = {
    {PIXEL(0), -PIXEL(18)},
};
