#include "global.h"
#include "overworld.h"
#include "physics.h"
#include "pickup.h"

/*
  マップ上に存在するアイテムとしてのシークレットディスク
*/

static const struct Collision sCollision;

bool8 CreateSmallNumber(s32 x, s32 y, u8 value);

static metatile_attr_t FUN_080e1360(s32 x, s32 y);
static s32 FUN_080e1394(s32 x, s32 y);
static s32 FUN_080e13c4(s32 x, s32 y);

static void PickupDisk_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED);

static void MapDisk_Init(Pickup* p);
static void MapDisk_Update(Pickup* p);
static void MapDisk_Die(Pickup* p);

// clang-format off
const PickupRoutine gPickupDiskRoutine = {
    [ENTITY_INIT] =      (PickupFunc)MapDisk_Init,
    [ENTITY_UPDATE] =    (PickupFunc)MapDisk_Update,
    [ENTITY_DIE] =       (PickupFunc)MapDisk_Die,
    [ENTITY_DISAPPEAR] = (PickupFunc)DeletePickup,
    [ENTITY_EXIT] =      (PickupFunc)DeleteEntity,
};
// clang-format on

struct Entity* CreateMapDisk(u8 diskNo, Coords32* _c, u8 r2) {
  Coords32 c = {_c->x, _c->y};

  struct Entity* p = AllocEntityLast(gPickupHeaderPtr);
  if (p != NULL) {
    INIT_ITEM_ROUTINE(p, ITEM_DISK);
    if (p->work[1] >= 2) {
      (p->coord).x = c.x;
      (p->coord).y = FUN_080e1394(c.x, c.y);
    } else if (FUN_080e1360(c.x, c.y) != 0) {
      (p->coord).y = FUN_080e1394(c.x, c.y);
      if ((p->coord).y > c.y) {
        (p->coord).y = FUN_080e13c4(c.x, c.y);
      }
      (p->coord).x = c.x;
    } else {
      (p->coord).x = c.x;
      (p->coord).y = c.y;
    }
    p->work[0] = diskNo, p->work[1] = r2;
  }
  return p;
}

static void MapDisk_Init(Pickup* p) {
  motion_t m;
  u8* disks = gStageDiskManager.disk;
  const s32 diskID = p->work[0] - 1;
  if (IS_DISK_UNLOCKED(disks, diskID) & 1) {
    p->flags &= ~DISPLAY;
    p->flags &= ~FLIPABLE;
    EXIT_BODY(p);
    SET_ITEM_ROUTINE(p, ENTITY_DISAPPEAR);
    return;
  }

  InitNonAffineMotion((void*)p);
  m = MOTION(SM176_RESULT_DISK, 11) + (((u16)gSystemSavedata.disk) << 8);
  SetSpriteAnimation(p, m);
  p->flags |= DISPLAY;
  p->flags |= FLIPABLE;
  INIT_BODY(p, &sCollision, 64, PickupDisk_OnCollision);
  p->y = (p->coord).y;
  p->z = NULL;

  if (p->work[1] >= 2) {
    (p->d).y = PIXEL(0);
  } else {
    (p->d).y = -PIXEL(4);
  }
  *((u16*)&p->work[2]) = 360;
  SET_ITEM_ROUTINE(p, ENTITY_UPDATE);
  MapDisk_Update(p);
}

