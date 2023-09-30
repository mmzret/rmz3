#include "collision.h"
#include "entity.h"
#include "global.h"
#include "mission.h"
#include "motion.h"
#include "overworld.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"
#include "zero.h"

#define BUSTER_BLIZZARD_ARROW 5

static bool8 isBlocked(struct Weapon *w);
static void onHit(struct Body *body, struct Coord *r1 UNUSED, struct Coord *r2 UNUSED);
static void Buster_Update(struct Weapon *w);
static u8 shouldDelete(struct Weapon *w);
static bool8 buster_08037f78(struct Weapon *w, const struct Rect *size);
static const WeaponFunc sBulletUpdate[6];
static const motion_t sFullBulletMotions[4];
static const struct Rect sFullBulletSize;

NAKED void MenuExit_Buster(struct Weapon *w) { INCCODE("asm/todo/MenuExit_Buster.inc"); }

WIP struct Weapon *CreateWeaponBuster(struct Zero *z, struct Coord *c, u8 charge, bool8 xflip, bool8 yflip) {
#if MODERN
  struct Weapon *w;
  struct Buster_b4 *b4;

  KillAllWeapons(DeleteSaber);
  w = (struct Weapon *)AllocEntityFirst(gWeaponHeaderPtr);
  if (w != NULL) {
    INIT_WEAPON_ROUTINE(w, WEAPON_MOVE_Z_BUSTER);
    (w->s).flags2 &= ~ENTITY_FLAGS2_B6;
    (w->s).taskCol = 16;
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      (w->s).tileNum = gWeaponTileNum[0];
      (w->s).palID = 1;
      SetWeaponElement(0, gSaberElements[(z->unk_b4).status.element]);
    } else {
      (w->s).tileNum = gWeaponTileNum[1];
      (w->s).palID = 1;
      SetWeaponElement(1, gSaberElements[(z->unk_b4).status.element]);
    }
    b4 = (struct Buster_b4 *)(&w->unk_b4);
    b4->z = z;
    b4->c.x = c->x, b4->c.y = c->y;
    (w->s).coord.x = (z->s).coord.x + c->x;
    (w->s).coord.y = (z->s).coord.y + c->y;
    (w->s).work[0] = charge;
    (w->s).work[1] = 0;
    if (xflip) {
      (w->s).flags |= X_FLIP;
    } else {
      (w->s).flags &= ~X_FLIP;
    }
    (w->s).spr.xflip = xflip;
    (w->s).spr.oam.xflip = xflip;
    if (yflip) {
      (w->s).flags |= Y_FLIP;
    } else {
      (w->s).flags &= ~Y_FLIP;
    }
    (w->s).spr.yflip = yflip;
    (w->s).spr.oam.yflip = yflip;
    b4->props[1] = (z->unk_b4).status.element;
  }
  return w;
#else
  INCCODE("asm/wip/CreateWeaponBuster.inc");
#endif
}

// --------------------------------------------

static void initLemonBullet(struct Weapon *w);
static void initSemiBullet(struct Weapon *w);
static void initFullBullet(struct Weapon *w);
static void initLaserShot(struct Weapon *w);
static void initBurstShotBullet(struct Weapon *w);
static void initBlizzardArrowBullet(struct Weapon *w);

static void Buster_Init(struct Weapon *w) {
  // clang-format off
  static const WeaponFunc sInitalizer[6] = {
      initLemonBullet,
      initSemiBullet,
      initFullBullet,
      initLaserShot,
      initBurstShotBullet,
      initBlizzardArrowBullet,
  };
  // clang-format on
  struct Buster_b4 *b4;
  struct Zero *z;
  struct Body *body;
  BodyFunc fn;

  SET_WEAPON_ROUTINE(w, ENTITY_MAIN);
  (sInitalizer[(w->s).work[0]])(w);
  b4 = (struct Buster_b4 *)&w->unk_b4;
  b4->props[0] = 0;
  b4->props[3] = 1;

  z = b4->z;
  z->bulletCount++;

  fn = onHit;
  body = &w->body;
  body->fn = fn;

  Buster_Update(w);
}

// --------------------------------------------

static void LemonBullet_Update(struct Weapon *w);

static void Buster_Update(struct Weapon *w) {
  struct Buster_b4 *b4 = (struct Buster_b4 *)&w->unk_b4;
  if (b4->props[0] != 0) {
    if ((w->s).work[0] == BUSTER_BLIZZARD_ARROW) {
      (w->body).status = 0;
      (w->body).prevStatus = 0;
      (w->body).invincibleTime = 0;
      (w->s).flags &= ~COLLIDABLE;
      (b4->props)[0] = 0;
      return;
    }

    (w->s).flags &= ~DISPLAY;
    (w->s).flags &= ~FLIPABLE;
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    SET_WEAPON_ROUTINE(w, ENTITY_DISAPPEAR);
    return;
  }

  (sBulletUpdate[(w->s).work[0]])(w);
  UpdateMotionGraphic(&w->s);
}

static void Buster_Die(struct Weapon *w) {
  (w->body).status = 0;
  (w->body).prevStatus = 0;
  (w->body).invincibleTime = 0;
  (w->s).flags &= ~COLLIDABLE;
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
}

static void Buster_Delete(struct Weapon *w) {
  (w->unk_b4.z)->bulletCount--;
  DeleteEntity(&w->s);
}

static const struct Collision gLemonBulletCollisions[2];

