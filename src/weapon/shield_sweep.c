#include "global.h"
#include "score.h"
#include "weapon.h"

static void ShieldSweep_Init(Weapon* p);
static void ShieldSweep_Update(Weapon* p);
static void ShieldSweep_Die(Weapon* p);

// clang-format off
const WeaponRoutine gShieldSweepRoutine = {
    [ENTITY_INIT] =      (void*)ShieldSweep_Init,
    [ENTITY_UPDATE] =    (void*)ShieldSweep_Update,
    [ENTITY_DIE] =       (void*)ShieldSweep_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteWeapon,
    [ENTITY_EXIT] =      (void*)DeleteEntity,    
};
// clang-format on

void MenuExit_ShieldSweep(WeaponCommon* p) {
  if ((p->props).z->unk_136 & (1 << WEAPON_SHIELD)) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_WEAPON_ROUTINE(p, ENTITY_DISAPPEAR);
  }
}

struct Entity* CreateShieldSweep(struct Zero* z, struct Entity* q, u8 n) {
  u8 element;
  WeaponCommon* p = AllocEntityLast(gWeaponHeaderPtr);
  if (p != NULL) {
    if ((z->unk_b4).mainCopy == WEAPON_SHIELD) {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_SWEEP);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[0], p->palID = gWeaponPalIDs[0];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(0, element);
    } else {
      INIT_WEAPON_ROUTINE(p, WEAPON_MOVE_SHIELD_SWEEP);
      p->flags2 &= ~ENTITY_FLAGS2_B6;
      p->renderPrio = 16;
      p->tileNum = gWeaponTileNum[1], p->palID = gWeaponPalIDs[1];
      element = ((&z->unk_b4)->status).element;
      SetWeaponElement(1, element);
    }
    (p->props).z = z;
    p->unk_28 = q;
    p->work[0] = n, p->work[1] = 0;
  }
  return (void*)p;
}

static void ShieldSweep_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

NAKED static void ShieldSweep_Init(Weapon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r6, [r4, #0x28]\n\
	bl InitNonAffineMotion\n\
	adds r0, r4, #0\n\
	bl ResetDynamicMotion\n\
	adds r0, r4, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #2\n\
	adds r2, r0, #0\n\
	orrs r2, r1\n\
	movs r0, #1\n\
	movs r3, #0\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	ldrb r0, [r6, #0xa]\n\
	lsrs r1, r0, #4\n\
	movs r0, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0803C270\n\
	movs r0, #0x10\n\
	orrs r2, r0\n\
	b _0803C274\n\
_0803C270:\n\
	movs r0, #0xef\n\
	ands r2, r0\n\
_0803C274:\n\
	strb r2, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r3, r4, #0\n\
	adds r3, #0x4a\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803C2A0\n\
	ldr r0, _0803C29C @ =0xFFFFFA00\n\
	b _0803C2A4\n\
	.align 2, 0\n\
_0803C29C: .4byte 0xFFFFFA00\n\
_0803C2A0:\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #3\n\
_0803C2A4:\n\
	str r0, [r4, #0x64]\n\
	ldrb r5, [r4, #0x10]\n\
	cmp r5, #0\n\
	bne _0803C2BA\n\
	movs r1, #0x8d\n\
	lsls r1, r1, #8\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	strb r5, [r4, #0x12]\n\
	b _0803C2CA\n\
_0803C2BA:\n\
	ldr r1, _0803C2F0 @ =0x00008D01\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	ldr r0, [r6, #0x54]\n\
	ldr r1, [r6, #0x58]\n\
	str r0, [r4, #0x54]\n\
	str r1, [r4, #0x58]\n\
_0803C2CA:\n\
	ldr r1, _0803C2F4 @ =ShieldSweep_OnCollision\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	str r1, [r0, #0x24]\n\
	ldr r1, _0803C2F8 @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl ShieldSweep_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803C2F0: .4byte 0x00008D01\n\
_0803C2F4: .4byte ShieldSweep_OnCollision\n\
_0803C2F8: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

NAKED static void ShieldSweep_Update(Weapon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x28]\n\
	bl UpdateEntityAnim\n\
	ldrb r2, [r4, #0x10]\n\
	cmp r2, #0\n\
	bne _0803C3BE\n\
	ldrb r0, [r5, #0xc]\n\
	cmp r0, #1\n\
	bhi _0803C318\n\
	ldrb r0, [r5, #0xd]\n\
	cmp r0, #3\n\
	beq _0803C354\n\
_0803C318:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _0803C350 @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _0803C3E0\n\
	.align 2, 0\n\
_0803C350: .4byte gWeaponFnTable\n\
_0803C354:\n\
	ldr r0, [r5, #0x60]\n\
	cmp r0, #0\n\
	bne _0803C3B4\n\
	ldrb r0, [r4, #0xa]\n\
	movs r6, #1\n\
	adds r2, r6, #0\n\
	orrs r2, r0\n\
	strb r2, [r4, #0xa]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4, #0x64]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r5, #0x58]\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #4\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	ldrb r1, [r4, #0x12]\n\
	adds r3, r1, #1\n\
	strb r3, [r4, #0x12]\n\
	movs r5, #1\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803C3E0\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x19\n\
	ands r0, r6\n\
	cmp r0, #0\n\
	beq _0803C3A2\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	lsrs r1, r2, #4\n\
	adds r2, r5, #0\n\
	bics r2, r1\n\
	movs r1, #4\n\
	bl CreateParticle\n\
	b _0803C3E0\n\
_0803C3A2:\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	lsrs r1, r2, #4\n\
	adds r2, r5, #0\n\
	bics r2, r1\n\
	movs r1, #5\n\
	bl CreateParticle\n\
	b _0803C3E0\n\
_0803C3B4:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	b _0803C3E0\n\
_0803C3BE:\n\
	adds r0, r4, #0\n\
	adds r0, #0x73\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0803C3E0\n\
	ldr r1, _0803C3E8 @ =gWeaponFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl ShieldSweep_Die\n\
_0803C3E0:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0803C3E8: .4byte gWeaponFnTable\n\
 .syntax divided\n");
}

static void ShieldSweep_Die(Weapon* p) {
  p->flags &= ~DISPLAY;
  SET_WEAPON_ROUTINE(p, ENTITY_EXIT);
}

// 0x0803C40C
static void ShieldSweep_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  if (body->hitboxFlags & BODY_STATUS_B2) IncWeaponUseCount(WEAPON_SHIELD);
}
