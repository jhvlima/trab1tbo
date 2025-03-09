#include "graph.h"

struct __aresta{
    int src, dst;
    float wgh;
    Aresta* next; //Proxima aresta na lista de adjacencias
};

struct __graph{
    int nVertices;
    int src;
    Aresta** adjacencias;
};

Aresta* arestaCreate(int src, int dst, float wgh)
{
    Aresta* aresta = (Aresta*) calloc (sizeof(Aresta), 1);
    aresta->src = src;
    aresta->dst = dst;
    aresta->wgh = wgh;
    aresta->next = NULL;
    return aresta;
}

Graph* graphCreate(int nVertices)
{
    Graph* graph = (Graph*) calloc (sizeof(Graph), 1);
    graph->nVertices = 0;
    graph->src = -1;
    graph->adjacencias = NULL;
    return graph;
}

void graphSetSource(Graph* graph, int src)
{
    graph->src = src;
}

void graphAddAresta(Graph* graph, Aresta* aresta)
{
    if(!graph || !aresta) return;

    if(aresta->src >= graph->nVertices){
        graph->nVertices = aresta->src + 1;
        graph->adjacencias = (Aresta**) realloc (graph->adjacencias, graph->nVertices * sizeof(Aresta*));
        graph->adjacencias[graph->nVertices] = NULL;
    }

    if(!graph->adjacencias[aresta->src]){
        graph->adjacencias[aresta->src] = aresta;
        return;
    }

    Aresta* aux = graph->adjacencias[aresta->src];
    while(aux->next){
        aux = aux->next;
    }
    aux->next = aresta;
    return;
}

void graphPrint(Graph* graph)
{
    printf("\nImprimindo Grafo:\nnVertices:%d\nSource: %d\n", graph->nVertices, graph->src);
    printf("\nLista de Adjacencias:\n");
    for(int i = 0; i < graph->nVertices; i++){
        printf("[%d]: {", i);
        Aresta* aux = graph->adjacencias[i];
        if(aux){
            printf("%d", aux->dst);
            aux = aux->next;
        }
        while(aux){
            printf(", %d", aux->dst);
            aux = aux->next;
        }
        printf("}\n");
    }
}