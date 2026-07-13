#include "collision.h"
#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "score.h"
#include "sound.h"
#include "weapon.h"
#include "zero.h"

static const u8 sElements[4];
static const motion_t gShieldGuardMotions[5];
static const struct Collision sShieldGuardCollisions[2][5];
static const s16 sCoords[11][2];

static void onCollision(struct Body* body, Coords32* r1, Coords32* r2);
static void ShieldGuard_Update(struct Weapon* w);

void MenuExit_ShieldGuard(struct WeaponCommon* p) {
  if (((p->props).z)->unk_136 & (1 << 3)) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateWeaponShieldGuard(struct Zero* z, u8 n) {
  struct WeaponCommon* p;
  u8 element;

  KillAllWeapons(DeleteSaber);
  p = (struct WeaponCommon*)AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SHIELD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_GUARD);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[0], (p->s).palID = gWeaponPalIDs[0];
      element = sElements[((&z->unk_b4)->status).element];
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_GUARD);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[1], (p->s).palID = gWeaponPalIDs[1];
      element = sElements[((&z->unk_b4)->status).element];
      SetWeaponElement(1, element);
    }
    (p->props).z = z;
    (p->s).work[0] = n, (p->s).work[1] = 0;
  }
  return (void*)p;
}

static void ShieldGuard_Init(struct WeaponCommon* p) {
  struct Zero* z = (p->props).z;
  SET_WEAPON_ROUTINE(p, ENTITY_UPDATE);
  EnableSpriteAnimation_Normal(p);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, gShieldGuardMotions[(p->s).work[0]]);

  if (isElfUsed_2(z, ELF_ENETHAS)) {
    ((&p->props)->props)[1][0] = 1;
  } else {
    ((&p->props)->props)[1][0] = 0;
  }

  ((&p->props)->props)[1][1] = 0;
  ((&p->props)->props)[1][2] = 0;
  INIT_BODY(p, &sShieldGuardCollisions[((&p->props)->props)[1][0]][(p->s).work[0]], 1, onCollision);
  ShieldGuard_Update((void*)p);
}

static void FUN_08039358(struct WeaponCommon* p);
static void FUN_08039368(struct WeaponCommon* p);

// clang-format off
static const WeaponFunc sUpdates[5] = {
    (void*)FUN_08039358,
    (void*)FUN_08039368,
    (void*)FUN_08039358,
    (void*)FUN_08039358,
    (void*)FUN_08039358,
};
// clang-format on

NAKED static void ShieldGuard_Update(struct Weapon* w) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0xc\n\
	adds r5, r0, #0\n\
	adds r4, r5, #0\n\
	adds r4, #0xb4\n\
	ldr r0, [r4]\n\
	str r0, [sp]\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #1\n\
	bls _08039108\n\
	ldr r1, _08039104 @ =gWeaponFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	b _080392F2\n\
	.align 2, 0\n\
