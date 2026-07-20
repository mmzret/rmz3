#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "physics.h"
#include "player/zero.h"
#include "score.h"
#include "sound.h"
#include "vfx.h"
#include "weapon.h"
#include "zero.h"

struct ZeroBuster {
  COLLISION_OBJECT_HDR;  // 0x00
  struct ZeroBusterProps {
    struct Zero* z;  // 0xB4
    Coords32 c;      // 0xB8
    u8 unk_c0;       // 0xC0
    u8 element;      // 0xC1
    u8 unk_c2;       // 0xC2
    u8 unk_c3;       // 0xC3
    u8 unk_c4[40];   // 0xC4
  } props;           // props (56bytes, offset: 0xB4..)
};
static_assert(sizeof(struct ZeroBuster) == sizeof(Weapon));

#define BUSTER_BLIZZARD_ARROW 5

static bool8 isBlocked(Weapon* w);
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);
static void Buster_Update(struct ZeroBuster* w);
static u8 shouldDelete(Weapon* w);
static bool8 buster_08037f78(Weapon* w, const struct Rect* size);
static const motion_t sFullBulletMotions[4];

static const struct Collision sCollisions[];

static const u8 sElements[4];

NAKED void MenuExit_Buster(Weapon* w) { INCCODE("asm/todo/MenuExit_Buster.inc"); }

Weapon* CreateWeaponBuster(struct Zero* z, Coords32* c, u8 charge, bool8 xflip, bool8 yflip) {
  struct ZeroBuster* p;

  KillAllWeapons(DeleteSaber);
  p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_Z_BUSTER);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
      SetWeaponElement(0, ((&z->unk_b4)->status).element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_Z_BUSTER);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
      SetWeaponElement(1, ((&z->unk_b4)->status).element);
    }
    (p->props).z = z;
    (p->props).c = *c;
    p->coord.x = (z->s).coord.x + c->x;
    p->coord.y = (z->s).coord.y + c->y;
    p->work[0] = charge, p->work[1] = 0;
    SET_XFLIP(p, xflip);
    SET_YFLIP(p, yflip);
    (&p->props)->element = ((&z->unk_b4)->status).element;
  }
  return (void*)p;
}

// --------------------------------------------

static void initLemonBullet(struct ZeroBuster* p);
static void initSemiBullet(struct ZeroBuster* p);
static void initFullBullet(Weapon* p);
static void initLaserShot(Weapon* p);
static void initBurstShotBullet(struct ZeroBuster* p);
static void initBlizzardArrowBullet(struct ZeroBuster* p);

static void Buster_Init(struct ZeroBuster* p) {
  // clang-format off
  static const WeaponFunc sInitalizer[6] = {
      (void*)initLemonBullet,
      (void*)initSemiBullet,
      (void*)initFullBullet,
      (void*)initLaserShot,
      (void*)initBurstShotBullet,
      (void*)initBlizzardArrowBullet,
  };
  // clang-format on

  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  (sInitalizer[p->work[0]])((void*)p);
  (&p->props)->unk_c0 = 0;
  (&p->props)->unk_c3 = 1;

  (p->props).z->bulletCount++;

  {
    BodyFunc fn = onCollision;
    struct Body* body = &p->body;
    body->fn = fn;
  }

  Buster_Update(p);
}

// --------------------------------------------

static void LemonBullet_Update(Object* p);
static void SemiBullet_Update(Object* p);
static void FullBullet_Update(struct ZeroBuster* p);
static void LaserShot_Main(struct ZeroBuster* p);
static void BurstShot_Main(struct ZeroBuster* p);
static void BlizzardArrow_Update(struct ZeroBuster* p);

