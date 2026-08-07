#include "boss.h"
#include "collision.h"
#include "element.h"
#include "global.h"
#include "enemy.h"
#include "overworld.h"
#include "zero.h"
#include "script.h"

struct Enemy* createGlacierleAtkHand(struct Entity* e);
struct Enemy* createGlacierleJoint(struct Entity* e, struct Entity* parent);
void FUN_080823a4(struct Entity* e, struct Entity* parent, s32 x, s32 y);
void FUN_08082484(struct Enemy* p, s32 dx, s32 dy);
u32 FUN_080823ec(struct Enemy* p);
u8 glacierle_08082598(struct Enemy* p, u8 n);
void FUN_08082348(struct Entity* e);
s32 FUN_0800a134(s32 x, s32 y);
struct Enemy* createGlacierleSucker(struct Entity* e, struct Entity* parent);
void FUN_0808288c(struct Enemy* p, u8 a);
void FUN_080aa5e8(s32 x, s32 y);
void FUN_0808242c(struct Enemy* p, s32 a, s32 b);
void FUN_08082348(struct Entity* e);
s32 PushoutToUp1(s32 x, s32 y);
s32 PushoutToDown1(s32 x, s32 y);
struct Entity* CreateBossExplosion(struct Entity* boss, struct Coord* c);

struct Glacierle {
  COLLISION_OBJECT_HDR;  // 0x00
  u32 unk_b4;            // 0xB4
  struct Entity* elfx;   // 0xB8, Element Effect
  s32 unk_bc;            // 0xBC
  u8 unk_c0;             // 0xC0
  u8 unk_c1;             // 0xC1
  bool8 shouldRightDir;  // 0xC2
  u8 unk_c3[5];          // 0xC3
  Coords32 unk_c8;       // 0xC8
  u8 unk_d0[20];         // 0xD0
};
static_assert(sizeof(struct Glacierle) == sizeof(struct Boss));

void CreateSolidGlacierleArm(struct Entity* e, s32 x, s32 y);

static const u8 u8_ARRAY_08364aac[2];
static const struct Collision sCollisions[];
static const Coords32 sElementCoord;
static const u8 sGlacierleModes[48];
static const Coords16 ALIGNED(2) Coord16_ARRAY_08364ac6[2];

NAKED static void Glacierle_Init(struct Boss* p);
static void Glacierle_Update(struct Glacierle* p);
static void Glacierle_Die(struct Boss* p);

