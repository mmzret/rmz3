#include "cyberelf.h"
#include "entity.h"
#include "global.h"
#include "stagerun.h"
#include "vfx.h"
#include "zero.h"

// HPゲージを増やすサイバーエルフ(ミルピィ、エルピィ、シルピィ、レルピィ)

struct CyberElf0 {
  OBJECT_HDR;
  // props (16bytes, offset: 0xB4..)
  Coords32 coord_b4;    // 0xB4
  struct Zero* player;  // 0xBC
  u8 unk_c0;            // 0xC0
  u8 unk_c1;            // 0xC1
};
static_assert(sizeof(struct CyberElf0) == sizeof(struct Elf));

static void Elf0_Init(struct CyberElf0* p);
static void Elf0_Update(struct CyberElf0* p);
static void Elf0_Die(struct Entity* p);

// clang-format off
const ElfRoutine gElf0Routine = {
    [ENTITY_INIT] =      (void*)Elf0_Init,
    [ENTITY_UPDATE] =    (void*)Elf0_Update,
    [ENTITY_DIE] =       (void*)Elf0_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateElf0(struct Zero* player, u8 breed, u8 availability, u8 _) {
  struct CyberElf0* p = (struct CyberElf0*)AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    INIT_ELF_ROUTINE(p, 0);
    p->player = player;
    (p->s).work[0] = breed, (p->s).work[1] = availability;
  }
  return (struct Entity*)p;
}

// --------------------------------------------

static void Elf0_Init(struct CyberElf0* p) {
  struct Zero* z = p->player;
  struct Rect r = gZeroRanges[z->posture];
  gPause = TRUE;
  EnableSpriteAnimation_Normal(p);
  ResetDynamicMotion(&p->s);
  (p->s).flags |= DISPLAY;
  (p->s).flags |= FLIPABLE;
  SetSpriteAnimation(p, GetElfMotion(0));
  UpdateSpriteAnimation(p);
  (p->s).spr.xflip = FALSE;
  (p->s).spr.oam.xflip = FALSE;
  (p->s).flags &= ~X_FLIP;
  (p->s).spr.oam.priority = 0;
  (p->s).coord.x = (z->s).coord.x + r.x;
  (p->s).coord.y = (z->s).coord.y + r.y;
  (p->coord_b4).x = PIXEL(10);
  (p->coord_b4).y = PIXEL(80);
  if ((p->s).work[0] == 0) {
    (p->coord_b4).y -= PIXEL(getMaxHP1x(z) * 2);
  } else {
    (p->coord_b4).y -= PIXEL(getMaxHP1x(z));
  }
  (p->s).unk_coord.x = PIXEL(120) - (&gStageRun.vm.camera.viewport)->x + (p->s).coord.x;
  (p->s).unk_coord.y = PIXEL(80) - (&gStageRun.vm.camera.viewport)->y + (p->s).coord.y;
  p->unk_c1 = 32;
  SET_ELF_ROUTINE(p, ENTITY_UPDATE);
  Elf0_Update(p);
}

static void FUN_080e1ef8(struct CyberElf0* p);
static void FUN_080e1fb8(struct Entity* p);
static void FUN_080e1fe8(struct CyberElf0* p);

static void Elf0_Update(struct CyberElf0* p) {
  u8 idx;
  static const EntityFunc sUpdates[3] = {
      (void*)FUN_080e1ef8,
      (void*)FUN_080e1fb8,
      (void*)FUN_080e1fe8,
  };  // 0x08371c80

  UpdateSpriteAnimation(p);
  (sUpdates[(p->s).mode[1]])((void*)p);
  if ((p->s).mode[0] == ENTITY_UPDATE) {
    (p->s).coord.x = (p->s).unk_coord.x - PIXEL(120);
    (p->s).coord.x += (&gStageRun.vm.camera.viewport)->x;
    (p->s).coord.y = (p->s).unk_coord.y - PIXEL(80);
    (p->s).coord.y += (&gStageRun.vm.camera.viewport)->y;
    idx = p->unk_c0;
    (p->s).coord.y += SIN(idx << 3) << 2;
  }
}

