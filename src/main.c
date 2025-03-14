#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

// #include "ioHandler.h"
// #include "graph.h"
// #include "heap.h"
#include "dijkstraHeap.h"
#include "dijkstraMatrix.h"

int main(int argc, char *argv[])
{

    char *entradaPath = argv[1];
    char *saidaPath = argv[2];

    struct timeval start, end;
    gettimeofday(&start, NULL); //inicia contagem de tempo

    resolveComDijkstraHeap(entradaPath, saidaPath);

    gettimeofday(&end, NULL); // Marca o tempo final
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Tempo de execução (heap): %.6f segundos\n", elapsed_time);

    //-----------------------------------------------

    // gettimeofday(&start, NULL); //inicia contagem de tempo

    // resolveComDijkstraMatrix(entradaPath, saidaPath);

    // gettimeofday(&end, NULL); // Marca o tempo final
    // elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    // printf("Tempo de execução (matriz): %.6f segundos\n", elapsed_time);

    
    return 0;
}