// clang-format off
const BossRoutine gGlacierleRoutine = {
    [ENTITY_INIT] =      (void*)Glacierle_Init,
    [ENTITY_UPDATE] =    (void*)Glacierle_Update,
    [ENTITY_DIE] =       (void*)Glacierle_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on


static const Coords32 sExplosionCoords[2];
static const u8 u8_ARRAY_08364ab1[8];
static const u8 u8_ARRAY_08364ab9[3];
static const u8 u8_ARRAY_08364abc[3];
static const u8 u8_ARRAY_08364abf[3];
static const u8 u8_ARRAY_08364ac2[4];
static const u8 u8_ARRAY_08364ace[5];
static const u8 u8_ARRAY_08364ad3[5];
static const u8 u8_ARRAY_08364b22[4];
NAKED static void calcNextGlacierleAction(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	mov ip, r0\n\
	ldr r0, _08057990 @ =pZero2\n\
	ldr r0, [r0]\n\
	mov r2, ip\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, [r0, #0x54]\n\
	subs r1, r1, r0\n\
	cmp r1, #0\n\
	bge _08057986\n\
	rsbs r1, r1, #0\n\
_08057986:\n\
	ldr r0, _08057994 @ =0x00005FFF\n\
	cmp r1, r0\n\
	bgt _08057998\n\
	movs r1, #0\n\
	b _080579AA\n\
	.align 2, 0\n\
_08057990: .4byte pZero2\n\
_08057994: .4byte 0x00005FFF\n\
_08057998:\n\
	ldr r0, _080579A4 @ =0x0000AFFF\n\
	cmp r1, r0\n\
	bgt _080579A8\n\
	movs r1, #1\n\
	b _080579AA\n\
	.align 2, 0\n\
_080579A4: .4byte 0x0000AFFF\n\
_080579A8:\n\
	movs r1, #2\n\
_080579AA:\n\
	ldr r7, _080579BC @ =RNG_0202f388\n\
	mov r5, ip\n\
	adds r5, #0xc0\n\
	ldr r0, _080579C0 @ =0x08364A7C\n\
	mov r8, r0\n\
	lsls r6, r1, #4\n\
	mov r4, ip\n\
	adds r4, #0xc1\n\
	b _080579CE\n\
	.align 2, 0\n\
_080579BC: .4byte RNG_0202f388\n\
_080579C0: .4byte sGlacierleModes\n\
_080579C4:\n\
	ldr r0, _08057A0C @ =gScore\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #4\n\
	bhi _080579FA\n\
_080579CE:\n\
	ldr r1, [r7]\n\
	ldr r0, _08057A10 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08057A14 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r7]\n\
	lsrs r3, r0, #0x11\n\
	movs r0, #0xf\n\
	ands r3, r0\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r5]\n\
	ldrb r2, [r0]\n\
	cmp r1, r2\n\
	bne _080579F6\n\
	ldrb r0, [r4]\n\
	cmp r0, #0\n\
	bne _080579CE\n\
_080579F6:\n\
	cmp r2, #0xf\n\
	beq _080579C4\n\
_080579FA:\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r1, [r0]\n\
	ldrb r0, [r5]\n\
	cmp r0, r1\n\
	bne _08057A18\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	b _08057A1C\n\
	.align 2, 0\n\
_08057A0C: .4byte gScore\n\
_08057A10: .4byte 0x000343FD\n\
_08057A14: .4byte 0x00269EC3\n\
_08057A18:\n\
	movs r0, #0\n\
	strb r1, [r5]\n\
_08057A1C:\n\
	strb r0, [r4]\n\
	adds r0, r3, r6\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	movs r1, #0\n\
	mov r2, ip\n\
	strb r0, [r2, #0xd]\n\
	strb r1, [r2, #0xe]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
 .syntax divided\n");
}

static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  struct Entity* q = (struct Entity*)body->enemy->parent;
  struct Glacierle* p = (struct Glacierle*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (p->unk_c8).x = (q->coord).x;
    (p->unk_c8).y = (q->coord).y;
    p->shouldRightDir = (p->coord).x < (q->coord).x;
  }
}

static bool8 tryKillGlacierle(struct Boss* p) {
  u32* status = &(p->body).status;

  if (((*status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    PlaySound(SE_GLACIERLE_DEATH);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if (*status & BODY_STATUS_SLASHED) {
      p->mode[1] = 1;
    } else {
      p->mode[1] = 0;
    }
    Glacierle_Die(p);
    return TRUE;
  }

  return FALSE;
}

// --------------------------------------------

NAKED static void Glacierle_Init(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	ldr r1, _08057C64 @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	mov sb, r1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	ldr r1, _08057C68 @ =u8_ARRAY_08364aac\n\
	ldrb r0, [r7, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	movs r4, #0\n\
	strb r0, [r7, #0xd]\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldr r1, _08057C6C @ =sCollisions\n\
	adds r0, r7, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	ldr r1, _08057C70 @ =onCollision\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, #0x44\n\
	str r4, [r0]\n\
	ldrb r2, [r7, #0x10]\n\
	mov r8, r2\n\
	cmp r2, #0\n\
	beq _08057B48\n\
	b _08057C4E\n\
_08057B48:\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	str r1, [r7, #0x58]\n\
	ldr r0, [r7, #0x54]\n\
	bl FUN_0800a134\n\
	adds r6, r0, #0\n\
	ldr r0, [r7, #0x54]\n\
	adds r1, r6, #0\n\
	bl FUN_0800a31c\n\
	adds r4, r0, #0\n\
	ldr r0, [r7, #0x54]\n\
	adds r1, r6, #0\n\
	bl FUN_0800a22c\n\
	adds r6, r0, #0\n\
	adds r5, r7, #0\n\
	adds r5, #0xbc\n\
	adds r4, r4, r6\n\
	lsrs r0, r4, #0x1f\n\
	adds r4, r4, r0\n\
	asrs r4, r4, #1\n\
	str r4, [r5]\n\
	ldr r0, _08057C74 @ =0xFFFFA000\n\
	adds r4, r4, r0\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	adds r1, r4, #0\n\
	bl CreateSolidGlacierleArm\n\
	ldr r1, [r5]\n\
	ldr r2, _08057C78 @ =0xFFFFE000\n\
	adds r1, r1, r2\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateSolidGlacierleArm\n\
	ldr r1, [r5]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	adds r1, r1, r0\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateSolidGlacierleArm\n\
	ldr r1, [r5]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #7\n\
	adds r1, r1, r2\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateSolidGlacierleArm\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	mov r1, sb\n\
	str r1, [r0]\n\
	adds r2, r7, #0\n\
	adds r2, #0xc0\n\
	ldrb r0, [r2]\n\
	movs r1, #0xff\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r7, #0\n\
	adds r0, #0xc1\n\
	mov r2, r8\n\
	strb r2, [r0]\n\
	ldr r4, _08057C7C @ =0x000006F4\n\
	ldr r0, _08057C80 @ =gStaticMotionGraphics\n\
	mov r8, r0\n\
	adds r0, r4, r0\n\
	ldr r6, _08057C84 @ =wStaticGraphicTilenums\n\
	adds r1, r6, #0\n\
	adds r1, #0xb2\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	bl LoadGraphic\n\
	ldr r0, _08057C88 @ =gStaticMotionGraphics+12\n\
	mov sl, r0\n\
	add r4, sl\n\
	ldr r5, _08057C8C @ =wStaticMotionPalIDs\n\
	adds r0, r5, #0\n\
	adds r0, #0xb2\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	mov sb, r2\n\
	add r1, sb\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xe1\n\
	lsls r4, r4, #3\n\
	add r8, r4\n\
	adds r6, #0xb4\n\
	ldrh r1, [r6]\n\
	mov r2, r8\n\
	ldrh r0, [r2, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl LoadGraphic\n\
	add r4, sl\n\
	adds r5, #0xb4\n\
	ldrh r1, [r5]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, sb\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
_08057C4E:\n\
	adds r0, r7, #0\n\
	bl Glacierle_Update\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08057C64: .4byte gBossFnTable\n\
_08057C68: .4byte u8_ARRAY_08364aac\n\
_08057C6C: .4byte sCollisions\n\
_08057C70: .4byte onCollision\n\
_08057C74: .4byte 0xFFFFA000\n\
_08057C78: .4byte 0xFFFFE000\n\
_08057C7C: .4byte 0x000006F4\n\
_08057C80: .4byte gStaticMotionGraphics\n\
_08057C84: .4byte wStaticGraphicTilenums\n\
_08057C88: .4byte gStaticMotionGraphics+12\n\
_08057C8C: .4byte wStaticMotionPalIDs\n\
 .syntax divided\n");
}

// --------------------------------------------

static void glacierle_08057d00(struct Glacierle* p);
static void tryMakeFlinch(struct Glacierle* p);
static void nop_08057cfc(struct Boss* p);

static void glacierle_08057d7c(struct Boss* p);
NAKED static void glacierle_08057e20(struct Boss* p);
void glacierle_08057f38(struct Boss* p);
void glacierle_08058018(struct Glacierle* p);
void glacierle_08058168(struct Boss* p);
void glacierle_080581d8(struct Boss* p);
void glacierle_0805836c(struct Boss* p);
void glacierle_080583c4(struct Boss* p);
void glacierleHammerPunch1(struct Boss* p);
void glacierleHammerPunch2(struct Boss* p);
void glacierleHammerPunch3(struct Boss* p);
void glacierleIceRainJump(struct Boss* p);
void glacierleIceRain1(struct Boss* p);
void glacierleIceRain2(struct Boss* p);
void glacierleIceRain3(struct Boss* p);
void glacierleIceCarnival1(struct Boss* p);
void glacierleIceCarnival2(struct Boss* p);
NON_MATCH void glacierle_080593c4(struct Boss* p);
void glacierle_080594dc(struct Boss* p);
void glacierle_080595ec(struct Boss* p);
void glacierle_08059674(struct Boss* p);

static void Glacierle_Update(struct Glacierle* p) {
  // clang-format off
  static const BossFunc sUpdates1[21] = {
      (void*)tryMakeFlinch,
      (void*)nop_08057cfc,
      (void*)tryMakeFlinch,
      (void*)tryMakeFlinch,
      (void*)tryMakeFlinch,
      (void*)tryMakeFlinch,
      (void*)tryMakeFlinch,
      (void*)tryMakeFlinch,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)tryMakeFlinch,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)glacierle_08057d00,
      (void*)nop_08057cfc,
      (void*)nop_08057cfc,
      (void*)glacierle_08057d00,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[21] = {
      (void*)glacierle_08057d7c,
      (void*)glacierle_08057e20,
      (void*)glacierle_08057f38,
      (void*)glacierle_08058018,
      (void*)glacierle_08058168,
      (void*)glacierle_080581d8,
      (void*)glacierle_0805836c,
      (void*)glacierle_080583c4,
      (void*)glacierleHammerPunch1,
      (void*)glacierleHammerPunch2,
      (void*)glacierleHammerPunch3,
      (void*)glacierleIceRainJump,
      (void*)glacierleIceRain1,
      (void*)glacierleIceRain2,
      (void*)glacierleIceRain3,
      (void*)glacierleIceCarnival1,
      (void*)glacierleIceCarnival2,
      (void*)glacierle_080593c4,
      (void*)glacierle_080594dc,
      (void*)glacierle_080595ec,
      (void*)glacierle_08059674,
  };
  // clang-format on

  if (p->elfx != NULL) {
    if (IsDead(p->elfx)) p->elfx = NULL;
  }
  if (tryKillGlacierle((void*)p)) {
    return;
  }
  (sUpdates1[p->mode[1]])((void*)p);
  (sUpdates2[p->mode[1]])((void*)p);
}

// --------------------------------------------

void glacierleDeath0(struct Boss* p);
NON_MATCH void glacierleDeath1(struct Boss* p);

static void Glacierle_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      glacierleDeath0,
      glacierleDeath1,
  };
  (sDeads[p->mode[1]])(p);
}

// --------------------------------------------

static void nop_08057cfc(struct Boss* p) {}

static void glacierle_08057d00(struct Glacierle* p) {
  if (((p->body).status & BODY_STATUS_WHITE) && (p->elfx == NULL)) {
    p->elfx = (void*)ApplyElementEffect(25, (Object*)p, &sElementCoord);
  }
}

// 0x08057d30
static void tryMakeFlinch(struct Glacierle* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      p->mode[1] = 20, p->mode[2] = 0;
    }
    if (p->elfx == NULL) {
      p->elfx = (void*)ApplyElementEffect(25, (Object*)p, &sElementCoord);
      if (p->elfx != NULL) {
        p->mode[1] = 19, p->mode[2] = 0;
      }
    }
  }
}

// --------------------------------------------

static void glacierle_08057d7c(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      p->work[2] = 24;
      SetSpriteAnimation(p, MOTION(DM178_GLACIERLE, 0));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      bool8 isZeroRight;
      SetDDP(&p->body, &sCollisions[1]);
      UpdateSpriteAnimation(p);

      isZeroRight = p->coord.x < (pZero2->s).coord.x;
      if (p->flags & X_FLIP) {
        if (!isZeroRight) goto _MODE2;
      } else if (isZeroRight) {
      _MODE2:
        p->mode[1] = 2;
        p->mode[2] = 0;
      }

      p->work[2]--;
      if (p->work[2] == 0) {
        if (!((pZero2->body).status & BODY_STATUS_DEAD) && ((pZero2->body).hp != 0)) {
          calcNextGlacierleAction(p);
        }
      }
      break;
    }
  }
}

NAKED static void glacierle_08057e20(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #9\n\
	bls _08057E2C\n\
	b _08057F2C\n\
_08057E2C:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08057E38 @ =_08057E3C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08057E38: .4byte _08057E3C\n\
_08057E3C: @ jump table\n\
	.4byte _08057E64 @ case 0\n\
	.4byte _08057E74 @ case 1\n\
	.4byte _08057E82 @ case 2\n\
	.4byte _08057EB6 @ case 3\n\
	.4byte _08057E94 @ case 4\n\
	.4byte _08057EB6 @ case 5\n\
	.4byte _08057ED4 @ case 6\n\
	.4byte _08057EE2 @ case 7\n\
	.4byte _08057F00 @ case 8\n\
	.4byte _08057F10 @ case 9\n\
_08057E64:\n\
	movs r1, #0xb2\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08057E74:\n\
	ldr r0, [r4, #0x18]\n\
	ldrb r1, [r0, #9]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08057EC8\n\
	b _08057EC2\n\
_08057E82:\n\
	movs r0, #0x8d\n\
	bl PlaySound\n\
	movs r0, #0x28\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _08057E90 @ =0x0000B21A\n\
	b _08057EAA\n\
	.align 2, 0\n\
_08057E90: .4byte 0x0000B21A\n\
_08057E94:\n\
	movs r0, #0x20\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #0x52\n\
	bl PlaySound\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl AppendQuake\n\
	ldr r1, _08057ED0 @ =0x0000B208\n\
_08057EAA:\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08057EB6:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08057EC8\n\
_08057EC2:\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08057EC8:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	b _08057F2C\n\
	.align 2, 0\n\
_08057ED0: .4byte 0x0000B208\n\
_08057ED4:\n\
	ldr r1, _08057EFC @ =0x0000B209\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08057EE2:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08057F2C\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
	b _08057F2C\n\
	.align 2, 0\n\
_08057EFC: .4byte 0x0000B209\n\
_08057F00:\n\
	movs r1, #0xb2\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08057F10:\n\
	ldr r0, _08057F34 @ =gStageRun\n\
	ldrb r0, [r0, #0x12]\n\
	movs r2, #1\n\
	adds r1, r2, #0\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _08057F26\n\
	strb r1, [r4, #0xd]\n\
	strb r2, [r4, #0xe]\n\
	movs r0, #0x18\n\
	strb r0, [r4, #0x12]\n\
_08057F26:\n\
	adds r0, r4, #0\n\
	bl UpdateEntityAnim\n\
_08057F2C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08057F34: .4byte gStageRun\n\
 .syntax divided\n");
}

void glacierle_08057f38(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x01));
      p->mode[2]++;
      FALLTHROUGH;
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      {
        register struct Body* bd asm("r0");
        register const u8* tb asm("r2");
        register s32 ix asm("r1");
        u8 k;
        bd = &p->body;
        tb = (const u8*)0x08364AAE;
        asm volatile("" : "+r"(bd));
        asm volatile("" : "+r"(tb));
        {
          register u8* q asm("r1");
          q = (u8*)p + 0x71;
          ix = *q;
        }
        ix <<= 24;
        ix >>= 24;
        {
          register const u8* e asm("r1");
          asm volatile("add %0, %1, %2" : "=l"(e) : "l"(ix), "l"(tb));
          k = *e;
        }
        SetDDP(bd, &sCollisions[k]);
      }
      break;
    case 2: {
      register s32 one asm("r2");
      register s32 f asm("r1");
      SetDDP(&p->body, (const struct Collision*)0x08363DE4);
      {
        register s32 t asm("r0");
        t = p->flags >> 4;
        one = 1;
        t ^= one;
        asm volatile("" : "+r"(t));
        t &= one;
        (p->spr).xflip = t;
      }
      f = p->flags >> 4;
      f ^= one;
      asm volatile("" : "+r"(f));
      f &= one;
      {
        register u8* oa asm("ip");
        u32 sh4;
        s32 ov;
        s32 m11;
        oa = (u8*)p + 0x4a;
        sh4 = f << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
      if (f != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x00));
      UpdateEntityAnim((struct Entity*)p);
      p->mode[1] = 0;
      p->mode[2] = 1;
      break;
    }
  }
}

void glacierle_08058018(struct Glacierle* p) {
  s32 m = p->mode[2];
  switch (m) {
    case 0: {
      s32 x = p->coord.x;
      s32 gx = x - 0x3200;
      u32 fl = p->flags;
      s32 c10 = 0x10;
      s32 t = c10;
      asm("" : "+r"(t));
      t &= fl;
      if (t != 0) {
        gx = x + 0x3200;
      }
      if (FUN_080098a4(gx, p->coord.y - 0x1000) != 0) {
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = m;
        p->mode[2] = m;
        p->unk_c1 = 0xA;
        return;
      }
      p->work[2] = 0x80;
      {
        s32 nc0 = -0xC0;
        s32 v;
        p->d.x = nc0;
        v = nc0;
        {
          u32 fl2 = p->flags;
          s32 t2 = c10;
          asm("" : "+r"(t2));
          t2 &= fl2;
          if (t2 != 0) {
            v = 0xC0;
          }
        }
        p->d.x = v;
        asm("" : "+r"(nc0));
      }
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x05));
      p->mode[2]++;
    }
      // fallthrough
    case 1: {
      s32 grounded = 0;
      s32 x = p->coord.x;
      s32 gx = x - 0x3200;
      if (p->flags & 0x10) {
        gx = x + 0x3200;
      }
      if (FUN_080098a4(gx, p->coord.y - 0x1000) != 0) {
        grounded = 1;
      }
      if (p->work[2] != 0) {
        p->work[2]--;
      }
      UpdateEntityAnim((struct Entity*)p);
      {
        s8 c = p->motion.cmdIdx;
        if (c != 1 && c != 5 && grounded == 0) {
          p->coord.x += p->d.x;
        }
      }
      if ((*(u32*)((u8*)p + 0x70) & 0xFFFF00) == 0x10000 || (*(u32*)((u8*)p + 0x70) & 0xFFFF00) == 0x10400) {
        PlaySound(0x8C);
      }
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ab1[p->motion.cmdIdx]]);
      if (grounded != 0) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      } else {
        u8 w = p->work[2];
        if (w == 0 && p->motion.cmdIdx == 2) {
          p->mode[1] = w;
          p->mode[2] = w;
        }
      }
      break;
    }
  }
}

void glacierle_08058168(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x90);
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x06));
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 5;
        p->mode[2] = 0;
      }
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ab9[p->motion.cmdIdx]]);
      break;
  }
}

