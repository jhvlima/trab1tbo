#ifndef DIJKSTRAHEAP_H
#define DIJKSTRAHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "graph.h"

/*
    @brief Realiza o algoritmo de Dijkstra em um grafo, utilizando uma MinHeap
    @param graph Grafo
    @return Caminhos minimos
*/
Node** dijkstraHeap(Graph* graph);

#endif