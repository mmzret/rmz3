#include "collision.h"
#include "global.h"
#include "overworld.h"
#include "solid.h"

// PantheonBase's snowboard

static void Solid18_Init(struct Solid* p);
void Solid18_Update(struct Solid* p);
void Solid18_Die(struct Solid* p);

// clang-format off
const SolidRoutine gSnowboardRoutine = {
    [ENTITY_INIT] =      Solid18_Init,
    [ENTITY_UPDATE] =    Solid18_Update,
    [ENTITY_DIE] =       Solid18_Die,
    [ENTITY_DISAPPEAR] = DeleteSolid,
    [ENTITY_EXIT] =      (SolidFunc)DeleteEntity,
};
// clang-format on

NAKED bool8 FUN_080cf428(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #5\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #6\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF4AE\n\
	ldr r1, [r5, #0x58]\n\
	movs r0, #0xc8\n\
	lsls r0, r0, #6\n\
	adds r1, r1, r0\n\
	adds r6, r0, #0\n\
	b _080CF4BC\n\
_080CF4AE:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	ldr r0, [r5, #0x58]\n\
	subs r6, r1, r0\n\
_080CF4BC:\n\
	ldr r0, _080CF4F4 @ =0x00001FFF\n\
	cmp r6, r0\n\
	bgt _080CF4FC\n\
	movs r0, #0\n\
	str r0, [r5, #0x60]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	subs r0, r0, r6\n\
	cmp r0, #0\n\
	bge _080CF4D2\n\
	adds r0, #0xf\n\
_080CF4D2:\n\
	asrs r1, r0, #4\n\
	ldr r0, _080CF4F8 @ =0xFFFFF800\n\
	cmp r1, r0\n\
	blt _080CF4DE\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
_080CF4DE:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	subs r0, r0, r6\n\
	cmp r0, #0\n\
	bge _080CF4EA\n\
	adds r0, #0xf\n\
_080CF4EA:\n\
	asrs r1, r0, #4\n\
	ldr r0, [r5, #0x58]\n\
	subs r0, r0, r1\n\
	b _080CF52A\n\
	.align 2, 0\n\
_080CF4F4: .4byte 0x00001FFF\n\
_080CF4F8: .4byte 0xFFFFF800\n\
_080CF4FC:\n\
	ldr r0, _080CF50C @ =0x000027FF\n\
	cmp r6, r0\n\
	bgt _080CF514\n\
	movs r0, #0\n\
	str r0, [r5, #0x60]\n\
	ldr r2, _080CF510 @ =0xFFFFE000\n\
	adds r0, r1, r2\n\
	b _080CF52A\n\
	.align 2, 0\n\
_080CF50C: .4byte 0x000027FF\n\
_080CF510: .4byte 0xFFFFE000\n\
_080CF514:\n\
	ldr r0, [r5, #0x60]\n\
	adds r0, #0x15\n\
	str r0, [r5, #0x60]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	cmp r0, r1\n\
	ble _080CF524\n\
	str r1, [r5, #0x60]\n\
_080CF524:\n\
	ldr r0, [r5, #0x58]\n\
	ldr r1, [r5, #0x60]\n\
	adds r0, r0, r1\n\
_080CF52A:\n\
	str r0, [r5, #0x58]\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r1, [r5, #0x54]\n\
	ldr r7, _080CF58C @ =0xFFFFE200\n\
	adds r2, r1, r7\n\
	ldr r0, [r5, #0x5c]\n\
	cmp r0, #0\n\
	ble _080CF542\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #5\n\
	adds r2, r1, r0\n\
_080CF542:\n\
	adds r4, r5, #0\n\
	adds r4, #0xb8\n\
	ldr r1, [r4]\n\
	adds r0, r2, #0\n\
	bl PushoutToUp1\n\
	adds r6, r0, #0\n\
	ldr r1, [r5, #0x54]\n\
	adds r2, r1, r7\n\
	ldr r0, [r5, #0x5c]\n\
	cmp r0, #0\n\
	ble _080CF560\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #5\n\
	adds r2, r1, r0\n\
_080CF560:\n\
	ldr r1, [r4]\n\
	adds r0, r2, #0\n\
	bl GetMetatileAttr\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080CF576\n\
	movs r2, #1\n\
	mov r8, r2\n\
_080CF576:\n\
	cmp r6, #0\n\
	beq _080CF59E\n\
	cmp r6, #0\n\
	bge _080CF594\n\
	ldr r0, _080CF590 @ =0xFFFFF600\n\
	cmp r6, r0\n\
	ble _080CF594\n\
	ldr r0, [r4]\n\
	adds r0, r0, r6\n\
	b _080CF628\n\
	.align 2, 0\n\
_080CF58C: .4byte 0xFFFFE200\n\
_080CF590: .4byte 0xFFFFF600\n\
_080CF594:\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	bne _080CF62A\n\
	movs r0, #1\n\
	b _080CF62C\n\
_080CF59E:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #4\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #5\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #6\n\
	adds r1, r1, r2\n\
	bl FUN_080098a4\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080CF614\n\
	ldr r0, [r5, #0x58]\n\
	b _080CF628\n\
_080CF614:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r4]\n\
	bl FUN_08009f6c\n\
	adds r1, r0, #0\n\
	ldr r0, [r5, #0x58]\n\
	cmp r1, r0\n\
	bge _080CF628\n\
	str r1, [r4]\n\
	b _080CF62A\n\
_080CF628:\n\
	str r0, [r4]\n\
_080CF62A:\n\
	movs r0, #0\n\
_080CF62C:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

static void onCollision(struct Body* body, struct Coord* r1 UNUSED, struct Coord* r2 UNUSED) { return; }

NAKED static void Solid18_Init(struct Solid* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldr r1, _080CF6C0 @ =gSolidFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r7, #1\n\
	str r7, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0x14]\n\
	ldr r1, _080CF6C4 @ =u8_ARRAY_083706c4\n\
	ldrb r0, [r5, #0x10]\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strb r0, [r5, #0xd]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	movs r1, #1\n\
	movs r6, #0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	bl InitNonAffineMotion\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r4, r5, #0\n\
	adds r4, #0x74\n\
	ldr r1, _080CF6C8 @ =sSolid18Collisions\n\
	adds r2, r5, #0\n\
	adds r2, #0x54\n\
	adds r0, r4, #0\n\
	movs r3, #0x18\n\
	bl InitBody\n\
	str r5, [r4, #0x2c]\n\
	ldr r0, _080CF6CC @ =onCollision\n\
	str r0, [r4, #0x24]\n\
	ldrb r2, [r5, #0x10]\n\
	cmp r2, #0\n\
	bne _080CF6D8\n\
	ldr r0, _080CF6D0 @ =gStageRun+232\n\
	ldr r0, [r0, #0x38]\n\
	ldr r1, _080CF6D4 @ =0x0000A7FF\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r2, [r0]\n\
	adds r2, r5, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _080CF702\n\
	.align 2, 0\n\
_080CF6C0: .4byte gSolidFnTable\n\
_080CF6C4: .4byte u8_ARRAY_083706c4\n\
_080CF6C8: .4byte sSolid18Collisions\n\
_080CF6CC: .4byte onCollision\n\
_080CF6D0: .4byte gStageRun+232\n\
_080CF6D4: .4byte 0x0000A7FF\n\
_080CF6D8:\n\
	ldr r0, _080CF73C @ =gStageRun+232\n\
	ldr r0, [r0, #0x38]\n\
	ldr r1, _080CF740 @ =0xFFFF5800\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	ldrb r0, [r5, #0xa]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x4c\n\
	strb r7, [r0]\n\
	adds r3, r5, #0\n\
	adds r3, #0x4a\n\
	movs r2, #0x10\n\
	ldrb r1, [r3]\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_080CF702:\n\
	ldr r0, [r5, #0x54]\n\
	ldr r1, [r5, #0x58]\n\
	bl FUN_08009f6c\n\
	ldr r1, _080CF744 @ =0xFFFFC000\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x58]\n\
	adds r0, r5, #0\n\
	adds r0, #0x74\n\
	ldr r1, _080CF748 @ =sSolid18Collisions\n\
	bl SetDDP\n\
	adds r0, r5, #0\n\
	adds r0, #0xb4\n\
	movs r4, #0\n\
	strh r4, [r0]\n\
	adds r0, r5, #0\n\
	bl FUN_0808a0ec\n\
	str r0, [r5, #0x2c]\n\
	adds r0, r5, #0\n\
	adds r0, #0xb6\n\
	strh r4, [r0]\n\
	adds r0, r5, #0\n\
	bl Solid18_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080CF73C: .4byte gStageRun+232\n\
_080CF740: .4byte 0xFFFF5800\n\
_080CF744: .4byte 0xFFFFC000\n\
_080CF748: .4byte sSolid18Collisions\n\
 .syntax divided\n");
}

INCASM("asm/solid/snowboard.inc");

// --------------------------------------------

void nop_080cf914(struct Solid* p);

// clang-format off
const SolidFunc sSolid18Updates1[5] = {
    nop_080cf914,
    nop_080cf914,
    nop_080cf914,
    nop_080cf914,
    nop_080cf914,
};
// clang-format on

// --------------------------------------------

void nop_080cf918(struct Solid* p);
void FUN_080cf91c(struct Solid* p);
void FUN_080cf9e0(struct Solid* p);
void FUN_080cfa80(struct Solid* p);
void FUN_080cfb38(struct Solid* p);

// clang-format off
const SolidFunc sSolid18Updates2[5] = {
    nop_080cf918,
    FUN_080cf91c,
    FUN_080cf9e0,
    FUN_080cfa80,
    FUN_080cfb38,
};
// clang-format on

// --------------------------------------------

const struct Collision sSolid18Collisions[2] = {
    [0] = {
      kind : DDP,
      faction : FACTION_ALLY,
      damage : 16,
      atkType : ATK_SABER,
      nature : BODY_NATURE_CUT,
      comboLv : 1,
      remaining : 0,
      layer : 0x00000020,
      range : {0x0000, 0x0700, 0x3E00, 0x1600},
    },
    [1] = {
      kind : DDP,
      faction : FACTION_ENEMY,
      special : 0,
      damage : 255,
      remaining : 0,
      layer : 0x00000001,
      range : {0x0000, -0x0100, 0x3A00, 0x0800},
    },
};

// --------------------------------------------

const u8 u8_ARRAY_083706c4[4] = {1, 1, 0, 0};
const struct Rect sSolid18Size = {0x0, 0x700, 0x3E00, 0x1000};

const motion_t sSolid18Motions[3] = {
    MOTION(SM109_PANTHEON_BASE, 14),
    MOTION(SM109_PANTHEON_BASE, 15),
    MOTION(SM109_PANTHEON_BASE, 15),
};