void glacierle_080581d8(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 d asm("r4");
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x07));
      {
        register s32 k asm("r4");
        k = 0x80 << 3;
        p->work[2] = Sqrt(k);
        p->d.y = -((u16)Sqrt(k) << 5);
      }
      {
        register s32 u asm("r1");
        register s32 w asm("r0");
        u = (pZero2->s).coord.x;
        w = p->coord.x;
        d = u - w;
      }
      if ((p->flags & 0x10) == 0) {
        if (d < -0x8000) {
          d = -0x8000;
        }
        if (d > -0x2000) {
          d = -0x2000;
        }
      } else {
        if (d > (0x80 << 8)) {
          d = 0x80 << 8;
        }
        if (d <= 0x1FFF) {
          d = 0x80 << 6;
        }
      }
      p->d.x = d / (u16)Sqrt(0x80 << 3);
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      if ((u8)--p->work[2] == 0) {
        p->mode[2]++;
      }
      {
        register s32 t asm("r2");
        register s32 cx asm("r1");
        cx = p->coord.x;
        t = cx + -0x1A00;
        if (p->d.x > 0) {
          t = cx + (0xd0 << 5);
        }
        if ((u16)FUN_080098a4(t, p->coord.y + -0x1000) == 0) {
          p->coord.x += p->d.x;
        }
      }
      {
        register s32 dy asm("r0");
        register s32 lim asm("r1");
        dy = p->d.y;
        dy += 0x20;
        p->d.y = dy;
        lim = 0xe0 << 3;
        if (dy > lim) {
          p->d.y = lim;
        }
      }
      p->coord.y += p->d.y;
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364abc[p->motion.cmdIdx]]);
      break;
    }
    case 2:
      p->work[2] = 0xc;
      p->mode[2]++;
      FALLTHROUGH;
    case 3: {
      register s32 r asm("r1");
      {
        register s32 t asm("r0");
        t = p->work[2];
        t -= 1;
        p->work[2] = t;
        r = (u8)t;
      }
      if (r == 0) {
        p->mode[1] = 6;
        p->mode[2] = r;
      }
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364abc[p->motion.cmdIdx]]);
      break;
    }
  }
}

