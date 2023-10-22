#include "collision.h"
#include "entity.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"
#include "zero.h"

static const struct Collision Collision_ARRAY_08370ea8[4];
static const struct Collision Collision_ARRAY_08370f08[4];
static const struct Collision Collision_ARRAY_08370f68[2];
static const struct Collision Collision_ARRAY_08370f98[2];
static const struct Collision Collision_ARRAY_08370fc8[3];

static const struct Rect Rect_08371014;
static const u8 sInitMode[4];

static void Solid23_Init(struct Solid* p);
static void Solid23_Update(struct Solid* p);
static void Solid23_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSolid23Routine = {
    [ENTITY_INIT] =      Solid23_Init,
    [ENTITY_UPDATE] =    Solid23_Update,
    [ENTITY_DIE] =       Solid23_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void onCollision(struct Body* _ UNUSED, struct Coord* r1, struct Coord* r2) { return; }

static void Solid23_Init(struct Solid* p) {
  SET_SOLID_ROUTINE(p, ENTITY_UPDATE);
  (p->s).mode[1] = sInitMode[(p->s).work[0]];
  (p->s).flags |= FLIPABLE;
  (p->s).flags |= DISPLAY;
  InitNonAffineMotion(&p->s);
  INIT_BODY(p, &Collision_ARRAY_08370ea8[0], 1, onCollision);
  (p->s).coord.y = SEA;
  Solid23_Update(p);
}

// --------------------------------------------

static void nop_080d8330(struct Solid* p);
static void FUN_080d8334(struct Solid* p);
static void FUN_080d83a4(struct Solid* p);
static void FUN_080d8460(struct Solid* p);
static void FUN_080d84e4(struct Solid* p);
static void FUN_080d85b4(struct Solid* p);

static void Solid23_Update(struct Solid* p) {
  // clang-format off
  static SolidFunc const sUpdates1[5] = {
    nop_080d8330,
    nop_080d8330,
    nop_080d8330,
    nop_080d8330,
    nop_080d8330,
  };
  // clang-format on
  // clang-format off
  static SolidFunc const sUpdates2[5] = {
    FUN_080d8334,
    FUN_080d83a4,
    FUN_080d8460,
    FUN_080d84e4,
    FUN_080d85b4,
  };
  // clang-format on
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void Solid23_Die(struct Solid* p) {
  (p->s).flags2 &= ~ENTITY_HAZARD;
  SET_SOLID_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

static void nop_080d8330(struct Solid* p) { return; }

static void FUN_080d8334(struct Solid* p) {
  s32 dy;
  switch ((p->s).mode[2]) {
    case 0: {
      SetDDP(&p->body, Collision_ARRAY_08370ea8);
      SetMotion(&p->s, MOTION(0x79, 0x02));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->body).status & BODY_STATUS_WHITE) {
        (p->s).mode[1] = 1;
        (p->s).mode[2] = 0;
      }
      UpdateMotionGraphic(&p->s);
      break;
    }
  }

  dy = SEA - (p->s).coord.y;
  if (dy < 0) {
    dy += 7;
  }
  (p->s).coord.y += (dy >> 3);
}

static void FUN_080d83a4(struct Solid* p) {
  s32 dy;
  switch ((p->s).mode[2]) {
    case 0: {
      SetDDP(&p->body, Collision_ARRAY_08370f08);
      (p->s).work[2] = 0x1e;
      SetMotion(&p->s, MOTION(0x79, 0x03));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
        (p->s).mode[2]++;
      }
      UpdateMotionGraphic(&p->s);
      break;
    }

    case 2: {
      SetDDP(&p->body, Collision_ARRAY_08370f68);
      SetMotion(&p->s, MOTION(0x79, 0x04));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }

  dy = SEA - (p->s).coord.y;
  if (dy < 0) {
    dy += 7;
  }
  (p->s).coord.y += (dy >> 3);
}

static void FUN_080d8460(struct Solid* p) {
  s32 dy;
  switch ((p->s).mode[2]) {
    case 0: {
      PlaySound(SE_SEA_LEVEL);
      SetMotion(&p->s, MOTION(0x79, 0x00));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateMotionGraphic(&p->s);
      if ((p->s).motion.cmdIdx > 3) {
        SetDDP(&p->body, Collision_ARRAY_08370f98);
      }
      if ((p->s).motion.state == MOTION_END) {
        (p->s).mode[1] = 3;
        (p->s).mode[2] = 0;
      }
      break;
    }
  }

  dy = SEA - (p->s).coord.y;
  if (dy < 0) {
    dy += 7;
  }
  (p->s).coord.y += (dy >> 3);
}

static void FUN_080d84e4(struct Solid* p) {
  s32 dy;
  switch ((p->s).mode[2]) {
    case 0: {
      SetDDP(&p->body, Collision_ARRAY_08370fc8);
      (p->s).work[2] = 0;
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      const bool8 ok = (pZero2->s).coord.y < ((p->s).coord.y - PIXEL(13));

      if (ok) {
        (p->s).flags2 |= ENTITY_HAZARD;
        (p->s).size = (struct Rect*)&Rect_08371014;
        (p->s).hazardAttr = 0x801;
      } else {
        (p->s).flags2 &= ~ENTITY_HAZARD;
      }

      if (((p->body).status & BODY_STATUS_B2) && ok) {
        (p->s).unk_coord.y = 0x400;
        (p->s).work[2] = 0;
      } else {
        (p->s).unk_coord.y = 0;
        (p->s).work[2]++;
        if ((p->s).work[2] >= 192) {
          (p->s).mode[1] = 4;
          (p->s).mode[2] = 0;
        }
      }
      dy = SEA + (p->s).unk_coord.y - (p->s).coord.y;
      if (dy < 0) {
        dy += 7;
      }
      (p->s).coord.y += (dy >> 3);
      UpdateMotionGraphic(&p->s);
      break;
    }
  }
}

NAKED static void FUN_080d85b4(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #1\n\
	beq _080D85F2\n\
	cmp r0, #1\n\
	bgt _080D85C8\n\
	cmp r0, #0\n\
	beq _080D85D2\n\
	b _080D8692\n\
_080D85C8:\n\
	cmp r0, #2\n\
	beq _080D862C\n\
	cmp r0, #3\n\
	beq _080D867C\n\
	b _080D8692\n\
_080D85D2:\n\
	ldrb r1, [r4, #0xb]\n\
	movs r0, #0xf7\n\
	ands r0, r1\n\
	strb r0, [r4, #0xb]\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080D8620 @ =Collision_ARRAY_08370f98\n\
	bl SetDDP\n\
	ldr r1, _080D8624 @ =0x00007901\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080D85F2:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x71\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	ble _080D8610\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080D8628 @ =Collision_ARRAY_08370f68\n\
	bl SetDDP\n\
_080D8610:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080D8692\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	b _080D8690\n\
	.align 2, 0\n\
_080D8620: .4byte Collision_ARRAY_08370f98\n\
_080D8624: .4byte 0x00007901\n\
_080D8628: .4byte Collision_ARRAY_08370f68\n\
_080D862C:\n\
	movs r2, #0\n\
	ldr r0, _080D8648 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, [r0, #0x54]\n\
	cmp r1, r0\n\
	bge _080D863C\n\
	movs r2, #1\n\
_080D863C:\n\
	cmp r2, #0\n\
	beq _080D864C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080D8652\n\
	.align 2, 0\n\
_080D8648: .4byte pZero2\n\
_080D864C:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080D8652:\n\
	strb r0, [r4, #0xa]\n\
	adds r1, r2, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r1, _080D86B0 @ =0x00007905\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_080D867C:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _080D8692\n\
	movs r0, #0\n\
	strb r0, [r4, #0xd]\n\
_080D8690:\n\
	strb r0, [r4, #0xe]\n\
_080D8692:\n\
	ldr r0, _080D86B4 @ =gOverworld\n\
	ldr r1, _080D86B8 @ =0x0002C00C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	cmp r0, #0\n\
	bge _080D86A4\n\
	adds r0, #7\n\
_080D86A4:\n\
	asrs r0, r0, #3\n\
	adds r0, r1, r0\n\
	str r0, [r4, #0x58]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080D86B0: .4byte 0x00007905\n\
_080D86B4: .4byte gOverworld\n\
_080D86B8: .4byte 0x0002C00C\n\
 .syntax divided\n");
}

static const struct Collision Collision_ARRAY_08370ea8[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0100, -0x1100, 0x2400, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x0300, 0x3900, 0x1100},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x2800, -0x1A00, 0x1300, 0x1100},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x2800, -0x1A00, 0x1300, 0x1100},
    },
};

static const struct Collision Collision_ARRAY_08370f08[4] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0100, -0x1100, 0x2400, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x0300, 0x3900, 0x1100},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1600, -0x1F00, 0x1300, 0x1100},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0x01,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-0x1600, -0x1F00, 0x1300, 0x1100},
    },
};

static const struct Collision Collision_ARRAY_08370f68[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0100, -0x1100, 0x2400, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0300, 0x3900, 0x1100},
    },
};

static const struct Collision Collision_ARRAY_08370f98[2] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0100, 0x1100, 0x2400, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, 0x0300, 0x3900, 0x1100},
    },
};

static const struct Collision Collision_ARRAY_08370fc8[3] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0100, 0x1100, 0x2400, 0x0D00},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0300, 0x3900, 0x1100},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      damage : 255,
      hitzone : 0x00,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0500, 0x3900, 0x1000},
    },
};

static const u8 sInitMode[4] = {0, 0, 0, 0};

static const struct Rect Rect_08371014 = {
    0x0000,
    -0x0500,
    0x3900,
    0x1000,
};
