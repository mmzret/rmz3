#include "collision.h"
#include "gfx.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "physics.h"

// 2Dドア(青色)

static const struct Collision sCollisions[2];

static void Door2DBlue_Init(struct Solid* p);
static void Door2DBlue_Update(struct Solid* p);
static void Door2DBlue_Die(struct Solid* p);

// clang-format off
const SolidRoutine gDoor2DBlueRoutine = {
    [ENTITY_INIT] =      (void*)Door2DBlue_Init,
    [ENTITY_UPDATE] =    (void*)Door2DBlue_Update,
    [ENTITY_DIE] =       (void*)Door2DBlue_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NON_MATCH static void Door2DBlue_Init(struct Solid* p) {
#if MODERN
  EnableSpriteAnimation_Normal(p);
  if ((p->s).work[1] == 0) {
    // Otherside
    struct Entity* q = (struct Entity*)AllocEntityLast(gSolidHeaderPtr);
    if (q == NULL) {
      return;
    }
    (p->s).coord.x += PIXEL(8);
    (p->s).coord.y += PIXEL(9);
    INIT_SOLID_ROUTINE(q, SOLID_DOOR_2D_BLUE);
    q->work[1] = 1;
    q->unk_28 = (void*)p;
    (q->coord).x = (p->s).coord.x - PIXEL(1);
    (q->coord).y = (p->s).coord.y;
    if ((gOverworld.terrain.id & 0x7F) == STAGE_OCEAN) wStaticMotionPalIDs[SM018_DOOR_2D_BLUE] = 10;
    LOAD_STATIC_GRAPHIC(SM018_DOOR_2D_BLUE);
  } else {
    SetSpriteAnimation(p, MOTION(SM018_DOOR_2D_BLUE, 0));
    SET_XFLIP(p, TRUE);
  }

  (p->s).spr.oam.priority = 1;
  (p->s).flags |= DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = 0, (p->s).mode[2] = 0;
  Door2DBlue_Update(p);
#else
  INCCODE("asm/wip/Door2DBlue_Init.inc");
#endif
}

// --------------------------------------------

static void FUN_080caf7c(struct Solid* p);
void FUN_080cafd0(struct Solid* p);
void FUN_080cb160(struct Solid* p);
void FUN_080cb2f8(struct Solid* p);

static void Door2DBlue_Update(struct Solid* p) {
  static const SolidFunc sUpdates[4] = {
      FUN_080caf7c,
      FUN_080cafd0,
      FUN_080cb160,
      FUN_080cb2f8,
  };

  if ((p->s).work[1] != 0) {
    struct Entity* friend = (p->s).unk_28;
    if (friend->mode[0] >= 2) {
      SET_SOLID_ROUTINE(p, ENTITY_DIE);
      Door2DBlue_Die(p);
    } else {
      (p->s).spr.sprites = (friend->spr).sprites;
      (p->s).spr.spriteIdx = (friend->spr).spriteIdx;
    }
    return;
  }
  (sUpdates[(p->s).mode[1]])((void*)p);
}

static void Door2DBlue_Die(struct Solid* p) {
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r3, [r0, #0x2c]\n\
	ldr r0, [r0, #0xc]\n\
	ldr r5, [r0, #0x2c]\n\
	movs r0, #8\n\
	ldrsb r0, [r5, r0]\n\
	cmp r0, #0\n\
	bne _080CAF6E\n\
	ldr r0, [r3, #0x58]\n\
	ldr r1, [r5, #0x58]\n\
	cmp r0, r1\n\
	blt _080CAF6E\n\
	subs r1, r0, r1\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	bgt _080CAF6E\n\
	ldrb r2, [r3, #0x10]\n\
	movs r6, #2\n\
	adds r0, r6, #0\n\
	ands r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0\n\
	beq _080CAF36\n\
	ldr r0, _080CAF2C @ =gCurStory\n\
	ldrb r1, [r0, #4]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	bne _080CAF6E\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080CAF30\n\
	movs r0, #1\n\
	strb r0, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080CAF58\n\
	.align 2, 0\n\
_080CAF2C: .4byte gCurStory\n\
_080CAF30:\n\
	strb r6, [r3, #0xd]\n\
	strb r2, [r3, #0xe]\n\
	b _080CAF58\n\
_080CAF36:\n\
	ldr r1, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080CAF4C\n\
	movs r1, #1\n\
	adds r0, r1, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080CAF6E\n\
	strb r1, [r3, #0xd]\n\
	b _080CAF56\n\
_080CAF4C:\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080CAF6E\n\
	strb r6, [r3, #0xd]\n\
_080CAF56:\n\
	strb r4, [r3, #0xe]\n\
_080CAF58:\n\
	ldr r0, _080CAF74 @ =0x00000119\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _080CAF78 @ =gStageRun\n\
	ldrh r1, [r2, #0x14]\n\
	orrs r0, r1\n\
	strh r0, [r2, #0x14]\n\
	adds r0, r3, #0\n\
	adds r0, #0xb4\n\
	str r5, [r0]\n\
_080CAF6E:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CAF74: .4byte 0x00000119\n\
_080CAF78: .4byte gStageRun\n\
 .syntax divided\n");
}

static void FUN_080caf7c(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(SM018_DOOR_2D_BLUE, 0));
      INIT_BODY(p, &sCollisions[0], 0, onCollision);
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

void FUN_080cafd0(struct Solid* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->body).status = 0;
      (p->body).prevStatus = 0;
      (p->body).invincibleTime = 0;
      (p->s).flags &= 0xFB;
      (p->s).flags2 &= 0xF7;
      SetMotion(&p->s, 0x1202);
      PlaySound(0x9E);
      {
        s32* tp = (s32*)((u8*)p + 0xbc);
        struct Entity* volatile* pb = (struct Entity**)((u8*)p + 0xb4);
        tp[0] = (*pb)->coord.x + 0x3800;
        tp[1] = (*pb)->coord.y;
      }
      (p->s).work[2] = 0x40;
      (p->s).mode[2]++;
      break;
    }
    case 1: {
      u32 g = (u8)((p->s).work[0] & 2);
      if (g == 0) {
        gCollisionManager.sweep = g;
      }
      (p->s).mode[2]++;
    }
      // fallthrough
    case 2: {
      struct Entity* volatile* pb = (struct Entity**)((u8*)p + 0xb4);
      (*pb)->spr.xflip = 1;
      *((u8*)(*pb) + 0x4a) |= 0x10;
      (*pb)->flags |= 0x10;
      UpdateEntityAnim(&p->s);
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      (p->s).work[2] = 0x38;
      (p->s).mode[2]++;
      break;
    }
    case 3: {
      UpdateEntityAnim(&p->s);
      (*(struct Entity**)((u8*)p + 0xb4))->coord.x += 0x100;
      if ((p->s).work[2] == 0x1C) {
        u8* cam = (u8*)&gStageRun + 0xE8;
        *(s32**)(cam + 0x48) = (s32*)((u8*)p + 0xbc);
      }
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      PlaySound(0x9F);
      SetMotion(&p->s, 0x1203);
      (p->s).work[2] = 0x20;
      (p->s).mode[2]++;
      break;
    }
    case 4: {
      struct Entity* volatile* pb;
      UpdateEntityAnim(&p->s);
      {
        s32 t = (p->s).work[2] - 1;
        (p->s).work[2] = t;
        if ((t << 24) != 0) {
          break;
        }
      }
      pb = (struct Entity**)((u8*)p + 0xb4);
      {
        struct Entity* e = *pb;
        if (GetGroundMetatileAttr(e->coord.x, e->coord.y)) {
          struct Entity* e2 = *pb;
          s32 ny = FUN_0800a05c(e2->coord.x, e2->coord.y);
          (*pb)->coord.y = ny;
        }
      }
      {
        u8* g = (u8*)&gStageRun;
        struct Entity* z3;
        u16 h = *(u16*)(g + 0x14);
        s32 v = 0xFFFE;
        s32 zz;
        v &= h;
        asm("mov %0, #0" : "=l"(zz));
        *(u16*)(g + 0x14) = v;
        {
          u8* cam = g + 0xE8;
          z3 = *pb;
          *(s32**)(cam + 0x48) = (s32*)&z3->coord;
        }
        *((u8*)z3 + 0x119) = zz;
        (p->s).mode[1] = 3;
        (p->s).mode[2] = zz;
      }
      break;
    }
  }
}

INCASM("asm/solid/unk_02_a.inc");

// --------------------------------------------

static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      atkType : 0x00,
      nature : BODY_NATURE_B7,
      comboLv : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x2000, 0x2200, 0x4200},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      damage : 255,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0000, 0x0000},
    },
};