void glacierle_0805836c(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      p->d.y = 0;
      p->mode[2]++;
      // fallthrough
    case 1: {
      s32 r;
      p->d.y += 0x40;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      r = PushoutToUp1(p->coord.x, p->coord.y);
      if (r < 0) {
        p->coord.y += r;
        p->mode[1] = 7;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void glacierle_080583c4(struct Boss* p0) {
  register struct Glacierle* p asm("r4");
  s32 m2;
  p = (struct Glacierle*)p0;
  switch (p->mode[2]) {
    case 0: {
      u32* st;
      s32* cp;
      PlaySound(0x91);
      st = (u32*)((u8*)p + 0xb4);
      *st |= 2;
      cp = (s32*)((u8*)p + 0xc4);
      *cp = p->coord.x;
      AppendQuake(3, (struct Coord*)((u8*)cp - 0x70));
      p->work[2] = 0x12;
      SetMotion((struct Entity*)p, 0xB208);
      p->mode[2]++;
    }
      /* fallthrough */
    case 1: {
      s32 raw;
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364abf[(s8) * (u8*)((u8*)p + 0x71)]]);
      raw = p->work[2] - 1;
      p->work[2] = raw;
      if ((raw << 24) != 0) {
        break;
      }
      m2 = p->mode[2] + 1;
      goto store;
    }
    case 2: {
      u32* st2 = (u32*)((u8*)p + 0xb4);
      *st2 &= -3;
      SetMotion((struct Entity*)p, 0xB209);
      p->mode[2]++;
    }
      /* fallthrough */
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (*(u8*)((u8*)p + 0x73) != 3) {
        break;
      }
      m2 = 0;
      p->mode[1] = m2;
    store:
      p->mode[2] = m2;
      break;
  }
}

void glacierleHammerPunch1(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      p->work[2] = 0x1E;
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x12));
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ac2[p->motion.cmdIdx]]);
      if ((u8)--p->work[2] == 0) {
        p->mode[2]++;
      }
      break;
    case 2:
      SetDDP(&p->body, &sCollisions[123]);
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x13));
      p->mode[2]++;
      // fallthrough
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.duration == 1) {
        p->mode[1] = 9;
        p->mode[2] = 0;
      }
      break;
  }
}

void glacierleHammerPunch2(struct Boss* p) {
  struct Enemy* q;
  u32* st;
  s32* cp;
  s32 v;
  s32 px;
  s32 hx, hy;

  switch (p->mode[2]) {
    case 0:
      PlaySound(0x8E);
      SetDDP(&p->body, &sCollisions[126]);
      st = (u32*)((u8*)p + 0xb4);
      *st &= ~1;
      q = createGlacierleAtkHand((struct Entity*)p);
      p->unk_28 = &createGlacierleJoint(&q->s, (struct Entity*)p)->s;
      p->unk_2c = &q->s;
      px = p->coord.x;
      (q->s).coord.x = px - 0x2F00;
      v = (q->s).coord.x;
      if (p->flags & X_FLIP) {
        v = px + 0x2F00;
      }
      (q->s).coord.x = v;
      (q->s).coord.y = p->coord.y - 0x2900;
      p->d.x = -0x300;
      v = p->d.x;
      if (p->flags & X_FLIP) {
        v = 0x300;
      }
      p->d.x = v;
      p->mode[2]++;
      /* fallthrough */
    case 1:
      q = (struct Enemy*)p->unk_2c;
      (q->s).coord.x += p->d.x;
      if ((*(u32*)((u8*)pZero2 + 0xc) & 0xFFFF00) == 0x400 && ((q->body).status & 4)) {
        PlaySound(0x52);
      }
      if ((u32)((q->s).coord.x - p->coord.x + 0x8000) > 0x10000) {
        p->mode[2]++;
      } else if ((p->flags & X_FLIP) == 0) {
        if ((q->s).coord.x - 0x1A00 < *(s32*)((u8*)p + 0xbc) - 0xAC00) {
          *(u32*)((u8*)p + 0xb4) |= 2;
          cp = (s32*)((u8*)p + 0xc4);
          *cp = *(s32*)((u8*)p + 0xbc) - 0xAC00;
          AppendQuake(3, (struct Coord*)((u8*)cp - 0x70));
          p->mode[2]++;
        }
      } else {
        if ((q->s).coord.x + 0x1A00 > *(s32*)((u8*)p + 0xbc) + 0xAC00) {
          *(u32*)((u8*)p + 0xb4) |= 2;
          cp = (s32*)((u8*)p + 0xc4);
          *cp = *(s32*)((u8*)p + 0xbc) + 0xAC00;
          AppendQuake(3, (struct Coord*)((u8*)cp - 0x70));
          p->mode[2]++;
        }
      }
      hx = p->coord.x;
      hx -= 0x1700;
      asm("" : "+l"(hx));
      if (p->flags & X_FLIP) {
        hx += 0x2E00;
      }
      hy = p->coord.y;
      hy -= 0x2900;
      FUN_080823a4(&q->s, (struct Entity*)p, hx, hy);
      FUN_08082484(q, hx, hy);
      UpdateEntityAnim((struct Entity*)p);
      break;
    case 2:
      p->work[2] = 0x20;
      p->mode[2]++;
      /* fallthrough */
    case 3:
      if (p->work[2] == 0x10) {
        *(u32*)((u8*)p + 0xb4) &= ~2;
      }
      if ((u8)--p->work[2] == 0) {
        p->mode[1] = 0xA;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
  }
}

void glacierleHammerPunch3(struct Boss* p) {
  u8 m = p->mode[2];
  struct Enemy* q;
  struct Entity* e;
  s32 v;
  s32 w;

  switch (m) {
    case 0:
      p->work[2] = 1;
      q = (struct Enemy*)p->unk_2c;
      *((u8*)q + 0xb5) = m;
      (q->s).unk_coord.x = FUN_080823ec(q) + 0x300;
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x14));
      p->mode[2]++;
      /* fallthrough */
    case 1:
      if ((p->work[2] & 3) == 0) {
        PlaySound(0x8F);
        p->work[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      e = p->unk_28;
      (e->coord).x = p->coord.x;
      (e->coord).x += Coord16_ARRAY_08364ac6[p->motion.cmdIdx].x;
      v = (e->coord).x;
      if (p->flags & X_FLIP) {
        v -= Coord16_ARRAY_08364ac6[p->motion.cmdIdx].x * 2;
      }
      (e->coord).x = v;
      (e->coord).y = p->coord.y;
      (e->coord).y += *(&Coord16_ARRAY_08364ac6[0].y + p->motion.cmdIdx * 2);
      q = (struct Enemy*)p->unk_2c;
      if ((q->s).unk_coord.x >= 0) {
        (q->s).unk_coord.x -= 0x20;
      } else {
        p->mode[2]++;
      }
      p->work[2] += glacierle_08082598(q, 1);
      (e->coord).x = p->coord.x;
      (e->coord).x += Coord16_ARRAY_08364ac6[p->motion.cmdIdx].x;
      w = (e->coord).x;
      if (p->flags & X_FLIP) {
        w -= Coord16_ARRAY_08364ac6[p->motion.cmdIdx].x * 2;
      }
      (e->coord).x = w;
      (e->coord).y = p->coord.y;
      (e->coord).y += *(&Coord16_ARRAY_08364ac6[0].y + p->motion.cmdIdx * 2);
      break;
    case 2:
      SetDDP(&p->body, &sCollisions[128]);
      q = (struct Enemy*)p->unk_2c;
      while (*((u8*)q + 0xb4) != 0) {
        FUN_08082348(&q->s);
      }
      (q->s).flags &= ~DISPLAY;
      (q->s).flags &= ~FLIPABLE;
      EXIT_BODY(q);
      SET_ENEMY_ROUTINE(q, ENTITY_DISAPPEAR);
      *(u32*)((u8*)p + 0xb4) |= 1;
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x15));
      p->mode[2]++;
      /* fallthrough */
    case 3:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      break;
  }
}