static void Buster_Update(struct ZeroBuster* p) {
  // clang-format off
  static const WeaponFunc sBulletUpdates[6] = {
    (void*)LemonBullet_Update,
    (void*)SemiBullet_Update,
    (void*)FullBullet_Update,
    (void*)LaserShot_Main,
    (void*)BurstShot_Main,
    (void*)BlizzardArrow_Update,
  };
  // clang-format on

  if ((&p->props)->unk_c0 != 0) {
    if (p->work[0] == BUSTER_BLIZZARD_ARROW) {
      EXIT_BODY(p);
      (&p->props)->unk_c0 = 0;
      return;
    }

    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  (sBulletUpdates[p->work[0]])((void*)p);
  UpdateSpriteAnimation(p);
}

static void Buster_Die(Object* p) {
  EXIT_BODY(p);
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

static void Buster_Delete(struct ZeroBuster* p) {
  ((p->props).z)->bulletCount--;
  DeleteEntity((void*)p);
}

static const struct Collision sLemonBulletCollisions[2];

NON_MATCH static void initLemonBullet(struct ZeroBuster* p) {
#if MODERN
  bool16 isVShot;
  u8 atk, element;
  struct ZeroBusterProps* s = &p->props;
  struct Zero* z = s->z;

  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;

  {
    u8 bullet = gSystemSavedata.bullet;
    if (bullet == BULLET_MOD_REALISTIC) {
      SetSpriteAnimation(p, MOTION(DM133_LEMON, 2));
    } else if (bullet == BULLET_MOD_BLACK) {
      SetSpriteAnimation(p, MOTION(DM133_LEMON, 1));
    } else {
      SetSpriteAnimation(p, MOTION(DM133_LEMON, 0));
    }
  }

  PlaySound(SE_Z_BUSTER);

  element = s->element;
  isVShot = FALSE;
  if (element == ELEMENT_THUNDER) {
    isVShot = (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_VSHOT)) >> EXSKILL_ID_VSHOT;
  }

  if (p->flags & X_FLIP) {
    p->d.x = 0x4C0;
    if (isVShot) {
      if (p->flags & Y_FLIP) {
        p->d.y = 0x130;
      } else {
        p->d.y = -0x130;
      }
    } else {
      p->d.y = 0;
    }
  } else {
    p->d.x = -0x4C0;
    if (isVShot) {
      if (p->flags & Y_FLIP) {
        p->d.y = 0x130;
      } else {
        p->d.y = -0x130;
      }
    } else {
      p->d.y = 0;
    }
  }

  _INIT_BODY(p, &sCollisions[0], 1);

  z = s->z;
  if ((((z->s).mode[1] == ZERO_GROUND) && ((z->s).mode[2] == GROUND_DASH))) {
    atk = 3;  // Dash buster
  } else {
    atk = 2;
  }
  InitWeaponBody(&p->body, &sCollisions[0], (u8)(CalcBusterBonus(z) + atk), -1, -1, -1);
#else
  INCCODE("asm/wip/initLemonBullet.inc");
#endif
}

static void initSemiBullet(struct ZeroBuster* p) {
  bool16 isVShot;
  u8 element;
  struct Zero* z = (p->props).z;

  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM134_UNK, 0));
  PlaySound(SE_CHARGE_BUSTER);

  element = (&p->props)->element;
  isVShot = FALSE;
  if (element == ELEMENT_THUNDER) {
    isVShot = (((&z->unk_b4)->status).exSkill & (1 << EXSKILL_ID_VSHOT)) >> EXSKILL_ID_VSHOT;
  }

  if (p->flags & X_FLIP) {
    p->d.x = PIXEL(6);
    if (isVShot) {
      if (p->flags & Y_FLIP) {
        p->d.y = 0x180;
      } else {
        p->d.y = -0x180;
      }
    } else {
      p->d.y = 0;
    }
  } else {
    p->d.x = -PIXEL(6);
    if (isVShot) {
      if (p->flags & Y_FLIP) {
        p->d.y = 0x180;
      } else {
        p->d.y = -0x180;
      }
    } else {
      p->d.y = 0;
    }
  }

  _INIT_BODY(p, &sCollisions[2], 1);
  InitWeaponBody(&p->body, &sCollisions[2], (u8)(CalcBusterBonus(z) + 6), -1, -1, -1);
}

NAKED static void initFullBullet(Weapon* w) {
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
	ldr r7, _0803744C @ =sFullBulletCollisions\n\
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
	ldr r2, _08037450 @ =sElements\n\
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
_0803744C: .4byte sCollisions+(24*4)\n\
_08037450: .4byte sElements\n\
_08037454:\n\
	ldr r1, _08037480 @ =sElements\n\
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
_08037480: .4byte sElements\n\
 .syntax divided\n");
}

NAKED static void initLaserShot(Weapon* w) {
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
	ldr r6, _08037614 @ =sLaserShotCollisions\n\
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
_08037614: .4byte sCollisions+(24*6)\n\
 .syntax divided\n");
}

