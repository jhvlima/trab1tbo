#include "graph.h"

struct __aresta{
    int src, dst;
    float wgh;
    Aresta* next; //Proxima aresta na lista de adjacencias
};

struct __vertice{
    char* nome;
    int id;
    int nAdj;
};

struct __graph{
    int nVertices;
    int src;
    Vertice** vertices;
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

Vertice* verticeCreate(char* nome, int id)
{
    Vertice* vertice = (Vertice*) calloc (1, sizeof(Vertice));
    vertice->nome = strdup(nome);
    vertice->id = id;
}

Graph* graphCreate(int nVertices)
{
    Graph* graph = (Graph*) calloc (sizeof(Graph), 1);
    graph->nVertices = 0;
    graph->src = -1;
    graph->vertices = NULL;
    graph->adjacencias = NULL;
    return graph;
}

void graphSetSize(Graph* graph, int size)
{
    if(!graph) return;

    graph->nVertices = size;  
    graph->adjacencias = (Aresta**) calloc (graph->nVertices, sizeof(Aresta*));
    graph->vertices = (Vertice**) calloc (graph->nVertices, sizeof(Vertice*));

}

char* verticeGetName(Vertice* vertice)
{
    return vertice->nome;
}

void verticeDestroy(Vertice* vertice)
{
    free(vertice->nome);
    free(vertice);
}

Vertice* graphGetVertice(Graph* graph, int id)
{
    return graph->vertices[id];
}

void graphAddVertice(Graph* graph, Vertice* vertice)
{
    if(!graph || !vertice || !graph->vertices) return;
    graph->vertices[vertice->id] = vertice;
}

void graphSetSource(Graph* graph, int src)
{
    graph->src = src;
}

int graphGetNVertices(Graph* graph)
{
    return graph->nVertices;
}

int graphGetSource(Graph* graph)
{
    return graph->src;
}

float getPesoAresta(Graph* graph, int o, int d)
{
    Aresta* aresta = graph->adjacencias[o];
    while(aresta){
        if(aresta->dst == d){
            return aresta->wgh;
        }
        aresta = aresta->next;
    }
}

int* graphGetAdjacencias(Graph* graph, int src, int* nAdj)
{
    if(!graph || !graph->adjacencias[src]) exit(EXIT_FAILURE);

    Aresta* aresta = graph->adjacencias[src];
    (*nAdj)++;
    while(aresta->next){
        aresta = aresta->next;
        (*nAdj)++;
    }
    int* adjacencias = (int*) calloc (*nAdj, sizeof(int));
    int i = 0;
    aresta = graph->adjacencias[src];
    while (aresta)
    {
        adjacencias[i] = aresta->dst;
        aresta = aresta->next;
        i++;
    }
    return adjacencias;    

}

void graphAddAresta(Graph* graph, Aresta* aresta)
{
    if(!graph || !aresta || !graph->adjacencias) return;

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

void arestaAdjDestroy(Aresta* aresta)
{
    if(aresta->next){
        arestaAdjDestroy(aresta->next);
    }
    free(aresta);
}

void graphDestroy(Graph* graph)
{
    if (!graph) return;
    for(int i = 0; i < graph->nVertices; i++){
        if(graph->adjacencias[i]){
            arestaAdjDestroy(graph->adjacencias[i]);
        }
        if(graph->vertices[i]){
            verticeDestroy(graph->vertices[i]);
        }
    }
    free(graph->adjacencias);
    free(graph->vertices);
    free(graph);
}

void graphPrint(Graph* graph)
{
    printf("\nImprimindo Grafo:\nnVertices:%d\nSource: %d\n", graph->nVertices, graph->src);
    printf("\nLista de Adjacencias:\n");
    for(int i = 0; i < graph->nVertices; i++){
        printf("[%d]: {", i);
        Aresta* aux = graph->adjacencias[i];
        if(aux){
            printf("%d(%.2f)", aux->dst, aux->wgh);
            aux = aux->next;
        }
        while(aux){
            printf(", %d(%.2f)", aux->dst, aux->wgh);
            aux = aux->next;
        }
        printf("}\n");
    }
}