void glacierleIceRainJump(struct Boss* p) {
  switch (p->mode[2]) {
    case 0:
      PlaySound(0x90);
      SetMotion((struct Entity*)p, MOTION(0xb2, 0x0A));
      p->mode[2]++;
      // fallthrough
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ace[p->motion.cmdIdx]]);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 2:
      p->unk_coord.y = FUN_0800a134(p->coord.x, p->coord.y);
      p->d.y = -0x480;
      p->mode[2]++;
      // fallthrough
    case 3: {
      s32 dy = p->d.y + 0x20;
      s32 y;
      s32 lim;
      p->d.y = dy;
      y = p->coord.y + dy;
      p->coord.y = y;
      lim = p->unk_coord.y + 0x5D00;
      if (y < lim) {
        p->coord.y = lim;
        p->mode[1] = 0xC;
        p->mode[2] = 0;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void glacierleIceRain1(struct Boss* p) {
  struct Enemy* q;
  struct Enemy* j;
  struct Enemy* sk;
  s32 c, c2, v, y;

  switch (p->mode[2]) {
    case 0:
      PlaySound(0x93);
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x0B));
      p->mode[2]++;
      /* fallthrough */
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ad3[(s8) * (u8*)((u8*)p + 0x71)]]);
      if ((*(u32*)((u8*)p + 0x70) & 0xFFFF00) == 0x10200) {
        p->mode[2]++;
      }
      break;
    case 2:
      *(u32*)((u8*)p + 0xb4) &= ~1;
      q = createGlacierleAtkHand((struct Entity*)p);
      p->unk_2c = &q->s;
      if (q != NULL) {
        j = createGlacierleJoint(&q->s, (struct Entity*)p);
        createGlacierleJoint(&q->s, (struct Entity*)p);
        createGlacierleJoint(&q->s, (struct Entity*)p);
        createGlacierleJoint(&q->s, (struct Entity*)p);
        if (j != NULL) {
          sk = createGlacierleSucker(&j->s, (struct Entity*)p);
          p->unk_28 = &sk->s;
          c = p->coord.x;
          (sk->s).coord.x = c + 0xA00;
          v = (sk->s).coord.x;
          if (p->flags & X_FLIP) {
            v = c - 0xA00;
          }
          (sk->s).coord.x = v;
          (sk->s).coord.y = p->coord.y - 0x2D00;
        }
        c2 = p->coord.x;
        (q->s).coord.x = c2 + 0xA00;
        v = (q->s).coord.x;
        if (p->flags & X_FLIP) {
          v = c2 - 0xA00;
        }
        (q->s).coord.x = v;
        y = p->coord.y;
        (q->s).coord.y = y - 0x200;
        FUN_08082484(q, v, y - 0x1E00);
        *((u8*)q + 0xb5) = 0;
        (q->s).unk_coord.x = 0x700;
      }
      p->mode[2]++;
      /* fallthrough */
    case 3:
      sk = (struct Enemy*)p->unk_28;
      FUN_0808288c(sk, 0x40);
      q = (struct Enemy*)p->unk_2c;
      glacierle_08082598(q, 0);
      UpdateEntityAnim((struct Entity*)p);
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364ad3[(s8) * (u8*)((u8*)p + 0x71)]]);
      if (p->motion.state == 3) {
        p->mode[2]++;
      }
      break;
    case 4:
      PlaySound(0x92);
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x0C));
      p->mode[2]++;
      /* fallthrough */
    case 5:
      sk = (struct Enemy*)p->unk_28;
      FUN_0808288c(sk, 0x40);
      q = (struct Enemy*)p->unk_2c;
      glacierle_08082598(q, 0);
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 0xD;
        p->mode[2] = 0;
      }
      break;
  }
}

INCASM("asm/boss/glacierle_a.inc");

void glacierleIceCarnival1(struct Boss* p) {
  s32 m = p->mode[2];
  switch (m) {
    case 0:
      if ((u32)(p->coord.x - *(s32*)((u8*)p + 0xbc) + 0x3C00) > 0x7800) {
        UpdateEntityAnim((struct Entity*)p);
        p->mode[1] = m;
        p->mode[2] = m;
        *((u8*)p + 0xc1) = 0xa;
        break;
      }
      PlaySound(0x95);
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x16));
      p->mode[2]++;
      FALLTHROUGH;
    case 1: {
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        s32 z = 0;
        p->mode[1] = 0x10;
        p->mode[2] = z;
      }
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364b22[(s8)p->motion.cmdIdx]]);
      break;
    }
  }
}

