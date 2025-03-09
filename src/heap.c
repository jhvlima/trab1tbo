#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    float distancia;
    Node* esq, *dir;
}Node;

typedef struct heap
{
    int tamanho;
    int capacidade;
    Node* top;

    int (*compare)(void*, void*);
}Heap;

Node* nodeCreate(int id)
{
    Node* node = (Node*) malloc (sizeof(Node));
    node->distancia = -1;
    node->id = id;
    node->esq = NULL;
    node->dir = NULL;
    return node;
}

int nodeGetId(Node* node)
{
    return node->id;
}

void nodeDestroyTree(Node* node)
{
    if(!node) return;
    nodeDestroyTree(node->esq);
    nodeDestroyTree(node->dir);
    free(node);
}

Heap* heapCreate(int (*compare)(void*, void*))
{
    Heap* heap = (Heap*) malloc (sizeof(Heap));
    heap->tamanho = 0;
    heap->capacidade = 0;
    heap->top = NULL;
    heap->compare = compare;
    return heap;
}

void heapDestroy(Heap* heap)
{
    if(!heap) return;
    if(heap->top) nodeDestroyTree(heap->top);
    free(heap);
}
