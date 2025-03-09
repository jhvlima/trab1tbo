#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __aresta Aresta;
typedef struct __graph Graph;

Aresta* arestaCreate(int src, int dst, float wgh);

Graph* graphCreate();
void graphAddAresta(Graph* graph, Aresta* aresta);
void graphSetSource(Graph* graph, int src);
void graphPrint(Graph* graph);



#endif