void glacierleIceCarnival2(struct Boss* p) {
  register s32 md asm("r4");
  struct Enemy* q;
  struct Enemy* sk;
  md = p->mode[2];
  if (md == 1) {
    goto case1;
  }
  if (md > 1) {
    goto gt;
  }
  if (md == 0) {
    goto case0;
  }
  return;
gt:
  if (md != 2) {
    goto n2;
  }
  goto case2;
n2:
  if (md != 3) {
    goto n3;
  }
  goto case3;
n3:
  return;
case0:
  SetDDP(&p->body, (const struct Collision*)0x08363F04);
  p->work[2] = md;
  {
    register u32* w asm("r2");
    register u32 v asm("r0");
    register s32 m asm("r1");
    w = (u32*)((u8*)p + 0xb4);
    v = *w;
    m = -2;
    v &= m;
    *w = v;
  }
  q = createGlacierleAtkHand((struct Entity*)p);
  p->unk_2c = &q->s;
  if (q != NULL) {
    struct Enemy* j;
    j = createGlacierleJoint(&q->s, (struct Entity*)p);
    createGlacierleJoint(&q->s, (struct Entity*)p);
    createGlacierleJoint(&q->s, (struct Entity*)p);
    createGlacierleJoint(&q->s, (struct Entity*)p);
    if (j != NULL) {
      register s32 c asm("r3");
      register s32 v asm("r2");
      sk = createGlacierleSucker(&j->s, (struct Entity*)p);
      p->unk_28 = &sk->s;
      c = p->coord.x;
      {
        register s32 k asm("r1");
        register s32 t asm("r0");
        k = 0xa0 << 4;
        t = c + k;
        (sk->s).coord.x = t;
        v = t;
      }
      {
        register u32 fl asm("r1");
        register u32 m asm("r0");
        fl = p->flags;
        m = 0x10;
        m &= fl;
        if (m != 0) {
          register s32 k asm("r0");
          k = -0xa00;
          v = c + k;
        }
      }
      (sk->s).coord.x = v;
      {
        register s32 y asm("r0");
        register s32 k asm("r1");
        y = p->coord.y;
        k = -0x2500;
        y += k;
        (sk->s).coord.y = y;
      }
    }
    {
      register s32 c asm("r3");
      register s32 v asm("r2");
      register s32 one asm("r4");
      c = p->coord.x;
      {
        register s32 k asm("r2");
        register s32 t asm("r0");
        k = 0xb0 << 6;
        t = c + k;
        (q->s).coord.x = t;
        v = t;
      }
      {
        register u32 fl asm("r1");
        register u32 m asm("r0");
        fl = p->flags;
        one = 0x10;
        m = one;
        m &= fl;
        if (m != 0) {
          register s32 k asm("r0");
          k = -0x2c00;
          v = c + k;
        }
      }
      (q->s).coord.x = v;
      {
        register s32 y asm("r0");
        register s32 k asm("r1");
        y = p->coord.y;
        k = -0x3700;
        y += k;
        (q->s).coord.y = y;
      }
      {
        register s32 hx asm("r3");
        register s32 hy asm("r2");
        {
          register s32 c2 asm("r2");
          register s32 k asm("r0");
          c2 = p->coord.x;
          k = 0x88 << 5;
          hx = c2 + k;
          {
            register u32 fl asm("r1");
            register u32 m asm("r0");
            fl = p->flags;
            m = one;
            m &= fl;
            if (m != 0) {
              register s32 k2 asm("r1");
              k2 = -0x1100;
              hx = c2 + k2;
            }
          }
        }
        hy = p->coord.y;
        {
          register s32 k asm("r0");
          k = -0x2c00;
          hy += k;
        }
        FUN_08082484(q, hx, hy);
      }
      {
        register u8* b5 asm("r1");
        register s32 z asm("r0");
        b5 = (u8*)q + 0xb5;
        z = 0;
        *b5 = z;
      }
      {
        register s32 k asm("r0");
        k = 0x80 << 3;
        *(s32*)((u8*)q + 0x64) = k;
      }
      {
        register u8* a asm("r0");
        register s32 v2 asm("r0");
        a = (u8*)q + 0x24;
        v2 = *a;
        v2 += 0x80;
        p->work[2] = v2;
      }
      FUN_0808242c(q, 0, 0x98 << 1);
    }
  }
  {
    register s32 z asm("r1");
    z = 0;
    p->work[3] = 0x20;
    *(s32*)((u8*)p + 0x64) = z;
  }
  SetMotion((struct Entity*)p, 0xB217);
  p->mode[2]++;
  FALLTHROUGH;
case1 : {
  register s32 base asm("r4");
  q = (struct Enemy*)p->unk_2c;
  base = 0x80 << 3;
  *(s32*)((u8*)q + 0x64) = base;
  {
    register const s16* tb asm("r5");
    register s32 t asm("r0");
    tb = gSineTable;
    t = *(s32*)((u8*)p + 0x64) << 8;
    t = t / 0x212;
    t = (u8)t;
    {
      register const s16* e asm("r0");
      register s32 s asm("r1");
      e = (const s16*)((u8*)(t * 2) + (u32)tb);
      s = *e;
      t = s << 2;
      t += s;
      t += base;
      *(s32*)((u8*)q + 0x64) = t;
    }
  }
  if ((*(u32*)((u8*)pZero2 + 0xc) & 0x00FFFF00) == base) {
    if ((*(u32*)((u8*)q + 0x8c) & 4) != 0) {
      PlaySound(0x52);
    }
  }
  if (*((u8*)q + 0xb4) <= 6) {
    register s32 t asm("r0");
    t = p->work[3] - 1;
    p->work[3] = t;
    if ((t << 24) == 0) {
      p->work[3] = 8;
      createGlacierleJoint(&q->s, (struct Entity*)p);
    }
  }
  sk = (struct Enemy*)p->unk_28;
  {
    register s32 n asm("r0");
    n = *(s32*)((u8*)p + 0x64) + 1;
    *(s32*)((u8*)p + 0x64) = n;
    if (n > 2) {
      register u32 fl asm("r1");
      register u32 m asm("r0");
      fl = p->flags;
      m = 0x10;
      m &= fl;
      if (m != 0) {
        p->work[2] = p->work[2] - 6;
      } else {
        p->work[2] = p->work[2] + 6;
      }
    }
  }
  if (*(s32*)((u8*)p + 0x64) > 0x90) {
    register u32 fl asm("r1");
    register u32 m asm("r0");
    fl = p->flags;
    m = 0x10;
    m &= fl;
    if (m != 0) {
      goto flipped;
    }
    if (p->work[2] == 0x1c) {
      goto bump;
    }
    goto swing;
  flipped:
    if (p->work[2] != 0x64) {
      goto swing;
    }
  bump:
    p->mode[2]++;
  }
swing : {
    register u32 wv asm("r0");
    register u32 mk asm("r1");
    wv = p->work[2];
    mk = 0x1f;
    wv &= mk;
    if (wv <= 5) {
    register s32 a asm("r3");
    register const s16* tb asm("r5");
    register s32 dx asm("r2");
    register s32 dy asm("r3");
    {
      register u8* w asm("r0");
      register s32 v asm("r0");
      w = (u8*)q + 0x24;
      v = *w;
      v += 0x80;
      v = (u8)v;
      asm("" : "+l"(v));
      a = v;
    }
    tb = gSineTable;
    {
      register const s16* e asm("r0");
      register s32 s asm("r1");
      register s32 v asm("r0");
      e = (const s16*)((u8*)((u8)(a + 0x40) * 2) + (u32)tb);
      s = *e;
      v = ((s << 3) - s) << 7;
      dx = v / 0x100;
    }
    {
      register const s16* e asm("r0");
      register s32 s asm("r1");
      register s32 v asm("r0");
      e = (const s16*)((u8*)(a * 2) + (u32)tb);
      s = *e;
      v = ((s << 3) - s) << 7;
      dy = v / 0x100;
    }
    FUN_080aa5e8((q->s).coord.x + dx, (q->s).coord.y + dy);
    }
  }
  if (p->work[2] <= 5) {
    PlaySound(0x96);
  }
  FUN_0808288c(sk, p->work[2]);
  glacierle_08082598(q, 0);
  FUN_0808288c(sk, p->work[2]);
  UpdateEntityAnim((struct Entity*)p);
  return;
}
case2:
  p->work[3] = 0x1e;
  *(s32*)((u8*)p + 0x64) = 0xc0 << 3;
  p->mode[2]++;
  FALLTHROUGH;
case3 : {
  q = (struct Enemy*)p->unk_2c;
  sk = (struct Enemy*)p->unk_28;
  {
    register u32 mv asm("r0");
    register u32 mk asm("r1");
    mv = *(u32*)((u8*)pZero2 + 0xc);
    mk = 0x00FFFF00;
    mv &= mk;
    mk = 0x80 << 3;
    if (mv == mk) {
      if ((*(u32*)((u8*)q + 0x8c) & 4) != 0) {
        PlaySound(0x52);
      }
    }
  }
  {
    register s32 v asm("r0");
    register s32 lim asm("r1");
    v = *(s32*)((u8*)p + 0x64) - 0x64;
    *(s32*)((u8*)p + 0x64) = v;
    lim = 0x2FF;
    if (v <= lim) {
      v = 0xc0 << 2;
      *(s32*)((u8*)p + 0x64) = v;
    }
  }
  {
    register u32 fl asm("r1");
    register u32 m asm("r0");
    fl = p->flags;
    m = 0x10;
    m &= fl;
    if (m != 0) {
      register s32 d asm("r1");
      register s32 v asm("r0");
      d = *(s32*)((u8*)p + 0x64) >> 8;
      v = p->work[2];
      v -= d;
      p->work[2] = v;
    } else {
      register s32 d asm("r0");
      register s32 v asm("r1");
      d = *(s32*)((u8*)p + 0x64) >> 8;
      v = p->work[2];
      d += v;
      p->work[2] = d;
    }
  }
  FUN_0808288c(sk, p->work[2]);
  glacierle_08082598(q, 0);
  FUN_0808288c(sk, p->work[2]);
  {
    register s32 t asm("r0");
    register u32 z asm("r1");
    t = p->work[3] - 1;
    p->work[3] = t;
    z = (u8)(t << 24 >> 24);
    if (z == 0) {
      p->mode[1] = 0x11;
      p->mode[2] = z;
    }
  }
  UpdateEntityAnim((struct Entity*)p);
}
}

NON_MATCH void glacierle_080593c4(struct Boss* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      struct Enemy* q = (struct Enemy*)p->unk_2c;
      u32* w;
      struct Enemy* e;
      w = (u32*)(0xb4 + (u32)p);
      while (*((u8*)q + 0xb4) != 0) {
        FUN_08082348(&q->s);
      }
      e = (struct Enemy*)p->unk_28;
      (e->s).flags &= ~DISPLAY;
      (e->s).flags &= ~FLIPABLE;
      EXIT_BODY(e);
      SET_ENEMY_ROUTINE(e, ENTITY_DISAPPEAR);
      (q->s).flags &= ~DISPLAY;
      (q->s).flags &= ~FLIPABLE;
      EXIT_BODY(q);
      SET_ENEMY_ROUTINE(q, ENTITY_DISAPPEAR);
      *w |= 1;
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x19));
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      if (p->motion.state == 3) {
        p->mode[1] = 0;
        p->mode[2] = 0;
      }
      SetDDP(&p->body, &sCollisions[u8_ARRAY_08364b26[p->motion.cmdIdx]]);
      break;
  }
#else
  INCCODE("asm/boss/glacierle_593c4.inc");
#endif
}

