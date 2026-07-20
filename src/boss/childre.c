#include "boss.h"
#include "collision.h"
#include "element.h"
#include "global.h"
#include "stagerun.h"
#include "vfx/bubble.h"
#include "vfx/necro.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;   // 0x00
  struct Entity* elfx;    // 0xB4, Element FX
  u32 unk_b8;             // 0xB8
  Coords32 unk_bc;        // 0xBC
  u8 unk_c4;              // 0xC4
  u8 unk_c5;              // 0xC5
  bool8 shouldTurnRight;  // 0xC6
  u8 unk_c7;              // 0xC7
  Coords32 unk_c8;        // 0xC8
  u8 unk_d0[20];          // 0xD0
} Childre;
static_assert(sizeof(Childre) == sizeof(Boss));

static const u8 sInitModes[4];
static const struct Collision sCollisions[];
static const Coords32 sChildre_ElfxOffsets;
static const motion_t s16_0836206c;

static void Childre_Init(Childre* p);
static void Childre_Update(Childre* p);
static void Childre_Die(Childre* p);

// clang-format off
const BossRoutine gChildreRoutine = {
    [ENTITY_INIT] =      (void*)Childre_Init,
    [ENTITY_UPDATE] =    (void*)Childre_Update,
    [ENTITY_DIE] =       (void*)Childre_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

NAKED void childre_08040428(Childre* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov ip, r0\n\
	ldr r0, _0804044C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	mov r2, ip\n\
	ldr r0, [r2, #0x54]\n\
	subs r3, r1, r0\n\
	cmp r3, #0\n\
	bge _0804043E\n\
	rsbs r3, r3, #0\n\
_0804043E:\n\
	mov r4, ip\n\
	adds r4, #0xc5\n\
	ldr r6, _08040450 @ =RNG_0202f388\n\
	mov r5, ip\n\
	adds r5, #0xc4\n\
	ldr r7, _08040454 @ =u8_ARRAY_0836205c\n\
	b _0804045E\n\
	.align 2, 0\n\
_0804044C: .4byte pZero2\n\
_08040450: .4byte RNG_0202f388\n\
_08040454: .4byte u8_ARRAY_0836205c\n\
_08040458:\n\
	ldrb r0, [r4]\n\
	cmp r0, #1\n\
	bls _080404B4\n\
_0804045E:\n\
	ldr r1, [r6]\n\
	ldr r0, _08040484 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08040488 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r6]\n\
	lsrs r1, r0, #0x11\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	adds r2, r1, #0\n\
	ldr r0, _0804048C @ =0x00004FFF\n\
	cmp r3, r0\n\
	bgt _08040494\n\
	ldr r0, _08040490 @ =u8_ARRAY_ARRAY_0836202c\n\
	adds r0, r1, r0\n\
	b _080404AC\n\
	.align 2, 0\n\
_08040484: .4byte 0x000343FD\n\
_08040488: .4byte 0x00269EC3\n\
_0804048C: .4byte 0x00004FFF\n\
_08040490: .4byte u8_ARRAY_ARRAY_0836202c\n\
_08040494:\n\
	ldr r0, _080404A0 @ =0x00008FFF\n\
	cmp r3, r0\n\
	bgt _080404A8\n\
	ldr r0, _080404A4 @ =u8_ARRAY_ARRAY_0836202c+16\n\
	adds r0, r1, r0\n\
	b _080404AC\n\
	.align 2, 0\n\
_080404A0: .4byte 0x00008FFF\n\
_080404A4: .4byte u8_ARRAY_ARRAY_0836202c+16\n\
_080404A8:\n\
	ldr r0, _080404C0 @ =u8_ARRAY_ARRAY_0836202c+32\n\
	adds r0, r2, r0\n\
_080404AC:\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	beq _08040458\n\
_080404B4:\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	bne _080404C4\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	b _080404C8\n\
	.align 2, 0\n\
_080404C0: .4byte u8_ARRAY_ARRAY_0836202c+32\n\
_080404C4:\n\
	movs r0, #0\n\
	strb r1, [r5]\n\
_080404C8:\n\
	strb r0, [r4]\n\
	adds r0, r1, r7\n\
	ldrb r0, [r0]\n\
	mov r2, ip\n\
	strb r0, [r2, #0xd]\n\
	cmp r1, #1\n\
	bhi _080404D8\n\
	strb r1, [r2, #0x12]\n\
_080404D8:\n\
	movs r0, #0\n\
	mov r1, ip\n\
	strb r0, [r1, #0xe]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

void Childre_OnCollision(struct Body* body, Coords32* c1, Coords32* c2) {
  Object* q = (Object*)body->enemy->parent;
  Childre* p = (Childre*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (p->unk_c8).x = (q->coord).x;
    (p->unk_c8).y = (q->coord).y;
    p->shouldTurnRight = (p->coord).x < (q->coord).x;
  }
}

static bool8 tryKillChildre(Childre* p) {
  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    PlaySound(SE_CHILDRE_DEATH);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if ((p->body).status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    Childre_Die(p);
    return TRUE;
  }

  return FALSE;
}

// --------------------------------------------

static void Childre_Init(Childre* p) {
  struct Body* body;
  s32 y;
  void* fn;

  // TODO: Kill them all
#if MODERN == 0
  register u32 r0 asm("r0");
  register u8 r1 asm("r1");
  register u8* r2 asm("r2");
#endif

  SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  ResetBossBody((void*)p, &sCollisions[0], 64);
  fn = Childre_OnCollision;
  body = &p->body;
  body->fn = fn;

  if (p->work[0] == 0) {
    LOAD_STATIC_GRAPHIC(SM036_UNK);
    LOAD_STATIC_GRAPHIC(SM037_EAR_SHOT);
    LOAD_STATIC_GRAPHIC(SM038_UNK);
    p->elfx = NULL;

    y = FUN_08009f6c(p->coord.x, p->coord.y);
    p->coord.y = y;
    p->unk_bc.y = y;

    p->unk_bc.x = (((p->coord).x / PIXEL(240)) * PIXEL(240)) + PIXEL(120);

#if MODERN
    p->unk_c4 = 0xFF;
#else
    r2 = &p->unk_c4;
    r0 = *r2;
    r1 = 0xFF;
    r0 |= r1;
    *r2 = r0;
#endif
    p->unk_c5 = 0;
  }
  Childre_Update(p);
}

void childreNeutral(Childre* p);
static void nop_08040788(Childre* p);

void childreMode0(Childre* p);
void childreMode1(Childre* p);
void childreMode2(Childre* p);
void childreMode3(Childre* p);
void childreStartRising(Childre* p);
void childreRising(Childre* p);
void childreMode6(Childre* p);
void childreMode7(Childre* p);
void childreMode8(Childre* p);
void childreStartScrewIce(Childre* p);
void childreMaybeMiddleScrewIce(Childre* p);
void childreScrewIce(Childre* p);
void childreMissile(Childre* p);
void childreStartEarShot(Childre* p);
void childreEarShot(Childre* p);
void childreEndEarShot(Childre* p);
void childreMode16(Childre* p);
void childreStun(Childre* p);
void childreMode18(Childre* p);

static void Childre_Update(Childre* p) {
  // clang-format off
  static void (*const sUpdates1[19])(Childre*) = {
      childreNeutral,
      nop_08040788,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      childreNeutral,
      nop_08040788,
      nop_08040788,
      nop_08040788,
  };
  // clang-format on

  // clang-format off
  static void (*const sUpdates2[19])(Childre*) = {
      childreMode0,
      childreMode1,
      childreMode2,
      childreMode3,
      childreStartRising,
      childreRising,
      childreMode6,
      childreMode7,
      childreMode8,
      childreStartScrewIce,
      childreMaybeMiddleScrewIce,
      childreScrewIce,
      childreMissile,
      childreStartEarShot,
      childreEarShot,
      childreEndEarShot,
      childreMode16,
      childreStun,
      childreMode18,
  };
  // clang-format on

  if ((p->elfx != NULL) && isKilled(p->elfx)) {
    p->elfx = NULL;
  }
  if (!tryKillChildre(p)) {
    (sUpdates1[p->mode[1]])(p);
    (sUpdates2[p->mode[1]])(p);
  }
}

void childre_08042140(Childre* p);
void childre_08042224(Childre* p);

static void Childre_Die(Childre* p) {
  static void (*const sDeads[2])(Childre*) = {
      childre_08042140,
      childre_08042224,
  };
  (sDeads[p->mode[1]])(p);
}

// --------------------------------------------

static void nop_08040788(Childre* _) {}

void childreNeutral(Childre* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      if (p->mode[1] == 5) {
        {
          // (p->coord).x = (p->flags & X_FLIP) ? (p->coord).x - PIXEL(8) : (p->coord).x + PIXEL(8);
          s32 prev = (p->coord).x;
          s32 x = (p->coord).x = prev + PIXEL(8);
          if (p->flags & X_FLIP) x = prev - PIXEL(8);
          (p->coord).x = x;
        }
        (p->coord).y += PIXEL(8);
      }
      p->mode[1] = 18, p->mode[2] = 0;
    }
    if ((p->body).elemented == ELEMENT_FLAME) {
      if (((p->coord).y - PIXEL(16)) > gOverworld.sea) {
        s32 i;
        for (i = 0; i < 5; i++) {
          if ((RANDOM(RNG_0202f388) & 1) == 0) {
            s32 x = (p->coord).x - PIXEL(16) + (RANDOM(RNG_0202f388) & 0x1FFF);
            s32 y = (p->coord).y - PIXEL(16) + (RANDOM(RNG_0202f388) & 0x1FFF);
            CreateBubble(x, y, 0);
          } else {
            s32 x = (p->coord).x - PIXEL(16) + (RANDOM(RNG_0202f388) & 0x1FFF);
            s32 y = (p->coord).y - PIXEL(16) + (RANDOM(RNG_0202f388) & 0x1FFF);
            CreateBubble(x, y, 1);
          }
        }
      } else {
        p->elfx = ApplyElementEffect(10, (Object*)p, &sChildre_ElfxOffsets);
      }
      p->mode[1] = 17, p->mode[2] = 0;
    }
  }
}

void childreMode0(Childre* p) {
  switch (p->mode[2]) {
    case 0: {
      bool32 isPlayerRight;
      (p->coord).y = (p->unk_bc).y;
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 0;
      isPlayerRight = (pZero2->s).coord.x - (p->coord).x < 0;
      if (p->flags & X_FLIP) {
        if (!isPlayerRight) {
          goto _MODE2;
        }
      } else {
        if (isPlayerRight) {
        _MODE2:
          p->mode[2] += 2;
          break;
        }
      }

      PlaySound(SE_UNK_67);
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 8));
      (p->d).y = -PIXEL(2);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      s32 dy;
      (p->d).y += PIXEL(1) / 4;
      if ((p->d).y > PIXEL(7)) (p->d).y = PIXEL(7);
      (p->coord).y += (p->d).y;
      dy = (p->unk_bc).y - (p->coord).y;
      if (dy < 0) (p->coord).y += dy;
      UpdateSpriteAnimation(p);
      if (IsSpriteAnimEnd(p)) {
        p->work[2] = 1;
        p->mode[2]++;
      }
      break;
    }
    case 2: {
      if (p->work[2] != 0) SET_PLAYER_XFLIP(p, !(p->flags & X_FLIP));
      SetDDP(&p->body, &sCollisions[1]);
      p->work[2] = 32;
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      p->work[2]--;
      if (p->work[2] == 0) {
        if (!((pZero2->body).status & BODY_STATUS_DEAD) && ((pZero2->body).hp != 0)) {
          childre_08040428(p);
        }
      }
      UpdateSpriteAnimation(p);
      break;
    }
  }
}

// 0x08040A58
WIP void childreMode1(Childre* p) {
#ifdef ALWAYS_FALSE
  switch (p->mode[2]) {
    case 0: {
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      UpdateSpriteAnimation(p);
      if ((p->scriptEntity)->flags & (1 << 0)) p->mode[2]++;
      break;
    }
    case 2: {
      PlaySound(SE_CHILDRE_VOICE_1);
      p->work[2] = 4;
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 27));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 3: {
      UpdateSpriteAnimation(p);
      if (--(p->work[2]) == 0) p->mode[2]++;
      break;
    }
    case 4: {
      PlaySound(SE_UNK_67);
      (p->d).y = -PIXEL(2);
      p->work[2] = 0;
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 28));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 5: {
      s32 dy;
      (p->d).y += PIXEL(1) / 4;
      if ((p->d).y > PIXEL(7)) (p->d).y = PIXEL(7);
      (p->coord).y += (p->d).y;
      if (p->work[2] == 0 && (p->d).y > 0) {
        p->work[2] = 1;
        SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 29));
      }
      dy = (p->unk_bc).y - (p->coord).y;
      if (dy < 0 && (p->d).y > 0) {
        (p->coord).y += dy;
        p->mode[2]++;
      }
      UpdateSpriteAnimation(p);
      break;
    }
    case 6: {
      p->work[2] = 4;
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 27));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 7: {
      UpdateSpriteAnimation(p);
      if (--(p->work[2]) == 0) p->mode[2]++;
      break;
    }
    case 8: {
      p->work[2] = 0;
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 25));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 9: {
      s8 i;
      UpdateSpriteAnimation(p);
      p->work[2]++;
      if (p->work[2] == 5) PlaySound(SE_UNK_66);
      i = p->work[2] % 5;
      if (i == 0) {
        if ((p->motion).cmdIdx == 1 || (p->motion).cmdIdx == 4 || (p->motion).cmdIdx == 5) {
          Coords32 c = {(p->coord).x + PIXEL(3), (p->coord).y - PIXEL(20)};
          Coords32 d = {PIXEL(1), -0x55 - (RANDOM(RNG_0202f388) & 0xFF)};
          FUN_080b834c((void*)p, &c, &d, 0, (motion_t*)&s16_0836206c, 24);
          c.x = (p->coord).x - PIXEL(8), c.y = (p->coord).y - PIXEL(20);
          d.x = -PIXEL(3) / 8, d.y = -0x20 - (RANDOM(RNG_0202f388) & 0xFF);
          FUN_080b8454((void*)p, &c, &d, 0, (motion_t*)&s16_0836206c, 24, 25);
        }
      }
      if (IsSpriteAnimEnd(p)) p->mode[2]++;
      break;
    }
    case 10: {
      SetSpriteAnimation(p, MOTION(DM164_CHILDRE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 11: {
      UpdateSpriteAnimation(p);
      if (!(gStageRun.vm.active & VM_ACTIVE)) p->mode[1] = 0, p->mode[2] = 0;
      break;
    }
  }
#else
  INCCODE("asm/wip/childreMode1.inc");
#endif
}

INCASM("asm/boss/childre.inc");

// --------------------------------------------

// 0x08361eac
static const struct Collision sCollisions[16] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x00,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x0800, 0x0800},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [2] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [3] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, 0x0000, 0x1300, 0x1500},
    },
    [4] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, 0x0000, 0x1300, 0x1500},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 4,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1200, 0x1000, 0x3800},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x2600, 0x1200, 0x1800},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {0x0000, -0x1200, 0x1000, 0x3800},
    },
    [8] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x2600, 0x1200, 0x1800},
    },
    [9] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x1000, -0x0E00, 0x3000, 0x0E00},
    },
    [11] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [12] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 3,
      layer : 0x00000001,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 2,
      layer : 0x00000001,
      range : {-0x2200, -0x0B00, 0x5200, 0x0E00},
    },
    [14] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      hitzone : 0x00,
      remaining : 1,
      layer : 0x00000001,
      range : {-0x0E00, -0x0C00, 0x2B00, 0x2200},
    },
    [15] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 0x08,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {0x0000, -0x0D00, 0x1400, 0x1A00},
    },
};

const u8 u8_ARRAY_ARRAY_0836202c[3][16] = {
    {0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3},
    {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3},
    {0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3},
};

const u8 u8_ARRAY_0836205c[4] = {2, 2, 12, 13};

static const u8 sInitModes[4] = {1, 16, 0, 0};

static const Coords32 sChildre_ElfxOffsets = {PIXEL(0), -PIXEL(16)};

static const motion_t s16_0836206c = MOTION(SM038_UNK, 1);

// clang-format off
const motion_t sChildreAnimations[6] = {
    MOTION(DM164_CHILDRE, 16),
    MOTION(DM164_CHILDRE, 17),
    MOTION(DM164_CHILDRE, 17),
    MOTION(DM164_CHILDRE, 17),
    MOTION(DM164_CHILDRE, 17),
    MOTION(DM164_CHILDRE, 18),
}; // 0x0836206E
// clang-format on

static const Coords32 sChildre_ExplosionOffsets[2] = {
    {PIXEL(2), -PIXEL(24)},
    {PIXEL(6), -PIXEL(25)},
};  // 0x0836207C
