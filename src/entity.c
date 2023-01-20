#include "entity.h"

#include "gba/gba.h"

extern struct EntityHeader *pCurEntityHeader;

// 0x08006ED0
NAKED void initEntityHeader(struct EntityHeader *h, s16 type, struct Entity *s, s16 size, s16 count) {
  asm(".syntax unified\n\
    push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	adds r5, r2, #0\n\
	ldr r0, [sp, #0x14]\n\
	lsls r1, r1, #0x18\n\
	lsls r3, r3, #0x10\n\
	lsrs r6, r3, #0x10\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	str r5, [r4]\n\
	lsrs r7, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	movs r2, #0\n\
	strh r1, [r4, #4]\n\
	strh r6, [r4, #6]\n\
	strh r3, [r4, #8]\n\
	adds r0, r4, #0\n\
	adds r0, #0x14\n\
	str r0, [r4, #0x18]\n\
	str r0, [r4, #0x14]\n\
	str r2, [r4, #0x10]\n\
	strh r3, [r4, #0xa]\n\
	lsls r1, r3, #0x10\n\
	cmp r1, #0\n\
	ble _08006F1A\n\
	lsls r0, r6, #0x10\n\
	asrs r3, r0, #0x10\n\
_08006F06:\n\
	str r2, [r5]\n\
	adds r2, r5, #0\n\
	strb r7, [r2, #8]\n\
	adds r5, r2, r3\n\
	ldr r0, _08006F20 @ =0xFFFF0000\n\
	adds r1, r1, r0\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0\n\
	bgt _08006F06\n\
	str r2, [r4, #0x10]\n\
_08006F1A:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08006F20: .4byte 0xFFFF0000\n\
                .syntax divided\n");
}

// 0x08006F24
static void resetEntityHeader(struct EntityHeader *h) {
  s8 t = h->type;
  s16 size = h->size;
  initEntityHeader(h, t, h->arr, size, h->length);
  return;
}

// 0x08006F44
void setCurProcessedEntityHeader(struct EntityHeader *h) {
  struct Entity **next;
  pCurEntityHeader = h;

  next = (struct Entity **)((u8 *)h + 0x14);
  h->done = next;
  return;
}

// 処理してないfnを無視して最新のfnを指すようにする
void ignoreEntityFn(struct EntityHeader *h) {
  h->done = &h->next;
  return;
}

// 0x08006f5c
struct Entity *getNextEntity(struct EntityHeader *h) {
  struct Entity *p;

  p = h->cur;
  if (p != (struct Entity *)0x0) {
    h->cur = p->next;
    h->remaining = h->remaining + -1;
    p->next = (struct Entity *)&h->next;
    p->prev = h->prev;
    h->prev->next = p;
    h->prev = p;
    *(u16 *)&p->flags = 0;
    *(u32 *)&p->fnIdx = 0;
    *(u32 *)&p->various = 0;
  }
  return p;
}

// 0x08006f90
// 新しいEntity割り当てのために用いる
// EntityHeaderに対応するさまざまなEntityを返す
// getNextEntity との違いは後で調べる
struct Entity *getNextEntity2(struct EntityHeader *h) {
  struct Entity *s;

  s = h->cur;
  if (s != (struct Entity *)0x0) {
    h->cur = s->next;
    h->remaining = h->remaining + -1;
    s->prev = (struct Entity *)&h->next;
    s->next = h->next;
    h->next->prev = s;
    h->next = s;
    *(u16 *)&s->flags = 0;
    *(u32 *)&s->fnIdx = 0;
    *(u32 *)&s->various = 0;
  }
  return s;
}

static struct Entity *entity_08006fc4(struct Entity *p) {
  struct Entity *s;
  struct EntityHeader *h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->cur;
  if (s != (struct Entity *)0x0) {
    pCurEntityHeader->cur = s->next;
    h->remaining = h->remaining + -1;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    *(u16 *)&s->flags = 0;
    *(u32 *)&s->fnIdx = 0;
    *(u32 *)&s->various = 0;
  }
  return s;
}

static struct Entity *entity_08006ffc(struct Entity *p) {
  struct Entity *s;
  struct EntityHeader *h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->cur;
  if (s != (struct Entity *)0x0) {
    pCurEntityHeader->cur = s->next;
    h->remaining = h->remaining + -1;
    s->prev = p->prev;
    s->next = p;
    p->prev->next = s;
    p->prev = s;
    *(u16 *)&s->flags = 0;
    *(u32 *)&s->fnIdx = 0;
    *(u32 *)&s->various = 0;
  }
  return s;
}

// EntityHeader の配列から不要なEntityを取り除く
void removeEntity(struct Entity *p) {
  struct EntityHeader *h;

  p->prev->next = p->next;
  p->next->prev = p->prev;
  h = pCurEntityHeader;
  p->next = pCurEntityHeader->cur;
  h->cur = p;
  h->remaining = h->remaining + 1;
  return;
}

/*
  zをh.curの目の前に挿入し、現在のcurをzにする

   Before: Zprev -> Z -> Znext
   After:
     Zprev -> Znext
     Z -> h.cur
*/
void prependZeroEntity(struct EntityHeader *h, struct Zero *z) {
  ((z->s).prev)->next = (z->s).next;
  ((z->s).next)->prev = (z->s).prev;
  (z->s).next = h->cur;
  h->cur = &z->s;
  h->remaining = h->remaining + 1;
  return;
}
