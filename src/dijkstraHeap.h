#ifndef DIJKSTRAHEAP_H
#define DIJKSTRAHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "heap.h"
#include "graph.h"
#include "ioHandler.h"

/*
    @brief Realiza o algoritmo de Dijkstra em um grafo, utilizando uma MinHeap
    @param graph Grafo
    @return Caminhos minimos
*/
Node** dijkstraHeap(Graph* graph);

/*
    @brief Resolve o problema utilizando o algoritmo de Dijkstra com MinHeap
    @param entradaPath Caminho para o arquivo de entrada
    @param saidaPath Caminho para o arquivo de saída
    @return Status da execução
*/
int resolveComDijkstraHeap(char* entradaPath, char* saidaPath);

#endif