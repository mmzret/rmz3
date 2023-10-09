#include "cyberelf.h"
#include "global.h"
#include "story.h"
#include "vfx.h"

static void FollowerElf_Init(struct Elf* e);
static void FollowerElf_Update(struct Elf* e);
static void FollowerElf_Die(struct Elf* e);

// clang-format off
const ElfRoutine gFollowerElfRoutine = {
    [ENTITY_INIT] =      FollowerElf_Init,
    [ENTITY_UPDATE] =    FollowerElf_Update,
    [ENTITY_DIE] =       FollowerElf_Die,
    [ENTITY_DISAPPEAR] = DeleteElf,
    [ENTITY_EXIT] =      (ElfFunc)DeleteEntity,
};
// clang-format on

void MenuExit_FollowerElf(struct Elf* e) {
  struct Zero* player = (e->props.follower).player;
  if ((e->props.follower).isSatelite1 == 0) {
    if ((e->props.follower).id == ((&player->unk_b4)->status).asset.satelites[0]) {
      return;
    }
    if (player->unk_121 == ELF_BYSE) {
      CLEAR_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    }
    (e->s).flags &= ~DISPLAY;
    (e->s).flags &= ~FLIPABLE;
    (e->body).status = 0;
    (e->body).prevStatus = 0;
    (e->body).invincibleTime = 0;
  } else {
    if ((e->props.follower).id == ((&player->unk_b4)->status).asset.satelites[1]) {
      return;
    }
    if (player->unk_121 == ELF_BYSE) {
      CLEAR_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
    }
    (e->s).flags &= ~DISPLAY;
    (e->s).flags &= ~FLIPABLE;
    (e->body).status = 0;
    (e->body).prevStatus = 0;
    (e->body).invincibleTime = 0;
  }
  (e->s).flags &= ~COLLIDABLE;
  SET_ELF_ROUTINE(e, ENTITY_DISAPPEAR);
}

struct Elf* CreateFollowerElf(struct Zero* p, u8 breed, u8 availability, bool8 isSatelite1) {
  struct Elf* e = (struct Elf*)AllocEntityFirst(gElfHeaderPtr);
  if (e != NULL) {
    (e->s).taskCol = 16;
    INIT_ELF_ROUTINE(e, 8);
    (e->s).tileNum = 0;
    (e->s).palID = 0;
    (e->props.follower).player = p;
    (e->s).work[0] = breed;
    (e->s).work[1] = availability;
    (e->props.follower).isSatelite1 = isSatelite1;
    if (isSatelite1 == 0) {
      (e->props.follower).id = ((&p->unk_b4)->status).asset.satelites[0];
    } else {
      (e->props.follower).id = ((&p->unk_b4)->status).asset.satelites[1];
    }
  }
  return e;
}

