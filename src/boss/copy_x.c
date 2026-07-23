#include "boss/copy_x.h"

#include "boss.h"
#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "palette_animation.h"

struct Entity* CreateVFX55(struct Boss* e, u8 r1, u8 r2);

void copyx_08057744(BossCopyX* p);

static void CopyX_Init(BossCopyX* p);
static void CopyX_Update(BossCopyX* p);
static void CopyX_Die(BossCopyX* p);

// clang-format off
const BossRoutine gCopyXRoutine = {
    [ENTITY_INIT] =      (void*)CopyX_Init,
    [ENTITY_UPDATE] =    (void*)CopyX_Update,
    [ENTITY_DIE] =       (void*)CopyX_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteBoss,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// --------------------------------------------

static void Unused_CreateCopyX(Coords32* c) {
  BossCopyX* p = AllocEntityLast(gBossHeaderPtr);
  if (p != NULL) {
    INIT_BOSS_ROUTINE(p, BOSS_COPY_X);
    (p->coord).x = c->x, (p->coord).y = c->y;
    p->work[0] = 0, p->work[1] = 0;
  }
}

// --------------------------------------------

static const struct Collision sCollisions[];

NAKED static void CopyX_Init(BossCopyX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r7, r0, #0\n\
	movs r4, #0xeb\n\
	lsls r4, r4, #3\n\
	ldr r5, _08055620 @ =gStaticMotionGraphics\n\
	adds r0, r4, r5\n\
	ldr r1, _08055624 @ =wStaticGraphicTilenums\n\
	mov sb, r1\n\
	adds r1, #0xbc\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	mov r8, r2\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	ldr r6, _08055628 @ =gStaticMotionGraphics+12\n\
	adds r4, r4, r6\n\
	ldr r0, _0805562C @ =wStaticMotionPalIDs\n\
	mov sl, r0\n\
	adds r0, #0xbc\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055630 @ =0x00000744\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xba\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xba\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055634 @ =0x0000071C\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xb6\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xb6\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xe6\n\
	lsls r4, r4, #3\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xb8\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xb8\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _08055638 @ =0x0000076C\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xbe\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xbe\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #3\n\
	adds r0, r4, r5\n\
	mov r1, sb\n\
	adds r1, #0xc0\n\
	ldrh r1, [r1]\n\
	ldrh r2, [r0, #6]\n\
	lsrs r2, r2, #6\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xc0\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	ldr r4, _0805563C @ =0x00000794\n\
	adds r5, r4, r5\n\
	mov r0, sb\n\
	adds r0, #0xc2\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r5, #6]\n\
	lsrs r0, r0, #6\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	add r1, r8\n\
	adds r0, r5, #0\n\
	bl LoadGraphic\n\
	adds r4, r4, r6\n\
	mov r0, sl\n\
	adds r0, #0xc2\n\
	ldrh r1, [r0]\n\
	ldrb r0, [r4, #7]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #5\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r1, r2\n\
	adds r0, r4, #0\n\
	bl LoadPalette\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #1\n\
	movs r5, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08055640 @ =0x0000B319\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	adds r0, r7, #0\n\
	bl UpdateEntityAnim\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	strb r5, [r0]\n\
	adds r2, r7, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _08055644 @ =sCollisions\n\
	adds r0, r7, #0\n\
	movs r2, #0x40\n\
	bl ResetBossBody\n\
	ldr r1, _08055648 @ =CopyX_OnDamage\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_0800a134\n\
	adds r1, r7, #0\n\
	adds r1, #0xb8\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_0800a31c\n\
	adds r1, r7, #0\n\
	adds r1, #0xb4\n\
	str r0, [r1]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r7, #0\n\
	adds r1, #0xd4\n\
	str r0, [r1]\n\
	str r0, [r7, #0x58]\n\
	subs r1, #0x18\n\
	ldr r0, [r7, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r7, #0x58]\n\
	str r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xc5\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r1, #0xa\n\
	movs r4, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xcc\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	adds r1, #0xe\n\
	movs r0, #0x3c\n\
	strh r0, [r1]\n\
	adds r1, #5\n\
	movs r0, #0x30\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xcf\n\
	strb r4, [r0]\n\
	subs r1, #1\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xde\n\
	strb r4, [r0]\n\
	subs r1, #0xc\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0xd2\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	strh r1, [r0]\n\
	str r5, [r7, #0x2c]\n\
	adds r1, r7, #0\n\
	adds r1, #0xce\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	movs r1, #1\n\
	movs r2, #0\n\
	bl CreateProjectile28\n\
	ldr r1, _0805564C @ =gBossFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	strb r4, [r7, #0xd]\n\
	strb r1, [r7, #0xe]\n\
	adds r0, r7, #0\n\
	bl CopyX_Update\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08055620: .4byte gStaticMotionGraphics\n\
_08055624: .4byte wStaticGraphicTilenums\n\
_08055628: .4byte gStaticMotionGraphics+12\n\
_0805562C: .4byte wStaticMotionPalIDs\n\
_08055630: .4byte 0x00000744\n\
_08055634: .4byte 0x0000071C\n\
_08055638: .4byte 0x0000076C\n\
_0805563C: .4byte 0x00000794\n\
_08055640: .4byte 0x0000B319\n\
_08055644: .4byte sCollisions\n\
_08055648: .4byte CopyX_OnDamage\n\
_0805564C: .4byte gBossFnTable\n\
 .syntax divided\n");
}

static void copyx_080557a4(struct Boss* p);
static void copyxMode1(struct Boss* p);
static void copyxNeutral(struct Boss* p);
static void copyxNextMode(Object* p);
static void copyxMode4(BossCopyX* p);
void copyxMode5(struct Boss* p);
void copyxMode6(struct Boss* p);
void copyxMode7(struct Boss* p);
void copyxMode8(struct Boss* p);
void copyxMode9(struct Boss* p);
void copyxMode10(struct Boss* p);
void copyxMode11(struct Boss* p);
void copyxMode12(struct Boss* p);
void copyxJumpForNovaStrike(struct Boss* p);
void copyxNovaStrike2(struct Boss* p);
void copyxNovaStrike3(struct Boss* p);
void copyxMode16(struct Boss* p);
void copyxMode17(struct Boss* p);
void copyxMode18(struct Boss* p);
void copyxMode19(struct Boss* p);
void copyx_08056508(struct Boss* p);
void copyx_080565c0(struct Boss* p);
void copyx_080566b0(struct Boss* p);
void copyx_08056724(struct Boss* p);
void copyx_08056794(struct Boss* p);
void copyx_080568bc(struct Boss* p);
void copyx_08056908(struct Boss* p);
void FUN_080569a4(struct Boss* p);
void copyx_080569e4(struct Boss* p);
void FUN_08056a80(struct Boss* p);
void copyx_08056ac0(struct Boss* p);
void copyx_08056b6c(struct Boss* p);
void copyx_08056bd0(struct Boss* p);
void copyxKnockBackDamage(struct Boss* p);
void FUN_08056d58(struct Boss* p);
void copyxRaisingExcharge(struct Boss* p);
void copyxMode36(struct Boss* p);
void copyx_08057094(struct Boss* p);
void copyxMode38(struct Boss* p);

static void CopyX_Update(BossCopyX* p) {
  // clang-format off
  static const BossFunc sUpdates[39] = {
      [0] =  (void*)copyx_080557a4,
      [1] =  (void*)copyxMode1,
      [2] =  (void*)copyxNeutral,
      [3] =  (void*)copyxNextMode,
      [4] =  (void*)copyxMode4,
      [5] =  (void*)copyxMode5,
      [6] =  (void*)copyxMode6,
      [7] =  (void*)copyxMode7,
      [8] =  (void*)copyxMode8,
      [9] =  (void*)copyxMode9,
      [10] = (void*)copyxMode10,
      [11] = (void*)copyxMode11,
      [12] = (void*)copyxMode12,
      [13] = (void*)copyxJumpForNovaStrike,
      [14] = (void*)copyxNovaStrike2,
      [15] = (void*)copyxNovaStrike3,
      [16] = (void*)copyxMode16,
      [17] = (void*)copyxMode17,
      [18] = (void*)copyxMode18,
      [19] = (void*)copyxMode19,
      [20] = (void*)copyx_08056508,
      [21] = (void*)copyx_080565c0,
      [22] = (void*)copyx_080566b0,
      [23] = (void*)copyx_08056724,
      [24] = (void*)copyx_08056794,
      [25] = (void*)copyx_080568bc,
      [26] = (void*)copyx_08056908,
      [27] = (void*)FUN_080569a4,
      [28] = (void*)copyx_080569e4,
      [29] = (void*)FUN_08056a80,
      [30] = (void*)copyx_08056ac0,
      [31] = (void*)copyx_08056b6c,
      [32] = (void*)copyx_08056bd0,
      [33] = (void*)copyxKnockBackDamage,
      [34] = (void*)FUN_08056d58,
      [35] = (void*)copyxRaisingExcharge,
      [36] = (void*)copyxMode36,
      [37] = (void*)copyx_08057094,
      [38] = (void*)copyxMode38,
  };
  // clang-format on

  if ((((p->body).status & BODY_STATUS_DEAD) || ((p->body).hp == 0)) && !(gStageRun.missionStatus & MISSION_PLAYER_DEAD)) {
    StartPaletteAnimation(92, 640);
    StepPaletteAnimation(92);
    RemovePaletteAnimation(92);
    SET_BOSS_ROUTINE(p, ENTITY_DIE);
    p->mode[2] = 1;
    EXIT_BODY(p);
    CopyX_Die(p);
    return;
  }

  copyx_08057744(p);
  if (p->mode[1] != 33) {
    p->unk_dd = (p->body).hp - 16;
    if (p->unk_dd < 0) {
      p->unk_dd = 0;
    }
  }

  // Check if Copy X is flinching
  if (((p->body).status & BODY_STATUS_WHITE) && (((p->body).unk_23 != 0) || ((p->body).status & (BODY_STATUS_B14 | BODY_STATUS_B15)))) {
    if ((u8)(p->mode[1] - 5) > 1) {
      if (p->mode[1] != 9) {
        if (p->mode[1] != 10) {
          if (p->mode[1] != 11) {
            p->mode[1] = 33;  // flinch(0x08056c14)
            p->mode[2] = 1;
            p->mode[3] = 33;
          }
        }
      }
    }
  }

  (sUpdates[p->mode[1]])((void*)p);
  StartPaletteAnimation(92 + p->unk_c5, 640);
  StepPaletteAnimation(92 + p->unk_c5);
  RemovePaletteAnimation(92 + p->unk_c5);
  UpdateSpriteAnimation(p);
}

void copyx_08057204(BossCopyX* p);
void copyx_08057418(BossCopyX* p);
void copyx_08057520(BossCopyX* p);
void copyx_08057590(BossCopyX* p);
void copyx_0805763c(BossCopyX* p);

static void CopyX_Die(BossCopyX* p) {
  // clang-format off
  static void (*const sDeads[5])(BossCopyX*) = {
      [0] = copyx_08057204,
      [1] = copyx_08057418,
      [2] = copyx_08057520,
      [3] = copyx_08057590,
      [4] = copyx_0805763c,
  };
  // clang-format on
  copyx_08057744(p);
  (sDeads[p->mode[1]])(p);
}

// --------------------------------------------

static void copyx_080557a4(struct Boss* p) {
  if (p->scriptEntity->flags & (1 << 0)) {
    p->mode[1] = 1, p->mode[2] = 1;
  }
}

static void copyxMode1(struct Boss* p) {
  if (p->mode[2] != 0) {
    SetSpriteAnimation(p, MOTION(DM179_COPY_X, 26));
    CreateVFX55(p, 0, 0);
    p->mode[2] = 0, p->mode[3] = 0;
    p->work[2] = 0;
  }
  if ((p->work[2] == 0) && (p->motion.cmdIdx == 6)) {
    PlaySound(SE_COPYX_MODE_CHANGE);
    p->work[2]++;
  }
  if (p->mode[3] == 0) {
    if (IsSpriteAnimEnd(p)) p->mode[3]++;
  } else if (!(gStageRun.vm.active & VM_ACTIVE)) {
    SetSpriteAnimation(p, MOTION(DM179_COPY_X, 0));
    p->mode[1] = 2, p->mode[2] = 1;
  }
}

// 0x08055848
NAKED static void copyxNeutral(struct Boss* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _0805587C @ =RNG_0202f388\n\
	ldr r1, [r2]\n\
	ldr r0, _08055880 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08055884 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r2]\n\
	lsrs r6, r0, #0x11\n\
	movs r0, #0x1f\n\
	ands r6, r0\n\
	ldr r0, _08055888 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _0805588C\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	adds r0, r0, r2\n\
	b _08055890\n\
	.align 2, 0\n\
_0805587C: .4byte RNG_0202f388\n\
_08055880: .4byte 0x000343FD\n\
_08055884: .4byte 0x00269EC3\n\
_08055888: .4byte pZero2\n\
_0805588C:\n\
	ldr r7, _080558DC @ =0xFFFFC000\n\
	adds r0, r0, r7\n\
_08055890:\n\
	subs r1, r1, r0\n\
	mov r8, r1\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	movs r3, #0\n\
	ldr r0, _080558E0 @ =pZero2\n\
	ldr r2, [r0]\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080558AA\n\
	movs r3, #1\n\
_080558AA:\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r3, [r0]\n\
	movs r3, #0\n\
	ldr r1, [r2, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	cmp r1, r0\n\
	ble _080558BC\n\
	movs r3, #1\n\
_080558BC:\n\
	adds r4, r5, #0\n\
	adds r4, #0x4a\n\
	lsls r2, r3, #4\n\
	ldrb r1, [r4]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r4]\n\
	cmp r3, #0\n\
	beq _080558E4\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080558EA\n\
	.align 2, 0\n\
_080558DC: .4byte 0xFFFFC000\n\
_080558E0: .4byte pZero2\n\
_080558E4:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080558EA:\n\
	strb r0, [r5, #0xa]\n\
	ldr r0, _0805591C @ =gStageRun+232\n\
	adds r4, r5, #0\n\
	adds r4, #0x54\n\
	adds r1, r4, #0\n\
	bl Camera_GetDistance\n\
	adds r3, r0, #0\n\
	mov ip, r4\n\
	adds r4, #0x50\n\
	cmp r3, #0\n\
	bne _08055920\n\
	adds r2, r5, #0\n\
	adds r2, #0xce\n\
	ldrb r1, [r2]\n\
	movs r7, #0\n\
	ldrsh r0, [r4, r7]\n\
	cmp r1, r0\n\
	ble _08055920\n\
	movs r0, #0x23\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
	strb r3, [r2]\n\
	b _08055ABC\n\
	.align 2, 0\n\
_0805591C: .4byte gStageRun+232\n\
_08055920:\n\
	adds r7, r5, #0\n\
	adds r7, #0xd8\n\
	movs r0, #0\n\
	ldrsh r1, [r7, r0]\n\
	movs r2, #0\n\
	ldrsh r0, [r4, r2]\n\
	cmp r1, r0\n\
	ble _08055942\n\
	adds r0, r5, #0\n\
	bl copyx_080578e0\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
	ldrh r0, [r4]\n\
	subs r0, #8\n\
	strh r0, [r7]\n\
	b _08055ABC\n\
_08055942:\n\
	adds r0, r5, #0\n\
	adds r0, #0xcd\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0805595A\n\
	adds r0, r5, #0\n\
	adds r0, #0xc6\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0805595A\n\
	movs r0, #0x11\n\
	b _08055AB6\n\
_0805595A:\n\
	ldr r0, _0805597C @ =gStageRun+232\n\
	mov r1, ip\n\
	bl Camera_GetDistance\n\
	cmp r0, #0\n\
	beq _080559A0\n\
	cmp r6, #0xf\n\
	bhi _08055984\n\
	movs r0, #9\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #0xd\n\
	strb r0, [r5, #0xf]\n\
	ldr r0, _08055980 @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x54]\n\
	b _080559CE\n\
	.align 2, 0\n\
_0805597C: .4byte gStageRun+232\n\
_08055980: .4byte pZero2\n\
_08055984:\n\
	movs r0, #9\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #0xb\n\
	strb r0, [r5, #0xf]\n\
	ldr r0, _0805599C @ =pZero2\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x54]\n\
	ldr r1, [r5, #0x54]\n\
	subs r0, r0, r1\n\
	movs r1, #0x2e\n\
	b _08055A6E\n\
	.align 2, 0\n\
_0805599C: .4byte pZero2\n\
_080559A0:\n\
	ldr r2, _080559E4 @ =pZero2\n\
	ldr r3, [r2]\n\
	ldr r1, [r5, #0x58]\n\
	ldr r0, [r3, #0x58]\n\
	subs r1, r1, r0\n\
	movs r0, #0x90\n\
	lsls r0, r0, #7\n\
	adds r7, r2, #0\n\
	cmp r1, r0\n\
	ble _080559EC\n\
	movs r7, #0\n\
	ldrsh r0, [r4, r7]\n\
	cmp r6, #1\n\
	bls _08055A62\n\
	cmp r6, #0x13\n\
	bls _08055A84\n\
	cmp r6, #0x19\n\
	bhi _08055AB4\n\
	movs r0, #9\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #0xd\n\
	strb r0, [r5, #0xf]\n\
	ldr r1, [r3, #0x54]\n\
_080559CE:\n\
	ldr r0, [r5, #0x54]\n\
	subs r0, r1, r0\n\
	cmp r0, #0\n\
	bge _080559D8\n\
	adds r0, #0x7f\n\
_080559D8:\n\
	asrs r0, r0, #7\n\
	str r0, [r5, #0x5c]\n\
	ldr r0, _080559E8 @ =0xFFFFFA00\n\
	str r0, [r5, #0x60]\n\
	b _08055AB8\n\
	.align 2, 0\n\
_080559E4: .4byte pZero2\n\
_080559E8: .4byte 0xFFFFFA00\n\
_080559EC:\n\
	ldr r2, [r3, #0x54]\n\
	ldr r0, [r5, #0x54]\n\
	subs r1, r2, r0\n\
	adds r3, r0, #0\n\
	cmp r1, #0\n\
	blt _08055A02\n\
	movs r0, #0xc8\n\
	lsls r0, r0, #7\n\
	cmp r1, r0\n\
	bgt _08055A0C\n\
	b _08055A36\n\
_08055A02:\n\
	subs r1, r3, r2\n\
	movs r0, #0xc8\n\
	lsls r0, r0, #7\n\
	cmp r1, r0\n\
	ble _08055A36\n\
_08055A0C:\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0x1f\n\
	bgt _08055A1E\n\
_08055A14:\n\
	cmp r6, #1\n\
	bls _08055A62\n\
_08055A18:\n\
	cmp r6, #0x13\n\
	bls _08055A84\n\
	b _08055A8C\n\
_08055A1E:\n\
	cmp r0, #0x2f\n\
	bgt _08055A2C\n\
	cmp r6, #0\n\
	beq _08055A50\n\
	cmp r6, #2\n\
	bls _08055A62\n\
	b _08055A18\n\
_08055A2C:\n\
	cmp r6, #1\n\
	bls _08055A50\n\
	cmp r6, #5\n\
	bls _08055A62\n\
	b _08055A18\n\
_08055A36:\n\
	movs r2, #0\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #0x1f\n\
	ble _08055A14\n\
	cmp r0, #0x2f\n\
	bgt _08055A4C\n\
	cmp r6, #0\n\
	beq _08055A50\n\
	cmp r6, #2\n\
	bls _08055A62\n\
	b _08055A18\n\
_08055A4C:\n\
	cmp r6, #1\n\
	bhi _08055A5E\n\
_08055A50:\n\
	movs r0, #3\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #2\n\
	strb r0, [r5, #0xf]\n\
	movs r0, #0x10\n\
	strb r0, [r5, #0x12]\n\
	b _08055AB8\n\
_08055A5E:\n\
	cmp r6, #3\n\
	bhi _08055A80\n\
_08055A62:\n\
	movs r0, #9\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #0xb\n\
	strb r0, [r5, #0xf]\n\
	mov r0, r8\n\
	movs r1, #0x28\n\
_08055A6E:\n\
	bl __divsi3\n\
	str r0, [r5, #0x5c]\n\
	ldr r0, _08055A7C @ =0xFFFFFB00\n\
	str r0, [r5, #0x60]\n\
	b _08055AB8\n\
	.align 2, 0\n\
_08055A7C: .4byte 0xFFFFFB00\n\
_08055A80:\n\
	cmp r6, #0x10\n\
	bhi _08055A8C\n\
_08055A84:\n\
	adds r0, r5, #0\n\
	bl copyx_080577c8\n\
	b _08055AB8\n\
_08055A8C:\n\
	cmp r6, #0x19\n\
	bhi _08055AB4\n\
	movs r0, #9\n\
	strb r0, [r5, #0xd]\n\
	movs r0, #0xd\n\
	strb r0, [r5, #0xf]\n\
	ldr r0, [r7]\n\
	ldr r0, [r0, #0x54]\n\
	subs r0, r0, r3\n\
	cmp r0, #0\n\
	bge _08055AA4\n\
	adds r0, #0x3f\n\
_08055AA4:\n\
	asrs r0, r0, #6\n\
	str r0, [r5, #0x5c]\n\
	ldr r0, _08055AB0 @ =0xFFFFFE00\n\
	str r0, [r5, #0x60]\n\
	b _08055AB8\n\
	.align 2, 0\n\
_08055AB0: .4byte 0xFFFFFE00\n\
_08055AB4:\n\
	movs r0, #6\n\
_08055AB6:\n\
	strb r0, [r5, #0xd]\n\
_08055AB8:\n\
	movs r0, #1\n\
	strb r0, [r5, #0xe]\n\
_08055ABC:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
 .syntax divided\n");
}

static void copyxNextMode(Object* p) {
  UpdateSpriteAnimation(p);
  if (--p->work[2] == 0xFF) {
    p->mode[1] = p->mode[3];
    p->mode[2] = 1;
  }
}

// 0x08055aec
static void copyxMode4(BossCopyX* p) {
  UpdateSpriteAnimation(p);
  p->unk_c6 = 1;
  p->mode[1] = 3, p->mode[2] = 1, p->mode[3] = 2;
  {
    s16 hp = (p->body).hp;
    if (hp < 32) {
      p->work[2] = 8;
    } else if (hp < 48) {
      p->work[2] = 4;
    } else {
      p->work[2] = 2;
    }
  }
}

INCASM("asm/boss/copy_x.inc");

// 0x08363c18
static const struct Collision sCollisions[10] = {
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(0), -PIXEL(18), PIXEL(16), PIXEL(36)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      nature : BODY_NATURE_B2,
      hitzone : 5,
      hardness : METAL,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      hardness : METAL,
      remaining : 0,
      layer : 0xFFFFFFFF,
      range : {PIXEL(12), -PIXEL(24), PIXEL(8), PIXEL(20)},
    },
    {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      atkType : 0x00,
      hitzone : 5,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(8), -PIXEL(8), PIXEL(8), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ENEMY,
      special : CS_BOSS,
      damage : 2,
      LAYER(0xFFFFFFFF),
      hitzone : 5,
      remaining : 0,
      range : {PIXEL(8), -PIXEL(8), PIXEL(8), PIXEL(16)},
    },
};
