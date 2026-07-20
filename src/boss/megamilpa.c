#include "boss.h"
#include "collision.h"
#include "enemy/megamilpa_node.h"
#include "global.h"
#include "mod.h"
#include "stagerun.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  Coords32 c_b4;         // 0xB4
  u8 unk_bc;             // 0xBC
  u8 unk_bd;             // 0xBD
  u8 unk_be[2];          // 0xBE
  s32 unk_c0;            // 0xC0
  s32 unk_c4;            // 0xC4
  bool8 unk_c8;          // 0xC8
  u8 unk_c9[3];          // 0xC9
  u8 buffer[24];         // 0xCC
} Megamilpa;
static_assert(sizeof(Megamilpa) == sizeof(struct Boss));

static const s32 s32_ARRAY_08361abc[2];
static const u8 u8_ARRAY_08361ac4[2];
static const struct Collision gMegamilpaCoreHitbox;
static const u8 sMegamilpa_InitModes[4];

static void Megamilpa_Init(Megamilpa* p);
static void Megamilpa_Update(Megamilpa* p);
static void Megamilpa_Die(Megamilpa* p);

// clang-format off
const BossRoutine gMegamilpaRoutine = {
    [ENTITY_INIT] =      (void*)Megamilpa_Init,
    [ENTITY_UPDATE] =    (void*)Megamilpa_Update,
    [ENTITY_DIE] =       (void*)Megamilpa_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

static void Megamilpa_Init(Megamilpa* p) {
  SET_BOSS_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sMegamilpa_InitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  (p->c_b4).x = (p->coord).x >> 8;
  (p->c_b4).x = (((p->c_b4).x / 240) * PIXEL(240)) + PIXEL(120);
  (p->c_b4).y = FUN_08009f6c((p->coord).x, (p->coord).y) - PIXEL(4);
  (p->coord).x = (p->c_b4).x;
  (p->coord).y = (p->c_b4).y;
  p->unk_c0 = 0;
  p->unk_bd = 0xFF, p->unk_bc = 0;
  if (p->work[0] == 0) {
    s32 i;
    for (i = 0; i < 11; i++) {
      if (i != 5) {
        MegamilpaNode* node = CreateMegamilpaNode(i);
        node->parent = p;
      }
    }
    if (FLAG(gSystemSavedata.flags, MOD_MEGAMILPA)) {
      ResetBossBody((void*)p, &gMegamilpaCoreHitbox, 80);
    } else {
      ResetBossBody((void*)p, &gMegamilpaCoreHitbox, 64);
    }
    LOAD_STATIC_GRAPHIC(SM005_GRAVEL);
  }
  Megamilpa_Update(p);
}

// --------------------------------------------

static void nop_0803d6a0(void* _);

void FUN_0803d6a4(Megamilpa* p);
void FUN_0803d6fc(Megamilpa* p);
void FUN_0803d7a0(Megamilpa* p);
void FUN_0803d844(Megamilpa* p);
void FUN_0803dba0(Megamilpa* p);
void FUN_0803dc34(Megamilpa* p);

static void Megamilpa_Update(Megamilpa* p) {
  // clang-format off
  static void (*const sUpdates1[6])(void*) = {
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0, 
      nop_0803d6a0,
  };
  static void (*const sUpdates2[6])(Megamilpa*) = {
      FUN_0803d6a4, 
      FUN_0803d6fc, 
      FUN_0803d7a0, 
      FUN_0803d844, 
      FUN_0803dba0, 
      FUN_0803dc34,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    Megamilpa_Die(p);
    return;
  }

  (sUpdates1[p->mode[1]])(p);
  (sUpdates2[p->mode[1]])(p);
}

// --------------------------------------------

NAKED static void Megamilpa_Die(Megamilpa* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #4\n\
	bls _0803D348\n\
	b _0803D448\n\
_0803D348:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0803D354 @ =_0803D358\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0803D354: .4byte _0803D358\n\
_0803D358: @ jump table\n\
	.4byte _0803D36C @ case 0\n\
	.4byte _0803D3D0 @ case 1\n\
	.4byte _0803D410 @ case 2\n\
	.4byte _0803D422 @ case 3\n\
	.4byte _0803D448 @ case 4\n\
_0803D36C:\n\
	ldr r0, _0803D3BC @ =0x0000010D\n\
	bl StopSound\n\
	ldr r3, _0803D3C0 @ =gStageRun\n\
	ldrh r2, [r3, #8]\n\
	movs r4, #1\n\
	adds r0, r4, #0\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0803D394\n\
	ldrb r1, [r3, #0x12]\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803D394\n\
	ldr r0, _0803D3C4 @ =0x0000FFFE\n\
	ands r0, r2\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r3, #8]\n\
_0803D394:\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	movs r2, #0\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0xfb\n\
	ands r1, r0\n\
	strb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803D3C8\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #2\n\
	b _0803D446\n\
	.align 2, 0\n\
_0803D3BC: .4byte 0x0000010D\n\
_0803D3C0: .4byte gStageRun\n\
_0803D3C4: .4byte 0x0000FFFE\n\
_0803D3C8:\n\
	str r2, [r5, #0x60]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_0803D3D0:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r1, #0x20\n\
	str r1, [r5, #0x60]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	cmp r1, r0\n\
	ble _0803D3E6\n\
	str r0, [r5, #0x60]\n\
_0803D3E6:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _0803D448\n\
	movs r0, #0x2a\n\
	bl PlaySound\n\
	adds r4, r5, #0\n\
	adds r4, #0x54\n\
	movs r0, #1\n\
	adds r1, r4, #0\n\
	bl CreateSmoke\n\
	adds r0, r5, #0\n\
	adds r1, r4, #0\n\
	bl CreateGhost19_2\n\
	b _0803D442\n\
_0803D410:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r0, #0x78\n\
	strb r0, [r5, #0x12]\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xd]\n\
_0803D422:\n\
	ldrb r0, [r5, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803D448\n\
	ldr r2, _0803D450 @ =gStageRun\n\
	ldrb r0, [r2, #0x12]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x12]\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #9\n\
	bl TryDropItem\n\
_0803D442:\n\
	ldrb r0, [r5, #0xd]\n\
	adds r0, #1\n\
_0803D446:\n\
	strb r0, [r5, #0xd]\n\
_0803D448:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D450: .4byte gStageRun\n\
 .syntax divided\n");
}

// --------------------------------------------

NAKED static void FUN_0803d454(Megamilpa* p, u8 r1, u8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x14\n\
	adds r7, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	mov sl, r1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	str r2, [sp, #0x10]\n\
	cmp r1, #0\n\
	beq _0803D4C4\n\
	ldr r0, _0803D4B0 @ =0xFFFFFD80\n\
	mov sb, r0\n\
	str r0, [sp]\n\
	ldr r4, _0803D4B4 @ =RNG_0202f388\n\
	ldr r0, [r4]\n\
	ldr r1, _0803D4B8 @ =0x000343FD\n\
	mov r8, r1\n\
	mov r2, r8\n\
	muls r2, r0, r2\n\
	adds r0, r2, #0\n\
	ldr r6, _0803D4BC @ =0x00269EC3\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r5, r0, #1\n\
	str r5, [r4]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #3\n\
	bl __umodsi3\n\
	add r0, sb\n\
	str r0, [sp]\n\
	ldr r2, _0803D4C0 @ =0xFFFFFF00\n\
	mov r0, r8\n\
	muls r0, r5, r0\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r4]\n\
	b _0803D4EC\n\
	.align 2, 0\n\
_0803D4B0: .4byte 0xFFFFFD80\n\
_0803D4B4: .4byte RNG_0202f388\n\
_0803D4B8: .4byte 0x000343FD\n\
_0803D4BC: .4byte 0x00269EC3\n\
_0803D4C0: .4byte 0xFFFFFF00\n\
_0803D4C4:\n\
	ldr r5, _0803D518 @ =RNG_0202f388\n\
	ldr r0, [r5]\n\
	ldr r4, _0803D51C @ =0x000343FD\n\
	muls r0, r4, r0\n\
	ldr r3, _0803D520 @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsls r0, r0, #5\n\
	lsrs r0, r0, #0x16\n\
	ldr r2, _0803D524 @ =0xFFFFFE00\n\
	adds r0, r0, r2\n\
	str r0, [sp]\n\
	ldr r2, _0803D528 @ =0xFFFFFF00\n\
	adds r0, r1, #0\n\
	muls r0, r4, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r5]\n\
_0803D4EC:\n\
	lsls r0, r0, #6\n\
	lsrs r0, r0, #0x17\n\
	subs r2, r2, r0\n\
	str r2, [sp, #4]\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	ldr r2, [r1]\n\
	str r2, [sp, #8]\n\
	adds r0, r7, #0\n\
	adds r0, #0xbe\n\
	mov sb, r1\n\
	mov r8, r0\n\
	ldrb r3, [r0]\n\
	cmp sl, r3\n\
	beq _0803D530\n\
	ldr r0, _0803D52C @ =s32_ARRAY_08361abc\n\
	ldr r3, [sp, #0x10]\n\
	lsls r1, r3, #2\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	subs r0, r2, r0\n\
	b _0803D53C\n\
	.align 2, 0\n\
_0803D518: .4byte RNG_0202f388\n\
_0803D51C: .4byte 0x000343FD\n\
_0803D520: .4byte 0x00269EC3\n\
_0803D524: .4byte 0xFFFFFE00\n\
_0803D528: .4byte 0xFFFFFF00\n\
_0803D52C: .4byte s32_ARRAY_08361abc\n\
_0803D530:\n\
	ldr r0, _0803D58C @ =s32_ARRAY_08361abc\n\
	ldr r3, [sp, #0x10]\n\
	lsls r1, r3, #2\n\
	adds r0, r1, r0\n\
	ldr r0, [r0]\n\
	adds r0, r0, r2\n\
_0803D53C:\n\
	str r0, [sp, #8]\n\
	adds r6, r1, #0\n\
	ldr r2, [sp, #8]\n\
	ldr r0, _0803D590 @ =0xFFFFF000\n\
	adds r2, r2, r0\n\
	ldr r3, _0803D594 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _0803D598 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803D59C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsls r0, r0, #2\n\
	lsrs r0, r0, #0x13\n\
	adds r0, r0, r2\n\
	str r0, [sp, #8]\n\
	adds r5, r7, #0\n\
	adds r5, #0xb8\n\
	ldr r0, [r5]\n\
	add r4, sp, #8\n\
	str r0, [r4, #4]\n\
	adds r0, r4, #0\n\
	mov r1, sp\n\
	bl CreateGhost19_1\n\
	mov r2, sb\n\
	ldr r1, [r2]\n\
	str r1, [sp, #8]\n\
	mov r3, r8\n\
	ldrb r3, [r3]\n\
	cmp sl, r3\n\
	beq _0803D5A0\n\
	ldr r0, _0803D58C @ =s32_ARRAY_08361abc\n\
	adds r0, r6, r0\n\
	ldr r0, [r0]\n\
	subs r0, r1, r0\n\
	b _0803D5A8\n\
	.align 2, 0\n\
_0803D58C: .4byte s32_ARRAY_08361abc\n\
_0803D590: .4byte 0xFFFFF000\n\
_0803D594: .4byte RNG_0202f388\n\
_0803D598: .4byte 0x000343FD\n\
_0803D59C: .4byte 0x00269EC3\n\
_0803D5A0:\n\
	ldr r0, _0803D5EC @ =s32_ARRAY_08361abc\n\
	adds r0, r6, r0\n\
	ldr r0, [r0]\n\
	adds r0, r1, r0\n\
_0803D5A8:\n\
	str r0, [sp, #8]\n\
	ldr r2, [sp, #8]\n\
	ldr r0, _0803D5F0 @ =0xFFFFF000\n\
	adds r2, r2, r0\n\
	ldr r3, _0803D5F4 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _0803D5F8 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _0803D5FC @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsls r0, r0, #2\n\
	lsrs r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	str r2, [sp, #8]\n\
	ldr r0, [r5]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r4, #4]\n\
	movs r0, #3\n\
	adds r1, r4, #0\n\
	bl CreateSmoke\n\
	add sp, #0x14\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803D5EC: .4byte s32_ARRAY_08361abc\n\
_0803D5F0: .4byte 0xFFFFF000\n\
_0803D5F4: .4byte RNG_0202f388\n\
_0803D5F8: .4byte 0x000343FD\n\
_0803D5FC: .4byte 0x00269EC3\n\
 .syntax divided\n");
}

static void FUN_0803d600(Megamilpa* p) {
  bool8 cond1 = (p->unk_c4 < 120);
  bool8 cond2 = (p->unk_c4 > 196);

  if (cond1 || cond2) {
    if (!p->unk_c8) {
      PlaySound(SE_UNK_10d);
      p->unk_c8 = TRUE;
    }
  } else {
    if (p->unk_c8) {
      StopSound(SE_UNK_10d);
      p->unk_c8 = FALSE;
    }
  }

  p->unk_c4++;
  if ((p->unk_c4 & 3) == 0) {
    if (cond1) {
      FUN_0803d454(p, 0, 1);
      AppendQuake(3, &p->coord);
    }
    if (cond2) {
      FUN_0803d454(p, 1, 1);
      AppendQuake(3, &p->coord);
    }
  }
}

static void nop_0803d6a0(void* _) {}

void FUN_0803d6a4(Megamilpa* p) {
  switch (p->mode[2]) {
    case 0: {
      p->flags &= ~DISPLAY;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->scriptEntity)->flags & (1 << 0)) p->mode[2]++;
      break;
    }
    case 2: {
      if (!(gStageRun.vm.active & VM_ACTIVE)) p->mode[1] = 1, p->mode[2] = 0;
      break;
    }
  }
}

void FUN_0803d6fc(Megamilpa* p) {
  switch (p->mode[2]) {
    case 0: {
      p->work[2] = 60;
      SetDDP(&p->body, &gMegamilpaCoreHitbox);
      p->flags &= ~DISPLAY;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      p->work[2]--;
      if (p->work[2] == 0) {
        u8 val;
        do {
          val = u8_ARRAY_08361ac4[RANDOM(RNG_0202f388) & 1];
          if (val == p->unk_bd) {
            p->unk_bc++;
          } else {
            p->unk_bc = 0;
          }
        } while (p->unk_bc > 1);
        p->unk_bd = val;
        p->mode[1] = val, p->mode[2] = 0;
      }
      break;
    }
  }
}

void FUN_0803d7a0(Megamilpa* p) {
  switch (p->mode[2]) {
    case 0: {
      PlaySound(SE_UNK_10d);
      p->work[2] = 32;
      p->unk_be[0] = RANDOM(RNG_0202f388) & 1;
      p->unk_be[1] = RANDOM(RNG_0202f388) & 1;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((p->work[2] & 3) == 0) FUN_0803d454(p, 0, 0);
      if (p->work[2] > 0) {
        p->work[2]--;
      } else {
        p->unk_c0 |= 1;
        p->mode[1] = 3, p->mode[2] = 0;
      }
      AppendQuake(3, &p->coord);
      break;
    }
  }
}

INCASM("asm/boss/megamilpa.inc");

// --------------------------------------------

const struct Collision Collision_ARRAY_ARRAY_083619c8[3][3] = {
    // 0
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          damage : 4,
          remaining : 2,
          layer : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          remaining : 1,
          range : {0xF800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          remaining : 0,
          layer : 0xFFFFFFFF,
          range : {0x400, 0x0, 0xF00, 0x1400},
        },
    },

    // 1
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          damage : 4,
          remaining : 2,
          layer : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          remaining : 1,
          range : {0x0, 0x800, 0x1400, 0xB00},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          hardness : METAL,
          remaining : 0,
          layer : 0xFFFFFFFF,
          range : {0x0, 0xFC00, 0x1400, 0xF00},
        },
    },

    // 2
    {
        {
          kind : DDP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          damage : 4,
          remaining : 2,
          layer : 1,
          range : {0x0, 0x0, 0x1400, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          remaining : 1,
          range : {0x800, 0x0, 0xB00, 0x1400},
        },
        {
          kind : DRP,
          faction : FACTION_ENEMY,
          special : CS_BOSS,
          LAYER(0xFFFFFFFF),
          hitzone : 5,
          hardness : METAL,
          remaining : 0,
          layer : 0xFFFFFFFF,
          range : {0xFC00, 0x0, 0xF00, 0x1400},
        },
    },
};

static const struct Collision gMegamilpaCoreHitbox = {
  kind : DRP,
  faction : FACTION_ENEMY,
  special : CS_BOSS,
  LAYER(0xFFFFFFFF),
  hitzone : 0,
  remaining : 0,
  range : {PIXEL(4), PIXEL(0), PIXEL(8), PIXEL(16)},
};  // 0x08361AA0

static const u8 sMegamilpa_InitModes[4] = {0, 0, 0, 0};  // 0x08361AB8

static const s32 s32_ARRAY_08361abc[2] = {0x4800, 0x3000};

static const u8 u8_ARRAY_08361ac4[2] = {2, 4};

const motion_t gMegamilpaMotions[5] = {
    MOTION(DM160_MEGAMILPA, 12), MOTION(DM160_MEGAMILPA, 13), MOTION(DM160_MEGAMILPA, 14), MOTION(DM160_MEGAMILPA, 15), MOTION(DM160_MEGAMILPA, 16),
};

const u8 u8_ARRAY_08361ad0[5] = {0, 0, 3, 6, 6};  // 083619c8 のidx