_08039104: .4byte gWeaponFnTable\n\
_08039108:\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #0x63\n\
	bhi _08039112\n\
	adds r0, #1\n\
	strb r0, [r4, #0xe]\n\
_08039112:\n\
	ldr r1, [sp]\n\
	movs r2, #0x9b\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	ldrb r1, [r0]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sb, r0\n\
	cmp r0, #0\n\
	bne _0803913A\n\
	ldr r3, [sp]\n\
	movs r1, #0x97\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	ldrb r1, [r0]\n\
	str r0, [sp, #4]\n\
	cmp r1, #0xff\n\
	bne _08039178\n\
_0803913A:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _08039174 @ =gWeaponFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080392F2\n\
	.align 2, 0\n\
_08039174: .4byte gWeaponFnTable\n\
_08039178:\n\
	ldr r0, [sp]\n\
	movs r1, #0x2f\n\
	bl isElfUsed_2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	cmp r0, #0\n\
	beq _08039228\n\
	ldrb r0, [r4, #0xe]\n\
	cmp r0, #3\n\
	bhi _080391F4\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #0\n\
	bne _080391B0\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r3, [sp, #4]\n\
	ldrb r2, [r3]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #3\n\
	ldr r2, _080391F0 @ =sShieldGuardCollisions+120\n\
	adds r1, r1, r2\n\
	bl SetDDP\n\
	movs r0, #1\n\
	strb r0, [r4, #0xc]\n\
_080391B0:\n\
	ldrb r0, [r4, #0xd]\n\
	adds r6, r4, #0\n\
	adds r7, r5, #0\n\
	adds r7, #0x70\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	str r1, [sp, #8]\n\
	movs r2, #0x4a\n\
	adds r2, r2, r5\n\
	mov sl, r2\n\
	cmp r0, #0\n\
	beq _0803925A\n\
	movs r4, #0\n\
	cmp sb, r0\n\
	bhs _080391E6\n\
_080391CE:\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	adds r1, #0x64\n\
	movs r2, #0\n\
	bl CreatePickupItem\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	ldrb r3, [r6, #0xd]\n\
	cmp r4, r3\n\
	blo _080391CE\n\
_080391E6:\n\
	movs r0, #0x1c\n\
	bl PlaySound\n\
	b _0803925A\n\
	.align 2, 0\n\
_080391F0: .4byte sShieldGuardCollisions+120\n\
_080391F4:\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, [sp, #4]\n\
	ldrb r2, [r1]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #3\n\
	ldr r2, _08039224 @ =sShieldGuardCollisions\n\
	adds r1, r1, r2\n\
	bl SetDDP\n\
	mov r2, sb\n\
	strb r2, [r4, #0xc]\n\
	adds r6, r4, #0\n\
	adds r7, r5, #0\n\
	adds r7, #0x70\n\
	adds r3, r5, #0\n\
	adds r3, #0x4c\n\
	str r3, [sp, #8]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r5\n\
	mov sl, r0\n\
	b _0803925A\n\
	.align 2, 0\n\
_08039224: .4byte sShieldGuardCollisions\n\
_08039228:\n\
	ldrb r0, [r4, #0xc]\n\
	adds r6, r4, #0\n\
	adds r7, r5, #0\n\
	adds r7, #0x70\n\
	adds r1, r5, #0\n\
	adds r1, #0x4c\n\
	str r1, [sp, #8]\n\
	movs r2, #0x4a\n\
	adds r2, r2, r5\n\
	mov sl, r2\n\
	cmp r0, #1\n\
	bne _0803925A\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r3, [sp, #4]\n\
	ldrb r2, [r3]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #3\n\
	ldr r2, _080392B0 @ =sShieldGuardCollisions\n\
	adds r1, r1, r2\n\
	bl SetDDP\n\
	mov r0, r8\n\
	strb r0, [r6, #0xc]\n\
_0803925A:\n\
	ldrb r0, [r5, #0x1e]\n\
	lsls r0, r0, #8\n\
	ldrb r1, [r7]\n\
	orrs r1, r0\n\
	ldr r2, _080392B4 @ =gShieldGuardMotions\n\
	ldr r3, [sp, #4]\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r2, [r0]\n\
	cmp r1, r2\n\
	beq _0803929A\n\
	adds r0, r5, #0\n\
	adds r1, r2, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldrb r2, [r6, #0xc]\n\
	lsls r1, r2, #4\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #3\n\
	ldr r2, [sp, #4]\n\
	ldrb r3, [r2]\n\
	lsls r2, r3, #1\n\
	adds r2, r2, r3\n\
	lsls r2, r2, #3\n\
	ldr r3, _080392B0 @ =sShieldGuardCollisions\n\
	adds r2, r2, r3\n\
	adds r1, r1, r2\n\
	bl SetDDP\n\
_0803929A:\n\
	ldr r3, [sp]\n\
	ldrb r0, [r3, #0xa]\n\
	lsrs r2, r0, #4\n\
	movs r0, #1\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	beq _080392B8\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0x10\n\
	orrs r0, r1\n\
	b _080392BE\n\
	.align 2, 0\n\
_080392B0: .4byte sShieldGuardCollisions\n\
_080392B4: .4byte gShieldGuardMotions\n\
_080392B8:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080392BE:\n\
	strb r0, [r5, #0xa]\n\
	adds r1, r2, #0\n\
	movs r4, #0\n\
	ldr r0, [sp, #8]\n\
	strb r1, [r0]\n\
	lsls r1, r1, #4\n\
	mov r3, sl\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldr r1, _08039304 @ =sUpdates\n\
	ldr r2, [sp, #4]\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	adds r0, r5, #0\n\
	bl _call_via_r1\n\
	strb r4, [r6, #0xd]\n\
_080392F2:\n\
	add sp, #0xc\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08039304: .4byte sUpdates\n\
   .syntax divided\n");
}

static void ShieldGuard_Die(struct Weapon* w) {
  SET_WEAPON_ROUTINE(w, ENTITY_EXIT);
  return;
}

static void onCollision(struct Body* body, Coords32* c1 UNUSED, Coords32* c2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B6) {
    struct Entity* q;
    if ((q = (struct Entity*)body->enemy->parent, q->kind == ENTITY_PROJECTILE) && (q->id == PROJECTILE_LEMON)) {
      struct WeaponCommon* p = (struct WeaponCommon*)body->parent;
      (p->s).unk_coord = q->coord;
      (&p->props)->props[1][1]++;
    }
  }
}

static void FUN_08039358(struct WeaponCommon* p) {
  struct Zero* z = (p->props).z;
  (p->s).coord.x = (z->s).coord.x;
  (p->s).coord.y = (z->s).coord.y;
}

static void FUN_08039368(struct WeaponCommon* p) {
  struct Zero* z = (p->props).z;
  if ((p->s).flags & X_FLIP) {
    (p->s).coord.x = (z->s).coord.x + sCoords[(z->s).motion.cmdIdx][0];
  } else {
    (p->s).coord.x = (z->s).coord.x - sCoords[(z->s).motion.cmdIdx][0];
  }
  (p->s).coord.y = (z->s).coord.y + sCoords[(z->s).motion.cmdIdx][1];
}

// --------------------------------------------

// clang-format off
static const motion_t gShieldGuardMotions[5] = {
    MOTION(DM108_UNK, 0),
    MOTION(DM110_UNK, 0),
    MOTION(DM111_UNK, 0),
    MOTION(DM113_UNK, 0),
    MOTION(DM115_UNK, 0),
};
// clang-format on

static const u8 sElements[4] = {0, 1, 2, 3};

static const struct Collision sShieldGuardCollisions[2][5] = {
    {
        [0] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          hardness : METAL,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0F00, -0x1600, 0x1000, 0x1E00},
        },
        [1] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          hardness : METAL,
          remaining : 0,
          layer : 0x00000000,
          range : {0x0100, 0x0000, 0x1000, 0x1E00},
        },
        [2] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          hardness : METAL,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0F00, -0x1500, 0x1000, 0x1E00},
        },
        [3] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          hardness : METAL,
          remaining : 0,
          layer : 0x00000000,
          range : {0x0C00, -0x1300, 0x1000, 0x1E00},
        },
        [4] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          hardness : METAL,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0E00, -0x1200, 0x1000, 0x1E00},
        },
    },
    {
        [0] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0F00, -0x1600, 0x1000, 0x1E00},
        },
        [1] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          layer : 0x00000000,
          range : {0x0100, 0x0000, 0x1000, 0x1E00},
        },
        [2] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0F00, -0x1500, 0x1000, 0x1E00},
        },
        [3] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          layer : 0x00000000,
          range : {0x0C00, -0x1300, 0x1000, 0x1E00},
        },
        [4] = {
          kind : DRP2,
          faction : FACTION_ALLY,
          special : 0,
          damage : 0,
          LAYER(0xFFFFFFFF),
          hitzone : 0xFF,
          remaining : 0,
          layer : 0x00000000,
          range : {-0x0E00, -0x1200, 0x1000, 0x1E00},
        },
    },
};

// clang-format off
static const s16 sCoords[11][2] = {
    {PIXEL(22), -PIXEL(20)},
    {PIXEL(21), -PIXEL(20)},
    {PIXEL(22), -PIXEL(21)},
    {PIXEL(22), -PIXEL(19)},
    {PIXEL(21), -PIXEL(19)},
    {PIXEL(20), -PIXEL(19)},
    {PIXEL(21), -PIXEL(20)},
    {PIXEL(22), -PIXEL(21)},
    {PIXEL(22), -PIXEL(19)},
    {PIXEL(21), -PIXEL(19)},
    {PIXEL(20), -PIXEL(19)},
};
// clang-format on

// clang-format off
const WeaponRoutine gShieldGuardRoutine = {
    [ENTITY_INIT] =      (void*)ShieldGuard_Init,
    [ENTITY_UPDATE] =    (void*)ShieldGuard_Update,
    [ENTITY_DIE] =       (void*)ShieldGuard_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on