NAKED static void MapDisk_Update(Pickup* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	bl UpdateEntityAnim\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0\n\
	bne _080E1144\n\
	ldrh r0, [r4, #0x12]\n\
	subs r1, r0, #1\n\
	strh r1, [r4, #0x12]\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x3b\n\
	bhi _080E1144\n\
	movs r0, #2\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080E113C\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	b _080E1142\n\
_080E113C:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
_080E1142:\n\
	strb r0, [r4, #0xa]\n\
_080E1144:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r1, [r0]\n\
	movs r2, #4\n\
	ands r1, r2\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	beq _080E11A4\n\
	adds r0, #0x2c\n\
	ldr r0, [r0]\n\
	cmp r0, #0\n\
	beq _080E11A4\n\
	ldrb r0, [r4, #0x10]\n\
	subs r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl getDiskInStageRun\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xa]\n\
	str r1, [r5]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r1, [r0]\n\
	adds r0, #4\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E11A0 @ =gPickupFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl MapDisk_Die\n\
	b _080E12FC\n\
	.align 2, 0\n\
_080E11A0: .4byte gPickupFnTable\n\
_080E11A4:\n\
	ldrh r0, [r4, #0x12]\n\
	cmp r0, #0\n\
	beq _080E11BC\n\
	ldr r0, _080E11F4 @ =gStageRun+232\n\
	adds r1, r4, #0\n\
	adds r1, #0x54\n\
	bl Camera_GetDistance\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bls _080E11FC\n\
_080E11BC:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r2, #0\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	str r2, [r5]\n\
	adds r0, r4, #0\n\
	adds r0, #0x90\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldr r1, _080E11F8 @ =gPickupFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r4, #0x14]\n\
	b _080E12FC\n\
	.align 2, 0\n\
_080E11F4: .4byte gStageRun+232\n\
_080E11F8: .4byte gPickupFnTable\n\
_080E11FC:\n\
	ldrb r6, [r4, #0xd]\n\
	cmp r6, #0\n\
	bne _080E1280\n\
	adds r0, r4, #0\n\
	adds r0, #0xb4\n\
	ldr r2, [r4, #0x58]\n\
	ldr r1, [r0]\n\
	adds r5, r0, #0\n\
	cmp r2, r1\n\
	blt _080E1234\n\
	ldr r0, [r4, #0x54]\n\
	adds r1, r2, #0\n\
	bl FUN_080e1360\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080E1234\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080e1394\n\
	adds r1, r0, #0\n\
	str r1, [r4, #0x58]\n\
	str r6, [r4, #0x60]\n\
	ldrb r0, [r4, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xd]\n\
	b _080E1260\n\
_080E1234:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r5]\n\
	bl FUN_080e1360\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	beq _080E1260\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r5]\n\
	bl FUN_080e1394\n\
	adds r1, r0, #0\n\
	ldr r0, [r4, #0x58]\n\
	ldr r2, _080E1278 @ =0xFFFFF900\n\
	adds r0, r0, r2\n\
	cmp r1, r0\n\
	bge _080E1260\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r5]\n\
	bl FUN_080e13c4\n\
	str r0, [r5]\n\
_080E1260:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
	str r0, [r4, #0x58]\n\
	ldr r0, _080E127C @ =0x000006FF\n\
	cmp r1, r0\n\
	bgt _080E12FC\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	b _080E12FC\n\
	.align 2, 0\n\
_080E1278: .4byte 0xFFFFF900\n\
_080E127C: .4byte 0x000006FF\n\
_080E1280:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	bl FUN_080e1394\n\
	adds r2, r0, #0\n\
	ldr r3, [r4, #0x58]\n\
	cmp r2, r3\n\
	bge _080E1298\n\
	str r2, [r4, #0x58]\n\
	movs r0, #0\n\
	str r0, [r4, #0x60]\n\
	b _080E12CE\n\
_080E1298:\n\
	cmp r2, r3\n\
	ble _080E12CE\n\
	ldr r1, [r4, #0x60]\n\
	cmp r1, #0\n\
	bne _080E12BA\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #3\n\
	adds r0, r3, r1\n\
	cmp r2, r0\n\
	ble _080E12B6\n\
	movs r0, #0x40\n\
	str r0, [r4, #0x60]\n\
	adds r0, r3, #0\n\
	adds r0, #0x40\n\
	b _080E12CC\n\
_080E12B6:\n\
	str r2, [r4, #0x58]\n\
	b _080E12CE\n\
_080E12BA:\n\
	ldr r0, _080E1304 @ =0x000006FF\n\
	cmp r1, r0\n\
	bgt _080E12C6\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	str r0, [r4, #0x60]\n\
_080E12C6:\n\
	ldr r0, [r4, #0x58]\n\
	ldr r1, [r4, #0x60]\n\
	adds r0, r0, r1\n\
_080E12CC:\n\
	str r0, [r4, #0x58]\n\
_080E12CE:\n\
	ldr r0, [r4, #0x54]\n\
	ldr r1, [r4, #0x58]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r1, r1, r2\n\
	bl FUN_080e13f4\n\
	adds r5, r0, #0\n\
	cmp r5, #0\n\
	beq _080E12FC\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r5\n\
	ldr r1, [r4, #0x58]\n\
	ldr r2, _080E1308 @ =0xFFFFFC00\n\
	adds r1, r1, r2\n\
	bl FUN_080e1360\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080E12FC\n\
	ldr r0, [r4, #0x54]\n\
	adds r0, r0, r5\n\
	str r0, [r4, #0x54]\n\
_080E12FC:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E1304: .4byte 0x000006FF\n\
_080E1308: .4byte 0xFFFFFC00\n\
 .syntax divided\n");
}

static void MapDisk_Die(Pickup* p) {
  const bool8 ok = CreateSmallNumber((p->coord).x, (p->coord).y, p->work[0]);
  if (ok) {
    PlaySound(SE_GAIN_DISK);
    SET_ITEM_ROUTINE(p, ENTITY_EXIT);
  }
}

// 0x080e1344
static void PickupDisk_OnCollision(struct Body* body, Coords32* r1 UNUSED, Coords32* r2 UNUSED) {
  Pickup* p = (Pickup*)body->parent;
  struct Entity* q = (struct Entity*)body->enemy->parent;
  if (q->kind == ENTITY_PLAYER) p->z = (Player*)q;
}

static metatile_attr_t FUN_080e1360(s32 x, s32 y) { return (FUN_080098a4(x - PIXEL(7), y) | FUN_080098a4(x + PIXEL(7), y)); }

static s32 FUN_080e1394(s32 x, s32 y) {
  s32 y1 = FUN_08009f6c(x - PIXEL(7), y);
  s32 y2 = FUN_08009f6c(x + PIXEL(7), y);
  return min(y1, y2);
}

static s32 FUN_080e13c4(s32 x, s32 y) {
  s32 y1 = FUN_0800a134(x - PIXEL(7), y);
  s32 y2 = FUN_0800a134(x + PIXEL(7), y);
  return max(y1, y2);
}

s32 FUN_0800a40c(s32 x, s32 y);

s32 FUN_080e13f4(s32 x, s32 y) {
  s32 y1 = FUN_0800a40c(x - PIXEL(7), y);
  s32 y2 = FUN_0800a40c(x + PIXEL(7), y);
  if (((y1 < 0) && (y2 > 0)) || ((y1 > 0) && (y2 < 0))) {
    return 0;
  }
  if (((y1 < 0) && (y1 < y2)) || ((y1 > 0) && (y1 > y2))) {
    return y1;
  }
  return y2;
}

// ------------------------------------------------------------------------------------------------------------------------------------

static const struct Collision sCollision = {
  kind : DDP,
  faction : FACTION_ENEMY,
  damage : 255,
  layer : 0x00000001,
  range : {PIXEL(0), -PIXEL(8), PIXEL(16), PIXEL(16)},
};