static void initBurstShotBullet(struct ZeroBuster* p) {
  struct Zero* z = (p->props).z;

  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM083_BURST_SHOT_FIREWORK, 3));
  PlaySound(SE_CHARGE_BUSTER);
  if (p->flags & X_FLIP) {
    p->d.x = PIXEL(6);
  } else {
    p->d.x = -PIXEL(6);
  }
  p->d.y = 0;
  p->work[2] = 0x14;

  _INIT_BODY(p, &sCollisions[8], 1);
  InitWeaponBody(&p->body, &sCollisions[8], (u8)(CalcBusterBonus(z) + 6), ELEMENT_FLAME, ELEMENT_ENCHANTABLE, -1);
}

static void initBlizzardArrowBullet(struct ZeroBuster* p) {
  struct Zero* z = (p->props).z;

  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);

  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, MOTION(DM082_BLIZZ_ARROW, 0));
  PlaySound(SE_CHARGE_BUSTER);

  _INIT_BODY(p, &sCollisions[10], 1);
  p->work[2] = 0;
  InitWeaponBody(&p->body, &sCollisions[10], (u8)(CalcBusterBonus(z) + 10), ELEMENT_ICE, -1, -1);
}

static void LemonBullet_Update(Object* p) {
  bool8 dir;
  p->coord.x += p->d.x;
  p->coord.y += p->d.y;

  if ((p->mode[1] == 0) && isBlocked((void*)p)) {  // 跳弾
    CreateParticle(&p->coord, 6, (p->flags >> 4) & 1);
    p->d.x = -p->d.x;
    if (dir = RANDOM(RNG_0202f388) & 1, dir) {
      p->d.y = p->d.x;
    } else {
      p->d.y = -p->d.x;
    }
    PlaySound(SE_BLOCKED);
    EXIT_BODY(p);
    p->mode[1]++;
  }

  if (shouldDelete((void*)p)) SET_WEAPON_ROUTINE(p, ENTITY_DIE);
}

// 0x08037810
static void SemiBullet_Update(Object* p) {
  static const struct Rect sSemiBulletSize = {PIXEL(0), PIXEL(4), PIXEL(10), PIXEL(8)};  // 0x0835ee7c

  if (p->mode[1] == 0) {
    if (buster_08037f78((void*)p, &sSemiBulletSize)) {
      SetSpriteAnimation(p, MOTION(DM135_UNK, 0));
      p->mode[1]++;
    }
  } else {
    p->coord.x += p->d.x;
    p->coord.y += p->d.y;
  }

  if (isBlocked((void*)p)) {
    CreateParticle(&p->coord, 6, (p->flags >> 4) & 1);
    PlaySound(SE_BLOCKED);
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
  } else if (shouldDelete((void*)p)) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
  }
}

static void FullBullet_Update(struct ZeroBuster* p) {
  static const struct Rect sFullBulletSize = {PIXEL(3), PIXEL(4), PIXEL(8), PIXEL(2)};

  if (p->mode[1] == 0) {
    if (buster_08037f78((void*)p, &sFullBulletSize)) {
      const motion_t* m = sFullBulletMotions;
      SetSpriteAnimation(p, m[(&p->props)->element]);
      p->mode[1]++;
    }
  } else {
    p->coord.x += p->d.x;
    p->coord.y += p->d.y;
  }

  if (isBlocked((void*)p)) {
    CreateParticle(&p->coord, 6, (p->flags >> 4) & 1);
    PlaySound(SE_BLOCKED);
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
  } else if (shouldDelete((void*)p)) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
  }
}