void glacierle_080594dc(struct Boss* p) {
  struct Entity* q = p->unk_28;
  u8 m2 = p->mode[2];
  switch (m2) {
    case 0: {
      u32 xf;
      register u32 xf2 asm("r1");
      p->flags2 |= 0x10;
      p->invincibleID = q->uniqueID;
      (p->body).status = m2;
      (p->body).prevStatus = m2;
      (p->body).invincibleTime = m2;
      p->flags &= ~COLLIDABLE;
      {
        register u32 one asm("r2");
        xf = q->flags >> 4;
        one = 1;
        xf &= one;
        (p->spr).xflip = xf;
        xf2 = (q->flags >> 4) & one;
      }
      {
        register u8* oa asm("ip");
        u32 k4a = 0x4a;
        u32 sh4;
        s32 ov, m11;
        asm("" : "+r"(k4a));
        oa = (u8*)((u32)p + k4a);
        sh4 = xf2 << 4;
        ov = *oa;
        m11 = -0x11;
        m11 &= ov;
        m11 |= sh4;
        *oa = m11;
      }
      if (xf2 != 0) {
        p->flags |= 0x10;
      } else {
        p->flags &= 0xEF;
      }
      if (*(s32*)((u8*)q + 0xb4) & 1) {
        SetMotion((struct Entity*)p, MOTION(0xB2, 0x02));
      } else {
        SetMotion((struct Entity*)p, MOTION(0xB2, 0x1C));
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 k asm("r0");
      s32 cx;
      register s32 dx asm("r1");
      cx = p->coord.x;
      dx = p->d.x;
      p->coord.x = cx + dx;
      if (p->work[3] != 0) {
        k = 0xF6;
      } else {
        k = 0xFA;
      }
      k *= dx;
      p->d.x = k / 256;
      FUN_0801779c((struct Entity*)p);
      if (q->mode[0] == 4) {
        p->flags &= ~DISPLAY;
        p->flags &= ~FLIPABLE;
        (p->body).status = 0;
        (p->body).prevStatus = 0;
        (p->body).invincibleTime = 0;
        p->flags &= ~COLLIDABLE;
        SET_BOSS_ROUTINE(p, ENTITY_DISAPPEAR);
      }
      break;
    }
  }
}

void glacierle_080595ec(struct Boss* p) {
  u8 m = p->mode[2];
  switch (m) {
    case 0:
      PlaySound(0x97);
      SetDDP(&p->body, &sCollisions[131]);
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x04));
      p->d.y = m;
      p->work[2] = 0x10;
      p->mode[2]++;
      /* fallthrough */
    case 1: {
      s32 r;
      u8 t;
      p->d.y += 0x20;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      p->coord.y += p->d.y;
      r = PushoutToUp1(p->coord.x, p->coord.y);
      if (r < 0) {
        p->coord.y += r;
        p->d.y = 0;
      }
      t = --p->work[2];
      if (t == 0) {
        p->mode[1] = t;
        p->mode[2] = t;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void glacierle_08059674(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      s32 dx, dy, dist, nx, ny;
      PlaySound(0x97);
      SetMotion((struct Entity*)p, MOTION(0xB2, 0x04));
      dx = p->coord.x - *(s32*)((u8*)p + 0xc8);
      p->d.x = dx;
      dy = p->coord.y - 0x3000;
      dy -= *(s32*)((u8*)p + 0xcc);
      p->d.y = dy;
      dist = (dx >> 8) * (dx >> 8);
      dist += (dy >> 8) * (dy >> 8);
      dist = Sqrt(dist) << 8;
      nx = (p->d.x << 8) / dist;
      p->d.x = nx;
      ny = (p->d.y << 8) / dist;
      p->d.y = ny;
      p->d.x = nx * 640 / 256;
      p->d.y = ny * 640 / 256;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 r asm("r6");
      s32 x, bx, ny;
      x = p->coord.x + p->d.x;
      p->coord.x = x;
      bx = *(s32*)((u8*)p + 0xbc);
      if (x > bx + 0x9A00) {
        p->coord.x = bx + 0x9A00;
      } else if (x < bx - 0x9A00) {
        p->coord.x = bx - 0x9A00;
      }
      p->d.y += 0x20;
      if (p->d.y > 0x700) {
        p->d.y = 0x700;
      }
      ny = p->coord.y + p->d.y;
      p->coord.y = ny;
      if (p->d.y > 0) {
        r = PushoutToUp1(p->coord.x, ny);
        if (r < 0) {
          p->coord.y += r;
          p->mode[1] = 0;
          p->mode[2] = 0;
        }
      } else {
        r = PushoutToDown1(p->coord.x, ny - 0x3000);
        if (r < 0) {
          p->coord.y += r;
        }
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
  }
}

void glacierleDeath0(struct Boss* p) {
  switch (p->mode[2]) {
    case 0: {
      register s32 one asm("r5");
      register struct StageRun* sr asm("r3");
      register s32 v asm("r2");
      {
        u8* a = (u8*)p + 0x8c;
        s32 z = 0;
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(s32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      {
        register u8 g asm("r0");
        register u8 h asm("r1");
        h = p->flags;
        asm("" : "+r"(h));
        g = 0xFB;
        g &= h;
        p->flags = g;
      }
      sr = &gStageRun;
      v = sr->missionStatus;
      one = 1;
      {
        s32 t = one;
        t &= v;
        if (t != 0) {
          register s32 a2 asm("r1");
          register s32 u asm("r0");
          a2 = (sr->vm).active;
          u = one;
          u &= a2;
          if (u == 0) {
            s32 w = 0xFFFE;
            s32 k;
            w &= v;
            k = 0x10;
            w |= k;
            sr->missionStatus = w;
          }
        }
      }
      p->work[2] = 0x50;
      if ((*(u32*)((u8*)p + 0xb4) & 1) != 0) {
        SetMotion((struct Entity*)p, MOTION(0xB2, 4));
      } else {
        SetMotion((struct Entity*)p, MOTION(0xB2, 0x1D));
      }
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1:
      UpdateEntityAnim((struct Entity*)p);
      p->work[2]--;
      if ((p->scriptEntity->flags & 0x80) == 0) {
        break;
      }
      goto bump;
    case 2:
      p->unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)sExplosionCoords);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if (((struct Entity*)p->unk_2c)->mode[0] <= 1) {
        break;
      }
      {
        register struct StageRun* sr2 asm("r2");
        register u8 g3 asm("r0");
        register u8 h3 asm("r1");
        sr2 = &gStageRun;
        h3 = (sr2->vm).active;
        g3 = 2;
        g3 |= h3;
        (sr2->vm).active = g3;
      }
    bump:
      p->mode[2]++;
      break;
    case 4:
      break;
  }
}

NON_MATCH void glacierleDeath1(struct Boss* p) {
#if MODERN
  switch (p->mode[2]) {
    case 0: {
      register s32 v asm("r6");
      register s32 one asm("r4");
      PlaySound(0x2F);
      v = *((u8*)p + 0xc2);
      {
        register struct Glacierle* c asm("r4");
        c = (struct Glacierle*)AllocEntityLast(gBossHeaderPtr);
        if (c != NULL) {
          {
            register s32 f2 asm("r1");
            (c->s).renderPrio = 0x18;
            f2 = 0x10;
            INIT_BOSS_ROUTINE(c, 0x10);
            {
              register s32 pz asm("r0");
              pz = 0;
              (c->s).tileNum = 0;
              (c->s).palID = pz;
            }
            (c->s).flags2 = f2 | (c->s).flags2;
          }
          (c->s).invincibleID = (c->s).uniqueID;
          (c->s).coord.x = p->coord.x;
          (c->s).coord.y = p->coord.y;
          {
            register s32 base asm("r0");
            register s32 one2 asm("r1");
            base = 0x100;
            base -= v << 9;
            (c->s).d.x = base;
            (c->s).unk_28 = (struct Entity*)p;
            one2 = 1;
            (c->s).work[0] = one2;
            (c->s).work[3] = ((p->flags >> 4) & one2) ^ v;
          }
        }
      }
      SetMotion((struct Entity*)p, 0xB203);
      {
        u8* a = (u8*)p + 0x8c;
        s32 z = 0;
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *(u32*)a = z;
        asm("" : "+r"(a));
        a += 4;
        asm("" : "+r"(a));
        *a = z;
      }
      p->flags &= ~COLLIDABLE;
      {
        register u16 ms asm("r2");
        register s32 t asm("r0");
        ms = gStageRun.missionStatus;
        one = 1;
        asm volatile("add %0, %1, #0" : "=&l"(t) : "l"(one));
        t &= ms;
        if (t != 0) {
          register u8 av asm("r1");
          register s32 t2 asm("r0");
          av = gStageRun.vm.active;
          asm volatile("add %0, %1, #0" : "=&l"(t2) : "l"(one));
          t2 &= av;
          if (t2 == 0) {
            gStageRun.missionStatus = (ms & 0xFFFE) | MISSION_SUCCESS;
          }
        }
      }
      {
        register s32 base2 asm("r0");
        base2 = 0x100;
        base2 -= v << 9;
        p->d.x = base2;
      }
      {
        struct Coord c2;
        {
          register s32 x asm("r0");
          x = p->coord.x + (0x80 << 4);
          x -= v << 12;
          c2.x = x;
        }
        c2.y = p->coord.y - 0x2800;
        ((void (*)(s32, struct Coord*, s32, s32))FUN_080b2b40)(0, &c2, 0x80 << 2, v);
      }
      p->work[2] = 0x32;
      p->mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      register s32 dx asm("r2");
      register s32 k asm("r0");
      register s32 v2 asm("r3");
      {
        register s32 cx asm("r0");
        cx = p->coord.x;
        dx = p->d.x;
        cx += dx;
        p->coord.x = cx;
      }
      v2 = *((u8*)p + 0xc2);
      if ((p->flags & 0x10) == 0) {
        goto elsearm;
      }
      if (v2 != 1) {
        goto fa;
      }
      goto f6;
    elsearm:
      if (v2 == 0) {
        goto f6;
      }
    fa:
      k = 0xFA;
      goto mul;
    f6:
      k = 0xF6;
    mul:
      k = k * dx;
      p->d.x = k / 256;
      p->work[2]--;
      if ((p->scriptEntity->flags & 0x80) != 0) {
        p->mode[2]++;
      }
      UpdateEntityAnim((struct Entity*)p);
      break;
    }
    case 2:
      p->unk_2c = CreateBossExplosion((struct Entity*)p, (struct Coord*)0x08364B34);
      p->mode[2]++;
      FALLTHROUGH;
    case 3:
      if ((p->unk_2c)->mode[0] <= 1) {
        break;
      }
      gStageRun.vm.active |= 2;
      p->mode[2]++;
      break;
    case 4:
      break;
  }
#else
  INCCODE("asm/boss/glacierle_death1.inc");
#endif
}

// --------------------------------------------

// 0x08363dcc
static const struct Collision sCollisions[135] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      LAYER(0xFFFFFFFF),
      hitzone : 0,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(1), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : BODY_NATURE_B2,
      comboLv : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(20), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(1), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(6), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(30), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(6), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(42), -PIXEL(34), PIXEL(18), PIXEL(19)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(38), -PIXEL(58), PIXEL(18), PIXEL(19)},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(38), -PIXEL(37), PIXEL(18), PIXEL(19)},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(31), PIXEL(18), PIXEL(19)},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(14), -PIXEL(12), PIXEL(18), PIXEL(19)},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(14), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [26] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [27] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(19), -PIXEL(8), PIXEL(18), PIXEL(19)},
    },
    [29] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [30] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [31] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(27), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [32] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [33] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [34] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 4,
      layer : 0x00000001,
      range : {PIXEL(35), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [35] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [36] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [37] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [38] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(27), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [39] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [41] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(19), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [42] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [43] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [44] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(32), -PIXEL(21), PIXEL(18), PIXEL(19)},
    },
    [45] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [47] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [48] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [49] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [50] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(17), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [51] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(20), -PIXEL(13), PIXEL(18), PIXEL(19)},
    },
    [52] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [53] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(28), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [55] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(40), -PIXEL(22), PIXEL(18), PIXEL(19)},
    },
    [56] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [57] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(42), -PIXEL(26), PIXEL(18), PIXEL(19)},
    },
    [59] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(34), -PIXEL(19), PIXEL(18), PIXEL(19)},
    },
    [60] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [61] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(30), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [63] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(31), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [64] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [65] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(3), -PIXEL(10), PIXEL(18), PIXEL(19)},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [69] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(11), -PIXEL(5), PIXEL(18), PIXEL(19)},
    },
    [70] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [71] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [72] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(38), -PIXEL(12), PIXEL(18), PIXEL(19)},
    },
    [73] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [74] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [75] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(39), -PIXEL(17), PIXEL(18), PIXEL(19)},
    },
    [76] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [77] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(28), PIXEL(34), PIXEL(47)},
    },
    [78] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(37), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [79] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(15), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [80] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(28), PIXEL(34), PIXEL(47)},
    },
    [81] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [82] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(35), -PIXEL(74), PIXEL(18), PIXEL(19)},
    },
    [83] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(4), -PIXEL(74), PIXEL(18), PIXEL(19)},
    },
    [84] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [85] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [86] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(23), -PIXEL(70), PIXEL(18), PIXEL(19)},
    },
    [87] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(19), -PIXEL(70), PIXEL(18), PIXEL(19)},
    },
    [88] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [89] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(4), -PIXEL(21), PIXEL(34), PIXEL(47)},
    },
    [90] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(32), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [91] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(15), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [92] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(4), -PIXEL(21), PIXEL(34), PIXEL(47)},
    },
    [93] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [94] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(38), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [95] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(22), -PIXEL(19), PIXEL(18), PIXEL(19)},
    },
    [96] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [97] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [98] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(27), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [99] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(14), -PIXEL(20), PIXEL(18), PIXEL(19)},
    },
    [100] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [101] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [102] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(7), -PIXEL(90), PIXEL(18), PIXEL(19)},
    },
    [103] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(20), -PIXEL(8), PIXEL(18), PIXEL(19)},
    },
    [104] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [105] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [106] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {-PIXEL(7), -PIXEL(90), PIXEL(18), PIXEL(19)},
    },
    [107] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [108] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [109] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(26), -PIXEL(67), PIXEL(18), PIXEL(19)},
    },
    [110] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(21), PIXEL(18), PIXEL(19)},
    },
    [111] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [112] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(2), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [113] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(26), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [114] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {-PIXEL(2), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [115] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [116] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(34), -PIXEL(31), PIXEL(18), PIXEL(19)},
    },
    [117] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(57), -PIXEL(37), PIXEL(18), PIXEL(19)},
    },
    [118] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [119] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [120] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(19), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [121] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(50), -PIXEL(64), PIXEL(18), PIXEL(19)},
    },
    [122] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [123] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [124] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(4), -PIXEL(41), PIXEL(18), PIXEL(19)},
    },
    [125] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [126] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [127] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [128] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 2,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [129] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(10), -PIXEL(10), PIXEL(18), PIXEL(19)},
    },
    [130] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [131] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      remaining : 3,
      layer : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [132] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 2,
      layer : 0x00000001,
      range : {-PIXEL(26), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [133] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 3,
      atkType : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(48), -PIXEL(50), PIXEL(18), PIXEL(19)},
    },
    [134] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      LAYER(0xFFFFFFFF),
      hitzone : 8,
      hardness : HARDNESS_B3,
      remaining : 0,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
};

