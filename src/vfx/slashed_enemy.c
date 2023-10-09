#include "entity.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

struct Ghost16 {
  struct Entity s;
  u16 unk_74[2];
  bool8 unk_78[2];
  u16 unk_7a;
  const struct SlashedEnemy* data;
  u8 work[4];
};

static void SlashedEnemy_Init(struct Ghost16* p);
static void SlashedEnemy_Update(struct Ghost16* p);
static void SlashedEnemy_Die(struct Ghost16* p);

// clang-format off
const VFXRoutine gSlashedEnemyRoutine = {
    [ENTITY_INIT] =      (VFXFunc)SlashedEnemy_Init,
    [ENTITY_UPDATE] =    (VFXFunc)SlashedEnemy_Update,
    [ENTITY_DIE] =       (VFXFunc)SlashedEnemy_Die,
    [ENTITY_DISAPPEAR] = DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

struct VFX* CreateSlashedEnemy(struct Coord* c, const struct SlashedEnemy* data, u8 r2, u8 r3) {
  struct Ghost16* g = (struct Ghost16*)AllocEntityFirst(gVFXHeaderPtr);
  if (g != NULL) {
    s32 y;
    (g->s).taskCol = 1;
    INIT_VFX_ROUTINE(g, VFX_SLASHED_ENEMY);
    (g->s).tileNum = 0;
    (g->s).palID = 0;
    (g->s).coord = *c;
    (g->s).work[0] = r2;
    (g->s).work[1] = 0;
    g->unk_78[0] = (r3 >> 4) & 1;
    g->unk_78[1] = r3 & 1;
    g->data = data;
  }
  return (struct VFX*)g;
}

NAKED static void SlashedEnemy_Init(struct Ghost16* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x7c]\n\
	bl InitNonAffineMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrh r1, [r5]\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _080B6544\n\
	ldrb r0, [r4, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	b _080B654A\n\
_080B6544:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
_080B654A:\n\
	strb r0, [r4, #0xa]\n\
	movs r1, #1\n\
	ands r1, r2\n\
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
	adds r0, r4, #0\n\
	adds r0, #0x78\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080B657C\n\
	movs r0, #4\n\
	ldrsh r1, [r5, r0]\n\
	ldr r0, [r4, #0x54]\n\
	subs r0, r0, r1\n\
	b _080B6584\n\
_080B657C:\n\
	movs r3, #4\n\
	ldrsh r1, [r5, r3]\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r1\n\
_080B6584:\n\
	str r0, [r4, #0x54]\n\
	adds r0, r4, #0\n\
	adds r0, #0x79\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080B65C8\n\
	movs r6, #8\n\
	ldrsh r2, [r5, r6]\n\
	rsbs r2, r2, #0\n\
	ldr r3, _080B65BC @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _080B65C0 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B65C4 @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	movs r6, #0xc\n\
	ldrsh r1, [r5, r6]\n\
	ands r0, r1\n\
	subs r2, r2, r0\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0x10\n\
	ldrsh r0, [r5, r1]\n\
	rsbs r0, r0, #0\n\
	b _080B65EE\n\
	.align 2, 0\n\
_080B65BC: .4byte RNG_0202f388\n\
_080B65C0: .4byte 0x000343FD\n\
_080B65C4: .4byte 0x00269EC3\n\
_080B65C8:\n\
	movs r3, #8\n\
	ldrsh r2, [r5, r3]\n\
	ldr r3, _080B6654 @ =RNG_0202f388\n\
	ldr r1, [r3]\n\
	ldr r0, _080B6658 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r6, _080B665C @ =0x00269EC3\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	movs r6, #0xc\n\
	ldrsh r1, [r5, r6]\n\
	ands r0, r1\n\
	adds r2, r2, r0\n\
	str r2, [r4, #0x5c]\n\
	movs r1, #0x10\n\
	ldrsh r0, [r5, r1]\n\
_080B65EE:\n\
	str r0, [r4, #0x64]\n\
	movs r6, #6\n\
	ldrsh r1, [r5, r6]\n\
	ldr r0, [r4, #0x58]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	movs r0, #0xa\n\
	ldrsh r2, [r5, r0]\n\
	ldr r1, [r3]\n\
	ldr r0, _080B6658 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r1, _080B665C @ =0x00269EC3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r3]\n\
	lsrs r0, r0, #0x11\n\
	movs r3, #0xe\n\
	ldrsh r1, [r5, r3]\n\
	ands r0, r1\n\
	adds r2, r2, r0\n\
	str r2, [r4, #0x60]\n\
	movs r6, #0x12\n\
	ldrsh r0, [r5, r6]\n\
	str r0, [r4, #0x68]\n\
	ldrh r1, [r5, #0x14]\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	strh r1, [r0]\n\
	ldrh r0, [r5, #0x16]\n\
	adds r1, r4, #0\n\
	adds r1, #0x76\n\
	strh r0, [r1]\n\
	ldrb r0, [r5, #2]\n\
	strb r0, [r4, #0x12]\n\
	ldr r1, _080B6660 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl SlashedEnemy_Update\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6654: .4byte RNG_0202f388\n\
_080B6658: .4byte 0x000343FD\n\
_080B665C: .4byte 0x00269EC3\n\
_080B6660: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080b6744(struct Ghost16* p);
static void FUN_080b6834(struct Ghost16* _);

static void SlashedEnemy_Update(struct Ghost16* p) {
  static VFXFunc const sUpdates[] = {
      (VFXFunc)FUN_080b6744,
      (VFXFunc)FUN_080b6834,
  };
  if (((p->data->unk_02[1] & 0x40) == 0) && IS_METTAUR) {
    (p->s).flags &= ~DISPLAY;
    (p->s).flags &= ~FLIPABLE;
    SET_VFX_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }
  (sUpdates[(p->s).work[1]])((struct VFX*)p);
}

static void SlashedEnemy_Die(struct Ghost16* p) {
  const struct SlashedEnemy* data = p->data;
  if (data->unk_02[1] & (1 << 0)) {
    CreateSmoke(3, &(p->s).coord);
  }
  if (data->unk_02[1] & (1 << 1)) {
    CreateSmoke(2, &(p->s).coord);
  }
  if (data->unk_02[1] & (1 << 2)) {
    CreateSmoke(1, &(p->s).coord);
    PlaySound(SE_ZAKO_EXPLODE);
  }
  if (data->unk_02[1] & (1 << 3)) {
    CreateSmoke(1, &(p->s).coord);
    PlaySound(SE_UNK_35);
  }
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

NAKED static void FUN_080b6744(struct Ghost16* p) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldr r5, [r4, #0x7c]\n\
	bl UpdateMotionGraphic\n\
	ldrb r1, [r5, #3]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B6772\n\
	ldrb r1, [r4, #0x12]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080B676A\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	b _080B6770\n\
_080B676A:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080B6770:\n\
	strb r0, [r4, #0xa]\n\
_080B6772:\n\
	ldr r1, [r4, #0x60]\n\
	ldr r0, [r4, #0x68]\n\
	adds r2, r1, r0\n\
	str r2, [r4, #0x60]\n\
	ldr r0, [r4, #0x58]\n\
	adds r3, r0, r2\n\
	str r3, [r4, #0x58]\n\
	ldrb r1, [r5, #3]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _080B67F6\n\
	adds r1, r3, #0\n\
	cmp r2, #0\n\
	ble _080B67A0\n\
	adds r0, r4, #0\n\
	adds r0, #0x76\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	adds r1, r1, r0\n\
	b _080B67AA\n\
_080B67A0:\n\
	adds r0, r4, #0\n\
	adds r0, #0x76\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	subs r1, r3, r0\n\
_080B67AA:\n\
	ldr r0, [r4, #0x54]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B67B8\n\
	strb r5, [r4, #0x12]\n\
_080B67B8:\n\
	ldr r0, [r4, #0x5c]\n\
	ldr r1, [r4, #0x64]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	ldr r1, [r4, #0x54]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	adds r2, r1, #0\n\
	cmp r0, #0\n\
	ble _080B67D8\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	movs r1, #0\n\
	ldrsh r0, [r0, r1]\n\
	adds r2, r2, r0\n\
	b _080B67E2\n\
_080B67D8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x74\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	subs r2, r1, r0\n\
_080B67E2:\n\
	ldr r1, [r4, #0x58]\n\
	adds r0, r2, #0\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080B6804\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	b _080B6804\n\
_080B67F6:\n\
	ldr r0, [r4, #0x5c]\n\
	ldr r1, [r4, #0x64]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x5c]\n\
	ldr r1, [r4, #0x54]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
_080B6804:\n\
	ldrb r0, [r4, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r4, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080B682A\n\
	ldr r1, _080B6830 @ =gVFXFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl SlashedEnemy_Die\n\
_080B682A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080B6830: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

static void FUN_080b6834(struct Ghost16* _ UNUSED) { return; }
