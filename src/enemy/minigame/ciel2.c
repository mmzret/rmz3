#include "collision.h"
#include "enemy.h"
#include "global.h"

static void CielMinigameEnemy2_Init(struct Enemy* p);
static void CielMinigameEnemy2_Update(struct Enemy* p);
static void CielMinigameEnemy2_Die(struct Enemy* p);

// clang-format off
const EnemyRoutine gCielMinigameEnemy2Routine = {
    [ENTITY_INIT] =      CielMinigameEnemy2_Init,
    [ENTITY_UPDATE] =    CielMinigameEnemy2_Update,
    [ENTITY_DIE] =       CielMinigameEnemy2_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteEnemy,
    [ENTITY_EXIT] =      (EnemyFunc)DeleteEntity,
};
// clang-format on

// --------------------------------------------

struct Enemy* FUN_0809c1cc(struct Entity* e, u8 a, u8 b) {
  struct Enemy* p = (struct Enemy*)AllocEntityLast(gEnemyHeaderPtr);
  if (p != NULL) {
    INIT_ENEMY_ROUTINE(p, ENEMY_CIEL_MG_2);
    (p->s).unk_28 = e;
    (p->s).work[0] = a;
    (p->s).work[1] = b;
  }
  return p;
}

// --------------------------------------------

NAKED static void CielMinigameEnemy2_Init(struct Enemy* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x28]\n\
	ldr r1, _0809C2D4 @ =gEnemyFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	movs r1, #0xe9\n\
	lsls r1, r1, #8\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	subs r2, #1\n\
	ldrb r0, [r2]\n\
	movs r1, #0xc\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xde\n\
	lsls r0, r0, #4\n\
	adds r4, r4, r0\n\
	ldrb r0, [r5, #0x10]\n\
	adds r4, r4, r0\n\
	ldrb r1, [r4]\n\
	strb r1, [r5, #0x12]\n\
	adds r1, #5\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r5, #0\n\
	bl ForceEntityPalette\n\
	movs r0, #0xd8\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x54]\n\
	ldrb r1, [r5, #0x10]\n\
	lsls r1, r1, #4\n\
	movs r0, #0x30\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x58]\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #3\n\
	bne _0809C2C6\n\
	movs r0, #0xe8\n\
	lsls r0, r0, #8\n\
	str r0, [r5, #0x54]\n\
_0809C2C6:\n\
	ldrb r0, [r5, #0x10]\n\
	cmp r0, #0\n\
	beq _0809C2D0\n\
	cmp r0, #3\n\
	bne _0809C2DC\n\
_0809C2D0:\n\
	ldr r0, _0809C2D8 @ =0xFFFFFF00\n\
	b _0809C2DE\n\
	.align 2, 0\n\
_0809C2D4: .4byte gEnemyFnTable\n\
_0809C2D8: .4byte 0xFFFFFF00\n\
_0809C2DC:\n\
	movs r0, #0\n\
_0809C2DE:\n\
	str r0, [r5, #0x5c]\n\
	adds r1, r5, #0\n\
	adds r1, #0xb4\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r1]\n\
	adds r1, #4\n\
	ldr r0, [r5, #0x58]\n\
	str r0, [r1]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	str r0, [r5, #0x60]\n\
	adds r0, r5, #0\n\
	bl CielMinigameEnemy2_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void CielMinigameEnemy2_Update(struct Enemy* p) {
  struct Entity* e = (p->s).unk_28;

  switch ((p->s).mode[1]) {
    case 0:
      if (*((u8*)e + 0xE0F) <= gEnemyHeaderPtr->remaining && *((u8*)e + 0xE12) == 0) {
        u8* tbl = (u8*)e + 0xDE0;
        (p->s).work[2] = tbl[(p->s).work[0]];
        (p->s).mode[1]++;
      }
      break;
    case 1:
      (p->s).coord.x += (p->s).d.x;
      (p->s).coord.y += (p->s).d.y;
      if ((p->s).coord.y >= *(s32*)&p->buffer[4] + 0x1000) {
        ForceEntityPalette(&p->s, (p->s).work[2] + 5);
        (p->s).coord.x = *(s32*)&p->buffer[0];
        (p->s).coord.y = *(s32*)&p->buffer[4];
        (p->s).mode[1] = 0;
      }
      break;
  }
  UpdateSpriteAnimation(p);
}

static void CielMinigameEnemy2_Die(struct Enemy* p) { SET_ENEMY_ROUTINE(p, ENTITY_EXIT); }