// --------------------------------------------

static const Coords32 sElementCoord = {PIXEL(0), -PIXEL(16)};

static const u8 sGlacierleModes[48] = {
    3, 3, 4, 4, 4, 4, 8, 8, 8, 8, 11, 11, 15, 15, 15, 15, 3, 3, 3, 4, 4, 4, 4, 8, 8, 11, 11, 11, 11, 15, 15, 15, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 11, 11, 15, 15,
};

static const u8 u8_ARRAY_08364aac[2] = {1, 18};
static const u8 u8_ARRAY_08364aae[3] = {30, 33, 37};
static const u8 u8_ARRAY_08364ab1[8] = {40, 43, 46, 49, 53, 57, 61, 65};
static const u8 u8_ARRAY_08364ab9[3] = {68, 71, 74};
static const u8 u8_ARRAY_08364abc[3] = {77, 81, 85};
static const u8 u8_ARRAY_08364abf[3] = {89, 1, 1};
static const u8 u8_ARRAY_08364ac2[4] = {112, 115, 119, 119};

static const Coords16 ALIGNED(2) Coord16_ARRAY_08364ac6[2] = {
    {-0x900, -0x2800},
    {0x800, -0x2100},
};

static const u8 u8_ARRAY_08364ace[5] = {68, 71, 74, 93, 97};
static const u8 u8_ARRAY_08364ad3[5] = {101, 101, 101, 105, 0};

// clang-format off
// 0x08364ad8
static const motion_t sMotions[8] = {
    MOTION(DM178_GLACIERLE, 0x1B),
    MOTION(DM178_GLACIERLE, 0x0D),
    MOTION(DM178_GLACIERLE, 0x0E),
    MOTION(DM178_GLACIERLE, 0x0D),
    MOTION(DM178_GLACIERLE, 0x1B),
    MOTION(DM178_GLACIERLE, 0x0F),
    MOTION(DM178_GLACIERLE, 0x10),
    MOTION(DM178_GLACIERLE, 0x0F),
};
// clang-format on

static const u8 u8_ARRAY_08364ae8[8] = {4, 8, 24, 8, 4, 8, 24, 8};
static const s16 s16_ARRAY_08364af0[8] = {0x0800, 0x0600, 0x0400, 0x0600, 0x0800, 0x0A00, 0x0C00, 0x0A00};
static const u8 u8_ARRAY_08364b00[8] = {64, 44, 24, 42, 64, 76, 88, 76};
static const s16 s16_ARRAY_08364b08[6] = {-0x01C0, -0x01C0, -0x02C0, -0x0180, -0x0200, -0x01C0};
static const s16 s16_ARRAY_08364b14[6] = {-0x0B00, -0x2100, -0x0C00, -0x1F00, -0x0D00, -0x1400};
static const u8 u8_ARRAY_08364b20[2] = {101, 108};
static const u8 u8_ARRAY_08364b22[4] = {4, 7, 10, 10};
static const u8 u8_ARRAY_08364b26[5] = {15, 18, 21, 24, 27};

// 0x08364b2c
static const Coords32 sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(35)},
    {PIXEL(0), -PIXEL(35)},
};
