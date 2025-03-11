#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "heap.h"
#include "dijkstraHeap.h"
#include "ioHandler.h"

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

    Node** arvoreMinima = dijkstraHeap(graph);

    for(int i = 0; i < graphGetNVertices(graph); i++){
        printf("SHORTEST PATH TO node_%d: ", i);

        if(i == graphGetSource(graph)){
            printf("node_%d <- node_%d (Distance: 0.00)\n", i, i);
            continue;
        }

        int leitor = i;
        while(leitor != graphGetSource(graph)){
            printf("node_%d <- ", nodeGetId(arvoreMinima[leitor]));
            leitor = nodeGetPai(arvoreMinima[leitor]);
        }
        printf("node_%d (Distance: %.2f)\n", nodeGetId(arvoreMinima[leitor]), nodeGetDistancia(arvoreMinima[i]));
    }
    for(int i = 0; i < graphGetNVertices(graph); i++){
        free(arvoreMinima[i]);
    }
    free(arvoreMinima);
    graphDestroy(graph);

    fclose(entrada);
    fclose(saida);

    return 0;
}