#include "entity.h"
#include "vfx.h"
#include "global.h"

struct Ghost18 {
  struct Entity s;
  struct Coord c;
  bool8 xflip;
  u8 unk_7d;
  u16 unk_7e;
  u8 work[4];
};

static void Ghost18_Init(struct VFX* p);
static void Ghost18_Update(struct VFX* p);
static void Ghost18_Die(struct VFX* p);

// clang-format off
const VFXRoutine gGhost18Routine = {
    [ENTITY_INIT] =      Ghost18_Init,
    [ENTITY_MAIN] =      Ghost18_Update,
    [ENTITY_DIE] =       Ghost18_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

void CreateGhost18(struct Coord* c, u8 kind, bool8 xflip, u8 r3) {
  struct Ghost18* g = (struct Ghost18*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_UNK_018);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).coord = *c;
    (g->s).work[0] = kind;
    (g->s).work[1] = 0;
    g->xflip = xflip;
    g->unk_7d = r3;
  }
}

NAKED static void Ghost18_Init(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	bl InitRotatableMotion\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #1\n\
	movs r4, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080B6C80 @ =0x00001305\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r5, #0\n\
	adds r0, #0x7c\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _080B6C84\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B6C8A\n\
	.align 2, 0\n\
_080B6C80: .4byte 0x00001305\n\
_080B6C84:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B6C8A:\n\
	strb r0, [r5, #0xa]\n\
	movs r3, #1\n\
	adds r1, r3, #0\n\
	ands r1, r2\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	movs r4, #0\n\
	strb r1, [r0]\n\
	movs r0, #0x4a\n\
	adds r0, r0, r5\n\
	mov ip, r0\n\
	lsls r1, r1, #4\n\
	ldrb r2, [r0]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x25\n\
	movs r0, #0x19\n\
	strb r0, [r1]\n\
	ldr r0, [r5, #0x54]\n\
	str r0, [r5, #0x74]\n\
	ldr r0, [r5, #0x58]\n\
	adds r0, #1\n\
	str r0, [r5, #0x78]\n\
	strb r4, [r5, #0x12]\n\
	strb r3, [r5, #0x13]\n\
	str r4, [r5, #0x60]\n\
	ldr r1, _080B6CE4 @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	str r3, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	adds r0, r5, #0\n\
	bl Ghost18_Update\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6CE4: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

NAKED static void Ghost18_Update(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, _080B6D18 @ =gCurStory\n\
	ldrb r1, [r0, #8]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B6D20\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080B6D1C @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080B6E48\n\
	.align 2, 0\n\
_080B6D18: .4byte gCurStory\n\
_080B6D1C: .4byte gVFXFnTable\n\
_080B6D20:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	ldrb r0, [r4, #0xd]\n\
	cmp r0, #0\n\
	beq _080B6D32\n\
	cmp r0, #1\n\
	beq _080B6D48\n\
	b _080B6D80\n\
_080B6D32:\n\
	ldr r0, [r4, #0x74]\n\
	ldr r1, [r4, #0x78]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080B6D80\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080B6D80\n\
_080B6D48:\n\
	ldr r0, [r4, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	ldr r1, [r4, #0x58]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x58]\n\
	ldr r0, [r4, #0x54]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B6E48\n\
	ldr r1, _080B6D7C @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Ghost18_Die\n\
	b _080B6E48\n\
	.align 2, 0\n\
_080B6D7C: .4byte gVFXFnTable\n\
_080B6D80:\n\
	ldrb r5, [r4, #0x12]\n\
	lsrs r1, r5, #5\n\
	ldrb r0, [r4, #0x13]\n\
	adds r1, r1, r0\n\
	strb r1, [r4, #0x13]\n\
	adds r1, r5, r1\n\
	lsls r1, r1, #0x18\n\
	ldr r3, _080B6DF0 @ =gSineTable\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x17\n\
	adds r0, r1, r2\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r6, #0\n\
	ldrsh r2, [r0, r6]\n\
	adds r0, r5, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r3\n\
	movs r6, #0\n\
	ldrsh r0, [r0, r6]\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #0x13\n\
	lsrs r2, r2, #0x10\n\
	adds r6, r2, #0\n\
	lsrs r1, r1, #0x17\n\
	adds r1, r1, r3\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	ldrb r0, [r4, #0x12]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #3\n\
	ldr r0, [r4, #0x58]\n\
	subs r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	adds r3, r4, #0\n\
	adds r3, #0x7c\n\
	adds r1, r4, #0\n\
	adds r1, #0x7d\n\
	ldrb r0, [r3]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bne _080B6DFE\n\
	adds r0, r4, #0\n\
	adds r0, #0x24\n\
	strb r5, [r0]\n\
	ldrb r0, [r3]\n\
	cmp r0, #0\n\
	beq _080B6DF4\n\
	lsls r1, r2, #0x10\n\
	b _080B6E18\n\
	.align 2, 0\n\
_080B6DF0: .4byte gSineTable\n\
_080B6DF4:\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	b _080B6E1E\n\
_080B6DFE:\n\
	mvns r0, r5\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	strb r0, [r1]\n\
	ldrb r0, [r3]\n\
	cmp r0, #0\n\
	beq _080B6E16\n\
	lsls r1, r2, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	b _080B6E1E\n\
_080B6E16:\n\
	lsls r1, r6, #0x10\n\
_080B6E18:\n\
	asrs r1, r1, #0x10\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r1\n\
_080B6E1E:\n\
	str r0, [r4, #0x54]\n\
	ldrb r0, [r4, #0x13]\n\
	ldrb r6, [r4, #0x12]\n\
	adds r0, r0, r6\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x40\n\
	bls _080B6E48\n\
	ldr r1, _080B6E50 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl Ghost18_Die\n\
_080B6E48:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6E50: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void Ghost18_Die(struct VFX* p) {
  CreateSmoke(1, &(p->s).coord);
  PlaySound(SE_ZAKO_EXPLODE);
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}
