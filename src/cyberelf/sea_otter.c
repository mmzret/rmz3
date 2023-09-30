#include "cyberelf.h"
#include "global.h"

void SeaOtterElf_Init(struct Elf* p);
void SeaOtterElf_Update(struct Elf* p);
void SeaOtterElf_Die(struct Elf* p);

// clang-format off
const ElfRoutine gSeaOtterElfRoutine = {
    [ENTITY_INIT] =      SeaOtterElf_Init,
    [ENTITY_MAIN] =      SeaOtterElf_Update,
    [ENTITY_DIE] =       SeaOtterElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

NAKED void MenuExit_SeaOtterElf(struct Elf* e) {
  asm(".syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r0, [r0]\n\
	ldrb r2, [r3, #0x12]\n\
	cmp r2, #0\n\
	bne _080E455E\n\
	adds r1, r0, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r3, #0x13]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _080E45AE\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	b _080E4572\n\
_080E455E:\n\
	adds r1, r0, #0\n\
	adds r1, #0xb4\n\
	ldrb r0, [r3, #0x13]\n\
	ldrb r1, [r1, #1]\n\
	cmp r0, r1\n\
	beq _080E45AE\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
_080E4572:\n\
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
	ldr r1, _080E45B4 @ =gElfFnTable\n\
	ldrb r0, [r3, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r3, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r3, #0x14]\n\
	ldr r2, [r3, #0x2c]\n\
	cmp r2, #0\n\
	beq _080E45AE\n\
	ldrb r1, [r2, #0xb]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	strb r0, [r2, #0xb]\n\
_080E45AE:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E45B4: .4byte gElfFnTable\n\
 .syntax divided\n");
}

INCASM("asm/cyberelf/sea_otter.inc");

void FUN_080e4a3c(struct Elf* p);
void FUN_080e4a88(struct Elf* p);
void FUN_080e4ae8(struct Elf* p);
void FUN_080e4b58(struct Elf* p);

static const ElfFunc sUpdates[4] = {
    FUN_080e4a3c,
    FUN_080e4a88,
    FUN_080e4ae8,
    FUN_080e4b58,
};
