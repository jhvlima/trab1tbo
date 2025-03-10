#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    float distancia;
}Node;

typedef struct heap
{
    int tamanho;
    int capacidade;
    Node** nodes;

    int (*compare)(void*, void*);
}Heap;

Node* nodeCreate(int id, float distancia)
{
    Node* node = (Node*) malloc (sizeof(Node));
    node->distancia = distancia;
    node->id = id;
    return node;
}

int nodeGetId(Node* node)
{
    return node->id;
}

float nodeGetDistancia(Node* node)
{
    return node->distancia;
}

int greater(Node* n1, Node* n2)
{
    if(n1->distancia > n2->distancia){
        return 1;
    }
    return 0;
}

void exch(Node* n1, Node* n2)
{
    
}

void heapFixUp(Heap* heap, int k)
{
    while (k > 1 && greater(heap->nodes[k/2], heap->nodes[k])) {
        exch(heap->nodes[k], heap->nodes[k/2]);
        k = k/2;
    }
}

void heapFixDown(Heap* heap, int k){
    while (2*k <= heap->tamanho) {
        int j = 2*k;
        if (j < heap->tamanho && greater(heap->nodes[j], heap->nodes[j+1])){
            j++;
        }
        if (!greater(heap->nodes[k], heap->nodes[j])) {
        break;
        }
        exch(heap->nodes[k], heap->nodes[j]);
        k = j;
    }
}

void heapAddNode(Heap* heap, Node* node)
{
    if(!heap || !node) return;

    heap->tamanho++;
    heap->nodes = (Node**) realloc (heap->nodes, (heap->tamanho + 1) * sizeof(Node*)); //(tamanho+1) pois indices comecam em 1
    heap->nodes[heap->tamanho - 1] = node;
    heapFixUp(heap, (heap->tamanho-1));
}

Heap* heapCreate(int (*compare)(void*, void*))
{
    Heap* heap = (Heap*) malloc (sizeof(Heap));
    heap->tamanho = 0;
    heap->capacidade = 0;
    heap->nodes = NULL;
    heap->compare = compare;
    return heap;
}

void heapDestroy(Heap* heap)
{
    if(!heap) return;
    for(int i = 0; i < heap->tamanho; i++){
        if(heap->nodes[i]){
            free(heap->nodes[i]);
        }
    }
    free(heap->nodes);
    free(heap);
}
