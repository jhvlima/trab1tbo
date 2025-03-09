#include <stdio.h>
#include <stdlib.h>

//#include "heap.h"
#include "graph.h"
#include "ioHandler.h"

void DijkstraHeap(FILE *entrada, FILE *saida)
{
    fprintf(saida, "Dijkstra Heap\n");
}

int main(int argc, char *argv[])
{
    char *entradaPath = argv[1];
    char *saidaPath = argv[2];

    FILE *entrada = fopen(entradaPath, "r");
    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada: %s\n", entradaPath);
        return 1;
    }

    FILE *saida = fopen(saidaPath, "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    Graph* graph = graphCreate();
    lerArquivoEntrada(entrada, graph);
    graphPrint(graph);
    graphDestroy(graph);

    DijkstraHeap(entrada, saida);

    fclose(entrada);
    fclose(saida);

    return 0;
}