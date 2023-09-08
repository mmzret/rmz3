#include "global.h"
#include "overworld.h"
#include "script.h"
#include "solid.h"

extern struct Solid* gResistanceBaseElevatorPtr;

static void updateElevator(struct StageRun* p);

NAKED s16 ResistanceBase_Update(struct StageRun* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	ldr r4, [r5, #0x20]\n\
	bl updateElevator\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _08021578\n\
	b _08021858\n\
_08021578:\n\
	ldr r4, _080215A0 @ =gStageRun\n\
	ldrh r0, [r4, #8]\n\
	movs r1, #1\n\
	mov r8, r1\n\
	movs r7, #0\n\
	mov r1, r8\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	ldrb r0, [r4, #2]\n\
	cmp r0, #0\n\
	bne _080215A8\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080215A4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_080215A0: .4byte gStageRun\n\
_080215A4: .4byte gStageScriptList\n\
_080215A8:\n\
	cmp r0, #1\n\
	bne _080215C0\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080215BC @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #4]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_080215BC: .4byte gStageScriptList\n\
_080215C0:\n\
	cmp r0, #2\n\
	bne _080215D8\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _080215D4 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_080215D4: .4byte gStageScriptList\n\
_080215D8:\n\
	cmp r0, #3\n\
	bne _080215F8\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080215F4 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0xc]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_080215F4: .4byte gStageScriptList\n\
_080215F8:\n\
	cmp r0, #4\n\
	bne _08021620\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802161C @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r0, [r4, #8]\n\
	movs r1, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	mov r0, r8\n\
	b _08021986\n\
	.align 2, 0\n\
_0802161C: .4byte gStageScriptList\n\
_08021620:\n\
	cmp r0, #6\n\
	bne _08021640\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802163C @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x18]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_0802163C: .4byte gStageScriptList\n\
_08021640:\n\
	cmp r0, #7\n\
	bne _08021660\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802165C @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_0802165C: .4byte gStageScriptList\n\
_08021660:\n\
	cmp r0, #8\n\
	bne _08021680\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802167C @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x20]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_0802167C: .4byte gStageScriptList\n\
_08021680:\n\
	cmp r0, #9\n\
	bne _080216B4\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080216AC @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x24]\n\
	bl SetScript\n\
	ldr r0, _080216B0 @ =gCurStory\n\
	ldrb r1, [r0, #6]\n\
	movs r0, #0x14\n\
	ands r0, r1\n\
	cmp r0, #4\n\
	beq _080216A6\n\
	b _08021848\n\
_080216A6:\n\
	movs r0, #7\n\
	b _08021986\n\
	.align 2, 0\n\
_080216AC: .4byte gStageScriptList\n\
_080216B0: .4byte gCurStory\n\
_080216B4:\n\
	ldrb r0, [r4, #2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0xa\n\
	bne _080216F0\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080216EC @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xb\n\
	bl setStageCheckpoint\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_080216EC: .4byte gStageScriptList\n\
_080216F0:\n\
	cmp r1, #0xb\n\
	bne _08021724\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _0802171C @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x2c]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	ldr r1, _08021720 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xc\n\
	bl setStageCheckpoint\n\
	b _08021848\n\
	.align 2, 0\n\
_0802171C: .4byte gStageScriptList\n\
_08021720: .4byte 0x0000FFFE\n\
_08021724:\n\
	cmp r1, #0xc\n\
	bne _08021738\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _08021734 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	b _08021848\n\
	.align 2, 0\n\
_08021734: .4byte 0x0000FFFE\n\
_08021738:\n\
	cmp r1, #0xd\n\
	bne _08021754\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _08021750 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x30]\n\
	b _08021768\n\
	.align 2, 0\n\
_08021750: .4byte gStageScriptList\n\
_08021754:\n\
	cmp r1, #0xe\n\
	bne _08021784\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _08021780 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x34]\n\
