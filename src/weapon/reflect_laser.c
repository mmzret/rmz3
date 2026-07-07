#include "collision.h"
#include "global.h"
#include "weapon.h"

struct ReflectLaser {
  OBJECT_HDR;
  // props (56bytes, offset: 0xB4..)
  struct ReflectLaserProps {
    struct Entity* q;  // 0xB4
    Coords32 c_b8;     // 0xB8
    u8 unk_c0;         // 0xC0
    u8 unk_c1[43];     // 0xC1
  } props;
};
static_assert(sizeof(struct ReflectLaser) == sizeof(struct Weapon));

static const struct Collision sCollisions[2];
static const motion_t sMotions[8];

// 0x08361504
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 10,
      atkType : 0x00,
      comboLv : 1,
      hitzone : 0,
      remaining : 1,
      layer : 0x00000001,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(8), PIXEL(8)},
    },
};

static void ReflectLaser_Init(struct ReflectLaser* p);
static void ReflectLaser_Update(struct ReflectLaser* p);
static void ReflectLaser_Die(Object* p);

// clang-format off
const WeaponRoutine gReflectLaserRoutine = {
    [ENTITY_INIT] =      (void*)ReflectLaser_Init,
    [ENTITY_UPDATE] =    (void*)ReflectLaser_Update,
    [ENTITY_DIE] =       (void*)ReflectLaser_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_ReflectLaser(struct Weapon* p) {
  struct Zero* z = (struct Zero*)(p->s).unk_28;
  if (P_ELEMENT(z) != 0) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  if (z->unk_136 & (1 << WEAPON_BUSTER)) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateReflectLaser(struct Zero* z, struct Entity* q, u8 n) {
  struct ReflectLaser* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_BUSTER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_REFLECT_LASER);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[0], (p->s).palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_REFLECT_LASER);
      (p->s).flags2 &= ~ENTITY_FLAGS2_B6;
      (p->s).renderPrio = 16;
      (p->s).tileNum = gWeaponTileNum[1], (p->s).palID = gWeaponPalIDs[1];
    }
    (p->s).unk_28 = (void*)z;
    (p->props).q = q;
    (p->s).work[0] = n, (p->s).work[1] = 0;
  }
  return (void*)p;
}

NAKED static struct Weapon* unused_CreateReflectLaser(struct Zero* z, struct Entity* p, void* r2, u8 r3, u8 r4) { INCCODE("asm/unused/unused_CreateReflectLaser.inc"); }

NAKED static void ReflectLaser_Init(struct ReflectLaser* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	adds r6, r0, #0\n\
	adds r7, r6, #0\n\
	adds r7, #0xb4\n\
	ldr r0, [r7]\n\
	mov r8, r0\n\
	ldr r1, [r6, #0x28]\n\
	mov sl, r1\n\
	ldr r1, _0803AF48 @ =gWeaponFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r6, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	ldr r1, _0803AF4C @ =sMotions\n\
	ldrb r0, [r6, #0x10]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	bl SetMotion\n\
	ldrb r1, [r6, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	movs r1, #0\n\
	mov sb, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r0, r6, #0\n\
	adds r0, #0x4c\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	adds r2, r6, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r6, #0x10]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803AF1A\n\
	ldrb r0, [r6, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r6, #0xa]\n\
	adds r4, r6, #0\n\
	adds r4, #0x74\n\
	ldr r5, _0803AF50 @ =sCollisions\n\
	adds r2, r6, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r6, [r4, #0x2c]\n\
	mov r0, sb\n\
	str r0, [r4, #0x24]\n\
	mov r0, sl\n\
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
	adds r1, r5, #0\n\
	bl InitWeaponBody\n\
_0803AF1A:\n\
	mov r1, r8\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r7, #4]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r7, #8]\n\
	movs r0, #0\n\
	strb r0, [r6, #0x12]\n\
	ldrb r2, [r6, #0x10]\n\
	cmp r2, #5\n\
	bhi _0803AF62\n\
	ldr r1, [r6, #0x28]\n\
	movs r0, #1\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0803AF54\n\
	adds r2, #1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	adds r0, r1, #0\n\
	adds r1, r6, #0\n\
	bl CreateReflectLaser\n\
	b _0803AF62\n\
	.align 2, 0\n\
_0803AF48: .4byte gWeaponFnTable\n\
_0803AF4C: .4byte sMotions\n\
_0803AF50: .4byte sCollisions\n\
_0803AF54:\n\
	adds r2, #1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	adds r0, r1, #0\n\
	mov r1, r8\n\
	bl CreateReflectLaser\n\
_0803AF62:\n\
	adds r0, r6, #0\n\
	bl ReflectLaser_Update\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// 0x0803af78
static void ReflectLaser_Update(struct ReflectLaser* p) {
  struct Entity* q = (&p->props)->q;
  if (q->mode[0] >= ENTITY_DIE) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  UpdateSpriteAnimation(p);
  if ((p->s).work[0] & 1) {
    (p->s).coord.x = ((&p->props)->c_b8).x;
    (p->s).coord.y = ((&p->props)->c_b8).y;
  } else {
    (p->s).coord.x = (q->coord).x + ((((&p->props)->c_b8).x - (q->coord).x) >> 1);
    (p->s).coord.y = (q->coord).y + ((((&p->props)->c_b8).y - (q->coord).y) >> 1);
  }
  ((&p->props)->c_b8).x = (q->coord).x;
  ((&p->props)->c_b8).y = (q->coord).y;
}

static void ReflectLaser_Die(Object* p) {
  EXIT_BODY(p);
  (p->s).flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// clang-format off
static const motion_t sMotions[8] = {
    MOTION(DM080_SEMI_BUSTER, 0),
    MOTION(DM080_SEMI_BUSTER, 0),
    MOTION(DM080_SEMI_BUSTER, 0),
    MOTION(DM080_SEMI_BUSTER, 1),
    MOTION(DM080_SEMI_BUSTER, 1),
    MOTION(DM080_SEMI_BUSTER, 2),
    MOTION(DM080_SEMI_BUSTER, 2),
    MOTION(DM080_SEMI_BUSTER, 2),
}; // 0x08361548
// clang-format on
