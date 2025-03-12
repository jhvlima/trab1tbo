#include "dijkstraHeap.h"

/*
    @brief Relaxa uma aresta (altera sua distancia se esta puder ser menor)
    @param heap Heap
    @param dest Id do vertice de destino da aresta
    @param pai Node do pai do vertice de destino na heap
    @param pesoAresta Peso da aresta
    @return
*/
void relaxarAresta(Heap* heap, int dest, Node* pai, float pesoAresta)
{
    float distDest = heapGetDistancia(heap, dest);
    float novaDistDest = nodeGetDistancia(pai) + pesoAresta;
    
    if(distDest < 0 || distDest > novaDistDest){
        heapAtualizaDistancia(heap, heapSearchId(heap, dest), novaDistDest, nodeGetId(pai));
    }
}

Node** dijkstraHeap(Graph* graph)
{
    
    Heap* heap = heapCreate(graphGetNVertices(graph), graphGetSource(graph));

    Node* min;
    Node** arvoreMin = (Node**) calloc (graphGetNVertices(graph), sizeof(Node*));
    Aresta* adjacencias;

    //heapPrint(heap);
    //printf("Rodando algoritmo...\n");

    while(!heapIsEmpty(heap)){
        min = heapPopMin(heap);
        int idMin = nodeGetId(min);
        arvoreMin[idMin] = min;
        
        Aresta* adjacencias = graphGetAdjacencias(graph, idMin);
        while(adjacencias){
            int dst = arestaGetDst(adjacencias);
            if(!arvoreMin[dst]){
                relaxarAresta(heap, dst, min, arestaGetPeso(adjacencias));
            }
            adjacencias = arestaGetNext(adjacencias);
        }
        
        //heapPrint(heap);
    }
    //printf("Pronto!\n");

    heapDestroy(heap);
    return arvoreMin;
}