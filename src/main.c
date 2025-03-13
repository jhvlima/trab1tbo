#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "graph.h"
#include "heap.h"
#include "dijkstraHeap.h"
#include "ioHandler.h"

int main(int argc, char *argv[])
{
    struct timeval start, end;
    gettimeofday(&start, NULL); //inicia contagem de tempo

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

    //Escolha entre ler com fscanf ou com getLine(e Token)
    //lerArquivoEntradaGraph(entrada, graph);
    lerArquivoEntradaGraphToken(entrada, graph);

    //graphPrint(graph);
    
    Node** arvoreMinima = dijkstraHeap(graph);

    escreverArquivoSaidaGraph(saida, arvoreMinima, graph);
    //escreverSaidaTerminalGraph(arvoreMinima, graph);

    if(arvoreMinima){
        for(int i = 0; i < graphGetNVertices(graph); i++){
            if(arvoreMinima[i]) free(arvoreMinima[i]);
        }
        free(arvoreMinima);
    }
    graphDestroy(graph);

    fclose(entrada);
    fclose(saida);

    gettimeofday(&end, NULL); // Marca o tempo final
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Tempo de execução: %.6f segundos\n", elapsed_time);
    
    return 0;
}