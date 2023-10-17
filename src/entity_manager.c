#include "entity.h"

NON_MATCH void InitEntityHeader(struct EntityHeader *h, s8 kind, struct Entity *arr, s16 size, s16 count) {
#if MODERN
  struct Entity *free;

  h->arr = arr;
  h->type = kind;
  h->size = size;
  h->length = count;
  h->prev = (struct Entity *)&h->next;
  h->next = (struct Entity *)&h->next;
  h->free = NULL;
  h->remaining = count;

  free = h->free;
  while (count > 0) {
    struct Entity *cur = arr;
    cur->next = free;
    cur->kind = kind;
    free = cur;
    arr = (struct Entity *)((u8 *)arr + size);
    count--;
    h->free = free;
  }
#else
  INCCODE("asm/wip/InitEntityHeader.inc");
#endif
}

// 0x08006F24
static void resetEntityHeader(struct EntityHeader *h) {
  s8 t = h->type;
  s16 size = h->size;
  InitEntityHeader(h, t, h->arr, size, h->length);
}

// 0x08006F44
void setCurProcessedEntityHeader(struct EntityHeader *h) {
  pCurEntityHeader = h;
  h->last = (struct Entity *)&h->next;  // この時点の h->next が last
}

// 処理してないfnを無視して最新のfnを指すようにする
void ignoreEntityFn(struct EntityHeader *h) {
  h->last = (struct Entity *)&h->next;
  return;
}

// Alloc entity as Entity linklist LAST entry
struct Entity *AllocEntityLast(struct EntityHeader *h) {
  struct Entity *p;

  p = h->free;
  if (p != NULL) {
    h->free = p->next;
    h->remaining--;

    p->next = (struct Entity *)&h->next;
    p->prev = h->prev;
    h->prev->next = p;
    h->prev = p;

    *(u16 *)&p->flags = 0;
    *(u32 *)&p->mode = 0;
    *(u32 *)&p->work = 0;
  }
  return p;
}

// Alloc entity as Entity linklist FIRST entry
struct Entity *AllocEntityFirst(struct EntityHeader *h) {
  struct Entity *p;

  p = h->free;
  if (p != NULL) {
    h->free = p->next;
    h->remaining--;

    p->prev = (struct Entity *)&h->next;
    p->next = h->next;
    h->next->prev = p;
    h->next = p;

    *(u16 *)&p->flags = 0;
    *(u32 *)&p->mode = 0;
    *(u32 *)&p->work = 0;
  }
  return p;
}

#if MODERN == 0
static struct Entity *unused_08006fc4(struct Entity *p) {
  struct Entity *s;
  struct EntityHeader *h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->next;
    h->remaining--;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    *(u16 *)&s->flags = 0;
    *(u32 *)&s->mode = 0;
    *(u32 *)&s->work = 0;
  }
  return s;
}
#endif

#if MODERN == 0
static struct Entity *unused_08006ffc(struct Entity *p) {
  struct Entity *s;
  struct EntityHeader *h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->next;
    h->remaining--;
    s->prev = p->prev;
    s->next = p;
    p->prev->next = s;
    p->prev = s;
    *(u16 *)&s->flags = 0;
    *(u32 *)&s->mode = 0;
    *(u32 *)&s->work = 0;
  }
  return s;
}
#endif

// EntityHeader の配列から不要なEntityを取り除く
void DeleteEntity(struct Entity *p) {
  struct EntityHeader *h;

  p->prev->next = p->next;
  p->next->prev = p->prev;
  h = pCurEntityHeader;
  p->next = pCurEntityHeader->free;
  h->free = p;
  h->remaining++;
}

void DeletePlayer(struct EntityHeader *h, struct Zero *z) {
  (ENTITY(z).prev)->next = ENTITY(z).next;
  (ENTITY(z).next)->prev = ENTITY(z).prev;
  ENTITY(z).next = h->free;
  h->free = &(z->s);
  h->remaining++;
}