NAKED static void LaserShot_Main(struct ZeroBuster* w) {
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
	bl Camera_GetDistance\n\
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
	bl Camera_GetDistance\n\
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

NAKED static void BurstShot_Main(struct ZeroBuster* w) {
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

static void BlizzardArrow_Update(struct ZeroBuster* p) {
  struct Zero* z = (p->props).z;
  switch (p->mode[1]) {
    case 0: {
      if (p->motion.state == ANIM_NEXT_GOTO) {
        p->work[2]++;
        if (p->work[2] > 4) {
          p->mode[1]++;
          break;
        }
        if (p->work[2] > 1) {
          CreateBlizzardArrow(z, &p->coord, p->work[2] - 2, (p->flags >> 4) & 1);
        }
      }
      break;
    }

    case 1: {
      SetSpriteAnimation(p, MOTION(DM082_BLIZZ_ARROW, 1));
      p->work[2] = 0;
      p->mode[1]++;
      break;
    }

    case 2: {
      if (IsSpriteAnimEnd(p)) SET_WEAPON_ROUTINE(p, ENTITY_DIE);
      break;
    }
  }
}

// 0x08037ed8
extern const s16 s16_ARRAY_0835ee8c[];

static u8 shouldDelete(struct Weapon* w) {
  struct ZeroBusterProps* b = &((struct ZeroBuster*)w)->props;
  struct Zero* z = b->z;
  metatile_attr_t attr;
  if (b->unk_c3 != 0) {
    b->unk_c3--;
    return 0;
  }
  attr = FUN_080098a4((w->s).coord.x, (w->s).coord.y);
  if (attr == MT_LADDER_FLOOR || attr == MT_LADDER) {
    attr = 0;
  }
  if (attr & MTATTR_SOFT_PLATFORM) {
    attr = 0;
  }
  if (attr & 0xf) {
    CreateParticle(&(w->s).coord, 7, ((w->s).flags >> 4) & 1);
    return 1;
  }
  if (z->body.status & 8) {
    return 1;
  }
  if (Camera_GetDistance(&gStageRun.vm.camera, &(w->s).coord) > s16_ARRAY_0835ee8c[(w->s).work[0]]) {
    return 2;
  }
  return 0;
}

NAKED static bool8 buster_08037f78(Weapon* w, const struct Rect* size) {
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
static void onCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    struct ZeroBuster* p = (struct ZeroBuster*)body->parent;

    IncWeaponUseCount(WEAPON_BUSTER);
    if (!(body->enemy->status & BODY_STATUS_DEAD) || (p->work[0] == 0)) {
      if (p->work[0] != 4) (&p->props)->unk_c0 = 1;
    }
  }
}

// 弾丸がブロックされたか(硬いものにあたって弾かれたか)
static bool8 isBlocked(Weapon* p) {
  u32 status = (p->body).status;
  if (status & BODY_STATUS_BLOCKED) return TRUE;
  return FALSE;
}

const s16 s16_ARRAY_0835ee8c[9] = {
    0x0400, 0x2400, 0x2800, 0x4000, 0x2800, 0x2800, 0x2800, 0x2800, 0x2800,
};

static const u8 sElements[4] = {0, 1, 2, 3};

// 0x0835eea4
static const struct Collision sCollisions[14] = {
    // Lemon
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 2,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    // Semi charge
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      nature : 0x01,
      comboLv : 1,
      remaining : 1,
      layer : 0x80000000,
      range : {PIXEL(2), PIXEL(0), PIXEL(18), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(2), PIXEL(0), PIXEL(18), PIXEL(16)},
    },
    // Full charge
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      nature : 0x02,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000002,
      range : {PIXEL(6), PIXEL(0), PIXEL(24), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(6), PIXEL(0), PIXEL(24), PIXEL(20)},
    },
    // Laser shot
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : 0x04,
      nature : 0x02,
      comboLv : 1,
      remaining : 1,
      layer : 0x00010000,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    // Burst shot
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : 0x06,
      nature : 0x02,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000008,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    // Blizzard arrow
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      atkType : 0x07,
      nature : 0x02,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000010,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(16), PIXEL(16)},
    },
    // VShot
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 8,
      nature : 0x02,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000002,
      range : {PIXEL(6), PIXEL(0), PIXEL(24), PIXEL(20)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      LAYER(0xFFFFFFFF),
      hitzone : 255,
      remaining : 0,
      range : {PIXEL(6), PIXEL(0), PIXEL(24), PIXEL(20)},
    },
};

// clang-format off
const WeaponRoutine gBusterRoutine = {
    [ENTITY_INIT] =      (void*)Buster_Init,
    [ENTITY_UPDATE] =    (void*)Buster_Update,
    [ENTITY_DIE] =       (void*)Buster_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)Buster_Delete,    
};
// clang-format on

static const motion_t sFullBulletMotions[4] = {
    MOTION(0x89, 0x00),
    MOTION(0x8A, 0x00),
    MOTION(0x8B, 0x00),
    MOTION(0x8C, 0x00),
};
