#include "global.h"
#include "motion.h"
#include "overworld.h"
#include "weapon.h"
#include "zero.h"

static void tryCommandDash(struct Zero* z);
void handlePlayerInput(struct Zero* z);
void ClearInputHistory(struct Zero* z);

void InitPlayerKeyMap(struct Zero* z) {
  struct Zero_b4* b4;

  ClearInputHistory(z);

  b4 = &(z->unk_b4);
  if ((b4->status).keyMap.btnMode == 0) {
    (z->keyMap).jump = A_BUTTON;
    (z->keyMap).dash = L_BUTTON;
    (z->keyMap).main = B_BUTTON;
    (z->keyMap).sub = R_BUTTON;

  } else if ((b4->status).keyMap.btnMode == 1) {
    (z->keyMap).jump = A_BUTTON;
    (z->keyMap).dash = R_BUTTON;
    (z->keyMap).main = B_BUTTON;
    (z->keyMap).sub = L_BUTTON;

  } else {
    (z->keyMap).jump = (b4->status).keyMap.keys.jump;
    (z->keyMap).dash = (b4->status).keyMap.keys.dash;
    (z->keyMap).main = (b4->status).keyMap.keys.main;
    (z->keyMap).sub = (b4->status).keyMap.keys.sub;
  }
  z->zeroInput = 0;
  z->commandDashTimer = 0;

  (z->ultimateCommand_224)[0] = 0;
  (z->ultimateCommand_224)[1] = 0;

  (z->ultimateCommand_227)[0] = 0;
  (z->ultimateCommand_227)[1] = 0;

  (z->ultimateCommand_22a)[0] = 0;
  (z->ultimateCommand_22a)[1] = 0;

  (z->ultimateCommand_22c)[0] = 0;
  (z->ultimateCommand_22c)[1] = 0;
}