NAKED static void FollowerElf_Init(struct Elf* e) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r5, [r0]\n\
	ldr r1, _080E41D8 @ =gZeroRanges\n\
	ldr r2, _080E41DC @ =0x00000147\n\
	adds r0, r5, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	ldr r7, [r0, #4]\n\
	ldr r1, _080E41E0 @ =gElfFnTable\n\
	ldrb r0, [r4, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	str r1, [r4, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl InitNonAffineMotion\n\
	adds r0, r4, #0\n\
	bl ResetDynamicMotion\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4, #0xa]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #0\n\
	bne _080E41E4\n\
	movs r0, #0\n\
	b _080E41EA\n\
	.align 2, 0\n\
_080E41D8: .4byte gZeroRanges\n\
_080E41DC: .4byte 0x00000147\n\
_080E41E0: .4byte gElfFnTable\n\
_080E41E4:\n\
	cmp r0, #1\n\
	bne _080E41FC\n\
	movs r0, #1\n\
_080E41EA:\n\
	bl GetElfMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
	b _080E420E\n\
_080E41FC:\n\
	movs r0, #2\n\
	bl GetElfMotion\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl SetMotion\n\
_080E420E:\n\
	adds r0, r4, #0\n\
	bl UpdateMotionGraphic\n\
	adds r1, r4, #0\n\
	adds r1, #0x4c\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	adds r2, r4, #0\n\
	adds r2, #0x4a\n\
	ldrb r1, [r2]\n\
	subs r0, #0x11\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0xef\n\
	ands r0, r1\n\
	strb r0, [r4, #0xa]\n\
	lsls r0, r6, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r1, [r5, #0x54]\n\
	adds r1, r1, r0\n\
	str r1, [r4, #0x54]\n\
	asrs r2, r6, #0x10\n\
	ldr r0, [r5, #0x58]\n\
	adds r0, r0, r2\n\
	str r0, [r4, #0x58]\n\
	str r1, [r4, #0x64]\n\
	str r0, [r4, #0x68]\n\
	adds r2, r4, #0\n\
	adds r2, #0xc2\n\
	movs r1, #0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	strh r0, [r2]\n\
	adds r0, r4, #0\n\
	adds r0, #0xc0\n\
	strb r1, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0xb9\n\
	movs r0, #0x20\n\
	strb r0, [r1]\n\
	ldr r1, _080E4280 @ =0x00000121\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0x28\n\
	bne _080E4274\n\
	ldr r0, _080E4284 @ =gCurStory\n\
	ldrb r1, [r0, #8]\n\
	movs r2, #0x80\n\
	orrs r1, r2\n\
	strb r1, [r0, #8]\n\
_080E4274:\n\
	adds r0, r4, #0\n\
	bl FollowerElf_Update\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080E4280: .4byte 0x00000121\n\
_080E4284: .4byte gCurStory\n\
 .syntax divided\n");
}

NAKED static void FollowerElf_Update(struct Elf* e) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	adds r0, #0xb4\n\
	ldr r4, [r0]\n\
	adds r0, r5, #0\n\
	bl UpdateMotionGraphic\n\
	ldr r0, _080E42E0 @ =gPause\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	beq _080E42A0\n\
	b _080E44E4\n\
_080E42A0:\n\
	ldr r1, _080E42E4 @ =0x00000232\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080E42EC\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfe\n\
	ands r0, r1\n\
	movs r1, #0xfd\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	adds r0, r5, #0\n\
	adds r0, #0x8c\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	str r2, [r0]\n\
	adds r0, #4\n\
	strb r2, [r0]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #0xfb\n\
	ands r0, r1\n\
	strb r0, [r5, #0xa]\n\
	ldr r1, _080E42E8 @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #3\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r5, #0x14]\n\
	b _080E44E4\n\
	.align 2, 0\n\
_080E42E0: .4byte gPause\n\
_080E42E4: .4byte 0x00000232\n\
_080E42E8: .4byte gElfFnTable\n\
_080E42EC:\n\
	adds r0, r4, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080E4308\n\
	adds r0, r4, #0\n\
	adds r0, #0xa4\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	cmp r0, #0\n\
	bne _080E4320\n\
_080E4308:\n\
	ldr r1, _080E431C @ =gElfFnTable\n\
	ldrb r0, [r5, #9]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r1, #2\n\
	str r1, [r5, #0xc]\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r5, #0x14]\n\
	b _080E44E4\n\
	.align 2, 0\n\
_080E431C: .4byte gElfFnTable\n\
_080E4320:\n\
	ldrb r1, [r4, #0xa]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080E4360\n\
	adds r0, r5, #0\n\
	adds r0, #0xc1\n\
	ldrb r1, [r0]\n\
	adds r7, r0, #0\n\
	cmp r1, #0\n\
	beq _080E434A\n\
	ldr r0, [r5, #0x64]\n\
	movs r3, #0xd8\n\
	lsls r3, r3, #5\n\
	adds r0, r0, r3\n\
	ldr r1, [r4, #0x54]\n\
	subs r6, r1, r0\n\
	ldr r0, [r5, #0x68]\n\
	movs r1, #0x98\n\
	lsls r1, r1, #5\n\
	b _080E4394\n\
_080E434A:\n\
	ldr r0, [r5, #0x64]\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #4\n\
	adds r0, r0, r2\n\
	ldr r1, [r4, #0x54]\n\
	subs r6, r1, r0\n\
	ldr r0, [r5, #0x68]\n\
	movs r3, #0xa4\n\
	lsls r3, r3, #6\n\
	adds r0, r0, r3\n\
	b _080E4396\n\
_080E4360:\n\
	adds r0, r5, #0\n\
	adds r0, #0xc1\n\
	ldrb r1, [r0]\n\
	adds r7, r0, #0\n\
	cmp r1, #0\n\
	beq _080E4384\n\
	ldr r0, [r5, #0x64]\n\
	ldr r1, _080E4380 @ =0xFFFFE500\n\
	adds r0, r0, r1\n\
	ldr r1, [r4, #0x54]\n\
	subs r6, r1, r0\n\
	ldr r0, [r5, #0x68]\n\
	movs r2, #0x98\n\
	lsls r2, r2, #5\n\
	adds r0, r0, r2\n\
	b _080E4396\n\
	.align 2, 0\n\
_080E4380: .4byte 0xFFFFE500\n\
_080E4384:\n\
	ldr r0, [r5, #0x64]\n\
	ldr r3, _080E43D8 @ =0xFFFFF300\n\
	adds r0, r0, r3\n\
	ldr r1, [r4, #0x54]\n\
	subs r6, r1, r0\n\
	ldr r0, [r5, #0x68]\n\
	movs r1, #0xa4\n\
	lsls r1, r1, #6\n\
_080E4394:\n\
	adds r0, r0, r1\n\
_080E4396:\n\
	ldr r1, [r4, #0x58]\n\
	subs r4, r1, r0\n\
	adds r0, r6, #0\n\
	adds r1, r4, #0\n\
	bl CalcAngle\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	adds r1, r6, #0\n\
	cmp r6, #0\n\
	bge _080E43AE\n\
	rsbs r1, r6, #0\n\
_080E43AE:\n\
	adds r0, r4, #0\n\
	cmp r4, #0\n\
	bge _080E43B6\n\
	rsbs r0, r4, #0\n\
_080E43B6:\n\
	cmp r1, r0\n\
	ble _080E43E0\n\
	adds r1, r6, #0\n\
	cmp r1, #0\n\
	bge _080E43C2\n\
	rsbs r1, r1, #0\n\
_080E43C2:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	ble _080E4404\n\
	ldr r1, [r5, #0x5c]\n\
	ldr r0, _080E43DC @ =0x000005FF\n\
	cmp r1, r0\n\
	bgt _080E4416\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	b _080E4414\n\
	.align 2, 0\n\
_080E43D8: .4byte 0xFFFFF300\n\
_080E43DC: .4byte 0x000005FF\n\
_080E43E0:\n\
	adds r1, r4, #0\n\
	cmp r1, #0\n\
	bge _080E43E8\n\
	rsbs r1, r1, #0\n\
_080E43E8:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	cmp r1, r0\n\
	ble _080E4404\n\
	ldr r1, [r5, #0x5c]\n\
	ldr r0, _080E4400 @ =0x000005FF\n\
	cmp r1, r0\n\
	bgt _080E4416\n\
	adds r0, r1, #0\n\
	adds r0, #0x10\n\
	b _080E4414\n\
	.align 2, 0\n\
_080E4400: .4byte 0x000005FF\n\
_080E4404:\n\
	ldr r0, [r5, #0x5c]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	cmp r0, r1\n\
	ble _080E4410\n\
	str r1, [r5, #0x5c]\n\
_080E4410:\n\
	ldr r0, [r5, #0x5c]\n\
	subs r0, #0x20\n\
_080E4414:\n\
	str r0, [r5, #0x5c]\n\
_080E4416:\n\
	ldr r0, [r5, #0x5c]\n\
	cmp r0, #0x7f\n\
	bgt _080E4420\n\
	movs r0, #0x80\n\
	str r0, [r5, #0x5c]\n\
_080E4420:\n\
	ldr r4, _080E4498 @ =gSineTable\n\
	adds r0, r3, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r0, [r0, r2]\n\
	ldr r2, [r5, #0x5c]\n\
	adds r1, r2, #0\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r5, #0x64]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x64]\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r4\n\
	movs r3, #0\n\
	ldrsh r0, [r0, r3]\n\
	adds r1, r2, #0\n\
	muls r1, r0, r1\n\
	asrs r1, r1, #8\n\
	ldr r0, [r5, #0x68]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x68]\n\
	adds r1, r5, #0\n\
	adds r1, #0xc0\n\
	ldrb r2, [r1]\n\
	adds r3, r2, #1\n\
	adds r0, r3, #0\n\
	asrs r0, r0, #5\n\
	lsls r0, r0, #5\n\
	subs r0, r3, r0\n\
	strb r0, [r1]\n\
	ldrb r3, [r1]\n\
	lsls r2, r3, #3\n\
	ldrb r0, [r7]\n\
	cmp r0, #0\n\
	beq _080E449C\n\
	movs r0, #0x3f\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r5, #0x64]\n\
	subs r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	mvns r0, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r5, #0x68]\n\
	subs r0, r0, r1\n\
	b _080E44C2\n\
	.align 2, 0\n\
_080E4498: .4byte gSineTable\n\
_080E449C:\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r5, #0x64]\n\
	adds r0, r0, r1\n\
	str r0, [r5, #0x54]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r4\n\
	movs r3, #0\n\
	ldrsh r1, [r0, r3]\n\
	lsls r1, r1, #2\n\
	ldr r0, [r5, #0x68]\n\
	adds r0, r0, r1\n\
_080E44C2:\n\
	str r0, [r5, #0x58]\n\
	adds r4, r5, #0\n\
	adds r4, #0xb9\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _080E44E4\n\
	adds r0, r5, #0\n\
	adds r0, #0x54\n\
	movs r1, #2\n\
	bl FUN_080bfc94\n\
	movs r0, #0x20\n\
	strb r0, [r4]\n\
_080E44E4:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void FollowerElf_Die(struct Elf* e) {
  struct Zero* player = (e->props.follower).player;
  FUN_080bfce8(&(e->s).coord, 0);
  if (player->unk_121 == ELF_BYSE) {
    CLEAR_FLAG(gCurStory.s.gameflags, BYSE_ENABLED);
  }
  (e->s).flags &= ~DISPLAY;
  SET_ELF_ROUTINE(e, ENTITY_EXIT);
}
