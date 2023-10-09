#include "boss.h"
#include "collision.h"
#include "element.h"
#include "global.h"
#include "overworld.h"
#include "zero.h"

void CreateGlacierleArm(struct Boss* glacierle, s32 x, s32 y);

static const u8 u8_ARRAY_08364aac[2];
static const struct Collision sCollisions[135];
static const struct Coord sElementCoord;

static void Glacierle_Init(struct Boss* p);
static void Glacierle_Update(struct Boss* p);
static void Glacierle_Die(struct Boss* p);

// clang-format off
const BossRoutine gGlacierleRoutine = {
    [ENTITY_INIT] =      Glacierle_Init,
    [ENTITY_UPDATE] =    Glacierle_Update,
    [ENTITY_DIE] =       Glacierle_Die,
    [ENTITY_DISAPPEAR] = DeleteBoss,
    [ENTITY_EXIT] =      (BossFunc)DeleteEntity,
};
// clang-format on

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
_080579C0: .4byte 0x08364A7C\n\
_080579C4:\n\
	ldr r0, _08057A0C @ =gMission\n\
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
_08057A0C: .4byte gMission\n\
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

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) {
  struct CollidableEntity* e = (struct CollidableEntity*)body->enemy->parent;
  struct Boss* p = (struct Boss*)body->parent;

  if (body->hitboxFlags & BODY_STATUS_WHITE) {
    (p->props.glacierle).unk_c8.x = (e->s).coord.x;
    (p->props.glacierle).unk_c8.y = (e->s).coord.y;
    (p->props.glacierle).shouldRightDir = (p->s).coord.x < (e->s).coord.x;
  }
}

