#include "cyberelf.h"
#include "global.h"

static const ElfFunc sUpdates[2];

void BirdElf_Init(struct Elf* p);
void BirdElf_Update(struct Elf* p);
void BirdElf_Die(struct Elf* p);

// clang-format off
const ElfRoutine gBirdElfRoutine = {
    [ENTITY_INIT] =      BirdElf_Init,
    [ENTITY_UPDATE] =    BirdElf_Update,
    [ENTITY_DIE] =       BirdElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

NAKED void FUN_080e58bc(struct Elf* p) {
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

void FUN_080e5b74(struct Elf* p);
void FUN_080e5d68(struct Elf* p);

static const ElfFunc sUpdates[2] = {
    FUN_080e5b74,
    FUN_080e5d68,
};

INCASM("asm/cyberelf/bird.inc");
