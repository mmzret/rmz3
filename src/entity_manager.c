#include "entity.h"

IWRAM_DATA struct Projectile gProjectiles[24] = {};
IWRAM_DATA struct Enemy gEnemies[18] = {};
IWRAM_DATA ALIGNED(16) struct VFX gVFXs[64] = {};

void InitEntityHeader(struct EntityHeader* h, s8 kind, struct Entity* arr, s16 size, s16 count) {
  h->arr = arr;
  h->type = kind;
  h->size = size;
  h->length = count;
  h->prev = (struct Entity*)&h->next;
  h->next = (struct Entity*)&h->next;
  h->free = NULL;
  h->remaining = count;

  for (; count > 0; --count) {
    arr->next = h->free;
    h->free = arr;
    arr->kind = kind;
    arr = (struct Entity*)((void*)arr + size);
  }
}

// 0x08006F24
static void resetEntityHeader(struct EntityHeader* h) {
  s8 t = h->type;
  s16 size = h->size;
  InitEntityHeader(h, t, h->arr, size, h->length);
}

// 0x08006F44
void setCurProcessedEntityHeader(struct EntityHeader* h) {
  pCurEntityHeader = h;
  h->last = (struct Entity*)&h->next;  // この時点の h->next が last
}

// 処理してないfnを無視して最新のfnを指すようにする
void ignoreEntityFn(struct EntityHeader* h) {
  h->last = (struct Entity*)&h->next;
  return;
}

// Alloc entity as Entity linklist LAST entry
struct Entity* AllocEntityLast(struct EntityHeader* h) {
  struct Entity* p;

  p = h->free;
  if (p != NULL) {
    h->free = p->next;
    h->remaining--;

    p->next = (struct Entity*)&h->next;
    p->prev = h->prev;
    h->prev->next = p;
    h->prev = p;

    *(u16*)&p->flags = 0;
    *(u32*)&p->mode = 0;
    *(u32*)&p->work = 0;
  }
  return p;
}

// Alloc entity as Entity linklist FIRST entry
struct Entity* AllocEntityFirst(struct EntityHeader* h) {
  struct Entity* p;

  p = h->free;
  if (p != NULL) {
    h->free = p->next;
    h->remaining--;

    p->prev = (struct Entity*)&h->next;
    p->next = h->next;
    h->next->prev = p;
    h->next = p;

    *(u16*)&p->flags = 0;
    *(u32*)&p->mode = 0;
    *(u32*)&p->work = 0;
  }
  return p;
}

static struct Entity* unused_08006fc4(struct Entity* p) {
  struct Entity* s;
  struct EntityHeader* h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->next;
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

static struct Entity* unused_08006ffc(struct Entity* p) {
  struct Entity* s;
  struct EntityHeader* h;

  h = pCurEntityHeader;
  s = pCurEntityHeader->free;
  if (s != NULL) {
    pCurEntityHeader->free = s->next;
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

// EntityHeader の配列から不要なEntityを取り除く
void DeleteEntity(struct Entity* p) {
  struct EntityHeader* h;

  p->prev->next = p->next;
  p->next->prev = p->prev;
  h = pCurEntityHeader;
  p->next = pCurEntityHeader->free;
  h->free = p;
  h->remaining++;
}

// DeleteEntity の EntityHeader* を引数で受け取るバージョン
void DeleteEntityEx(struct EntityHeader* h, struct Entity* p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  p->next = h->free;
  h->free = p;
  h->remaining++;
}