WIP static void initLemonBullet(struct Weapon *w) {
#if MODERN
  struct Body *body;
  struct Zero *z = (w->unk_b4).z;

  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);

  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;

  switch (gSystemSavedataManager.bullet) {
    case BULLET_MOD_BLACK: {
      SetMotion(&w->s, MOTION(0x85, 0x01));
      break;
    }
    case BULLET_MOD_REALISTIC: {
      SetMotion(&w->s, MOTION(0x85, 0x02));
      break;
    }
    default: {
      SetMotion(&w->s, MOTION(0x85, 0x00));
      break;
    }
  }
  PlaySound(SE_Z_BUSTER);

  bool16 isVShot = FALSE;
  if ((w->unk_b4).props[1][1] == ELEMENT_THUNDER) {
    struct Zero_b4 *b4 = &(z->unk_b4);
    isVShot = ((b4->status).exSkill & (1 << EXSKILL_ID_VSHOT)) != 0;
  }

  if ((w->s).flags & X_FLIP) {
    (w->s).d.x = (0x98 * 8);
  } else {
    (w->s).d.x = -(0x98 * 8);
  }

  if (isVShot) {
    if ((w->s).flags & Y_FLIP) {
      (w->s).d.y = (0x98 * 2);
    } else {
      (w->s).d.y = -(0x98 * 2);
    }
  } else {
    (w->s).d.y = 0;
  }

  (w->s).flags |= COLLIDABLE;

  body = &w->body;
  InitBody(body, gLemonBulletCollisions, &(w->s).coord, 1);
  body->parent = (struct CollidableEntity *)w;
  body->fn = NULL;

  s32 atk = 2;
  if (((z->s).mode[1] == ZERO_GROUND) && ((z->s).mode[2] == GROUND_DASH)) {
    atk = 3;  // Dash buster
  }
  InitWeaponBody(body, gLemonBulletCollisions, atk + CalcBusterBonus(z), ELEMENT_NONE, -1, -1);
#else
  INCCODE("asm/wip/initLemonBullet.inc");
#endif
}

WIP static void initSemiBullet(struct Weapon *w) {
#if MODERN
  bool16 isVShot;
  struct Body *body;
  struct Weapon_b4 *b4 = &w->unk_b4;
  struct Zero *z = b4->z;

  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);

  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, MOTION(0x86, 0x00));
  PlaySound(SE_CHARGE_BUSTER);

  isVShot = FALSE;
  if (b4->props[1][1] == ELEMENT_THUNDER) {
    isVShot = (((z->unk_b4).status).exSkill & (1 << EXSKILL_ID_VSHOT)) >> 1;
  }

  if ((w->s).flags & X_FLIP) {
    (w->s).d.x = PIXEL(6);
  } else {
    (w->s).d.x = -PIXEL(6);
  }

  if (isVShot) {
    if ((w->s).flags & Y_FLIP) {
      (w->s).d.x = 0x180;
    } else {
      (w->s).d.x = -0x180;
    }
  } else {
    (w->s).d.y = 0;
  }

  (w->s).flags |= COLLIDABLE;

  body = &w->body;
  InitBody(body, gSemiBulletCollisions, &(w->s).coord, 1);
  body->parent = (struct CollidableEntity *)w;
  body->fn = NULL;

  InitWeaponBody(body, gSemiBulletCollisions, (u8)(CalcBusterBonus(z) + 6), -1, -1, -1);
#else
  INCCODE("asm/wip/initSemiBullet.inc");
#endif
}