_08021768:\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_08021780: .4byte gStageScriptList\n\
_08021784:\n\
	cmp r1, #0xf\n\
	bne _080217B4\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080217B0 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_080217B0: .4byte gStageScriptList\n\
_080217B4:\n\
	cmp r1, #0x10\n\
	bne _080217E4\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r2, _080217E0 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x1c]\n\
	bl SetScript\n\
	ldrh r1, [r4, #8]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_080217E0: .4byte gStageScriptList\n\
_080217E4:\n\
	cmp r1, #0x11\n\
	bne _08021808\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021804 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #8]\n\
	bl SetScript\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_08021804: .4byte gStageScriptList\n\
_08021808:\n\
	cmp r1, #0x12\n\
	bne _0802181C\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021818 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x48]\n\
	b _08021844\n\
	.align 2, 0\n\
_08021818: .4byte gStageScriptList\n\
_0802181C:\n\
	cmp r1, #0x13\n\
	bne _08021830\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _0802182C @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	b _08021848\n\
	.align 2, 0\n\
_0802182C: .4byte 0x0000FFFE\n\
_08021830:\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x14\n\
	beq _0802183A\n\
	b _08021988\n\
_0802183A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x10\n\
	ldr r1, _08021854 @ =gStageScriptList\n\
	ldr r1, [r1, #0x44]\n\
	ldr r1, [r1, #0x54]\n\
_08021844:\n\
	bl SetScript\n\
_08021848:\n\
	movs r0, #0xbe\n\
	lsls r0, r0, #1\n\
	adds r1, r5, r0\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	b _08021988\n\
	.align 2, 0\n\
_08021854: .4byte gStageScriptList\n\
_08021858:\n\
	cmp r0, #1\n\
	bne _0802187C\n\
	ldr r0, _08021874 @ =gStageRun+16\n\
	ldr r2, _08021878 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x10]\n\
	bl SetScript\n\
	movs r0, #2\n\
	b _08021986\n\
	.align 2, 0\n\
_08021874: .4byte gStageRun+16\n\
_08021878: .4byte gStageScriptList\n\
_0802187C:\n\
	cmp r0, #2\n\
	bne _080218A4\n\
	ldr r0, _0802189C @ =gStageRun+16\n\
	ldr r2, _080218A0 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x28]\n\
	bl SetScript\n\
	movs r0, #0xb\n\
	bl setStageCheckpoint\n\
	movs r0, #3\n\
	b _08021986\n\
	.align 2, 0\n\
_0802189C: .4byte gStageRun+16\n\
_080218A0: .4byte gStageScriptList\n\
_080218A4:\n\
	cmp r0, #3\n\
	bne _080218D8\n\
	ldr r4, _080218CC @ =gStageRun+16\n\
	ldr r1, _080218D0 @ =gStageScriptList\n\
	ldrh r0, [r5]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, [r0, #0x2c]\n\
	adds r0, r4, #0\n\
	bl SetScript\n\
	subs r4, #0x10\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, _080218D4 @ =0x0000FFFE\n\
	ands r0, r1\n\
	strh r0, [r4, #8]\n\
	movs r0, #0xc\n\
	b _08021980\n\
	.align 2, 0\n\
_080218CC: .4byte gStageRun+16\n\
_080218D0: .4byte gStageScriptList\n\
_080218D4: .4byte 0x0000FFFE\n\
_080218D8:\n\
	cmp r0, #4\n\
	bne _08021908\n\
	ldr r0, _080218FC @ =gStageRun+16\n\
	ldr r2, _08021900 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x38]\n\
	bl SetScript\n\
	ldr r2, _08021904 @ =gCurStory\n\
	ldrb r1, [r2, #5]\n\
	movs r0, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r2, #5]\n\
	movs r0, #0x14\n\
	b _08021980\n\
	.align 2, 0\n\
_080218FC: .4byte gStageRun+16\n\
_08021900: .4byte gStageScriptList\n\
_08021904: .4byte gCurStory\n\
_08021908:\n\
	cmp r0, #5\n\
	bne _08021928\n\
	ldr r0, _08021920 @ =gStageRun+16\n\
	ldr r2, _08021924 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x3c]\n\
	bl SetScript\n\
	b _08021984\n\
	.align 2, 0\n\
_08021920: .4byte gStageRun+16\n\
_08021924: .4byte gStageScriptList\n\
_08021928:\n\
	cmp r0, #6\n\
	bne _0802194C\n\
	ldr r0, _08021944 @ =gStageRun+16\n\
	ldr r2, _08021948 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x40]\n\
	bl SetScript\n\
	movs r0, #7\n\
	b _08021986\n\
	.align 2, 0\n\
