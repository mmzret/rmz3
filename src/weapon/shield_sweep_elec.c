#include "global.h"
#include "score.h"
#include "weapon.h"

// クロールシールドの電気びりびり

// 0x08361724
static const struct Collision sCollisions[2] = {
    {
      kind : DDP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 4,
      element : ELEMENT_THUNDER,
      nature : ELEMENT_ENCHANTABLE,
      comboLv : 1,
      remaining : 1,
      layer : 0x00000004,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
    {
      kind : DRP,
      faction : FACTION_ALLY,
      special : HALFABLE,
      damage : 0,
      LAYER(0xFFFFFFFF),
      hitzone : 0xFF,
      remaining : 0,
      range : {PIXEL(0), PIXEL(0), PIXEL(18), PIXEL(18)},
    },
};

static void ElecShieldSweep_Init(Weapon* p);
static void ElecShieldSweep_Update(struct Entity* p);
static void ElecShieldSweep_Die(struct Entity* p);

// clang-format off
const WeaponRoutine gElecShieldSweepRoutine = {
    [ENTITY_INIT] =      (void*)ElecShieldSweep_Init,
    [ENTITY_UPDATE] =    (void*)ElecShieldSweep_Update,
    [ENTITY_DIE] =       (void*)ElecShieldSweep_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_ShieldSweepElec(Weapon* p) {
  Player* z = (Player*)p->unk_28;
  if (((&z->unk_b4)->status).element != ELEMENT_THUNDER || (z->unk_136 & (1 << WEAPON_SHIELD))) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

Weapon* CreateShieldSweepElec(Player* z, s32 x, s32 y) {
  Weapon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SABER) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_SWEEP_ELEC);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_SWEEP_ELEC);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
    }
    p->unk_28 = (void*)z;
    p->coord.x = x, p->coord.y = y;
    p->work[0] = 0, p->work[1] = 0;
  }
  return p;
}

NAKED static void ElecShieldSweep_Init(Weapon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	ldr r0, [r7, #0x28]\n\
	mov r8, r0\n\
	ldr r1, _0803CD40 @ =gWeaponFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r7, #0x14]\n\
	adds r0, r7, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r7, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r7, #0xb]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	movs r6, #0\n\
	strb r0, [r7, #0xb]\n\
	movs r0, #0\n\
	strh r6, [r7, #0x20]\n\
	adds r1, r7, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #1\n\
	movs r2, #0\n\
	mov sb, r2\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _0803CD44 @ =0x00001A06\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r7, #0xa]\n\
	adds r4, r7, #0\n\
	adds r4, #0x74\n\
	ldr r5, _0803CD48 @ =sCollisions\n\
	adds r2, r7, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	movs r3, #1\n\
	bl InitBody\n\
	str r7, [r4, #0x2c]\n\
	str r6, [r4, #0x24]\n\
	mov r0, r8\n\
	bl CalcShieldBonus\n\
	adds r2, r0, #0\n\
	adds r2, #4\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	str r3, [sp]\n\
	str r3, [sp, #4]\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl InitWeaponBody\n\
	ldrb r2, [r7, #0x10]\n\
	cmp r2, #0\n\
	beq _0803CD4C\n\
	ldrb r0, [r7, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _0803CD52\n\
	.align 2, 0\n\
_0803CD40: .4byte gWeaponFnTable\n\
_0803CD44: .4byte 0x00001A06\n\
_0803CD48: .4byte sCollisions\n\
_0803CD4C:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_0803CD52:\n\
	strb r0, [r7, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r7, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r7, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r0, #0x20\n\
	strb r0, [r7, #0x12]\n\
	ldr r1, _0803CD90 @ =ElecShieldSweep_OnCollision\n\
	adds r0, r7, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	adds r0, r7, #0\n\
	bl ElecShieldSweep_Update\n\
	add sp, #8\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803CD90: .4byte ElecShieldSweep_OnCollision\n\
 .syntax divided\n");
}

static void ElecShieldSweep_Update(struct Entity* p) {
  UpdateSpriteAnimation(p);
  if (p->work[2] < 16) {
    if (p->work[2] & 1) {
      p->flags &= ~DISPLAY;
    } else {
      p->flags |= DISPLAY;
    }
  }
  if (((--p->work[2]) == 0xFF) || p->work[1]) {
    SET_WEAPON_ROUTINE(p, ENTITY_DIE);
    ElecShieldSweep_Die(p);
  }
}

static void ElecShieldSweep_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// 0x0803ce10
static void ElecShieldSweep_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) {
    struct Entity* p = body->parent;
    IncWeaponUseCount(WEAPON_SHIELD);
    p->work[1] = 1;
  }
}
