#ifndef HEAP_H
#define HEAP_H

typedef struct _Node Node;
typedef struct _Heap Heap;

Heap* heapCreate(int (*compare)(void*, void*));
void heapDestroy(Heap* heap);
void heapPush(Heap* heap, void* data);
void* heapPop(Heap* heap);
void* heapTop(Heap* heap);
int heapSize(Heap* heap);
void* heapFind(Heap* heap, int id);

Node* nodeCreate(int id);
int nodeGetId(Node* node);

#endif // HEAP_H