NAKED void HandlePlayerInput(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	adds r6, r0, #0\n\
	ldr r0, _08032FE8 @ =0x00000216\n\
	adds r0, r6, r0\n\
	str r0, [sp, #8]\n\
	ldrh r1, [r0]\n\
	mov sb, r1\n\
	adds r4, r6, #0\n\
	adds r4, #0xdc\n\
	ldrb r2, [r4]\n\
	str r2, [sp]\n\
	adds r7, r6, #0\n\
	adds r7, #0xdd\n\
	ldrb r3, [r7]\n\
	str r3, [sp, #4]\n\
	mov r8, sb\n\
	adds r0, r6, #0\n\
	bl handlePlayerInput\n\
	ldrb r0, [r4]\n\
	ldr r4, _08032FEC @ =0x00000131\n\
	adds r2, r6, r4\n\
	movs r1, #0\n\
	strb r0, [r2]\n\
	ldrb r0, [r7]\n\
	movs r3, #0x99\n\
	lsls r3, r3, #1\n\
	adds r2, r6, r3\n\
	strb r0, [r2]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r4, r6, r0\n\
	ldr r2, [r4]\n\
	mov ip, r2\n\
	str r1, [r4]\n\
	ldr r3, [sp, #8]\n\
	ldrh r2, [r3]\n\
	movs r0, #0xf0\n\
	adds r1, r0, #0\n\
	ands r1, r2\n\
	str r1, [r4]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r5, r6, r2\n\
	ldrh r2, [r5]\n\
	ands r0, r2\n\
	lsls r2, r0, #4\n\
	orrs r2, r1\n\
	str r2, [r4]\n\
	movs r3, #0x87\n\
	lsls r3, r3, #2\n\
	adds r7, r6, r3\n\
	ldr r0, [sp, #8]\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r7]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032EFC\n\
	movs r3, #2\n\
	orrs r3, r2\n\
	str r3, [r4]\n\
	ldrh r1, [r5]\n\
	ldrh r0, [r7]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032EFC\n\
	movs r0, #1\n\
	orrs r3, r0\n\
	str r3, [r4]\n\
_08032EFC:\n\
	ldr r1, _08032FE8 @ =0x00000216\n\
	adds r2, r6, r1\n\
	ldr r3, _08032FF0 @ =0x0000021E\n\
	adds r4, r6, r3\n\
	ldrh r1, [r2]\n\
	ldrh r0, [r4]\n\
	ands r0, r1\n\
	str r2, [sp, #0xc]\n\
	cmp r0, #0\n\
	beq _08032F34\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r3, r6, r0\n\
	ldr r2, [r3]\n\
	movs r0, #8\n\
	orrs r2, r0\n\
	str r2, [r3]\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldrh r1, [r0]\n\
	ldrh r0, [r4]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032F34\n\
	movs r0, #4\n\
	orrs r2, r0\n\
	str r2, [r3]\n\
_08032F34:\n\
	ldr r2, [sp, #0xc]\n\
	ldrh r4, [r2]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #8\n\
	adds r0, r5, #0\n\
	ands r0, r4\n\
	movs r3, #0xb4\n\
	adds r3, r3, r6\n\
	mov sl, r3\n\
	cmp r0, #0\n\
	bne _08032F4C\n\
	b _08033092\n\
_08032F4C:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08032F66\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r1, r6, r4\n\
	ldr r0, [r1]\n\
	orrs r0, r5\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
_08032F66:\n\
	ldr r0, [sp, #0xc]\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032F90\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r2, r6, r1\n\
	ldr r0, [r2]\n\
	movs r1, #0xc\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	ldr r2, _08032FF4 @ =0x0000022F\n\
	adds r1, r6, r2\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _08032F90\n\
	movs r0, #0x1c\n\
	strb r0, [r1]\n\
_08032F90:\n\
	ldr r3, [sp, #0xc]\n\
	ldrh r1, [r3]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #6\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08032FAE\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
	ldr r1, [r0]\n\
	movs r2, #3\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_08032FAE:\n\
	adds r0, r6, #0\n\
	adds r0, #0xd9\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _08033028\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r6, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08032FF8\n\
	mov r0, ip\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08033000\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r1, r6, r4\n\
	ldr r0, [r1]\n\
	orrs r0, r3\n\
	str r0, [r1]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08032FFE\n\
	.align 2, 0\n\
_08032FE8: .4byte 0x00000216\n\
_08032FEC: .4byte 0x00000131\n\
_08032FF0: .4byte 0x0000021E\n\
_08032FF4: .4byte 0x0000022F\n\
_08032FF8:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	movs r0, #0\n\
_08032FFE:\n\
	strb r0, [r1]\n\
_08033000:\n\
	ldrb r1, [r2]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803300C\n\
	b _08033508\n\
_0803300C:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	mov r0, ip\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0803301A\n\
	b _080335CA\n\
_0803301A:\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	b _080334FC\n\
_08033028:\n\
	movs r4, #0x92\n\
	lsls r4, r4, #1\n\
	adds r2, r6, r4\n\
	ldrb r1, [r2]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0803305E\n\
	mov r0, ip\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _0803305E\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r6, r0\n\
	ldr r0, [r1]\n\
	orrs r0, r3\n\
	str r0, [r1]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	subs r1, #1\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0803305E:\n\
	ldrb r1, [r2]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803306A\n\
	b _080335CA\n\
_0803306A:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	mov r1, ip\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	bne _08033078\n\
	b _080335CA\n\
_08033078:\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r1, r6, r3\n\
	ldr r0, [r1]\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	subs r1, #1\n\
	b _08033500\n\
_08033092:\n\
	mov r0, sb\n\
	ands r0, r5\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	cmp r7, #0\n\
	beq _0803310C\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r2, r6, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080330D8\n\
	movs r3, #0x80\n\
	lsls r3, r3, #6\n\
	mov r0, ip\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _080330D8\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r1, r6, r4\n\
	ldr r0, [r1]\n\
	orrs r0, r3\n\
	str r0, [r1]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	subs r1, #1\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_080330D8:\n\
	ldrb r1, [r2]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080330E4\n\
	b _080335CA\n\
_080330E4:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	mov r0, ip\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _080330F2\n\
	b _080335CA\n\
_080330F2:\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r1, r6, r3\n\
	ldr r0, [r1]\n\
	orrs r0, r2\n\
	str r0, [r1]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	subs r1, #1\n\
	b _08033500\n\
_0803310C:\n\
	adds r0, r6, #0\n\
	adds r0, #0xd9\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08033118\n\
	b _0803329C\n\
_08033118:\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r3, r6, r2\n\
	ldrh r1, [r0]\n\
	ldrh r2, [r3]\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803317A\n\
	ldr r3, _08033154 @ =0x00000222\n\
	adds r0, r6, r3\n\
	ldrh r0, [r0]\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08033158\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdd\n\
	b _0803316C\n\
	.align 2, 0\n\
_08033154: .4byte 0x00000222\n\
_08033158:\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
_0803316C:\n\
	strb r7, [r0]\n\
	mov r1, sl\n\
	ldrb r0, [r1, #0xf]\n\
_08033172:\n\
	cmp r0, #2\n\
	bne _08033178\n\
	b _080335CA\n\
_08033178:\n\
	b _080335BE\n\
_0803317A:\n\
	ands r2, r4\n\
	cmp r2, #0\n\
	beq _080331E0\n\
	ldr r2, _0803319C @ =0x00000222\n\
	adds r0, r6, r2\n\
	ldrh r0, [r0]\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _080331A0\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r1, r6, r3\n\
	ldr r0, [r1]\n\
	orrs r0, r5\n\
	str r0, [r1]\n\
	b _080331B0\n\
	.align 2, 0\n\
_0803319C: .4byte 0x00000222\n\
_080331A0:\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_080331B0:\n\
	movs r0, #0x92\n\
	lsls r0, r0, #1\n\
	adds r2, r6, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080331CA\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _080331D0\n\
_080331CA:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	movs r0, #0\n\
_080331D0:\n\
	strb r0, [r1]\n\
	ldrb r1, [r2]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080331DE\n\
	b _080334FC\n\
_080331DE:\n\
	b _08033508\n\
_080331E0:\n\
	mov r1, sl\n\
	ldrb r0, [r1, #0xf]\n\
	cmp r0, #2\n\
	bne _08033254\n\
	ldrh r0, [r3]\n\
	mov r2, r8\n\
	ands r2, r0\n\
	cmp r2, #0\n\
	bne _080331F4\n\
	b _080335CA\n\
_080331F4:\n\
	ldr r3, _08033228 @ =0x00000222\n\
	adds r0, r6, r3\n\
	ldrh r0, [r0]\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _0803322C\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08033210\n\
	b _080335CA\n\
_08033210:\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdd\n\
	strb r7, [r0]\n\
	b _080335CA\n\
	.align 2, 0\n\
_08033228: .4byte 0x00000222\n\
_0803322C:\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0803323C\n\
	b _080335CA\n\
_0803323C:\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r7, [r0]\n\
	b _080335CA\n\
_08033254:\n\
	ldr r1, _08033280 @ =0x00000222\n\
	adds r0, r6, r1\n\
	ldrh r0, [r0]\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _08033284\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08033270\n\
	b _080335BE\n\
_08033270:\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	b _080335BA\n\
	.align 2, 0\n\
_08033280: .4byte 0x00000222\n\
_08033284:\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08033294\n\
	b _080335BE\n\
_08033294:\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r0, r6, r3\n\
	b _080335B4\n\
_0803329C:\n\
	cmp r0, #1\n\
	beq _080332A2\n\
	b _08033414\n\
_080332A2:\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r6, r0\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r5, r6, r2\n\
	ldrh r0, [r1]\n\
	ldrh r2, [r5]\n\
	adds r3, r2, #0\n\
	ands r3, r0\n\
	mov sb, r1\n\
	cmp r3, #0\n\
	beq _080332D4\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r2, r6, r3\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r7, [r0]\n\
	b _08033364\n\
_080332D4:\n\
	ands r4, r2\n\
	cmp r4, #0\n\
	beq _0803330E\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r2, r6, r4\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #6\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033306\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _08033364\n\
_08033306:\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r3, [r0]\n\
	b _08033364\n\
_0803330E:\n\
	mov r2, sl\n\
	ldrb r0, [r2, #0xf]\n\
	cmp r0, #2\n\
	bne _08033340\n\
	ldrh r0, [r5]\n\
	mov r3, r8\n\
	ands r0, r3\n\
	cmp r0, #0\n\
	beq _08033364\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _08033364\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	b _0803335E\n\
_08033340:\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0803335E\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_0803335E:\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r4, [r0]\n\
_08033364:\n\
	ldr r3, _08033388 @ =0x00000222\n\
	adds r2, r6, r3\n\
	mov r4, sb\n\
	ldrh r0, [r4]\n\
	ldrh r1, [r2]\n\
	adds r3, r1, #0\n\
	ands r3, r0\n\
	cmp r3, #0\n\
	beq _0803338C\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	b _08033508\n\
	.align 2, 0\n\
_08033388: .4byte 0x00000222\n\
_0803338C:\n\
	ldr r4, [sp, #0xc]\n\
	ldrh r0, [r4]\n\
	adds r4, r0, #0\n\
	ands r4, r1\n\
	cmp r4, #0\n\
	beq _080333C2\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #8\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080333BA\n\
	b _080334FC\n\
_080333BA:\n\
	adds r0, r6, #0\n\
	adds r0, #0xdd\n\
	strb r3, [r0]\n\
	b _080335CA\n\
_080333C2:\n\
	mov r3, sl\n\
	ldrb r0, [r3, #0xf]\n\
	cmp r0, #2\n\
	bne _080333EE\n\
	ldrh r0, [r2]\n\
	mov r1, r8\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	bne _080333D6\n\
	b _080335CA\n\
_080333D6:\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080333E6\n\
	b _080335CA\n\
_080333E6:\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	b _08033402\n\
_080333EE:\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0803340C\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r0, r6, r3\n\
_08033402:\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_0803340C:\n\
	adds r0, r6, #0\n\
	adds r0, #0xdd\n\
	strb r4, [r0]\n\
	b _080335CA\n\
_08033414:\n\
	ldrb r0, [r6, #0xd]\n\
	movs r4, #0x85\n\
	lsls r4, r4, #2\n\
	adds r4, r4, r6\n\
	mov sb, r4\n\
	cmp r0, #8\n\
	bhi _08033442\n\
	ldr r1, _0803347C @ =0x00000222\n\
	adds r0, r6, r1\n\
	ldrh r1, [r4]\n\
	ldrh r0, [r0]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033442\n\
	movs r0, #5\n\
	bl PlaySound\n\
	adds r2, r6, #0\n\
	adds r2, #0xda\n\
	ldrb r0, [r2]\n\
	movs r1, #1\n\
	eors r0, r1\n\
	strb r0, [r2]\n\
_08033442:\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r3, r6, r2\n\
	mov r4, sb\n\
	ldrh r1, [r4]\n\
	ldrh r2, [r3]\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0803349C\n\
	adds r0, r6, #0\n\
	adds r0, #0xda\n\
	ldrb r3, [r0]\n\
	cmp r3, #0\n\
	beq _08033480\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r2, r6, r0\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #7\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08033496\n\
	.align 2, 0\n\
_0803347C: .4byte 0x00000222\n\
_08033480:\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r2, r6, r1\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r3, [r0]\n\
_08033496:\n\
	mov r2, sl\n\
	ldrb r0, [r2, #0xf]\n\
	b _08033172\n\
_0803349C:\n\
	ldr r4, [sp, #0xc]\n\
	ldrh r0, [r4]\n\
	adds r5, r0, #0\n\
	ands r5, r2\n\
	cmp r5, #0\n\
	beq _08033512\n\
	adds r0, r6, #0\n\
	adds r0, #0xda\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080334C0\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #8\n\
	b _080334CC\n\
_080334C0:\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #6\n\
_080334CC:\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	movs r3, #0x92\n\
	lsls r3, r3, #1\n\
	adds r2, r6, r3\n\
	ldrb r1, [r2]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _080334EA\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _080334F0\n\
_080334EA:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	movs r0, #0\n\
_080334F0:\n\
	strb r0, [r1]\n\
	ldrb r1, [r2]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033508\n\
_080334FC:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
_08033500:\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _080335CA\n\
_08033508:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _080335CA\n\
_08033512:\n\
	mov r4, sl\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _0803357A\n\
	ldrh r0, [r3]\n\
	mov r1, r8\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _080335CA\n\
	adds r0, r6, #0\n\
	adds r0, #0xda\n\
	ldrb r4, [r0]\n\
	cmp r4, #0\n\
	beq _08033554\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080335CA\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdd\n\
	strb r5, [r0]\n\
	b _080335CA\n\
_08033554:\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080335CA\n\
	movs r3, #0x86\n\
	lsls r3, r3, #2\n\
	adds r2, r6, r3\n\
	ldr r0, [r2]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	strb r4, [r0]\n\
	b _080335CA\n\
_0803357A:\n\
	adds r0, r6, #0\n\
	adds r0, #0xda\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080335A0\n\
	adds r0, r6, #0\n\
	movs r1, #1\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080335BE\n\
	movs r4, #0x86\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #7\n\
	b _080335BA\n\
_080335A0:\n\
	adds r0, r6, #0\n\
	movs r1, #0\n\
	bl GetWeaponCharge\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080335BE\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
_080335B4:\n\
	ldr r1, [r0]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #5\n\
_080335BA:\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
_080335BE:\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
_080335CA:\n\
	adds r0, r6, #0\n\
	bl tryCommandDash\n\
	mov r2, sl\n\
	ldrb r0, [r2, #0x1a]\n\
	cmp r0, #2\n\
	bne _080335F0\n\
	adds r0, r6, #0\n\
	bl ultimate_command_080339a8\n\
	adds r0, r6, #0\n\
	bl ultimate_command_08033ad8\n\
	adds r0, r6, #0\n\
	bl ultimate_command_08033c8c\n\
	adds r0, r6, #0\n\
	bl ultimate_command_08033da0\n\
_080335F0:\n\
	ldr r3, [sp, #0xc]\n\
	ldrh r1, [r3]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033646\n\
	mov r4, sl\n\
	ldrb r0, [r4, #0xf]\n\
	cmp r0, #2\n\
	bne _08033646\n\
	adds r3, r6, #0\n\
	adds r3, #0xdc\n\
	ldrb r2, [r3]\n\
	ldr r0, [sp]\n\
	cmp r0, r2\n\
	bne _08033626\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033626\n\
	adds r0, r2, #1\n\
	strb r0, [r3]\n\
_08033626:\n\
	adds r3, r6, #0\n\
	adds r3, #0xdd\n\
	ldrb r2, [r3]\n\
	ldr r4, [sp, #4]\n\
	cmp r4, r2\n\
	bne _08033646\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	adds r0, r6, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033646\n\
	adds r0, r2, #1\n\
	strb r0, [r3]\n\
_08033646:\n\
	ldrb r0, [r6, #0xd]\n\
	cmp r0, #9\n\
	bne _0803365A\n\
	adds r0, r6, #0\n\
	adds r0, #0xdc\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	b _080336E4\n\
_0803365A:\n\
	mov r2, sl\n\
	ldrb r0, [r2, #0x1a]\n\
	cmp r0, #1\n\
	bne _080336C8\n\
	ldrb r0, [r2, #0xc]\n\
	cmp r0, #1\n\
	beq _08033692\n\
	cmp r0, #1\n\
	bgt _08033672\n\
	cmp r0, #0\n\
	beq _08033684\n\
	b _0803369A\n\
_08033672:\n\
	cmp r0, #3\n\
	bgt _0803369A\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	cmp r0, #0xc8\n\
	bls _0803369A\n\
	movs r0, #0xc8\n\
	b _08033698\n\
_08033684:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x28\n\
	bls _0803369A\n\
	movs r0, #0x28\n\
	b _08033698\n\
_08033692:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	movs r0, #0\n\
_08033698:\n\
	strb r0, [r1]\n\
_0803369A:\n\
	mov r3, sl\n\
	ldrb r0, [r3, #0xd]\n\
	cmp r0, #1\n\
	beq _080336C0\n\
	cmp r0, #1\n\
	bgt _080336AC\n\
	cmp r0, #0\n\
	beq _080336B2\n\
	b _080336E4\n\
_080336AC:\n\
	cmp r0, #3\n\
	bgt _080336E4\n\
	b _080336D6\n\
_080336B2:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x28\n\
	bls _080336E4\n\
	movs r0, #0x28\n\
	b _080336E2\n\
_080336C0:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	movs r0, #0\n\
	b _080336E2\n\
_080336C8:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdc\n\
	ldrb r0, [r1]\n\
	cmp r0, #0xc8\n\
	bls _080336D6\n\
	movs r0, #0xc8\n\
	strb r0, [r1]\n\
_080336D6:\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	ldrb r0, [r1]\n\
	cmp r0, #0xc8\n\
	bls _080336E4\n\
	movs r0, #0xc8\n\
_080336E2:\n\
	strb r0, [r1]\n\
_080336E4:\n\
	mov r4, sl\n\
	ldrb r0, [r4, #0xc]\n\
	ldrb r1, [r4, #0xd]\n\
	cmp r0, r1\n\
	bne _080336F6\n\
	adds r1, r6, #0\n\
	adds r1, #0xdd\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080336F6:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
 .syntax divided\n");
}

WIP static void tryCommandDash(struct Zero* z) {
#if MODERN
  u8 i, j;
  if (z->commandDashTimer > 0) {
    z->commandDashTimer--;
    z->inputHistory[0] |= COMMAND_DASH;
    if ((z->last & (DPAD_RIGHT | DPAD_LEFT)) == 0) {
      z->commandDashTimer = 0;
      return;
    }
    // Continue command dash
    z->zeroInput |= ZERO_INPUT_DASH;
    return;
  }

  if (z->pressed & DPAD_RIGHT) {
    for (i = 1; i < 10; i++) {
      KEY_INPUT pressed = z->inputHistory[i];
      if (pressed & COMMAND_DASH) {
        return;
      }
      if (pressed & DPAD_LEFT) {
        return;
      }
      if (pressed & DPAD_RIGHT) {
        for (j = 0; j < 10; j++) {
          if (!(z->inputHistory[i + j] & DPAD_RIGHT)) {
            z->inputHistory[0] |= COMMAND_DASH;
            z->zeroInput |= ZERO_INPUT_PRESS_DASH;
            z->commandDashTimer = 28;
          }
        }
        return;
      }
    }
  } else if (z->pressed & DPAD_LEFT) {
    for (i = 1; i < 10; i++) {
      KEY_INPUT pressed = z->inputHistory[i];
      if (pressed & COMMAND_DASH) {
        return;
      }
      if (pressed & DPAD_RIGHT) {
        return;
      }
      if (pressed & DPAD_LEFT) {
        for (j = 0; j < 10; j++) {
          if (!(z->inputHistory[i + j] & DPAD_LEFT)) {
            z->inputHistory[0] |= COMMAND_DASH;
            z->zeroInput |= ZERO_INPUT_PRESS_DASH;
            z->commandDashTimer = 28;
          }
        }
        return;
      }
    }
  }

  z->commandDashTimer = 0;
#else
  INCCODE("asm/wip/tryCommandDash.inc");
#endif
}

bool8 IsButtonMashed(struct Zero* z) {
  if (CountButtonMashing(z) != 0) {
    return TRUE;
  }
  return FALSE;
}

NAKED u8 CountRodButton(struct Zero* z, bool8 isSubWeapon) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	lsls r1, r1, #0x18\n\
	cmp r1, #0\n\
	beq _080338EC\n\
	adds r0, r3, #0\n\
	adds r0, #0xd9\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080338EC\n\
	cmp r0, #1\n\
	bne _080338EC\n\
	ldr r1, _080338E8 @ =0x00000222\n\
	b _080338F0\n\
	.align 2, 0\n\
_080338E8: .4byte 0x00000222\n\
_080338EC:\n\
	movs r1, #0x88\n\
	lsls r1, r1, #2\n\
_080338F0:\n\
	adds r0, r3, r1\n\
	ldrh r2, [r0]\n\
	movs r4, #0\n\
	movs r1, #0\n\
	movs r0, #0xca\n\
	lsls r0, r0, #1\n\
	adds r3, r3, r0\n\
_080338FE:\n\
	lsls r0, r1, #1\n\
	adds r0, r3, r0\n\
	ldrh r0, [r0]\n\
	ands r0, r2\n\
	adds r1, #1\n\
	cmp r0, #0\n\
	beq _0803391E\n\
	lsls r0, r1, #1\n\
	adds r0, r3, r0\n\
	ldrh r0, [r0]\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0803391E\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
_0803391E:\n\
	lsls r0, r1, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0x1f\n\
	bls _080338FE\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

void FUN_08033930(struct Zero* z, u8 r1, u8 r2) {
  (z->unk_b4).status.keyMap.btnMode = r1;
  if (r1 == 0) {
    (z->keyMap).jump = A_BUTTON;
    (z->keyMap).dash = L_BUTTON;
    (z->keyMap).main = B_BUTTON;
    (z->keyMap).sub = R_BUTTON;
  } else if (r1 == 1) {
    (z->keyMap).jump = A_BUTTON;
    (z->keyMap).dash = R_BUTTON;
    (z->keyMap).main = B_BUTTON;
    (z->keyMap).sub = L_BUTTON;
  }
  (z->unk_b4).status.keyMap.attackMode = r2;
}

NAKED bool8 ultimate_command_080339a8(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r1, r0, #0\n\
	ldr r0, _080339C0 @ =0x00000225\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3]\n\
	cmp r0, #1\n\
	beq _080339F4\n\
	cmp r0, #1\n\
	bgt _080339C4\n\
	cmp r0, #0\n\
	beq _080339CE\n\
	b _08033AC2\n\
	.align 2, 0\n\
_080339C0: .4byte 0x00000225\n\
_080339C4:\n\
	cmp r0, #2\n\
	beq _08033A40\n\
	cmp r0, #3\n\
	beq _08033AA4\n\
	b _08033AC2\n\
_080339CE:\n\
	ldr r2, _080339F0 @ =0x00000216\n\
	adds r0, r1, r2\n\
	ldrh r2, [r0]\n\
	movs r0, #0x30\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08033ACA\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033ACA\n\
	movs r4, #0x89\n\
	lsls r4, r4, #2\n\
	adds r1, r1, r4\n\
	movs r0, #0xa\n\
	strb r0, [r1]\n\
	b _08033A96\n\
	.align 2, 0\n\
_080339F0: .4byte 0x00000216\n\
_080339F4:\n\
	movs r0, #0x89\n\
	lsls r0, r0, #2\n\
	adds r2, r1, r0\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033A0C\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033A0C:\n\
	ldr r4, _08033A20 @ =0x00000216\n\
	adds r0, r1, r4\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033A24\n\
	movs r0, #0xa\n\
	strb r0, [r2]\n\
	b _08033A96\n\
	.align 2, 0\n\
_08033A20: .4byte 0x00000216\n\
_08033A24:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033A32\n\
	movs r0, #0xa\n\
	strb r0, [r2]\n\
	b _08033A96\n\
_08033A32:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033ACA\n\
	movs r0, #0xa\n\
	strb r0, [r2]\n\
	b _08033A96\n\
_08033A40:\n\
	movs r0, #0x89\n\
	lsls r0, r0, #2\n\
	adds r5, r1, r0\n\
	ldrb r0, [r5]\n\
	subs r0, #1\n\
	strb r0, [r5]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033A58\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033A58:\n\
	ldr r2, _08033A7C @ =0x00000216\n\
	adds r0, r1, r2\n\
	ldrh r2, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08033ACA\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r4, r0, #0x10\n\
	cmp r4, #0\n\
	beq _08033A84\n\
	ldr r4, _08033A80 @ =0x00000226\n\
	adds r1, r1, r4\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _08033A92\n\
	.align 2, 0\n\
_08033A7C: .4byte 0x00000216\n\
_08033A80: .4byte 0x00000226\n\
_08033A84:\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033ACA\n\
	ldr r2, _08033AA0 @ =0x00000226\n\
	adds r0, r1, r2\n\
	strb r4, [r0]\n\
_08033A92:\n\
	movs r0, #0xa\n\
	strb r0, [r5]\n\
_08033A96:\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	strb r0, [r3]\n\
	b _08033ACA\n\
	.align 2, 0\n\
_08033AA0: .4byte 0x00000226\n\
_08033AA4:\n\
	movs r4, #0x89\n\
	lsls r4, r4, #2\n\
	adds r1, r1, r4\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033ABE\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	b _08033ACC\n\
_08033ABE:\n\
	movs r0, #1\n\
	b _08033ACC\n\
_08033AC2:\n\
	ldr r0, _08033AD4 @ =0x00000225\n\
	adds r1, r1, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033ACA:\n\
	movs r0, #0\n\
_08033ACC:\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08033AD4: .4byte 0x00000225\n\
 .syntax divided\n");
}

NAKED bool8 ultimate_command_08033ad8(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #6\n\
	bls _08033AEA\n\
	b _08033C80\n\
_08033AEA:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08033AF4 @ =_08033AF8\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08033AF4: .4byte _08033AF8\n\
_08033AF8: @ jump table\n\
	.4byte _08033B14 @ case 0\n\
	.4byte _08033B64 @ case 1\n\
	.4byte _08033BD8 @ case 2\n\
	.4byte _08033B14 @ case 3\n\
	.4byte _08033B64 @ case 4\n\
	.4byte _08033BD8 @ case 5\n\
	.4byte _08033C58 @ case 6\n\
_08033B14:\n\
	ldr r1, _08033B5C @ =0x00000227\n\
	adds r3, r2, r1\n\
	ldrb r0, [r3]\n\
	subs r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033B30\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033B30:\n\
	ldr r1, _08033B60 @ =0x00000216\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033B40\n\
	b _08033C84\n\
_08033B40:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033B4A\n\
	b _08033C84\n\
_08033B4A:\n\
	movs r0, #0xa\n\
	strb r0, [r3]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
	.align 2, 0\n\
_08033B5C: .4byte 0x00000227\n\
_08033B60: .4byte 0x00000216\n\
_08033B64:\n\
	ldr r1, _08033BA0 @ =0x00000227\n\
	adds r3, r2, r1\n\
	ldrb r0, [r3]\n\
	subs r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033B80\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033B80:\n\
	ldr r1, _08033BA4 @ =0x00000216\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033BA8\n\
	movs r0, #0xa\n\
	strb r0, [r3]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
	.align 2, 0\n\
_08033BA0: .4byte 0x00000227\n\
_08033BA4: .4byte 0x00000216\n\
_08033BA8:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033BC0\n\
	movs r0, #0xa\n\
	strb r0, [r3]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
_08033BC0:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033C84\n\
	movs r0, #0xa\n\
	strb r0, [r3]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
_08033BD8:\n\
	ldr r1, _08033C28 @ =0x00000227\n\
	adds r4, r2, r1\n\
	ldrb r0, [r4]\n\
	subs r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033BF4\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033BF4:\n\
	ldr r1, _08033C2C @ =0x00000216\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033C84\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	cmp r3, #0\n\
	beq _08033C34\n\
	ldr r0, _08033C30 @ =0x00000229\n\
	adds r1, r2, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
	.align 2, 0\n\
_08033C28: .4byte 0x00000227\n\
_08033C2C: .4byte 0x00000216\n\
_08033C30: .4byte 0x00000229\n\
_08033C34:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033C84\n\
	ldr r1, _08033C54 @ =0x00000229\n\
	adds r0, r2, r1\n\
	strb r3, [r0]\n\
	movs r0, #0xa\n\
	strb r0, [r4]\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	b _08033C82\n\
	.align 2, 0\n\
_08033C54: .4byte 0x00000229\n\
_08033C58:\n\
	ldr r0, _08033C78 @ =0x00000227\n\
	adds r1, r2, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033C7C\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _08033C86\n\
	.align 2, 0\n\
_08033C78: .4byte 0x00000227\n\
_08033C7C:\n\
	movs r0, #1\n\
	b _08033C86\n\
_08033C80:\n\
	movs r0, #0\n\
_08033C82:\n\
	strb r0, [r1]\n\
_08033C84:\n\
	movs r0, #0\n\
_08033C86:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
 .syntax divided\n");
}

NAKED bool8 ultimate_command_08033c8c(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, lr}\n\
	adds r1, r0, #0\n\
	ldr r0, _08033CA4 @ =0x0000022B\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3]\n\
	cmp r0, #1\n\
	beq _08033CF4\n\
	cmp r0, #1\n\
	bgt _08033CA8\n\
	cmp r0, #0\n\
	beq _08033CB2\n\
	b _08033D8C\n\
	.align 2, 0\n\
_08033CA4: .4byte 0x0000022B\n\
_08033CA8:\n\
	cmp r0, #2\n\
	beq _08033D2C\n\
	cmp r0, #3\n\
	beq _08033D6C\n\
	b _08033D8C\n\
_08033CB2:\n\
	ldr r2, _08033CD4 @ =0x00000216\n\
	adds r0, r1, r2\n\
	ldrh r2, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _08033D94\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033CDC\n\
	ldr r4, _08033CD8 @ =0x0000022A\n\
	adds r1, r1, r4\n\
	movs r0, #0xa\n\
	strb r0, [r1]\n\
	b _08033D5C\n\
	.align 2, 0\n\
_08033CD4: .4byte 0x00000216\n\
_08033CD8: .4byte 0x0000022A\n\
_08033CDC:\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033D94\n\
	ldr r0, _08033CF0 @ =0x0000022A\n\
	adds r1, r1, r0\n\
	movs r0, #0xa\n\
	strb r0, [r1]\n\
	b _08033D5C\n\
	.align 2, 0\n\
_08033CF0: .4byte 0x0000022A\n\
_08033CF4:\n\
	ldr r4, _08033D24 @ =0x0000022A\n\
	adds r2, r1, r4\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033D0A\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033D0A:\n\
	ldr r4, _08033D28 @ =0x00000216\n\
	adds r0, r1, r4\n\
	ldrh r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033D58\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033D58\n\
	movs r0, #0x20\n\
	b _08033D52\n\
	.align 2, 0\n\
_08033D24: .4byte 0x0000022A\n\
_08033D28: .4byte 0x00000216\n\
_08033D2C:\n\
	ldr r0, _08033D64 @ =0x0000022A\n\
	adds r2, r1, r0\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033D42\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033D42:\n\
	ldr r4, _08033D68 @ =0x00000216\n\
	adds r0, r1, r4\n\
	ldrh r1, [r0]\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033D94\n\
	movs r0, #0x40\n\
_08033D52:\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033D94\n\
_08033D58:\n\
	movs r0, #0xa\n\
	strb r0, [r2]\n\
_08033D5C:\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	strb r0, [r3]\n\
	b _08033D94\n\
	.align 2, 0\n\
_08033D64: .4byte 0x0000022A\n\
_08033D68: .4byte 0x00000216\n\
_08033D6C:\n\
	ldr r0, _08033D84 @ =0x0000022A\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033D88\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	b _08033D96\n\
	.align 2, 0\n\
_08033D84: .4byte 0x0000022A\n\
_08033D88:\n\
	movs r0, #1\n\
	b _08033D96\n\
_08033D8C:\n\
	ldr r2, _08033D9C @ =0x0000022B\n\
	adds r1, r1, r2\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033D94:\n\
	movs r0, #0\n\
_08033D96:\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08033D9C: .4byte 0x0000022B\n\
 .syntax divided\n");
}

NAKED bool8 ultimate_command_08033da0(struct Zero* z) {
  asm(".syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, _08033DB8 @ =0x0000022D\n\
	adds r3, r4, r0\n\
	ldrb r1, [r3]\n\
	cmp r1, #1\n\
	beq _08033DFC\n\
	cmp r1, #1\n\
	bgt _08033DBC\n\
	cmp r1, #0\n\
	beq _08033DC6\n\
	b _08033EBE\n\
	.align 2, 0\n\
_08033DB8: .4byte 0x0000022D\n\
_08033DBC:\n\
	cmp r1, #2\n\
	beq _08033E60\n\
	cmp r1, #3\n\
	beq _08033EA0\n\
	b _08033EBE\n\
_08033DC6:\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033DDC\n\
	strb r1, [r3]\n\
_08033DDC:\n\
	ldr r1, _08033DF8 @ =0x00000216\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033EC6\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033E8E\n\
	movs r0, #0x20\n\
	b _08033E88\n\
	.align 2, 0\n\
_08033DF8: .4byte 0x00000216\n\
_08033DFC:\n\
	movs r2, #0x8b\n\
	lsls r2, r2, #2\n\
	adds r5, r4, r2\n\
	ldrb r0, [r5]\n\
	subs r0, #1\n\
	strb r0, [r5]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033E14\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033E14:\n\
	ldr r2, _08033E28 @ =0x00000216\n\
	adds r0, r4, r2\n\
	ldrh r2, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033E2C\n\
	movs r0, #0xa\n\
	strb r0, [r5]\n\
	b _08033E92\n\
	.align 2, 0\n\
_08033E28: .4byte 0x00000216\n\
_08033E2C:\n\
	movs r0, #0x10\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, #0\n\
	beq _08033E48\n\
	ldr r2, _08033E44 @ =0x0000022E\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	movs r0, #0xa\n\
	strb r0, [r5]\n\
	b _08033E92\n\
	.align 2, 0\n\
_08033E44: .4byte 0x0000022E\n\
_08033E48:\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08033EC6\n\
	ldr r1, _08033E5C @ =0x0000022E\n\
	adds r0, r4, r1\n\
	strb r6, [r0]\n\
	movs r0, #0xa\n\
	strb r0, [r5]\n\
	b _08033E92\n\
	.align 2, 0\n\
_08033E5C: .4byte 0x0000022E\n\
_08033E60:\n\
	movs r0, #0x8b\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033E78\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
_08033E78:\n\
	ldr r1, _08033E9C @ =0x00000216\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	movs r0, #0x30\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08033EC6\n\
	movs r0, #0x80\n\
_08033E88:\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08033EC6\n\
_08033E8E:\n\
	movs r0, #0xa\n\
	strb r0, [r2]\n\
_08033E92:\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	strb r0, [r3]\n\
	b _08033EC6\n\
	.align 2, 0\n\
_08033E9C: .4byte 0x00000216\n\
_08033EA0:\n\
	movs r2, #0x8b\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xff\n\
	bne _08033EBA\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	b _08033EC8\n\
_08033EBA:\n\
	movs r0, #1\n\
	b _08033EC8\n\
_08033EBE:\n\
	ldr r0, _08033ED0 @ =0x0000022D\n\
	adds r1, r4, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_08033EC6:\n\
	movs r0, #0\n\
_08033EC8:\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08033ED0: .4byte 0x0000022D\n\
 .syntax divided\n");
}
