#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static void Ghost27_Init(struct VFX *p);
static void Ghost27_Update(struct VFX *p);
static void Ghost27_Die(struct VFX *p);

// clang-format off
const VFXRoutine gGhost27Routine = {
    [ENTITY_INIT] =      Ghost27_Init,
    [ENTITY_MAIN] =      Ghost27_Update,
    [ENTITY_DIE] =       Ghost27_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

NAKED void CreateGhost27(struct Coord *c, u8 r1, u8 r2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r4, r1, #0x18\n\
	lsls r2, r2, #0x18\n\
	lsrs r6, r2, #0x18\n\
	ldr r0, _080B9AAC @ =gVFXHeaderPtr\n\
	ldr r0, [r0]\n\
	bl AllocEntityFirst\n\
	adds r3, r0, #0\n\
	cmp r3, #0\n\
	beq _080B9ADE\n\
	adds r1, r3, #0\n\
	adds r1, #0x25\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r1, _080B9AB0 @ =gVFXFnTable\n\
	movs r0, #0x1b\n\
	strb r0, [r3, #9]\n\
	ldr r0, [r1, #0x6c]\n\
	ldr r0, [r0]\n\
	str r0, [r3, #0x14]\n\
	movs r0, #0\n\
	strh r2, [r3, #0x20]\n\
	adds r1, r3, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	str r0, [r3, #0x54]\n\
	str r1, [r3, #0x58]\n\
	adds r2, r4, #0\n\
	cmp r2, #0\n\
	beq _080B9AB4\n\
	ldrb r0, [r3, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B9ABA\n\
	.align 2, 0\n\
_080B9AAC: .4byte gVFXHeaderPtr\n\
_080B9AB0: .4byte gVFXFnTable\n\
_080B9AB4:\n\
	ldrb r1, [r3, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B9ABA:\n\
	strb r0, [r3, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
	adds r0, r3, #0\n\
	adds r0, #0x4c\n\
	strb r1, [r0]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r3\n\
	mov ip, r0\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	strb r6, [r3, #0x10]\n\
_080B9ADE:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

// --------------------------------------------

void FUN_080b9b9c(struct VFX *p);
void FUN_080b9c08(struct VFX *p);

static void Ghost27_Init(struct VFX *p) {
  static const VFXFunc sInitializers[] = {
      FUN_080b9b9c,
      FUN_080b9c08,
  };
  (sInitializers[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080b9c50(struct VFX *p);
void FUN_080b9ca4(struct VFX *p);

static void Ghost27_Update(struct VFX *p) {
  static const VFXFunc sUpdates[] = {
      FUN_080b9c50,
      FUN_080b9ca4,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[0]])(p);
}

// --------------------------------------------

void FUN_080b9cf8(struct VFX *p);
void FUN_080b9db0(struct VFX *p);

static void Ghost27_Die(struct VFX *p) {
  static const VFXFunc sDeinitializers[] = {
      FUN_080b9cf8,
      FUN_080b9db0,
  };
  if (IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sDeinitializers[(p->s).work[0]])(p);
}

INCASM("asm/vfx/unk_27.inc");
