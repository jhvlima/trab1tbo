#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __aresta Aresta;
typedef struct __graph Graph;

Aresta* arestaCreate(int src, int dst, float wgh);

Graph* graphCreate();
int graphGetNVertices(Graph* graph);
int graphGetSource(Graph* graph);
float getPesoAresta(Graph* graph, int o, int d);
void graphAddAresta(Graph* graph, Aresta* aresta);
void graphSetSource(Graph* graph, int src);
int* graphGetAdjacencias(Graph* graph, int src, int* nAdj);
void graphPrint(Graph* graph);
void graphDestroy(Graph* graph);



#endif
