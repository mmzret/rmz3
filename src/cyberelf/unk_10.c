#include "cyberelf.h"
#include "global.h"
#include "vfx.h"
#include "zero.h"

// サテライトエルフ全般？

struct CyberElf10 {
  COLLISION_OBJECT_HDR;  // 0x00
  Player* player;        // 0xB4
  Coords32 c_b8;         // 0xB8
  u8 unk_c0;             // 0xC0
  u8 unk_c1;             // 0xC1
  u16 unk_c2;            // 0xC2
};
static_assert(sizeof(struct CyberElf10) == sizeof(CyberElf));

static void Elf10_Init(struct CyberElf10* p);
static void Elf10_Update(struct CyberElf10* p);
static void Elf10_Die(struct Entity* p);

// clang-format off
const ElfRoutine gElf10Routine = {
    [ENTITY_INIT] =      (void*)Elf10_Init,
    [ENTITY_UPDATE] =    (void*)Elf10_Update,
    [ENTITY_DIE] =       (void*)Elf10_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

// 0x080e4b88
void MenuExit_CyberElf10(struct CyberElf10* p) {
  Player* player = p->player;
  if (p->unk_coord.x == 0) {
    if (p->work[3] == ((&player->unk_b4)->status).satelites[0]) {
      return;
    }
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
  } else {
    if (p->work[3] == ((&player->unk_b4)->status).satelites[1]) {
      return;
    }
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
  }
  SET_ELF_ROUTINE(p, ENTITY_DISAPPEAR);
}

struct Entity* elf_080e4bf4(Player* player, u8 kind1, u8 kind2, bool8 is_satelite2) {
  struct CyberElf10* p = AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 10);
    p->player = player;
    p->work[0] = kind1, p->work[1] = kind2;
    p->unk_coord.x = is_satelite2;
    if (is_satelite2 == 0) {
      p->work[3] = ((&player->unk_b4)->status).satelites[0];
    } else {
      p->work[3] = ((&player->unk_b4)->status).satelites[1];
    }
  }
  return (struct Entity*)p;
}

