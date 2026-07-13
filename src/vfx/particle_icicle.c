#include "global.h"
#include "vfx.h"

// グラチャー・レ・カクタンク戦でのつらら が砕ける時のパーティクル

static void VFX54_Init(struct Entity* p);
static void VFX54_Update(struct Entity* p);
static void VFX54_Die(struct Entity* p);

// clang-format off
const VFXRoutine gIcicleParticleRoutine = {
    [ENTITY_INIT] =      (VFXFunc)VFX54_Init,
    [ENTITY_UPDATE] =    (VFXFunc)VFX54_Update,
    [ENTITY_DIE] =       (VFXFunc)VFX54_Die,
    [ENTITY_DISAPPEAR] = (VFXFunc)DeleteVFX,
    [ENTITY_EXIT] =      (VFXFunc)DeleteEntity,
};
// clang-format on

// 0x080c0f2c
void CreateIcicleParticle(s32 x, s32 y, s32 dy) {
  struct Entity* p = AllocEntityLast(gVFXHeaderPtr);
  if (p != NULL) {
    INIT_VFX_ROUTINE(p, VFX_ICICLE_PARTICLE);
    p->work[0] = 0;
    p->coord.x = x, p->coord.y = y;
    p->d.y = dy;
  }
}

// --------------------------------------------

static const u8 sInitModes[];

static void VFX54_Init(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_UPDATE);
  p->mode[1] = sInitModes[p->work[0]];
  p->flags |= FLIPABLE;
  p->flags |= DISPLAY;
  EnableSpriteAnimation_Normal(p);
  VFX54_Update((void*)p);
}

// --------------------------------------------

static void FUN_080c0ff4(struct Entity* p);

static void VFX54_Update(struct Entity* p) {
  static const EntityFunc sUpdates[1] = {
      FUN_080c0ff4,
  };
  (sUpdates[p->mode[1]])((void*)p);
}

// --------------------------------------------

static void VFX54_Die(struct Entity* p) {
  SET_VFX_ROUTINE(p, ENTITY_EXIT);
  return;
}

// --------------------------------------------

static const motion_t sMotions[];

NAKED static void FUN_080c0ff4(struct Entity* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r7, r0, #0\n\
	ldrb r6, [r7, #0xe]\n\
	cmp r6, #0\n\
	beq _080C1004\n\
	cmp r6, #1\n\
	beq _080C1062\n\
	b _080C10F8\n\
_080C1004:\n\
	ldr r0, _080C1078 @ =RNG_0202f388\n\
	mov ip, r0\n\
	ldr r0, [r0]\n\
	ldr r3, _080C107C @ =0x000343FD\n\
	muls r0, r3, r0\n\
	ldr r2, _080C1080 @ =0x00269EC3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	lsls r0, r0, #6\n\
	lsrs r0, r0, #0x17\n\
	ldr r4, _080C1084 @ =0xFFFFFF00\n\
	adds r0, r0, r4\n\
	str r0, [r7, #0x5c]\n\
	adds r0, r1, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r4, r0, #1\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	ldr r1, [r7, #0x60]\n\
	adds r1, r1, r0\n\
	str r1, [r7, #0x60]\n\
	ldr r5, _080C1088 @ =sMotions\n\
	adds r0, r4, #0\n\
	muls r0, r3, r0\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	mov r2, ip\n\
	str r1, [r2]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #3\n\
	bl __umodsi3\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrh r1, [r0]\n\
	adds r0, r7, #0\n\
	bl SetMotion\n\
	strb r6, [r7, #0x12]\n\
	ldrb r0, [r7, #0xe]\n\
	adds r0, #1\n\
	strb r0, [r7, #0xe]\n\
_080C1062:\n\
	ldrb r0, [r7, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r7, #0x12]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080C108C\n\
	ldrb r0, [r7, #0xa]\n\
	orrs r0, r1\n\
	b _080C1092\n\
	.align 2, 0\n\
_080C1078: .4byte RNG_0202f388\n\
_080C107C: .4byte 0x000343FD\n\
_080C1080: .4byte 0x00269EC3\n\
_080C1084: .4byte 0xFFFFFF00\n\
_080C1088: .4byte sMotions\n\
_080C108C:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080C1092:\n\
	strb r0, [r7, #0xa]\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x5c]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x54]\n\
	ldr r0, [r7, #0x60]\n\
	adds r0, #0x40\n\
	str r0, [r7, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080C10AC\n\
	str r1, [r7, #0x60]\n\
_080C10AC:\n\
	ldr r0, [r7, #0x58]\n\
	ldr r1, [r7, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r7, #0x58]\n\
	adds r0, r7, #0\n\
	bl UpdateEntityAnim\n\
	ldr r0, [r7, #0x54]\n\
	ldr r1, [r7, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080C10DA\n\
	ldr r0, _080C1100 @ =gStageRun+232\n\
	adds r1, r7, #0\n\
	adds r1, #0x54\n\
	bl Camera_GetDistance\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	cmp r0, r1\n\
	bls _080C10F8\n\
_080C10DA:\n\
	ldrb r1, [r7, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r7, #0xa]\n\
	ldr r1, _080C1104 @ =gVFXFnTable\n\
	ldrb r0, [r7, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r7, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r7, #0x14]\n\
_080C10F8:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080C1100: .4byte gStageRun+232\n\
_080C1104: .4byte gVFXFnTable\n\
 .syntax divided\n");
}

// --------------------------------------------

// 0x0836f1e4
static const u8 sInitModes[2] = {0, 0};

// 0x0836F1E6
static const motion_t sMotions[3] = {
    MOTION(SM090_ICICLE, 0x08),
    MOTION(SM090_ICICLE, 0x09),
    MOTION(SM090_ICICLE, 0x0A),
};