static bool8 tryKillGlacierle(struct Boss* p) {
  u32* status = &(p->body).status;

  if (((*status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && ((gStageRun.missionStatus & MISSION_FAIL) == 0)) {
    PlaySound(SE_GLACIERLE_DEATH);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    if (*status & BODY_STATUS_SLASHED) {
      (p->s).mode[1] = 1;
    } else {
      (p->s).mode[1] = 0;
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
	bl CreateGlacierleArm\n\
	ldr r1, [r5]\n\
	ldr r2, _08057C78 @ =0xFFFFE000\n\
	adds r1, r1, r2\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateGlacierleArm\n\
	ldr r1, [r5]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	adds r1, r1, r0\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateGlacierleArm\n\
	ldr r1, [r5]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #7\n\
	adds r1, r1, r2\n\
	ldr r2, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl CreateGlacierleArm\n\
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

static void glacierle_08057d00(struct Boss* p);
static void FUN_08057d30(struct Boss* p);
static void nop_08057cfc(struct Boss* p);

static void glacierle_08057d7c(struct Boss* p);
static void glacierle_08057e20(struct Boss* p);
void glacierle_08057f38(struct Boss* p);
void glacierle_08058018(struct Boss* p);
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
void glacierle_080593c4(struct Boss* p);
void glacierle_080594dc(struct Boss* p);
void glacierle_080595ec(struct Boss* p);
void glacierle_08059674(struct Boss* p);

static void Glacierle_Update(struct Boss* p) {
  // clang-format off
  static const BossFunc sUpdates1[21] = {
      FUN_08057d30,
      nop_08057cfc,
      FUN_08057d30,
      FUN_08057d30,
      FUN_08057d30,
      FUN_08057d30,
      FUN_08057d30,
      FUN_08057d30,
      glacierle_08057d00,
      glacierle_08057d00,
      glacierle_08057d00,
      FUN_08057d30,
      glacierle_08057d00,
      glacierle_08057d00,
      glacierle_08057d00,
      glacierle_08057d00,
      glacierle_08057d00,
      glacierle_08057d00,
      nop_08057cfc,
      nop_08057cfc,
      glacierle_08057d00,
  };
  // clang-format on

  // clang-format off
  static const BossFunc sUpdates2[21] = {
      glacierle_08057d7c,
      glacierle_08057e20,
      glacierle_08057f38,
      glacierle_08058018,
      glacierle_08058168,
      glacierle_080581d8,
      glacierle_0805836c,
      glacierle_080583c4,
      glacierleHammerPunch1,
      glacierleHammerPunch2,
      glacierleHammerPunch3,
      glacierleIceRainJump,
      glacierleIceRain1,
      glacierleIceRain2,
      glacierleIceRain3,
      glacierleIceCarnival1,
      glacierleIceCarnival2,
      glacierle_080593c4,
      glacierle_080594dc,
      glacierle_080595ec,
      glacierle_08059674,
  };
  // clang-format on

  if ((p->props.glacierle).unk_b8 != NULL) {
    if (isKilled(&((p->props.glacierle).unk_b8)->s)) {
      (p->props.glacierle).unk_b8 = NULL;
    }
  }
  if (tryKillGlacierle(p)) {
    return;
  }
  (sUpdates1[(p->s).mode[1]])(p);
  (sUpdates2[(p->s).mode[1]])(p);
}

// --------------------------------------------

void glacierleDeath0(struct Boss* p);
void glacierleDeath1(struct Boss* p);

static void Glacierle_Die(struct Boss* p) {
  static const BossFunc sDeads[2] = {
      glacierleDeath0,
      glacierleDeath1,
  };
  (sDeads[(p->s).mode[1]])(p);
}

// --------------------------------------------

static void nop_08057cfc(struct Boss* p) {
  // nop
  return;
}

static void glacierle_08057d00(struct Boss* p) {
  if (((p->body).status & BODY_STATUS_WHITE) && ((p->props.glacierle).unk_b8 == NULL)) {
    (p->props.glacierle).unk_b8 = ApplyElementEffect(25, &p->s, &sElementCoord);
  }
}

static void FUN_08057d30(struct Boss* p) {
  if ((p->body).status & BODY_STATUS_WHITE) {
    if ((p->body).status & BODY_STATUS_RECOILED) {
      (p->s).mode[1] = 20;
      (p->s).mode[2] = 0;
    }
    if ((p->props.glacierle).unk_b8 == NULL) {
      (p->props.glacierle).unk_b8 = ApplyElementEffect(25, &p->s, &sElementCoord);
      if ((p->props.glacierle).unk_b8 != NULL) {
        (p->s).mode[1] = 19;
        (p->s).mode[2] = 0;
      }
    }
  }
}

// --------------------------------------------

static void glacierle_08057d7c(struct Boss* p) {
  switch ((p->s).mode[2]) {
    case 0: {
      (p->s).work[2] = 24;
      SetMotion(&p->s, MOTION(DM178_GLACIERLE, 0));
      (p->s).mode[2]++;
      FALLTHROUGH;
    }
    case 1: {
      bool8 isZeroRight;
      SetDDP(&p->body, &sCollisions[1]);
      UpdateMotionGraphic(&p->s);

      isZeroRight = (p->s).coord.x < (pZero2->s).coord.x;
      if ((p->s).flags & X_FLIP) {
        if (!isZeroRight) goto _MODE2;
      } else if (isZeroRight) {
      _MODE2:
        (p->s).mode[1] = 2;
        (p->s).mode[2] = 0;
      }

      (p->s).work[2]--;
      if ((p->s).work[2] == 0) {
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
	bl UpdateMotionGraphic\n\
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
	bl UpdateMotionGraphic\n\
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
	bl UpdateMotionGraphic\n\
_08057F2C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08057F34: .4byte gStageRun\n\
 .syntax divided\n");
}

INCASM("asm/boss/glacierle.inc");

// --------------------------------------------

static const struct Collision sCollisions[135] = {
    [0] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 0,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(1), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [2] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(20), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [3] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(1), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [4] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(6), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [5] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(30), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [6] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(6), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [7] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [8] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(42), -PIXEL(34), PIXEL(18), PIXEL(19)},
    },
    [9] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [10] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [11] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(38), -PIXEL(58), PIXEL(18), PIXEL(19)},
    },
    [12] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [13] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [14] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [15] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [16] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(38), -PIXEL(37), PIXEL(18), PIXEL(19)},
    },
    [17] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(1), -PIXEL(24), PIXEL(34), PIXEL(47)},
    },
    [18] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [19] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(31), PIXEL(18), PIXEL(19)},
    },
    [20] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [21] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [22] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(14), -PIXEL(12), PIXEL(18), PIXEL(19)},
    },
    [23] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(7), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [24] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [25] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(14), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [26] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [27] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [28] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(19), -PIXEL(8), PIXEL(18), PIXEL(19)},
    },
    [29] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [30] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [31] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(27), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [32] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [33] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [34] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 4,
      unk_0c : 0x00000001,
      range : {PIXEL(35), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [35] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(35), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [36] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [37] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [38] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(27), -PIXEL(7), PIXEL(18), PIXEL(19)},
    },
    [39] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [40] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [41] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(19), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [42] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [43] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [44] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(32), -PIXEL(21), PIXEL(18), PIXEL(19)},
    },
    [45] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [46] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [47] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(3), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [48] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [49] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [50] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(17), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [51] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(20), -PIXEL(13), PIXEL(18), PIXEL(19)},
    },
    [52] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [53] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [54] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(28), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [55] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(40), -PIXEL(22), PIXEL(18), PIXEL(19)},
    },
    [56] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [57] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [58] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(42), -PIXEL(26), PIXEL(18), PIXEL(19)},
    },
    [59] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(34), -PIXEL(19), PIXEL(18), PIXEL(19)},
    },
    [60] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [61] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [62] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(30), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [63] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(31), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [64] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [65] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [66] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(3), -PIXEL(10), PIXEL(18), PIXEL(19)},
    },
    [67] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [68] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [69] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(11), -PIXEL(5), PIXEL(18), PIXEL(19)},
    },
    [70] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [71] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [72] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(38), -PIXEL(12), PIXEL(18), PIXEL(19)},
    },
    [73] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [74] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [75] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(39), -PIXEL(17), PIXEL(18), PIXEL(19)},
    },
    [76] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [77] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(28), PIXEL(34), PIXEL(47)},
    },
    [78] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(37), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [79] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(15), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [80] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(28), PIXEL(34), PIXEL(47)},
    },
    [81] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [82] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(35), -PIXEL(74), PIXEL(18), PIXEL(19)},
    },
    [83] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(4), -PIXEL(74), PIXEL(18), PIXEL(19)},
    },
    [84] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [85] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [86] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(23), -PIXEL(70), PIXEL(18), PIXEL(19)},
    },
    [87] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(19), -PIXEL(70), PIXEL(18), PIXEL(19)},
    },
    [88] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(0), -PIXEL(33), PIXEL(34), PIXEL(47)},
    },
    [89] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(4), -PIXEL(21), PIXEL(34), PIXEL(47)},
    },
    [90] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(32), -PIXEL(14), PIXEL(18), PIXEL(19)},
    },
    [91] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(15), -PIXEL(11), PIXEL(18), PIXEL(19)},
    },
    [92] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(4), -PIXEL(21), PIXEL(34), PIXEL(47)},
    },
    [93] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [94] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(38), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [95] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(22), -PIXEL(19), PIXEL(18), PIXEL(19)},
    },
    [96] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [97] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [98] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(27), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [99] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(14), -PIXEL(20), PIXEL(18), PIXEL(19)},
    },
    [100] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(31), PIXEL(34), PIXEL(47)},
    },
    [101] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [102] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(7), -PIXEL(90), PIXEL(18), PIXEL(19)},
    },
    [103] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(20), -PIXEL(8), PIXEL(18), PIXEL(19)},
    },
    [104] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [105] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [106] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {-PIXEL(7), -PIXEL(90), PIXEL(18), PIXEL(19)},
    },
    [107] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [108] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [109] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(26), -PIXEL(67), PIXEL(18), PIXEL(19)},
    },
    [110] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(12), -PIXEL(21), PIXEL(18), PIXEL(19)},
    },
    [111] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(30), PIXEL(34), PIXEL(47)},
    },
    [112] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(2), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [113] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(26), -PIXEL(9), PIXEL(18), PIXEL(19)},
    },
    [114] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {-PIXEL(2), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [115] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [116] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(34), -PIXEL(31), PIXEL(18), PIXEL(19)},
    },
    [117] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(57), -PIXEL(37), PIXEL(18), PIXEL(19)},
    },
    [118] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [119] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [120] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(19), -PIXEL(49), PIXEL(18), PIXEL(19)},
    },
    [121] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(50), -PIXEL(64), PIXEL(18), PIXEL(19)},
    },
    [122] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [123] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [124] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(4), -PIXEL(41), PIXEL(18), PIXEL(19)},
    },
    [125] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [126] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [127] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [128] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [129] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(10), -PIXEL(10), PIXEL(18), PIXEL(19)},
    },
    [130] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [131] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x00,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 3,
      unk_0c : 0x00000001,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
    [132] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 2,
      unk_0c : 0x00000001,
      range : {-PIXEL(26), -PIXEL(46), PIXEL(18), PIXEL(19)},
    },
    [133] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 3,
      unk_04 : 0x00,
      element : 0x00,
      nature : 0x04,
      comboLv : 0,
      hitzone : 0,
      hardness : 0x00,
      unk_0a : 0x00,
      remaining : 1,
      unk_0c : 0x00000001,
      range : {PIXEL(48), -PIXEL(50), PIXEL(18), PIXEL(19)},
    },
    [134] = {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : 2,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 255,
      hitzone : 8,
      hardness : 0x08,
      unk_0a : 0x00,
      remaining : 0,
      unk_0c : 0x00000000,
      range : {PIXEL(3), -PIXEL(22), PIXEL(34), PIXEL(47)},
    },
};

// --------------------------------------------

static const struct Coord sElementCoord = {PIXEL(0), -PIXEL(16)};

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

static const struct Coord16 ALIGNED(2) Coord16_ARRAY_08364ac6[2] = {
    {-0x900, -0x2800},
    {0x800, -0x2100},
};

static const u8 u8_ARRAY_08364ace[5] = {68, 71, 74, 93, 97};
static const u8 u8_ARRAY_08364ad3[5] = {101, 101, 101, 105, 0};

// clang-format off
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

static const struct Coord sExplosionCoords[2] = {
    {PIXEL(0), -PIXEL(35)},
    {PIXEL(0), -PIXEL(35)},
};
