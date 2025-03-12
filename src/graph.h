#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __aresta Aresta;
typedef struct __vertice Vertice;
typedef struct __graph Graph;

Aresta* arestaCreate(int src, int dst, float wgh);
Vertice* verticeCreate(char* nome, int id);
char* verticeGetName(Vertice* vertice);

Graph* graphCreate();
int graphGetNVertices(Graph* graph);
Vertice* graphGetVertice(Graph* graph, int id);
int graphGetSource(Graph* graph);
float getPesoAresta(Graph* graph, int o, int d);
void graphAddAresta(Graph* graph, Aresta* aresta);
void graphAddVertice(Graph* graph, Vertice* vertice);
void graphSetSource(Graph* graph, int src);
void graphSetSize(Graph* graph, int size);
int* graphGetAdjacencias(Graph* graph, int src, int* nAdj);
void graphAllocateVertices(Graph* graph);
void graphPrint(Graph* graph);
void graphDestroy(Graph* graph);



#endif
