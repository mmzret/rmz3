#include "stage.h"

#include "gba/gba.h"
#include "global.h"

void FUN_08004e64(void* p, void* s);
u32 FUN_080094f0(s32 x, s32 y);

// ステージのロードに関係
NAKED void stage_08008a54(s32 stageID, struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	adds r3, r0, #0\n\
	ldr r5, _08008B64 @ =0x020023C8\n\
	ldr r0, [r1]\n\
	str r0, [r5]\n\
	ldr r0, [r1, #4]\n\
	str r0, [r5, #4]\n\
	ldr r1, _08008B68 @ =0x0833A2E8\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldr r3, [r7]\n\
	ldr r2, _08008B6C @ =0x02002140\n\
	ldrh r1, [r2]\n\
	ldr r0, _08008B70 @ =0x0000C1FF\n\
	ands r0, r1\n\
	movs r6, #0\n\
	strh r0, [r2]\n\
	ldr r0, _08008B74 @ =0xFFFFFE38\n\
	adds r4, r5, r0\n\
	ldr r1, _08008B78 @ =FUN_080096b8\n\
	adds r0, r4, #0\n\
	str r3, [sp, #4]\n\
	bl setU32ToArrIdx1\n\
	str r4, [r4, #8]\n\
	ldr r1, _08008B7C @ =0x0002BE3A\n\
	adds r0, r5, r1\n\
	strh r6, [r0]\n\
	movs r1, #0x80\n\
	ldr r3, [sp, #4]\n\
	adds r0, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r5, #8]\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #2\n\
	ldr r2, _08008B80 @ =0x0863C578\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	adds r2, r2, r0\n\
	ldr r3, [r0, #8]\n\
	adds r3, r3, r0\n\
	ldr r1, [r0, #4]\n\
	adds r1, r1, r0\n\
	adds r0, r5, #0\n\
	subs r0, #0x10\n\
	ldr r4, [r7, #0xc]\n\
	str r4, [sp]\n\
	bl FUN_08006db8\n\
	ldr r3, _08008B84 @ =0x0000060C\n\
	adds r1, r5, r3\n\
	ldr r0, _08008B88 @ =0x0000FFFF\n\
	strh r0, [r1]\n\
	ldr r0, _08008B8C @ =0x0000060E\n\
	adds r1, r5, r0\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	strh r0, [r1]\n\
	ldr r2, _08008B90 @ =0x0002BE3C\n\
	adds r1, r5, r2\n\
	ldr r0, [r7, #0x78]\n\
	str r0, [r1]\n\
	ldr r3, _08008B94 @ =0x0002BE40\n\
	adds r5, r5, r3\n\
	ldr r0, [r7, #0x7c]\n\
	str r0, [r5]\n\
	ldr r1, [r7, #0xc]\n\
	adds r0, r7, #0\n\
	bl loadStageTerrain\n\
	movs r0, #0\n\
_08008AE8:\n\
	lsls r4, r0, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r4, #0\n\
	adds r1, r7, #0\n\
	bl resetStageBg\n\
	adds r4, #1\n\
	lsls r4, r4, #0x10\n\
	lsrs r0, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	cmp r4, #2\n\
	ble _08008AE8\n\
	ldr r1, _08008B98 @ =0x02002200\n\
	ldr r2, _08008B9C @ =0x0002C00C\n\
	adds r0, r1, r2\n\
	ldr r2, _08008BA0 @ =0x7FFFFFFF\n\
	str r2, [r0]\n\
	ldr r3, _08008BA4 @ =0x0002C010\n\
	adds r0, r1, r3\n\
	str r2, [r0]\n\
	ldr r2, _08008BA8 @ =0x0002C014\n\
	adds r0, r1, r2\n\
	movs r3, #0\n\
	str r3, [r0]\n\
	adds r2, #4\n\
	adds r0, r1, r2\n\
	str r3, [r0]\n\
	ldr r0, _08008BAC @ =0x0002C01C\n\
	adds r2, r1, r0\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #0xe\n\
	str r0, [r2]\n\
	ldr r0, _08008BB0 @ =0x0002C020\n\
	adds r2, r1, r0\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0xe\n\
	str r0, [r2]\n\
	movs r2, #0xe9\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	strb r3, [r0]\n\
	adds r2, #1\n\
	adds r0, r1, r2\n\
	strb r3, [r0]\n\
	movs r2, #0\n\
	ldr r3, _08008BB4 @ =0x0002D024\n\
	adds r4, r1, r3\n\
	movs r3, #0\n\
_08008B48:\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r0, r4\n\
	strb r3, [r1]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _08008B48\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008B64: .4byte 0x020023C8\n\
_08008B68: .4byte 0x0833A2E8\n\
_08008B6C: .4byte 0x02002140\n\
_08008B70: .4byte 0x0000C1FF\n\
_08008B74: .4byte 0xFFFFFE38\n\
_08008B78: .4byte FUN_080096b8\n\
_08008B7C: .4byte 0x0002BE3A\n\
_08008B80: .4byte 0x0863C578\n\
_08008B84: .4byte 0x0000060C\n\
_08008B88: .4byte 0x0000FFFF\n\
_08008B8C: .4byte 0x0000060E\n\
_08008B90: .4byte 0x0002BE3C\n\
_08008B94: .4byte 0x0002BE40\n\
_08008B98: .4byte 0x02002200\n\
_08008B9C: .4byte 0x0002C00C\n\
_08008BA0: .4byte 0x7FFFFFFF\n\
_08008BA4: .4byte 0x0002C010\n\
_08008BA8: .4byte 0x0002C014\n\
_08008BAC: .4byte 0x0002C01C\n\
_08008BB0: .4byte 0x0002C020\n\
_08008BB4: .4byte 0x0002D024\n\
     .syntax divided\n");
}

/*
中でstage関数リスト(例: 083472e8)の idx 0,1を呼び出している

さらに、02002220,020022a8,02002330 の指す関数(stage関数リストのどれか？)を呼び出している

引数のcoordはゼロのいる座標ではなく、現在の視界(だいたいゼロの座標と一致するが)
*/
NAKED void runStageScript(struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #8\n\
	ldr r4, _08008C2C @ =0x020023C8\n\
	ldr r1, [r0]\n\
	str r1, [r4]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #4]\n\
	asrs r1, r1, #8\n\
	subs r1, #0x78\n\
	lsls r1, r1, #8\n\
	str r1, [sp]\n\
	asrs r0, r0, #8\n\
	subs r0, #0x50\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #4]\n\
	mov r0, sp\n\
	bl loadStageTileset_0800956c\n\
	adds r5, r0, #0\n\
	ldrh r0, [r4, #8]\n\
	ldr r1, [r5]\n\
	cmp r0, r1\n\
	beq _08008BF2\n\
	strh r1, [r4, #8]\n\
	ldr r0, [r5, #4]\n\
	ldr r1, [r0]\n\
	mov r0, sp\n\
	bl _call_via_r1\n\
_08008BF2:\n\
	ldr r0, [r5, #4]\n\
	ldr r1, [r0, #4]\n\
	mov r0, sp\n\
	bl _call_via_r1\n\
	movs r7, #0\n\
	movs r6, #2\n\
_08008C00:\n\
	ldr r0, _08008C30 @ =0x02002220\n\
	adds r4, r7, r0\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	mov r2, sp\n\
	bl FUN_08009754\n\
	ldr r2, [r4]\n\
	cmp r2, #0\n\
	beq _08008C1C\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl _call_via_r2\n\
_08008C1C:\n\
	adds r7, #0x88\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bge _08008C00\n\
	add sp, #8\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008C2C: .4byte 0x020023C8\n\
_08008C30: .4byte 0x02002220\n\
   .syntax divided\n");
}

void FUN_08008c34(void* p) {
  FUN_08004e64(p, (void*)(0x02002200));
  return;
}

/*
void saveBgSettings(void) {
  EnabledBG = (wDISPCNT >> 8) & 0xf;
  SavedBGCNT[0] = wBGnCNT[1];
  SavedBGCNT[1] = wBGnCNT[2];
  SavedBGCNT[2] = wBGnCNT[3];
  return;
}
*/
NAKED void saveBgSettings(void) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	ldr r2, _08008C7C @ =0x02002200\n\
	ldr r3, _08008C80 @ =0x02002140\n\
	ldrh r1, [r3]\n\
	movs r0, #0xf0\n\
	lsls r0, r0, #4\n\
	ands r0, r1\n\
	lsrs r0, r0, #8\n\
	movs r4, #0xfb\n\
	lsls r4, r4, #3\n\
	adds r1, r2, r4\n\
	strh r0, [r1]\n\
	ldrh r1, [r3, #6]\n\
	adds r4, #2\n\
	adds r0, r2, r4\n\
	strh r1, [r0]\n\
	ldrh r1, [r3, #8]\n\
	adds r4, #2\n\
	adds r0, r2, r4\n\
	strh r1, [r0]\n\
	ldrh r0, [r3, #0xa]\n\
	ldr r1, _08008C84 @ =0x000007DE\n\
	adds r2, r2, r1\n\
	strh r0, [r2]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008C7C: .4byte 0x02002200\n\
_08008C80: .4byte 0x02002140\n\
_08008C84: .4byte 0x000007DE\n\
   .syntax divided\n");
}

NAKED void loadStageTileset_08008c88(void) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r2, _08008D78 @ =0x02002140\n\
	ldrh r1, [r2]\n\
	ldr r0, _08008D7C @ =0x0000C1FF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _08008D80 @ =0x02002200\n\
	ldr r1, _08008D84 @ =0x000007D4\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsrs r5, r0, #8\n\
	cmp r5, #0xff\n\
	beq _08008CD2\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0xff\n\
	beq _08008CD2\n\
	lsls r5, r5, #2\n\
	ldr r2, _08008D88 @ =0x087044B0\n\
	adds r5, r5, r2\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	lsls r4, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #2\n\
	adds r0, r0, r4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl loadGraphic\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	adds r0, r0, r4\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl transferPalette\n\
_08008CD2:\n\
	ldr r0, _08008D80 @ =0x02002200\n\
	ldr r1, _08008D8C @ =0x000007D6\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsrs r5, r0, #8\n\
	cmp r5, #0xff\n\
	beq _08008D10\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0xff\n\
	beq _08008D10\n\
	lsls r5, r5, #2\n\
	ldr r2, _08008D88 @ =0x087044B0\n\
	adds r5, r5, r2\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	lsls r4, r1, #2\n\
	adds r4, r4, r1\n\
	lsls r4, r4, #2\n\
	adds r0, r0, r4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl loadGraphic\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	adds r0, r0, r4\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl transferPalette\n\
_08008D10:\n\
	ldr r5, _08008D78 @ =0x02002140\n\
	ldr r4, _08008D80 @ =0x02002200\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	adds r1, r4, #0\n\
	adds r1, #0x5c\n\
	movs r3, #2\n\
_08008D1E:\n\
	ldr r0, [r1]\n\
	adds r0, r0, r2\n\
	str r0, [r1]\n\
	ldr r0, [r1, #4]\n\
	adds r0, r0, r2\n\
	str r0, [r1, #4]\n\
	ldr r0, [r1, #0x18]\n\
	adds r0, r0, r2\n\
	str r0, [r1, #0x18]\n\
	ldr r0, [r1, #0x1c]\n\
	adds r0, r0, r2\n\
	str r0, [r1, #0x1c]\n\
	adds r1, #0x88\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _08008D1E\n\
	ldrh r0, [r5]\n\
	ldr r1, _08008D90 @ =0x0000F0FF\n\
	ands r1, r0\n\
	movs r2, #0xfb\n\
	lsls r2, r2, #3\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	orrs r1, r0\n\
	strh r1, [r5]\n\
	ldr r1, _08008D94 @ =0x000007DA\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	strh r0, [r5, #6]\n\
	adds r2, #4\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r5, #8]\n\
	adds r1, #4\n\
	adds r0, r4, r1\n\
	ldrh r0, [r0]\n\
	strh r0, [r5, #0xa]\n\
	ldr r2, _08008D98 @ =0x0002C002\n\
	adds r1, r4, r2\n\
	movs r0, #1\n\
	strh r0, [r1]\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008D78: .4byte 0x02002140\n\
_08008D7C: .4byte 0x0000C1FF\n\
_08008D80: .4byte 0x02002200\n\
_08008D84: .4byte 0x000007D4\n\
_08008D88: .4byte 0x087044B0\n\
_08008D8C: .4byte 0x000007D6\n\
_08008D90: .4byte 0x0000F0FF\n\
_08008D94: .4byte 0x000007DA\n\
_08008D98: .4byte 0x0002C002\n\
   .syntax divided\n");
}

/*
  処理内容:
    1. stageFuncの配列(例: 0833b208) の idx=3の関数を実行
    2. 02002220 の3要素について、 fn_08 が null じゃないなら fn_08 を実行

  エスケープ時やステージクリア時に実行される
  ベースからステージへの転送では実行されない(ベースで死ぬと実行されるが)
*/
NAKED void runStageExitScript(void) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	ldr r1, _08008DFC @ =0x020023C8\n\
	ldr r0, [r1]\n\
	asrs r0, r0, #8\n\
	subs r0, #0x78\n\
	lsls r0, r0, #8\n\
	str r0, [sp]\n\
	ldr r0, [r1, #4]\n\
	asrs r0, r0, #8\n\
	subs r0, #0x50\n\
	lsls r0, r0, #8\n\
	str r0, [sp, #4]\n\
	ldrh r1, [r1, #8]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	ldr r1, _08008E00 @ =0x0833A2E8\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	ldr r0, [r6, #4]\n\
	ldr r1, [r0, #0xc]\n\
	mov r0, sp\n\
	bl _call_via_r1\n\
	movs r5, #0\n\
	movs r4, #2\n\
_08008DD2:\n\
	ldr r0, _08008E04 @ =0x02002220\n\
	adds r0, r5, r0\n\
	ldr r2, [r0, #8]\n\
	cmp r2, #0\n\
	beq _08008DE2\n\
	adds r1, r6, #0\n\
	bl _call_via_r2\n\
_08008DE2:\n\
	adds r5, #0x88\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _08008DD2\n\
	ldr r2, _08008E08 @ =0x02002140\n\
	ldrh r1, [r2]\n\
	ldr r0, _08008E0C @ =0x0000C1FF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008DFC: .4byte 0x020023C8\n\
_08008E00: .4byte 0x0833A2E8\n\
_08008E04: .4byte 0x02002220\n\
_08008E08: .4byte 0x02002140\n\
_08008E0C: .4byte 0x0000C1FF\n\
   .syntax divided\n");
}

/*
  (x, y)のタイルブロックのIDを入手する
*/
NAKED u16 getBlockID(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {lr}\n\
	asrs r3,r0,#0xc\n\
	asrs r2,r1,#0xc\n\
	movs r0,#0xee\n\
	lsls r0,r0,#0x3\n\
	cmp r3,r0\n\
	bhi _08008e28\n\
	cmp r2,#0x0\n\
	blt _08008e28\n\
	ldr r0, _08008e30\n\
	cmp r2,r0\n\
	ble _08008e34\n\
_08008e28:\n\
	movs r0,#0x1\n\
	rsbs r0,r0,#0\n\
	b _08008e4c\n\
	.align 2, 0\n\
_08008e30: .4byte 0x4F5\n\
_08008e34:\n\
	ldr r1, _08008e50\n\
	movs r0,#0xfc\n\
	lsls r0,r0,#0x3\n\
	adds r1,r1,r0\n\
	ldrh r0,[r1,#0x0]\n\
	muls r0,r2\n\
	adds r0,r0,r3\n\
	adds r0,r0,#0x2\n\
	lsls r0,r0,#0x1\n\
	adds r0,r0,r1\n\
	movs r1,#0x0\n\
	ldrsh r0,[r0,r1]\n\
_08008e4c:\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08008e50: .4byte 0x02002200\n\
	 .syntax divided\n");
}

/*
  (x, y)のタイルブロックのBlockAttrを取得する
*/
NAKED struct BlockAttr getBlockAttr(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	asrs r4, r0, #0xc\n\
	asrs r3, r1, #0xc\n\
	movs r0, #0xee\n\
	lsls r0, r0, #3\n\
	cmp r4, r0\n\
	bhi _08008E6C\n\
	cmp r3, #0\n\
	blt _08008E6C\n\
	ldr r0, _08008E70 @ =0x000004F5\n\
	cmp r3, r0\n\
	ble _08008E78\n\
_08008E6C:\n\
	ldr r0, _08008E74 @ =0x00000A01\n\
	b _08008E96\n\
	.align 2, 0\n\
_08008E70: .4byte 0x000004F5\n\
_08008E74: .4byte 0x00000A01\n\
_08008E78:\n\
	ldr r2, _08008E9C @ =0x020023B8\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r1, r2, r0\n\
	ldrh r0, [r1]\n\
	muls r0, r3, r0\n\
	adds r0, r0, r4\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
_08008E96:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08008E9C: .4byte 0x020023B8\n\
	 .syntax divided\n");
}

bool8 FUN_08008ea0(s32 x, s32 y) {
  u32 a = FUN_080094f0(x, y);
  y = 0;
  return ((a << 0x18) >> 0x18) == 0xF0;
}

void FUN_08008eb8(s32 x, s32 y, struct Coord* c) {
  s32 bx, by;
  bx = (x >> 0xc);
  by = (y >> 0xc);
  c->x = bx * 0x1000 - x;
  c->y = by * 0x1000 - y;
  return;
}

NAKED void FUN_08008ed0(struct Coord* c1, struct Coord* c2) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r5, r0, #0\n\
	adds r6, r1, #0\n\
	movs r0, #0\n\
	str r0, [r6, #4]\n\
	str r0, [r6]\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	bl FUN_080094f0\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	mov r8, r7\n\
	ldr r0, [r5]\n\
	ldr r1, _08008F94 @ =0xFFFF8800\n\
	adds r0, r0, r1\n\
	ldr r1, [r5, #4]\n\
	bl FUN_080094f0\n\
	subs r0, #1\n\
	subs r0, r7, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _08008F18\n\
	ldr r4, [r6]\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #7\n\
	adds r4, r4, r1\n\
	ldr r0, [r5]\n\
	bl __modsi3\n\
	subs r4, r4, r0\n\
	str r4, [r6]\n\
_08008F18:\n\
	ldr r0, [r5]\n\
	movs r4, #0xf0\n\
	lsls r4, r4, #7\n\
	adds r0, r0, r4\n\
	ldr r1, [r5, #4]\n\
	bl FUN_080094f0\n\
	subs r0, #1\n\
	subs r0, r7, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _08008F40\n\
	ldr r0, [r5]\n\
	adds r1, r4, #0\n\
	bl __modsi3\n\
	ldr r1, [r6]\n\
	subs r1, r1, r0\n\
	str r1, [r6]\n\
_08008F40:\n\
	cmp r7, #0xd\n\
	bhi _08008F9C\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	ldr r2, _08008F98 @ =0xFFFFB000\n\
	adds r1, r1, r2\n\
	bl FUN_080094f0\n\
	subs r0, #1\n\
	subs r0, r7, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _08008F6E\n\
	ldr r4, [r6, #4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #7\n\
	adds r4, r4, r1\n\
	ldr r0, [r5, #4]\n\
	bl __modsi3\n\
	subs r4, r4, r0\n\
	str r4, [r6, #4]\n\
_08008F6E:\n\
	ldr r0, [r5]\n\
	ldr r1, [r5, #4]\n\
	movs r4, #0xa0\n\
	lsls r4, r4, #7\n\
	adds r1, r1, r4\n\
	bl FUN_080094f0\n\
	subs r0, #1\n\
	subs r0, r7, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _08008FC2\n\
	ldr r0, [r5, #4]\n\
	adds r1, r4, #0\n\
	bl __modsi3\n\
	ldr r1, [r6, #4]\n\
	b _08008FBE\n\
	.align 2, 0\n\
_08008F94: .4byte 0xFFFF8800\n\
_08008F98: .4byte 0xFFFFB000\n\
_08008F9C:\n\
	mov r0, r8\n\
	cmp r0, #0xe\n\
	bne _08008FB2\n\
	ldr r0, [r5, #4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #8\n\
	bl __modsi3\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	b _08008FBE\n\
_08008FB2:\n\
	ldr r0, [r5, #4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #8\n\
	bl __modsi3\n\
	ldr r1, _08008FCC @ =0xFFFFB000\n\
_08008FBE:\n\
	subs r1, r1, r0\n\
	str r1, [r6, #4]\n\
_08008FC2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08008FCC: .4byte 0xFFFFB000\n\
	 .syntax divided\n");
}

/*
  ステージの ブロックマップ=地形データ を読み込む関数
  例:
    r0 = 0x08347268
    r1 = 0x08346ab0
*/
NAKED void loadStageTerrain(struct Stage* p, struct ScreenMap* maps) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x2c\n\
	mov r8, r1\n\
	ldr r3, _080090BC @ =0x020029E0\n\
	ldrb r1, [r1]\n\
	mov r4, r8\n\
	ldrb r2, [r4, #2]\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov sb, r1\n\
	ldrb r1, [r4, #1]\n\
	str r1, [sp, #0x10]\n\
	ldrb r4, [r4, #3]\n\
	movs r1, #4\n\
	add r8, r1\n\
	ldr r1, [r0, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r0, r0, r1\n\
	str r0, [sp, #8]\n\
	adds r7, r2, #0\n\
	lsls r0, r7, #4\n\
	subs r0, r0, r7\n\
	strh r0, [r3]\n\
	adds r3, #4\n\
	adds r6, r0, #0\n\
	lsls r1, r6, #2\n\
	adds r1, r1, r6\n\
	lsls r1, r1, #1\n\
	movs r0, #0xf\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
	ldr r2, [sp, #0x10]\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, [sp, #8]\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r1, r0, #0x10\n\
	orrs r0, r1\n\
	str r0, [sp]\n\
	ldr r2, _080090C0 @ =0x0100AE08\n\
	mov r0, sp\n\
	adds r1, r3, #0\n\
	str r3, [sp, #0x28]\n\
	bl CpuFastSet\n\
	movs r5, #0\n\
	lsls r0, r4, #0x10\n\
	ldr r3, [sp, #0x28]\n\
	cmp r5, r4\n\
	bge _080090FA\n\
	str r7, [sp, #0x1c]\n\
	str r0, [sp, #0x20]\n\
	mov r2, sb\n\
	lsls r0, r2, #0x10\n\
	mov sl, r6\n\
	asrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
_08009058:\n\
	movs r2, #0\n\
	lsls r5, r5, #0x10\n\
	str r5, [sp, #0x24]\n\
	ldr r4, [sp, #0x1c]\n\
	cmp r2, r4\n\
	bge _080090D8\n\
	ldr r0, [sp, #0x10]\n\
	str r0, [sp, #0x14]\n\
_08009068:\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	movs r4, #1\n\
	add r8, r4\n\
	ldr r1, [sp, #0x14]\n\
	cmp r0, r1\n\
	beq _080090C4\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r0, r1, #4\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r1, [sp, #8]\n\
	adds r4, r1, r0\n\
	movs r6, #0\n\
	ldr r0, [sp, #0xc]\n\
	lsls r0, r0, #0x10\n\
	mov sb, r0\n\
	lsls r5, r2, #0x10\n\
	mov r1, sl\n\
	lsls r7, r1, #1\n\
_08009092:\n\
	adds r0, r4, #0\n\
	adds r1, r3, #0\n\
	movs r2, #0x1e\n\
	str r3, [sp, #0x28]\n\
	bl transferMax30Bytes\n\
	ldr r3, [sp, #0x28]\n\
	adds r3, r3, r7\n\
	adds r4, #0x1e\n\
	lsls r0, r6, #0x10\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r0, r2\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	ble _08009092\n\
	mov r4, sb\n\
	asrs r0, r4, #0xf\n\
	adds r3, r3, r0\n\
	b _080090C8\n\
	.align 2, 0\n\
_080090BC: .4byte 0x020029E0\n\
_080090C0: .4byte 0x0100AE08\n\
_080090C4:\n\
	adds r3, #0x1e\n\
	lsls r5, r2, #0x10\n\
_080090C8:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r5, r1\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	ldr r4, [sp, #0x1c]\n\
	cmp r0, r4\n\
	blt _08009068\n\
_080090D8:\n\
	ldr r0, [sp, #0x18]\n\
	add r8, r0\n\
	mov r1, sl\n\
	lsls r0, r1, #3\n\
	add r0, sl\n\
	lsls r0, r0, #1\n\
	adds r3, r3, r0\n\
	ldr r2, [sp, #0x24]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #9\n\
	adds r1, r2, r4\n\
	lsrs r5, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r2, [sp, #0x20]\n\
	asrs r0, r2, #0x10\n\
	cmp r1, r0\n\
	blt _08009058\n\
_080090FA:\n\
	ldr r0, _08009118 @ =0x02002200\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #0xa\n\
	adds r0, r0, r4\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	add sp, #0x2c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08009118: .4byte 0x02002200\n\
	 .syntax divided\n");
}

// (s.x, s.row+s.y) -> (x, s.row+y) にブロックをずらす
NAKED void shiftTerrain(s32 x, s32 y, struct TerrainShift* s) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r2, #0\n\
	ldr r4, _080091A4 @ =0x02002200\n\
	movs r3, #0xe8\n\
	lsls r3, r3, #1\n\
	adds r2, r4, r3\n\
	ldrb r3, [r2]\n\
	movs r2, #0x7f\n\
	ands r2, r3\n\
	ldr r3, _080091A8 @ =0x0833A2E8\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r3\n\
	ldr r2, [r2]\n\
	ldr r3, _080091AC @ =0x000007E4\n\
	adds r7, r4, r3\n\
	mov r8, r7\n\
	ldr r2, [r2, #0xc]\n\
	ldrb r3, [r2, #2]\n\
	lsls r2, r3, #4\n\
	subs r3, r2, r3\n\
	movs r4, #6\n\
	ldrsh r2, [r6, r4]\n\
	adds r1, r1, r2\n\
	muls r1, r3, r1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #1\n\
	adds r7, r1, r7\n\
	movs r1, #2\n\
	ldrsh r0, [r6, r1]\n\
	adds r0, r0, r2\n\
	muls r0, r3, r0\n\
	movs r4, #0\n\
	ldrsh r1, [r6, r4]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	add r8, r0\n\
	movs r5, #0\n\
	cmp r5, r2\n\
	bge _0800918E\n\
	lsls r4, r3, #1\n\
_08009170:\n\
	subs r7, r7, r4\n\
	mov r0, r8\n\
	subs r0, r0, r4\n\
	mov r8, r0\n\
	movs r1, #4\n\
	ldrsh r2, [r6, r1]\n\
	lsls r2, r2, #1\n\
	adds r1, r7, #0\n\
	bl transferMax30Bytes\n\
	adds r5, #1\n\
	movs r3, #6\n\
	ldrsh r0, [r6, r3]\n\
	cmp r5, r0\n\
	blt _08009170\n\
_0800918E:\n\
	ldr r0, _080091A4 @ =0x02002200\n\
	movs r4, #0xb0\n\
	lsls r4, r4, #0xa\n\
	adds r0, r0, r4\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080091A4: .4byte 0x02002200\n\
_080091A8: .4byte 0x0833A2E8\n\
_080091AC: .4byte 0x000007E4\n\
	 .syntax divided\n");
}

/*
  ステージのブロックマップ (x, y)から(x+p.w, y+p.h) の内容を変更する

  x, y は ブロック単位
  つまり、ピクセルで言うとステージの左上(0, 0)から(x*16, y*16)離れたところ
*/
NAKED void patchBlockMap(u32 x, u32 y, struct TerrainPatch* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r5, r2, #0\n\
	ldr r4, _08009244 @ =0x02002200\n\
	movs r3, #0xe8\n\
	lsls r3, r3, #1\n\
	adds r2, r4, r3\n\
	ldrb r3, [r2]\n\
	movs r2, #0x7f\n\
	ands r2, r3\n\
	ldr r3, _08009248 @ =0x0833A2E8\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r3\n\
	ldr r3, [r2]\n\
	ldr r2, _0800924C @ =0x000007E4\n\
	adds r7, r4, r2\n\
	ldrh r2, [r5]\n\
	lsls r2, r2, #0x11\n\
	lsrs r6, r2, #0x10\n\
	adds r5, #2\n\
	ldrh r2, [r5]\n\
	mov r8, r2\n\
	adds r5, #2\n\
	ldr r2, [r3, #0xc]\n\
	ldrb r3, [r2, #2]\n\
	lsls r2, r3, #4\n\
	subs r2, r2, r3\n\
	muls r1, r2, r1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #1\n\
	adds r7, r1, r7\n\
	mov r3, r8\n\
	lsls r0, r3, #0x10\n\
	movs r4, #0\n\
	cmp r0, #0\n\
	ble _08009228\n\
	lsls r6, r6, #0x10\n\
	asrs r0, r6, #0x10\n\
	mov sl, r0\n\
	lsls r2, r2, #1\n\
	mov sb, r2\n\
_08009208:\n\
	adds r0, r5, #0\n\
	adds r1, r7, #0\n\
	asrs r2, r6, #0x10\n\
	bl transferMax30Bytes\n\
	add r5, sl\n\
	add r7, sb\n\
	lsls r1, r4, #0x10\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r1, r1, r2\n\
	lsrs r4, r1, #0x10\n\
	mov r3, r8\n\
	lsls r0, r3, #0x10\n\
	cmp r1, r0\n\
	blt _08009208\n\
_08009228:\n\
	ldr r0, _08009244 @ =0x02002200\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08009244: .4byte 0x02002200\n\
_08009248: .4byte 0x0833A2E8\n\
_0800924C: .4byte 0x000007E4\n\
	 .syntax divided\n");
}

/**
 * @fn loadScreenIntoBlockMap(s32, s32, u32)
 * @brief Screen構造体を wStage.bm にロードする
 * @param screen 08649444 とかの Screen[] の idx
 * @note 0x08009250
 */
NAKED void loadScreenIntoBlockMap(s32 x, s32 y, u32 screen) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	ldr r5, _080092D4 @ =0x02002200\n\
	movs r4, #0xe8\n\
	lsls r4, r4, #1\n\
	adds r3, r5, r4\n\
	ldrb r4, [r3]\n\
	movs r3, #0x7f\n\
	ands r3, r4\n\
	ldr r4, _080092D8 @ =0x0833A2E8\n\
	lsls r3, r3, #2\n\
	adds r3, r3, r4\n\
	ldr r6, [r3]\n\
	ldr r3, _080092DC @ =0x000007E4\n\
	adds r5, r5, r3\n\
	ldr r4, [r6, #8]\n\
	ldr r3, [r4, #8]\n\
	adds r4, r3, r4\n\
	lsls r3, r2, #2\n\
	adds r3, r3, r2\n\
	lsls r2, r3, #4\n\
	subs r2, r2, r3\n\
	lsls r2, r2, #2\n\
	adds r4, r4, r2\n\
	ldr r2, [r6, #0xc]\n\
	ldrb r2, [r2, #2]\n\
	lsls r3, r2, #4\n\
	subs r3, r3, r2\n\
	adds r2, r3, #0\n\
	muls r2, r1, r2\n\
	lsls r1, r2, #2\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #1\n\
	lsls r2, r0, #4\n\
	subs r2, r2, r0\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #1\n\
	adds r5, r1, r5\n\
	movs r6, #0\n\
	lsls r7, r3, #1\n\
_080092A2:\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	movs r2, #0x1e\n\
	bl transferMax30Bytes\n\
	adds r5, r5, r7\n\
	adds r4, #0x1e\n\
	lsls r0, r6, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #9\n\
	adds r0, r0, r1\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #9\n\
	ble _080092A2\n\
	ldr r0, _080092D4 @ =0x02002200\n\
	movs r3, #0xb0\n\
	lsls r3, r3, #0xa\n\
	adds r0, r0, r3\n\
	movs r1, #1\n\
	strh r1, [r0]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080092D4: .4byte 0x02002200\n\
_080092D8: .4byte 0x0833A2E8\n\
_080092DC: .4byte 0x000007E4\n\
	 .syntax divided\n");
}

/**
 * @fn resetStageBg(s32 n, struct Stage* p)
 * @brief wStage.bgs[n]をリセットする
 * @param n 0(BG1) or 1(BG2) or 2(BG3)
 * @note 0x080092e0
 */
NAKED void resetStageBg(s32 n, struct Stage* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #8\n\
	adds r3, r0, #0\n\
	adds r5, r1, #0\n\
	lsls r0, r3, #4\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #3\n\
	ldr r1, _0800934C @ =0x02002220\n\
	mov r8, r1\n\
	add r0, r8\n\
	mov ip, r0\n\
	ldr r2, [r5, #8]\n\
	movs r0, #0\n\
	movs r1, #0\n\
	mov r4, ip\n\
	strh r3, [r4, #0xc]\n\
	strb r0, [r4, #0xf]\n\
	strb r0, [r4, #0xe]\n\
	strh r1, [r4, #0x12]\n\
	strh r1, [r4, #0x10]\n\
	adds r4, #0x34\n\
	ldr r0, _08009350 @ =0x80000001\n\
	mov r6, ip\n\
	str r0, [r6, #0x40]\n\
	str r0, [r6, #0x3c]\n\
	str r0, [r4, #4]\n\
	str r0, [r6, #0x34]\n\
	str r0, [r6, #0x58]\n\
	str r0, [r6, #0x54]\n\
	str r1, [r6]\n\
	movs r0, #1\n\
	str r0, [r6, #4]\n\
	str r1, [r6, #8]\n\
	ldr r0, [r2]\n\
	adds r7, r0, r2\n\
	ldr r0, [r2, #8]\n\
	adds r6, r0, r2\n\
	cmp r3, #0\n\
	bne _08009358\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	ldr r2, _08009354 @ =0x0002C004\n\
	add r2, r8\n\
	str r6, [sp]\n\
	ldr r1, [r5, #0xc]\n\
	str r1, [sp, #4]\n\
	adds r1, r4, #0\n\
	adds r3, r7, #0\n\
	bl FUN_08005088\n\
	b _0800938E\n\
	.align 2, 0\n\
_0800934C: .4byte 0x02002220\n\
_08009350: .4byte 0x80000001\n\
_08009354: .4byte 0x0002C004\n\
_08009358:\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	mov r2, ip\n\
	ldr r1, [r2, #0x5c]\n\
	lsrs r1, r1, #4\n\
	lsls r1, r1, #1\n\
	ldr r2, _0800939C @ =0x02002144\n\
	adds r1, r1, r2\n\
	ldrh r1, [r1]\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r2, r1\n\
	lsls r2, r2, #3\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	adds r2, r2, r1\n\
	str r6, [sp]\n\
	lsls r3, r3, #2\n\
	adds r1, r5, #0\n\
	adds r1, #0xc\n\
	adds r1, r1, r3\n\
	ldr r1, [r1]\n\
	str r1, [sp, #4]\n\
	adds r1, r4, #0\n\
	adds r3, r7, #0\n\
	bl FUN_08005088\n\
_0800938E:\n\
	add sp, #8\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800939C: .4byte 0x02002144\n\
_080093A0:\n\
	.byte 0x01, 0x01, 0x09, 0x18, 0xC9, 0x00, 0x03, 0x48, 0x09, 0x18, 0x00, 0x20, 0x08, 0x60, 0x48, 0x60\n\
	.byte 0x70, 0x47, 0x00, 0x00, 0x20, 0x22, 0x00, 0x02\n\
	 .syntax divided\n");
}

NAKED void variousStageFunc_080093b8(struct StageBg* p) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #8\n\
	adds r7, r0, #0\n\
	movs r0, #0x14\n\
	adds r0, r0, r7\n\
	mov r8, r0\n\
	ldr r0, [r7, #0x34]\n\
	ldr r1, [r7, #0x44]\n\
	adds r3, r0, #0\n\
	muls r3, r1, r3\n\
	asrs r3, r3, #8\n\
	ldr r0, [r7, #0x4c]\n\
	adds r3, r3, r0\n\
	ldr r0, [r7, #0x38]\n\
	ldr r4, [r7, #0x48]\n\
	adds r2, r0, #0\n\
	muls r2, r4, r2\n\
	asrs r2, r2, #8\n\
	ldr r0, [r7, #0x50]\n\
	adds r2, r2, r0\n\
	ldr r0, [r7, #0x3c]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r7, #0x54]\n\
	adds r5, r0, r1\n\
	ldr r0, [r7, #0x40]\n\
	muls r0, r4, r0\n\
	asrs r0, r0, #8\n\
	ldr r1, [r7, #0x58]\n\
	adds r6, r0, r1\n\
	subs r0, r3, r5\n\
	adds r1, r0, #0\n\
	adds r1, #0xf\n\
	subs r0, r2, r6\n\
	adds r4, r0, #0\n\
	adds r4, #0xf\n\
	ldr r0, [r7, #0x2c]\n\
	asrs r0, r0, #8\n\
	adds r0, r0, r3\n\
	str r0, [sp]\n\
	ldr r0, [r7, #0x30]\n\
	asrs r0, r0, #8\n\
	adds r0, r0, r2\n\
	str r0, [sp, #4]\n\
	ldrh r0, [r7, #0xc]\n\
	cmp r0, #0\n\
	beq _08009474\n\
	cmp r1, #0x1e\n\
	bhi _08009422\n\
	cmp r4, #0x1e\n\
	bls _0800944C\n\
_08009422:\n\
	ldr r0, [r7, #0x5c]\n\
	lsrs r0, r0, #4\n\
	lsls r0, r0, #1\n\
	ldr r1, _08009448 @ =0x02002144\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r2, r0\n\
	lsls r2, r2, #3\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	mov r0, r8\n\
	mov r1, sp\n\
	bl FUN_08005a70\n\
	b _080094C6\n\
	.align 2, 0\n\
_08009448: .4byte 0x02002144\n\
_0800944C:\n\
	ldr r0, [r7, #0x5c]\n\
	lsrs r0, r0, #4\n\
	lsls r0, r0, #1\n\
	ldr r1, _08009470 @ =0x02002144\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	movs r2, #0xf8\n\
	lsls r2, r2, #5\n\
	ands r2, r0\n\
	lsls r2, r2, #3\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	adds r2, r2, r0\n\
	mov r0, r8\n\
	mov r1, sp\n\
	bl FUN_080050b0\n\
	b _080094C6\n\
	.align 2, 0\n\
_08009470: .4byte 0x02002144\n\
_08009474:\n\
	cmp r1, #0x1e\n\
	bhi _0800948A\n\
	cmp r4, #0x1e\n\
	bhi _0800948A\n\
	ldr r3, _0800949C @ =0x02002200\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #0xa\n\
	adds r0, r3, r1\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	beq _080094A8\n\
_0800948A:\n\
	ldr r2, _080094A0 @ =0x0202E224\n\
	ldr r0, _080094A4 @ =0xFFFD47BC\n\
	adds r3, r2, r0\n\
	mov r0, r8\n\
	mov r1, sp\n\
	bl FUN_08006a10\n\
	b _080094BA\n\
	.align 2, 0\n\
_0800949C: .4byte 0x02002200\n\
_080094A0: .4byte 0x0202E224\n\
_080094A4: .4byte 0xFFFD47BC\n\
_080094A8:\n\
	ldr r1, _080094E4 @ =0x0002C024\n\
	adds r2, r3, r1\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #3\n\
	adds r3, r3, r0\n\
	mov r0, r8\n\
	mov r1, sp\n\
	bl FUN_08006bb4\n\
_080094BA:\n\
	ldr r0, _080094E8 @ =0x02002200\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #0xa\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
_080094C6:\n\
	ldr r1, [r7, #0x5c]\n\
	lsrs r1, r1, #4\n\
	lsls r1, r1, #2\n\
	ldr r0, _080094EC @ =0x0200214C\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	bl FUN_08006dac\n\
	add sp, #8\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080094E4: .4byte 0x0002C024\n\
_080094E8: .4byte 0x02002200\n\
_080094EC: .4byte 0x0200214C\n\
	 .syntax divided\n");
}

NAKED u32 FUN_080094f0(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r1, #0\n\
	cmp r4, #0\n\
	blt _0800950A\n\
	cmp r5, #0\n\
	blt _0800950A\n\
	ldr r0, _08009510 @ =0x00770FFF\n\
	cmp r4, r0\n\
	bgt _0800950A\n\
	ldr r0, _08009514 @ =0x004F5FFF\n\
	cmp r5, r0\n\
	ble _08009518\n\
_0800950A:\n\
	movs r0, #0xf\n\
	b _08009554\n\
	.align 2, 0\n\
_08009510: .4byte 0x00770FFF\n\
_08009514: .4byte 0x004F5FFF\n\
_08009518:\n\
	ldr r2, _0800955C @ =0x0833A2E8\n\
	ldr r0, _08009560 @ =0x02002200\n\
	movs r1, #0xe8\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r3, [r0]\n\
	ldr r0, _08009564 @ =0x083396E8\n\
	asrs r1, r4, #0xc\n\
	adds r1, r1, r0\n\
	ldr r2, _08009568 @ =0x08338EE8\n\
	asrs r0, r5, #0xc\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	ldr r2, [r3, #0x74]\n\
	ldrh r3, [r2]\n\
	lsls r0, r3\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0, #8]\n\
	lsrs r0, r0, #0xc\n\
	cmp r0, #0xf\n\
	bne _08009554\n\
	movs r0, #0xf0\n\
_08009554:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0800955C: .4byte 0x0833A2E8\n\
_08009560: .4byte 0x02002200\n\
_08009564: .4byte 0x083396E8\n\
_08009568: .4byte 0x08338EE8\n\
	 .syntax divided\n");
}

NAKED struct Stage* loadStageTileset_0800956c(struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	ldr r3, _080095DC @ =0x02002200\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #1\n\
	adds r1, r3, r2\n\
	ldrh r1, [r1]\n\
	movs r4, #0x7f\n\
	mov r8, r4\n\
	mov r2, r8\n\
	ands r2, r1\n\
	mov r8, r2\n\
	ldr r2, _080095E0 @ =0x0833A2E8\n\
	mov r4, r8\n\
	lsls r1, r4, #2\n\
	adds r1, r1, r2\n\
	ldr r1, [r1]\n\
	mov sb, r1\n\
	ldr r1, [r0]\n\
	ldr r0, [r0, #4]\n\
	ldr r2, _080095E4 @ =0x083396E8\n\
	asrs r1, r1, #0xc\n\
	adds r1, r1, r2\n\
	ldrb r2, [r1]\n\
	ldr r1, _080095E8 @ =0x08338EE8\n\
	asrs r0, r0, #0xc\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	mov r4, sb\n\
	ldr r1, [r4, #0x6c]\n\
	ldrb r4, [r1, #2]\n\
	cmp r2, r4\n\
	bhs _0800969C\n\
	ldrb r4, [r1, #3]\n\
	cmp r0, r4\n\
	bhs _0800969C\n\
	ldrb r4, [r1]\n\
	lsls r0, r4\n\
	adds r0, r0, r2\n\
	adds r0, r0, r1\n\
	ldrb r7, [r0, #4]\n\
	lsrs r2, r7, #4\n\
	ldr r1, _080095EC @ =0x000007D4\n\
	adds r0, r3, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, r8\n\
	bne _080095F0\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _080095F4\n\
	b _0800962E\n\
	.align 2, 0\n\
_080095DC: .4byte 0x02002200\n\
_080095E0: .4byte 0x0833A2E8\n\
_080095E4: .4byte 0x083396E8\n\
_080095E8: .4byte 0x08338EE8\n\
_080095EC: .4byte 0x000007D4\n\
_080095F0:\n\
	cmp r2, #0xff\n\
	beq _0800962E\n\
_080095F4:\n\
	mov r2, r8\n\
	lsls r5, r2, #2\n\
	ldr r4, _0800964C @ =0x087044B0\n\
	adds r5, r5, r4\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	lsrs r6, r7, #4\n\
	lsls r4, r6, #2\n\
	adds r4, r4, r6\n\
	lsls r4, r4, #2\n\
	adds r0, r0, r4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl appendGraphicTask\n\
	ldr r0, [r5]\n\
	adds r0, r0, r5\n\
	adds r0, r0, r4\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl transferPalette\n\
	ldr r0, _08009650 @ =0x02002200\n\
	mov r2, r8\n\
	lsls r1, r2, #8\n\
	orrs r6, r1\n\
	ldr r4, _08009654 @ =0x000007D4\n\
	adds r0, r0, r4\n\
	strh r6, [r0]\n\
_0800962E:\n\
	movs r2, #0xf\n\
	ands r2, r7\n\
	ldr r0, _08009650 @ =0x02002200\n\
	ldr r1, _08009658 @ =0x000007D6\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	lsrs r0, r1, #8\n\
	cmp r0, r8\n\
	bne _0800965C\n\
	movs r0, #0xff\n\
	ands r0, r1\n\
	cmp r2, r0\n\
	bne _08009660\n\
	b _0800969C\n\
	.align 2, 0\n\
_0800964C: .4byte 0x087044B0\n\
_08009650: .4byte 0x02002200\n\
_08009654: .4byte 0x000007D4\n\
_08009658: .4byte 0x000007D6\n\
_0800965C:\n\
	cmp r2, #0xff\n\
	beq _0800969C\n\
_08009660:\n\
	mov r2, r8\n\
	lsls r6, r2, #2\n\
	ldr r4, _080096AC @ =0x087044B0\n\
	adds r6, r6, r4\n\
	ldr r0, [r6]\n\
	adds r0, r0, r6\n\
	movs r5, #0xf\n\
	ands r5, r7\n\
	lsls r4, r5, #2\n\
	adds r4, r4, r5\n\
	lsls r4, r4, #2\n\
	adds r0, r0, r4\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	bl appendGraphicTask\n\
	ldr r0, [r6]\n\
	adds r0, r0, r6\n\
	adds r0, r0, r4\n\
	adds r0, #0xc\n\
	movs r1, #0\n\
	bl transferPalette\n\
	ldr r0, _080096B0 @ =0x02002200\n\
	mov r2, r8\n\
	lsls r1, r2, #8\n\
	orrs r5, r1\n\
	ldr r4, _080096B4 @ =0x000007D6\n\
	adds r0, r0, r4\n\
	strh r5, [r0]\n\
_0800969C:\n\
	mov r0, sb\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080096AC: .4byte 0x087044B0\n\
_080096B0: .4byte 0x02002200\n\
_080096B4: .4byte 0x000007D6\n\
 .syntax divided\n");
}

/**
 * @brief stageFunc の idx 2　を呼び出す(例: 0x08016379)
 * @note 0x080096B8
 */
NAKED void FUN_080096b8(struct StageBg* p, u32 r1) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r1, #0\n\
	ldr r0, _0800973C @ =0x02002200\n\
	movs r1, #0xe8\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	ldr r1, _08009740 @ =0x0833A2E8\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldr r0, [r7, #4]\n\
	ldr r1, [r0, #8]\n\
	adds r0, r6, #0\n\
	bl _call_via_r1\n\
	movs r5, #0\n\
	movs r4, #2\n\
_080096E4:\n\
	ldr r2, _08009744 @ =0x02002220\n\
	mov r8, r2\n\
	adds r1, r5, r2\n\
	ldr r0, [r6, #0x10]\n\
	str r0, [r1, #0x2c]\n\
	ldr r0, [r6, #0x14]\n\
	str r0, [r1, #0x30]\n\
	ldr r2, [r1, #4]\n\
	cmp r2, #1\n\
	bls _08009700\n\
	adds r0, r1, #0\n\
	adds r1, r7, #0\n\
	bl _call_via_r2\n\
_08009700:\n\
	adds r5, #0x88\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _080096E4\n\
	movs r4, #0\n\
	ldr r0, _08009748 @ =0x0002C004\n\
	add r0, r8\n\
	mov r2, r8\n\
	ldr r1, [r2, #0x5c]\n\
	lsrs r1, r1, #4\n\
	lsls r1, r1, #1\n\
	ldr r2, _0800974C @ =0x02002144\n\
	adds r1, r1, r2\n\
	ldrh r2, [r1]\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #5\n\
	ands r1, r2\n\
	lsls r1, r1, #3\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	bl appendBgMapTask\n\
	ldr r0, _08009750 @ =0x0002BFE2\n\
	add r0, r8\n\
	strh r4, [r0]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800973C: .4byte 0x02002200\n\
_08009740: .4byte 0x0833A2E8\n\
_08009744: .4byte 0x02002220\n\
_08009748: .4byte 0x0002C004\n\
_0800974C: .4byte 0x02002144\n\
_08009750: .4byte 0x0002BFE2\n\
	 .syntax divided\n");
}

NAKED void FUN_08009754(struct StageBg* p, struct Stage* s, struct Coord* c) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	adds r4, r0, #0\n\
	adds r5, r1, #0\n\
	ldrh r0, [r4, #0xc]\n\
	mov sb, r0\n\
	adds r3, r4, #0\n\
	adds r3, #0x34\n\
	ldr r0, [r4, #0x34]\n\
	str r0, [r4, #0x3c]\n\
	ldr r0, [r3, #4]\n\
	str r0, [r4, #0x40]\n\
	ldr r0, [r4, #0x4c]\n\
	str r0, [r4, #0x54]\n\
	ldr r0, [r4, #0x50]\n\
	str r0, [r4, #0x58]\n\
	ldr r0, [r2]\n\
	asrs r0, r0, #8\n\
	str r0, [r4, #0x34]\n\
	ldr r1, [r2, #4]\n\
	asrs r0, r1, #8\n\
	str r0, [r3, #4]\n\
	ldr r2, _080097B0 @ =0x083396E8\n\
	ldr r0, [r4, #0x34]\n\
	asrs r0, r0, #4\n\
	adds r0, r0, r2\n\
	ldrb r2, [r0]\n\
	ldr r0, _080097B4 @ =0x08338EE8\n\
	asrs r1, r1, #0xc\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	ldr r1, [r5, #0x6c]\n\
	ldrb r3, [r1, #2]\n\
	cmp r2, r3\n\
	bhs _080097A4\n\
	ldrb r1, [r1, #3]\n\
	cmp r0, r1\n\
	blo _080097B8\n\
_080097A4:\n\
	ldr r7, [r4]\n\
	ldr r0, [r4, #4]\n\
	mov r8, r0\n\
	ldr r6, [r4, #8]\n\
	adds r0, r7, #0\n\
	b _080097E8\n\
	.align 2, 0\n\
_080097B0: .4byte 0x083396E8\n\
_080097B4: .4byte 0x08338EE8\n\
_080097B8:\n\
	ldr r1, [r5, #0x74]\n\
	ldrh r3, [r1]\n\
	lsls r0, r3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0, #8]\n\
	movs r0, #2\n\
	mov r2, sb\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	asrs r1, r0\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	ldr r2, [r5, #0x70]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r7, [r0]\n\
	ldr r3, [r0, #4]\n\
	mov r8, r3\n\
	ldr r6, [r0, #8]\n\
	ldr r0, [r4]\n\
_080097E8:\n\
	cmp r0, r7\n\
	bne _080097F2\n\
	ldr r0, [r4, #4]\n\
	cmp r0, r8\n\
	beq _0800988E\n\
_080097F2:\n\
	ldr r2, [r4, #8]\n\
	cmp r2, #0\n\
	beq _08009800\n\
	adds r0, r4, #0\n\
	adds r1, r5, #0\n\
	bl _call_via_r2\n\
_08009800:\n\
	str r7, [r4]\n\
	mov r0, r8\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	mov r2, sb\n\
	lsls r1, r2, #2\n\
	adds r0, r5, #0\n\
	adds r0, #0x18\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	str r6, [r4, #0x5c]\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	adds r0, r0, r1\n\
	ldr r3, [r0]\n\
	str r3, [r4, #0x60]\n\
	adds r0, r5, #0\n\
	adds r0, #0x30\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov ip, r0\n\
	str r0, [r4, #0x64]\n\
	lsls r1, r2, #3\n\
	adds r1, r1, r5\n\
	ldr r0, [r1, #0x3c]\n\
	str r0, [r4, #0x44]\n\
	ldr r0, [r1, #0x40]\n\
	str r0, [r4, #0x48]\n\
	ldr r0, [r1, #0x54]\n\
	str r0, [r4, #0x4c]\n\
	ldr r0, [r1, #0x58]\n\
	str r0, [r4, #0x50]\n\
	cmp r7, #0\n\
	bne _0800984A\n\
	mov r5, r8\n\
	cmp r5, #0\n\
	beq _08009870\n\
_0800984A:\n\
	lsrs r1, r6, #4\n\
	lsls r1, r1, #1\n\
	ldr r2, _08009868 @ =0x02002144\n\
	adds r1, r1, r2\n\
	mov r0, ip\n\
	orrs r3, r0\n\
	ldr r5, _0800986C @ =0x00006044\n\
	adds r0, r5, #0\n\
	orrs r3, r0\n\
	strh r3, [r1]\n\
	subs r2, #4\n\
	lsls r0, r6, #8\n\
	ldrh r1, [r2]\n\
	orrs r0, r1\n\
	b _08009878\n\
	.align 2, 0\n\
_08009868: .4byte 0x02002144\n\
_0800986C: .4byte 0x00006044\n\
_08009870:\n\
	ldr r2, _0800989C @ =0x02002140\n\
	lsls r1, r6, #8\n\
	ldrh r0, [r2]\n\
	bics r0, r1\n\
_08009878:\n\
	strh r0, [r2]\n\
	ldr r0, _080098A0 @ =0x80000001\n\
	str r0, [r4, #0x40]\n\
	str r0, [r4, #0x3c]\n\
	str r0, [r4, #0x58]\n\
	str r0, [r4, #0x54]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xf]\n\
	strb r0, [r4, #0xe]\n\
	strh r0, [r4, #0x12]\n\
	strh r0, [r4, #0x10]\n\
_0800988E:\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0800989C: .4byte 0x02002140\n\
_080098A0: .4byte 0x80000001\n\
	 .syntax divided\n");
}

NAKED s32 FUN_080098a4(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r5, r0, #0\n\
	adds r6, r1, #0\n\
	asrs r4, r5, #0xc\n\
	asrs r3, r6, #0xc\n\
	movs r0, #0xee\n\
	lsls r0, r0, #3\n\
	cmp r4, r0\n\
	bhi _080098BC\n\
	ldr r0, _080098C0 @ =0x000004F5\n\
	cmp r3, r0\n\
	bls _080098C8\n\
_080098BC:\n\
	ldr r0, _080098C4 @ =0x00000A01\n\
	b _08009922\n\
	.align 2, 0\n\
_080098C0: .4byte 0x000004F5\n\
_080098C4: .4byte 0x00000A01\n\
_080098C8:\n\
	ldr r2, _08009914 @ =0x020023B8\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r1, r2, r0\n\
	ldrh r0, [r1]\n\
	muls r0, r3, r0\n\
	adds r0, r0, r4\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldr r1, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	ldr r0, _08009918 @ =0x08338DE8\n\
	movs r2, #0xf\n\
	ands r2, r4\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r0\n\
	ldr r3, _0800991C @ =0x00000FFF\n\
	adds r0, r5, #0\n\
	ands r0, r3\n\
	adds r1, r6, #0\n\
	ands r1, r3\n\
	ldr r2, [r2]\n\
	bl _call_via_r2\n\
	cmp r0, #0\n\
	bne _08009920\n\
	adds r0, r5, #0\n\
	adds r1, r6, #0\n\
	bl blocking_0800ac18\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	b _08009922\n\
	.align 2, 0\n\
_08009914: .4byte 0x020023B8\n\
_08009918: .4byte 0x08338DE8\n\
_0800991C: .4byte 0x00000FFF\n\
_08009920:\n\
	adds r0, r4, #0\n\
_08009922:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED s32 FUN_08009928(s32 x, s32 y) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	adds r5, r1, #0\n\
	asrs r3, r6, #0xc\n\
	asrs r1, r5, #0xc\n\
	ldr r4, _0800997C @ =0x020023B8\n\
	movs r0, #0xc5\n\
	lsls r0, r0, #3\n\
	adds r2, r4, r0\n\
	ldrh r0, [r2]\n\
	muls r0, r1, r0\n\
	adds r0, r0, r3\n\
	adds r0, #2\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	adds r4, r0, #0\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _08009976\n\
	cmp r1, #1\n\
	beq _0800998A\n\
	ldr r0, _08009980 @ =0x08338DE8\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, _08009984 @ =0x00000FFF\n\
	ands r5, r0\n\
	ldr r2, [r1]\n\
	ands r0, r6\n\
	adds r1, r5, #0\n\
	bl _call_via_r2\n\
	cmp r0, #0\n\
	bne _08009988\n\
_08009976:\n\
	movs r0, #0\n\
	b _0800998A\n\
	.align 2, 0\n\
_0800997C: .4byte 0x020023B8\n\
_08009980: .4byte 0x08338DE8\n\
_08009984: .4byte 0x00000FFF\n\
_08009988:\n\
	adds r0, r4, #0\n\
_0800998A:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	 .syntax divided\n");
}

// TODO asm/stage.o
