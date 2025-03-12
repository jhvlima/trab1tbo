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
    Aresta* aresta = (Aresta*) malloc (sizeof(Aresta));
    aresta->src = src;
    aresta->dst = dst;
    aresta->wgh = wgh;
    aresta->next = NULL;
    return aresta;
}

int arestaGetDst(Aresta* aresta)
{
    return aresta->dst;
}

Vertice* verticeCreate(char* nome, int id)
{
    Vertice* vertice = (Vertice*) malloc (sizeof(Vertice));
    vertice->nome = strdup(nome);
    vertice->id = id;
    vertice->nAdj = 0;
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

float arestaGetPeso(Aresta* aresta)
{
    if(!aresta) exit(EXIT_FAILURE);
    return aresta->wgh;
}

Aresta* arestaGetNext(Aresta* aresta)
{
    return aresta->next;
}

Aresta* graphGetAdjacencias(Graph* graph, int id)
{
    if(!graph) exit(EXIT_FAILURE);

    return graph->adjacencias[id];    

}

void graphAddAresta(Graph* graph, Aresta* aresta)
{
    if(!graph || !aresta || !graph->adjacencias) return;

    if(!graph->adjacencias[aresta->src]){
        graph->adjacencias[aresta->src] = aresta;
        return;
    }

    aresta->next = graph->adjacencias[aresta->src];
    graph->adjacencias[aresta->src] = aresta;
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