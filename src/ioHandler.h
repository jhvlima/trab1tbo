#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "graph.h"
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
void lerArquivoEntrada(FILE* entrada, Graph* graph);

/*
    @brief Le arquivo de entrada usando getLine (menos acessos a disco) e atribui informacoes ao grafo
    @param entrada Arquivo de entrada
    @param graph Grafo
    @return
*/
void lerArquivoEntradaToken(FILE* entrada, Graph* graph);

//SAIDA --------------------------------
/*
    @brief Imprime caminhos minimos no arquivo de saida
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param graph Grafo
    @return
*/
void escreverArquivoSaida(FILE* saida, Node** arvoreMinima, Graph* graph);

/*
    @brief Imprime caminhos minimos no terminal
    @param saida Arquivo de saida
    @param arvoreMinima Vetor de arvores minimas
    @param graph Grafo
    @return
*/
void escreverSaidaTerminal(Node** arvoreMinima, Graph* graph);

#endif