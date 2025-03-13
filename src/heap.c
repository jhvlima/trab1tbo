#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

struct __heap
{
    int tamanho;
    int capacidade;
    Node** nodes;
    int* posicaoId;
};


//FUNCOES AUXILIARES DE MANUTENCAO DA HEAP

int greater(Node* n1, Node* n2) //1: n1>n2; 0: n1<n2
{
    if(nodeGetDistancia(n2) < 0){
        return 0;
    }
    if(nodeGetDistancia(n1) < 0){
        return 1;
    }
    if(nodeGetDistancia(n1) > nodeGetDistancia(n2)){
        return 1;
    }
    return 0;
}

//troca os nodes de lugar, atualizando no vetor de posicoes
void exch(Heap* heap, int k1, int k2)
{
    int id1 = nodeGetId(heap->nodes[k1]);
    int id2 = nodeGetId(heap->nodes[k2]);

    Node* aux = heap->nodes[k1];
    heap->nodes[k1] = heap->nodes[k2];
    heap->nodes[k2] = aux;
    
    heap->posicaoId[id1] = k2;
    heap->posicaoId[id2] = k1;
}

//"sobe" um node menor
void heapFixUp(Heap* heap, int k)
{
    while (k > 1 && greater(heap->nodes[k/2], heap->nodes[k])) {
        exch(heap, k, k/2);
        k = k/2;
    }
}

//"desce" um node maior
void heapFixDown(Heap* heap, int k){
    while (2*k <= heap->tamanho) {
        int j = 2*k;
        if (j < heap->tamanho && greater(heap->nodes[j], heap->nodes[j+1])){
            j++;
        }
        if (!greater(heap->nodes[k], heap->nodes[j])) {
        break;
        }
        exch(heap, k, j);
        k = j;
    }
}

//cria heap com n nós inicializados com -1, e source com 0
Heap* heapCreate(int nVertices, int source)
{
    //printf("Criando Heap\n");
    Heap* heap = (Heap*) malloc (sizeof(Heap));
    heap->tamanho = 0;
    heap->capacidade = nVertices + 1;
    heap->posicaoId = (int*) malloc (nVertices * sizeof(int));
    heap->nodes = (Node**) calloc ((nVertices+1),  sizeof(Node*)); //(nVertices+1) pois indices comecam em 1
    for (int i = 0; i < nVertices; i++){
        Node* node = nodeCreate(i, -1);
        if(source == i){
            nodeSetDistancia(node, 0);
        }
        heapAddNode(heap, node);
    }
    //printf("Pronto!\n");

    return heap;
}

void heapAddNode(Heap* heap, Node* node)
{
    if(!heap || !node) return;

    heap->tamanho++;
    heap->nodes[heap->tamanho] = node;
    heap->posicaoId[nodeGetId(node)] = heap->tamanho;
    heapFixUp(heap, (heap->tamanho));
}

int heapIsEmpty(Heap* heap)
{
    if(heap->tamanho) return 0;
    return 1;
}

Node* heapPopMin(Heap* heap) {
    Node* min = heap->nodes[1];
    exch(heap, 1, heap->tamanho);
    heap->tamanho--;
    heapFixDown(heap, 1);
    return min;
}

void heapAtualizaDistancia(Heap* heap, int pos, float distancia, int pai)
{
    Node* node = heap->nodes[pos];
    nodeSetDistancia(node, distancia);
    nodeSetPai(node, pai);
    heapFixUp(heap, pos);
}

float heapGetDistancia(Heap* heap, int id)
{
    int k = heapSearchId(heap, id);
    return nodeGetDistancia(heap->nodes[k]);
}

int heapSearchId(Heap* heap, int id)
{
    if(!heap || id > heap->capacidade - 1){
        printf("\nErro heapSearchId\n");     
        exit(EXIT_FAILURE);

    }
    return heap->posicaoId[id];
}

void heapDestroy(Heap* heap)
{
    if(!heap) return;
    free(heap->posicaoId);
    free(heap->nodes);
    free(heap);
}

//retorna indice do pai na heap
int pai(int k)
{
    if(k == 1){
        return 1;
    }
    return k/2;
}

void heapPrint(Heap* heap)
{
    printf("\nImprimindo Heap Binaria - sz(%d/%d):\n", heap->tamanho, heap->capacidade);
    printf("ID_NODE_HEAP: (ID_VERTICE//ID_VERTICE_PAI)<--[DISTANCIA]--(ID_PAI_HEAP)");
    for(int i = 1; i <= heap->tamanho; i++){
        printf("%d:(%d//%d)<--[%.2f]--(%d)\n", i, nodeGetId(heap->nodes[i]), nodeGetId(heap->nodes[pai(i)]), nodeGetDistancia(heap->nodes[i]), nodeGetPai(heap->nodes[i]));
    }
}
