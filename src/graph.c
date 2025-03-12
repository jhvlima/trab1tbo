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
    Aresta** adjacencias; //cada aresta eh a primeira da lista de adjacencias de um vertice
};

//ARESTA ----------------------------------

Aresta* arestaCreate(int src, int dst, float wgh)
{
    Aresta* aresta = (Aresta*) malloc (sizeof(Aresta));
    aresta->src = src;
    aresta->dst = dst;
    aresta->wgh = wgh;
    aresta->next = NULL;
    return aresta;
}

Aresta* arestaGetNext(Aresta* aresta)
{
    return aresta->next;
}

float arestaGetPeso(Aresta* aresta)
{
    if(!aresta) exit(EXIT_FAILURE);
    return aresta->wgh;
}

int arestaGetDst(Aresta* aresta)
{
    return aresta->dst;
}

void arestaNextsDestroy(Aresta* aresta)
{
    if(!aresta) return;

    if(aresta->next){
        arestaNextsDestroy(aresta->next);
    }
    free(aresta);
}

//VERTICE ----------------------------------

Vertice* verticeCreate(char* nome, int id)
{
    Vertice* vertice = (Vertice*) malloc (sizeof(Vertice));
    vertice->nome = strdup(nome); //aloca dinamicamente espaco para o nome e o copia
    vertice->id = id;
    vertice->nAdj = 0;
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

//GRAPH --------------------------------------

Graph* graphCreate()
{
    Graph* graph = (Graph*) malloc (sizeof(Graph));
    graph->nVertices = 0;
    graph->src = -1;
    graph->vertices = NULL;
    graph->adjacencias = NULL;
    return graph;
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

void graphAddVertice(Graph* graph, Vertice* vertice)
{
    if(!graph || !vertice || !graph->vertices) return;
    graph->vertices[vertice->id] = vertice;
}

Aresta* graphGetAdjacencias(Graph* graph, int id)
{
    if(!graph || (id > graph->nVertices)) return NULL;

    return graph->adjacencias[id];    

}

int graphGetNVertices(Graph* graph)
{
    if(!graph) return 0;

    return graph->nVertices;
}

Vertice* graphGetVertice(Graph* graph, int id)
{
    if(!graph || id > graph->nVertices) return NULL;

    return graph->vertices[id];
}

int graphGetSource(Graph* graph)
{
    if(!graph) return -1;

    return graph->src;
}

void graphSetSize(Graph* graph, int size)
{
    if(!graph) return;

    graph->nVertices = size;  
    graph->adjacencias = (Aresta**) calloc (graph->nVertices, sizeof(Aresta*));
    graph->vertices = (Vertice**) calloc (graph->nVertices, sizeof(Vertice*));

}

void graphSetSource(Graph* graph, int src)
{
    if(!graph) return;

    graph->src = src;
}

void graphDestroy(Graph* graph)
{
    if (!graph) return;

    int flag1 = 0, flag2=0;
    if(!graph->adjacencias){
        flag1++;
    }
    if(!graph->vertices){
        flag2++;
    }

    if(!flag1 || !flag2){
        for(int i = 0; i < graph->nVertices; i++){
            if(!flag1 && graph->adjacencias[i]){
                arestaNextsDestroy(graph->adjacencias[i]);
            }
            if(!flag2 && graph->vertices[i]){
                verticeDestroy(graph->vertices[i]);
            }
        }
        if(graph->adjacencias){
            free(graph->adjacencias);
        }
        if(graph->vertices){
            free(graph->vertices);
        }
    }

    free(graph);
}

void graphPrint(Graph* graph)
{
    if(!graph) return;

    printf("\nImprimindo Grafo:\nnVertices:%d\nSource: %d\n", graph->nVertices, graph->src);
    printf("Formatacao: [ID_VERTICE]: {ID_VERTICE_ADJACENTE(PESO_ARESTA), ...}\n");
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