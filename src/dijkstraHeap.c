#include "dijkstraHeap.h"

void relaxarAresta(Heap* heap, int dest, Node* pai, float pesoAresta)
{
    float distPai = nodeGetDistancia(pai);
    float novaDistDest = distPai + pesoAresta;
    if(heapGetDistancia(heap, dest) < 0 || heapGetDistancia(heap, dest) > novaDistDest){
        heapAtualizaDistancia(heap, heapSearchId(heap, dest), novaDistDest, nodeGetId(pai));
    }
}

Node** dijkstraHeap(Graph* graph)
{
    Heap* heap = heapCreate(graphGetNVertices(graph), graphGetSource(graph));
    Node* min;
    Node** arvoreMin = (Node**) calloc (graphGetNVertices(graph), sizeof(Node*));
    int* adjacencias;

    heapPrint(heap);

    while(!heapIsEmpty(heap)){
        min = heapPopMin(heap);
        arvoreMin[nodeGetId(min)] = min;
        int nAdj = 0;
        adjacencias = graphGetAdjacencias(graph, nodeGetId(min), &nAdj);
        for(int i = 0; i < nAdj; i++){
            if(!arvoreMin[adjacencias[i]]){
                float pesoAresta = getPesoAresta(graph, nodeGetId(min), adjacencias[i]);
                relaxarAresta(heap, adjacencias[i], min, pesoAresta);
            }
        }
        heapPrint(heap);
        free(adjacencias);
    }

    heapDestroy(heap);
    return arvoreMin;
}