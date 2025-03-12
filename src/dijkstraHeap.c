#include "dijkstraHeap.h"

void relaxarAresta(Heap* heap, int dest, Node* pai, float pesoAresta)
{
    float distPai = nodeGetDistancia(pai);
    float distDest = heapGetDistancia(heap, dest);
    float novaDistDest = distPai + pesoAresta;
    //printf("\n(%d)%f, (%d)%f, %f, %f", nodeGetId(pai), distPai, dest, distDest, pesoAresta, novaDistDest);
    if(distDest < 0 || distDest > novaDistDest){
        heapAtualizaDistancia(heap, heapSearchId(heap, dest), novaDistDest, nodeGetId(pai));
    }
}

Node** dijkstraHeap(Graph* graph)
{
    printf("Criando Heap\n");
    Heap* heap = heapCreate(graphGetNVertices(graph), graphGetSource(graph));
    printf("Pronto!\n");
    Node* min;
    Node** arvoreMin = (Node**) calloc (graphGetNVertices(graph), sizeof(Node*));
    Aresta* adjacencias;

    //heapPrint(heap);

    printf("Rodando algoritmo...\n");
    while(!heapIsEmpty(heap)){
        min = heapPopMin(heap);
        int idMin = nodeGetId(min);
        arvoreMin[idMin] = min;
        //int nAdj = 0;
        //adjacencias = graphGetAdjacencias(graph, nodeGetId(min), &nAdj);
        Aresta* adjacencias = graphGetAdjacencias(graph, idMin);
        while(adjacencias){
            int dst = arestaGetDst(adjacencias);
            if(!arvoreMin[dst]){
                relaxarAresta(heap, dst, min, arestaGetPeso(adjacencias));
            }
            adjacencias = arestaGetNext(adjacencias);
        }
        // for(int i = 0; i < nAdj; i++){
        //     if(!arvoreMin[adjacencias[i]]){
        //         float pesoAresta = getPesoAresta(graph, idMin, adjacencias[i]);
        //         relaxarAresta(heap, adjacencias[i], min, pesoAresta);
        //     }
        // }
        //heapPrint(heap);
        free(adjacencias);
    }
    printf("Pronto!\n");

    heapDestroy(heap);
    return arvoreMin;
}