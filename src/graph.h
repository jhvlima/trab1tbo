#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __aresta Aresta;
typedef struct __vertice Vertice;
typedef struct __graph Graph;

Aresta* arestaCreate(int src, int dst, float wgh);
int arestaGetDst(Aresta* aresta);
float arestaGetPeso(Aresta* aresta);
Aresta* arestaGetNext(Aresta* aresta);

Vertice* verticeCreate(char* nome, int id);
char* verticeGetName(Vertice* vertice);

Graph* graphCreate();
int graphGetNVertices(Graph* graph);
Vertice* graphGetVertice(Graph* graph, int id);
int graphGetSource(Graph* graph);
void graphAddAresta(Graph* graph, Aresta* aresta);
void graphAddVertice(Graph* graph, Vertice* vertice);
void graphSetSource(Graph* graph, int src);
void graphSetSize(Graph* graph, int size);
Aresta* graphGetAdjacencias(Graph* graph, int id);
void graphAllocateVertices(Graph* graph);
void graphPrint(Graph* graph);
void graphDestroy(Graph* graph);



#endif