static void Elf10_Init(struct CyberElf10* p) {
  struct Zero* z = p->player;
  struct Rect r = gZeroRanges[z->posture];
  EnableSpriteAnimation_Normal(p);
  SetSpriteTableDynamic(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  SetSpriteAnimation(p, GetElfMotion(1));
  UpdateSpriteAnimation(p);
  p->spr.xflip = FALSE, p->spr.oam.xflip = FALSE;
  p->flags &= ~X_FLIP;
  p->coord.x = (z->s).coord.x + r.x;
  p->coord.y = (z->s).coord.y + r.y;
  (p->c_b8).x = p->coord.x;
  (p->c_b8).y = p->coord.y;
  p->unk_c2 = 0x200;
  p->unk_c0 = 0;
  p->unk_c1 = 32;
  p->work[2] = 60;
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  Elf10_Update(p);
}

NAKED static void Elf10_Update(struct CyberElf10* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r5, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r7, [r0]\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldr r0, _080E4D9C @ =gPause\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _080E4D5A\n\
	b _080E500A\n\
_080E4D5A:\n\
	ldr r1, _080E4DA0 @ =0x00000232\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080E4DA8\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
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
	ldr r1, _080E4DA4 @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080E500A\n\
	.align 2, 0\n\
_080E4D9C: .4byte gPause\n\
_080E4DA0: .4byte 0x00000232\n\
_080E4DA4: .4byte gElfFnTable\n\
_080E4DA8:\n\
	adds r0, r7, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E4DC4\n\
	adds r0, r7, #0\n\
	adds r0, #0xa4\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	cmp r0, #0\n\
	bne _080E4DDC\n\
_080E4DC4:\n\
	ldr r1, _080E4DD8 @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	b _080E500A\n\
	.align 2, 0\n\
_080E4DD8: .4byte gElfFnTable\n\
_080E4DDC:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E4E14\n\
	ldr r0, [r5, #0x64]\n\
	cmp r0, #0\n\
	beq _080E4E08\n\
	adds r3, r5, #0\n\
	adds r3, #0xb8\n\
	ldr r0, [r3]\n\
	movs r1, #0xd8\n\
	lsls r1, r1, #5\n\
	adds r0, r0, r1\n\
	ldr r1, [r7, #0x54]\n\
	subs r6, r1, r0\n\
	adds r2, r5, #0\n\
	adds r2, #0xbc\n\
	ldr r0, [r2]\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	b _080E4E50\n\
_080E4E08:\n\
	adds r3, r5, #0\n\
	adds r3, #0xb8\n\
	ldr r0, [r3]\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #4\n\
	b _080E4E40\n\
_080E4E14:\n\
	ldr r0, [r5, #0x64]\n\
	cmp r0, #0\n\
	beq _080E4E38\n\
	adds r3, r5, #0\n\
	adds r3, #0xb8\n\
	ldr r0, [r3]\n\
	ldr r2, _080E4E34 @ =0xFFFFE500\n\
	adds r0, r0, r2\n\
	ldr r1, [r7, #0x54]\n\
	subs r6, r1, r0\n\
	adds r2, r5, #0\n\
	adds r2, #0xbc\n\
	ldr r0, [r2]\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	b _080E4E50\n\
	.align 2, 0\n\
_080E4E34: .4byte 0xFFFFE500\n\
_080E4E38:\n\
	adds r3, r5, #0\n\
	adds r3, #0xb8\n\
	ldr r0, [r3]\n\
	ldr r2, _080E4E98 @ =0xFFFFF300\n\
_080E4E40:\n\
	adds r0, r0, r2\n\
	ldr r1, [r7, #0x54]\n\
	subs r6, r1, r0\n\
	adds r2, r5, #0\n\
	adds r2, #0xbc\n\
	ldr r0, [r2]\n\
	movs r1, #0xa4\n\
	lsls r1, r1, #6\n\
_080E4E50:\n\
	adds r0, r0, r1\n\
	ldr r1, [r7, #0x58]\n\
	subs r4, r1, r0\n\
	mov r8, r3\n\
	mov sb, r2\n\
	adds r0, r6, #0\n\
	adds r1, r4, #0\n\
	bl CalcAngle\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	adds r1, r6, #0\n\
	cmp r6, #0\n\
	bge _080E4E6E\n\
	rsbs r1, r6, #0\n\
_080E4E6E:\n\
	adds r0, r4, #0\n\
	cmp r4, #0\n\
	bge _080E4E76\n\
	rsbs r0, r4, #0\n\
_080E4E76:\n\
	cmp r1, r0\n\
	ble _080E4EA0\n\
	adds r1, r6, #0\n\
	cmp r1, #0\n\
	bge _080E4E82\n\
	rsbs r1, r1, #0\n\
_080E4E82:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	ble _080E4EC4\n\
	ldr r1, [r5, #0x5c]\n\
	ldr r0, _080E4E9C @ =0x000005FF\n\
	cmp r1, r0\n\
	bgt _080E4ED6\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	b _080E4ED4\n\
	.align 2, 0\n\
_080E4E98: .4byte 0xFFFFF300\n\
_080E4E9C: .4byte 0x000005FF\n\
_080E4EA0:\n\
	adds r1, r4, #0\n\
	cmp r1, #0\n\
	bge _080E4EA8\n\
	rsbs r1, r1, #0\n\
_080E4EA8:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	ble _080E4EC4\n\
	ldr r1, [r5, #0x5c]\n\
	ldr r0, _080E4EC0 @ =0x000005FF\n\
	cmp r1, r0\n\
	bgt _080E4ED6\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	b _080E4ED4\n\
	.align 2, 0\n\
_080E4EC0: .4byte 0x000005FF\n\
_080E4EC4:\n\
	ldr r0, [r5, #0x5c]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	cmp r0, r1\n\
	ble _080E4ED0\n\
	str r1, [r5, #0x5c]\n\
_080E4ED0:\n\
	ldr r0, [r5, #0x5c]\n\
	subs r0, #0x20\n\
_080E4ED4:\n\
	str r0, [r5, #0x5c]\n\
_080E4ED6:\n\
	ldr r0, [r5, #0x5c]\n\
	cmp r0, #0x9f\n\
	bgt _080E4EE0\n\
	movs r0, #0xa0\n\
	str r0, [r5, #0x5c]\n\
_080E4EE0:\n\
	mov r6, r8\n\
	ldr r3, _080E4F5C @ =gSineTable\n\
	mov ip, r3\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, ip\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	ldr r0, [r5, #0x5c]\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r6]\n\
	adds r0, r0, r1\n\
	str r0, [r6]\n\
	mov r4, sb\n\
	lsls r0, r2, #1\n\
	add r0, ip\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	ldr r0, [r5, #0x5c]\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r4]\n\
	adds r0, r0, r1\n\
	str r0, [r4]\n\
	adds r1, r5, #0\n\
	adds r1, #0xc0\n\
	ldrb r2, [r1]\n\
	adds r3, r2, #1\n\
	adds r0, r3, #0\n\
	asrs r0, r0, #5\n\
	lsls r0, r0, #5\n\
	subs r0, r3, r0\n\
	strb r0, [r1]\n\
	ldrb r3, [r1]\n\
	lsls r2, r3, #3\n\
	ldr r0, [r5, #0x64]\n\
	cmp r0, #0\n\
	beq _080E4F60\n\
	movs r0, #0x3f\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, ip\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r6]\n\
	subs r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	mvns r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, ip\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r4]\n\
	subs r0, r0, r1\n\
	b _080E4F8A\n\
	.align 2, 0\n\
_080E4F5C: .4byte gSineTable\n\
_080E4F60:\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	add r0, ip\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r1, r1, #2\n\
	mov r2, r8\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x17\n\
	add r0, ip\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #2\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	adds r0, r0, r1\n\
_080E4F8A:\n\
	str r0, [r5, #0x58]\n\
	ldrb r0, [r5, #0x12]\n\
	cmp r0, #0\n\
	beq _080E4F96\n\
	subs r0, #1\n\
	b _080E4FE8\n\
_080E4F96:\n\
	adds r0, r7, #0\n\
	bl CheckPlayerStandStill\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080E4FE6\n\
	ldr r0, [r5, #0x64]\n\
	cmp r0, #0\n\
	bne _080E4FB0\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0]\n\
	b _080E4FB6\n\
_080E4FB0:\n\
	adds r0, r7, #0\n\
	adds r0, #0xb4\n\
	ldrb r1, [r0, #1]\n\
_080E4FB6:\n\
	ldr r0, _080E4FD8 @ =gElfAvailability\n\
	ldr r0, [r0]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E4FDC\n\
	ldrb r2, [r5, #0x10]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	bl FUN_080e5048\n\
	b _080E4FE6\n\
	.align 2, 0\n\
_080E4FD8: .4byte gElfAvailability\n\
_080E4FDC:\n\
	ldrb r2, [r5, #0x10]\n\
	adds r0, r7, #0\n\
	adds r1, r5, #0\n\
	bl FUN_080e5048\n\
_080E4FE6:\n\
	movs r0, #0x3c\n\
_080E4FE8:\n\
	strb r0, [r5, #0x12]\n\
	adds r4, r5, #0\n\
	adds r4, #0xc1\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E500A\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	movs r1, #2\n\
	bl FUN_080bfc94\n\
	movs r0, #0x20\n\
	strb r0, [r4]\n\
_080E500A:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
 .syntax divided\n");
}

static void Elf10_Die(struct Entity* p) {
  FUN_080bfce8(&p->coord, 0);
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}
