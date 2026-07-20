#include "global.h"
#include "story.h"
#include "vfx.h"
#include "vfx/unk_common.h"

static void VFX63_Init(struct Entity* p);
static void VFX63_Update(struct Entity* p);
static void VFX63_Die(struct Entity* p);

// clang-format off
const VFXRoutine gVFX63Routine = {
    [ENTITY_INIT] =      (void*)VFX63_Init,
    [ENTITY_UPDATE] =    (void*)VFX63_Update,
    [ENTITY_DIE] =       (void*)VFX63_Die,
    [ENTITY_DISAPPEAR] = (void*)DeleteVFX,
    [ENTITY_EXIT] =      (void*)DeleteEntity,
};
// clang-format on

struct Entity* CreateVFX63(Coords32* c, u8 kind, motion_t m, u32 val) {
  VFXUnkCommon* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_UNK_063);
    p->work[0] = kind, p->work[1] = 0;
    p->coord.x = c->x, p->coord.y = c->y;
    p->m_74 = m;
    p->unk_78 = val;
  }
  return (void*)p;
}

// --------------------------------------------

static void VFX63_Init(struct Entity* p) {
  EnableSpriteAnimation_Normal(p);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  if (p->work[0] == 0) {
    SET_XFLIP(p, FALSE);
  } else {
    SET_XFLIP(p, TRUE);
  }
  if (p->work[0] == 0) {
    (p->d).x = -PIXEL(3) / 4;
  } else {
    (p->d).x = PIXEL(3) / 4;
  }
  (p->d).y = 0;

  if (p->work[1] == 0) {
    p->work[2] = 127 + (RANDOM(RNG_0202f388) & 7);
    SET_VFX_ROUTINE(p, ENTITY_UPDATE);
    p->mode[1] = 0, p->mode[2] = 0, p->mode[3] = 0;
  }
  VFX63_Update(p);
}

static void _VFX63_Update(VFXUnkCommon* p);

static void VFX63_Update(struct Entity* p) {
  static const VFXFunc sUpdates[1] = {
      (void*)_VFX63_Update,
  };

  if (IS_METTAUR) {
    SET_VFX_ROUTINE(p, ENTITY_DIE);
    VFX63_Die(p);
    return;
  }
  (sUpdates[(p->mode)[1]])((void*)p);
}

static void VFX63_Die(struct Entity* p) {
  p->flags &= ~DISPLAY;
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
}

// --------------------------------------------

/**
 * @note 0x080c3864
 */
NAKED static void _VFX63_Update(VFXUnkCommon* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r7, r0, #0\n\
	ldrb r0, [r7, #0x12]\n\
	subs r0, #1\n\
	strb r0, [r7, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080C3882\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #2\n\
	b _080C38A8\n\
_080C3882:\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	beq _080C38C4\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080C38C4\n\
	ldr r0, [r7, #0x60]\n\
	cmp r0, #0\n\
	ble _080C38C4\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	movs r0, #3\n\
_080C38A8:\n\
	bl CreateSmoke\n\
	ldr r1, _080C38C0 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r7, #0x14]\n\
	b _080C3992\n\
	.align 2, 0\n\
_080C38C0: .4byte gVFXFnTable\n\
_080C38C4:\n\
	ldrb r0, [r7, #0xe]\n\
	mov sb, r0\n\
	cmp r0, #0\n\
	beq _080C38D2\n\
	cmp r0, #1\n\
	beq _080C393C\n\
	b _080C3992\n\
_080C38D2:\n\
	ldr r4, _080C3954 @ =PTR_s32_ARRAY_0836f538\n\
	movs r1, #0x74\n\
	adds r1, r1, r7\n\
	mov r8, r1\n\
	ldrh r0, [r1]\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0xe\n\
	adds r0, r0, r4\n\
	ldr r0, [r0]\n\
	ldr r2, [r7, #0x78]\n\
	lsls r2, r2, #3\n\
	adds r2, r2, r0\n\
	ldr r3, _080C3958 @ =RNG_0202f388\n\
	ldr r0, [r3]\n\
	ldr r6, _080C395C @ =0x000343FD\n\
	adds r1, r0, #0\n\
	muls r1, r6, r1\n\
	ldr r5, _080C3960 @ =0x00269EC3\n\
	adds r1, r1, r5\n\
	lsls r1, r1, #1\n\
	lsrs r4, r1, #1\n\
	str r4, [r3]\n\
	lsrs r1, r1, #0x11\n\
	movs r0, #0x1f\n\
	ands r1, r0\n\
	ldr r0, [r2, #4]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x60]\n\
	adds r1, r4, #0\n\
	muls r1, r6, r1\n\
	adds r1, r1, r5\n\
	lsls r1, r1, #1\n\
	lsrs r0, r1, #1\n\
	str r0, [r3]\n\
	lsrs r1, r1, #0x11\n\
	movs r0, #0x3f\n\
	ands r1, r0\n\
	ldr r0, [r2]\n\
	subs r0, r0, r1\n\
	str r0, [r7, #0x5c]\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	mov r1, sb\n\
	strb r1, [r7, #0x13]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080C393C:\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x13]\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C3964\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080C396A\n\
	.align 2, 0\n\
_080C3954: .4byte PTR_s32_ARRAY_0836f538\n\
_080C3958: .4byte RNG_0202f388\n\
_080C395C: .4byte 0x000343FD\n\
_080C3960: .4byte 0x00269EC3\n\
_080C3964:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080C396A:\n\
	strb r0, [r7, #0xa]\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x20\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C397C\n\
	str r1, [r7, #0x60]\n\
_080C397C:\n\
	ldr r0, [r7, #0x58]\n\
	ldr r1, [r7, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x58]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	adds r0, r7, #0\n\
	bl UpdateEntityAnim\n\
_080C3992:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
 .syntax divided\n");
}

// --------------------------------------------

static const s32 s32_ARRAY_0836f4d8[8 * 3] = {
    0x00000120, -0x00000260, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, -0x000000B0, -0x000001A0, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x00000260, 0x00000120, -0x000001A0, 0x00000120, -0x00000260, -0x000000B0, -0x000001A0,
};

// 0x0836f538
static const s32* const PTR_s32_ARRAY_0836f538[3] = {
    &s32_ARRAY_0836f4d8[0],
    &s32_ARRAY_0836f4d8[8],
    &s32_ARRAY_0836f4d8[16],
};