_08021944: .4byte gStageRun+16\n\
_08021948: .4byte gStageScriptList\n\
_0802194C:\n\
	cmp r0, #7\n\
	bne _08021988\n\
	ldr r1, [r4, #0x54]\n\
	ldr r0, _08021994 @ =0x000B3FFF\n\
	cmp r1, r0\n\
	ble _08021988\n\
	ldr r0, _08021998 @ =0x000C2FFF\n\
	cmp r1, r0\n\
	bgt _08021988\n\
	ldr r1, [r4, #0x58]\n\
	ldr r0, _0802199C @ =0x0001DFFF\n\
	cmp r1, r0\n\
	ble _08021988\n\
	ldr r0, _080219A0 @ =0x00027FFF\n\
	cmp r1, r0\n\
	bgt _08021988\n\
	ldr r0, _080219A4 @ =gStageRun+16\n\
	ldr r2, _080219A8 @ =gStageScriptList\n\
	ldrh r1, [r5]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	ldr r1, [r1, #0x44]\n\
	bl SetScript\n\
	movs r0, #0x12\n\
_08021980:\n\
	bl setStageCheckpoint\n\
_08021984:\n\
	movs r0, #0xff\n\
_08021986:\n\
	strb r0, [r6]\n\
_08021988:\n\
	movs r0, #0\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08021994: .4byte 0x000B3FFF\n\
_08021998: .4byte 0x000C2FFF\n\
_0802199C: .4byte 0x0001DFFF\n\
_080219A0: .4byte 0x00027FFF\n\
_080219A4: .4byte gStageRun+16\n\
_080219A8: .4byte gStageScriptList\n\
 .syntax divided\n");
}

static void updateElevator(struct StageRun* p) {
  u8 level;
  struct Solid* lift;
  struct Zero* z = (struct Zero*)(p->vm).entities[0].entity;
  if (((z->s).coord.x - 0x59001U < 0x19FFF) && (z->s).coord.y < 0x5A000 && ((6 >> gStageEntityManager.area) & 1)) {
    if (p->unk_0a & 1) {
      return;
    }
    if ((z->s).coord.y < 0x28000) {
      level = 0;
    } else if ((z->s).coord.y < 0x32000) {
      level = 1;
    } else if ((z->s).coord.y < 0x3c000) {
      level = 2;
    } else if ((z->s).coord.y < 0x46000) {
      level = 3;
    } else if ((z->s).coord.y < 0x50000) {
      level = 4;
    } else {
      level = 5;
    }
    gResistanceBaseElevatorPtr = CreateResistanceBaseElevator(level);
    if (gResistanceBaseElevatorPtr != NULL) {
      p->unk_0a |= 1;
    }
    return;
  }

  if (!(p->unk_0a & 1)) {
    return;
  }

  lift = gResistanceBaseElevatorPtr;
  (lift->s).flags &= ~DISPLAY;
  (lift->s).flags &= ~FLIPABLE;
  (lift->body).status = 0;
  (lift->body).prevStatus = 0;
  (lift->body).invincibleTime = 0;
  (lift->s).flags &= ~COLLIDABLE;
  SET_SOLID_ROUTINE(lift, ENTITY_DISAPPEAR);
  p->unk_0a ^= 1;
}
