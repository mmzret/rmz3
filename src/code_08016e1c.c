#include "entity.h"
#include "gba/gba.h"

void _call_via_r1(u32 r0, u32* r1);
void setCurProcessedEntityHeader(struct EntityHeader* h);

/**
 * @brief 引数の EntityHeader の示す fnを処理していく
 * @note 0x08016e1c
 */
void runEntityFn(struct EntityHeader* h) {
  struct Entity* p;

  setCurProcessedEntityHeader(h);
  p = h->done[1];
  h->done = &p->next;
  while (p != (struct Entity*)&h->next) {
    _call_via_r1((u32)p, (u32*)p->fn);
    p = h->done[1];
    h->done = &p->next;
  }
  return;
}

NAKED void FUN_08016e4c(struct EntityHeader* h) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	bl setCurProcessedEntityHeader\n\
	b _08016E76\n\
_08016E56:\n\
	ldr r1, [r4, #0x14]\n\
	adds r0, r4, #0\n\
	bl _call_via_r1\n\
	ldrb r1, [r4, #0xb]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08016E76\n\
	ldrb r0, [r4, #0x1c]\n\
	ldrh r1, [r4, #0x26]\n\
	adds r2, r4, #0\n\
	adds r2, #0x54\n\
	ldr r3, [r4, #0x30]\n\
	bl appendBlocking\n\
_08016E76:\n\
	ldr r0, [r5, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0xc]\n\
	adds r4, r0, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x14\n\
	cmp r4, r0\n\
	bne _08016E56\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
     .syntax divided\n");
}

NAKED void FUN_08016e8c(struct EntityHeader* h) {
  asm(".syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	bl setCurProcessedEntityHeader\n\
	b _08016EDC\n\
_08016E96:\n\
	ldrb r2, [r3, #0xa]\n\
	movs r0, #4\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08016EDC\n\
	adds r4, r3, #0\n\
	adds r4, #0x74\n\
	movs r0, #2\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08016ED6\n\
	movs r0, #0x40\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08016EC8\n\
	movs r1, #0x30\n\
	ands r1, r2\n\
	lsrs r1, r1, #4\n\
	adds r0, r3, #0\n\
	adds r0, #0x24\n\
	ldrb r2, [r0]\n\
	adds r0, r4, #0\n\
	bl FUN_08007464\n\
	b _08016EDC\n\
_08016EC8:\n\
	movs r1, #0x30\n\
	ands r1, r2\n\
	lsrs r1, r1, #4\n\
	adds r0, r4, #0\n\
	bl FUN_0800735c\n\
	b _08016EDC\n\
_08016ED6:\n\
	adds r0, r4, #0\n\
	bl hitbox_0800729c\n\
_08016EDC:\n\
	ldr r0, [r5, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r5, #0xc]\n\
	adds r3, r0, #0\n\
	adds r0, r5, #0\n\
	adds r0, #0x14\n\
	cmp r3, r0\n\
	bne _08016E96\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
     .syntax divided\n");
}

/**
 * @brief 各EntityHeaderの持つEntityを見ていって、必要な場合は 無敵点滅処理 と ダメージSE を行う
 * @note 0x08016EF4
 */
NAKED void runDamageEffect(struct EntityHeader* h) {
  asm(".syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	bl setCurProcessedEntityHeader\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r3, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r3, r0\n\
	beq _08016F8C\n\
	ldr r5, _08016F94 @ =0x00001004\n\
	ldr r0, _08016F98 @ =0x0202F360\n\
	mov ip, r0\n\
	ldr r7, _08016F9C @ =0x0202F344\n\
	ldr r6, _08016FA0 @ =0x0202F330\n\
_08016F16:\n\
	ldrh r1, [r3, #0xa]\n\
	adds r0, r5, #0\n\
	ands r0, r1\n\
	cmp r0, r5\n\
	bne _08016F7C\n\
	adds r0, r3, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08016F48\n\
	adds r0, r3, #0\n\
	adds r0, #0x90\n\
	ldr r0, [r0]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08016F48\n\
	adds r0, r3, #0\n\
	adds r0, #0x94\n\
	ldrb r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08016F5E\n\
_08016F48:\n\
	ldrb r1, [r3, #0x1d]\n\
	lsrs r2, r1, #5\n\
	lsls r2, r2, #2\n\
	add r2, ip\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	movs r1, #1\n\
	lsls r1, r0\n\
	ldr r0, [r2]\n\
	orrs r0, r1\n\
	str r0, [r2]\n\
_08016F5E:\n\
	ldrb r0, [r7]\n\
	cmp r0, #0\n\
	bne _08016F7C\n\
	adds r0, r3, #0\n\
	adds r0, #0x8c\n\
	ldr r0, [r0]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08016F7C\n\
	ldr r0, [r3, #0x74]\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #0\n\
	beq _08016F7C\n\
	strb r1, [r6]\n\
_08016F7C:\n\
	ldr r0, [r4, #0xc]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0xc]\n\
	adds r3, r0, #0\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	cmp r3, r0\n\
	bne _08016F16\n\
_08016F8C:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08016F94: .4byte 0x00001004\n\
_08016F98: .4byte 0x0202F360\n\
_08016F9C: .4byte 0x0202F344\n\
_08016FA0: .4byte 0x0202F330\n\
 .syntax divided\n");
}
