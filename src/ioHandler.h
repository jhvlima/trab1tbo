#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "graph.h"
#include "heap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void lerArquivoEntrada(FILE* entrada, Graph* graph);
void lerArquivoEntradaToken(FILE* entrada, Graph* graph);
void escreverArquivoSaida(FILE* saida, Node** arvoreMinima, Graph* graph);
void escreverSaidaTerminal(FILE* saida, Node** arvoreMinima, Graph* graph);

#endif