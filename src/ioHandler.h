#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "graph.h"
#include "matrix.h"
#include "heap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//ENTRADA --------------------------------
/*
    @brief Le arquivo de entrada usando fscanf e atribui informacoes ao grafo
    @param entrada Arquivo de entrada
    @param graph Grafo
    @return
*/
void lerArquivoEntradaGraph(FILE* entrada, Graph* graph);

/*
    @brief Le arquivo de entrada usando getLine (menos acessos a disco) e atribui informacoes ao grafo
    @param entrada Arquivo de entrada
    @param graph Grafo
    @return
*/
void lerArquivoEntradaGraphToken(FILE* entrada, Graph* graph);

/*
    @brief Le arquivo de entrada usando fscanf e atribui informacoes a matriz de adjacencias
    @param entrada Arquivo de entrada
    @param matrix Matriz
    @return
*/
void lerArquivoEntradaMatrix(FILE* entrada, Matrix* matrix);

/*
    @brief Le arquivo de entrada usando getLine (menos acessos a disco) e atribui informacoes a matriz de adjacencias
    @param entrada Arquivo de entrada
    @param matrix Matriz
    @return
*/
void lerArquivoEntradaMatrixToken(FILE* entrada, Matrix* matrix);

//SAIDA --------------------------------
/*
    @brief Imprime caminhos minimos no arquivo de saida
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param graph Grafo
    @return
*/
void escreverArquivoSaidaGraph(FILE* saida, Node** arvoreMinima, Graph* graph);

/*
    @brief Imprime caminhos minimos no terminal
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param graph Grafo
    @return
*/
void escreverSaidaTerminalGraph(Node** arvoreMinima, Graph* graph);

/*
    @brief Imprime caminhos minimos no arquivo de saida
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param graph Matriz
    @return
*/
void escreverArquivoSaidaMatrix(FILE* saida, Node** arvoreMinima, Matrix* matrix);

/*
    @brief Imprime caminhos minimos no terminal
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param matrix Matriz
    @return
*/
void escreverSaidaTerminalMatrix(Node** arvoreMinima, Matrix* matrix);

#endif