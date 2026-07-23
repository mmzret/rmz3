#include "entity.h"

IWRAM_DATA ALIGNED(16) Projectile gProjectiles[24] = {};
IWRAM_DATA struct Enemy gEnemies[18] = {};
IWRAM_DATA ALIGNED(16) struct VFX gVFXs[64] = {};

void InitEntityHeader(struct EntityHeader* h, s8 kind, struct Entity* arr, s16 size, s16 count) {
  h->arr = arr;
  h->type = kind;
  h->size = size;
  h->length = count;
  h->head = (struct Entity*)&h->tail;
  h->tail = (struct Entity*)&h->tail;
  h->free = NULL;
  h->remaining = count;

  // e.g.
  // gSolids[0].prev = h->free; // NULL
  // gSolids[1].prev = &gSolids[0];
  // gSolids[2].prev = &gSolids[1];
  // ...
  // gSolids[21].prev = &gSolids[20], h->free = &gSolids[21];
  for (; count > 0; --count) {
    arr->prev = h->free;
    h->free = arr;
    arr->kind = kind;
    arr = (struct Entity*)((void*)arr + size);
  }
}

// 0x08006F24
static void Unused_ResetEntityHeader(struct EntityHeader* h) {
  s8 t = h->type;
  s16 size = h->size;
  InitEntityHeader(h, t, h->arr, size, h->length);
}

// 0x08006F44
void _StartEntityListIteration(struct EntityHeader* h) {
  pCurEntityHeader = h;
  h->cur = (struct Entity*)&h->tail;  // h->cur = {h->tail, h->head} なので、 (h->cur)->next で h->head が取れる
}

void _GetEntityList(struct EntityHeader* h) {
  h->cur = (struct Entity*)&h->tail;  // h->cur = {h->tail, h->head} なので、 (h->cur)->next で h->head が取れる
  return;
}

// 0x08006f5c
// Alloc entity as Entity linklist FIRST entry (こっちで追加したEntityが最初に処理される)
void* AllocEntityFirst(struct EntityHeader* h) {
  struct Entity* p = h->free;  // 1st: p = &gSolids[21];, 2nd: p = &gSolids[20]
  if (p != NULL) {
    h->free = p->prev;  // 1st: h->free = &gSolids[20];, 2nd: h->free = &gSolids[19];
    h->remaining--;

    p->prev = (struct Entity*)&h->tail;  // 1st: gSolids[21].prev = &h->tail, 2nd: gSolids[20].prev = &h->tail
    p->next = h->head;                   // 1st: gSolids[21].next = &h->tail, 2nd: gSolids[20].next = &gSolids[21]
    (h->head)->prev = p;                 // 1st: (h->head)->prev = &gSolids[21], 2nd: gSolids[21].prev = &gSolids[20]
    h->head = p;                         // 1st: h->head = &gSolids[21], 2nd: h->head = &gSolids[20]

    *(u16*)&p->flags = 0;
    *(u32*)&p->mode = 0;
    *(u32*)&p->work = 0;
  }
  return (void*)p;
}

// 0x08006f90
// Alloc entity as Entity linklist LAST entry (こっちで追加したEntityが最後に処理される)
void* AllocEntityLast(struct EntityHeader* h) {
  struct Entity* p;

  p = h->free;
  if (p != NULL) {
    h->free = p->prev;
    h->remaining--;

    p->next = (struct Entity*)&h->tail;
    p->prev = h->tail;
    (h->tail)->next = p;
    h->tail = p;

    *(u16*)&p->flags = 0;
    *(u32*)&p->mode = 0;
    *(u32*)&p->work = 0;
  }
  return (void*)p;
}

static struct Entity* unused_08006fc4(struct Entity* p) {
  struct Entity* s;
  struct EntityHeader* h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->prev;
    h->remaining--;
    s->prev = p->prev;
    s->next = p;
    p->prev->next = s;
    p->prev = s;
    *(u16*)&s->flags = 0;
    *(u32*)&s->mode = 0;
    *(u32*)&s->work = 0;
  }
  return s;
}

static struct Entity* unused_08006ffc(struct Entity* p) {
  struct Entity* s;
  struct EntityHeader* h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->prev;
    h->remaining--;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
    *(u16*)&s->flags = 0;
    *(u32*)&s->mode = 0;
    *(u32*)&s->work = 0;
  }
  return s;
}

// EntityHeader の配列から不要なEntityを取り除く
void DeleteEntity(struct Entity* p) {
  struct EntityHeader* h;

  (p->next)->prev = p->prev;
  (p->prev)->next = p->next;
  h = pCurEntityHeader;
  p->prev = pCurEntityHeader->free;
  h->free = p;
  h->remaining++;
}

// DeleteEntity の EntityHeader* を引数で受け取るバージョン
void DeleteEntityEx(struct EntityHeader* h, struct Entity* p) {
  (p->next)->prev = p->prev;
  (p->prev)->next = p->next;
  p->prev = h->free;
  h->free = p;
  h->remaining++;
}
