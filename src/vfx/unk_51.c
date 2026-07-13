#include "global.h"
#include "vfx.h"

static void VFX51_Init(struct Entity* p);
static void VFX51_Update(struct Entity* p);
static void VFX51_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX51Routine = {
    [ENTITY_INIT] =      (void*)VFX51_Init,
    [ENTITY_UPDATE] =    (void*)VFX51_Update,
    [ENTITY_DIE] =       (void*)VFX51_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

void CreateVFX51(struct Entity* e, s32 x, s32 y) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_051);
    p->coord.x = x, p->coord.y = y;
    p->unk_28 = (void*)e;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX51_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX51_Update((void*)p);
}

static void FUN_080c0b68(struct VFX* p);

static void VFX51_Update(struct Entity* p) {
  static const VFXFunc sUpdates[1] = {
      (void*)FUN_080c0b68,
  };
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX51_Die(struct Entity* p) { SET_VFX_ROUTINE(p, ENTITY_EXIT); }

// --------------------------------------------

NAKED static void FUN_080c0b68(struct VFX* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldrb r6, [r5, #0xe]\n\
	cmp r6, #0\n\
	beq _080C0B78\n\
	cmp r6, #1\n\
	beq _080C0BC6\n\
	b _080C0C54\n\
_080C0B78:\n\
	ldr r4, _080C0BDC @ =RNG_0202f388\n\
	ldr r0, [r4]\n\
	ldr r1, _080C0BE0 @ =0x000343FD\n\
	muls r0, r1, r0\n\
	ldr r2, _080C0BE4 @ =0x00269EC3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r3, r0, #1\n\
	lsls r0, r0, #5\n\
	lsrs r0, r0, #0x16\n\
	ldr r7, _080C0BE8 @ =0xFFFFFE00\n\
	adds r0, r0, r7\n\
	str r0, [r5, #0x5c]\n\
	adds r0, r3, #0\n\
	muls r0, r1, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r3, r0, #1\n\
	lsls r0, r0, #6\n\
	lsrs r0, r0, #0x17\n\
	rsbs r0, r0, #0\n\
	str r0, [r5, #0x60]\n\
	muls r1, r3, r1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #1\n\
	lsrs r0, r1, #1\n\
	str r0, [r4]\n\
	lsrs r1, r1, #0x11\n\
	movs r0, #1\n\
	ands r1, r0\n\
	ldr r0, _080C0BEC @ =0x0000540B\n\
	adds r1, r1, r0\n\
	adds r0, r5, #0\n\
	bl SetMotion\n\
	strb r6, [r5, #0x12]\n\
	ldrb r0, [r5, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xe]\n\
_080C0BC6:\n\
	ldrb r0, [r5, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C0BF0\n\
	ldrb r0, [r5, #0xa]\n\
	orrs r0, r1\n\
	b _080C0BF6\n\
	.align 2, 0\n\
_080C0BDC: .4byte RNG_0202f388\n\
_080C0BE0: .4byte 0x000343FD\n\
_080C0BE4: .4byte 0x00269EC3\n\
_080C0BE8: .4byte 0xFFFFFE00\n\
_080C0BEC: .4byte 0x0000540B\n\
_080C0BF0:\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080C0BF6:\n\
	strb r0, [r5, #0xa]\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldr r0, [r5, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r5, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C0C10\n\
	str r1, [r5, #0x60]\n\
_080C0C10:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	bl UpdateEntityAnim\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080C0C54\n\
	adds r1, r5, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
	bl CreateSmoke\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080C0C5C @ =gVFXFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
_080C0C54:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C0C5C: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

static const u8 sInitModes[4] = {0, 0, 0, 0};