NAKED static void initFullBullet(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #8\n\
	adds r5, r0, #0\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	ldr r0, [r4]\n\
	mov sb, r0\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r5, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r1, #0x88\n\
	lsls r1, r1, #8\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	movs r0, #0x1a\n\
	bl PlaySound\n\
	ldrb r0, [r4, #0xd]\n\
	movs r1, #0\n\
	mov r8, r1\n\
	cmp r0, #1\n\
	bne _080373A2\n\
	mov r0, sb\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #0x12]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x11\n\
	mov r8, r0\n\
_080373A2:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080373D0\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	str r0, [r5, #0x5c]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _080373F4\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080373C6\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	b _080373F6\n\
_080373C6:\n\
	ldr r0, _080373CC @ =0xFFFFFE40\n\
	b _080373F6\n\
	.align 2, 0\n\
_080373CC: .4byte 0xFFFFFE40\n\
_080373D0:\n\
	ldr r0, _080373E8 @ =0xFFFFF900\n\
	str r0, [r5, #0x5c]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _080373F4\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080373EC\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	b _080373F6\n\
	.align 2, 0\n\
_080373E8: .4byte 0xFFFFF900\n\
_080373EC:\n\
	ldr r0, _080373F0 @ =0xFFFFFE40\n\
	b _080373F6\n\
	.align 2, 0\n\
_080373F0: .4byte 0xFFFFFE40\n\
_080373F4:\n\
	mov r0, r8\n\
_080373F6:\n\
	str r0, [r5, #0x60]\n\
	movs r0, #4\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r6, r5, #0\n\
	adds r6, #0x74\n\
	ldr r7, _0803744C @ =gFullBulletCollisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r6, #0\n\
	adds r1, r7, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r5, [r6, #0x2c]\n\
	str r4, [r6, #0x24]\n\
	mov r0, sb\n\
	bl CalcBusterBonus\n\
	adds r0, #0xc\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	beq _08037454\n\
	adds r1, r7, #0\n\
	adds r1, #0xc0\n\
	ldr r2, _08037450 @ =u8_ARRAY_0835ee9e\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xd]\n\
	adds r0, r0, r2\n\
	ldrb r3, [r0]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	str r0, [sp]\n\
	str r0, [sp, #4]\n\
	adds r0, r6, #0\n\
	adds r2, r4, #0\n\
	bl InitWeaponBody\n\
	b _08037472\n\
	.align 2, 0\n\
_0803744C: .4byte gFullBulletCollisions\n\
_08037450: .4byte u8_ARRAY_0835ee9e\n\
_08037454:\n\
	ldr r1, _08037480 @ =u8_ARRAY_0835ee9e\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrb r0, [r0, #0xd]\n\
	adds r0, r0, r1\n\
	ldrb r3, [r0]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	str r0, [sp]\n\
	str r0, [sp, #4]\n\
	adds r0, r6, #0\n\
	adds r1, r7, #0\n\
	adds r2, r4, #0\n\
	bl InitWeaponBody\n\
_08037472:\n\
	add sp, #8\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08037480: .4byte u8_ARRAY_0835ee9e\n\
 .syntax divided\n");
}

NAKED static void initLaserShot(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080374D0\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080374BC\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl PushoutToLeft1\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bge _080374D0\n\
	b _080374CA\n\
_080374BC:\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl PushoutToRight1\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	ble _080374D0\n\
_080374CA:\n\
	ldr r0, [r7, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
_080374D0:\n\
	movs r4, #0\n\
	strb r4, [r7, #0x12]\n\
	adds r0, r7, #0\n\
	bl InitScalerotMotion2\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _0803753C @ =0x00005004\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	movs r0, #0x12\n\
	bl PlaySound\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	beq _0803754E\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, _08037540 @ =0xFFFFFB00\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #3\n\
	str r0, [r7, #0x5c]\n\
	adds r1, r7, #0\n\
	adds r1, #0x24\n\
	movs r0, #0x80\n\
	strb r0, [r1]\n\
	strb r4, [r7, #0x13]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	ldr r0, [r0]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08037544\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	movs r0, #0x60\n\
	b _08037588\n\
	.align 2, 0\n\
_0803753C: .4byte 0x00005004\n\
_08037540: .4byte 0xFFFFFB00\n\
_08037544:\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	movs r0, #0xa0\n\
	b _08037588\n\
_0803754E:\n\
	ldr r0, [r7, #0x54]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #3\n\
	adds r0, r0, r2\n\
	str r0, [r7, #0x54]\n\
	ldr r0, _0803757C @ =0xFFFFF900\n\
	str r0, [r7, #0x5c]\n\
	adds r0, r7, #0\n\
	adds r0, #0x24\n\
	strb r1, [r0]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	ldr r0, [r0]\n\
	movs r1, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08037580\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	movs r0, #0x20\n\
	b _08037588\n\
	.align 2, 0\n\
_0803757C: .4byte 0xFFFFF900\n\
_08037580:\n\
	movs r1, #0x9f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	movs r0, #0xe0\n\
_08037588:\n\
	strb r0, [r1, #0xe]\n\
	movs r5, #0\n\
	str r5, [r7, #0x60]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
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
	subs r2, #1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r1, r7, #0\n\
	adds r1, #0x25\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r4, r7, #0\n\
	adds r4, #0x74\n\
	ldr r6, _08037614 @ =gLaserShotCollisions\n\
	adds r2, #0xb\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r7, [r4, #0x2c]\n\
	str r5, [r4, #0x24]\n\
	mov r0, r8\n\
	bl CalcBusterBonus\n\
	adds r2, r0, #0\n\
	adds r2, #0xa\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	str r3, [sp]\n\
	str r3, [sp, #4]\n\
	adds r0, r4, #0\n\
	adds r1, r6, #0\n\
	bl InitWeaponBody\n\
	mov r0, r8\n\
	adds r1, r7, #0\n\
	movs r2, #0\n\
	bl CreateReflectLaser\n\
	add sp, #8\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08037614: .4byte gLaserShotCollisions\n\
 .syntax divided\n");
}

static void initBurstShotBullet(struct Weapon *w) {
  struct Body *body;
  struct Zero *z = (w->unk_b4).z;

  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);

  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, MOTION(DM083_BURST_SHOT_FIREWORK, 0x03));
  PlaySound(SE_CHARGE_BUSTER);
  if ((w->s).flags & X_FLIP) {
    (w->s).d.x = PIXEL(6);
  } else {
    (w->s).d.x = -PIXEL(6);
  }
  (w->s).d.y = 0;
  (w->s).work[2] = 0x14;
  (w->s).flags |= COLLIDABLE;

  body = &w->body;
  InitBody(body, gBurstShotCollisions, &(w->s).coord, 1);
  body->parent = (struct CollidableEntity *)w;
  body->fn = NULL;

  InitWeaponBody(body, gBurstShotCollisions, (u8)(CalcBusterBonus(z) + 6), ELEMENT_FLAME, BODY_NATURE_B1, -1);
}

static void initBlizzardArrowBullet(struct Weapon *w) {
  struct Body *body;
  struct Zero *z = (w->unk_b4).z;

  InitNonAffineMotion(&w->s);
  ResetDynamicMotion(&w->s);

  (w->s).flags |= DISPLAY;
  (w->s).flags |= FLIPABLE;
  SetMotion(&w->s, MOTION(0x52, 0x00));
  PlaySound(SE_CHARGE_BUSTER);
  (w->s).flags |= COLLIDABLE;

  body = &w->body;
  InitBody(body, gBlizzardArrowCollisions, &(w->s).coord, 1);
  body->parent = (struct CollidableEntity *)w;
  body->fn = NULL;
  (w->s).work[2] = 0;

  InitWeaponBody(body, gBlizzardArrowCollisions, (u8)(CalcBusterBonus(z) + 10), ELEMENT_ICE, -1, -1);
}

WIP static void LemonBullet_Update(struct Weapon *w) {
#if MODERN
  (w->s).coord.x += (w->s).d.x;
  (w->s).coord.y += (w->s).d.y;
  if (((w->s).mode[1] == 0) && isBlocked(w)) {
    CreateParticle(&(w->s).coord, 6, ((w->s).flags >> 4) & 1);
    (w->s).d.x = -(w->s).d.x;
    RNG_0202f388 = LCG(RNG_0202f388);
    if ((RNG_0202f388 >> 16) & 1) {
      (w->s).d.y = (w->s).d.x;
    } else {
      (w->s).d.y = -(w->s).d.x;
    }
    PlaySound(SE_BLOCKED);
    (w->body).status = 0;
    (w->body).prevStatus = 0;
    (w->body).invincibleTime = 0;
    (w->s).flags &= ~COLLIDABLE;
    (w->s).mode[1]++;
  }
  if (shouldDelete(w)) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
#else
  INCCODE("asm/wip/LemonBullet_Update.inc");
#endif
}

NAKED static void SemiBullet_Main(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	bne _08037840\n\
	ldr r1, _0803783C @ =Coord_0835ee7c\n\
	adds r0, r4, #0\n\
	bl buster_08037f78\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08037850\n\
	movs r1, #0x87\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _08037850\n\
	.align 2, 0\n\
_0803783C: .4byte Coord_0835ee7c\n\
_08037840:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
_08037850:\n\
	adds r0, r4, #0\n\
	bl isBlocked\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08037876\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #6\n\
	bl CreateParticle\n\
	movs r0, #0x2b\n\
	bl PlaySound\n\
	b _08037882\n\
_08037876:\n\
	adds r0, r4, #0\n\
	bl shouldDelete\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08037894\n\
_08037882:\n\
	ldr r1, _0803789C @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_08037894:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803789C: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

static void FullBullet_Update(struct Weapon *w) {
  if ((w->s).mode[1] == 0) {
    if (buster_08037f78(w, &sFullBulletSize)) {
      const motion_t *m = sFullBulletMotions;
      struct Weapon_b4 *b4 = &w->unk_b4;
      SetMotion(&w->s, m[(b4->props)[1][1]]);
      (w->s).mode[1]++;
    }
  } else {
    (w->s).coord.x += (w->s).d.x;
    (w->s).coord.y += (w->s).d.y;
  }

  if (isBlocked(w)) {
    CreateParticle(&(w->s).coord, 6, ((w->s).flags >> 4) & 1);
    PlaySound(SE_BLOCKED);
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  } else if (shouldDelete(w)) {
    SET_WEAPON_ROUTINE(w, ENTITY_DIE);
  }
}

NAKED static void LaserShot_Main(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r4, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, [r4, #0x60]\n\
	adds r1, r1, r2\n\
	str r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #0\n\
	bne _08037968\n\
	b _08037BC4\n\
_08037968:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	subs r0, r0, r1\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, [r4, #0x60]\n\
	subs r1, r1, r2\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _08037992\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	subs r0, r0, r1\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, [r4, #0x60]\n\
	subs r1, r1, r2\n\
	bl GetMetatileAttr\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
_08037992:\n\
	ldr r1, _080379DC @ =0x00007FF2\n\
	adds r0, r5, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bhi _080379A0\n\
	movs r5, #0\n\
_080379A0:\n\
	movs r0, #0xf\n\
	ands r5, r0\n\
	cmp r5, #0xd\n\
	bls _080379AA\n\
	movs r5, #1\n\
_080379AA:\n\
	cmp r5, #0\n\
	bne _080379B0\n\
	b _08037BC4\n\
_080379B0:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #3\n\
	bls _080379E4\n\
	ldr r1, _080379E0 @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x5c]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	b _08037C1C\n\
	.align 2, 0\n\
_080379DC: .4byte 0x00007FF2\n\
_080379E0: .4byte gWeaponFnTable\n\
_080379E4:\n\
	ldr r0, [r4, #0x5c]\n\
	cmp r0, #0\n\
	ble _080379FA\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToLeft1\n\
	adds r7, r0, #0\n\
	cmp r7, #1\n\
	bne _08037A0E\n\
	b _08037A0C\n\
_080379FA:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToRight1\n\
	adds r7, r0, #0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r7, r0\n\
	bne _08037A0E\n\
_08037A0C:\n\
	movs r7, #0\n\
_08037A0E:\n\
	ldr r0, [r4, #0x60]\n\
	cmp r0, #0\n\
	ble _08037A24\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToUp1\n\
	adds r6, r0, #0\n\
	cmp r6, #1\n\
	bne _08037A38\n\
	b _08037A36\n\
_08037A24:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl PushoutToDown1\n\
	adds r6, r0, #0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	cmp r6, r0\n\
	bne _08037A38\n\
_08037A36:\n\
	movs r6, #0\n\
_08037A38:\n\
	adds r0, r6, #0\n\
	cmp r6, #0\n\
	bge _08037A40\n\
	rsbs r0, r6, #0\n\
_08037A40:\n\
	cmp r0, #1\n\
	bne _08037A46\n\
	movs r6, #0\n\
_08037A46:\n\
	cmp r7, #0\n\
	beq _08037A68\n\
	cmp r6, #0\n\
	beq _08037A68\n\
	adds r1, r7, #0\n\
	cmp r7, #0\n\
	bge _08037A56\n\
	rsbs r1, r7, #0\n\
_08037A56:\n\
	adds r0, r6, #0\n\
	cmp r6, #0\n\
	bge _08037A5E\n\
	rsbs r0, r6, #0\n\
_08037A5E:\n\
	cmp r1, r0\n\
	ble _08037A66\n\
	movs r7, #0\n\
	b _08037A68\n\
_08037A66:\n\
	movs r6, #0\n\
_08037A68:\n\
	ldr r0, _08037AB8 @ =gOverworld\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #1\n\
	adds r0, r0, r2\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	cmp r0, #0x11\n\
	bne _08037A8A\n\
	ldr r0, _08037ABC @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	cmp r0, #0\n\
	beq _08037A8A\n\
	b _08037C0A\n\
_08037A8A:\n\
	adds r0, r7, #0\n\
	cmp r7, #0\n\
	bge _08037A92\n\
	rsbs r0, r7, #0\n\
_08037A92:\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	bgt _08037AA6\n\
	adds r0, r6, #0\n\
	cmp r6, #0\n\
	bge _08037AA2\n\
	rsbs r0, r6, #0\n\
_08037AA2:\n\
	cmp r0, r1\n\
	ble _08037AC0\n\
_08037AA6:\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #0x80\n\
	strb r0, [r4, #0x13]\n\
	ldr r0, [r4, #0x5c]\n\
	rsbs r7, r0, #0\n\
	ldr r0, [r4, #0x60]\n\
	rsbs r6, r0, #0\n\
	b _08037B7A\n\
	.align 2, 0\n\
_08037AB8: .4byte gOverworld\n\
_08037ABC: .4byte gStageRun+232\n\
_08037AC0:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	bne _08037B06\n\
	ldr r0, [r4, #0x5c]\n\
	cmp r0, #0\n\
	bge _08037AEA\n\
	cmp r5, #9\n\
	bls _08037AD6\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0xec\n\
	b _08037B76\n\
_08037AD6:\n\
	cmp r5, #7\n\
	bls _08037AE0\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0xda\n\
	b _08037B76\n\
_08037AE0:\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	ldrb r0, [r0, #0xe]\n\
	b _08037B78\n\
_08037AEA:\n\
	cmp r5, #7\n\
	bhi _08037AF2\n\
	cmp r5, #1\n\
	bne _08037AFC\n\
_08037AF2:\n\
	movs r0, #0x9f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	ldrb r0, [r0, #0xe]\n\
	b _08037B78\n\
_08037AFC:\n\
	cmp r5, #3\n\
	bls _08037B72\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x14\n\
	b _08037B76\n\
_08037B06:\n\
	ldr r0, [r4, #0x5c]\n\
	cmp r0, #0\n\
	bge _08037B40\n\
	cmp r5, #9\n\
	bls _08037B16\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0xec\n\
	b _08037B76\n\
_08037B16:\n\
	cmp r5, #7\n\
	bls _08037B20\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0xda\n\
	b _08037B76\n\
_08037B20:\n\
	adds r1, r7, #0\n\
	cmp r7, #0\n\
	bge _08037B28\n\
	rsbs r1, r7, #0\n\
_08037B28:\n\
	adds r0, r6, #0\n\
	cmp r6, #0\n\
	bge _08037B30\n\
	rsbs r0, r6, #0\n\
_08037B30:\n\
	cmp r1, r0\n\
	ble _08037B3A\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x80\n\
	b _08037B76\n\
_08037B3A:\n\
	ldrb r0, [r4, #0x13]\n\
	rsbs r0, r0, #0\n\
	b _08037B78\n\
_08037B40:\n\
	cmp r5, #7\n\
	bhi _08037B48\n\
	cmp r5, #1\n\
	bne _08037B68\n\
_08037B48:\n\
	adds r1, r7, #0\n\
	cmp r7, #0\n\
	bge _08037B50\n\
	rsbs r1, r7, #0\n\
_08037B50:\n\
	adds r0, r6, #0\n\
	cmp r6, #0\n\
	bge _08037B58\n\
	rsbs r0, r6, #0\n\
_08037B58:\n\
	cmp r1, r0\n\
	ble _08037B62\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x80\n\
	b _08037B76\n\
_08037B62:\n\
	ldrb r0, [r4, #0x13]\n\
	rsbs r0, r0, #0\n\
	b _08037B78\n\
_08037B68:\n\
	cmp r5, #3\n\
	bls _08037B72\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x14\n\
	b _08037B76\n\
_08037B72:\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x26\n\
_08037B76:\n\
	subs r0, r0, r1\n\
_08037B78:\n\
	strb r0, [r4, #0x13]\n\
_08037B7A:\n\
	ldrb r1, [r4, #0x13]\n\
	movs r0, #0x80\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	strb r0, [r1]\n\
	adds r0, #0x80\n\
	lsls r0, r0, #0x18\n\
	ldr r3, _08037BEC @ =gSineTable\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x17\n\
	adds r1, r0, r5\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r3\n\
	movs r5, #0\n\
	ldrsh r2, [r1, r5]\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	str r1, [r4, #0x5c]\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x60]\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r7\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x58]\n\
	adds r0, r0, r6\n\
	str r0, [r4, #0x58]\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
_08037BC4:\n\
	adds r0, r4, #0\n\
	bl isBlocked\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08037BF0\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #6\n\
	bl CreateParticle\n\
	movs r0, #0x2b\n\
	bl PlaySound\n\
	b _08037C0A\n\
	.align 2, 0\n\
_08037BEC: .4byte gSineTable\n\
_08037BF0:\n\
	ldr r0, _08037C28 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	ldr r2, _08037C2C @ =s16_ARRAY_0835ee8c\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r2\n\
	movs r5, #0\n\
	ldrsh r1, [r1, r5]\n\
	cmp r0, r1\n\
	bls _08037C1C\n\
_08037C0A:\n\
	ldr r1, _08037C30 @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
_08037C1C:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08037C28: .4byte gStageRun+232\n\
_08037C2C: .4byte s16_ARRAY_0835ee8c\n\
_08037C30: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

NAKED static void BurstShot_Main(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0xd]\n\
	cmp r0, #0\n\
	bne _08037D2C\n\
	ldrb r1, [r7, #0x1e]\n\
	lsls r1, r1, #8\n\
	adds r0, r7, #0\n\
	adds r0, #0x70\n\
	ldrb r0, [r0]\n\
	orrs r0, r1\n\
	ldr r1, _08037C90 @ =0x00005303\n\
	cmp r0, r1\n\
	bne _08037C6E\n\
	adds r0, r7, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _08037C6E\n\
	movs r1, #0xa2\n\
	lsls r1, r1, #7\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
_08037C6E:\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	adds r0, r7, #0\n\
	bl shouldDelete\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bne _08037C98\n\
	ldr r1, _08037C94 @ =gWeaponFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r4, [r7, #0xc]\n\
	b _08037E1C\n\
	.align 2, 0\n\
_08037C90: .4byte 0x00005303\n\
_08037C94: .4byte gWeaponFnTable\n\
_08037C98:\n\
	adds r0, r7, #0\n\
	bl isBlocked\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08037CBE\n\
	adds r0, r7, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r7, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #6\n\
	bl CreateParticle\n\
	movs r0, #0x2b\n\
	bl PlaySound\n\
	movs r4, #1\n\
_08037CBE:\n\
	adds r5, r7, #0\n\
	adds r5, #0x8c\n\
	cmp r4, #0\n\
	bne _08037CE0\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	beq _08037CE0\n\
	ldr r0, [r5]\n\
	movs r1, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08037CE0\n\
	b _08037E22\n\
_08037CE0:\n\
	ldrb r0, [r7, #0xd]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r7, #0xd]\n\
	str r2, [r7, #0x5c]\n\
	ldr r3, _08037D20 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _08037D24 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _08037D28 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	strb r0, [r7, #0x12]\n\
	strb r2, [r7, #0x13]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	str r2, [r5]\n\
	adds r0, r7, #0\n\
	adds r0, #0x90\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	b _08037E22\n\
	.align 2, 0\n\
_08037D20: .4byte RNG_0202f388\n\
_08037D24: .4byte 0x000343FD\n\
_08037D28: .4byte 0x00269EC3\n\
_08037D2C:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	mov sl, r0\n\
	ldrb r4, [r7, #0x12]\n\
	ldr r3, [r7, #0x5c]\n\
	mov r8, r3\n\
	movs r0, #0xa7\n\
	lsls r0, r0, #1\n\
	bl PlaySound\n\
	ldr r6, _08037E34 @ =RNG_0202f388\n\
	ldr r0, [r6]\n\
	ldr r1, _08037E38 @ =0x000343FD\n\
	adds r2, r0, #0\n\
	muls r2, r1, r2\n\
	ldr r3, _08037E3C @ =0x00269EC3\n\
	adds r2, r2, r3\n\
	lsls r2, r2, #1\n\
	lsrs r0, r2, #1\n\
	str r0, [r6]\n\
	lsrs r2, r2, #0x11\n\
	movs r0, #1\n\
	mov sb, r0\n\
	ands r2, r0\n\
	ldr r5, _08037E40 @ =gSineTable\n\
	adds r0, r4, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r5\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	mov r3, r8\n\
	muls r3, r0, r3\n\
	asrs r3, r3, #8\n\
	lsls r4, r4, #1\n\
	adds r4, r4, r5\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	mov r4, r8\n\
	muls r4, r0, r4\n\
	adds r0, r4, #0\n\
	asrs r0, r0, #8\n\
	str r0, [sp]\n\
	mov r0, sl\n\
	adds r1, r7, #0\n\
	bl CreateBurstShot\n\
	ldrb r1, [r7, #0x12]\n\
	adds r1, #0x80\n\
	lsls r1, r1, #0x18\n\
	ldr r0, [r6]\n\
	ldr r3, _08037E38 @ =0x000343FD\n\
	adds r2, r0, #0\n\
	muls r2, r3, r2\n\
	ldr r4, _08037E3C @ =0x00269EC3\n\
	adds r2, r2, r4\n\
	lsls r2, r2, #1\n\
	lsrs r0, r2, #1\n\
	str r0, [r6]\n\
	lsrs r2, r2, #0x11\n\
	mov r0, sb\n\
	ands r2, r0\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x17\n\
	adds r0, r1, r3\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r5\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	mov r3, r8\n\
	muls r3, r0, r3\n\
	asrs r3, r3, #8\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r5\n\
	movs r4, #0\n\
	ldrsh r0, [r1, r4]\n\
	mov r1, r8\n\
	muls r1, r0, r1\n\
	adds r0, r1, #0\n\
	asrs r0, r0, #8\n\
	str r0, [sp]\n\
	mov r0, sl\n\
	adds r1, r7, #0\n\
	bl CreateBurstShot\n\
	ldr r0, [r7, #0x5c]\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #1\n\
	adds r0, r0, r3\n\
	str r0, [r7, #0x5c]\n\
	ldrb r2, [r7, #0x12]\n\
	adds r2, #0x20\n\
	ldr r0, [r6]\n\
	ldr r4, _08037E38 @ =0x000343FD\n\
	muls r0, r4, r0\n\
	ldr r1, _08037E3C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r6]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	adds r2, r2, r0\n\
	strb r2, [r7, #0x12]\n\
	ldrb r0, [r7, #0x13]\n\
	adds r1, r0, #1\n\
	strb r1, [r7, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xf\n\
	bls _08037E22\n\
	ldr r1, _08037E44 @ =gWeaponFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
_08037E1C:\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
_08037E22:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08037E34: .4byte RNG_0202f388\n\
_08037E38: .4byte 0x000343FD\n\
_08037E3C: .4byte 0x00269EC3\n\
_08037E40: .4byte gSineTable\n\
_08037E44: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

static void BlizzardArrow_Update(struct Weapon *w) {
  struct Zero *z = (w->unk_b4).z;
  switch ((w->s).mode[1]) {
    case 0: {
      if ((w->s).motion.state == MOTION_NEXT) {
        (w->s).work[2]++;
        if ((w->s).work[2] > 4) {
          (w->s).mode[1]++;
          break;
        }
        if ((w->s).work[2] > 1) {
          CreateBlizzardArrow(z, &(w->s).coord, (w->s).work[2] - 2, ((w->s).flags >> 4) & 1);
        }
      }
      break;
    }

    case 1: {
      SetMotion(&w->s, MOTION(DM082_BLIZZ_ARROW, 0x01));
      (w->s).work[2] = 0;
      (w->s).mode[1]++;
      break;
    }

    case 2: {
      if ((w->s).motion.state == MOTION_END) {
        SET_WEAPON_ROUTINE(w, ENTITY_DIE);
      }
      break;
    }
  }
}

// 0x08037ed8
NAKED static u8 shouldDelete(struct Weapon *w) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r1, r4, #0\n\
	adds r1, #0xb4\n\
	ldr r5, [r1]\n\
	ldrb r0, [r1, #0xf]\n\
	cmp r0, #0\n\
	beq _08037EF0\n\
	subs r0, #1\n\
	strb r0, [r1, #0xf]\n\
	movs r0, #0\n\
	b _08037F72\n\
_08037EF0:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldr r2, _08037F34 @ =0x7FF20000\n\
	adds r0, r0, r2\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bhi _08037F08\n\
	movs r1, #0\n\
_08037F08:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08037F14\n\
	movs r1, #0\n\
_08037F14:\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08037F38\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	ldrb r2, [r4, #0xa]\n\
	lsrs r2, r2, #4\n\
	movs r1, #1\n\
	ands r2, r1\n\
	movs r1, #7\n\
	bl CreateParticle\n\
	movs r0, #1\n\
	b _08037F72\n\
	.align 2, 0\n\
_08037F34: .4byte 0x7FF20000\n\
_08037F38:\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08037F4A\n\
	movs r0, #1\n\
	b _08037F72\n\
_08037F4A:\n\
	ldr r0, _08037F68 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl CalcFromCamera\n\
	ldr r2, _08037F6C @ =s16_ARRAY_0835ee8c\n\
	ldrb r1, [r4, #0x10]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r2\n\
	movs r2, #0\n\
	ldrsh r1, [r1, r2]\n\
	cmp r0, r1\n\
	bhi _08037F70\n\
	movs r0, #0\n\
	b _08037F72\n\
	.align 2, 0\n\
_08037F68: .4byte gStageRun+232\n\
_08037F6C: .4byte s16_ARRAY_0835ee8c\n\
_08037F70:\n\
	movs r0, #2\n\
_08037F72:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED static bool8 buster_08037f78(struct Weapon *w, const struct Rect *size) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	mov ip, r0\n\
	adds r4, r1, #0\n\
	movs r0, #0xb4\n\
	add r0, ip\n\
	mov r8, r0\n\
	ldr r5, [r0]\n\
	movs r7, #0\n\
	mov r0, ip\n\
	adds r0, #0x71\n\
	ldrb r3, [r0]\n\
	ldrb r0, [r5, #0xa]\n\
	lsrs r0, r0, #4\n\
	movs r2, #1\n\
	adds r1, r2, #0\n\
	bics r1, r0\n\
	mov r6, ip\n\
	ldrb r0, [r6, #0xa]\n\
	lsrs r0, r0, #4\n\
	ands r0, r2\n\
	cmp r1, r0\n\
	beq _0803801E\n\
	ldrb r0, [r6, #0xe]\n\
	cmp r0, #0\n\
	bne _0803801E\n\
	ldr r0, [r5, #0x54]\n\
	mov r2, r8\n\
	ldr r1, [r2, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	mov r0, ip\n\
	adds r0, #0x72\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bgt _08037FD2\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #3\n\
	bls _08037FD2\n\
	movs r7, #1\n\
_08037FD2:\n\
	mov r6, ip\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08037FFE\n\
	cmp r3, #0\n\
	beq _08038064\n\
_08037FE2:\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r6, ip\n\
	ldr r0, [r6, #0x54]\n\
	adds r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	subs r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0\n\
	bne _08037FE2\n\
	b _08038064\n\
_08037FFE:\n\
	cmp r3, #0\n\
	beq _08038064\n\
_08038002:\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r6, ip\n\
	ldr r0, [r6, #0x54]\n\
	subs r0, r0, r1\n\
	str r0, [r6, #0x54]\n\
	subs r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0\n\
	bne _08038002\n\
	b _08038064\n\
_0803801E:\n\
	movs r0, #1\n\
	mov r1, ip\n\
	strb r0, [r1, #0xe]\n\
	mov r0, ip\n\
	adds r0, #0x72\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bgt _08038064\n\
	ldrb r1, [r1, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803804C\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r6, ip\n\
	ldr r0, [r6, #0x54]\n\
	adds r0, r0, r1\n\
	b _0803805A\n\
_0803804C:\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	mov r6, ip\n\
	ldr r0, [r6, #0x54]\n\
	subs r0, r0, r1\n\
_0803805A:\n\
	str r0, [r6, #0x54]\n\
	adds r0, r3, #1\n\
	cmp r0, #3\n\
	ble _08038064\n\
	movs r7, #1\n\
_08038064:\n\
	adds r0, r7, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

// 0x08038070
static void onHit(struct Body *body, struct Coord *r1 UNUSED, struct Coord *r2 UNUSED) {
  struct Body *enemy;
  struct CollidableEntity *parent;
  u8 uVar1, enemyStatus;

  if (body->hitboxFlags & (1 << 2)) {
    parent = body->parent;

    if (gMission.weaponCount[WEAPON_BUSTER] < 0xFFFF) {
      gMission.weaponCount[WEAPON_BUSTER]++;
    }

    if (!(body->enemy->status & BODY_STATUS_DEAD) || ((parent->s).work[0] == 0)) {
      if ((parent->s).work[0] != 4) {
        u8 *work = parent->work;
        work[12] = 1;
      }
    }
  }
}

// 弾丸がブロックされたか(硬いものにあたって弾かれたか)
static bool8 isBlocked(struct Weapon *w) {
  u32 status = (w->body).status;
  if (status & BODY_STATUS_BLOCKED) return TRUE;
  return FALSE;
}

// clang-format off
static const WeaponFunc sBulletUpdate[6] = {
  LemonBullet_Update,
  SemiBullet_Main,
  FullBullet_Update,
  LaserShot_Main,
  BurstShot_Main,
  BlizzardArrow_Update,
};
// clang-format on

const struct Coord Coord_0835ee7c = {0x4000000, 0x8000A00};
static const struct Rect sFullBulletSize = {0x300, 0x400, 0x800, 0x200};

const s16 s16_ARRAY_0835ee8c[9] = {
    0x0400, 0x2400, 0x2800, 0x4000, 0x2800, 0x2800, 0x2800, 0x2800, 0x2800,
};

const u8 u8_ARRAY_0835ee9e[4] = {
    0,
    1,
    2,
    3,
};

static const struct Collision gLemonBulletCollisions[2] = {
    {0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, {0, 0, 0x800, 0x800}},
    {1, 0, 1, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, {0, 0, 0x800, 0x800}},
};

const struct Collision gSemiBulletCollisions[2] = {
    {0, 0, 1, 4, 0, 0, 1, 1, 0, 0, 0, 1, 0x80000000, {0x200, 0, 0x1200, 0x1000}},
    {1, 0, 1, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, {0x200, 0, 0x1200, 0x1000}},
};

const struct Collision gFullBulletCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0,
      element : 0,
      nature : 2,
      comboLv : 1,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0,
      remaining : 1,
      unk_0c : 2,
      range : {0x600, 0x0, 0x1800, 0x1400},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0,
      unk_0a : 0,
      remaining : 0,
      unk_0c : 0,
      range : {0x600, 0x0, 0x1800, 0x1400},
    },
};

const struct Collision gLaserShotCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 4,
      element : 0,
      nature : 2,
      comboLv : 1,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0,
      remaining : 1,
      unk_0c : 0x10000,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0,
      unk_0a : 0,
      remaining : 0,
      unk_0c : 0,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
};

const struct Collision gBurstShotCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 6,
      element : 0,
      nature : 2,
      comboLv : 1,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0,
      remaining : 1,
      unk_0c : 8,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0,
      unk_0a : 0,
      remaining : 0,
      unk_0c : 0,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
};

const struct Collision gBlizzardArrowCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 7,
      element : 0,
      nature : 2,
      comboLv : 1,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0,
      remaining : 1,
      unk_0c : 0x10,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0,
      unk_0a : 0,
      remaining : 0,
      unk_0c : 0,
      range : {0x0, 0x0, 0x1000, 0x1000},
    },
};

const struct Collision Hitbox_ARRAY_0835efc4[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 8,
      unk_04 : 0,
      element : 0,
      nature : 2,
      comboLv : 1,
      hitzone : 0,
      hardness : 0,
      unk_0a : 0,
      remaining : 1,
      unk_0c : 2,
      range : {0x600, 0x0, 0x1800, 0x1400},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : 1,
      damage : 0,
      unk_04 : 0xFF,
      element : 0xFF,
      nature : 0xFF,
      comboLv : 0xFF,
      hitzone : 0xFF,
      hardness : 0,
      unk_0a : 0,
      remaining : 0,
      unk_0c : 0,
      range : {0x600, 0x0, 0x1800, 0x1400},
    },
};

const WeaponRoutine gBusterRoutine = {
    Buster_Init, Buster_Update, Buster_Die, DeleteWeapon, Buster_Delete,
};

static const motion_t sFullBulletMotions[4] = {
    MOTION(0x89, 0x00),
    MOTION(0x8A, 0x00),
    MOTION(0x8B, 0x00),
    MOTION(0x8C, 0x00),
};