static void Elf0_Die(struct Entity* p) {
  gPause = FALSE;
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

NAKED static void FUN_080e1ef8(struct CyberElf0* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r3, r4, #0\n\
	adds r3, #0xc0\n\
	ldrb r1, [r3]\n\
	adds r2, r1, #1\n\
	adds r0, r2, #0\n\
	asrs r0, r0, #5\n\
	lsls r0, r0, #5\n\
	subs r0, r2, r0\n\
	strb r0, [r3]\n\
	adds r6, r4, #0\n\
	adds r6, #0xb4\n\
	ldr r1, [r6]\n\
	ldr r0, [r4, #0x64]\n\
	subs r3, r1, r0\n\
	adds r5, r4, #0\n\
	adds r5, #0xb8\n\
	ldr r1, [r5]\n\
	ldr r0, [r4, #0x68]\n\
	subs r2, r1, r0\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	bhi _080E1F5C\n\
	movs r7, #0x80\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	cmp r0, r1\n\
	bhi _080E1F5C\n\
	adds r0, r3, #0\n\
	muls r0, r3, r0\n\
	adds r1, r2, #0\n\
	muls r1, r2, r1\n\
	adds r0, r0, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0xb\n\
	cmp r0, r1\n\
	bgt _080E1F5C\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	ldr r0, [r6]\n\
	str r0, [r4, #0x64]\n\
	ldr r0, [r5]\n\
	str r0, [r4, #0x68]\n\
	b _080E1FAE\n\
_080E1F5C:\n\
	adds r0, r3, #0\n\
	adds r1, r2, #0\n\
	bl CalcAngle\n\
	ldr r3, _080E1FB4 @ =gSineTable\n\
	adds r1, r0, #0\n\
	adds r1, #0x40\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r3\n\
	movs r5, #0\n\
	ldrsh r2, [r1, r5]\n\
	lsls r2, r2, #1\n\
	ldr r1, [r4, #0x64]\n\
	adds r1, r1, r2\n\
	str r1, [r4, #0x64]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r7, #0\n\
	ldrsh r1, [r0, r7]\n\
	lsls r1, r1, #1\n\
	ldr r0, [r4, #0x68]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x68]\n\
	adds r5, r4, #0\n\
	adds r5, #0xc1\n\
	ldrb r0, [r5]\n\
	subs r0, #1\n\
	strb r0, [r5]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E1FAE\n\
	adds r0, r4, #0\n\
	adds r0, #0x54\n\
	movs r1, #0\n\
	bl FUN_080bfc94\n\
	movs r0, #0x20\n\
	strb r0, [r5]\n\
_080E1FAE:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E1FB4: .4byte gSineTable\n\
 .syntax divided\n");
}

static void FUN_080e1fb8(struct Entity* p) {
  if (p->mode[2] == 0) {
    p->unk_2c = FUN_080bfce8(&p->coord, 0);
    p->mode[2]++;
  }
  if ((p->unk_2c)->mode[0] >= ENTITY_DIE) p->mode[1]++;
}

NAKED static void FUN_080e1fe8(struct CyberElf0* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	adds r0, #0xbc\n\
	ldr r5, [r0]\n\
	ldrb r0, [r6, #0x10]\n\
	cmp r0, #0\n\
	bne _080E2012\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #4]\n\
	adds r1, #3\n\
	strh r1, [r0, #4]\n\
	adds r0, r5, #0\n\
	bl IsDoubleHP\n\
	lsls r0, r0, #0x18\n\
	movs r3, #4\n\
	cmp r0, #0\n\
	beq _080E2026\n\
	movs r3, #8\n\
	b _080E2026\n\
_080E2012:\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	ldrh r1, [r0, #4]\n\
	adds r1, #5\n\
	strh r1, [r0, #4]\n\
	adds r0, r5, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
_080E2026:\n\
	ldr r0, _080E2094 @ =gScore\n\
	ldr r0, [r0]\n\
	adds r1, r0, #0\n\
	adds r1, #0x4c\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x62\n\
	bhi _080E2038\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_080E2038:\n\
	ldr r1, _080E2098 @ =gElfAvailability\n\
	ldr r2, _080E209C @ =0x00000121\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	ldr r1, [r1]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	movs r2, #2\n\
	orrs r0, r2\n\
	strb r0, [r1]\n\
	adds r4, r5, #0\n\
	adds r4, #0xa4\n\
	ldrh r0, [r4]\n\
	adds r0, r0, r3\n\
	strh r0, [r4]\n\
	adds r0, r5, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	movs r2, #0\n\
	ldrsh r1, [r4, r2]\n\
	cmp r0, r1\n\
	bge _080E2074\n\
	adds r0, r5, #0\n\
	bl GetMaxHP\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	strh r0, [r4]\n\
_080E2074:\n\
	ldr r1, _080E20A0 @ =gElfFnTable\n\
	ldrb r0, [r6, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r6, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r6, #0x14]\n\
	adds r0, r6, #0\n\
	bl Elf0_Die\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E2094: .4byte gScore\n\
_080E2098: .4byte gElfAvailability\n\
_080E209C: .4byte 0x00000121\n\
_080E20A0: .4byte gElfFnTable\n\
 .syntax divided\n");
}
