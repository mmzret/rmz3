#include "cyberelf.h"
#include "global.h"
#include "zero.h"
#include "zero.h"

typedef struct {
  COLLISION_OBJECT_HDR;  // 0x00
  // props (16bytes, offset: 0xB4..)
  struct Zero* player;  // 0xB4
  u8 unk_b8[12];        // 0xB8
} CyberElfBird;
static_assert(sizeof(CyberElfBird) == sizeof(CyberElf));

static const ElfFunc sUpdates[2];

void BirdElf_Init(CyberElf* p);
void BirdElf_Update(CyberElf* p);
void BirdElf_Die(CyberElf* p);

// clang-format off
const ElfRoutine gBirdElfRoutine = {
    [ENTITY_INIT] =      (void*)BirdElf_Init,
    [ENTITY_UPDATE] =    (void*)BirdElf_Update,
    [ENTITY_DIE] =       (void*)BirdElf_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteElf,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

NAKED void FUN_080e58bc(CyberElf* p) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	ldrb r2, [r3, #0x12]\n\
	cmp r2, #0\n\
	bne _080E58DE\n\
	adds r1, r0, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r3, #0x13]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _080E5920\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	b _080E58F2\n\
_080E58DE:\n\
	adds r1, r0, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r3, #0x13]\n\
	ldrb r1, [r1, #1]\n\
	cmp r0, r1\n\
	beq _080E5920\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
_080E58F2:\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	adds r0, r3, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r3, #0xa]\n\
	ldr r1, _080E5924 @ =gElfFnTable\n\
	ldrb r0, [r3, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r3, #0x14]\n\
_080E5920:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E5924: .4byte gElfFnTable\n\
 .syntax divided\n");
}

void FUN_080e5b74(CyberElf* p);
void FUN_080e5d68(CyberElf* p);

static const ElfFunc sUpdates[2] = {
    (void*)FUN_080e5b74,
    (void*)FUN_080e5d68,
};

void FUN_080bfce8(struct Coord* c, s32 r1);

CyberElf* CreateBirdElf(struct Zero* z, u8 breed, u8 availability, u8 satelite_slot) {
  CyberElfBird* p = (CyberElfBird*)AllocEntityLast(gElfHeaderPtr);
  if (p != NULL) {
    p->renderPrio = 16;
    INIT_ELF_ROUTINE(p, 12);
    p->tileNum = 0, p->palID = 0;
    p->player = z;
    p->work[0] = breed, p->work[1] = availability, p->work[2] = satelite_slot;
    if (satelite_slot == 0) {
      p->work[3] = SATELITE_1;
    } else {
      p->work[3] = SATELITE_2;
    }
  }
  return (CyberElf*)p;
}

INCASM("asm/cyberelf/bird_a_a.inc");

void BirdElf_Die(CyberElf* p) {
  FUN_080bfce8(&p->coord, 0);
  p->flags &= ~DISPLAY;
  SET_ELF_ROUTINE(p, ENTITY_EXIT);
}

INCASM("asm/cyberelf/bird_b.inc");
