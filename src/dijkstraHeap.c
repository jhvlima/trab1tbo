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

int resolveComDijkstraHeap(char* entradaPath, char* saidaPath)
{
    FILE *entrada = fopen(entradaPath, "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada: %s\n", entradaPath);
        return 1;
    }

    FILE *saida = fopen(saidaPath, "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    Graph* graph = graphCreate();

    //Escolha entre ler com fscanf ou com getLine(e Token)
    //lerArquivoEntradaGraph(entrada, graph);
    lerArquivoEntradaGraphToken(entrada, graph);

    //graphPrint(graph);
    
    Node** arvoreMinima = dijkstraHeap(graph);

    escreverArquivoSaidaGraph(saida, arvoreMinima, graph);
    //escreverSaidaTerminalGraph(arvoreMinima, graph);

    nodeDestroyArvoreMinima(arvoreMinima, graphGetNVertices(graph));
    
    graphDestroy(graph);

    fclose(entrada);
    fclose(saida);
    return 0;
}