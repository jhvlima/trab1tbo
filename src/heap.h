#ifndef HEAP_H
#define HEAP_H

typedef struct __node Node;
typedef struct __heap Heap;

Heap* heapCreate(int nVertices, int source);
void heapDestroy(Heap* heap);
void heapPush(Heap* heap, void* data);
Node* heapPopMin(Heap* heap);
void* heapTop(Heap* heap);
int heapSize(Heap* heap);
float heapGetDistancia(Heap* heap, int id);
int heapIsEmpty(Heap* heap);
int heapSearchId(Heap* heap, int id);
void heapAddNode(Heap* heap, Node* node);
void heapPrint(Heap* heap);

void heapAtualizaDistancia(Heap* heap, int k, float distancia, int pai);

Node* nodeCreate(int idVert, float distancia);
float nodeGetDistancia(Node* node);
int nodeGetPai(Node* node);
int nodeGetId(Node* node);

#endif // HEAP_H