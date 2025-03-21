//Autoria:
//Daniel Corona de Aguiar (2023101578)
//João Henrique Valbusa Lima (2023100583)

#ifndef DIJKSTRAMATRIX_H
#define DIJKSTRAMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "matrix.h"
#include "graph.h"
#include "ioHandler.h"

/*
    @brief Realiza o algoritmo de Dijkstra em uma matriz de adjacências
    @param matrix Matriz de adjacências
    @return Caminhos mínimos
*/
Node** dijkstraMatrix(Matrix* matrix);

/*
    @brief Resolve o problema utilizando o algoritmo de Dijkstra com matriz de adjacências
    @param entradaPath Caminho para o arquivo de entrada
    @param saidaPath Caminho para o arquivo de saída
    @return Status da execução
*/
int resolveComDijkstraMatrix(char* entradaPath, char* saidaPath);

#endif