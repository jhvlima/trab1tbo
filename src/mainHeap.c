//Autoria:
//Daniel Corona de Aguiar (2023101578)
//João Henrique Valbusa Lima (2023100583)

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "dijkstraHeap.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *entradaPath = argv[1];
    char *saidaPath = argv[2];

    // struct timeval start, end;
    // gettimeofday(&start, NULL); //inicia contagem de tempo

    resolveComDijkstraHeap(entradaPath, saidaPath);

    // gettimeofday(&end, NULL); // Marca o tempo final
    // float elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    // printf("Tempo de execução (heap) [%s]: %.6f segundos\n", entradaPath, elapsed_time);

    return 0;
}