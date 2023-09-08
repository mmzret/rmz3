#include "global.h"
#include "overworld.h"

static void clearQuakeManager(void);

void ClearQuakeManager(void) {
  gQuakeManager.rng = 0;
  gQuakeManager.frame = 0;
  gQuakeManager.power = 0;
  gQuakeManager.unk_1a6 = 0;
  clearQuakeManager();
}

static void clearQuakeManager(void) {
  gQuakeManager.length = 0;
  gQuakeManager.quakes[0].power = 0;
  gQuakeManager.unk_1a4 = 0;
  gQuakeManager.unk_0d0[0].power = 0;
}

void AppendQuake(u8 power, struct Coord *c) {
  if (power != 0) {
    s32 n = gQuakeManager.length;
    if (n < 16) {
      gQuakeManager.quakes[n].c.x = c->x;
      gQuakeManager.quakes[n].c.y = c->y;
      gQuakeManager.quakes[n].power = power;

      n++;
      gQuakeManager.quakes[n].power = 0;
      gQuakeManager.length = n;
    }
  }
}

// 画面を揺らす量を計算して第二引数のCoordにセットする
NAKED void CalcQuake(struct Coord *c, struct Coord *ofs) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r6, r1, #0\n\
	ldr r1, _0801AC50 @ =gQuakeManager+4\n\
	movs r2, #0xce\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	ldr r5, [r0]\n\
	ldr r0, [r1]\n\
	subs r3, r1, #4\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _0801ABE2\n\
_0801ABD0:\n\
	ldr r0, [r1]\n\
	lsls r0, r0, #8\n\
	cmp r5, r0\n\
	bge _0801ABDA\n\
	adds r5, r0, #0\n\
_0801ABDA:\n\
	adds r1, #0xc\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _0801ABD0\n\
_0801ABE2:\n\
	asrs r0, r5, #6\n\
	cmp r0, #0\n\
	beq _0801AC60\n\
	ldr r2, _0801AC54 @ =gSineTable\n\
	movs r3, #0xcf\n\
	lsls r3, r3, #1\n\
	add r3, ip\n\
	ldrh r0, [r3]\n\
	adds r1, r0, #1\n\
	strh r1, [r3]\n\
	lsls r0, r0, #0x1e\n\
	lsrs r0, r0, #0x17\n\
	adds r0, r0, r2\n\
	movs r7, #0\n\
	ldrsh r0, [r0, r7]\n\
	muls r0, r5, r0\n\
	cmp r0, #0\n\
	bge _0801AC08\n\
	adds r0, #0xff\n\
_0801AC08:\n\
	asrs r2, r0, #8\n\
	asrs r0, r0, #0xc\n\
	str r0, [r6]\n\
	mov r1, ip\n\
	ldr r0, [r1]\n\
	ldr r4, _0801AC58 @ =0x000343FD\n\
	muls r0, r4, r0\n\
	ldr r3, _0801AC5C @ =0x00269EC3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	mov r7, ip\n\
	str r1, [r7]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #0xff\n\
	ands r0, r1\n\
	subs r0, #0x7f\n\
	ldr r1, [r6]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #7\n\
	str r0, [r6]\n\
	str r2, [r6, #4]\n\
	subs r2, #3\n\
	ldr r0, [r7]\n\
	muls r0, r4, r0\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #1\n\
	lsrs r1, r0, #1\n\
	str r1, [r7]\n\
	lsrs r0, r0, #0x11\n\
	movs r1, #7\n\
	ands r0, r1\n\
	adds r2, r2, r0\n\
	asrs r2, r2, #1\n\
	str r2, [r6, #4]\n\
	b _0801AC64\n\
	.align 2, 0\n\
_0801AC50: .4byte gQuakeManager+4\n\
_0801AC54: .4byte gSineTable\n\
_0801AC58: .4byte 0x000343FD\n\
_0801AC5C: .4byte 0x00269EC3\n\
_0801AC60:\n\
	str r0, [r6, #4]\n\
	str r0, [r6]\n\
_0801AC64:\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	lsls r0, r5, #4\n\
	subs r0, r0, r5\n\
	asrs r0, r0, #4\n\
	str r0, [r1]\n\
	movs r1, #0xce\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	mov r1, ip\n\
	str r0, [r1, #4]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

static void Unused_0801ac88(u32 power, struct Coord *c) {
  if (power != 0) {
    s32 n = gQuakeManager.unk_1a4;
    if (n < 16) {
      gQuakeManager.unk_0d0[n].c.x = c->x;
      gQuakeManager.unk_0d0[n].c.y = c->y;
      gQuakeManager.unk_0d0[n].power = power;

      n++;
      gQuakeManager.unk_0d0[n].power = 0;
      gQuakeManager.unk_1a4 = n;
    }
  }
}

NAKED s32 quake_0801acdc(struct Coord *_) {
  asm(".syntax unified\n\
	push {lr}\n\
	ldr r1, _0801AD34 @ =gQuakeManager+208\n\
	adds r0, r1, #0\n\
	adds r0, #0xd6\n\
	ldrh r2, [r0]\n\
	ldr r0, [r1]\n\
	movs r3, #0xd0\n\
	rsbs r3, r3, #0\n\
	adds r3, r3, r1\n\
	mov ip, r3\n\
	cmp r0, #0\n\
	beq _0801AD06\n\
_0801ACF4:\n\
	ldr r0, [r1]\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	bge _0801ACFE\n\
	adds r2, r0, #0\n\
_0801ACFE:\n\
	adds r1, #0xc\n\
	ldr r0, [r1]\n\
	cmp r0, #0\n\
	bne _0801ACF4\n\
_0801AD06:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #6\n\
	cmp r2, r0\n\
	ble _0801AD10\n\
	adds r2, r0, #0\n\
_0801AD10:\n\
	lsls r0, r2, #4\n\
	subs r0, r0, r2\n\
	asrs r0, r0, #4\n\
	movs r3, #0xd3\n\
	lsls r3, r3, #1\n\
	add r3, ip\n\
	movs r1, #0\n\
	strh r0, [r3]\n\
	movs r0, #0xd2\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	strh r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0xd0\n\
	str r1, [r0]\n\
	asrs r0, r2, #8\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0801AD34: .4byte gQuakeManager+208\n\
 .syntax divided\n");
}
